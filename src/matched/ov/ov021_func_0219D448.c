/*
 * function: func_0219D448
 * address:  0x0219D448
 * packet:   pkt_ov021_0219D448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D524  0x0216D524  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0219D4AC  0x0219D4AC  thumb  ov021
 *   d_021DDD80     0x021DDD80  data ov021 a4
 */

extern int func_0216D4F8(int);
extern int func_0216D4F0(int);
extern void func_0216D524(int, void *);
extern void *func_02030734(int, int, int, void *, int);
extern void func_0219D4AC(int *obj, int a);
extern unsigned char d_021DDD80[];

void func_0219D448(int a, int b)
{
    int h;
    int *p;

    h = func_0216D4F8(a);
    p = (int *)func_02030734(h, 0x10, 1, d_021DDD80, 0x48);
    p[0] = a;
    p[1] = b;
    *(unsigned short *)(p + 2) = func_0216D4F0(a);
    func_0219D4AC(p, h);
    func_0216D524(a, p);
}
