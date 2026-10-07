/*
 * file:     fldeff_namipoke_p05.c
 * unit:     yes
 * function: func_021ACFD8, func_021ACFF8, func_021AD274
 * address:  0x021ACFD8
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
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_021ACBE4  0x021ACBE4  thumb  ov021
 *   func_020521BC  0x020521BC  arm
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 */
struct Actor;
struct VecFx32;
struct Mtx33;
struct Vec3;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Y { u8 pad[0x18]; u16 h18; u16 pad1a; u32 *f1c; u8 pad20[0x34]; u16 h54; } Y;

typedef int            s32;

typedef struct V3 { s32 x, y, z; } V3;

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
    s32 f10;
    s32 f14;
    u8 pad3[4];
    u32 *f1c;
    u32 f20;
    u8 pad4[0x14];
    Inner_021ACFF8 in;
} B_021ACFF8;

typedef struct M33 { s32 m[9]; } M33;

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

extern u32 func_021ABE18(u8 *p);
extern void func_021C67F4(u32 a, u32 b);
extern u16 func_0216D5F8(void *p);
extern void func_0219E784(u32 a, u32 b, s16 *out);
extern void func_0207CDB8(s16 *a, s16 *b);
extern void func_0216D8E0(u32 a, V3 *v);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_021AC1CC(u32 a, V3 *v);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern s32 func_0207CF3C(const V3 *a, const V3 *b);
extern s32 func_021ACBE4(s32 d);
extern void func_020521BC(const struct Vec3 *v, struct Mtx33 *dst);
extern int func_021C6658(u32 a, u32 b);
extern void func_021AC1B8(u32 a, Node *n);
extern void func_021C6678(u32 a, u32 b, u32 c);
void func_021ACFD8(u32 a, Y *y);
void func_021ACFF8(u32 a, B_021ACFF8 *b);
void func_021AD274(u32 a, B_021AD274 *b);


void func_021ACFD8(u32 a, Y *y)
{
    u32 h = func_021ABE18((u8 *)(*y->f1c));

    func_021C67F4(h, y->h18);
    func_021C67F4(h, y->h54);
}


static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021ACFF8(u32 a, B_021ACFF8 *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    s16 f[3];
    s16 d[3];
    Inner_021ACFF8 *in;
    s32 dist;
    s32 r;

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
    func_02197CCC((u8 *)b->f20, (s32 *)(&w));
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
