/*
 * function: func_02050550
 * address:  0x02050550
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02050920  0x02050920  arm
 *   func_02050944  0x02050944  arm
 *   func_020506B8  0x020506B8  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F764  0x0204F764  arm
 *   func_0204F794  0x0204F794  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Cmd {
    u16 a : 14;
    u16 b : 1;
    u16 c : 1;
    u16 f02;
} Cmd;

typedef struct Ent {
    u32   f00;
    u16   f04;
    u16   f06;
    u32 **f08;
    u16   f0c;
    u16   f0e;
    u16   f10;
    u16   f12;
    u32   f14;
    u32   f18;
} Ent;

typedef struct Own {
    u32  f00;
    u32  f04;
    u32  f08;
    u8  *f0c;
} Own;

extern u32  func_02050920(Cmd *c);
extern u32  func_02050944(Ent *e, Cmd *c);
extern void func_020506B8(Own *o, u8 *p, u32 a2);
extern void func_0204F66C(u32 res, u32 id, u16 *v);
extern void func_0204F764(u32 res, u32 id, u32 *v);
extern void func_0204F794(u32 res, u32 id, u32 *v);

void func_02050550(Own *o, Ent *e)
{
    Cmd *c;
    u32  s2;
    u32  s1;
    u16  s0;
    u16  rem;
    u8  *p;

    if (e->f08 == 0 || e->f18 == 0) {
        return;
    }
    if (e->f12 != 0) {
        e->f12 = e->f12 - 1;
        return;
    }

    c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    while (func_02050920(c)) {
        if (func_02050944(e, c)) {
            return;
        }
        c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    }

    e->f10 = e->f10 + 1;
    s0 = c->a;
    rem = c->f02;

    p = (u8 *)(e->f04 * 8);
    p = p + (u32)o->f0c;
    if (*(u32 *)(p + 4) != 0) {
        func_020506B8(o, p, s0);
    } else {
        func_0204F66C(o->f04, e->f00, &s0);
    }

    if (c->b) {
        s2 = 1;
    } else {
        s2 = 0;
    }
    if (c->c) {
        s1 = 1;
    } else {
        s1 = 0;
    }

    func_0204F764(o->f04, e->f00, &s2);
    func_0204F794(o->f04, e->f00, &s1);

    if (rem != 0) {
        rem = rem - 1;
    }
    e->f12 = rem;
}
