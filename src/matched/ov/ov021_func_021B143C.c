/*
 * function: func_021B143C
 * address:  0x021B143C
 * packet:   pkt_ov021_021B143C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B143C  0x021B143C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_021B162C  0x021B162C  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0219270C  0x0219270C  thumb  ov021
 *   func_0219272C  0x0219272C  thumb  ov021
 *   func_02192570  0x02192570  thumb  ov021
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_0219269C  0x0219269C  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_021B1424  0x021B1424  thumb
 *   func_02159144  0x02159144  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void *func_0215A5F4(void *p);
struct Stream;
extern u16 func_02011330(struct Stream *s);
typedef unsigned int   u32;
struct Q;
struct T;
extern u32 func_021B162C(u32 a, u32 b, u32 c);
extern int func_02158F58(int a0);
extern u32 func_0219270C(struct Q *q, int a, int n);
extern u32 func_0219272C(u16 *a, u32 b, u32 c);
extern u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
extern void func_0215A614(u8 *p, u32 v);
extern void func_0219269C(struct T *t, u16 b, u16 c, u32 d);
extern void func_020113D0(char *p, int val);
extern void func_02159144(int);
extern int func_021B1424(int, int, int, int);

int func_021B143C(void *a, int b)
{
    void *o;
    int s0, k, n;
    u8 s1, s2;
    int *q;
    u16 h0, h1;
    u8 *p;
    u8 **pp =(u8 **)((char *)a + 0x14);
    o = func_0215A5F4((void *)b);
    s0 = func_02011330(a);
    s1 = **pp;
    (*pp)++;
    s2 = **pp;
    (*pp)++;
    k = func_02011330(a);
    n = func_021B162C(b, (u32)o, s0);
    q = (int *)func_02158F58((int)o);
    h0 = func_0219270C((struct Q *)(*q), n, 4);
    h1 = func_0219272C((u16 *)(*q), n, 4);
    {
        int m = (int)func_02192570((u16 *)(*q), k, s1, s2, h0, h1);
        func_0215A614((u8 *)b, m);
        func_0219269C((struct T *)m, 4, 4, n);
    }
    func_020113D0(a, (int)func_021B1424);
    func_02159144(6);
    return 1;
}
