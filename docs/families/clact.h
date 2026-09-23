/*
 * docs/families/clact.h -- shared declarations for the clact.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and `match.py` never sees it.  It is the adjudicated
 * union of the declarations that the family's byte-exact sources already
 * carry, written down once so a new attempt on an open function starts from
 * the settled shape instead of re-deriving it.
 *
 * Family: original source file clact.c, 0x0204A48C..0x0204E0D0 in the ARM9
 * image (edges inferred from the __FILE__ anchor s_clact_c @ 0x020A7F74).
 * Derived from the 194 matched sources found with
 *   grep -l "address:  0x0204[A-E]" src/matched/*.c
 * restricted to that range.  Each field carries the matched function that
 * evidences it.  Where two matched files disagreed, the file whose code
 * actually constrains the field wins, and the losing spelling is recorded
 * beside it as `WAS:` so the adjudication is auditable.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load instruction constrains a field
 * and a name does not.  `ldrsh` proves s16 (there is no immediate-offset
 * ldrsh, see docs/idioms/ldrsh-register-offset-is-signedness.md); `ldrh`
 * proves 16-bit but not signedness; a shift pair proves a bitfield's width.
 * A file that only passes a pointer through constrains nothing, so its
 * `void *` spelling never outranks a file that dereferences.
 *
 * NOTE ON THE +0x60 FLAG WORD.  Fourteen matched files partition it
 * differently.  Only three claims are made by every file that touches the
 * relevant bits, and only those are asserted below; the rest are listed as
 * unsettled.  Do not treat the full bitfield struct as evidence.
 */

#ifndef CLACT_H
#define CLACT_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;
typedef long long      s64;

struct ClActor;
struct ClBank;
struct ClSub;
struct ClRes;

/* ------------------------------------------------------------------ */
/* The singleton at 0x02146A74.  Total size 0x124, evidenced by        */
/* sub_0204A48C's own sizeof() in the sub_02030734 allocation.         */
/*                                                                     */
/*   +0x000  two OAM sub-records (struct ClSub w[2]) -- sub_0204A5AC   */
/*           passes g+0 to func_0204BCD8, func_0204BCF4 walks the pair */
/*   +0x040  bank default block -- sub_0204B270 stores g+0x40 into a   */
/*           bank's +0x08, sub_0204A5AC finalises it via func_0204BE28 */
/*   +0x0e0  entry pool (struct ClPool) -- func_0204C83C takes         */
/*           &g->pool, func_0204C660 constructs it, func_0204C6E4      */
/*           destroys it                                              */
/*   +0x0ec  latch -- func_0204A600/func_0204A648 test it before       */
/*           releasing the +0xe0 sub-object                           */
/*   +0x0f0  u16 pair -- func_0204BA7C writes both halves separately,  */
/*           which is what settles them as two u16 and not one u32.    */
/*           WAS: sub_0204A48C spells it `u16 unk_f0[2]` and clears it */
/*           with a 2-iteration loop; that is the same two halfwords   */
/*           and the array spelling is what its loop needs.            */
/*   +0x0f8  enable latch A -- func_0204BAEC writes, func_0204BB04     */
/*           reads                                                    */
/*   +0x0fc  enable latch B -- func_0204BB20 writes, func_0204BB38     */
/*           reads                                                    */
/*   +0x100  head of the circular bank ring -- func_0204BB8C,          */
/*           func_0204BBC8, func_0204BC40                              */
/*   +0x104  resource block (struct ClRes) -- func_0204D7E0 builds it, */
/*           func_0204D8AC tears it down                               */
/* ------------------------------------------------------------------ */
struct ClSys {
    u8              pad_000[0x40];  /* ClSub w[2] -- func_0204BCF4      */
    u8              bank_default[0xa0];             /* sub_0204B270     */
    u8              pool[0x0c];     /* ClPool @ +0xe0 -- func_0204C660  */
    u32             latch_0ec;      /* func_0204A648, func_0204A600     */
    u16             unk_0f0;        /* func_0204BA7C, func_0204BFC4     */
    u16             unk_0f2;        /* func_0204BA7C, func_0204BFF4     */
    u32             unk_0f4;        /* func_0204BA7C, func_0204BFC4     */
    u32             enable_a;       /* func_0204BAEC / func_0204BB04    */
    u32             enable_b;       /* func_0204BB20 / func_0204BB38    */
    struct ClBank  *ring_head;      /* func_0204BB8C, func_0204BBC8     */
    struct ClRes    res;            /* +0x104, func_0204D7E0            */
};

/*
 * The resource block at ClSys+0x104.  0x20 bytes.
 *
 * Three matched files name the three count halfwords differently.
 * func_0204D7E0 WINS: it writes all six counts in one run from the
 * caller's `u16 dims[6]`, so the six-halfword shape at +0x14..+0x1f is
 * constrained by its store sequence, not merely named.
 *   WAS: sub_0204AC18 spells +0x14/+0x16 `volatile u16 count/count2`.
 *        Its volatile is a codegen device (it needs the count re-read on
 *        the loop's back edge) and is NOT a claim about the type.
 *   WAS: sub_0204AF28 / func_0204E074 put the 0x14-stride table pointer
 *        at +0x10 and a volatile count at +0x18.  Same words, same
 *        widths; only the names differ.
 */
/*
 * READING ClRes THROUGH THE SINGLETON: the +0x104 base must be a LIVE LOCAL.
 * PROVED 2026-09-22 by src/matched/func_0204ACEC.c.  A function that reads
 * both ClRes.cell (+0x10c absolute) and one of the count halfwords
 * (+0x118..+0x123 absolute) wants the image's shared base:
 *     add rB, rG, #0x104 ; ldrh rN, [rB, #0x16] ; ldr rA, [rB, #0xc]
 * mwcc 1.1p1 does NOT produce that from a nested sub-struct, from a cast, or
 * from `&g->res`: all three fold to base 0x100 for the ldrh (offset 0x1a is
 * inside its 8-bit immediate) and reach the array straight off the global at
 * +0x110 (inside the ldr 12-bit immediate).  Only a named local
 * `struct ClRes *r = &g->res;` emits the 0x104 add.
 *
 * AND IT MUST BE PAIRED WITH `volatile` ON THE COUNT.  The local pointer also
 * hoists a loop bound out of the loop, dropping the image's back-edge count
 * re-read; `volatile u16` on the count halfword restores it.  Each lever
 * alone is a regression (109 bytes out, or four bytes long); the pair is
 * byte-exact.  The volatile is a codegen device, NOT a claim about the type,
 * exactly as sub_0204AC18's own note says of its count fields.
 */
struct ClRes {
    void *tiles;            /* +0x00  func_0204D7E0, func_0204D8AC      */
    void *palettes;         /* +0x04  func_0204D7E0, func_0204D8AC      */
    void *cell;             /* +0x08  func_0204D7E0; func_0204E0D0 and
                             *        sub_0204AC18 index it at 0x40     */
    void *anim;             /* +0x0c  func_0204D7E0; 0x18 stride        */
    void *pattern;          /* +0x10  func_0204D7E0; 0x14 stride        */
    u16   n_cell;           /* +0x14  func_0204D7E0, func_0204D8AC      */
    u16   n_anim;           /* +0x16  func_0204D7E0, func_0204D8AC      */
    u16   n_pattern;        /* +0x18  func_0204D7E0, func_0204D8AC      */
    u16   n_unk_06;         /* +0x1a  func_0204D7E0                     */
    u16   n_tiles;          /* +0x1c  func_0204D7E0                     */
    u16   n_palettes;       /* +0x1e  func_0204D7E0                     */
};

/*
 * The cell actor.  0xE4 bytes: sub_0204B100 allocates count*0xe4 and
 * sub_0204CAE4 fills 0xe4 bytes, which is what fixes the size.
 *
 * COORDINATE PAIR AT +0x0c.  func_0204CC6C WINS with s16: it loads the
 * pair with `ldrsh`, and an immediate-offset ldrsh does not exist, so the
 * sign extension can only come from the declared type.
 *   WAS: sub_0204B528 / sub_0204B53C / sub_0204B550 / sub_0204B560 spell
 *        the same four halfwords u16.  Those four files only move the
 *        values through `ldrh`/`strh`, which cannot tell the widths apart,
 *        so they do not constrain the sign.
 *
 * THE SUB-OBJECT AT +0x40.  sub_0204B728 and unit_0204B764 WIN at 20
 * bytes (five words): sub_0204B728 declares `u32 w[5]` and copies all
 * five, so the extent is constrained by its store run.
 *   WAS: func_0204CB44 spells it 0x20 bytes -- it only takes the address
 *        and passes it on, which constrains nothing.
 *   WAS: sub_0204CAE4 spells it 0x14, which agrees (0x14 == 20).
 *
 * THE SUB-OBJECT AT +0x68.  0x7c bytes, fixed by the MI_CpuFill8(p,0,0x7c)
 * in sub_0204D104, sub_0204D2DC and sub_0204D300.
 *   WAS: func_0204CC6C reads +0x68 as a plain u32 switch selector.  That
 *        is the first word of the sub-object (its `kind`), not a rival
 *        layout -- sub_0204D0C4 and func_0204D324 dispatch on the same
 *        word.  Both spellings are correct at different granularities.
 */
struct ClActor {
    void           *res_handle;     /* +0x00  sub_0204B1CC liveness test */
    u8              pad_004[4];
    void           *owner;          /* +0x08  sub_0204B3B4, sub_0204CFDC */
    s16             x;              /* +0x0c  func_0204CC6C (ldrsh)      */
    s16             y;              /* +0x0e  func_0204CC6C (ldrsh)      */
    s16             unk_10;         /* +0x10  func_0204CC6C (ldrsh)      */
    s16             unk_12;         /* +0x12  func_0204CC6C (ldrsh)      */
    u32             scale_x;        /* +0x14  unit_0204B59C, init 0x1000 */
    u32             scale_y;        /* +0x18  unit_0204B59C, init 0x1000 */
    u8              unk_1c[0x24];   /* +0x1c  sub_0204CAE4 (sub_02063790)*/
    u32             xform[5];       /* +0x40  sub_0204B728, 20 bytes     */
    u32             scale_z;        /* +0x54  func_0204B954, init 0x1000 */
    u16             unk_58;         /* +0x58  unit_0204B5F4; func_0204CC6C
                                     *        reads it >>4 as a rotation
                                     *        index                      */
    u16             unk_5a;         /* +0x5a  sub_0204B878 / unit_0204B898*/
    u16             unk_5c;         /* +0x5c  func_0204B7F0, sub_0204CF40 */
    u16             unk_5e;         /* +0x5e  func_0204B7F8, sub_0204CF40 */
    u32             flags;          /* +0x60  see the bitfield note below */
    u32             flags2;         /* +0x64  bit 0 = hidden, func_0204BA20*/
    u8              anim[0x7c];     /* +0x68  0x7c bytes, sub_0204D104    */
    /* +0xe4 total -- sub_0204B100 allocates count * 0xe4 */
};

/*
 * THE +0x60 FLAG WORD -- WHAT IS ACTUALLY SETTLED.
 *
 * Fourteen matched files partition this word and they do not agree.  Only
 * the three claims below are made by every file that reads the bits in
 * question, so only these three are safe to build on:
 *
 *   bits  8..11  a 4-bit field   -- func_0204B604, sub_0204B658,
 *                                   unit_0204B688, func_0204CBB0,
 *                                   sub_0204CAE4 all agree
 *   bits 18..19  a 2-bit field   -- func_0204CC6C, unit_0204B570,
 *                                   func_0204CBB0, sub_0204CAE4 agree
 *   bits 22..23  a 2-bit field   -- unit_0204B688, func_0204CBB0 agree
 *
 * UNSETTLED, do not rely on:
 *   - the "enabled" bit.  unit_0204B92C and sub_0204CEB4 place it at bit
 *     25; unit_0204B3DC and func_0204CB44 place it at bit 26.  Both pairs
 *     are byte-exact, so the word carries two different single-bit flags
 *     and the name "enabled" has been attached to each of them.  Read the
 *     bit number off the original, never off a sibling's name.
 *   - bits 12..17.  func_0204B604's 6-bit field vs func_0204CB44 and
 *     unit_0204B6F4's 4-bit field at 12..15.  Both compile exact because
 *     neither writes the bits the other claims.
 *   - bits 24..31.  unit_0204B9C4 puts a 4-bit "mode" at 27..30 inside
 *     what func_0204B604 calls one 8-bit field.
 *
 * The practical consequence for an open function: spell only the bits the
 * function you are matching actually touches, and pad the rest.  A full
 * partition copied from a sibling will be wrong for some other function's
 * bits and the extra fields cost nothing only when they are never read.
 */

/* ------------------------------------------------------------------ */
/* The bank: 0x18-byte header, allocated with its actor array by       */
/* sub_0204B100.                                                       */
/*                                                                     */
/* THE BYTE AT +0x0f.  func_0204BBC8 WINS: it is the ring's insertion   */
/* sort key and func_0204BBC8 compares it, which constrains it.        */
/*   WAS: sub_0204B100 calls it `unk_0f` (just the caller's flag        */
/*        stored through) and sub_0204B270 / unit_0204B22C start a      */
/*        pad run at +0x0f.  Neither reads it back.                    */
/* ------------------------------------------------------------------ */
struct ClBank {
    struct ClActor *actors;         /* +0x00  sub_0204B100, sub_0204B1CC */
    u8              pad_004[4];
    void           *unk_08;         /* +0x08  sub_0204B270 sets it to
                                     *        &g_02146A74->bank_default  */
    u16             count;          /* +0x0c  sub_0204B100, sub_0204B1CC */
    u8              kind;           /* +0x0e  low nibble = source
                                     *        (0 default, 1 caller),
                                     *        high nibble = mode;
                                     *        sub_0204B270, unit_0204B22C */
    u8              prio;           /* +0x0f  func_0204BBC8 sort key      */
    struct ClBank  *next;           /* +0x10  func_0204BBC8, func_0204BC40*/
    struct ClBank  *prev;           /* +0x14  func_0204BBC8, func_0204BC40*/
};

/* The OAM sub-record.  0x20 bytes, two per actor at ClSys+0x00. */
struct ClSub {
    u8  pad_00[0x1c];
    u32 bound;                      /* +0x1c  func_0204BD3C reads it raw  */
};

/* ------------------------------------------------------------------ */
/* The entry pool at ClSys+0xe0, and its 0x10-byte entries.            */
/*                                                                     */
/* THE FOURTH WORD OF AN ENTRY.  func_0204C8A4 and func_0204C8B8 name   */
/* it `sel` and `kind` respectively; both only compare it against small */
/* constants, so nothing constrains the name.  Either spelling matches. */
/* ------------------------------------------------------------------ */
struct ClPool {
    void *recs;                     /* +0x00  0x30 stride, func_0204C660  */
    void *ents;                     /* +0x04  0x10 stride, func_0204C718  */
    u32   count;                    /* +0x08  func_0204C660, func_0204C804*/
    u32   ready;                    /* +0x0c  func_0204C660, func_0204C6E4*/
};

struct ClEntry {
    u32 live;                       /* +0x00  func_0204C804 liveness      */
    u32 unk_04;                     /* +0x04  func_0204C8A4               */
    u32 size;                       /* +0x08  func_0204C8A4, func_0204C8B8*/
    u32 kind;                       /* +0x0c  func_0204C8A4 (`sel`)       */
};

/* ------------------------------------------------------------------ */
/* The three record tables reachable through ClRes.                    */
/*                                                                     */
/* RecC, 0x40 bytes, ClRes.cell.  The stride is fixed by the `<< 6`    */
/* index scaling in func_0204A9D0, func_0204AA94, func_0204AB84,       */
/* func_0204D8AC and func_0204E0D0.                                    */
/*                                                                     */
/* THE STATUS WORD AT +0x3c.  The 1/30/1 split WINS.  func_0204DACC is */
/* decisive: it rebuilds the word as                                   */
/*     (w & 0x80000001) | ((key << 2) >> 1)                            */
/* preserving bit 0 and bit 31 and overwriting bits 1..30, which is    */
/* exactly the three-field split and cannot be read as anything else.  */
/*   WAS: func_0204DA5C spells it 31/1, with no bit-0 field.  It never */
/*        writes bit 0, so its spelling is compatible but weaker.      */
/*   WAS: func_0204E0D0 and sub_0204AC18 keep it a plain u32 and mask  */
/*        by hand (`&= ~0x80000000`, `>> 31`).  Also compatible.       */
/*                                                                     */
/* Bit 31 is the free/busy flag: the scan in the open func_0204A6C8    */
/* tests `>> 31` and func_0204E0D0 clears it with `& ~0x80000000`.     */
/* ------------------------------------------------------------------ */
struct ClRecC {
    u8   pad_00[0x24];
    void *payload;                  /* +0x24  sub_0204A8D4                */
    u32  sink;                      /* +0x28  sub_0204A8D4, func_0204DACC */
    u32  desc_a[2];                 /* +0x2c  func_0204DA5C sentinel pair */
    u32  desc_b[2];                 /* +0x34  func_0204DA5C sentinel pair */
    u32  status;                    /* +0x3c  bit0 | bits1-30 | bit31     */
};

/* RecA, 0x18 bytes, ClRes.anim.  The stride is a real `mul` by 0x18,
 * not a shift -- sub_0204ADA4, sub_0204ADEC, func_0204DCA8. */
struct ClRecA {
    u32 w[5];                       /* +0x00  unit_0204AEC0 copies all 5  */
    u32 status;                     /* +0x14  bit 31 is the flag;
                                     *        sub_0204ADA4, func_0204DCA8 */
};

/*
 * RecB, 0x14 bytes, ClRes.pattern.
 *
 * Two matched spellings name different slots and BOTH are byte-exact,
 * because no single matched function reads all five words:
 *   sub_0204AFD8 / sub_0204AF28 / func_0204E074 -> {ptr@0, ptr@4, ..,
 *                                                   u32 free@0x10}
 *   sub_0204B294 / func_0204B324               -> {.., u32@8, u32@0xc, ..}
 * The union below is the safe reading: +0x00 and +0x04 are pointers
 * (func_0204E074 dereferences them), +0x08 and +0x0c are plain words,
 * and +0x10 is the free flag (1 == free: sub_0204AFD8 sets it,
 * func_0204E074 clears it, func_0204D8AC tests it against 0).
 */
struct ClRecB {
    void *unk_00;                   /* +0x00  sub_0204AF28, func_0204E074 */
    void *unk_04;                   /* +0x04  sub_0204AF28                */
    u32   unk_08;                   /* +0x08  sub_0204B294, func_0204B324 */
    u32   unk_0c;                   /* +0x0c  sub_0204B294, func_0204B324 */
    u32   free;                     /* +0x10  1 == free, sub_0204AFD8     */
};

/* ------------------------------------------------------------------ */
/* Globals.                                                            */
/* ------------------------------------------------------------------ */

/* The singleton.  Every matched file in the family reaches it through a
 * pool word; the compiler cannot see through the extern, so it is re-read
 * after every call that might store to it (sub_0204A5AC documents this --
 * it is NOT a volatile). */
extern struct ClSys *g_02146A74;        /* 0x02146A74  data */

/* The __FILE__ anchor every allocation site in clact.c passes to
 * sub_02030734.  Declare it as an extern char[] pinned by address in the
 * symbols: block, never as a literal __FILE__ --
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md. */
extern char s_clact_c[];                /* 0x020A7F74  data */

/* Two u16 tables of four entries, stride 8, indexed by a 2-bit field and
 * selected by the low bit of a second value.  Both are `literal`-attested
 * (x20 witnesses each), so they cost nothing to cite.  func_0204C2C8 is
 * the only reader. */
extern const u16 tbl_020A17D8[4][4];    /* 0x020A17D8  data */
extern const u16 tbl_020A17F0[4][4];    /* 0x020A17F0  data */
/* const is load-bearing (wave 16): without it func_0204C2C8 is 58 bytes
 * of register names out; with it, EXACT. */

/*
 * THE SPRITE EXTENT WORD, ClActor+0x02 (`struct A.f02` in the culling pair).
 * PROVED 2026-09-22 by src/matched/func_0204C214.c reaching EXACT, and
 * already carried by src/matched/func_0204C060.c.  Both culling helpers read
 * the SAME halfword and partition it the same way:
 *
 *   bits  0..5   a 6-bit half-extent, scaled by 4 and then truncated to 8
 *                bits, giving the synthetic square used when bit 11 is clear
 *   bit  11      selects which shape the extents come from: SET means read the
 *                four explicit s16 half-extents at +0x08/+0x0a/+0x0c/+0x0e,
 *                CLEAR means synthesise the square from bits 0..5
 *
 * The test is a COMPARISON WITH 1, `((f02 >> 11) & 1) == 1`, not a truth
 * test: written as `if ((f02 >> 11) & 1)` the compiler emits `tst` and
 * inverts the arms.  The field arm is the FALL-THROUGH and the synthetic arm
 * is the predicated one, which only happens when the 6-bit extraction is
 * hoisted above the `if`.
 *
 * THE EXTRACTION IS NOT FREELY SPELLABLE.  It must narrow the MASK and then
 * shift, in two statements:
 *
 *     s32 m6 = (s32)(u8)(f02 & 0x3f);
 *     s32 e  = (m6 << 2) & 0xff;
 *
 * giving the image's `and #0x3f` / `lsl #2` / `and #0xff`.  Every spelling
 * that narrows the SHIFTED value instead -- `(u8)((f02 & 0x3f) << 2)`,
 * `((f02 & 0x3f) << 2) & 0xff`, the u32 forms, the `* 4` forms, and the
 * two-named-variable form -- lets 1.1p1 prove the field contiguous and fuse
 * it to `lsl #26` + `lsr #24`.  Measured on both functions, six bytes each.
 * This costs a whole slot to rediscover; it is written here so it is not.
 *
 * The camera delta pair is likewise ordered: `dy = b->f10 - c->f00` is
 * declared BEFORE `dx = b->f14 - c->f04` in both files.
 */

/* EVIDENCE-STARVED DATA.  These two have no witness of any class outside
 * the single function that names them, so any function reading them caps
 * at MATCH regardless of how correct the C is.  Recorded here so the next
 * attempt does not spend a slot rediscovering it:
 *   0x020A1388  read only by func_0204BF28 (src/pending/)
 *   0x020A1430  read only by func_0204A7A0 (docs/notes/)
 *   0x020A138C  see docs/notes/clact_c_fan_in_1_blockers.c.txt
 */

/* ------------------------------------------------------------------ */
/* Helper prototypes.                                                  */
/*                                                                     */
/* Outside-family helpers first.  These are spelled identically across  */
/* every matched file that calls them, so they are settled.            */
/* ------------------------------------------------------------------ */

/* The allocator.  The fifth argument is a pooled small constant, which is
 * an R_ARM_ABS32 and not a literal --
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * The fourth is s_clact_c. */
extern void *sub_02030734(u32 heapId, u32 size, int clear,
                          const char *file, u32 line);   /* 0x02030734 arm */
extern void  sub_020307B0(void *p);                      /* 0x020307B0 arm */
extern void  func_02082BCC(void *dst, int fill, u32 size);/* 0x02082BCC arm */

/*
 * In-family helpers.  Where the family's own files disagree on a
 * prototype, the winner below is the spelling whose call site constrains
 * the type; the loser is recorded as WAS:.
 *
 * A caller that passes `void *` constrains nothing, so a definition file's
 * typed spelling always beats a caller's `void *`.  Conversely a caller
 * that passes a NARROWER type than the definition (u8 where the definition
 * says u32) DOES constrain: the narrowing is visible in the call's codegen.
 */

/* Latches and ticks.  func_0204BAEC's argument is u32 in five of six
 * files; func_0204A600's `int` is the outlier and is unconstrained
 * (the only values passed are 0 and 1). */
extern void func_0204BAEC(u32 on);                       /* 0x0204BAEC arm */
extern u32  func_0204BB04(void);                         /* 0x0204BB04 arm */
extern void func_0204BB20(u32 on);                       /* 0x0204BB20 arm */
extern u32  func_0204BB38(void);                         /* 0x0204BB38 arm */
extern void func_0204BB54(void);                         /* 0x0204BB54 arm */
extern void func_0204BB8C(void);                         /* 0x0204BB8C arm */

/* Ring maintenance. */
extern void func_0204BBC8(struct ClBank *bank);          /* 0x0204BBC8 arm */
extern void func_0204BC40(struct ClBank *bank);          /* 0x0204BC40 arm */
extern void func_0204C944(struct ClBank *bank);          /* 0x0204C944 arm */

/* OAM sub-record pair.
 *   WAS: sub_0204A48C spells func_0204BC94 as (void*, u8,u8,u8,u8).  The
 *        definition's (struct ClSub*, u32,u32,u32,u8) wins on the first
 *        three arguments -- sub_0204A48C loads them with ldrb from a u8
 *        config field, which is the narrowing at the CALL, not in the
 *        callee -- and the caller's u8 wins on the fourth. */
extern void func_0204BC94(struct ClSub *sub, u32 base, u32 count,
                          u32 base2, u8 count2);         /* 0x0204BC94 arm */
extern void func_0204BCD8(struct ClSub *sub);            /* 0x0204BCD8 arm */
extern void func_0204BCF4(struct ClSub *sub);            /* 0x0204BCF4 arm */
extern void func_0204BD18(struct ClSub *sub);            /* 0x0204BD18 arm */
extern void func_0204BD64(struct ClSub *sub);            /* 0x0204BD64 arm */
extern void func_0204BD7C(struct ClSub *sub);            /* 0x0204BD7C arm */

/* Pool lifecycle.
 *   WAS: sub_0204A48C spells func_0204C660's second argument u8.  That
 *        narrowing is real at its call site (cfg->unk_0c is a u32 field
 *        but only its low byte is passed), so BOTH spellings are correct
 *        and the u32 definition is the one to declare. */
extern void func_0204C660(struct ClPool *pool, u32 n, u32 heapId);
extern void func_0204C6E4(struct ClPool *pool);          /* 0x0204C6E4 arm */
extern void func_0204C718(struct ClPool *pool, u32 n, u32 heapId);
extern void func_0204C788(struct ClPool *pool);          /* 0x0204C788 arm */
extern void func_0204C7A4(struct ClPool *pool);          /* 0x0204C7A4 arm */
extern struct ClEntry *func_0204C804(struct ClPool *pool);
extern void func_0204C8B8(struct ClEntry *e);            /* 0x0204C8B8 arm */
extern void func_0204C8A4(struct ClEntry *e, u32 sel, u32 a, u32 b, u32 c);

/* Resource block lifecycle.  func_0204D7E0's fourth argument is the
 * caller's `u16 dims[6]`, spelled `struct Caps {u16 cell, anim, pattern,
 * unk_06, tiles, palettes;}` in its own file.  sub_0204A48C passes a
 * stack array of six u16 copied one field at a time -- an aggregate
 * assignment would be an inlined ldm/stm pair and the original spells out
 * six ldrh/strh (docs/idioms/aggregate-assignment-is-ldm-stm.md). */
extern void func_0204D7E0(struct ClRes *res, u32 heapId, u32 arg,
                          const u16 *dims);              /* 0x0204D7E0 arm */
extern void func_0204D8AC(struct ClRes *res);            /* 0x0204D8AC arm */

/* Actor lifecycle. */
extern void sub_0204B3B4(struct ClActor *a);             /* 0x0204B3B4 arm */
extern void func_0204B95C(struct ClActor *a);            /* 0x0204B95C arm */

/*
 * Coordinate accessors.  The whole group takes s16, not u16:
 * sub_0204B560 RETURNS s16 in every file that declares it, and
 * sub_0204B49C's own note shows the value round-tripping through an
 * `asr #16` sign extension.  The u16 spellings in sub_0204B528 /
 * sub_0204B53C are unconstrained pass-throughs.
 */
struct ClPt { s16 x; s16 y; };

extern void sub_0204B528(struct ClActor *a, const struct ClPt *p);
extern void sub_0204B53C(const struct ClActor *a, struct ClPt *out);
extern void sub_0204B550(struct ClActor *a, s16 v, u32 axis);
extern s16  sub_0204B560(const struct ClActor *a, u32 axis);
extern void func_0204CF74(struct ClActor *a, u32 space, struct ClPt *origin);

/* ------------------------------------------------------------------ */
/* Recurring constants.                                                */
/* ------------------------------------------------------------------ */

#define CL_FX_ONE       0x1000      /* the 20.12 unit; the init value of
                                     * ClActor.scale_x/y/z             */
#define CL_FX_SHIFT     12          /* every coordinate reaching the
                                     * culling helpers is << 12        */
#define CL_ACTOR_SIZE   0xe4        /* sub_0204B100, sub_0204CAE4      */
#define CL_ANIM_SIZE    0x7c        /* sub_0204D104, sub_0204D2DC      */
#define CL_SYS_SIZE     0x124       /* sub_0204A48C                    */
#define CL_RECC_STRIDE  0x40        /* index scaling is << 6           */
#define CL_RECA_STRIDE  0x18        /* a real mul, not a shift         */
#define CL_RECB_STRIDE  0x14
#define CL_BUSY_BIT     0x80000000u /* ClRecC.status bit 31            */

/*
 * The fixed-point multiply every culling helper uses, from the byte-exact
 * func_0204C060.  Rounding is +0x800 before the >> 12, and the product is
 * formed in 64 bits.
 */
#define CL_FXMUL(a, b)  ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))


/* ------------------------------------------------------------------ */
/* WAVE 10 (2026-09-22) additions, each proved by an EXACT file.       */
/* ------------------------------------------------------------------ */

/*
 * THE CULL PAIR func_0204C2C8 -> func_0204C3CC.
 * func_0204C3CC (src/matched/func_0204C3CC.c) takes EIGHT arguments:
 *   (s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1,
 *    const struct M *m, const struct C *c)
 * with struct M { s32 f00, f04, f08, f0c, f10, f14; } (2x2 matrix + the
 * translation f10/f14) and struct C the viewport {f00, f04, f08, f0c}.  It
 * transforms the four corners, takes min/max per axis and culls exactly as
 * func_0204C060 does.  Levers: min/max seeded `min = p; max = p;` with the
 * locals declared max-first, and the four `+= d` translations as statements
 * before the && chain.
 *
 * The pool word in func_0204C2C8 is 0xC000C000 (GX_OAM_ATTR01_SHAPE_MASK |
 * GX_OAM_ATTR01_SIZE_MASK), NOT 0x00C000C0 as every older note says; its
 * `asr #22` is ~0xff.  The 0x48-stride element's +0x38 word is a GXOamAttr
 * attr01 union and tbl_020A17F0 / tbl_020A17D8 are the OBJ width / height
 * tables indexed [shape][size].  EXACT since wave 16 once the two tables
 * are declared const (src/matched/func_0204C2C8.c).
 */
extern int  func_0204C3CC(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1,
                          const void *m, const void *c);     /* 0x0204C3CC arm */

/*
 * THE 0x48-STRIDE ELEMENT ARRAY (f98 pointer / f9c count, allocated by
 * func_0204BD94).  Element +0x40 is a cull callback: func_0204BE38(obj, on)
 * installs func_0204C2C8 in every element when on != 0, and clears them and
 * sets obj->f30 = 1 when on == 0 (src/matched/func_0204BE38.c).
 */
extern void func_0204BE38(void *obj, int on);               /* 0x0204BE38 arm */

/*
 * THE ENTRY RECONFIGURE PAIR func_0204DD08 / func_0204DEE8 (both EXACT).
 * Same 0x18-byte entry table at holder+0x0c, same 0x200 large-layer split
 * (size -= 0x200, (u16); flag 1), same double upload bracketed by
 * func_02080C34/func_020801F8 (engine 0) and func_02080C74/func_0208083C
 * (engine 1).  Pins shared by both: `off = idx * sizeof(struct Ent)` as a
 * byte-offset local, the entry re-derived from h->ents at the end.
 *   func_0204DEE8 returns void; its out-locals are declared b-then-a and its
 *   0x200 test is written small-arm-first.
 *   func_0204DD08's materialised `lsl r0, r3, #5` is a 64-bit local
 *   (`unsigned long long ofs = head * 32;`): the one C spelling that keeps a
 *   plain shift as a register temporary without folding it into both
 *   consumers or narrowing it.
 */
extern void func_0204DD08(void *h, int idx, void *src, void *sel, u32 size,
                          u16 head, u16 tail);               /* 0x0204DD08 arm */
extern void func_0204DEE8(void *h, int idx, void *src, void *sel, u32 size);
                                                             /* 0x0204DEE8 arm */

/*
 * WAVE 15 (2026-09-23) additions, each proved by an EXACT file.
 *  - func_0204BF28 takes TWO arguments: (obj, idx), body
 *    `obj->f14 = tbl_020A1388[idx]` (u16 table).  func_0204BE84 passes
 *    a1->f8.  src/matched/func_0204BE84.c.
 *  - const on the read-only source parameter of a field-copy builder
 *    settles the register tie that three notes recorded as allocator
 *    residue: func_0204D18C, func_0204D224, func_0204BE84.  See
 *    docs/idioms/const-on-a-read-only-source-parameter-settles-a-register-tie.md.
 *  - 0x0204D2C8 is an unlabelled leaf: fill(anim, 0, 0x7c) as a tail call
 *    (src/matched/func_0204D2C8.c).
 */
extern void func_0204BF28(void *obj, u32 idx);              /* 0x0204BF28 arm */

/*
 * WAVE 16 (2026-09-23), declaration facts:
 *  - const on the READ-ONLY EXTERN DATA closes a register tie the way const
 *    on a read-only source parameter does: func_0204C2C8 58 -> EXACT with
 *    tbl_020A17D8 / tbl_020A17F0 declared const, nothing else changed.
 *  - sub_0204DACC is (res, u32 idx, desc, ovr pointer, u32 mode); func_0204E0D0
 *    is (owner, s32 idx, void *handle, u32 mode, ovr pointer).  Neither
 *    moved func_0204A7A0 (37) or sub_0204A6C8 (4).
 *  - The template at 0x020A1430 that func_0204A7A0 copies is an
 *    NNSG2dCharacterData {0xffff, 0xffff, GX_TEXFMT_PLTT16, mapping from
 *    DISPCNT & 0x00300010, 0, size, pRawData}.
 */

#endif /* CLACT_H */
