/*
 * function: func_021B54FC
 * address:  0x021B54FC
 * packet:   pkt_ov021_021B54FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021B55F0  0x021B55F0  thumb  ov021
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020122C0(void *a0, int a1, int (*cb)(void *), int a3);
extern void func_0215897C(void *vm, void *task);
extern int func_021B55F0(void *a);

int func_021B54FC(void *a, void *b)
{
    void *s = func_0215A5F4(b);
    void *d = func_0215A5DC(b);

    func_0215897C(s, func_020122C0(d, 0, func_021B55F0, 0));
    return 1;
}
