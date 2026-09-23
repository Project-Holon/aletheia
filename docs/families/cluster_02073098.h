/*
 * docs/families/cluster_02073098.h -- shared declarations for the
 * pseudo-family at 0x02073098..0x02073760 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.  Never edit src/matched from this file; the
 * matched sources are the evidence and this is the summary.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit.  It was formed by address adjacency plus shared callees and data
 * objects.  What it holds is THE SOUND VOICE ALLOCATOR AND ITS PRIORITY QUEUE:
 * the layer between the channel allocator below it (0x020726D0..0x02072A28,
 * see docs/families/cluster_020726D0.h) and the per-frame mixer above it
 * (func_020731E0).
 *
 * The model, in one paragraph, because every function here is a few lines of
 * it.  A VOICE is a 0x44-byte object with a priority byte at +0x3d, a state
 * byte at +0x2c and an embedded envelope sub-object at +0x1c.  Voices live on
 * exactly one of two intrusive lists at any moment: the FREE list g_0214E00C
 * and the ACTIVE list g_0214E018, both driven by the generic list primitives
 * func_02060614 (iterate: a null cursor asks for the head, a node asks for its
 * successor), func_020605B4 (unlink) and func_02060550 (insert before a
 * cursor; a null cursor appends).  The ACTIVE list is kept sorted by priority,
 * which is the whole job of func_02073598 and func_02073548.  A third object,
 * the 0x24-stride table g_0214E464, holds per-slot free lists of request nodes
 * at +0x0c and is indexed by a plain subscript.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x02073[0-7]" src/matched/*.c
 * and from the notes docs/notes/pkt_020733E8.c.txt,
 * docs/notes/pkt_02072EA8.c.txt, docs/notes/pkt_02072F5C.func_020730B8.c.txt
 * and docs/notes/func_02073438.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrb`/`ldrsb` prove width and signedness; `blo`
 * versus `blt` proves the comparison's signedness; an `add rN, rM, #k` handed
 * to a callee proves an EMBEDDED object where an `ldr` would prove a pointer.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * This range is MIXED, and getting the compiler right is worth more than any
 * respelling.  As of 2026-09-22 the matched sources split:
 *
 *   ../2.0/sp2   func_0207312C  func_02073344  func_02073624  func_0207368C
 *                func_020734AC  func_02073598
 *   1.1p1        func_020730DC  func_020731E0  func_02073484  func_02073500
 *                func_02073548  func_020735EC  func_02073710  func_02073760
 *
 * The tell that decides it is ALWAYS the same one, it is mechanical, and it is
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md (the
 * "kept constants" row of docs/FRONTEND-PINS.md):
 *
 *   IF A VALUE IS LIVE AT MORE THAN ONE POINT -- a small literal (0 or 1), or,
 *   in this cluster far more often, THE POOL WORD FOR g_0214E00C / g_0214E018 /
 *   g_0214E464 -- dsi/1.1p1 -O4,p hoists it into a callee-saved register and
 *   reuses it.  That widens the prologue's push list and shifts every later
 *   register.  ../2.0/sp2 rematerialises it at each use, which is what the
 *   image does.
 *
 * SYMPTOM TO RECOGNISE INSTANTLY: a compile whose instructions and relocations
 * are ALL correct, in the image's order, but whose `push`/`pop` lists are one
 * or two registers wider than the image's -- and which is often four or eight
 * bytes SHORT, because the pool folded from two entries to one.
 *
 * TWO FUNCTIONS WERE CLOSED THIS PASS BY CHANGING ONLY THE `--cc` FLAG, with
 * no change to C that had already been measured and rejected:
 *   func_020734AC  docs/notes/pkt_020733E8.c.txt section 1 recorded it as
 *                  88 bytes against 80 with seven rejected null spellings.
 *                  Under the pin the SAME body is 84 bytes, 0 mismatches.
 *   func_02073598  47 bytes out and demoted from EXACT to DIFF the day before.
 *                  Under the pin, 0 mismatches (after one real declaration fix,
 *                  below).
 * IF A FUNCTION IN THIS RANGE IS SIZE-EXACT BUT A PUSH-LIST WIDE, CHANGE THE
 * COMPILER, NOT THE SOURCE.
 *
 * A SECOND, INDEPENDENT WALL LIVES IN THIS RANGE AND THE PIN DOES NOT TOUCH IT:
 * IF-CONVERSION.  This front end (all three of 1.1p1, ../1.2/sp2 and
 * ../2.0/sp2, measured) turns any if-arm of one or two statements into a
 * predicated block, so `if (p == 0) return; <two stores>` never produces the
 * image's `bxeq lr`.  Three statements do not predicate, which is exactly why
 * func_020730DC (three stores) is EXACT and its otherwise byte-identical
 * sibling func_020730B8 (two stores) is not.  See
 * docs/notes/pkt_02072F5C.func_020730B8.c.txt.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02073098_H
#define CLUSTER_02073098_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 *
 * ALL THREE ARE ARRAYS, NOT POINTERS, AND THAT DISTINCTION COST A DAY.
 * The image hands the ADDRESS 0x0214E018 straight to func_02060614; a
 * `void *` declaration adds an `ldr r0, [r0]` at every call site that no
 * instruction in the image has.  `extern char g_0214E018[];` is the spelling
 * every matched source in this range uses, and src/pending/func_02073598.c
 * disagreeing with them was the whole tail of its 47-byte residue (now filed
 * EXACT as src/matched/func_02073598.c).  Declare a list object as an array.
 * ================================================================== */

extern char g_0214E00C[];               /* 0x0214E00C -- the FREE voice list  */
extern char g_0214E018[];               /* 0x0214E018 -- the ACTIVE voice list,
                                           kept sorted by Voice.b3d priority  */

/* The per-slot request table.  `mov r2, #0x24 / mla r5, r0, r2, r3` in
   func_020734AC fixes the 0x24 stride and proves the index is a plain
   subscript; `add r0, r5, #0xc` proves the list at +0x0c is EMBEDDED, so its
   address is taken and never loaded.  func_0207312C initialises all 0x20
   entries, func_02073710 returns a node to one. */
struct Slot {
    u8  pad00[0x0c];
    u8  list[0x24 - 0x0c];  /* 0x0c  embedded free list of request nodes      */
};
extern struct Slot g_0214E464[];        /* 0x0214E464, stride 0x24, 0x20 slots */

#define SLOT_STRIDE     0x24    /* func_020734AC's `mov r2, #0x24`            */
#define SLOT_LIST_OFF   0x0c    /* func_020734AC's `add r0, r5, #0xc`         */
#define SLOT_COUNT      0x20    /* func_0207312C's second loop bound          */

/* ================================================================== *
 * 1.  struct Voice -- the 0x44-byte voice object
 *
 * Field evidence, one function per line.  Only the loads and stores are
 * listed; where two matched files spell the same offset differently, the file
 * whose code CONSTRAINS it wins and the loser is recorded as WAS:.
 *
 *   +0x00   owner back-pointer.  func_0207368C: `if (v->f00 != 0) {
 *           v->f00->f00 = 0; v->f00 = 0; }` -- a pointer to an object whose
 *           own +0x00 is cleared, i.e. a two-way binding.
 *   +0x04   THE LIST THIS VOICE IS CURRENTLY ON.  func_02073760 reads it into
 *           a local, unlinks from it, re-inserts elsewhere, and only then uses
 *           the SAVED value again -- which is why the local is required and a
 *           re-read is a byte difference.  func_02073548 writes it
 *           (`obj->f4 = list;`) as the last statement of an insert, so the
 *           field is maintained BY the queue operations, not by the caller.
 *           func_020733E8 reads a sub-object THROUGH it (+0x1c of the pointee).
 *   +0x08   a second sub-object pointer, unbound by func_0207368C, whose own
 *           +0x0c points back at the voice.
 *   +0x1c   THE EMBEDDED ENVELOPE, 0x10 bytes.  func_02073438 and
 *           func_02073500 pass `&v->env` (an `add r0, rN, #0x1c`) to
 *           func_02075BAC / func_02075B94; func_020731E0 passes the same
 *           address to func_02075C08 / func_02075BD4 / func_02075C20.
 *           EMBEDDED, never loaded.
 *   +0x2c   the STATE byte (`ldrb`/`strb`).  0 = free, 1 = playing
 *           (func_020733E8 sets it), 2 = releasing (func_02073438 sets it, and
 *           func_020731E0 tests `v->b2c == 2` before finishing the voice).
 *           func_0207368C clears it to 0 on teardown.
 *   +0x2d   a second flag byte, cleared by func_02073500.
 *   +0x2e   the cached value func_02073484 compares before writing.
 *   +0x2f   set to 1 beside +0x2c by func_020733E8, cleared by func_02073500;
 *           func_020731E0 reads it as a one-shot request and clears it.
 *   +0x30   the command tag func_02089D40 returns (func_020733E8 stores it).
 *   +0x34   halfword, zeroed by func_02073500.
 *   +0x3c   THE PLAYER/CHANNEL INDEX (`ldrb`).  Every call into the driver
 *           layer passes it: func_02089350, func_0208948C, func_020893D0,
 *           func_02089378.
 *   +0x3d   THE PRIORITY BYTE (`ldrb`), and the sort key of the active list.
 *           THE COMPARISON IS UNSIGNED: func_02073598 emits `blo`, so the
 *           test is `obj->b3d < curr->b3d` on u8; a signed spelling emits
 *           `blt`.  func_02073624 writes it from an s32 argument with a
 *           narrowing cast and compares `pri < v->b3d` the other way round.
 *   +0x3e   s16, the last volume written (func_020731E0 compares before
 *           writing so an unchanged volume costs nothing).
 *   +0x40, +0x41   two curve indices, both u8 (func_020731E0).
 * ================================================================== */
struct Voice {
    struct Voice *f00_owner;    /* 0x00  two-way binding, cleared in pairs    */
    void         *f04_list;     /* 0x04  the list this voice is on RIGHT NOW  */
    void         *f08_sub;      /* 0x08  second sub-object, back-linked       */
    u8  pad0c[0x1c - 0x0c];
    u8  env[0x2c - 0x1c];       /* 0x1c  EMBEDDED envelope, address taken     */
    u8  b2c_state;              /* 0x2c  0 free / 1 playing / 2 releasing     */
    u8  b2d;                    /* 0x2d                                       */
    u8  b2e_cached;             /* 0x2e  func_02073484's compare-before-write */
    u8  b2f_oneshot;            /* 0x2f                                       */
    u32 f30_tag;                /* 0x30  func_02089D40's command tag          */
    u16 h34;                    /* 0x34                                       */
    u8  pad36[0x3c - 0x36];
    u8  b3c_player;             /* 0x3c  driver-layer player index            */
    u8  b3d_prio;               /* 0x3d  priority, UNSIGNED sort key          */
    s16 h3e_vol;                /* 0x3e  last volume written                  */
    u8  b40;                    /* 0x40  curve index                          */
    u8  b41;                    /* 0x41  curve index                          */
    u8  pad42[0x44 - 0x42];
};

/* The envelope sub-object read through Voice.f04 by func_020733E8: only its
   +0x1c word is constrained, as a plain u32 guard.  Recorded as its own view
   rather than merged, per the adjudication rule. */
struct Sub { u8 pad00[0x1c]; u32 f1c; };

/* The request node func_020734AC hands out and func_02073710 takes back. */
struct ReqNode {
    u8    pad00[8];
    void *f08;                  /* 0x08  the owner's back-pointer             */
    void *f0c;                  /* 0x0c  the owner                            */
};

/* ================================================================== *
 * 2.  The one object shape the 0x02073098 wrapper series uses
 *
 * The nine wrappers at 0x02072F88..0x02073098 and their two DIFF siblings
 * 0x02072EA8 / 0x020730B8 all read a single pointer field and store through
 * it.  THE POINTER FIELD MUST BE `volatile`: the image re-reads it once per
 * statement, and without the qualifier the compiler folds the three loads into
 * one (28 bytes instead of 36).  This is the only place in the cluster where
 * volatile is load-bearing; see func_020730DC, which is EXACT with it.
 * ================================================================== */
struct WrapSub { u8 pad00[0x34]; u16 h34; u16 h36; u16 h38; u16 h3a; };
struct Wrap    { struct WrapSub * volatile p; };

/* ================================================================== *
 * 3.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the generic intrusive-list primitives (0x0206xxxx) ------------------- */
extern void *func_02060614(void *list, void *cursor);  /* null cursor = head  */
extern void  func_020605B4(void *list, void *node);    /* unlink              */
extern void  func_02060550(void *list, void *cursor, void *node); /* insert
                                                  before cursor; null = append */
extern void  func_020604AC(void *list, void *node);    /* append              */
extern void  func_02060468(void *list, u32 elem_size);

/* --- the envelope layer (0x02075xxx) -------------------------------------- */
extern s32   func_02075B94(void *env, s32 v);
extern void  func_02075BAC(void *env, u32 v);
extern void  func_02075BD4(void *env);
extern void  func_02075C08(void *env);
extern u32   func_02075C20(void *env);

/* --- the audio driver layer (0x02089xxx) ---------------------------------- */
extern void  func_02089330(u32 player);
extern void  func_02089350(u32 player);
extern void  func_02089378(u32 player);
extern void  func_02089398(u32 player);
extern void  func_0208948C(u32 player, u32 v);
extern void  func_020893D0(u32 player, s32 vol);
extern u32   func_02089D40(void);                      /* current command tag */
extern u32   func_02089D6C(u32 tag);                   /* tag finished?       */

/* --- this cluster's own --------------------------------------------------- */
extern void          func_020730B8(struct Wrap *o, u16 v);    /* DIFF, if-conv */
extern void          func_020730DC(struct Wrap *o, u16 a, u16 b);
extern void          func_0207312C(void);              /* build both lists     */
extern void          func_020731E0(void);              /* the per-frame mixer  */
extern struct Voice *func_02073344(void *o, s32 idx, s32 pri);
extern void          func_020733E8(struct Voice *v);   /* start playing        */
extern void          func_02073438(struct Voice *v, u32 n);   /* DIFF          */
extern void          func_02073484(struct Voice *v, u8 val);
extern void         *func_020734AC(s32 idx, void *owner);     /* take a node   */
extern int           func_02073500(struct Voice *v);   /* reset the voice      */
extern void          func_02073548(void *list, struct Voice *v); /* sorted ins */
extern void          func_02073598(struct Voice *v);   /* sorted ins, g_0214E018 */
extern void          func_020735EC(struct Voice *v);   /* stop and tear down   */
extern struct Voice *func_02073624(s32 pri);           /* allocate by priority */
extern void          func_0207368C(struct Voice *v);   /* full unbind          */
extern void          func_02073710(void *a);           /* return a request node */
extern void          func_02073760(struct Voice *v, u32 pri); /* re-prioritise */

/* --- reached from here, outside this cluster ------------------------------ */
extern void  func_02072EA8(void *o);
extern void  func_02074758(u32 a);
extern void  func_02074770(void *owner);

#endif /* CLUSTER_02073098_H */

/* CORRECTION 2026-09-23 (wave 13).  The IF-CONVERSION wall above is not a
 * wall: func_020730B8 is EXACT under ../2.0/sp2 with the guard written as a
 * WRAPPING `if (o->p != 0) { two stores }` instead of an early return.  And
 * two arities: func_020733E8 takes (voice, seqBase, seqOffset, bankData) and
 * forwards r1..r3 to SND_PrepareSeq (0x02089350, four arguments);
 * func_0208948C is SND_SetTrackAllocatableChannel(player, trackMask, chMask);
 * func_02075BAC is a three-argument fader set (fader, target, frames).  All
 * three of 0x020730B8 / 0x020733E8 / 0x02073438 are now EXACT (sp2).  The
 * cluster is NitroSystem snd (sound player over the TwlSDK SND driver). */
