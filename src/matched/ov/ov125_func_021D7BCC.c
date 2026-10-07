/*
 * function: func_021D7BCC
 * address:  0x021D7BCC
 * packet:   pkt_021D7BCC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves.
 *
 * symbols:
 *   d_021D9E40  0x021D9E40  data  a4
 *
 * Addresses are Black-image addresses.
 */

#include "../include/G_Clear.h"

extern struct Clear d_021D9E40;

unsigned int func_021D7BCC(void)
{
    return ((unsigned int *)&d_021D9E40)[0x4f];
}
