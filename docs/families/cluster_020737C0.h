/*
 * docs/families/cluster_020737C0.h -- shared declarations for the
 * pseudo-family at 0x020737C0..0x020748E0 in the ARM9 image.
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
 * shared callees and data objects, and it is in fact TWO adjacent subsystems
 * that happen to sit next to each other and share a compiler pin:
 *
 *   A. 0x020737C0..0x02073FB8 -- a SOUND / SEQUENCE PLAYER.  Every function
 *      here talks to the 0x02089xxx-0x0208Cxxx audio driver layer
 *      (func_020894B4 / func_020894DC channel release, func_02089638 parameter
 *      write, func_02089D40 / func_02089B38 / func_02089CD4 save-mute-restore,
 *      func_0208C808 / func_0208C828 / func_0208C86C / func_0208C884 sub-object
 *      setup and teardown, func_0208A24C value conversion) and operates on one
 *      0x54-byte object (struct SndObj below) plus the single global instance
 *      g_0214E9FC.  The subsystem owns a channel-slot model: a count at +0x50,
 *      that many slot indices at +0x54, and a mask of them at +0x4C.
 *
 *   B. 0x02074048..0x020748E0 -- an ARCHIVE / RESOURCE LOADER.  These read a
 *      table-of-contents through a file handle (func_02078B44 seek,
 *      func_02078B70 read, func_020788AC / func_020788D8 / func_020789A4
 *      stream setup), relocate a loaded header in place, and hand out its
 *      records.  Everything here reaches the module through the single global
 *      pointer ptr_0214EA50 (struct Arc below).  The deferred-request drain at
 *      0x02074770 / 0x020748E0 walks the linked lists at +0x04 with the generic
 *      list iterator func_0206062C.
 *
 * Derived from the 27 matched sources found with
 *   grep -l "address:  0x02073[7-9A-F]\|address:  0x02074[0-8]" src/matched/*.c
 * and from the notes docs/notes/func_020737C0.c.txt,
 * docs/notes/func_02073DFC.c.txt, docs/notes/func_02074894.c.txt,
 * docs/notes/pkt_02073BF0.c.txt, docs/notes/pkt_02073D5C.c.txt,
 * docs/notes/pkt_02073F3C.c.txt, docs/notes/pkt_020746E8.c.txt,
 * docs/notes/pkt_02074770.c.txt and docs/notes/pkt_02074894.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing happens
 * at the use.  Where two matched files disagree, the file whose code actually
 * constrains the field wins and the losing spelling is recorded beside it as
 * `WAS:`.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * EIGHT of this cluster's functions are byte-exact only under `--cc ../2.0/sp2`
 * and are DIFF under the project default dsi/1.1p1:
 *
 *   func_020737C0  func_02073AD0  func_02073B3C  func_02073CA0
 *   func_02073F3C  func_020746E8  func_02074220  func_02074770
 *   func_02074894
 *
 * The tell is always the same one, and it is
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md:
 * whenever a small literal (nearly always 0, sometimes 1) is live at more than
 * one point, 1.1p1 pools it into a callee-saved register and reuses it, which
 * also widens the prologue's push list by a slot and shifts every later
 * register.  The image rematerialises the literal at each use.  Symptom to
 * recognise instantly: a compile whose instructions and relocations are all
 * correct but whose `push`/`pop` lists are one register wider than the image's.
 *
 * FOUR of the notes in docs/notes/ for this range spent whole passes measuring
 * respellings of the C against this wall before the pin was known
 * (func_020737C0, func_02074894, pkt_02073F3C, pkt_020746E8 -- between them
 * some thirty rejected spellings).  Every one of those bodies turned out to be
 * correct C.  If a function in this range is size-exact but a push-list wide,
 * change the compiler, not the source.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_020737C0_H
#define CLUSTER_020737C0_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The one-shot latch and the heap-name pair the constructor uses.
   func_020737C0: `if (g_0214E8E4 == 0) { func_02060468(g_0214E8E8, 0);
   g_0214E8E4 = 1; }`.  g_0214E8E8 is also func_02073BB0's first argument to
   func_020605B4, i.e. it names a list/heap object, not a scalar. */
extern u32 g_0214E8E4;                  /* 0x0214E8E4 -- init-once latch      */
extern u8  g_0214E8E8[];                /* 0x0214E8E8 -- heap/list object     */

/* Evidenced by func_02073760 (func_020605B4(g_0214E018, o)).                 */
extern u8  g_0214E018[];                /* 0x0214E018                         */

/* A second list object, func_02073710's target through func_020605B4, indexed
   by the object's +0x10 word at a 0x24 stride with the used field at +0x0C.   */
struct Ent0214E464 { u8 pad00[0x0c]; u8 f0c; u8 pad0d[0x24 - 0x0d]; };
extern struct Ent0214E464 g_0214E464[]; /* 0x0214E464, stride 0x24            */

/* The slot descriptor table.  Two words per slot; `ldr r1,[r2,r1,lsl #3]` in
   func_02073BF0 fixes the 8-byte stride, and func_02073AD0 adds the SECOND
   word to a base while func_02073BF0 reads the FIRST.  Indexed by a slot byte
   out of SndObj.slots[].                                                      */
struct SlotDesc { u32 a; u32 b; };
extern struct SlotDesc g_0214E934[];    /* 0x0214E934, stride 8               */

/* The per-frame scratch array func_02073BF0 fills and then passes to the
   object's callback as its THIRD argument -- see the note in
   docs/notes/pkt_02073BF0.c.txt; the pool word that looks like a dead load at
   +0x68 is this address.                                                      */
extern u32 g_0214E8F4[];                /* 0x0214E8F4                         */

/* func_02073D5C zeroes this pair.  g_0214E9B4 has no witness outside
   0x02073D5C..0x02073D7C and is the blocker recorded in that file's header.   */
extern u32 g_0214E9B4;                  /* 0x0214E9B4                         */
extern u8  g_0214E9BC[];                /* 0x0214E9BC -- func_02073DFC's pool */

/* ================================================================== *
 * 1.  struct SndObj -- the sound object (0x54+ bytes), subsystem A
 *
 * Field evidence, one function per line:
 *   +0x08, +0x18   func_02073A60 passes (u8 *)a + 8 and + 0x18 to
 *                  func_0208C808 / func_0208C828; func_02073B3C passes the
 *                  same two to func_0208C86C / func_0208C884.  So these are
 *                  two EMBEDDED sub-objects, 0x10 and 0x14 bytes, not
 *                  pointers -- their addresses are taken, never loaded.
 *   +0x08, +0x18   func_020737C0 instead stores a code pointer at +0x08 and
 *                  +0x18 with the object's own address at +0x0C / +0x1C.
 *                  THE TWO READINGS ARE BOTH RIGHT: the constructor writes a
 *                  (callback, context) pair into the first two words of each
 *                  sub-object.  Declare per function, not once.
 *   +0x2c          flags.  func_02073AB4 reads bit 0 as `lsl #31 / asrs #31`
 *                  and func_02073B3C / func_02073CA0 read bit 1 as
 *                  `lsl #30 / asrs #31`: BOTH ARE SIGNED ONE-BIT BITFIELDS.
 *                  `(f2c >> 1) & 1` on a plain word is 12 bytes out.
 *                  func_02073BB0 clears bit 0 with `x->f2c &= ~1` (the bic
 *                  spelling); func_020737C0 clears bits 0 and 1 with TWO
 *                  separate statements -- `&= ~3` folds to one bic and loses
 *                  four bytes, which is what proves they are two 1-bit fields.
 *   +0x40          frame counter.  func_02073BF0 increments it and wraps it
 *                  at +0x34.  Signed (`cmp r1,r0` then `movge`).
 *   +0x44          base value func_02073AD0 latches and re-reads.  Signed.
 *   +0x48          the channel INDEX; every user spells the mask `1u << f48`.
 *   +0x4c          the channel MASK.  func_02073898 releases it through
 *                  func_02072974 and then zeroes +0x4c and +0x50 out of one
 *                  `mov r0,#0`.
 *   +0x50          active slot COUNT.  Signed: func_02073AD0's loop guard is
 *                  `for (i = 0; i < s->f50; i++)` with the image's single
 *                  predicated `pople`, and writing it as a separate early
 *                  return emits a second `cmp r0,#0`.
 *   +0x54          the slot INDEX BYTES, one per active slot (`ldrb`).
 * ================================================================== */
struct SndObj {
    u8  pad_00[0x08];
    u8  sub08[0x10];        /* 0x08  sub-object; +0x00 callback, +0x04 ctx    */
    u8  sub18[0x14];        /* 0x18  sub-object; +0x00 callback, +0x04 ctx    */

    u32 flag0 : 1;          /* 0x2c  bit 0 -- read SIGNED where it is a guard */
    s32 flag1 : 1;          /*       bit 1 -- likewise                        */
    u32 flag_hi : 30;

    u8  pad_30[0x04];       /* 0x30  (func_02073BF0 reads +0x30/+0x34 here as
                                      a (u32, s32) pair -- see SndSeq below)  */
    u8  pad_34[0x0c];
    u32 f40_counter;        /* 0x40  frame counter, wraps at +0x34            */
    s32 f44_base;           /* 0x44                                           */
    u32 f48_chan;           /* 0x48  channel index; mask is 1u << this        */
    u32 f4c_mask;           /* 0x4c  channel mask                             */
    s32 f50_nslots;         /* 0x50  active slot count                        */
    u8  f54_slots[4];       /* 0x54  slot index bytes, f50_nslots of them     */
};

/* func_02073BF0 reads a different, overlapping view of the same object: a
   (u32, s32) pair at +0x30/+0x34 handed to func_0209C2B0, a callback at +0x38
   with a context word at +0x3C, and +0x28.  Recorded as its own view rather
   than merged, per the adjudication rule -- only the loads constrain it. */
struct SndSeq {
    u8  pad_00[0x28];
    u32 f28;                /* 0x28  callback argument 5 (via the stack)      */
    u8  pad_2c[0x04];
    u32 f30;                /* 0x30  \  handed to func_0209C2B0 as (a, b)     */
    s32 f34;                /* 0x34  /  f34 is also the counter's wrap bound  */
    u32 f38_cb;             /* 0x38  callback, invoked with blx               */
    u32 f3c;                /* 0x3c  callback argument 6 (via the stack)      */
    s32 f40_counter;        /* 0x40                                           */
    u8  pad_44[0x0c];
    s32 f50_nslots;         /* 0x50                                           */
    u8  f54_slots[4];       /* 0x54                                           */
};

/* THE CALLBACK AT +0x38, spelled out because it cost a whole pass to read.
   Six arguments: only r0 and the two STACK words are set up by the image, and
   the `ldr r2,[pc,#0x3c]` that looks like a dead load is g_0214E8F4 going into
   argument three.  Arguments two and four are leftovers (the loop's base value
   and its final counter) and any live value spells them. */
typedef void (*SndSeqCb)(u32 arg, u32 base, u32 *scratch,
                         u32 i, u32 f28, u32 f3c);

/* ================================================================== *
 * 2.  struct SndGlobal -- the single global sequence object, subsystem A
 *
 * g_0214E9FC.  Three matched files read it (func_02073D7C, func_02073EE4,
 * func_02073F3C) and each constrains a different part; the union is below.
 *   +0x00   liveness guard: every entry point starts `if (f00 == 0) return;`
 *   +0x04   second guard (func_02073D7C only)
 *   +0x0c,  +0x10  two channel handles, unbound in pairs by func_02073F3C
 *   +0x14   the owner both handles are unbound from
 *   +0x1c   cleared to 0 on shutdown
 *   +0x24,  +0x28  the (a, b) pair handed to func_020894B4/func_020894DC
 *   +0x2c   channel index, SIGNED: `if (f2c >= 0) m = 1u << f2c; else m = 0;`
 *           is required to get `movge r0,#1 / lslge r2,r0,r1 / movlt r2,#0`.
 *           Writing the non-negative test second inverts both predicates.
 *   +0x3c   a 0x10-byte embedded reader object (func_02075BD4/C08/C20)
 *   +0x4c   guard on the func_02073DFC path
 *   +0x50   last value written out through func_02089638, compared before
 *           writing so an unchanged value costs nothing
 * ================================================================== */
struct SndGlobal {
    u32 f00;                /* 0x00  liveness                                 */
    u32 f04;                /* 0x04                                           */
    u8  pad_08[0x04];
    u32 f0c_handle;         /* 0x0c                                           */
    u32 f10_handle;         /* 0x10                                           */
    u32 f14_owner;          /* 0x14                                           */
    u8  pad_18[0x04];
    u32 f1c;                /* 0x1c  cleared on shutdown                      */
    u8  pad_20[0x04];
    u32 f24;                /* 0x24                                           */
    u32 f28;                /* 0x28                                           */
    s32 f2c_chan;           /* 0x2c  SIGNED -- negative means "no channel"    */
    u8  pad_30[0x0c];
    u8  f3c_reader[0x10];   /* 0x3c  embedded reader object                   */
    u32 f4c;                /* 0x4c                                           */
    s32 f50_last;           /* 0x50                                           */
};
extern struct SndGlobal g_0214E9FC;     /* 0x0214E9FC                         */

/* ================================================================== *
 * 3.  struct Arc -- the archive/loader module object, subsystem B
 *
 * Reached ONLY through the global pointer ptr_0214EA50, which
 * unit_020742E4's func_020742E4 swaps and func_020742FC returns, and which
 * func_02073FB8 and func_02074220 both publish on success.
 *
 *   +0x30   "loaded" latch, set to 1 by func_02073FB8, cleared by
 *           func_02074220
 *   +0x34   the file handle, 0x48 bytes, embedded.  func_020745A4 passes
 *           &ctx->f34 to func_02078B44 / func_02078B70; func_02073FB8 resets
 *           it with func_020788AC.
 *   +0x7c   a TWO-WORD PAIR, loaded with a single `ldm r1,{r1,r2}` and passed
 *           BY VALUE as func_020789A4's second argument.  Two scalar fields
 *           is 14 bytes out; see docs/notes/pkt_02073F3C.c.txt.
 *   +0x88   the table-of-contents pointer (func_02074220 relocates it and then
 *           walks its records)
 *   +0x8c,  +0x90  two further relocated pointers (from stored offsets at
 *           +0x10 and +0x18)
 *   +0x94   cleared by both func_02073FB8 and func_02074220
 *   +0x98   the read chunk size; 0 means "the whole request in one go"
 *           (func_020745A4)
 * ================================================================== */
struct ArcHdr {                 /* the 0x30-byte header read off the file     */
    u8  pad_00[0x08];
    u32 off_08;                 /* six offset-table offsets, one per getter   */
    u32 off_0c;
    u32 off_10;
    u32 off_14;
    u32 off_18;
    u32 off_1c;
};

struct ArcTable { u32 count; u32 entries[1]; };  /* offset table (unit_020742E4) */

struct ArcEntry {               /* the TOC record, stride 0x10                */
    u32 offset;                 /* +0x00  file offset                         */
    u32 size;                   /* +0x04                                      */
    u32 field8;                 /* +0x08  relocated in place by func_02074220 */
    u32 fieldC;                 /* +0x0c                                      */
};

struct ArcToc { u32 unk0; u32 unk4; u32 count; struct ArcEntry entries[1]; };

struct ArcPair { u32 a; u32 b; };   /* the +0x7c pair, PASSED BY VALUE        */

struct Arc {
    u8  pad_00[0x10];
    u32 f10_off;                /* 0x10  stored offset -> f8c                 */
    u8  pad_14[0x04];
    u32 f18_off;                /* 0x18  stored offset -> f90                 */
    u8  pad_1c[0x04];
    u32 f20_off;                /* 0x20  stored offset -> f88                 */
    u8  pad_24[0x0c];
    u32 f30_loaded;             /* 0x30                                       */
    u8  f34_file[0x48];         /* 0x34  embedded file handle                 */
    struct ArcPair f7c;         /* 0x7c  BY VALUE to func_020789A4            */
    u8  pad_84[0x04];
    struct ArcToc *f88;         /* 0x88                                       */
    u32 f8c;                    /* 0x8c                                       */
    u32 f90;                    /* 0x90                                       */
    u32 f94;                    /* 0x94                                       */
    u32 f98_chunk;              /* 0x98  0 = unchunked                        */
};
extern struct Arc *ptr_0214EA50;        /* 0x0214EA50                         */

/* The deferred-request node walked by func_02074770 and func_020748E0.  The
   lists themselves live at object + 4 and are walked with func_0206062C, whose
   second argument is the cursor: a null cursor asks for the head, a node asks
   for its successor.  One function serving both roles is why all four call
   sites look identical. */
struct ReqNode {
    u8  pad_00[0x08];
    u32 f08;                    /* 0x08  callback argument 2                  */
    u32 f0c_cb;                 /* 0x0c  callback, null means "skip"          */
    u32 f10;                    /* 0x10  callback argument 3                  */
    u32 f14;                    /* 0x14  callback argument 4                  */
    /* the callback's first argument is (u8 *)node + 0x20 */
};
typedef void (*ReqCb)(void *payload, u32 f08, u32 f10, u32 f14);

struct ReqOwner {
    u32 f00_heap;               /* 0x00                                       */
    u8  list[8];                /* 0x04  the list head(s)                     */
    u16 f0c_count;              /* 0x0c  live count, read with ldrh           */
};

/* ================================================================== *
 * 4.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- subsystem A: the audio driver layer (0x02089xxx / 0x0208Cxxx) ------- */
extern void func_020894B4(u32 a, u32 b, u32 mask, u32 d);
extern void func_020894DC(u32 a, u32 b, u32 mask, u32 d);
extern void func_02089638(u32 mask, u32 lo, s32 hi);   /* hi is an ARITHMETIC
                                                          shift of the value  */
extern u32  func_02089D40(void);                       /* save   -- returns a
                                                          token handed back   */
extern void func_02089B38(u32 a);                      /* mute, always (1)    */
extern void func_02089CD4(u32 token);                  /* restore             */
extern void func_0208C808(void *sub);
extern void func_0208C828(void *sub);
extern void func_0208C86C(void *sub);
extern void func_0208C884(void *sub);
extern s32  func_0208A24C(s32 x);
extern void func_02082A7C(u32 zero, u32 handle, u32 owner);
extern void func_020862F0(u32 handle, u32 owner);
extern u32  func_02087988(void);
extern void func_0208799C(u32 token);
extern u32  func_0209C2B0(u32 a, s32 b);

/* --- subsystem A: this cluster's own ------------------------------------- */
extern void func_020737C0(struct SndObj *o);           /* constructor         */
extern void func_02073710(void *a);
extern void func_02073760(void *o, u32 v);
extern int  func_02073838(u8 *o, int n, u8 *src);      /* register n slots    */
extern void func_02073898(struct SndObj *o);           /* release the slot    */
extern void func_02073A60(struct SndObj *o);
extern void func_02073AB4(struct SndObj *o);
extern void func_02073AD0(struct SndObj *o, s32 v);    /* push base + re-emit */
extern void func_02073B3C(struct SndObj *o);           /* full teardown       */
extern void func_02073BB0(struct SndObj *o);
extern void func_02073BF0(struct SndSeq *o, u32 arg);  /* per-frame step      */
extern void func_02073CA0(struct SndObj *o);           /* short teardown      */
extern void func_02073CEC(struct SndObj *o);
extern void func_02073D5C(void);
extern void func_02073D7C(void);
extern void func_02073DFC(void);
extern void func_02073EE4(void);
extern void func_02073F3C(void);                       /* global shutdown     */

/* --- subsystem B: the file/stream layer ---------------------------------- */
extern int  func_02078B44(void *file, u32 pos, int origin);   /* seek         */
extern int  func_02078B70(void *file, void *dst, int len);    /* read         */
extern void func_020788AC(void *stream);
extern u32  func_020788D8(void *pair);
extern u32  func_020789A4(void *stream, struct ArcPair v);    /* BY VALUE     */

/* --- subsystem B: the allocator / list layer ----------------------------- */
extern u32   func_02060468(u8 *heap, u32 flag);
extern void *func_0206062C(void *list, void *cursor);  /* null cursor = head  */
extern void  func_020605B4(void *list, void *node);    /* unlink              */
extern void  func_020604AC(void *t, void *p);
extern void *func_020610E0(u32 size, u32 extra, u32 flag);
extern void  func_02061118(void *p);
extern u32   func_02061124(u32 heap, u32 size, u32 align);
extern void  func_02061158(u32 heap, u32 k);
extern void  func_02061184(u32 owner, u16 n);
extern void  func_020611D4(u32 owner, s32 key);
extern void  func_02082A90(void *dst, void *src, u32 n);      /* memcpy       */

/* --- subsystem B: this cluster's own ------------------------------------- */
extern u32   func_02073FB8(struct Arc *c, u32 unused, u32 a, u32 b);
extern u32   func_02074048(struct Arc *c, u32 a, u32 b);      /* 472 B, open  */
extern void  func_02074220(struct Arc *h, u8 *base);   /* relocate + publish  */
extern struct Arc *func_020742E4(struct Arc *val);     /* swap the global     */
extern struct Arc *func_020742FC(void);
extern void *func_0207430C(int index);                 /* the six getters     */
extern void *func_02074324(int index);
extern void *func_02074388(int index);
extern void *func_020743EC(int index);
extern void *func_02074450(int index);
extern void *func_020744B4(int index);
extern void *func_02074518(int index);
extern u32   func_0207457C(u32 idx);                   /* entry.size          */
extern int   func_020745A4(u32 idx, void *dst, int len, u32 off);
extern u32   func_0207466C(u32 idx);                   /* entry.field8        */
extern void  func_02074694(u32 idx, u32 val);          /* entry.field8 =      */
extern void  func_020746B0(int p0, int p1, int p2, int p3);
extern u32   func_020746E8(u32 off, u32 size);         /* sub-allocate        */
extern void  func_02074758(int a0, int a1, int a2, int a3);
extern void  func_02074770(struct ReqOwner *o);        /* drain everything    */
extern u32   func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern s32   func_02074894(struct ReqOwner *o);        /* close one handle    */
extern void  func_020748E0(struct ReqOwner *o, s32 k); /* bounded drain       */
extern void  func_020749F8(struct ReqOwner *o);
extern void  func_02074A34(void);

/* ================================================================== *
 * 5.  Constants
 * ================================================================== */
#define ARC_HDR_SIZE        0x30    /* func_02074220, func_02074048           */
#define ARC_ENTRY_STRIDE    0x10    /* func_02074220's walk                   */
#define ARC_TOC_RECS_OFF    0x0c    /* records start at toc + 0x0c            */
#define SND_SLOT_STRIDE     8       /* g_0214E934, ldr r1,[r2,r1,lsl #3]      */
#define REQ_PAYLOAD_OFF     0x20    /* callback arg 1 = node + 0x20           */
#define ALLOC_ALIGN         0x20    /* func_0207482C, func_020746E8 header    */

#endif /* CLUSTER_020737C0_H */
