/*
 * file:     mail_p03.c
 * unit:     yes
 * function: func_02008C20, func_02008C28, func_02008C58, func_02008C64, func_02008C94, func_02008CB4, func_02008CD4, func_02008CF8, func_02008D1C, func_02008D58, func_02008DAC, func_02008DF0, func_02008DFC, func_02008E30, func_02008E68, func_02008E78, func_02008E88, func_02008EAC, func_02008EF8, func_02008F08, func_02008F3C, func_02008F48, func_02008F80, func_02008F84, func_02008F88, func_02008F9C, func_02008FA0, func_02008FA4, func_02008FA8, func_02008FB0, func_02008FB4, func_02008FB8, func_02008FBC, func_02008FC0, func_02008FC4, func_02008FC8, func_02008FD8, func_02008FEC
 * address:  0x02008C20
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
 *   func_02082A7C  0x02082A7C  arm
 *   func_02008C64  0x02008C64  thumb
 *   sub_020071CC  0x020071CC  thumb
 *   sub_0203F2FC  0x0203F2FC  arm
 *   sub_0203F328  0x0203F328  arm
 *   sub_0203F37C  0x0203F37C  arm
 *   g_020A70AC      0x020A70AC  data
 *   g_020A70C4      0x020A70C4  data
 *   g_0209DDB4      0x0209DDB4  data
 *   g_020A716C      0x020A716C  data
 *   g_0209DDA0      0x0209DDA0  data
 *   unk_0209DF0C   0x0209DF0C  data
 *   unk_0209DF08   0x0209DF08  data
 *   func_02045A98  0x02045A98  arm
 *   func_0202428C  0x0202428C  thumb
 *   MIi_CpuClear16 0x02082A48  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   sub_02012EBC  0x02012EBC  thumb
 *   sub_02024570  0x02024570  thumb
 */
#include "../../matched/include/Obj02635.h"

struct Sub02008C20Obj;
struct Sub020071CCCtrl;
struct Sub02008EACObj;
struct Sub0200852CObj;
struct Big;
struct Rec8;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub02008C20Obj {
    u32 unk000[0x47];
    u16 unk11C[0x60];
    u16 unk1DC;
    u16 unk1DE;
};

struct Entry02008E30 {
    u16 a;
    u16 b;
};

struct Sub0202428CObj {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
};

struct Sub02008EACObj {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u16 unk08[8];
    u16 unk18[3];
    u16 unk1E;
    struct Sub0202428CObj unk20[3];
};

struct Sub02008F80Obj_02008EF8 {
    u8 unk00[7];
    u8 unk07;
};

struct Sub02008F80Obj_02008F3C {
    u8 unk00[0x38];
};

struct Sub02008EACObjLayout {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08[0x10];
};

struct Sub02008F80Entry {
    u8 unk00[8];
};

struct Sub02008F80Obj_02008F80 {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08[0x10];
    u8  unk18[6];
    u16 unk1E;
    struct Sub02008F80Entry unk20[3];
};

extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02008C64(struct Sub02008C20Obj *obj, int commit);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
/* The checksum pair over a byte range: sub_0203F2FC computes it, sub_0203F328
 * writes it back into the range's own trailer. */
extern u32 sub_0203F2FC(const u8 *p, u32 len);
extern void sub_0203F328(u16 *p, u32 size, u32 seed);
extern void sub_0203F37C(void *p, u32 size, u32 sum);
void sub_02008C64(struct Sub02008C20Obj *obj, int commit);
u32  sub_02008CB4(const struct Sub02008C20Obj *obj, int i);
extern int sub_02008CF8(int idx);
extern void sub_02008C94(struct Sub02008C20Obj *obj, int i);
extern u32  sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value);
u32 sub_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern u32 func_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit);
extern u32 func_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value);
int func_02008CF8(int idx);
void func_02008E30(void *a0);
extern u32 sub_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit);
extern u32 sub_02008DFC(struct Sub02008C20Obj *obj, int i);
extern u16  func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);
extern void func_0202428C(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void sub_02008EAC(struct Sub02008EACObj *obj);
extern u8 *func_02012944(void *p);
extern const void *sub_020084F4(const void *p);
extern u32 sub_02008530(const struct Sub0200852CObj *obj);
extern u8  sub_02008550(const struct Sub0200852CObj *obj);
extern void *sub_02012EBC(struct Big *p);
extern void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);
void *func_02008F08(int a0);
u32 sub_02008C20(void);
void func_02008C28(void *obj);
struct Sub02008C20Obj *sub_02008C58(void *sys);
void sub_02008E68(struct Sub02008C20Obj *obj, u32 value);
extern unsigned char g_020A70C4[];
extern int g_0209DDB4[];
extern struct Entry02008E30 g_0209DDA0[5];
extern const u8 unk_0209DF0C;
extern const u8 unk_0209DF08;
extern char g_020A716C[];



/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (6 bytes, leaf, no relocations):
 *   movs r0, #0x1e
 *   lsls r0, r0, #4
 *   bx   lr
 *
 * The first function of the save block with id 0x26: it returns the block's
 * own size, 0x1E0, which is what the constructor at 0x02008C28 clears.  0x1E0
 * has no Thumb immediate encoding, so it arrives as a `movs` of 0x1E and a
 * shift rather than out of a literal pool; a pool would have cost four bytes
 * more and this compiler prefers the shift for any constant it can build in
 * two instructions.
 *
 * The rest of the file is src/matched/unit_02008C58.c; see its header for the
 * block layout and for the near miss that separates the two.
 */
u32 sub_02008C20(void)
{
    return sizeof(struct Sub02008C20Obj);
}



#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)



/*
 * The block constructor: MIi_CpuClear32 wipes 0x1E0 bytes, then the checksum
 * high half (+0x1DE) is seeded from the word at 0x02FFFC3C in the shared
 * region, then sub_02008C64 commits.  This is the block whose layout
 * src/matched/unit_02008C58.c describes; that file called it a "NEAR MISS, 48
 * bytes, 3 concrete bytes wrong" and blamed the register numbering of the three
 * loads.  The three bytes are in fact the operand order of the combine, and the
 * spelling that reproduces them is two named u32 locals assigned in order (a
 * first, then b) and combined as `a << 8 | b`, which puts the pool address in r1
 * and the first value in r0 as the original does.  The two reads must not be
 * commoned up, so the 0x02FFFC3C cast constant is `volatile`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02008C28.c \
 *       --func func_02008C28 --addr 0x02008C28 --cc 1.1p1 --thumb
 */
void func_02008C28(void *obj)
{
    u32 a;
    u32 b;

    func_02082A7C(0, obj, 0x1e0);
    a = unk_02FFFC3C;
    b = unk_02FFFC3C;
    ((struct Obj02635 *)obj)->f1DE = a << 8 | b;
    func_02008C64(obj, 1);
}



#define BLOCK_ID 0x26



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008CD4
 *
 * alias: the head of the save block with id 0x26, 0x1E0 bytes.  The original
 * file opens at 0x02008C20 with the four bytes that return that size
 * (src/matched/sub_02008C20.c) and this range follows the constructor; the
 * file runs on past 0x02008CF8, where it starts reaching into the static
 * tables at 0x0209DDB4 and 0x020A70C4, which is where this range stops.
 *
 * What the attestation rules say about the run after it, checked with the
 * indexes behind `python tools/match.py tu --suggest-split`:
 *
 *  - sub_02008CF8 itself stays blocked, and not for want of a cut.  It loads
 *    0x020A70C4 and 0x0209DDB4, and each of those two addresses is named by
 *    exactly one pool word in the whole image, its own, at 0x02008D14 and
 *    0x02008D18.  The `literal` class has nothing outside the range, and the
 *    `string` class cannot reach either: 0x020A70C4 is the data table
 *    immediately after "playtime.c", not a string.  It closes the day
 *    anything else in the image loads one of them.
 *  - the four functions after it, 0x02008D1C..0x02008E30, are no longer
 *    blocked by attestation at all, only by not having been written.  Each of
 *    them calls sub_02008C64, sub_02008C94, sub_02008CB4, sub_02008CD4 and
 *    sub_02008CF8, and the callers of each of those five are spread across
 *    several of the four, so any range holding at most two of the four leaves
 *    every one of the five a witness outside it.  0x02008D1C..0x02008DAC and
 *    0x02008DAC..0x02008E30 is such a pair, and the twelve byte thunk at
 *    0x02008DF0 is `local` to the second of them.
 *
 * The block is a flat table with two element widths and its own checksum:
 *
 *   +0x000  u32[0x47]   indices 0x00..0x46
 *   +0x11C  u16[0x60]   indices 0x47..0xA6
 *   +0x1DC  u16         the low half of a checksum over +4..+0x1DC
 *   +0x1DE  u16         ... and its high half
 *
 * sub_02008CB4 and sub_02008CD4 are the getter and setter over that split
 * index space, and both answer 0 for an index at or past 0xA7.  The setter
 * returns what the getter would return, by calling it: the `bl` at the point
 * where both arms have joined is a tail call the compiler could not turn into
 * a `b` because it still has `r4` to pop.
 *
 * The checksum covers 0x1D8 bytes starting at +4, not the whole block, and the
 * pair at +0x1DC and +0x1DE is one 32 bit value split across two `u16` fields:
 * sub_02008C64 reassembles it with an `adds`, not an `orrs`, so the source
 * adds rather than ors.
 *
 * NEAR MISS, 0x02008C28, 48 bytes, 3 concrete bytes wrong, skipped.  The
 * constructor clears the block and then seeds +0x1DE from the word at
 * 0x02FFFC3C in the region the two processors share.  That word is read twice
 * in a row and the two loads are not commoned up, which is a `volatile` read
 * and nothing else: written as a plain `extern u32` the function is two
 * instructions short.  With the `volatile` the size, the schedule and every
 * instruction are the original's, and the three wrong bytes are the register
 * numbering of the three loads alone: the original puts the pool address in
 * `r1` and the first value in `r0`, the compiler does the reverse.  Eleven
 * source shapes were tried (both operand orders, a temporary for either side,
 * a cast on either side, an array-typed declaration, a `const volatile`
 * declaration, and the multiply that folds the two terms into one) and none of
 * them moves it off three.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008C58.c  *       --addr 0x02008C58 --thumb
 */
struct Sub02008C20Obj *sub_02008C58(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}



void sub_02008C64(struct Sub02008C20Obj *obj, int commit)
{
    if (commit) {
        obj->unk1DC = sub_0203F2FC((const u8 *)(&obj->unk000[1]), 0x1D8);
        sub_0203F328((u16 *)(&obj->unk000[1]), 0x1D8,
                     obj->unk1DC + (obj->unk1DE << 16));
    }
}

void sub_02008C94(struct Sub02008C20Obj *obj, int commit)
{
    if (commit) {
        sub_0203F37C(&obj->unk000[1], 0x1D8,
                     obj->unk1DC + (obj->unk1DE << 16));
    }
}

u32 sub_02008CB4(const struct Sub02008C20Obj *obj, int i)
{
    if (i < 0x47) {
        return obj->unk000[i];
    }
    if (i < 0xA7) {
        return obj->unk11C[i - 0x47];
    }
    return 0;
}

u32 sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value)
{
    if (i < 0x47) {
        obj->unk000[i] = value;
    } else if (i < 0xA7) {
        obj->unk11C[i - 0x47] = value;
    }
    return sub_02008CB4(obj, i);
}

int func_02008CF8(int idx)
{
    int v = g_020A70C4[idx];
    if (v >= 0xa7) return 0;
    if (v >= 6) return 0;
    return g_0209DDB4[v];
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the first half of the clamped read-modify-write layer over the save
 * block with id 0x26 (src/matched/unit_02008C58.c).  Each of these takes the
 * block and a counter index, looks the counter's ceiling up with
 * sub_02008CF8, unlocks the block with sub_02008C94, writes through
 * sub_02008CD4 and re-checksums with sub_02008C64.
 *
 * The cut at 0x02008DAC is the one the header of unit_02008C58.c recorded as
 * viable: sub_02008CF8, sub_02008C64, sub_02008C94, sub_02008CB4 and
 * sub_02008CD4 are each called from both halves, so each half is the other's
 * outside witness and no site is left without one.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008D1C.c \
 *       --addr 0x02008D1C --thumb
 */
u32 sub_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    if (value < max) {
        result = sub_02008CD4(obj, i, value);
    } else {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}

u32 sub_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    result = sub_02008CB4(obj, i);
    if (limit > max) {
        limit = max;
    }
    if (result < limit) {
        result = sub_02008CD4(obj, i, limit);
    } else if (result > max) {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the second half of the clamped read-modify-write layer over the save
 * block with id 0x26; see src/matched/unit_02008D1C.c for the cut.
 *
 * sub_02008DF0 is twelve bytes with no prologue and carries no label in the
 * listing: `ldr r3, [pc, #4]; movs r2, #1; bx r3` plus the pool word
 * 0x02008DAD.  That is `return sub_02008DAC(obj, i, 1);`, the increment-by-one
 * spelling of the function above it, and it is `local` to this range because
 * sub_02008DAC is in it.
 *
 * The one byte that had to be found: `adds r2, r0, r7` in sub_02008DAC is the
 * counter plus the delta with the *call result* in the left slot, and that
 * only happens when a named local holds it.  Written inline in either operand
 * order, `sub_02008CB4(obj, i) + delta` and `delta + sub_02008CB4(obj, i)`
 * both give `adds r2, r7, r0`.  See
 * docs/idioms/commutative-operand-order-names-the-temporary.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008DAC.c \
 *       --addr 0x02008DAC --thumb
 */
u32 sub_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta)
{
    u32 max = sub_02008CF8(i);
    u32 result;
    u32 cur;

    sub_02008C94(obj, i);
    cur = sub_02008CB4(obj, i);
    result = cur + delta;
    if (result < max) {
        result = sub_02008CD4(obj, i, result);
    } else {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}

u32 sub_02008DF0(struct Sub02008C20Obj *obj, int i)
{
    return sub_02008DAC(obj, i, 1);
}

u32 sub_02008DFC(struct Sub02008C20Obj *obj, int i)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    result = sub_02008CB4(obj, i);
    sub_02008C64(obj, i);
    if (result <= max) {
        max = result;
    }
    return max;
}


/*
 *           this function's own.  The `literal` class discards that witness
 *           under the honesty rule and no cut helps (the pool word is inside
 *           the section whatever the range).  Every concrete byte is right:
 *           56 bytes, 3 calls resolved, 1 ABS32 wildcarded.
 */
void func_02008E30(void *a0)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        u16 b = g_0209DDA0[i].b;

        func_02008D58(a0, g_0209DDA0[i].a, func_02008DFC(a0, b));
        func_02008D1C(a0, b, 0);
    }
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the named entry points on top of the clamped counter layer of
 * src/matched/unit_02008D1C.c and src/matched/unit_02008DAC.c.  Counter 0x7B
 * has a ceiling of 6 and counter 0x7C a ceiling of 9999, and each writer range
 * checks its argument against that ceiling before writing.
 *
 * The ceiling table sub_02008CF8 indexes is at 0x0209DDB4 and is six words:
 * 999999999, 999999, 65535, 9999, 999, 6.  That is what makes the bare 9999
 * here and the 7 in sub_02008E68 readable.
 *
 * sub_02008EA0 is twelve bytes with no prologue and no label:
 * `ldr r3, [pc, #4]; movs r1, #0x7c; bx r3` over the pool word 0x02008DFD,
 * that is `return sub_02008DFC(obj, 0x7C);`.
 *
 * NEAR MISS, 0x02008E30, 56 bytes, MATCH with every concrete byte right,
 * skipped.  It walks a five entry table of counter index pairs at 0x0209DDA0,
 *
 *   1A 1B  51 52  53 54  55 56  57 58
 *
 * copying the value of each pair's second counter into its first through
 * sub_02008D58 and then zeroing the second with sub_02008D1C.  Written as
 *
 *   for (i = 0; i < 5; i++) {
 *       int src = tbl[i].unk02;
 *       sub_02008D58(obj, tbl[i].unk00, sub_02008DFC(obj, src));
 *       sub_02008D1C(obj, src, 0);
 *   }
 *
 * over `struct { u16 unk00; u16 unk02; }` it reproduces all 56 bytes, both
 * loads of the one pool word included, and caps at MATCH on the pool word
 * itself: 0x0209DDA0 is named by exactly one word in the 3.9 MB image, its own
 * at 0x02008E64, so the `literal` class discards its only witness and no cut
 * helps.  `--suggest-split` reports the same and leaves this one function out.
 * It is a table of halfwords, not a string, so the `string` class cannot reach
 * it either.  It closes the day anything else in the image loads 0x0209DDA0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008E68.c \
 *       --addr 0x02008E68 --thumb
 */
void sub_02008E68(struct Sub02008C20Obj *obj, u32 value)
{
    if (value < 7) {
        sub_02008D58(obj, 0x7B, value);
    }
}

u8 sub_02008E78(struct Sub02008C20Obj *obj)
{
    return sub_02008DFC(obj, 0x7B);
}

void sub_02008E88(struct Sub02008C20Obj *obj, u32 value)
{
    if (value < 9999) {
        sub_02008D58(obj, 0x7C, value);
    }
}

u32 sub_02008EA0(struct Sub02008C20Obj *obj)
{
    return sub_02008DFC(obj, 0x7C);
}


static inline void MI_CpuFill16(void *dest, u16 data, u32 size)
{
    MIi_CpuClear16(data, dest, size);
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the constructor of a 0x38-byte record.  It is the last function of
 * the file that begins at 0x02008C20 with the 0x26 save block, or the first of
 * the next one; nothing in the bytes separates them, so it is kept as its own
 * range.
 *
 * The two byte globals it seeds the record from are 0x0209DF0C and 0x0209DF08,
 * and each is also loaded from a pool word in 005_02013528.s, at 0x020178C8
 * and 0x020178D4, which is what attests them.
 *
 * `MI_CpuFill16` is the SDK header's inline wrapper: it compiles to a direct
 * `blx MIi_CpuClear16` with the data and destination swapped, which is exactly
 * what the original does.  Calling MIi_CpuClear16 by hand would produce the
 * same bytes, but the wrapper is what the source said.
 *
 * The 0xFFFF at +0x1E is a pool word rather than a `movs`, because the Thumb
 * immediate stops at 255; the 0xFF at +7 is a `movs`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008EAC.c \
 *       --addr 0x02008EAC --thumb
 */
void sub_02008EAC(struct Sub02008EACObj *obj)
{
    int i;

    obj->unk00 = 0;
    obj->unk04 = 0;
    obj->unk05 = unk_0209DF0C;
    obj->unk06 = unk_0209DF08;
    obj->unk07 = 0xFF;
    MI_CpuFill16(obj->unk08, func_02045A98(), sizeof(obj->unk08));
    obj->unk1E = 0xFFFF;
    for (i = 0; i < 3; i++) {
        func_0202428C(&obj->unk20[i]);
    }
}


/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (14 bytes, leaf, no relocations):
 *   ldrb r0, [r0, #7]
 *   cmp  r0, #0xb
 *   bhi  0x2008f02
 *   movs r0, #1
 *   bx   lr
 *   movs r0, #0
 *   bx   lr
 *
 * The range predicate on the byte at +7 of the 0x38-byte object described in
 * src/matched/unit_02008F80.c: the setter there refuses anything at or past
 * 0xC, and this answers whether the field is inside that range.  `bhi` rather
 * than `bgt` is the only evidence that the comparison is unsigned; the field is
 * loaded with `ldrb` either way.
 *
 * The taken arm is the zero, so the source tests the in-range case and returns
 * 1 by falling through.
 *
 * Recorded as a one-function byte range rather than as a function entry
 * because the function ends at 0x02008F06 and the next label is at 0x02008F08:
 * two bytes of inter-section fill sit between them, so the extent disasm.py
 * infers runs two bytes long and a function entry would read EXACT*.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008EF8.c  *       --addr 0x02008EF8 --thumb
 */
int sub_02008EF8(const struct Sub02008F80Obj_02008EF8 *obj)
{
    if (obj->unk07 <= 0xB) {
        return 1;
    }
    return 0;
}

void *func_02008F08(int a0)
{
    void *p = func_02030734((unsigned short)((a0 & 0x7fff) | 0x8000), 0x38, 0, g_020A716C, 0x87);
    func_02008EAC(p);
    return p;
}


/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (6 bytes plus a literal pool, leaf):
 *   ldr  r3, [pc, #4]
 *   movs r2, #0x38
 *   bx   r3
 *
 * A whole-object copy of the 0x38-byte object described in
 * src/matched/unit_02008F80.c.  Both pointer arguments are already in the
 * registers MI_CpuCopy8 wants, so the only work is the size and the tail call;
 * the `bx r3` rather than a `blx` is what a tail call to an ARM function
 * through a pool word looks like, and the pool word carries the Thumb bit
 * clear because the callee is ARM.
 */
void sub_02008F3C(const struct Sub02008F80Obj_02008F3C *src, struct Sub02008F80Obj_02008F3C *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Sub02008F80Obj_02008F3C));
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: mail.c.  The record this fills in is the 0x38-byte object
 * src/matched/unit_02008EAC.c constructs and src/matched/unit_02008F80.c
 * accesses, and the file name is in the image: the allocator at 0x02008F08
 * passes 0x020A716C to the debug allocator and those bytes spell "mail.c".
 *
 * sub_020084F4 is four bytes, `bx lr`, and src/matched/unit_020084BC.c records
 * it as `void sub_020084F4(void)`.  This call site says what it is: its result
 * feeds MI_CpuCopy8's source operand with no move in between, so it is an
 * identity accessor on its argument, declared here with the type that call
 * needs.  The declaration is a claim about the source, not about the bytes,
 * which are `bx lr` either way.
 *
 * The third parameter is dead: nothing in the function reads r2.
 *
 * NEAR MISS, 0x02008F08, 52 bytes, MATCH with every concrete byte right,
 * skipped.  It is mail.c's allocator,
 *
 *   struct Mail *sub_02008F08(u32 heap)
 *   {
 *       struct Mail *p = sub_02030734((u16)((heap & 0x7FFF) | 0x8000), 0x38,
 *                                     0, sub_02008F08_File, 135);
 *       sub_02008EAC(p);
 *       return p;
 *   }
 *
 * which reproduces all 52 bytes, the single 0x7FFF pool word the compiler
 * turns into 0x8000 with `adds r0, r1, #1` included, and caps at MATCH on the
 * __FILE__ pool word.  0x020A716C is named by exactly one word in the image,
 * its own at 0x02008F38, so `literal` has no witness and no cut helps.  The
 * `string` class cannot reach it either, and the reason is worth recording:
 * the run before "mail.c" is not a string.  Its single NUL terminator at
 * 0x020A716B is preceded by 0x2B bytes of 0x02 and 0x03, a static table, so
 * condition 5 of the rule ("the bytes before those NULs are themselves at
 * least four printable ASCII characters") refuses it.  A string at the head of
 * a string section, or one whose neighbour is data, has no outside witness at
 * all.  See docs/idioms/a-string-after-a-data-table-has-no-witness.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008F48.c \
 *       --addr 0x02008F48 --thumb
 */
void sub_02008F48(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused,
                  void *p)
{
    struct Sub0200852CObj *src;

    sub_02008EAC((struct Sub02008EACObj *)obj);
    obj->unk07 = kind;
    src = (struct Sub0200852CObj *)func_02012944(p);
    MI_CpuCopy8(sub_020084F4(src), obj->unk08, sizeof(obj->unk08));
    obj->unk04 = sub_02008550(src);
    obj->unk00 = sub_02008530(src);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008FA0, sub_02008FA4, sub_02008FA8, sub_02008FB0,
 *           sub_02008FB4, sub_02008FB8, sub_02008FBC, sub_02008FC0,
 *           sub_02008FC4, sub_02008FC8, sub_02008FD8, sub_02008FEC
 *
 * The accessor tail of the 0x38-byte object the allocator at 0x02008F08 hands
 * out, plus the two functions after it.  The range is closed on the right by
 * 0x02008FFC, which is a four-byte function returning 0x460: the size-returning
 * opener of the next file, the same seam that separates the three save block
 * files before this one.  On the left it is closed by the end of sub_02008F48
 * at 0x02008F7E.
 *
 * Fourteen of the sixteen carry no label in the generated listing, because
 * disasm.py's prologue sweep only fires on a function that saves `lr` and a
 * two-instruction accessor saves nothing; the listing emits them as data words
 * and they were read out of the bytes.
 *
 * Object layout, from the accessors:
 *
 *   +0x00  u32   get by sub_02008F80, written by sub_02008F48
 *   +0x04  u8    get/set
 *   +0x05  u8    get/set
 *   +0x06  u8    get/set
 *   +0x07  u8    get by sub_02008F9C's neighbour; the setter refuses >= 0xC
 *   +0x08  0x10  a block copied in whole by sub_02008F88, address handed out
 *                by sub_02008F84
 *   +0x1E  u16   get/set
 *   +0x20  3 x 8 a small table, indexed with a range check that folds out of
 *                range to entry 0 rather than failing
 *
 * Two things worth naming:
 *
 *  - sub_02008F88 copies *into* the object, not out of it.  The argument
 *    shuffle says so: `adds r2, r0, #0` / `adds r2, #8` builds the field
 *    address in `r2`, then `adds r0, r1, #0` puts the caller's pointer in the
 *    source register and `adds r1, r2, #0` the field in the destination
 *    register.  Reading the `#8` as the first argument inverts the function.
 *  - sub_02008FC8 falls through to the in-range arm and puts the out of range
 *    arm at the end, so the source tests `i < 3` first and returns entry 0
 *    after it.  Written the other way round the compiler emits the same six
 *    instructions with the branch inverted and the two arms swapped, which is
 *    ten wrong bytes in a sixteen-byte function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008F80.c \
 *       --addr 0x02008F80 --thumb
 */
u32 sub_02008F80(const struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk00;
}

u8 *sub_02008F84(struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk08;
}

void sub_02008F88(struct Sub02008F80Obj_02008F80 *obj, const void *src)
{
    MI_CpuCopy8(src, obj->unk08, sizeof(obj->unk08));
}

u8 sub_02008F9C(const struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk04;
}

void sub_02008FA0(struct Sub02008F80Obj_02008F80 *obj, u8 value)
{
    obj->unk04 = value;
}

u8 sub_02008FA4(const struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk07;
}

void sub_02008FA8(struct Sub02008F80Obj_02008F80 *obj, u32 value)
{
    if (value < 0xC) {
        obj->unk07 = value;
    }
}

u8 sub_02008FB0(const struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk05;
}

void sub_02008FB4(struct Sub02008F80Obj_02008F80 *obj, u8 value)
{
    obj->unk05 = value;
}

u8 sub_02008FB8(const struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk06;
}

void sub_02008FBC(struct Sub02008F80Obj_02008F80 *obj, u8 value)
{
    obj->unk06 = value;
}

u16 sub_02008FC0(const struct Sub02008F80Obj_02008F80 *obj)
{
    return obj->unk1E;
}

void sub_02008FC4(struct Sub02008F80Obj_02008F80 *obj, u16 value)
{
    obj->unk1E = value;
}

struct Sub02008F80Entry *sub_02008FC8(struct Sub02008F80Obj_02008F80 *obj, u32 i)
{
    if (i < 3) {
        return &obj->unk20[i];
    }
    return &obj->unk20[0];
}

void sub_02008FD8(struct Sub02008F80Obj_02008F80 *obj, void *arg, u32 i)
{
    if (i < 3) {
        sub_02024570((struct Rec8 *)(&obj->unk20[i]), arg);
    }
}

struct Sub02008F80Obj_02008F80 *sub_02008FEC(void *sys)
{
    return sub_020071CC(sub_02012EBC(sys), 0x28);
}
