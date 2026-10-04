/*
 * function: func_02185D38
 * address:  0x02185D38
 * packet:   pkt_ov020_02185D38
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_02158630  0x02158630  thumb  ov010
 *   func_021D2750  0x021D2750  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026484  0x02026484  thumb
 *   func_0217574C  0x0217574C  thumb  ov011
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02175B4C  0x02175B4C  thumb  ov011
 *   func_02012B78  0x02012B78  thumb
 *   func_02039338  0x02039338  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02185C4C  0x02185C4C  thumb  ov020
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x1c];
    int f1c;
    int f20;
    int f24;
    int f28;
    u8 b2c;
} Ctx;

struct Ctx;
extern unsigned int func_02012138(const struct Ctx *a);
struct Comm;
struct Evt;
extern int func_02158344(int a0);
extern int func_0217C070(u8 *o);
extern int func_02158630(int h);
typedef unsigned int   u32;
extern int func_021D2750(u32 a);
extern u16 func_02188C84(u8 *p);
extern void func_02158780(int a0, u16 id, int b, int c, int d);
extern int func_02158590(void *p);
extern void func_02026400(struct Comm *p);
extern int func_02026454(int h);
extern void func_02026484(void *obj);
extern void func_0217574C(u8 *o, u32 v);
extern void func_02175710(u8 *o, u32 v);
extern void func_02175B4C(u8 *o, u8 *p);
extern int func_02012B78(int a, int b);
extern int func_02039338(int a);
extern void func_02012B64(int a, int b);
extern int func_02185C4C(int a, int b, Ctx *c);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_02185D38(int a0, int *state, Ctx *c)
{
    int r;
    int h;
    int flag;
    int id;
    u8 *obj;

    h = func_02012138((const struct Ctx *)c->f1c);
    switch (*state) {
    case 0:
        obj = (u8 *)func_02158344(h);
        flag = 0;
        r = 0;
        if (obj != 0) {
            r = func_0217C070(obj);
            if (func_02158630(h) == 3)
                flag = 1;
        }
        if (r == 0 && func_021D2750(c->f1c) != 0) {
            id = !flag ? 0x279A : 0x279B;
            func_02158780(a0, id, 0, 0, func_02188C84((u8 *)c->f24));
            if (func_02158590((void *)c->f20) == 0)
                func_02026400((struct Comm *)h);
            *state = 1;
        } else {
            id = !r ? 0x279C : 0x279D;
            func_02158780(a0, id, 0, 0, func_02188C84((u8 *)c->f24));
            *state = 3;
        }
        break;
    case 1:
        if (func_02158590((void *)c->f20) == 0) {
            if (func_02026454(h) != 0)
                break;
            func_02026484((void *)h);
        }
        if (c->f28 == 1 && func_02158630(h) != 3) {
            func_02158780(a0, 0x279F, 0, 0, func_02188C84((u8 *)c->f24));
            *state = 3;
            break;
        }
        obj = (u8 *)func_02158344(h);
        if (obj != 0) {
            func_0217574C(obj, 1);
            func_02175710(obj, c->b2c);
            if (c->f28 == 1)
                func_02175B4C(obj, obj + 0x1AC);
        }
        func_02012B64(c->f20, func_02039338(func_02012B78(c->f20, 1)));
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185C4C(c->f1c, c->f24, c));
        *state = 2;
        break;
    case 2:
        obj = (u8 *)func_02158344(h);
        if (obj != 0)
            func_0217574C(obj, 0);
        *state = 3;
        break;
    case 3:
        return 1;
    }
    return 0;
}
