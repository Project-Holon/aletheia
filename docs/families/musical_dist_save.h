/*
 * docs/families/musical_dist_save.h -- shared declarations for the
 * musical_dist_save.c family (0x0200C52C..0x0200D494 in the ARM9 Black
 * image; the __FILE__ anchor at 0x020A71D4 reads "musical_dist_save.c".
 * Per src/matched/unit_0200C6D8.c: the constructor of the file,
 * func_0200C52C, loads 0x020A71D4 as the file-name argument to the debug
 * allocator at 0x02030734, and the bytes at 0x020A71D4 spell
 * "musical_dist_save.c"; the string before it is "battle_rec.c", whose
 * terminator at 0x020A71DF fixes that start.  That is the fourth original
 * source file name the project has recovered, after "playtime.c",
 * "box_savedata.c" and "battle_rec.c".
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT (or EXACT*), and the
 * matched function that evidences each field or parameter is named in the
 * comment beside it.  Where two matched sources spell the same field
 * differently (they were written by different lanes/waves), the spelling
 * recorded here is the one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 *
 * THREE DISTINCT OBJECTS live in this family:
 *   1. struct MusicalDist  -- a 0x2C-byte heap distribution record
 *      (unit_0200C5A4.c / unit_0200C5F8.c).
 *   2. struct Blk37        -- save block id 0x37, size 0x4D4, the "seen /
 *      distributed" species tracker (unit_0200C9EC.c for the head and
 *      bitfields; unit_0200CDE0.c / unit_0200CED4.c / unit_0200CFA0.c /
 *      unit_0200D0AC.c / unit_0200D368.c for the bitmap array layout).
 *   3. struct Blk38 / struct GdsEnt -- save block id 0x38, size 0x34, a
 *      pair of "gift distribution" entries (unit_0200D414.c).
 * Plus a {u16 id, u16 count} form table at 0x0209DE4C
 * (unit_0200C7C0.c / unit_0200CC20.c) and two plain u16 scan tables at
 * 0x0209DE20 (6 entries, func_0200C7A0.c) and 0x0209DE2C (15 entries,
 * func_0200C780.c).
 */

#ifndef MUSICAL_DIST_SAVE_H
#define MUSICAL_DIST_SAVE_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * Species id bound.
 * ------------------------------------------------------------------ */
#define MDS_SPECIES_MIN     1       /* func_0200CF28/func_0200CF54/
                                     * func_0200D0CC/func_0200D0F8/
                                     * func_0200D2D8/func_0200D368 all loop
                                     * `for (i = 1; i <= 0x289; i++)` */
#define MDS_SPECIES_MAX      0x289  /* same loops; also func_0200C720's
                                     * `v == 0 || v > 0x289` range guard
                                     * (unit_0200C6D8.c) */
#define MDS_NO_INDEX         0x3E7  /* 999, the id-to-index table's "no
                                     * entry" sentinel: func_0200CF54,
                                     * func_0200D0F8, sub_0200D310 and
                                     * func_0200D368 all test
                                     * `t[i] != 0x3E7` */

/* ------------------------------------------------------------------ *
 * struct MusicalDist -- the 0x2C-byte distribution record.
 *
 * Evidenced by unit_0200C5A4.c (destructor func_0200C5A4, constructor
 * wrapper func_0200C5C8) and unit_0200C5F8.c (the state machine
 * func_0200C5F8, which re-declares the identical struct).  Only field
 * names touched by these two files are known; nothing else in the range
 * reads or writes the interior.
 * ------------------------------------------------------------------ */
struct DistHdr {
    u32 unk00;                  /* +0x00  copied whole via MI_CpuCopy8 into
                                 *        *unk1C by func_0200C5C8. */
    u32 unk04;                  /* +0x04 */
    u32 unk08;                  /* +0x08 */
    u32 unk0C;                  /* +0x0C */
};                              /*  = 0x10 bytes */

struct MusicalDist {
    u16 unk00;                  /* +0x00  a tag source: func_0200C5F8 uses
                                 *        `(u16)((unk00 & 0x7FFF) | 0x8000)`
                                 *        at all three of its service-call
                                 *        sites (unit_0200C5F8.c). */
    u32 unk04;                  /* +0x04  unaccessed in these two files. */
    u32 unk08;                  /* +0x08  THE STATE COUNTER: func_0200C5F8
                                 *        switches on it (0, 1) and
                                 *        increments it in case 0
                                 *        (unit_0200C5F8.c). */
    struct DistHdr unk0C;       /* +0x0C  the 0x10-byte header; unk0C.unk00
                                 *        is set to `size` and the whole
                                 *        header copied into *unk1C by
                                 *        func_0200C5C8 (unit_0200C5A4.c). */
    void *unk1C;                /* +0x1C  the working buffer.  Its zero/
                                 *        non-zero state gates both the
                                 *        destructor's free
                                 *        (func_0200C5A4) and whether
                                 *        func_0200C5C8 fills the record at
                                 *        all; also the "already torn down"
                                 *        test in func_0200C5F8's case 0
                                 *        and case 1. */
    void *unk20;                 /* +0x20  the buffer's base again
                                 *        (unaccessed in these two files
                                 *        beyond its declaration). */
    u8   *unk24;                 /* +0x24  the payload, base + 0x10:
                                 *        MI_CpuCopy8(src, p->unk24, size)
                                 *        in func_0200C5C8, and the source
                                 *        buffer for func_0204913C in
                                 *        func_0200C5F8. */
    void *unk28;                 /* +0x28  the system pointer:
                                 *        func_02012EBC(p->unk28) resolves
                                 *        it to the save context in both
                                 *        func_0200C5A4 and func_0200C5F8;
                                 *        func_02012E4C/func_02012E7C key
                                 *        the heap-id-6 handshake off it. */
};                              /*  = 0x2C bytes (unit_0200C5A4.c's header
                                 *    comment states the record is 0x2C
                                 *    bytes) */

extern struct MusicalDist *func_0200C52C(void *sys, u32 heap);
                                /* 0x0200C52C  the constructor.  Reached as
                                 * a `label` witness only (near miss inside
                                 * unit_0200C5A4.c); not itself matched. */

/* 0x0200C5A4  destructor: releases the heap-id-6 registration, frees the
 * working buffer if present (fall-through arm, source order `if (unk1C
 * != 0)`), then frees the record itself. */
void func_0200C5A4(struct MusicalDist *p);

/* 0x0200C5C8  (re)initialise via func_0200C52C and, if the buffer exists,
 * stamp the header and copy `src`/`size` into the payload. */
struct MusicalDist *func_0200C5C8(void *sys, const void *src, u32 size,
                                  u32 heap);

/* 0x0200C5F8  the two-phase state machine: case 0 kicks off the async
 * service chain (func_0204913C/func_0204A39C/func_02045C44/func_02045EC0/
 * func_02045A38/func_02045808/func_02045C04/func_020307B0/func_02049238)
 * and registers heap id 6; case 1 polls func_02012E7C(unk28, 6) for
 * completion (== 2) and tears down through func_0200C5A4.  Returns 1 once
 * torn down, 0 otherwise. */
u32 func_0200C5F8(struct MusicalDist *p);

/* ------------------------------------------------------------------ *
 * struct Blk2C / struct Buf2000 -- auxiliary shapes from unit_0200C6D8.c.
 * Not part of struct MusicalDist; two independent getters/helpers that
 * share the file but not the record.
 * ------------------------------------------------------------------ */
struct Blk2C {
    u8   unk00[0x20];           /* +0x00 */
    u32 *unk20;                 /* +0x20  func_0200C6DC dereferences it. */
    u32  unk24;                 /* +0x24  func_0200C6D8 returns it
                                 *        directly. */
    u32  unk28;                 /* +0x28 */
};                              /*  = 0x2C bytes */

struct Buf2000 {
    u8 unk0000[0x1FE0];         /* +0x0000 */
    u8 unk1FE0[0x20];           /* +0x1FE0  compared byte-for-byte against
                                 *        a zeroed stack copy by
                                 *        func_0200C6F0 ("is this record
                                 *        still blank"). */
};                              /*  = 0x2000 bytes */

/* 0x0200C6D8  getter: return p->unk24. */
u32 func_0200C6D8(struct Blk2C *p);

/* 0x0200C6DC  getter: return *p->unk20. */
u32 func_0200C6DC(struct Blk2C *p);

/* 0x0200C6E4  constant getter: always 0x2600. */
u32 func_0200C6E4(void);

/* 0x0200C6EC  empty hook: `bx lr` and nothing else, never filled in. */
void func_0200C6EC(void);

/* 0x0200C6F0  "is this 0x2000-byte record still blank": compares the last
 * 0x20 bytes against a zeroed stack buffer via func_0203EFC8. */
u32 func_0200C6F0(struct Buf2000 *p);

/* 0x0200C720  species id range guard: true (1) when v == 0 or v >
 * MDS_SPECIES_MAX (0x289), i.e. out of range; false (0) otherwise. */
u32 func_0200C720(u16 id);
extern u32 func_0200C720(u16 id);   /* re-declared with a u16 parameter by
                                     * unit_0200CDE0.c and its siblings;
                                     * unit_0200C6D8.c's own definition
                                     * takes u32 v -- the callers all pass
                                     * a u16 id, so u16 is the tighter,
                                     * evidence-constrained spelling used
                                     * throughout this header. */

/* ------------------------------------------------------------------ *
 * struct Blk37 -- save block id 0x37, size 0x4D4.
 *
 * func_0200C9EC returns sizeof(struct Blk37) == 0x4D4 (unit_0200C9EC.c);
 * func_0200C9F4 zero-fills exactly that many bytes and stamps 0xBEEFCAFE
 * into +0x00 (the "is this a checked record" tell -- nothing in this
 * family reads the magic back); func_0200CA10 is
 * `func_020071CC(sys, 0x37)`, the save-block lookup by id.
 *
 * The word at +0x04 is a packed bitfield, widths read off the shift pairs
 * in unit_0200C9EC.c rather than guessed: `lsls #0x15`/`lsrs #0x16` is
 * bits 1..10 (f1, width 10) and `lsls #0x0A`/`lsrs #0x16` is bits 12..21
 * (f12, width 10); the layout is therefore 1 + 10 + 1 + 10 bits, with the
 * top ten (f22, unused by anything in this family) closing out the word:
 *   bit  0       f0   : 1   (func_0200CA28 sets it to 1;
 *                             func_0200CA38 reads it back)
 *   bits 1..10   f1   : 10  (func_0200CA40 sets it to 1;
 *                             func_0200CA54 reads it back)
 *   bit  11      f11  : 1   (func_0200CA5C/func_0200CA70,
 *                             plain get/set of a caller value)
 *   bits 12..21  f12  : 10  (func_0200CA78 sets it; func_0200CA8C reads
 *                             it back, TRUNCATED TO u16 at the return --
 *                             a return-type narrowing, not a field-width
 *                             fact)
 *   bits 22..31  f22  : 10  (declared for bit-layout completeness; no
 *                             matched function in this family reads or
 *                             writes it)
 *
 * THE BITMAP ARRAY LAYOUT.  unit_0200CDE0.c / unit_0200CED4.c /
 * unit_0200CFA0.c / unit_0200D0AC.c / unit_0200D368.c all agree on this
 * shape for the tail of the struct, from +0x008 to +0x4D0:
 *   u8  unk008[0x54];       +0x008..+0x05C  ONE bitmap row
 *   u8  unk05C[4][0x54];    +0x05C..+0x1AC  FOUR bitmap rows
 *   u8  unk1AC[4][0x54];    +0x1AC..+0x2FC  FOUR more bitmap rows
 *   u8  unk2FC[4][9];       +0x2FC..+0x320  FOUR small 9-byte rows
 *   u8  unk320[0x1B0];      +0x320..+0x4D0  the big flat form/seen bitset
 *   u32 unk4D0;             +0x4D0          (see below)
 *
 * The raw constants other matched sources spell out resolve against that
 * layout as follows (each is a base address = struct base + offset, or an
 * element of an array above):
 *   0x008  == &unk008 itself (sub_0200C818.c's `half == 0` "0" case
 *            reaches +0x5C, not +0x008 directly; +0x008 is unk008's own
 *            base, touched by func_0200CDE0's final `p->unk008[y>>3] |=`
 *            store and read back by func_0200CED4's `p->unk008[y>>3] &`
 *            test)
 *   0x05C  == &unk05C[0][0]   (sub_0200C818.c: sel==0, half==0)
 *   0x0B0  == &unk05C[1][0]   (0x05C + 0x54; sub_0200C818.c: sel==1,
 *            half==0)
 *   0x104  == &unk05C[2][0]   (0x0B0 + 0x54; sub_0200C818.c: sel==0 and
 *            sel==2, half==1 -- both branches store to the SAME offset,
 *            which is why the `sel==0`/`half==1` and `sel==2`/`half==1`
 *            arms of sub_0200C818 are byte-identical)
 *   0x158  == &unk05C[3][0]   (0x104 + 0x54; sub_0200C818.c: sel==1,
 *            half==1)
 *   0x1AC  == &unk1AC[0][0]   (end of unk05C[4]; start of the second
 *            4-row group)
 *   0x200  == &unk1AC[1][0]   (0x1AC + 0x54)
 *   0x254  == &unk1AC[2][0]   (0x200 + 0x54)
 *   0x2A8  == &unk1AC[3][0]   (0x254 + 0x54)
 *   0x2FC  == &unk2FC[0][0]   (end of unk1AC[4]; start of the 9-byte-row
 *            group)
 *   0x305  == &unk2FC[1][0]   (0x2FC + 9)
 *   0x30E  == &unk2FC[2][0]   (0x305 + 9)
 *   0x317  == &unk2FC[3][0]   (0x30E + 9; 0x317 + 9 == 0x320 exactly)
 *   0x320  == &unk320[0]      (func_0200C738.c and unit_0200D368.c's
 *            func_0200D3C0 both compute `q = p + 0x320` for the flat
 *            form/seen bitset; func_0200CDE0.c's call chain into
 *            func_0200C738 confirms the same base)
 *   0x4D0  == unk4D0          (func_0200CDE0.c / func_0200CFA0.c:
 *            `if (id == 0x147 && p->unk4D0 == 0) p->unk4D0 = v0;` --
 *            a u32, first-write-wins cache keyed off species 0x147)
 *
 * unk320's bitset is row-bound at 0x1ED (493 decimal): func_0200C738.c's
 * guard `if (a1 > 493) return;` and unit_0200D368.c's func_0200D3C0 guard
 * `if (a > 0x1ED) return 0;` are the same bound spelled in decimal and
 * hex by two different lanes; 0x1ED is used here as the byte-evidenced
 * spelling since func_0200D3C0 is the read half of the exact bit
 * func_0200C738 writes (same index formula `(b-1) + a*7`, same 7-wide
 * column selector with the hole at column value 6).
 * ------------------------------------------------------------------ */
struct Blk37 {
    u32 unk00;                  /* +0x00  0xBEEFCAFE stamp
                                 *        (unit_0200C9EC.c func_0200C9F4) */
    u32 f0  : 1;                /* +0x04 bit 0   func_0200CA28/func_0200CA38 */
    u32 f1  : 10;                /* +0x04 bits 1..10   func_0200CA40/func_0200CA54 */
    u32 f11 : 1;                /* +0x04 bit 11   func_0200CA5C/func_0200CA70 */
    u32 f12 : 10;                /* +0x04 bits 12..21   func_0200CA78/func_0200CA8C */
    u32 f22 : 10;                /* +0x04 bits 22..31   unused in this family */
    u8  unk008[0x54];            /* +0x008  one bitmap row (func_0200CDE0.c's
                                 *        trailing `p->unk008[y>>3] |= ...`,
                                 *        y from species id; func_0200CED4.c
                                 *        reads it back) */
    u8  unk05C[4][0x54];         /* +0x05C  four bitmap rows: bases 0x05C,
                                 *        0x0B0, 0x104, 0x158
                                 *        (sub_0200C818.c) */
    u8  unk1AC[4][0x54];         /* +0x1AC  four more bitmap rows: bases
                                 *        0x1AC, 0x200, 0x254, 0x2A8
                                 *        (sub_0200C818.c's sel==0/half==1
                                 *        and sel==2/half==1 both land on
                                 *        +0x104, which is inside unk05C,
                                 *        not unk1AC -- unk1AC's own bases
                                 *        are reached by the sibling
                                 *        function pkt_0200C818's other
                                 *        callers, not by sub_0200C818.c
                                 *        itself) */
    u8  unk2FC[4][9];            /* +0x2FC  four 9-byte rows: bases 0x2FC,
                                 *        0x305, 0x30E, 0x317 */
    u8  unk320[0x1B0];           /* +0x320  the flat form/seen bitset,
                                 *        row-bound 0x1ED (493), 7-wide
                                 *        column selector with a hole at
                                 *        column value 6
                                 *        (func_0200C738.c write half,
                                 *        func_0200D3C0 read half in
                                 *        unit_0200D368.c) */
    u32 unk4D0;                  /* +0x4D0  first-write-wins u32 cache for
                                 *        species id 0x147
                                 *        (unit_0200CDE0.c/unit_0200CFA0.c) */
};                              /*  = 0x4D4 bytes (func_0200C9EC) */

/* 0x0200C9EC  return sizeof(struct Blk37) == 0x4D4. */
u32 func_0200C9EC(void);

/* 0x0200C9F4  zero-fill the whole record and stamp 0xBEEFCAFE at +0x00. */
void func_0200C9F4(struct Blk37 *p);

/* 0x0200CA10  save-block lookup: func_020071CC(sys, 0x37). */
void *func_0200CA10(void *sys);

/* 0x0200CA1C  resolve sys through func_02012EBC, then func_0200CA10. */
void *func_0200CA1C(void *a);

/* 0x0200CA28 / 0x0200CA38  set / get bitfield f0. */
void func_0200CA28(struct Blk37 *p);
u32  func_0200CA38(struct Blk37 *p);

/* 0x0200CA40 / 0x0200CA54  set / get bitfield f1. */
void func_0200CA40(struct Blk37 *p);
u32  func_0200CA54(struct Blk37 *p);

/* 0x0200CA5C / 0x0200CA70  set / get bitfield f11. */
void func_0200CA5C(struct Blk37 *p, u32 v);
u32  func_0200CA70(struct Blk37 *p);

/* 0x0200CA78 / 0x0200CA8C  set bitfield f12 / get it back truncated to
 * u16 at the return (the truncation is the function's return type, not a
 * field-width fact -- the field itself is 10 bits). */
void func_0200CA78(struct Blk37 *p, u32 v);
u16  func_0200CA8C(struct Blk37 *p);

/* 0x0200C738  set one bit of the flat unk320 bitset.  Guard chain: a2 > 8
 * bails, a2 == 6 bails (the hole), a1 > 493 (0x1ED) bails; a2 >= 7 is then
 * decremented so the seven live selector values 1..5,7,8 map onto 0..6.
 * Index v = (a2-1) + (a1-1)*7 into a bit of q = p + 0x320. */
void func_0200C738(u8 *p, u32 a1, u32 a2);

/* 0x0200C780  linear scan of the 15-entry u16 table at 0x0209DE2C
 * (g_0209DE2C).  Returns 0 if v is found, 1 otherwise. */
int func_0200C780(u32 v);

/* 0x0200C7A0  linear scan of the 6-entry u16 table at 0x0209DE20
 * (g_0209DE20).  Returns 0 if v is found, 1 otherwise. */
int func_0200C7A0(u32 v);

/* struct DistEnt -- the {u16 id, u16 count} form table at 0x0209DE4C
 * (unit_0200C7C0.c).  Zero-terminated (id == 0 ends the table); the two
 * scanning functions are `do`/`while`, so the table is non-empty by
 * construction. */
struct DistEnt {
    u16 id;                      /* +0x00 */
    u16 count;                   /* +0x02 */
};

extern const struct DistEnt func_0200C7C0_Table[]; /* 0x0209DE4C */

/* 0x0200C7C0  sum the counts of every entry before the first match of
 * `id`; answers (u32)-1 if id is not listed. */
u32 func_0200C7C0(u16 id);

/* 0x0200C7F4  the entry's own index for `id` in the same table; answers
 * (u32)-1 if not listed. */
u32 func_0200C7F4(u16 id);

/* struct FormCount -- unit_0200CC20.c's re-declaration of the same
 * 0x0209DE4C table (its own symbol func_0200CA98_Table), stride 4
 * confirmed by both this file and func_0200CA98: unk00 is id, unk02 is
 * count -- identical layout to struct DistEnt above, kept as a distinct
 * type because unit_0200CC20.c spells the fields unk00/unk02 rather than
 * id/count. */
struct FormCount {
    u16 unk00;                   /* +0x00  == DistEnt.id */
    u16 unk02;                   /* +0x02  == DistEnt.count */
};

extern const struct FormCount func_0200CA98_Table[]; /* 0x0209DE4C, alias
                                                       * of func_0200C7C0_Table */

/* 0x0200CC20  form-group count: func_0200C7F4's index into
 * func_0200CA98_Table, else 1 if not found. */
u16 func_0200CC20(u32 a);

/* 0x0200CA98  the bit-array maintenance over unk008/unk05C/unk1AC driven
 * by func_0200CA98_Table.  NOT matched (near miss, four bytes short; see
 * unit_0200CC20.c's header comment). */
extern void func_0200CA98(struct Blk37 *p, u16 id, u32 c, u32 d, u32 e);

/* 0x0200C818  the six-armed bitmap setter over sel/half (sub_0200C818.c).
 * `sel` picks a pair of unk05C/unk1AC bases, `half` which of the pair;
 * bit index is `idx - 1` (idx is 1-based). */
void sub_0200C818(u8 *p, u32 idx, int sel, int half);
extern void func_0200C818(struct Blk37 *p, u16 id, u32 c, u32 d); /* the
                                     * 4-argument caller-visible wrapper
                                     * unit_0200CDE0.c and unit_0200CFA0.c
                                     * call; sub_0200C818 is its leaf
                                     * implementation over (sel, half). */

/* 0x0200C914  companion setter (not itself matched in this family; called
 * with the same (p, id, c, d, e) shape as func_0200CA98 by
 * unit_0200CDE0.c and unit_0200CFA0.c). */
extern void func_0200C914(struct Blk37 *p, u16 id, u32 c, u32 d, u32 e);

/* 0x0200CDE0  the RECORD path: pull id/f/g/v6F/v0C out of the record `m`
 * via func_02017E1C etc., bail on the 0x4C flag or an out-of-range id,
 * else run func_0200CA98 (if func_0200D064 says "not yet seen"),
 * func_0147 cache, func_0200C818, func_0200C914, func_0200C738 (the
 * unk320 bit) AND finally set unk008's own bit for id.  This is the
 * superset of func_0200CFA0: unit_0200CDE0.c's header states the diff
 * against unit_0200CFA0.c is exactly the func_0200C738 call plus the
 * final unk008 bit set. */
void func_0200CDE0(struct Blk37 *p, void *m);

/* 0x0200CFA0  the same record path WITHOUT the func_0200C738 call and
 * without the final unk008 bit set (see unit_0200CDE0.c's header). */
void func_0200CFA0(struct Blk37 *p, void *m);

/* 0x0200D064  the four-bitmap ("distributed") test: OR of unk008 and the
 * four unk05C rows (NOT matched here, but its shape is read off its
 * callers' near-miss comments in unit_0200D0AC.c: it walks p + i*0x54 +
 * (id>>3) for i in 0..3 plus the unk008 row). */
extern u32 func_0200D064(struct Blk37 *p, u16 id);   /* EXACT, wave 13 */

/* 0x0200CED4  the SINGLE-bitmap ("seen") test: reads only unk008's bit for
 * id, after the func_0200C720 range guard. */
u32 func_0200CED4(struct Blk37 *p, u16 id);

/* 0x0200CF08  dispatch: if func_0200CA38 (bitfield f0) is set, count via
 * func_0200CF28 (raw), else via func_0200CF54 (id-table filtered). */
u16 func_0200CF08(struct Blk37 *p, u32 heap);

/* 0x0200CF28  count species 1..0x289 for which func_0200CED4 (the "seen"
 * bitmap) is 1. */
u16 func_0200CF28(struct Blk37 *p);

/* 0x0200CF54  same count, additionally filtered by
 * func_0201AF80(heap,0)[i] != MDS_NO_INDEX (the id-to-index table). */
u16 func_0200CF54(struct Blk37 *p, u32 heap);

/* 0x0200D0AC  the "distributed" counterpart of func_0200CF08, dispatching
 * on func_0200CA38 to func_0200D0CC / func_0200D0F8, over func_0200D064
 * (the four-bitmap test) instead of func_0200CED4 (the single-bitmap
 * test). */
u16 func_0200D0AC(struct Blk37 *p, u32 heap);

/* 0x0200D0CC  count species 1..0x289 for which func_0200D064 is 1. */
u16 func_0200D0CC(struct Blk37 *p);

/* 0x0200D0F8  same count, additionally filtered by the id-to-index table
 * as in func_0200CF54. */
u16 func_0200D0F8(struct Blk37 *p, u32 heap);

/* 0x0200D298  wraps func_0200D2D8, true when the result is >= 0x27a
 * (634). */
int func_0200D298(void);

/* 0x0200D2B0  wraps func_0200D310, true when the result is >= 0x96 (150).
 * EXACT* (listing extent runs two bytes long over linker filler). */
int func_0200D2B0(void);

/* 0x0200D2C4  wraps func_0200D368, true when the result is >= 0x96 (150). */
int func_0200D2C4(void);

/* 0x0200D2D8  count species 1..0x289 that are "seen" (func_0200CED4 == 1)
 * AND accepted by func_0200C780 (i.e. NOT in the 15-entry
 * g_0209DE2C exclusion table). */
u16 func_0200D2D8(void *a0);

/* 0x0200D310  count species 1..0x289 that are "seen", have an id-table
 * entry (!= MDS_NO_INDEX) and are accepted by func_0200C7A0 (i.e. NOT in
 * the 6-entry g_0209DE20 exclusion table). */
int sub_0200D310(void *a0, int a1);

/* 0x0200D368  count species 1..0x289 that are "distributed"
 * (func_0200D064 == 1), have an id-table entry, and are accepted by
 * func_0200C7A0 (the 6-entry exclusion table). */
u16 func_0200D368(struct Blk37 *p, u32 heap);

/* 0x0200D3C0  read one bit of the flat unk320 bitset.  Same guard chain
 * and index formula as func_0200C738 (the write half): b > 8 or b == 6
 * bails 0, a > 0x1ED bails 0, b >= 7 decremented, x = (b-1) + (a-1)*7. */
u32 func_0200D3C0(struct Blk37 *p, u32 a, u32 b);

/* ------------------------------------------------------------------ *
 * struct GdsEnt -- one 0x14-byte gift-distribution entry.
 *
 * Evidenced entirely by unit_0200D414.c.  func_0200D494 zero-fills the
 * entry and sets unk00 to 0xFFFF, the "empty" sentinel; func_0200D4B8 /
 * func_0200D50C are the get/set dispatchers whose switch-table ORDER
 * (1, 2, 3, 10, 4, 5, 6, 7, 8, 9) fixes the field for selector 10 as
 * unk02 rather than a field between unk08 and unk0C.
 * ------------------------------------------------------------------ */
struct GdsEnt {
    u16 unk00;                   /* +0x00  0xFFFF sentinel when empty
                                 *        (func_0200D494); selector 1 */
    u8  unk02;                   /* +0x02  selector 10 (out of numeric
                                 *        order in the switch table, which
                                 *        is the source's own arm order) */
    u8  unk03;                   /* +0x03  no selector reaches it in this
                                 *        family; padding by elimination */
    u32 unk04;                   /* +0x04  selector 2 */
    u32 unk08;                   /* +0x08  selector 3 */
    u16 unk0C;                   /* +0x0C  selector 4 */
    u16 unk0E;                   /* +0x0E  selector 5 */
    u8  unk10;                   /* +0x10  selector 6 */
    u8  unk11;                   /* +0x11  selector 7 */
    u8  unk12;                   /* +0x12  selector 8; also read directly
                                 *        by func_0200D488 */
    u8  unk13;                   /* +0x13  selector 9 */
};                              /*  = 0x14 bytes */

/* ------------------------------------------------------------------ *
 * struct Blk38 -- save block id 0x38, size 0x34.
 *
 * func_0200D414 returns sizeof(struct Blk38) == 0x34; func_0200D418 is
 * func_020071CC(sys, 0x38); func_0200D424 zero-fills the whole record and
 * then explicitly re-sets unk30 and unk31 to 0 (both after the fill, so
 * neither is redundant with MI_CpuFill8 by the source's own account).
 * unk31 is declared `volatile`: func_0200D564 reads it three times with
 * the address recomputed before each access, which only reproduces under
 * that qualifier (unit_0200D414.c's header comment; the same reading
 * recurs as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c, outside
 * this family).
 * ------------------------------------------------------------------ */
struct Blk38 {
    u16 unk00;                   /* +0x00  func_0200D45C: if changing,
                                 *        unk02 first takes the OLD unk00,
                                 *        then unk00 takes the new value
                                 *        (history-of-one) */
    u16 unk02;                   /* +0x02  previous unk00, per func_0200D45C */
    struct GdsEnt unk04[2];      /* +0x04  two entries, func_0200D4AC
                                 *        indexes them (0x04 + 0x14*i) */
    u8  unk2C[2];                /* +0x2C  func_0200D478/func_0200D480
                                 *        get/set by index */
    u8  unk2E[2];                /* +0x2E  func_0200D468/func_0200D470
                                 *        get/set by index */
    u8  unk30;                   /* +0x30  explicitly re-zeroed by
                                 *        func_0200D424 after the fill;
                                 *        func_0200D440 sets it from
                                 *        func_02005728(0x11);
                                 *        func_0200D454 reads it back */
    volatile u8 unk31;            /* +0x31  a countdown byte: func_0200D55C
                                 *        sets it, func_0200D564
                                 *        decrements and reports "hit
                                 *        zero" once, func_0200D58C tests
                                 *        "already zero"; must be volatile
                                 *        for func_0200D564's triple read
                                 *        of +0x31 to reproduce */
    u8  unk32[2];                 /* +0x32  unaccessed in this family;
                                 *        padding by elimination to close
                                 *        out 0x34 bytes */
};                              /*  = 0x34 bytes (func_0200D414) */

/* 0x0200D414  return sizeof(struct Blk38) == 0x34. */
u32 func_0200D414(void);

/* 0x0200D418  save-block lookup: func_020071CC(sys, 0x38). */
void *func_0200D418(void *sys);

/* 0x0200D424  zero-fill the whole record, then explicitly re-clear unk30
 * and unk31. */
void func_0200D424(struct Blk38 *p);

/* 0x0200D440  resolve the block via func_0200D418 and set unk30 from
 * func_02005728(0x11). */
void func_0200D440(void *sys);

/* 0x0200D454  get unk30. */
u8 func_0200D454(struct Blk38 *p);

/* 0x0200D45C  set unk00, shifting the old value into unk02 first, only if
 * the new value differs. */
void func_0200D45C(struct Blk38 *p, u16 v);

/* 0x0200D468 / 0x0200D470  get / set unk2E[i]. */
u8   func_0200D468(struct Blk38 *p, u32 i);
void func_0200D470(struct Blk38 *p, u32 i, u8 v);

/* 0x0200D478 / 0x0200D480  get / set unk2C[i]. */
u8   func_0200D478(struct Blk38 *p, u32 i);
void func_0200D480(struct Blk38 *p, u32 i, u8 v);

/* 0x0200D488  get unk04[i].unk12 directly (bypasses the field-selector
 * dispatcher below). */
u8 func_0200D488(struct Blk38 *p, u32 i);

/* 0x0200D494  clear one GdsEnt and set its unk00 to the 0xFFFF empty
 * sentinel. */
void func_0200D494(struct GdsEnt *e);

/* 0x0200D4AC  return &p->unk04[i]. */
struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);

/* 0x0200D4B8  field-selector getter over a GdsEnt.  Selector 0 and any
 * value outside 1..10 answer 0; the arm order in the source (and the
 * jump table) is 1, 2, 3, 10, 4, 5, 6, 7, 8, 9. */
u32 func_0200D4B8(const struct GdsEnt *e, u32 i);

/* 0x0200D50C  field-selector setter over a GdsEnt, same selector layout
 * as func_0200D4B8. */
void func_0200D50C(struct GdsEnt *e, u32 i, u32 v);

/* 0x0200D55C  set the volatile countdown byte unk31. */
void func_0200D55C(struct Blk38 *p, u8 v);

/* 0x0200D564  decrement unk31 if nonzero; return 1 the instant it reaches
 * zero, 0 otherwise (including when it was already zero). */
u32 func_0200D564(struct Blk38 *p);

/* 0x0200D58C  return 1 if unk31 is already zero, 0 otherwise. */
u32 func_0200D58C(struct Blk38 *p);

/* ------------------------------------------------------------------ *
 * ADDED 2026-09-23 (wave 11).  Nothing in this family closed this pass;
 * three facts proven against the bytes, for the next attempt:
 *
 *  - func_0200CC40 takes SIX parameters: (u8 *p, u32 id, u32 *out1, u32
 *    *out2, u32 *outForm, u16 a5).  Its closing call is
 *    func_0201ADE4(id, (u16)*outForm, a5).  With the bit tests as an inline
 *    `TestBit(const u8 *row, u16 x)` over `p + K`, its form loop is
 *    byte-exact (docs/notes/pkt_0200CC40.c.txt).
 *  - func_0200C52C calls func_02012EBC(sys): the first parameter is passed
 *    through in r0, so the zero-argument prototype the notes used cost the
 *    size.  Written with the stores and the `== 1` flag test duplicated
 *    into both arms it is 120/120 bytes, 36 out
 *    (docs/notes/pkt_0200C52C.c.txt).
 *  - func_0200D144's arms 1-5 are 1.1p1-exact; under 2.0/sp2 the size is
 *    right (322) but the constant 1 is shared between the mask and the
 *    result, so the compiler is 1.1p1 and the last-arm residue stands.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * ADDED 2026-09-23 (wave 13).  Four closed: func_0200D064 (EXACT),
 * func_0200D144 (EXACT*), its follower func_0200D288 (EXACT, new witness),
 * func_0200CC40 (EXACT).  Facts proven against the bytes:
 *
 *  - THE SPECIES-BIT HELPER.  Three functions close only through
 *        static inline u32 TestSpecies(const u8 *row, u32 id)
 *        { u16 x = id - 1; return row[x >> 3] & (1 << (x & 7)); }
 *    called with a row base (`p + K`, or a row accessor) and the 1-BASED
 *    species id.  Each inlined copy owns its `x`: the `id - 1` is shared
 *    but `x & 7`, `x >> 3` and `row + (x >> 3)` are rebuilt per call,
 *    except between the two operands of one `||`, which share the mask.
 *    That per-copy rebuild is the "recomputed at every join" the wave-11
 *    notes could not reproduce with one shared index.  The form-bit rows
 *    (+0x30E/+0x317) take an already 0-based index: `TestBit(row, u16 x)`.
 *  - func_0200D064 reads its row through a u16-indexed accessor
 *        static inline u8 *DistRow(struct Blk37 *p, u16 row)
 *        { return p->unk05C[row]; }
 *    (the per-use `lsls/lsrs #16` of the u32 loop counter), and returns 1
 *    straight from the loop.
 *  - func_0200CC40 takes `u16 id` (the narrow-parameter tell: its home slot
 *    is stored and then RELOADED for the first call); its prototype is
 *        void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2,
 *                           u32 *outForm, u16 a5);
 *  - 0x0200D288, the unlabelled leaf after func_0200D144:
 *        u32 func_0200D288(struct Blk37 *p, u32 which)
 *        { if (which == 0) return p->unk4D0; return 0; }
 *    the reader of the unk4D0 species-0x147 cache.
 *  - func_020073D8 takes THREE arguments (save, id, c): its body forwards
 *    r2 to func_020319A4.  In func_0200C52C the third is the literal 0 that
 *    also feeds the +0x08/+0x04 stores.  func_0200C52C remains DIFF (120/56
 *    with the real prototypes); see docs/notes/pkt_0200C52C.c.txt.
 *  - func_0200CA98 is size-exact (392/392, 147 out, allocation only) when
 *    the form-row clears are `q = p + 0x30E; q += o; *q &= ...` (row
 *    pointers hoisted after the cnt guard) and the tail is open-coded with
 *    named off/bit/nm; docs/notes/pkt_0200CA98.c.txt.  The TestSpecies
 *    helper does NOT fit its tail: there the image shares bit and off
 *    across the four-row clear and all six set arms.
 * ------------------------------------------------------------------ */

#endif /* MUSICAL_DIST_SAVE_H */
