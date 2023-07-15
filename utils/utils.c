#include <stdio.h>

#include "utils.h"

void utils_print_version(void)
{
    printf("utils v%d.%d.%d-%s\n", UTILS_VERSION_MAJOR, UTILS_VERSION_MINOR, UTILS_VERSION_PATCH, UTILS_VERSION_EXTRA);
}
