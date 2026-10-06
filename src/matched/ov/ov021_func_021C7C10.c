/*
 * function: func_021C7C10
 * address:  0x021C7C10
 * packet:   pkt_ov021_021C7C10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_021C7C74  0x021C7C74  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    u16 f8;
    u16 fA;
    Vec fC;
    Vec f18;
    Vec f24;
    int f30;
} Obj;

extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern int func_021C6C70(int, int, int (*)(Obj *));
typedef unsigned int   u32;
extern u32 func_021C6CCC(u8 *p);
extern void func_0207CA00(Vec *, Vec *, Vec *);
extern int func_021C7C74(Obj *);

int func_021C7C10(int a, int b, const Vec *c, const Vec *d)
{
    int w;
    int h;
    Obj *o;

    w = func_02188C84((u8 *)a);
    func_02188C58((void *)a);
    h = func_021C6C70(w, 0x34, func_021C7C74);
    o = (Obj *)func_021C6CCC((u8 *)h);
    o->f0 = 0;
    o->f4 = a;
    o->f8 = 0;
    o->fA = b;
    o->fC = *c;
    o->f18 = *d;
    func_0207CA00(&o->f18, &o->fC, &o->f24);
    return h;
}
