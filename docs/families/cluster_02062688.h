/*
 * docs/families/cluster_02062688.h -- shared declarations for the
 * pseudo-family at 0x02062688..0x02062B64 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so unlike docs/families/mcss.h this cluster is NOT a
 * recovered original translation unit.  It was formed by address adjacency plus
 * shared callees and data objects, and here that grouping is unusually tight:
 * every function in the range is part of ONE subsystem, the
 * NNS G2D BINARY-RESOURCE ACCESSOR LAYER (the NITRO file format reader that
 * NCGR / NCLR / NCER / NANR / NMCR / NSCR assets are unpacked through).
 *
 * The subsystem has exactly three kinds of function, and every member is one
 * of them:
 *
 *   A. THE BLOCK FINDER, func_02062B64.  Walks a loaded NITRO file's block
 *      chain from the file header's headerSize (u16 at +0x0C) for numBlocks
 *      (u16 at +0x0E) blocks and returns the first whose 4-character signature
 *      matches, else NULL.  ONE function, called by every accessor.
 *
 *   B. THE ACCESSORS, one per block signature.  All eight are the same six
 *      lines: call func_02062B64 with a tag, return 0 with `*out = 0` if the
 *      block is absent, otherwise run the format's fixup on (block + 8) and
 *      hand that back through `*out`, returning 1.  The +8 is the block
 *      header {u32 signature; u32 size} the body follows.  The tag constant is
 *      how the family is recognised straight out of the literal pool:
 *
 *        0x02062634  'KNBA'  0x4142_4E4B  -> func_02062688   (NANR body)
 *        0x02062820  'KBEC'  0x4345_424B  -> func_02062884   (NCER body)
 *        0x02062920  'KBCM'  0x4D43_424B  -> func_0206296C   (NMCR body)
 *        0x02062A00  'RAHC'  0x4348_4152  -> func_02062A3C   (NCGR body)
 *        0x02062A4C  'RAHC'  0x4348_4152  -> func_02062A88   (NCGR, 2nd entry)
 *        0x02062A98  'TTLP'  0x504C_5454  -> func_02062B20   (NCLR body)
 *        0x02062AD4  'PMCP'  0x5043_4D50  -> func_02062B10   (palette map)
 *        0x02062B30  'NRCS'  0x5343_524E  -> (no fixup)      (NSCR body)
 *
 *      func_02062670 and func_0206267C are two further thin wrappers that
 *      forward to func_02062634 unchanged.
 *
 *   C. THE FIXUPS, one per format.  Each turns the block body's stored
 *      SELF-RELATIVE OFFSETS into absolute pointers, in place, exactly once.
 *      The trivial ones are a single field (func_02062A3C and func_02062A88
 *      at +0x14, func_02062B10 at +0x04, func_02062B20 at +0x0C); the three
 *      substantial ones walk nested arrays (func_02062688 the NANR bank,
 *      func_02062884 the NCER bank, func_0206296C the NMCR bank).
 *
 *   Two further members are pure getters that the rest of the game calls with
 *   an index: func_020627D8 (sequence by index, NANR), func_0206285C (cell by
 *   index, NCER), func_020629E8 (multi-cell by index, NMCR).  func_020627F0 is
 *   the one hand-written `asm` leaf in the range, the "address past the last
 *   cell record" helper func_02062884 adds to every cell's OAM offset.
 *
 * Derived from the 19 matched sources found with
 *   grep -l "address:  0x02062[6-9A-B]" src/matched/*.c
 * and from docs/notes/pkt_02062688.c.txt, docs/notes/func_0206296C.c.txt,
 * docs/notes/pkt_02062B30.c.txt and docs/notes/func_020627F0.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrh` proves a 16-bit field, `ldrb` an 8-bit one, a
 * scaled register offset (`lsl #3`, `lsl #4`, an `add #0xc`) proves an array's
 * STRIDE and nothing else, and a plain `ldr` followed by an `add` of the base
 * proves only that the word is a self-relative offset.
 *
 * ============================================================================
 * THE COMPILER PIN.  There ISN'T one -- and that is worth stating.
 * ============================================================================
 *
 * Every one of the 19 matched sources in this range carries `compiler: 1.1p1`,
 * the project default, and both functions closed in wave 7 (func_0206296C and,
 * in the sibling cluster, func_020948E0) closed under it too.  Unlike
 * docs/families/cluster_020737C0.h there is no `../2.0/sp2` sub-family here:
 * a size-exact compile whose push list is one register WIDER than the image's
 * in THIS range is not a compiler tell, it is a live-value count -- see the
 * lever below.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 *
 * ============================================================================
 * THE LEVER THIS CLUSTER IS ABOUT: A RE-READ THE OPTIMISER DELETES.
 * ============================================================================
 *
 * Every fixup in group C has the same shape -- store a relocated pointer into
 * a field, then READ THAT FIELD BACK to walk what it now points at -- and at
 * -O4,p mwccarm forwards the stored value instead of re-loading it, which is
 * four bytes short every time.  This was recorded as a wall on BOTH
 * func_0206296C (120 of 124 bytes, docs/notes/func_0206296C.c.txt) and
 * func_02062688 (docs/notes/pkt_02062688.c.txt) before wave 7.
 *
 * What reproduces the re-load, measured on func_0206296C:
 *
 *   1. the bank pointer is `volatile`-qualified.  This is what stops the two
 *      adjacent fixups being scheduled in parallel into two scratch registers,
 *      which is a separate 8-byte difference of its own.
 *   2. the re-load is spelled as an explicit `*(volatile u32 *)((u8 *)bank + 4)`
 *      cast read into a local.  A plain `array = bank->array` is STILL folded
 *      even when the struct pointer is volatile; the cast read is not.
 *   3. the loop bound is re-read at the BOTTOM of the loop body, which is what
 *      puts the count's `ldrh` AHEAD of the array re-load rather than behind
 *      it -- the two loads' order is visible in the image and is evidence.
 *
 * What does NOT work, all measured: a `static` helper taking the field's
 * address (not inlined at all -- it compiles to three real `bl`s); volatile
 * STORES with plain reads (the reads hoist above the stores); a `volatile`
 * struct-typed pair copy (it spills to a stack home); and a plain struct-typed
 * pair copy (same).
 *
 * The remaining open function of the cluster, func_02062688, is a measured
 * 328/336 near miss at exactly this point -- see docs/notes/pkt_02062688.c.txt.
 * Its image loads the +0x04/+0x08 pair back with ONE `ldmib r0, {r4, r5}`, and
 * `volatile` is what blocks that merge: the re-load and the merge cannot
 * currently be had at the same time.  A source that gets both is the whole
 * remaining puzzle; everything else in that function is byte-identical.
 * ============================================================================
 */

#ifndef CLUSTER_02062688_H
#define CLUSTER_02062688_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  The NITRO container
 *
 * func_02062B64 is the only reader of these two, and it constrains them
 * exactly: headerSize is `ldrh [r0,#0xc]`, numBlocks `ldrh [r0,#0xe]`, and
 * the walk advances by the block's own `size`, so `size` covers the header.
 * ================================================================== */

struct NitroBlock {
    u32 signature;              /* +0x00  four ASCII characters, little-endian */
    u32 size;                   /* +0x04  the WHOLE block, header included     */
};

struct NitroFileHeader {
    u32 magic;                  /* +0x00 */
    u32 unk04;                  /* +0x04 */
    u32 fileSize;               /* +0x08 */
    u16 headerSize;             /* +0x0c  where the block chain starts         */
    u16 numBlocks;              /* +0x0e */
};

#define NITRO_BLOCK_BODY    8   /* every accessor hands back block + 8         */

/* Block signatures, as the literal pool spells them (little-endian words). */
#define SIG_KNBA            0x4142424B  /* 'KNBA' -- NANR cell-animation bank  */
#define SIG_KBEC            0x4345424B  /* 'KBEC' -- NCER cell data bank       */
#define SIG_KBCM            0x4D43424B  /* 'KBCM' -- NMCR multi-cell bank      */
#define SIG_RAHC            0x43484152  /* 'RAHC' -- NCGR character data       */
#define SIG_TTLP            0x504C5454  /* 'TTLP' -- NCLR palette data         */
#define SIG_PMCP            0x50434D50  /* 'PMCP' -- palette compression map   */
#define SIG_NRCS            0x5343524E  /* 'NRCS' -- NSCR screen data          */

/* ================================================================== *
 * 1.  The NANR cell-animation bank ('KNBA' body)
 *
 * Field evidence, one function per line:
 *   +0x00  u16   func_020627D8's `cmp`, func_02062688's `ldrh r1,[r0]`
 *   +0x04  the sequence array.  func_020627D8's `lsl #4` pins the 16-byte
 *          stride; func_02062688's `add r2, r4, ip, lsl #4` agrees.
 *   +0x08  the frame-entry array, the base a SEQUENCE's +0x0c offset is
 *          relative to (func_02062688: `add r7, r5, r7` where r5 is this
 *          field and r7 the sequence's +0x0c word).
 *   +0x0c  the frame-data pool, the base a FRAME's +0x00 offset is relative
 *          to (func_02062688's r6).
 *   +0x14  an embedded NMCR-shaped sub-bank, or 0.  func_02062688 relocates
 *          it and then fixes up (sub + 8) -- i.e. the sub-object is itself a
 *          NITRO block and its BODY starts 8 bytes in.
 * ================================================================== */

struct AnimFrame {              /* stride 8, func_02062688's `lsl #3`          */
    u32 data;                   /* +0x00  offset into the frame-data pool      */
    u32 duration;               /* +0x04                                       */
};

struct AnimSequence {           /* stride 0x10, func_020627D8's `lsl #4`       */
    u16 numFrames;              /* +0x00 */
    u16 loopStartFrameIdx;      /* +0x02 */
    u32 animType;               /* +0x04  low byte 0/1/2 picks the frame-data
                                           record shape, see func_0206419C     */
    u32 playMode;               /* +0x08 */
    struct AnimFrame *frames;   /* +0x0c  offset, relative to the bank's +0x08 */
};

struct AnimBank {
    u16 numSequences;           /* +0x00 */
    u16 numTotalFrames;         /* +0x02 */
    struct AnimSequence *seq;   /* +0x04 */
    struct AnimFrame *frames;   /* +0x08 */
    u8 *pool;                   /* +0x0c */
    u32 unk10;                  /* +0x10 */
    u8 *sub;                    /* +0x14  an embedded NITRO block, or 0        */
};

/* ================================================================== *
 * 2.  The NCER cell data bank ('KBEC' body)
 *
 *   +0x02  bankAttr, bit 0: cells carry a bounding box.  func_0206285C's
 *          `tst #1` plus its two shifts pin BOTH cell strides -- 8 bytes for
 *          a plain cell, 16 for one with the extra rectangle.
 *   +0x04  the cell array.  func_02062884 relocates it, then adds
 *          func_020627F0's result (the address PAST the last cell record) to
 *          each cell's own +0x04 OAM offset: an OAM offset is relative to the
 *          byte after the cell array, not to the block.
 *   +0x0c  VRAM transfer data, or 0.  func_02062884 relocates it AND the
 *          +0x04 field of what it points at.
 *   +0x14  an embedded cell-animation bank, or 0, handed to func_02062810.
 * ================================================================== */

struct Cell {                   /* stride 8, or 16 when bankAttr bit 0 is set  */
    u16 numOam;                 /* +0x00 */
    u16 cellAttr;               /* +0x02 */
    void *oam;                  /* +0x04  offset, relative to past the array   */
};

struct CellDataBank {
    u16 numCells;               /* +0x00 */
    u16 bankAttr;               /* +0x02  bit 0: cells carry a bounding box    */
    void *cells;                /* +0x04 */
    u32 mappingType;            /* +0x08 */
    void *vramTransfer;         /* +0x0c  or 0                                 */
    u32 unk10;                  /* +0x10 */
    void *animBank;             /* +0x14  or 0                                 */
};

/* ================================================================== *
 * 3.  The NMCR multi-cell bank ('KBCM' body)
 *
 * Pinned by func_020629E8 (the `lsl #3` stride) and func_0206296C (the
 * fixup).  A 10- or 12-byte descriptor stride is not what this game reads.
 * ================================================================== */

struct MultiCellData {          /* stride 8 */
    u16 numNodes;               /* +0x00 */
    u16 unk02;                  /* +0x02 */
    u32 nodes;                  /* +0x04  offset, relative to the bank's +0x08 */
};

struct MultiCellBank {
    u16 numMultiCell;           /* +0x00 */
    u16 unk02;                  /* +0x02 */
    struct MultiCellData *array;/* +0x04 */
    u32 nodeBase;               /* +0x08  what a descriptor's +0x04 is off     */
    u32 unk0C;                  /* +0x0c */
    u8 *animBank;               /* +0x10  embedded 'KNBA' body, or 0           */
};

/* The per-node record func_02062688's SECOND half walks, stride 0x0c (the
   image's `add r3, r3, #0xc`).  Its +0x08 array is a run of u32 offsets, one
   per cell, stepped four bytes at a time (`add r8, r8, #4`).                  */
struct MultiCellNode {          /* stride 0x0c */
    u16 numCells;               /* +0x00 */
    u16 unk02;                  /* +0x02 */
    u8 *unk04;                  /* +0x04 */
    u32 *cells;                 /* +0x08  array of numCells offsets            */
};

/* ================================================================== *
 * 4.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- A: the block finder ------------------------------------------------- */
extern void *func_02062B64(struct NitroFileHeader *file, u32 signature);

/* --- B: the accessors.  All return 1 on success, 0 with *out = 0 else. ---- */
extern s32   func_02062634(struct NitroFileHeader *file, void **out); /* KNBA */
extern void  func_02062670(void);                      /* forwards to 02062634 */
extern void  func_0206267C(void);                      /* forwards to 02062634 */
extern s32   func_02062820(struct NitroFileHeader *file, void **out); /* KBEC */
extern s32   func_02062920(struct NitroFileHeader *file, void **out); /* KBCM */
extern s32   func_02062A00(struct NitroFileHeader *file, void **out); /* RAHC */
extern s32   func_02062A4C(struct NitroFileHeader *file, void **out); /* RAHC */
extern s32   func_02062A98(struct NitroFileHeader *file, void **out); /* TTLP */
extern s32   func_02062AD4(struct NitroFileHeader *file, void **out); /* PMCP */
extern s32   func_02062B30(struct NitroFileHeader *file, void **out); /* NRCS */

/* --- B: the indexed getters ---------------------------------------------- */
extern struct AnimSequence  *func_020627D8(struct AnimBank *bank, u32 idx);
extern void                 *func_0206285C(struct CellDataBank *bank, u32 idx);
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);

/* --- C: the fixups ------------------------------------------------------- */
extern void func_02062688(volatile struct AnimBank *bank);      /* 336 B, open */
extern void func_02062884(struct CellDataBank *bank);
extern void func_0206296C(volatile struct MultiCellBank *bank);
extern void func_02062A3C(u8 *block);   /* +0x14 += block */
extern void func_02062A88(u8 *block);   /* +0x14 += block */
extern void func_02062B10(u8 *block);   /* +0x04 += block */
extern void func_02062B20(u8 *block);   /* +0x0c += block */

/* --- the helpers the fixups call ----------------------------------------- */

/* The one hand-written asm leaf: "address past the last cell record".
   `ldrh r1,[r0,#2] / tst r1,#1 / ldrh r1,[r0] / add r0, cells, n << (4 or 3)`. */
extern void *func_020627F0(struct CellDataBank *bank);

/* NOT functions: both of these addresses hold a linker stub of the shape
     ldr ip,[pc,#4] ; add r0, r0, #8 ; bx ip ; .word <real callee>
   i.e. a veneer that ALSO adds 8 to its first argument -- the NITRO block
   header skip.  `veneer_at()` in tools/match.py refuses them (it only knows
   the two plain encodings), so a call site here never resolves through the
   `veneer` class; see src/matched/func_02062884.c's header for the full
   write-up.  Declare them as ordinary externs at the STUB's address. */
extern void func_02062810(void *p);     /* -> 0x02062BAC */
extern void func_0206295C(void *p);     /* -> 0x02062BAC */

/* ================================================================== *
 * 5.  Constants
 * ================================================================== */
#define ANIM_SEQ_STRIDE     0x10    /* func_020627D8's `lsl #4`                */
#define ANIM_FRAME_STRIDE   8       /* func_02062688's `lsl #3`                */
#define CELL_STRIDE_PLAIN   8       /* func_0206285C, bankAttr bit 0 clear     */
#define CELL_STRIDE_BBOX    16      /* func_0206285C, bankAttr bit 0 set       */
#define MCELL_DATA_STRIDE   8       /* func_020629E8's `lsl #3`                */
#define MCELL_NODE_STRIDE   0x0c    /* func_02062688's `add r3, r3, #0xc`      */

/* WAVE 12 (2026-09-23): THE "NO PIN" STATEMENT ABOVE IS WITHDRAWN.
   func_02062688 and func_02062B30 both closed EXACT under ../2.0/sp2 and are
   DIFF under 1.1p1 in every spelling measured:
     - func_02062688: the re-load + `ldmib` pair the header calls "the whole
       remaining puzzle" is what 2.0/sp2 emits for the note's a9 spelling
       (volatile bank, pair read through a non-volatile BankPair view).  Also
       needed: AnimFrame.data is a `void *` (relocated as
       `(void *)((u32)data + (u32)pool)`), `&mc->nodes[k]` with u32 k, and
       the inner walk a guarded do-while with its byte cursor set inside the
       guard.
     - func_02062B30: the POSITIVE accessor spelling (`if (b) {...return 1;}
       else {...return 0;}`) under 2.0 predicates only the zero arm.
   Rule for this cluster now: a 1.1p1 wall here is a pin probe first.        */

#endif /* CLUSTER_02062688_H */
