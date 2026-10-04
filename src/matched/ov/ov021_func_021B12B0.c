/*
 * function: func_021B12B0
 * address:  0x021B12B0
 * packet:   pkt_ov021_021B12B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B12B0  0x021B12B0  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02191A04  0x02191A04  thumb  ov021
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

extern void *func_0215A5F4(void *p);
typedef unsigned short u16;
struct Stream;
struct WordSet;
extern u16 func_02011330(struct Stream *s);
extern int func_02158F58(int a0);
extern int func_0215A60C(int);
extern int func_02191A04(int, int);
extern void func_0215A614(int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02158F78(u8 *p);
extern void *func_02158F74(void *p);
extern u32 func_02158F7C(u8 *p);
extern void func_02045CAC(int, int, int);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_020113D0(char *p, int val);
extern void func_02159144(int);
extern int func_021B1240(int, int);

int func_021B12B0(int a, int b)
{
    void *o;
    int s0, s1, s2;
    int *q;
    int x, y, z;
    o = func_0215A5F4((void *)b);
    s0 = func_02011330((struct Stream *)a);
    s1 = func_02011330((struct Stream *)a);
    q = (int *)func_02158F58((int)o);
    s2 = func_0215A60C(b);
    func_0215A614(b, func_02191A04(*q, s1));
    x = func_02158F78(o);
    y = (int)func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC(s2, s0, z);
    func_0201F250((struct WordSet *)y, (void *)x, (void *)z);
    func_020113D0((char *)a, (int)func_021B1240);
    func_02159144(4);
    return 1;
}
