/*
 * function: func_021B7EE0
 * address:  0x021B7EE0
 * packet:   pkt_ov071_021B7EE0
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021B82A4  0x021B82A4  thumb  ov071
 *   func_021B82FC  0x021B82FC  thumb  ov071
 *   func_02035C08  0x02035C08  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B6B98  0x021B6B98  thumb  ov071
 *   func_020061E4  0x020061E4  thumb
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_021B83CC  0x021B83CC  thumb  ov071
 *   func_021B6BEC  0x021B6BEC  thumb  ov071
 *   func_021B7108  0x021B7108  thumb  ov071
 *   func_021B6C74  0x021B6C74  thumb  ov071
 *   func_021B7114  0x021B7114  thumb  ov071
 *   func_021B8434  0x021B8434  thumb  ov071
 *   func_02035C60  0x02035C60  arm
 *   func_021B8440  0x021B8440  thumb  ov071
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9F8     0x021BA9F8  data  a4
 *   d_021BA9C8     0x021BA9C8  data  a4
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct {
    void **f0;
    void *f4;
    char pad8[0x24];
    u8 f2c;
    u8 f2d;
    u8 f2e;
} C;

typedef struct {
    u8 pad0[0x30];
    s8 sel;
    s8 res;
    u8 kind;
    u8 armed;
    u8 f34[8];
} D;

typedef struct {
    u8 b[0x14];
} Menu;

extern unsigned d_021BA978[];
extern Menu d_021BA9F8[];
extern int d_021BA9C8[][4];

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_021B82A4(int *a, char *p);
extern void func_021B82FC(void *p);
extern int func_02035C08(void *);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_020061E4(unsigned int);
extern int func_02175B14(u8 *);
extern void func_021B83CC(void *w, void *x, unsigned y);
extern void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
extern void func_021B7108(void *);
extern u8 func_021B6C74(void *p, int i);
extern int func_021B7114(void *);
extern int func_021B8434(u8 *p, u8 *q);
extern int func_02035C60(void);
extern void func_021B8440(void *w);

int func_021B7EE0(int a, int *state, C *c, D *d)
{
    u8 *r;
    int res;
    u32 keys;
    int t;

    r = (u8 *)func_02158344(func_02012138(*c->f0));
    func_021B82A4((int *)c, (char *)d);
    func_021B82FC(d);
    if (c->f2e == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        res = func_02035C08(&d_021BA9F8[d->kind]);
        if (res != -1) {
            d->sel = res;
            d->res = d_021BA9C8[d->kind][res];
            func_020355D8(1);
            d->armed = 0;
            (*state)++;
            break;
        }
        keys = func_0203633C();
        t = func_020362DC();
        if (t > 0 && d->armed == 1) {
            func_020355D8(0);
            d->armed = 0;
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
            break;
        }
        if (t & 1) {
            d->res = d_021BA9C8[d->kind][d->sel];
            (*state)++;
        } else if (t & 2) {
            d->res = 3;
            (*state)++;
        } else if (keys & 0x80) {
            d->sel++;
            if (d->sel >= d_021BA978[d->kind]) {
                d->sel = 0;
            }
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
        } else if (keys & 0x40) {
            d->sel--;
            if (d->sel < 0) {
                d->sel = d_021BA978[d->kind] - 1;
            }
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
        }
        break;
    case 1:
        if (d->res == 0) {
            if (((u8 *)c->f0)[0x3d] == 0) {
                (*state)--;
                break;
            }
            if (r != 0 && func_02175B14(r + 0x1ac) == 1) {
                func_020061E4(0x54c);
                func_021B83CC(d, c->f4, 4);
                *state = 3;
                break;
            }
        }
        if (d->res != 3) {
            func_021B6BEC(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x54c);
        } else {
            func_021B7108(d->f34);
            func_020061E4(0x551);
        }
        (*state)++;
        break;
    case 2:
        if (d->res != 3) {
            if (func_021B6C74(c, 3) != 2) {
                c->f2c = d->res + 1;
                return 1;
            }
        } else {
            if (func_021B7114(d->f34) == 0) {
                c->f2c = d->res + 1;
                return 1;
            }
        }
        break;
    case 3:
        if (func_021B8434(c->f4, (u8 *)d) == 1) {
            if (func_02035C60() != 0 || (func_020362DC() & 3) != 0) {
                func_021B8440(d);
                func_020061E4(0x547);
                *state = 0;
            }
        }
        break;
    }
    return 0;
}
