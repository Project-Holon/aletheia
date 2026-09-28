/*
 * function: func_021B919C
 * address:  0x021B919C
 * packet:   pkt_021B919C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object, a pass-through argument and the word at +0x78.
 *
 * symbols:
 *   func_021B9164  0x021B9164  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B9164(u8 *p, u32 a, u32 v);

void func_021B919C(u8 *p, u32 a)
{
    func_021B9164(p, a, *(u32 *)(p + 0x78));
}
