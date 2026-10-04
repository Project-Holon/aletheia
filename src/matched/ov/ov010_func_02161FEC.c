/*
 * function: func_02161FEC
 * address:  0x02161FEC
 * packet:   pkt_ov010_02161FEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, four bytes: strh r1, [r0, #4]; bx lr.
 */
#include "../include/Obj18948.h"

typedef unsigned short u16;

void func_02161FEC(char *p, u16 v)
{
    ((struct Obj18948 *)p)->f4 = v;
}
