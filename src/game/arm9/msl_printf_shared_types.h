#ifndef MSL_PRINTF_SHARED_TYPES_H
#define MSL_PRINTF_SHARED_TYPES_H

#include "../types.h"

typedef struct { char style; short digits; } decform;

typedef struct {
    unsigned char sgn;
    char unused;
    short exp;
    struct { unsigned char length; unsigned char text[34]; unsigned char unused; } sig;
} decimal;

#endif
