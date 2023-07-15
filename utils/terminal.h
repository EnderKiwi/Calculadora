/* terminal.h - v0.0.3-alpha by EnderKiwi (Alex M.)
 ******************************************************************************
 * A collection of functions for terminal manipulation.
 * Features: Rich Text (i.e. Color, Bold/Italic/Underline), Cursor Movement,
 *   Erasing (i.e. Line, Screen), etc.
 *
 * ANSI escape codes are heavily relied upon and NO terminal checking is done.
 * This SHOULD be portable, but it is not guaranteed. USE AT YOUR OWN RISK.
 ******************************************************************************
 * Created 2023-07-09 by EnderKiwi.
 */
#ifndef UTILS_TERMINAL_H
#define UTILS_TERMINAL_H

#include <stdio.h>

enum term_codes {
     TERM_BEL = 7, /* Terminal Bell */
     TERM_BS = 8, /* Backspace */
     TERM_HT = 9, /* Horizontal Tab */
     TERM_LF = 10, /* Line Feed */
     TERM_VT = 11, /* Vertical Tab */
     TERM_FF = 12, /* Form Feed */
     TERM_CR = 13, /* Carriage Return */
     TERM_ESC = 27, /* Escape */
     TERM_DEL = 127, /* Delete */
};

enum term_color {
     TERM_COLOR_RESET = 0,
     TERM_COLOR_BLACK = 30,
     TERM_COLOR_RED,
     TERM_COLOR_GREEN,
     TERM_COLOR_YELLOW,
     TERM_COLOR_BLUE,
     TERM_COLOR_MAGENTA,
     TERM_COLOR_CYAN,
     TERM_COLOR_WHITE
};

void terminal_set_color(int color);
void terminal_set_bold(int bold);
void terminal_set_italic(int italic);
void terminal_set_underline(int underline);
void terminal_set_blink(int blink);


#endif /* UTILS_TERMINAL_H */
