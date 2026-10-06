/*
 * file:     unit_0200E44C_p04.c
 * unit:     yes
 * function: func_0200EA2C, func_0200EA3C, func_0200EBD0, func_0200EC14, func_0200EC2C, func_0200EC98, func_0200ECB4, func_0200ECD0, func_0200ECF0, func_0200ED14, func_0200ED38, func_0200ED3C, func_0200ED48, func_0200ED54, func_0200EDC4, func_0200EDEC
 * address:  0x0200EA2C
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045A38  0x02045A38  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02017D70  0x02017D70  thumb
 *   func_02045808  0x02045808  arm
 *   func_0200EA3C  0x0200EA3C  thumb
 *   func_02045994  0x02045994  arm
 *   sub_0200EC14   0x0200EC14  thumb
 *   sub_0200EC98   0x0200EC98  thumb
 *   MI_CpuCopy8   0x02082D44  arm
 */
#include "../../matched/include/Obj08961.h"
#include "../../matched/include/Obj17088.h"
#include "../../matched/include/Obj17089.h"
#include "../../matched/include/Obj17090.h"
#include "../../matched/include/Obj15609.h"

struct Sav;
struct U16Vec;
struct Rec;
struct Date;
struct Strbuf;
struct Src0200EC2C;
struct Dst0200EC2C;
struct Out0200EC98;
struct Sub020071CCCtrl;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

struct Entry {
    u16 species;
    u8  level;
    u8  f03a : 6;
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u16 name[11];
    u16 ot[8];
    u16 f32[4];
};

struct Rec {
    struct Entry e[6];
    u16 year;
    u8  month;
    u8  day;
};

struct Date {
    u32 year;
    u32 month;
    u32 day;
};

struct Obj {
    u8  pad[0x1554];
    u32 unk1554;
    u32 unk1558;
};

struct Bits {
    u8 a : 6;
    u8 b : 2;
};

struct Src0200EC2C {
    u16 f00;
    u8  f02;
    u8  f03a : 6;
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u8  f0C[0x16];
    u8  f22[0x10];
    u16 f32[4];
};

struct Dst0200EC2C {
    void *p00;
    void *p04;
    u32   f08;
    u32   f0C;
    u16   f10;
    u8    f12;
    u8    f13a : 6;
    u8    f13b : 2;
    u16   f14[4];
};

struct Out0200EC98 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct L0200ED54 { u32 arr[32]; u32 count; };

struct L0200EDC4 {
    u32 arr[32];
    u32 count;
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32 func_0201AA18(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017D30(struct Sav *p);
extern u32   func_02017E1C(void *mon, u32 id, u32 buf);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern u16   func_02045A98(void);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_0200EA3C(struct Rec *rec, void *a1, struct Date *date, u32 heap);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern int sub_0200EC14(char *o);
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern void sub_0200EC98(const u8 *o, struct Out0200EC98 *out);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
int func_0200EC14(char *p);
u32 sub_0200ECB4(char *o);
u32 sub_0200ECC4(char *o, u32 n);
int sub_0200ECD0(char *o, int idx);
void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
void func_0200ED14(u8 *o, int idx, void *out);
u32 func_0200ED38(void);
void func_0200ED3C(void *block);
void *func_0200ED48(void *p);
void func_0200EA2C(void *block);



/*
 * Save-table init callback: clears the 0x16C-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200EA38).  Pointer word
 * 0x0200EA2D at 0x0209DD48.
 */
void func_0200EA2C(void *block)
{
    MI_CpuFill8(block, 0, 0x16C);
}



/*
 * Snapshot of a party into a 0x16c-byte ring record (func_0200EBD0's slot):
 * zero the six 0x3c-byte entries, then for every non-egg member (field 0x4c
 * of func_02017E1C is 0) store species (5), level (0x9e), the 6/2-bit pair
 * 0x6f/0x6e, fields 0 and 7, fields 0x36..0x39, and the nickname (0x73, 11
 * u16) and OT name (0x8d, 8 u16) through an 11-char string buffer, or the
 * terminator from func_02045A98 in both name slots when the buffer could not
 * be allocated.  The date record (first three words) goes to +0x168.
 * The layout of struct Entry is the one func_0200EC2C (EXACT*) reads back.
 *
 * Levers: the loop counter i is initialised AFTER the memset and before
 * n (both zeroes are then scheduled across the call with i first, which is
 * what puts i at sp+0x14 and n at sp+0x10); the species store goes through
 * rec->e[n] and every later field through the named entry pointer.
 *
 * EXACT* only because the 402 compiled bytes stop two short of the listing
 * extent at a "movs r0, r0" alignment filler; no byte differs.
 */
void func_0200EA3C(struct Rec *rec, void *party, struct Date *date, u32 heap)
{
    int count = func_0201AA18(party);
    void *buf = func_020457B0(11, heap);
    int i;
    int n;

    MI_CpuFill8(rec, 0, 0x168);
    i = 0;
    n = 0;
    for (; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 saved = func_02017D30(mon);
        if (func_02017E1C(mon, 0x4c, 0) == 0) {
            struct Entry *e = &rec->e[n];
            rec->e[n].species = func_02017E1C(mon, 5, 0);
            e->level = func_02017E1C(mon, 0x9e, 0);
            e->f03a = func_02017E1C(mon, 0x6f, 0);
            e->f03b = func_02017E1C(mon, 0x6e, 0);
            e->f04 = func_02017E1C(mon, 0, 0);
            e->f08 = func_02017E1C(mon, 7, 0);
            e->f32[0] = func_02017E1C(mon, 0x36, 0);
            e->f32[1] = func_02017E1C(mon, 0x37, 0);
            e->f32[2] = func_02017E1C(mon, 0x38, 0);
            e->f32[3] = func_02017E1C(mon, 0x39, 0);
            if (buf != 0) {
                func_02017E1C(mon, 0x73, (u32)buf);
                func_02045A38(buf, e->name, 11);
                func_02017E1C(mon, 0x8d, (u32)buf);
                func_02045A38(buf, e->ot, 8);
            } else {
                e->name[0] = func_02045A98();
                e->ot[0] = func_02045A98();
            }
            n++;
        }
        func_02017D70(mon, saved);
    }
    rec->year = date->year;
    rec->month = date->month;
    rec->day = date->day;
    if (buf != 0) {
        func_02045808(buf);
    }
}



/*
 * Ring-buffer record dispatcher: while the saturating counter at +0x1558 is
 * below 9999, hand the 0x16c-byte record at slot +0x1554 to func_0200EA3C,
 * then advance the slot (wrapping at 15) and the counter.
 *
 * The residue that stood for four passes (r6 vs r1, push one register
 * narrower) was the parameter list: func_0200EA3C takes FOUR arguments
 * (its prologue homes r0..r3), and this function forwards its own r1..r3 to
 * it untouched.  With a1..a3 live in r1..r3 across the prologue the index
 * temporary cannot take r1 and lands in r6.  The only caller
 * (ov205 0x021B9B62) passes (obj, func_02012934 result, &stack date record
 * from func_02088864, 4).  The slot index is read inline in the call's
 * argument, not through a named local.
 *
 * Current listing extent is 68 bytes; compiled bytes match exactly.
 */
void func_0200EBD0(struct Obj *obj, void *a1, void *date, u32 heap)
{
    if (obj->unk1558 < 9999) {
        u32 idx;
        func_0200EA3C((struct Rec *)((u8 *)obj + obj->unk1554 * 0x16c), a1, date, heap);
        idx = obj->unk1554 + 1;
        obj->unk1554 = idx;
        if (idx >= 15) {
            obj->unk1554 = 0;
        }
        obj->unk1558 += 1;
    }
}


/*
 * An unlabelled leaf: it saves nothing, so disasm.py's lr-saving prologue
 * sweep never fired and the bytes print as a run of `.word` in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing in
 * the image branches to it either, so no `function_starts.txt` seed exists.
 * First zero halfword of six 0x3c-byte records.
 *
 * It is not an anonymous hole, though: sub_0200ECD0 (src/matched/
 * unit_0200EC98.c) tail-calls it through a pool word, which is why that file
 * could not resolve its one relocation until this entry existed -- the
 * `matched` class is the only witness 0x0200EC14 can ever have, since no
 * branch anywhere in the image names it and its address appears in exactly
 * one pool.
 */
int func_0200EC14(char *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(u16 *)(p + i * 0x3c) == 0)
            break;
    }
    return i;
}


/*
 * One record of a 0x3c-byte table copied into a destination object.
 *
 * This closes the 76-byte residue that docs/notes/pkt_0200EA3C.c.txt
 * section 2 recorded.  Three spellings had to hold at once:
 *
 *  1. the byte at source +3 is a `u8 :6 / u8 :2` bitfield PAIR, not a plain
 *     u8.  The source side is what produces the `lsls #26 / lsrs #26` pair
 *     the note could not reach; reading it as a plain u8 and shifting gives
 *     `ands` instead and compiles 104 bytes.
 *  2. the destination byte at +0x13 is the same bitfield pair.  That is what
 *     turns the insert into `movs r1, #0x3f; ands r1, r3` rather than a
 *     single immediate mask.  Both sides are needed: either one alone is
 *     still wrong.
 *  3. the source pointer must be `const`.  Without it, the store to
 *     dst->f13a may alias s->f03a, so mwcc reloads `ldrb [r4, #3]` a second
 *     time for the `:2` field, two bytes over at 110.  The original loads it
 *     once into r2 and keeps it live across the first insert.  See
 *     docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *
 * EXACT* : the inferred extent ran to 0x0200ECF0 because the accessor at
 * 0x0200EC98 saves no lr and so carries no label.  0x0200EC98 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200EC2C.c \
 *       --func func_0200EC2C --addr 0x0200EC2C --cc 1.1p1 --thumb
 */
void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst)
{
    const struct Src0200EC2C *s = base + idx;
    int i;

    dst->f10 = s->f00;
    dst->f12 = s->f02;
    dst->f08 = s->f04;
    dst->f0C = s->f08;
    dst->f13a = s->f03a;
    dst->f13b = s->f03b;

    func_02045994(dst->p00, (const u16 *)s->f0C, 0xb);
    func_02045994(dst->p04, (const u16 *)s->f22, 8);

    for (i = 0; i < 4; i++)
        dst->f14[i] = s->f32[i];
}


/*
 * An unlabelled leaf accessor (it saves no lr, so disasm.py gives it no
 * label, see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It unpacks the three fields at +0x168..+0x16b of the object into a
 * four-word output record and zeroes the fourth word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200EC98.c \
 *       --func sub_0200EC98 --addr 0x0200EC98 --cc 1.1p1 --thumb
 */
void sub_0200EC98(const u8 *o, struct Out0200EC98 *out)
{
    out->a = *(const u16 *)&((struct Obj08961 *)o)->f168;
    out->b = o[0x16a];
    out->c = o[0x16b];
    out->d = 0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The tail of this packet: three unlabelled accessors of the object
 * func_0200EBD0 and func_0200EC2C work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * sub_0200EC98 (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * sub_0200ECD0 is a tail call through a pool word to
 * src/matched/func_0200EC14.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */
u32 sub_0200ECB4(char *o)
{
    u32 v = ((struct Obj17088 *)o)->f1558;

    if (v >= 0xf)
        v = 0xf;
    return v;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The tail of this packet: three unlabelled accessors of the object
 * func_0200EBD0 and func_0200EC2C work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * sub_0200EC98 (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * sub_0200ECD0 is a tail call through a pool word to
 * src/matched/func_0200EC14.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */
u32 sub_0200ECC4(char *o, u32 n)
{
    return ((struct Obj17089 *)o)->f1558 - n;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The tail of this packet: three unlabelled accessors of the object
 * func_0200EBD0 and func_0200EC2C work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * sub_0200EC98 (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * sub_0200ECD0 is a tail call through a pool word to
 * src/matched/func_0200EC14.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */
int sub_0200ECD0(char *o, int idx)
{
    int n = ((struct Obj17090 *)o)->f1554 - 1 - idx;

    if (n < 0)
        n += 0xf;
    return sub_0200EC14(o + n * 0x16c);
}


void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3)
{
    int v = ((struct Obj15609 *)a0)->f1554 - 1 - (int)a1;

    if (v < 0)
        v += 0xf;
    func_0200EC2C((const struct Src0200EC2C *)((u8 *)a0 + v * 0x16c), (int)a2, a3);
}


/*
 * An unlabelled accessor (its bytes print as a `.word` run after the pool
 * of func_0200ECF0): the header of ring entry `count - 1 - idx`, a tail call
 * to sub_0200EC98 through a pool word. Same shape as sub_0200ECD0 in
 * unit_0200ECB4.c. Its only caller is ov171 func_021DCCC8.
 */
void func_0200ED14(u8 *o, int idx, void *out)
{
    int n = *(int *)(o + 0x1554) - 1 - idx;

    if (n < 0)
        n += 0xf;
    sub_0200EC98(o + n * 0x16c, out);
}


/*
 * Save-table size callback: returns 0xFC, the size of the block that
 * func_0200ED3C clears.  Pointer word 0x0200ED39 at 0x0209DD5C.
 */
u32 func_0200ED38(void)
{
    return 0xFC;
}


/*
 * Save-table init callback: clears the 0xFC-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200ED44).  Pointer word
 * 0x0200ED3D at 0x0209DD60.
 */
void func_0200ED3C(void *block)
{
    MI_CpuFill8(block, 0, 0xFC);
}


/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void *func_0200ED48(void *p)
{
    return func_020071CC(p, 0x44);
}


/*
 * Insert `val` into a 32-entry u32 list unless it is already there: the
 * table is the object's first 0x80 bytes and the count lives at +0x80.
 * When the value is found at index i, everything above it shifts up one
 * slot (the memmove) and the value is rewritten into the last live slot
 * (`p[-1]` on a pointer to one past the end), so the list keeps its
 * length; when it is not found and there is room it goes at the end, and
 * when the list is full the whole table shifts up one slot and the value
 * lands in slot 31.
 *
 * Two shapes the bytes pinned down, both from
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md and the
 * signed/unsigned split:
 *
 *  - the copy is MI_CpuCopy8(src, dst, size) -- the SDK's argument order,
 *    which is why the source passes the higher index first: the shift is
 *    downward, arr[i+1] is copied onto arr[i];
 *  - the trailing store is NOT `l->arr[l->count - 1]` (which subtracts one
 *    from the count and then scales) but `p[-1]` on a pointer computed as
 *    `l->arr + l->count`: the original scales the count by four first and
 *    subtracts the element size afterwards, four instructions against
 *    three and the whole tail shifts;
 *  - the walk is unsigned (`bls`/`blo`) while the element count `n` that
 *    gates the shift is signed (`ble`).
 *
 * EXACT* rather than EXACT: the follower at 0x0200EDC4 saves registers but
 * not lr, so disasm.py did not label it (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md) and the inferred extent
 * runs to 0x0200EE48. The bytes all match; see
 * src/matched/unit_0200EDC4.c for that follower, which this project can
 * reproduce but has not been able to seed in layout/function_starts.txt.
 */
void func_0200ED54(struct L0200ED54 *l, u32 val)
{
    u32 i;
    int n;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i] != val)
            continue;
        n = (int)l->count - 1 - (int)i;
        if (n <= 0)
            return;
        MI_CpuCopy8(&l->arr[i + 1], &l->arr[i], (u32)n * 4);
        {
            u32 *p = l->arr + l->count;
            p[-1] = val;
        }
        return;
    }

    if (l->count < 32) {
        l->arr[l->count] = val;
        l->count++;
        return;
    }

    MI_CpuCopy8(&l->arr[1], &l->arr[0], 0x7c);
    l->arr[31] = val;
    l->count = 32;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The three functions that follow func_0200ED54 (src/matched/
 * func_0200ED54.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * func_0200ED54 inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */
int sub_0200EDC4(struct L0200EDC4 *l, u32 val)
{
    u32 i;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i] == val)
            return 1;
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The three functions that follow func_0200ED54 (src/matched/
 * func_0200ED54.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * func_0200ED54 inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */
int sub_0200EDEC(char *obj, int i)
{
    u32 *bits = (u32 *)(obj + 0x84);

    return (bits[i / 32] >> (i % 32)) & 1;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The three functions that follow func_0200ED54 (src/matched/
 * func_0200ED54.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * func_0200ED54 inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */
void sub_0200EE14(char *obj, int i)
{
    if (i >= 256)
        return;
    ((u32 *)(obj + 0x84))[i / 32] |= (u32)(1 << (i % 32));
}
