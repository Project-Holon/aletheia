/*
 * function: func_021C812C
 * address:  0x021C812C
 * packet:   pkt_ov021_021C812C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern int func_0215A5DC(int b);
extern int func_0201210C(int a);
extern int func_02189A00(int a);
extern int func_02011330(int a);
extern int func_0215A5F4(int b);
extern int func_021C1CB0(int a, int b, int c);
extern void func_0215897C(int a, int b);

int func_021C812C(int a, int b)
{
    int r5, r7, r4, r6, v;

    r5 = func_0215A5DC(b);
    r7 = func_02189A00(func_0201210C(r5));
    r4 = func_02011330(a);
    r6 = func_0215A5F4(b);
    v = func_021C1CB0(r5, r7, (unsigned char)r4);
    if (v) {
        func_0215897C(r6, v);
    }
    return 1;
}
