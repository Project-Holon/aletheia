/*
 * function: func_021C1094
 * address:  0x021C1094
 * packet:   pkt_021C1094
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
 *   func_02030EE8  0x02030EE8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02030EE8(u32, u32, u32, u32);

int func_021C1094(u32 a, u32 b, u32 c, u32 d)
{
return *(u16 *)((u8 *)(func_02030EE8(a, b, c, d)) + 4);
}

