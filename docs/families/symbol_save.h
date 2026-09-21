/*
 * docs/families/symbol_save.h -- shared declarations for the symbol_save.c
 * family (0x0200E2BC..0x0200F6B8 in the ARM9 image).  The range packs
 * several distinct sub-packets the byte evidence shows share objects and
 * idioms rather than one translation unit: a keyed-record table
 * (func_0200E2BC, an 11/12/6/3-bit packed key, 530 entries); a capped
 * byte-counter array (func_0200E460/0x0200E49C/0x0200E4B0/0x0200E4CC,
 * capped at 0x63); a value pair at offsets 0x5c2/0x5c6 of a caller object
 * (func_0200E5A0, func_0200E9E0, unit_0200E684); a table addressed
 * through counters at +0x1554/+0x1558 (func_0200EC14, func_0200EC2C,
 * func_0200ECF0, unit_0200ECB4); a 32-slot MRU u32 list plus a 256-bit
 * companion bitmap (func_0200ED54, unit_0200EDC4); a producer/consumer
 * drain over 0x50-byte destination records built from 0x100-byte source
 * records (func_0200EE64, sub_0200EEAC, sub_0200EED8, func_0200EF78,
 * sub_0200F0CC, sub_0200F104); a per-save object with fields at
 * +0x6200/+0x6204 and mod-10-indexed 6-byte sub-records (unit_0200E884,
 * unit_0200E918, unit_0200E938); a 0x20-byte-stride ten-accessor record
 * array (unit_0200E730); an id-space remap table (sub_0200F128); and a
 * DWC "friend data" slot manager built from a 0xc-byte record and
 * DWC_IsValidFriendData (func_0200F38C, func_0200F4E4, sub_0200F34C,
 * sub_0200F520, sub_0200F594, func_0200F5EC).  They are documented
 * together because they occupy one contiguous, gapless matched range and
 * cross-call each other (func_0200ECF0 -> func_0200EC2C, func_0200EE64 ->
 * sub_0200F0CC/sub_0200EED8, sub_0200EEAC -> func_0200F104/func_0200EF78,
 * func_0200F5EC -> sub_0200F34C/sub_0200F594 -> sub_0200F520); nothing
 * here asserts they are fields of a single outer struct.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT (or EXACT*,
 * meaning the compiled bytes match but the disasm.py extent runs a little
 * further over unlabelled followers -- noted per file where it applies),
 * and the matched function that evidences each field or parameter is
 * named beside it.  Where two matched sources could be read as spelling
 * the same thing differently, the spelling recorded here is the one the
 * byte evidence actually constrains.
 *
 * func_0200F2D4.c and sub_0200F2D4.c are two on-disk matches of the SAME
 * address (0x0200F2D4): the former is a garbled single-line "unit: no"
 * spelling, the latter a clean rewrite with prose.  This header uses only
 * sub_0200F2D4's spelling and does not double-count the two.
 *
 * Addresses are Black-image addresses throughout.  Nothing here encodes a
 * guess about the White layout.
 */

#ifndef SYMBOL_SAVE_H
#define SYMBOL_SAVE_H

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * WHAT THIS FAMILY APPEARS TO DO.
 *
 * The range mixes trainer/record-style save data (a packed-key lookup
 * table, a capped byte counter array reminiscent of a friendship/medal
 * value, a fixed six-entry sub-table addressed by a running index at
 * +0x1554/+0x1558) with DWC (Nintendo WFC / friend list) bookkeeping:
 * DWC_IsValidFriendData is called directly by func_0200F5EC, and
 * func_0200F38C/func_0200F4E4/sub_0200F34C/sub_0200F520/sub_0200F594 all
 * thread a 0xc-byte friend record through a 32-slot table.  The
 * 0x50-byte/0x100-byte producer/consumer pair (func_0200EE64 and friends)
 * reads like a save-file export path: it drains a bounded record source
 * into a fixed-stride destination buffer.  Nothing in the matched
 * evidence names a single umbrella struct for all of this; the
 * sub-packets are grouped here because they are contiguous and
 * cross-call, not because one struct spans them.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * struct SymKey -- the packed key func_0200E2BC matches against.
 *
 * func_0200E2BC casts its second parameter (a1) to this bitfield type when
 * mode == 1, and compares only the lo and hi fields against each 4-byte
 * table entry read as the same bitfield; when mode != 1 it instead does a
 * flat 4-byte memcmp of the same entry.  The bit widths (11/12/6/3) are
 * exactly what the source's `Key` typedef packs into one u32; mid is never
 * read by func_0200E2BC's mode-1 compare but is included because it is
 * part of the 4-byte layout the memcmp path evidences.
 * ------------------------------------------------------------------ */
typedef struct {
    u32 lo  : 11;   /* func_0200E2BC, mode == 1 compare */
    u32 mid : 12;   /* part of the packed u32; not read by the mode-1 test */
    u32 hi  : 6;     /* func_0200E2BC, mode == 1 compare */
    u32 top : 3;     /* part of the packed u32 (11+12+6+3 == 32) */
} SymKey;

#define SYM_TABLE_ENTRIES   530     /* func_0200E2BC's inner loop bound */
#define SYM_TABLE_BYTES     0x850   /* func_0200E2BC's allocation size for
                                     * the 530-entry table (0x850 / 4 == 530,
                                     * consistent with 4-byte entries) */
#define SYM_TABLE_PAGES     2       /* func_0200E2BC's outer loop bound;
                                     * func_02007248 is asked for page 0 and
                                     * page 1 in turn */
#define SYM_TABLE_PAGE_KIND 0x3d    /* func_0200E2BC's constant passed as
                                     * func_02007248's second argument
                                     * (the record-kind selector) */

/* 0x0200E2BC  scan a two-page, 530-entry keyed table for a4/a1's key.
 * mode == 1 compares SymKey.lo and SymKey.hi only; any other mode does a
 * flat 4-byte memcmp of the whole entry against *a1.  Allocates the
 * 0x850-byte scratch table itself (func_02030734/func_020307B0) and frees
 * it before returning; func_0200E06C is called once per successfully
 * loaded page, before the inner scan. */
u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode);

/* 0x0200E368  a bare constant getter: 0xa1 * 4 == 0x284, the same size
 * func_0200E370 zeroes.  Reads as the size-of-the-zeroed-block accessor
 * for whatever object func_0200E370 initialises. */
int func_0200E368(void);

/* ------------------------------------------------------------------ *
 * The 0x284-byte descriptor block func_0200E370 zeroes and tags.
 *
 * func_0200E370 memsets 0x284 bytes to 0 and then writes three trailing
 * bytes at +0x280/+0x281/+0x282 to the constants 0, 8 and 0x1d. 0x0200E44C
 * and 0x0200E4F8 both compute their offset as `p0 + p1 + 0x280`
 * (`(0xa << 6) << 0` literally decodes to 0x280), i.e. they index a table
 * that starts exactly where func_0200E370's tag bytes are -- so the three
 * tag bytes are the HEAD of a following table, not padding at the end of a
 * fixed record.  func_0200E44C reads one byte at that base; func_0200E4F8
 * reads a u16 at base + (idx << 1) + 0x154 (`0x55 << 2 == 0x154`), i.e. a
 * parallel u16 array 0x154 bytes further into the same table region.  No
 * matched source names the element count of either array, so none is
 * recorded here.
 * ------------------------------------------------------------------ */

/* 0x0200E370  zero 0x284 bytes at p, then write the tag bytes 0, 8, 0x1d
 * at p[0x280..0x282]. */
void func_0200E370(u8 *p);

/* 0x0200E394  forward a0 to func_020071CC with the fixed id 0x3f. */
void func_0200E394(int a0);

/* 0x0200E3A0  return a + 0xd2. */
u32 func_0200E3A0(u32 a);

/* 0x0200E44C  byte read at object[p0 + p1 + 0x280] (four raw ints in the
 * unit:no source; p2/p3 are read but not used in the returned expression). */
int func_0200E44C(int p0, int p1, int p2, int p3);

/* ------------------------------------------------------------------ *
 * struct SymCounters -- the capped byte-value array at object+0x3c.
 *
 * func_0200E4B0/func_0200E4CC/func_0200E49C all address the SAME base:
 * `a0 + 0x3c` (func_0200E4CC's comment records that this has to be written
 * as pointer-then-index, `p = a0 + 0x3c; p[off]`, not `a0[off + 0x3c]`, or
 * the byte match is lost).  func_0200E488 (outside this range) computes
 * the element offset from (a1, a2); every value stored through this array
 * is clamped to 0x63 (99) by func_0200E4CC, and func_0200E49C reports
 * "maxed" (1) once a value reaches 0x63 -- the shape of a friendship or
 * happiness-style capped counter table indexed by some (a1, a2) key pair
 * rather than a flat index.
 * ------------------------------------------------------------------ */
#define SYM_COUNTER_BASE  0x3c    /* func_0200E4B0, func_0200E4CC */
#define SYM_COUNTER_CAP   0x63    /* func_0200E4CC clamps stores to this;
                                   * func_0200E49C's "maxed" threshold */

/* 0x0200E460  add v (as u16, clamped to 0x270f) into a 16-bit slot at
 * p + idx*2. */
void func_0200E460(char *p, int idx, int v);

/* 0x0200E49C  1 when func_0200E4B0(p, a, count) >= SYM_COUNTER_CAP, else 0. */
u32 func_0200E49C(u8 *p, u32 a, u32 count);

/* 0x0200E4B0  read one byte of the SYM_COUNTER_BASE array at the offset
 * func_0200E488(a1, a2) computes; returns 0 when a2 == 0 without calling
 * func_0200E488 at all. */
u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);

/* 0x0200E4CC  write-and-clamp counterpart of func_0200E4B0.  a3 is SIGNED
 * (the compare against SYM_COUNTER_CAP is `ble`, not `bls`); a3 + v is
 * added with a3 named first (`adds r1, r4, r2`), which the source has to
 * preserve as written (`a3 + v`) to reproduce the encoded operand order. */
void func_0200E4CC(u8 *a0, u32 a1, u32 a2, int a3);

/* 0x0200E4F8  u16 read at object[(p0 + (t0<<1)) + 0x154], where
 * t0 = func_0200E488(p1, p2); returns 0 without calling func_0200E488 when
 * p2 == 0 (four raw ints in the unit:no source). */
int func_0200E4F8(int a0, int a1, int a2, int a3);

/* ------------------------------------------------------------------ *
 * The +0x5c2/+0x5c6 field pair.
 *
 * func_0200E5A0 and sub_0200E684 (alias of unit_0200E684.c) both address a
 * caller object through the SAME two offsets: +0x5c6 is a cached u16 whose
 * fresh value comes from func_0203F1FC(obj, 0x5c6) (a lookup keyed by its
 * own offset as an id), and +0x5c2 is a paired u16 that is rewritten
 * whenever +0x5c6 is refreshed.  func_0200E5A0 reads +0x5c2 for a
 * different fixed constant (0xd68) than sub_0200E684 writes into it
 * (0x7da); both are plausible states of the same paired field, but no
 * matched source ties the two constants to named enum values, so neither
 * is asserted as an enum here.
 * ------------------------------------------------------------------ */
#define SYM_FIELD_LO_OFF     0x5c2   /* func_0200E5A0, sub_0200E684 */
#define SYM_FIELD_CACHE_OFF  0x5c6   /* func_0200E5A0, sub_0200E684:
                                      * looked up via func_0203F1FC(obj, id)
                                      * with id == this offset */
#define SYM_FIELD_LO_TEST    0xd68   /* func_0200E5A0's required value */
#define SYM_FIELD_LO_SET     0x7da   /* sub_0200E684's written value */

/* 0x0200E5A0  EXACT*: listing extent runs to 0x0200E688 over three
 * unlabelled followers; compiled bytes match exactly.  True only when
 * BOTH obj[+0x5c6] == func_0203F1FC(obj, 0x5c6) AND obj[+0x5c2] ==
 * SYM_FIELD_LO_TEST (one conjunction; two separate ifs miscompile). */
int func_0200E5A0(void *a0);

/* 0x0200E684 (unit_0200E684.c, sub_0200E684)  when obj[+0x5c6] equals a
 * fresh func_0203F1FC(obj, 0x5c6) lookup, rewrite obj[+0x5c2] with
 * SYM_FIELD_LO_SET and refresh obj[+0x5c6] with a second lookup. */
void sub_0200E684(void *obj, void *unused);

/* 0x0200E6B0 (unit_0200E684.c)  unlabelled constant getter, returns 0x28. */
u32 sub_0200E6B0(void);

/* 0x0200E6E8 (unit_0200E6E8.c)  pure forwarder to sub_0200E6F0. */
void *sub_0200E6E8(u32 a);

/* 0x0200E6F0 (unit_0200E6E8.c)  tail-calls func_020071CC(a, 0x3e). */
void *sub_0200E6F0(u32 a);

/* ------------------------------------------------------------------ *
 * struct SymRec0200E6FC -- one 8-byte record, four u16 fields.
 *
 * func_0200E6FC copies src[idx] into *dst as a struct assignment; the
 * struct spelling is required (a field-by-field copy or a u16* temporary
 * picks a different register for the scaled index and misses by 6 bytes).
 * No matched source names what a, b, c, d mean individually.
 * ------------------------------------------------------------------ */
struct SymRec0200E6FC {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

/* 0x0200E6FC  EXACT*: listing extent runs 192 bytes because the follower
 * at 0x0200E714 carries no label; compiled bytes match exactly.  Copies
 * src[idx] to *dst. */
void func_0200E6FC(struct SymRec0200E6FC *src, int idx, struct SymRec0200E6FC *dst);

/* ------------------------------------------------------------------ *
 * struct SymRec0200E730 -- ten accessors on a 0x20-byte-stride table
 * (unit_0200E730.c).  Only the fields the ten accessors actually touch
 * are named; other bytes in the 0x20-byte stride are unaccounted for.
 * ------------------------------------------------------------------ */
typedef struct {
    u8 flag  : 1;   /* sub_0200E740, bit 0 of the +0x1a byte */
    u8 level : 7;   /* sub_0200E74C, bits [7:1] of the +0x1a byte, clamped
                     * into [0x41, 0x64] with +5 applied once >= 0x41 */
} SymFlagsE730;

#define SYM_E730_FILL_SIZE   0x40    /* sub_0200E730's constant, the size
                                      * sub_0200E734 zero-fills */
#define SYM_E730_STRIDE      0x20    /* every accessor's per-record size */
#define SYM_E730_LEVEL_MIN   0x41    /* sub_0200E74C's clamp floor */
#define SYM_E730_LEVEL_MAX   0x64    /* sub_0200E74C's clamp ceiling */
#define SYM_E730_UNSET       0xff    /* sub_0200E76C/sub_0200E780's "unset"
                                      * sentinel for the byte at +0x1b */

/* 0x0200E730  constant getter, returns SYM_E730_FILL_SIZE (0x40). */
u32 sub_0200E730(void);

/* 0x0200E734  zero-fill SYM_E730_FILL_SIZE bytes at dest. */
void sub_0200E734(void *dest);

/* 0x0200E740  read the 1-bit flag at record[idx]+0x1a. */
u32 sub_0200E740(const void *obj, u32 idx);

/* 0x0200E74C  read the 7-bit level at record[idx]+0x1a, clamped into
 * [SYM_E730_LEVEL_MIN, SYM_E730_LEVEL_MAX] (raw values below the floor
 * clamp up; raw values at or above the floor get +5 then clamp down). */
u32 sub_0200E74C(const void *obj, u32 idx);

/* 0x0200E76C  is record[idx]+0x1b anything other than SYM_E730_UNSET? */
u32 sub_0200E76C(const void *obj, u32 idx);

/* 0x0200E780  raw byte read of record[idx]+0x1b. */
u8 sub_0200E780(const void *obj, u32 idx);

/* 0x0200E788  a two-flag cost table: ignores its first argument; 0x23c
 * when a == 1, 0x222 when b == 0x15, 0x224 otherwise. */
u32 sub_0200E788(u32 unused, u32 a, u32 b);

/* 0x0200E7A4  plain u32 getter at record[idx]+0. */
u32 sub_0200E7A4(const void *obj, u32 idx);

/* 0x0200E7AC  pointer-to-field getter, record[idx]+4. */
void *sub_0200E7AC(void *obj, u32 idx);

/* 0x0200E7B4  plain u32 getter at record[idx]+0x1c. */
u32 sub_0200E7B4(const void *obj, u32 idx);

/* 0x0200E874 (unit_0200E874.c)  unlabelled size-getter, returns 0x10. */
int sub_0200E874(void);

/* 0x0200E878 (unit_0200E874.c)  tail call to MI_CpuFill8, clears 0x10
 * bytes at dst. */
void sub_0200E878(void *dst);

/* ------------------------------------------------------------------ *
 * The big per-save object (unit_0200E884.c / unit_0200E918.c /
 * unit_0200E938.c): fields at +0x6200/+0x6204, a byte array at +6, and a
 * 6-byte-record array starting at +0xa with an 8-byte stride, indexed by
 * "id mod 10".  Twelve accessors work the +0x6200/+0x6204 half in
 * unit_0200E884.c; two more work the +6 byte array in unit_0200E918.c;
 * three more work the +0xa record array in unit_0200E938.c.  No matched
 * source ties these three groups to one named struct, so they are kept
 * as separate offset facts on the same underlying object rather than one
 * struct definition.
 * ------------------------------------------------------------------ */
#define SYM_OBJ_SIZE_FIELD_OFF  0x6200  /* unit_0200E884.c: sub_0200E8D8/
                                         * sub_0200E8E0's plain getter/setter */
#define SYM_OBJ_ZEROFILL_SIZE   0x6204  /* unit_0200E884.c: sub_0200E8B0's
                                         * constant, used by sub_0200E8B8
                                         * as the whole-object zero-fill size */
#define SYM_OBJ_TAIL_OFF        0x6000  /* unit_0200E884.c: sub_0200E8D0's
                                         * returned address, obj+0x6000 */
#define SYM_OBJ_SCRATCH_SIZE    0x10    /* unit_0200E884.c: the copy-in/
                                         * copy-out scratch object size */
#define SYM_OBJ_ALT_FILL_SIZE   0x5c    /* unit_0200E884.c: sub_0200E8E8's
                                         * constant / sub_0200E8EC's fill */
#define SYM_OBJ_SCRATCH2_SIZE   0x5a    /* unit_0200E884.c: sub_0200E904's
                                         * zero-fill size before
                                         * func_02087C6C */
#define SYM_OBJ_BYTEARR_OFF     6       /* unit_0200E918.c: base+idx offset
                                         * into the per-index byte array */
#define SYM_OBJ_REC_BASE_OFF    0xa     /* unit_0200E938.c: obj + 0xa +
                                         * idx*8 for the 6-byte records */
#define SYM_OBJ_REC_STRIDE      8       /* unit_0200E938.c */
#define SYM_OBJ_REC_SIZE        6       /* unit_0200E938.c */
#define SYM_OBJ_REC_MOD         10      /* unit_0200E938.c: idx = id % 10 */

/* 0x0200E884  copy a SYM_OBJ_SCRATCH_SIZE-byte record from sub_020071CC
 * (id 0x40) into sys. */
void sub_0200E884(void *sys, void *src);

/* 0x0200E89C  the inverse copy: sub_020071CC's (id 0x40) scratch object
 * out to dest. */
void sub_0200E89C(void *sys, void *dest);

/* 0x0200E8B0  constant getter, returns SYM_OBJ_ZEROFILL_SIZE (0x6204). */
u32 sub_0200E8B0(void);

/* 0x0200E8B8  zero-fill the whole object (SYM_OBJ_ZEROFILL_SIZE bytes). */
void sub_0200E8B8(void *dest);

/* 0x0200E8CC  empty hook; no body. */
void sub_0200E8CC(void);

/* 0x0200E8D0  return obj + SYM_OBJ_TAIL_OFF. */
void *sub_0200E8D0(void *obj);

/* 0x0200E8D8  plain u32 getter at obj + SYM_OBJ_SIZE_FIELD_OFF. */
u32 sub_0200E8D8(const void *obj);

/* 0x0200E8E0  plain u32 setter at obj + SYM_OBJ_SIZE_FIELD_OFF. */
void sub_0200E8E0(void *obj, u32 value);

/* 0x0200E8E8  constant getter, returns SYM_OBJ_ALT_FILL_SIZE (0x5c). */
u32 sub_0200E8E8(void);

/* 0x0200E8EC  tail call to MI_CpuFill8, zero-fills SYM_OBJ_ALT_FILL_SIZE
 * bytes at dest (the constant is inlined directly, not routed through
 * sub_0200E8E8). */
void sub_0200E8EC(void *dest);

/* 0x0200E8F8  tail call to sub_020071CC(sys, 0x41). */
void *sub_0200E8F8(void *sys);

/* 0x0200E904  zero-fill a SYM_OBJ_SCRATCH2_SIZE-byte (0x5a) scratch object
 * and hand it to func_02087C6C. */
void sub_0200E904(void *obj);

/* 0x0200E918  plain byte getter: (base+idx)[SYM_OBJ_BYTEARR_OFF]. */
u8 sub_0200E918(const u8 *base, u32 idx);

/* 0x0200E920  add a signed delta into (base+6)[idx], clamped to [0,255]. */
void sub_0200E920(u8 *base, u32 idx, int delta);

/* 0x0200E938  copy the SYM_OBJ_REC_SIZE-byte record at
 * obj + SYM_OBJ_REC_BASE_OFF + (id % SYM_OBJ_REC_MOD)*SYM_OBJ_REC_STRIDE
 * out to dest. */
void sub_0200E938(u8 *obj, u32 id, void *dest);

/* 0x0200E958  the inverse: store src into the same mod-10-indexed record. */
void sub_0200E958(u8 *obj, u32 id, const void *src);

/* 0x0200E978  write one byte field at (record base + extra)+0x10 of the
 * mod-10-indexed slot. */
void sub_0200E978(u8 *obj, u32 id, u32 extra, u8 value);

/* ------------------------------------------------------------------ *
 * struct SymList -- the 32-entry u32 MRU list func_0200ED54 maintains,
 * plus its companion 256-bit bitmap read by unit_0200EDC4.c.
 *
 * func_0200ED54's comment records the exact MRU behaviour: insert val
 * unless already present (in which case shift everything above it down
 * one slot via MI_CpuCopy8 and re-write val into the last live slot); if
 * absent and there is room, append; if absent and full, shift the whole
 * table down one slot and place val in slot 31.  sub_0200EDC4 (a plain
 * membership test) operates on the SAME 32-entry-plus-count shape.  The
 * 256-bit bitmap at +0x84 (sub_0200EDEC get-bit, sub_0200EE14 set-bit) is
 * documented by unit_0200EDC4.c as being "of the same object" as the
 * 32-entry list, which is 0x84 bytes (32*4 + 4), i.e. the bitmap begins
 * exactly where the list struct ends.
 * ------------------------------------------------------------------ */
#define SYM_LIST_CAPACITY    32     /* func_0200ED54, sub_0200EDC4 */
#define SYM_BITMAP_OFF        0x84  /* sub_0200EDEC, sub_0200EE14: bitmap
                                     * base, immediately after the 32-entry
                                     * + count list (32*4 + 4 == 0x84) */
#define SYM_BITMAP_BITS       256   /* sub_0200EE14's upper guard */

struct SymList {
    u32 arr[SYM_LIST_CAPACITY];   /* func_0200ED54, sub_0200EDC4 */
    u32 count;                    /* func_0200ED54, sub_0200EDC4 */
};

/* 0x0200ED54  EXACT*: listing extent runs to 0x0200EE48 over the
 * unlabelled follower at 0x0200EDC4; compiled bytes match exactly.
 * Insert val into l's MRU list per the algorithm above. */
void func_0200ED54(struct SymList *l, u32 val);

/* 0x0200EDC4 (unit_0200EDC4.c)  membership test on the same 32-entry list
 * shape as func_0200ED54. */
int sub_0200EDC4(struct SymList *l, u32 val);

/* 0x0200EDEC (unit_0200EDC4.c)  get bit i of the SYM_BITMAP_BITS-bit
 * bitmap at obj+SYM_BITMAP_OFF (signed index: i/32, i%32). */
int sub_0200EDEC(char *obj, int i);

/* 0x0200EE14 (unit_0200EDC4.c)  set bit i of the same bitmap; no-op when
 * i >= SYM_BITMAP_BITS. */
void sub_0200EE14(char *obj, int i);

/* 0x0200EE48 (unit_0200EE48.c)  constant getter, returns 5 << 10 (0x1400). */
u32 sub_0200EE48(void);

/* 0x0200EE50 (unit_0200EE48.c)  zero-fill 0x1400 bytes at dest (via
 * sub_0200EE48's own call, not the raw constant). */
void sub_0200EE50(void *dest);

/* ------------------------------------------------------------------ *
 * The 0x1554/0x1558-counted table func_0200EC14/func_0200EC2C/
 * func_0200ECF0/unit_0200ECB4 all index.
 *
 * unit_0200ECB4.c documents two counters on the same object: a signed int
 * at +0x1554 (the running write index, clamped/wrapped through the
 * 0x16c-byte-stride table by func_0200ECF0 and sub_0200ECD0) and a u32 at
 * +0x1558 clamped to at most 0xf (sub_0200ECB4).  func_0200EC14 is a
 * SEPARATE, smaller six-entry sub-table with a 0x3c-byte stride, whose
 * entries' leading u16 doubles as an "empty slot" sentinel (0 means
 * empty); func_0200EC2C copies one 0x3c-byte source record of that
 * sub-table into a differently laid out destination record.  No matched
 * source ties the 0x16c-stride outer table and the 0x3c-stride six-entry
 * sub-table to the same base offset, so they are kept as two separate
 * facts about the containing object.
 * ------------------------------------------------------------------ */
#define SYM_TBL0200E9E0_COUNT_OFF   0x1554  /* func_0200ECF0, sub_0200ECD0:
                                             * signed running index */
#define SYM_TBL0200E9E0_LIMIT_OFF   0x1558  /* sub_0200ECB4, sub_0200ECC4:
                                             * u32 counter, clamped <= 0xf */
#define SYM_TBL0200E9E0_LIMIT_CAP   0xf     /* sub_0200ECB4's clamp */
#define SYM_TBL0200E9E0_STRIDE      0x16c   /* func_0200ECF0, sub_0200ECD0 */
#define SYM_TBL0200E9E0_WRAP        0xf     /* func_0200ECF0, sub_0200ECD0:
                                             * added back when the index
                                             * goes negative */
#define SYM_SUBTBL_COUNT     6       /* func_0200EC14's loop bound */
#define SYM_SUBTBL_STRIDE    0x3c    /* func_0200EC14, func_0200EC2C */

/* struct SymSubSrc0200EC2C -- source record of the 0x3c-byte-stride
 * six-entry sub-table (func_0200EC2C). */
struct SymSubSrc0200EC2C {
    u16 f00;
    u8  f02;
    u8  f03a : 6;   /* func_0200EC2C: read as a bitfield pair, not a plain
                     * byte -- required for the byte match (see source
                     * comment on the `lsls #26 / lsrs #26` pair) */
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u8  f0C[0x16];
    u8  f22[0x10];
    u16 f32[4];
};

/* struct SymSubDst0200EC2C -- func_0200EC2C's destination record. */
struct SymSubDst0200EC2C {
    void *p00;
    void *p04;
    u32   f08;
    u32   f0C;
    u16   f10;
    u8    f12;
    u8    f13a : 6;   /* func_0200EC2C: destination bitfield pair, required
                       * together with the source pair for the byte match */
    u8    f13b : 2;
    u16   f14[4];
};

/* 0x0200EC14  first zero-halfword search over the SYM_SUBTBL_COUNT-entry,
 * SYM_SUBTBL_STRIDE-stride sub-table starting at p: returns the index of
 * the first entry whose leading u16 is 0, or SYM_SUBTBL_COUNT if none is. */
int func_0200EC14(char *p);

/* 0x0200EC2C  EXACT*: inferred extent runs to 0x0200ECF0 because the
 * unlabelled accessor sub_0200EC98 (its own matched entry) follows it
 * with no label of its own; compiled bytes match exactly.  Copy sub-table
 * entry base[idx] into *dst, field by field, per the struct layouts above. */
void func_0200EC2C(const struct SymSubSrc0200EC2C *base, int idx, struct SymSubDst0200EC2C *dst);

/* 0x0200ECF0  compute the wrapped index into the SYM_TBL0200E9E0_STRIDE
 * outer table from a0's SYM_TBL0200E9E0_COUNT_OFF counter and a1, then
 * call func_0200EC2C on that slot. */
void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);

/* ------------------------------------------------------------------ *
 * struct SymOut0200EC98 -- sub_0200EC98's four-word unpack of the three
 * bytes at object+0x168..+0x16b.
 * ------------------------------------------------------------------ */
struct SymOut0200EC98 {
    u32 a;   /* sub_0200EC98: u16 at o+0x168 */
    u32 b;   /* sub_0200EC98: byte at o+0x16a */
    u32 c;   /* sub_0200EC98: byte at o+0x16b */
    u32 d;   /* sub_0200EC98: always zeroed */
};

/* 0x0200EC98  EXACT*: an unlabelled leaf accessor; compiled bytes match
 * exactly.  Unpack o+0x168 (u16) and o+0x16a/o+0x16b (bytes) into *out;
 * out->d is always zero. */
void sub_0200EC98(const u8 *o, struct SymOut0200EC98 *out);

/* 0x0200ECB4 (unit_0200ECB4.c)  read o+SYM_TBL0200E9E0_LIMIT_OFF, clamped
 * to SYM_TBL0200E9E0_LIMIT_CAP. */
u32 sub_0200ECB4(char *o);

/* 0x0200ECC4 (unit_0200ECB4.c)  o[SYM_TBL0200E9E0_LIMIT_OFF] - n. */
u32 sub_0200ECC4(char *o, u32 n);

/* 0x0200ECD0 (unit_0200ECB4.c)  the same wrapped-index computation as
 * func_0200ECF0's first half, tail-called into func_0200EC14 on the
 * resulting SYM_SUBTBL_STRIDE-stride slot; the only reference to
 * func_0200EC14 anywhere in the image. */
void sub_0200ECD0(char *o, int idx);

/* ------------------------------------------------------------------ *
 * struct SymDstRec / struct SymSrcRec -- func_0200EF78's field-by-field
 * marshal (0x100-byte-ish source, 0x100-byte-ish destination).  Field
 * names below are exactly as func_0200EF78.c's matched source spells
 * them; this header records their sizes and offsets, not semantic names,
 * since none of the matched sources names most of the individual fields.
 * ------------------------------------------------------------------ */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} SymVecFx32;

struct SymDstRec {
    u32 flags;
    u32 flags4;
    u16 f8, fa, fc, fe, f10, f12, f14;
    s16 f16, f18, f1a;
    u8  pad1c[4];
    s16 f20, f22, f24;
    u8  pad26[6];
    s16 f2c, f2e, f30, f32, f34, f36, f38, f3a, f3c, f3e, f40;
    u8  pad42[2];
    SymVecFx32 f44;
    u8  pad50[0x7c - 0x50];
    u8  f7c, f7d;
    s8  f7e, f7f, f80;
    u8  pad81[7];
    void *f88;
    u8  pad8c[0x94 - 0x8c];
    u8  f94[0x10];
    u8  fa4[0x10];
    u8  padb4[0xe4 - 0xb4];
    u8  fe4[0x1c];
};   /* func_0200EF78: MI_CpuFill8(dst, 0, 0x100) before any field write */

struct SymSrcRec {
    u32 f0;
    u8  f4, f5;
    u8  pad6[2];
    u8  f8, f9;
    s8  fa, fb, fc, fd, fe;
    u8  padf;
    u16 f10, f12, f14, f16, f18, f1a, f1c, f1e;
    s16 f20, f22, f24, f26, f28, f2a;
    s32 f2c;
    u8  f30[0x10];
    u8  f40[0x10];
};

/* 0x0200EF78  EXACT*: compiled bytes match exactly.  Marshal *src into
 * *dst per the field-by-field mapping in func_0200EF78.c (dst is
 * zero-filled to 0x100 bytes first); arg2 is threaded through to
 * func_0216E2E8 and stashed at dst->f88. */
void func_0200EF78(struct SymDstRec *dst, const struct SymSrcRec *src, void *arg2);

/* ------------------------------------------------------------------ *
 * The producer/consumer drain: func_0200EE64 walks sub_0200F0CC's 0x100-
 * byte-stride record source and, for records whose +4 word does not have
 * bit 20 set, retires each into a 0x50-byte destination cursor via
 * sub_0200EED8 (whose own field marshal is documented at each store in
 * its matched source; offsets are not repeated here since they read
 * directly off sub_0200EED8.c). sub_0200EEAC is the same style of walk
 * over a 64-entry, 0x50-byte-stride table, dispatching bit-0-tagged
 * records to func_0200EF78 via a free-slot lookup in sub_0200F104.
 * ------------------------------------------------------------------ */
#define SYM_DRAIN_DST_STRIDE   0x50    /* func_0200EE64, sub_0200EEAC */
#define SYM_DRAIN_SRC_STRIDE   0x100   /* sub_0200F0CC, sub_0200F104 */
#define SYM_DRAIN_SKIP_BIT     0x100000 /* func_0200EE64: skip a record
                                         * whose (+4 word & this) is set */
#define SYM_SCAN_RECORDS       0x40    /* sub_0200EEAC's fixed walk count */
#define SYM_SCAN_LIVE_BIT      1        /* sub_0200EEAC, sub_0200F0CC,
                                         * sub_0200F104: bit 0 of the
                                         * record's leading word */

/* 0x0200EE64  drain sub_0200F0CC's enumerator (state a0, hint local to
 * this call) into a1's SYM_DRAIN_DST_STRIDE-byte cursor via
 * sub_0200EED8, skipping records with SYM_DRAIN_SKIP_BIT set at +4.
 * Calls sub_0200EE50(a1) once before the loop. */
void func_0200EE64(u32 a0, u8 *a1);

/* 0x0200EEAC  EXACT* (promoted from src/pending, no C change; func_0200F104
 * and func_0200EF78 are each called from exactly this one site so their
 * relocations stay unresolved under the honesty rule).  Walk
 * SYM_SCAN_RECORDS SYM_DRAIN_DST_STRIDE-byte records at list; for each
 * with SYM_SCAN_LIVE_BIT set in its leading word, hand
 * func_0200F104(ctx)'s free slot, the record and ctx to func_0200EF78.
 * Stores the record count (always SYM_SCAN_RECORDS) into ctx+6. */
void sub_0200EEAC(void *ctx, void *list);

/* 0x0200EED8  field-by-field marshal from a source "item" object into a
 * "record" object; several 16-bit fields narrow to 8-bit destination
 * fields, several signed-halfword source fields widen to unsigned
 * destination halfwords, and the tail is two flat 0x10-byte MI_CpuCopy8
 * blocks.  See sub_0200EED8.c for the exact per-field offsets (they are
 * specific to this one marshal and are not repeated here as named
 * fields). */
void sub_0200EED8(const void *item, void *record);

/* 0x0200F0CC  scan obj's SYM_DRAIN_SRC_STRIDE-byte record array (count at
 * obj+4 as u16, base pointer at obj+0x18) from *idxptr for a record with
 * SYM_SCAN_LIVE_BIT set; on a hit, *out gets the record pointer, *idxptr
 * is left one past the hit, returns 1; exhausting the scan returns 0 and
 * leaves *idxptr == count. */
u32 sub_0200F0CC(const void *obj, void *out, u32 *idxptr);

/* 0x0200F104  EXACT*: 34 compiled bytes fall two short of the disasm.py
 * extent over an inter-function "movs r0, r0" filler halfword, not a byte
 * difference.  Scan ctx's SYM_DRAIN_SRC_STRIDE-byte slots (count at
 * ctx+4 as u16, base at ctx+0x18) for the first with SYM_SCAN_LIVE_BIT
 * CLEAR; returns that slot pointer, or NULL once the count is reached. */
void *sub_0200F104(void *ctx);

/* ------------------------------------------------------------------ *
 * sub_0200F128 -- id-space remap table.
 *
 * Below 0xdf the id passes through unchanged; ids in [0x1000, 0x1236)
 * rebase by subtracting 0xf21 (result truncated to u16); ids in
 * [0x2000, 0x200a) rebase by subtracting 0x1ceb (also truncated to u16);
 * everything else, including the gap between the two windows, maps to
 * the constant 0xa.
 * ------------------------------------------------------------------ */
#define SYM_REMAP_PASSTHROUGH_MAX  0xdf     /* below this, id is unchanged */
#define SYM_REMAP_WIN1_LO          0x1000
#define SYM_REMAP_WIN1_HI          0x1236   /* exclusive */
#define SYM_REMAP_WIN1_DELTA       0xf21
#define SYM_REMAP_WIN2_LO          0x2000
#define SYM_REMAP_WIN2_HI          0x200a   /* exclusive */
#define SYM_REMAP_WIN2_DELTA       0x1ceb
#define SYM_REMAP_FALLBACK         0xa

/* 0x0200F128  remap x through the four-way table above. */
u32 sub_0200F128(u32 x);

/* ------------------------------------------------------------------ *
 * sub_0200F2D4 -- a one-byte latch at data address 0x02146178
 * (spelled sub_0200F2D4_Flag), gated on func_0203D5D4() == 2.
 * ------------------------------------------------------------------ */
extern u8 sub_0200F2D4_Flag;   /* 0x02146178, data; referenced only by this
                                * function's pool word, so the relocation
                                * stays unresolved under the honesty rule */

/* 0x0200F2D4 / sub_0200F2D4  while func_0203D5D4() == 2: turn the flag on
 * (from func_0203CF5C()'s result) if it was off, or clear it if it was
 * already on. Outside the gate, call func_0203CF5C() for effect only and
 * leave the flag alone. */
void sub_0200F2D4(void);

/* 0x0200F300  EXACT*: 74 compiled bytes fall two short of the disasm.py
 * extent over a "movs r0, r0" alignment filler, not a byte difference.
 * Membership test on func_0203D5D4()'s result: true for
 * {12,13,14,15,16,28,31,37,38,48}, false otherwise. func_0203D5D4 must be
 * declared returning a SIGNED int (an unsigned return flips every range
 * test's compare instructions). */
int sub_0200F300(void);

/* 0x0200F34C  three-way friend-key comparator.  Returns 0 if
 * func_02059A5C(a, c) flags the pair invalid; else compares b against a
 * with func_020598EC -- "not newer" (2) if that result is <= 0; otherwise
 * re-derives the b-against-a comparison and checks it against a fresh
 * b-against-c comparison, reporting "newer" (1) only when they agree,
 * "not newer" (2) otherwise. */
int sub_0200F34C(void *a, void *b, void *c);

/* ------------------------------------------------------------------ *
 * The friend-slot search / friend record install pair
 * (func_0200F38C/func_0200F4E4) and the 32-slot friend list writer chain
 * (func_0200F5EC -> sub_0200F594 -> sub_0200F520).  All work a 0xc-byte
 * friend record (func_0200F4E4's copy size, sub_0200F594's copy size).
 * ------------------------------------------------------------------ */
#define SYM_FRIEND_TABLE_STRIDE  12    /* func_0200F38C: i*12; func_0200F4E4/
                                        * sub_0200F594: 0xc-byte copies */
#define SYM_FRIEND_SLOTS         0x20  /* func_0200F5EC's loop bound */

/* func_0200F38C's four result codes for a friend-slot search. */
#define SYM_FRIEND_SEARCH_ACCEPT     0   /* tester accepted this slot */
#define SYM_FRIEND_SEARCH_KEY_MATCH  1   /* object's key matches a record */
#define SYM_FRIEND_SEARCH_SCAN_DONE  2   /* scan exhausted, *out is the
                                          * best fallback slot found */
#define SYM_FRIEND_SEARCH_UNKNOWN    3   /* func_020596D8(a) == 0: object
                                          * not known at all, *out == -1 */

/* 0x0200F38C  EXACT*: promoted witness for src/pending/sub_0200F4E4.c
 * (its only call site).  Search func_0203D610()'s func_0203D634()-entry,
 * SYM_FRIEND_TABLE_STRIDE-stride table for a free/matching friend slot
 * for a; *out starts at -1.  See the SYM_FRIEND_SEARCH_* codes above for
 * the return values. */
int func_0200F38C(void *a, int *out);

/* 0x0200F4E4  promoted from src/pending 2026-09-19 (no C change) once
 * func_0200F38C became a matched witness for its call site.  Calls
 * func_0200F38C(o, &out); on SYM_FRIEND_SEARCH_KEY_MATCH copies the
 * matched table entry (SYM_FRIEND_TABLE_STRIDE bytes) over o; on
 * SYM_FRIEND_SEARCH_SCAN_DONE returns 1; otherwise returns 0. */
int func_0200F4E4(void *o);

/* 0x0200F520  install (when flag != 0) src's sub_02008510(sel) data into
 * slot i of obj via sub_02009A00, then release it with func_02045808;
 * always mirrors four sub_020085xx accessor results into obj's fields 9,
 * 0, 1 and 8 for slot i via sub_02009918. */
void sub_0200F520(void *obj, void *src, int i, int sel, int flag);

/* 0x0200F594  fetch obj's slot i via sub_020099C8; when mode != 2, copy
 * a SYM_FRIEND_TABLE_STRIDE-byte record from src into a2; dispatch to
 * sub_0200F520 with flag 1 (mode 0) or flag 0 (mode 1), or neither
 * (mode 2); always mirrors sub_02008554(a1) into field 8 of slot i. */
void sub_0200F594(void *a0, void *a1, void *a2, int a3, void *a4, int mode);

/* 0x0200F5EC  insert one friend record (a2) into the SYM_FRIEND_SLOTS
 * (0x20) entry list rooted at sub_0201283C(a0), mirroring the outcome
 * into the three sub_0200F594 case slots (0 = "not valid yet", the only
 * arm that returns 1; 2 = sub_0200F34C reports equality; 1 = "newer").
 * Rejects immediately (returns 0) when DWC_IsValidFriendData(a2) is 0. */
int func_0200F5EC(void *a0, void *a1, void *a2, void *a3);

/* ------------------------------------------------------------------ *
 * sub_0200E6B4 -- object bring-up, unrelated in shape to the friend-list
 * chain above but contiguous with it: four 8-byte slots starting at
 * obj+8, each tagged with its index 0..3 via func_020242D8.
 * ------------------------------------------------------------------ */

/* 0x0200E6B4  func_02024344(obj); then func_020242D8 on obj's four 8-byte
 * slots at +8, +0x10, +0x18, +0x20, tagged 0..3. */
void sub_0200E6B4(void *obj);

/* ------------------------------------------------------------------ *
 * The keyed-record search over a small array (sub_0200E994.c /
 * sub_0200E9DC.c): up to 10 stored 6-byte keys.
 * ------------------------------------------------------------------ */
#define SYM_KEYSCAN_MAX     10    /* sub_0200E994's cap on the stored
                                   * count returned by func_0200E918 */
#define SYM_KEYSCAN_KEYLEN  6     /* sub_0200E994's per-key size, passed to
                                   * func_0203EFC8 */

/* 0x0200E994  EXACT*: 70 compiled bytes fall six short of the disasm.py
 * extent, which hides sub_0200E9DC's four bytes plus alignment filler.
 * Linear search over up to SYM_KEYSCAN_MAX stored SYM_KEYSCAN_KEYLEN-byte
 * keys: func_0200E918(base, 0) gives the (capped) stored count,
 * func_0200E938 copies key i into a stack buffer, func_0203EFC8 (DWC's
 * own key comparator) compares it against key. Returns 1 on the first
 * match, 0 if none match. */
u32 sub_0200E994(void *base, void *key);

/* 0x0200E9DC  a four-byte constant getter with no register-saving
 * prologue, hiding as sub_0200E994's unlabelled follower.  Returns 0x9c. */
u32 sub_0200E9DC(void);

/* 0x0200E9E0  func_0200E904(a0); func_0200DFCC(a0 + SYM_FIELD_LO_OFF - 8)
 * (a0 + 0x5a). */
void func_0200E9E0(void *a0);

/* ------------------------------------------------------------------ *
 * struct Sub0200F16CHdr -- the three-word header sub_0200F16C stamps.
 * ------------------------------------------------------------------ */
struct Sub0200F16CHdr {
    u32 tag;     /* sub_0200F16C: always 2 */
    u32 size;    /* sub_0200F16C: always 4 */
    u32 count;   /* sub_0200F16C: always 1 */
};

/* 0x0200F168  stub, returns 0. */
u32 sub_0200F168(void);

/* 0x0200F16C  stamp {tag=2, size=4, count=1} into *hdr. */
void sub_0200F16C(struct Sub0200F16CHdr *hdr);

/* ------------------------------------------------------------------ *
 * sub_0200F6B8 -- module bring-up for a 0x60-byte-padded global object.
 * ------------------------------------------------------------------ */
struct Sub0200F6B8Obj {
    u8 pad[0x60];    /* sub_0200F6B8: MI_CpuFill8(&obj, 0, 0x64) zeroes 4
                      * bytes beyond this struct's declared size; the
                      * matched source notes only the 0x60-byte pad and the
                      * 0x64 fill length, so the trailing 4 bytes are left
                      * unaccounted rather than guessed into a field. */
};

extern struct Sub0200F6B8Obj sub_0200F6B8_Obj;   /* 0x0214617C, data */

/* 0x0200F6B8  func_0203064C(1, 8, 0x4920); MI_CpuFill8(&sub_0200F6B8_Obj,
 * 0, 0x64). */
void sub_0200F6B8(void);

#endif /* SYMBOL_SAVE_H */
