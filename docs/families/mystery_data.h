/*
 * docs/families/mystery_data.h -- shared declarations for the mystery_data.c
 * family (mystery gift / Wi-Fi gift data), 0x0200A300..0x0200ADB8 in the ARM9
 * image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * Derived from the 35 matched functions found with
 *   grep -l "address:  0x0200A[3-9A-D]" src/matched/*.c
 * (16 files: 8 single functions, 6 `unit:` ranges, 2 unlabelled-leaf pairs).
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE.  A load or a store instruction constrains a field; a
 * name does not.  A `lsls`/`lsrs` pair of equal width proves a bitfield's
 * width (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); an
 * unequal pair is a narrowing cast folded with a shift.  Where two matched
 * files spell the same object differently, the file whose code actually
 * constrains it wins.
 *
 * ------------------------------------------------------------------------
 * THE THREE OBJECTS
 * ------------------------------------------------------------------------
 * 1. `Obj` (12 bytes), the handle: block pointer, a `kind` that is only ever
 *    0 or 1, and a third word.  Every accessor is a `switch (kind)` whose two
 *    arms are byte-for-byte identical and whose default falls through to a
 *    zero return -- the distinction lives in the source, not the code.
 *    Evidenced by unit_0200A3FC.c (func_0200A3FC/A400/A418/A41C/A43C).
 *
 * 2. `Big` (0x2A4 bytes), two parallel 0x20-byte bitmaps at +0x258 and
 *    +0x278, 100 of the 256 bits in use.  Evidenced by unit_0200A3FC.c
 *    (func_0200A53C returns sizeof; func_0200A544 constructs).
 *
 * 3. `Rec` (0x34C bytes), THE CENTRAL OBJECT OF THE FAMILY: an array of 30
 *    `Entry` records of 0x1C bytes (30 * 0x1C == 0x348) followed by one word
 *    of flags at +0x348.  Evidenced by unit_0200A864.c (func_0200A8AC scans
 *    30), sub_0200AB24 (returns 0x34C) and func_0200AB2C (clears 0x34C then
 *    writes the +0x348 word).
 *
 * THE ONE BIG IDEA: 0x1C-BYTE ENTRY RECORDS, WALKED BY LINEAR SCAN.
 * Almost every open function left in this family is a `for (i = 0; i < n;
 * i++)` over the same 0x1C-byte stride, testing the same two fields:
 *   - the u32 at +0x14 compared against a key, and
 *   - bit 31 of the packed u32 at +0x10 (the "in use" flag).
 * That pair is the accept test in sub_0200A9A4, sub_0200A9D4, func_0200ABE0
 * and func_0200ACD0 -- four independent byte-exact witnesses.  A new scan in
 * this family almost certainly has the same shape, and the two levers that
 * cost time there are recorded below.
 */

#ifndef MYSTERY_DATA_H
#define MYSTERY_DATA_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;

/* ===================================================================== *
 * Externs used across the family
 * ===================================================================== */

/* heap alloc: (heap, id, ?, __FILE__, size) -- func_0200A300 */
extern void *func_02030734(void *heap, int b, int c, void *d, int e);
/* memset-alike: (p, fill, n) -- func_0200A300, func_0200AB2C, func_0200A3D0 */
extern void  func_02082BCC(void *p, int c, u32 n);
/* heap free -- func_0200A338 */
extern void  func_020307B0(void *p);
/* save-block getter: (sys, block id) -- func_0200A5F8 (0x2A),
 * func_0200A864 (0x2B), func_0200A8A0 (0x2C) */
extern void *func_020071CC(void *sys, u32 id);
/* checksum / obfuscation trio -- func_0200A4B8, func_0200A50C */
extern u16   func_0203F2FC(void *base, u32 size);
extern void  func_0203F328(void *base, u32 size, u32 seed);
extern void  func_0203F37C(void *base, u32 size, u32 seed);
/* rand-below-n -- sub_0200A940 */
extern s32   func_020056EC(s32 n);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void *memcpy(void *dst, const void *src, u32 n);   /* 0x02082D44, arm */

/* The system word read twice for the obfuscation key; a cast address
 * constant, NOT an extern -- an `extern volatile u32` there produces an
 * ABS32 relocation and changes the register.  unit_0200A3FC.c. */
#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)

/* ===================================================================== *
 * Object 1: the 12-byte handle
 * ===================================================================== */

struct Obj {
    void *unk00;     /* the block                 -- func_0200A418 */
    u32   unk04;     /* kind, 0 or 1 only         -- func_0200A3FC */
    void *unk08;
};

/* size of the block for each kind, from func_0200A4B8's switch:
 *   kind 0 -> 0x368,  kind 1 -> 0xA94;
 * the 4-byte Hdr sits at (size - 4).  */
struct Hdr {
    u16 unk00;       /* checksum, func_0203F2FC's return */
    u16 unk02;       /* key, (sysword << 8) | sysword, never 0 */
};

u32   func_0200A3FC(struct Obj *obj);            /* -> kind */
u32   func_0200A400(struct Obj *obj);            /* kind 0 -> 3, 1 -> 12 */
void *func_0200A418(struct Obj *obj);            /* -> unk00 */
void *func_0200A41C(struct Obj *obj);
void *func_0200A43C(struct Obj *obj, u32 index); /* unk00 + 0x100 + i*0xCC */
void  func_0200A480(struct Obj *obj);            /* stamp   */
void  func_0200A49C(struct Obj *obj);            /* unstamp */
void  func_0200A4B8(void *base, u32 kind);
void  func_0200A50C(void *base, u32 kind);

/* constructor / destructor of the handle, 0x0200A300 region */
void *func_0200A300(void *a0, void *a1, void *a2);
void  func_0200A338(void *a0);
void  func_0200A348(void *a0, void *a1, void *a2);   /* tail call to A400 */

/* ===================================================================== *
 * Object 2: the 0x2A4-byte Big record with two bitmaps
 * ===================================================================== */

struct BigSub6 { u8 unk0; u8 unk1[5]; };
struct BigSub4 { u8 unk0; u8 unk1[3]; };

struct Big {
    u8 unk000[0x1B0];
    struct BigSub6 unk1B0[8];      /* seeded to 10 by func_0200A604 */
    struct BigSub4 unk1E0[10];     /* seeded to 4  by func_0200A544 */
    u8  unk208[0x4A];
    u16 unk252;
    u16 unk254;
    u16 unk256;
    u8  unk258[0x20];              /* bitmap A -- func_0200A644 tests */
    u8  unk278[0x20];              /* bitmap B -- func_0200A680 tests */
    u8  unk298[4];
    u8  unk29C;
    u8  unk29D;
    u8  unk29E;
    u8  unk29F;
    u8  unk2A0[4];
};

u32  func_0200A53C(void);                        /* sizeof(struct Big) */
void func_0200A544(struct Big *p);
void func_0200A604(struct Big *p);
u8  *func_0200A628(struct Big *p);
u32  func_0200A644(struct Big *p, u32 index);    /* bitmap A, index < 100 */
u32  func_0200A680(struct Big *p, u32 index);    /* bitmap B, index < 100 */
void func_0200A6BC(struct Big *p, u32 index);    /* set the bit in both */

/* The bit arithmetic, identical in all three and load-bearing:
 *     if (index >= 100) ...;
 *     u8 shift = (s32)index % 8;     -- the (s32) cast is required
 *     u8 byte  = index >> 3;
 *     map[byte] |= (u8)(1 << shift);
 */

/* ===================================================================== *
 * Object 3: Rec, 30 x Entry(0x1C) + one flag word.  THE CENTRAL OBJECT.
 * ===================================================================== */

struct Entry {
    u8  unk00[0x10];
    /* the packed word at +0x10; widths proved by the shift pairs in
     * func_0200A8D0 (lsls #25/lsrs #25), func_0200A8E4 and func_0200A8F8 */
    u32 f10_0  : 7;      /* the key/id     -- func_0200A8D0 returns u8  */
    u32 f10_7  : 10;     /* an offset      -- func_0200A8E4 returns u16 */
    u32 f10_17 : 1;      /*                -- func_0200A8F8 returns u32 */
    u32 f10_18 : 13;
    u32 f10_31 : 1;      /* IN USE; the scan terminator everywhere      */
    u32 unk14;           /* THE KEY compared in every linear scan       */
    u16 unk18;
    u8  unk1A;
    u8  f1B_0 : 6;
    u8  f1B_6 : 1;
    u8  f1B_7 : 1;       /* the flag sub_0200A9A4 returns, sub_0200AB04
                          * clears across all 30 entries                */
};

struct Rec {
    struct Entry entries[30];
    u32 f348_0 : 8;      /* func_0200AB2C writes 0x7F here after clearing */
    u32 f348_8 : 24;
};

s32           func_0200A8AC(struct Rec *r);      /* count of in-use entries */
struct Entry *func_0200A8C8(struct Rec *r, u32 index);
u8            func_0200A8D0(struct Rec *r, u32 index);   /* f10_0  */
u16           func_0200A8E4(struct Rec *r, u32 index);   /* f10_7  */
u32           func_0200A8F8(struct Rec *r, u32 index);   /* f10_17 */
void          func_0200AB2C(struct Rec *r);              /* clear + set 0x7F */
s32           sub_0200AB24(void);                        /* 0x34C */

/* The four byte-exact linear scans.  All four use the SAME accept test:
 *     o[i].unk14 == key && (o[i].f10 >> 31) == 1
 * and all four index with an explicit `base + i * 0x1c` or a struct array;
 * three of the four are written on a raw u8* with hand-written offsets and
 * one (unit_0200A9A4) on a struct.  Both spellings reach EXACT, so the
 * choice is free -- but the OPERAND ORDER of the comparison is not.        */
s32  sub_0200A9A4(struct Entry *o, u32 key);   /* -> f1B_7 of the hit */
s32  sub_0200A9D4(struct Entry *o, u32 key);   /* -> 1 on a hit       */
s32  func_0200ABE0(u8 *base, s32 n, u8 *other);
u8  *func_0200ACD0(u8 *base, s32 n, s32 key);
void sub_0200AB04(struct Rec *r);              /* clear f1B_7 on all 30 */

/* ---- the two levers that cost time in this family --------------------
 * 1. cmp operand order names the temporary (func_0200ABE0): both sides of
 *    the equality are loads, and the side the SOURCE names first lands in
 *    cmp's left slot.  Write the CALLER's object on the left:
 *        *(u32 *)(b + 0x14) == *(u32 *)(p + 0x14)
 *    Swapping them is one byte (`cmp r2, r5` vs `cmp r5, r2`).
 * 2. Do NOT hoist the loop-invariant load into a local (func_0200ABE0):
 *    as a local it is materialised before the `n <= 0` guard and the whole
 *    entry test moves.  Leave it in the condition.
 * (See docs/idioms/cmp-operand-order-names-the-temporary.md and
 *  docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md)
 */

/* ===================================================================== *
 * The insert/shift helper -- func_0200AB50, 0x0200AB50
 * ===================================================================== */
/* Finds the insertion point by key order, shifts the tail down one slot
 * with memcpy(&list[k-1], &list[k], 0x1c), copies the new entry out and
 * returns the slot index, or 0xFF when there is none.  It is the only
 * function in the family that names `memcpy` (0x02082D44, arm) rather
 * than func_02082BCC. */
u8 func_0200AB50(struct Entry *list, s32 n, struct Entry *dst);

/* ===================================================================== *
 * Known permanent walls in this family (do not re-derive)
 * ===================================================================== */
/* func_0200A3D0 (src/pending, MATCH, all 44 bytes right): the call at +0x10
 *   targets 0x021DFDB8, which seven overlays hold (ov093, ov119, ov137,
 *   ov170, ov175, ov183, ov228) and NONE labels, so `label` cannot carry it
 *   and the `veneer` class admits ARM shapes only.  Also note 0xE4 there is
 *   an R_ARM_ABS32 against an absolute linker symbol, not the integer 228:
 *   every numeric spelling gives `movs r0, #0xe4`, the pool word needs an
 *   extern (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * func_0200A848 (src/pending, MATCH, all 28 bytes right): 0x02161EEC has no
 *   func_ label in either overlay that holds it (ov009, ov010), and
 *   0x02161F00 is labelled in ov010 but has no branch witness outside this
 *   28-byte range.  The only witness is the call that needs it, so no cut
 *   helps.  Closes the day disasm.py labels 0x02161EEC.
 * func_0200A300 is EXACT but was blocked on 0x0200A358; 0x0200A358 is itself
 *   still open (see docs/notes/pkt_0200A358.c.txt). */

#endif /* MYSTERY_DATA_H */
