/*
 * function: func_021C7878
 * address:  0x021C7878
 * packet:   pkt_ov021_021C7878
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
 *   func_021C7A20  0x021C7A20  thumb  ov021
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

extern u16 func_02188C84(u8 *p);
extern int func_021C6C70(int, int, int (*)(Obj *));
extern Obj *func_021C6CCC(int);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_021C7A20(Obj *);

/* The Vec copy is a VEC_Set-style inline setter: its arguments are
 * evaluated right to left, which is what puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

int func_021C7878(int a, int b, const Vec *c, int d)
{
    Obj *o;
    int h;

    h = func_021C6C70(func_02188C84((u8 *)a), 0x2c, func_021C7A20);
    o = func_021C6CCC(h);
    o->f0 = 0;
    o->f4 = a;
    o->f28 = d;
    func_0216D88C((const struct Actor *)d, (struct VecFx32 *)o->f1C);
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
