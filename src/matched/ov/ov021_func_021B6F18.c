/*
 * function: func_021B6F18
 * address:  0x021B6F18
 * packet:   pkt_ov021_021B6F18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_021B6EE0  0x021B6EE0  thumb  ov021
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

extern void *func_02012934(void *p);
extern void *func_021B6EE0(int a, int b);
extern int func_0201AA18(void *p);
extern unsigned int func_0201A98C(void *l, void *m);
extern int func_0200CA1C(int p);
extern void func_0200CDE0(int a, void *m);
extern void func_020307B0(void *p);

void func_021B6F18(int a, int b, int c)
{
    void *l;
    void *m;

    l = func_02012934((void *)b);
    m = func_021B6EE0(a, c);
    if (func_0201AA18(l) < 6 && m != 0) {
        func_0201A98C(l, m);
        func_0200CDE0(func_0200CA1C(b), m);
        func_020307B0(m);
    }
}
