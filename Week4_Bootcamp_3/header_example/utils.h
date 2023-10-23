// Contains foward decleration of function
// Header file does not contain function itself, it refers to implementation file where it is defined

#ifndef UTILS_H // GUARD
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>

FILE *open_file(char filename[], char mode[]);

// GUARD
#endif /* UTILS_H */

// to use the above in other files do this: #include "utils.h"