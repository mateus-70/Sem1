#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#include "../headers/menus.h"
#include "../headers/terminal.h"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_ENTER 10
#define KEY_ESC 27
#define KEY_Q 113

// typedef struct {
//     char **options;
//     int num_options;
//     int selected;
//     char *title;
// } Dropdown;

Dropdown *create_dropdown(char *title, char **options, int num_options) {
    Dropdown *dropdown = (Dropdown *) malloc(sizeof(Dropdown));
    if (!dropdown) {
        return NULL;
    }

    dropdown->options = options;
    dropdown->num_options = num_options;
    dropdown->selected = 0;
    dropdown->title = title;
    return dropdown;
}

void free_dropdown(Dropdown *dropdown) {
    free(dropdown);
}

void display_dropdown(Dropdown *dropdown) {
    printf(CLEAR_SCREEN);
    printf("%s\n\n", dropdown -> title);

    for (int i = 0; i < dropdown -> num_options; i++) {
        if (i == dropdown -> selected) {
            printf("%s> %s%s\n", HIGHLIGHT, dropdown -> options[i], RESET);
        } else {
            printf("  %s\n", dropdown -> options[i]);
        }
    }
}


int read_key() {
    char c;
    // if (read(STDIN_FILENO, &c, 1) == 1) { // original
    if (read(STDIN_FILENO, &c, 1) == 1) {
        return c;
    }
    return 0;
}

void handle_arrow_key(Dropdown *dropdown) {
    switch (read_key()) {
    case KEY_UP: // ascii code for A
        if (dropdown->selected > 0) {
            dropdown->selected--;
            display_dropdown(dropdown);
        }
        break;

    case KEY_DOWN: // ascii code for B
        if (dropdown->selected < dropdown->num_options - 1) {
            dropdown->selected++;
            display_dropdown(dropdown);
        }
        break;
    }
}

int run_dropdown(Dropdown *dropdown) {
    init_terminal();
    bool is_running = true;
    display_dropdown(dropdown);

    while (is_running) {
        int key = read_key();

        switch (key) {
        case KEY_ESC: // Check if this is an escape sequence for arrow keys
            if (read_key() == '[') {
                handle_arrow_key(dropdown);
            } else {
                // Plain ESC key was pressed - cancel selection
                dropdown->selected = -1;
                is_running = false;
            }
            break;

        case KEY_ENTER:
            // Confirm selection
            is_running = false;
            break;

        case KEY_Q:
            // Cancel selection
            dropdown->selected = -1;
            is_running = false;
            break;
        }
    }

    reset_terminal();
    return dropdown->selected;
}

