/*
 * function: func_021DCE40
 * address:  0x021DCE40
 * packet:   pkt_021DCE40
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
 * Two-word setter: stores the caller's word at +4 and hard-codes 2 at +0x1c.
 */
#include "../include/Obj14351.h"

typedef unsigned long u32;

void func_021DCE40(char *ctx, u32 v, int line)
{
    ((struct Obj14351 *)ctx)->f4 = v;
    ((struct Obj14351 *)ctx)->f1C = 2;
}
