/*
 * function: func_021BDAE8
 * address:  0x021BDAE8
 * packet:   pkt_021BDAE8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD358 0x021BD358  thumb  ov208

 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
#include "../include/Obj02345.h"


extern void func_021BD358(char *, int);

void func_021BDAE8(char *p, int v)
{
    ((struct Obj02345 *)p)->f20 = v;
    if (((struct Obj02345 *)p)->f8 != 0) {
        ((struct Obj02345 *)p)->f8 = 3;
        p[0x24] = 0;
        func_021BD358(*(char * *)&((struct Obj02345 *)p)->f30, 0);
    }
}

