/*
 * function: func_021ABDE8
 * address:  0x021ABDE8
 * packet:   pkt_021ABDE8
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
 *   func_021ABFC0  0x021ABFC0  thumb  ov021
 *   func_021ABEE8  0x021ABEE8  thumb  ov021
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_02049238(u32);
extern u32 func_021ABEE8(u32);
extern u32 func_021ABFC0(u32, u32, u32, u32);

int func_021ABDE8(u32 a, u32 b, u32 c, u32 d)
{
func_021ABFC0(a, b, c, d);
func_021ABEE8(a);
func_02049238(*(u32 *)((u8 *)(a) + 12));
return func_020307B0(a);
}

