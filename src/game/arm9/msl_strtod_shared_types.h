#ifndef MSL_STRTOD_SHARED_TYPES_H
#define MSL_STRTOD_SHARED_TYPES_H

typedef struct decimal2 {
    unsigned char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal2;

enum { dec_start = 1, check_for_zero = 2, leading_zero = 4, need_digit = 8,
       digit_loop = 16, dec_finished = 32, dec_failure = 64 };

#endif
