/*
 * function: func_021B1334
 * address:  0x021B1334
 * packet:   pkt_ov021_021B1334
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1334  0x021B1334  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02158F80  0x02158F80  thumb  ov010
 *   func_02191A10  0x02191A10  thumb  ov021
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_021B1240  0x021B1240  thumb
 */

extern void *func_0215A5F4(int);
extern int *func_02158F58(void *);
extern int func_02011330(int);
extern int func_02188C84(int);
extern int func_0215A60C(int);
extern int func_0201D7EC(int, int, int, int, int);
extern void func_02158F80(void *, int);
extern int func_02191A10(int, int, int);
extern void func_0215A614(int, int);
extern int func_02158F78(void *);
extern int func_02158F74(void *);
extern int func_02158F7C(void *);
extern void func_02045CAC(int, int, int);
extern void func_0201F250(int, int, int);
extern void func_020113D0(int, int (*)(int, int));
extern void func_02159144(int);
extern int func_021B1240(int, int);

int func_021B1334(int a, int b)
{
    void *o;
    int *q, *q2;
    int s0, s1, s2, h, m;
    int x, y, z;
    o = func_0215A5F4(b);
    q = func_02158F58(o);
    s0 = func_02011330(a);
    s1 = func_02011330(a);
    h = func_02188C84(q[1]);
    q2 = func_02158F58(o);
    s2 = func_0215A60C(b);
    m = func_0201D7EC(0x17, 4, 0, 0, h);
    func_02158F80(o, m);
    func_0215A614(b, func_02191A10(*q2, s1, m));
    x = func_02158F78(o);
    y = func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC(s2, s0, z);
    func_0201F250(y, x, z);
    func_020113D0(a, func_021B1240);
    func_02159144(4);
    return 1;
}
