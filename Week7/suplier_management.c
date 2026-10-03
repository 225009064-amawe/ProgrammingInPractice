#include <stdio.h>
#include <string.h>

int main()
{
    
    char name[100];
    char email[100];
    char phone[20];
    char town[50];

    printf("Enter supplier name: ");
    scanf(" %[^\n]", name);
    printf("Enter email: ");
    scanf(" %[^\n]", email);
    printf("Enter phone: ");
    scanf(" %[^\n]", phone);
    printf("Enter town: ");
    scanf(" %[^\n]", town);

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    
    printf("\nSupplier name length: %d\n", strlen(name));
    printf("Email length: %d\n", strlen(email));
    printf("Town length: %d\n", strlen(town));

    
    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";
    char search[100];

    printf("\nEnter supplier name to search: ");
    scanf(" %[^\n]", search);

    if (strcmp(search, supplier1) == 0 || strcmp(search, supplier2) == 0)
        printf("Supplier found.\n");
    else
        printf("Supplier not found.\n");

    
    char backup[100];
    strcpy(backup, name);

    printf("\nOriginal name: %s\n", name);
    printf("Backup name  : %s\n", backup);

    
    char description[200];
    strcpy(description, name);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");

    printf("\n%s\n", description);

   
    char supplierName[100] = "";
    char supplierEmail[100] = "";
    char supplierTown[50] = "";
    int choice;
    int added = 0;

    do {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter supplier name: ");
            scanf(" %[^\n]", supplierName);
            printf("Enter email: ");
            scanf(" %[^\n]", supplierEmail);
            printf("Enter town: ");
            scanf(" %[^\n]", supplierTown);
            added = 1;
            printf("Supplier added.\n");
        }
        else if (choice == 2) {
            if (added) {
                printf("\nName : %s\n", supplierName);
                printf("Email: %s\n", supplierEmail);
                printf("Town : %s\n", supplierTown);
            } else {
                printf("No supplier added yet.\n");
            }
        }
        else if (choice == 3) {
            char find[100];
            printf("Enter supplier name to search: ");
            scanf(" %[^\n]", find);
            if (added && strcmp(find, supplierName) == 0)
                printf("Supplier found.\n");
            else
                printf("Supplier not found.\n");
        }
        else if (choice == 4) {
            if (added)
                printf("Name length: %d\n", strlen(supplierName));
            else
                printf("No supplier added yet.\n");
        }
        else if (choice == 5) {
            printf("Exiting program.\n");
        }
        else {
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}