/*
 * function: func_021BA9FC
 * address:  0x021BA9FC
 * packet:   pkt_ov068_021BA9FC
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: stores a byte at +0x48, then redraws through
 * func_021BAA0C with the stored +0x54 flag.
 *
 * symbols:
 *   func_021BAA0C  0x021BAA0C  thumb  ov068
 */
#include "../include/Obj00103.h"

typedef unsigned char u8;

extern void func_021BAA0C(u8 *p, int flag);

void func_021BA9FC(u8 *p, u8 v)
{
    p[0x48] = v;
    func_021BAA0C(p, ((struct Obj00103 *)p)->f54);
}
