/*
 * docs/families/palanm.h -- shared declarations for the palanm.c family
 * (0x02021518..0x020224DC in the ARM9 image).  The family anchor is the
 * __FILE__ pointer at g_020A73BC, which src/matched/func_02021518.c and
 * src/matched/func_0202155C.c both pass to the tagged allocator.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT or EXACT*, and the
 * matched function that evidences each field is named in the comment beside
 * it.  Where the matched sources disagree on a parameter's spelling (they
 * were written by different lanes), the spelling recorded here is the one
 * the byte evidence actually constrains.
 *
 * NOTE ON EXTENT.  The span holds THREE distinct subsystems, not one
 * original file, and the seams are sharp:
 *
 *   0x02021518..0x020216D4  the palette double-buffer array (struct
 *     PalAnmSlot below): allocate, free, blit, load-from-archive, and the
 *     four-bank hardware-palette snapshot.  This is the part the palanm.c
 *     anchor actually names.
 *   0x0202173C..0x020220xx  the fourteen-channel animation engine (struct
 *     PalAnmObj below): a 0x140-byte object of 14 channel records plus a
 *     0x118 header, driven per frame by func_02021A84 / func_02021D50 and
 *     the RGB555 blend loops func_02021C20 / func_02021F64.  It shares the
 *     PalAnmSlot array only indirectly.
 *   0x0202208C..0x020224DC  the dual-screen window/text cluster at the
 *     fixed object g_021467A4, with its own callback block, its own mode
 *     decoder and its own task handle at g_021468A4 +0x54.  This is NOT
 *     palette animation at all; it is a separate original file that happens
 *     to be laid down adjacent.  Its declarations are kept in their own
 *     section at the bottom.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef PALANM_H
#define PALANM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;

/* ================================================================== *
 * PART 1: the palette double-buffer array, 0x02021518..0x020216D4
 * ================================================================== */

/* One slot: two buffers of identical size, double-buffered so the engine
 * can blend into one while the other is being DMA'd out.  The 0x14 stride
 * is evidenced by the `muls`/`adds` scaling in func_020215A0 and
 * func_020215BC; only the first three words are ever touched by a matched
 * function, so +0x0C and +0x10 are named but not typed.
 *
 * The two buffer pointers are `u16 *`, not `void *`: func_020215BC scales
 * the offset ONCE (`lsls r4, r3, #1`) and reuses it for both destinations,
 * which is halfword pointer arithmetic and not a byte offset the caller
 * pre-doubled.  func_02021548 spells them `void *` because it only stores
 * them; func_020215BC is the file that constrains the type. */
struct PalAnmSlot {
    u16 *unk_00;    /* +0x00  func_02021548 stores a; func_020215A0 frees it */
    u16 *unk_04;    /* +0x04  func_02021548 stores b; func_020215A0 frees it */
    u32  size;      /* +0x08  func_0202155C: the allocator's own size arg,
                     *        never reloaded, which is what pins it as the
                     *        caller's parameter rather than a field read */
    u32  unk_0c;    /* +0x0C  no matched function touches it */
    u32  unk_10;    /* +0x10  no matched function touches it */
};

/* The palette resource header the archive loaders hand back.  Only +0x08
 * and +0x0C are read (func_020215EC, func_02021660): the count falls
 * through to the caller when it passed zero, and the data pointer is
 * halfword-indexed by the source offset. */
struct PltRes {
    u32  unk_00;
    u32  unk_04;
    u32  count;     /* +0x08  func_020215EC: used when count == 0 */
    u16 *data;      /* +0x0C  func_020215EC: `res->data + srcOff` */
};

/* Allocate and zero the 0x120-byte palette-animation context.  The size is
 * out of Thumb immediate range, so func_02021518 materialises the tag 88
 * first and derives 0x120 from it with `adds r4, #0xc8`. */
extern void *func_02021518(u32 heap);

/* Fill one slot: the two buffers and their common size.  The fifth
 * argument arrives on the stack, at [sp, #8] behind two pushed registers. */
extern void func_02021548(struct PalAnmSlot *slots, u32 idx, void *a,
                          void *b, u32 size);

/* Allocate the double buffer for one slot: two blocks of the same size
 * from the same heap, tags 142 and 143, then func_02021548. */
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size,
                          u32 heap);

/* Release the double buffer of one slot; the inverse of func_0202155C.
 * The two pointers are read back from the array rather than passed in,
 * which is what keeps the 0x14 stride multiply live. */
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);

/* Copy the same source halfwords into BOTH buffers of one slot at the same
 * halfword offset.  `size` is a u16 read with `ldrh` at [sp, #0x18] behind
 * six pushed registers, and widened into the copier's u32 length. */
extern void func_020215BC(struct PalAnmSlot *slots, const void *src,
                          u32 idx, u32 off, u16 size);

/* Load a palette resource, copy a run of it into both buffers, release the
 * block.  The two are the same function against sibling loaders
 * (func_02049F34 / func_02049F78).  The loader's fourth argument is
 * `(u16)((tag & 0x7fff) | 0x8000)`: 0x7fff is one pool word and 0x8000 is
 * re-derived from it with `adds r3, r4, #1`. */
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_02021660(struct PalAnmSlot *slots, u32 arcId, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);

/* The srcOff-of-zero forwarders.  The seventh argument is re-read with
 * `ldrh`, which is what pins it u16 in both prototypes. */
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off);
extern void func_020216B4(struct PalAnmSlot *slots, u32 arcId, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off);

/* Snapshot one hardware palette bank into the slot that shadows it.  The
 * bank selector indexes BOTH the hardware base and the slot array, so
 * 0..3 are the four DS palette RAM windows in this order:
 *
 *   0  0x05000000  main BG     (the only one built with movs #5 / lsls #24)
 *   1  0x05000400  sub  BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub  OBJ
 *
 * which is why the dense halfword switch has one two-instruction arm and
 * three one-instruction ones (func_020216D4). */
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off,
                          u32 size);

/* ================================================================== *
 * PART 2: the fourteen-channel animation engine, 0x0202173C..0x02022004
 * ================================================================== */

/* The per-channel record, 0x14 bytes, fourteen of them at the head of the
 * object.  Two matched files read it through different lenses:
 * func_02021D50 (the apply pass) wants f4/f8 as the surface handle and its
 * argument; func_02021BC8 and func_02021FD8 want +0x00/+0x04 as the two
 * halfword buffers of the blend.  They are the same five words. */
struct PalAnmChan {
    u16 *src;       /* +0x00  func_02021BC8, func_02021FD8 */
    u16 *dst;       /* +0x04  func_02021BC8, func_02021FD8; func_02021D50
                     *        reads the same word as the surface handle it
                     *        passes to func_020862F0 and the 0x0207xxxx
                     *        setters, so a channel's "buffer" and its
                     *        "surface" are one field */
    u32  f8;        /* +0x08  func_02021D50 passes it as the setters' third
                     *        argument; func_02021984 reads the SAME word as
                     *        a packed width: bits[5:13) for channels 0..3
                     *        and bits[9:17) for 4..0xD */
    u32  fc;        /* +0x0C  the 8-byte animation sub-object below, which
                     *        func_020219C4 initialises and func_02021BC8 /
                     *        func_02021CA8 step; both callers pass
                     *        `p + idx * 0x14 + 0xc` */
    u32  f10;       /* +0x10  func_02021BC8 reads it as `field0xc`'s upper
                     *        half; no matched function writes it */
};

/* The 8-byte animation sub-object at channel +0x0C.  Every field is a
 * bitfield of one of the four halfwords; func_020219C4 is the initialiser
 * that fixes the whole layout and func_02021CA8 the stepper that confirms
 * it independently.
 *
 * The two files name the +0x02 triple differently -- func_020219C4 calls
 * them lo/mid/hi, func_02021CA8 calls them lo6/cur/max -- and they are the
 * same three fields.  func_02021C20 multiplies by the middle one, which is
 * therefore both "the current slider position" and "the blend weight". */
struct PalAnmAnim {
    u16 f0;         /* +0x00  func_020219C4 stores arg2 whole (strh) */
    u16 lo6  : 6;   /* +0x02  func_020219C4: 0 for a negative step, else the
                     *        clamped start value; func_02021CA8: unused */
    u16 cur  : 5;   /* +0x02  func_020219C4 `mid` = arg4; func_02021CA8
                     *        steps it and clamps at `max`; func_02021C20
                     *        multiplies by it as the blend weight.
                     *        Arg 4 must be u8 at func_020219C4 or the 5-bit
                     *        store costs an extra truncation shift pair */
    u16 max  : 5;   /* +0x02  func_020219C4 `hi` = arg5; func_02021CA8's
                     *        clamp target in both directions */
    u16 target : 15;/* +0x04  func_020219C4 `val` = arg6 (u16, `ldrh
                     *        [r5,#4]` off the stack-arg area);
                     *        func_02021C20 reads it as a packed RGB555 */
    u16 sign : 1;   /* +0x04  func_020219C4 sets it from `b < c`;
                     *        func_02021CA8 uses it to pick the direction */
    u16 step : 5;   /* +0x06  func_020219C4: 2, or |a| + 2 clamped to 0x10;
                     *        func_02021CA8: the per-tick amount */
    u16 copy : 6;   /* +0x06  func_020219C4 copies `lo6` here */
    u16 pad6 : 5;   /* +0x06  no matched function touches it */
};

/* The 0x140-byte slot object: fourteen channel records, then a 4-byte
 * header at +0x118 and a latch byte at +0x11C.  The header is the part
 * every file in the engine shares, and five matched files plus two DIFF
 * notes agree on it exactly.
 *
 * b_x is bit 14 of the +0x11A halfword, NOT bit 15: sub_02021EE4 writes
 * bit 15 (`lsls #0x11 / lsrs #0x1f` and `movs #1 / lsls #0xe` in the
 * 0x0202173C note pin the two apart). */
struct PalAnmObj {
    struct PalAnmChan ch[14];   /* +0x000 .. +0x117 */

    u16 a_mode : 2; /* +0x118  the running mode; func_02021A84 ticks only
                     *         when it reads 1, func_02021D50 clears it when
                     *         the channel mask drains, func_02021F08 arms
                     *         it from the low bit of its argument */
    u16 a_big  : 14;/* +0x118  the fourteen "channel wants to run" bits;
                     *         func_02021944 sets one, func_0202173C ORs a
                     *         whole mask in, func_02021848 assigns it,
                     *         func_02021F08 sets all fourteen */
    u16 b_lo : 14;  /* +0x11A  the fourteen "channel is running" bits,
                     *         copied from a_big by func_02021A84 and
                     *         func_02021D50; func_02021B6C and
                     *         func_02021CA8 test and toggle single bits of
                     *         it through the 0xFFFF0003 pool mask */
    u16 b_x  : 1;   /* +0x11A bit 14: "the per-frame tick is registered".
                     *         func_0202173C sets it and registers
                     *         func_02021A84 with func_02030DA8;
                     *         func_02021A84 clears it on teardown */
    u16 b_hi : 1;   /* +0x11A bit 15: "apply every channel unconditionally".
                     *         sub_02021EE4 is the setter; func_02021D50
                     *         skips its per-channel guards when it is set */
    u8  latch;      /* +0x11C  func_02021A84 reads 1 here as "tear down on
                     *         the next tick" and clears it; sub_02021B18
                     *         sets it when b_lo has drained */
};

/* ADDED 2026-09-23 (wave 13).  func_0202173C and func_02021848 (both DIFF,
 * 33 out) are mis-cut in the listing (extent 2 bytes each), which poisons
 * the permuter's size term.  A scratch wrapper that imports tools/permuter.py
 * and overrides match.target_extent() (268 / 232) gives it a fair run
 * without editing tools/: hill and anneal both plateau at 33, so the
 * home-store placement of `a` is now a real permuter negative.  Their
 * func_020219C4 call passes SIX arguments; the callee's seventh slot is
 * whatever sits at [sp,#8] (passing a seventh costs 12-16 bytes). */

/* Bit test: returns 1 when bit `bit` of `val` is set, else 0.  A leaf that
 * saves no lr, so disasm.py prints it inside a `.word` run
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The whole
 * engine funnels its mask tests through it. */
extern u8 func_02021930(u32 val, int bit);

/* Set bit `a1` of a_big, unless the bit is already set. */
extern void func_02021944(struct PalAnmObj *p, int a1);

/* Narrow *pv to channel `idx`'s own bit width, which is an 8-bit field of
 * the channel's f8: bits[5:13) for 0..3, bits[9:17) for 4..0xD.  The mask
 * is accumulated in a u16 `1 << n` loop, NOT built as `(1 << w) - 1`; the
 * loop is what the original bytes show. */
extern void func_02021984(s32 idx, struct PalAnmChan *c, u16 *pv);

/* Seven-argument initialiser for one PalAnmAnim.  Arguments 5..7 arrive on
 * the caller's stack (`add r5, sp, #0x10` with a bare `push {r4-r7}`);
 * argument 7 is never read.  Both callers (0x0202173C, 0x02021848) pass
 * `p + idx * 0x14 + 0xc`. */
extern void func_020219C4(struct PalAnmAnim *s, u16 f0, s32 a, u8 b,
                          u8 c, u16 d, u32 e);

/* Per-frame tick, the function func_0202173C registers with func_02030DA8.
 * Teardown when `latch` is set; otherwise, when a_mode reads 1, copy a_big
 * into b_lo, step all fourteen channels and clear b_x when a_big drains. */
extern void func_02021A84(void *a, struct PalAnmObj *p);

/* Set `latch` when b_lo (the 14 bits above a_mode) is non-zero.  Another
 * unlabelled leaf; the `lsls #0x10 / lsrs #0x12` pair is the unequal-shift
 * narrowing form, a u16 truncation folded with a >> 2. */
extern void sub_02021B18(struct PalAnmObj *o);

/* Step channels 0..3 with arg 0x10, and 4..0xD with arg 0x100.  The split
 * is the same one func_02021984 uses for the width field and
 * func_0202173C for the func_02021BC8 argument, so "channel < 4" is a real
 * structural boundary in this object, not a coincidence. */
extern void func_02021B2C(struct PalAnmObj *p);
extern void func_02021B4C(struct PalAnmObj *p);

/* One channel's tick: returns early unless bit `idx` of b_lo is set, then
 * advances `cur` toward `max` or, at the end, resets and re-runs the
 * channel through func_02021BC8. */
extern void func_02021B6C(struct PalAnmObj *p, u32 idx, u32 arg);

/* Re-run one channel: for each of the sixteen sub-slots whose bit is set
 * in the anim sub-object's +0x0C halfword, blend one run of `arg`
 * halfwords, then step the slider through func_02021CA8. */
extern void func_02021BC8(struct PalAnmObj *p, u32 idx, u32 arg);

/* The per-pixel RGB555 blend loop, `weight`/16 of the way from src to the
 * anim sub-object's own target colour.  EXACT since wave 13
 * (src/matched/func_02021C20.c): `u16 a = src[i]; u16 t = c->target;` as
 * LOCALS, every channel extraction inline in its blend, blends in r, b, g
 * order, and the pack `r | ((b << 10) | (g << 5))` -- the operand ORed last
 * is the one the compiler evaluates first.  Same shape as func_0202EA40 in
 * blink_palanm.c. */
extern void func_02021C20(u16 *src, u16 *dst, struct PalAnmAnim *c,
                          u32 count);

/* Step or clear one slider.  When `cur` has reached `max` it instead
 * toggles bit `idx` of b_lo (pool word 0xFFFF0003 preserves a_mode) and
 * returns; otherwise `sign` picks the direction and `step` the amount, and
 * the result is clamped to `max` and written back through 0xFFFFF83F. */
extern void func_02021CA8(struct PalAnmObj *p, u32 idx, struct PalAnmAnim *s);

/* The apply pass: walks the fourteen channels and pushes each one's value
 * out through the graphics-engine setter its index selects (a dense
 * 14-entry halfword switch at 0x02021DBA).  `i` must be u32 for the
 * switch's range guard to be `cmp #0xd; bhi`, but the LOOP bound must be
 * compared signed, `(int)i < 14`, or the back edge is `bhs` where the
 * original has `bge`. */
extern void func_02021D50(struct PalAnmObj *p);

/* Write b_hi (bit 15 of +0x11A) from the low bit of the argument.  An
 * unlabelled leaf; both pool words are plain literals, 0x0000011A for the
 * offset (past the ldrh immediate reach) and 0xFFFF7FFF for the mask. */
extern void sub_02021EE4(struct PalAnmObj *o, int v);

/* Arm the header: a_mode from the low bit of the argument, then all
 * fourteen a_big bits set.  The other unlabelled leaf of this pair, and
 * the second pool pair, 0xFFFF0003 / 0x0000FFFC, is the matching
 * clear-mask and all-ones insert. */
extern void func_02021F08(struct PalAnmObj *o, int v);

/* The second RGB555 blend loop, toward a colour passed by value rather
 * than read from the anim sub-object.  `weight` is a SIGNED int: as u32
 * the products go unsigned and the three `>> 4` become `lsrs` where the
 * original has `asrs`.  The channels must be read through a bitfield
 * pointer INTO src[i], not through a value copy, which would spill the
 * pixel to a stack slot the image never uses. */
struct PalAnmRgb555 {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 pad : 1;
};
extern void func_02021F64(u16 *src, u16 *dst, u32 count, int weight,
                          struct PalAnmRgb555 color);

/* The func_02021F64 wrapper: picks channel `idx`, advances both pointers
 * by `c` halfwords.  Arguments 5 and 6 arrive on the stack and must be
 * u8 / u16, which is what makes them `ldrb [r5]` and `ldrh [r5, #4]`. */
extern void func_02021FD8(struct PalAnmChan *p, u32 idx, u32 c, u32 count,
                          u8 weight, u16 color);

/* Run func_02021FD8 over every set bit of a 16-bit mask, 0x10 halfwords at
 * a time, walking the offset up by 0x10 per bit whether or not the bit is
 * set. */
extern void func_02022004(u32 a0, u32 a1, u16 m, u32 a3, u32 a4);

/* ================================================================== *
 * PART 3: the dual-screen window/text cluster, 0x0202208C..0x020224DC.
 * A DIFFERENT SUBSYSTEM, sharing only adjacency with the above.
 * ================================================================== */

/* One screen descriptor, 0x26 bytes, built field-for-field by
 * func_02022430 with no validation.  The sixth and seventh arguments are
 * stored the other way round from the argument order (+0x14 before +0x10),
 * so the struct's field order is NOT the parameter order. */
struct TxtScreen {
    u32   f00;
    u32   f04;
    s32   f08;      /* the sector-scaled count func_0202208C divides */
    u32   f0C;
    u32   f10;
    u32   f14;
    void *f18;      /* the shared f8C buffer */
    void *f1C;      /* the shared f74 callback block */
    u32   f20;
    u16   f24;      /* a u16, not a pointer: `ldrh [r1,#0x18]` off sp */
};

/* The two-entry callback block at cluster +0x74: three parallel arrays.
 * Both handler slots are armed with the do-nothing func_020225F0 rather
 * than a null, so the dispatcher never has to test them. */
typedef void (*TxtHandler)(void);
struct TxtSlots {
    void       *ctx[2];     /* +0x00 */
    TxtHandler  fn[2];      /* +0x08 */
    u32         arg[2];     /* +0x10 -- the liveness words */
};

/* The fixed cluster object at 0x021467A4.  Every pool word in
 * func_020221B8 and func_02022174 is this ONE symbol with a different
 * displacement, not seven objects
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-
 * the-load-reach.md). */
struct TxtSub { u8 pad[0x30]; };   /* +0x0C is the state word, +0x28 the
                                    * task handle func_020222EC retests */
struct TxtCluster {
    u32            mode;    /* +0x00  func_020223C0 writes the triple here */
    void          *f04;     /* +0x04  the top screen slot */
    void          *f08;     /* +0x08  the bottom screen slot */
    void          *f0C;     /* +0x0C  the top delegate */
    void          *f10;     /* +0x10  the bottom delegate */
    struct TxtSub  f14;     /* +0x14  the top sub-object */
    struct TxtSub  f44;     /* +0x44  the bottom sub-object */
    struct TxtSlots f74;    /* +0x74  the callback block */
    u8             f8C[0xC0];/* +0x8C the shared buffer */
    u16            f14C;    /* +0x14C the live counter; func_020221A4 is the
                             *        image's most-called predicate on it */
    u8             f14E;    /* +0x14E top delegate armed */
    u8             f14F;    /* +0x14F bottom delegate armed */
    u16            f150;    /* +0x150 the latched sentinel colour */
};
extern struct TxtCluster g_021467A4;

/* The second fixed object of this subsystem.  +0x10 is the sentinel colour
 * func_0202223C reads back for 0xFFFF and func_02022268 writes; +0x54 is
 * the task handle func_02022490 creates and func_020224DC releases. */
struct TxtSys {
    u8    pad00[0x10];
    u16   f10;
    u8    pad12[0x42];
    void *f54;
};
extern struct TxtSys g_021468E4;   /* the +0x10 half */
extern char g_021468A4[];          /* the +0x54 half, spelled as a byte
                                    * array by func_02022490's own file */

extern void  func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5,
                           u32 p6, u32 p7);   /* setup */
extern void  func_02022174(void);             /* per-frame poll */
extern u32   func_020221A4(void);             /* "is it idle?" (fan-in 111) */
extern void  func_020221B8(void);             /* shutdown */
extern void  func_0202223C(u32 a, u32 color); /* sentinel -> blend const */
extern void  func_02022268(u32 color);        /* the read-modify-write form */
extern void  func_020222CC(u32 which, u32 unused);  /* 0x0400006C/0x0400106C */
extern void  func_020222EC(struct TxtCluster *p);   /* teardown */
extern u32   func_02022340(struct TxtCluster *p, void *top, void *bottom);
extern void  func_020223C0(u32 mode, void *p);      /* the 5-case decoder */
extern void  func_02022430(struct TxtScreen *s, u32 a, u32 b, s32 c, u32 d,
                           u32 e, u32 f, void *g, void *h, u32 i, u16 j);
extern void  func_02022458(struct TxtSlots *p);     /* arm both slots */
extern void  func_02022478(int a0, int *p);         /* the dispatcher */
extern void  func_02022490(char *p, int a1, int a2, int a3);  /* arm one */
extern void  func_020224DC(struct TxtSlots *p, u32 idx);      /* drop one */
extern void  func_020225F0(void);                   /* the do-nothing */

/* ================================================================== *
 * Externals the family calls out to
 * ================================================================== */

extern const char g_020A73BC[];     /* the palanm.c __FILE__ anchor */

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *site,
                           u16 tag);                /* tagged allocator */
extern void  func_020307B0(void *p);                /* the matching free */
extern u32   func_02030DA8(void *owner, void *fn, void *p, s32 n);
extern void  func_02030EAC(void *a);                /* task release */
extern int   func_02005624(int fn, void *ctx, int arg);  /* task create */
extern void  MI_CpuFill8(void *dest, u32 data, u32 size);
extern void  MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void *func_02049F34(u32 arcId, u32 fileId, struct PltRes **out, u16 tag);
extern void *func_02049F78(u32 arcId, u32 fileId, struct PltRes **out, u16 tag);
extern u32   CARD_GetBackupSectorSize(void);

#endif /* PALANM_H */
