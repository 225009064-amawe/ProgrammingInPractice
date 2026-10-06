#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>     
#include "storage.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"

#define DATA_DIR  "data"
#define EMP_TXT   DATA_DIR "/employees.txt"
#define EMP_BIN   DATA_DIR "/employees.dat"
#define SUP_TXT   DATA_DIR "/suppliers.txt"
#define AST_TXT   DATA_DIR "/assets.txt"
#define BUD_TXT   DATA_DIR "/budget.txt"

#define BIN_MAGIC   0x4D464D53u   
#define BIN_VERSION 1u



int ensure_data_dir(void) {
    if (mkdir(DATA_DIR, 0755) == 0 || errno == EEXIST)
        return 1;
    perror("mkdir data");
    return 0;
}



static FILE *open_file(const char *path, const char *mode) {
    FILE *fp = fopen(path, mode);
    if (!fp) perror(path);
    return fp;
}



int save_employees_text(void) {
    if (!ensure_data_dir()) return 0;
    FILE *fp = open_file(EMP_TXT, "w");       
    if (!fp) return 0;

    int n = employee_count();
    const Employee *arr = employees_array();
    for (int i = 0; i < n; i++) {
        if (fprintf(fp, "%d|%s|%s|%.2f\n",
                    arr[i].id, arr[i].name,
                    arr[i].role, arr[i].salary) < 0) {
            perror("fprintf employees");
            fclose(fp);
            return 0;
        }
    }
    if (fclose(fp) != 0) { perror("fclose employees"); return 0; }
    printf("Saved %d employee(s) to %s\n", n, EMP_TXT);
    return 1;
}

int load_employees_text(void) {
    FILE *fp = open_file(EMP_TXT, "r");
    if (!fp) return 0;   /* missing file is not fatal — just empty */

    char line[256];
    int  loaded = 0;
    while (fgets(line, sizeof line, fp)) {
        int id; char name[50], role[30]; double salary;
        /* %49[^|] stops at the pipe; handles spaces in names */
        if (sscanf(line, "%d|%49[^|]|%29[^|]|%lf",
                   &id, name, role, &salary) == 4) {
            employee_add_raw(id, name, role, salary);   /* see note */
            loaded++;
        } else {
            fprintf(stderr, "Skipping malformed line: %s", line);
        }
    }
    fclose(fp);
    printf("Loaded %d employee(s) from %s\n", loaded, EMP_TXT);
    return 1;
}



typedef struct {
    unsigned magic;
    unsigned version;
    unsigned count;
} BinHeader;

int save_employees_binary(void) {
    if (!ensure_data_dir()) return 0;
    FILE *fp = open_file(EMP_BIN, "wb");
    if (!fp) return 0;

    int n = employee_count();
    BinHeader h = { BIN_MAGIC, BIN_VERSION, (unsigned)n };
    if (fwrite(&h, sizeof h, 1, fp) != 1) goto fail;

    const Employee *arr = employees_array();
    if (n && fwrite(arr, sizeof *arr, (size_t)n, fp) != (size_t)n) goto fail;

    fclose(fp);
    printf("Saved %d employee(s) (binary) to %s\n", n, EMP_BIN);
    return 1;
fail:
    perror("fwrite employees binary");
    fclose(fp);
    return 0;
}

int load_employees_binary(void) {
    FILE *fp = open_file(EMP_BIN, "rb");
    if (!fp) return 0;

    BinHeader h;
    if (fread(&h, sizeof h, 1, fp) != 1) { fclose(fp); return 0; }
    if (h.magic != BIN_MAGIC || h.version != BIN_VERSION) {
        fprintf(stderr, "Bad or incompatible binary file\n");
        fclose(fp);
        return 0;
    }

    Employee tmp;
    int loaded = 0;
    while (fread(&tmp, sizeof tmp, 1, fp) == 1) {
        employee_add_raw(tmp.id, tmp.name, tmp.role, tmp.salary);
        loaded++;
    }
    fclose(fp);
    printf("Loaded %d employee(s) (binary) from %s\n", loaded, EMP_BIN);
    return 1;
}



int save_suppliers_text(void) {
    if (!ensure_data_dir()) return 0;
    FILE *fp = open_file(SUP_TXT, "w");
    if (!fp) return 0;
    int n = supplier_count();
    const Supplier *arr = suppliers_array();
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d|%s|%s|%.2f\n",
                arr[i].id, arr[i].name, arr[i].contact, arr[i].rating);
    fclose(fp);
    printf("Saved %d supplier(s).\n", n);
    return 1;
}

int load_suppliers_text(void) {
    FILE *fp = open_file(SUP_TXT, "r");
    if (!fp) return 0;
    char line[256];
    int loaded = 0;
    while (fgets(line, sizeof line, fp)) {
        int id; char name[50], contact[50]; double rating;
        if (sscanf(line, "%d|%49[^|]|%49[^|]|%lf",
                   &id, name, contact, &rating) == 4) {
            supplier_add_raw(id, name, contact, rating);
            loaded++;
        }
    }
    fclose(fp);
    printf("Loaded %d supplier(s).\n", loaded);
    return 1;
}

int save_assets_text(void) {
    if (!ensure_data_dir()) return 0;
    FILE *fp = open_file(AST_TXT, "w");
    if (!fp) return 0;
    int n = asset_count();
    const Asset *arr = assets_array();
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d|%s|%.2f\n",
                arr[i].id, arr[i].description, arr[i].value);
    fclose(fp);
    return 1;
}

int load_assets_text(void) {
    FILE *fp = open_file(AST_TXT, "r");
    if (!fp) return 0;
    char line[256];
    while (fgets(line, sizeof line, fp)) {
        int id; char desc[80]; double value;
        if (sscanf(line, "%d|%79[^|]|%lf", &id, desc, &value) == 3)
            asset_add_raw(id, desc, value);
    }
    fclose(fp);
    return 1;
}

int save_budget_text(void) {
    if (!ensure_data_dir()) return 0;
    FILE *fp = open_file(BUD_TXT, "w");
    if (!fp) return 0;
    fprintf(fp, "total=%.2f\n", budget_total());
    fclose(fp);
    return 1;
}

int load_budget_text(void) {
    FILE *fp = open_file(BUD_TXT, "r");
    if (!fp) return 0;
    double t;
    if (fscanf(fp, "total=%lf", &t) == 1)
        budget_set_total(t);
    fclose(fp);
    return 1;
}



int save_all_text(void) {
    return save_employees_text()
         & save_suppliers_text()
         & save_assets_text()
         & save_budget_text();
}

int load_all_text(void) {
    return load_employees_text()
         & load_suppliers_text()
         & load_assets_text()
         & load_budget_text();
}