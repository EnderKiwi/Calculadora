#include <stdio.h>

#include "QuickMaths.h"
#include "license.h"
#include "maths/maths.h"
#include "utils/utils.h"

void QuickMaths_print_version(void)
{
    printf("QuickMaths v%d.%d.%d-%s\n", QUICKMATHS_VERSION_MAJOR, QUICKMATHS_VERSION_MINOR, QUICKMATHS_VERSION_PATCH, QUICKMATHS_VERSION_EXTRA);
}

void QuickMaths_cmd_help(void)
{
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
     QuickMaths_print_version();
     puts("Copyright (c) 2023 EnderKiwi");
}

void QuickMaths_cmd_ahelp(char *name)
{
     printf("USAGE: %s [OPTIONS] [EXPRESSION]\n", name);
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
