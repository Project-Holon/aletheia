/*
 * function: func_021BF080
 * address:  0x021BF080
 * packet:   pkt_021BF080
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14620.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021BF080(char *p, u8 i)
{
    char *q;

    *(int *)(p + i * 4 + 0x20) = 0;
    q = p + i * 0xC;
    ((struct Obj14620 *)q)->f40 = 0;
    ((struct Obj14620 *)q)->f44 = 0;
}
