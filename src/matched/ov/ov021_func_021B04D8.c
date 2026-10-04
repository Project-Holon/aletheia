/*
 * function: func_021B04D8
 * address:  0x021B04D8
 * packet:   pkt_ov021_021B04D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_021B03E4  0x021B03E4  thumb  ov021
 *   func_021B162C  0x021B162C  thumb  ov021
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191084  0x02191084  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_021B04C0  0x021B04C0  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *, void *);
typedef unsigned short u16;
struct P;
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern void func_021B03E4(u32, u32);
extern u32 func_021B162C(u32 a, u32 b, u32 c);
extern int func_0215A61C(int a0);
extern void func_02191084(struct P *p, u32 b, u16 c, u32 d);
extern void func_020113D0(char *p, int val);
extern int func_021B04C0(u32 a, u32 b, u32 c, u32 d);

int func_021B04D8(u32 a, u32 b)
{
    u32 x, y;
    void *t;

    t = func_0215A5F4((void *)b);
    x = func_02159B10((void *)a, (void *)b);
    func_021B03E4(b, (u8)func_02011330((struct Stream *)a));
    y = func_021B162C(b, (u32)t, x);
    func_02191084((struct P *)func_0215A61C(b), 0, 0, y);
    func_020113D0((char *)a, (u32)func_021B04C0);
    return 1;
}
