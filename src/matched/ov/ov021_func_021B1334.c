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

extern void *func_0215A5F4(void *p);
typedef unsigned short u16;
struct Stream;
struct WordSet;
extern int func_02158F58(int a0);
extern u16 func_02011330(struct Stream *s);
struct GfFont;
extern u16 func_02188C84(unsigned char *p);
extern unsigned int func_0215A60C(unsigned char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02158F80(u8 *p, u32 v);
struct MsgBank;
extern u32 *func_02191A10(u16 *a, u32 b, u32 c);
extern void func_0215A614(u8 *p, u32 v);
extern u32 func_02158F78(u8 *p);
extern void *func_02158F74(void *p);
extern u32 func_02158F7C(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_020113D0(char *p, int val);
extern void func_02159144(int);
extern int func_021B1240(int, int);

int func_021B1334(int a, unsigned char *b)
{
    void *o;
    int *q, *q2;
    int s0, s1, s2, h, m;
    int x, y, z;
    o = func_0215A5F4((void *)b);
    q = (int *)func_02158F58((int)o);
    s0 = func_02011330((struct Stream *)a);
    s1 = func_02011330((struct Stream *)a);
    h = func_02188C84((unsigned char *)q[1]);
    q2 = (int *)func_02158F58((int)o);
    s2 = func_0215A60C(b);
    m = (int)func_0201D7EC(0x17, 4, 0, 0, h);
    func_02158F80(o, m);
    func_0215A614((u8 *)b, (u32)func_02191A10((u16 *)(*q2), s1, m));
    x = func_02158F78(o);
    y = (int)func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC((struct MsgBank *)s2, s0, (void *)z);
    func_0201F250((struct WordSet *)y, (void *)x, (void *)z);
    func_020113D0((char *)a, (int)func_021B1240);
    func_02159144(4);
    return 1;
}
