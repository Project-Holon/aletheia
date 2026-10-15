#ifndef MSL_WCHAR_SHARED_TYPES_H
#define MSL_WCHAR_SHARED_TYPES_H

#include "msl_crt_shared_types.h"
#include "msl_printf_shared_types.h"

typedef struct DB {
    u8  sign;
    u8  pad;
    s16 exp;
    u8  length;
    u8  digits[33];
} DB;

#endif
