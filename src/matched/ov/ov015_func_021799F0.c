/*
 * function: func_021799F0
 * address:  0x021799F0
 * packet:   pkt_ov015_021799F0
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf getter: returns the byte at +0xC of d_0217AB80.  Its
 * unlabelled followers at 021799FC, 02179A08 and 02179A18 (two more
 * getters and a predicate over the same block) make the extent run long.
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015  a1
 */

#include "../include/G_State.h"

extern struct State d_0217AB80;

unsigned char func_021799F0(void)
{
    return ((unsigned char *)&d_0217AB80)[0xc];
}
