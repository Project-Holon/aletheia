/*
 * docs/families/billboard_act.h -- shared declarations for the
 * billboard_act.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * Family: original source file **billboard_act.c**, 0x0204FE94..0x02050B80 in
 * the ARM9 image (edges fuzzy by a function or two).  The file name is not a
 * guess: layout/file_anchors.txt row 273 resolves the pool word at 0x0204FFF4
 * (the __FILE__ argument of the constructor func_0204FE94's three
 * func_02030734 calls) to 0x020A7FB0, and the bytes there spell
 * "billboard_act.c"; its start is pinned by the NUL terminator of
 * "billboard.c" at 0x020A7FAF, which is the sibling family's own anchor.  The
 * constructor's three allocation line numbers, 94 / 119 / 123, are monotone in
 * address, which is the second, independent check that this is one original
 * translation unit.  The next anchor down, 0x020A7FC0 = "particle.c", is what
 * bounds the family from below: func_02050B80 onwards is particle.c, not this
 * file (src/matched/func_02050B80.c carries that anchor).
 *
 * Sibling family: **billboard.c**, 0x0204EBD4..0x0204F7DC, anchor 0x020A7FA4.
 * billboard_act.c is the ACTOR layer over it: every graphics primitive this
 * family needs is a func_0204Fxxx call into billboard.c, and the constructor
 * builds a billboard.c board (func_0204EBD4) as its own sub-object at +4.  Its
 * declarations are reproduced below under "billboard.c interface" because
 * nothing in this family can be written without them.
 *
 * Derived from the 25 matched sources found with
 *   grep -l "address:  0x0204F[E-F]\|address:  0x02050[0-9A-B]" src/matched/*.c
 * plus the billboard.c sources at 0x0204EBD4..0x0204F7DC for the callee
 * prototypes.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness (there is no
 * immediate-offset form, see
 * docs/idioms/ldrsh-register-offset-is-signedness.md); a shift pair of unequal
 * amounts proves a bitfield's width and position; a plain `ldrh` followed by a
 * SIGNED compare (`blt`/`bge`) proves the field is a u16 PROMOTED to int at the
 * use, not that the counter is unsigned.  Where two matched files disagree, the
 * file whose code actually constrains the field wins and the losing spelling is
 * recorded beside it as `WAS:`.
 */

#ifndef BILLBOARD_ACT_H
#define BILLBOARD_ACT_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ */
/* THE FILE NAME.  Declared as an extern array pinned by address, never  */
/* as a literal __FILE__ (docs/idioms/file-string-is-an-abs32-into-the-  */
/* string-area.md).  Evidenced by src/matched/func_0204FE94.c.          */
/* ------------------------------------------------------------------ */

extern const char sBillboardAct[];          /* 0x020A7FB0  "billboard_act.c" */

/* The 28-byte board template the constructor copies onto its stack before
 * handing it to func_0204EBD4.  Its ONLY referrer image-wide is the pool word
 * at 0x0204FFF8 inside func_0204FE94, so it is attested `sole-ref/data`, never
 * `literal`.  It must be a 4-ALIGNED AGGREGATE (seven u32 words): mwcc expands
 * the assignment to a 16-byte ldm/stm pair with write-back plus a 12-byte pair
 * without, reusing the bases the write-back left behind
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).  A byte array compiles to
 * a copy loop instead.  Evidenced by src/matched/func_0204FE94.c, and by the
 * identical expansion in the sibling src/matched/func_0204EBD4.c.
 */
struct Blob28 { u32 w[7]; };

extern const struct Blob28 gBillboardActTpl;   /* 0x020A155C, align 4 */

/* ------------------------------------------------------------------ */
/* STRUCT LAYOUTS                                                       */
/* ------------------------------------------------------------------ */

/* The system object.  0x24 bytes, allocated at billboard_act.c line 94.
 * Every offset below is constrained by a load or a store in a matched source;
 * the evidencing function is named per field.
 */
struct BbActSys {
    u16   f00;      /* heap id, narrowed to u16      func_0204FE94 (strh r7,[r6]) */
    u16   f02;      /* (padding; never touched)                                   */
    void *f04;      /* the billboard.c board          func_0204FE94, func_0204FFFC */
    u32   f08;      /* caller's mode word             func_0204FE94 (str r8,[r6,#8]) */
    u8   *f0C;      /* slot array, f10 * 8 bytes      func_0204FE94 line 119      */
    u16   f10;      /* slot count                     func_0204FE94 (strh sl,[r6,#0x10]) */
    u16   f12;      /* (padding; never touched)                                   */
    void *f14;      /* slot index pool (func_02033C00 over f10)  func_0204FE94    */
    void *f18;      /* entry array, f1C * 0x28 bytes  func_0204FE94 line 123      */
    u16   f1C;      /* entry count, LIVE count        func_020504D8, func_0204FFFC */
    u16   f1E;      /* (padding; never touched)                                   */
    void *f20;      /* entry index pool (func_02033C00 over f1C) func_0204FE94    */
};

/* NOTE on f1C.  It is a u16 but every loop over it compares SIGNED (`blt` on
 * the back edge, `ble` on the entry guard), so the loop counter is a plain
 * `int` and f1C is promoted to int at the compare -- NOT an unsigned compare
 * against a u16.  Evidenced identically by src/matched/func_020504D8.c and
 * docs/notes/pkt_02050340.c.txt (func_0204FFFC).  Contrast the `count` PARAMETER of
 * func_02050278 and func_02050468, which really is u32 (`blo` back edge).
 *
 * NOTE on the re-read.  f1C is re-loaded from the object at the BOTTOM of
 * every loop as well as at the top, because the per-entry callbacks may change
 * it.  Caching it in a local gives one load and a different loop shape.
 * Evidenced by src/matched/func_020504D8.c and docs/notes/pkt_02050340.c.txt (func_0204FFFC).
 */

/* The 8-byte slot record, the element of BbActSys.f0C.  Written as an ARRAY
 * SUBSCRIPT on this struct, never as a pointer-plus-byte-offset: the subscript
 * form emits the original's split `base + idx<<3` / `i<<3` addressing and the
 * `strh r0,[r2,r1]` pair, while the pointer form allocates the same two
 * instructions the other way round and is a whole-function DIFF.  Evidenced by
 * src/matched/func_02050238.c (which cost three attempts on exactly this) and
 * again by the residue note for func_020500F0.
 */
struct BbActSlot {
    u16 id;         /* 0xFFFF = empty sentinel     func_02050238, func_02050278 */
    u16 pad;
    u32 val;        /* payload word                func_02050238, func_02050894 */
};

/* The 0x28-byte entry record, the element of BbActSys.f18. */
struct BbActEntry {
    u32   f00;                              /* 0xFFFF = empty sentinel   func_020504D8, func_0204FFFC */
    u16   f04;                              /* index into the slot array func_02050894 */
    u16   f06;
    u32 **f08;                              /* command script table      func_02050550 */
    u16   f0C;
    u16   f0E;                              /* script page index         func_02050550 */
    u16   f10;                              /* command cursor            func_02050550, func_02050A00 */
    u16   f12;                              /* delay counter             func_02050550, func_02050A00 */
    u32   f14;                              /* repeat counter            func_02050A00 */
    u32   f18;                              /* enabled flag              func_02050550 */
    void (*f20)(void *owner, int i, u32 a); /* per-entry hook, optional  func_020504D8 */
    u32   f24;                              /* hook's third argument     func_020504D8 */
};

/* The 0x24-byte build descriptor func_02050340 consumes, one per entry. */
struct BbActDesc {
    u16 slot;               /* 0x00  added to the caller's base -> entry f04 */
    s16 v12;                /* 0x02  -> func_0204F428 v12 (ldrsh) */
    s16 v14;                /* 0x04  -> func_0204F428 v14 (ldrsh) */
    u8  k;                  /* 0x06  -> func_0204F428 k */
    u8  pad07;
    u32 flag;               /* 0x08  address passed to func_0204F720 */
    u32 w;                  /* 0x0c  -> func_0204F428 w */
    s32 pos[3];             /* 0x10  -> func_0204F428 src (Vec3) */
    u32 f1c;                /* 0x1c  -> entry f20 */
    u32 f20;                /* 0x20  -> entry f24 */
};

/* The 12-byte request func_020500F0 consumes. */
struct BbActRec { u32 f00; u8 b4, b5, b6, b7; u32 type; };

/* The 4-byte script command.  The 14/1/1 bit split is proved by the lsl/lsr
 * pairs, which no mask spelling reproduces
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  Evidenced
 * by src/matched/func_02050550.c, func_02050920.c and func_02050944.c; the
 * same 14-bit field appears on the billboard.c side in func_0204F5A8.c.
 */
struct BbActCmd {
    u16 op  : 14;   /* command id; 0x3FFC..0x3FFF are the four handlers */
    u16 b   : 1;
    u16 c   : 1;
    u16 f02;        /* argument halfword; some handlers read it as two bytes */
};

/* The slot bank of the 3D-engine configuration layer, 0x02146A84.  Four
 * 16-byte records.  The stride is a POWER OF TWO and the image emits
 * `add r1, r3, r4, lsl #4` for it: spelling the record any other size makes
 * mwcc emit a multiply and shifts the whole register file.  This was the
 * single cause of the 44-byte residue docs/notes/pkt_02050A70.c.txt had
 * written up as an unreachable allocator tie; see src/matched/func_02050B14.c.
 * Evidenced by src/matched/func_02050A70.c and src/matched/func_02050B14.c.
 */
struct BbActBankSlot {
    u32 unk00;
    u32 unk04;
    u32 unk08;      /* the packed configuration word func_02050B14 repacks */
    u32 active : 1; /* bit 0 of +0x0C */
    u32 torn   : 1; /* bit 1 of +0x0C */
    u32 kill   : 1; /* bit 2 of +0x0C */
    u32        : 29;
};

extern struct BbActBankSlot *g_02146A84;    /* the bank pointer, a VARIABLE:
                                             * re-read after every store,
                                             * because a store through it can
                                             * overwrite the pointer itself.
                                             * func_02050A70. */

/* ------------------------------------------------------------------ */
/* PROTOTYPES -- billboard_act.c's own functions                        */
/* ------------------------------------------------------------------ */

/* construction / destruction */
void *func_0204FE94(u16 slots, u16 entries, u32 mode, int heap);  /* EXACT */
void  func_0204FFFC(struct BbActSys *o);                          /* EXACT*, F5A8 gets
                                                                   * (o->f04, entry word) */

/* slot-record initialisers */
void  func_02050084(void);                                        /* EXACT, the no-op hook */
void  func_02050088(int p0, int p1, int p2, int p3);              /* EXACT */
void  func_020500A0(int p0, int p1, int p2, int p3);              /* EXACT */
void  func_020500B8(u32 *p);                                      /* EXACT */

/* slot allocation / release */
u16   func_020500F0(struct BbActSys *p, const struct BbActRec *recs,
                    u32 n);                                       /* EXACT, recs is CONST */
int   func_02050238(void *p, u16 b, int c);                       /* EXACT */
void  func_02050278(struct BbActSys *o, u32 first, u32 count);    /* EXACT */
int   func_02050304(int a0, int a1, int a2, int a3);              /* EXACT */
u16   func_02050340(struct BbActSys *o, u16 base,
                    const struct BbActDesc *d, u32 count, u32 mode); /* EXACT, d is CONST */
void  func_02050468(struct BbActSys *o, u32 first, u32 count);    /* EXACT, o->f18[first + i] */

/* the per-frame tick */
void  func_020504D8(struct BbActSys *o);                          /* EXACT */
void  func_02050550(void *owner, void *entry);                    /* EXACT */
void  func_020506B8(void *o, void *e, u32 a2);                    /* EXACT */
u32   func_02050738(void *p, void *q);                            /* EXACT* */
int   func_020507A0(void *p, int idx, u32 x);                     /* EXACT, entry is
                                                                   * 0x020507A0, NOT the
                                                                   * worklist's 0x020507A4;
                                                                   * see below. */
void  func_02050804(void *p, int idx, u32 v, u16 h);              /* EXACT */
void  func_0205085C(void *p, int idx, u16 v);                     /* EXACT */
int   func_02050894(void *p, int idx, int j);                     /* EXACT* */

/* the script-command handlers, and the table that dispatches them */
int   func_02050920(struct BbActCmd *c);                          /* EXACT */
int   func_02050944(void *p, struct BbActCmd *c);                 /* EXACT */
void *func_02050984(u32 id);                                      /* MATCH (src/pending) */
int   func_020509E0(void);                                        /* EXACT, returns 1 */
int   func_020509E8(void *e, void *c);                            /* EXACT, returns 0 */
int   func_02050A00(void *e, struct BbActCmd *c);                 /* EXACT, returns 0 */
int   func_02050A58(void *e, struct BbActCmd *c);                 /* EXACT, returns 0 */

/* the 3D-engine configuration layer */
void  func_02050A70(void);                                        /* EXACT */
void  func_02050B14(u32 idx);                                     /* EXACT */

/* ------------------------------------------------------------------ */
/* THE DISPATCH TABLE                                                   */
/* ------------------------------------------------------------------ */

/* func_02050984 maps a command op to one of four handlers and returns 0 for
 * anything else.  The case labels read 0x3FFC..0x3FFF because the image
 * normalises with TWO subtracts and no `mov` of the base (0x3FC then 0x3C00,
 * i.e. 0x3FFC); spelling them 0x43FC..0x43FF makes the second subtract
 * `#0x4000` and reorders the arms.  The cases must be written in DESCENDING
 * source order, which is what puts case 0x3FFF's arm nearest the table.
 * Evidenced by src/pending/func_02050984.c.
 *
 *   0x3FFC -> func_02050A58   set cursor from the argument's low half, clear delay
 *   0x3FFD -> func_02050A00   repeat-count form of the same, two bytes packed in f02
 *   0x3FFE -> func_020509E8   copy the argument halfword into the entry's +0x0E
 *   0x3FFF -> func_020509E0   stop (returns 1, the "script finished" verdict)
 *
 * Every handler returns int, and the two callers (func_02050920 and
 * func_02050944) test it: 0 means "command consumed, keep reading", nonzero
 * means "stop".  func_02050944 CALLS the returned pointer, so the table's
 * entries are `int (*)(void *entry, struct BbActCmd *cmd)`, not `void (*)(void)`.
 */

#define BBACT_CMD_SET      0x3FFC
#define BBACT_CMD_REPEAT   0x3FFD
#define BBACT_CMD_PAGE     0x3FFE
#define BBACT_CMD_STOP     0x3FFF
#define BBACT_SLOT_EMPTY   0xFFFF   /* always a POOL WORD, never an immediate:
                                     * hoisted into a callee-saved register
                                     * before every loop that tests it.
                                     * func_020504D8, func_0204FFFC,
                                     * func_02050278, func_020500F0. */
#define BBACT_ENTRY_STRIDE 0x28
#define BBACT_SLOT_STRIDE  8
#define BBACT_BANK_STRIDE  0x10     /* a power of two -- see BbActBankSlot */

/* ------------------------------------------------------------------ */
/* billboard.c interface -- the sibling family this one is layered on    */
/* ------------------------------------------------------------------ */

void *func_0204EBD4(void *src28, int heap);            /* board constructor */
void  func_0204ED24(void *board);                      /* board destructor  */
u16   func_0204EF58(void *board, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
void  func_0204F10C(void *board, u32 id);
void  func_0204F150(void *board, u32 id);                /* TWO args: func_02050278 */
void  func_0204F2B4(u32 res, u32 id, u32 *out);
void  func_0204F2CC(u32 a, u16 b, u32 *out);
void  func_0204F344(u32 res, u32 id, u32 a2, u32 *o0, u32 *o1, u32 zero);
void  func_0204F5A8(void *board, u32 idx);             /* release one record */
void  func_0204F66C(u32 res, u32 id, u16 *v);
int   func_0204F720(u32 a, u32 b, void *buf);
void  func_0204F764(u32 res, u32 id, u32 *v);
void  func_0204F794(u32 res, u32 id, u32 *v);

/* NOTE on const.  TWO of this family's "scheduling walls" were a missing
 * `const` on a read-only input array (func_020500F0's request records,
 * func_02050340's 0x24-byte descriptors): with const, mwcc lets the field loads
 * move above the stores into the entry / slot arrays and the outgoing-argument
 * stores, which is the batched-load schedule the image has.  If a residue
 * here is "the image loads early, we load late", try const before anything
 * else.  Evidenced by src/matched/func_020500F0.c and func_02050340.c.
 *
 * NOTE on subscripts.  `o->f18[first + i]` / `o->f0C[first + i]` written
 * plainly is what emits the image's hoisted `first * stride` and the mixed
 * `base + (first<<3) + (i<<3)` addressing; every hand-built byte-offset or
 * stride-local spelling in the old notes was a regression.  Evidenced by
 * src/matched/func_02050468.c and func_02050278.c.
 *
 * NOTE on func_02050340's view of func_0204F428: the caller passes v12/v14 as
 * s16 (ldrsh, no narrowing) and the Vec3 source as const.
 */

/* NOTE on func_0204F5A8's arity.  It takes TWO arguments, and both call sites
 * in this family pass both (`ldr r0,[r5,#4]; ldr r1,<record word>`).  Declaring
 * it with one argument costs four bytes at func_0204FFFC's call site (the
 * second argument's `mov` disappears and the whole register file shifts), and
 * declaring it with two at a site that only sets r0 adds four.  Evidenced by
 * docs/notes/pkt_02050340.c.txt (func_0204FFFC) and the func_02050468 residue.
 */

/* ------------------------------------------------------------------ */
/* OUTSIDE THE FAMILY -- allocator and index-pool helpers               */
/* ------------------------------------------------------------------ */

void *func_02030734(int heap, int size, int align, const char *file, int line);
void  func_020307B0(void *p);
void *func_02033C00(int n, int heap);       /* make an index pool of n entries */
void  func_02033C9C(void *pool);            /* destroy an index pool           */
int   func_02033CA8(u32 pool, u32 n);       /* take n consecutive indices      */
void  func_0203422C(void *pool, u32 first, u32 count);  /* give them back      */
u32   func_020473D8(u32 v);
u32   func_020473EC(u32 v);
void  func_02046EFC(void *p);
u32   OS_DisableInterrupts(void);           /* 0x02087988 */
void  OS_RestoreInterrupts(u32 s);          /* 0x0208799C */

/* ------------------------------------------------------------------ */
/* ONE ARTIFACT ROW, resolved                                           */
/* ------------------------------------------------------------------ */

/* 0x02050080 IS a function, and 0x02050084 is not: the 8 bytes after
 * func_0204FFFC's pool are `ldr r0, [r0, #4]; bx lr`, the board getter
 * `void *f(struct BbActSys *o) { return o->f04; }`, blx'd from ov021
 * (0x02188EFE and four more).  layout/function_starts.txt seeds 0x02050084,
 * the getter's `bx lr`, and src/matched/func_02050084.c matches that lone
 * instruction as an "empty leaf".  Integrator item: seed 0x02050080; the
 * 0x02050084 entry is the tail of the getter.  func_0204FFFC is EXACT* until
 * then.
 */

/* The worklist row "0x020507A4 / 44 bytes" is NOT a function.  The real entry
 * is 0x020507A0, four bytes earlier: the function's first instruction is a bare
 * `push {r0, r1, r2, r3}`, the address-of-a-register-parameter lowering
 * (docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md), and
 * disasm.py only auto-labels a prologue that saves lr, so it prints as a stray
 * `.word` and the label lands on the `push {r3, lr}` behind it.  The function
 * is 48 bytes from 0x020507A0 and is filed as src/matched/func_020507A0.c.
 * docs/notes/pkt_020507A4.c.txt records the same finding.
 */

#endif /* BILLBOARD_ACT_H */
