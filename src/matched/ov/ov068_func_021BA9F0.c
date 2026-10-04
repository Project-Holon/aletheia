/*
 * function: func_021BA9F0
 * address:  0x021BA9F0
 * packet:   pkt_ov068_021BA9F0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub after func_021BA9E0: redraws through
 * func_021BAA0C with the stored +0x54 flag.  func_021BB1C4 passes a second
 * argument (0 or 1) in r1 that this body never reads.
 *
 * symbols:
 *   func_021BAA0C  0x021BAA0C  thumb  ov068
 */
#include "../include/Obj00103.h"

typedef unsigned char u8;

extern void func_021BAA0C(u8 *p, int flag);

void func_021BA9F0(u8 *p, int unused)
{
    func_021BAA0C(p, ((struct Obj00103 *)p)->f54);
}
