/*
 * function: func_021B5128
 * address:  0x021B5128
 * packet:   pkt_ov021_021B5128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAB48  0x021AAB48  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5DC(u32);
extern u32 func_0201210C(u32);
extern u16 *func_02159AE8(u32, u32);
extern u32 func_02188CE8(u32);
extern u16 func_021AAB48(u32);

int func_021B5128(u32 a, u32 b)
{
    u32 w = func_0201210C(func_0215A5DC(b));
    u16 *o = func_02159AE8(a, b);

    *o = func_021AAB48(func_02188CE8(w));
    return 0;
}
