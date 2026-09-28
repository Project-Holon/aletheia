/*
 * function: func_021C0360
 * address:  0x021C0360
 * packet:   pkt_021C0360
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
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0218FE98(u32);
extern u32 func_0218FF20(u32, u32, u32, u32);

int func_021C0360(u32 a, u32 b, u32 c, u32 d)
{
func_0218FF20(*(u32 *)((u8 *)(a) + 112), b, c, d);
return func_0218FE98(*(u32 *)((u8 *)(a) + 112));
}

