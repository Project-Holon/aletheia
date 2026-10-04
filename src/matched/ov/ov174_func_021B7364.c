/*
 * function: func_021B7364
 * address:  0x021B7364
 * packet:   pkt_021B7364
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10674.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021B7364(char *p, int v)
{
    if (((struct Obj10674 *)p)->f34 == 1 && v == 0)
        ((struct Obj10674 *)p)->f38 = 0x46;
    ((struct Obj10674 *)p)->f34 = v;
}
