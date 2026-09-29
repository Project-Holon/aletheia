/*
 * function: func_021D2EDC
 * address:  0x021D2EDC
 * packet:   pkt_ov021_021D2EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021F3CFC  0x021F3CFC  thumb  ov059
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern void func_0201210C(void);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_0215A5EC(u32 a);
extern u32 func_0216DE94(u32 a, u32 b);
extern void func_0216D88C(u32 a, int *v);
extern u32 func_021F3CFC(u32 a, int *v, u32 b, u32 c);
extern void func_0215897C(u32 a, u32 b);

u32 func_021D2EDC(u32 a, u32 b)
{
    int v[3];
    u32 r7;
    u32 s0;
    u32 r6;
    u32 r5;
    u32 r;

    r7 = func_0215A5F4(b);
    s0 = func_0215A5DC(b);
    func_0201210C();
    r6 = func_02159B10(a, b);
    r5 = func_02159B10(a, b);
    func_0216D88C(func_0216DE94(func_0215A5EC(b), r6), v);
    r = func_021F3CFC(s0, v, r6, r5);
    if (r == 0) {
        return 1;
    }
    func_0215897C(r7, r);
    return 1;
}
