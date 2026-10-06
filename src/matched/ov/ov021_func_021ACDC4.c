/*
 * function: func_021ACDC4
 * address:  0x021ACDC4
 * packet:   pkt_ov021_021ACDC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
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

extern void func_021ACCB0(u32 a, B *b);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D598(void *p);
extern void func_0216D8E0(u32 a, V3 *v);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_021AC1CC(u32 a, V3 *v);
extern u32 func_021ABE18(u32 a);
extern int func_021C66EC(u32 *a, int idx, int v);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
struct E;
extern int func_021ACC04(struct E *a, struct E *b, u32 mode);
extern s32 func_021ACBE4(s32 d);

void func_021ACDC4(u32 a, B *b)
{
    V3 v = {0, 0, 0};
    V3 w;
    V3 u;
    Inner *in;
    s32 d;
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
    func_02197CCC((u8 *)b->f20, (s32 *)(&w));
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
        func_021C66EC((u32 *)func_021ABE18(*b->f1c), in->c, 0x1000);
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
