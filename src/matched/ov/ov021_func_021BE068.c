/*
 * function: func_021BE068
 * address:  0x021BE068
 * packet:   pkt_ov021_021BE068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE17C  0x021BE17C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BE194  0x021BE194  thumb  ov021
 *   func_021BE148  0x021BE148  thumb  ov021
 *   func_021BE1B0  0x021BE1B0  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE158  0x021BE158  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *
 * Twin of func_021BDFB0 with the pose block at a+0xC instead of a+0x2C.
 * A function-scope In pointer is what keeps the else-arm copy's
 * destination as (s+4)+8 in a fresh register; &s->in.pos folds to s+0xC.
 * The two rot/pos Vec writes are VEC_Set-style inline setters (arguments
 * evaluated right to left). The EXACT* is the 2-byte pad after the pop.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 f04;
    u16 f06;
    int f08;
    Vec pos;
    Vec rot;
} In;

static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

typedef struct {
    u32 f00;
    In  in;
    u8  sub[0x20];
    int f44;
    int f48;
} S;

typedef struct {
    u32 obj;
    u32 f04;
    S   s;
    u32 f54;
    u32 pad58[4];
    u32 f68;
    u32 f6C;
} A;

typedef struct {
    int f00, f04, f08, f0C, f10;
    Vec v1;
    Vec v2;
    int f2C, f30, f34, f38, f3C;
} Rec;

extern u32 func_021BE17C(A *a);
extern u32 func_02188CB4(u32 o);
extern void func_021A3050(u32 t);
extern int func_021BE194(A *a);
extern void func_021BE148(Rec *r, int id);
extern int func_021BE1B0(A *a);
extern void func_021A7B08(u32 o, Vec *v);
extern void func_021A3038(u32 t, Vec *v);
extern void func_021BE158(u32 h, Vec *v);
extern void func_0218FEA4(u32 p);
extern void func_0218FE78(u32 p, u8 *sub);
extern void func_0218FEC0(u32 p);

void func_021BE068(A *a)
{
    Vec v;
    Rec rec;
    u32 t;
    S *s = &a->s;
    u8 *sub = s->sub;
    In *in = &s->in;
    u32 h = func_021BE17C(a);

    t = func_02188CB4(a->obj);
    func_021A3050(t);
    func_021BE148(&rec, func_021BE194(a));
    s->f48 = rec.f3C;
    s->f44 = rec.f38;
    a->f68 = rec.f30;
    a->f6C = rec.f34;
    if (a->f6C == 0)
        return;
    if (func_021BE1B0(a) != 0)
        func_021A7B08(a->obj, &v);
    else
        func_021A3038(t, &v);
    if (s->f44 != 0 && func_021BE1B0(a) != 0)
        func_021BE158(h, &v);
    func_0218FEA4(a->f54);
    func_0218FE78(a->f04, sub);
    s->f00 = rec.f2C;
    in->f04 = rec.f04;
    in->f06 = rec.f08;
    in->f08 = rec.f0C << 12;
    vset(&in->rot, rec.v2.x << 12, rec.v2.y << 12, rec.v2.z << 12);
    if (rec.f10 != 0) {
        vset(&in->pos, rec.v1.x << 12, rec.v1.y << 12, rec.v1.z << 12);
    } else {
        in->pos = v;
    }
    if (a->f6C != 0)
        func_0218FEC0(a->f54);
}
