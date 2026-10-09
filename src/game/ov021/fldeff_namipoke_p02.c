/*
 * file:     fldeff_namipoke_p02.c
 * unit:     yes
 * function: func_021ACDC4, func_021ACFD8, func_021ACFF8, func_021AD274, func_021AD3D4, func_021AD3FC, func_021AD410, func_021AD530, func_021AD564, func_021AD598, func_021AD5CC, func_021AD5E0, func_021AD6A4
 * address:  0x021ACDC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ACCB0  0x021ACCB0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ACC04  0x021ACC04  thumb  ov021
 *   func_021ACBE4  0x021ACBE4  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_020521BC  0x020521BC  arm
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 *   d_021DE080  0x021DE080  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021D9170  0x021D9170  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   d_021D91F8     0x021D91F8  data  a4
 *   func_021C6628  0x021C6628  thumb  ov021
 */
#include "../../matched/include/Obj18088.h"
#include "../../matched/include/Obj12097.h"

struct Actor;
struct VecFx32;
struct E;
struct Mtx33;
struct Vec3;
struct X;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32_021ACDC4;

typedef struct V3 { s32_021ACDC4 x, y, z; } V3;

typedef struct Inner {
    u16 a;
    u16 b;
    V3 p4;
    V3 p10;
    u16 c;
    u16 pad;
    V3 scale;
    V3 pos;
} Inner;

typedef struct B {
    u8 pad0[9];
    u8 f9;
    u8 fa;
    u8 pad1;
    u16 fc;
    u8 pad2[2];
    s32_021ACDC4 f10;
    s32_021ACDC4 f14;
    u8 pad3[4];
    u32 *f1c;
    u32 f20;
    u8 pad4[0x14];
    Inner in;
} B;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Y { u8 pad[0x18]; u16 h18; u16 pad1a; u32 *f1c; u8 pad20[0x34]; u16 h54; } Y;

typedef struct Inner_021ACFF8 {
    u16 a;
    u16 b;
    V3 p4;
    V3 p10;
    u16 c;
    u16 pad;
    V3 scale;
    V3 pos;
} Inner_021ACFF8;

typedef struct B_021ACFF8 {
    u8 pad0[9];
    u8 f9;
    u8 fa;
    u8 pad1;
    u16 fc;
    u8 pad2[2];
    s32_021ACDC4 f10;
    s32_021ACDC4 f14;
    u8 pad3[4];
    u32 *f1c;
    u32 f20;
    u8 pad4[0x14];
    Inner_021ACFF8 in;
} B_021ACFF8;

typedef struct M33 { s32_021ACDC4 m[9]; } M33;

typedef struct Node {
    V3 pos;
    V3 scale;
    M33 mtx;
} Node;

typedef struct Inner_021AD274 {
    u16 a;
    u16 b;
    u8 pad[0x18];
    u16 c;
    u16 pad2;
    V3 scale;
    V3 pos;
} Inner_021AD274;

typedef struct B_021AD274 {
    u8 pad0[0xc];
    u16 fc;
    u8 pad1[0xa];
    u16 f18;
    u8 pad2[2];
    u32 *f1c;
    u32 f20;
    u8 pad3[0x14];
    Inner_021AD274 in;
} B_021AD274;

typedef struct P { u32 f0; } P;

typedef signed int     s32_021AD3D4;

typedef struct X { u32 f0; u16 h4; u16 h6; u16 h8; u16 ha; u16 hc; } X;

typedef struct Arg { u32 f0; u32 f4; u32 f8; u32 fc; } Arg;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct T5 {
    Vec v[5];
} T5;

typedef struct S16 {
    int a, b, c, d;
} S16;

typedef struct Tab {
    int f0;
    u16 h4, h6, h8, ha, hc;
} Tab;

typedef struct Obj {
    Vec v;
    int padc;
    u16 h10;
    u16 pad12;
    S16 s14;
} Obj;

extern void func_021ACCB0(u32 a, B *b);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D598(void *p);
extern void func_0216D8E0(u32 a, V3 *v);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_02197CCC(u8 *p, s32_021ACDC4 *out);
extern void func_021AC1CC(u32 a, V3 *v);
extern u32 func_021ABE18(u8 *p);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ACC04(struct E *a, struct E *b, u32 mode);
extern s32_021ACDC4 func_021ACBE4(s32_021ACDC4 d);
extern void func_021C67F4(u32 a, u32 b);
extern void func_0219E784(u32 a, u32 b, s16 *out);
extern void func_0207CDB8(s16 *a, s16 *b);
extern s32_021ACDC4 func_0207CF3C(const V3 *a, const V3 *b);
extern void func_020521BC(const struct Vec3 *v, struct Mtx33 *dst);
extern int func_021C6658(u32 a, u32 b);
extern void func_021AC1B8(u32 a, Node *n);
extern void func_021C6678(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 *a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern u8 func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern int func_021AC1E0(u32 a);
extern int func_021AC1AC(u32 a);
extern u16 func_021C6590(int a, int b, int c, int d);
extern u32 func_021C6628(u32, u32);
void func_021ACDC4(u32 a, B *b);
void func_021ACFD8(u32 a, Y *y);
void func_021ACFF8(u32 a, B_021ACFF8 *b);
void func_021AD274(u32 a, B_021AD274 *b);
P *func_021AD3D4(u32 a, int heap);
void func_021AD3FC(u32 a, u8 *p);
void func_021AD410(u32 *a);
void func_021AD530(X *x);
void func_021AD564(u32 a, u32 b, u32 c);
void func_021AD598(u32 a, u32 b, u32 c);
int func_021AD5CC(u32 a);
void func_021AD5E0(int a, int *bp);
int func_021AD6A4(u32 a, u32 b, u32 c, u32 d);
extern char d_021DE080[];
extern u8 d_021D9170[];
extern T5 d_021D91F8;




/*
 * Addresses are Black-image addresses.
 */
void func_021ACDC4(u32 a, B *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    Inner *in;
    s32_021ACDC4 d;
    u16 k;

    if (b->f9 == 0) {
        func_021ACCB0(a, b);
        return;
    }
    b->fc = func_0216D5F8((void *)b->f20);
    if (b->f9 == 1) {
        b->f10 += b->f14;
        if (b->f10 >= 0x4000) {
            b->f10 = 0x4000;
            b->f14 = -b->f14;
        } else if (b->f10 <= 0x1000) {
            b->f10 = 0x1000;
            b->f14 = -b->f14;
        }
        v.x = 0;
        v.y = b->f10 + 0x1000;
        v.z = 0x5000;
        k = func_0216D598((void *)b->f20);
        if (k == 0xA0 || k == 0xA1)
            v.y = b->f10 + 0x8000;
        func_0216D8E0(b->f20, &v);
    } else if (b->f9 == 2) {
        func_0216D8D0((u8 *)b->f20, (u8 *)(&v));
    }
    func_02197CCC((u8 *)b->f20, (s32_021ACDC4 *)(&w));
    w.x -= v.x;
    w.y -= v.y;
    w.z -= v.z;
    if (b->f9 != 2)
        w.y += b->f10 - 0x1000;
    func_021AC1CC(a, &w);
    if (b->f9 == 2 || b->fa == 1) {
        in = &b->in;
        in->b = 9;
        if (b->fa == 1)
            in->a = 1;
    } else {
        in = &b->in;
        func_021C66EC((u32 *)func_021ABE18((u8 *)(*b->f1c)), in->c, 0x1000);
        func_0216D88C((const struct Actor *)b->f20, (struct VecFx32 *)&u);
        if (b->fc != in->b) {
            in->b = b->fc;
            in->p4 = u;
        } else if (u.x == in->p10.x && u.y == in->p10.y && u.z == in->p10.z) {
            switch (in->b) {
            case 0:
                in->p4.z -= 0x4000;
                if (in->p4.z < u.z)
                    in->p4.z = u.z;
                break;
            case 1:
                in->p4.z += 0x4000;
                if (in->p4.z > u.z)
                    in->p4.z = u.z;
                break;
            case 2:
                in->p4.x -= 0x4000;
                if (in->p4.x < u.x)
                    in->p4.x = u.x;
                break;
            case 3:
                in->p4.x += 0x4000;
                if (in->p4.x > u.x)
                    in->p4.x = u.x;
                break;
            }
        }
        d = func_021ACC04((struct E *)(&u), (struct E *)(&in->p4), in->b);
        if (d >= 0x40000) {
            switch (in->b) {
            case 0:
                in->p4.z = u.z + 0x40000;
                break;
            case 1:
                in->p4.z = u.z - 0x40000;
                break;
            case 2:
                in->p4.x = u.x + 0x40000;
                break;
            case 3:
                in->p4.x = u.x - 0x40000;
                break;
            }
        }
        d = func_021ACBE4(d);
        if (d < 0x28) {
            in->a = 1;
        } else {
            in->a = 0;
            in->scale.x = d;
            in->scale.y = d;
            in->scale.z = d;
        }
        in->p10 = u;
    }
    func_021ACCB0(a, b);
}





void func_021ACFD8(u32 a, Y *y)
{
    u32 h = func_021ABE18((u8 *)(*y->f1c));

    func_021C67F4(h, y->h18);
    func_021C67F4(h, y->h54);
}





static inline s32_021ACDC4 FX_Mul(s32_021ACDC4 a, s32_021ACDC4 b)
{
    return (s32_021ACDC4)(((long long)a * b + 0x800LL) >> 12);
}





void func_021ACFF8(u32 a, B_021ACFF8 *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    s16 f[3];
    s16 d[3];
    Inner_021ACFF8 *in;
    s32_021ACDC4 dist;
    s32_021ACDC4 r;

    if (b->f9 == 0)
        return;
    b->fc = func_0216D5F8((void *)b->f20);
    func_0219E784(b->f20, 0, f);
    func_0219E784(b->f20, b->fc, d);
    f[1] = 0;
    func_0207CDB8(f, f);
    d[1] = 0;
    func_0207CDB8(d, d);
    if (b->f9 == 1) {
        b->f10 += b->f14;
        if (b->f10 >= 0x4000) {
            b->f10 = 0x4000;
            b->f14 = -b->f14;
        } else if (b->f10 <= 0x1000) {
            b->f10 = 0x1000;
            b->f14 = -b->f14;
        }
        v.x = FX_Mul(-f[0], 0x7000);
        v.y = b->f10 + 0x5000;
        v.z = FX_Mul(-f[2], 0x7000);
        func_0216D8E0(b->f20, &v);
    }
    func_02197CCC((u8 *)b->f20, (s32_021ACDC4 *)(&w));
    w.x -= v.x;
    w.y -= v.y;
    w.z -= v.z;
    w.y += b->f10 - 0x1000;
    func_021AC1CC(a, &w);
    if (b->f9 == 2 || b->fa == 1) {
        in = &b->in;
        in->b = 9;
        if (b->fa == 1)
            in->a = 1;
    } else {
        in = &b->in;
        func_021C66EC((u32 *)func_021ABE18((u8 *)(*b->f1c)), in->c, 0x1000);
        func_0216D88C((const struct Actor *)b->f20, (struct VecFx32 *)&u);
        if (b->fc != in->b) {
            in->b = b->fc;
            in->p4 = u;
        } else if (u.x == in->p10.x && u.y == in->p10.y && u.z == in->p10.z) {
            in->p4.x += FX_Mul(d[0], 0x4000);
            in->p4.z += FX_Mul(d[2], 0x4000);
            in->p4.y = u.y;
            if (d[0] > 0) {
                if (in->p4.x > u.x)
                    in->p4.x = u.x;
            } else if (d[0] < 0) {
                if (in->p4.x < u.x)
                    in->p4.x = u.x;
            }
            if (d[2] > 0) {
                if (in->p4.z > u.z)
                    in->p4.z = u.z;
            } else if (d[2] < 0) {
                if (in->p4.z < u.z)
                    in->p4.z = u.z;
            }
        }
        dist = func_0207CF3C(&u, &in->p4);
        if (dist >= 0x40000) {
            in->p4.x = u.x - FX_Mul(d[0], 0x40000);
            in->p4.z = u.z - FX_Mul(d[2], 0x40000);
        }
        r = func_021ACBE4(dist);
        if (r <= 0x28) {
            in->a = 1;
        } else {
            in->a = 0;
            in->scale.x = r;
            in->scale.y = r;
            in->scale.z = r;
        }
        in->p10 = u;
    }
}





void func_021AD274(u32 a, B_021AD274 *b)
{
    V3 va;
    V3 vb;
    M33 ma;
    M33 mb;
    s16 f[3];
    Inner_021AD274 *in = &b->in;
    u32 obj;
    Node *n;

    func_0219E784(b->f20, b->fc, f);
    va.x = f[0];
    va.y = 0;
    va.z = f[2];
    vb.x = -f[0];
    vb.y = 0;
    vb.z = -f[2];
    func_020521BC((const struct Vec3 *)(&va), (struct Mtx33 *)(&ma));
    func_020521BC((const struct Vec3 *)(&vb), (struct Mtx33 *)(&mb));
    obj = func_021ABE18((u8 *)(*b->f1c));
    n = (Node *)func_021C6658(obj, b->f18);
    n->mtx = ma;
    func_021AC1B8(a, n);
    if (b->in.a == 0) {
        func_021C6678(obj, in->c, 0);
        n = (Node *)func_021C6658(obj, in->c);
        n->mtx = mb;
        func_021AC1B8(a, n);
        n->pos.x = n->pos.x + (in->pos.x - FX_Mul(va.x, 0xE000));
        n->pos.y = n->pos.y + (in->pos.y - 0x4000 - FX_Mul(va.y, 0xE000));
        n->pos.z = n->pos.z + (in->pos.z - FX_Mul(va.z, 0xE000));
        n->scale = in->scale;
    } else {
        func_021C6678(obj, in->c, 1);
    }
    func_021C67F4(obj, b->f18);
    func_021C67F4(obj, in->c);
}




P *func_021AD3D4(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x10, 1, d_021DE080, 0x3cf);
    p->f0 = a;
    func_021AD410((u32 *)p);
    return p;
}




/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD3FC(u32 a, u8 *p)
{
    func_021AD530((X *)((struct X *)p));
    func_020307B0(p);
}




/*
 * Addresses are Black-image addresses.
 *
 * The buffer handle p is assigned after the func_021ABE24 call, but the
 * first func_021C6AE0 call takes the buffer itself, so a call lies between
 * the assignment and the first read of p. That keeps p a register variable
 * (r7) instead of a rematerialised address, and the repeated 0 argument is
 * rebuilt per call. See docs/idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md.
 */
void func_021AD410(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r6;
    u32 r4;
    u32 p;
    r6 = func_021ABE18((u8 *)a[0]);
    r4 = func_021ABE24((u8 *)a[0]);
    p = (u32)buf;
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x37);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x80);
    func_021C6AFC(p, 0x6c);
    h[2] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x3a);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x6f);
    func_021C6AFC(p, 0x63);
    h[3] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x39);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x6e);
    func_021C6AFC(p, 0x62);
    h[5] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x3b);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x70);
    func_021C6AFC(p, 0x64);
    h[4] = func_021C6574(r6, p, 0);
    func_021C6AE0(buf);
    func_021C6AF0(p, r4, 0x38);
    func_021C6AF8((u32 *)p, r4);
    func_021C6AFC(p, 0x6d);
    func_021C6AFC(p, 0x61);
    h[6] = func_021C6574(r6, p, 0);
}




void func_021AD530(X *x)
{
    u32 h = func_021ABE18((u8 *)x->f0);

    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
    func_021C6580((u8 *)h, x->ha);
    func_021C6580((u8 *)h, x->h8);
    func_021C6580((u8 *)h, x->hc);
}




void func_021AD564(u32 a, u32 b, u32 c)
{
    Arg s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = c;
    s.f0 = 0;
    func_021ABFA8(a, d_021D9170, 0, 0, &s, 1);
}




void func_021AD598(u32 a, u32 b, u32 c)
{
    Arg s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = 0;
    s.f0 = 1;
    func_021ABFA8(a, d_021D9170, c, 0, &s, 1);
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AD5CC(u32 a)
{
if (a != 0) {
    return ((struct Obj18088 *)((u8 *)(func_021AC1E0(a))))->fC;
}
return 1;
}




void func_021AD5E0(int a, int *bp)
{
    Obj *b = (Obj *)bp;
    Vec out;
    T5 tab;
    int r;
    int m;
    Tab *t;

    b->s14 = *((S16 *)func_021AC1AC(a));
    t = (Tab *)b->s14.b;
    r = func_021ABE18((u8 *)t->f0);
    switch (b->s14.c) {
    case 0:
        m = ((Tab *)b->s14.b)->h4;
        break;
    case 1:
        m = ((Tab *)b->s14.b)->h6;
        break;
    case 2:
        m = ((Tab *)b->s14.b)->ha;
        break;
    case 3:
        m = ((Tab *)b->s14.b)->h8;
        break;
    case 4:
        m = ((Tab *)b->s14.b)->hc;
        break;
    default:
        goto skip;
    }
    b->h10 = func_021C6590(r, m, 0, 0);
skip:
    if (b->s14.d != 0) {
        tab = d_021D91F8;
        b->v = tab.v[b->s14.c];
        func_021AC1B8(b->s14.d, (Node *)&out);
        out.x += b->v.x;
        out.y += b->v.y;
        out.z += b->v.z;
        func_021AC1CC(a, (V3 *)&out);
    }
}



int func_021AD6A4(u32 a, u32 b, u32 c, u32 d)
{
return func_021C6628(func_021ABE18((u8 *)(*(u32 *)((u8 *)(((struct Obj12097 *)((u8 *)(b)))->f18)))), ((struct Obj12097 *)((u8 *)(b)))->f10);
}
