/*
 * function: func_021B3158
 * address:  0x021B3158
 * packet:   pkt_ov021_021B3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback armed by func_021B2FD8; steps the 0x214-byte work block it
 * allocated.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021B30C8  0x021B30C8  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_021B35A4  0x021B35A4  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
} Work;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

extern void *func_0215A5F4(void *p);
struct Ctx;
extern void *func_02158FB4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021B30C8(u32 *p, u32 b, void *h);
extern int func_0218FE50(u8 *a);
extern void func_02193060(u32 a);
extern int func_021B35A4(u32 a, char *p, u32 c, u8 d);
extern void func_0218F9C4(u8 *p, u8 *src, u16 v);
extern int func_0218EC60(u32 a);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218F878(u8 *a);
extern u32 func_020307B0(void *p);
extern const Buf24 d_021D9738;

int func_021B3158(u32 a, u32 b)
{
    Work **slot;
    Work *w;
    void *t;
    void *x;
    void *h;
    Buf24 buf;

    slot = func_02158FB4(func_0215A5F4((void *)b));
    w = *slot;
    t = func_0215A5DC((void *)b);
    x = func_0201210C((void *)t);
    h = func_02188C58(x);
    switch (w->state) {
    case 0:
        func_0218F0A8(h);
        w->state++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0) {
            w->state++;
        }
        break;
    case 2:
        func_021B30C8((u32 *)w, (u32)x, h);
        w->state++;
        break;
    case 3:
        if (func_0218FE50(h) == 0) {
            w->state++;
            w->f08 = 0;
            func_02193060(0);
        }
        break;
    case 4:
        if (func_021B35A4((u32)t, (char *)(&w->f08), w->b2, w->b3)) {
            w->state++;
        }
        break;
    case 5:
        buf = d_021D9738;
        func_0218F9C4(h, (u8 *)(&buf), 8);
        w->state++;
        w->sub = 0;
        break;
    case 6:
        if (func_0218FE50(h) == 0) {
            func_0218EC60((u32)h);
            func_0218F1AC(h, w->f04);
            func_0218F05C(h);
            func_0218F878(h);
            func_02193060(1);
            w->state++;
        }
        break;
    case 7:
        func_020307B0(*slot);
        return 1;
    }
    return 0;
}
