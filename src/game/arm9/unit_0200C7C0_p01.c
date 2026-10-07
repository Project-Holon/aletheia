/*
 * file:     unit_0200C7C0_p01.c
 * unit:     yes
 * function: func_0200C7C0, func_0200C7F4, func_0200C818, func_0200C914, func_0200C9EC, func_0200C9F4, func_0200CA10, func_0200CA1C, func_0200CA28, func_0200CA38, func_0200CA40, func_0200CA70, func_0200CA78, func_0200CA8C, func_0200CA98, func_0200CC20
 * address:  0x0200C7C0
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
 *   func_0200C7C0_Table  0x0209DE4C  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0200CA98_Table  0x0209DE4C  data
 */
struct Big;
struct Sub020071CCCtrl;
typedef unsigned short u16;

typedef unsigned int   u32;

struct DistEnt {
    u16 id;
    u16 count;
};

typedef unsigned char u8;

typedef signed int     s32;

struct Blk37_0200C9EC {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk08[0x4CC];
};

struct Blk37_0200CA98 {
    u32 unk00;
    u32 unk04;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

struct FormCount {
    u16 unk00;
    u16 unk02;
};

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02012EBC(struct Big *p);
void *func_0200CA10(void *sys);
u32 func_0200C7C0(u16 id);
u32 func_0200C7F4(u32 id);
void sub_0200C818(u8 *p, u32 idx, int sel, int half);
void func_0200C914(u8 *p, u32 id, u32 a2, u32 a3, u32 start);
u32 func_0200C9EC(void);
u16 func_0200CC20(u32 a);
extern const struct DistEnt func_0200C7C0_Table[];
extern const struct FormCount func_0200CA98_Table[];



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 88 bytes, 0x0200C7C0..0x0200C818, 2 functions, neither of which carries a
 * label in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the name is attested.
 *
 * Two searches of the same zero-terminated table of `{u16 id, u16 count}`
 * pairs at 0x0209DE4C: the first returns the running sum of the counts in
 * front of the match, which is a base index into a flat array, and the second
 * returns the entry's own index.  Both return ~0 when the id is not listed,
 * spelled `movs r0, #0` / `mvns r0, r0` rather than a pool word.
 *
 * Both are `do`/`while` loops and not `while` loops: the key of entry zero is
 * never tested before the first body, so the table is known to be non-empty
 * by construction.  A `while (tbl[i].key != 0)` adds the entry test in front
 * of the loop and moves every instruction after it.
 *
 * The declaration order of the two locals in func_0200C7C0 is load bearing
 * and is the only thing the bytes say about it: the running sum is declared
 * first and lands in r2, the index second and lands in r3.  Declared the
 * other way round the two swap registers and five bytes differ with nothing
 * else moving.
 *
 * The pool word holding 0x0209DE4C is attested as `literal`: three literal
 * pools in the image hold that address, so even with both of these functions
 * in one range a witness survives outside it.
 *
 * The two neighbours immediately before this range, func_0200C780 and
 * func_0200C7A0, reproduce every concrete byte and stay at MATCH.  Each is a
 * linear scan of a `u16` table, at 0x0209DE2C with fifteen entries and at
 * 0x0209DE20 with six, and each table's address appears in exactly one
 * literal pool in the whole image: its own.  The `literal` class discards
 * that witness under the honesty rule and no cut helps, because shrinking the
 * range to one function keeps its own pool word in it.  Evidence class:
 * `literal`, no outside witness; the C is not in question.
 */
u32 func_0200C7C0(u16 id)
{
    u32 base = 0, i = 0;

    do {
        if (id == func_0200C7C0_Table[i].id) {
            return base;
        }
        base += func_0200C7C0_Table[i].count;
        i++;
    } while (func_0200C7C0_Table[i].id != 0);
    return (u32)-1;
}



u32 func_0200C7F4(u32 id)
{
    u32 i = 0;

    do {
        if (id == func_0200C7C0_Table[i].id) {
            return i;
        }
        i++;
    } while (func_0200C7C0_Table[i].id != 0);
    return (u32)-1;
}



/*
 * Set one bit in a byte array of a manager struct.  `sel` picks the pair of
 * tables, `half` which table of the pair, and the bit is entry `idx - 1`
 * (the parameter is 1-based).  Each of the six arms is an independent
 * read-modify-write of one byte.
 *
 * Shape notes:
 *  - `idx` is 32-bit in the ABI: every arm opens with a cast-to-u16 /
 *    subtract-one / cast-to-u16 quintet, which is `u16 i = (u16)idx - 1;`
 *    and only exists when the parameter is wider than u16.  Declaring the
 *    parameter `u16` loses the leading shift pair and reallocates the whole
 *    function (196 vs 250 bytes).
 *  - The index local is declared inside each arm, not hoisted above the
 *    `sel` tests.  Hoisting it keeps it in r1 and drops the callee-saved
 *    r5, which is where the original parks it -- each arm alone needs
 *    r0 (base), r1 (offset), r2 (pointer), r3/r4 (mask temps), so the
 *    index has to be r5, and that is what pulls in `push {r4, r5}`.
 *  - `|= (u8)(1 << (i & 7))` on a u8 lvalue is what emits the
 *    lsls/lsrs #0x18 pair around the mask.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200C818.c \
 *       --func sub_0200C818 --addr 0x0200C818 --cc 1.1p1 --thumb
 *   -> EXACT* (250 of 250 bytes; the listing extent runs two bytes long
 *      over the pool padding after the body)
 */
void sub_0200C818(u8 *p, u32 idx, int sel, int half)
{
    if (sel == 0) {
        if (half == 1) {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x104))[i >> 3] |= (u8)(1 << (i & 7));
        } else {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x5C))[i >> 3] |= (u8)(1 << (i & 7));
        }
    } else if (sel == 1) {
        if (half == 1) {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x158))[i >> 3] |= (u8)(1 << (i & 7));
        } else {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0xB0))[i >> 3] |= (u8)(1 << (i & 7));
        }
    } else {
        if (half == 1) {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x104))[i >> 3] |= (u8)(1 << (i & 7));
        } else {
            u16 i = (u16)idx - 1;
            ((u8 *)(p + 0x5C))[i >> 3] |= (u8)(1 << (i & 7));
        }
    }
}



/*
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
 */
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



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200CA28, func_0200CA38, func_0200CA40, func_0200CA54,
 *           func_0200CA5C, func_0200CA70, func_0200CA78, func_0200CA8C
 *
 * 172 bytes, 0x0200C9EC..0x0200CA98, 12 functions, nine of which carry no
 * label in the generated listing.
 *
 * The opening of the save block with id 0x37: func_0200C9EC returns 0x4D4,
 * func_0200C9F4 clears exactly 0x4D4 bytes and stamps 0xBEEFCAFE into the
 * first word, and func_0200CA10 is the whole of the lookup
 * `func_020071CC(sys, 0x37)`.  The magic word is the tell that the record is
 * checked rather than merely zeroed; nothing in this range reads it back.
 *
 * The word at +0x04 is a packed set of bitfields, and the widths are read off
 * the shift pairs rather than guessed: `lsls #0x15` / `lsrs #0x16` is bits
 * 1..10 and `lsls #0x0A` / `lsrs #0x16` is bits 12..21, so the layout is
 * 1 + 10 + 1 + 10 bits with the top ten unused by anything in this range.
 * func_0200CA8C truncates its ten-bit field to `u16` on the way out, which is
 * the second shift pair in it and is a return type rather than a field width.
 *
 * This unit stops at 0x0200CA98 rather than running to the end of the
 * original file: func_0200CA98 is 376 bytes of bit-array maintenance over
 * three module-level tables and is not attempted here.
 */
u32 func_0200C9EC(void)
{
    return sizeof(struct Blk37_0200C9EC);
}



void func_0200C9F4(struct Blk37_0200C9EC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk37_0200C9EC));
    p->unk00 = 0xBEEFCAFE;
}

void *func_0200CA10(void *sys)
{
    return func_020071CC(sys, 0x37);
}

void *func_0200CA1C(void *a)
{
    return func_0200CA10(func_02012EBC(a));
}

struct Blk37_0200C9EC *func_0200CA28(struct Blk37_0200C9EC *p)
{
    p->f0 = 1;
    return p;
}

u32 func_0200CA38(struct Blk37_0200C9EC *p)
{
    return p->f0;
}

struct Blk37_0200C9EC *func_0200CA40(struct Blk37_0200C9EC *p)
{
    p->f1 = 1;
    return p;
}

u32 func_0200CA54(struct Blk37_0200C9EC *p)
{
    return p->f1;
}

void func_0200CA5C(struct Blk37_0200C9EC *p, u32 v)
{
    p->f11 = v;
}

u32 func_0200CA70(struct Blk37_0200C9EC *p)
{
    return p->f11;
}

void func_0200CA78(struct Blk37_0200C9EC *p, u32 v)
{
    p->f12 = v;
}

u16 func_0200CA8C(struct Blk37_0200C9EC *p)
{
    return p->f12;
}


static inline void FormSetBit(u8 *a, u16 no)
{
    a[no >> 3] |= (u8)(1 << (no & 7));
}


static inline void FormResetBit(u8 *a, u16 no)
{
    a[no >> 3] &= (u8)((1 << (no & 7)) ^ 0xFF);
}


static inline void SetBit(u8 *a, u16 no)
{
    no--;
    a[no >> 3] |= (u8)(1 << (no & 7));
}


static inline void ResetBit(u8 *a, u16 no)
{
    no--;
    a[no >> 3] &= (u8)((1 << (no & 7)) ^ 0xFF);
}


/*
 * The bitmap maintenance of "musical_dist_save.c" (block 0x37): for a
 * species id listed in the {id, count} form table it clears the species'
 * run of form bits in the two nine-byte form rows at +0x30E and +0x317,
 * clamps the caller's form index to the species' count and sets that one
 * form bit in the row `alt` picks; then, for every species, it clears the
 * id's bit in the four 0x54-byte rows at +0x1AC and sets it in the row
 * chosen by (sel, alt), with the same six-arm shape as sub_0200C818.
 *
 * Written from the start (wave 20, lane musical_fresh) after five lanes
 * iterated on one inherited source and stopped at 89 bytes out; see
 * docs/notes/pkt_0200CA98.c.txt.  Two things closed it:
 *
 *  - The bit operations are four inline helpers on a u16 index, two plain
 *    ones for the flat form index and two that decrement the 1-based
 *    species id first (the `subs #1` / `lsls #0x10` / `lsrs #0x10` on the
 *    id, with no narrowing of id itself because it arrives as u16).  The
 *    inlining is what puts x>>3, 1<<(x&7) and the 0xFF mask into shared
 *    values: the tail's bit and byte offset are computed once, before the
 *    clear loop, and reused by all six set arms.
 *  - Every row argument is passed through an explicit `(u8 *)` cast.  With
 *    the bare array (`p->unk1AC[i]`, which decays to the same type) the
 *    optimizer reassociates the address as (p + off) + K and keeps K in a
 *    register; the cast keeps p + K as one operand, so p + 0x30E / p + 0x317
 *    are hoisted out of the form loop and p + 0x1AC out of the clear loop,
 *    as the image does.  That also moves p off the register file onto the
 *    stack, which was the tail's register rotation.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_0200CA98.c \
 *       --func func_0200CA98 --addr 0x0200CA98
 *   -> EXACT (392 bytes, both table literals resolved)
 */
void func_0200CA98(struct Blk37_0200CA98 *p, u16 id, u32 sel, u32 alt, u32 form)
{
    u32 i;
    u32 j;
    u32 off;

    off = 0;
    i = 0;
    do {
        if (id == func_0200CA98_Table[i].unk00) {
            for (j = 0; j < func_0200CA98_Table[i].unk02; j++) {
                FormResetBit((u8 *)p->unk2FC[2], off + j);
                FormResetBit((u8 *)p->unk2FC[3], off + j);
            }
            if (form >= func_0200CA98_Table[i].unk02) {
                form = 0;
            }
            if (alt == 1) {
                FormSetBit((u8 *)p->unk2FC[3], off + form);
            } else {
                FormSetBit((u8 *)p->unk2FC[2], off + form);
            }
            break;
        }
        off += func_0200CA98_Table[i].unk02;
        i++;
    } while (func_0200CA98_Table[i].unk00 != 0);

    for (i = 0; i < 4; i++) {
        ResetBit((u8 *)p->unk1AC[i], id);
    }
    if (sel == 0) {
        if (alt == 1) {
            SetBit((u8 *)p->unk1AC[2], id);
        } else {
            SetBit((u8 *)p->unk1AC[0], id);
        }
    } else if (sel == 1) {
        if (alt == 1) {
            SetBit((u8 *)p->unk1AC[3], id);
        } else {
            SetBit((u8 *)p->unk1AC[1], id);
        }
    } else {
        if (alt == 1) {
            SetBit((u8 *)p->unk1AC[2], id);
        } else {
            SetBit((u8 *)p->unk1AC[0], id);
        }
    }
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 32 bytes, 0x0200CC20..0x0200CC40, one function, which carries a label in the
 * generated listing.
 *
 * The table at 0x0209DE4C is a run of `{u16 form; u16 count;}` pairs: this
 * function returns the count for a form group and func_0200CA98 walks the same
 * array looking for the first pair whose first halfword matches.  The stride is
 * four, which is the `lsls #2` here and in func_0200CA98, so the two halfwords
 * are one record and not two parallel arrays; the pool word for the second
 * field is the symbol plus two rather than a second symbol.
 *
 * The branch that answers 1 is the `else`, so the table lookup is the source's
 * `then`: written the other way round, as a guard returning 1 first, the
 * condition inverts and the two arms swap.  See
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Two near misses in the same original file, recorded here because this is the
 * matched file next to them.
 *
 * func_0200CA98, 376 bytes at 0x0200CA98, the bit-array maintenance this
 * table drives.  It comes out four bytes short of 392 with the right control
 * flow throughout: mwccarm hoists the two loop-invariant bitmap pointers above
 * the loop's own entry test, where the original computes them in the loop
 * preheader and reloads the block pointer from its spill slot once for each of
 * them, and it hoists `m + (id >> 3)` out of the four-iteration clearing loop,
 * where the original forms `m + i * 0x54` first and leaves the byte index as
 * the load's register operand.  Both are the same choice of which half of an
 * address expression to make loop-invariant, and neither moved under any of the
 * shapes tried: the two pointers as locals assigned before the loop, assigned
 * inside it and written out inline; the loop as `for`, as `do`/`while` and
 * behind an explicit `if (n != 0)` guard; the mask operands in both orders; and
 * the row index through a `u8 (*)[0x54]` local, through the struct member and
 * through a flat offset.
 *
 * func_0200CC40, 402 bytes at 0x0200CC40, the query that reads the same three
 * bitmap groups back.  Its first half reproduces instruction for instruction;
 * its second half, four independent `if`s that each test one bitmap and write
 * two out-parameters, does not, because the original recomputes the shift, the
 * mask and the base address inside every one of the four blocks and mwccarm
 * computes them once in the dominating block and reuses them.  That is 52 bytes
 * of common subexpressions the original does not share, and writing the
 * expressions out in full in each block does not restore them.
 */
u16 func_0200CC20(u32 a)
{
    s32 i = func_0200C7F4(a);

    if (i != -1) {
        return func_0200CA98_Table[i].unk02;
    }
    return 1;
}
