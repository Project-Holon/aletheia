/*
 * docs/families/poke_tool.h -- shared declarations for the poke_tool.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * Family: original source file poke_tool.c, 0x020173F0..0x0201A3F4 in the
 * ARM9 image (edges fuzzy by a function or two).  Derived from the 84 matched
 * sources found with
 *   grep -l "address:  0x02017[4-9A-F]\|address:  0x02018\|address:  0x02019\
 *            \|address:  0x0201A[0-3]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or a store instruction
 * constrains a field; a name does not.  `ldrsh` proves s16; a `lsls`/`lsrs`
 * pair of equal width proves a bitfield's width
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); a
 * truncation emitted at the CALL rather than at the assignment proves the
 * CALLEE's parameter width, not the local's.  Where two matched files
 * disagree, the file whose code actually constrains wins and the losing
 * spelling is recorded beside it as `WAS:`.
 *
 * ------------------------------------------------------------------------
 * THE ONE BIG IDEA: EVERYTHING GOES THROUGH A SELECTOR
 * ------------------------------------------------------------------------
 * Almost no function in this family touches a Pokemon field directly.  The
 * record is XOR-masked in memory, so every read is
 *
 *     func_02017E88(p, <id>, 0)      -- or func_02017E1C(p, <id>, 0)
 *
 * and every write is
 *
 *     func_02017E64(p, <id>, v)      -- or func_02017E40(p, <id>, v)
 *
 * The <id> is a member of the field enum below.  The E88/E64 pair and the
 * E1C/E40 pair differ ONLY in which lock helper they use (func_02018D34 /
 * func_02018D8C versus func_02018D10 / func_02018D6C) and are otherwise
 * interchangeable; which one a given caller uses is not free -- it is fixed
 * by the bytes and must be copied from the original, not chosen.
 *
 * That is why a new open function in this family almost always compiles from
 * a handful of accessor calls and nothing else: get the ids and the E88-vs-E1C
 * choice right and the body follows.
 */

#ifndef POKE_TOOL_H
#define POKE_TOOL_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;

/* ===================================================================== *
 * 1.  THE RECORD
 * ===================================================================== *
 *
 * 0xDC bytes total.  Two XOR-masked areas plus a plaintext header.
 *
 *   +0x00  u32  seed        the PID; also the permutation key for the four
 *                           substructs (func_02019C38(p, p->unk00, n))
 *   +0x04  u16  three flag bits and a 13-bit remainder
 *   +0x06  u16  checksum    of the 0x80-byte block area only
 *   +0x08  u8[0x80]         the block area: four 0x20-byte substructs,
 *                           permuted by the seed
 *   +0x88  u8[0x54]         the party area: plaintext stats + mail
 *
 * The size 0xDC is fixed three times over: unit_02017528.c's
 * `MIi_CpuClearFast(0, p, sizeof(struct Sav))`, and unit_02019C7C.c's
 * func_02019CE0 whole-object copy (27 eight-byte ldm/stm pairs plus a word).
 * The eight-byte ldm/stm step also says the record is at least 4-aligned
 * (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md).
 */

/* The three flag bits at +0x04.  Every matched file that tests one spells it
 * as a 1-bit bitfield, never as a mask: the original's `lsls`/`lsrs` pair of
 * width one IS the bitfield shape, and a mask spelling emits movs/ands
 * instead (unit_02018D10.c's header records the cost).
 *
 * WAS: unit_02017D30.c spells the tail `u16 b2 : 14`, because it only ever
 * touches b0 and b1.  unit_02018D10.c, sub_02018DB4.c, sub_02018E34.c and
 * sub_02019308.c all spell it `b2 : 1; b3 : 13` and they WIN: func_02018D34
 * actually WRITES bit 2 and func_02018E34 reads it back as id 0x03, so the
 * three-bit partition is constrained and the two-bit one is merely sufficient
 * for that one file.
 */
struct Mon {
    u32 unk00;              /* +0x00  seed / PID.  unit_02017D30.c passes it
                             *        to func_02019A50 as the party mask key;
                             *        sub_02018E34.c passes it to
                             *        func_02019C38 as the permutation key */
    u16 b0 : 1;             /* +0x04.0  party-area lock.  func_02017D30 sets,
                             *          func_02017D70 clears, func_02018D10
                             *          and func_02018D6C test.  id 0x01 */
    u16 b1 : 1;             /* +0x04.1  block-area lock.  func_02017DBC sets,
                             *          func_02017DE4 clears, func_02018D34
                             *          and func_02018D8C test.  id 0x02 */
    u16 b2 : 1;             /* +0x04.2  sticky "checksum did not match".
                             *          func_02018D34 sets it on a mismatch;
                             *          read back as id 0x03, and it is what
                             *          makes ids 0x05/0x73/0x74/0xAA/0xAB
                             *          answer the placeholder 650/651 */
    u16 b3 : 13;            /* +0x04.3  nothing matched touches these */
    u16 unk06;              /* +0x06  block-area checksum, func_02019A9C over
                             *        unk08[0x80].  unit_02018D10.c.  id 0x04 */
    u8  unk08[0x80];        /* +0x08  the masked block area */
    /* ---- the party area, +0x88..+0xDB.  Plaintext: func_02018DB4 and
     * func_02019308 read and write these directly, with no substruct call.
     * Their twelve ids 0x9D..0xA8 are exactly this run. ---- */
    u32 unk88;              /* +0x88  id 0x9D  (func_02018DB4, func_02019308) */
    u8  unk8C;              /* +0x8C  id 0x9E  level */
    u8  unk8D;              /* +0x8D  id 0x9F */
    u16 unk8E;              /* +0x8E  id 0xA0  current HP  (func_02018A7C) */
    u16 unk90;              /* +0x90  id 0xA1  max HP      (func_02018A7C) */
    u16 unk92;              /* +0x92  id 0xA2  attack      (func_02018A7C) */
    u16 unk94;              /* +0x94  id 0xA3  defence     (func_02018A7C) */
    u16 unk96;              /* +0x96  id 0xA4  speed       (func_02018A7C) */
    u16 unk98;              /* +0x98  id 0xA5  sp. attack  (func_02018A7C) */
    u16 unk9A;              /* +0x9A  id 0xA6  sp. defence (func_02018A7C) */
    struct Mail unk9C;      /* +0x9C  id 0xA7, 0x38 bytes, copied whole
                             *        through sub_02008F3C */
};

/* The mail block at +0x9C.  0x38 bytes, only ever copied whole.
 * sub_02018DB4.c (read, id 0xA7) and sub_02019308.c (write, id 0xA7). */
struct Mail {
    u8 unk00[0x38];
};

/* ===================================================================== *
 * 2.  THE FOUR SUBSTRUCTS OF THE BLOCK AREA
 * ===================================================================== *
 *
 * func_02019C38(p, p->unk00, n) hands back the n-th of four 0x20-byte
 * substructs inside unk08[0x80], permuted by the seed word.  Every block-area
 * id is one field of one of them.  The full id-to-field map lives in the
 * header of src/matched/sub_02018E34.c and is not repeated here; what follows
 * is the structure shape those ids imply.
 */

/* Substruct A (n = 0).  sub_02018E34.c, sub_02019388.c, unit_02019ABC.c
 * (which only needs `species` and so declares a one-field prefix),
 * unit_020188B4.c (which only needs unk1C and so declares an 0x1C-byte pad). */
struct BlockA {
    u16 species;            /* +0x00  id 0x05 (650 when b2), id 0xAB, id 0xA9 */
    u16 item;               /* +0x02  id 0x06, forced 0 above 626 */
    u32 otId;               /* +0x04  id 0x07 */
    u32 exp;                /* +0x08  id 0x08.  func_0201850C's third arg */
    u8  unk0C;              /* +0x0C  id 0x09 */
    u8  unk0D;              /* +0x0D  id 0x0A  ability (121 at id 0xAE) */
    u8  unk0E;              /* +0x0E  id 0x0B */
    u8  unk0F;              /* +0x0F  id 0x0C */
    u8  unk10[6];           /* +0x10  ids 0x0D..0x12, the six EVs.  The writer
                             *        (sub_02019388.c) caps their sum at 510
                             *        and each at 255, with a SIGNED compare */
    u8  unk16[6];           /* +0x16  ids 0x13..0x18 */
    u32 unk1C;              /* +0x1C  ids 0x19..0x35, 29 flag bits */
};

/* Substruct B (n = 1).  sub_02018E34.c, sub_02019388.c, unit_020188B4.c.
 *
 * The six 5-bit fields at +0x10 are the IVs.  They are a bitfield and not a
 * packed word: ids 0x46..0x4B read them one at a time and the reader's id
 * 0xAC repacks all six.  NOTE the asymmetry sub_02019388.c documents: the
 * WRITER's id 0xAC takes them from the packed argument in the order
 * 0,1,2,4,5,3, so field[3] comes from bits 25..29 while the reader's 0xAC is
 * a plain identity.  That permutation is in the game. */
struct BlockB {
    u16 moves[4];           /* +0x00  ids 0x36..0x39 */
    u8  pp[4];              /* +0x08  ids 0x3A..0x3D.  unit_020181A0.c writes
                             *        these from func_0201C158 */
    u8  ppUp[4];            /* +0x0C  ids 0x3E..0x41 */
    u32 iv0 : 5;            /* +0x10.0   id 0x46  HP  */
    u32 iv1 : 5;            /* +0x10.5   id 0x47  attack */
    u32 iv2 : 5;            /* +0x10.10  id 0x48  defence */
    u32 iv3 : 5;            /* +0x10.15  id 0x49  speed */
    u32 iv4 : 5;            /* +0x10.20  id 0x4A  sp. attack */
    u32 iv5 : 5;            /* +0x10.25  id 0x4B  sp. defence */
    u32 iv6 : 1;            /* +0x10.30  id 0x4C / 0xAA  "is an egg" */
    u32 iv7 : 1;            /* +0x10.31  id 0x75  "name is not the default";
                             *           written by func_02019388 from
                             *           func_02019ABC (unit_02019ABC.c) */
    u32 unk14;              /* +0x14  ids 0x4D..0x6C, 32 flag bits */
    u8  f0 : 1;             /* +0x18.0  id 0x6D */
    u8  f1 : 2;             /* +0x18.1  id 0x6E, WRITTEN by the reader from
                             *          func_02017F50 */
    u8  f2 : 5;             /* +0x18.3  id 0x6F  FORM.  The single most-read
                             *          id in the family: every call to
                             *          func_02019C54 pairs it with species */
    u8  unk19;              /* +0x19  id 0x70  nature (func_020185A0,
                             *        func_020185B0 in unit_02018598.c) */
    u16 g0 : 1;             /* +0x1A.0  id 0x71 */
    u16 g1 : 15;            /* +0x1A.1 */
    u32 unk1C;              /* +0x1C  id 0x72 */
};

/* Substruct C (n = 2).  sub_02018E34.c, unit_020188B4.c. */
struct BlockC {
    u16 unk00[11];          /* +0x00  ids 0x73 / 0x74, the nickname.  Copied
                             *        out whole (func_02045924) or as 11
                             *        halfwords (func_0201F41C).  When b2 is
                             *        set the placeholder string id 651 from
                             *        gMsgBank is substituted instead */
    u8  unk16;              /* +0x16  id 0x76 */
    u8  unk17;              /* +0x17  id 0x77  the "origin game" byte that
                             *        func_02017C50 compares against 0x14 */
    u64 unk18;              /* +0x18  ids 0x78..0x8C, 21 flag bits.  The u64
                             *        is what calls _ll_shl (0x0209C074);
                             *        docs/idioms/long-long-aligns-to-four.md */
};

/* Substruct D (n = 3).  sub_02018E34.c. */
struct BlockD {
    u16 unk00[8];           /* +0x00  ids 0x8D / 0x8E, the OT name */
    u8  unk10;              /* +0x10  id 0x8F */
    u8  unk11;              /* +0x11  id 0x90 */
    u8  unk12;              /* +0x12  id 0x91 */
    u8  unk13;              /* +0x13  id 0x92 */
    u8  unk14;              /* +0x14  id 0x93 */
    u8  unk15;              /* +0x15  id 0x94 */
    u16 unk16;              /* +0x16  id 0x95 */
    u16 unk18;              /* +0x18  id 0x96 */
    u8  unk1A;              /* +0x1A  id 0x97 */
    u8  unk1B;              /* +0x1B  id 0x98 */
    u8  h0 : 7;             /* +0x1C.0  id 0x99 */
    u8  h1 : 1;             /* +0x1C.7  id 0x9A */
    u8  unk1D;              /* +0x1D  id 0x9B */
    u16 unk1E;              /* +0x1E  id 0x9C */
};

/* ===================================================================== *
 * 3.  THE FIELD ID ENUM
 * ===================================================================== *
 *
 * The ids the family's OPEN functions are most likely to need, named.  Only
 * ids some matched source actually passes as a literal are listed; the full
 * 0x00..0xB1 map is in sub_02018E34.c's header.  Treat the numbers, not the
 * names, as the evidence.
 */
enum MonField {
    MON_SEED        = 0x00,  /* func_02017C50, func_02017F08, func_02018A08 */
    MON_LOCK_PARTY  = 0x01,
    MON_LOCK_BLOCK  = 0x02,
    MON_BAD_CHECKSUM= 0x03,
    MON_CHECKSUM    = 0x04,
    MON_SPECIES     = 0x05,  /* unit_02018430, unit_0201854C, unit_020188B4,
                              * unit_02019B58, sub_02019ED4, sub_02018A7C */
    MON_ITEM        = 0x06,  /* func_02019DA4, func_02019FD0 (as "id 6") */
    MON_OTID        = 0x07,  /* func_02017EB4 */
    MON_EXP         = 0x08,  /* unit_02018430, func_02019CA0 */
    MON_TYPE        = 0x0A,  /* func_02017C50, func_02018A08 write it */
    MON_EV0         = 0x0D,  /* ..0x12, the six EVs.  sub_02018A7C */
    MON_MOVE0       = 0x36,  /* ..0x39.  unit_0201808C, unit_020181A0,
                              * func_020180FC, func_02018240 */
    MON_PP0         = 0x3A,  /* ..0x3D */
    MON_PPUP0       = 0x3E,  /* ..0x41 */
    MON_IV0         = 0x46,  /* ..0x4B.  unit_02018790, unit_02018820,
                              * sub_02018A7C */
    MON_IS_EGG      = 0x4C,  /* func_02019DA4, func_02019FD0 */
    MON_FORM_CALC   = 0x6E,  /* sub_02017CC8 writes it */
    MON_FORM        = 0x6F,  /* the second-most-read id.  func_020179B8,
                              * func_02017C50, sub_02017CC8, func_02017F08,
                              * unit_02018430, unit_0201854C, unit_020188B4,
                              * sub_02018A7C, func_02019CA0 */
    MON_NATURE      = 0x70,  /* unit_02018598, func_020189D8 */
    MON_UNK71       = 0x71,  /* func_02017C50, func_02018A08 */
    MON_NICKNAME    = 0x74,  /* unit_02019B58 writes it */
    MON_MAIL        = 0xA7,
    MON_LEVEL       = 0x9E,  /* unit_0201854C, sub_02018A7C, func_02019DA4,
                              * func_02019FD0, sub_02019ED4, func_0201A2A8 */
    MON_EXISTS      = 0xA9,  /* func_0201A2A8, func_0201A30C */
    MON_MAXHP       = 0xA1,  /* sub_02018A7C; 0xA0 is current HP */
    MON_CURHP       = 0xA0
};

/* ===================================================================== *
 * 4.  THE ACCESSOR / LOCK API -- the core of the family
 * ===================================================================== */

/* --- the four lock helpers, unit_02018D10.c (all EXACT) --- */
extern u32  func_02018D10(struct Mon *p);   /* take the PARTY lock; returns 1
                                             * on success, 0 on a checksum
                                             * failure */
extern u32  func_02018D34(struct Mon *p);   /* take the BLOCK lock, same */
extern void func_02018D6C(struct Mon *p);   /* release the party lock */
extern void func_02018D8C(struct Mon *p);   /* release the block lock */

/* --- the older lock pair, unit_02017D30.c.  These RETURN whether they
 * actually took the lock, and that flag is what the release takes back.
 * The sandwich `f = func_02017D30(p); ...; func_02017D70(p, f);` is the
 * single most common shape in the family. --- */
extern u32  func_02017D30(struct Mon *p);            /* party lock */
extern u32  func_02017D70(struct Mon *p, u32 flag);  /* party release */
extern u32  func_02017DBC(struct Mon *p);            /* block lock */
extern u32  func_02017DE4(struct Mon *p, u32 flag);  /* block release */

/* --- the four public accessors.  ALL FOUR take (p, id, v) and ALL FOUR
 * return u32 or void as spelled.  The third argument is the value for a
 * setter and an out-pointer (or an ignored 0) for a getter. --- */
extern u32  func_02017E1C(void *p, u32 id, u32 v);  /* get, party lock */
extern void func_02017E40(void *p, u32 id, u32 v);  /* set, party lock */
extern void func_02017E64(void *p, u32 id, u32 v);  /* set, block lock */
extern u32  func_02017E88(void *p, u32 id, u32 v);  /* get, block lock */

/* --- the four dispatchers behind them.  Never called directly by anything
 * outside unit_02017E1C/E40/E64.c. --- */
extern u32  func_02018DB4(struct Mon *p, u32 id, u32 v); /* get, party area,
                                                          * ids 0x9D..0xA8,
                                                          * else tail-calls
                                                          * func_02018E34 */
extern u32  func_02018E34(struct Mon *p, u32 id, u32 v); /* get, block area,
                                                          * 176 cases */
extern void func_02019308(struct Mon *p, u32 id, u32 v); /* set, party area */
extern void func_02019388(struct Mon *p, u32 id, u32 v); /* set, block area,
                                                          * 178 cases */

/* --- the substruct permutation, src/pending/sub_02019C38.c (MATCH-capped on
 * its private table) --- */
extern void *func_02019C38(struct Mon *p, u32 seed, u32 n);

/* ===================================================================== *
 * 5.  THE MASK / CHECKSUM PRIMITIVES -- unit_02019A50.c
 * ===================================================================== *
 *
 * func_02019A50 is an involution: masking the same area twice with the same
 * seed is the identity, which is what lets the lock helpers mask on the way
 * in and on the way out.  The seed is passed BY VALUE and stepped through its
 * own home slot, which is why func_02019A50 opens `push {r0,r1,r2,r3}`
 * (docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md).
 */
extern void func_02019A50(void *p, u32 size, u32 seed);
extern u16  func_02019A7C(u32 *state);   /* one LCG step,
                                          * s = s*0x41C64E6D + 0x6073 */
extern u16  func_02019A9C(const void *p, u32 size);  /* halfword sum */

/* ===================================================================== *
 * 6.  THE SPECIES/FORM TABLE API
 * ===================================================================== *
 *
 * func_02019C54(species, form) is a ONE-ENTRY MEMO over the pair, backed by
 * g_02146270 (unit_02019C54.c): it returns a 0x10-byte record rebuilt through
 * sub_0201ADA4 only when the key changes.  func_0201AE1C(h, k) reads field k
 * out of that record, and func_02019C90 is the two composed.
 *
 * Note the parameter-width disagreement, which is REAL and load bearing:
 *   unit_02019C7C.c, unit_02018A00.c, unit_0201850C.c, unit_020185F0.c all
 *   spell it `void *func_02019C54(u16 a, u16 b)` and WIN, because their
 *   callers emit the `lsls #0x10 / lsrs #0x10` pair AT THE CALL.
 *   WAS: unit_02017E64.c spells the second parameter u16 and the first u32;
 *        sub_02017CC8.c spells it `u32 func_02019C54(void *a0, u16 a1)`.
 *        Neither file dereferences the result, so neither constrains a1.
 * sub_02018A7C.c goes further and spells the RESULT `const u8 *`, because it
 * indexes base[0..5] as the six base stats -- that is the only matched file
 * that dereferences it, so it wins on the return type.
 */
extern void *func_02019C54(u16 species, u16 form);
extern u32   func_0201AE1C(void *rec, u32 field);   /* field 0x14 = the
                                                     * evolution/stage byte,
                                                     * 0x17 = growth rate,
                                                     * 0x1B/0x1C = type flags */
extern u32   func_02019C90(u16 species, u16 form, u32 field);
extern u32   func_02019C7C(void *rec);   /* 2 when field 0x1B is set, else 1 */
extern u32   func_0201AF6C(u32 n);       /* "is this stage terminal" */

/* ===================================================================== *
 * 7.  DERIVED QUERIES ALREADY PROVED IN THIS FAMILY
 * ===================================================================== */
extern u32  func_0201850C(u16 species, u16 form, u32 exp); /* exp -> level.
                                                            * unit_0201850C.c */
extern u32  func_02018430(void *p);      /* the same on a record */
extern u32  func_02018438(void *p);
extern u32  func_02018584(u16 species, u16 form, u16 level); /* unit_0201854C */
extern u32  func_0201854C(void *p);
extern u32  func_020185A0(void *p);      /* nature, id 0x70 */
extern void func_020185B0(void *p, u32 v);
extern u32  func_02018598(void *p);      /* nature again, as a thunk.  Its
                                          * result MUST be bound to a named
                                          * local before being passed to
                                          * func_02019B04 -- see
                                          * sub_02018A7C.c's header and
                                          * docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md */
extern u32  func_02019B04(u32 nature, u32 stat, u32 n);  /* nature multiplier,
                                                          * +/-10%.  n is
                                                          * 1,2,5,3,4 for the
                                                          * five non-HP stats
                                                          * -- the table's own
                                                          * order differs from
                                                          * the base stats' */
extern u32  func_02018790(void *p);      /* Hidden Power type.  MATCH-capped */
extern u32  func_02018820(void *p);      /* Hidden Power power.  EXACT */
extern void func_02018A7C(void *p);      /* recompute all six stats */
extern void func_020185C4(void *p);      /* refresh level then stats.  The
                                          * canonical "something changed"
                                          * call: every setter wrapper in the
                                          * family ends with it */
extern u32  func_02017F50(u32 species, u16 form, u32 seed);  /* gender/form */
extern u32  func_02017FB0(void *p);
extern u32  func_02019BBC(u32 item);     /* plate item -> type, unit_02019B58 */
extern u32  func_0201C158(u16 move, u8 ppUp);  /* move + ppUp -> max PP */
extern u32  func_0201BD28(u32 move, u32 n);    /* func_020180FC */

/* move-slot writers, unit_020181A0.c */
extern void func_020181A0(void *p);                          /* refill all PP */
extern void func_020181FC(void *p, u16 move, u32 slot);      /* write one slot */
extern void func_020182A8(void *p, u16 move, u32 slot);      /* the twin
                                                              * func_02018240
                                                              * calls; OPEN */

/* ===================================================================== *
 * 8.  EXTERNALS OUTSIDE THE FAMILY
 * ===================================================================== */
extern void  sub_02008F3C(const struct Mail *src, struct Mail *dest);
extern void  MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void  MI_CpuFill8(void *dst, u8 v, u32 n);
extern void  func_0201F41C(const void *src, void *dest, u32 n);
extern u32   func_0201F448(const void *a, const void *b);
extern void  func_02045924(void *dest, const void *src);
extern void  func_02045CAC(void *bank, u32 id, void *dest);
extern void  func_02045F5C(void *bank, u32 id, void *dest, u32 n);
extern void  func_02048F4C(void *dest, u32 kind, u32 a);
extern u32   func_0200AE54(void *ctx, u32 k);           /* rule-set query */
extern u32   func_0200AFD4(void *ctx, u32 k, u32 v);    /* rule-set test */
extern u32   func_0201AA18(void *party);                /* party count */
extern void *func_0201AB28(void *party, u32 i);         /* party member i */

/* the compiler's own helpers, all ARM, declared `arm` in symbols: */
extern u32 _s32_div_f;   /* 0x0209C0A4 */
extern u32 _u32_div_f;   /* 0x0209C2B0 */
extern u32 _ll_shl;      /* 0x0209C074 */

/* ===================================================================== *
 * 9.  PINNED DATA OBJECTS
 * ===================================================================== *
 * Every one of these is a `data` line in some matched file's symbols: block.
 * The three tables marked CAPPED have exactly one pool word naming them in
 * the whole image, the one under test, so the `literal` class discards its
 * only witness and the function that reads them cannot rise above MATCH
 * however it is written (docs/idioms/a-string-after-a-data-table-has-no-witness.md).
 */
extern void *gMsgBank;            /* 0x020A7370  unit_02019ABC, unit_02019B58,
                                   *             sub_02018E34 */
extern u16   gNameBuf[];          /* 0x021462F0  0x20 halfwords */
extern u32   gWordBuf[];          /* 0x02146398  unit_0201850C, unit_02019B58 */
extern const s8 func_02019B04_Table[][5];  /* 0x0209E324  the nature table.
                                            * NOT capped: sub_02019B44.c's
                                            * pool word and unit_02019B04.c's
                                            * witness each other */
extern const u8 func_02018790_Table[];     /* 0x0209E288  CAPPED */
/* 0x0209E2A4  s8[][5], read by func_020189F0            CAPPED */
/* 0x0209E280, 0x0209E42C  halfword tables, func_02019D58/func_02019D84 CAPPED */
/* 0x0209E3A4  read by func_02019C38                     CAPPED */

/* ===================================================================== *
 * 10.  VERSION SENSITIVITY (read before porting to Pokemon White)
 * ===================================================================== *
 * Content constants, as opposed to structure offsets, that appear in this
 * family.  All are expected to be identical in IRAO because Black and White
 * share species/item/ability numbering, but they are what to re-read first:
 *   650, 651   the placeholder species and its string id (sub_02018E34)
 *   626        the item ceiling at id 0x06 (sub_02018E34)
 *   493, 121   the species and ability selecting the item-derived type
 *   29, 32     the two species special-cased at id 0xAD
 *   292        the species whose HP is forced to 1 (sub_02018A7C)
 *   0x12A..0x139  sixteen plate item ids (func_02019BBC)
 *   0x28A      the species short-circuited in func_020188E0/func_02018948
 *              and func_02019D30
 * gMsgBank, gNameBuf and gWordBuf are globals, so their ADDRESSES are build
 * properties and must be re-derived, never copied.
 */

#endif /* POKE_TOOL_H */
