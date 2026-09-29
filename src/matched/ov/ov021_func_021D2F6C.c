/*
 * function: func_021D2F6C
 * address:  0x021D2F6C
 * packet:   pkt_ov021_021D2F6C
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
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021F3970  0x021F3970  thumb  ov064
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_0201210C(void);
extern int func_02159B10(u32 a, u32 b);
extern u32 func_02188C7C(u32 a);
extern u32 func_0216DE94(u32 a, int b);
extern void func_0216D88C(u32 a, int *v);
extern u32 func_021F3970(u32 a, int *v, int *w, int c, int d);
extern void func_0215897C(u32 a, u32 b);

u32 func_021D2F6C(u32 a, u32 b)
{
    int v[3];
    int w[3];
    u32 s10;
    u32 sc;
    u32 s14;
    int s18;
    int s8;
    int s4;
    int r7;
    int r6;
    int r4;
    u32 r;

    s10 = func_0215A5F4(b);
    sc = func_0215A5DC(b);
    s14 = func_0201210C();
    s18 = func_02159B10(a, b);
    s8 = func_02159B10(a, b);
    s4 = func_02159B10(a, b);
    r7 = func_02159B10(a, b);
    r6 = func_02159B10(a, b);
    r4 = func_02159B10(a, b);
    r = func_0216DE94(func_02188C7C(s14), s18);
    if (r != 0) {
        func_0216D88C(r, v);
    }
    w[0] = (s8 << 16) + 0x8000;
    w[1] = s4 << 15;
    w[2] = (r7 << 16) + 0x8000;
    r = func_021F3970(sc, v, w, r6 << 15, r4);
    if (r == 0) {
        return 1;
    }
    func_0215897C(s10, r);
    return 1;
}
