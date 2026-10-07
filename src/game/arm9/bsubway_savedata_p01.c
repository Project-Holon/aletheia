/*
 * file:     bsubway_savedata_p01.c
 * unit:     yes
 * function: func_0200DE5C, func_0200DE64, func_0200DE6C, func_0200DE94, func_0200DEA0, func_0200DEA8, func_0200DF10, func_0200DF58, func_0200DF94, func_0200DFB4, func_0200DFCC, func_0200DFD8, func_0200DFE4, func_0200E008, func_0200E024, func_0200E06C, func_0200E090, func_0200E098, func_0200E0B0, func_0200E0BC, func_0200E0E8, func_0200E124, func_0200E164
 * address:  0x0200DE5C
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
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02082D44  0x02082D44  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   func_0200DF58_File  0x020A71F8  data
 *   func_0203F2FC  0x0203F2FC  arm
 *   func_0203F328  0x0203F328  arm
 *   func_020071CC  0x020071CC  thumb
 *   g_0209DE90  0x0209DE90  data
 *   func_0200E0BC  0x0200E0BC  thumb
 */
#include "../../matched/include/Obj11710.h"
#include "../../matched/include/Obj00318.h"

struct Sub020071CCCtrl;
struct Slot;
typedef unsigned char  u8;

struct RecSlot_0200DE5C {
    u8 unk000[0xFE];
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    u8 unk101;
    u8 unk102;
    u8 unk103;
    u8 unk104[0x690];
};

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct SubEnt {
    u16 unk00;
    u8  unk02[0x12];
    u8  unk14[4];
    u8  unk18[0x0A];
};

struct Buf3FC {
    struct SubEnt ent[30];
};

struct RecSlot_0200DEA8 {
    u8 unk000[0xFE];
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    u8 unk101;
    u8 unk102;
    u8 unk103;
    u8 unk104[0x794 - 0x104];
    struct Buf3FC unk794;
};

typedef u16 Row[3];

typedef enum { IDX_0 = 0, IDX_MAX = 4 } Idx;

struct Rec { u16 a; u16 b; };

typedef struct Slot {
    u32 id   : 11;
    u32 rest : 21;
} Slot;

extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);
extern void func_02082D44(void *dst, const void *src, u32 n);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void sub_0200DEA8(u8 *base, u8 *out, int idx);
extern u32 func_0203F2FC(const u8 *p, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
u16 func_0200DFD8(Row *table, int row, int col);
void func_0200DFE4(Row *table, int row, int col, int value);
void func_0200E008(u8 *base, int a, int idx);
void func_0200E024(void *obj);
extern void func_0203F37C(void *p, unsigned int size, unsigned int seed);
extern void func_02082BCC(void *p, u32 v, u32 size);
void func_0200E06C(char *p);
u32 func_0200E090(void);
void func_0200E098(u8 *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
void *func_0200E0B0(void *p);
u32 func_0200E0BC(u32 value);
u32 func_0200E0E8(const Slot *obj, int idx);
void func_0200E124(u32 *obj, u32 idx);
u32 func_0200E164(u32 *p, u32 a);
extern const char func_0200DF58_File[];
extern const struct Rec g_0209DE90[];








/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200DEA0
 *
 * 76 bytes, 0x0200DE5C..0x0200DEA8, 5 functions, four of which carry no label
 * in the generated listing.
 *
 * One slot of a record that holds a 0x690-byte payload at +0x104 behind a
 * present flag at +0xFE and two byte tags at +0x100 and +0x101.
 * func_0200DE6C fills all four in one go, and the three constants it needs
 * are one constant in the compiled code: 0x104 is materialised once in r7 and
 * the two stores reach +0x101 and +0x100 as `subs r0, r7, #3` and
 * `subs r0, r7, #4`.  That is the compiler reusing a live value and not three
 * offsets in the source.
 *
 * The two getters are the same function at two neighbouring offsets and they
 * do not compile alike: +0x100 is `movs r1, #1` / `lsls r1, #8` and +0x101
 * needs a literal pool word, because the first is a shifted eight-bit
 * immediate and the second is not.  Neither offset fits a `ldrb` immediate,
 * whose reach is 31, so both are register-offset loads; see
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 */
u8 func_0200DE5C(struct RecSlot_0200DE5C *p)
{
    return p->unkFE;
}

u8 func_0200DE64(struct RecSlot_0200DE5C *p)
{
    return p->unkFF;
}

void func_0200DE6C(struct RecSlot_0200DE5C *p, const void *src, u8 a, u8 b)
{
    MI_CpuCopy8(src, p->unk104, sizeof(p->unk104));
    p->unk101 = a;
    p->unk100 = b;
    p->unkFE = 1;
}

u8 func_0200DE94(struct RecSlot_0200DE5C *p)
{
    return p->unk101;
}

u8 func_0200DEA0(struct RecSlot_0200DE5C *p)
{
    return p->unk100;
}



void sub_0200DEA8(u8 *base, u8 *out, int idx)
{
    u8 *rec = base + 0x104 + idx * 0xf0;

    ((struct Obj11710 *)out)->f0 = 0xffff;
    ((struct Obj11710 *)out)->f4 = rec[0xd5];
    func_02082D44(rec + 0xb4, out + 8, 0x10);
    func_02082D44(rec + 0xd6, out + 0x18, 8);
    func_02082D44(rec + 0xde, out + 0x20, 8);
    func_02082D44(rec + 0xe6, out + 0x28, 8);
    func_02082D44(rec, out + 0x30, 0xb4);
}



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200DF94, func_0200DFB4, func_0200DFCC
 *
 * 200 bytes, 0x0200DF10..0x0200DFD8, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71F8 spells "bsubway_savedata.c", the fifth original source
 * file name this project has recovered, attested by the `string` class off
 * the terminator of "gds_profile.c" at 0x020A71F5.  func_0200DF58 passes it
 * to the debug allocator at 0x02030734 with line 0x508.
 *
 * The second slot of the record whose first slot is
 * src/matched/unit_0200DE5C.c: a 0x3FC-byte payload at +0x794 behind a
 * present flag at +0xFF and two byte tags at +0x102 and +0x103.  0x3FC is
 * thirty entries of 0x22 bytes, which is what func_0200DF94 walks, so the
 * payload's element type is pinned by the stride rather than assumed.
 *
 * Three details are worth having.
 *
 *  - func_0200DF58 allocates a copy of the payload and returns it; the size
 *    0x3FC is live in r6 across the allocation and is used again as the copy
 *    length, which is what writing it as `sizeof` at both sites gives.
 *  - in func_0200DF94 the loop index is declared **before** the counter even
 *    though the counter is the one assigned first in the output.  Declared
 *    the other way round the two swap registers and nothing else moves; see
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *  - func_0200DFB4 assembles a little-endian word out of four bytes and the
 *    compiler schedules the loads 0x16, 0x17, 0x14, 0x15, which is not the
 *    source order.  Every spelling tried, field by field or through an array,
 *    with or without casts on the operands, produces exactly these bytes, so
 *    the schedule says nothing about how it was written.
 */
void func_0200DF10(struct RecSlot_0200DEA8 *p, const void *src, u8 a, u8 b)
{
    MI_CpuCopy8(src, &p->unk794, sizeof(p->unk794));
    p->unk103 = a;
    p->unk102 = b;
    p->unkFF = 1;
}

int func_0200DF40(struct RecSlot_0200DEA8 *p)
{
    return p->unk103;
}

u8 func_0200DF4C(struct RecSlot_0200DEA8 *p)
{
    return p->unk102;
}

struct Buf3FC *func_0200DF58(struct RecSlot_0200DEA8 *p, u32 heap)
{
    struct Buf3FC *copy = func_02030734(heap, sizeof(p->unk794), 1,
                                        func_0200DF58_File, 0x508);

    MI_CpuCopy8(&p->unk794, copy, sizeof(p->unk794));
    return copy;
}

u32 func_0200DF94(struct Buf3FC *b)
{
    s32 i;
    u32 n = 0;

    for (i = 0; i < 30; i++) {
        if (b->ent[i].unk00 != 0) {
            n++;
        }
    }
    return n;
}

u32 func_0200DFB4(struct SubEnt *e)
{
    return e->unk14[0] | (e->unk14[1] << 8) | (e->unk14[2] << 16)
           | (e->unk14[3] << 24);
}

void func_0200DFCC(void *p)
{
    MI_CpuFill8(p, 0, 0x42);
}



/*
 * Two leaves after func_0200DFCC on a table of three-halfword records:
 * read entry [row][col], and write it clamped to 0..0xFFFF (signed
 * compares, so the value is an int). Seeded from ov175 (0x021D62E8,
 * 0x021D6502, 0x021D9DA2 and their siblings).
 */
u16 func_0200DFD8(Row *table, int row, int col)
{
    return table[row][col];
}



void func_0200DFE4(Row *table, int row, int col, int value)
{
    if (value > 0xFFFF) {
        value = 0xFFFF;
    } else if (value < 0) {
        value = 0;
    }
    table[row][col] = value;
}



/*
 * Unlabelled Thumb leaf: increment a clamped u16 counter.  Each record of the
 * table is six bytes; the counter for (a, idx) sits at base + a*6 + idx*2 and
 * is bumped by one only while it is below 0xFFFF.
 */
void func_0200E008(u8 *base, int a, int idx)
{
    u16 *p = (u16 *)(base + a * 6 + idx * 2);

    if (*p < 0xFFFFu) {
        *p = (u16)(*p + 1);
    }
}



#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)



/*
 * The 0x84C-byte save block's commit, and the second instance of the
 * 0x02FFFC3C idiom (see src/matched/unit_02008C58.c, which is the same block
 * 0x1E0 bytes smaller): the shared word is read TWICE and the two reads are not
 * commoned up, which is a `volatile` read and nothing else, and the two halves
 * are combined as `a << 8 | b`.
 *
 * The write at +0x84E is followed by a readback test against 0 and a store of 1
 * if it came back 0 -- the field is volatile all the way through, which is why
 * the `ldrh` is not folded away.  The checksum pair is the same shape as the
 * one in unit_02008C58.c: func_0203F2FC computes it over (obj, 0x84C) and
 * func_0203F328 writes it back with the +0x84E halfword as the high word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E024.c \
 *       --func func_0200E024 --addr 0x0200E024 --cc 1.1p1 --thumb
 */
void func_0200E024(void *obj)
{
    u32 a = unk_02FFFC3C;
    u32 b = unk_02FFFC3C;

    ((struct Obj00318 *)obj)->f84E = a << 8 | b;
    if (((struct Obj00318 *)obj)->f84E == 0) {
        ((struct Obj00318 *)obj)->f84E = 1;
    }
    ((struct Obj00318 *)obj)->f84C = func_0203F2FC(obj, 0x84c);
    func_0203F328(obj, 0x84c,
                  ((struct Obj00318 *)obj)->f84C +
                  (((struct Obj00318 *)obj)->f84E << 16));
}


void func_0200E06C(char *p)
{
    func_0203F37C(p, 0x84c,
        ((struct Obj00318 *)p)->f84C + (((struct Obj00318 *)p)->f84E << 16));
    ((struct Obj00318 *)p)->f84E = 0;
}



/*
 * Save-table size callback: returns 0x850, the size of the block whose
 * init is func_0200E098.  Pointer word 0x0200E091 at 0x0209DD08.
 */
u32 func_0200E090(void)
{
    return 0x850;
}



/*
 * Zeroes 0x850 bytes then runs the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E098.c \
 *       --func func_0200E098 --addr 0x0200E098 --thumb --cc 1.1p1
 */
void func_0200E098(u8 *p)
{
    func_02082BCC(p, 0, 0x850);
    func_0200E024(p);
}


/*
 * Unlabelled leaf: tail-calls func_020071CC(p, 0x3d).
 */
void *func_0200E0B0(void *p)
{
    return func_020071CC(p, 0x3d);
}


/*
 * Band lookup: the index of the first of four records whose .b bound is
 * above value, or 3. func_0200E124 indexes the same table with the result.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 44/44, 9 out, the "pool load
 * in the preheader" wall of docs/notes/pkt_0200E0BC.c.txt): the counter AND
 * the result are enum-typed, as in src/matched/func_02010DCC.c. An enum
 * induction variable keeps the unfolded `cmp #4; bhs` entry guard with the
 * table load after it, and no redundant `if (i >= 4) break;` is needed. The
 * bound is compared unsigned (`(u32)IDX_MAX`) for the image's bhs/blo; with
 * that compare a u32 result swaps r3/r4, an enum result does not.
 */
u32 func_0200E0BC(u32 value)
{
    Idx i;
    Idx r = 3;

    for (i = 0; i < (u32)IDX_MAX; i++) {
        if (value < g_0209DE90[i].b) {
            r = i;
            break;
        }
    }
    return r;
}


/*
 * Wave 17 lane untried_small. Three levers together: the range table read as
 * `struct Rec { u16 a; u16 b; }` (two pool words, tbl and tbl + 2, as in
 * func_0200E124); the slot word read as an 11-bit bitfield (the image masks
 * with `lsls #21; lsrs #21`, which `& 0x7ff` never produces); and an element
 * pointer walked beside the index in a `while` loop.
 */
u32 func_0200E0E8(const Slot *obj, int idx)
{
    u32 r = 0xffff;
    u32 i = g_0209DE90[idx].a;
    u32 hi = g_0209DE90[idx].b;
    const Slot *p = &obj[i];

    while (i < hi) {
        if (p->id == 0) {
            r = i;
            break;
        }
        i++;
        p++;
    }
    return r;
}



/*
 * The third pass's one in-lane conversion (lane 1 of the 0-64 byte band).
 * The two earlier attempts on this address both stopped at MATCH/DIFF on the
 * *pool word* rather than on any instruction: the entry point is a two-field
 * record table, and the field the original reads is the SECOND one, so its
 * `ldr r0, [pc, #0x28]` loads `g_0209DE90 + 2` (the address of `.b`), not the
 * table base.  Reading `struct Rec { u16 a; u16 b; } g_0209DE90[]` and taking
 * `.b` folds that +2 into the pool word exactly as the original does;
 * reading the same address as `u16[]` at `[i * 2]` gives `.a` (the wrong
 * field, one byte off in the pool) and `[i * 2 + 1]` gives 68 bytes instead
 * of 64.  See `docs/idioms/table-field-offset-folds-into-the-pool-word.md`
 * for the lever and docs/notes/pkt_0200E0BC.c.txt for the two residues.
 *
 * `u32 *o = obj;` is load-bearing: without it mwcc strength-reduces
 * `obj + (idx + 1)` to `(obj + idx) + 4`, which is the same address but a
 * different instruction order in the argument set-up.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E124.c \
 *       --func func_0200E124 --addr 0x0200E124 --cc 1.1p1 --thumb
 */
void func_0200E124(u32 *obj, u32 idx)
{
    u32 hi = g_0209DE90[func_0200E0BC(idx)].b;
    u32 *o = obj;

    if (idx < hi)
        func_02082D44(o + (idx + 1), o + idx, (hi - (idx + 1)) * 4);
    o[hi - 1] &= 0xfffff800;
}



/*
 * Runs func_0200E06C, then func_0200E0E8, then the initialiser, returning
 * the middle result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E164.c \
 *       --func func_0200E164 --addr 0x0200E164 --thumb --cc 1.1p1
 */
u32 func_0200E164(u32 *p, u32 a)
{
    func_0200E06C((char *)p);
    {
        u32 r = func_0200E0E8((const struct Slot *)p, (int)a);

        func_0200E024(p);
        return r;
    }
}
