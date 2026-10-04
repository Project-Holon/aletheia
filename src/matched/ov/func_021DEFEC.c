/*
 * function: func_021DEFEC
 * address:  0x021DEFEC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEF98  0x021DEF98  thumb  ov170
 *
 * Forward with the byte field at +0x14.
 */
#include "../include/Obj18458.h"

extern int func_021DEF98(char *p, int a, unsigned b);

void func_021DEFEC(char *p, int b)
{
    func_021DEF98(p, ((struct Obj18458 *)p)->f14, b);
}

