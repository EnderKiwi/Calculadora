#include <stdio.h>
#include "Calculadora.h"
#include "util/util.h"
#include "math/math.h"

int main(int argc, char **argv)
{
     printf("Calculadora v%d.%d.%d-%s build %d\n",
            CALCULADORA_VERSION_MAJOR,
            CALCULADORA_VERSION_MINOR,
            CALCULADORA_VERSION_PATCH,
            CALCULADORA_VERSION_EXTRA,
            CALCULADORA_VERSION_BUILD);
     printf(": util v%d.%d.%d-%s build %d\n",
            UTIL_VERSION_MAJOR,
            UTIL_VERSION_MINOR,
            UTIL_VERSION_PATCH,
            UTIL_VERSION_EXTRA,
            UTIL_VERSION_BUILD);
     printf(": math v%d.%d.%d-%s build %d\n",
            MATH_VERSION_MAJOR,
            MATH_VERSION_MINOR,
            MATH_VERSION_PATCH,
            MATH_VERSION_EXTRA,
            MATH_VERSION_BUILD);

     return 0;
}
