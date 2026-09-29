/*
 * function: func_0218A6E8
 * address:  0x0218A6E8
 * packet:   pkt_ov021_0218A6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A1358  0x021A1358  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_021F2AB8  0x021F2AB8  thumb  ov029
 *   func_021F2AD4  0x021F2AD4  thumb  ov029
 */

extern void func_02188CCC(void *p);
extern void *func_021A1358(void);
extern void *func_020120F4(void *p);
extern void *func_02012A30(void *p);
extern void func_02028A70(void *p);
extern int func_021F2AB8(void *p);
extern void func_021F2AD4(void *p);

void func_0218A6E8(void *sys, void *q)
{
    void *r;

    func_02188CCC(q);
    r = func_021A1358();
    if (r == 0) {
        func_02028A70(func_02012A30(func_020120F4(sys)));
        return;
    }
    if (func_021F2AB8(r) == 0) {
        func_02028A70(func_02012A30(func_020120F4(sys)));
        func_021F2AD4(r);
    }
}
