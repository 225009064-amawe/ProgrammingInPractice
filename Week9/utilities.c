#include <stdio.h>
#include <string.h>
#include "utilities.h"

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int read_int(const char *prompt, int min, int max) {
    int value;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= min && value <= max) {
            clear_input_buffer();
            return value;
        }
        printf("Invalid input. Enter a number between %d and %d.\n", min, max);
        clear_input_buffer();
    }
}

void read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void pause_screen(void) {
    printf("\nPress Enter to continue...");
    clear_input_buffer();
}