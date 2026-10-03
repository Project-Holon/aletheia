/*
 * function: func_021892B4
 * address:  0x021892B4
 * packet:   pkt_021892B4
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
 *   func_0216D2AC  0x0216D2AC  thumb  ov010
 *   func_0216CD50  0x0216CD50  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216CD50(int a0);
extern u32 func_0216D2AC(u32, u32, u32, u32);

int func_021892B4(u32 a, u32 b, u32 c, u32 d)
{
func_0216D2AC(*(u32 *)((u8 *)(a) + 56), b, c, d);
func_0216CD50(*(u32 *)((u8 *)(a) + 56));
*(u32 *)((u8 *)(a) + 56) = 0;
return 0;
}

