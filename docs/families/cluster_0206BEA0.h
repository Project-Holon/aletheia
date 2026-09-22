/*
 * docs/families/cluster_0206BEA0.h -- shared declarations for the
 * pseudo-family cluster_0206BEA0 (0x0206BEA0..0x0206E388 in the ARM9 image).
 *
 * SUBSYSTEM.  This is the NDS 3D geometry-engine command layer: the GX
 * display-list / command-FIFO writer and the script interpreter that walks a
 * compiled model's command stream.  There is no __FILE__ anchor anywhere in
 * the upper half of the ARM9 image, so this cluster was formed by address
 * adjacency plus shared callees and data objects, not by a filename.  Three
 * things make the identification solid rather than a guess:
 *
 *   - func_0206DDA4 (src/matched/func_02047B4C.c, func_02047C04.c,
 *     func_0206A884.c, func_0206D3C4.c and twenty other callers) takes a
 *     command byte, a parameter block and a word count and either appends them
 *     to a capture list or writes them straight at 0x04000400, which is the
 *     DS GXFIFO port.  Its callers pass GX command numbers (0x10 MTX_MODE,
 *     0x11 MTX_PUSH, 0x12 MTX_POP, 0x15 MTX_IDENTITY, 0x19 MTX_TRANS,
 *     0x1b MTX_SCALE, 0x29 POLYGON_ATTR, 0x40 BEGIN_VTXS, 0x41 END_VTXS,
 *     0x70 BOX_TEST).
 *   - func_0206DE88 (src/matched/func_0206DE88.c) zeroes 0x04000440,
 *     0x04000444 and 0x04000454 and finishes by writing 1 to 0x04000448 and
 *     2 to 0x04000440: the geometry-engine control block.
 *   - func_0206DB80 / func_0206DB40 / func_0206DB60 / func_0206DBDC all
 *     manage one global pair at 0x0214BAB4, the capture-list head and the
 *     in-flight flag, and func_0206DBDC spins on the flag with `volatile`.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every declaration below is
 * derived from a file in src/matched that is EXACT, and the matched function
 * that evidences each field or parameter is named in the comment beside it.
 *
 * COMPILER.  This cluster is NOT the project default.  Every member whose
 * codegen is discriminating carries the `../2.0/sp2` per-file pin
 * (docs/FRONTEND-PINS.md): func_0206BF50, func_0206D2E8, func_0206D3C4,
 * func_0206DB80 and func_0206DE88.  The four trivial forwarders
 * (func_0206E348/58/88, func_0206DB40/60) and func_0206DBDC/func_0206DF14 are
 * byte-identical under both front ends and carry the default 1.1p1 header, so
 * they are not counterevidence.  Assume ../2.0/sp2 for anything in this range
 * and confirm with a probe; two long-standing DIFF notes in docs/notes
 * (func_0206DDA4.c.txt, pkt_0206DB80.c.txt) were 1.1p1 pin misses, and
 * func_0206DB80 closed to EXACT on the pin alone with no change to the C.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef CLUSTER_0206BEA0_H
#define CLUSTER_0206BEA0_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * HARDWARE.  The geometry engine's MMIO, spelled as cast constants
 * throughout this family (never as relocations).
 * ------------------------------------------------------------------ */

#define GXFIFO       (*(volatile u32 *)0x04000400)  /* func_0206DDA4 tail,
                                                       func_0206DB80's fill
                                                       constant is the same
                                                       word 0x04000400 used as
                                                       DATA, not an address */
#define GXSTAT_440   (*(volatile u32 *)0x04000440)  /* func_0206DE88 +0x1c */
#define GX_444       (*(volatile u32 *)0x04000444)  /* func_0206DE88 +0x20 */
#define GX_448       (*(volatile u32 *)0x04000448)  /* func_0206DE88 tail;
                                                       the store to 440 is
                                                       spelled `str r0,[r1,#-8]`
                                                       off THIS pool word, so
                                                       the pair is one base */
#define GX_454       (*(volatile u32 *)0x04000454)  /* func_0206DE88 +0x24 */
#define GXCLIP_600   (*(u32 *)0x04000600)           /* func_0206DF14 */

/* ------------------------------------------------------------------ *
 * THE CAPTURE-LIST GLOBAL at 0x0214BAB4.
 *
 * Two words.  Word 0 is the head of the display list currently being
 * captured (null when commands go straight at the FIFO); word 1 is a
 * secondary object whose non-zero value means a transfer is in flight.
 * func_0206DBDC spins on a THIRD word at +4 of the same address read as a
 * different shape -- the two spellings below are both attested and both
 * needed, because func_0206DBDC only reproduces with `volatile` on its word
 * and func_0206DDA4 only reproduces without it.
 * ------------------------------------------------------------------ */

struct GxList {
    u32 count;      /* +0x00  words already in the list  (func_0206DDA4) */
    u32 cmds[1];    /* +0x04  the command words themselves (func_0206DDA4) */
};

struct GxState {
    struct GxList *list;    /* +0x00  func_0206DB40, func_0206DB60,
                                       func_0206DB80, func_0206DDA4 */
    void          *unk_04;  /* +0x04  func_0206DDA4, func_0206DBDC */
};

extern struct GxState g_0214BAB4;

/* The same object seen as a plain word array, which is how func_0206DB80
 * spells it (src/matched/func_0206DB80.c): g[1] is the in-flight test and
 * g[0] is the list head whose word 0 is the count.  A bare `char *` form is
 * what func_0206DB40/func_0206DB60 use. */
extern u32  *g_0214BAB4_words[2];   /* func_0206DB80 */

/* The capacity bound, from the `cmp r1, #0xc0` at func_0206DDA4+0x38: a
 * capture list holds 0xc0 words INCLUDING the command word. */
#define GX_LIST_CAPACITY 0xc0

/* ------------------------------------------------------------------ *
 * THE SCRIPT-INTERPRETER CONTEXT.
 *
 * Every opcode handler in the 0x0206BEA0..0x0206D778 half takes one pointer
 * to this object.  Offsets 0x00, 0x08, 0x34 and 0x96 are attested by
 * src/matched/func_0206D2E8.c; 0x20 and 0x91 by src/matched/func_0206BF50.c;
 * 0xad and 0xd8 by func_0206BEA0 (docs/notes/pkt_0206BEA0.c.txt, DIFF but
 * every branch and immediate reproduces); 0xdc by func_0206C024
 * (docs/notes/pkt_0206BEA0.func_0206C024.c.txt); 0xe0/0xe4 by
 * src/matched/func_0206D3C4.c; 0xb0 by func_0206D434's prologue.
 *
 * The struct is deliberately written as one union of the attested offsets
 * rather than as several per-function structs: every handler is reading the
 * same object, and the per-function structs in src/matched differ only in
 * which padding run they chose to name.
 * ------------------------------------------------------------------ */

struct GxScript {
    u8  *cur;                       /* +0x00  the instruction cursor.  Every
                                               handler advances it by its own
                                               opcode width: +2 in
                                               func_0206BEA0 / func_0206C024,
                                               +9 in func_0206D2E8. */
    u32  pad04;
    u32  flags;                     /* +0x08  the gate word; see below */
    u8   pad0c[0x20 - 0x0c];
    void (*hook20)(struct GxScript *); /* +0x20  func_0206BF50 */
    u8   pad24[0x34 - 0x24];
    void (*hook34)(struct GxScript *); /* +0x34  func_0206D2E8 */
    u8   pad38[0x91 - 0x38];
    u8   state91;                   /* +0x91  func_0206BF50: the four-stop
                                               walk's state byte, read THROUGH
                                               hook20 (zero when hook20 is
                                               null) */
    u8   pad92[0x96 - 0x92];
    u8   mode96;                    /* +0x96  func_0206D2E8, the same byte one
                                               hook over */
    u8   pad97[0xad - 0x97];
    u8   last_opcode;               /* +0xad  func_0206BEA0: the previous
                                               record index, compared against
                                               cur[1] under flag bit 3 */
    u8   padae[0xb0 - 0xae];
    void *obj_b0;                   /* +0xb0  func_0206D434 */
    u8   padb4[0xd8 - 0xb4];
    u8   *recbase_d8;               /* +0xd8  func_0206BEA0: the record table
                                               whose sub-table starts at +4 */
    u8   *recbase_dc;               /* +0xdc  func_0206C024: the same shape one
                                               slot over, sub-table at +0 */
    u8   pade0[0xe0 - 0xe0];
    u32  fe0;                       /* +0xe0  func_0206D3C4 */
    u32  fe4;                       /* +0xe4  func_0206D3C4 */
};

/* The gate word at +0x08.  Four bits are attested:
 *
 *   0x001  "run this opcode"      func_0206BEA0, func_0206C024 (tst/bne)
 *   0x002  "suppressed"           func_0206C024 (tst r0,#2 / bne skip)
 *   0x008  "dedupe against +0xad" func_0206BEA0 (tst r0,#8 / beq run)
 *   0x040  the hook's own busy bit; every hook dispatch in func_0206BF50 and
 *          func_0206D2E8 clears it with `bic r1,r1,#0x40` before the call and
 *          re-tests it after
 *   0x100  "do not forward"       func_0206BF50, func_0206D2E8, func_0206D3C4
 *   0x200  "whole context off"    func_0206BEA0, func_0206C024,
 *          func_0206C524, func_0206D434, func_0206D3C4 (with 0x100)
 */
#define GXS_RUN       0x001
#define GXS_SUPPRESS  0x002
#define GXS_DEDUPE    0x008
#define GXS_HOOK_BUSY 0x040
#define GXS_NOFWD     0x100
#define GXS_OFF       0x200

/* ------------------------------------------------------------------ *
 * THE RECORD TABLE.
 *
 * func_0206BEA0 and func_0206C024 are the same lookup written one slot apart
 * (+0xd8 with the sub-table at rec+4, +0xdc with it at rec+0).  The layout is
 * fixed by func_0206BEA0's `ldrb r0,[lr,#5]` / `ldrh r2,[lr,#0xa]` against
 * func_0206C024's `ldrb r0,[ip,#1]` / `ldrh r2,[ip,#6]`: the same two fields,
 * four bytes apart, which is what proves the +4.
 * ------------------------------------------------------------------ */

struct GxRecTbl {
    u8  f0;
    u8  n;      /* +0x01  entry count; the index is bounds-checked `>= n` */
    u8  f2;
    u8  f3;
    u16 f4;
    u16 off;    /* +0x06  byte offset from THIS struct to the stride header */
};

/* The lookup both functions inline, written out so a later lane can spell it
 * the same way.  `sz` is the record stride, read as a halfword at the head of
 * the sub-table; the payload starts four bytes past it.  Both functions then
 * indirect once more, `q = base + *(u32 *)q`, and dispatch on the halfword at
 * the result through a table of function pointers. */
static u8 *gx_rec_lookup(struct GxRecTbl *t, u32 k)
{
    u8 *p;
    u16 sz;
    if (t == 0) return 0;                   /* the null test really is
                                               duplicated in the image: the
                                               doubled `beq` on one `cmp` at
                                               func_0206C024+0x34/+0x38 is
                                               this test plus the caller's */
    if (k >= t->n) return 0;
    p = (u8 *)t + t->off;
    sz = *(u16 *)p;
    return p + 4 + sz * k;
}

/* The two dispatch tables, one per lookup site.  Both are pure data in the
 * rodata tail and both resolve `literal x5`. */
extern void (*tbl_020A82C8[])(struct GxScript *);  /* func_0206BEA0 +0x8c */
extern void (*tbl_020A82D8[])(struct GxScript *);  /* func_0206C024 +0x7c */

/* ------------------------------------------------------------------ *
 * PROTOTYPES, with the exact parameter types the byte evidence fixes.
 * ------------------------------------------------------------------ */

/* --- the command writer and its helpers --- */

/* The one command writer.  `cmd` is the packed command word, `params` the
 * parameter block, `n` the parameter WORD count (the image multiplies by 4 at
 * every use).  n == 0 is a legal early return. */
extern void  func_0206DDA4(u32 cmd, const void *params, u32 n);

/* Drain: wait out any in-flight transfer, then blank the current list's
 * payload with the word 0x04000400 and zero its count.  No arguments; its
 * 1.1p1/2.0 split is the address-rematerialisation tell. */
extern void  func_0206DB80(void);

extern void  func_0206DB40(u32 *p);    /* install p as the list head, once */
extern void *func_0206DB60(void);      /* drain, then take and clear the head */
extern void  func_0206DBDC(void);      /* spin while g_0214BAB4.unk_04 != 0 */

/* Geometry-engine reset: drain, clear 440/444/454, optionally spin two
 * readiness polls, then arm 448 and 440. */
extern void  func_0206DE88(void *a, void *b);

extern void  func_0206DF14(void);      /* clip-matrix reset via 0x04000600 */

/* --- the script-interpreter opcode handlers --- */

extern void  func_0206BEA0(struct GxScript *c);  /* opcode via +0xd8 table */
extern void  func_0206BF50(struct GxScript *p, u32 unused, void *a);
                                                 /* the four-stop hook walk;
                                                    the middle argument is
                                                    genuinely unused, it is
                                                    the family's fixed
                                                    three-argument handler
                                                    signature */
extern void  func_0206C024(struct GxScript *c);  /* opcode via +0xdc table */
extern void  func_0206C0C4(struct GxScript *c);  /* the big parser, 1104 B */
extern void  func_0206C524(struct GxScript *c, u32 kind);
                                                 /* 732 B; `kind` is compared
                                                    against 0x20/0x40/0x60 and
                                                    decides a cursor step of
                                                    2, 3 or 4 */
extern void  func_0206C82C(struct GxScript *c);  /* 820 B */
extern void  func_0206CB8C(struct GxScript *c);  /* 1868 B, the widest handler */
extern void  func_0206D2E8(struct GxScript *s);  /* the nine-byte opcode */
extern void  func_0206D3C4(void *o, u32 which);  /* the 0x1b three-word push */
extern void  func_0206D434(struct GxScript *c);  /* 816 B, works through +0xb0 */
extern void  func_0206D778(struct GxScript *c);  /* 908 B */

extern void  func_0206DC00(void *p, u32 v);      /* 404 B; the forwarder every
                                                    gated handler calls with a
                                                    pointer and a word */
extern void  func_0206DF3C(void *a, void *b, void *c);
                                                 /* 384 B, fixed-point matrix
                                                    multiply: smull/smlal
                                                    quartets against a 0x40-byte
                                                    matrix at a pooled global,
                                                    results shifted right 12 */
extern void  func_0206E0C4(void);                /* 644 B */

/* --- the tail forwarders (all EXACT, all trivial) --- */
extern void  func_0206E348(int a0, int a1, int a2, int a3);  /* -> func_02061330
                                                                with a1 forced
                                                                to 0x54 */
extern void  func_0206E358(void);                /* -> func_02061344 */
extern void  func_0206E364(u32 a, u32 b, u32 c); /* -> func_02061330(a,
                                                    func_02069C14(b, c)) */
extern void  func_0206E388(void);                /* -> func_02061344 */

/* --- externals this cluster calls --- */
extern void  func_02082AA8(void *dst, u32 c, u32 n);   /* word fill */
extern void  func_02082B0C(const void *src, void *dst, u32 n); /* word copy */
extern u32   func_0207DC98(void *p);
extern u32   func_0207DCC8(void *p);
extern void  func_0207BDE0(void *p, void *q);
extern void  func_0207BC08(void *a, void *b, void *c);
extern void  func_0207C8A0(u32 v);
extern void  func_02085D3C(void);
extern void  func_0207D988(void);
extern void  func_0206A700(void);
extern void  func_02061330(u32 a, u32 b);
extern void  func_02061344(void);
extern u32   func_02069C14(u32 a, u32 b);

#endif /* CLUSTER_0206BEA0_H */
