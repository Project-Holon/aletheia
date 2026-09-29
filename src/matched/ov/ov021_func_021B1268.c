/*
 * function: func_021B1268
 * address:  0x021B1268
 * packet:   pkt_ov021_021B1268
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1268  0x021B1268  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191B14  0x02191B14  thumb  ov021
 *   func_02158F84  0x02158F84  thumb  ov010
 *   func_02158F80  0x02158F80  thumb  ov010
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 */

extern void *func_0215A5F4(void *);
extern int func_02159190(int);
extern int func_0215A61C(void *);
extern void func_02191B14(void);
extern void *func_02158F84(void *);
extern void func_02158F80(void *, int);
extern void func_0201D83C(void *);
extern void func_0215A614(void *, int);
extern void func_02159168(int);

void func_021B1268(void *p)
{
    void *q = func_0215A5F4(p);
    void *r;
    if (func_02159190(4) != 0) {
        func_0215A61C(p);
        func_02191B14();
        r = func_02158F84(q);
        func_02158F80(q, 0);
        if (r != 0) {
            func_0201D83C(r);
        }
        func_0215A614(p, 0);
        func_02159168(4);
    }
}
