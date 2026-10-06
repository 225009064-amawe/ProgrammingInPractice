#ifndef UTILITIES_H
#define UTILITIES_H

int  read_int(const char *prompt, int min, int max);
void read_string(const char *prompt, char *buffer, int size);
void clear_input_buffer(void);
void pause_screen(void);

#endif