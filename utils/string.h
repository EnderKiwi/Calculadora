/* string.h - v0.0.5-alpha by EnderKiwi (Alex M.)
 ******************************************************************************
 * String manipulation functions and string type.
 ******************************************************************************
 * Created 2023-07-09 by EnderKiwi.
 */
#ifndef UTILS_STRING_H
#define UTILS_STRING_H

#include <stdbool.h>

typedef struct string_struct {
     char *data;
     int length;
     bool needs_free;
} string;

#endif /* UTILS_STRING_H */
