/*
 * function: func_021D13F0
 * address:  0x021D13F0
 * packet:   pkt_021D13F0
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
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020452E8(u32, u32, u32, u32);

int func_021D13F0(u32 a, u32 b, u32 c, u32 d)
{
func_020452E8(*(u32 *)((u8 *)(a) + 4), b, c, d);
*(u32 *)((u8 *)(a) + 4) = 0;
return 0;
}

