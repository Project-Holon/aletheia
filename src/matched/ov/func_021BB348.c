/*
 * function: func_021BB348
 * address:  0x021BB348
 * packet:   pkt_021BB348
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
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021B7954  0x021B7954  thumb  ov021
 *   func_0219EFFC  0x0219EFFC  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021BB11C  0x021BB11C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0219EFFC(u32);
extern u32 func_021AB650(u32);
extern u32 func_021AB868(u32);
extern u32 func_021B7954(u32);
extern u32 func_021BB11C(u32);

int func_021BB348(u32 a)
{
func_021AB650(*(u32 *)((u8 *)(a) + 12));
func_021B7954(*(u32 *)((u8 *)(a)));
func_0219EFFC(*(u32 *)((u8 *)(a) + 4));
func_021AB868(*(u32 *)((u8 *)(a) + 16));
return func_021BB11C(*(u32 *)((u8 *)(a) + 8));
}

