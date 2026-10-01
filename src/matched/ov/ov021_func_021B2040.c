/*
 * function: func_021B2040
 * address:  0x021B2040
 * packet:   pkt_ov021_021B2040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 *func_02158F58(u32);
extern u32 func_02188CB4(u32);
extern u16 *func_02159AE8(u32, u32);
extern u16 func_021A3238(u32);

int func_021B2040(u32 a, u32 b)
{
    u32 x = func_02188CB4(func_02158F58(func_0215A5F4(b))[1]);
    u16 *o = func_02159AE8(a, b);

    *o = func_021A3238(x);
    return 0;
}
