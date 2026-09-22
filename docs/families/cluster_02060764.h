/*
 * docs/families/cluster_02060764.h -- shared declarations for the
 * pseudo-family at 0x02060764..0x02060C5C in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  Formed by address adjacency plus shared
 * callees and data objects, and unlike most clusters in the unanchored upper
 * half it is ONE COHERENT SUBSYSTEM: the NitroSDK **expanded heap**
 * (`MEM_*ExpHeap`), complete from its block-list primitives up to its public
 * create/alloc/free entry points.  Read in dependency order:
 *
 *   0x02060764  block extent            the two ends of a block from its header
 *   0x02060790  unlink                  remove a block from a MBlockList
 *   0x020607B8  link-after              insert a block after a given one
 *   0x020607E8  make-block              write a header over a 2-word region
 *   0x02060814  heap layout             lay the 0x38-byte handle out in place
 *   0x02060888  carve                   cut an allocation out of a free block
 *   0x02060A08  alloc from head         smallest-fit walk, align up
 *   0x02060ABC  alloc from tail         smallest-fit walk, align down
 *   0x02060B6C  free-list re-insert     splice back and coalesce neighbours
 *   0x02060C5C  create                  align the arena, size-check, lay out
 *   0x02060CA0  alloc front door        round up, dispatch on alignment sign
 *   0x02060E30  free                    (cluster_02060C5C) unlink and coalesce
 *
 * The heap sits UNDER the game's own heap layer: src/matched/sub_02030098.c
 * calls func_02060CA0 once it has picked the arena, and the sign of the
 * alignment argument is how that layer spells "take this from the high end".
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x020607\|address:  0x020608\|address:  0x020609\|\
 *            address:  0x02060A\|address:  0x02060B\|address:  0x02060C" \
 *        src/matched/*.c
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  The block header's `ldrh [blk, #2]` followed by an
 * ARITHMETIC shift pair is what makes the attribute halfword an int temporary
 * at its use rather than a u16 one (func_02060764); the free walk's unsigned
 * `cmp` against `block->size` versus the tail walk's signed `subs`/`bmi` is
 * what separates func_02060A08 from func_02060ABC.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THIS CLUSTER IS MIXED, and that is the single most expensive thing to get
 * wrong here.  Eleven of its twelve functions are byte-exact under the project
 * default dsi/1.1p1.  ONE is byte-exact only under `--cc ../2.0/sp2`:
 *
 *   func_02060814
 *
 * The tell is docs/idioms/a-repeated-small-constant-takes-a-callee-saved-
 * register.md, the same one docs/families/cluster_020737C0.h records: the
 * function materialises the literal 0 at two separate points, 1.1p1 pools it
 * into a callee-saved register and reuses it, which widens the prologue by a
 * slot and shifts every later register.  On func_02060814 that is exactly
 * `push {r4, r5, lr}` compiled against the image's `push {r3, r4, lr}`, with
 * the `mov r0, #0` at +0x20 and the `mov r1, #0` at +0x54 collapsed into one
 * `mov r4, #0`.  Under the pin the identical C is 0 mismatches.
 *
 * RECOGNITION RULE: size-exact or a few bytes short, every instruction and
 * relocation structurally right, and a `push`/`pop` list ONE REGISTER WIDER
 * than the image's.  Change the compiler, not the source.  The converse also
 * holds -- do not reach for the pin on a residue that is a register
 * PERMUTATION at the same push width; that is an allocation tie and the
 * permuter's ground, not the front end's.  It was measured on this cluster's
 * standing residue func_02060B6C and sp2 is no better there.
 *
 * See docs/FRONTEND-PINS.md for func_02060814's evidence row.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02060764_H
#define CLUSTER_02060764_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

/* ================================================================== *
 * 1.  struct MBlock -- the 0x10-byte block header
 *
 * Every allocation and every free region carries one of these immediately
 * BEFORE its data, which is why every conversion between a block and its
 * payload in this cluster is a plain +/- 0x10.
 *
 * Field evidence:
 *   +0x00  signature, a HALFWORD.  func_020607E8 writes it with
 *          `strh` from its second argument; func_02060888 passes 0x4652
 *          ('FR', a free block) and 0x5544 ('UD', a used one), and
 *          func_02060B6C passes 0x4652 -- the pool words at 0x02060884 and
 *          0x02060C58 are both the bare 0x00004652.
 *   +0x02  attr, a HALFWORD, three packed fields, all evidenced by
 *          func_02060888's three clear-then-set statement PAIRS:
 *            bits 0..7   the heap's group id       (`& ~0xff`   / `| id`)
 *            bits 8..14  distance to the PRECEDING block, in bytes
 *                        (`& ~0x7f00` / `| ((sz & 0x7f) << 8)`)
 *            bit  15     the direction the carve came from
 *                        (`& ~0x8000` / `| (fromTail << 15)`)
 *          func_02060764 READS bits 8..14 back as `(f >> 8) & 0x7f` to
 *          recover the block's own start.  The pairs are load-bearing: three
 *          masked assignments emit one store per field where the image has
 *          two.
 *   +0x04  size, the payload length in bytes.  `ldr r2, [r4, #4]` in
 *          func_02060B6C and func_02060CD0; func_020607E8 computes it as
 *          `end - (block + 0x10)`.
 *   +0x08  prev, +0x0c  next.  func_02060790's unlink writes `[a, #0xc]`
 *          and `[b, #8]`; func_02060A08's head walk advances through +0x0c
 *          and func_02060ABC's tail walk through +0x08.
 * ================================================================== */
struct MBlock {
    u16            signature;   /* 0x00  0x4652 free / 0x5544 used           */
    u16            attr;        /* 0x02  group | (gap << 8) | (dir << 15)    */
    u32            size;        /* 0x04  payload bytes                       */
    struct MBlock *prev;        /* 0x08                                      */
    struct MBlock *next;        /* 0x0c                                      */
};

/* The head/tail pair every list in the heap is.  func_02060790 and
   func_020607B8 both take one; func_02060888 is handed &heap->freeList and
   &heap->usedList at different call sites. */
struct MBlockList {
    struct MBlock *head;        /* 0x00 */
    struct MBlock *tail;        /* 0x04 */
};

/* The two-word extent every internal boundary is passed as.  func_02060764
   FILLS one; func_020607E8 and func_02060B6C CONSUME one.  Declaring it as a
   struct rather than two scalars is load-bearing in the OPPOSITE direction at
   two call sites -- see the note under func_02060888 below. */
struct MemRegion {
    int start;                  /* 0x00 */
    int end;                    /* 0x04 */
};

/* ================================================================== *
 * 2.  struct ExpHeap -- the 0x38-byte heap handle
 *
 * Laid out by func_02060814 at the very start of the arena it manages, so the
 * handle and its own heap share one allocation.  The first 0x24 bytes are the
 * common arena header func_020606D0 fills (see
 * docs/families/cluster_02060550.h, `struct Arena`), and +0x24 onward is the
 * expanded heap's own record.
 *
 * Field evidence:
 *   +0x18  lo, +0x1c  hi.  func_02060814 reads both back out of the header
 *          func_020606D0 just wrote and hands the pair to func_020607E8 as
 *          the first free block's extent.
 *   +0x20  attr.  func_02060888 reads it as `(u8)((u32 *)heap)[-1] & 1`
 *          relative to the FREE LIST pointer it was handed -- bit 0 is the
 *          "clear on allocate" feature and the `(u8)` cast is load-bearing,
 *          since a bare `& 0xff` folds away and loses the `and r0, r0, #0xff`.
 *   +0x24  freeList, +0x2c  usedList.  func_02060814 seeds the free list with
 *          one block spanning the arena and leaves the used list empty;
 *          func_02060888 moves the carved block from the first to the second.
 *   +0x34  groupId, a HALFWORD (`strh [r4, #0x34]`), stamped into every
 *          block's attribute low byte.
 *   +0x36  feature, a HALFWORD.  Bit 0 is the ALLOCATION MODE, read by both
 *          walkers as `(u16)(heap->feature & 1) == 0` meaning "smallest fit";
 *          func_02060814 clears it with a `bic r0, r0, #1` that only survives
 *          if the FIELD is read back (see that file's header).
 * ================================================================== */
struct ExpHeap {
    u8                pad_00[0x18];
    void             *lo;           /* 0x18 */
    void             *hi;           /* 0x1c */
    u32               attr;         /* 0x20  bit 0: clear on allocate        */
    struct MBlockList freeList;     /* 0x24 */
    struct MBlockList usedList;     /* 0x2c */
    u16               groupId;      /* 0x34 */
    u16               feature;      /* 0x36  bit 0: 0 = smallest fit         */
};

/* The heap's 'EXPH' signature, the pool word at 0x02060880.  func_02060814
   passes it to func_020606D0 as the SECOND argument. */
#define EXPHEAP_SIGNATURE   0x45585048u

/* Block signatures, the pool words at 0x02060884 and 0x02060C58. */
#define MBLOCK_SIG_FREE     0x4652      /* 'FR' */
#define MBLOCK_SIG_USED     0x5544      /* 'UD' */

/* The smallest region that can still become a block: a 0x10-byte header plus
   one word.  func_02060888 snaps a remainder below this to the block's own
   edge; func_02060B6C drops a coalesced region below it entirely. */
#define MBLOCK_MIN_SPLIT    0x14
#define MBLOCK_MIN_REGION   0x10

/* The smallest arena that can hold a heap: the 0x38-byte handle plus a header
   plus a word.  func_02060C5C's `cmp r3, #0x4c`. */
#define EXPHEAP_MIN_ARENA   0x4c

/* ================================================================== *
 * 3.  Prototypes, with the exact parameter types the matched sources use
 * ================================================================== */

/* 0x02060764  EXACT.  Write the block's two ends into `out`.  out[0] is the
   block's own start, recovered from the attribute's bits 8..14; out[1] is the
   block's end.  The `out` pair is TWO SCALARS at its callers, never a struct
   -- see func_02060E30. */
extern void func_02060764(int *out, struct MBlock *blk);

/* 0x02060790  EXACT.  Unlink `node`; returns its former `prev`. */
extern struct MBlock *func_02060790(struct MBlockList *list, struct MBlock *node);

/* 0x020607B8  EXACT.  Link `node` after `after` (a null `after` prepends);
   returns `node`. */
extern struct MBlock *func_020607B8(struct MBlockList *list, struct MBlock *node,
                                    struct MBlock *after);

/* 0x020607E8  EXACT.  Write a header with signature `sig` over the region
   `pair` names, and return the new block.  Takes the pair as an `int *`
   because its callers spell the base differently at different sites. */
extern struct MBlock *func_020607E8(int *pair, u16 sig);

/* 0x02060814  EXACT, **PINNED TO ../2.0/sp2** (see the pin section above).
   Lay the heap handle out over an already-aligned, already-size-checked
   arena and seed the free list with one block spanning the rest. */
extern void *func_02060814(struct ExpHeap *heap, void *lo, u32 attr);

/* 0x02060888  EXACT.  The carve: unlink the chosen block, cut the allocation
   out of it, and put the remainders back as free blocks around it.  Three
   shapes in its own header are load-bearing and easy to lose -- the first
   2-word region must be TWO SCALARS while the other two are `struct
   MemRegion` (three structs cost a sixth callee-saved register), the clear
   size must pass through the `sz` local, and the attribute must be three
   clear-then-set PAIRS.  Read src/matched/func_02060888.c before touching it.
   NOTE the first parameter: it is `&heap->freeList`, not the heap. */
extern void *func_02060888(struct MBlockList *freeList, struct MBlock *block,
                           void *ptr, u32 size, u16 fromTail);

/* 0x02060A08 / 0x02060ABC  EXACT.  Smallest-fit walk from the head (aligning
   the data start UP) and from the tail (aligning the end DOWN).  Both stop
   early on the first hit in "first fit" mode and on an exact size match in
   either mode.  Their fifth argument to func_02060888 is the direction flag,
   0 from the head and 1 from the tail. */
extern void *func_02060A08(struct ExpHeap *heap, u32 size, s32 align);
extern void *func_02060ABC(struct ExpHeap *heap, u32 size, s32 align);

/* 0x02060B6C  open, standing residue at 52 concrete bytes / 240 size-exact
   (docs/notes/pkt_02060B6C.c.txt).  Splice a freed region back into the free
   list, coalescing with the block that starts at its end and with the block
   that ends at its start.  Returns 1 when a block was made, 0 when the
   region was too small to hold one. */
extern int func_02060B6C(struct MBlockList *freeList, struct MemRegion *rgn);

/* 0x02060C5C  EXACT.  The create front door: word-align the arena (start up,
   end down), reject it if the rounding inverted the range OR left under
   0x4c bytes -- ONE `||`, not two `if`s -- and lay the handle out.  The end
   address is `size + (u32)start`, the commutative-operand-order tell. */
extern void *func_02060C5C(void *start, u32 size, u32 attr);

/* 0x02060CA0  EXACT.  The alloc front door: a zero-byte request still costs
   one word, the size rounds up to a word, and the SIGN of the alignment
   picks the head or the tail walk. */
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);

/* 0x02060E30  EXACT (cluster_02060C5C).  The free primitive. */
extern void func_02060E30(struct ExpHeap *heap, void *block);

/* The clear helper func_02060888 calls under the heap's feature bit 0. */
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

#endif /* CLUSTER_02060764_H */
