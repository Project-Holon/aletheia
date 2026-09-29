/*
 * function: func_021ACFF8
 * address:  0x021ACFF8
 * packet:   pkt_ov021_021ACFF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_021ACBE4  0x021ACBE4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;

typedef struct V3 { s32 x, y, z; } V3;

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
    s32 f10;
    s32 f14;
    u8 pad3[4];
    u32 *f1c;
    u32 f20;
    u8 pad4[0x14];
    Inner in;
} B;

extern u16 func_0216D5F8(u32 a);
extern void func_0219E784(u32 a, u32 b, s16 *out);
extern void func_0207CDB8(s16 *a, s16 *b);
extern void func_0216D8E0(u32 a, V3 *v);
extern void func_02197CCC(u32 a, V3 *v);
extern void func_021AC1CC(u32 a, V3 *v);
extern u32 func_021ABE18(u32 a);
extern void func_021C66EC(u32 a, u32 b, u32 c);
extern void func_0216D88C(u32 a, V3 *v);
extern s32 func_0207CF3C(const V3 *a, const V3 *b);
extern s32 func_021ACBE4(s32 d);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

void func_021ACFF8(u32 a, B *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    s16 f[3];
    s16 d[3];
    Inner *in;
    s32 dist;
    s32 r;

    if (b->f9 == 0)
        return;
    b->fc = func_0216D5F8(b->f20);
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
    func_02197CCC(b->f20, &w);
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
        func_021C66EC(func_021ABE18(*b->f1c), in->c, 0x1000);
        func_0216D88C(b->f20, &u);
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
