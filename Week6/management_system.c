
#include <stdio.h>
#include <string.h>

int main()
{
    
    float salaries[50];
    int i;
    float sum = 0, average, highest, lowest;
    float search;
    int found;

    printf("=== EMPLOYEE SALARIES ===\n");

    /* Capture 50 salaries */
    for (i = 0; i < 50; i++) {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    /* Display all salaries */
    printf("\nAll salaries:\n");
    for (i = 0; i < 50; i++) {
        printf("%.2f\n", salaries[i]);
    }

    
    for (i = 0; i < 50; i++) {
        sum += salaries[i];
    }
    average = sum / 50;
    printf("\nAverage salary: %.2f\n", average);

    
    highest = salaries[0];
    for (i = 1; i < 50; i++) {
        if (salaries[i] > highest)
            highest = salaries[i];
    }
    printf("Highest salary: %.2f\n", highest);

    
    lowest = salaries[0];
    for (i = 1; i < 50; i++) {
        if (salaries[i] < lowest)
            lowest = salaries[i];
    }
    printf("Lowest salary: %.2f\n", lowest);

    
    printf("Enter salary to search: ");
    scanf("%f", &search);
    found = 0;
    for (i = 0; i < 50; i++) {
        if (salaries[i] == search) {
            printf("Found at position %d\n", i + 1);
            found = 1;
        }
    }
    if (found == 0)
        printf("Salary not found\n");


    
    float budgets[10];
    float total = 0, avgBudget, temp;
    int j;

    printf("\n=== DEPARTMENT BUDGETS ===\n");

    /* Capture 10 budgets */
    for (i = 0; i < 10; i++) {
        printf("Enter budget %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    
    printf("\nAll budgets:\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    
    for (i = 0; i < 10; i++) {
        total += budgets[i];
    }
    printf("\nTotal budget: %.2f\n", total);

    
    avgBudget = total / 10;
    printf("Average budget: %.2f\n", avgBudget);

    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }
    printf("\nBudgets sorted lowest to highest:\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }


   
    char registrations[20][20];
    char searchReg[20];

    printf("\n=== VEHICLE REGISTRATIONS ===\n");

    /* Capture 20 registration numbers */
    for (i = 0; i < 20; i++) {
        printf("Enter registration %d: ", i + 1);
        scanf("%s", registrations[i]);
    }

    
    printf("\nAll registrations:\n");
    for (i = 0; i < 20; i++) {
        printf("%s\n", registrations[i]);
    }

    
    printf("Enter registration to search: ");
    scanf("%s", searchReg);
    found = 0;
    for (i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Found at position %d\n", i + 1);
            found = 1;
        }
    }
    if (found == 0)
        printf("Registration not found\n");

    return 0;
}