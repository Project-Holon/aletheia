/*
 * function: func_021D2124
 * address:  0x021D2124
 * packet:   pkt_021D2124
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
 *   func_021D201C  0x021D201C  thumb  ov021
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(u32);
extern int func_021D201C(u32 a, u32 b, u32 c, u32 d);

int func_021D2124(u32 a, u32 b, u32 c, u32 d)
{
func_021D201C(a, b, c, d);
func_0201F7A8((void *)(*(u32 *)((u8 *)(a) + 48)), 1);
return func_020452E8(*(u32 *)((u8 *)(a) + 48));
}

