#include <stdio.h>
#include <string.h>
#include "Calculadora.h"
#include "utils/utils.h"
#include "math/math.h"
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
     if (argc < 2) {
          // TODO: enter interactive mode
          return 1;
     }
     // Loop through arguments
     // If they are prefixed with '--' ignore everything else
     for (int i = 1; i < argc; i++) {
          int len = strlen(argv[i]);
          if (strcmp(argv[i], "--help") == 0) {
               printf("USAGE: calculadora [OPTIONS] [EXPRESSION]\n");
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
               printf("Calculadora v%d.%d.%d-%s build %d\n",
                    CALCULADORA_VERSION_MAJOR,
                    CALCULADORA_VERSION_MINOR,
                    CALCULADORA_VERSION_PATCH,
                    CALCULADORA_VERSION_EXTRA,
                    CALCULADORA_VERSION_BUILD);
               puts("Copyright (c) 2023 EnderKiwi");
               return 0;
          }
          if (strcmp(argv[i], "--version") == 0) {
               printf("Calculadora v%d.%d.%d-%s build %d\n",
                    CALCULADORA_VERSION_MAJOR,
                    CALCULADORA_VERSION_MINOR,
                    CALCULADORA_VERSION_PATCH,
                    CALCULADORA_VERSION_EXTRA,
                    CALCULADORA_VERSION_BUILD);
               puts("");
               puts("Libraries:");
               printf("  math v%d.%d.%d-%s build %d\n",
                    MATH_VERSION_MAJOR,
                    MATH_VERSION_MINOR,
                    MATH_VERSION_PATCH,
                    MATH_VERSION_EXTRA,
                    MATH_VERSION_BUILD);
               printf("  utils v%d.%d.%d-%s build %d\n",
                    UTILS_VERSION_MAJOR,
                    UTILS_VERSION_MINOR,
                    UTILS_VERSION_PATCH,
                    UTILS_VERSION_EXTRA,
                    UTILS_VERSION_BUILD);
               puts("");
               puts("Calculadora, math, and utils are licensed under the MIT License.");
               puts("Use --license to view the license and other information.");
               puts("Copyright (c) 2023 EnderKiwi");
               return 0;
          }
          if (strcmp(argv[i], "--license") == 0) {
               puts("Calculadora, as well as it's accompanying math and utils libraries, are all");
               puts("licensed under the MIT License and are owned by EnderKiwi.");
               puts("");
               puts(calculadora_license);
               puts("");
               
               return 0;
          }
          if (strcmp(argv[i], "--interactive") == 0) {
               ret = 1;
          }
          // TODO: do maths
     }
     return ret;
}
