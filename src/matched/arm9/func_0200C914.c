/*
 * function: func_0200C914
 * address:  0x0200C914
 * packet:   pkt_0200C914
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The "caught" half of the musical-distribution form bookkeeping in
 * "musical_dist_save.c": it sets one bit of one of the two nine-byte form
 * bitmaps at +0x2FC (base) and +0x305 (alt), indexed by the flat form index
 * func_0200C7C0 answers for the species.
 *
 * Four species ids get a fixed form count and a forced start of zero: 0x15F
 * with four forms and 0x1A5 / 0x22B / 0x288 with two each.  Everything else
 * takes one form and clamps the caller's form index against func_0200CC20's
 * count for that species.
 *
 * What closed it, after the two things the older DIFF note
 * (docs/notes/pkt_0200C914.c.txt) had wrong:
 *
 *  - the loop counter is `u16`, not `unsigned`.  Its `lsls #0x10 / lsrs
 *    #0x10` truncation at the top of each loop body is the tell, and the note's
 *    `unsigned i` loses eight bytes of it (208 against the original's 216 code
 *    bytes).  See docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 *    for the general shape.
 *  - the "not listed" sentinel is compared as `u32`, not as `int`.  The
 *    original builds it with `movs r1, #0 / mvns r1, r1` and a register
 *    `cmp`, which is what `res == (u32)-1` emits when func_0200C7C0 is
 *    declared to return `u32`, exactly as src/matched/unit_0200C7C0.c
 *    defines it.  Declared `int` with a literal `-1` the compare folds to an
 *    immediate and the whole head reallocates; that was the "codegen,
 *    register allocation" verdict the old note recorded, and it was really a
 *    type error.
 *  - `idx` is a SIGNED int holding a `(u16)` value.  `idx >> 3` is `asrs` in
 *    the original and `lsrs` when idx is `u32`; those two instructions were
 *    the last two concrete bytes out.  See
 *    docs/idioms/ldrsh-register-offset-is-signedness.md for the same class of
 *    tell read off a load.
 *
 * The first parameter is spelled `u8 *` here and `struct Blk37 *` in the two
 * callers (src/matched/unit_0200CDE0.c and src/matched/unit_0200CFA0.c); the
 * second is `u32` here and `u16` at the call sites, which widens without
 * truncation, so neither caller's argument changes.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_0200C914.c \
 *       --func func_0200C914 --addr 0x0200C914 --cc 1.1p1 --thumb
 *   -> EXACT* (216 code bytes; the listing extent runs to 224 over the eight
 *      bytes of literal pool that follow the body)
 *
 * symbols:
 *   func_0200C7C0  0x0200C7C0  thumb
 *   func_0200CC20  0x0200CC20  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_0200C7C0(u16 id);
extern u16 func_0200CC20(u32 a);

void func_0200C914(u8 *p, u32 id, u32 a2, u32 a3, u32 start)
{
    u32 res;
    u32 cnt;
    u16 i;

    res = func_0200C7C0((u16)id);
    if (res == (u32)-1) {
        return;
    }
    if (id == 0x15F) {
        start = 0;
        cnt = 4;
    } else if (id == 0x1A5) {
        start = 0;
        cnt = 2;
    } else if (id == 0x22B) {
        start = 0;
        cnt = 2;
    } else if (id == 0x288) {
        start = 0;
        cnt = 2;
    } else {
        if (start >= func_0200CC20((u16)id)) {
            start = 0;
        }
        cnt = 1;
    }
    if (a3 == 1) {
        for (i = 0; i < cnt; i++) {
            u8 m;
            s32 idx = (u16)(res + start + i);
            m = (u8)(1 << (idx & 7));
            p[0x305 + (idx >> 3)] |= m;
        }
    } else {
        for (i = 0; i < cnt; i++) {
            u8 m;
            s32 idx = (u16)(res + start + i);
            m = (u8)(1 << (idx & 7));
            p[0x2FC + (idx >> 3)] |= m;
        }
    }
}
