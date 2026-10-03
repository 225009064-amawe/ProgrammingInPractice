

#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 10 


extern char departmentNames[MAX_DEPARTMENTS][50];
extern double departmentBudgets[MAX_DEPARTMENTS];
extern double departmentExpenditures[MAX_DEPARTMENTS];
extern int departmentCount;


void addDepartmentBudget(void);
void displayBudgets(void);
double calculateBalance(double budget, double expenditure);
void budgetManagementMenu(void);

#endif