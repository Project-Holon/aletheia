/*
 * function: func_021B53BC
 * address:  0x021B53BC
 * packet:   pkt_ov021_021B53BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0218F900  0x0218F900  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 pad0[3];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 pad18[3];
    u16 h24;
    u16 h26;
    u32 f28;
    u32 pad2c;
    u32 w30[6];
} Out;

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Stream;
extern void *func_02188C58(void *p);
extern u16 func_02011330(struct Stream *s);
extern u32 func_0201134C();
extern void func_0218F900();

int func_021B53BC(int a0, int a1)
{
    Out o;
    int r4;

    r4 = (int)func_02188C58(func_0201210C(func_0215A5DC((void *)a1)));
    o.h24 = func_02011330((struct Stream *)a0);
    o.h26 = func_02011330((struct Stream *)a0);
    o.f28 = func_0201134C(a0);
    o.f0c = func_0201134C(a0);
    o.f10 = func_0201134C(a0);
    o.f14 = func_0201134C(a0);
    o.w30[0] = 0;
    o.w30[1] = 1;
    o.w30[2] = 1;
    o.w30[3] = 1;
    o.w30[4] = 0;
    o.w30[5] = 1;
    func_0218F900(r4, &o, func_02011330((struct Stream *)a0));
    return 0;
}
