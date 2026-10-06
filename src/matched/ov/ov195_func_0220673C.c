/*
 * function: func_0220673C
 * address:  0x0220673C
 * packet:   pkt_0220673C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj08348.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_0220673C(int *p)
{
    int v = **(int * *)&((struct Obj08348 *)p)->f58;

    return v != 0 && v != 4;
}
