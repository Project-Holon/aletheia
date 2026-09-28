/*
 * function: func_021904B0
 * address:  0x021904B0
 * packet:   pkt_021904B0
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
 *   func_02045B38  0x02045B38  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02045B38(u32, u32, u32, u32);

int func_021904B0(u32 a, u32 b)
{
return func_02045B38(0, 2, ((b << 16) >> 16), *(u16 *)((u8 *)(a)));
}

