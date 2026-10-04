/*
 * function: func_021BCF3C
 * address:  0x021BCF3C
 * packet:   pkt_021BCF2C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD140 0x021BD140  thumb  ov208

 * Calls func_021BD140 on +8 when the word at +0x10 is set.
 */
#include "../include/Obj18204.h"


extern void func_021BD140(char *);

void func_021BCF3C(char *p)
{
    if (((struct Obj18204 *)p)->f10 != 0)
        func_021BD140(p + 8);
}

