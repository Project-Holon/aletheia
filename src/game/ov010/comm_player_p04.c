/*
 * file:     comm_player_p04.c
 * unit:     yes
 * function: func_021677E4, func_02167810, func_02167848, func_0216786C, func_021679A4, func_021679C4
 * address:  0x021677E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02172A28 0x02172A28 data a4
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02194384   0x02194384  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021943EC  0x021943EC  thumb  ov021
 *   func_021BB578  0x021BB578  thumb
 */
#include "../../matched/include/Obj12372.h"
#include "../../matched/include/Obj12373.h"
#include "../../matched/include/Obj17734.h"

struct BigObj;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct Sub02014444Obj;
struct Obj00020;
struct Tbl;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 used:1; u8 rest:7; u8 pad[27]; } Slot;

typedef struct { u8 pad[28]; Slot slot; } Row;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct Blk12_02167810 {
    u64 lo;
    u32 hi;
} Blk12_02167810;

typedef struct Ent {
    Blk12_02167810 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work_02167810 {
    void *sys;
    void *obj;
    Ent e[4];
} Work_02167810;

typedef struct {
    u64 lo;
    u32 hi;
} Blk12_02167848;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Where {
    VecFx32 pos;        /* 0x00 */
    u16 zone;           /* 0x0C */
    u8 dir : 4;         /* 0x0E */
    u8 flag : 1;
} Where;

typedef struct Report {
    u32 flag;           /* 0x00 */
    VecFx32 pos;        /* 0x04 */
    u16 zone;           /* 0x10 */
    u8 dir;             /* 0x12 */
} Report;

typedef struct Work_0216786C {
    void *sys;          /* 0x00 */
    u8 pad04[0x78 - 0x04];
    Where last;         /* 0x78 */
    u8 pad88[0x8F - 0x88];
    u8 f8f;             /* 0x8F */
} Work_0216786C;

typedef struct Blk12_021679C4 {
    u64 lo;
    u32 hi;
} Blk12_021679C4;

typedef struct Work_021679C4 {
    void *sys;
    void *obj;
    Ent e[4];
} Work_021679C4;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02014484(struct Sub02014444Obj *o);
extern u32 func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *proc);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_021A34EC(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_02197CCC(u8 *p, s32 *out);
extern u16 func_021A3050(u8 *p);
extern VecFx32 *func_02012AA0(void *pl);
extern u16 func_02012AE4(void *pl);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_02194384(int, int, int, int, int, int);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021943EC(struct Tbl *t, u32 key);
extern u32 func_021BB578(void *a, void *b, int c, int d);
int func_021677E4(void *p, int i);
u16 func_02167810(Work_02167810 *w, int i);
void func_02167848(char *a0, int a1, char *a2);
int func_0216786C(Work_0216786C *w, Report *out);
int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5);
int func_021679C4(Work_021679C4 *w, int i);
extern const char d_02172A28[];

/*
 * domain: the signed i>=4 guard admits negative indices; raw unsigned scaling preserves the original modulo-32 address arithmetic without a fixed-array bound.
 * address lever: Row supplies the +28 load offset after unsigned scaling; combining +28 with the scaled index folds i+1 and changes the instructions.
 */
int func_021677E4(void *p, int i) {
    if (p == 0 || i >= 4) func_02034714(d_02172A28, 0, d_02172A28);
    return ((Row *)((u32)p + (u32)i * 28u))->slot.used;
}


u16 func_02167810(Work_02167810 *w, int i)
{
    if (w == 0 || i >= 4 || w->e[i].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return w->e[i].f12;
}


/*
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +005C.  An
 * unlabelled Thumb leaf inside ov010: `disasm.py` emitted its body as the
 * `pool_02167844` word run because its `push {r4, r5}` prologue saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  ov009 holds
 * ARM data at the address, ov011/ov018/ov019 only call it, so ov010 is the
 * region it lives in.
 *
 * The byte shape turns on the 12-byte aggregate copy: writing the +8 block as
 * one `struct { u64; u32; }` assignment is what makes mwcc evaluate the
 * destination address first (dst in r3, a2 kept in r2) and emit the exact
 * `ldm r5!`/`stm r4!` run.  Splitting it into a `u64` store plus a `u32` store
 * (or an explicit `dst` local, u32 index, Src/Dst structs) makes the allocator
 * compute the source address first and move a2 into r4, losing the whole range.
 * See docs/notes/recursive-match-unblocker-ov010-0215.c.txt and
 * docs/idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md.
 */
void func_02167848(char *a0, int a1, char *a2)
{
    char *d = a0 + a1 * 0x1C;

    *(Blk12_02167848 *)(d + 8) = *(Blk12_02167848 *)(a2 + 4);
    ((struct Obj12373 *)d)->f18 = ((struct Obj12372 *)a2)->f10;
    ((struct Obj12373 *)d)->f14 = ((struct Obj12372 *)a2)->f0;
}


/*
 * Report the player's position, zone and facing (from the saved copy
 * while flying, from the ov021 rail object, or from the player object),
 * returning 1 only when it differs from the last report. One lever: the
 * change test written positively so the update block comes before the
 * `return 0`.
 */
int func_0216786C(Work_0216786C *w, Report *out)
{
    VecFx32 pos;
    void *a;
    void *pl;
    void *ctx;
    Where *last;
    void *q;
    u32 flag;
    u32 dir;
    u16 zone;

    ctx = func_020120F4(w->sys);
    last = &w->last;
    flag = 0;
    if (w->f8f == 1)
        return 0;
    pl = func_020127A4(ctx);
    dir = func_02012B28(pl);
    if (func_02014484(func_02012B38(ctx)) == 2) {
        zone = last->zone;
        pos = last->pos;
        flag = 1;
        dir = last->dir;
    } else if (func_02012114(w->sys) == 1 && func_02188BE8(func_0201210C(w->sys)) == 1) {
        q = func_02188CB4(func_0201210C(w->sys));
        a = func_021A3074(q);
        if (func_021A34EC(q) == 4)
            func_021A3038(q, &pos);
        else
            func_02197CCC(a, (s32 *)(&pos));
        zone = func_021A3050(q);
    } else {
        pos = *func_02012AA0(pl);
        zone = func_02012AE4(pl);
    }
    out->zone = zone;
    out->pos = pos;
    out->flag = flag;
    out->dir = dir;
    if (zone != last->zone || dir != last->dir || flag != last->flag
        || func_0203EFC8((const u8 *)(&pos), (const u8 *)last, sizeof(VecFx32)) != 0) {
        last->zone = zone;
        last->pos = pos;
        last->dir = dir;
        last->flag = flag;
        return 1;
    }
    return 0;
}


/*
 * The record's second word is the first argument of the six-argument
 * overlay call, with a zero bail.
 */
int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5)
{
    int v = ((struct Obj17734 *)a0)->f4;

    if (v == 0)
        return 0;

    return func_02194384(v, a1, a2, a3, a4, a5);
}


int func_021679C4(Work_021679C4 *w, int i)
{
    Ent *e;
    void *a;

    e = &w->e[i];
    if (w->obj == 0 || e->used == 0 || e->f18 != 0)
        return 0;
    a = (void *)func_02188CD0(func_0201210C(w->sys));
    e->f18 = func_021BB578(a, (void *)func_021943EC(w->obj, i), 0, 0);
    return 1;
}
