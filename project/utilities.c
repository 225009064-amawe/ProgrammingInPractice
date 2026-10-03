

#include <stdio.h>
#include <string.h>
#include "utilities.h"


int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter a whole number: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
    return value;
}


double readDouble(const char *prompt)
{
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1)
    {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return value;
}


void readString(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    
    buffer[strcspn(buffer, "\n")] = '\0';
}


void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
}


void displayMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  1. Employee Management\n");
    printf("  2. Budget Management\n");
    printf("  3. Supplier Management\n");
    printf("  4. Asset Management\n");
    printf("  5. Reports\n");
    printf("  6. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}