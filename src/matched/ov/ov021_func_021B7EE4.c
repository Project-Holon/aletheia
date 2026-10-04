/*
 * function: func_021B7EE4
 * address:  0x021B7EE4
 * packet:   pkt_ov021_021B7EE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B919C  0x021B919C  thumb  ov021
 *   func_021B9278  0x021B9278  thumb  ov021
 *   func_021B9280  0x021B9280  thumb  ov021
 *   func_021B8658  0x021B8658  thumb  ov021
 *   func_021B91F8  0x021B91F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;

typedef struct { u32 a, b, c; } V3;
typedef struct { u16 a; u8 t; u8 c; s16 e; u16 d; } Out;

typedef struct Info {
    u32 arr[4];
    u32 f10[4];
    u32 f20;
    u8 pad24[0x4c];
} Info;

typedef struct Rec {
    u32 f0;
    u32 f4;
    u8 pad8[0xc];
    u32 f14;
    u8 pad18[0x30];
} Rec;

typedef struct Tbl {
    u8 pad0[0x10];
    Info *f10;
    Rec *f14;
} Tbl;

typedef struct Sub {
    u16 f0;
    u16 pad2;
    Info *f4;
    u16 f8;
    u16 padA;
    int fC;
    u8 pad10[8];
    u32 f18;
    u32 f1C;
    u8 pad20[4];
    Tbl *f24;
    u8 pad28[4];
    u8 f2C;
    s8 f2D;
    u16 f2E;
    u16 f30;
    u8 f32;
    u8 f33;
    u8 f34;
    u8 pad35[3];
    V3 f38;
    V3 f44;
    u8 pad50[0xc];
    Out f5C;
    Out f64;
} Sub;

extern void func_021B919C(u8 *p, u32 a);
extern u32 func_021B9278(Rec *o, u32 b, Tbl *t);
extern u32 func_021B9280(Rec *o, u32 a, u32 b, Tbl *t);
extern void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_021B91F8(Sub *p, V3 *out);

void func_021B7EE4(Sub *p, const Out *q)
{
    Rec *o;
    int i;
    u32 m;
    u32 d;
    u32 e;
    u32 c;
    u32 v;

    o = 0;
    func_021B919C((u8 *)p, (u32)p->f24);
    if (q->t == 0) {
        p->f0 = 0;
        p->f4 = &p->f24->f10[q->a];
        p->f18 = p->f4->f20;
        for (i = 0; i < 4; i++) {
            if (p->f4->arr[i] != 0xFFFF && o == 0) {
                o = &p->f24->f14[p->f4->arr[i]];
                if (o->f0 == q->a) {
                    d = 0;
                    e = 0;
                    c = p->f4->f10[i];
                } else if (o->f4 == q->a) {
                    d = func_021B9278(o, p->f1C, p->f24);
                    e = 0;
                    c = p->f4->f10[i];
                }
            }
        }
    } else {
        o = &p->f24->f14[q->a];
        v = q->d;
        if (v >= o->f14) {
            v--;
        }
        d = v << 4;
        e = q->e << 4;
        c = q->c;
    }
    m = func_021B9278(o, p->f1C, p->f24);
    func_021B8658((u8 *)p, (u32)o, c, d, e, m, func_021B9280(o, d, m, p->f24));
    p->f33 = 1;
    p->f32 = c;
    p->f8 = 1;
    func_021B91F8(p, &p->f38);
    p->f5C = *q;
    p->f64 = *q;
    p->f44 = p->f38;
}
