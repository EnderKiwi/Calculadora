#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "QuickMaths.h"
#include "maths/maths.h"
#include "utils/utils.h"
#include "utils/terminal.h"

/**
 * @brief Parses the command line arguments.
 * @returns 1 if the program should enter interactive mode, 0 if the program should exit.
 */
static int parse_args(int argc, char **argv);

int main(int argc, char **argv)
{
     if (parse_args(argc, argv)) {
          // TODO: interactive mode
     }

     return 0;
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
     bool using_last = false;
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
               using_last = false;
          } else if (skip) {
               // do nothing
          } else {
               last = current;
               using_last = true;
          }
          skip = false;
     }
     if (return_result) {
          exit(result);
     }
     return ret;
}
