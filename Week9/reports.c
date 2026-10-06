#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void report_all(void) {
    printf("\n===== MFMS Report =====\n");
    list_employees();
    printf("\nBudget total:     %.2f\n", budget_total());
    printf("Budget remaining: %.2f\n", budget_remaining());
    printf("=======================\n");
}

void report_salary_totals(void) {
    printf("Total salaries: %.2f\n", employees_total_salary());
}