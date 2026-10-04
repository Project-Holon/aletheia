/*
 * function: func_021FD1CC
 * address: 0x021FD1CC
 * packet: pkt_ov094_021FD1CC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * 2026-10-02: the kind == 4 swap closed. It is a per-axis swap through
 * temps from a (tx = a.x; a.x = b.x; ...), then the sums read the new a:
 * b.x = tx + a.x. Grouped temps, temps from b and `b.x = b.x + tx` all
 * leave the spill on old b.y or the add operands reversed.
 * symbols:
 *   func_02051774 0x02051774 arm
 *   func_021FD070 0x021FD070 thumb ov094
 *   func_021FCF2C 0x021FCF2C thumb ov094
 *   func_021FD088 0x021FD088 thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_021FF3FC 0x021FF3FC thumb ov094
 *   func_021FF3F4 0x021FF3F4 thumb ov094
 *   func_021FE1B8 0x021FE1B8 thumb ov094
 *   func_021FD8CC 0x021FD8CC thumb ov094
 *   func_02011324 0x02011324 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02051A2C 0x02051A2C arm
 *   func_02051A24 0x02051A24 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207CF3C 0x0207CF3C arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CA68 0x0207CA68 arm
 *   func_0207D184 0x0207D184 arm
 *   func_0207CAE8 0x0207CAE8 arm
 *   func_0207B65C 0x0207B65C arm
 *   func_0207BC08 0x0207BC08 arm
 *   func_020519C4 0x020519C4 arm
 *   func_02051A04 0x02051A04 arm
 *   func_020517B4 0x020517B4 arm
 *   func_020519E4 0x020519E4 arm
 *   func_02051880 0x02051880 arm
 *   func_020517D0 0x020517D0 arm
 *   func_02051830 0x02051830 arm
 *   func_02051820 0x02051820 arm
 *   func_020517E0 0x020517E0 arm
 *   func_020517D8 0x020517D8 arm
 *   func_020517E8 0x020517E8 arm
 *   func_020518A4 0x020518A4 arm
 *   func_0205189C 0x0205189C arm
 *   func_02051790 0x02051790 arm
 *   func_020517A4 0x020517A4 arm
 *   func_020517F0 0x020517F0 arm
 *   func_02051800 0x02051800 arm
 *   func_02051808 0x02051808 arm
 *   func_02051818 0x02051818 arm
 *   func_02051838 0x02051838 arm
 *   _ll_mul 0x0209C054 arm
 *   d_0220AE68 0x0220AE68 data
 *   d_020A1B38 0x020A1B38 data
 */
#include "../include/Obj07881.h"
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef struct { int x, y, z; } Vec;
typedef struct { s16 x, y, z; } Vec16;
typedef struct { int m[12]; } Mtx;
typedef struct { u16 on; Vec16 dir; } Dir;
typedef struct {
    int vm;         /* 0x00 */
    int k1;         /* 0x04 */
    int k2;         /* 0x08 */
    Vec ofs;        /* 0x0c */
    int f18;        /* 0x18 */
    int f1c;        /* 0x1c */
    int kind;       /* 0x20 */
    int f24;        /* 0x24 */
    Vec pa;         /* 0x28 */
    Vec pb;         /* 0x34 */
    int mode;       /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int flip;       /* 0x58 */
} Rec;
typedef struct {
    int m[9];       /* 0x00 */
    Vec pos;        /* 0x24 */
    int f30;        /* 0x30 */
    int f34;        /* 0x34 */
    int f38;        /* 0x38 */
    int f3c;        /* 0x3c */
    int f40;        /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int f58;        /* 0x58 */
    int f5c;        /* 0x5c */
} Obj;
extern char d_0220AE68[];
extern const s16 d_020A1B38[];
extern Rec *func_02051774(void *p);
extern int func_021FD070(int a, int b);
extern int func_021FCF2C(int a, int idx);
extern int func_021FD088(int a, int *out);
struct ScriptVm;
extern int func_021F8694(void);
extern int func_021F8710(void);
extern void func_021FF3FC(const Vec *def, Vec *out, int idx, int kind);
extern void func_021FF3F4(void *obj, Vec *out, int idx);
extern void func_021FE1B8(Vec *v, const Vec *ofs);
extern void func_021FD8CC(void *p, int active);
extern void *func_02011324(struct ScriptVm *vm);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *);
extern void func_02051A2C(void *p, Obj *o);
extern void func_02051A24(void *p, int v);
extern int func_0207C768(int a, int b);
extern int func_0207CF3C(const Vec *a, const Vec *b);
extern void func_0207CCA4(const Vec *a, Vec *b);
extern int func_0207CA68(const Vec *a, const Vec *b);
extern u16 func_0207D184(int a);
extern void func_0207CAE8(const Vec *a, const Vec *b, Vec *c);
extern void func_0207B65C(void *m, const Vec *axis, int s, int c);
extern void func_0207BC08(const Vec *a, const void *m, Vec *out);
extern void func_020519C4(void *p, Vec *v);
extern void func_02051A04(void *p, Vec *v);
extern void func_020517B4(void *p, Vec16 *v);
extern void func_020519E4(void *p, Dir *d);
extern void func_02051880(void *p, const Vec16 *v);
extern int func_020517D0(void *p);
extern unsigned short func_02051830(char *p);
extern short func_02051820(char *p);
extern int func_020517E0(void *p);
extern void func_020517D8(void *p, int v);
extern void func_020517E8(void *p, int v);
extern void func_020518A4(void *p, u16 v);
extern void func_0205189C(void *p, int v);
extern void func_02051790(void *p, Vec *v);
extern void func_020517A4(void *p, const Vec *v);
extern short func_020517F0(char *p);
extern void func_02051800(void *p, int v);
extern short func_02051808(char *p);
extern void func_02051818(void *p, int v);
extern void func_02051838(void *p, const Vec *v);
#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

void func_021FD1CC(void *p)
{
    Vec a;
    Vec b;
    Vec c;
    Vec axis;
    Vec d;
    Vec e;
    Mtx m;
    Vec v1;
    Vec v2;
    Vec axis2;
    Vec sc;
    Dir dir;
    Rec *r;
    int flip;
    char *s;
    Obj *o;
    u16 ang;
    int t0, t1, t2, t3;
    int n;
    int tx, ty, tz;

    r = func_02051774(p);
    flip = r->flip;
    switch (r->k1) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k1 = func_021FD070(r->vm, r->k1);
        break;
    case 9:
    case 11:
        r->k1 = func_021FCF2C(r->vm, r->k1 + 5);
        break;
    case 8:
        a.x = r->pa.x;
        a.y = r->pa.y;
        a.z = r->pa.z;
        break;
    case 14: case 15: case 16: case 17:
        func_021FF3FC((const Vec *)func_021F8694(), &a, r->k1 - 12, 1);
        r->k1 = -1;
        break;
    case 18: case 19: case 20: case 21:
        func_021FF3FC((const Vec *)func_021F8694(), &a, r->k1 - 16, 1);
        switch (r->k1) {
        case 18: a.z += 0x1a00; break;
        case 19: a.z += 0x2600; break;
        case 20: a.z += 0x600; break;
        case 21: a.z += 0x3900; break;
        }
        r->k1 = -1;
        break;
    }
    if (r->k1 != -1 && r->k1 != 8)
        func_021FF3F4((void *)func_021F8694(), &a, r->k1);
    switch (r->k2) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k2 = func_021FD070(r->vm, r->k2);
        break;
    case 9:
        r->k2 = func_021FCF2C(r->vm, r->k2 + 5);
        break;
    case 10:
        flip = 1;
        r->k2 = func_021FCF2C(r->vm, r->k2 + 4);
        break;
    case 12:
        flip = 1;
    case 11:
        n = func_021FD088(r->vm, &r->k2);
        func_021FF3FC((const Vec *)func_021F8694(), &b, r->k2, n);
        r->k2 = -1;
        break;
    case 8:
        b.x = r->pb.x;
        b.y = r->pb.y;
        b.z = r->pb.z;
        break;
    case 14: case 15: case 16: case 17:
        func_021FF3FC((const Vec *)func_021F8694(), &b, r->k2 - 12, 1);
        r->k2 = -1;
        break;
    case 18: case 19: case 20: case 21:
        func_021FF3FC((const Vec *)func_021F8694(), &b, r->k2 - 16, 1);
        switch (r->k1) {
        case 18: b.z += 0x1a00; break;
        case 19: b.z += 0x2600; break;
        case 20: b.z += 0x600; break;
        case 21: b.z += 0x3900; break;
        }
        r->k2 = -1;
        break;
    }
    if (r->k2 != -1 && r->k2 != 8)
        func_021FF3F4((void *)func_021F8694(), &b, r->k2);
    func_021F8710();
    a.z += 0x500;
    b.z += 0x500;
    if ((u32)(r->mode - 1) <= 1) {
        func_021FE1B8(&a, &r->ofs);
        func_021FE1B8(&b, &r->ofs);
    } else if (r->mode == 3) {
        c.x = a.x;
        c.y = a.y;
        c.z = a.z;
        a.y += r->ofs.y;
        func_021FE1B8(&c, &r->ofs);
    } else {
        a.y += r->ofs.y;
    }
    b.y += r->ofs.y;
    if (r->kind != 0) {
        s = func_02011324((struct ScriptVm *)r->vm);
        *(Obj **)(s + 0x1f4 + ((struct Obj07881 *)s)->f234 * 4) = func_02030734((u16)((((struct Obj07881 *)s)->f238 & 0x7fff) | 0x8000), 0x60, 0, d_0220AE68, 0x194a);
        o = *(Obj **)(s + 0x1f4 + ((struct Obj07881 *)s)->f234 * 4);
        func_02051A2C(p, o);
        func_02051A24(p, (int)func_021FD8CC);
        ((struct Obj07881 *)s)->f234 += 1;
        o->f38 = 0;
        o->f50 = 0;
        o->f54 = 0;
        o->f58 = 0;
        o->f4c = r->kind;
        o->f48 = r->f24 >> 12;
        o->f5c = r->mode;
        if (r->kind == 3) {
            o->f40 = func_0207C768(0x6000000, r->f24);
        } else if ((u32)(r->kind - 5) <= 1) {
            o->f40 = func_0207C768(0x8000000, r->f24);
            o->f44 = func_0207C768(0x10000000, r->f24);
            o->f44 = MUL(o->f44, r->f54);
        } else {
            o->f40 = func_0207C768(0x8000000, r->f24);
        }
        if (o->f40 == 0)
            o->f40 = 1;
        o->f30 = func_0207CF3C(&a, &b) / 2;
        if (r->kind == 1 || r->kind == 4)
            o->f34 = 0;
        else
            o->f34 = r->f1c;
        if (r->kind == 4) {
            tx = a.x;
            a.x = b.x;
            ty = a.y;
            a.y = b.y;
            tz = a.z;
            a.z = b.z;
            b.x = tx + a.x;
            b.y = ty + a.y;
            b.z = tz + a.z;
        }
        d.x = b.x - a.x;
        d.y = b.y - a.y;
        d.z = b.z - a.z;
        func_0207CCA4(&d, &d);
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
        ang = func_0207D184(func_0207CA68(&e, &d));
        func_0207CAE8(&e, &d, &axis);
        func_0207CCA4(&axis, &axis);
        func_0207B65C(o, &axis, d_020A1B38[(ang >> 4) * 2], d_020A1B38[(ang >> 4) * 2 + 1]);
        o->pos.x = a.x;
        o->pos.y = a.y;
        o->pos.z = a.z;
    }
    if (r->k1 != 8 && r->k2 != 8 && r->k1 != r->k2) {
        dir.on = 2;
        b.x -= a.x;
        b.y -= a.y;
        b.z -= a.z;
        func_020519C4(p, &b);
        func_02051A04(p, &b);
        v2.x = b.x;
        v2.y = 0;
        v2.z = b.z;
        func_020517B4(p, &dir.dir);
        v1.x = dir.dir.x;
        v1.y = 0;
        v1.z = dir.dir.z;
        func_0207CCA4(&v1, &v1);
        func_0207CCA4(&v2, &v2);
        ang = func_0207D184(func_0207CA68(&v1, &v2));
        func_0207CAE8(&v1, &v2, &axis2);
        func_0207CCA4(&axis2, &axis2);
        func_0207B65C(&m, &axis2, d_020A1B38[(ang >> 4) * 2], d_020A1B38[(ang >> 4) * 2 + 1]);
        v1.x = dir.dir.x;
        v1.y = dir.dir.y;
        v1.z = dir.dir.z;
        func_0207BC08(&v1, &m, &v1);
        func_0207CCA4(&v1, &v1);
        if (flip == 1) {
            v1.x *= -1;
            v1.z *= -1;
        }
        dir.dir.x = v1.x;
        dir.dir.y = v1.y;
        dir.dir.z = v1.z;
        if (ang < 0x2000 || (ang > 0x6000 && ang < 0xa000) || ang > 0xe000)
            dir.on = 0;
        func_020519E4(p, &dir);
        func_02051880(p, &dir.dir);
    }
    if ((r->mode != 0 && (r->k1 & 1)) || r->mode == 0 || (u32)(r->mode - 2) <= 1) {
        t0 = func_020517D0(p);
        t1 = func_02051830(p) << 12;
        t2 = func_02051820(p);
        t3 = func_020517E0(p);
        if (r->f44 != 0) {
            func_020517D8(p, MUL(t0, r->f44));
            func_020517E8(p, MUL(t3, r->f44));
        }
        if (r->f48 != 0)
            func_020518A4(p, (u16)(MUL(t1, r->f48) >> 12));
        if (r->f4c != 0)
            func_0205189C(p, (s16)MUL(t2, r->f4c));
        if (r->f50 != 0) {
            func_02051790(p, &sc);
            sc.x = MUL(sc.x, r->f50);
            sc.y = MUL(sc.y, r->f50);
            sc.z = MUL(sc.z, r->f50);
            func_020517A4(p, &sc);
            t0 = func_020517F0(p);
            func_02051800(p, (s16)MUL(t0, r->f50));
            t0 = func_02051808(p);
            func_02051818(p, (s16)MUL(t0, r->f50));
        }
    }
    if (r->mode == 3)
        func_02051838(p, &c);
    else
        func_02051838(p, &a);
    func_020307B0(r);
}
