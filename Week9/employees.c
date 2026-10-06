#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int      count = 0;

int employee_count(void) { return count; }

const Employee *employees_array(void) { return employees; }

double employees_total_salary(void) {
    double sum = 0.0;
    for (int i = 0; i < count; i++)
        sum += employees[i].salary;
    return sum;
}

int add_employee(void) {
    if (count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return 0;
    }
    Employee *e = &employees[count];
    e->id = count + 1;
    read_string("Name: ", e->name, sizeof e->name);
    read_string("Role: ", e->role, sizeof e->role);
    printf("Salary: ");
    if (scanf("%lf", &e->salary) != 1) {
        clear_input_buffer();
        printf("Invalid salary.\n");
        return 0;
    }
    clear_input_buffer();
    count++;
    printf("Employee #%d added.\n", e->id);
    return 1;
}

void list_employees(void) {
    if (count == 0) { printf("No employees yet.\n"); return; }
    printf("\n%-4s %-20s %-15s %10s\n", "ID", "Name", "Role", "Salary");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-20s %-15s %10.2f\n",
               employees[i].id, employees[i].name,
               employees[i].role, employees[i].salary);
    }
}

int find_employee_by_id(int id) {
    for (int i = 0; i < count; i++)
        if (employees[i].id == id) return i;
    return -1;
}