/*
 * function: func_021BDC14
 * address:  0x021BDC14
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD3A4 0x021BD3A4  thumb  ov208

 * Calls func_021BD3A4 with two fields and the second argument while +0x10 is clear.
 */
#include "../include/Obj02345.h"


extern void func_021BD3A4(int a, int b, int c);

void func_021BDC14(char *p, int b)
{
    if (((struct Obj02345 *)p)->f10 == 0)
        func_021BD3A4(*(int *)&((struct Obj02345 *)p)->f30, *(int *)*(int * *)&((struct Obj02345 *)p)->f7C, b);
}

