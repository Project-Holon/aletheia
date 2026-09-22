/*
 * docs/families/cluster_020611D4.h -- shared declarations for the
 * pseudo-family at 0x020611D4..0x02061824 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit.  It was formed by address adjacency plus shared callees and data
 * objects.  It is in fact TWO cooperating layers that sit next to each other:
 *
 *   A. THE GENERIC HEAP / ARENA LAYER, 0x020611D4..0x02061390 and the strip at
 *      0x02061808..0x02061824.  Small helpers over a heap object whose
 *      sub-allocator state lives at +0x24 (func_02061124, func_02061158,
 *      func_02061184, func_020611D4, func_02061224, func_0206123C,
 *      func_020612C8).  func_02061184 pushes a {key, cur, limit, head} record
 *      onto a singly linked list at heap+0x2c and func_020611D4 pops the one
 *      whose key matches: a SAVE/RESTORE MARK STACK over the arena.
 *
 *   B. THE NNS G2D MULTI-CELL VRAM MANAGER, 0x02061330..0x020617FC.  A
 *      five-slot bank of 0x18-byte descriptors at 0x020A816C, the mode word at
 *      0x02146B70, the {cur, end} arena pair at 0x02146B74, two callback slots
 *      at 0x020A8140 / 0x020A8144 and the pointer tables at 0x020A8150 /
 *      0x020A8158 / 0x020A8184 / 0x020A819C.  func_020613D8 selects the mode
 *      and installs the callbacks, func_02061460 re-derives every descriptor's
 *      enable and limit words from it, func_020614D4 and func_020616CC are the
 *      two allocators (the first over the descriptor bank, the second over the
 *      flat {cur, end} arena), and func_0206164C / func_0206168C save and
 *      restore the bank's live cursors around a mode switch.
 *
 * Derived from the 19 matched sources found with
 *   grep -l "address:  0x02061[1-8]" src/matched/*.c
 * and from docs/notes/func_020611D4.c.txt, docs/notes/pkt_020611D4.c.txt,
 * docs/notes/pkt_020613D8.c.txt and docs/notes/pkt_0206164C.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrh` proves a halfword; a plain `ldr` followed by
 * a shift pair proves the FIELD is 32-bit and the narrowing happens at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * The cluster's DEFAULT IS THE PROJECT DEFAULT, dsi/1.1p1: seventeen of the
 * nineteen matched sources carry `compiler: 1.1p1` and nothing else was
 * needed for them.  Unlike cluster_020737C0, this is NOT a cluster-wide pin.
 *
 * TWO functions, and only two, are byte-exact only under `--cc ../2.0/sp2`:
 *
 *   func_020613D8   func_020616CC
 *
 * and they are exactly the two that subsystem B's mode selector owns.  Their
 * evidence rows are in docs/FRONTEND-PINS.md.  The tells:
 *
 *   func_020616CC -- the "kept constants" tell applied to a POOL ADDRESS
 *     rather than to a literal.  The image re-materialises &g_02146B74 from
 *     the pool at six separate sites (0x020616FC, 0x02061724, 0x02061754,
 *     0x02061778, 0x02061798, 0x020617C4) against the single ABS32 at
 *     0x02061804, and pushes `{r4, lr}`.  1.1p1 CSEs that load to function
 *     entry, keeps it live across the body and therefore needs
 *     `push {r3, r4, r5, lr}`, ONE REGISTER WIDER.  Symptom to recognise
 *     instantly, and it is the same one cluster_020737C0 records: all the
 *     instructions and relocations right, the push/pop list a register wide.
 *   func_020613D8 -- the same front-end split seen on TAIL DUPLICATION.
 *     1.1p1 cross-jumps the two calls' identical two-instruction tails
 *     (`str ip, [sp]; bl func_02061390`) into one shared block, 128 bytes; the
 *     image keeps both copies, 136.  2.0/sp2 keeps them.
 *
 * Both of these cost earlier waves whole passes against the wrong front end:
 * docs/notes/pkt_020613D8.c.txt records some FIFTY rejected spellings between
 * the two of them ("WALL 1" and "WALL 2" for func_020616CC, and the
 * separate-ifs / else-if / goto / switch / four-pragma sweep for
 * func_020613D8), and EVERY ONE of those bodies turned out to be correct C.
 * If a function in this range is size-exact but a push-list wide, or is
 * size-SHORT by exactly one duplicated tail, change the compiler, not the
 * source.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_020611D4_H
#define CLUSTER_020611D4_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The multi-cell renderer's mode word.  A HALFWORD: func_02061460 reads it
   with `ldrh r7, [r0]` and func_020613D8 writes it as `(u16)mode`.  These two
   functions are the ONLY two places in the image that name 0x02146B70, which
   is why they must stay in separate files -- cut apart, each one's pool word
   is the other's witness; a unit spanning both leaves it unattested.         */
extern u16 g_02146B70;                  /* 0x02146B70 -- renderer mode        */

/* The flat VRAM arena func_020616CC bump-allocates from, in both directions.
   src/matched/func_02061808.c exposes the same pair as struct Pair02061808.  */
struct Arena02146B74 {
    u32 cur;                            /* 0x00  low  cursor, grows upward    */
    u32 end;                            /* 0x04  high cursor, grows downward  */
};
extern struct Arena02146B74 g_02146B74; /* 0x02146B74                         */

/* The two callback slots func_020613D8 installs when its second argument is
   non-zero.  0x020A8144's default is func_02061644, the eight-byte
   `return 0;` stub, and that store is the ONLY reference to the stub anywhere
   in the image -- filing src/matched/func_02061644.c is what lets the pool
   word resolve at all.                                                       */
extern u32 g_020A8140;                  /* 0x020A8140                         */
extern u32 g_020A8144;                  /* 0x020A8144                         */

/* The descriptor bank: five records of 0x18 bytes.  The stride is fixed by
   func_02061390's `mla r6, r0, ip, r5` with ip = 0x18, and independently by
   func_0206164C / func_0206168C's `add ip, ip, #0x18` per iteration.

   FIELD EVIDENCE, one function per line:
     +0x00, +0x04   the {cur, end} limit pair.  func_02061460 writes BOTH on
                    every record: +0x00 always 0, +0x04 either 0x10000 or
                    0x20000 depending on +0x0c.  func_0206164C copies exactly
                    these two words out per record, and func_0206168C copies
                    them back -- two words per record, five records, so the
                    caller's buffer is ten flat words.
     +0x08          the ENABLE word.  func_02061460 sets it to 1 for the first
                    `n` records and 0 for the rest (`strlt`/`strge` on one
                    predicated pair); func_020614D4 skips a record whose +0x08
                    is zero.
     +0x0c          a mode/kind word tested against zero by func_02061460.
     +0x10          a HALFWORD kind, `ldrh r5, [lr, #0x10]`, dispatched by
                    func_020614D4 against 0 and 3.
     +0x14          the record's BASE, added to the allocated offset to form
                    the returned address (func_020614D4 twice).               */
struct Rec020A816C {
    u32 lo;                             /* 0x00  limit low  (always 0)        */
    u32 hi;                             /* 0x04  limit high (0x10000/0x20000) */
    u32 enable;                         /* 0x08                               */
    u32 kind32;                         /* 0x0c  tested against zero          */
    u16 kind16;                         /* 0x10  ldrh; 0 and 3 are the cases  */
    u16 pad_12;
    u32 base;                           /* 0x14                               */
};
extern struct Rec020A816C g_020A816C[]; /* 0x020A816C, stride 0x18, five recs */

/* The pointer tables func_020614D4 walks.  func_02061390 fills g_020A8150's
   five slots at +0x08..+0x18 with &g_020A816C[k] for five caller-chosen k,
   which is what makes the five-record bank addressable in a chosen ORDER --
   the mode switch is a permutation of the bank, not a rewrite of it.         */
struct Ptrs020A8150 {
    u32 unk0;                           /* 0x00                               */
    u32 unk4;                           /* 0x04                               */
    struct Rec020A816C *p[5];           /* 0x08..0x18                         */
};
extern struct Ptrs020A8150  g_020A8150; /* 0x020A8150 -- func_02061390's dest */
extern struct Rec020A816C  *g_020A8158[2];  /* 0x020A8158                     */
extern struct Rec020A816C  *g_020A8184;     /* 0x020A8184 -- kind16 == 3      */
extern struct Rec020A816C  *g_020A819C;     /* 0x020A819C -- kind16 == 0      */

/* The dispatch table unit_02061358's func_02061358 installs at an object's
   word 0.  Forty witnesses image-wide, which is what makes that unit EXACT.  */
extern u8 g_020A1708[];                 /* 0x020A1708                         */

/* ================================================================== *
 * 1.  struct Heap -- subsystem A's arena object
 *
 * The heap is reached at object + 0x24 everywhere: func_02061124 does
 * `p += 0x24` before dispatching, and func_02061184 passes `&h->h24` to
 * func_02060FEC.  The MARK STACK head is one word past the pair, at +0x2c.
 * ================================================================== */
struct HeapCore {
    u32 cur;                            /* 0x00  bump cursor                  */
    u32 limit;                          /* 0x04                               */
    struct Mark *head;                  /* 0x08  mark-stack head              */
};

/* One saved mark.  func_02061184 builds it, func_020611D4 pops it:
   +0x00 is the KEY the pop matches on, +0x04/+0x08 are the two saved words
   the pop republishes into the heap at +0x24/+0x28, and +0x0c is `next`.     */
struct Mark {
    u32          key;                   /* 0x00                               */
    u32          saved_cur;             /* 0x04  -> heap + 0x24               */
    u32          saved_limit;           /* 0x08  -> heap + 0x28               */
    struct Mark *next;                  /* 0x0c                               */
};

struct Heap {
    u8              pad_00[0x24];
    struct HeapCore core;               /* 0x24  {cur, limit, head}           */
    /* head is core.head, i.e. the object's +0x2c: that is the list
       func_020611D4 searches and splices.                                    */
};

/* The object func_0206123C / func_020612C8 work over.  +0x20's low byte is a
   FLAG WORD read with a plain `ldr` and then narrowed (`and r0, r0, #0xff`
   before the `tst r0, #1`), so the field is 32 bits and the cast is in the C;
   +0x24 is the free-list head handed to func_02061224; +0x28 is the block
   size, both the clear length and func_020612C8's unsigned bound.            */
struct Pool0206123C {
    u32 w[8];                           /* 0x00                               */
    u32 flags;                          /* 0x20  bit 0 read as ((u8)f) & 1    */
    u32 freelist;                       /* 0x24                               */
    u32 size;                           /* 0x28                               */
};

/* unit_02061330's two-slot vtable and unit_02061358's four-word object.      */
typedef void (*Vfn02061330)(void *self, u32 x);
struct Vt02061330  { Vfn02061330 f0; Vfn02061330 f1; };
struct Obj02061330 { struct Vt02061330 *vt; };

struct S02061358 { u32 unk0; u32 unk4; u32 unk8; u32 unkC; };

/* ================================================================== *
 * 2.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the layer below (heap primitives, not in this cluster) -------------- */
extern void *func_02060FEC(struct HeapCore *h, u32 size, u32 align);
extern u32   func_02061048(u32 *p, u32 a, u32 b);
extern void  func_020610A0(void *p);
extern void  func_020610B4(void *p);
extern void  func_0206074C(void);
extern void  MIi_CpuClear32(u32 val, void *dst, u32 size);   /* 0x02082A7C   */

/* --- subsystem A: this cluster's own ------------------------------------- */
extern void  func_02061118(void);
extern void  func_02061124(char *p, int n, int v);
extern void  func_02061158(void *p, int flags);
extern int   func_02061184(struct Heap *h, u32 key);   /* push a mark         */
extern int   func_020611D4(struct Heap *h, u32 key);   /* pop it -- 80 B, DIFF*/
extern void *func_02061224(int **p);                   /* pop a free-list head*/
extern void *func_0206123C(struct Pool0206123C *o);
extern int   func_020612C8(void *o, u32 i);

/* --- subsystem B: this cluster's own ------------------------------------- */
extern void  func_02061330(struct Obj02061330 *o, u32 x);
extern void  func_02061344(struct Obj02061330 *o, u32 x);
extern void  func_02061358(struct S02061358 *s, u32 a, u32 b);
extern int   func_02061370(void);      /*  0 */
extern int   func_02061378(void);      /* -1 */
extern int   func_02061380(void);      /*  0 */
extern int   func_02061388(void);      /* -1 */
extern void  func_02061390(u32 a, u32 b, u32 c, u32 d, u32 e);  /* permute    */
extern void  func_020613D8(u32 mode, u32 flag);        /* PIN ../2.0/sp2      */
extern void  func_02061460(void);                      /* 116 B, DIFF 6 bytes */
extern u32   func_020614D4(u32 size, u32 which);       /* 348 B, open         */
extern u32   func_02061644(void);                      /* the `return 0` stub */
extern void  func_0206164C(u32 *dst);                  /* save the bank       */
extern void  func_0206168C(u32 *src);                  /* restore the bank    */
extern u32   func_020616CC(u32 size, u32 flag, u32 dir);/* PIN ../2.0/sp2     */

/* ================================================================== *
 * 3.  Constants
 * ================================================================== */
#define REC_STRIDE          0x18    /* g_020A816C; mla ip=0x18, add #0x18     */
#define REC_COUNT           5       /* every loop in the cluster is `< 5`     */
#define HEAP_CORE_OFF       0x24    /* func_02061124's `p += 0x24`            */
#define MARK_HEAD_OFF       0x2c    /* func_020611D4 / func_02061184          */
#define ARENA_MAX           0x7fff8 /* func_020616CC's refusal bound          */
#define BANK_MAX            0x7fff0 /* func_020614D4's, 16-byte grain         */
#define ARENA_CAP           0x10000 /* the `flag != 0` ceiling, tested with > */

#endif /* CLUSTER_020611D4_H */
