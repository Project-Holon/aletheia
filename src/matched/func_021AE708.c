/*
 * function: func_021AE708
 * address:  0x021AE708
 * packet:   pkt_021AE708
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
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D480(u32, u32, u32, u32);
extern u32 func_0216E0E8(u32, u32);

int func_021AE708(u32 a, u32 b, u32 c, u32 d)
{
func_0216D480(*(u32 *)((u8 *)(a) + 8), b, c, d);
func_0216E0E8(*(u32 *)((u8 *)(a) + 8), 0);
*(u32 *)((u8 *)(a)) = 17;
return 1;
}

