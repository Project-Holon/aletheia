/*
 * function: func_021B7A14
 * address:  0x021B7A14
 * packet:   pkt_ov071_021B7A14
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02034714  0x02034714  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_02040588  0x02040588  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   d_021BABF4     0x021BABF4  data  a1
 */

typedef unsigned int u32;

extern void *func_02045770(void *p);
extern void func_02034714(void *a, int b, void *c);
extern void func_0201CE48(void *a);
extern void func_02045808(void *a);
extern void func_02040588(int a, int b);
extern void func_02043B5C(void *p, u32 v);
extern void func_02045334(void *p);
extern void func_0201DD78(u32, u32, u32);
extern char d_021BABF4[];

void func_021B7A14(void **p)
{
    void *h;

    h = func_02045770(p[0]);
    if (p[2] == 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201CE48(p[2]);
    p[2] = 0;
    func_02045808(p[1]);
    p[1] = 0;
    func_02040588(5, 0);
    func_02043B5C(h, 0xff);
    func_02045334(p[0]);
    func_0201DD78(15, 2, 0);
}
