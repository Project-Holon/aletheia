/*
 * function: func_021AD274
 * address:  0x021AD274
 * packet:   pkt_ov021_021AD274
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_020521BC  0x020521BC  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   func_021C67F4  0x021C67F4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;

typedef struct V3 { s32 x, y, z; } V3;
typedef struct M33 { s32 m[9]; } M33;

typedef struct Node {
    V3 pos;
    V3 scale;
    M33 mtx;
} Node;

typedef struct Inner {
    u16 a;
    u16 b;
    u8 pad[0x18];
    u16 c;
    u16 pad2;
    V3 scale;
    V3 pos;
} Inner;

typedef struct B {
    u8 pad0[0xc];
    u16 fc;
    u8 pad1[0xa];
    u16 f18;
    u8 pad2[2];
    u32 *f1c;
    u32 f20;
    u8 pad3[0x14];
    Inner in;
} B;

extern void func_0219E784(u32 o, u32 idx, s16 *v);
struct Mtx33;
struct Vec3;
extern void func_020521BC(const struct Vec3 *v, struct Mtx33 *dst);
extern u32 func_021ABE18(u32 a);
extern int func_021C6658(u32 a, u32 b);
extern void func_021AC1B8(u32 a, Node *n);
extern void func_021C6678(u32 a, u32 b, u32 c);
extern void func_021C67F4(u32 a, u32 b);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

void func_021AD274(u32 a, B *b)
{
    V3 va;
    V3 vb;
    M33 ma;
    M33 mb;
    s16 f[3];
    Inner *in = &b->in;
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
    obj = func_021ABE18(*b->f1c);
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
