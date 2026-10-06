/*
 * function: func_021BCF2C
 * address:  0x021BCF2C
 * packet:   pkt_021BCF2C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD12C 0x021BD12C  thumb  ov208

 * Calls func_021BD12C on +8 when the word at +0x10 is set.
 */
#include "../include/Obj18203.h"


extern void func_021BD12C(int *p);

void func_021BCF2C(char *p)
{
    if (((struct Obj18203 *)p)->f10 != 0)
        func_021BD12C((int *)(p + 8));
}

