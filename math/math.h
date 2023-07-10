/* math.h - v0.0.1-alpha by EnderKiwi (Alex M.)
 ******************************************************************************
 * A collection of math functions
 ******************************************************************************
 * Created 2023-07-09 by EnderKiwi.
 */
#ifndef MATH_H
#define MATH_H

/// @brief Semantic versioning major version for the math library.
#define MATH_VERSION_MAJOR 0
/// @brief Semantic versioning minor version for the math library.
#define MATH_VERSION_MINOR 0
/// @brief Semantic versioning patch version for the math library.
#define MATH_VERSION_PATCH 1
/// @brief Semantic versioning extension/extra for the math library.
#define MATH_VERSION_EXTRA "alpha"
/// @brief Build number for the version.
#define MATH_VERSION_BUILD 5

int end_add(int a, int b);
int end_sub(int a, int b);
int end_mul(int a, int b);
int end_div(int a, int b);
int end_mod(int a, int b);

#endif /* MATH_H */
