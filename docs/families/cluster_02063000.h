/*
 * docs/families/cluster_02063000.h -- shared declarations for the
 * pseudo-family at 0x02063000..0x02063780 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered translation unit; it
 * was formed by address adjacency plus shared callees and data objects.  The
 * subsystem is unambiguous all the same, because every open function in the
 * range reaches the same two globals:
 *
 *   THE OAM / CELL-WINDOW ALLOCATOR.  `g_02146BC8` is an array of three
 *   0x540-byte BANK records (main engine, sub engine, and a third), each
 *   holding an OAM shadow buffer and two free-slot bitmaps; `g_02146BC4` is
 *   the 16-bit running allocation id that stamps a reserved span.  Callers
 *   reserve a span of OAM entries (func_02063138), write entries into it
 *   (func_02063294), write affine/colour parameters into it (func_02063378),
 *   flush or blank it (func_02063640, func_0206343C), and the whole thing is
 *   reset at boot by func_02063078.  The leaf thunks at 0x02063054 and
 *   0x02063068 (already matched) bias a byte offset into an absolute OAM
 *   address (0x07000000 main, 0x07000400 sub) and tail-call the DMA transfer
 *   at 0x02082A60, which is what identifies the buffer at +0x100 as OAM.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02063" src/matched/*.c
 * and from the notes docs/notes/pkt_02063078.c.txt,
 * docs/notes/sub_02063138.c.txt, docs/notes/func_02063640.c.txt,
 * docs/notes/func_0206343C_and_02063640.c.txt and docs/notes/pkt_02063054.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrh`/`strh` prove a 16-bit field, a `mla` against
 * `mov rN, #0x540` proves the record stride, and a shift pair of unequal
 * amounts proves a narrowing cast rather than a bitfield.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * This cluster is a `--cc ../2.0/sp2` family on the project's standard
 * "kept constants" / "kept branches" tells (docs/FRONTEND-PINS.md).  The
 * recognition rule, in the form that costs the least time:
 *
 *   IF a size-exact-looking body comes out of dsi/1.1p1 SHORT by four or
 *   eight bytes, or at the right size with a `push`/`pop` list ONE REGISTER
 *   WIDER than the image's, CHANGE THE COMPILER BEFORE CHANGING THE SOURCE.
 *
 * Two rows measured in this range, both on the first compile under the pin:
 *
 *   func_02063078  (filed EXACT, 192 bytes).  The image rematerialises every
 *     one of the nine MIi_CpuClear16 calls' fill value and size into r0/r2 and
 *     spends NO callee-saved register: `push {r3, lr}` / `pop {r3, pc}`.
 *     1.1p1 -O4,p CSEs the 0xFFFF sentinel into r5 and the 0x40 size into r4,
 *     widening the prologue to `push {r3, r4, r5, lr}` and replacing each
 *     rematerialisation with `mov r0,r5` / `mov r2,r4`: same 192 bytes, 30
 *     concrete out.  Under the pin, 0 mismatches.
 *
 *   func_02063640  (DIFF 24, not filed).  The image materialises the -1
 *     channel sentinel into a register and compares register-to-register
 *     (`mvn r1,#0` ... `cmp r0,r1`); 1.1p1 folds it to `cmn r0,#1` and comes
 *     out FOUR BYTES SHORT at 320 against 324, 160 concrete out.
 *     docs/notes/func_02063640.c.txt spent TEN spellings of the constant on
 *     that four-byte gap -- `(u32)-1`, `0xFFFFFFFFu`, `~0u`, a named local, an
 *     `int` channel, a `void *` channel, the compare reversed, `< 0xFFFFFFFFu`,
 *     a `static` helper, a `static inline` helper, and finally `~(u32)0u` --
 *     and concluded "the next attempt should not be another spelling of the
 *     constant."  It was right, and the reason is that the sentinel spelling
 *     was never the variable: under `../2.0/sp2` the ORIGINAL ten-spelling C,
 *     unchanged, is size-exact at 324 with 31 concrete bytes out (24 after one
 *     loop-body reorder).  A register-held -1 is a FRONT-END TELL, not a C
 *     shape.  Add it to the table in docs/FRONTEND-PINS.md as such.
 *
 * ISA: ARM throughout this cluster, which is unusual for game code (the ARM9
 * static module is Thumb almost everywhere) and is itself worth knowing:
 * always pass `--arm`.
 *
 * One row in the range carries a -proc pin instead of a front-end pin:
 * src/matched/sub_02063054.c is `-O4,p -proc arm7tdmi` (its own header
 * carries the measurement).  Its twin sub_02063068 is plain 1.1p1.
 *
 * ============================================================================
 * THE STANDING WALL: THE `mla` DESTINATION REGISTER
 * ============================================================================
 *
 * Every function in this cluster computes its bank address the same way --
 * `&g_02146BC8[which].<member>[index]`, which mwccarm emits as a real
 * `mla rD, rWhich, rStride, rBase` against `mov rStride, #0x540`.  THREE of
 * the four open rows left in the range are blocked on the same residue and no
 * other: the image spends three distinct registers on the triple (one for the
 * loaded index, one for the pool base, one for the destination) while every
 * front end reuses the base's own register as the destination, because it can
 * see the base is dead after the multiply.
 *
 *   func_02063378   5 bytes out, one instruction triple   (22 spellings)
 *   func_02063294  13 bytes out, that triple plus one     (16 spellings)
 *   func_02063640  24 bytes out, that triple twice         (permuter plateau)
 *
 * MEASURED EXHAUSTION, so the next lane does not repeat it: twenty-two hand
 * spellings on 0x02063378 and sixteen on 0x02063294 across four earlier passes
 * (naming, declaration order, declaration/assignment splitting, stride locals,
 * operand order, re-association, `volatile` on the index, casts, and the base
 * given a second use to keep it live -- the last of which DOES stop the reuse
 * but costs a whole compare-and-branch and is strictly worse), plus, this wave,
 * the pycparser AST permuter (`tools/permuter.py`) which the earlier passes did
 * not have: 800 compiles in `--mode hill` and 2000 in `--mode anneal` on
 * 0x02063640, flat at 24 for the last 1700 of them, and a full singles
 * exhaustion on 0x02063378.  The decision is made after linearisation on a
 * value the source has already spelled as dead, and no source-level lever
 * reaches it.  THE DESTINATION REGISTER OF AN `mla` IS NOT SOURCE-ADDRESSABLE.
 * The same class is recorded at 0x02072374 (an `smull`); one fix moves all
 * four rows.
 * ============================================================================
 */

/*
 * ============================================================================
 * WAVE 10 (2026-09-22): THE WALL IS NOT ONE WALL.  Two rows filed.
 * ============================================================================
 *
 *   func_02063294  EXACT (src/matched/).  The "mla destination" residue MOVED
 *     under the permuter's split-assign: `ptr = g_02146BC8; ptr = ptr +
 *     win->bank * 0x540;` (g_02146BC8 declared u8[]) gives the image's
 *     `mla ip, r4, r3, ip`.  The remaining RMW swap was the SDK GXOamAttr
 *     bitfield union: `if (dst->rsMode & 1) dst->rsParam = mode;` -- the
 *     (<<22, >>30) shift pair is the 2-bit rsMode field, the 0x3E000000 mask
 *     the 5-bit rsParam.  So "NOT SOURCE-ADDRESSABLE" above is refuted for
 *     this row; it was a declarations question.
 *   func_02063138  EXACT (src/matched/).  Two inline helpers used twice,
 *     IsFree(tbl, first, last) and Fill(tbl, first, last, id), each check
 *     written `if (IsFree(..)) {..} else return 0;`; Fill's destination
 *     spelled `(u8 *)tbl + first * 2` (a different expression from IsFree's
 *     &tbl[first], so the address is recomputed, not CSE-copied across the
 *     loop); the coarse table bound to a local (`coarse = bank->slotsB`).
 *
 *   func_02063378  DIFF 4.  READING ERROR FIXED: the failure return is the
 *     constant 0xFFFE (pool word 0x02063434), not the table base; the
 *     function is 196 bytes with a two-word pool and returns u16.  With that
 *     it is size-exact and the triple is the ONLY residue.  Here the image
 *     does NOT coalesce base and destination (`mla ip, lr, r2, r3`); the
 *     split-assign lever does not apply, and every 2.0 build gives the same
 *     bytes.  Measured: the image colours base (r3), dest (ip), index (lr);
 *     the one spelling that uncoalesces dest (`aff = (T *)(g + i*0x540 +
 *     0x100); aff = aff + idx;`) colours them in exactly the reverse order.
 *   func_02063640  DIFF 19 (was 24).  The split-assign lever fixes most of
 *     the flag-clear arm's copy; the first copy is the same colouring-order
 *     residue as 0x02063378.
 *   func_0206343C  DIFF 99, size-exact at 516, written this wave (notes).
 *     `switch (which)` for the main/sub OAM load, a u16 offset local taken
 *     before the flush call, a volatile read of the affine window's +0x0c in
 *     the guard.  Residue is callee-saved allocation only.
 *
 * NEW CALLEES/DATA proved by 0x0206343C (all resolve):
 *   func_020862F0(const void *p, u32 size)                  -- the DC flush
 *   func_0207E684 / func_0207E708(const void *src, u32 off, u32 size)
 *                                           -- main / sub OAM load, by which
 *   g_020A81E4[] = { sub_02063068, sub_02063054, 0 }        -- per-engine
 *     loader table, type void (*)(const void *src, u32 off, u32 size)
 * ============================================================================
 */

/*
 * ============================================================================
 * WAVE 11 (2026-09-23): THE RANGE IS NITROSYSTEM g2d_OamManager.c.
 * ============================================================================
 *
 * struct Span / WinOam / WinAffine below are ONE NNSG2dOamManagerInstance:
 *   +0x00 u32 type (the bank index); +0x04 ManagedOamRegion attr
 *   {fromIdx +4, toIdx +6, currentIdx +8}; +0x0a ManagedOamRegion affine
 *   {fromIdx +0xa, toIdx +0xc, currentIdx +0xe}; +0x14 BOOL
 *   bFastTransferEnable.  The "two views with different cursor offsets" are
 *   the two regions.  Rows:
 *     func_02063294  NNS_G2dEntryOamManagerOamWithAffineIdx   EXACT
 *     func_02063378  NNS_G2dEntryOamManagerAffine -> u16, 0xFFFE = none
 *     func_0206343C  NNS_G2dApplyOamManagerToHW
 *     func_02063640  the buffer reset (0xC0 fill, currentIdx = fromIdx)
 *
 * func_02063378 in NitroSystem form reaches the same DIFF 4 WITHOUT the
 * volatile hack: IsAreaValid_ as `return (cur <= to + 1) && (from <= to);`,
 * GetCapacity_ as if/else returning `(u16)(to - cur + 1)` or 0, and
 * HasCapacity_ as `return (BOOL)(GetCapacity_(a) >= num);` -- the explicit
 * (BOOL) cast is what keeps the image's materialised movhs/movlo (without
 * it the guard folds to a branch, 184 bytes).  Source in
 * docs/notes/pkt_02063078.c.txt (2026-09-23 appendix).
 *
 * The mla triples of 378 and 640 did NOT move this wave: declaration order
 * (54 orders on 378, 14 on 640), an 8x8 per-block spelling grid on 640
 * (block 1's residue is independent of block 1's spelling), every 2.0
 * build and the 1.2 line (1.2/sp3 keeps the same two triples).  Unlike
 * 0x020691E0 (closed this wave by declaration order), no declaration moves
 * them.
 * ============================================================================
 */

#ifndef CLUSTER_02063000_H
#define CLUSTER_02063000_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The running 16-bit allocation id.  func_02063138 reads it with `ldrh`,
   stores id+1 back with `strh`, and stamps the reserved span with the value
   it read; nothing else in the range touches it.  16-bit is proved by the
   loads, not by the name.                                                    */
extern u16 g_02146BC4;                  /* 0x02146BC4                        */

/* The three bank records.  The 0x540 stride is proved by the `mla` against
   `mov rN, #0x540` in func_02063138, func_02063294, func_02063378,
   func_0206343C and func_02063640 alike -- never a shift chain, so the stride
   is a real multiply and the array is a real array of records.  The three
   base addresses func_02063078 clears (0x02146BC8, 0x02147108, 0x02147648)
   are exactly 0x540 apart, which is the independent confirmation of BOTH the
   stride and the element count of three.                                    */
struct Bank;
extern struct Bank g_02146BC8[3];       /* 0x02146BC8, stride 0x540          */

/* ================================================================== *
 * 1.  struct Bank -- one 0x540-byte bank record
 *
 * The three regions and their evidence, all from func_02063078's nine
 * MIi_CpuClear16 calls (the only place all three are named at once):
 *
 *   +0x000  0x100 bytes cleared to 0xFFFF   -- slotsA, the fine-grained
 *           free-slot table.  0xFFFF is the FREE sentinel: func_02063138
 *           tests `*p != 0xFFFF` against a pool word holding exactly it, and
 *           stamps the span with the allocation id on success.  0x100 bytes
 *           of u16 is 128 slots, one per OAM entry.
 *   +0x100  0x400 bytes cleared to 0xC0     -- the OAM shadow buffer.  0x400
 *           bytes of 8-byte entries is 128 entries, matching slotsA exactly.
 *           func_02063294 writes three halfwords per entry at +0/+2/+4 (the
 *           three OAM attribute words) and leaves +6 alone, which is the OAM
 *           layout.  0xC0 in attr0 is the "disabled / double-size off" OAM
 *           idle pattern, which is why the reset fills with it and why
 *           func_02063640's blank loop stores 0xC0 into each entry's FIRST
 *           halfword only.
 *   +0x500  0x40 bytes cleared to 0xFFFF    -- slotsB, the coarse free-slot
 *           table at 1/4 granularity.  func_02063138 derives its index as
 *           `base >> 2` and its count as `count >> 2`, which is what fixes
 *           the granularity; 0x40 bytes of u16 is 32 entries, one per four
 *           OAM entries.
 *
 * func_02063378 writes at a 0x20 stride inside the +0x100 region (four
 * halfwords at +0x06, +0x0e, +0x16, +0x1e of a 0x20-byte group, i.e. the
 * fourth halfword of each of four consecutive 8-byte entries), which is the
 * affine-parameter view of the same OAM buffer: the DS packs one 2x2 affine
 * matrix into the unused fourth halfword of four consecutive OAM entries.
 * That is why its stride is 0x20 where func_02063294's is 8, and it is the
 * strongest single piece of evidence that +0x100 really is DS OAM.
 * ================================================================== */
struct OamEntry {
    u16 attr0;              /* +0x0  0xC0 when idle                          */
    u16 attr1;
    u16 attr2;
    u16 affine;             /* +0x6  one quarter of an affine matrix         */
};

struct Bank {
    u16 slotsA[0x80];               /* 0x000  free-slot table, 0xFFFF = free */
    struct OamEntry oam[0x80];      /* 0x100  OAM shadow, 0x400 bytes        */
    u16 slotsB[0x20];               /* 0x500  coarse table, 1/4 granularity  */
};                                  /* 0x540                                 */

/* ================================================================== *
 * 2.  struct Span -- the caller-side span record
 *
 * func_02063138 fills it, func_02063640 and func_0206343C consume it.  The
 * two functions agree field for field, which is why it is written once here
 * rather than per function.  Every offset below is a `ldrh`/`strh`/`ldr`/`str`
 * in one of those three bodies.
 *
 *   +0x00  u32  the bank index; the `mla`'s multiplicand in all three
 *   +0x04  u16  first entry of the span
 *   +0x06  u16  last entry of the span (INCLUSIVE: every count in the range
 *               is spelled `last - first + 1`)
 *   +0x08  u16  the cursor; func_02063640 resets it to `first` on exit
 *   +0x0a  u16  mirrored to +0x0e on exit by func_02063640
 *   +0x0e  u16  the mirror
 *   +0x10  u16  the allocation id stamped from g_02146BC4.  func_02063138
 *               RE-READS it with `ldrh r0,[r8,#0x10]` for each of its two
 *               MIi_CpuClear16 calls rather than keeping the value it just
 *               stored -- reproducing that re-read is what closed the first
 *               eight bytes of that function's diff and it must not be
 *               written as a local (see the note).
 *   +0x14  u32  the "live" flag; func_02063640 branches on it
 * ================================================================== */
struct Span {
    u32 which;              /* 0x00 */
    u16 first;              /* 0x04 */
    u16 last;               /* 0x06  inclusive */
    u16 cur;                /* 0x08 */
    u16 unk_0a;             /* 0x0a */
    u16 pad_0c;
    u16 unk_0e;             /* 0x0e  mirror of +0x0a */
    u16 id;                 /* 0x10  allocation id out of g_02146BC4 */
    u16 pad_12;
    u32 live;               /* 0x14 */
};

/* The narrower view func_02063294 and func_02063378 take of the SAME record.
   They never touch +0x08 upward, and they read the cursor at a DIFFERENT
   offset (+0x0e for 378, +0x08 for 294), so the two are recorded as their own
   views per the adjudication rule rather than merged into struct Span.  Both
   need the cursor's GUARD read spelled `*(volatile u16 *)&...` or the front
   end forwards it and drops the image's second load -- the single change that
   took func_02063378 from 91 concrete bytes out to 5.                        */
struct WinOam {                     /* func_02063294's view */
    u32 bank;               /* 0x00 */
    u16 min_oam;            /* 0x04 */
    u16 max_oam;            /* 0x06 */
    u16 cur_oam;            /* 0x08 */
};

struct WinAffine {                  /* func_02063378's view */
    u32 index;              /* 0x00 */
    u8  pad_04[6];
    u16 min_idx;            /* 0x0a */
    u16 max_idx;            /* 0x0c */
    u16 cur_idx;            /* 0x0e */
};

/* The four s32 affine terms func_02063378 stores, each narrowed by an
   arithmetic `>> 4` into the halfword.  The shift is in the STORE, so the
   source fields are 32-bit fixed point and the OAM halfword is the 1.7.8
   affine form; `s32` is proved by the arithmetic shift.                      */
struct AffineParams { s32 c0, c1, c2, c3; };

/* ================================================================== *
 * 3.  Callees
 * ================================================================== */

/* The MSL/SDK memory fill, `label x131` image-wide.  func_02063078 and
   func_02063138 both call it; the first argument is a 16-bit fill value, so
   it is MIi_CpuClear16 and not the 32-bit form.                              */
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);

/* The OAM DMA thunks at the head of the cluster, already matched.  They take
   a source pointer and a BYTE OFFSET, not an address, and add the engine's
   OAM base themselves.  Declared `arm`.                                      */
extern void sub_02063054(void *src, u32 offset);   /* sub engine, +0x07000400 */
extern void sub_02063068(void *src, u32 offset);   /* main engine, +0x07000000 */
extern void sub_02082A60(void *src, u32 dest);     /* the transfer they reach */

/* The cache/flush and fill routines func_02063640 and func_0206343C reach.
   func_020821C0 takes FIVE arguments, the fifth through a reserved stack word,
   which is the whole reason those two functions open with `sub sp, sp, #4`;
   getting the arity wrong loses the frame adjustment and the whole body.      */
extern void func_020862B8(struct OamEntry *p, u32 len);
extern void func_020821C0(u32 ch, struct OamEntry *p, u32 data, u32 len, u32 f);
extern void func_02082A7C(u32 data, struct OamEntry *p, u32 len);

/* The DMA channel number, clamped to a -1 sentinel above 3.  See the pin
   section: the sentinel's register-held compare is a front-end tell.         */
extern u32 g_020A84C0;

/* ================================================================== *
 * 4.  The matched accessors at the tail of the range
 *
 * 0x02063784 and 0x020637B4 are one-line indexed loads (`return p[i];`, u16
 * and u32 respectively) and are plain 1.1p1, no pin.  They are listed here
 * only so a reader does not mistake them for part of the allocator: they are
 * generic and carry no cluster evidence.
 * ================================================================== */

/*
 * ============================================================================
 * WAVE 13 (2026-09-23): THREE ROWS CLOSED FROM g2d_OAM.c ITSELF
 * ============================================================================
 *   func_02063378  NNS_G2dEntryOamManagerAffine    EXACT (../2.0/sp2)
 *   func_02063640  NNS_G2dResetOamManagerBuffer    EXACT (../2.0/sp2)
 *   func_0206343C  NNS_G2dApplyOamManagerToHW      EXACT (../2.0/sp2)
 * struct Bank is OamCache { OamAttributeCache { u16 reservationTable[128];
 * GXOamAttr oamBuffer[128]; }; OamAffineCache { u16 reservationTable[32]; } }
 * and g_02146BC8 is oamCache_[3]; g_02146BC4 is numRegisterdInstance_
 * (GetNewGUID_).  g_020A84C0 is GXi_DmaId (GX_GetDefaultDMA clamps >3 to
 * GX_DMA_NOT_USE -- the register-held -1), g_020A81E4 GetOBJLoadFunction_'s
 * funcTbl, func_020862F0 DC_FlushRange, func_020862B8 DC_InvalidateRange,
 * func_020821C0 MIi_DmaFill32, func_02082A7C MIi_CpuClear32, func_0207E684
 * GX_LoadOAM, func_0207E708 GXS_LoadOAM.  THE "mla DESTINATION WALL" ABOVE
 * WAS THE INLINE BOUNDARY: every buffer address in g2d_OAM.c is computed by
 * GetOamBufferPtr_ / GetAffineBufferPtr_ (base + type * 0x540 + 0x100, then
 * + index), and written through those inlines all three rows compiled
 * byte-exact the first time.  Write the library's inlines, not the address.
 * ============================================================================
 */

#endif /* CLUSTER_02063000_H */
