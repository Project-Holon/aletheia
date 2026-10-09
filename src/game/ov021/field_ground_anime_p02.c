/*
 * file:     field_ground_anime_p02.c
 * unit:     yes
 * function: func_021A7678, func_021A77E8, func_021A7818, func_021A78DC, func_021A78EC, func_021A797C, func_021A79E4, func_021A7A28, func_021A7A34, func_021A7A40, func_021A7A88, func_021A7A8C, func_021A7A90, func_021A7AB0, func_021A7B08, func_021A7B10, func_021A7B20, func_021A7B88
 * address:  0x021A7678
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
 *   func_02046C94  0x02046C94  arm
 *   func_02030734  0x02030734  arm
 *   func_02046CE0  0x02046CE0  arm
 *   d_021DDF7C     0x021DDF7C  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   func_02061CA4  0x02061CA4  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02047250  0x02047250  arm
 *   func_0206E7EC  0x0206E7EC  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   d_021D8B08     0x021D8B08  data  a2
 *   d_021D8B00     0x021D8B00  data  a1
 *   func_021A811C  0x021A811C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_021A80FC  0x021A80FC  thumb  ov021
 *   func_021BDC94  0x021BDC94  thumb  ov021
 *   func_021A810C  0x021A810C  thumb  ov021
 *   func_021A8214  0x021A8214  thumb  ov021
 *   func_021A7CE8  0x021A7CE8  thumb  ov021
 *   func_021A8268  0x021A8268  thumb  ov021
 *   func_02162370  0x02162370  thumb  ov010
 */
#include "../../matched/include/Obj18065.h"
#include "../../matched/include/Obj18066.h"
#include "../../matched/include/Obj18067.h"
#include "../../matched/include/Obj12760.h"

struct Out;
struct S02046CE0;
struct V3;
struct Obj00020;
struct Desc;
struct Obj;
struct BigObj;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct Pair { u8 lo; u8 hi; } Pair;

typedef struct Obj {
    u32 f00;
    Pair *f04;
    s32 *f08;
    u32 *f0C;
    s32 *f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x1C];
    void *f3C;
} Obj;

typedef struct {
    int f0;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
    int pad14[2];
    int f1c;
    int pad20[7];
    void *f3c;
} E;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Dict {
    u8 rev;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} Dict;

typedef struct DictEntryHdr {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} DictEntryHdr;

typedef struct Res_021A7678 {
    u8 pad00[8];
    u32 f08;
    u8 pad0C[8];
    u32 f14;
    u8 pad18[0x3C - 0x18];
    Dict dict;
} Res_021A7678;

typedef struct Tbl {
    u16 *keys;
    u8 *lo;
    u8 *hi;
    u8 *group;
    u32 limit;
    u32 count;
} Tbl;

typedef struct Out {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
} Out;

typedef struct Work_021A79E4 {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x28 - 0x1B];
    int f28;
    u8 pad2C[0x36 - 0x2C];
    u8 f36;
} Work_021A79E4;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args;

typedef struct Work_021A7B88 {
    Args *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x2C - 0x1B];
    u8 step[9];
} Work_021A7B88;

extern int func_02046C94(void);
extern void *func_02030734(u16 heap, u32 size, u32 one, char *file, u32 line);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern u32 func_020307B0(void *p);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern Res_021A7678 *func_02047250(void *p);
extern int func_0206E7EC(const Dict *d, const void *name);
extern u32 func_0209C2B0(u32 a, u32 b);
extern int func_021A811C(u32 a, u32 b);
extern void *func_0216D4B4(char *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02012A30(const struct BigObj *p);
extern int func_021A80FC(u32 a);
extern void *func_021BDC94(void *p);
extern void func_021A810C(struct Obj00020 *p, struct VecFx32 *out);
extern void func_021A8214(Work_021A79E4 *w);
extern int func_021A7CE8(void *task, int *state, struct Work_021A79E4 *w);
extern int func_021A8268(u32 a);
extern int func_02162370(int a);
void func_021A7678(Obj *o, u32 a, u32 b, u32 c, u16 heap);
void func_021A77E8(E *e);
void func_021A7818(Obj *a, s32 dt);
int func_021A78DC(u32 a);
int func_021A78EC(void *a, void *b, u32 idx);
u32 func_021A797C(void *a, u32 idx);
u8 *func_021A79E4(void *a, u32 idx);
int func_021A7A28(u32 a, u32 b);
int func_021A7A34(u32 a, u32 b);
Pair func_021A7A40(const Tbl *t, u32 idx, u32 key);
u32 func_021A7A88(u8 *p);
u32 func_021A7A8C(u8 *p);
u16 func_021A7A90(Tbl *s, int i);
void func_021A7AB0(u32 *src, Out *o);
void func_021A7B08(int a, struct V3 *b);
int func_021A7B10(void *a);
void *func_021A7B20(Args *a);
void func_021A7B88(Work_021A7B88 *w);
extern char d_021DDF7C;
extern const u16 d_021D8B08[];
extern const u8 d_021D8B00[];





/*
 * Initialiser for the animation object func_021A7818 steps: allocates the
 * per-track arrays and seeds each track's frame Pair and minimum key.
 * The heap id is u16 in both this signature and func_02030734's: with u32
 * the stack-argument load drops from the first instruction to after the
 * register copies (docs/idioms/a-narrow-parameter-pins-its-home-store-to-
 * the-front-of-the-prologue.md, here for a load).
 */
void func_021A7678(Obj *o, u32 a, u32 b, u32 c, u16 heap)
{
    u32 i;
    s32 j;
    s32 n;
    u8 m;
    Pair t;

    o->f18 = c;
    o->f1C = func_021A7A28(a, b);
    func_021A7AB0((u32 *)o->f1C, (struct Out *)o->f20);
    o->f3C = func_02030734(heap, func_02046C94(), 1, &d_021DDF7C, 0x2c9);
    func_02046CE0(o->f3C, (u32 *)func_021A7A34(a, b));
    o->f14 = func_021A7A88(o->f20);
    o->f04 = func_02030734(heap, o->f14 * 2, 1, &d_021DDF7C, 0x2d4);
    o->f08 = func_02030734(heap, o->f14 * 4, 1, &d_021DDF7C, 0x2d5);
    o->f0C = func_02030734(heap, o->f14 * 4, 1, &d_021DDF7C, 0x2d6);
    o->f10 = func_02030734(heap, o->f14 * 4, 1, &d_021DDF7C, 0x2d7);
    for (i = 0; i < o->f14; i++) {
        o->f04[i] = func_021A7A40((const Tbl *)o->f20, i, 0);
        n = func_021A7A90((Tbl *)o->f20, i);
        m = o->f04[i].lo;
        for (j = 0; j < n; j++) {
            t = func_021A7A40((const Tbl *)o->f20, i, j);
            if (m > t.lo) {
                m = t.lo;
            }
        }
        o->f08[i] = func_021A78EC((void *)c, o->f3C, m);
        o->f0C[i] = func_021A797C(o->f3C, m);
    }
    o->f00 = 1;
}





void func_021A77E8(E *e)
{
    if (e->f1c != 0) {
        func_020307B0(e->f4);
        func_020307B0(e->f8);
        func_020307B0(e->fc);
        func_020307B0(e->f10);
        func_020307B0(e->f3c);
        e->f1c = 0;
        e->f3c = 0;
    }
}





/*
 * Addresses are Black-image addresses.
 * func_021A7A40 returns its two-byte Pair by value in r0 (see its matched
 * file): the call result is spilled to a compiler temporary at sp+0x14 and
 * copied into t at sp+0x16, and every later use reads t. An inline unpack
 * of a u16 return forwards the copy and reads the temporary instead.
 */
void func_021A7818(Obj *a, s32 dt)
{
    s32 lim;
    u32 i;
    Pair t;

    if (a->f1C == 0)
        return;
    lim = func_021A7A8C(a->f20) << 12;
    for (i = 0; i < a->f14; i++) {
        a->f10[i] += dt;
        if (a->f10[i] >= lim) {
            a->f10[i] %= lim;
        } else if (a->f08[i] != -1) {
            t = func_021A7A40((const Tbl *)a->f20, i, a->f10[i] >> 12);
            if (t.lo != a->f04[i].lo || a->f00)
                func_02061CA4(0, a->f08[i], (u32)func_021A79E4(a->f3C, t.lo), a->f0C[i]);
            a->f04[i] = t;
        }
    }
    a->f00 = 0;
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A78DC(u32 a)
{
if (((struct Obj18065 *)((u8 *)(a)))->f1C != 0) {
    return 1;
}
return 0;
}




static inline void *DictGetByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}




static inline void *DictGetNameByIdx(const Dict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const DictEntryHdr *h = (const DictEntryHdr *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h + h->ofsName + idx * 16);
    }
    return 0;
}




int func_021A78EC(void *a, void *b, u32 idx)
{
    Res_021A7678 *ra;
    Res_021A7678 *rb;
    void *name;
    int k;
    u32 *e;

    ra = func_02047250(a);
    rb = func_02047250(b);
    name = rb ? DictGetNameByIdx(&rb->dict, idx) : 0;
    if (ra) {
        k = func_0206E7EC(&ra->dict, name);
    } else {
        k = -1;
    }
    if (k < 0) {
        return -1;
    }
    e = ra ? DictGetByIdx(&ra->dict, k) : 0;
    return ((*e << 16) >> 13) + ((ra->f08 << 16) >> 13);
}



u32 func_021A797C(void *a, u32 idx)
{
    Res_021A7678 *r;
    u32 *e;
    u32 v;

    r = func_02047250(a);
    e = r ? DictGetByIdx(&r->dict, idx) : 0;
    v = *e;
    return func_0209C2B0(d_021D8B08[(v & 0x700000) >> 20] * d_021D8B08[(v & 0x3800000) >> 23], d_021D8B00[(v & 0x1C000000) >> 26]);
}








u8 *func_021A79E4(void *a, u32 idx)
{
    Res_021A7678 *r;
    u32 *e;

    r = func_02047250(a);
    e = r ? DictGetByIdx(&r->dict, idx) : 0;
    return (u8 *)r + r->f14 + ((*e & 0xFFFF) << 3);
}








int func_021A7A28(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 3))) + 4));
}








int func_021A7A34(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 3))) + 8));
}








/*
 * Levers: the 2-byte struct returned by value (stack stores, reload of byte 0),
 * `*(g + idx + 1)` for the (g+idx)[1] address, and `const Tbl *` so the
 * t->hi load schedules above the first store.
 */
Pair func_021A7A40(const Tbl *t, u32 idx, u32 key)
{
    Pair r;
    u8 *g;
    u32 n;
    u32 i;
    u32 end;

    g = t->group;
    n = t->count;
    i = g[idx];
    if (idx + 1 < n)
        end = *(g + idx + 1);
    else
        end = t->limit;
    end = end - 1;
    for (; i < end; i++) {
        if (t->keys[i + 1] > key)
            break;
    }
    r.lo = t->lo[i];
    r.hi = t->hi[i];
    return r;
}








/*
 * Loads the 32-bit word at byte +0x14 of the object.
 */
u32 func_021A7A88(u8 *p)
{
    return ((struct Obj18066 *)p)->f14;
}








/*
 * Loads the 32-bit word at byte +0x18 of the object.
 */
u32 func_021A7A8C(u8 *p)
{
    return ((struct Obj18067 *)p)->f18;
}








u16 func_021A7A90(Tbl *s, int i)
{
    int k;
    if (i + 1 < s->count) {
        k = *(s->group + i + 1);
    } else {
        k = s->limit;
    }
    return *(s->keys + k - 1);
}







void func_021A7AB0(u32 *src, Out *o)
{
    u32 n;
    u32 p;
    u32 m;

    n = *src;
    p = (u32)(src + 1);
    o->f10 = n;
    o->f00 = p;
    p += n * 2;
    m = (n * 2) & 3;
    if (m != 0) p += 4 - m;
    o->f04 = p;
    p += o->f10;
    m = o->f10 & 3;
    if (m != 0) p += 4 - m;
    o->f08 = p;
    p += o->f10;
    m = o->f10 & 3;
    if (m != 0) p += 4 - m;
    n = ((struct Obj12760 *)p)->f0;
    p += 4;
    o->f0C = p;
    o->f14 = n;
    p += n;
    m = n & 3;
    if (m != 0) p += 4 - m;
    o->f18 = ((struct Obj12760 *)p)->f0;
}







/*
 * Tail-call thunk: forwards to func_021A811C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A7B08(int a, struct V3 *b)
{
    func_021A811C(a, (u32)b);
}





int func_021A7B10(void *a)
{
return (int)func_0216D4B4(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}




void *func_021A7B20(Args *a)
{
    void *task;
    Work_021A79E4 *w;

    task = func_020122C0(a->f04, 0, func_021A7CE8, 0x3C);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = (void *)func_02012A30(a->f08);
    w->f28 = 0;
    w->f18 = 0;
    w->f1A = func_021A80FC((u32)a->f0C);
    w->f36 = 0;
    w->f08 = func_021BDC94(a->f0C);
    w->f0C = a->f14;
    w->f10 = 1;
    w->f14 = 0;
    func_021A810C(a->f0C, (struct VecFx32 *)((u8 *)w + 0x1C));
    func_021A8214(w);
    func_021A7B88((Work_021A7B88 *)w);
    return task;
}



/*
 * Fills the Work step table (bytes 0x2C..) from the mode the Args' f0C
 * object reports.
 */
void func_021A7B88(Work_021A7B88 *w)
{
    Args *a;
    void *o;

    a = w->f00;
    o = a->f0C;
    if (func_021A8268((u32)w) != 0) {
        switch (func_021A80FC((u32)o)) {
        case 0:
        case 1:
        default:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 5;
            w->step[3] = 2;
            w->step[4] = 3;
            w->step[5] = 4;
            w->step[6] = 6;
            w->step[7] = 7;
            w->step[8] = 8;
            return;
        case 2:
        case 3:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 2;
            w->step[3] = 3;
            w->step[4] = 4;
            w->step[5] = 5;
            w->step[6] = 6;
            w->step[7] = 7;
            w->step[8] = 8;
            return;
        }
    } else if (func_02162370((int)a->f14) != 0) {
        w->step[0] = 0;
        w->step[1] = 1;
        w->step[2] = 4;
        w->step[3] = 5;
        w->step[4] = 8;
        return;
    } else {
        switch (func_021A80FC((u32)o)) {
        case 0:
        case 1:
        default:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 5;
            w->step[3] = 4;
            w->step[4] = 8;
            return;
        case 2:
        case 3:
            w->step[0] = 0;
            w->step[1] = 1;
            w->step[2] = 4;
            w->step[3] = 5;
            w->step[4] = 8;
            return;
        }
    }
}
