/*
 * function: func_021A56F4
 * address:  0x021A56F4
 * packet:   pkt_021A56F4
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
 *   func_021A5378  0x021A5378  thumb  ov021
 *   func_021A39AC  0x021A39AC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A39AC(u32, u32);
extern u32 func_021A5378(u32, u32, u32, u32);

int func_021A56F4(u32 a, u32 b, u32 c, u32 d)
{
func_021A5378(a, 1, c, d);
return func_021A39AC(*(u32 *)((u8 *)(a) + 12), 7);
}

