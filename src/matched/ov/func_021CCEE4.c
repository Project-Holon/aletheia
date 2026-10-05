/*
 * function: func_021CCEE4
 * address:  0x021CCEE4
 * packet:   pkt_021CCEE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021904C8  0x021904C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201ED04(u32, u32, u32, u32);
extern u32 func_021904C8(u32);

int func_021CCEE4(u32 a, u32 b, u32 c, u32 d)
{
func_0201ED04(*(u32 *)((u8 *)((a + 160))), b, c, d);
return func_021904C8(*(u32 *)((u8 *)((a + 168))));
}

