/*
 * function: GURU2_MAIN_TickTimeout
 * address:  0x021E161C
 * packet:   pkt_021E161C
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10636.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int GURU2_MAIN_TickTimeout(char *p)
{
    int n = ((struct Obj10636 *)p)->f8 + 1;

    ((struct Obj10636 *)p)->f8 = n;
    if (n < 0x258)
        return 0;
    ((struct Obj10636 *)p)->f8 = 0x258;
    return 1;
}
