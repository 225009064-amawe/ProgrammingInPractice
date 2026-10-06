#include <stdio.h>
#include "budget.h"
#include "utilities.h"
#include "employees.h"

static double total_budget = 0.0;

double budget_total(void)         { return total_budget; }
void   budget_set_total(double a) { total_budget = a; }

double budget_remaining(void) {
    return total_budget - employees_total_salary();
}

void budget_menu(void) {
    printf("\n--- Budget ---\n");
    printf("1. Set total budget\n");
    printf("2. View remaining\n");
    int choice = read_int("Choice: ", 1, 2);
    if (choice == 1) {
        printf("Enter total budget: ");
        if (scanf("%lf", &total_budget) != 1) {
            clear_input_buffer();
            return;
        }
        clear_input_buffer();
    } else {
        printf("Total budget:     %.2f\n", total_budget);
        printf("Total salaries:   %.2f\n", employees_total_salary());
        printf("Budget remaining: %.2f\n", budget_remaining());
    }
}