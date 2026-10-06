/*
 * file:     particle_p04.c
 * unit:     yes
 * function: func_02050340, func_02050468, func_020504D8, func_02050550
 * address:  0x02050340
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02033CA8  0x02033CA8  arm
 *   func_020500B8  0x020500B8  arm
 *   func_0204F428  0x0204F428  arm
 *   func_0204F720  0x0204F720  arm
 *   func_0204F5A8  0x0204F5A8  arm
 *   func_0203422C  0x0203422C  arm
 *   func_02050920  0x02050920  arm
 *   func_02050944  0x02050944  arm
 *   func_020506B8  0x020506B8  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F764  0x0204F764  arm
 *   func_0204F794  0x0204F794  arm
 */
#include "../../matched/include/Obj06991.h"

struct AreaMan;
struct Ent;
struct Own;
struct Entry;
struct Owner;
struct S14;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Vec3 { s32 a, b, c; };

struct BbActSlot { u16 id; u16 pad; u32 val; };

struct BbActEntry_02050340 {
    u32   f00;
    u16   f04;
    u16   f06;
    u32   f08;
    u16   f0C;
    u16   f0E;
    u16   f10;
    u16   f12;
    u32   f14;
    u32   f18;
    u16   f1C;
    u16   f1E;
    u32   f20;
    u32   f24;
};

struct BbActDesc {          /* 0x24 bytes */
    u16 slot;               /* 0x00 */
    s16 v12;                /* 0x02 */
    s16 v14;                /* 0x04 */
    u8  k;                  /* 0x06 */
    u8  pad07;
    u32 flag;               /* 0x08 */
    u32 w;                  /* 0x0c */
    struct Vec3 pos;        /* 0x10 */
    u32 f1c;                /* 0x1c */
    u32 f20;                /* 0x20 */
};

struct BbActSys_02050340 {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    void *f14;
    struct BbActEntry_02050340 *f18;
    u16 f1C;
    u16 f1E;
    u32 f20;
};

struct BbActEntry_02050468 { u32 f00; u8 pad[0x24]; };

struct BbActSys_02050468 {
    u16 f00;
    u16 f02;
    void *f04;
    u8  pad_08[0x10];
    struct BbActEntry_02050468 *f18;
    u16 f1C;
    u16 f1E;
    void *f20;
};

struct Entry {
    u32 f00;             /* 0x00 */
    u8  pad_04[0x1C];
    void (*f20)(void *o, int i, u32 a); /* 0x20 */
    u32 f24;             /* 0x24 */
};

struct Owner {
    u8            pad_00[0x18];
    struct Entry *f18;   /* 0x18 */
    u16           f1C;   /* 0x1C */
};

typedef struct Cmd {
    u16 a : 14;
    u16 b : 1;
    u16 c : 1;
    u16 f02;
} Cmd;

typedef struct Ent {
    u32   f00;
    u16   f04;
    u16   f06;
    u32 **f08;
    u16   f0c;
    u16   f0e;
    u16   f10;
    u16   f12;
    u32   f14;
    u32   f18;
} Ent;

typedef struct Own {
    u32  f00;
    u32  f04;
    u32  f08;
    u8  *f0c;
} Own;

extern s32 func_02033CA8(struct AreaMan *p, u32 len);
extern void func_020500B8(u32 *p);
extern s32  func_0204F428(void *board, u32 id, s16 v12, s16 v14, const struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *p, u32 idx, u32 *flag);
extern void func_0204F5A8(void *board, u32 idx);
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);
extern int func_02050920(struct S14 *p);
extern int func_02050944(void *p, struct S14 *q);
extern void func_020506B8(struct Owner *o, struct Entry *e, u32 a2);
extern void func_0204F66C(int p0, int p1, int p2);
extern void func_0204F764(void *p, u32 idx, u32 *val);
extern void func_0204F794(void *p, u32 idx, u32 *val);
void func_02050550(Own *o, Ent *e);


/*
 * billboard_act.c: take `count` consecutive entry indices from the pool at
 * +0x20 and build one board element per 0x24-byte descriptor through
 * func_0204F428, returning the first index (0xFFFF when the pool is full).
 * Levers, all measured: the descriptor array is `const` (its field loads
 * then move above the entry stores, 62 -> 15 bytes); the element id is a
 * named local passed on to func_0204F720 rather than re-read; the caller's
 * view of func_0204F428 takes s16 v12/v14 (ldrsh, no narrowing); all five
 * locals at function scope in the order p, e, idx, i, r (loop-scoped e/p
 * swap the i and p registers).
 */
u16 func_02050340(struct BbActSys_02050340 *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode)
{
    const struct BbActDesc *p;
    struct BbActEntry_02050340 *e;
    int idx;
    u32 i;
    s32 r;

    idx = func_02033CA8((struct AreaMan *)o->f20, count);
    if (idx == -1) {
        return 0xFFFF;
    }
    for (i = 0; i < count; i++) {
        e = &o->f18[idx + i];
        p = &d[i];

        func_020500B8((u32 *)e);
        e->f04 = base + p->slot;
        r = func_0204F428(o->f04, o->f0C[e->f04].id, p->v12, p->v14, &p->pos, p->k, p->w, mode);
        e->f00 = r;
        e->f20 = p->f1c;
        e->f24 = p->f20;
        func_0204F720(o->f04, r, (u32 *)(&p->flag));
        e->f1C = 0x3FFF;
    }
    return idx;
}


/*
 * billboard_act.c: release `count` entries from `first` and give the index
 * range back to the pool.  The earlier 2-byte floor (add operand order) and
 * the hand-copied stride came from writing the address arithmetic by hand;
 * the source is plain subscripts, o->f18[first + i], in a for loop.
 */
void func_02050468(struct BbActSys_02050468 *o, u16 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        func_0204F5A8(o->f04, o->f18[first + i].f00);
        func_020500B8((u32 *)(&o->f18[first + i]));
    }
    func_0203422C(o->f20, first, count);
}


/*
 * Tick every live entry of the 0x28-stride array at o->f18: for each index
 * below the live count at o->f1C, skip the entry whose first word is the
 * sentinel 0xFFFF, otherwise call its per-entry hook (a function pointer at
 * +0x20, taking the owner, the index and the entry's +0x24 word) when one is
 * installed, then hand the entry to func_02050550.
 *
 * Two shapes are load-bearing:
 *
 *   - The live count is re-read from o->f1C at the BOTTOM of the loop
 *     (`ldrh r0, [r5, #0x1c]` at +0x60) as well as at the top, because the
 *     hook and func_02050550 may both change it.  Caching it in a local gives
 *     one load and a different loop shape.
 *   - The count is a u16 but the comparison is SIGNED (`blt`, and `pople` on
 *     the entry guard), so the index is a plain `int` and the count is
 *     promoted, not an unsigned compare.
 *
 * The 0xFFFF sentinel lives in the pool at 0x0205054C rather than as an
 * immediate, which is why r7 is loaded once before the loop.
 *
 * UNBLOCKED 2026-09-21: func_02050550 was filed EXACT
 * (src/matched/func_02050550.c, shard arm9/pkt_02050340.json), so the single
 * relocation site, the `bl` at +0x5C, is now attested `matched` and this file
 * verifies EXACT unchanged.  No C was altered to promote it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020504D8.c \
 *       --func func_020504D8 --addr 0x020504D8 --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void func_020504D8(struct Owner *o)
{
    int i = 0;
    int n = o->f1C;

    if (n <= 0) {
        return;
    }
    do {
            struct Entry *e = (struct Entry *)((u8 *)o->f18 + i * 0x28);

            if (e->f00 != 0xFFFF) {
                if (e->f20 != 0) {
                    e->f20(o, i, e->f24);
                }
                func_02050550((struct Own *)o, (struct Ent *)e);
            }
        i++;
    } while (i < o->f1C);
}


void func_02050550(Own *o, Ent *e)
{
    Cmd *c;
    u32  s2;
    u32  s1;
    u16  s0;
    u16  rem;
    u8  *p;

    if (e->f08 == 0 || e->f18 == 0) {
        return;
    }
    if (e->f12 != 0) {
        e->f12 = e->f12 - 1;
        return;
    }

    c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    while (func_02050920((struct S14 *)c)) {
        if (func_02050944(e, (struct S14 *)c)) {
            return;
        }
        c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    }

    e->f10 = e->f10 + 1;
    s0 = c->a;
    rem = c->f02;

    p = (u8 *)(e->f04 * 8);
    p = p + (u32)o->f0c;
    if (((struct Obj06991 *)p)->f4 != 0) {
        func_020506B8((struct Owner *)o, (struct Entry *)p, s0);
    } else {
        func_0204F66C(o->f04, e->f00, (int)(&s0));
    }

    if (c->b) {
        s2 = 1;
    } else {
        s2 = 0;
    }
    if (c->c) {
        s1 = 1;
    } else {
        s1 = 0;
    }

    func_0204F764((void *)o->f04, e->f00, &s2);
    func_0204F794((void *)o->f04, e->f00, &s1);

    if (rem != 0) {
        rem = rem - 1;
    }
    e->f12 = rem;
}
