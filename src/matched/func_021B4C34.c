/*
 * function: func_021B4C34
 * address:  0x021B4C34
 * packet:   pkt_021B4C34
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201283C  0x0201283C  thumb
 *   func_02009A34  0x02009A34  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02009A34(u32);
extern u32 func_0201283C(u32);
extern u32 func_02159AE8(u32, u32, u32, u32);
extern u32 func_0215A5E4(u32);

int func_021B4C34(u32 a, u32 b, u32 c, u32 d)
{
*(u16 *)((u8 *)(func_02159AE8(a, b, c, d))) = func_02009A34(func_0201283C(func_0215A5E4(b)));
return 0;
}

