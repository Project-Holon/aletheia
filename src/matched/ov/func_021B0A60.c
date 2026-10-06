/*
 * function: func_021B0A60
 * address:  0x021B0A60
 * packet:   pkt_021B0A60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A614 (0x0215A614) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_0215A614  0x0215A614  thumb
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02159168(int n);
extern u32 func_0215A614(u32, u32);
extern int func_0215A61C(int a0);
extern u32 func_021912F8(u32);

int func_021B0A60(u32 a, u32 b, u32 c, u32 d)
{
if (func_021912F8(func_0215A61C(b)) == 1) {
    func_0215A614(b, 0);
    func_02159168(2);
    return 1;
}
return 0;
}

