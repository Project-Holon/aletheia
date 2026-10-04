/*
 * function: func_021BB240
 * address:  0x021BB240
 * packet:   pkt_021BB240
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
 *   func_021BB0A4  0x021BB0A4  thumb  ov021
 *   func_021B791C  0x021B791C  thumb  ov021
 *   func_0219EF6C  0x0219EF6C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern void func_0219EF6C(u8 *p);
extern void func_021B791C(void **o);
extern u32 func_021BB0A4(u32, u32, u32, u32);

int func_021BB240(u32 a, u32 b, u32 c, u32 d)
{
func_021BB0A4(*(u32 *)((u8 *)(a) + 8), b, c, d);
func_021B791C((void **)(*(u32 *)((u8 *)(a))));
func_0219EF6C((u8 *)(*(u32 *)((u8 *)(a) + 4)));
return func_020307B0(a);
}

