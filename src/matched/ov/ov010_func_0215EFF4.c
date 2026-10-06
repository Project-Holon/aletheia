/*
 * function: func_0215EFF4
 * address:  0x0215EFF4
 * packet:   pkt_ov010_0215EFF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_021587B0  0x021587B0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern int func_021587B0(int a0, int a1, int a2, int a3);

int func_0215EFF4(void *a, int *st, struct C *c)
{
    u32 h;
    u32 x;
    void *t;

    func_0201296C(func_020120F4(c->f8));
    x = func_02188C84(func_0201210C(c->f8));
    switch (*st) {
    case 0:
        h = c->fc;
        t = func_02158780(a, 0x271d, 0, 0, x);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_021587B0((int)a, 0x28e2, 0, 0);
        break;
    }
    return 0;
}
