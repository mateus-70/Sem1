#ifndef MENUS_H
#define MENUS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void init_terminal();
void reset_terminal();


typedef struct {
    char **options;
    int num_options;
    int selected;
    char *title;
} Dropdown;

Dropdown *create_dropdown(char *title, char **options, int num_options);

void free_dropdown(Dropdown *dropdown) ;
void display_dropdown(Dropdown *dropdown) ;
int read_key() ;
void handle_arrow_key(Dropdown *dropdown) ;
int run_dropdown(Dropdown *dropdown) ;

#endif
