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
extern void func_020426A0(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u32 a6);
extern void func_020428E8(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u32 a6);
extern void func_02042B24(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u32 a6);

/* The fill/copy trio reached from func_02041300, which reads the layer's
 * +0x1c mode byte to choose between them.  The trailing u8 parameters are
 * what force the caller's `and #0xff` sequence. */
extern void func_02042D2C(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02042E34(void *p, u8 a1, int a2, int a3, u8 a4, u8 a5);
extern void func_02042ED8(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);

/* Display bring-up, called in pairs by func_0203FC28 / func_0203FC6C. */
extern void func_0207D4B0(u32 a, u32 b, u32 c);
extern void func_0207D518(u32 a);
extern void func_0207D59C(void *reg, u32 a, u32 b, u32 c, u32 x, u32 y);
extern void func_0204349C(void);
extern void func_02043558(void);
extern void func_020434CC(u32 handle);
extern void func_02043588(u32 handle);

extern void DC_FlushRange(void *p, u32 size);

#endif /* BG_SYS_H */
