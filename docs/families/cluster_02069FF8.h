/*
 * docs/families/cluster_02069FF8.h -- shared declarations for the pseudo-family
 * at 0x02069FF8..0x0206A110 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit; it was formed by address adjacency plus shared callees and data
 * objects.  All three members operate on ONE 0x2C-byte descriptor -- struct Up
 * below -- and together they are its whole lifecycle:
 *
 *   func_02069FF8  set either VRAM address field, skipping the zero ones
 *   func_0206A00C  ATTACH:  upload both slots into texture VRAM, set each
 *                  slot's "uploaded" bit
 *   func_0206A0C4  DETACH:  clear each slot's bit, hand the caller back the
 *                  VRAM address the slot held, and zero the slot
 *
 * The immediate neighbour is docs/families/cluster_0206A17C.h (the 3D model /
 * animation rig, 0x0206A17C..0x0206AE94), and the relationship is worth
 * knowing: this descriptor is what the rig's texture and palette slots are
 * uploaded through.  That cluster's own note that it is "unusually pin-heavy"
 * on ../2.0/sp2 does NOT carry over -- see the pin section.
 *
 * Derived from src/matched/func_02069FF8.c, src/matched/func_0206A00C.c and
 * src/matched/func_0206A0C4.c, and from the callers src/matched/func_02046FF8.c
 * and src/matched/func_020470D0.c, which between them fix both arities.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing happens
 * at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THERE IS NO SINGLE PIN HERE, and that is the finding.  Measured, per row:
 *
 *   func_02069FF8   dsi/1.1p1
 *   func_0206A00C   dsi/1.1p1        -- and ONLY 1.1p1; see below
 *   func_0206A0C4   ../2.0/sp2 and ../1.2/sp2 both byte-exact, 1.1p1 is not
 *
 * So the neighbouring cluster's 2.0 habit must NOT be assumed here.  Take the
 * pin from the residue, one row at a time.
 *
 * WHERE THE FRONT END DOES SHOW, it is on the leaf (func_0206A0C4) and it is
 * the usual frame tell read on a function that has no frame at all: 1.1p1
 * spends `lr` as a scratch register for a loaded halfword and therefore has to
 * open `push {r3, lr}` and return through `pop {r3, pc}`, where the image
 * keeps everything in `ip` and `r3` and never pushes.  Symptom: a leaf that
 * grows a prologue.  Both other front ends reproduce it, so the row is not
 * usable as evidence for either pin on its own and is deliberately not offered
 * as one in docs/FRONTEND-PINS.md.
 *
 * WHERE IT DOES NOT SHOW is more useful.  func_0206A00C sat at 51 concrete
 * bytes out under 1.1p1 AND at the same 51 under ../2.0/sp2 -- the identical
 * residue under two front ends, which is the reliable sign that the problem is
 * in the SOURCE and not in the compiler.  It was: a value the image keeps live
 * across a call (see wall C below).  When a change of front end does not move
 * the residue at all, stop changing it.
 *
 * THREE SPELLING WALLS IN THIS CLUSTER, all three measured:
 *
 *   A. `x &= ~1` ON A `u16` FIELD COSTS A POOL WORD.  The field arrives by
 *      `ldrh`, so after promotion the operand is `int` and `~1` is
 *      0xFFFFFFFE, which is not an ARM rotated immediate: the front end
 *      materialises it as a literal and the function grows a pool.  The image
 *      has `bic ip, ip, #1`.  Narrow the result back inside the expression --
 *      `t->f10 = (u16)(t->f10 & ~1)` -- and the AND becomes 16-bit, ~1 becomes
 *      0xFFFE, and `bic #1` is exact.  Costs 16 bytes of size when missed.
 *      The halfword sibling of
 *      docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md.
 *      The same applies to `|= 1`, which is why the attach side is written
 *      `u->f10 = (u16)(u->f10 | 1)`.
 *
 *   B. +0x08 AND +0x18 ARE `u32`, AND THE NARROWING IS AN UNEQUAL SHIFT PAIR.
 *      The image loads each with a full-word `ldr` and then does
 *      `lsl #0x10` / `lsr #0xd`, i.e. a 16-bit truncation folded with the
 *      `<< 3` that scales it to a VRAM offset --
 *      docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md.
 *      Declaring the fields `u16` gives `ldrh` plus a separate `lsl #3`
 *      (125 bytes out); the cast `(u32)(u16)f << 3` on a u32 field does not
 *      fold either (4 bytes long).  Write the pair out: `(u->f08 << 16) >> 13`.
 *
 *   C. A VALUE THE IMAGE KEEPS LIVE ACROSS A CALL IS A NAMED LOCAL, AND
 *      LEAVING IT AT ITS USE SITE COSTS A WHOLE REGISTER.  func_0206A00C
 *      reads +0x28 into r5 one instruction BEFORE its first GX_LoadTex.  Read
 *      at the second call site instead, the function is one callee-saved
 *      register short and pushes six where the image pushes eight -- 51
 *      concrete bytes, under both front ends.  This is
 *      docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md
 *      read in the other direction: the extra register is what the image
 *      SPENDS, so the local is required rather than forbidden.
 *
 * AND ONE NOTE ON THE PERMUTER, because this cluster is a clean example.  Once
 * walls A-C were paid, func_0206A00C's residue was 5 concrete bytes and purely
 * a colouring tie: `--explain` printed a three-way rotation (r6->r7, r7->r5,
 * r5->r6) with every instruction and relocation already correct.  Five
 * hand-written permutations of the declaration list all gave the same 5 bytes,
 * because these locals colour in FIRST-DEFINITION order, not declaration
 * order.  `--mode anneal --budget 2000 --jobs 8 --types` reached EXACT and
 * named `decl-order(d2<->n) ; block(if1,2) ; selfassign(n)`; only the first is
 * real, and applied alone to the readable source it is byte-exact.  A residue
 * whose `--explain` is a pure register rotation is the permuter's own class --
 * run it before any further hand sweep.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02069FF8_H
#define CLUSTER_02069FF8_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 1.  struct Up -- the VRAM upload descriptor, 0x2C bytes
 *
 * TWO SLOTS with the same five-field shape, at +0x08 and +0x18:
 *
 *      +0x00  the VRAM address (a u32, narrowed at the use -- see wall B)
 *      +0x04  the size in 8-byte units (u16, `<< 3` gives bytes)
 *      +0x08  flags; bit 0 is "currently uploaded"
 *      +0x0c  the offset from the descriptor to the source bytes
 *
 * mapped onto the descriptor as +0x08/+0x0c/+0x10/+0x14 for the TEXTURE slot
 * and +0x18/+0x1c/+0x20/+0x24 for the PALETTE slot.  The palette slot has one
 * extra field, +0x28, a SECOND source offset: the palette is uploaded twice,
 * once whole and once remapped into the second bank at half the size.
 *
 * Field evidence, one function per line:
 *   +0x08, +0x18  full-word `ldr` then `lsl #0x10` / `lsr #0xd`, so u32 with
 *                 a folded 16-bit narrowing and `<< 3` scale (func_0206A00C).
 *                 func_0206A0C4 hands the raw word back to the caller and
 *                 zeroes it; func_02069FF8 writes it when non-zero.
 *   +0x0c, +0x1c  `ldrh` then `lsls #3`, and the `s` is the guard: a zero size
 *                 skips the slot entirely (func_0206A00C).
 *   +0x10, +0x20  `ldrh` / `orr #1` / `strh` on attach, `ldrh` / `bic #1` /
 *                 `strh` on detach.  Halfword throughout -- see wall A.
 *   +0x14, +0x24  added to the descriptor's own address to reach the source
 *                 bytes, so these are OFFSETS and not pointers.
 *   +0x28         the palette's second source offset, read into a named local
 *                 before the first upload -- see wall C.
 * ================================================================== */
struct Up {
    u32 pad00[2];
    u32 f08;                    /* 0x08  texture VRAM address (u32, see B)   */
    u16 f0c;                    /* 0x0c  texture size, 8-byte units          */
    u16 pad0e;
    u16 f10;                    /* 0x10  texture flags; bit 0 = uploaded     */
    u16 pad12;
    u32 f14;                    /* 0x14  offset to the texture bytes         */
    u32 f18;                    /* 0x18  palette VRAM address (u32, see B)   */
    u16 f1c;                    /* 0x1c  palette size, 8-byte units          */
    u16 pad1e;
    u16 f20;                    /* 0x20  palette flags; bit 0 = uploaded     */
    u16 pad22;
    u32 f24;                    /* 0x24  offset to the palette bytes         */
    u32 f28;                    /* 0x28  offset to the SECOND palette copy   */
};

/* ================================================================== *
 * 2.  The palette bank remap, spelled out once
 *
 * func_0206A00C uploads the palette slot TWICE: once from +0x24 at the full
 * offset and size, and once from +0x28 at
 *
 *     ((off & 0x1FFFF) >> 1) + 0x20000 + ((off & 0x40000) >> 2)
 *
 * with the length halved.  Read off 0x0206A080..0x0206A098 with the pool word
 * 0x0001FFFF at 0x0206A0C0: the low 17 bits are scaled for 4-bit palettes, bit
 * 18 (the bank select) moves down two places, and 0x20000 is the second bank's
 * base.  The `& 0x1FFFF` operand is derived from the PRE-SHIFT value with
 * `and r0, r0, r4, lsr #13`, not from the already-computed offset -- see
 * wall C's neighbour in func_0206A00C's own header.
 * ================================================================== */
#define UP_PAL_BANK2_BASE   0x20000
#define UP_PAL_LOW_MASK     0x1FFFF     /* the pool word at 0x0206A0C0       */
#define UP_PAL_BANK_BIT     0x40000

/* ================================================================== *
 * 3.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the SDK layer, named (docs/families/cluster_020637F4.h fixed these) -- */
extern void GX_BeginLoadTex(void);                   /* 0x0207F7A0           */
extern void GX_LoadTex(void *src, u32 off, u32 n);   /* 0x0207F7FC           */
extern void GX_EndLoadTex(void);                     /* 0x0207F9B4           */

/* --- this cluster's own -------------------------------------------------- */
/* Spelled on a `char *` because that is the form that is byte-exact; the
   two offsets it writes are struct Up's +0x08 and +0x18. */
extern void func_02069FF8(char *p, int tex, int pal);

extern void func_0206A00C(struct Up *u, u32 wrap);   /* attach; wrap != 0
                                                        brackets with
                                                        Begin/EndLoadTex     */
extern void func_0206A0C4(struct Up *u, u32 *tex_out, u32 *pal_out);
                                                     /* detach; a null
                                                        out-pointer skips
                                                        that slot            */

#endif /* CLUSTER_02069FF8_H */
