/*
 * docs/families/shinka_check.h -- shared declarations for the shinka_check.c
 * family (evolution checks) and the pokeparty.c / waza_tool.c code that shares
 * its address range.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * Family: 0x0201B2B0..0x0201C314 in the ARM9 image (edges fuzzy by a function
 * or two).  Derived from the matched sources found with
 *   grep -l "address:  0x0201B[2-9A-F]\|address:  0x0201C[0-3]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * THE RANGE IS THREE ORIGINAL FILES, NOT ONE.  This matters when choosing a
 * `tu` range, because a unit may never span two of them:
 *
 *   shinka_check.c   0x0201B2B0..0x0201B818   the evolution checker and its
 *                    data layer (sub_0201B70C..sub_0201B774), plus the three
 *                    table-driven wrappers at 0x0201B7A0/0x0201B7B4/0x0201B7EC
 *                    and the party sweep at 0x0201B818.
 *   pokeparty.c      0x0201B850..0x0201BC3C   the EV/stat gain at 0x0201B850,
 *                    the PP pair 0x0201B920/0x0201B970, the healer
 *                    0x0201B9F0/0x0201BA34 and the two graphics-index pairs
 *                    0x0201BA68/0x0201BABC and 0x0201BB5C/0x0201BBE8.
 *   waza_tool.c      0x0201BD28..0x0201C314   the move-record cache and the
 *                    readers over it.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or a store instruction
 * constrains a field; a name does not.  `ldrsh`/`ldrsb` with a register
 * offset proves a signed field, since Thumb has no immediate-offset form; an
 * equal-width `lsls`/`lsrs` pair proves a bitfield, an unequal one a
 * narrowing cast folded with a shift; a truncation emitted at the CALL rather
 * than at the assignment proves the CALLEE's parameter width, not the local's.
 * Where two matched files disagree, the file whose code actually constrains
 * wins and the losing spelling is recorded beside it as `WAS:`.
 *
 * ------------------------------------------------------------------------
 * THE ONE BIG IDEA: THE PARTY RECORD IS READ THROUGH A SELECTOR
 * ------------------------------------------------------------------------
 * As in poke_tool.c, almost nothing here touches a Pokemon field directly.
 * Every read is a selector call, and the <id> is a party-record id in
 * src/matched/sub_02018DB4.c's space:
 *
 *     func_02017E1C(mon, <id>, 0)     -- read, checked
 *     func_02017E88(mon, <id>, 0)     -- read, raw (used inside a
 *                                        func_02017DBC/func_02017DE4 bracket)
 *     func_02017E40(mon, <id>, v)     -- write
 *
 * func_02017DBC / func_02017DE4 bracket a run of raw reads; that bracket is
 * what selects the E88 form over the E1C form
 * (src/matched/unit_0201BA68.c, src/matched/unit_0201BB5C.c).
 */

#ifndef DOCS_FAMILIES_SHINKA_CHECK_H
#define DOCS_FAMILIES_SHINKA_CHECK_H

typedef unsigned char      u8;
typedef signed char        s8;
typedef unsigned short     u16;
typedef short              s16;
typedef unsigned int       u32;
typedef int                s32;
typedef unsigned long long u64;

/* ---------------------------------------------------------------------------
 * PARTY RECORD IDS USED IN THIS RANGE
 * ---------------------------------------------------------------------------
 * Party-record ids in src/matched/sub_02018DB4.c's id space.  Three of them
 * are parallel runs indexed by move slot, and the sources write the three out
 * as three separate literals rather than deriving them from one base, so a
 * version that inserted a field would move all three independently
 * (src/matched/unit_0201B920.c).
 */
#define PARTY_ID_PID          0x00   /* sub_0201B2B0 gate */
#define PARTY_ID_SPECIES      0x05   /* unit_0201BA68.c, unit_0201B100.c */
#define PARTY_ID_HELD_ITEM    0x06   /* sub_0201B850, sub_0201B2B0 gate */
#define PARTY_ID_EV_LIKE      0x09   /* sub_0201B850 reads and writes it */
#define PARTY_ID_LEVEL        0x14   /* sub_0201B2B0 gate */
#define PARTY_ID_MOVE(slot)   (0x36 + (slot))  /* unit_0201B920.c */
#define PARTY_ID_PP(slot)     (0x3A + (slot))  /* unit_0201B920.c */
#define PARTY_ID_PP_UP(slot)  (0x3E + (slot))  /* unit_0201B920.c */
#define PARTY_ID_IS_EGG       0x4C   /* unit_0201BA68.c, unit_0201BB5C.c */
#define PARTY_ID_GENDER       0x6E   /* unit_0201BA68.c, unit_0201BB5C.c */
#define PARTY_ID_FORM         0x6F   /* unit_0201BA68.c, unit_0201BB5C.c */
#define PARTY_ID_NIBBLES      0x97   /* unit_0201B220.c: counter | flags */
#define PARTY_ID_STATUS       0x9D   /* unit_0201B9F0.c clears it */
#define PARTY_ID_HP_CUR       0xA0   /* unit_0201B9F0.c writes it */
#define PARTY_ID_HP_MAX       0xA1   /* unit_0201B9F0.c reads it */
#define PARTY_ID_OCCUPIED     0xA9   /* unit_0201B9F0.c gates on it */
#define PARTY_ID_SPECIES_2    0xAB   /* sub_0201B850 gate; 0 and 650 exit */
#define PARTY_ID_MET_PLACE    0x96   /* sub_0201B850 */
#define PARTY_ID_BALL_LIKE    0x98   /* sub_0201B850, compared with 11 */

/* Move-slot count, written out as the loop bound 4 (unit_0201B9F0.c) and as
 * the literal 0x3A in sub_0201B774's `for (i = 0x36; i < 0x3A; i++)`
 * (unit_0201B70C.c). */
#define PARTY_MOVE_SLOTS      4
#define PP_FILL_SENTINEL      0x7F   /* unit_0201B9F0.c <-> sub_0201B970 */

/* ---------------------------------------------------------------------------
 * THE EVOLUTION TABLE   (src/matched/unit_0201B70C.c)
 * ---------------------------------------------------------------------------
 * Archive member kind 0x13.  The record is 0x2C bytes: seven six-byte rows and
 * a trailing halfword.  The row layout is readable only because sub_0201B718's
 * three-arm switch selects between the three halfwords of a row.
 *
 * VERSION SENSITIVITY: 7 is the rows-per-species count as the 0x2C record size
 * fixes it.  A build that gave a species an eighth evolution would change the
 * record size and all four of unit_0201B70C.c's functions together.
 */
#define NARC_KIND_EVO         0x13
#define EVO_ROWS              7

struct EvoRow {                      /* 6 bytes; evidenced by sub_0201B718 */
    u16 method;
    u16 param;
    u16 species;
};

struct EvoTable {                    /* 0x2C bytes */
    struct EvoRow rows[EVO_ROWS];
    u16 unk2A;
};

/* ---------------------------------------------------------------------------
 * THE MOVE RECORD AND ITS CACHE   (waza_tool.c)
 * ---------------------------------------------------------------------------
 * Archive member kind 0x15.  Every reader carries its OWN copy of the cache
 * lookup (slot search, "cache full, reuse the last slot" fixup, func_02048F4C
 * load, and the fallback to the single record buffer at 0x02146534 when the
 * cache has not been built).  That duplication is in the source, not an
 * inlining decision: sub_0201BD28 is a real function with eight callers, and
 * the bodies reach the record directly rather than through its 32-case getter
 * (src/matched/unit_0201C1F4.c).
 *
 * The struct below is the union of the four partial views the matched files
 * declare; each file declares only the prefix it needs, so the field names
 * differ between them and only the OFFSETS are adjudicated here.
 */
#define NARC_KIND_WAZA        0x15

struct Waza {
    u8  unk00;          /* getter id 0  (unit_0201BD28.c) */
    u8  unk01;          /* getter id 1 */
    u8  unk02;          /* getter id 2 */
    u8  unk03;          /* getter id 3 */
    u8  unk04;          /* getter id 4; 0x65 answers 0x64 (unit_0201C1F4.c) */
    u8  unk05;          /* getter id 5: base PP (unit_0201C158.c) */
    s8  unk06;          /* getter id 6; signed, per its sign-extending load */
    u8  lo : 4;         /* getter id 9  -- equal shift pair, so a bitfield */
    u8  hi : 4;         /* getter id 8 */
    u16 unk08;          /* getter id 11 */
    u8  unk0A;          /* getter id 12 */
    u8  unk0B;          /* getter id 13; gates sub_0201BF58's pack */
    u8  unk0C;          /* getter id 14 */
    u8  unk0D;          /* getter id 15 */
    u8  unk0E;          /* getter id 7; 6 answers 0 (unit_0201C1F4.c) */
    u8  unk0F;          /* getter id 10 */
    u16 unk10;          /* getter id 28 */
    s8  unk12;          /* getter ids 25 (>0) and 30 (<0) */
    s8  unk13;          /* getter ids 26 (>0) and 31 (<0) */
    u8  unk14;          /* getter id 27 */
    u8  unk15[3];       /* getter ids 16, 19, 22 -- unsigned */
    s8  unk18[3];       /* getter ids 17, 20, 23 -- SIGNED: the register-offset
                         * ldrsb is the only evidence (unit_0201C020.c) */
    u8  unk1B[3];       /* getter ids 18, 21, 24 */
    u8  unk1E[2];
    u32 unk20;          /* the flag word sub_0201BF44 tests a bit of */
};

struct WazaTool {                    /* the cache; gWazaTool points at it */
    struct Waza **recs;
    u16          *vals;              /* 0 means "slot free" */
    s32           count;
};

/* sub_0201BF58 packs three fields into one halfword and hands it back SIGNED.
 * Two details are load-bearing: the halfword is never initialised (when
 * unk0B is zero the function returns whatever the stack slot the prologue's
 * `push {r3, ...}` reserved happens to hold), and the result is read with a
 * register-offset `ldrsh`, which is the only form Thumb has -- so the object
 * is a union of the bitfield triple and an s16, not three variables
 * (src/matched/unit_0201BEB8.c). */
union WazaPacked {
    struct {
        u16 a : 4;
        u16 b : 6;
        u16 c : 6;
    } f;
    s16 v;
};

extern struct WazaTool *gWazaTool;   /* 0x02146530  data */
extern struct Waza      g_02146534;  /* 0x02146534  data */

/* ---------------------------------------------------------------------------
 * THE THREE-BYTE BAND TABLES   (shinka_check.c)
 * ---------------------------------------------------------------------------
 * Three sibling wrappers hand sub_0201B850 a three-byte row of a table.  The
 * stride is 3 (`lsls #1` plus `adds`), and each table is named by exactly one
 * pool word, the wrapper's own.
 *
 *   g_0209E45C   func_0201B7A0  indexed, stride 3      (EXACT)
 *   g_0209E462   func_0201B818  fixed row, party sweep (MATCH-capped, below)
 *   g_0209E465   func_0201B7EC  fixed row, coin flip   (EXACT, wave 14: u64 rand * 2 >> 32)
 *
 * All three resolve as of 2026-09-22.  0x0209E462 is 2-ALIGNED (the 3-byte
 * stride puts that row at +6 into a word) and for a long time every sole-ref
 * sub-kind refused it, because `in_data_section()` accepts only an address
 * the listings emit a datum AT.  It now passes and func_0201B818 is EXACT.
 * The lesson is procedural: `in_data_section()` is answered from the listings
 * and `layout/data_objects.txt`, both of which OTHER lanes regenerate, so a
 * refusal observed early in a run can be stale by the end of it.  Re-run the
 * check before recording any address as permanently unattestable -- this one
 * was measured False and True in the same session.
 */
extern const s8 g_0209E45C[];        /* 0x0209E45C  data  a4 */
extern const s8 g_0209E462[];        /* 0x0209E462  data  a2 */
extern const s8 g_0209E465[];        /* 0x0209E465  data */
extern const u8 g_0209E474[];        /* 0x0209E474  data  a4; one packed byte
                                      * per index, two 4-bit values */

/* ---------------------------------------------------------------------------
 * EXTERNAL PROTOTYPES, WITH EXACT PARAMETER TYPES
 * ---------------------------------------------------------------------------
 * Every one of these is the spelling a byte-exact source in this range uses.
 * Where two matched files spell a parameter differently and nothing in the
 * code distinguishes them (`void *p` vs `void *mon`), the name is arbitrary
 * and only the TYPE is adjudicated.
 */

/* The party-record selectors.  poke_tool.c's, used everywhere here. */
extern u32   func_02017E1C(void *mon, u32 id, u32 v);
extern u32   func_02017E88(void *mon, u32 id, u32 v);
extern void  func_02017E40(void *mon, u32 id, u32 v);
extern u32   func_02017DBC(void *mon);              /* open the raw bracket */
extern void  func_02017DE4(void *mon, u32 save);    /* close it */

/* The party container. */
extern s32   sub_0201AA18(void *party);             /* occupied slot count */
extern void *sub_0201AB28(void *party, s32 i);      /* slot i */
extern void *func_020185F0(void *a);                /* a -> mon */

/* Personal / species data.
 * The three attrs func_02019C90 answers in this range: 0x1F the form block's
 * first index, 0x20 the form count, 0x23 the "not drawn separately" flag
 * (unit_0201BA68.c, unit_0201BB5C.c). */
extern u32   func_02019C90(u16 species, u32 form, u32 attr);

/* func_02020FE4 answers an item's hold effect / kind.  TWO SPELLINGS of the
 * first parameter appear and neither is constrained by a load, because the
 * value is passed in a register either way:
 *   u32 species  (sub_0201B850)      WAS: void *a  (func_0201B7B4)
 * Adjudicated to u32: sub_0201B850 passes a species id and func_0201B7B4
 * passes a cast integer, so nothing is ever dereferenced. */
extern u32   func_02020FE4(u32 id, u32 sel, u32 heap);

/* The archive layer. */
extern void *func_020490F4(u32 kind, u32 heap);
extern void  func_0204932C(void *a, u32 id, void *dest);
extern void  func_02048F4C(void *dest, u32 kind, u32 id);
extern u32   func_020490A8(u32 kind, u32 member);

/* The RNG.  TAKES NO ARGUMENTS -- this is the declaration error that costs a
 * whole function: written `func_0203F0A8(x)` the call still compiles and still
 * emits the same `blx`, but the argument setup shifts every register after it.
 * It is ARM, reached by `blx`, so declare it `arm` in symbols:
 * (src/matched/unit_02011D28.c, src/matched/unit_0201B100.c). */
extern u32   func_0203F0A8(void);                   /* 0x0203F0A8  arm */

/* Misc. */
extern int   func_02013E4C(int a0);                 /* sub_0201B850 */
extern int   func_02011014(int a0);                 /* sub_0201B850 */

/* ---------------------------------------------------------------------------
 * THE FAMILY'S OWN FUNCTIONS
 * ---------------------------------------------------------------------------
 * The evolution table's data layer (src/matched/unit_0201B70C.c). */
extern void *sub_0201B70C(u32 heap);
extern u32   sub_0201B718(void *a, u32 id, u32 row, u32 field);
extern void  sub_0201B764(u32 id, void *dest);
extern u32   sub_0201B774(void *mon, u32 move);     /* knows this move? */

/* The 0x97 nibble readers (src/matched/unit_0201B220.c). */
extern u32   sub_0201B220(void *party);             /* bitmask of slots */
extern u32   sub_0201B25C(void *a);
extern u32   sub_0201B268(void *mon);               /* low nibble set? */
extern u32   sub_0201B280(void *a);
extern u32   sub_0201B28C(void *mon);               /* high set, low clear? */

/* The band-table wrappers (shinka_check.c). */
extern void  func_0201B7A0(void *a0, int a1, int a2, int a3);
extern void  func_0201B7B4(void *a0, u16 a1, int a2, u16 a3);
extern void  func_0201B7EC(void *a0, int a1, int a2);
extern void  func_0201B818(void *a0, int a1, int a2);

/* The EV/stat gain (src/matched/sub_0201B850.c).  Note the table parameter is
 * `const s8 *`: the entries are SIGNED, per the sign-extending load. */
extern void  sub_0201B850(void *mon, const s8 *tbl, int a2, u32 a3);

/* The PP pair (src/matched/unit_0201B920.c and sub_0201B970, still open). */
extern u8    sub_0201B920(void *mon, u32 slot);     /* slot short of PP? */
extern u32   sub_0201B970(void *mon, u32 slot, u32 amount);  /* give PP back */

/* The healer (src/matched/unit_0201B9F0.c). */
extern void  sub_0201B9F0(void *mon);
extern void  sub_0201BA34(void *party);

/* The graphics index, twice over (unit_0201BA68.c, unit_0201BB5C.c). */
extern u32   sub_0201BA68(void *mon);
extern u32   sub_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32   sub_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern u32   sub_0201BBE8(void *mon);

/* waza_tool.c's readers. */
extern u32   sub_0201BD28(u16 id, u32 field);       /* the 32-case getter */
extern u32   sub_0201BDB4(const struct Waza *p, u32 id);
extern u32   sub_0201BEB8(u16 id, u32 bit);         /* flag-bit query */
extern u32   sub_0201BF44(const struct Waza *p, u32 bit);
extern s16   sub_0201BF58(u16 id);                  /* the packed triple */
extern u32   sub_0201C020(u16 id);
extern void  sub_0201C0BC(u16 id, u32 i, s8 *out);
extern u32   sub_0201C1F4(u16 id);                  /* field 4 == 0x65? */
extern u32   sub_0201C284(u16 id);                  /* field 0x0E == 6? */
extern u32   sub_0201C314(void *p);

/* sub_0201C158 is the effective-PP calculation: base PP (field 5) plus
 * base * 20 * ppUp / 100, ppUp clamped to 3, every intermediate truncated to
 * u8.  TWO THINGS THE DECLARATION MUST GET RIGHT, and both cost bytes:
 *
 *   * `ppUp` is UNSIGNED (the clamp compares `bls`) while the product is cast
 *     to `int` before the divide (the call goes to _s32_div_f, not
 *     _u32_div_f).  Written unsigned throughout every concrete byte is still
 *     right and only the helper address differs, which reads as a DIFF.
 *   * the FIRST parameter is WIDE, not u16.  Declared `u16 move` the caller
 *     re-truncates the already-narrow value at the call site and gains a
 *     `lsls`/`lsrs` pair; that is what put sub_0201B970 two bytes over its
 *     126 for a whole wave (found 2026-09-22, see docs/notes/sub_0201B970.c.txt).
 */
extern u8    sub_0201C158(u32 move, u32 ppUp);
extern u32   sub_0201C184(int id);                  /* sparse 4-case switch;
                                                     * `int`, per bgt/blt */
extern u32   sub_0201C1BC(u16 move);
extern u8    sub_0201C1C8(void *p);
extern u16   sub_0201C1D8(void *p);

/* ---------------------------------------------------------------------------
 * THE ONE STANDING BLOCKER IN THIS RANGE
 * ---------------------------------------------------------------------------
 * sub_0201B2B0 (1116 bytes, the evolution checker itself) caps at MATCH no
 * matter how good the C is: the `bl` at 0x0201B360 passes 0x020A7330 to the
 * debug allocator and those bytes spell this file's name, but that address
 * appears in exactly one literal pool image-wide -- the pool word at
 * 0x0201B5D4 INSIDE the function -- and the sixteen bytes in front of the
 * string are a static table rather than a string, so `string` refuses too.
 * It closes only if something else is ever found to load 0x020A7330.
 * See docs/notes/sub_0201B2B0.c.txt for the structural map.
 */

#endif /* DOCS_FAMILIES_SHINKA_CHECK_H */
