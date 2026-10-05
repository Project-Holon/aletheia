/*
 * function: func_021CCFE4
 * address:  0x021CCFE4
 * packet:   pkt_021CCFE4
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
 *   func_02190E74  0x02190E74  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02190E74(u32, u32, u32, u32);

int func_021CCFE4(u32 a, u32 b, u32 c)
{
return func_02190E74(*(u32 *)((u8 *)((a + 176))), 0, 0, b);
}

