/*
 * function: func_021B17F8
 * address:  0x021B17F8
 * packet:   pkt_ov021_021B17F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021B1E74  0x021B1E74  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021B1E74(u32);
extern u16 *func_02159AE8(u32, u32);
extern u16 func_0216D5F8(u32);

int func_021B17F8(u32 a, u32 b)
{
    u32 x = func_021B1E74(b);
    u16 *o = func_02159AE8(a, b);

    *o = func_0216D5F8(x);
    return 0;
}
