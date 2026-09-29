/*
 * function: func_021C46A4
 * address:  0x021C46A4
 * packet:   pkt_ov021_021C46A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D2418  0x021D2418  thumb  ov021
 *   func_021D2440  0x021D2440  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *
 * The shared func_0215897C call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills z instead of b.
 */

typedef unsigned int u32;

extern u32 func_0215A5DC(u32 a);
extern u32 func_0201210C(void);
extern u32 func_0215A5F4(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_021D2418(u32 a, u32 b);
extern u32 func_021D2440(u32 a, u32 b, u32 c);
extern void func_0215897C(u32 a, u32 b);

int func_021C46A4(u32 a, u32 b)
{
    u32 z, y, x, t;

    x = func_0215A5DC(b);
    y = func_0201210C();
    z = func_0215A5F4(b);
    t = func_02159B10(a, b);
    if (t == 0)
        func_0215897C(z, func_021D2418(x, y));
    else if (t == 1)
        func_0215897C(z, func_021D2440(x, y, 0));
    else
        func_0215897C(z, func_021D2440(x, y, 1));
    return 1;
}
