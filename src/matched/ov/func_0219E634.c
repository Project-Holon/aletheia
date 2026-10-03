/*
 * function: func_0219E634
 * address:  0x0219E634
 * packet:   pkt_0219E634
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7E60  0x021B7E60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 func_0201441C(int i);
extern u32 func_0216D530(u32);
extern u32 func_0216D5F8(u32);
extern u32 func_0216D67C(u32, u32, u32, u32);
extern u32 func_0216D69C(u32);
extern u32 func_021B7E60(u32, u32, u32, u32);

int func_0219E634(u32 a, u32 b, u32 c, u32 d)
{
func_0216D530(func_0216D67C(a, b, c, d));
return func_021B7E60(*(u32 *)((u8 *)(func_0216D69C(a))), func_0201441C(func_0216D5F8(a)), b, 0);
}

