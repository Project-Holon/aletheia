/*
 * docs/families/bg_sys.h -- shared declarations for the bg_sys.c family
 * (background / tilemap system), 0x0203F8F4..0x02043668 in the ARM9 image.
 * Edges are fuzzy by a function or two at both ends.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  It is the adjudicated
 * union of the declarations that the family's byte-exact sources already
 * carry, written down once so a new attempt on an open function starts from
 * the settled shape instead of re-deriving it.
 *
 * Derived from the 66 matched sources found with
 *   grep -l "address:  0x0203F[89A-F]\|address:  0x0204[0-2]\|address:  0x02043[0-6]" \
 *        src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load instruction constrains a field
 * and a name does not.  `ldrb [r,#N]` fixes a byte at exactly +N; `ldrsh`
 * proves s16 (there is no immediate-offset ldrsh, see
 * docs/idioms/ldrsh-register-offset-is-signedness.md); a shift pair proves a
 * bitfield's width.  A file that only passes a pointer through constrains
 * nothing, so its `void *` spelling never outranks a file that dereferences.
 */

#ifndef BG_SYS_H
#define BG_SYS_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct BgSys;
struct BgSlot;

/* ------------------------------------------------------------------ *
 * THE SINGLETON at 0x02146A44, total size 0x1d0.
 *
 * The size is not inferred: func_0203F8F4 allocates exactly 0x1d0 bytes
 * and func_02082BCC-clears the same 0x1d0.  The internal layout is then
 * forced by arithmetic that closes exactly:
 *
 *     8 slots * 0x2c  = 0x160     (the per-layer records)
 *     0x160 + 8       = 0x168     (pad, two words)
 *     +0x168, +0x16c              (the two 0x1000-byte arenas)
 *     0x170 + 8*4     = 0x190
 *     0x190 + 8*4     = 0x1b0
 *     0x1b0 + 8*4     = 0x1d0     == the allocation size
 *
 * THIS RECONCILES THE TWO SPELLINGS IN THE MATCHED SET.  Five files spell
 * the head flat (`u16 heapId; u8 pad_02[2]; u16 unk_04; u16 unk_06;
 * u8 pad_08[0x160]`), two (func_02040C14, unit_02041F28) spell it as
 * `struct Slot slots[8]`.  They are the same object: the flat `pad_08`
 * run and the slot array cover the identical 0x160 bytes.  The slot-array
 * spelling is preferred below because the 0x2c stride is proved by
 * `mov ip, #0x2c` + `mla` in func_02040B1C, func_02040AF0, func_02040C14
 * and sub_020409E0, while the flat spelling merely pads over it.
 *
 * CAUTION: the first slot overlaps the system header words.  slots[0]'s
 * first halfword IS the system heapId -- func_02040C14 reads it as
 * `g_02146A44->slots[0].heapId`, func_0203F8F4 writes it as the system's
 * own `heapId`, and func_02041B6C reaches +0x06 directly off the base
 * (`ldrh r1, [r3, #6]`).  Both views are correct; neither is a typo.
 * ------------------------------------------------------------------ */
struct BgSys {
    struct BgSlot slots[8];     /* +0x000  stride 0x2c, func_02040B1C   */
    u8    pad_160[8];           /* +0x160                               */
    void *arena_a;              /* +0x168  func_02033C00(0x1000) --
                                 *         func_0203F8F4; layers 0-3.
                                 *         func_0203FAF0/func_0203FB44
                                 *         pick it for layer < 4        */
    void *arena_b;              /* +0x16c  layers 4-7, same evidence    */
    u32   tile_base[8];         /* +0x170  func_0203FAF0 divides it by
                                 *         the layer stride;
                                 *         func_02040C14 biases by it   */
    u32   unk_190[8];           /* +0x190  zeroed by func_0203F8F4;
                                 *         no matched reader constrains
                                 *         the width beyond u32         */
    u32   unk_1b0[8];           /* +0x1b0  func_020411E8 passes
                                 *         unk_1b0[i] as a byte size to
                                 *         func_02040B94               */
};

/*
 * The system header, as the flat spelling sees the same first bytes.
 * Recorded because five matched files use it and it names two fields the
 * slot view leaves anonymous:
 *   +0x00  u16 heapId   func_0203F8F4 stores the constructor parameter
 *   +0x04  u16 unk_04   func_0203F8F4 zeroes it; unit_02041F28 ORs
 *                       (1 << layer) into it after every register write,
 *                       so it is a per-layer dirty mask, 8 bits used
 *   +0x06  u16 unk_06   func_0203F8F4 zeroes it; sub_02041B6C reads and
 *                       writes it with ldrh/strh at [base, #6]
 */

/* ------------------------------------------------------------------ *
 * THE PER-LAYER SLOT, 0x2c bytes.  Eight of them, indexed by layer 0-7.
 *
 * NOTE ON +0x1e VERSUS +0x1f.  func_02040B1C reads `ldrb ip, [ip, #0x1e]`
 * and func_02040C14 reads `ldrb r3, [r0, #0x1f]` off the SAME 0x2c-stride
 * record.  These are NOT a disagreement between lanes and must not be
 * collapsed: they are two adjacent, independently-read bytes.  +0x1e is a
 * zero/non-zero flag (func_02040B1C only tests `== 0` and picks a 32- or
 * 64-byte tile stride from it); +0x1f is a numeric bit depth, multiplied
 * by a tile index and compared against 0x20 in func_02040C14.  Declaring
 * either at the other's offset moves a live ldrb and loses the function.
 * ------------------------------------------------------------------ */
struct BgSlot {
    u16   heapId;               /* +0x00  slots[0] only; func_02040C14
                                 *        masks it (&0x7fff)|0x8000 as a
                                 *        heap id for a scratch alloc    */
    u8    pad_02[6];
    void *tiles;                /* +0x08  the layer's tile/screen buffer.
                                 *        func_02040AF0 loads [ip,#8];
                                 *        sub_02040968's caller adds an
                                 *        offset to it; NULL means the
                                 *        layer is not allocated         */
    u32   unk_0c;               /* +0x0c  sub_020403F4 passes it to
                                 *        sub_02043094 as a cookie;
                                 *        sub_020409E0 loads [r1,#0xc]   */
    u32   size;                 /* +0x10  sub_020409E0 loads [r1,#0x10]
                                 *        and func_0204241C takes it as a
                                 *        byte count (*2 at the call)    */
    u32   scroll_x;             /* +0x14  sub_020407E8 returns it        */
    u32   scroll_y;             /* +0x18  sub_02040804 returns it        */
    u8    mode;                 /* +0x1c  sub_02040820/sub_02040860 and
                                 *        func_02041300 read this byte;
                                 *        the BG mode / screen-size code
                                 *        handed to sub_020422D4         */
    u8    unk_1d;
    u8    flag_1e;              /* +0x1e  func_02040B1C: tested == 0 only */
    u8    depth;                /* +0x1f  func_02040C14: bit depth, a
                                 *        real multiplicand, == 0x20 test */
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

/* ------------------------------------------------------------------ *
 * THE AFFINE ARMS REACH PAST THE 0x2c STRIDE.
 *
 * func_02041B94 (EXACT, src/matched/func_02041B94.c) reads FIVE consecutive words off an
 * affine-capable layer's record, at slot-relative +0x20, +0x24, +0x28,
 * +0x2c and +0x30.  The last two lie PAST the 0x2c stride, in the head of
 * the next record: for layer 2 they are the absolute offsets 0x84 and 0x88,
 * which are layer 3's +0x00 and +0x04.  The offsets are identical for all
 * four affine layers (2, 3, 6 and 7), so this is the structure and not a
 * misread.
 *
 * CONSEQUENCE FOR ANYONE WRITING C HERE.  A `struct BgSlot slots[8]` whose
 * element is exactly 0x2c bytes cannot express those two reads: declaring
 * them as members runs the element to 0x34 and the array's own stride then
 * becomes 0x34, which moves every later layer.  func_02041B94 resolves it
 * by declaring the record out to +0x34 and doing the indexing explicitly
 * with a 0x2c byte stride:
 *
 *     struct BgSys { u8 raw[0x1d0]; };
 *     #define SLOT(i) (*(struct BgSlot *)((u8 *)g_02146A44 + (i) * 0x2c))
 *
 * The image shows all eight indices are compile-time constants -- there is
 * no `mla` anywhere in that function -- so nothing is lost by spelling the
 * stride out.  The five fields are, in order: a u16 at +0x20 and u32s at
 * +0x24, +0x28 (the three func_02051E74 takes) and +0x2c, +0x30 (the pair
 * func_0207D59C takes).
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * THE SEPARATE BG CONFIG TABLE at 0x02146A44 seen as `g_BgConfig`.
 *
 * sub_020407E8, sub_02040820, sub_02040860 and func_02041300 declare the
 * SAME pointer under the name g_BgConfig with an all-u32 0x2c record.
 * That is the identical object as struct BgSlot above (same address, same
 * 0x2c stride, scrollX/scrollY at the same +0x14/+0x18); only the field
 * spelling differs, u32 where the slot view has bytes.  The byte view
 * wins wherever a `ldrb` exists, per the adjudication rule.  Recorded here
 * so a reader of those four files does not think there are two tables.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * A SCREEN / SURFACE descriptor, passed by pointer into the family's
 * tilemap writers.  func_02042ED8 is the constraining file: it loads the
 * entry pointer at +0x00 and a size code at +0x15, then asks
 * sub_020422D4 to turn that code into a width/height pair.
 * ------------------------------------------------------------------ */
struct BgScreen {
    u16 *entries;               /* +0x00  func_02042ED8; NULL -> return  */
    u8   pad_04[0x11];
    u8   size_code;             /* +0x15  func_02042ED8 -> sub_020422D4  */
};

/* The four-word display config block saved and restored around a mode
 * change.  func_0203FC28 replays it; func_0203FC6C selects between its
 * two halves.  Fields 0/4/0xc go to func_0207D4B0, field 8 to
 * func_0207D518 -- which is what proves 0x08 is a separate word and not
 * part of a three-word run. */
struct BgDispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

/* ------------------------------------------------------------------ *
 * A NOTE ON EXTENTS IN THIS FAMILY.
 *
 * Several of the family's functions are followed by leaf accessors that
 * save no registers and so carry no `func_` label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  match.py's
 * inferred extent then runs past the real end of the function and every
 * verification reads as a large SIZE shortfall that is not a shortfall at
 * all.
 *
 * The known case: sub_02040618's listing extent is 0x02040618..0x02040820,
 * 520 bytes, but the function is 464 bytes and ends at 0x020407E8.  The
 * remaining 56 bytes are sub_020407E8 and sub_02040804, the two scroll
 * accessors, which are ALREADY MATCHED as src/matched/unit_020407E8.c.
 * A `tu` over the full range lays out all three sections and confirms
 * 520/520.
 *
 * This matters beyond bookkeeping: tools/permuter.py folds the size gap
 * into its score, so annealing such a function optimises against the wrong
 * target and walks away from a good point.  Establish the true extent with
 * a `tu` before running the permuter on anything in this family whose
 * `one` verdict shows a size shortfall.
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * GLOBALS
 * ------------------------------------------------------------------ */
extern struct BgSys *g_02146A44;    /* the singleton; func_0203F8F4
                                     * allocates it, func_0203F9B4 frees
                                     * and NULLs it                      */
extern u32 gVisiblePlane[2];        /* six matched files; index 0 = engine
                                     * A, 1 = engine B                   */
extern char g_020A7E5C[];           /* the "bg_sys.c" __FILE__ anchor
                                     * passed to sub_02030734            */

/* ------------------------------------------------------------------ *
 * REGISTERS.  Written as cast constants, never relocations
 * (docs/idioms/volatile-reread-needs-two-locals.md).
 * ------------------------------------------------------------------ */
#define REG_DISPCNT   (*(volatile u32 *)0x04000000)  /* func_0203FC28:
                                                      * two separate RMWs,
                                                      * &= ~0x38000000 then
                                                      * &= ~0x07000000     */
/* Affine parameter blocks, one per affine-capable layer.  sub_02040860
 * names all four: main BG2/BG3 and sub BG2/BG3.  Only layers 2, 3, 6, 7
 * have one; cases 0/1/4/5 are empty arms that exist solely to keep the
 * dense jump table (docs/idioms/empty-switch-arms-are-what-make-the-table.md). */
#define REG_BG2P_A    ((void *)0x04000020)
#define REG_BG3P_A    ((void *)0x04000030)
#define REG_BG2P_B    ((void *)0x04001020)
#define REG_BG3P_B    ((void *)0x04001030)

/* ------------------------------------------------------------------ *
 * HELPER PROTOTYPES.  Parameter widths matter: a helper's parameter
 * declared u8/u16 instead of int changes the CALLER's masking.  Each
 * spelling below is the one its matched caller compiles against.
 * ------------------------------------------------------------------ */

/* Allocator / heap, outside the family but used throughout. */
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);                     /* func_0203F8F4 */
extern void  sub_020307B0(void *p);                     /* func_0203F9B4 */
extern void *func_02033C00(u32 size, u32 heapId);       /* func_0203F8F4 */
extern void  func_02033C9C(void *p);                    /* func_0203F9B4 */
extern void  func_02082BCC(void *dst, u32 value, u32 size);
extern void  func_02082AC0(u32 value, void *dst, u32 size); /* func_02040C14 */

/* Arena (VRAM offset allocator) over arena_a / arena_b. */
extern void  func_020341F0(void *arena, u32 unit, u32 count); /* func_02040C14 */
extern void  func_0203422C(void *arena, u32 unit, u32 count); /* func_0203FB44 */

/* IN-FAMILY helpers.  These are the ones an open function most often needs. */

/* The layer's tile stride in bytes.  Takes a u8: func_0203FB44 casts its
 * u32 layer to (u8) at the call, and that cast is load-bearing. */
extern u32  sub_020416B8(u8 layer);                     /* func_0203FB44 */

/* Turn a size code into a width/height pair, both u8 out-parameters.
 * The u8* is what makes the callers' stores strb. */
extern void sub_020422D4(u32 mode, u8 *width, u8 *height); /* func_02042ED8 */

/* Tilemap entry index from a coordinate pair and a size code.  Returns
 * u16.  Case 5 returns 0 and the switch has no default: the matched file
 * falls off the end, which is what the original does. */
extern u16  func_02040EE0(int x, int y, u32 size_code);

/* The BG priority getter, now EXACT (src/matched/func_020416D4.c).
 * Returns the 2-bit priority field of the layer's BGxCNT register.  Three
 * declarations carry it and none is optional:
 *   - the return is a 2-BIT BITFIELD of a struct COPIED from the register,
 *     `struct { u16 prio : 2; u16 rest : 14; }` assigned into a local.
 *     That one spelling emits BOTH the `lsl #0x1e / lsr #0x1e` pair and the
 *     `strh r1, [sp, #N]` spill of the raw halfword; `(x & 3)` loses both
 *     and a plain u16 local loses the spill.
 *   - each read needs its OWN local; the sixteen distinct locals are what
 *     place the spills at the descending slots 0x1e, 0x1c, 0x1a, ...
 *   - the return type is u8, which is the trailing `and r0, r0, #0xff`.
 *
 * AND ONE CONTROL-FLOW FACT, which is what closed it on the second pass.
 * The four affine layers' sub-dispatch emits the FULL unfused chain
 *     cmp r0,#0 ; beq A ; cmp r0,#1 ; beq B ; cmp r0,#2 ; beq C ; <fall>
 * in which the mode==0 target IS the fall-through address.  No if/else-if
 * chain reproduces that (the compiler fuses the first test into
 * `cmp r0,#0 / bne`) and an inner switch builds a jump table and comes out
 * 16 bytes short.  Only an explicit goto chain does it:
 *     u8 m = g[layer].mode;
 *     if (m == 0) goto L_0;  if (m == 1) goto L_1;  if (m == 2) goto L_2;
 *     L_0: ...  L_1: ...  L_2: ...
 * with the labels in source order, so L_0 doubles as the fall-through.
 * Caching the mode in `m` is part of it: reading the field three times
 * re-emits the `mla` address computation before each test.  This is
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * applied to a dispatch rather than to a guard chain. */
extern u8   func_020416D4(u32 layer);

/* Per-layer visible-plane toggles, one per engine.  sub_02040588 fans a
 * 0-7 selector into these with a one-hot mask. */
extern void func_020434DC(u32 mask, u32 enable);        /* engine A */
extern void func_02043598(u32 mask, u32 enable);        /* engine B */

/* The three register-write paths, all sharing the +0x04 dirty-mask OR. */
extern void func_02043228(void *slot, u32 op, u16 value);  /* unit_02041F28 */
extern void func_02043264(void *slot, u32 op, u16 value);
extern void func_020432E4(void *slot, u32 op, u16 value);

/* Tilemap / VRAM writers.  Note the u8 index on func_02042508 against the
 * u32 index on func_0204241C: both are as their matched callers spell them. */
extern void func_02042508(u8 index, const void *src, u32 size, u32 offset);
extern void func_0204241C(u32 index, const void *src, u32 offset, u32 size);
extern void func_020425B4(u32 layer, const void *src, u32 offset, u32 size);
extern void func_02040968(const void *src, void *dst, u32 mode);

/* The three blit variants selected by the slot's +0x1c kind byte.  All
 * three share one argument shape; sub_02042360's caller (func_020422xx)
 * dispatches on `g_02146A44[i].unk_1c`. */
/* THE THREE TILE-RECT COPIERS, all EXACT since wave 11
 * (src/matched/func_020426A0.c, func_020428E8.c, func_02042B24.c).  One
 * prototype for all three, differing only in the cell type:
 *
 *   void f(struct Screen *s, u8 dx, u8 dy, u8 cw, u8 ch, const T *src,
 *          u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
 *
 *   func_020426A0  T = u16, destination through func_02040EE0's index
 *   func_020428E8  T = u8,  destination through func_02040EE0's index
 *   func_02042B24  T = u16, destination linear: dst[dx + x + w * (dy + y)]
 *
 * dx is compared against the FIRST out-byte of func_020422D4 (w) and is
 * func_02040EE0's first argument; dy against the second (h).  mode 0 reads
 * src[sx + x + sw * (sy + y)]; any other mode reads src[func_02040F84(sx +
 * x, sy + y, sw, sh)].  In the u8-wrap arms (mode 0 of 020426A0 and
 * 02042B24) the clip tests are on `(u8)(d + i)` and a miss SKIPS the cell or
 * row; everywhere else the tests are on plain int sums and a miss breaks /
 * returns.  The source row index in 02042B24's mode 0 is the UNWRAPPED
 * sy + y even though the clip test wraps it.
 *
 * WHAT CLOSED THEM, and it generalises: ch, sw and sh are u8 STACK
 * parameters although the image loads each with a full `ldr` and re-stores
 * it to its own home (`ldr r0,[sp,#0x50]; str r0,[sp,#0x50]`).  Declared
 * u32 or int they compile to the same size with the prologue's parameter
 * homes scheduled in a different order.  A u8 stack argument occupies a
 * word and is read as one; do not infer u32 from the `ldr`.  (Same fact as
 * func_02042D2C's seventh parameter below.)  The out-bytes are declared
 * `u8 w, h;` so w takes the higher address; the loop counters `u8 y, x;`.
 * The callers func_020410D0 / func_020411E8 already declare the fifth
 * parameter (ch) as u8. */
extern void func_020426A0(void *s, u8 dx, u8 dy, u8 cw, u8 ch, const u16 *src,
                          u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
extern void func_020428E8(void *s, u8 dx, u8 dy, u8 cw, u8 ch, const u8 *src,
                          u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
extern void func_02042B24(void *s, u8 dx, u8 dy, u8 cw, u8 ch, const u16 *src,
                          u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);

/* The source-index router the copiers call in mode != 0.  Its own EXACT
 * definition spells four u32 parameters, but all three copiers compile
 * byte-exact only against `u8 w, u8 h` for the last two (u8 values passed
 * straight through; declaring them int moves the callers' allocation). */
extern u16 func_02040F84(u8 x, u8 y, u8 w, u8 h);

/* func_0203FA08 (EXACT, wave 11): the tile-run allocator paired with
 * func_0203FAF0.  The tile stride func_020416B8 returns is held in an INT
 * local (u32 gives the right code in the wrong registers); the round-up
 * flag is `f = (size % t != 0)` taken before `n = size / t` (remainder
 * first), and the arena base is selected into a local before the
 * direction test.  Returns the run's tile index relative to tile_base[] or
 * 0xFFFFFFFF. */
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);

/* sub_02040618 (EXACT*, wave 11): the per-layer scroll flush.  Confirms
 * func_0203D814(scroll_x, scroll_y) from a second caller: the layer-1 arm
 * keeps x/y live in r0/r1 across the BG1HOFS write for the call.  scrollX
 * is read before scrollY. */

/* func_02041FF4 is EXACT since wave 12 (src/matched/func_02041FF4.c), the
 * pixel-under-(x, y) colour test.  It proves, against its own bytes:
 *   extern void func_02043130(u16 pal, void *buf, u16 heap);  (u16 first
 *     parameter; 75 -> 63 on its own in wave 11)
 *   extern u16  func_02040EE0(u8 x, u8 y, u8 size_code);      (the caller
 *     masks both coordinates and passes slot->unk_1d)
 *   extern u8  *func_020415B4(u32 layer);                     (char base)
 * and one allocation rule worth reusing: the sub-tile coordinates are
 * FUNCTION-SCOPE `u8 px, py;` declared first and assigned `px = x & 7`
 * after the two calls -- they then coalesce with x/y (the image's in-place
 * `and r5, r5, #7`).  Block-scoped `u8 px = x & 7` keeps both alive (42
 * out), and in-place `x &= 7` reorders the prologue (63).  The nibble loop
 * counter `u8 i` is also function-scope and must be declared before the
 * tile table pointer, which is declared before the scratch buffer. */

/* The fill/copy trio reached from func_02041300, which reads the layer's
 * +0x1c mode byte to choose between them.  The trailing u8 parameters are
 * what force the caller's `and #0xff` sequence. */
/* func_02042D2C is EXACT (src/matched/func_02042D2C.c, filed in df76914).  Its seventh
 * parameter is u8, NOT u32.  The old note argued for u32 because the
 * argument arrives by `ldr` and not `ldrb`; that reasoning is wrong, since
 * a u8 stack argument also occupies a full word of the argument area and is
 * also loaded with `ldr`.  The narrower type is what closed the function's
 * last 11 bytes: it changes the value's spill cost and so moves its home
 * load behind the other two prologue instructions.  Its two siblings
 * func_02042E34 and func_02042ED8 keep u32 on their own last parameter --
 * this is a per-function fact, not a family-wide one. */
extern void func_02042D2C(void *p, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                          u8 mode);
extern void func_02042E34(void *p, u8 a1, int a2, int a3, u8 a4, u8 a5);
extern void func_02042ED8(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);

/* Display bring-up, called in pairs by func_0203FC28 / func_0203FC6C. */
extern void func_0207D4B0(u32 a, u32 b, u32 c);
extern void func_0207D518(u32 a);
/* The affine register writer.  func_02041B94 pins the argument order: the
 * matrix pointer is second, the layer's affine pair (+0x2c/+0x30 of the
 * record) is third and fourth, and the SCROLL pair is fifth and sixth --
 * i.e. the two that end up spilled to [sp] and [sp,#4] are the scroll
 * values, not the affine ones.  The reversed order compiles to the same
 * size and differs only in which pair is spilled. */
extern void func_0207D59C(void *reg, struct BgMtx *m, u32 a, u32 b,
                          u32 x, u32 y);

/* Builds the 16-byte affine matrix func_0207D59C consumes.  The SIZE is
 * pinned by func_02041B94's frame: its four stack temporaries sit at
 * sp+0x38, +0x28, +0x18 and +0x08, a stride of 0x10, and a 32-byte matrix
 * gives `sub sp, #0x88` instead of the image's `#0x48`. */
struct BgMtx { u32 w[4]; };
extern void func_02051E74(struct BgMtx *m, u16 a, u32 b, u32 c, u32 d);

/* Takes the layer's SCROLL PAIR, not void.  func_02041B94 loads +0x40 and
 * +0x44 (layer 1's scroll_x/scroll_y) immediately before the `bl`; a void
 * declaration leaves those two loads with no reason to exist. */
extern void func_0203D814(u32 scroll_x, u32 scroll_y);

/* The per-frame scroll/affine flush for all eight layers, EXACT
 * (src/matched/func_02041B94.c, filed in 9e49e95).  Eight independent blocks, one per layer,
 * each guarded by its own bit of the +0x04 dirty mask; nothing loops. */
extern void func_02041B94(void);
extern void func_0204349C(void);
extern void func_02043558(void);
extern void func_020434CC(u32 handle);
extern void func_02043588(u32 handle);

extern void DC_FlushRange(void *p, u32 size);

#endif /* BG_SYS_H */
