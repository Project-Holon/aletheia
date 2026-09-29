/*
 * function: func_021A3220
 * address:  0x021A3220
 * packet:   pkt_ov021_021A3220
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the second argument passing through in r1.
 * symbols:
 *   func_021A3938  0x021A3938  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021A3938();

void func_021A3220(u8 *p)
{
    func_021A3938(*(u32 *)(p + 0x4));
}
