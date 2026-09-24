/*
 * function: func_021CCCC4
 * address:  0x021CCCC4
 * packet:   pkt_021CCCC4
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
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0204A8D4(u32, u32, u32, u32);
extern u32 func_0204ADA4(u32);
extern u32 func_0204AFD8(u32);

int func_021CCCC4(u32 a, u32 b, u32 c, u32 d)
{
func_0204A8D4(*(u16 *)((u8 *)((a + 156))), b, c, d);
func_0204AFD8(*(u16 *)((u8 *)((a + 154))));
return func_0204ADA4(*(u16 *)((u8 *)((a + 152))));
}

