#include <stdio.h>

#include "QuickMaths.h"
#include "license.h"
#include "maths/maths.h"
#include "utils/utils.h"

void QuickMaths_print_version(void)
{
    printf("QuickMaths v%d.%d.%d-%s\n", QUICKMATHS_VERSION_MAJOR, QUICKMATHS_VERSION_MINOR, QUICKMATHS_VERSION_PATCH, QUICKMATHS_VERSION_EXTRA);
}

static const char *QuickMaths_help = "\
USAGE: %s [OPTIONS] [EXPRESSION]\n\
\n\
OPTIONS:\n\
  --help"          "\x09"    "See this help message\n\
  --version"       "\x09"    "Get version information\n\
  --license"       "\x09"    "Get license information\n\
  --interactive"   "\x09"    "Enter interactive mode\n\
  --return"        "\x09"    "Return the result as command output\n\
\n\
EXPRESSION:\n\
  A mathematical expression to be evaluated.\n\
    e.g. 1 + 1\n\
  If not provided, enter interactive mode.\n\
\n";

void QuickMaths_cmd_help(void)
{
     QuickMaths_cmd_ahelp("QuickMaths");
}

void QuickMaths_cmd_ahelp(char *name)
{
     printf(QuickMaths_help, name);
     QuickMaths_print_version();
     puts("Copyright (c) 2023 EnderKiwi");
}

void QuickMaths_cmd_version(void)
{
     QuickMaths_print_version();
     puts("");
     puts("Libraries:");
     printf("  ");
     maths_print_version();
     printf("  ");
     utils_print_version();
     puts("");
     puts("QuickMaths, maths, and utils are licensed under the MIT License.");
     puts("Use --license to view the license and other information.");
     puts("Copyright (c) 2023 EnderKiwi");
}

void QuickMaths_cmd_license(void)
{
     puts("QuickMaths, as well as it's accompanying maths and utils libraries, are all");
     puts("licensed under the MIT License and are owned by EnderKiwi.");
     puts("");
     puts(QuickMaths_license);
     puts("");
}
