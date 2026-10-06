/*
 * file:     bg_sys_p05.c
 * unit:     yes
 * function: func_020426A0, func_020428E8, func_02042B24, func_02042D2C, func_02042E34, func_02042ED8, sub_02042FB0, sub_02042FF8, sub_02043094, func_02043130, sub_02043228, sub_02043264
 * address:  0x020426A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand from the verified parts of tools/restructure.py.
 *
 * symbols:
 *   func_020422D4  0x020422D4  arm
 *   func_02040EE0  0x02040EE0  arm
 *   func_02040F84  0x02040F84  arm
 *   g_02146A44     0x02146A44  data
 *   func_020341F0  0x020341F0  arm
 *   func_0203422C  0x0203422C  arm
 *   func_02043130_File 0x020A7E5C  data
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj16005.h"

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed int         s32;
typedef signed short       s16;
typedef int                BOOL;

struct AreaMan;
struct Mtx22;

struct Bg {
    void *buf;
    u32   bufSize;
    u32   unk_08;
    u32   scrollX;
    u32   scrollY;
    u8    type;
    u8    unk_15;
    u8    unk_16;
    u8    unk_17;
    u16   unk_18;
    u16   unk_1a;
    u32   unk_1c;
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

struct BgSys {
    u16       heapId;
    u16       unk_02;
    u16       unk_04;
    u16       unk_06;
    struct Bg bgs[8];
    void     *unk_168;
    void     *unk_16c;
    u32       unk_170[8];
    u32       unk_190[8];
    u32       unk_1b0[8];
};

struct Mtx { u32 w[4]; };
struct BgConfigLayer {
    char pad_00[0x1C];
    u8 mode;
    char pad_1D[0x0F];
};
struct BgCnt { u16 prio : 2; u16 rest : 14; };
struct Param {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];

void func_020426A0(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
void func_020428E8(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
void func_02042B24(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
void func_02042D2C(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u8 mode);
void func_02042E34(struct Bg *s, u8 value, u8 x0, u8 y0, u8 w, u8 h);
void func_02042ED8(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u32 mode);
void sub_02042FB0(u32 idx, u32 x, u32 y, u16 value);
void sub_02042FF8(u32 idx, u32 offset, u32 size);
void sub_02043094(u32 idx, u32 offset, u32 size);
void func_02043130(u16 flags, u8 *buf, u32 page);
void sub_02043228(struct Bg *p, u32 op, u16 value);
void sub_02043264(struct Bg *p, u32 op, u32 value);
extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern u16  func_02040EE0(u8 x, u8 y, u8 size_code);
extern u16  func_02040F84(u8 x, u8 y, u8 w, u8 h);
struct AreaMan;
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082D44(void *dst, void *src, u32 n);
extern u8 func_02043130_File[];

/*
 * The u16 tile-to-tile copier, sibling of func_020428E8 (u8 cells) and
 * func_02042B24 (linear destination).  mode 0 clips each row and cell
 * with u8-wrapped coordinates and skips; any other mode clips with int
 * sums, stops at the first miss and indexes the source through
 * func_02040F84.  Written in wave 11 straight from the two siblings'
 * settled declarations (u8 ch/sw/sh stack parameters, u8 w/h for
 * func_02040F84, `u8 w, h;` and `u8 y, x;`); EXACT at the first compile.
 */
void func_020426A0(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = (u16 *)s->buf;
    if (dst == 0)
        return;

    func_020422D4(s->unk_15, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                            src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                    src[func_02040F84(sx + x, sy + y, sw, sh)];
            }
        }
    }
}

/*
 * Tile-to-tile copier: copies a cw x ch block of a source tilemap
 * (row stride sw, height sh, origin sx/sy) into the screen's tilemap at
 * dx/dy, clipped to the screen size func_020422D4 reports.  mode 0 reads
 * the source linearly, any other mode through func_02040F84's index.
 *
 * Closed in wave 11.  Three declarations carry it: ch, sw and sh are u8
 * stack parameters even though the image loads each with a full `ldr`
 * (a u8 stack argument still occupies and is read as a word; the narrow
 * type is what moves the prologue's parameter homes, as with
 * func_02042D2C's seventh parameter), func_02040F84 is called with u8
 * w/h, and the two out-bytes are declared `u8 w, h;` so w lands at
 * sp+0x29 and h at sp+0x28.  The callers (func_020410D0, func_020411E8)
 * already declare the fifth parameter (ch) as u8.
 */
void func_020428E8(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u8 *dst;
    u8 w, h;
    u8 x, y;

    dst = (u8 *)s->buf;
    if (dst == 0)
        return;

    func_020422D4(s->unk_15, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                    src[sw * (sy + y) + sx + x];
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                    src[func_02040F84(sx + x, sy + y, sw, sh)];
            }
        }
    }
}

/*
 * The halfword sibling of func_020428E8: copies a cw x ch block of u16
 * source cells into a linear w-wide screen buffer at dx/dy.  mode 0 clips
 * each row and cell with u8-wrapped coordinates and skips (the source row
 * index itself is the unwrapped sy + y); any other mode clips with plain
 * int sums, stops at the first miss, and indexes the source through
 * func_02040F84.  Closed in wave 11 with the same declarations as
 * func_020428E8 (ch, sw, sh are u8 stack parameters; func_02040F84 takes
 * u8 w/h; `u8 w, h;` puts w at sp+0x1d) and the loop counters declared
 * `u8 y, x;`.
 */
void func_02042B24(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = (u16 *)s->buf;
    if (dst == 0)
        return;

    func_020422D4(s->unk_15, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[dx + x + w * (dy + y)] = src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[dx + x + w * (dy + y)] = src[func_02040F84((u8)(sx + x), (u8)(sy + y), sw, (u8)sh)];
            }
        }
    }
}

/*
 * The third of the three tilemap blitters func_02041300 dispatches to on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot.  Its two siblings are
 * src/matched/func_02042E34.c (8bpp pixel fill, tiled addressing, u8 buffer)
 * and src/matched/func_02042ED8.c (text fill, linear addressing, u16 buffer);
 * this one is func_02042ED8's three write modes over func_02042E34's tiled
 * addressing, into a u16 buffer.  Like both of those it is handed the slot's
 * sub-object (slot + 8), so the buffer pointer is at +0x00 and the
 * screen-size code at +0x15, i.e. slot +0x08 and slot +0x1d.
 *
 * The three write modes, on the seventh argument:
 *     0x11     entry = value
 *     0x10     entry = value + (entry & 0xf000)      keep the palette nibble
 *     other    entry = (u16)(value + (mode << 12))   fold the mode in
 * The third form is loop-invariant and is materialised once in the preheader.
 * func_02040EE0 is called once per cell, before the dispatch, so its result
 * has to be bound to a local; writing the call out in each arm emits it three
 * times.
 *
 * WHAT CLOSED IT (wave 2 of this family).  docs/notes/func_02042D2C.c.txt
 * recorded an 11-byte plateau at +0x10..+0x18, three mutually independent
 * prologue instructions issued in a different order:
 *     +0010  orig mov sb, r1          got ldr r7, [sp, #0x38]
 *     +0014  orig str r2, [sp]        got mov sb, r1
 *     +0018  orig ldr r7, [sp, #0x38] got str r2, [sp]
 * and concluded it was the instruction scheduler, hence unreachable from C.
 * That conclusion was wrong, and so was the premise it rested on: the note
 * argued the seventh parameter must be u32 because it arrives by `ldr` and
 * not `ldrb`.  A u8 stack argument also occupies a full word of the argument
 * area and is also loaded with `ldr`, so the load width says nothing about
 * the declared type.  Declaring
 *     u8 mode
 * instead of u32 is the whole fix, and it closes all 11 bytes at once: the
 * narrower type gives the value a different spill cost, which moves its home
 * load behind the other two prologue instructions.  Nothing else in the body
 * changed.  tools/permuter.py found it with --types (mutation
 * `type:p(mode:u32->u8)`); the earlier permute.py pass recorded in the note
 * had no type mutation and so could not reach it.
 *
 * All seven parameter types are pinned by the diff: `s` pointer, `u16 value`,
 * `u8 x0`, `u8 y0`, `u8 w`, `u8 h`, `u8 mode`.  Every other choice blows the
 * function up: value as u32 costs 157 bytes, x0 as u32 170, y0 as u32 190,
 * the helper result as u16 107.
 *
 * This unblocks src/pending/func_02041300.c (fan-in 224), which needed all
 * three blitters as `matched` witnesses and now has them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02042D2C.c \
 *       --func func_02042D2C --addr 0x02042D2C --arm --cc 1.1p1
 */
void func_02042D2C(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u8 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = (u16 *)s->buf;
    if (entries == 0) {
        return;
    }

    func_020422D4(s->unk_15, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }

            i = func_02040EE0(x, y, s->unk_15);

            if (mode == 0x11) {
                entries[i] = value;
            } else if (mode == 0x10) {
                entries[i] = value + (entries[i] & 0xf000);
            } else {
                entries[i] = (u16)(value + (mode << 12));
            }
        }
    }
}

/*
 * The 8bpp-screen fill of the three blitters func_02041300 dispatches to on
 * the bit-depth byte at +0x1c of the 0x2c-byte slot.  It takes the slot's
 * sub-object (slot + 8) rather than the slot index, so the buffer pointer is
 * at +0x00 and the screen-size code at +0x15, which are slot +0x08 and
 * +0x1d, the same two fields src/matched/func_020413B0.c reaches through the
 * table.
 *
 * Same clip-and-scan shape as func_020413B0, and the same two loop-shape
 * rules apply here: the y bound is only the `for` condition (the compiler's
 * loop-rotation entry test is the guard), and the x bound stays the
 * expression `x < x0 + w` so that it is hoisted into the outer preheader,
 * after the y guard rather than before it.  Both bounds are signed compares
 * (a sum of two u8 has type int); both clip tests against width and height
 * are unsigned, because there both sides are u8.
 *
 * The screen-size code is re-read from the object on every store, since the
 * store through the buffer pointer may alias it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042E34.c \
 *       --func func_02042E34 --addr 0x02042E34 --cc 1.1p1 --arm
 */
void func_02042E34(struct Bg *s, u8 value, u8 x0, u8 y0, u8 w, u8 h)
{
    u8  width;
    u8  height;
    u8 *pixels;
    u8  x;
    int yEnd;

    pixels = (u8 *)s->buf;
    if (pixels == 0) {
        return;
    }

    func_020422D4(s->unk_15, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            pixels[func_02040EE0(x, y0, s->unk_15)] = value;
        }
    }
}

/*
 * The text-screen fill of the three blitters func_02041300 dispatches to.
 * Like func_02042E34 it takes the slot's sub-object (slot + 8), so the
 * buffer pointer is at +0x00 and the screen-size code at +0x15, but the
 * buffer is a linear u16 screen here: the row base is `width * y`, not the
 * tiled func_02040EE0 mapping.
 *
 * The seventh argument is the write mode and decides what lands in the
 * entry: 0x11 writes the value as it stands, 0x10 keeps the existing palette
 * nibble and adds the value to it, and anything else folds the mode itself
 * into bits 12-15.  That last form is loop-invariant, so the compiler
 * materialises it once in the outer preheader (the `lsl #0x10 / lsr #0x10`
 * pair at +0x54 is the u16 narrowing of it); writing it as a local computed
 * before the nest would instead put it ahead of the y guard.
 *
 * Loop shape.  Both bounds are expressions in their own `for` condition,
 * `y < y0 + h` and `x < x0 + w`, over loop variables distinct from the two
 * origin parameters, and the row base is the subscript `entries[width * y +
 * x]` rather than a hoisted row pointer.  Every other arrangement is right
 * to within a register permutation and wrong by eleven bytes: binding either
 * bound to a local before the nest moves it ahead of the guard it belongs
 * behind and rotates the four scratch registers holding the bounds, the
 * width and the height.  The subscript form is also what puts the scaled x
 * in the base slot of the store, `strh r7, [sl, r1]` rather than
 * `[r3, sl]`.
 *
 * The mode arrives on the stack as a full word (`ldr`, not `ldrb`), so it is
 * `u32` here even though func_02041300 hands it a value that fits in a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042ED8.c \
 *       --func func_02042ED8 --addr 0x02042ED8 --cc 1.1p1 --arm
 */
void func_02042ED8(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u32 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = (u16 *)s->buf;
    if (entries == 0) {
        return;
    }

    func_020422D4(s->unk_15, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            if (mode == 0x11) {
                entries[width * y + x] = value;
            } else if (mode == 0x10) {
                entries[width * y + x] =
                    value + (entries[width * y + x] & 0xf000);
            } else {
                entries[width * y + x] = (u16)(value + (mode << 12));
            }
        }
    }
}

/*
 * Poke one tile entry into the screen buffer of table slot `idx`.  The
 * table is the 0x2c-byte-per-slot array hanging off the singleton pointer
 * at 0x02146A44 (the same one sub_020403F4 tears down): +8 is the screen
 * buffer and +0x1d the screen-size code that tells func_02040EE0 how to
 * fold (x, y) into a linear index.  A slot with no buffer is skipped.
 *
 * The three `and rN, rM, #0xff` are the truncations at the call, not casts
 * in this function's own arithmetic; func_02040EE0 takes three u8.
 */
void sub_02042FB0(u32 idx, u32 x, u32 y, u16 value)
{

    u16 *screen = (u16 *)g_02146A44->bgs[idx].buf;
    u32 code = g_02146A44->bgs[idx].unk_15;

    if (screen == 0) {
        return;
    }

    screen[(u32)func_02040EE0((u8)x, (u8)y, (u8)code)] = value;
}

/*
 * The reserve half of the pair whose release half is sub_02043094: same
 * arena selection by slot index (0..3 at +0x168, 4..7 at +0x16c, anything
 * else a no-op), same bias by the per-slot base at +0x190 and the same
 * round-up of the byte length to 32-byte units, but handed to
 * func_020341F0 instead of func_0203422C.
 *
 * Codegen note: the round-up flag must be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`; see sub_02043094.c for why the relational form
 * reschedules.
 */
void sub_02042FF8(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->unk_168,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->unk_16c,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    }
}

/*
 * Release one block back to whichever of the two arenas the slot index
 * names.  Slots 0..3 belong to the arena at +0x168 of the singleton hanging
 * off 0x02146A44, slots 4..7 to the one at +0x16c, and any other index is a
 * no-op.  The byte offset is biased by the per-slot base at +0x190 and the
 * byte length rounded up, both converted to 32-byte units before
 * func_0203422C sees them.  The index is not rebased for the second arena:
 * both arms read unk_190[idx] with the raw index.
 *
 * Codegen note: the round-up flag has to be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`, not as the relational `(size & 0x1f) != 0`.
 * Both are `tst`/`movne`/`moveq`, but the relational form is folded into
 * the argument expression and the scheduler then hoists the global load
 * above it, spilling the flag into lr; the ternary is materialised as its
 * own value first, which keeps ip free and reproduces the original order.
 */
void sub_02043094(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_0203422C(g_02146A44->unk_168,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_0203422C(g_02146A44->unk_16c,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    }
}

/*
 * Reorder an 8x8 tile in place, using one 0x40-byte scratch tile from the
 * heap the caller names in `page` (its low 15 bits, with bit 15 set).
 *
 *  - bit 0 of `flags` mirrors every 8-byte row horizontally: the scratch
 *    tile is filled with the row's bytes taken in reverse and copied back
 *    over the original, so the tile is transformed through the scratch.
 *  - bit 1 rotates the eight rows by reversing their order, one memcpy per
 *    row straight into the scratch tile, then one memcpy back.
 * `flags` is tested with `tst`/`beq`, so 0 means "nothing to do" and the
 * early `popeq` is the whole prologue.
 *
 * Shape notes:
 *  - The heap id is a u16 local, not a cast expression: the original
 *    truncates `page` to u16 *before* the mask (`lsl #0x10` /
 *    `and r0, r1, r0, lsr #16`) and truncates again after the `orr`, which
 *    only falls out of `heap = (u16)page; heap = (heap & 0x7FFF) | 0x8000;`.
 *  - Both loop counters are u8: the increments carry the `and #0xff` that
 *    an int counter does not.
 *  - The two memcpy pairs through `tmp` are what make this a three-call
 *    shape; the helper at 0x02082D44 is the project's 8-bit copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043130.c \
 *       --func func_02043130 --addr 0x02043130 --cc 1.1p1 --arm
 */
void func_02043130(u16 flags, u8 *buf, u32 page)
{
    u8 *tmp;
    u16 heap;
    u8 i;
    u8 j;

    if (flags == 0) {
        return;
    }

    heap = (u16)page;
    heap = (heap & 0x7FFF) | 0x8000;

    tmp = func_02030734(heap, 0x40, 0,
                        (const char *)func_02043130_File, 0xD48);

    if (flags & 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                tmp[i * 8 + j] = buf[i * 8 + (7 - j)];
            }
        }
        func_02082D44(buf, tmp, 0x40);
    }

    if (flags & 2) {
        for (i = 0; i < 8; i++) {
            func_02082D44(tmp + i * 8, buf + (7 - i) * 8, 8);
        }
        func_02082D44(buf, tmp, 0x40);
    }

    func_020307B0(tmp);
}

/*
 * The 16-bit member of the set / add / subtract family that sub_02043264
 * and sub_020432E4 cover for the 32-bit registers: opcodes 0..2 on the
 * halfword at +0x18.  Three comparisons rather than a table, because the
 * arms are too few to be worth one; the last arm is folded into predicated
 * `ldrheq`/`subeq`/`strheq` in the fall-through block and only the first
 * two get out-of-line bodies.
 */
void sub_02043228(struct Bg *p, u32 op, u16 value)
{
    switch (op) {
    case 0:
        p->unk_18 = value;
        break;
    case 1:
        p->unk_18 = p->unk_18 + value;
        break;
    case 2:
        p->unk_18 = p->unk_18 - value;
        break;
    }
}

/*
 * Apply one of three operations (set / add / subtract) to one of two
 * 32-bit scroll registers of the object, at +0x1c and +0x20, selected by
 * the opcode in r1.  Opcodes 0..2 are live case labels with empty bodies:
 * they are what makes the dispatch table start at zero and therefore what
 * makes it exist at all
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Their table
 * slots hold a bare `bx lr` rather than a branch, same as the out-of-range
 * default.
 *
 * The companion sub_020432E4 handles opcodes 9..14 on the two registers
 * at +0x24 and +0x28; nothing in this packet covers 15 and above.
 */
void sub_02043264(struct Bg *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        p->unk_1c = value;
        break;
    case 4:
        p->unk_1c = p->unk_1c + value;
        break;
    case 5:
        p->unk_1c = p->unk_1c - value;
        break;
    case 6:
        p->unk_20 = value;
        break;
    case 7:
        p->unk_20 = p->unk_20 + value;
        break;
    case 8:
        p->unk_20 = p->unk_20 - value;
        break;
    }
}
