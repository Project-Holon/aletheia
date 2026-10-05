/*
 * function: func_021A73C0
 * address:  0x021A73C0
 * packet:   pkt_021A73C0
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
 *   func_021A7620  0x021A7620  thumb  ov021
 *   func_021A7484  0x021A7484  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_021A7484(u32);
extern u32 func_021A7620(u32, u32, u32, u32);

int func_021A73C0(u32 a, u32 b, u32 c, u32 d)
{
func_021A7620((a + 24), b, c, d);
func_021A7484((a + 8));
return func_020307B0(a);
}

