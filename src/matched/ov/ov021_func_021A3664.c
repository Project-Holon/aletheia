/*
 * function: func_021A3664
 * address:  0x021A3664
 * packet:   pkt_ov021_021A3664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A5880  0x021A5880  thumb  ov021
 */

typedef unsigned int u32;

u32 func_021A5880(u32 x, u32 heap);

void func_021A3664(u32 *p, u32 heap)
{
    p[3] = func_021A5880(p[1], heap);
}
