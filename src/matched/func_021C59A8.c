/*
 * function: func_021C59A8
 * address:  0x021C59A8
 * packet:   pkt_021C59A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201F868(u32);
extern u32 func_0202020C(u32, u32, u32, u32);

int func_021C59A8(u32 a, u32 b, u32 c, u32 d)
{
func_0202020C(*(u32 *)((u8 *)(a) + 4), b, c, d);
return func_0201F868(*(u32 *)((u8 *)(a)));
}

