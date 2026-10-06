/*
 * function: func_021DCE48
 * address:  0x021DCE48
 * packet:   pkt_021DCE48
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Two-word setter: stores the caller's word at +8 and hard-codes 2 at +0x1c.
 */
#include "../include/Obj14352.h"

typedef unsigned long u32;

void func_021DCE48(char *ctx, u32 v, int line)
{
    ((struct Obj14352 *)ctx)->f8 = v;
    ((struct Obj14352 *)ctx)->f1C = 2;
}
