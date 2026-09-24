/*
 * function: func_02191A04
 * address:  0x02191A04
 * packet:   pkt_02191A04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the object, a pass-through argument and the word at +8.
 *
 * symbols:
 *   func_02191A10  0x02191A10  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02191A10(u8 *p, u32 a, u32 v);

void func_02191A04(u8 *p, u32 a)
{
    func_02191A10(p, a, *(u32 *)(p + 8));
}
