#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "QuickMaths.h"
#include "maths/maths.h"
#include "utils/utils.h"
#include "utils/except.h"
#include "utils/terminal.h"

typedef struct end_expression end_expression;

union end_value {
     int i;
     float f;
     double d;
     end_expression *e;
};

struct end_expression {
     union end_value a;
     char operation;
     union end_value b;
     int info;
};

end_expression end_expression_default = {
     .a.i = 0,
     .operation = 0,
     .b.i = 0,
     .info = 0,
};

enum end_expression_infos {
     END_EXPRESSION_INFO_INT = 0,
     END_EXPRESSION_INFO_FLOAT = 1,
     END_EXPRESSION_INFO_DOUBLE = 2,
     END_EXPRESSION_INFO_EXPRESSION = 3,
};
struct end_expression_info {
     int a_type;
     bool a_needs_free;
     int b_type;
     bool b_needs_free;
};

end_expression end_expression_set_info(end_expression expr, struct end_expression_info info)
{
     expr.info = 0;
     expr.info |= info.a_type << 6;
     expr.info |= info.a_needs_free << 5;
     expr.info |= info.b_type << 3;
     expr.info |= info.b_needs_free << 2;
     return expr;
}

struct end_expression_info end_expression_get_info(end_expression expr)
{
     return (struct end_expression_info) {
          .a_type = expr.info >> 6 & 0b00000011,
          .a_needs_free = expr.info >> 5 & 0b00000001,
          .b_type = expr.info >> 3 & 0b00000011,
          .b_needs_free = expr.info >> 2 & 0b00000001,
     };
}

int end_solve_expression(end_expression expr)
{
     int result = 0;

     int a = 0;
     int b = 0;

     struct end_expression_info info = end_expression_get_info(expr);

     if (info.a_type == 3)    a = end_solve_expression(*expr.a.e);
     else                     a = expr.a.i;

     if (info.b_type == 3)    b = end_solve_expression(*expr.b.e);
     else                     b = expr.b.i;

     switch (expr.operation) {
          case '+':
               result = end_add(a, b);
               break;
          case '-':
               result = end_sub(a, b);
               break;
          case '*':
               result = end_mul(a, b);
               break;
          case '/':
               end_error_try_else(
                    result = end_div(a, b),
                    end_error temp = end_error_get();
                    if (temp.code == END_ERROR_DIVISION_BY_ZERO.code) {
                         printf("Division by zero is undefined and results in 0.\n");
                    } else {
                         printf("An error occurred: [%d] %s\n", temp.code, temp.message);
                    }
               );
               //result = end_div(a, b);
               break;
          case '%':
               result = end_mod(a, b);
               break;
          default:
               break;
     }

     return result;
}

/**
 * @brief Parses the command line arguments.
 * @returns 1 if the program should enter interactive mode, 0 if the program should exit.
 */
static int parse_args(int argc, char **argv);
/**
 * @brief Parses the command line arguments.
 * @returns 1 if the program should enter interactive mode, 0 if the program should exit.
 */
static int new_parse_args(int argc, char **argv);

int main(int argc, char **argv)
{
     #if 0
     argc = 8;
     argv = (char *[]) {
          "QuickMaths",
          "5",
          "+",
          "5",
          "/",
          "5",
          "*",
          "10"
     };
     #endif // 0
     if (new_parse_args(argc, argv)) {
          // TODO: interactive mode
     }

     return 0;
}

static int new_parse_args(int argc, char **argv)
{
     /**
      * @brief Return value of parse_args
      * @details 0 if the program should exit, 1 if the program should enter interactive mode.
      */
     int ret = 0;
     //int current = 0;
     //int last = 0;
     //int operation = -1;
     int result = 0;
     bool skip = false;
     bool return_result = false;

     //bool expr_init = false;
     end_expression expr = {
          .a.i = 0,
          .operation = 0,
          .b.i = 0,
          .info = 0,
     };

     end_expression *current_expr = &expr;
     end_expression *last_expr = &expr;

     int place = 0;

     if (argc < 2) {
          // TODO: enter interactive mode
          return 1;
     }
     // Loop through arguments
     // If they are prefixed with '--' ignore everything else
     for (int i = 1; i < argc; i++) {
          if (strcmp(argv[i], "--help") == 0) {
               QuickMaths_cmd_help();
               return 0;
          } else
          if (strcmp(argv[i], "--version") == 0) {
               QuickMaths_cmd_version();
               return 0;
          } else
          if (strcmp(argv[i], "--license") == 0) {
               QuickMaths_cmd_license();
               return 0;
          } else
          if (strcmp(argv[i], "--interactive") == 0) {
               ret = 1;
               skip = true;
          } else
          if (strcmp(argv[i], "--return") == 0) {
               return_result = true;
               skip = true;
          }
          // TODO: do maths
          else
          if (strspn(argv[i], "0123456789") == strlen(argv[i])) {
               // This is a number
               if (place == 0) {
                    current_expr->a.i = atoi(argv[i]);
                    place += 1;
               }
               else if (place == 2) {
                    current_expr->b.i = atoi(argv[i]);
                    place += 1;
               }
          } else
          if (strspn(argv[i], "+-*/%") == strlen(argv[i])) {
               // This is an operation
               if (place == 1) {
                    current_expr->operation = argv[i][0];
                    place += 1;
               }
          } else {
               // This is an invalid argument
               printf("Invalid argument: %s\n", argv[i]);
               puts("Please note for the time being, everything must be separated by spaces, no parentheses are supported, only integers are supported, and commas are not yet supported.");
               exit(1);
          }
          last_expr = current_expr;
          if (place == 3 && i < argc - 1) {
               // We have a full expression
               last_expr = current_expr;
               current_expr = malloc(sizeof(end_expression));
               *current_expr = *last_expr;
               union end_value temp = last_expr->b;
               struct end_expression_info temp2 = end_expression_get_info(*last_expr);
               last_expr->b.e = current_expr;
               *last_expr = end_expression_set_info(*last_expr, (struct end_expression_info) {
                    .b_type = END_EXPRESSION_INFO_EXPRESSION,
                    .b_needs_free = true,
               });
               current_expr->a = temp;
               *current_expr = end_expression_set_info(*current_expr, (struct end_expression_info) {
                    .a_type = temp2.a_type,
                    .a_needs_free = temp2.a_needs_free,
               });
               place = 1;
          }
          skip = false;
     }
     printf("%d\n", end_solve_expression(expr));
     if (return_result) {
          exit(result);
     }
     return ret;
}

static int parse_args(int argc, char **argv)
{
     /**
      * @brief Return value of parse_args
      * @details 0 if the program should exit, 1 if the program should enter interactive mode.
      */
     int ret = 0;
     int current = 0;
     int last = 0;
     int operation = -1;
     int result = 0;
     bool skip = false;
     bool return_result = false;
     if (argc < 2) {
          // TODO: enter interactive mode
          return 1;
     }
     // Loop through arguments
     // If they are prefixed with '--' ignore everything else
     for (int i = 1; i < argc; i++) {
          //int len = strlen(argv[i]);
          if (strcmp(argv[i], "--help") == 0) {
               QuickMaths_cmd_help();
               return 0;
          }
          if (strcmp(argv[i], "--version") == 0) {
               QuickMaths_cmd_version();
               return 0;
          }
          if (strcmp(argv[i], "--license") == 0) {
               QuickMaths_cmd_license();
               return 0;
          }
          if (strcmp(argv[i], "--interactive") == 0) {
               ret = 1;
          }
          if (strcmp(argv[i], "--return") == 0) {
               return_result = true;
          }
          // TODO: do maths
          if (strcmp(argv[i], "+") == 0) {
               operation = 0;
               skip = true;
          } else if (strcmp(argv[i], "-") == 0) {
               operation = 1;
               skip = true;
          } else if (strcmp(argv[i], "*") == 0) {
               operation = 2;
               skip = true;
          } else if (strcmp(argv[i], "/") == 0) {
               operation = 3;
               skip = true;
          } else if (strcmp(argv[i], "%") == 0) {
               operation = 4;
               skip = true;
          } else {
               current = atoi(argv[i]);
          }
          if (operation != -1 && !skip) {
               switch (operation) {
                    case 0:
                         result = end_add(last, current);
                         break;
                    case 1:
                         result = end_sub(last, current);
                         break;
                    case 2:
                         result = end_mul(last, current);
                         break;
                    case 3:
                         result = end_div(last, current);
                         break;
                    case 4:
                         result = end_mod(last, current);
                         break;
                    default:
                         break;
               };
               printf("%d\n", result);
               last = result;
          } else if (skip) {
               // do nothing
          } else {
               last = current;
          }
          skip = false;
     }
     if (return_result) {
          exit(result);
     }
     return ret;
}
