/*
 * function: func_021A2DE4
 * address:  0x021A2DE4
 * packet:   pkt_021A2DE4
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
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02188CA4(u32, u32, u32, u32);

int func_021A2DE4(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0(func_02188CA4(a, b, c, d));
}

