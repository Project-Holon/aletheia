/*
 * function: func_021AE498
 * address:  0x021AE498
 * packet:   pkt_021AE498
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
 *   func_0216DB04  0x0216DB04  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216DA5C(u32, u32, u32, u32);
extern void func_0216DB04(void *a0);

int func_021AE498(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DA5C(*(u32 *)((u8 *)(a) + 8), b, c, d) == 1) {
    func_0216DB04((void *)(*(u32 *)((u8 *)(a) + 8)));
}
*(u32 *)((u8 *)(a)) = 1;
return 1;
}

