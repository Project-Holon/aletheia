/*
 * function: func_021A02F4
 * address:  0x021A02F4
 * packet:   pkt_021A02F4
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
 *   func_02049238  0x02049238  arm
 *   func_021A0358  0x021A0358  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02049238(u32, u32, u32, u32);
extern u32 func_021A0358(u32);

int func_021A02F4(u32 a, u32 b, u32 c, u32 d)
{
func_02049238(*(u32 *)((u8 *)(a) + 12), b, c, d);
func_021A0358(a);
return func_020307B0(a);
}

