/*
 * function: func_021F3970
 * address:  0x021F3970
 * packet:   pkt_ov044_021F3970
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0201210C(void *a);
extern void *func_02188D2C(u32 a);
extern int *func_021897BC(u32 a, int b);
extern u32 func_02188C58(u32 a);
extern int func_0218EC5C(u32 a);
extern void func_0218EC54(u32 a);
extern int *func_021BE480(void *p, int i, int j);
extern void *func_02188CB4(unsigned char *p);
extern void func_021A3038(u32 a, int *v);
extern void func_021A3044(u32 a, int *v);

void func_021F3970(void *a)
{
    void *s;
    void *r;
    int *p;
    u32 h;
    void *c;
    int v[3];

    s = func_0201210C((void *)a);
    r = func_02188D2C(s);
    p = func_021897BC(s, 1);
    h = func_02188C58(s);
    p[3] = func_0218EC5C(h);
    func_0218EC54(h);
    func_021BE480(r, 0, 0)[1] = -0x50000;
    c = func_02188CB4((void *)s);
    func_021A3038(c, v);
    v[1] = -0x50000;
    func_021A3044(c, v);
}
