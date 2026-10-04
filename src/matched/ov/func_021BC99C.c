/*
 * function: func_021BC99C
 * address:  0x021BC99C
 * packet:   pkt_021BC99C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Restarts the widget when its +5 counter has run out, otherwise counts it down.
 */
#include "../include/Obj07226.h"


typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);

void func_021BC99C(char *p)
{
    unsigned char c;

    c = ((struct Obj07226 *)p)->f5;
    if (c == 0) {
        func_02041EE4(((struct Obj07226 *)p)->f4, 1, 1);
        ((struct Obj07226 *)p)->f5 = 4;
    } else {
        ((struct Obj07226 *)p)->f5 = c - 1;
    }
}

