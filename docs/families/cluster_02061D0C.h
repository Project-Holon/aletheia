/*
 * docs/families/cluster_02061D0C.h -- shared declarations for the
 * pseudo-family at 0x02061D0C..0x02062680 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so unlike docs/families/mcss.h this cluster is NOT a
 * recovered original translation unit.  It was formed by address adjacency
 * plus shared callees and data objects.
 *
 * SUBSYSTEM: the VRAM / sub-64K HEAP ALLOCATOR.  This is one coherent
 * subsystem in three layers, bottom to top:
 *
 *   LAYER 1, 0x02061D0C..0x02061FF8 -- the GENERIC FREE-LIST ENGINE.  A
 *     doubly-linked list of 16-byte { addr, size, prev, next } block records
 *     drawn from a caller-supplied node pool, with a second list head acting
 *     as the pool's free chain.  Every routine here takes the pair
 *     (list head **, pool head **) as its first two arguments and touches no
 *     global at all -- that parameterisation is what lets one engine serve
 *     several independent heaps, and it is why the layer's own functions carry
 *     no relocations.  The five routines are:
 *       func_02061D0C  coalesce a { start, end } range against the free list,
 *                      moving every block it touches back to the pool
 *       func_02061DF0  clear one list head (unlabelled leaf, see below)
 *       func_02061DFC  thread `count` records into a fresh pool chain and
 *                      return the array pointer
 *       func_02061E48  push one { addr, size } record from the pool onto a list
 *       func_02061EA4  zero one stack word and tail into func_02061EB8
 *                      (unlabelled leaf, see below)
 *       func_02061EB8  first-fit ALLOCATE with an alignment argument -- the
 *                      engine's core, the only open function of this layer
 *       func_02061FF8  coalesce sweep: walk the list re-offering each block's
 *                      { addr, addr+size } range to func_02061D0C until the
 *                      list stops changing
 *       func_0206207C  FREE: coalesce a { addr, addr+size } range, then take a
 *                      pool node for the merged result and push it on the list
 *       func_0206210C / func_0206246C  `v << 4` -- two identical size scalers
 *
 *   LAYER 2, 0x02062114..0x02062270 -- the 16-BYTE-GRANULE CLIENT.  A save
 *     hook (func_02062114) parks its four register arguments in the global
 *     configuration block g_02146B94 and runs the real initialiser
 *     func_02062270, then optionally installs the layer's alloc/free pair into
 *     the two handler slots 0x020A8140 / 0x020A8144.  The pair itself is
 *     func_0206216C (allocate; round to 16, refuse >= 0x7FFF0, pack the
 *     handle) and func_020621FC (free/validate; unpack the handle).  The heap
 *     pair it drives is g_02146B98 / g_02146B9C, and the flag argument picks
 *     between the g_02146B94 pair and the g_02146B98 pair.
 *
 *   LAYER 3, 0x02062474..0x0206267C -- the 8-BYTE-GRANULE CLIENT.  Exactly the
 *     same shape one granule down: a save hook (func_02062474) writing
 *     g_02146BB0 and installing func_020624C8 / func_02062594 into
 *     0x020A8148 / 0x020A814C, an allocator func_020624C8 (round to 8, refuse
 *     >= 0x7FFF8, packed handle `(addr >> 3) | ((size >> 3) << 16)`), a
 *     validator func_02062594, an initialiser func_020625D8, and the
 *     'KNBA'-tagged lookup func_02062634 with its two thin wrappers
 *     func_02062670 and func_0206267C.
 *
 *   The layer-2/layer-3 correspondence is exact and is the most useful fact in
 *   this file: func_0206216C : func_020624C8 :: func_020621FC : func_02062594
 *   :: func_02062114 : func_02062474 :: func_02062270 : func_020625D8.  A
 *   spelling that closed one member closes its partner.
 *
 * Derived from the 16 matched sources found with
 *   grep -l "address:  0x02061[D-F]\|address:  0x02062[0-6]" src/matched/*.c
 * and from the notes docs/notes/pkt_02061DFC.c.txt, docs/notes/pkt_02061EB8.c.txt,
 * docs/notes/func_0206216C.c.txt, docs/notes/func_020621FC.c.txt,
 * docs/notes/func_020625D8.c.txt and docs/notes/pkt_02062688.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  Where two matched files disagree on a spelling, the
 * file whose code actually constrains the field wins.  The block record below
 * is spelled five different ways across the matched sources (`struct Node`,
 * `struct Node02061DFC`, `struct Node02061E48`, `Node02061FF8`,
 * `Node0206207C`); they are all the same 16-byte record and are unified here
 * as `struct Blk`.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * This cluster is SPLIT between the two front ends, and which one a function
 * wants tracks the LAYER, not the address:
 *
 *   dsi/1.1p1  (project default, `-O4,p`):
 *       func_02061D0C  func_02061DFC  func_02061E48  func_02061FF8
 *       func_0206207C  func_0206210C  func_02062114  func_0206246C
 *       func_02062474  func_02062594  func_02062634  func_02062670
 *       func_0206267C
 *   ../2.0/sp2  (`-O4,p -proc arm946e`):
 *       func_0206216C  func_020621FC  func_020624C8
 *
 * Every 2.0/sp2 member is an ALLOCATOR-OR-VALIDATOR ENTRY POINT of layer 2 or
 * layer 3 -- the four functions that unpack or pack a handle and dispatch on a
 * flag to one of two heap pairs.  Nothing else in the cluster needs 2.0.
 *
 * The tell for func_020624C8 is the one docs/families/cluster_020737C0.h
 * records: on 1.1p1 the two heap addresses are pooled into callee-saved
 * registers and the push list comes out one register wider than the image's.
 *
 * The tell for func_0206216C / func_020621FC is a DIFFERENT and, as far as
 * this tree records, new one, and it is worth recognising on sight:
 *
 *   *** 1.1p1 TAIL-MERGES THE TWO ARMS OF A FLAG DISPATCH; 2.0/sp2 DOES NOT. ***
 *
 * Both functions are `if (flag) r = f(&A, &C, x, y); else r = f(&B, &C, x, y);`.
 * The image emits each arm in full -- `ldr r0,[pc]; ldr r1,[pc]; bl; b` then
 * `ldr r0,[pc]; ldr r1,[pc]; bl` -- eight instructions, because the two arms
 * load the SAME second pool word from two different pool offsets and are still
 * not merged.  dsi/1.1p1 hoists the common `ldr r1,[pc]; bl` suffix out of the
 * two arms and comes out exactly one instruction (4 bytes) SHORT, with the
 * arms reduced to a bare `ldr r0` plus a `b`.  No respelling of the C reaches
 * it: duplicating the whole tail in each arm overshoots by 20 bytes instead,
 * and forcing the result through a `volatile` local buys the instruction count
 * back in the wrong place (a str/ldr pair at the join).  Symptom to recognise
 * instantly: a compile whose prologue, arithmetic and epilogue are all
 * byte-identical but whose flag dispatch is four bytes short and missing one
 * `ldr rN,[pc]`.  Change the compiler, not the source.
 *
 * Both notes docs/notes/func_0206216C.c.txt and docs/notes/func_020621FC.c.txt
 * measured that 4-byte gap against 1.1p1 and stopped there; both bodies turned
 * out to be correct C and both closed on 2.0/sp2 on 2026-09-22 with one further
 * change each (see the two source headers).
 *
 * ISA: ARM throughout.  Unusual for game code (the ARM9 static module is Thumb
 * almost everywhere) and a cluster property worth knowing: always pass `--arm`.
 *
 * UNLABELLED LEAVES.  Two functions in the range save no `lr` and so carry no
 * `func_` label in the listings (docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md):
 *     0x02061DF0  12 bytes  `void f(u32 *p) { *p = 0; }`
 *     0x02061EA4  20 bytes  `u32 f(a,b,out) { u32 z = 0; return f_02061EB8(a,b,out,?,z); }`
 * Both are called from inside the cluster and both are real code.  Sweep this
 * range by address, never by label.
 * ============================================================================
 */

#ifndef CLUSTER_02061D0C_H
#define CLUSTER_02061D0C_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  The block record -- the one type layer 1 is built on
 * ================================================================== */

/* 16 bytes.  Every offset is pinned by a load or a store:
     +0x00 addr   func_02061D0C `range->end = curr->start + curr->size`
                  and func_02061EB8 `ldr r5,[r7]` / `str r3,[r6]`
     +0x04 size   func_02061EB8 `ldr sl,[r7,#4]; cmp sl,r4` -- the first-fit
                  comparison, so this is the free extent, not an end address
     +0x08 prev   func_02061D0C `prev->next = next` after `ldr r?,[c,#8]`
     +0x0c next   func_02061E48 `pool->free_list = node->next` at +0x0c and
                  func_02061EB8 `ldr r7,[r7,#0xc]` as the walk step
   The record is used as BOTH a live block and a free pool cell; the pool
   chains through `next` only and leaves `prev` undefined.                    */
struct Blk {
    u32 addr;           /* 0x00 */
    u32 size;           /* 0x04 */
    struct Blk *prev;   /* 0x08 */
    struct Blk *next;   /* 0x0c */
};

/* The { start, end } range func_02061D0C coalesces and func_02061FF8 /
   func_0206207C build on the stack.  It is passed as a u32[2] by every caller
   (func_02061FF8 `buf[0]=n->f00; buf[1]=n->f00+n->f04`), never as a struct,
   so a matcher should declare it `u32 *` unless the image says otherwise.    */
struct Range {
    u32 start;          /* 0x00 */
    u32 end;            /* 0x04 */
};

/* ================================================================== *
 * 1.  Layer 1 -- the generic free-list engine (no globals at all)
 * ================================================================== */

/* Coalesce `range` against the list at *head, returning non-zero if anything
   merged.  Every block whose addr == range->end or whose addr+size ==
   range->start is absorbed into the range and unlinked to *pool.  Evidenced by
   src/matched/func_02061D0C.c, which is EXACT.  NOTE the two zero-valued
   locals `zero1`/`zero2` in that source: they are the `repeated small constant
   takes a register` idiom and are load-bearing, not noise.                   */
extern u32  func_02061D0C(struct Blk **head, struct Blk **pool, struct Range *range);

/* Clear one list head.  Unlabelled leaf at 0x02061DF0, 12 bytes.            */
extern void func_02061DF0(struct Blk **head);

/* Thread `count` records of `arr` into a pool chain and RETURN `arr`.  The
   return value is load-bearing: src/matched/func_02061DFC.c records that the
   void spelling frees r0 two bytes early, and the permuter's `ret-var`
   mutation is what found it.  The last cell's `next` is zeroed through a
   `u32 *` cast of `&arr[count]`, i.e. `((u32 *)&arr[count])[-1] = 0`.       */
extern struct Blk *func_02061DFC(struct Blk *arr, u32 count);

/* Take one cell off *pool, fill it with { addr, size } and push it on *head.
   Returns 1 on success, 0 when the pool is empty.  Evidenced by
   src/matched/func_02061E48.c, which is EXACT.  The `goto err` shape in that
   source is load-bearing: the two `if (node == 0)` tests are separate
   statements, not one conjunction.                                          */
extern u32  func_02061E48(struct Blk **head, struct Blk **pool, u32 addr, u32 size);

/* Zero a stack word and tail into func_02061EB8 with alignment 0.  Unlabelled
   leaf at 0x02061EA4, 20 bytes.  Called by func_0206216C as the layer-2
   allocate entry, so its fourth argument is the SIZE and the alignment it
   supplies is the zeroed word.                                              */
extern u32  func_02061EA4(struct Blk **head, struct Blk **pool, u32 *out, u32 size);

/* FIRST-FIT ALLOCATE with alignment.  *out receives the aligned address; the
   return is 1 on success, 0 on failure (and *out is zeroed).  When the
   alignment forces padding, the padding is itself pushed back on the free list
   as its own block, which is why this needs the pool.  OPEN -- see
   docs/notes/pkt_02061EB8.c.txt; the body there is believed correct and is
   size-exact under ../2.0/sp2, with a whole-function register reshuffle left.
   The `alignment` argument arrives on the STACK at [sp,#0x28] behind the
   ten-register push, which is the tell that this is a five-argument
   function.                                                                  */
extern u32  func_02061EB8(struct Blk **head, struct Blk **pool, u32 *out,
                          u32 size, u32 alignment);

/* Repeatedly re-offer every live block's own extent to func_02061D0C until the
   list stops changing.  Evidenced by src/matched/func_02061FF8.c (EXACT):
   the re-read of *head after a successful merge, not a cached cursor, is what
   the image does.                                                            */
extern void func_02061FF8(struct Blk **head, struct Blk **pool);

/* FREE.  Coalesce { addr, addr+size } into the list, then take one pool cell
   for the merged result and push it.  Returns 1 on success, 0 when the pool is
   empty.  Evidenced by src/matched/func_0206207C.c (EXACT).  Its return value
   is used as a PREDICATE by func_02062594 and func_020621FC, which invert it
   (`moveq r0,#1; movne r0,#0`), so this is the validator path too.          */
extern int  func_0206207C(struct Blk **head, struct Blk **pool, u32 addr, u32 size);

/* `v << 4`, the 16-byte granule scaler.  Two byte-identical copies at
   0x0206210C and 0x0206246C.                                               */
extern int  func_0206210C(int v);
extern int  func_0206246C(int v);

/* ================================================================== *
 * 2.  Layer 2 -- the 16-byte-granule client
 * ================================================================== */

/* The layer-2 configuration block.  func_02062114 writes its four register
   arguments at +0x0c..+0x18 and func_02062270 reads +0x0c, +0x10, +0x14 and
   +0x18 back.  The block is written THROUGH ITS OWN ADDRESS -- a plain global
   struct, never a pointer variable -- which is why it costs exactly one pool
   word per compilation unit.  The first three words are the heap-pair triple
   the layer-1 engine is handed: g_02146B94 and g_02146B98 are two list heads
   and g_02146B9C is the shared pool head.                                    */
struct Cfg02146B94 {
    u32 head_a;         /* 0x00 == g_02146B94, list head, flag == 0 path     */
    u32 head_b;         /* 0x04 == g_02146B98, list head, flag != 0 path     */
    u32 pool;           /* 0x08 == g_02146B9C, shared pool head              */
    u32 f0c;            /* 0x0c   first save-hook argument                   */
    u32 f10;            /* 0x10   second                                     */
    u32 f14;            /* 0x14   third -- a record array base               */
    u32 f18;            /* 0x18   fourth -- a byte count, used as `>> 4`     */
};
extern struct Cfg02146B94 g_02146B94_blk;   /* 0x02146B94                     */

/* The same three words as separate externs, which is how every matched source
   in this cluster actually spells them (one pool word each).  Use these, not
   the struct, unless the image forces a single base.                         */
extern u32 g_02146B94;                  /* 0x02146B94 -- list head A          */
extern u32 g_02146B98;                  /* 0x02146B98 -- list head B          */
extern u32 g_02146B9C;                  /* 0x02146B9C -- shared pool head     */

/* The two layer-2 handler slots, in the same table clact.c uses.            */
extern void *g_020A8140;                /* 0x020A8140 <- func_0206216C        */
extern void *g_020A8144;                /* 0x020A8144 <- func_020621FC        */

/* The save hook.  Its fifth argument is read at [sp,#8], the caller's first
   stack slot past the 8-byte {r3,lr} frame.  EXACT, 1.1p1.                   */
extern void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 install);

/* ALLOCATE, 16-byte granule.  Round up to 16 (0x10 for a zero request),
   refuse 0x7FFF0 and above, allocate through func_02061EA4 from the heap pair
   the flag picks, and pack the answer as
       ((n >> 4) << 16) | ((addr << 13) >> 16) | (flag << 31)
   -- size-high FIRST; the other order swaps r0 and r1 through the last four
   instructions.  EXACT under ../2.0/sp2 ONLY (see the pin above).            */
extern u32  func_0206216C(u32 size, u32 flag);

/* FREE / VALIDATE, 16-byte granule.  Unpack the handle -- address field
   `(h << 16) >> 13`, size field `((h & 0x7fff0000) >> 16) << 4`, flag bit 31
   -- answer 2 immediately when the size field is zero, otherwise probe
   func_0206207C and answer 0 on success / 1 on failure.  The `mov r0,#2` on
   the zero path is the only constant return and pins the convention.  EXACT
   under ../2.0/sp2 ONLY.                                                     */
extern u32  func_020621FC(u32 handle);

/* The layer-2 INITIALISER: copy a 0x30-byte, four-record table from
   0x020A17A8 to the stack, apportion the configured extents across the four
   records in two counted passes of stride 0x0c, then build the two lists with
   func_02061DF0 / func_02061DFC / six conditional func_02061E48 calls and
   sweep both with func_02061FF8.  OPEN, 488 bytes.  It carries the duplicate
   live pool word described below.                                            */
extern void func_02062270(u32 a, u32 b, u32 c, u32 d);

/* The four-record apportionment table at 0x020A17A8: stride 0x0c, read with
   three `ldm`/`stm` quads into a 0x30-byte stack frame.  The per-record fields
   are pinned by func_02062270's two loops: +0x00 is tested against zero and
   decremented by the take, +0x04 and +0x08 are each accumulated into by a take
   in one of the two passes.                                                  */
struct Rgn020A17A8 { u32 avail; u32 acc4; u32 acc8; };
extern const struct Rgn020A17A8 g_020A17A8[4];  /* 0x020A17A8, stride 0x0c    */

/* ================================================================== *
 * 3.  Layer 3 -- the 8-byte-granule client
 * ================================================================== */

/* The layer-3 configuration block, the exact analogue of g_02146B94.  Pinned
   by src/matched/func_02062474.c (writes +0x08, +0x0c, +0x10) and by
   func_020625D8 (reads +0x0c, +0x10, and passes +0x00 / +0x04 / +0x08 to the
   engine).                                                                   */
struct Cfg02146BB0 {
    u32 head;           /* 0x00 == g_02146BB0, list head                      */
    u32 pool;           /* 0x04 == g_02146BB4, pool head (filled by 020625D8) */
    u32 f08;            /* 0x08   third save-hook argument                    */
    u32 f0c;            /* 0x0c   record array base                           */
    u32 f10;            /* 0x10   byte count, used as `>> 4`                  */
};
extern struct Cfg02146BB0 g_02146BB0_blk;   /* 0x02146BB0                     */

extern u32 g_02146BB0;                  /* 0x02146BB0 -- list head            */
extern u32 g_02146BB4;                  /* 0x02146BB4 -- pool head            */

/* The two layer-3 handler slots.                                            */
extern void *g_020A8148;                /* 0x020A8148 <- func_020624C8        */
extern void *g_020A814C;                /* 0x020A814C <- func_02062594        */

/* The layer-3 save hook.  EXACT, 1.1p1.                                      */
extern void func_02062474(u32 a, u32 b, u32 c, u32 install);

/* ALLOCATE, 8-byte granule.  Round to 8 (8 for zero), refuse 0x7FFF8 and
   above, and pack `((size >> 3) << 16) | ((addr << 13) >> 16)`.  The flag
   picks the 8-byte-flag heap or the 0x10-byte-flag one; on the latter a block
   that would cross 0x10000 is handed straight back to func_0206207C and
   refused.  EXACT under ../2.0/sp2 ONLY -- the push-list tell.               */
extern u32  func_020624C8(u32 size, u32 flag);

/* VALIDATE, 8-byte granule.  The two halfword extractions are deliberately
   spelled DIFFERENTLY and that is what the image has: `(id & 0xFFFFu) << 3`
   fuses to `lsl #0x10; lsr #0xd`, while `((id & 0xFFFF0000u) >> 16) << 3` is
   materialised through a `mov r1,#0x10000; rsb r1,r1,#0; and; lsr; lsl` run.
   Declaring two u16 locals instead comes out 8 bytes short.  EXACT, 1.1p1.   */
extern int  func_02062594(u32 id);

/* The layer-3 INITIALISER, the analogue of func_02062270 and the smaller of
   the two.  Its five steps are fully recovered (see the note), but it does not
   compile byte-exact under ANY front end in the tree because of the duplicate
   pool word described below.  OPEN, 92 bytes.                                */
extern void func_020625D8(void);

/* The 'KNBA'-tagged lookup: ask func_02062B64 for the object tagged
   0x41424E4B ("KNBA"), run func_02062688 over `r + 8` and publish `r + 8`.
   EXACT, 1.1p1.  Its two thin wrappers each just call it.                    */
extern int  func_02062634(u32 a, u32 *out);
extern void func_02062670(void);
extern void func_0206267C(void);

extern u32  func_02062B64(u32 a, u32 tag);   /* outside the cluster           */
extern void func_02062688(u32 a);            /* outside the cluster           */

/* ================================================================== *
 * 4.  The cluster's one unresolved wall: the duplicate live pool word
 * ================================================================== */

/*
 * Both INITIALISERS -- func_020625D8 (layer 3) and func_02062270 (layer 2) --
 * end in a literal pool that holds the SAME ADDRESS TWICE, with both copies
 * live:
 *
 *     func_020625D8:  0x02062628 .word 0x02146BB0   (loaded at +04, +18, +28)
 *                     0x0206262C .word 0x02146BB0   (loaded at +20, +2C, +40)
 *                     0x02062630 .word 0x02146BB4
 *
 *     func_02062270:  0x0206245C .word 0x02146B94   (six loads share these
 *                     0x02062460 .word 0x02146B94    two copies the same way)
 *
 * Every front end in this tree deduplicates the pool and emits ONE word,
 * reusing the register a previous site already loaded, which costs the
 * function four bytes and reallocates from that point on.  The full compiler
 * sweep for func_020625D8 -- nine front ends, both granularities -- is in
 * docs/notes/func_020625D8.c.txt, and so is the list of C respellings tried
 * against it (struct member, local pointer, casts, volatile, the pool-relative
 * forms, and one-struct-for-both-words).  None move it.
 *
 * DO NOT RE-RUN THAT SWEEP.  The conclusion recorded there is that the
 * original came from a front end outside the tree, or the same front end with
 * a pool rule that emits a word per MATERIALISATION-SITE GROUP rather than per
 * constant.  Recognising this pattern is cheap: count the `.word`s in the
 * function's own pool and look for a repeat.  If there is one, the function is
 * not closable with what this tree has, whatever the C says.
 */

#endif /* CLUSTER_02061D0C_H */
