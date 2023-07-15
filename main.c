#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "QuickMaths.h"
#include "utils/utils.h"
#include "utils/terminal.h"
#include "maths/maths.h"
#include "license.h"

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
     if (argc < 2) {
          // TODO: enter interactive mode
          return 1;
     }
     // Loop through arguments
     // If they are prefixed with '--' ignore everything else
     for (int i = 1; i < argc; i++) {
          int len = strlen(argv[i]);
          if (strcmp(argv[i], "--help") == 0) {
               printf("USAGE: quickmaths [OPTIONS] [EXPRESSION]\n");
               puts("");
               printf("OPTIONS:\n");
               printf("  --help\n");
               printf("  --version\n");
               printf("  --interactive\n");
               printf("  --license\n");
               puts("");
               printf("EXPRESSION:\n");
               printf("  A mathematical expression to be evaluated.\n");
               printf("    e.g. 1 + 1\n");
               printf("  If not provided, enter interactive mode.\n");
               puts("");
               printf("QuickMaths v%d.%d.%d-%s\n",
                    QUICKMATHS_VERSION_MAJOR,
                    QUICKMATHS_VERSION_MINOR,
                    QUICKMATHS_VERSION_PATCH,
                    QUICKMATHS_VERSION_EXTRA);
               puts("Copyright (c) 2023 EnderKiwi");
               return 0;
          }
          if (strcmp(argv[i], "--version") == 0) {
               printf("QuickMaths v%d.%d.%d-%s\n",
                    QUICKMATHS_VERSION_MAJOR,
                    QUICKMATHS_VERSION_MINOR,
                    QUICKMATHS_VERSION_PATCH,
                    QUICKMATHS_VERSION_EXTRA);
               puts("");
               puts("Libraries:");
               printf("  maths v%d.%d.%d-%s\n",
                    MATHS_VERSION_MAJOR,
                    MATHS_VERSION_MINOR,
                    MATHS_VERSION_PATCH,
                    MATHS_VERSION_EXTRA);
               printf("  utils v%d.%d.%d-%s\n",
                    UTILS_VERSION_MAJOR,
                    UTILS_VERSION_MINOR,
                    UTILS_VERSION_PATCH,
                    UTILS_VERSION_EXTRA);
               puts("");
               puts("QuickMaths, maths, and utils are licensed under the MIT License.");
               puts("Use --license to view the license and other information.");
               puts("Copyright (c) 2023 EnderKiwi");
               return 0;
          }
          if (strcmp(argv[i], "--license") == 0) {
               puts("QuickMaths, as well as it's accompanying maths and utils libraries, are all");
               puts("licensed under the MIT License and are owned by EnderKiwi.");
               puts("");
               puts(QuickMaths_license);
               puts("");
               
               return 0;
          }
          if (strcmp(argv[i], "--interactive") == 0) {
               ret = 1;
          }
          // TODO: do maths
          if (argv[i][0] == '+') {
               operation = 0;
               skip = true;
          } else if (argv[i][0] == '-') {
               operation = 1;
               skip = true;
          } else if (argv[i][0] == '*') {
               operation = 2;
               skip = true;
          } else if (argv[i][0] == '/') {
               operation = 3;
               skip = true;
          } else if (argv[i][0] == '%') {
               operation = 4;
               skip = true;
          } else {
               current = atoi(argv[i]);
          }
          if (using_last && operation != -1 && !skip) {
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
          } else {
               last = current;
               using_last = true;
          }
          skip = false;
     }
     return ret;
}
