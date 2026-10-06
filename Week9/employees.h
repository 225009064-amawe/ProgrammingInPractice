#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int    id;
    char   name[50];
    char   role[30];
    double salary;
} Employee;

int  employee_count(void);
int  add_employee(void);
void list_employees(void);
int  find_employee_by_id(int id);

const Employee *employees_array(void);
double          employees_total_salary(void);

#endif