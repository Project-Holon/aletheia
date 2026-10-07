/*
 * file:     field_palace_sys_p02.c
 * unit:     yes
 * function: func_021D1488, func_021D14C4, func_021D1670, func_021D16D8, func_021D179C, func_021D182C
 * address:  0x021D1488
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
 *   d_021DB990     0x021DB990  data  a2
 *   func_021D1430  0x021D1430  thumb  ov021
 *   d_021DB9A0     0x021DB9A0  data
 *   d_021DC158     0x021DC158  data
 *   _ll_mul        0x0209C054  arm
 *   func_0207C768  0x0207C768  arm
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012F8C  0x02012F8C  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_020092D8  0x020092D8  thumb
 *   func_02009390  0x02009390  thumb
 *   func_020093D8  0x020093D8  thumb
 *   func_02009418  0x02009418  thumb
 *   func_02009428  0x02009428  thumb
 *   func_020093F0  0x020093F0  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   d_021DD5F0     0x021DD5F0  data    ov021  a4
 */
#include "../../matched/include/Obj09751.h"

#define NRM(i) ((s16 *)d_021DB9A0)[i]
struct Sub02009210Obj;
struct Sub02009210Ent;
struct U16Vec;
struct Strbuf;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Step021D1488 {
    u16 v;
    u16 dur;
} Step021D1488;

typedef struct Anim021D1488 {
    u32 f0[5];
    int cnt;
    u32 idx;
} Anim021D1488;

typedef short s16;

typedef int fx32;

typedef long long s64;

typedef struct VecFx32_021D14C4 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021D14C4;

/* s16 (x, y, z) normal triples */
typedef struct Norm021D14C4 {
    s16 x;
    s16 y;
    s16 z;
} Norm021D14C4;

typedef struct Tile021D14C4 {
    u16 type : 2;
    u16 norm : 14;
    u16 d;
    u32 attr : 31;
    u32 flag : 1;
} Tile021D14C4;

typedef struct Sub021D14C4 {
    u16 type : 2;
    u16 norm0 : 14;
    u16 norm1;
    u16 d0;
    u16 d1;
} Sub021D14C4;

typedef struct Map021D14C4 {
    u16 w;
    u16 h;
    Tile021D14C4 tiles[1];
} Map021D14C4;

typedef struct Plane021D14C4 {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
    u32 attr;
    fx32 height;
} Plane021D14C4;

struct V3 { u32 a, b, c; };

extern void func_021D1430(u8 *p, u32 n);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012F8C(u32 *p);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern u8 func_020092D8(const struct Sub02009210Obj *obj);
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern u32 func_02009418(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
extern u16 func_0215A5CC(void *a0);
extern void *func_02158F74(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
extern u32 func_021BBA6C(const void *p);
extern void *func_0216DE94(void *map, u32 id);
void func_021D1488(void *task, Anim021D1488 *p);
void func_021D14C4(Plane021D14C4 *out, int idx, Map021D14C4 *map, VecFx32_021D14C4 *pos, fx32 size, fx32 base);
int func_021D1670(u32 a, u32 b);
int func_021D16D8(u32 a, u32 b);
int func_021D179C(u32 a, u32 b);
u8 *func_021D182C(u32 a, u16 b, struct V3 *c, u16 d);
extern Step021D1488 d_021DB990[];
extern Norm021D14C4 d_021DB9A0[];
extern const fx32 d_021DC158[];
extern int d_021DD5F0[];


/*
 * Blocked: d_021DB990 ({u16 v; u16 dur;} step table, two pool words for
 * +0 and +2) is contested: another overlay in the window starts an object at
 * 0x021DB990 and this function has no overlay_id site.
 */
void func_021D1488(void *task, Anim021D1488 *p)
{
    int c = p->cnt + 1;
    u16 d = d_021DB990[p->idx].dur;

    p->cnt = c;
    if (d <= c) {
        p->idx++;
        if (p->idx >= 4) {
            p->idx = 0;
            p->cnt = 0;
        }
        func_021D1430((u8 *)p, d_021DB990[p->idx].v);
    }
}


static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}


static inline void VecSet021D14C4(Plane021D14C4 *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}


/*
 * The a/0/0/8 grid tile reader (see docs/notes/func_021D14C4_tile_record_reader.c.txt):
 * picks the tile under pos, writes its surface normal, attribute word and
 * solved height into out[idx].
 *
 * Shape notes, each one measured:
 * - the normal table is read through an s16 pointer cast of a differently
 *   typed object, so mwcc cannot prove it disjoint from out: the setter's
 *   right-to-left arguments then stay as z, y, x temporaries (y spilled) and
 *   the pool word is reloaded per access. A plain s16 array sinks the loads.
 * - the height table is const (its load is scheduled above the z store).
 * - the tile record is read through a volatile pointer: the image reloads
 *   the norm halfword after the type test instead of reusing the type load;
 *   no non-volatile spelling (casts, unions, other access paths, const)
 *   stopped mwcc from CSE-ing the two halfword loads.
 * - the row index is x/0x10000 + w * (z/0x10000) in that operand order;
 *   p (= &out[idx]) is live into the tail, where only the x read uses it.
 */
void func_021D14C4(Plane021D14C4 *out, int idx, Map021D14C4 *map, VecFx32_021D14C4 *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    int i = x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000);
    volatile Tile021D14C4 *t = &map->tiles[i];
    fx32 d;
    Plane021D14C4 *p;
    u8 type = t->type;

    if (type == 0) {
        int n = t->norm * 3;
        int di = t->d;
        VecSet021D14C4(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else if (type == 2) {
        Sub021D14C4 *s = (Sub021D14C4 *)(map->tiles + map->w * map->h) + t->d;
        int n;
        int di;
        if (t->flag == 0) {
            if (lx + lz < 0x10000) {
                n = s->norm0 * 3;
                di = s->d0;
            } else {
                n = s->norm1 * 3;
                di = s->d1;
            }
        } else {
            if (lx > lz) {
                n = s->norm0 * 3;
                di = s->d0;
            } else {
                n = s->norm1 * 3;
                di = s->d1;
            }
        }
        VecSet021D14C4(p = &out[idx], NRM(n), NRM(n + 1), -NRM(n + 2));
        d = d_021DC158[di];
    } else {
        VecSet021D14C4(p = &out[idx], 0, 0x1000, 0);
        d = 0;
    }
    {
        fx32 ny = out[idx].y;
        fx32 mz = FX_MUL(out[idx].z, pos->z);
        fx32 mx = FX_MUL(p->x, pos->x);
        out[idx].attr = t->attr;
        out[idx].height = base + func_0207C768(-(d + (mx + mz)), ny);
    }
}


/*
 * func_02012F8C (arm9 Thumb leaf) is filed as src/matched/arm9/func_02012F8C.c
 * to give the witness.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1670(u32 a, u32 b)
{
    void *r7;
    u32 r6;
    u16 *r4;
    u32 r5;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    r7 = func_0215A5E4((void *)b);
    r6 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    r5 = func_02012F8C(r7);
    if (r6 == 0) {
        if (func_020092EC((const struct Sub02009210Obj *)r5) == 1 && func_020092D8((const struct Sub02009210Obj *)r5) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
    }
    return 0;
}


int func_021D16D8(u32 a, u32 b)
{
    void *r6;
    u32 r7;
    u32 k1;
    u16 *r4;
    u8 i;
    u16 *e;
    u32 id;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    r6 = func_0215A5E4((void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    id = func_02012F8C(r6);
    switch (r7) {
    case 0:
        *r4 = 1;
        for (i = 0; i < 5; i++) {
            e = (u16 *)func_02009390((struct Sub02009210Obj *)id, i);
            if (e == 0) {
                *r4 = 0;
            } else if (e[0] == 0x7E || e[0] == 0) {
                *r4 = 0;
            }
        }
        break;
    case 1:
        if (func_020093D8((const struct Sub02009210Obj *)id) == 0x7F) {
            *r4 = 0;
        } else {
            *r4 = 1;
        }
        break;
    case 2:
        if (func_02009418((const struct Sub02009210Obj *)id) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
        break;
    case 3:
        func_02009428((struct Sub02009210Obj *)id, 0);
        break;
    case 4:
        func_020093F0((struct Sub02009210Obj *)id, k1);
        break;
    }
    return 0;
}


int func_021D179C(u32 a, u32 b)
{
    void *r6 = func_0215A5F4((void *)b);
    void *r7;
    u32 s8;
    u32 s12;
    u32 k0;
    u32 k1;
    u16 *e;
    u32 h;
    u32 id;

    func_0215A5DC((void *)b);
    r7 = func_0215A5E4((void *)b);
    s8 = func_0215A5CC((void *)b);
    s12 = (u32)func_02158F74(r6);
    id = func_02012F8C(r7);
    k0 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    e = (u16 *)func_02009390((struct Sub02009210Obj *)id, k1);
    if (e != 0 && e[0] != 0x7E && e[0] != 0) {
        h = (u32)func_020457B0(0xE, s8);
        func_02045994((struct Strbuf *)h, e + 1, 0xD);
        func_0201EE0C((struct WordSet *)s12, k0, (const void *)h, 0, 0, 2);
        func_02045808((struct U16Vec *)h);
    }
    return 0;
}


/*
 * The spilled second parameter is a u16 (func_0216DE94 compares its id
 * against func_0216D588's u16): as u32/int its reload from [sp] is hoisted
 * above the struct copy's last store. func_021BBA6C takes the result of
 * func_021BB990 (the bl has no argument setup of its own).
 *
 * Addresses are Black-image addresses.
 */
u8 *func_021D182C(u32 a, u16 b, struct V3 *c, u16 d)
{
    void *t = func_02188C7C((void *)a);
    u32 h = func_02188D24((u8 *)a);
    int *w = func_021BB990(-1, (int *)h, d_021DD5F0);
    u8 *p = (u8 *)func_021BBA6C(w);

    *(int * *)&((struct Obj09751 *)p)->f188 = w;
    ((struct Obj09751 *)p)->f19C = d;
    *(struct V3 *)(p + 0x18C) = *c;
    ((struct Obj09751 *)p)->f0 = (u32)func_0216DE94(t, b);
    return p;
}
