/*
 * function: func_021909BC
 * address:  0x021909BC
 * packet:   pkt_021909BC
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
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201F868(u32);
extern u32 func_0202020C(u32, u32, u32);
extern u32 func_020307B0(u32);
extern u32 func_02190538(u32);
extern u32 func_02193130(u32);

int func_021909BC(u32 a)
{
func_0202020C(*(u32 *)((u8 *)(a) + 16), 0, 0);
func_0201F868(*(u32 *)((u8 *)(a) + 12));
func_02193130(*(u32 *)((u8 *)(a) + 8));
func_02190538(*(u32 *)((u8 *)(a) + 4));
return func_020307B0(a);
}

