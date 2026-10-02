/*
 * function: func_021F5324
 * address: 0x021F5324
 * packet: pkt_ov076_021F5324
 * region: ov076
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding.
 * symbols:
 *   func_021CF560 0x021CF560 thumb ov021
 *   func_0202E688 0x0202E688 thumb
 */
typedef unsigned int u32;
extern u32 func_021CF560(u32 *);
extern void func_0202E688(u32);
void func_021F5324(u32 *p) { func_0202E688(*(u32 *)(func_021CF560(p) + 0x28)); }
