/*
 * function: func_021AE4B4
 * address:  0x021AE4B4
 * packet:   pkt_021AE4B4
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
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D5E0(int a0, int a1);
extern u32 func_0216DA5C(u32, u32, u32, u32);
extern u32 func_0216DAF8(u32);

int func_021AE4B4(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DA5C(*(u32 *)((u8 *)(a) + 8), b, c, d) == 1) {
    return 0;
}
func_0216D5E0(*(u32 *)((u8 *)(a) + 8), ((*(u32 *)((u8 *)(a) + 16) << 16) >> 16));
func_0216DAF8(*(u32 *)((u8 *)(a) + 8));
*(u32 *)((u8 *)(a)) = 2;
return 1;
}

