/*
 * function: func_021BCF6C
 * address:  0x021BCF6C
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD11C 0x021BD11C  thumb  ov208

 * BLOCKED.  Unverifiable: func_021BD11C resolves only through the `matched` class and layout/matched/ov093 holds func_021B911C in two shards, which aborts every manifest load.
 */
#include "../include/Obj04613.h"


extern void func_021BD11C(int *p);

void func_021BCF6C(char *p)
{
    if (((struct Obj04613 *)p)->f10 != 0) {
        func_021BD11C((int *)(p + 8));
        ((struct Obj04613 *)p)->f10 = 0;
    }
}

