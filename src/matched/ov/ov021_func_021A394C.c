/*
 * function: func_021A394C
 * address:  0x021A394C
 * packet:   pkt_ov021_021A394C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov021 func_021A322C (itself a blocker of
 * ov018 func_0217BCDC): tail call on the object's word at +0xC.
 * symbols:
 *   func_02012B30  0x02012B30  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02012B30(u32, int);

void func_021A394C(u8 *p)
{
    func_02012B30(*(u32 *)(p + 0xC), 0xFFFF);
}
