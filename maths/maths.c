#include <stdio.h>

#include "maths.h"

void maths_print_version(void)
{
    printf("maths v%d.%d.%d-%s\n", MATHS_VERSION_MAJOR, MATHS_VERSION_MINOR, MATHS_VERSION_PATCH, MATHS_VERSION_EXTRA);
}

int end_add(int a, int b)
{
     return a + b;
}

int end_sub(int a, int b)
{
     return a - b;
}

int end_mul(int a, int b)
{
     return a * b;
}

int end_div(int a, int b)
{
     // TODO: Check for division by zero
     return a / b;
}

int end_mod(int a, int b)
{
     return a % b;
}
