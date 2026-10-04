/*
 * docs/families/pms_draw.h -- shared declarations for the pms_draw.c family
 * (0x0202DB0C..0x0202E43C in the ARM9 image).  The __FILE__ anchor at
 * 0x020A77B8 reads "pms_draw.c" and is loaded twice by func_0202DB0C
 * (line 0x81 for the 0x34-byte owner, line 0x8c for the element array),
 * which layout/file_anchors.txt pins to the range starting at 0x0202DB0C.
 * The tail is fuzzy by a function: 0x0202E474 onward is bag_param.c.
 *
 * This is the easy-chat (Pokemon Musical Sentence) message DRAWING side:
 * one owner object holds N "element" records, each of which owns two
 * clact actors, and the family creates, moves, redraws and tears those
 * down.  The INPUT side lives in overlay_110 (pms_input_*.c) and is not
 * part of this range.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT, and the
 * matched function that evidences each field or parameter is named in the
 * comment beside it.  Where two matched sources spell the same field
 * differently (they were written by different lanes), the spelling
 * recorded here is the one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef PMS_DRAW_H
#define PMS_DRAW_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * The owner.  0x34 bytes, evidenced twice over by func_0202DB0C, which
 * passes the literal 0x34 both to the allocator and to the memset.
 * ------------------------------------------------------------------ */
struct PmsDraw {
    u16   heap;      /* +0x00  the heap id the whole object was built on.
                      *        func_0202DB0C stores its own heap argument
                      *        here with `strh`, which is what makes it a
                      *        halfword; func_0202DB0C, func_0202DC60 and
                      *        func_0202E1F0 all re-read it out of the
                      *        object rather than off their own stack. */
    u8    pad02[2];
    u32   unk04;     /* +0x04  func_0202DB0C stores its fourth argument;
                      *        func_0202DC60 passes it on as the THIRD
                      *        register argument to func_0202E1F0. */
    void *unk08;     /* +0x08  func_0202DB0C stores its third argument;
                      *        func_0202DC60 passes it on as the SECOND
                      *        register argument to func_0202E1F0.  It is
                      *        also the cursor word func_0202DBC4 hands
                      *        to func_0202E0E0. */
    struct PmsElem *elems;
                     /* +0x0c  the element array, count * 0x28 bytes,
                      *        allocated at line 0x8c of func_0202DB0C.
                      *        The 0x28 stride is what the `movs r0,#0x28`
                      *        / `muls` pair says in func_0202DBC4,
                      *        func_0202DC08, func_0202DC60, sub_0202DCC4
                      *        and func_0202DD24: a stride the compiler
                      *        could reach with a shift would be `lsls`. */
    u8    sub10[0x14];
                     /* +0x10  the four-word resource sub-object
                      *        func_0202DF68 fills and sub_0202DFD4 tears
                      *        down; see struct PmsRes below.  It starts
                      *        at +0x10 because func_0202DB0C passes
                      *        `p + 0x10` to func_0202DF68 and
                      *        func_0202DC08 passes it to sub_0202DFD4. */
    u16   unk24;     /* +0x24  func_0202DB0C stores 0x11 << 6 = 0x440
                      *        (`movs r0,#0x11; lsls r0,#6`, the shifted
                      *        small constant idiom); func_0202DC60
                      *        forwards it to func_0202E1F0 as the second
                      *        of the four trailing stack arguments. */
    u8    pad26[2];
    u32   selected;  /* +0x28  func_0202DBC4 primes it to 1 and clears it
                      *        to 0 as soon as func_0202E0E0 answers
                      *        non-zero for any enabled element;
                      *        func_0202DC60 clears it unconditionally. */
    u32   unk2c;     /* +0x2c  func_0202DB0C zeroes it; func_0202DBC4
                      *        passes it to func_0202E0E0 as the third
                      *        argument (the "do the move" flag). */
    u8    count;     /* +0x30  how many elements.  UNSIGNED: func_0202DB0C
                      *        and func_0202DBC4 both load it with `ldrb`
                      *        and then compare signed (`ble` / `blt`), so
                      *        the field is u8 and the loop counter is
                      *        s32.  func_0202DB0C, func_0202DBC4 and
                      *        func_0202DC08 all re-read it at the top of
                      *        every iteration, and all three pay
                      *        `adds rN, #0x30` for the load because 0x30
                      *        is past the Thumb ldrb reach of +31
                      *        (docs/idioms/thumb-immediate-reach-costs-an-adds.md). */
    u8    unk31;     /* +0x31  func_0202DB0C stores the constant 0xf. */
};

/* ------------------------------------------------------------------ *
 * One element.  0x28 bytes, evidenced by the `movs #0x28` / `muls` pair
 * in every function that indexes the array (see PmsDraw::elems above).
 * ------------------------------------------------------------------ */
struct PmsElem {
    void *handle;    /* +0x00  the clact/resource handle every
                      *        func_02045xxx entry point takes.
                      *        func_0202E0E0 reads it for func_02045770,
                      *        func_02045334 and func_02045730;
                      *        func_0202E38C and func_0202E3E4 likewise. */
    u8    live;      /* +0x04  BYTE, not a word: func_0202E0E0 tests it
                      *        with `ldrb` and func_0202E1F0 clears and
                      *        sets it with `strb r,[r6,#4]`.
                      *        func_0202DD24 copies it byte-for-byte from
                      *        the source element. */
    u8    pad05[3];
    void *actor[2];  /* +0x08, +0x0c  the two clact actors.  A TWO-
                      *        ITERATION LOOP, not two written-out calls:
                      *        sub_0202E0C8, func_0202E38C, func_0202E3E4
                      *        and func_0202E0E0 all index with
                      *        `lsls`/`adds`/`ldr` and compare `cmp r,#2`
                      *        with a signed `blt`. */
    s32   x;         /* +0x10  func_0202E0E0 compares them against the
                      *        func_02041648/func_02041664 answers and
                      *        keeps the SIGNED difference, which is what
                      *        makes both fields s32. */
    s32   y;         /* +0x14 */
    struct PmsFlags flags;
                     /* +0x18  see below */
    u32   unk1c;     /* +0x1c */
    u32   enabled[2];
                     /* +0x20, +0x24  per-actor enable words.
                      *        func_0202E0E0 tests `!= 0`, func_0202E38C
                      *        zeroes both, func_0202E3E4 gates its
                      *        func_0204B3DC call on them, func_0202E1F0
                      *        writes 1, and func_0202DD24 copies both.
                      *        func_0202E1F0 reaches the ACTOR through
                      *        this field's address plus 8, not off the
                      *        element pointer: `*(void **)((u8 *)&e->enabled[i] + 8)`. */
};

/* The bitfield word at element +0x18.  Three bits are attested; the rest
 * of the word is untouched by anything matched so far.
 *
 * It must be spelled as BITFIELDS and not as `&= ~1` / `|= 2` masks
 * wherever two adjacent bits are set in a row: the compiler folds
 * `(x | 1) | 2` into `x | 3`, and func_0202E1F0's tail is
 * `bics #1; orrs #1; orrs #2` -- three separate operations that only a
 * bitfield pair produces.  func_0202E38C's two CLEARS do not fold and
 * are spelled there as `&= ~1` then `&= ~2`. */
struct PmsFlags {
    u32 b0 : 1;      /* sub_0202DCC4 returns exactly this bit with the
                      * `lsls #0x1f` / `lsrs #0x1f` pair
                      * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md);
                      * func_0202DBC4 gates on it; func_0202DD24 copies it. */
    u32 b1 : 1;      /* func_0202E0E0 gates the actor-enable loop on it;
                      * func_0202E3E4 assigns `(a1 & 1) << 1` into it. */
    u32 b2 : 1;      /* func_0202DCD4 writes it, guarded by b0. */
    u32 rest : 29;
};

/* ------------------------------------------------------------------ *
 * The resource sub-object at owner +0x10.  Five words; func_0202DF68
 * fills words 1..4 and sub_0202DFD4 releases words 2..4 with three
 * different ARM entry points in field order.
 * ------------------------------------------------------------------ */
struct PmsRes {
    u32   engine;    /* +0x00  BG engine selector, 0 = engine A.  Read by
                      *        func_0202DF68 as o[1] -- the sub-object's
                      *        SECOND word -- and handed to each of
                      *        sub_0202DE9C / sub_0202DEE0 / sub_0202DF24,
                      *        which turn it into 0x04000000 or
                      *        0x04001000.  (func_0202DF68 indexes its
                      *        own parameter from +0, so this struct's
                      *        word 0 is the owner's +0x10 and `engine`
                      *        is the owner's +0x14.) */
    void *unk04;     /* +0x04  ENV_SetResourceSet's answer; released by
                      *        func_0204ADA4. */
    void *unk08;     /* +0x08  func_0204A6C8's answer; released by
                      *        func_0204A8D4. */
    void *unk0c;     /* +0x0c  func_0204AF28's answer; released by
                      *        func_0204AFD8. */
    u32   unk10;
};

/* ------------------------------------------------------------------ *
 * The context block func_0202DC60 builds and func_0202E1F0 consumes.
 *
 * It is NOT a struct passed by value.  func_0202DC60 stores each field
 * straight into its own outgoing stack slot with `str`; a 16-byte
 * by-value struct makes the compiler stage a local and `ldm`/`stm` it
 * into the argument area, eighteen bytes more.  So func_0202E1F0's
 * trailing parameters are four plain words behind `w`, and the halfword
 * owner fields (+0x24, +0x31, +0x00) are widened to words at the call.
 *
 * The FIRST of the four, `cs`, is a POINTER: func_0202E1F0 does
 * `ldr r2,[sp,#0x64]; ldr r2,[r2]` and `ldr r3,[r2,#4]`, then narrows
 * both to s16 with `lsls #0x10` / `asrs #0x10`.  That refutes the
 * by-value reading recorded in the older docs/notes/pkt_0202E1F0.c.txt
 * prose.
 *
 * The stack parameter `w` is REUSED as the word-set pointer (wave 16):
 * `func_02024570(ws, w); w = ws;` and every later call passes w.  That is
 * what keeps &ws in r7 for the rest of the function and spills n; a fresh
 * pointer local is copy-propagated away.  412/412, 21 bytes out (an o/w
 * r6/r7 swap), docs/notes/pkt_0202E1F0.c.txt.
 * ------------------------------------------------------------------ */
struct PmsCs {
    u32 x;           /* +0x00  narrowed to s16 for func_0201C724 */
    u32 y;           /* +0x04  likewise */
};

/* ------------------------------------------------------------------ *
 * Prototypes.  Parameter types are the ones the byte evidence forces;
 * the evidencing function is named for each.
 * ------------------------------------------------------------------ */

/* Constructor.  The trailing arguments arrive as three separate word
 * slots read as u8 / u8 / u16 (`add rN, sp, #0x20` then `ldrb [.]`,
 * `ldrb [.,#4]`, `ldrh [.,#8]`), not as one by-value struct.
 * EXACT since wave 12 (src/matched/func_0202DB0C.c): the second
 * allocator's heap is `h = p->heap;` read back right after the store. */
struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d,
                              u8 e0, u8 e1, u16 heap);

/* The per-frame update over enabled elements; clears `selected` when any
 * element's func_0202E0E0 answers non-zero.  src/matched/func_0202DBC4.c */
void func_0202DBC4(struct PmsDraw *p);

/* Destructor: per-element teardown, then the array, then the resource
 * sub-object, then the owner.  src/matched/func_0202DC08.c */
void func_0202DC08(struct PmsDraw *p);

/* Two-argument shim that zeroes a 2-word scratch buffer and forwards.
 * src/matched/func_0202DC48.c */
void func_0202DC48(u32 a, u32 b, u32 c, u32 d);

/* The redraw entry.  ARGUMENT ORDER is pinned by func_0202DC60's own
 * bytes: r1 is the owner's +0x08 pointer, r2 the word at +0x04 and r3
 * the caller's own `a`, which func_0202DC60's prologue parks in r4
 * (`adds r4, r1, #0`) exactly because it is consumed last.
 * src/matched/func_0202DC60.c */
void func_0202DC60(struct PmsDraw *p, u32 a, void *w, u32 i, u32 e);

/* Reads element[i].flags.b0.  Leaf, no prologue, so no label.
 * src/matched/sub_0202DCC4.c */
u32  sub_0202DCC4(const struct PmsDraw *p, u32 i);

/* Sets element[i].flags.b2, guarded by b0.  src/matched/sub_0202DCD4.c */
void func_0202DCD4(struct PmsDraw *p, u32 i, u32 val);

/* Calls sub_0204B688 on both of element[i]'s actors.
 * src/matched/sub_0202DCFC.c */
void func_0202DCFC(struct PmsDraw *p, u32 i, u32 val);

/* Copies element[i] onto element[j], sprite state included.
 * EXACT* since wave 14 (src/matched/func_0202DD24.c): src = &p->elems[i]
 * before dst = &p->elems[j], handles read as src->handle / dst->handle,
 * dx declared before dy, the loop counter declared FIRST, and the offset
 * applied in the loop as `pt.x += dx * 8` (no ox/oy locals). */
void func_0202DD24(struct PmsDraw *p, u32 i, u32 j);

/* Grid coordinates to pixel coordinates, written through the fifth
 * argument, which arrives on the stack.  src/matched/unit_0202DE6C.c */
void sub_0202DE6C(u32 a, u32 b, u32 c, const struct PmsPos *base,
                  struct PmsPos *out);

/* Three copies of one BG-mode-to-resource-id map, differing only in the
 * four constants they answer with.  The mapping is a `switch` over
 * sparse values, not a chain of `if`s.  src/matched/unit_0202DE9C.c */
u32  sub_0202DE9C(u32 engine);
u32  sub_0202DEE0(u32 engine);
u32  sub_0202DF24(u32 engine);

/* Builds the four handles of the resource sub-object.  The screen-size
 * argument to ENV_SetResourceSet is `(u16)(a1 << 5)`, an unequal shift
 * pair, not a bitfield.  src/matched/func_0202DF68.c */
void func_0202DF68(struct PmsRes *o, u32 a1, u32 heap);

/* Creates one actor from the resource record and returns it.  The four
 * zero halfwords it stages MUST be a brace initialiser; the four-
 * statement form swaps r0 and r2 through the whole block.
 * src/matched/func_0202DFEC.c */
void *func_0202DFEC(struct PmsRes *r, u32 a);

/* Releases the sub-object's three handles, in field order.
 * src/matched/sub_0202DFD4.c */
void sub_0202DFD4(struct PmsRes *p);

/* Places one element sprite.  src/matched/func_0202E040.c */
void func_0202E040(void *h, u32 cell, u32 b, u32 c, u32 n,
                   const struct PmsPos *base);

/* Creates both of an element's actors and sets its flags.  The loop
 * counter is SIGNED: the image compares with `blt`, and u32 gives `blo`
 * (closed 2026-09-21 by tools/permuter.py).  src/matched/func_0202E09C.c */
struct Res;
void func_0202E09C(u8 *e, struct Res *r, u16 b);

/* Releases both of an element's actors.  src/matched/sub_0202E0C8.c */
void sub_0202E0C8(struct PmsElem *p);

/* The per-element update: retires a finished handle, syncs the two
 * actors' enable state, and slides both actors by the difference between
 * the stored and the current position.  src/matched/func_0202E0E0.c */
int  func_0202E0E0(struct PmsElem *e, void *cursor, int domove);

/* The full redraw.  Nine parameters: four in registers and five on the
 * stack (`w`, then `cs` and three words).  DIFF; see
 * docs/notes/pkt_0202E1F0.c.txt.  Its two callees' argument orders, read
 * off the image in wave 12:
 *   func_0202E040(e->actor[i], a3, p0, p1, func_020244D4(ws, i), cs);
 *   func_02043AF4(func_02045770(a3), p0, (s16)(p1 << 4), 0x54, 0x10, c2); */
void func_0202E1F0(struct PmsElem *e, u32 a1, u32 a2, u32 a3,
                   void *w, struct PmsCs *cs, u16 c1, u32 c2, u16 c3);
/* ADDED 2026-09-23 (wave 13): the image's 0x48-byte frame gives the two
 * arms of the second loop SEPARATE p0/p1 slots (0x28/0x2c and 0x30/0x34),
 * so each arm declares its own pair; &ws lives in r7 from the second call
 * on and the loop count n is spilled (0x20).  Still DIFF. */

/* Tears the drawing down and clears both flag bits.
 * src/matched/func_0202E38C.c */
void func_0202E38C(struct PmsElem *e, u32 a1);

/* Shows or hides: assigns `(a1 & 1) << 1` into flags.b1 and forwards to
 * both enabled actors.  src/matched/func_0202E3E4.c */
void func_0202E3E4(struct PmsElem *e, u32 a1);

/* Three unlabelled setters between func_0202DD24 and sub_0202DE6C
 * (src/matched/unit_0202DE5C.c, wave 12): +0x31 u8, +0x24 u16, +0x2c u32.
 * They are why func_0202DD24's listing extent reads 328 against 312. */
void sub_0202DE5C(struct PmsDraw *p, u8 v);
void sub_0202DE64(struct PmsDraw *p, u16 v);
void sub_0202DE68(struct PmsDraw *p, u32 v);

/* Is this cell id at or above 4.  Twelve bytes, no prologue; the arm
 * that falls through the `blo` is the one the source wrote first.
 * src/matched/sub_0202E430.c */
u32  sub_0202E430(u32 id);

/* A pool-word-and-bx tail call with two constant arguments.
 * src/matched/sub_0202E43C.c */
void sub_0202E43C(void *p);

struct PmsPos { u32 x; u32 y; };

#endif /* PMS_DRAW_H */
