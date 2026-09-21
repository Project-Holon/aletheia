/*
 * docs/families/game_data.h -- shared declarations for the game_data.c family
 * (the game-data / save-block master object), 0x020124F4..0x02013080 in the
 * ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * The family's own name is not a guess: the __FILE__ anchor these functions
 * pass to the allocator is 0x020A728C, and layout/file_anchors.txt line 40
 * spells it out --
 *     020126F8  020124F4  arm9_main  020A728C  game_data.c
 * That anchor is referenced from 0x020126F8, the literal pool of
 * func_020124F4, which is why the constructor is the family's lead function.
 *
 * Derived from the 36 matched functions found with
 *   grep -l "address:  0x02012[4-9A-F]\|address:  0x020130" src/matched/*.c
 * plus the two src/pending/ files.  Each declaration names the matched
 * function that evidences it.
 *
 * ADJUDICATION RULE.  A load or a store instruction constrains a field; a
 * name does not.  Where two matched files spell the same object differently,
 * the file whose code actually constrains it wins.  Several files in this
 * family are machine-shaped (`int f(int a0, int a1, int a2, int a3){...}`
 * with `t0`/`t1` temporaries); those constrain the OFFSETS and the CALL
 * ORDER but say nothing about parameter types, so they never win a type
 * argument against a hand-written sibling.
 *
 * ------------------------------------------------------------------------
 * THE ONE BIG IDEA: ONE 0x6B0-BYTE OBJECT, ONE u8 * , RAW BYTE OFFSETS
 * ------------------------------------------------------------------------
 * Every function in this family takes a pointer to the same object.  It is
 * 0x6B0 bytes (func_020124F4's allocation size), it holds the save handle in
 * its FIRST WORD, and everything else is reached by a raw byte displacement
 * from a `u8 *`.  Ten matched files spell it that way and all ten are EXACT;
 * nobody in this family has ever needed a struct declaration, and writing one
 * is a good way to lose the derived-constant chains described below.
 *
 * *(u32 *)p -- the save handle -- is the single most common expression in the
 * family: it is argument 0 of roughly forty calls across the file.  Read it
 * FRESH at every use.  Binding it to a local costs a callee-saved register
 * and is wrong everywhere it has been tried (see the levers section).
 */

#ifndef GAME_DATA_H
#define GAME_DATA_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;

/* ===================================================================== *
 * The object.  Offsets only -- there is no struct, by design.
 * ===================================================================== */
/*
 *  +0x000  u32   the save handle.  `*(u32 *)p`.  func_020124F4 fills it from
 *                func_020070A4(); func_02012FCC/func_02012F20 and every
 *                accessor in the family read it.
 *  +0x004  0x44 x 5   five 0x44-byte sub-records, each initialised by
 *                func_02012A60 in a `for (i = 0; i < 5; i++)` loop
 *                                                        -- func_020124F4
 *  +0x158  u32   func_0216237C(heap)                     -- func_020124F4
 *                (the destructor func_02012704 releases it via func_021623BC)
 *  +0x15C  u32   func_02008854(handle); the parent of the four below, and
 *                the value func_02012C18/func_02012CE0 keep live in a NAMED
 *                LOCAL across their two 0x0200893C / 0x02008954 calls
 *  +0x160  u32   func_02008844(*(u32 *)(p + 0x15C))      -- func_020124F4
 *  +0x164  u32   func_02008844(*(u32 *)(p + 0x15C))      (yes, called twice)
 *  +0x168  u32   func_02008848(*(u32 *)(p + 0x15C))
 *  +0x16C  u32   func_0200884C(*(u32 *)(p + 0x15C))
 *  +0x18C  u32   func_02008254(heap)                     -- func_020124F4
 *                (released by func_020307B0 in func_02012704)
 *  +0x190  u32   func_020071CC(handle, 0x19)             -- func_020124F4
 *  +0x194  u32   func_020071CC(handle, 0x1A)             -- func_020124F4
 *  +0x198  u32   func_0200873C(handle)                   -- func_020124F4
 *  +0x19C  u32   func_02007AA4(heap, handle)             -- func_020124F4
 *                (released by func_02007AC8 in func_02012704)
 *  +0x1A0  u32   func_020097C4(heap)                     -- func_020124F4
 *  +0x1A4  u32   func_02006E40(heap)                     -- func_020124F4
 *                (released by func_02006E64 in func_02012704)
 *  +0x1A8  u32   func_0216CC58(heap, 0x40, func_020071CC(handle, 0x33))
 *  +0x1AC  u32   func_02012FE4(handle)                   -- func_020124F4
 *  +0x1B0  u32   func_02159B48(heap)                     -- func_020124F4
 *  +0x1B4  u32   func_02028844(p, heap)                  -- func_020124F4
 *  +0x1B8  u32   func_02014428(heap); also the second argument of
 *                func_0200893C in func_02012C18/func_02012CE0
 *  +0x1C0  u32   zeroed by func_020124F4 (spelled `7 << 6`)
 *  +0x1C4  u8    func_0202E888()'s byte; also func_02008954's argument in
 *                func_02012CE0 (as a u8) and func_02012C18 (as a pointer)
 *  +0x1C5  u8    func_02008964 / func_0200895C's second argument
 *  +0x1C6  u8    zeroed by func_020124F4
 *  +0x1CE  u8    THE "BUSY" FLAG.  sub_02012E40 returns it, func_02012E4C
 *                sets it to 1, and func_02012E08 / func_02012DD0 /
 *                func_02012E7C all clear it to 0 on the way out.  Five
 *                independent byte-exact witnesses.
 *  +0x1D4  0x10 x 4    four 0x10-byte sub-records, each initialised by
 *                func_0200BDE4 in a `for (i = 0; i < 4; i++)` loop
 *                                                        -- func_020124F4
 *  +0x214  0x1E8 x 2   TWO 0x1E8-BYTE SLOTS.  The second most load-bearing
 *                fact in the family, and the one with the most witnesses:
 *                  - func_020124F4 initialises both in a `for (i = 0; i < 2;
 *                    i++)` loop over func_02161D98(p + 0x214 + i * 0x1E8);
 *                  - sub_020127D0 IS the indexer: `o + 0x214 + idx * 0x1E8`;
 *                  - func_0201281C clears slot 0 (0x1E8 bytes at +0x214) and
 *                    then calls func_02161D64 on +0x3FC, which is 0x214 +
 *                    0x1E8, i.e. slot 1 -- the stride confirmed by arithmetic
 *                    in a second, independent function;
 *                  - func_02012800 copies slot 0 out with a 0x1E8-byte
 *                    func_02082D44 and re-inits it.
 *                func_020127B8 selects index 3 and func_020127C4 index 1
 *                through the indexers, so the "two slots" above is the
 *                initialised prefix of a longer run, not the whole array.
 *  +0x5E4  u32   func_0215E31C(heap)                     -- func_020124F4
 *                (released by func_0215E334 in func_02012704)
 *  +0x5E8  ...   initialised in place by func_0202E43C(p + 0x5E8)
 *  +0x5EC  ...   passed as a POINTER to func_0200B3C8 (func_02012C18) and
 *                func_0200B3B0 (func_02012CE0); mwcc pools 0x5EC as a literal
 *                word, it is not a Thumb immediate
 *  +0x680  u32   zeroed by func_020124F4
 *  +0x684  u32   func_0202E770(heap); func_02012F20 returns it
 *                (released by func_0202E794 in func_02012704)
 *  +0x688  u32   zeroed by func_020124F4
 *  +0x68C  u32   func_0202751C(heap, 0x8001)             -- func_020124F4
 *                (released by func_02027584 in func_02012704)
 *  +0x690  u32   func_021647A0(p, heap)                  -- func_020124F4
 *                (released by func_021647D8 in func_02012704)
 *  +0x694  ...   passed as a POINTER to func_0200E884 (func_02012CE0) and
 *                func_0200E89C (func_02012C18)
 *  +0x6A4  u32   zeroed by func_020124F4
 *  +0x6A8  u32   zeroed by func_020124F4
 *  +0x6AC  u32   func_0200857C(heap).  func_02012FCC returns it, func_02012FBC
 *                passes it to func_020085D4, and it is the FIRST thing
 *                func_02012704 releases.  The constructor and the destructor
 *                both pool 0x6AC as a literal and derive 0x690/0x68C/0x684/
 *                0x5E4 from it with `subs`, which is why a u8 * with plain
 *                byte offsets reproduces the original and a `u32 *` with
 *                indices does not.
 *  size    0x6B0 -- func_020124F4's allocation request.
 */

/* ===================================================================== *
 * Externs used across the family
 * ===================================================================== */

/* heap alloc: (heap, size, flag, __FILE__, __LINE__).  NOTE the heap
 * parameter is passed NARROW; see the levers section.  -- func_020124F4,
 * func_02013090, and src/matched/func_020082EC.c outside the family */
extern void *func_02030734(int heap, int size, int flag, void *file, int line);
extern void  func_020307B0(u32 p);                  /* the base deleter, arm */

/* the family's own __FILE__ anchor, "game_data.c" */
extern char  g_020A728C[];                          /* 0x020A728C, data */

/* memset / memcpy alikes -- func_0201281C, func_02012800, func_020130C4 */
extern void  func_02082BCC(void *dst, int c, u32 n);
extern void  func_02082D44(void *dst, const void *src, u32 n);
extern void *memcpy(void *dst, const void *src, u32 n);  /* 0x02082D44, arm */

/* save-block getter: (handle, block id).  Called with 0x19, 0x1A, 0x26,
 * 0x29, 0x2D and 0x33 in this family alone -- func_020124F4, func_02012C18,
 * func_02012F2C, func_02012FE4 */
extern u32   func_020071CC(u32 handle, u32 id);

/* the save handle's own constructor / state machine -- func_020124F4,
 * func_02012C18, func_02012DD0, func_02012E08, func_02012E7C */
extern u32   func_020070A4(void);
extern u32   func_020071E4(u32 handle);   /* returns 1 when already running */
extern int   func_02007168(u32 handle);
extern int   func_020073B0(u32 handle, int b);
extern void  func_020071A8(u32 handle);
extern void  func_02007374(u32 handle, void *a);

/* the "am I in a cutscene" guard, the first statement of three functions
 * -- func_02012DD0, func_02012E7C */
extern int   func_02005C64(void);

/* the UI mode pair that always travels together -- func_02012DD0,
 * func_02012E08, func_02012E7C */
extern void  func_020351A0(int mode);     /* always called with 2 */
extern void  func_02010444(void);
extern void  func_02034F84(u32 bit);      /* always 0x80 */
extern void  func_02034FB8(u32 bit);      /* always 0x80 */
extern int   func_02034FE8(u32 bit);

/* the event-descriptor allocator pair -- func_02012444, func_020124AC */
struct Desc;
extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern u32  *sub_020124E8(struct Desc *d);
extern void *func_02012374(void *evt, void **out);

/* ===================================================================== *
 * Prototypes, in address order
 * ===================================================================== */

/* -- the constructor / destructor pair, the two biggest functions -------- */
void *func_020124F4(u16 heap);            /* 0x020124F4, 528 bytes, MATCH   */
void  func_02012704(u8 *p);               /* 0x02012704, 160 bytes, MATCH   */

/* -- the event-descriptor drivers --------------------------------------- */
int   func_0201240C(void *o, u32 *state, u32 *item);
void *func_02012444(void *obj, u32 a1, u32 a2, u32 a3);
int   func_02012474(void *a0, u32 *state, u32 *item);
struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);

/* -- the 0x1E8 slot indexers -------------------------------------------- */
u8   *sub_020127D0(u8 *o, u32 idx);       /* o + 0x214 + idx * 0x1E8        */
void  func_020127B8(void *p);             /* -> func_020127AC(p, 3)         */
void  func_020127C4(void *p);             /* -> sub_020127D0(p, 1)          */
void  func_0201281C(u8 *o);               /* clear slot 0, re-init slot 1   */
void  func_02012800(u8 *o, void *dst);    /* copy slot 0 out, re-init it    */

/* -- the two big "wire everything up" siblings -------------------------- */
void  func_02012C18(u8 *p);               /* 0x02012C18, 204 bytes, EXACT   */
void  func_02012CE0(u8 *p);               /* 0x02012CE0, 204 bytes, EXACT   */

/* -- the +0x1CE busy-flag group ----------------------------------------- */
u8    sub_02012E40(const u8 *o);          /* -> o[0x1CE]                    */
void  func_02012E4C(u8 *p, void *a);      /* sets o[0x1CE] = 1              */
void  func_02012E08(char *p);             /* clears it, guarded by == 1     */
int   func_02012DD0(u8 *p);               /* clears it when r is 2 or 3     */
int   func_02012E7C(char *p, int a1);     /* same, plus func_02034FB8(0x80) */

/* -- the plain field accessors ------------------------------------------ */
u32   func_02012F20(u8 *p);               /* -> *(u32 *)(p + 0x684)         */
u32   func_02012FCC(u8 *p);               /* -> *(u32 *)(p + 0x6AC)         */
u32   func_02012FBC(u8 *p, u32 x);        /* func_020085D4(p[0x6AC], x)     */
void  func_02012F08(int *p);              /* func_0200C0F0(*p)              */
void  func_02012F2C(int *p);              /* func_020071CC(*p, 0x26)        */
void  func_02012FE4(int handle);          /* func_020071CC(handle, 0x2D)    */

/* -- the neighbouring 0xF0-byte object at 0x02013090 -------------------- */
void *func_02013090(u32 heap);            /* 0xF0 bytes, sZonedataFile, 0x31 */
void  func_020130C4(u8 *p);               /* clear 0xF0, then +8            */

/* ===================================================================== *
 * The levers that cost time in this family (do not re-derive)
 * ===================================================================== */
/*
 * 1. THE HEAP PARAMETER IS NARROW.  func_020124F4 takes `u16 heap`, not
 *    `int`.  The tell is the FIRST instruction after the frame setup: the
 *    original spills r0 to [sp, #4] BEFORE it materialises the other four
 *    arguments of func_02030734, and an `int` parameter spills it LAST.  A
 *    narrow parameter has a home store pinned to the front of the prologue
 *    (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-
 *    prologue.md).  Nothing in the BODY moves it: an `int heap = a0;` local
 *    first, last, a named `size` for 0x6B0, and 300 single mutations of
 *    tools/permuter.py in --mode hill all leave the same seven instructions
 *    in the wrong order.  --mode anneal found it in 286 compiles as
 *    `type:p(a0:int->u16)`.  src/matched/func_020082EC.c corroborates it
 *    independently, passing `(unsigned short)a0` to the same allocator.
 *    EXPECT THIS FOR EVERY CONSTRUCTOR IN THE FAMILY.
 *
 * 2. A CALL USED AS AN ARGUMENT IS SCHEDULED PER SITE; A LOCAL IS NOT.
 *    func_020124F4's memcpy is three calls in its argument list, and the
 *    original evaluates them in the order func_02008468, func_02012944,
 *    func_02008730.  Written as one nested expression mwcc picks
 *    func_02008730 first and the whole tail of the function reallocates --
 *    169 of 176 concrete bytes wrong from that alone.  Bind the first two to
 *    named locals in the original's order:
 *        n   = func_02008468();
 *        src = func_02012944(p);
 *        memcpy(func_02008730(*(u32 *)p), src, n);
 *    (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-
 *    not.md)
 *
 * 3. ARGUMENT ORDER IS NOT SHARED BETWEEN THE TWO SIBLINGS.  func_02012C18
 *    and func_02012CE0 are the same function twice, statement for statement,
 *    and they DISAGREE at 0x020097F0:
 *        func_02012CE0:  func_020097F0(v, func_02009D08(*(u32 *)p));
 *        func_02012C18:  func_020097F0(func_02009D08(*(u32 *)p), v);
 *    Copying the sibling's order into func_02012C18 costs one extra
 *    `adds r0, r7, #0`, shifts everything after it by two bytes, forces a
 *    trailing `c046` pool-alignment nop and rotates three callee-saved
 *    registers -- a residue that reads exactly like an allocation tie and is
 *    not one.  docs/notes/pkt_02012C18.c.txt recorded it as an unmovable
 *    register rotation for a whole lane on that basis.  THE TELL: a genuine
 *    allocation tie never changes the INSTRUCTION COUNT.  If the rotation
 *    comes with an inserted instruction or a two-byte shift, a value reached
 *    a call in the wrong argument slot and that is a source fact.
 *
 * 4. RE-READ *(u32 *)p AT EVERY USE.  Never bind the save handle to a local.
 *    (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-
 *    register.md.)  The ONE exception in the family is the 0x15C value in
 *    func_02012C18 / func_02012CE0, which IS a named local because its two
 *    uses are back to back across two calls; its third use, after two more
 *    calls, re-reads the field -- which is what the original does too.
 *
 * 5. THE OFFSETS ARE BYTE OFFSETS ON A u8 *.  0x1C4 is `0x71 << 2`, 0x158 is
 *    `0x56 << 2` and 0x6AC is a pool word; mwcc derives every neighbouring
 *    offset from those three bases with `adds`/`subs`, which is what a u8 *
 *    with plain displacements produces and a `u32 *` with array indices does
 *    not.  Both the constructor and the destructor depend on this.
 */

/* ===================================================================== *
 * Known permanent walls in this family (do not re-derive)
 * ===================================================================== */
/*
 * THE OVERLAY WALL.  This family calls into ov010 a dozen times, and ov009
 * and ov010 BOTH hold every one of those addresses.  For each of them the
 * only branch anywhere in the image is the `bl` inside the function that
 * needs it, so:
 *   - `label` refuses: no witness outside the compared range (condition 3 of
 *     attest_overlay_label()).  The `ov010` region hint on the symbols: line
 *     narrows the candidates but does NOT supply the missing outside branch,
 *     so it does not help;
 *   - `sole-ref/code` cannot reach them either: it reads evidence().labels,
 *     which indexes the ARM9 listings only, so an overlay-resident function
 *     start is simply not in its map;
 *   - `tu --suggest-split` confirms no cut helps -- the witnesses are the
 *     calls themselves.
 * Both of the family's two byte-correct-but-capped files are stuck on
 * exactly this and nothing else:
 *
 * func_020124F4 (src/pending, MATCH, all 528 bytes right, 35 of 39
 *   relocations resolved): 0x0216237C, 0x0216CC58, 0x0215E31C, 0x021647A0.
 * func_02012704 (src/pending, MATCH, all 148 compiled bytes right, 10 of 15
 *   resolved): 0x021647D8, 0x0215E334, 0x0216CCB0, 0x02159BBC, 0x021623BC.
 *
 * Both close the day disasm.py labels those addresses in ov010 with a branch
 * outside, or the day an ov010 packet is matched and the `matched` class can
 * carry them.  Nothing in the C is in question for either file.
 *
 * Note also that func_02012704's listing extent is 160 bytes while the
 * compile is 148: the trailing 12 bytes are its literal pool.
 */

#endif /* GAME_DATA_H */
