/*
 * function: func_021EC4E0
 * address:  0x021EC4E0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC48C  0x021EC48C  thumb  ov170
 *
 * Loop 0x1e entries forwarding (p[0x14], i, i+0x33).
 */
#include "../include/Obj18520.h"


extern void func_021EC48C(char *, int, unsigned, unsigned);
void func_021EC4E0(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1e; i++)
        func_021EC48C(p, ((struct Obj18520 *)p)->f14, i, i + 0x33);
}
