/*
 * function: func_021C78DC
 * address:  0x021C78DC
 * packet:   pkt_ov021_021C78DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021C7A7C  0x021C7A7C  thumb  ov021
 *
 * Twin of func_021C7878 (only the callback differs).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    int f8;
    u16 fC;
    u16 fE;
    Vec f10;
    int f1C[3];
    int f28;
} Obj;

extern int func_02188C84(int);
extern int func_021C6C70(int, int, int (*)(Obj *));
extern Obj *func_021C6CCC(int);
extern void func_0216D88C(int, int *);
extern int func_021C7A7C(Obj *);

/* The Vec copy is a VEC_Set-style inline setter: its arguments are
 * evaluated right to left, which is what puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

int func_021C78DC(int a, int b, const Vec *c, int d)
{
    Obj *o;
    int h;

    h = func_021C6C70(func_02188C84(a), 0x2c, func_021C7A7C);
    o = func_021C6CCC(h);
    o->f0 = 0;
    o->f4 = a;
    o->f28 = d;
    func_0216D88C(d, o->f1C);
    if (b >= 0) {
        o->f8 = 0;
        o->fC = 0;
        o->fE = b;
    } else {
        o->f8 = 1;
        o->fC = 0;
        o->fE = -b;
    }
    vset(&o->f10, c->x, c->y, c->z);
    return h;
}
