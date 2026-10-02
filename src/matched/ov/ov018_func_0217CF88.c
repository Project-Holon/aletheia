/*
 * function: func_0217CF88
 * address:  0x0217CF88
 * packet:   pkt_ov018_0217CF88
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0217BBCC  0x0217BBCC  thumb  ov018
 *   func_0217BBD8  0x0217BBD8  thumb  ov018
 *   func_0217BC94  0x0217BC94  thumb  ov018
 *   func_0217C194  0x0217C194  thumb  ov018
 */

struct Ctx;

extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(void *p);
extern int func_02012138();
extern int func_02026454();
extern int func_02026474();
extern void func_0217BBCC();
extern void func_0217BBD8();
extern void func_0217BC94();
extern void func_0217C194();

int func_0217CF88(int a0, int a1)
{
    void *w;
    void *c;
    int h;
    int v;

    w = func_0215A5DC((void *)a1);
    func_020120F4((const struct Ctx *)w);
    c = func_0201210C((void *)w);
    h = func_02012138(w);
    v = 0;
    if (func_02026454(h) == 2)
        v = func_02026474(h);
    if (v != 0) {
        func_0217BBCC(c, w, v);
        func_0217BBD8(c, w, v);
    } else {
        func_0217BC94(c, 1);
    }
    func_0217C194(c);
    return 0;
}
