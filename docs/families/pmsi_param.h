/*
 * docs/families/pmsi_param.h -- shared declarations for the pmsi_param.c
 * family, 0x02024044..0x02024768+ in the ARM9 image.
 *
 * The file identity is settled, not guessed: layout/file_anchors.txt line 83
 * pins the ABS32 pool word at 0x020240F4, inside func_02024044, to the
 * __FILE__ string at 0x020A745C, which reads "pmsi_param.c".  That anchor is
 * loaded at line 0x56 for the 0x20-byte owner object.
 *
 * This is the easy-chat (Pokemon Musical Sentence) PARAMETER side: the small
 * object that remembers which archived word list the player is browsing and
 * which words are currently selected, plus the validators that keep a saved
 * selection legal across a game version.  The DRAWING side is pms_draw.c
 * (docs/families/pms_draw.h, 0x0202DB0C..0x0202E43C) and the INPUT side lives
 * in overlay_110; neither is part of this range.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every declaration below is
 * derived from a file in src/matched that is EXACT or EXACT*, and the matched
 * function that evidences each field or parameter is named beside it.  Where
 * two matched sources spell the same object differently (they were written by
 * different lanes), the spelling recorded here is the one the byte evidence
 * actually constrains.
 *
 * ADJUDICATION RULE, as in the other family headers: a load or a store
 * instruction constrains a field; a name does not.  An equal-width lsls/lsrs
 * pair proves a bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); an unequal
 * pair is a narrowing cast folded with a shift.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.  The one
 * item that is plainly content rather than code is the 0xFFFF "empty word"
 * sentinel and the 0x6A1 "invalid word" replacement id: both are word-list
 * ids and are the kind of constant that could differ between versions.
 */

#ifndef PMSI_PARAM_H
#define PMSI_PARAM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE ONE BIG IDEA: an 8-byte SLOT of four halfwords.
 *
 * Every initialiser, comparator and copier in the family works on the same
 * four-halfword record: an id, a flag, and two trailing "word" halfwords
 * seeded with a shared 0xFFFF sentinel.  func_020242A4 (the shared
 * initialiser), sub_0202428C (its id-less sibling), func_02024534 (the
 * comparator) and sub_02024570 (the copier) are four independent byte-exact
 * witnesses to the SAME layout, and the two-iteration seeding loop appears
 * in all of them with a SIGNED counter -- the original compares `blt`, and an
 * unsigned counter gives `blo`.
 * ------------------------------------------------------------------ */
struct PmsiSlot {
    u16 id;       /* +0x00  func_020242A4 stores its `id` argument here
                   *        with `strh`; sub_0202428C writes 0xFFFF instead,
                   *        which is what makes the sibling id-less. */
    u16 flag;     /* +0x02  func_020242A4 zeroes it; unit_020242D8's four
                   *        arms then overwrite it with 0, 0, 0 and 0xd. */
    u16 word[2];  /* +0x04, +0x06  the two selected word ids, seeded to
                   *        0xFFFF.  func_020244F0 returns word[idx] raw;
                   *        func_020244D4 returns it masked to 11 bits
                   *        unless it is the sentinel. */
};

/* ------------------------------------------------------------------ *
 * The owner, 0x20 bytes.  Evidenced by func_02024044, which passes the
 * literal 0x20 to func_02030734 and then writes every field below.
 * ------------------------------------------------------------------ */
struct PmsiParam {
    u8   kind;      /* +0x00  func_02024044 stores its FIRST argument with
                     *        `strb`, and later compares it against 2 to pick
                     *        the initialisation path.  Only kind 2 gets a
                     *        slot at +0x10; every other kind gets the
                     *        halfword pair at +0x18 seeded to 0xFFFF. */
    u8   f01;       /* +0x01  func_02024044 sets it to 1 unconditionally. */
    u8   f02;       /* +0x02  func_02024044 clears it. */

    /* +0x03: the flag BYTE.  It must be spelled as BITFIELDS and not as
     * `&= ~1` / `|= 2` masks: func_02024044's sequence is
     * `bics #1; orrs; strb` then `bics #2; strb` then `bics #8; orrs; strb`
     * -- three separate read-modify-write pairs that only per-bit bitfield
     * assignments produce.  A folded mask collapses them. */
    u8   b0 : 1;    /* func_02024044 assigns (u8)func_020142E8(...) & 1 */
    u8   b1 : 1;    /* func_02024044 clears it */
    u8   b2 : 1;    /* func_02024044 sets it on the memcpy path only */
    u8   b3 : 1;    /* func_02024044 assigns (u8)flag; the original's
                     * `lsls #0x18 / lsrs #0x18` is the (u8) cast and the
                     * following `lsls #0x1f / lsrs #0x1c` is this 1-bit
                     * field sitting at bit 3. */
    u8   rest : 4;

    u8   pad04[4];
    void *f08;      /* +0x08  func_020071CC(sys, 0x37)'s answer */
    void *f0c;      /* +0x0c  func_02024988(sys)'s answer */
    struct PmsiSlot slot;
                    /* +0x10  the 8-byte slot.  func_02024044 passes
                     *        `o + 0x10` to func_020242A4 on the empty path
                     *        and as MI_CpuCopy8's DEST on the copy path. */
    u16  f18[2];    /* +0x18  seeded to 0xFFFF by func_02024044's two-
                     *        iteration loop on the non-kind-2 path */
    u8   pad1c[4];
};

/* ------------------------------------------------------------------ *
 * The word-list cursor, used by the validators.  Four halfwords, and the
 * first two are an archive coordinate: func_02024498 turns (f00, f02) into
 * a word count by opening arc 2, file Table_0209F724[f00], entry f02.
 * ------------------------------------------------------------------ */
struct PmsiCursor {
    u16 cat;      /* +0x00  the category, always compared against 7
                   *        (func_0202465C, func_020245D4) */
    u16 page;     /* +0x02  the page within the category, compared against
                   *        func_02024584(cat) */
    u16 word[2];  /* +0x04, +0x06  the selected word ids */
};

/* ===================================================================== *
 * Externs used across the family
 * ===================================================================== */

/* heap alloc: (heap, size, kind, __FILE__, __LINE__).  The heap argument is
 * a u32 parameter narrowed by an EXPLICIT (u16) cast at the call -- a u16
 * parameter gives `ldrh` where func_02024044 loads a word and narrows with
 * lsls/lsrs #0x10. */
extern void *func_02030734(u32 heap, u32 size, u32 kind, void *file, u32 line);

/* save-block getter -- func_02024044 passes block id 0x37 */
extern void *func_020071CC(void *sys, u32 id);
extern void *func_02024988(void *sys);
extern u32   func_02012FE4(void *sys);
/* returns u32; func_02024044 narrows the answer with an explicit (u8) cast
 * before the bitfield store.  Declaring the return u8 folds the
 * `lsls #0x18 / lsrs #0x18` pair away and costs four bytes. */
extern u32   func_020142E8(u32 a, u32 b);

/* 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, NOT
 * memcpy's (dest, src, size): func_02024044 loads r0 from its `src`
 * argument and r1 from `o + 0x10`.  Spelling it memcpy swaps r0/r1. */
extern void  MI_CpuCopy8(const void *src, void *dest, u32 n);

/* the archive file-id table, 12 halfwords at 0x0209F724, indexed by cat.
 * Named by sub_02024368, func_0202441C and func_02024498. */
extern const u16 Table_0209F724[];
/* the per-category page-count table, 7 bytes at 0x0209F71C -- func_02024584 */
extern const u8  Table_0209F71C[];
/* the 12-halfword legal-word table at 0x0209F734 -- func_02024768 */
extern const u16 Table_0209F734[];

/* the ARM9 __FILE__ anchor for this file */
extern u8    file_020A745C[];   /* "pmsi_param.c" */

/* ===================================================================== *
 * Prototypes.  Parameter types are the ones the byte evidence forces; the
 * evidencing source file is named for each.
 * ===================================================================== */

/* THE CONSTRUCTOR.  Six parameters: four in registers and two on the stack
 * (`sys` at sp+0x18, `hh` at sp+0x1c behind the six-register push).  `hh` is
 * a u32 narrowed by an explicit (u16) cast at the allocator call, and `flag`
 * is a u32 narrowed by an explicit (u8) cast into bitfield b3.
 * src/matched/func_02024044.c  (EXACT*) */
struct PmsiParam *func_02024044(u32 kind, u32 a1, void *src, u32 flag,
                                void *sys, u32 hh);

/* Eight-byte tail-call thunks (pool word + bx).  The follower run at
 * 0x020240F4 onward is a dense sequence of UNLABELLED leaf accessors that
 * save no lr, so disasm.py never labels them
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); that run is
 * what makes func_02024044 verify EXACT* rather than EXACT.
 * src/matched/func_020240FC.c, src/matched/func_0202421C.c */
void func_020240FC(void);   /* -> 0x020307B0, arm */
void func_0202421C(void);   /* -> 0x020355C4, arm */

/* Compares the caller's halfword pair against the object's, dispatching on
 * the object's kind byte; kind 2 falls through to the four-halfword
 * comparator at +0x10.  src/matched/func_0202419C.c */
u32  func_0202419C(void *p, u16 *q, u32 a);

/* Rebuilds the object's halfword window from two caller arrays.
 * src/matched/func_020241E0.c  (EXACT*) */
void func_020241E0(void *p, u16 *a1, u16 *a2);

/* Waveform sampler, NOT part of the parameter object: fills out[0..count)
 * with a scaled sample of the shared s16 table at 0x02021B38.  DIFF, one
 * byte, and evidence-capped besides; see docs/notes/func_02024230.c.txt. */
void func_02024230(s16 *out, u32 count, u16 step, s32 amp);

/* THE SHARED SLOT INITIALISER.  Store the id, zero the flag, then a
 * two-iteration SIGNED loop seeds both trailing halfwords with 0xFFFF.
 * src/matched/sub_020242A4.c */
void func_020242A4(void *obj, u32 id);

/* The same, with the id set to the sentinel too, so there is no second
 * parameter.  src/matched/sub_0202428C.c */
void sub_0202428C(void *obj);

/* A 0..3 dense jump table over four presets, each of which calls
 * func_020242A4 with a small id and then overwrites flag and word[0] with
 * plain 16-bit constants (0x5D2, 0x5CD, 0x667, 0x573).  An index over 3
 * lands on the shared epilogue with neither a call nor a store, which only a
 * `default: break;` with nothing in it produces.  Case 3 passes the same id
 * as case 1 but a different flag, so the arms cannot be collapsed by id.
 * src/matched/unit_020242D8.c  (a tu range covering both functions) */
void func_020242D8(void *slot, u32 idx);
void func_02024344(void *obj);   /* preset 0 inlined outside the switch */

/* Two callers of func_020242A4/func_02024598 in sequence.
 * src/matched/func_020242C0.c */
void func_020242C0(void *a, void *b, void *c);

/* Archived graphics-slot loader.  A slot word of 0xFFFF means "empty";
 * otherwise bit 11 says whether the value carries a 0x7FF payload.
 * src/matched/sub_02024368.c */
void *sub_02024368(u16 *slots, u32 heap, int count);

/* Opens arc 2 / Table_0209F724[arcFileIdx] and returns entry strIdx.
 * src/matched/sub_0202441C.c  (EXACT*) */
void *func_0202441C(const void *obj, u32 heapId);

/* Are all `n` words of the cursor non-sentinel.  src/matched/func_02024464.c */
int  func_02024464(struct PmsiCursor *p, u32 a1);

/* HOW MANY WORDS does (cat, page) carry.  The workhorse of the family: four
 * ARM entry points in a fixed order, arc 2, file Table_0209F724[cat], entry
 * page.  src/matched/func_02024498.c */
u32  func_02024498(u32 cat, u32 page, u32 heap);

/* Accessors over the trailing halfword array at +4.
 * src/matched/sub_020244D4.c (EXACT*), sub_020244F0.c, sub_020244F8.c */
u16  func_020244D4(void *obj, u32 idx);   /* masked to 11 bits, sentinel passes through */
u16  func_020244F0(void *obj, u32 idx);   /* raw */
u32  func_020244F8(void *p, u32 idx);     /* -> sub_02024508 of the raw word */

/* Sentinel-guarded bit test: 0xFFFF reads as 0, everything else as bit 11.
 * The `(s32)x >> 11` is an ARITHMETIC shift.  src/matched/sub_02024508.c */
u32  sub_02024508(u32 x);

/* The 11-bit payload mask.  src/matched/sub_02024520.c */
u32  sub_02024520(u32 x);

/* Four-halfword comparator: two scalar compares then a two-iteration loop.
 * src/matched/unit_02024534.c */
int  func_02024534(const struct PmsiSlot *p1, const struct PmsiSlot *p2);

/* Plain 8-byte slot copy, spelled as a struct assignment.
 * src/matched/sub_02024570.c */
void sub_02024570(struct PmsiSlot *dst, const struct PmsiSlot *src);

/* Page count for a category; 7 categories, 0 past the end.
 * src/matched/func_02024584.c */
u8   func_02024584(u32 cat);

/* Writes two halfwords through a word pointer; the third and fourth
 * parameters exist in the signature but the second is the only one stored
 * past the first (docs/idioms/a-forwarding-call-passes-one-argument-and-the-
 * rest-are-leftovers.md).  src/matched/func_02024598.c */
void func_02024598(int p0, int p1, int p2, int p3);

/* Resets the cursor's trailing words to the sentinel from index `n` on.
 * src/matched/func_020245AC.c */
void func_020245AC(struct PmsiCursor *p, u32 a1);

/* THE VALIDATOR, inlined form.  Guards (cat, page), asks func_02024498 for
 * the word count, and runs each word through the same two-arm check
 * func_020246C8 performs on one word.  src/matched/func_020245D4.c */
u32  func_020245D4(struct PmsiCursor *p, u32 a1);

/* THE VALIDATOR, delegating form: the same guard chain, but the per-word
 * check is a call to func_020246C8 rather than an inlined copy, and the
 * cursor is repaired to (0, 0) rather than rejected outright.
 * src/matched/func_0202465C.c */
u32  func_0202465C(struct PmsiCursor *p, u32 a1, u32 a2);

/* THE PER-WORD CHECK.  Sentinel handling on `mode`, then the two-arm test:
 * a payload word is range-checked 1..10 through sub_02024520, and a plain
 * word must be either in Table_0209F734 or resolvable by func_020248D8.
 * A failing word is replaced with 0x6A1.  DIFF, ONE byte; see the appended
 * section of docs/notes/func_020246C8.diff.c.txt. */
u32  func_020246C8(u16 *p, u32 mode, u32 flag);

/* Clamp a counter to 1..10, with a mode argument that changes only the zero
 * case.  wordset.c's normaliser, called from src/pending/sub_0201EFFC.c.
 * src/matched/sub_0202473C.c */
u32  func_0202473C(u32 *p, u32 a);

/* Is `v` one of the 12 halfwords of Table_0209F734.  The table is COPIED TO
 * A LOCAL before the scan (`b = data_0209F734;`), which is what the ldm/stm
 * run in the prologue says; scanning the extern in place loses the copy.
 * src/matched/func_02024768.c */
s32  func_02024768(u32 v);

/* Releases 13 handles hanging off the object, then the object.
 * src/matched/func_020247F0.c */
void func_020247F0(char *p);

/* Called by both validators; resolves a plain word id into two out-
 * parameters and answers non-zero on success.  Outside this range. */
extern u32 func_020248D8(u32 v, u32 *a1, u32 *a2);

/* ===================================================================== *
 * The two levers that cost this family the most time
 * ===================================================================== */
/* 1. TWO ARMS WRITE THE FAIL TAIL OUT, AND THE LABEL SITS INSIDE THE FIRST
 *    ARM'S COPY.  Both validators end in a two-arm word check whose failing
 *    paths each spend their own `ok = 0; goto ret;`.  Sharing one copy behind
 *    a single label lets mwccarm cross-jump the arms into one inverted `beq`,
 *    which costs four bytes and shifts every later branch target, so the diff
 *    then reads as a general reshuffle rather than a shape error.  This is
 *    what closed func_020245D4 (DIFF 132/136 for a whole wave -> EXACT).  See
 *    docs/idioms/two-arms-write-the-tail-out-and-the-third-branches-back-
 *    into-one.md.
 * 2. THE `!= 0` ARM IS WRITTEN FIRST.  With the `== 0` arm first the two call
 *    sites swap and 17 bytes differ (docs/idioms/the-fall-through-arm-is-the-
 *    source-order.md).
 */

/* ===================================================================== *
 * Known walls in this family (do not re-derive)
 * ===================================================================== */
/* func_020246C8 (0x020246C8): DIFF at exactly ONE byte, and unmoved by
 *   tools/permuter.py over 220 single mutations (hill) and 3000 compiles
 *   (anneal), plus about twenty hand-written control-flow shapes.  The
 *   original's `blt` at +0x3E targets the `b` at +0x44 instead of that `b`'s
 *   own target; every spelling that reaches the same instructions points the
 *   `blt` straight at the final target.  Both `b` instructions are emitted
 *   correctly -- it is the conditional branch's TARGET that differs, not the
 *   code.  See the appended section of docs/notes/func_020246C8.diff.c.txt.
 * func_02024230 (0x02024230): DIFF at exactly ONE byte after the permuter's
 *   `temp` mutation closed 7 of the 8 (see the appended section of
 *   docs/notes/func_02024230.c.txt).  It is ALSO evidence-capped: the ABS32
 *   pool word naming the s16 table at 0x02021B38 has no witness outside the
 *   function's own 92-byte range, so even a byte-exact version caps at MATCH
 *   until something else in the image loads that address.
 * func_02024768 is EXACT in src/matched, which unstuck func_020246C8's own
 *   call site: that relocation now resolves `sole-ref`.  The older prose in
 *   docs/notes/func_020246C8.diff.c.txt describing it as a MATCH-capped
 *   pending file is stale.
 */

#endif /* PMSI_PARAM_H */
