/*
 * function: func_021B1008
 * address:  0x021B1008
 * packet:   pkt_ov021_021B1008
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1008  0x021B1008  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B162C  0x021B162C  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_02159144  0x02159144  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021B0FF0  0x021B0FF0  thumb
 */

typedef unsigned char u8;

extern void *func_0215A5F4(void *p);
extern int *func_02158F58(void *);
extern int func_02159B10(void *, int);
extern int func_021B162C(int, void *, int);
extern int func_02159190(int);
extern int func_0215A61C(int);
extern void func_021915EC(int r);
extern int func_02191558(int, int, int, int, int, int, int);
extern void func_0215A614(int, int);
extern void func_021916A8(int, int, int, int);
extern void func_02159144(int);
extern void func_020113D0(void *, int (*)(int, int));
extern int func_021B0FF0(int, int);

int func_021B1008(void *a, int b, int c)
{
    void *o;
    int n, r, t, m;
    int *q;
    u8 *p;
    o = func_0215A5F4((void *)b);
    q = func_02158F58(o);
    t = func_02159B10(a, b);
    p = *(u8 **)((char *)a + 0x14);
    n = *p;
    *(u8 **)((char *)a + 0x14) = p + 1;
    r = 1;
    m = func_021B162C(b, o, t);
    if (n != 1) {
        r = 0x13;
    }
    if (func_02159190(3) != 0) {
        r = func_0215A61C(b);
        func_021915EC(r);
    } else {
        r = func_02191558(*q, 0, c, 1, r, 0x1e, 4);
        func_0215A614(b, r);
    }
    func_021916A8(r, 8, 0, m);
    func_02159144(3);
    func_020113D0(a, func_021B0FF0);
    return 1;
}
