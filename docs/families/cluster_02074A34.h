/*
 * docs/families/cluster_02074A34.h -- shared declarations for the
 * pseudo-family at 0x02074A34..0x0207533C in the ARM9 image, and for its
 * immediate neighbour pkt_02075404 (0x02075404..0x02075794).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.  Same format and same adjudication rule as
 * docs/families/cluster_020737C0.h, from which this file takes its layout.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit; it was formed by address adjacency plus shared callees and data
 * objects.  Unlike its neighbour at 0x020737C0, however, it is ONE subsystem
 * throughout:
 *
 *   THE SOUND ARCHIVE LOADER -- the layer between the resource archive
 *   (func_02074324 / func_02074388 / func_020743EC / func_02074450 /
 *   func_02074518 entry lookup, func_0207457C sizing, func_020745A4 streamed
 *   read, func_0207466C residency test, func_02074694 publish, func_0207482C
 *   allocate-with-teardown, func_020742FC current heap) and the NitroSDK sound
 *   driver (SND_* at 0x020894xx-0x0208Axxx: func_0208A2BC, func_0208A38C,
 *   func_0208A424, func_0208A46C/0x0208A48C sequence iteration,
 *   func_0208A638/0x0208A640/0x0208A674 bank residency, func_020896AC /
 *   func_020896CC / func_020896EC range invalidation).  Its job is to take a
 *   resource id, work out which waves, banks and sequence-archive entries that
 *   id transitively needs, pull each one into a heap buffer, flush it with
 *   DC_StoreRange and hand it to the driver -- and to run the same walk in
 *   reverse on teardown.
 *
 *   Four layers, bottom up:
 *     1. LEAF LOADERS.  func_02074E9C is the generic "size it, allocate it,
 *        read it, flush it" worker; func_02074F3C / func_02074FA8 /
 *        func_02075014 / func_02075080 are four byte-identical wrappers that
 *        differ ONLY in which teardown callback they hand it (func_0207524C /
 *        func_020752A4 / func_02075274 / func_020752A4).  func_020750EC is the
 *        fifth, the one whose payload needs splitting and clearing.
 *     2. TEARDOWN CALLBACKS.  func_020751F4 is the shared body; func_0207524C /
 *        func_02075274 / func_020752A4 / func_020752D4 / func_020752F4 are its
 *        five flavours, each adding the driver call its resource kind needs.
 *     3. KIND DISPATCHERS.  func_02074BEC, func_02074C70, func_02074CD0 and
 *        func_02074E10 are the four "load a resource of kind K and everything
 *        it depends on" entry points, and func_02074AE8 is the event-list
 *        walker that runs a table of {kind, arg} records through them.
 *        func_02074A6C / func_02074A98 / func_02074AC4 are their boolean
 *        wrappers.
 *     4. PLAYER BINDING (pkt_02075404).  func_0207533C pulls one bank entry,
 *        func_02075404 pulls every bank a sequence's group needs,
 *        func_020754C4 re-publishes all 0x20 slots, and func_02075698 /
 *        func_02075794 are the twin open/bind paths that allocate a voice
 *        (func_02073344), load its wave and bank and push the per-voice
 *        parameters.
 *
 * Derived from the 31 matched sources found with
 *   grep -l "address:  0x02074[A-F]\|address:  0x02075" src/matched/*.c
 * and from the notes docs/notes/pkt_02074A6C.c.txt, docs/notes/pkt_02074CD0.c.txt,
 * docs/notes/pkt_020750EC.c.txt, docs/notes/pkt_0207533C.c.txt,
 * docs/notes/func_02075794.c.txt and docs/notes/pkt_02075794.c.txt.
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
 * This cluster is MIXED, and the split is NOT by address -- it interleaves.
 * Nine of its functions are byte-exact only under `--cc ../2.0/sp2`:
 *
 *   func_02074A6C  func_02074A98  func_02074AC4  func_02074AE8
 *   func_02074E10  func_02074E9C  func_0207533C  func_02075404
 *   func_02075794
 *
 * while func_02074BEC, func_02074C70, func_02074F3C, func_02074FA8,
 * func_02075014, func_02075080, func_020751F4, func_0207524C, func_02075274,
 * func_020752A4, func_020752D4, func_020752F4, func_02075560, func_020755A8
 * and func_02075618 are all byte-exact under the project default dsi/1.1p1.
 * So neither front end is "the" cluster compiler: TRY THE SIBLING'S FIRST,
 * then try the other one before touching the C.
 *
 * The tell is always docs/FRONTEND-PINS.md's "kept constants": wherever a small
 * literal (nearly always 0, sometimes 1) is live at more than one point, 1.1p1
 * pools it into a callee-saved register and reuses it, which widens the
 * prologue's push list by a slot and shifts every later register; the image
 * rematerialises the literal at each use.  Symptom to recognise instantly: a
 * compile whose instructions and relocations are all correct but whose
 * `push`/`pop` lists are one register wider than the image's, or that is four
 * to eight bytes SHORT because the constant-sharing let the compiler
 * cross-jump two arms onto one call sequence.
 *
 * THE COST OF NOT KNOWING THIS, measured: FOUR of the five notes in
 * docs/notes/ for this range spent whole passes measuring respellings against
 * the wall -- docs/notes/func_02075794.c.txt lists seven rejected spellings of
 * a body that is byte-exact under the pin on the first compile, and
 * docs/notes/pkt_02074CD0.c.txt three of a body that needed one further change.
 * If a function in this range is size-exact but a push-list wide, or is short
 * by one call sequence, CHANGE THE COMPILER, NOT THE SOURCE.
 *
 * ISA: ARM throughout, like the 0x020737C0 cluster and unlike game code
 * generally.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02074A34_H
#define CLUSTER_02074A34_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The loader's one scratch header, 0x3c bytes read straight off the stream.
   func_020750EC reads 0x3c bytes into it and takes the entry count from +0x38.
   WAVE 12: func_020750EC is EXACT (../2.0/sp2).  0x0214EA54 resolves by
   sole-ref/data.  The image pools the word TWICE, and mwcc merges pool
   entries per symbol, so the source declares two extern names at this one
   address (d_0214EA54 for the read, d_0214EA54_hdr for the count load).  The
   old "own-pool-only literal" park no longer applies. */
struct ArcHdr { u32 pad00[0xe]; u32 count; };  /* count at +0x38 */
extern struct ArcHdr d_0214EA54;               /* 0x0214EA54 */

/* ================================================================== *
 * 1.  The archive-entry header word
 * ================================================================== */

/* THE SINGLE MOST IMPORTANT DECLARATION IN THIS CLUSTER, and the one that cost
   two earlier passes.  Every entry object begins with ONE 32-bit word that is
   read through TWO different views, and it must therefore be a UNION:

     - the low 24 bits are the entry's id, and they are a BITFIELD.  Only the
       bitfield read emits the image's `lsl r0,r0,#8` / `lsr r0,r0,#8` pair
       (func_02074E10 at 0x02074E44/0x02074E54, func_02074CD0 at
       0x02074DA8/0x02074DB4); spelling it `(w << 8) >> 8` folds to
       `bic r0, r0, #0xff000000` and loses four bytes.  This is
       docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md seen
       through a 24-bit field.
     - bit 24 is a flag, and it is read from the PLAIN WORD, `(w >> 24) & 1`:
       the image has `lsr r1,r0,#0x18` / `tst r1,#1` (func_02074E10 at
       0x02074E3C, func_02074CD0 at 0x02074D8C).  Taking it as a 1-bit member
       of the same bitfield view gives `lsl r1,r0,#7` / `lsrs r1,r1,#0x1f`
       instead.

   Two separate pointers do NOT work: the two views then stop sharing the
   single `ldr r0,[r0]` and the whole function goes out.  The union is what
   makes both spellings read one load.  Evidencing function: func_02074E10
   (src/matched/func_02074E10.c, EXACT); confirmed independently by
   func_02074CD0 (docs/notes/pkt_02074CD0.c.txt, 2 bytes out). */
union ArcEntry {
    u32 w;
    struct {
        unsigned id   : 24;   /* the resource id handed to the next layer */
        unsigned flag : 1;    /* selects func_020750EC over func_02075080  */
        unsigned rest : 7;
    } b;
};

/* ================================================================== *
 * 2.  The group record and the event table
 * ================================================================== */

/* func_02074CD0's object: a word followed by FOUR halfword slot ids, with
   0xffff as the empty marker.  `add r0, r5, r7, lsl #1` / `ldrh r0, [r0, #4]`
   at 0x02074D34 fixes the halfword stride and the +4 base; `ldr r1,[pc,#0xc8]`
   / `cmp r0, r1` against the pool word 0x02074E0C (0x0000ffff) fixes the
   sentinel, and the sentinel being POOLED rather than an immediate is itself
   part of the ../2.0/sp2 pin.  The loop bound is 4 and the counter must be
   `int`: the image's `blt` at 0x02074DF0 is signed, `u32` gives `blo`. */
struct Group { u32 f00; u16 slot[4]; };

/* func_02074AE8's event table: a count followed by 8-byte records.  The
   dispatch is a dense 4-way switch whose SOURCE ORDER is 0, 3, 1, 2, read off
   the branch table at 0x02074B34..0x02074B40, handlers BEC / C70 / CD0 / E10.
   See src/matched/func_02074AE8.c for the three further levers. */
struct EventRec   { u8 kind; u8 b1; u16 h2; u32 f4; };
struct EventTable { u32 count; struct EventRec entries[1]; };

/* ================================================================== *
 * 3.  The bank object and its offset table
 * ================================================================== */

/* func_0207533C's object.  `ldr r1,[r8,#0x38]` / `add r1,r1,r7` /
   `add r1,r8,r1,lsl #2` / `ldr r4,[r1,#0x3c]` / `ldrlo r0,[r1,#0x40]` at
   0x02075368..0x02075380 fixes all of it: a u32 offset array based at +0x3c,
   indexed by the object's own base index at +0x38 plus the caller's entry
   index.  Entry i spans [off[i], off[i+1]), except the last entry
   (i >= func_0208A638(o) - 1) whose end is the total at +0x08.  The
   `ldrlo`/`ldrhs` pair is an UNSIGNED compare, so index and count are u32. */
struct Bank {
    u32 pad00[2];
    u32 total;                 /* +0x08, end offset of the last entry */
    u32 pad0c[(0x38 - 0x0c) / 4];
    u32 base;                  /* +0x38, index of this object's first slot */
    u32 off[1];                /* +0x3c, the offset table                  */
};

/* ================================================================== *
 * 4.  The sequence iterator and its records (pkt_02075404)
 * ================================================================== */

/* func_02075404's two stack objects.  func_0208A46C opens an iterator into an
   8-byte cell; the working cursor is a copy of it; func_0208A48C steps the
   cursor and writes a record.  THE RECORD IS 12 BYTES, NOT 8 -- only its first
   four bytes are ever read here (`ldrb [sp,#0x10]`, `ldrh [sp,#0x12]`,
   `ldrheq [sp,#0x14]`), and the extra eight bytes are evidenced ONLY by the
   frame: an 8-byte Rec gives `push {r4..sl,lr}` / `sub sp,#0x18` where the
   image has `push {r3,r4..sl,lr}` / `sub sp,#0x1c`.  The +6..+11 split is
   therefore NOT constrained by any code in this cluster; `u16 h6; u32 w8;`,
   `u16 h6; u16 h8;` and a bare `u32 w8;` are all byte-exact.  A later caller
   of func_0208A48C can settle it. */
struct SeqIter { u32 a; u32 b; };
struct SeqRec  {
    u8  kind;   /* +0, 1 selects a bank record */
    u8  p1;
    u16 bank;   /* +2, the bank index handed to func_0207533C */
    u16 group;  /* +4, matched against the caller's group id  */
    u16 h6;     /* +6..+11 sized by the frame only, split unconstrained */
    u32 w8;
};

/* func_020754C4's slot descriptor, 8 bytes.  `ldrb r1,[r7]` / `ldrh r1,[r7,#2]`
   / `ldr r0,[r7,#4]` at 0x020754E8..0x02075500 fixes the three fields.  The
   count at +0 is SIGNED at the use: the image's `ble` at 0x020754D8 and `blt`
   at 0x02075548 both need the byte promoted to `int`, and the inner counter
   declared `int`, or the compares come out `bls`/`blo`. */
struct SlotDesc02074A34 { u8 n; u8 p1; u16 h2; u32 f4; };

/* ================================================================== *
 * 5.  Prototypes, with the exact parameter types the matched sources use
 * ================================================================== */

/* -- the archive below this cluster (all attested by matched sources here) -- */
extern u8   *func_02074324(u32 id);                     /* entry lookup, u8* */
extern void *func_02074388(u32 a, u32 b, u32 c);        /* 3-arg lookup      */
extern struct Group     *func_020743EC(u32 id);
extern union  ArcEntry  *func_02074450(u32 id);         /* ONE argument.     */
extern struct EventTable*func_02074518(u32 index);
extern u32   func_0207457C(u32 id);                     /* byte size of entry */
extern u32   func_020745A4(u32 id, void *dst, u32 len, u32 off);  /* bytes read */
extern u32   func_0207466C(u32 id);                     /* 0 = not resident   */
extern void  func_02074694(u32 id, void *p);            /* publish            */
extern void *func_0207482C(u32 *heap, u32 size, u32 cb, u32 cookie, u32 arg);
extern u32   func_020742FC(void);                       /* current heap       */

/* func_02074450's ARITY IS ONE, and this is not a detail: declaring it with
   four parameters costs sixteen bytes in func_02074CD0, because the compiler
   then emits `mov r1,sl` / `mov r2,sb` / `mov r3,fp` before the call where the
   image emits nothing at all (0x02074D48).  Attested outside this cluster by
   src/matched/func_02028C50.c, src/matched/unit_020064B8.c and
   src/matched/unit_020067E0.c, all EXACT. */

/* -- the four kind dispatchers.  The fifth argument is an OUT CELL, u32*, and
      is 0 at almost every call site; the return is an error code, 0 for
      success, and the wrappers invert it. -- */
extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);  /* 1.1p1   */
extern u32 func_02074C70(u32 a, u32 b, u32 c, u32 d, u32 *out);  /* 1.1p1   */
extern u32 func_02074CD0(u32 a, u32 flags, u32 c, u32 d, u32 *out); /* 2.0/sp2 */
extern u32 func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out);  /* 2.0/sp2 */

/* Error codes the dispatchers return, read straight off the `mov r0, #N`
   immediates: 2 (BEC lookup failed), 3 (C70 lookup failed), 4 (CD0 group
   lookup failed), 5 (entry lookup failed), 6 (BEC load failed), 7 (C70 load
   failed), 8 (CD0 bank load failed), 9 (wave load failed).  0 is success. */

/* -- the leaf loaders.  The four wrappers differ ONLY in the callback. -- */
extern void *func_02074E9C(u32 id, void (*teardown)(void), u32 cookie,
                           u32 arg, u32 heap);
extern u32   func_02074F3C(u32 a, u32 b, u32 c);
extern u32   func_02074FA8(u32 a, u32 b, u32 c);
extern u32   func_02075014(u32 a, u32 b, u32 c);
extern u32   func_02075080(u32 a, u32 b, u32 c);
extern u32   func_020750EC(u32 id, u32 *heap, int flag);  /* EXACT w12, 2.0 */

/* -- the teardown callbacks -- */
extern void func_020751F4(u32 p, u32 b, u32 c);   /* the shared body */
extern void func_0207524C(void);
extern void func_02075274(void);
extern void func_020752A4(void);
extern void func_020752D4(void);
extern void func_020752F4(void);

/* -- the player binding layer (pkt_02075404) -- */
extern u32  func_0207533C(struct Bank *o, u32 i, u32 h, u32 *heap);
extern u32  func_02075404(u32 o, u32 seq, u32 group, u32 h, u32 *heap);
extern u32  func_020754C4(u32 a);
extern u32  func_02075560(u32 a, u32 b);
extern u32  func_020755A8(u32 a, int b, int c, int d, u32 e);
extern u32  func_02075618(u32 a, u32 b, u32 c);
extern u32  func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1);
extern u32  func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u8 *s1,
                          u32 s2, u32 s3);

/* -- the SDK sound driver, ARM, all label-attested outside this cluster -- */
extern void func_0208A2BC(u32 bank, u32 slot, u32 waveArc);  /* THREE args:
   prologue saves r2 (SND_AssignWaveArc shape); proved by func_02074CD0
   EXACT, wave 12 */
extern void func_0208A38C(u8 *p);
extern void func_0208A424(int a);
extern void func_0208A46C(struct SeqIter *it, u32 seq, u32 group, u32 h);
extern u32  func_0208A48C(u32 seq, struct SeqRec *r, struct SeqIter *it);
extern u32  func_0208A638(struct Bank *o);      /* entry count */
extern void func_0208A640(struct Bank *o, u32 i, void *p);
extern u32  func_0208A674(struct Bank *o, u32 i);  /* nonzero = resident */
extern void func_020896AC(u8 *p, u8 *end);
extern void func_020896CC(u8 *p, u8 *end);
extern void func_020896EC(int p, int end);
extern void DC_StoreRange(void *addr, u32 size);   /* 0x020862D4 */

/* WAVE 12: func_02074CD0 is EXACT and needs no pin (1.1p1, sp2 and sp2p2 all
   reproduce it) once func_0208A2BC has its three-argument prototype.  The
   old 2-byte `ldrne r2` residue was the third argument being loaded. */

#endif /* CLUSTER_02074A34_H */
