/*
 * function: func_0217B054
 * address:  0x0217B054
 * packet:   pkt_ov019_0217B054
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0217AFB0  0x0217AFB0  thumb  ov019
 *   func_02188CE0  0x02188CE0  thumb  ov021
 *   func_0217F958  0x0217F958  thumb  ov019
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 */

extern void *func_0201210C(void *p);
extern void *func_0217AFB0(void *, int, void *);
extern void *func_02188CE0(void *);
extern void func_0217F958(void *, void *);
extern void func_0216CF2C(void *);
extern void MI_CpuFill8(void *p, int v, int n);

void func_0217B054(void **a, int b, void *c)
{
    void *h;
    void *r;

    h = func_0201210C(((void **)a[0])[3]);
    r = func_0217AFB0(a, b, c);
    if (h != 0 && r != 0)
        func_0217F958(func_02188CE0(h), r);
    func_0216CF2C(r);
    MI_CpuFill8(c, 0, 12);
}
