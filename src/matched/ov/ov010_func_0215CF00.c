/*
 * function: func_0215CF00
 * address:  0x0215CF00
 * packet:   pkt_ov010_0215CF00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_0215D2A4  0x0215D2A4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *);
extern u32 func_02159AE8(void *, void *);
extern void *func_0215A5E4(void *);
extern void *func_0215A5DC(void *);
extern void *func_0201210C(void *);
extern void func_02012934(void *);
extern void func_02012EBC(void *);
extern void func_0200BDB0(void);
extern void *func_0215D2A4(void *, void *, u32);
extern void func_0215897C(void *, void *);

int func_0215CF00(void *a, void *b)
{
    void *t = func_0215A5F4(b);
    u32 v = func_02159AE8(a, b);
    void *p = func_0215A5E4(b);
    void *h = func_0215A5DC(b);
    void *s = func_0201210C(h);
    func_02012934(p);
    func_02012EBC(p);
    func_0200BDB0();
    func_0215897C(t, func_0215D2A4(h, s, v));
    return 1;
}
