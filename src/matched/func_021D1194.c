/*
 * function: func_021D1194
 * address:  0x021D1194
 * packet:   pkt_021D1194
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
 *   func_021D11D8  0x021D11D8  thumb  ov021
 *   func_021D13F0  0x021D13F0  thumb  ov021
 *   func_021D1254  0x021D1254  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_021D11D8(u32, u32, u32, u32);
extern u32 func_021D1254(u32);
extern u32 func_021D13F0(u32);

int func_021D1194(u32 a, u32 b, u32 c, u32 d)
{
func_021D11D8(a, b, c, d);
func_021D13F0(a);
func_021D1254(a);
return func_020307B0(a);
}

