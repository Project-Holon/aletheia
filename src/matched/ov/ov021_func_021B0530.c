/*
 * function: func_021B0530
 * address:  0x021B0530
 * packet:   pkt_ov021_021B0530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_021B03E4  0x021B03E4  thumb  ov021
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02191184  0x02191184  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *func_0215A5F4(void *p);
struct P;
extern u32 func_02158F78(u8 *p);
extern unsigned int func_02159B10(void *, void *);
typedef unsigned short u16;
struct MsgBank;
struct Q;
struct Stream;
struct WordSet;
extern u16 func_02011330(struct Stream *s);
extern void func_021B03E4(u32, u32);
extern u32 func_0215A60C(u8 *p);
extern void *func_02158F74(void *p);
extern u32 func_02158F7C(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_0215A61C(int a0);
extern void func_02191164(struct P *p);
extern void func_02191184(struct Q *q, u32 b, int c, u32 d);

int func_021B0530(u32 a, u32 b)
{
    u32 s, x, y, z, w;
    void *t;

    t = func_0215A5F4((void *)b);
    s = func_02158F78(t);
    x = func_02159B10((void *)a, (void *)b);
    func_021B03E4(b, (u8)func_02011330((struct Stream *)a));
    y = func_0215A60C((u8 *)b);
    z = (u32)func_02158F74(t);
    w = func_02158F7C(t);
    func_02045CAC((struct MsgBank *)y, x, (void *)w);
    func_0201F250((struct WordSet *)z, (void *)s, (void *)w);
    y = func_0215A61C(b);
    func_02191164((void *)y);
    func_02191184((struct Q *)y, 0, 0, s);
    return 0;
}
