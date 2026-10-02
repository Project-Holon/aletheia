/*
 * function: func_021C8170
 * address:  0x021C8170
 * packet:   pkt_ov021_021C8170
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
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern int func_0215A5DC(int b);
extern int func_0201210C(int a);
extern int func_02189A00(int a);
extern int func_02159B10(int a, int b);
extern int func_0215A5F4(int b);
extern int func_021C1D68(int a, int b, int c);
extern void func_0215897C(int a, int b);

int func_021C8170(int a, int b)
{
    int r6, r7, r5, r4, v;

    r6 = func_0215A5DC(b);
    r7 = func_02189A00(func_0201210C(r6));
    r5 = func_02159B10(a, b);
    r4 = func_0215A5F4(b);
    v = func_021C1D68(r6, r7, (unsigned char)r5);
    if (v) {
        func_0215897C(r4, v);
    }
    return 1;
}
