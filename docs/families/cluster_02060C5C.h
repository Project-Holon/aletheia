/*
 * docs/families/cluster_02060C5C.h -- shared declarations for the
 * pseudo-family at 0x02060C5C..0x02060E30 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  Formed by address adjacency, and it is the
 * PUBLIC FACE of the expanded heap whose internals are cluster_02060764 next
 * door.  Its five members are:
 *
 *   0x02060C5C  create      align the arena, size-check it, lay out the handle
 *   0x02060C94  destroy     forwards to func_0206074C, the arena deregister
 *   0x02060CA0  alloc       round up, dispatch on the alignment's sign
 *   0x02060CD0  resize      grow or shrink an allocation in place
 *   0x02060E30  free        unlink from the used list and coalesce
 *
 * The struct layouts, the block signatures, the size thresholds and the
 * compiler-pin recognition rule all belong to
 * docs/families/cluster_02060764.h.  READ THAT HEADER FIRST; this one records
 * only what is specific to the public entry points.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02060C\|address:  0x02060E" src/matched/*.c
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * dsi/1.1p1 (the project default) throughout.  All four byte-exact sources
 * here carry `compiler: 1.1p1`.  The SIBLING cluster_02060764 does contain one
 * sp2-pinned function (func_02060814) and records the recognition rule in
 * full; the rule is worth carrying, the pin is not.  Its short form:
 *
 *   size-exact or a few bytes short, every instruction and relocation
 *   structurally right, and a `push`/`pop` list ONE REGISTER WIDER than the
 *   image's  =>  try `--cc ../2.0/sp2` before spending a spelling sweep.
 *
 *   a register PERMUTATION at the SAME push width  =>  an allocation tie.
 *   That is tools/permuter.py's ground, not the front end's.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 *
 * THE TWO-SCALAR EXTENT.  The one shape this cluster must not lose.
 *
 * func_02060764 fills a two-word extent and func_020607E8 / func_02060B6C
 * consume one, so a function that does both names the same 8 bytes twice.
 * Whether those 8 bytes are ONE object or TWO decides four bytes of code:
 *
 *   TWO separate scalars  ->  mwcc's alias analysis sees two objects, each
 *   call site rematerialises `sp + 0`, and the image's 60 bytes come out.
 *   ONE array or struct   ->  it caches the address in a callee-saved
 *   register across the second call, collapsing two `add rN, sp, #0` into an
 *   `add r4, sp, #0` plus a `mov`, four bytes longer.
 *
 * The second site is then spelled `&end - 1`, because mwcc lays locals out
 * with the LATER declaration at the LOWER address: with `int end; int start;`
 * declared in that order, `end` sits at sp+0 and `&end - 1` and `&start` are
 * the same word.  src/matched/func_02060E30.c is the evidencing function and
 * carries the full derivation; src/matched/func_02060888.c shows the mixed
 * case, where the FIRST region is two scalars and the other two are structs
 * because three structs cost a sixth callee-saved register.
 * ============================================================================
 */

#ifndef CLUSTER_02060C5C_H
#define CLUSTER_02060C5C_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

/* struct MBlock, struct MBlockList, struct ExpHeap, struct MemRegion and the
   signature / threshold constants: see docs/families/cluster_02060764.h. */
struct MBlock;
struct MBlockList;
struct ExpHeap;
struct MemRegion;

/* ================================================================== *
 * Prototypes, with the exact parameter types the matched sources use
 * ================================================================== */

/* 0x02060C5C  EXACT (src/matched/func_02060C5C.c).  Create.  Two shapes are
   load-bearing and both are cheap to get wrong:
     - the end address is `size + (u32)start`, NOT `start + size`; the image's
       `add r1, r1, r0` accumulates into the SIZE register, which is
       docs/idioms/commutative-operand-order-names-the-temporary.md;
     - the two rejections are ONE `||`, not two `if`s.  The image's `bhi`
       jumps to the same `mov r0, #0` / `pop` the length test falls into,
       which a chain of separate `if`s cannot reach -- mwcc if-converts each
       one into its own `movhi`/`pophi` pair instead and four instructions
       differ.  This is
       docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md. */
extern void *func_02060C5C(void *start, u32 size, u32 attr);

/* 0x02060C94  EXACT (src/matched/func_02060C94.c).  Destroy: a bare forward
   to func_0206074C, the arena deregister on the other side of the list
   library (cluster_02060550). */
extern void func_02060C94(void);

/* 0x02060CA0  EXACT (src/matched/func_02060CA0.c).  Alloc.  A zero-byte
   request still costs one word, which is what makes an empty allocation a
   distinct pointer; the size then rounds up to a word and the SIGN of the
   alignment picks the head walk or the tail walk.  Neither call is a tail
   call even though nothing follows it, since each is reached through its own
   `pop`. */
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);

/* 0x02060CD0  open, 352 bytes, eight callee-saved registers.  Resize an
   allocation in place.  Structure read off the image, for whoever takes it:
     - the new size rounds up to a word and is compared with the block's
       current `size` at +0x04; EQUAL returns the pointer unchanged through a
       predicated epilogue (`addeq sp` / `moveq r0, sb` / `popeq`) and SMALLER
       falls through to the shrink path at 0x02060DF0;
     - the grow path walks the FREE list at heap+0x24 looking for the block
       that starts exactly at this allocation's end (`add r0, r7, r0` against
       each candidate, advancing through +0x0c), and fails out through the
       shared `mov r0, #0` at 0x02060D4C when there is none or when the
       neighbour is too small;
     - on success it takes the neighbour's extent with func_02060764, unlinks
       it with func_02060790, and rebuilds the boundary, snapping a remainder
       under 0x10 with a predicated `strlo` at 0x02060D84.
   The two-scalar extent rule above applies to its func_02060764 /
   func_020607E8 pair. */
extern void *func_02060CD0(struct ExpHeap *heap, void *ptr, u32 size);

/* 0x02060E30  EXACT (src/matched/func_02060E30.c).  Free: read the block's
   extent, unlink its header from the USED list at +0x2c, and hand the extent
   to func_02060B6C, which splices it back into the free list at +0x24 and
   merges it with any adjacent free block.  THE EVIDENCING FUNCTION for the
   two-scalar extent rule above. */
extern void func_02060E30(struct ExpHeap *heap, void *block);

/* Callees, all in cluster_02060764. */
extern void           func_02060764(int *out, struct MBlock *blk);
extern struct MBlock *func_02060790(struct MBlockList *list, struct MBlock *node);
extern struct MBlock *func_020607B8(struct MBlockList *list, struct MBlock *node,
                                    struct MBlock *after);
extern struct MBlock *func_020607E8(int *pair, u16 sig);
extern void          *func_02060814(struct ExpHeap *heap, void *lo, u32 attr);
extern void          *func_02060A08(struct ExpHeap *heap, u32 size, s32 align);
extern void          *func_02060ABC(struct ExpHeap *heap, u32 size, s32 align);
extern int            func_02060B6C(struct MBlockList *freeList,
                                    struct MemRegion *rgn);

/* WAVE 12 (2026-09-23): func_02060CD0 CLOSED, EXACT, ../2.0/sp2 -- the
   cluster's first 2.0 pin.  The plain NitroSystem free-list search
       for (p = head; p; p = p->next) { if (p == end) break; }
   is the image's cmp / ldrne / cmpne / bne loop under 2.0 (356 bytes under
   1.1p1), and the shrink arm's volatile re-read is unnecessary there.       */

#endif /* CLUSTER_02060C5C_H */
