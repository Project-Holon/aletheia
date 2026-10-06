/*
 * function: func_021C459C
 * address:  0x021C459C
 * packet:   pkt_ov021_021C459C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021C1024  0x021C1024  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C457C  0x021C457C  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
typedef unsigned short u16;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
typedef unsigned char  u8;
extern u32 func_02188C98(u8 *p);
extern u16 func_0215A5CC(void *a0);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB0D4(void *a, void *b);
extern u32 func_021C1024(void *a, u32 b, u32 c, u32 d);
extern void func_0215A644(void *p, u32 v);
extern void func_020113D0(char *p, int val);
extern int func_021C457C(void *a, void *b);

u32 func_021C459C(u32 a, u32 b)
{
    u32 buf[3];
    u32 z, w, t;
    void *x;
    void *y;

    x = func_0201210C(func_0215A5DC((void *)b));
    y = func_02188CB4((void *)x);
    z = func_0216D5F8(func_021A3074(y));
    x = (void *)func_02188C98(x);
    w = func_0215A5CC((void *)b);
    func_021A3364(y, z, (int *)buf);
    t = func_021AB0D4(x, buf);
    t = func_021C1024(y, z, t, w);
    func_0215A644((void *)b, t);
    func_020113D0((char *)a, (int)func_021C457C);
    return 1;
}
