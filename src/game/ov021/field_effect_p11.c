/*
 * file:     field_effect_p11.c
 * unit:     yes
 * function: func_021AB4B8, func_021AB4EC, func_021AB4F8, func_021AB504, func_021AB580, func_021AB5AC, func_021AB5F4, func_021AB624, func_021AB634, func_021AB650, func_021AB660, func_021AB75C, func_021AB760, func_021AB764, func_021AB768, func_021AB780, func_021AB798, func_021AB7C0, func_021AB7E4, func_021AB81C, func_021AB840, func_021AB868, func_021AB880, func_021AB884, func_021AB888, func_021AB890, func_021AB908, func_021AB9FC, func_021ABA3C, func_021ABABC, func_021ABB54, func_021ABB78, func_021ABBA0, func_021ABBF0
 * address:  0x021AB4B8
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
 *   func_021AB140  0x021AB140  thumb
 *   func_021AB404  0x021AB404  thumb
 *   func_021AB410  0x021AB410  thumb
 *   func_021AB328  0x021AB328  thumb
 *   data_021D8EA0  0x021D8EA0  data
 *   data_021D8EA1  0x021D8EA1  data
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB11C  0x021AB11C  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DDFC8  0x021DDFC8  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE000  0x021DE000  data  a4
 *   d_021D8EEC  0x021D8EEC  data  a4
 *   func_02049238  0x02049238  arm
 *   func_0204A39C  0x0204A39C  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   d_021D8EF4  0x021D8EF4  data  a4
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218E124  0x0218E124  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   tbl_020A1B38   0x020A1B38  data  a2
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   FX_Div         0x0207C768  arm
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   func_0218F0D4  0x0218F0D4  thumb
 *   func_0218F05C  0x0218F05C  thumb
 *   func_021ABC5C  0x021ABC5C  thumb  ov021
 *   func_021ABD08  0x021ABD08  thumb  ov021
 */
#include "../../matched/include/Obj18074.h"
#include "../../matched/include/Obj18075.h"
#include "../../matched/include/Obj18076.h"
#include "../../matched/include/Obj12093.h"
#include "../../matched/include/Obj12094.h"
#include "../../matched/include/Obj18077.h"
#include "../../matched/include/Obj18078.h"
#include "../../matched/include/Obj04239.h"
#include "../../matched/include/Obj00757.h"

typedef unsigned short u16;

typedef int BOOL;

typedef unsigned long u32_021AB504;

typedef unsigned char  u8;

typedef unsigned int   u32_021AB580;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32_021AB4B8;

typedef struct {
    int f0;
    int f4;
    int pad8[3];
    int f14;
    int f18;
    int pad1c;
} S_021AB4B8;

typedef unsigned int   u32;

typedef struct {
    int pad[2];
    int f8;
    int fc;
    int f10;
    int f14;
} S_021AB634;

struct Rec {
    u8 pad00[0x40];
    u16 f40;
    u16 f42;
    u16 f44;
    u16 f46;
};

struct Obj {
    u8 pad00[8];
    struct Rec *recs;
    void *f0C;
    u32 count;
    int cur;
    int f18;
    u32 f1C;
};

typedef int (*Fn_021AB798)(int a, int b, int c);

typedef struct {
    Fn_021AB798 *f0;
    Fn_021AB798 *f4;
} S_021AB768;

typedef void (*Fn_021AB7C0)(int a, int b, int c);

typedef struct {
    int pad[2];
    int f8[2];
} S_021AB7E4;

typedef struct {
    int f0;
    u32 f4;
    int f8[2];
} S_021AB840;

typedef struct {
    void *f0;
    int f4;
} S_021AB868;

typedef struct Vec_021AB4B8 { int x, y, z; } Vec_021AB4B8;

typedef struct Range { unsigned long lo, hi; int min, max; Vec_021AB4B8 dir; } Range;

typedef int            s32_021AB908;

typedef struct Vec_021AB908 { s32_021AB908 x, y, z; } Vec_021AB908;

typedef struct {
    int x;
    int y;
    int z;
} V;

typedef struct {
    int pad[9];
    V f24;
    V f30;
} S_021AB908;

typedef long long s64;

typedef struct {
    int pad[7];
    int f1c;
} S_021ABB54;

extern int func_021AB140(int id);
extern int func_021AB404(int id);
extern int func_021AB410(int id);
extern int func_021AB328(int id);
extern unsigned short func_021AB0F0(unsigned long attr);
extern unsigned short func_021AB0F8(unsigned long attr);
extern int func_021AB11C(unsigned long attr);
extern int func_021AB2E8(int id);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(int a);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void func_0207CA00(const Vec_021AB4B8 *a, const Vec_021AB4B8 *b, Vec_021AB4B8 *out);
extern int func_0207CBD0(const Vec_021AB4B8 *v);
extern void func_0207CCA4(const Vec_021AB4B8 *v, Vec_021AB4B8 *out);
extern unsigned long func_0207CFB8(int x, int z);
extern void func_0218E124(u8 *a, u32 s);
extern void func_0218EC90(u32 a, Vec_021AB908 *v);
extern void func_0218ECF4(u32 a, Vec_021AB908 *v);
extern u32 func_02188CFC(u8 *p);
extern int FX_Div(int a, int b);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218F0D4(u8 *a, int b);
extern void func_0218F05C(unsigned char *a);
extern void func_021ABC5C(u8 *a0, char *p, void *q);
extern u32 func_021ABD08(u32, u32, u32);
int func_021AB4B8(int id);
BOOL sub_021AB4EC(u16 id);
BOOL sub_021AB4F8(u16 id);
int func_021AB504(u32_021AB504 attr);
u8 func_021AB580(u16 x);
int func_021AB5AC(unsigned long a, unsigned long b);
S_021AB4B8 *func_021AB5F4(int heap, int a, int b);
void func_021AB624(u8 *p);
void func_021AB634(S_021AB634 *s, int a, int b, int c);
void func_021AB650(S_021AB634 *s);
int func_021AB660(struct Obj *o, void *arg);
void func_021AB75C(u8 *p, u32 v);
u32 func_021AB760(u8 *p);
u32 func_021AB764(u8 *p);
int func_021AB768(u32 a, u32 b);
int func_021AB780(u32 a, u32 b);
int func_021AB798(S_021AB768 *s, int i, int a, int b, int c);
void func_021AB7C0(S_021AB768 *s, int i, int a, int b, int c);
S_021AB7E4 *func_021AB7E4(int heap);
void func_021AB81C(S_021AB7E4 *s);
void func_021AB840(S_021AB840 *s, int i, int b, int d);
void func_021AB868(S_021AB868 *s);
u32 func_021AB880(u8 *p);
u32 func_021AB884(u8 *p);
void *func_021AB888(void);
int func_021AB890(void *self, const Range *r, Vec_021AB4B8 *ref);
void func_021AB908(u32 a0, const u8 *p, const Vec_021AB908 *q);
void func_021AB9FC(int a, const S_021AB908 *s);
int func_021ABA3C(int a, const u16 *r, V *v);
void func_021ABABC(int a0, const u16 *p, void *q);
void func_021ABB54(int a, S_021ABB54 *s, int c);
void func_021ABB78(int a, S_021ABB54 *s, int c);
void func_021ABBA0(u16 *r, V *v, int *o1, int *o2);
int func_021ABBF0(u8 *a, u32 b, u32 c, u32 d);
extern const u8 data_021D8EA0[];
extern const u8 data_021D8EA1[];
extern char d_021DDFC8[];
extern char d_021DE000[];
extern const int d_021D8EEC[];
extern s16 tbl_020A1B38[];







int func_021AB4B8(int id)
{
    if (func_021AB140(id) || func_021AB404(id) || func_021AB410(id) || func_021AB328(id))
        return 1;
    return 0;
}







/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x21.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB4EC(u16 id)
{
    if (id == 0x21) {
        return 1;
    }

    return 0;
}







/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x22.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB4F8(u16 id)
{
    if (id == 0x22) {
        return 1;
    }

    return 0;
}







/*
 * Terrain class of a tile attribute word, for the encounter-effect lane.
 * Its one caller, func_021AACD4 in effect_encount.c, drops the tile when
 * the answer is 8 and otherwise stores the class byte in its per-tile
 * candidate list, so 8 is "no effect".  Note the flag-half gate: unless
 * bit 2 of the high half is set, every id falls through to 8, which is why
 * the overwhelmingly common 0x0081 flag half never produces a class.
 *
 * The two half accessors are func_021AB0F0/func_021AB0F8 inlined.
 */
int func_021AB504(u32_021AB504 attr)
{
    u16 id = (u16)attr;
    u16 flags = (u16)(attr >> 16);

    if (id == 0x20) {
        return 7;
    }

    if (!(flags & 4)) {
        return 8;
    }

    switch (id) {
    case 4:
        return 0;
    case 5:
        return 1;
    case 0x21:
        return 2;
    case 8:
        return 3;
    case 10:
        return 4;
    case 0x3d:
        return 5;
    case 0x3f:
    case 0x43:
        return 6;
    }

    return 8;
}







/*
 * Addresses are Black-image addresses.
 */
u8 func_021AB580(u16 x)
{
    u32_021AB580 i;

    for (i = 0; i < 0x25; i++) {
        if (x == data_021D8EA0[i * 2])
            return data_021D8EA1[i * 2];
    }
    return 0;
}







int func_021AB5AC(unsigned long a, unsigned long b)
{
    unsigned short lo = func_021AB0F8(b);
    unsigned short hi = func_021AB0F0(b);

    if (func_021AB11C(a))
        return 0;
    if (((lo & 2) && !func_021AB11C(b)) || func_021AB2E8(hi))
        return 1;
    return 0;
}






S_021AB4B8 *func_021AB5F4(int heap, int a, int b)
{
    S_021AB4B8 *p = func_02030734((u16)heap, 0x20, 1, d_021DDFC8, 0x51);
    p->f0 = a;
    p->f4 = b;
    p->f14 = -1;
    p->f18 = 1;
    return p;
}






/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB624(u8 *p)
{
    func_021AB650((void *)p);
    func_020307B0(p);
}






void func_021AB634(S_021AB634 *s, int a, int b, int c)
{
    func_021AB650(s);
    s->f8 = a;
    s->fc = c;
    s->f10 = b;
    s->f14 = -1;
}






void func_021AB650(S_021AB634 *s)
{
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = -1;
}






/*
 * The loop's id load is spelled as byte-base + i * sizeof + 0x40: with
 * o->recs[i].f40, (o->recs + i)->f40, a Rec * local, a recs local, a
 * u16 ids[4] member or a cast through &o->recs[i], the records base and the
 * i * 0x48 product swap r3/r6 (7 bytes); int i and declaration order do
 * not move it.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB660(struct Obj *o, void *arg)
{
    u32 i;
    int sel;

    if (o->f18 == 0)
        return -1;
    o->f1C = 0xFFFF;
    sel = -1;
    for (i = 0; i < o->count; i++) {
        if (func_021AB798((S_021AB768 *)o->f0C, *(u16 *)((u8 *)o->recs + i * sizeof(struct Rec) + 0x40), (int)o, (int)(&o->recs[i]), (int)arg))
            sel = i;
    }
    if (sel != o->cur) {
        if (o->cur != -1) {
            func_021AB7C0((S_021AB768 *)o->f0C, o->recs[o->cur].f46, (int)o, (int)(&o->recs[o->cur]), (int)arg);
            o->f1C = o->recs[o->cur].f46;
        }
        if (sel != -1) {
            func_021AB7C0((S_021AB768 *)o->f0C, o->recs[sel].f44, (int)o, (int)(&o->recs[sel]), (int)arg);
            o->f1C = o->recs[sel].f44;
        }
        o->cur = sel;
    } else if (o->cur != -1) {
        func_021AB7C0((S_021AB768 *)o->f0C, o->recs[o->cur].f42, (int)o, (int)(&o->recs[o->cur]), (int)arg);
        o->f1C = o->recs[o->cur].f42;
    }
    return o->cur;
}






/*
 * Field setter at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB75C(u8 *p, u32 v)
{
    ((struct Obj18074 *)p)->f18 = v;
}






/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021AB760(u8 *p)
{
    return ((struct Obj18075 *)p)->f0;
}






/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021AB764(u8 *p)
{
    return ((struct Obj18076 *)p)->f4;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB768(u32 a, u32 b)
{
if (((struct Obj12093 *)((u8 *)(a)))->f8 > b) {
    if (*(u32 *)((u8 *)(((struct Obj12093 *)((u8 *)(a)))->f0) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}






int func_021AB780(u32 a, u32 b)
{
if (((struct Obj12094 *)((u8 *)(a)))->fA > b) {
    if (*(u32 *)((u8 *)(((struct Obj12094 *)((u8 *)(a)))->f4) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}






int func_021AB798(S_021AB768 *s, int i, int a, int b, int c)
{
    if (func_021AB768((u32)s, i)) {
        return s->f0[i](a, b, c);
    }
    return 0;
}






void func_021AB7C0(S_021AB768 *s, int i, int a, int b, int c)
{
    if (func_021AB780((u32)s, i)) {
        s->f4[i](a, b, c);
    }
}






S_021AB7E4 *func_021AB7E4(int heap)
{
    S_021AB7E4 *p = func_02030734(heap, 0x10, 1, d_021DE000, 0x81);
    int i;
    for (i = 0; i < 2; i++) {
        p->f8[i] = (int)func_020490F4(d_021D8EEC[i], heap);
    }
    return p;
}






void func_021AB81C(S_021AB7E4 *s)
{
    int i;
    func_021AB868((void *)s);
    for (i = 0; i < 2; i++) {
        func_02049238(s->f8[i]);
    }
    func_020307B0(s);
}






void func_021AB840(S_021AB840 *s, int i, int b, int d)
{
    u32 out;
    s->f0 = (int)func_0204A39C((void *)s->f8[i], b, 0, d, &out);
    s->f4 = out / 0x48;
}






void func_021AB868(S_021AB868 *s)
{
    if (s->f0 != 0) {
        func_020307B0(s->f0);
        s->f0 = 0;
        s->f4 = 0;
    }
}






u32 func_021AB880(u8 *p)
{
    return ((struct Obj18077 *)p)->f0;
}






u32 func_021AB884(u8 *p)
{
    return ((struct Obj18078 *)p)->f4;
}





void *func_021AB888(void)
{
    return (void *)0x021D8EF4;
}






static inline void VecSet(Vec_021AB4B8 *v, int x, int y, int z) { v->x = x; v->y = y; v->z = z; }






/*
 * Lever: `const Range *` together with the inline VecSet helper gives the
 * y, x, z load order of the 12-byte vector fill; either alone does not.
 */
int func_021AB890(void *self, const Range *r, Vec_021AB4B8 *ref)
{
    Vec_021AB4B8 out;
    Vec_021AB4B8 a;
    int d;
    unsigned long ang;

    VecSet(&a, r->dir.x, r->dir.y, r->dir.z);
    func_0207CA00((const Vec_021AB4B8 *)ref, (const Vec_021AB4B8 *)&a, (Vec_021AB4B8 *)&out);
    out.y = 0;
    d = func_0207CBD0((const Vec_021AB4B8 *)&out);
    func_0207CCA4((const Vec_021AB4B8 *)&out, (Vec_021AB4B8 *)&out);
    ang = func_0207CFB8(out.x, out.z);
    if (r->min <= d && r->max > d) {
        if (r->hi < r->lo) {
            if (r->hi >= ang || (ang < 0x10000 && ang >= r->lo))
                return 1;
        } else {
            if (r->lo <= ang && r->hi > ang)
                return 1;
        }
    }
    return 0;
}




static inline s32_021AB908 FX_Mul(s32_021AB908 a, s32_021AB908 b)
{
    return (s32_021AB908)(((long long)a * b + 0x800LL) >> 12);
}




/*
 * Lever (wave A3): the position is copied field by field with its y kept in
 * the vector (`a.y = p->y`), y is saved by reading it back (`y = a.y`), and
 * a.y is zeroed before the copy of *q. The read keeps the first a.y store
 * alive and puts the zero ahead of the q copy, which gives the colouring
 * (y r7, zero r6, table r4) and lets the final a.y reload become `mov r1, r7`.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB908(u32 a0, const u8 *p, const Vec_021AB908 *q)
{
    Vec_021AB908 b;
    Vec_021AB908 a;
    Vec_021AB908 n;
    Vec_021AB908 out;
    u32 obj;
    s32_021AB908 y;
    s32_021AB908 c;
    s16 t0;
    s16 t1;

    obj = func_021AB760((u8 *)a0);
    func_0218E124((u8 *)obj, 2);
    a.x = *(const s32_021AB908 *)&((struct Obj04239 *)p)->f10;
    a.y = *(const s32_021AB908 *)&((struct Obj04239 *)p)->f14;
    a.z = *(const s32_021AB908 *)&((struct Obj04239 *)p)->f18;
    y = a.y;
    a.y = 0;
    b = *q;
    b.y = 0;
    func_0207CA00((const Vec_021AB4B8 *)&b, (const Vec_021AB4B8 *)&a, (Vec_021AB4B8 *)&b);
    func_0207CCA4((const Vec_021AB4B8 *)&b, (Vec_021AB4B8 *)&n);
    t0 = tbl_020A1B38[(*(const s32_021AB908 *)&((struct Obj04239 *)p)->f1C >> 4) * 2];
    a.y = y;
    out.y = FX_Mul(t0, *(const s32_021AB908 *)&((struct Obj04239 *)p)->f20);
    t1 = tbl_020A1B38[(*(const s32_021AB908 *)&((struct Obj04239 *)p)->f1C >> 4) * 2 + 1];
    c = FX_Mul(t1, *(const s32_021AB908 *)&((struct Obj04239 *)p)->f20);
    out.x = FX_Mul(n.x, c);
    out.z = FX_Mul(n.z, c);
    out.x += a.x;
    out.y += a.y;
    out.z += a.z;
    func_0218EC90(obj, (Vec_021AB908 *)&a);
    func_0218ECF4(obj, (Vec_021AB908 *)&out);
}






static inline void set3(V *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}





/*
 * Lever: `const S *` together with the inline set3 helper gives the y, x, z
 * load order of the two 12-byte vector fills (as in ov021_func_021AB890.c).
 */
void func_021AB9FC(int a, const S_021AB908 *s)
{
    int h = func_021AB760((u8 *)a);
    V v1;
    V v0;

    func_0218E124((u8 *)h, 2);
    set3(&v1, s->f24.x, s->f24.y, s->f24.z);
    set3(&v0, s->f30.x, s->f30.y, s->f30.z);
    func_0218EC90(h, (Vec_021AB908 *)((void *)&v1));
    func_0218ECF4(h, (Vec_021AB908 *)((void *)&v0));
}






/*
 * Lever: `const u16 *r` sinks the t.z spill store below the first shift pair
 * (const on the vector source alone does not).
 */
int func_021ABA3C(int a, const u16 *r, V *v)
{
    V t;
    u16 px;
    u16 pz;
    int w;
    int h;

    if (func_02188CFC((u8 *)func_021AB764((u8 *)a)) == 1)
        return 0;
    t = *v;
    t.x -= 0x8000;
    t.z -= 0x8000;
    px = (t.x >> 12) / 16;
    pz = (t.z >> 12) / 16;
    w = r[2];
    if (w == 1) {
        w = r[4];
        h = r[3];
    } else {
        h = r[4];
    }
    if (px >= r[0] && px < r[0] + w && pz >= r[1] && pz < r[1] + h)
        return 1;
    return 0;
}






/*
 * const on p lets the three loads from p schedule above the store of t to the
 * address-taken d (docs/idioms/a-const-parameter-hoists-field-loads-above-a-
 * call-result-store-into-an-address-taken-local.md). One reused temporary v
 * keeps the quotient on the left of each add and stops x and y being
 * forward-substituted into their calls; z, the last, is.
 */
void func_021ABABC(int a0, const u16 *p, void *q)
{
    int h = func_021AB760((u8 *)a0);
    int s;
    int d;
    int t;
    int x, y, z;
    int v;

    func_0218E124((u8 *)h, 0);
    func_021ABBA0((void *)p, q, &s, &d);
    d = t = FX_Div(d, s);
    v = p[10] - p[6];
    v = v * t / 4096;
    x = v + p[6];
    v = p[11] - p[7];
    v = v * t / 4096;
    y = v + p[7];
    v = *(const int *)&((struct Obj00757 *)p)->f18 - *(const int *)&((struct Obj00757 *)p)->f10;
    v = (int)(((s64)v * t + 0x800) >> 12);
    z = v + *(const int *)&((struct Obj00757 *)p)->f10;
    func_0218ED34((u8 *)h, x);
    func_0218ED48((u8 *)h, (u16)y);
    func_0218ED58((u8 *)h, z);
}




void func_021ABB54(int a, S_021ABB54 *s, int c)
{
    int h = func_021AB760((u8 *)a);
    if (s->f1c != 0) {
        func_0218F0D4((u8 *)h, s->f1c);
    }
    func_021ABABC(a, (const u16 *)s, (void *)c);
}




void func_021ABB78(int a, S_021ABB54 *s, int c)
{
    int h = func_021AB760((u8 *)a);
    func_021ABABC(a, (const u16 *)s, (void *)c);
    if (s->f1c != 0) {
        func_0218F05C((unsigned char *)h);
    }
}




void func_021ABBA0(u16 *r, V *v, int *o1, int *o2)
{
    V t = *v;

    t.x -= 0x8000;
    t.z -= 0x8000;
    *o1 = r[4] << 16;
    if (r[2] == 1)
        *o2 = t.x - (r[0] << 16);
    else
        *o2 = t.z - (r[1] << 16);
}




int func_021ABBF0(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABABC((int)a, (const u16 *)b, (void *)c);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08((u32)a, b, c);
}
