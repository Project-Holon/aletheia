/*
 * function: func_021C4628
 * address:  0x021C4628
 * packet:   pkt_ov021_021C4628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1228  0x021C1228  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C4608  0x021C4608  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5CC(u32 a);
extern void *func_0215A5DC(void *a0);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(unsigned char *p);
extern u16 func_021A3050(u8 *p);
extern u32 func_02159B10(void *a, void *b);
extern u32 func_021C1228(void *a, u32 b, u32 c, u32 d);
extern void func_0215A644(void *p, u32 v);
extern void func_020113D0(char *p, int val);
extern int func_021C4608(void *a, void *b);

u32 func_021C4628(u32 a, u32 b)
{
    u32 w, y, t;
    void *x;

    w = func_0215A5CC(b);
    x = func_02188CB4(func_0201210C(func_0215A5DC((void *)b)));
    y = func_021A3050(x);
    t = func_02159B10((void *)a, (void *)b);
    t = func_021C1228(x, y, t, w);
    func_0215A644((void *)b, t);
    func_020113D0((char *)a, (int)func_021C4608);
    return 1;
}
