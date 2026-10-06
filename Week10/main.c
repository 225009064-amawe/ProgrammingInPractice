static void print_menu(void) {
    printf("\n===== %s v%s =====\n", APP_NAME, APP_VERSION);
    printf("1. Add employee\n");
    printf("2. List employees\n");
    printf("3. Budget\n");
    printf("4. Reports\n");
    printf("5. Save data (text)\n");
    printf("6. Load data (text)\n");
    printf("7. Save employees (binary)\n");
    printf("8. Load employees (binary)\n");
    printf("0. Exit\n");
}

int main(void) {
    int running = 1;
    while (running) {
        print_menu();
        int choice = read_int("Choice: ", 0, 8);
        switch (choice) {
            case 1: add_employee();                break;
            case 2: list_employees();              break;
            case 3: budget_menu();                 break;
            case 4: report_all();                  break;
            case 5: save_all_text();               break;
            case 6: load_all_text();               break;
            case 7: save_employees_binary();       break;
            case 8: load_employees_binary();       break;
            case 0: running = 0;                   break;
        }
        if (running) pause_screen();
    }
    printf("Goodbye.\n");
    return 0;
}