/*
 * function: func_021BE10C
 * address:  0x021BE10C
 * packet:   pkt_021BE10C
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10870.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021BE10C(char *p, int b, int *c)
{
    ((struct Obj10870 *)p)->f1C = *c;
    ((struct Obj10870 *)p)->fA0 = 0;
    return 1;
}
