/*
 * function: func_021D1884
 * address:  0x021D1884
 * packet:   pkt_021D1884
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0x188.
 *
 * symbols:
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BBA1C(u32 v);

void func_021D1884(u8 *p)
{
    func_021BBA1C(*(u32 *)(p + 0x188));
}
