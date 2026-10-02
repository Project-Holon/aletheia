/*
 * function: func_021A35E0
 * address:  0x021A35E0
 * packet:   pkt_ov021_021A35E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A4140  0x021A4140  thumb  ov021
 */

typedef unsigned int u32;

u32 func_021A4140(u32 x, u32 heap);

void func_021A35E0(u32 *p, u32 heap)
{
    p[2] = func_021A4140(p[1], heap);
}
