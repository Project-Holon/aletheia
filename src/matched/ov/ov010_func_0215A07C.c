/*
 * function: func_0215A07C
 * address:  0x0215A07C
 * packet:   pkt_ov010_0215A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02030734  0x02030734  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A214  0x0215A214  thumb  ov010
 *   d_021728CC  0x021728CC  data
 */

typedef unsigned int u32;

extern int func_020120F4(int);
extern int func_02012934(int);
extern u32 *func_02030734(int, int, int, const char *, int);
extern void *func_020122C0(int, int, void (*)(void), int);
extern u32 *func_020124E8(void *);
extern int func_0201210C(int);
extern void func_0215A214(void);
extern const char d_021728CC[];

void *func_0215A07C(int a, int b, int c)
{
    int h = func_02012934(func_020120F4(a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x40);
    void *r;
    u32 *q;
    p[0] = h;
    p[0x34 / 4] = 3;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    r = func_020122C0(a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = func_0201210C(a);
    q[2] = (u32)p;
    q[3] = 0;
    q[4] = b;
    q[5] = c;
    return r;
}
