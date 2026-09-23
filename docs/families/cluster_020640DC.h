/*
 * docs/families/cluster_020640DC.h -- shared declarations for the
 * pseudo-family at 0x020640DC..0x02064AB4 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so unlike docs/families/mcss.h this cluster is NOT a
 * recovered original translation unit; it was formed by address adjacency plus
 * shared callees and data objects.  Unlike docs/families/cluster_020737C0.h it
 * is ONE subsystem throughout:
 *
 *   THE NNS G2D MULTI-CELL ANIMATION CONTROLLER.  Every function here drives
 *   the per-node state of a multi-cell (NMCR/NANR) animation: the three SRT
 *   setters at the bottom (func_020640DC translate, func_02064100 rotate,
 *   func_02064120 scale) and the dirty-flag opener func_02064140, the binders
 *   that attach a cell bank to an animation object (func_02064178,
 *   func_0206428C, func_020642C8, func_02064754), the two bank-sizing leaves
 *   (func_02064648 cell-anim count, func_020648E0 node count, and the
 *   func_020648B4 that picks between their strides), the per-node steppers
 *   (func_02064364 by tick, func_02064384 by frame, func_020643A4 restart) and
 *   the four whole-object walks that rebuild every node's SRT block from its
 *   current NANR frame record (func_0206419C, func_0206469C, func_020649D4,
 *   func_02064AB4).  It reaches the resource layer through func_020627D8 /
 *   func_020629E8 and the cell-animation layer through func_02062D40 /
 *   func_02062D4C / func_02062F00 / func_02062F38 / func_02062F90 /
 *   func_02062FF0 / func_0206434C.  There is no global state: everything is
 *   reached through the animation object passed in r0.
 *
 * Derived from the 15 matched sources found with
 *   grep -l "address:  0x02064[0-9A]" src/matched/*.c
 * and from the notes docs/notes/pkt_020640DC.c.txt,
 * docs/notes/pkt_02064178.c.txt, docs/notes/pkt_020643CC.c.txt,
 * docs/notes/pkt_0206469C.c.txt, docs/notes/pkt_02064754.c.txt,
 * docs/notes/func_02064934.c.txt and
 * docs/notes/pkt_02064934.func_020649D4.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsh` proves signedness; `ldmib`/`stmib` proves
 * two adjacent words are read or written as a pair; a plain `ldr` followed by
 * `and #0xff` proves the FIELD is 32-bit and the narrowing happens at the use
 * (this is why the switch selector below is `u32 & 0xff` and never a `ldrb`).
 * Where two matched files disagree, the file whose code actually constrains
 * the field wins.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * SIX of this cluster's functions are byte-exact only under `--cc ../2.0/sp2`
 * and are DIFF under the project default dsi/1.1p1:
 *
 *   func_02064178  func_0206428C  func_0206419C
 *   func_0206469C  func_020649D4  func_02064AB4
 *
 * That is every non-leaf function in the cluster that has been closed.  The
 * pin is a CLUSTER PROPERTY here, not a per-function accident: assume it and
 * probe the default only if the pin fails.  Wave 7 (2026-09-22) closed four
 * rows with it, three of them on the FIRST compile of C that earlier lanes had
 * already measured as DIFF under 1.1p1 -- no change to the C at all.
 *
 * The pin shows up in three of the four recognised forms, all of them
 * instances of "1.1p1 optimises harder than the image's front end did":
 *
 *   a. THE CROSS-JUMP (kept branches).  The image writes a call tail out in
 *      its own switch arm although another arm ends in a byte-identical pair.
 *      1.1p1 -O4,p cross-jumps the two and lands 4 or 8 bytes short.  This is
 *      the tell on func_0206419C, func_0206469C, func_020649D4 and
 *      func_02064AB4 -- ALL FOUR of the cluster's SRT-rebuild walks, on their
 *      shared `add r0, self, #X` / `bl func_020640DC` tail.
 *      Symptom to recognise instantly: a compile 4 or 8 bytes SHORT whose
 *      relocation-site COUNT is also short by one or two.
 *   b. KEPT CONSTANTS, allocation form.  The image materialises a small
 *      literal into a scratch register at the point of use and stores it in
 *      source order; 1.1p1 allocates it to a different register and sinks the
 *      store below the next call's argument setup.  Same size, ~17 bytes out.
 *      func_0206428C's `mvn r2, #0` sentinel is the case.
 *   c. KEPT CONSTANTS, tail-call form.  The image materialises a zero and
 *      stores it BEFORE loading the tail-call pool word; 1.1p1 hoists the pool
 *      load above the stores, posts the zero store after them and drops an
 *      instruction.  func_02064178 is the case (32 bytes against 36).
 *
 * If a function in this range is size-exact but a register-allocation or a
 * store-order out, or is 4/8 bytes short at a shared call tail, CHANGE THE
 * COMPILER, NOT THE SOURCE.  Three of wave 7's four closes cost one compile
 * each once that was assumed.
 *
 * THE THREE SRT SETTERS ARE THE EXCEPTION and are pinned the OTHER way.
 * func_020640DC / func_02064100 / func_02064120 are EXACT under the DEFAULT
 * 1.1p1 at -O1 (see src/matched/unit_020640DC.c, which files all three as one
 * tu-verified unit).  They are 4 bytes short under 1.1p1 -O4,p, because -O4,p
 * if-converts their five-instruction guarded block (`ldrheq`/`orreq`/`strheq`)
 * and drops the image's `bxne lr`; docs/notes/pkt_020640DC.c.txt measured five
 * spellings against that wall before -O1 was tried.  Do not re-derive them.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_020640DC_H
#define CLUSTER_020640DC_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 1.  struct Srt -- the per-node SRT control block, 0x14 bytes
 *
 * The cluster's most-referenced object: four of its functions exist only to
 * write one field of it, and every whole-object walk ends by driving them.
 *
 * Field evidence, one function per line:
 *   +0x00  mode.  EVERY setter opens `if (mode != 1) return;` -- the image's
 *          `cmp r0, #1` / `bxne lr` pair.  1 = SRT enabled.
 *   +0x04  \  scale x, y.  func_02064120 writes the PAIR, and the image fuses
 *   +0x08  /  the two stores into one `stmib r0, {r1, r2}`, which is what
 *             proves they are adjacent 32-bit words and written together.
 *             fx32 (16.16), from the <<12 the callers apply.
 *   +0x0c  \  translate x, y.  SIGNED 16-bit: every caller reads its source
 *   +0x0e  /  through `ldrsh` (0x02064A54/0x02064A58 in func_02064AB4 and
 *             0x02064A80/0x02064A84 for the second pair), and immediate-offset
 *             `ldrsh` is the only evidence of signedness there is.
 *   +0x10  rotation.  UNSIGNED 16: func_02064100's caller reads its source
 *          through a plain `ldrh` (0x02064A74), never `ldrsh`.
 *   +0x12  dirty flags.  Three bits, one per setter, each set with a separate
 *          `orr`: bit1 (2) scale, bit2 (4) rotation, bit3 (8) translation.
 *          func_02064140 writes the whole block's "open" word, not this.
 * ================================================================== */
struct Srt {
    u32 mode;               /* 0x00  1 = SRT enabled; every setter no-ops    */
    s32 scaleX;             /* 0x04  fx32   \  written as a PAIR (stmib)     */
    s32 scaleY;             /* 0x08  fx32   /                                */
    s16 tx;                 /* 0x0c  SIGNED (ldrsh at every source site)     */
    s16 ty;                 /* 0x0e  SIGNED                                  */
    u16 rot;                /* 0x10  UNSIGNED (plain ldrh at the source)     */
    u16 dirty;              /* 0x12  bit1 scale, bit2 rotation, bit3 xlate   */
};

/* ================================================================== *
 * 2.  struct CellAnim -- one cell animation's state, 0x5C bytes
 *
 *   +0x0c  active flag, set to 1 by func_020643A4 and by both arms of
 *          func_020643CC's node walk.
 *   +0x58  "already initialised this pass" latch.  func_020643CC zeroes one
 *          per cell anim up front and sets it as it visits each; func_02064754
 *          sets it on every cell of the FLAT shape.  This is what makes the
 *          node walk idempotent when two nodes share a cell animation.
 *
 * The 0x5C stride is fixed by the `mla r7, r0, r1, r5` at 0x0206445C with
 * `mov r1, #0x5c`, and again by func_020648B4's `* 0x5c`.
 * ================================================================== */
struct CellAnim {
    u8  pad_00[0x0c];
    u32 active;             /* 0x0c                                          */
    u8  pad_10[0x48];
    u32 initialised;        /* 0x58  per-pass latch                          */
};

/* ================================================================== *
 * 3.  The two array shapes, and the `kind` word that picks between them
 *
 * THE CLUSTER'S CENTRAL BRANCH.  func_020643CC, func_02064754 and
 * func_02064934 all open `if (obj->kind == 1)` and lay their cell array out
 * one of two ways.  Reading this wrong is a whole-function diff, so it is
 * spelled out:
 *
 *   kind == 1, THE FLAT SHAPE.  One array of 0x5C-byte struct CellAnim,
 *   sized by func_02064648(bank) (the largest per-multi-cell cell-anim
 *   count).  A node's cell animation is `&cells[i]`, `mla` with 0x5c.
 *
 *   anything else, THE TWO-LEVEL SHAPE.  func_020648E0(bank) 0x28-byte group
 *   headers first, then the cell array immediately after them at
 *   `cells + n * 0x28`, with a 0x58 stride (NOT 0x5c -- see the
 *   `mov r1, #0x58` at 0x0206482C).  A node's cell animation is the FIRST
 *   WORD of its group header, `ldr r0, [r5, r0]`, not an index.
 *
 * func_020648B4(bank, kind) returns the byte size of whichever shape `kind`
 * names, and is the allocator's sizing call: `func_02064648(bank) * 0x5c` for
 * kind 1, `func_020648E0(bank) << 7` otherwise.  Note the SHIFT: 0x80, not
 * 0x28 + 0x58; the two-level shape is allocated with slack.
 * ================================================================== */
struct Group {                  /* 0x28 bytes, the two-level shape's header  */
    struct CellAnim *anim;      /* 0x00  the node's cell animation           */
    u32 unk_04;
    u32 inuse;                  /* 0x08  set to 1 by func_02064178           */
    struct Srt srt;             /* 0x0c  func_02064178 tail-calls the opener */
    u8  pad_20[0x08];
};

/* ================================================================== *
 * 4.  struct MultiCell -- the NMCR bank and its records
 *
 * func_02064648 and func_020648E0 are the same loop over different fields of
 * the same 8-byte descriptor, which is what fixes the two halfwords:
 *   +0x00 numNodes      (func_020648E0's max)
 *   +0x02 numCellAnims  (func_02064648's max)
 * Both re-read `bank->count` from memory EVERY iteration (the rotated
 * `cmp count, #0` guard at the top is the tell), and both counters are u16
 * (the `lsl #0x10` / `lsr #0x10` pair per iteration).
 * ================================================================== */
struct MultiCellData {
    u16 numNodes;               /* 0x00                                      */
    u16 numCellAnims;           /* 0x02                                      */
    struct Node *nodes;         /* 0x04                                      */
};

struct MultiCellBank {
    u16 numMultiCell;           /* 0x00                                      */
    u16 unk_02;
    struct MultiCellData *array;/* 0x04                                      */
};

/* The NMCR node record, 8 bytes.  func_020643CC's walk constrains all four
   halfwords:
     +0x00 the cell/entry id handed to func_020627D8
     +0x02 \  SIGNED: written straight into the node's SRT translate through
     +0x04 /  func_020640DC(&rec->srt, node->x, node->y)
     +0x06 two packed fields: the HIGH byte is the cell-animation index
           (`and #0xff00` / `lsl #8` / `lsr #0x10`, NOT `>> 8 & 0xff`), the
           LOW nibble is a flag, ==1 meaning "seek this node into the loop".
   This record is where the a/0/0/4 rig placement question lands: the node's
   own signed (x, y) is the translation, verbatim, with no table between. */
struct Node {
    u16 id;                     /* 0x00                                      */
    s16 x;                      /* 0x02  SIGNED                              */
    s16 y;                      /* 0x04  SIGNED                              */
    u16 packed;                 /* 0x06  high byte = cell-anim index,
                                         low nibble = seek flag              */
};

/* The NANR frame record the SRT walks read, and its header.  The walks take
   the kind selector as a WORD masked with 0xff, never a `ldrb`:
       kind = *(u32 *)(hdr + 4) & 0xff;
   0 does nothing, 2 is the TRANSLATE-ONLY form, anything else is the full SRT
   form (scale pair, then rotation, then translate).  The three arms' field
   offsets differ between the two forms and that is not a mistake:
       kind == 2 : translate from +0x04/+0x06   (ldrsh, ldrsh)
       default   : scale from +0x04/+0x08 (ldmib, ONE pair load),
                   rotation from +0x02 (ldrh),
                   translate from +0x0c/+0x0e (ldrsh, ldrsh)  */
struct FrameRec {
    u16 id;                     /* 0x00                                      */
    u16 rot;                    /* 0x02  unsigned                            */
    s16 tx2;                    /* 0x04  kind==2 translate x; also scale x lo */
    s16 ty2;                    /* 0x06  kind==2 translate y                 */
    u32 scaleY;                 /* 0x08                                      */
    u8  pad_0c_[0];
    s16 tx;                     /* 0x0c  default-arm translate x             */
    s16 ty;                     /* 0x0e  default-arm translate y             */
};

struct FrameHdr {
    u8  pad_00[4];
    u32 kind;                   /* 0x04  masked with 0xff at every use       */
};

/* The 0x10-byte NANR entry func_020627D8 returns, walked by func_020643CC to
   sum the frame durations.  `count` is +0x00 and the frames are at +0x0c with
   an 8-byte stride whose duration halfword is at +0x04. */
struct Frame { u32 unk_00; u16 dur; u16 unk_06; };
struct Entry { u16 count; u16 unk_02; u32 unk_04; u32 unk_08; struct Frame *frames; };

/* ================================================================== *
 * 5.  struct Anim -- the animation object every entry point takes in r0
 *
 * No two matched sources spell this the same way (most use `char *self` with
 * literal offsets, which is what the image's `add r0, r4, #0x48` favours), so
 * the union below is written from the offsets they use rather than imposed:
 *
 *   +0x00  the frame keeper; `*(u32 *)self` then `+4` is a u16 frame count
 *          that every walk tests for zero before doing anything.
 *   +0x04  a SECOND keeper with the same `+4` u16 count.  func_020649D4 reads
 *          BOTH: +0x00's count is latched into a local before the step call
 *          and added to +0x30 after it; +0x04's count is the walk's guard.
 *   +0x1c  the frame header (struct FrameHdr) -- the switch selector's home.
 *   +0x30  a u16 progress counter, accumulated across steps and handed to
 *          func_020643CC as its third argument.
 *   +0x34  the multi-cell walk block (struct Root below), passed to
 *          func_020643CC and func_02064934 as `self + 0x34`.
 *   +0x38  the bound cell-bank row, or -1 for "none" (func_0206428C writes the
 *          sentinel, func_020642C8 writes a row).  func_0206419C's second
 *          guard tests it against -1 and must read it through
 *          `*(volatile int *)` to keep the image's separate `mvn r0, #0`.
 *   +0x3c  \  the SRT block.  ONE object at ONE of TWO offsets: the
 *   +0x48  /  func_0206419C family uses +0x3c, the func_02064AB4 family +0x48.
 *             That offset is the only structural difference between the two
 *             otherwise byte-identical walk families.
 *   +0x40  the cell array base (either shape, see section 3).
 *   +0x44  the NMCR bank.
 * ================================================================== */
struct Anim {
    void *keeper0;              /* 0x00                                      */
    void *keeper1;              /* 0x04                                      */
    u8    pad_08[0x14];
    struct FrameHdr *hdr;       /* 0x1c                                      */
    u8    pad_20[0x10];
    u16   progress;             /* 0x30                                      */
    u16   pad_32;
    u32   walk[4];              /* 0x34  struct Root, by address             */
    void *row;                  /* 0x38  -1 = none; read volatile as a guard */
    struct Srt srt_3c;          /* 0x3c  func_0206419C family                */
    /* +0x40 cell array base, +0x44 bank -- these OVERLAP srt_3c in the two
       families and are per-function, not one layout; see the note above. */
};

/* The walk block at Anim+0x34, as func_020643CC and func_02064934 read it.
   +0x08 is the SAME `kind` word section 3 describes and +0x0c the same array
   base; +0x00 is the descriptor the walk was last run against. */
struct Root {
    struct MultiCellData *data; /* 0x00                                      */
    void *set;                  /* 0x04  resource set for func_020627D8      */
    u32   kind;                 /* 0x08  1 = flat, else two-level            */
    void *cells;                /* 0x0c                                      */
};

/* ================================================================== *
 * 6.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the SRT setters and the dirty opener (leaves) ----------------------- */
extern void func_020640DC(struct Srt *p, s16 x, s16 y);     /* translate     */
extern void func_02064100(struct Srt *p, u16 rot);          /* rotate        */
extern void func_02064120(struct Srt *p, s32 sx, s32 sy);   /* scale, PAIRED */
extern void func_02064140(struct Srt *p, u32 mode);         /* open + reset  */
extern void func_02064150(void *p);                         /* the reset     */

/* --- the three-slot cell table ------------------------------------------- */
extern void func_020640B0(s32 *tbl);            /* fill 3 slots with -1      */
extern void func_020640CC(s32 *tbl, u32 i, s32 v);
extern s32  func_020640D4(const s32 *tbl, u32 i);

/* --- the binders --------------------------------------------------------- */
extern void func_02064178(struct Group *hdr, u32 v);        /* open a group  */
extern void func_0206428C(char *self, int a1, void *row);   /* bind a row    */
extern void func_020642C8(char *self, int a1, void *row, int d,
                          int e, int f, int g, int h, int i, int j);
extern void func_02064754(char *self, void *bank, void *set, int a3,
                          void *a4, int kind);              /* build the array */

/* --- the bank-sizing leaves ---------------------------------------------- */
extern u16 func_02064648(struct MultiCellBank *bank);   /* max numCellAnims  */
extern u16 func_020648E0(struct MultiCellBank *bank);   /* max numNodes      */
extern int func_020648B4(struct MultiCellBank *bank, u32 kind);  /* byte size */

/* --- the per-node steppers ----------------------------------------------- */
extern void func_02064364(struct CellAnim *a);  /* step by a tick, then dirty */
extern void func_02064384(struct CellAnim *a);  /* step one frame, then dirty */
extern void func_020643A4(struct CellAnim *a);  /* restart, force active      */
extern void func_020643C4(void *mca, u32 value);/* store the callback word    */

/* --- the whole-object walks ---------------------------------------------- */
extern void func_020643CC(struct Root *root, struct MultiCellData *d, u32 total);
extern void func_0206419C(char *self);          /* SRT rebuild, +0x3c family  */
extern void func_0206469C(char *self);          /* SRT rebuild, +0x48 family  */
extern void func_020649D4(char *self, int a1);  /* step then rebuild          */
extern void func_02064AB4(char *self);          /* guarded rebuild            */
extern void func_02064934(struct Root *p, int arg);  /* step every node       */

/* --- the layers this cluster calls out to -------------------------------- */
extern void *func_020627D8(void *set, u32 idx);     /* NANR entry lookup      */
extern void *func_020629E8(void *bank, u32 idx);    /* NMCR descriptor lookup */
extern void *func_02062D40(char *self);             /* current frame record   */
extern int   func_02062D4C(char *self, int a1);     /* step by a tick; ARITY 2 */
extern int   func_02062F00(char *self);             /* step one frame         */
extern void  func_02062F38(char *self);             /* commit                 */
extern void  func_02062F90(char *self);             /* restart                */
extern void  func_02062FF0(char *self);             /* pre-walk reset         */
extern void  func_0206434C(char *self, int v);      /* init a cell animation  */
extern u32   func_02063030(struct CellAnim *a);     /* "has residual"         */
extern int   func_0206285C(void *a, int v);
extern void  func_02066ABC(int a, int b, int c);    /* ARITY 3, not 4         */
extern void  func_02066890(int a0, int a1, int a2, int a3,
                           int s0, int s1, int s2, int s3);

/* ================================================================== *
 * WAVE 11 (2026-09-23): what was proved
 * ================================================================== *
 *
 * Two more EXACT: func_02064754 (../2.0/sp2) and func_02064934 (identical
 * bytes under both front ends).  func_020643CC 31 -> 7 out.
 *
 * 1. DECLARATION SCOPE IS THE CLUSTER'S ALLOCATION LEVER, and the permuter
 *    cannot reach it (it reorders declarations, never moves them between
 *    scopes).  Both closes and the 020643CC gain were scope moves only:
 *      func_02064934  `u16 i; char *cells` declared INSIDE EACH kind arm
 *                     (function scope swaps the two head loads, 4 out);
 *      func_02064754  `u16 n, i` INSIDE EACH arm (function scope 18 out);
 *      func_020643CC  the opposite direction: the node counter shared by
 *                     both arms, `sum` and the arm-1 cell-anim pointer at
 *                     FUNCTION scope, `k` in its block (31 -> 7).
 *    When a residue here is a clean register swap, try moving each local
 *    between block and function scope before anything else.
 *
 * 2. func_02064754's real signature: (char *self, char *buf, void *set,
 *    int a3, void *bank, int kind).  The NMCR bank handed to both sizing
 *    calls is the FIFTH argument (stack, respilled to its own slot); the
 *    second argument is the cell buffer stored at +0x40 and used as the
 *    group-header base.  The prototype in section 6 above names them in the
 *    wrong slots (`bank` second, `a4` fifth).  Arm 2 runs the four-call tail
 *    twice (falls into the shared copy).
 *
 * 3. func_02064934 is NOT pinned; the pin claim in the header stays true for
 *    every non-leaf function whose bytes differ between the front ends.
 */

#endif /* CLUSTER_020640DC_H */
