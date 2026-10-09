/*
 * file:     field_effect_p10.c
 * unit:     yes
 * function: func_021AAEC0, func_021AAF54, func_021AAFA0, func_021AAFC0, func_021AAFFC, func_021AB018, func_021AB070, func_021AB0AC, func_021AB0D4, func_021AB0F0, func_021AB0F8, func_021AB100, func_021AB11C, func_021AB140, func_021AB158, func_021AB164, func_021AB170, func_021AB17C, func_021AB188, func_021AB194, func_021AB1A0, func_021AB1AC, func_021AB1B8, func_021AB1C4, func_021AB1D0, func_021AB1DC, func_021AB1E8, func_021AB1F4, func_021AB200, func_021AB20C, func_021AB218, func_021AB224, func_021AB230, func_021AB23C, func_021AB250, func_021AB264, func_021AB270, func_021AB27C, func_021AB29C, func_021AB2BC, func_021AB2DC, func_021AB2E8, func_021AB2F8, func_021AB304, func_021AB310, func_021AB31C, func_021AB328, func_021AB334, func_021AB348, func_021AB358, func_021AB364, func_021AB370, func_021AB37C, func_021AB390, func_021AB3B0, func_021AB3D4, func_021AB3E0, func_021AB3EC, func_021AB3F8, func_021AB404, func_021AB410, func_021AB41C, func_021AB428, func_021AB434, func_021AB440, func_021AB44C, func_021AB458
 * address:  0x021AAEC0
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
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_02012A38  0x02012A38  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021ADAAC  0x021ADAAC  thumb
 *   func_021AC154  0x021AC154  thumb
 *   func_02005728  0x02005728  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D8E8A     0x021D8E8A  data  a2
 *   func_02188C84  0x02188C84  thumb
 *   func_02158768  0x02158768  thumb
 *   func_0218DAEC  0x0218DAEC  thumb
 */
struct Obj00020;
struct Ctx;
struct Rec;
struct BigObj;
typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Self_021AAEC0 {
    void *ctx;
} Self_021AAEC0;

typedef unsigned char  u8;

typedef unsigned int   u32_021AAEC0;

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent;

typedef struct Self_021AAF54 {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0c[4];
    void *f10;
} Self_021AAF54;

typedef struct {
    u8 b[0x10];
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    int pad[2];
    int f8;
} S_021AAEC0;

typedef struct D_021AAFA0 D_021AAFA0;

typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 pad[3];
} R;

typedef struct {
    int f0;
    char pad[0x5b0];
    int f5b4;
} D_021AAFC0;

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D_021AAFFC;

typedef unsigned int u32_021AB070;

typedef unsigned int u32_021AB0AC;

typedef struct {
    char pad[0x5bc];
    u16 h5bc;
} D_021AB070;

typedef struct {
    u32_021AB0AC f0;
    void *f4;
    int pad[2];
    D_021AB070 *f10;
} S_021AAFFC;

typedef unsigned int   u32_021AB0D4;

typedef signed short   s16;

typedef unsigned long u32_021AB0F0;

typedef unsigned long u32_021AB0F8;

typedef int BOOL;

typedef unsigned long u32_021AB100;

typedef unsigned long u32_021AB11C;

typedef unsigned int   u32_021AB140;

typedef signed char    s8;

typedef signed int     s32;

typedef unsigned long u32_021AB158;

typedef unsigned long u32_021AB164;

typedef unsigned long u32_021AB170;

typedef unsigned long u32_021AB17C;

typedef unsigned long u32_021AB188;

typedef unsigned long u32_021AB194;

typedef unsigned long u32_021AB23C;

typedef unsigned long u32_021AB250;

typedef unsigned long u32_021AB264;

typedef unsigned long u32_021AB270;

typedef unsigned long u32_021AB27C;

typedef unsigned long u32_021AAFFC;

typedef unsigned long u32;

extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void *func_02188C7C(u8 *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32_021AAEC0 *iter);
extern int func_0216D454(void *rec);
extern void *func_0216E3C4(void *p);
extern void func_0216D828(void *rec, Vec3s *out);
extern u32_021AAEC0 func_02012A38(const struct BigObj *p);
extern void func_02082BCC(void *p, int v, int n);
extern u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f);
extern void func_021AC154(int a);
extern unsigned long func_02005728(unsigned long v);
extern u16 func_02188C84(u8 *p);
extern int func_02158768(void *a0, u32_021AB0AC a1, int a2, u16 a3);
extern int func_0218DAEC(void *a, void *b, u32_021AB0D4 *out);
int func_021AAEC0(Self_021AAEC0 *self, int x, short y2, int z, int skip);
int func_021AAF54(Self_021AAF54 *self);
void func_021AAFA0(S_021AAEC0 *s, D_021AAFA0 *d);
void func_021AAFC0(int a, D_021AAFC0 *d, R *r);
void func_021AAFFC(D_021AAFFC *d);
unsigned short func_021AB018(void);
u16 func_021AB070(void);
void func_021AB0AC(S_021AAFFC *s, u16 v);
int func_021AB0D4(void *a, void *b);
u16 func_021AB0F0(u32_021AB0F0 attr);
u16 func_021AB0F8(u32_021AB0F8 attr);
BOOL func_021AB100(u32_021AB100 attr);
BOOL func_021AB11C(u32_021AB11C attr);
int func_021AB140(int x);
BOOL func_021AB158(u16 id);
BOOL func_021AB164(u16 id);
BOOL func_021AB170(u16 id);
BOOL func_021AB17C(u16 id);
BOOL func_021AB188(u16 id);
BOOL func_021AB194(u16 id);
int func_021AB1A0(int x);
BOOL sub_021AB1AC(u16 id);
BOOL sub_021AB1B8(u16 id);
BOOL sub_021AB1C4(u16 id);
BOOL sub_021AB1D0(u16 id);
BOOL sub_021AB1DC(u16 id);
BOOL sub_021AB1E8(u16 id);
BOOL sub_021AB1F4(u16 id);
BOOL sub_021AB200(u16 id);
BOOL sub_021AB20C(u16 id);
BOOL sub_021AB218(u16 id);
BOOL sub_021AB224(u16 id);
BOOL sub_021AB230(u16 id);
BOOL func_021AB23C(u16 id);
BOOL func_021AB250(u16 id);
BOOL func_021AB264(u16 id);
BOOL func_021AB270(u16 id);
BOOL func_021AB27C(u16 id);
BOOL func_021AB29C(u16 id);
BOOL func_021AB2BC(u16 id);
BOOL func_021AB2DC(u16 id);
BOOL func_021AB2E8(int id);
int func_021AB2F8(int x);
BOOL sub_021AB304(u16 id);
BOOL func_021AB310(u16 id);
BOOL func_021AB31C(u16 id);
BOOL func_021AB328(int id);
BOOL func_021AB334(u16 id);
BOOL func_021AB348(u32 id);
int func_021AB358(int x);
BOOL func_021AB364(u16 id);
BOOL func_021AB370(u16 id);
BOOL func_021AB37C(u32 id);
BOOL func_021AB390(u16 id);
BOOL func_021AB3B0(u16 id);
int func_021AB3D4(int x);
BOOL sub_021AB3E0(u16 id);
BOOL sub_021AB3EC(u16 id);
BOOL sub_021AB3F8(u16 id);
int func_021AB404(int x);
int func_021AB410(int x);
BOOL sub_021AB41C(u16 id);
BOOL sub_021AB428(u16 id);
BOOL sub_021AB434(u16 id);
BOOL sub_021AB440(u16 id);
BOOL sub_021AB44C(u16 id);
int func_021AB458(int id);
extern unsigned short d_021D8E8A[];






int func_021AAEC0(Self_021AAEC0 *self, int x, short y2, int z, int skip)
{
    Vec3s v;
    void *rec;
    unsigned long it = 0;
    void *list;
    void *cur;
    unsigned char *info;

    cur = func_021A3074(func_02188CB4(self->ctx));
    list = func_02188C7C(self->ctx);
    for (;;) {
        if (!func_0216DD1C(list, (struct Rec **)(&rec), (u32_021AAEC0 *)(&it)))
            break;
        if (!func_0216D454(rec))
            continue;
        if (rec == cur && skip)
            continue;
        info = func_0216E3C4(rec);
        func_0216D828(rec, &v);
        if (y2 != v.y)
            continue;
        if (x < v.x || x >= v.x + info[0xb])
            continue;
        if (z > v.z || z <= v.z - info[0xc])
            continue;
        return 1;
    }
    return 0;
}






int func_021AAF54(Self_021AAF54 *self)
{
    Ent *e = (Ent *)(func_02012A38(self->obj) + 0x10);

    if (e->flags == 0)
        return 0;
    if (func_021AAEC0((void *)self, e->x, e->y, e->z, 1)) {
        func_021AAFA0((void *)self, self->f10);
        return 1;
    }
    return 0;
}






void func_021AAFA0(S_021AAEC0 *s, D_021AAFA0 *d)
{
    T *t = (T *)func_02012A38((const struct BigObj *)s->f8);
    func_021AAFFC((void *)d);
    func_02082BCC(&t->sub, 0, 0x10);
}






void func_021AAFC0(int a, D_021AAFC0 *d, R *r)
{
    if (d->f5b4 == 0) {
        d->f5b4 = func_021ADAAC(a, (u8 *)d->f0, r->h2, r->h6, r->f8, r->bc);
        if (d->f5b4 == 0) {
            func_02082BCC(r, 0, 0x10);
        }
    }
}








void func_021AAFFC(D_021AAFFC *d)
{
    if (d->f5b4 != 0) {
        func_021AC154(d->f5b4);
        d->f5b4 = 0;
    }
}








unsigned short func_021AB018(void)
{
    unsigned short r = func_02005728(1000);

    if (r < 100)
        return d_021D8E8A[(unsigned short)(func_02005728(1000) / 100)];
    if (r < 950)
        return (unsigned short)((unsigned short)(func_02005728(1700) / 100) + 548);
    return 229;
}








u16 func_021AB070(void)
{
    if ((u16)func_02005728(1000) < 900) {
        return (u16)(func_02005728(600) / 100) + 565;
    }
    return 571;
}








void func_021AB0AC(S_021AAFFC *s, u16 v)
{
    s->f10->h5bc = v;
    func_02158768(s->f4, 0x2795, 0, func_02188C84((u8 *)s->f0));
}








/*
 * Runs the lookup func_0218DAEC into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB0D4(void *a, void *b)
{
    u32_021AB0D4 buf[4];

    if (func_0218DAEC(a, b, buf) == 1)
        return buf[2];
    return -1;
}








/*
 * Terrain-attribute accessor: the low half of the 32-bit attribute word a
 * map tile's 8-byte grid record carries at byte offset 4 (see
 * func_021D14C4, which hands that word to its caller verbatim with bit 31
 * cleared).  The low half is the terrain id; func_021AB0F8 is the matching
 * accessor for the high half, which is the flag half.
 *
 * A leaf that saves nothing, so disasm.py labels it only because a branch
 * elsewhere in ov021 targets it.
 */
u16 func_021AB0F0(u32_021AB0F0 attr)
{
    return (u16)attr;
}










/*
 * Terrain-attribute accessor: the high half of the tile attribute word,
 * the flag half.  bit 0 is the passable flag (func_021AB11C), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in func_021AB504.
 */
u16 func_021AB0F8(u32_021AB0F8 attr)
{
    return (u16)(attr >> 16);
}









/*
 * The tile attribute word is present at all: neither the all-ones no-tile
 * sentinel nor the 0xFF no-terrain id in its low half.
 */
BOOL func_021AB100(u32_021AB100 attr)
{
    u16 id;

    id = func_021AB0F0(attr);

    if (attr == 0xFFFFFFFF || id == 0xFF) {
        return 0;
    }

    return 1;
}









/*
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (func_021AB100) or when bit 0 of the flag half is set.
 */
BOOL func_021AB11C(u32_021AB11C attr)
{
    u16 flags;

    flags = func_021AB0F8(attr);

    if (!func_021AB100(attr) || (flags & 1)) {
        return 1;
    }

    return 0;
}








/*
 * Addresses are Black-image addresses.
 */
int func_021AB140(int x)
{
    if ((u16)(x + 0xFFF8) <= 1)
        return 1;
    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x74.
 */
BOOL func_021AB158(u16 id)
{
    if (id == 0x74) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x75.
 */
BOOL func_021AB164(u16 id)
{
    if (id == 0x75) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x73.
 */
BOOL func_021AB170(u16 id)
{
    if (id == 0x73) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x72.
 */
BOOL func_021AB17C(u16 id)
{
    if (id == 0x72) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x7c.
 */
BOOL func_021AB188(u16 id)
{
    if (id == 0x7c) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xd4.
 */
BOOL func_021AB194(u16 id)
{
    if (id == 0xd4) {
        return 1;
    }

    return 0;
}







int func_021AB1A0(int x)
{
    return x == 0xD6;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1AC(u16 id)
{
    if (id == 0xd7) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd8.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1B8(u16 id)
{
    if (id == 0xd8) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe2.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1C4(u16 id)
{
    if (id == 0xe2) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd9.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1D0(u16 id)
{
    if (id == 0xd9) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xda.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1DC(u16 id)
{
    if (id == 0xda) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdb.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1E8(u16 id)
{
    if (id == 0xdb) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdc.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1F4(u16 id)
{
    if (id == 0xdc) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdd.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB200(u16 id)
{
    if (id == 0xdd) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xde.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB20C(u16 id)
{
    if (id == 0xde) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdf.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB218(u16 id)
{
    if (id == 0xdf) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe0.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB224(u16 id)
{
    if (id == 0xe0) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe1.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB230(u16 id)
{
    if (id == 0xe1) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x4, 0x21, 0x5.
 */
BOOL func_021AB23C(u16 id)
{
    if (id == 0x4 || id == 0x21 || id == 0x5) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x6, 0x22, 0x7.
 */
BOOL func_021AB250(u16 id)
{
    if (id == 0x6 || id == 0x22 || id == 0x7) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x8.
 */
BOOL func_021AB264(u16 id)
{
    if (id == 0x8) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x9.
 */
BOOL func_021AB270(u16 id)
{
    if (id == 0x9) {
        return 1;
    }

    return 0;
}









/*
 * Terrain-id predicate: the union of the two families below.
 */
BOOL func_021AB27C(u16 id)
{
    if (func_021AB23C(id) == 1 || func_021AB264(id) == 1) {
        return 1;
    }

    return 0;
}








BOOL func_021AB29C(u16 id)
{
    if (func_021AB250(id) == 1 || func_021AB270(id) == 1) {
        return 1;
    }

    return 0;
}








BOOL func_021AB2BC(u16 id)
{
    if (func_021AB27C(id) == 1 || func_021AB29C(id) == 1) {
        return 1;
    }

    return 0;
}







/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1d.
 */
BOOL func_021AB2DC(u16 id)
{
    if (id == 0x1d) {
        return 1;
    }

    return 0;
}






/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x41, 0x44.
 */
BOOL func_021AB2E8(int id)
{
    if (id == 0x41 || id == 0x44) {
        return 1;
    }

    return 0;
}





/*
 * Two equality predicates.
 */
int func_021AB2F8(int x)
{
    return x == 0x14;
}








/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x17.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB304(u16 id)
{
    if (id == 0x17) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x40.
 */
BOOL func_021AB310(u16 id)
{
    if (id == 0x40) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xe.
 */
BOOL func_021AB31C(u16 id)
{
    if (id == 0xe) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xf.
 */
BOOL func_021AB328(int id)
{
    if (id == 0xf) {
        return 1;
    }

    return 0;
}









/*
 * Terrain-id predicate forwarding to func_021AB31C (id 0x0e).
 */
BOOL func_021AB334(u16 id)
{
    if (func_021AB31C(id)) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x18, 0x10.
 */
BOOL func_021AB348(u32 id)
{
    if (id == 0x18 || id == 0x10) {
        return 1;
    }

    return 0;
}







int func_021AB358(int x)
{
    return x == 0x10;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1c.
 */
BOOL func_021AB364(u16 id)
{
    if (id == 0x1c) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x19.
 */
BOOL func_021AB370(u16 id)
{
    if (id == 0x19) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xc, 0xb, 0x23.
 */
BOOL func_021AB37C(u32 id)
{
    if (id == 0xc || id == 0xb || id == 0x23) {
        return 1;
    }

    return 0;
}








/*
 * Terrain-id predicate: func_021AB370 (0x19) or func_021AB37C (0x0b, 0x0c, 0x23).
 */
BOOL func_021AB390(u16 id)
{
    if (func_021AB370(id) || func_021AB37C(id)) {
        return 1;
    }

    return 0;
}









/*
 * Terrain-id predicate: true for id 0x3d, 0x3e, 0x3f, 0x42 and 0x43.  The
 * compiler folds the last two arms into one (u16)(id - 0x42) <= 1 range test.
 */
BOOL func_021AB3B0(u16 id)
{
    if (id == 0x3d || id == 0x3e || id == 0x3f || id == 0x42 || id == 0x43) {
        return 1;
    }

    return 0;
}






int func_021AB3D4(int x)
{
    return x == 0x2;
}







/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x1e.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3E0(u16 id)
{
    if (id == 0x1e) {
        return 1;
    }

    return 0;
}






/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x30.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3EC(u16 id)
{
    if (id == 0x30) {
        return 1;
    }

    return 0;
}






/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x32.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3F8(u16 id)
{
    if (id == 0x32) {
        return 1;
    }

    return 0;
}



/*
 * Seven one-line equality predicates, one per constant.
 */
int func_021AB404(int x)
{
    return x == 0xBE;
}




int func_021AB410(int x)
{
    return x == 0xBF;
}




/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xc.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB41C(u16 id)
{
    if (id == 0xc) {
        return 1;
    }

    return 0;
}




/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x5.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB428(u16 id)
{
    if (id == 0x5) {
        return 1;
    }

    return 0;
}




/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB434(u16 id)
{
    if (id == 0x7) {
        return 1;
    }

    return 0;
}




/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x1b.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB440(u16 id)
{
    if (id == 0x1b) {
        return 1;
    }

    return 0;
}




/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x33.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB44C(u16 id)
{
    if (id == 0x33) {
        return 1;
    }

    return 0;
}



int func_021AB458(int id)
{
    if (id == 0x53 || (unsigned short)(id + 0xFFAB) <= 1)
        return 1;
    return 0;
}
