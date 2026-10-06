/*
 * file:     iss_zone_sys_p03.c
 * unit:     yes
 * function: func_0202BEEC, func_0202BF54, func_0202BF84, func_0202BF90, func_0202BFC4, func_0202BFF0
 * address:  0x0202BEEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ffltu  0x0209BE04  arm
 *   _fdiv   0x0209CE10  arm
 *   _fmul   0x0209C77C  arm
 *   _fsub   0x0209CB8C  arm
 *   _f2s    0x0209C494  arm
 */
#include "../../matched/include/Obj08807.h"

struct ArcFile;
struct Container;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Rec_0202BF54 {
    u16 key;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct Obj_0202BF54 {
    u32 state;
    u32 pad4;
    const struct Rec_0202BF54 *base;
    u8  sel;
    u8  pad_d;
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Rec_0202BF90 {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct Obj_0202BF90 {
    u32 pad0;
    u32 pad4;
    u32 base;
    u8  sel;
    u8  pad_d;
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Item {
    u16 key;
    u16 pad[3];
};

struct Container {
    u8 pad[4];
    u8 count;
    u8 pad2[3];
    const struct Item *items;
};

struct Obj_0202BFF0 {
    u32 pad0;
    u32 pad4;
    u32 pad8;
    u8  padc[2];
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

extern void *func_020490F4(u32 id, u32 heap);
extern u16 func_0204961C(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void   func_02049238(void *handle);
extern u32 func_0202BFC4(const struct Container *c, u32 key);
extern void func_02005F24(u32 a0, u32 a1);
extern float _ffltu(u32 v);
extern float _fdiv(float a, float b);
extern float _fmul(float a, float b);
extern float _fsub(float a, float b);
extern int   _f2s(float a);
void func_0202BEEC(u8 *p, u32 id);
void func_0202BF84(u32 *p);


/*
 * Sibling of func_0202B958: builds a selector out of the caller's id, takes
 * a handle from func_020490F4, sizes the record table from func_0204961C's
 * count and allocates it with func_02030734, then reads every 8-byte record
 * into the handle with func_0204944C and releases it with func_02049238.
 * The record table is at +8 and the count byte at +4 rather than the +0x264
 * and +0x268 func_0202B958 uses, and the count here stays a signed int (the
 * guard is `ble`), which is the whole difference between the two.
 *
 * The five-argument window read is the same call func_0204944C makes from
 * its other sites; the buffer is its own stack word because the argument
 * count already spends r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEEC.c \
 *       --func func_0202BEEC --addr 0x0202BEEC --thumb --cc 1.1p1
 */
void func_0202BEEC(u8 *p, u32 id)
{
    void *h = func_020490F4(0x88, (u16)((id & 0x7fff) | 0x8000));
    int   n = func_0204961C(h);
    int   i;

    p[4] = (u8)n;
    ((struct Obj08807 *)p)->f8 = (u32)func_02030734(id, (u32)(n << 3), 0,
                                         (const void *)0x020A7748, 0xd2);

    for (i = 0; i < n; i++) {
        func_0204944C(h, (u32)i, 0, 8,
                      (void *)(((struct Obj08807 *)p)->f8 + ((u32)i << 3)));
    }
    func_02049238(h);
}


/*
 * Selects the record func_0202BFC4 matches for the caller's key and latches
 * it into the object: +0xc keeps the index, +0xe and +0x10 take the record's
 * +2 and +4 words, +0x12 and +0x14 are the arm flag and its counter, and the
 * +0 word marks the object live.  A non-zero +0 word means "already
 * selected", and 0xff means "no match"; both leave the object untouched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BF54.c \
 *       --func func_0202BF54 --addr 0x0202BF54 --thumb --cc 1.1p1
 */
void func_0202BF54(struct Obj_0202BF54 *o, u16 key)
{
    u32 idx;

    if (o->state != 0) {
        return;
    }
    idx = func_0202BFC4((const struct Container *)((const u8 *)o), key);
    if (idx == 0xff) {
        return;
    }
    o->sel = (u8)idx;
    o->state = 1;
    o->fxe = o->base[idx].f2;
    o->f10 = o->base[idx].f4;
    o->f12 = 1;
    o->f14 = 0;
}


void func_0202BF84(u32 *p)
{
    if (*p != 0) {
        *p = 0;
    }
}


/*
 * Combines the record selected by the object's +0xc byte with the record
 * func_0202BFC4 has just selected for the caller's key: the two crossings are
 * ANDed into +0xe and +0x10, +0x12 takes the new record's +6 and +0xc records
 * the new selection.
 *
 * The spelling that matters here is the object as a struct with named members:
 * with `u8 *p` and literal offsets the allocator puts p in r4 and sel in r5,
 * twenty bytes of register numbering away.  Reading `o->sel` first, calling
 * func_0202BFC4 on the same object and only then loading `o->base` is what puts
 * sel in r4, p in r5 and the base in r6, which is the original.
 *
 * Closes the blocker of src/pending/func_0202BECC.c and, through it,
 * src/pending/func_0202B7D4.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BF90.c \
 *       --func func_0202BF90 --addr 0x0202BF90 --thumb --cc 1.1p1
 */
void func_0202BF90(struct Obj_0202BF90 *o, u32 key)
{
    u8 sel;
    u32 idx;
    const struct Rec_0202BF90 *base;

    sel = o->sel;
    idx = func_0202BFC4((const struct Container *)o, key);
    base = (const struct Rec_0202BF90 *)o->base;
    if (idx == 0xff) {
        return;
    }
    o->fxe = base[sel].f4 & base[idx].f2;
    o->f10 = base[sel].f2 & base[idx].f4;
    o->f12 = base[idx].f6;
    o->f14 = 0;
    o->sel = (u8)idx;
}


u32 func_0202BFC4(const struct Container *c, u32 key)
{
    u8 i;

    for (i = 0; i < c->count; i++) {
        if (c->items[i].key == key) {
            return i;
        }
    }

    return 0xff;
}


/*
 * The record's active window: while +0x12 exceeds the running +0x14 counter,
 * bump the counter and push a percentage to the +0xe and +0x10 gauges
 * (func_02005F24).  The two gauges differ only in the numerator: the first
 * scales the counter, the second the counter brought round by one.
 *
 * Each gauge id is bound to a local before the counter is stored and before
 * the division, which is what keeps it in the callee-saved r4 across the five
 * soft-float calls; read at the call site it is reloaded instead and the
 * frame loses a register and its numbering shifts.  Both arms re-read the two
 * u16 fields rather than sharing a computed quotient, which is why each is
 * loaded and converted twice.
 *
 * The counter bump is the one spelling that matters: `o->f14 = o->f14 + 1;`
 * compiles the same increment but lands the guard's two u16 loads in the
 * opposite r0/r1 pair (and so the `adds` that follows them), four concrete
 * bytes away from the original, while `o->f14 += 1;` reproduces it.  See
 * docs/idioms/a-compound-assignment-on-a-field-flips-the-guards-register-pair.md.
 *
 * The soft-float helpers are MSL/runtime.a's; this front end names them
 * _ffltu, _fdiv, _fmul, _fsub and _f2s, which is what the relocations carry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BFF0.c \
 *       --func func_0202BFF0 --addr 0x0202BFF0 --thumb --cc 1.1p1
 */
void func_0202BFF0(struct Obj_0202BFF0 *o)
{
    u16 id;

    if (o->f12 <= o->f14) {
        return;
    }
    id = o->fxe;
    o->f14 += 1;
    if (id != 0) {
        func_02005F24(id, _f2s(_fmul(127.0f,
                                      _fdiv(_ffltu(o->f14),
                                            _ffltu(o->f12)))));
    }
    id = o->f10;
    if (id != 0) {
        func_02005F24(id, _f2s(_fmul(127.0f,
                                      _fsub(1.0f,
                                            _fdiv(_ffltu(o->f14),
                                                  _ffltu(o->f12))))));
    }
}
