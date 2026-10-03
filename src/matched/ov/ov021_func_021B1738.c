/*
 * function: func_021B1738
 * address:  0x021B1738
 * packet:   pkt_ov021_021B1738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 */

typedef unsigned int u32;

extern u32 func_0215A5EC(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_0216DE94(u32, u32);
extern int func_0216E0E8(int a0, int a1);

int func_021B1738(u32 a, u32 b)
{
    u32 t = func_0215A5EC(b);
    u32 x = func_02159B10(a, b);
    u32 y = func_02159B10(a, b);

    func_0216E0E8(func_0216DE94(t, x), y);
    return 0;
}
