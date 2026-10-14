/*
 * function: CircleGraph_InitFields
 * address:  0x021C1D7C
 * packet:   pkt_021C1D7C
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */
#include "../include/Obj02555.h"

void CircleGraph_InitFields(unsigned char *p, short a)
{
    ((struct Obj02555 *)p)->f0 = a;
    ((struct Obj02555 *)p)->f4 = 0;
    ((struct Obj02555 *)p)->f8 = 0;
    ((struct Obj02555 *)p)->fC = 0;
    ((struct Obj02555 *)p)->f14 = 0;
    ((struct Obj02555 *)p)->f18 = 0;
    ((struct Obj02555 *)p)->f1B0 = 0x7db;
    p[0x1ac] = 0;
    ((struct Obj02555 *)p)->f1B4 = -0xb2f;
    ((struct Obj02555 *)p)->f1B6 = -0xc9;
    ((struct Obj02555 *)p)->f1B8 = -0x1000;
}
