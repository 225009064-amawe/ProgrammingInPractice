#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"

static void print_menu(void) {
    printf("\n===== MFMS =====\n");
    printf("1. Add employee\n");
    printf("2. List employees\n");
    printf("3. Budget\n");
    printf("0. Exit\n");
}

int main(void) {
    int running = 1;
    while (running) {
        print_menu();
        int choice = read_int("Choice: ", 0, 3);
        switch (choice) {
            case 1: add_employee();   break;
            case 2: list_employees(); break;
            case 3: budget_menu();    break;
            case 0: running = 0;      break;
        }
        if (running) pause_screen();
    }
    printf("Goodbye.\n");
    return 0;
}