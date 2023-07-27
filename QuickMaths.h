/* QuickMaths.h - v0.0.6-alpha by EnderKiwi (Alex M.)
 ******************************************************************************
 * A simple calculator program. Currently for terminal only.
 * Made as a learning project for C.
 ******************************************************************************
 * Created 2023-07-09 by EnderKiwi.
 */
#ifndef QUICKMATHS_H
#define QUICKMATHS_H

/// @brief Semantic versioning major version for QuickMaths.
#define QUICKMATHS_VERSION_MAJOR 0
/// @brief Semantic versioning minor version for QuickMaths.
#define QUICKMATHS_VERSION_MINOR 0
/// @brief Semantic versioning patch version for QuickMaths.
#define QUICKMATHS_VERSION_PATCH 6
/// @brief Semantic versioning extension/extra for QuickMaths.
#define QUICKMATHS_VERSION_EXTRA "alpha"

void QuickMaths_print_version(void);
void QuickMaths_cmd_help(void);
void QuickMaths_cmd_ahelp(char *name); // Help but it takes the program name aka argv[0]
void QuickMaths_cmd_version(void);
void QuickMaths_cmd_license(void);

#endif /* QUICKMATHS_H */
