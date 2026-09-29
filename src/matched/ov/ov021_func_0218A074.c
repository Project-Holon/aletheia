/*
 * function: func_0218A074
 * address:  0x0218A074
 * packet:   pkt_ov021_0218A074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA8F8  0x021AA8F8  thumb  ov021
 *   func_02189BD0  0x02189BD0  thumb  ov021
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3550  0x021A3550  thumb  ov021
 *   func_021A356C  0x021A356C  thumb  ov021
 *   func_02189A70  0x02189A70  thumb  ov021
 *   func_021F3B10  0x021F3B10  thumb  ov053
 *   func_0218A6E8  0x0218A6E8  thumb  ov021
 */

extern void *func_0201210C(void *p);
extern void *func_02188CE8(void *p);
extern void func_021AA8F8(void);
extern int func_02189BD0(void *a, int b, int *c, int *d);
extern void func_021AA8EC(void *p);
extern void *func_02188D20(void *p);
extern int func_021BC5BC(void *p);
extern void *func_02188CB4(void *p);
extern void func_021A3550(void *p, int v);
extern void func_021A356C(void *p);
extern int func_02189A70(void *p);
extern void func_021F3B10(void);
extern void func_0218A6E8(void *a, void *b);

int func_0218A074(void *a, int b)
{
    int u;
    int v;
    int r;
    void *p;
    void *q;

    p = func_0201210C(a);
    q = func_02188CE8(p);
    func_021AA8F8();
    r = func_02189BD0(a, b, &u, &v);
    if (r != 0) {
        if (u != 0)
            func_021AA8EC(q);
        func_021BC5BC(func_02188D20(p));
        func_021A3550(func_02188CB4(p), v);
        func_021A356C(func_02188CB4(p));
        if (func_02189A70(p) != 0)
            func_021F3B10();
        func_0218A6E8(a, p);
    }
    return r;
}
