/*
 * function: func_021BF374
 * address:  0x021BF374
 * packet:   pkt_021BF374
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14622.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int *func_021BF374(char *p, int v)
{
    ((struct Obj14622 *)p)->f30 = v;
    ((struct Obj14622 *)p)->f34 = 0;
    return (int *)(p + 0x30);
}
