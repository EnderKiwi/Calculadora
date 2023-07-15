/* maths.h - v0.0.1-alpha by EnderKiwi (Alex M.)
 ******************************************************************************
 * A collection of math functions
 ******************************************************************************
 * Created 2023-07-09 by EnderKiwi.
 */
#ifndef MATHS_H
#define MATHS_H

/// @brief Semantic versioning major version for the maths library.
#define MATHS_VERSION_MAJOR 0
/// @brief Semantic versioning minor version for the maths library.
#define MATHS_VERSION_MINOR 0
/// @brief Semantic versioning patch version for the maths library.
#define MATHS_VERSION_PATCH 1
/// @brief Semantic versioning extension/extra for the maths library.
#define MATHS_VERSION_EXTRA "alpha"
/// @brief Build number for the version.
#define MATHS_VERSION_BUILD 5

int end_add(int a, int b);
int end_sub(int a, int b);
int end_mul(int a, int b);
int end_div(int a, int b);
int end_mod(int a, int b);

#endif /* MATHS_H */
