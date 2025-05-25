#ifndef TERMINAL_H
#define TERMINAL_H

#define CLEAR_SCREEN "\033[2J\033[H"
#define CURSOR_UP "\033[A"
#define CURSOR_DOWN "\033[B"
#define CLEAR_LINE "\033[K"
#define HIGHLIGHT "\033[7m" // Reverse video (highlight)
#define RESET "\033[0m"     // Reset attributes

void init_terminal();
void reset_terminal();

#endif
