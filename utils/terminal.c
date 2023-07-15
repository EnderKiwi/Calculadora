#include <stdio.h>

#include "terminal.h"

void terminal_set_color(int color) {
    printf("\x1B[%dm", color);
}
