/*
 * file:     unit_0204EE0C.c
 * unit:     yes
 * function: func_0204EE0C, func_0204EE64, func_0204EEC8, func_0204EF58, func_0204EFC8, func_0204F044, func_0204F10C, func_0204F150, func_0204F1A0, func_0204F214, func_0204F27C, func_0204F2B4, func_0204F2CC, func_0204F2E4
 * address:  0x0204EE0C
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
 *   func_02046FF8   0x02046FF8  arm
 *   func_02047388   0x02047388  arm
 *   func_020473B8   0x020473B8  arm
 *   _s32_div_f   0x0209C0A4  arm
 *   gTexSizeTbl  0x020A14C0  data
 *   gTexParamS   0x020A14D4  data
 *   gTexParamT   0x020A14D8  data
 *   func_02046DB8   0x02046DB8  arm
 *   func_02046F48  0x02046F48  arm
 *   func_02047250  0x02047250  arm
 *   func_020307E0  0x020307E0  arm
 *   func_020470D0   0x020470D0  arm
 *   func_02046EFC   0x02046EFC  arm
 *   g_020A8144  0x020A8144  data
 *   g_020A814C  0x020A814C  data
 */
#include "../../matched/include/Obj16122.h"
#include "../../matched/include/Obj05758.h"
#include "../../matched/include/Obj06988.h"
#include "../../matched/include/Obj16126.h"
#include "../../matched/include/Obj16127.h"
#include "../../matched/include/Obj16128.h"
#include "../../matched/include/Obj16129.h"
#include "../../matched/include/Obj16130.h"

struct Layer;
struct Struct_0204EE0C;
struct Struct_0204EE64;
struct Cell;
struct Tagged;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Elem_0204EE0C {
    u32 field0;
    u8 pad[0x14 - 4];
    u32 field14;
    u8 pad2[0x28 - 0x18];
};

struct Struct_0204EE0C {
    u8 pad[4];
    struct Elem_0204EE0C *items;
    u8 pad2[0xc - 8];
    u16 count;
};

struct Struct_0204EE64 {
    u32 heapId;
    u8 pad[0xc - 4];
    u32 offC;
    u32 off10;
    u8 pad2[0x20 - 0x14];
    u32 off20;
    u32 off24;
};

typedef signed int     s32;

struct Cell {
    u8  pad_00[4];
    u16 f04;
    u16 f06;
    u8  f08;
    u8  f09;
    u8  f0a;
    u8  f0b;
    u8  pad_0c[8];
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Pair8 { u32 w; u32 pad; };

struct Slot_0204EF58 {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8  pad_18[8];
    u32 unk_20;
    u32 unk_24;
};

struct Desc {
    u8           pad_00[4];
    struct Slot_0204EF58 *slots;
    u32          unk_08;
    int          count;
};

struct Slot_0204EFC8 {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8  pad_18[8];
    u32 unk_20;
    u32 unk_24;
};

struct Slot_0204F044 {
    u32 f00;
    u8  pad04[0xc - 4];
    u32 f0c;
    u32 f10;
    u8  pad14[0x20 - 0x14];
    u32 f20;
    u32 f24;
};

struct Board {
    u8           pad00[4];
    struct Slot_0204F044 *ptr0;
};

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct Record {
    u8  pad00[0x14];
    u32 size;
};

struct Entry {
    void *payload;
    u8    pad04[0x28 - 4];
};

typedef void (*Fn0204F1A0)(u32);

typedef struct Obj0204F1A0 {
    u8  pad00[4];
    u8 *f04;
} Obj0204F1A0;

struct Actor {
    u8  pad_000[0xc];
    u16 count;
};

struct Slot {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8  pad_18[8];
    u32 unk_20;
    u32 unk_24;
};

extern int func_02046FF8(int *self);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern s32 _s32_div_f(s32 a, s32 b);
extern void *func_02046DB8(u32 a0, u32 a1);
extern void *func_02046F48(struct Tagged *p);
extern struct Record *func_02047250(void *p);
extern void func_020307E0(void *p, u32 size);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
int func_0204EE0C(struct Struct_0204EE0C *p, int *out_index);
void func_0204EE64(struct Struct_0204EE64 *p, u32 heapId);
void func_0204EEC8(struct Cell *dst, u32 idx, s32 fmt, u32 b, u8 c);
u32 func_0204EF58(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
u32 func_0204EFC8(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
void func_0204F10C(void *table, u32 idx);
void func_0204F150(u8 *a0, int i);
void func_0204F1A0(Obj0204F1A0 *a0, u32 a1);
void func_0204F214(u8 *a0, int i);
void func_0204F27C(struct Actor *p);
void func_0204F2B4(int p0, int p1, int p2);
void func_0204F2CC(int p0, int p1, int p2);
void func_0204F2E4(u8 *a0, int i, u32 *out);
extern const u32 gTexSizeTbl[];
extern const struct Pair8 gTexParamS[];
extern const struct Pair8 gTexParamT[];
extern Fn0204F1A0 g_020A8144;
extern Fn0204F1A0 g_020A814C;



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204EE0C.c \
 *       --func func_0204EE0C --addr 0x0204EE0C --cc 1.1p1 --arm
 */
int func_0204EE0C(struct Struct_0204EE0C *p, int *out_index)
{
    int i;
    u16 count = p->count;

    for (i = 0; i < count; i++) {
        struct Elem_0204EE0C *elem = &p->items[i];
        if (elem->field0 == 0 && elem->field14 == 5) {
            *out_index = i;
            return 1;
        }
    }

    *out_index = 0;
    return 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204EE64.c \
 *       --func func_0204EE64 --addr 0x0204EE64 --cc 1.1p1 --arm
 */
void func_0204EE64(struct Struct_0204EE64 *p, u32 heapId)
{
    u32 res;

    p->heapId = heapId;
    if (func_02046FF8((int *)heapId) == 0) {
        p->offC = 0;
        p->off10 = 0;
        return;
    }

    p->off20 = func_02047388((struct Layer *)heapId);
    res = func_020473B8((struct Layer *)heapId);

    p->off24 = res;
    p->offC = (u32)(p->off20 << 16) >> 13;
    p->off10 = (u32)(res << 16) >> 13;
}



/*
 * Seats a billboard cell's texture parameters: the S and T sizes come from
 * the two 3-bit fields of fmt (bits 4..6 and 0..2) as 1 << (n + 3), the
 * three table words go to 0x14/0x18/0x1C, and the two byte ratios at
 * 0x0A/0x0B are the sizes divided by b and c.
 *
 * Source order of the stores decides the prologue's colouring. The three
 * table stores come before the two size stores: with f04 written first the
 * sb field, sb + 3 and the constant 1 rotate through lr/r5/ip (14 bytes
 * out); with f04 after the table loads they land in ip/lr/r5 as the image.
 * The T field is not a named local: as a local it gets its own web and the
 * st half of the same rotation moves; written as `fmt & 7` at both uses it
 * is a CSE temporary and colours as the image.
 */
void func_0204EEC8(struct Cell *dst, u32 idx, s32 fmt, u32 b, u8 c)
{
    s32 sb = (fmt & 0x70) >> 4;

    dst->f14 = gTexSizeTbl[idx];
    dst->f18 = gTexParamS[sb].w;
    dst->f1c = gTexParamT[fmt & 7].w;
    dst->f04 = 1 << (sb + 3);
    dst->f06 = 1 << ((fmt & 7) + 3);
    dst->f09 = c;
    dst->f08 = b;
    dst->f0a = _s32_div_f(dst->f04, dst->f08);
    dst->f0b = _s32_div_f(dst->f06, dst->f09);
}



/*
 * The first of the two "insert and publish" wrappers over the 0x28-byte slot
 * table: scan for a free slot with func_0204EE0C, seat it with func_0204EE64
 * and hand it to func_0204EEC8.
 *
 * The scan index is an out-parameter on the caller's own frame (`add r1,
 * sp, #4`), which is where the 8-byte frame comes from, and the same word is
 * the return value whether or not the scan succeeded, so the local is
 * deliberately left uninitialised: func_0204EE0C writes it on both paths.
 *
 * The two trailing parameters are `u8`: a byte-typed parameter that arrives on
 * the stack is read with `ldrb` where a 32-bit one would be `ldr`, and that is
 * the only thing that distinguishes this prototype from func_0204EFC8's
 * (a word, a byte, a byte).
 *
 * `&desc->slots[idx]` is spelled as an index, not as byte arithmetic: the
 * element stride has to be a declared sizeof, because that is what emits the
 * `mov r6, #0x28` / `mla` pair the image has (an `idx * 0x28` on a byte
 * pointer comes out as `mul` plus `add`).
 *
 * The slot base is re-read for the second call, because the first one may
 * have changed it.
 */
u32 func_0204EF58(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    u32 idx;

    if (func_0204EE0C((struct Struct_0204EE0C *)desc, (int *)(&idx)) == 1) {
        func_0204EE64((struct Struct_0204EE64 *)(&desc->slots[idx]), a1);
        func_0204EEC8((struct Cell *)(&desc->slots[idx]), a2, a3, a4, a5);
    }
    return idx;
}



/*
 * The second wrapper, one call longer than func_0204EF58: the handle it seats
 * the slot with is func_02046DB8(a1, a2) rather than a1 directly, and the
 * trailing parameters are one word and two bytes rather than two bytes
 * (`ldr` at sp+0x20, `ldrb` at sp+0x24 and sp+0x28).
 *
 * The frame and the scan out-parameter are the same as func_0204EF58's, and
 * the slot base is again re-read for each call.
 */
u32 func_0204EFC8(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6)
{
    u32 idx;

    if (func_0204EE0C((struct Struct_0204EE0C *)desc, (int *)(&idx)) == 1) {
        func_0204EE64((struct Struct_0204EE64 *)(&desc->slots[idx]), (u32)func_02046DB8(a1, a2));
        func_0204EEC8((struct Cell *)(&desc->slots[idx]), a3, a4, a5, a6);
    }
    return idx;
}



/*
 * billboard.c: take a free slot and fill it from caller-supplied texture
 * sizes, then hand it to func_0204EEC8.  The pure register residue of the
 * earlier notes (52 bytes, stride constant in ip instead of r0) was the
 * spelling of the two size fields: `(u32)(u16)f20 << 3` gives the same
 * instructions but a different allocation; the sibling func_0204EE64's
 * `(u32)(f20 << 16) >> 13` is what the image has.
 */
int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6)
{
    u32 idx;

    if (func_0204EE0C((struct Struct_0204EE0C *)b, (int *)(&idx)) == 1) {
        b->ptr0[idx].f00 = 0;
        b->ptr0[idx].f20 = w;
        b->ptr0[idx].f24 = h;
        b->ptr0[idx].f0c = (u32)(b->ptr0[idx].f20 << 16) >> 13;
        b->ptr0[idx].f10 = (u32)(b->ptr0[idx].f24 << 16) >> 13;
        func_0204EEC8((struct Cell *)(&b->ptr0[idx]), a3, a4, a5, a6);
    }
    return idx;
}



/*
 * Hand the 0x28-stride entry's payload buffer to func_020307E0 with its
 * length.  The payload pointer is a named local, not an inline call argument,
 * or the entry pointer would have to stay live in a third callee-saved
 * register across both calls.  Same shape as src/matched/sub_02046FCC.c.
 */
void func_0204F10C(void *table, u32 idx)
{
    struct Entry  *e       = &((struct Entry *)((struct Obj16122 *)table)->f4)[idx];
    void          *payload = e->payload;
    void          *buf     = func_02046F48(payload);
    struct Record *last    = func_02047250(payload);

    func_020307E0(buf, (u32)((u8 *)last + last->size - (u8 *)buf));
}



/*
 * The direct form of the entry teardown: release the 0x28-byte entry's first
 * word if it is live, zero it, and stamp 5 into the halfword-style state word
 * at +0x14, which is what func_0204EE0C's scan looks for.
 *
 * Every access re-reads the descriptor's +4 word, so the source spells the
 * base out at each use instead of binding it to a pointer local; the two
 * release calls take a fresh read of the entry's first word each, since the
 * first call may have changed it.  The value the `cmp` tested is the one the
 * first call receives, which is why there is no reload between them.
 *
 * The sibling entry points are func_0204F1A0 (guarded, through two
 * function-pointer globals) and func_0204F214 (unguarded, same two globals);
 * neither is contiguous with this one.
 */
void func_0204F150(u8 *a0, int i)
{
    u32 off = i * 0x28;

    if (*(u32 *)(((struct Obj05758 *)a0)->f4 + off) != 0) {
        func_020470D0((u32 *)(*(u32 *)(((struct Obj05758 *)a0)->f4 + off)));
        func_02046EFC((struct Tagged *)(*(u32 *)(((struct Obj05758 *)a0)->f4 + off)));
        *(u32 *)(((struct Obj05758 *)a0)->f4 + off) = 0;
    }
    *(u32 *)(((struct Obj05758 *)a0)->f4 + off + 0x14) = 5;
}



/*
 * Release one record of the 0x28-byte array hanging off the object's +0x04
 * field: when the record's first word is set, hand its +0x20 and +0x24
 * pointers to the two callbacks installed in 0x020A8144 / 0x020A814C, then
 * clear the first word.  The record's state word at +0x14 is stamped 5
 * whether or not the release ran.
 *
 * The record size is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces a multiply whose constant is a power of two.
 * The object field is re-read for every statement after the first, because
 * the two indirect calls may write it, so the tail reloads +0x04 instead of
 * reusing the pointer computed for the guard.
 *
 * Address arithmetic: every access spells the base as `(char *)a0->f04`.
 * The cast is load-bearing - with the field left as `u8 *` the front end
 * schedules `base + off` for the first call argument ABOVE the guard branch
 * (a different 7-instruction block, 18 bytes of DIFF); spelled through a
 * `char *` the sum stays inside the guarded block.  See
 * docs/idioms/a-char-cast-on-the-base-pins-the-base-plus-index-sum.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204F1A0.c \
 *       --func func_0204F1A0 --addr 0x0204F1A0 --cc 1.1p1 --arm
 */
void func_0204F1A0(Obj0204F1A0 *a0, u32 a1)
{
    u32 off = a1 * 0x28;

    if (*(u32 *)(a0->f04 + off) != 0) {
        g_020A8144(*(u32 *)((char *)a0->f04 + off + 0x20));
        g_020A814C(*(u32 *)((char *)a0->f04 + off + 0x24));
        *(u32 *)((char *)a0->f04 + off) = 0;
    }
    *(u32 *)((char *)a0->f04 + off + 0x14) = 5;
}



extern void (*g_020A8144)(u32 v);


extern void (*g_020A814C)(u32 v);



/*
 * The unguarded entry teardown: it runs the two function-pointer globals over
 * the entry's +0x20 and +0x24 words unconditionally (their addresses in the
 * pools are the two ABS32 relocations), then clears the entry and stamps 5
 * into +0x14.
 *
 * A different file from func_0204F1A0, which is the same body behind the
 * "entry is live" guard, and from func_0204F150, which does the same work
 * through two direct calls.  The three are consecutive in the image and call
 * 0x0204F5A8-free leaf helpers, so each stands alone.
 */
void func_0204F214(u8 *a0, int i)
{
    u32 off = i * 0x28;

    g_020A8144(*(u32 *)(((struct Obj06988 *)a0)->f4 + off + 0x20));
    g_020A814C(*(u32 *)(((struct Obj06988 *)a0)->f4 + off + 0x24));
    *(u32 *)(((struct Obj06988 *)a0)->f4 + off) = 0;
    *(u32 *)(((struct Obj06988 *)a0)->f4 + off + 0x14) = 5;
}



/*
 * Walk the actor's u16 count at +0xc and release every entry.  The count is
 * re-read on each iteration because func_0204F150 may change it.  The
 * comparison comes out signed (blt, not blo) because the u16 count promotes
 * to int against an s32 counter.
 */
void func_0204F27C(struct Actor *p)
{
    s32 i;

    for (i = 0; i < p->count; i++) {
        func_0204F150((u8 *)p, i);
    }
}



void func_0204F2B4(int p0, int p1, int p2){ ((struct Obj16127 *)p2)->f0 = (int)*(int *)(((p1 * 0x28 + ((struct Obj16126 *)p0)->f4) + 12)); }



void func_0204F2CC(int p0, int p1, int p2){ ((struct Obj16129 *)p2)->f0 = (int)*(int *)(((p1 * 0x28 + ((struct Obj16128 *)p0)->f4) + 16)); }


/*
 * Word getter through an out-parameter on one 0x28-byte slot; the `mla`
 * means the stride is the entry type's sizeof, not a byte offset.
 */
void func_0204F2E4(u8 *a0, int i, u32 *out)
{
    struct Slot *p = (struct Slot *)((struct Obj16130 *)a0)->f4;

    *out = p[i].unk_20;
}
