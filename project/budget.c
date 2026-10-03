include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"
]
#
char   departmentNames[MAX_DEPARTMENTS][50];
double departmentBudgets[MAX_DEPARTMENTS];
double departmentExpenditures[MAX_DEPARTMENTS];
int    departmentCount = 0;


double calculateBalance(double budget, double expenditure)
{
    return budget - expenditure;
}


void addDepartmentBudget(void)
{
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("\nDepartment limit reached (%d).\n", MAX_DEPARTMENTS);
        pauseScreen();
        return;
    }

    printf("\n--- ADD DEPARTMENT BUDGET ---\n");

    readString("Enter Department Name: ",
               departmentNames[departmentCount], 50);

    departmentBudgets[departmentCount] =
        readDouble("Enter Allocated Budget: N$");
    if (departmentBudgets[departmentCount] < 0) {
        printf("Invalid budget. Setting to 0.\n");
        departmentBudgets[departmentCount] = 0;
    }

    departmentExpenditures[departmentCount] =
        readDouble("Enter Expenditure: N$");
    if (departmentExpenditures[departmentCount] < 0) {
        printf("Invalid expenditure. Setting to 0.\n");
        departmentExpenditures[departmentCount] = 0;
    }

    departmentCount++;
    printf("\nDepartment budget added successfully!\n");
    pauseScreen();
}


void displayBudgets(void)
{
    int i;
    double balance;

    if (departmentCount == 0) {
        printf("\nNo department budgets to display.\n");
        pauseScreen();
        return;
    }

    printf("\n--- DEPARTMENT BUDGET REPORT ---\n");
    printf("%-15s %-12s %-12s %-12s %-15s\n",
           "Department", "Budget", "Expenditure", "Balance", "Status");
    printf("-----------------------------------------------\n");

    for (i = 0; i < departmentCount; i++) {
        balance = calculateBalance(departmentBudgets[i],
                                   departmentExpenditures[i]);

        printf("%-15s N$%-10.2f N$%-10.2f N$%-10.2f ",
               departmentNames[i],
               departmentBudgets[i],
               departmentExpenditures[i],
               balance);

        if (balance >= 0)
            printf("WITHIN BUDGET\n");
        else
            printf("OVER BUDGET\n");
    }
    pauseScreen();
}


void budgetManagementMenu(void)
{
    int choice;

    do {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Back to Main Menu\n");
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: addDepartmentBudget(); break;
            case 2: displayBudgets();      break;
            case 3: printf("Returning to main menu...\n"); break;
            default:
                printf("Invalid choice. Try again.\n");
                pauseScreen();
        }
    } while (choice != 3);
}