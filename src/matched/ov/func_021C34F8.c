/*
 * function: func_021C34F8
 * address:  0x021C34F8
 * packet:   pkt_021C34F8
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
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0200BC2C(u32, u32);
extern u32 func_0200BCA8(u32, u32, u32, u32);

int func_021C34F8(u32 a, u32 b, u32 c, u32 d)
{
func_0200BCA8(*(u32 *)((u8 *)(a) + 8), b, c, d);
return func_0200BC2C(*(u32 *)((u8 *)(a) + 8), b);
}

