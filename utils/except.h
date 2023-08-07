/* except.h - v0.0.5-alpha by EnderKiwi (Alex M.)
 ******************************************************************************
 * Error handling and exception handling.
 ******************************************************************************
 * Created 2023-07-09 by EnderKiwi.
 */
#ifndef UTILS_EXCEPT_H
#define UTILS_EXCEPT_H

#include <stdbool.h>

/**
 * Try to run some code, but ignore any end_errors that occur.
*/
#define end_error_try_ignore(try)                           \
{                                                           \
    int end_error_try_ignore_temp = end_error_get_id();     \
    try;                                                    \
    if (end_error_get_id() != end_error_try_ignore_temp) {} \
}

/**
 * Try to run some code, but if an end_error occurs, run some other code.
*/
#define end_error_try_else(try, else)                       \
{                                                           \
     int end_error_try_else_temp = end_error_get_id();      \
     try;                                                   \
     if (end_error_get_id() != end_error_try_else_temp) {   \
          else;                                             \
     }                                                      \
}

typedef struct end_error_struct {
     int code;
     char *message;
     bool message_needs_free;
} end_error;

extern const end_error END_ERROR_NONE;
extern const end_error END_ERROR_DEFAULT;
extern const end_error END_ERROR_INVALID_ARGUMENT;
extern const end_error END_ERROR_DIVISION_BY_ZERO;

void end_error_throw(end_error error);
end_error end_error_get(void);
int end_error_get_id(void);

#endif /* UTILS_EXCEPT_H */
