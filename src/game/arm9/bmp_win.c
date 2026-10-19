/*
 * file:     bmp_win.c
 * unit:     yes
 * function: BMP_WIN_Init, BMP_WIN_Exit, BMP_WIN_Create, BMP_WIN_CreateAt, BMP_WIN_Alloc, BMP_WIN_Delete, BMP_WIN_TransferChars, BMP_WIN_MakeScreen, BMP_WIN_DrawFrame, BMP_WIN_ClearScreen, BMP_WIN_GetBgLayer, BMP_WIN_GetWidth, BMP_WIN_GetHeight, BMP_WIN_GetDispWidth, BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset, BMP_WIN_GetBmp, BMP_WIN_GetPalette, BMP_WIN_SetPosX, BMP_WIN_SetPosY, BMP_WIN_SetDispHeight, BMP_WIN_SetPalette
 * address:  0x02045088
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from bmp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sBmpWinHeapRecord     0x02146A50  data
 *   bmpWin_File   0x020A7E70  data
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   BG_SYS_ReserveTileRun  0x0203FAF0  arm
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   BG_SYS_GetField17  0x020416B8  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   BG_SYS_GetType  0x02041680  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_Create 0x02043678 arm arm9
 *   BMP_Delete 0x020437AC arm arm9
 *   BMP_GetPixels 0x020437D4 arm arm9
 */
#include "bmp_shared_types.h"

struct BmpWin;

#define BMP_WIN_MAGIC 0x7fb2

/*
 * A bitmap window: a rectangle of a BG layer backed by a Bmp.  One object
 * for every view the accessors and the constructors take.
 */
struct BmpWin {
    u16 magic : 15;          /* +0x00, BMP_WIN_MAGIC while live */
    u16 is8bpp : 1;          /*        BG layer uses 8bpp characters */
    u8  bgLayer;             /* +0x02 */
    u8  posX;                /* +0x03, in tiles */
    u8  posY;                /* +0x04 */
    u8  width;               /* +0x05, in tiles */
    u8  height;              /* +0x06 */
    u8  dispWidth;           /* +0x07, on-screen extent, starts equal to width */
    u8  dispHeight;          /* +0x08, starts equal to height */
    u8  palette;             /* +0x09 */
    u16 charOffset;          /* +0x0a, first character number in BG VRAM */
    struct Bmp *bmp;         /* +0x0c */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern u8 BG_SYS_GetField16(int channel);

extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);

extern u32 BG_SYS_ReserveTileRun(u32 layer, u32 offset, u32 units);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern u8 BG_SYS_GetField17(int channel);

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

extern u8 BG_SYS_GetType(int channel);

extern void BG_SYS_DrawTileEx(u32 index, u32 dx, u32 dy, u32 cw, u8 ch, u32 src, u8 sx, u8 sy, u8 sw, u8 sh);

extern void BG_SYS_SetTileEntry(u32 index, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 m);

struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);

void BMP_Delete(struct Bmp *bmp);

void *BMP_GetPixels(const struct Bmp *bmp);

void BMP_WIN_Init(u16 heapId);

void BMP_WIN_Exit(void);

struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);

struct BmpWin *BMP_WIN_CreateAt(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset);

struct BmpWin *BMP_WIN_Alloc(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset, u8 is8bpp);

u32 BMP_WIN_Delete(struct BmpWin *win);

void BMP_WIN_TransferChars(struct BmpWin *win);

void BMP_WIN_MakeScreen(struct BmpWin *win);

void BMP_WIN_DrawFrame(struct BmpWin *win, u16 baseTile, u32 palette);

void BMP_WIN_ClearScreen(struct BmpWin *win);

u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

u8 BMP_WIN_GetWidth(struct BmpWin *win);

u8 BMP_WIN_GetHeight(struct BmpWin *win);

u8 BMP_WIN_GetDispWidth(struct BmpWin *win);

u8 BMP_WIN_GetDispHeight(struct BmpWin *win);

u8 BMP_WIN_GetPosX(struct BmpWin *win);

u8 BMP_WIN_GetPosY(struct BmpWin *win);

u16 BMP_WIN_GetCharOffset(struct BmpWin *win);

struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

u8 BMP_WIN_GetPalette(struct BmpWin *win);

void BMP_WIN_SetPosX(struct BmpWin *win, u8 posX);

void BMP_WIN_SetPosY(struct BmpWin *win, u8 posY);

void BMP_WIN_SetDispHeight(struct BmpWin *win, u8 dispHeight);

void BMP_WIN_SetPalette(struct BmpWin *win, u8 palette);

extern u16 *sBmpWinHeapRecord;      /* 4-byte block, first halfword = the heap id */

extern const char bmpWin_File[];    /* "bmp_win.c" */

/*
 * The one-time init of the BG subsystem's heap record.  Four bytes are
 * allocated on the heap the caller names, the pointer is published in the
 * global at 0x02146A50, and the heap id itself is written back into the
 * first halfword of the block.  Every later allocation in this family reads
 * that halfword back out (see src/matched/BMP_WIN_MakeScreen.c, which spells it
 * (*sBmpWinHeapRecord & 0x7fff) | 0x8000), so the block is the subsystem's record
 * of which heap it owns.
 *
 * The allocator's fourth and fifth arguments are the same debug site string
 * and tag pair used everywhere else in this file; here the tag is 0x4f.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Init.c \
 *       --func BMP_WIN_Init --addr 0x02045088 --cc 1.1p1 --arm
 */
void BMP_WIN_Init(u16 heapId)
{
    u16 *heapRecord = GFL_HEAP_Alloc(heapId, 4, 0, bmpWin_File, 0x4f);

    sBmpWinHeapRecord = heapRecord;
    *heapRecord = heapId;
}

/*
 * The teardown that pairs with BMP_WIN_Init: free the four-byte heap record
 * published at 0x02146A50 and clear the pointer, doing nothing if it was
 * never allocated.  The idempotent shape (test, free, null out) is why the
 * global is read once into a callee-saved register and stored back through
 * the same register rather than re-loaded from the pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Exit.c \
 *       --func BMP_WIN_Exit --addr 0x020450C8 --cc 1.1p1 --arm
 */
void BMP_WIN_Exit(void)
{
    if (sBmpWinHeapRecord == 0)
        return;

    GFL_HEAP_Free(sBmpWinHeapRecord);
    sBmpWinHeapRecord = 0;
}

/*
 * Set up a BG layer whose character data is placed at a VRAM offset chosen
 * by the allocator.  BG_SYS_GetField16 says whether the layer is 8bpp; that
 * decides both the flag handed to BMP_WIN_Alloc and whether a cell costs one
 * or two units, and the unit count is scaled by 32 to bytes before
 * BG_SYS_CreateRun is asked for room.  A returned -1 (not 0) is the allocator's
 * failure answer, and the function reports failure as 0.
 *
 * BMP_WIN_CreateAt, the next function, is the same routine for the case where
 * the caller already knows the offset: it calls BG_SYS_ReserveTileRun to reserve
 * that exact offset instead, passes a count rather than a byte size, and
 * forwards the caller's offset straight through as BMP_WIN_Alloc's seventh
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Create.c \
 *       --func BMP_WIN_Create --addr 0x020450F0 --cc 1.1p1 --arm
 */
struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir)
{
    u8 is8bpp;
    u32 charCount;
    s32 offset;

    if (BG_SYS_GetField16(bgLayer) == 0) {
        is8bpp = 0;
        charCount = width * height;
    } else {
        is8bpp = 1;
        charCount = width * height * 2;
    }

    offset = BG_SYS_CreateRun(bgLayer, charCount * 32, allocDir);
    if (offset == -1)
        return 0;

    return BMP_WIN_Alloc(bgLayer, posX, posY, width, height, palette, offset, is8bpp);
}

/*
 * closed:   blocker BG_SYS_ReserveTileRun is now a manifest entry (matched class)
 *
 * Every concrete byte is right; the file is capped at MATCH by one
 * relocation site, the bl to BG_SYS_ReserveTileRun at +0x44.  Blocking evidence
 * class: none available.  0x0203FAF0 has exactly one witness image wide and
 * it is the call inside this very function (--suggest-split reports "the
 * whole range as one file is NOT viable", best partition 0 pieces), so no
 * cut of this range can attest it.  It unsticks the moment either
 * 0x0203FAF0 itself is taken EXACT (the `matched` class) or a second caller
 * of it turns up in another packet.
 *
 * The fixed-offset twin of BMP_WIN_Create: the caller already knows where the
 * layer's character data goes, so BG_SYS_ReserveTileRun is asked to reserve that
 * offset (answering 0 on failure, not -1), the cell count is passed in units
 * rather than scaled to bytes, and the caller's own offset is what reaches
 * BMP_WIN_Alloc as the seventh argument.
 *
 * The 8bpp test and the doubling of the unit count are identical to
 * BMP_WIN_Create; only the missing `lsl #5` and the different failure
 * convention separate the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_CreateAt.c \
 *       --func BMP_WIN_CreateAt --addr 0x02045180 --cc 1.1p1 --arm
 */
struct BmpWin *BMP_WIN_CreateAt(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset)
{
    u8 is8bpp;
    u32 charCount;

    if (BG_SYS_GetField16(bgLayer) == 0) {
        is8bpp = 0;
        charCount = width * height;
    } else {
        is8bpp = 1;
        charCount = width * height * 2;
    }

    if (BG_SYS_ReserveTileRun(bgLayer, charOffset, charCount) == 0)
        return 0;

    return BMP_WIN_Alloc(bgLayer, posX, posY, width, height, palette, charOffset, is8bpp);
}

/*
 * The constructor shared by BMP_WIN_Create and BMP_WIN_CreateAt: build the
 * sixteen-byte descriptor for one BG layer on the subsystem heap recorded by
 * BMP_WIN_Init, fill in its geometry, and attach the tile buffer
 * BMP_Create hands back.
 *
 *   +0x00  u16  two bitfields: a 15-bit tag set to 0x7fb2, and the 8bpp
 *               flag in bit 15
 *   +0x02  u8   layer
 *   +0x03  u8   screen base
 *   +0x04  u8   character base
 *   +0x05  u8   width in tiles       (also at +0x07)
 *   +0x06  u8   height in tiles      (also at +0x08)
 *   +0x09  u8   palette
 *   +0x0a  u16  character offset in VRAM
 *   +0x0c  void *tile buffer
 *
 * The tag is one 15-bit field, not two adjacent fields of 8 and 7 bits:
 * splitting it produces two read-modify-writes (bic #0xff / orr #0xb2 then
 * bic #0x7f00 / orr #0x7f00) instead of the single masked write the original
 * has, where the constant 0x7fb2 needs two `orr`s only because it is not one
 * ARM immediate.  The 8bpp bit is a second read-modify-write because its
 * assignment is separated from the tag by the byte stores.
 *
 * The width parameter is u8, not u32: assigning a u32 to the two u8 width
 * fields makes the compiler materialise `(u8)width` once with `and #0xff`
 * and store that register twice, where the original stores the incoming
 * register directly.  Same for the width argument of BMP_Create.
 *
 * The 0xffff8000 mask is materialised as `sub r0, fp, #0x8000` off the
 * register already holding the allocator's zero third argument, the
 * rematerialisation idiom in
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Alloc.c \
 *       --func BMP_WIN_Alloc --addr 0x02045210 --cc 1.1p1 --arm
 */
struct BmpWin *BMP_WIN_Alloc(u32 bgLayer, u32 posX, u32 posY,
                             u8 width, u8 height, u8 palette, u32 charOffset,
                             u8 is8bpp)
{
    struct BmpWin *win;
    u32 tileBytes = is8bpp == 0 ? BMP_TILE_BYTES_4BPP : BMP_TILE_BYTES_8BPP;

    win = GFL_HEAP_Alloc(*sBmpWinHeapRecord, 0x10, 0, bmpWin_File, 0xd5);

    win->magic = BMP_WIN_MAGIC;
    win->bgLayer = bgLayer;
    win->posX = posX;
    win->posY = posY;
    win->width = width;
    win->height = height;
    win->dispWidth = width;
    win->dispHeight = height;
    win->palette = palette;
    win->charOffset = charOffset;
    win->is8bpp = is8bpp;

    win->bmp = BMP_Create(width, height, tileBytes, *sBmpWinHeapRecord);
    return win;
}

/*
 * The descriptor family's destructor: release the payload through
 * BG_SYS_DeleteHalf, release the heap handle through BMP_Delete, then free
 * the descriptor itself with the generic free at 0x020307B0 (the same
 * free STRBUF_Delete tail-calls).
 *
 * The payload size is (win->width * win->height) * 32, doubled when the top bit
 * of the halfword at +0 is set. That bit is a 1-wide bitfield, not a
 * mask: `ldrh` followed by `lsl #16` / `lsrs #31` is the bitfield extract
 * shape (shift the field to the top, then all the way down by 32 minus
 * its width), and a plain `win->is8bpp` mask test folds to a single
 * `tst`. Declaring the halfword as a 15-bit field plus a 1-bit field is
 * what reproduces it.
 *
 * Both arms of the doubling compute the u8 * u8 product themselves, which
 * is why `smulbb` appears twice under opposite predicates rather than
 * once before the test. Writing the shared multiply above the `if` and
 * only the doubling inside it produces one unconditional `smulbb` and a
 * different register assignment throughout; this is
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md seen from
 * the entry side.
 *
 * The whole conditional is predicated, so there is no branch at all: the
 * `s` suffix on the `lsrs` is the test, and the three following
 * instructions carry `eq`/`ne`. Because there is no branch, the only
 * thing that fixes their order is source order: the `eq` arm is emitted
 * first, so the undoubled case has to be written as the `if` and the
 * doubled case as the `else`, even though `if (bit) double` reads more
 * naturally (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Delete.c \
 *       --func BMP_WIN_Delete --addr 0x020452E8 --cc 1.1p1 --arm
 */
u32 BMP_WIN_Delete(struct BmpWin *win)
{
    u32 charCount;

    if (win->is8bpp == 0) {
        charCount = win->width * win->height;
    } else {
        charCount = (win->width * win->height) * 2;
    }
    BG_SYS_DeleteHalf(win->bgLayer, win->charOffset, charCount * 32);
    BMP_Delete(win->bmp);
    return GFL_HEAP_Free(win);
}

/*
 * One of the descriptor family's two teardown/commit paths (the other is
 * BMP_WIN_Delete immediately before it). It sizes the descriptor's payload
 * as
 *
 *   BG_SYS_GetField17(win->bgLayer) * (win->width * win->height)
 *
 * and passes that, the heap handle obtained from d->heap via
 * BMP_GetPixels, and win->charOffset on to BG_SYS_LoadTileData.
 *
 * The u8 * u8 product compiles to `smulbb`, not `mul`: the compiler knows
 * both operands came from `ldrb` and fit in sixteen bits, so it uses the
 * halfword multiply. The second multiply, against a call result of
 * unknown range, has to be a full `mul`.
 *
 * The product is computed before the BMP_GetPixels call and so has to
 * survive it, which is what buys the callee-saved r4 and turns
 * push {r4, lr} into push {r3, r4, r5, lr}: r5 holds the descriptor
 * pointer across all three calls and r3 is the alignment filler.
 *
 * win->bgLayer is loaded twice, once for each call that takes it, rather than
 * kept in a register: re-reading the field is cheaper than spending a
 * third callee-saved register on it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_TransferChars.c \
 *       --func BMP_WIN_TransferChars --addr 0x02045334 --cc 1.1p1 --arm
 */
void BMP_WIN_TransferChars(struct BmpWin *win)
{
    u32 byteCount;

    byteCount = (win->width * win->height) * BG_SYS_GetField17(win->bgLayer);
    BG_SYS_LoadTileData(win->bgLayer, BMP_GetPixels(win->bmp), byteCount, win->charOffset);
}

/*
 * Fill a rectangle of the screen described by the configuration block with
 * a run of consecutive tile numbers.  BG_SYS_GetType says whether the layer
 * is 8bpp (answer 1, one byte per cell) or 16bpp (two bytes per cell, each
 * carrying the palette number from +9 in its top nibble); either way a
 * scratch buffer of w*h cells is allocated from the heap named by the word
 * behind 0x02146A50, filled with an increasing counter seeded from +0xa,
 * handed to BG_SYS_DrawTileEx and freed again.
 *
 * The palette nibble is hoisted as `lsl r4, r2, #0x1c` before the branch
 * and consumed as `orr r2, r5, r4, lsr #16` inside the loop: that is one
 * `(x & 0xf) << 12`, split so that only the cheap half stays in the loop,
 * not two separate shifts.
 *
 * The two allocation sites carry different line numbers, 0x133 and 0x13e,
 * and that is load-bearing: give both the same constant and the compiler
 * hoists the single pool load above the branch, which costs one
 * instruction, one pool word and shifts every later pc-relative offset.
 * Eleven source lines apart matches the two arms of one if/else.
 */
void BMP_WIN_MakeScreen(struct BmpWin *win)
{
    u16 charCount = win->width * win->height;
    u32 paletteBits = (win->palette & 0xf) << 12;
    u16 tile = win->charOffset;
    void *cells;
    s32 index;

    if (BG_SYS_GetType(win->bgLayer) != 1) {
        u16 *chars = GFL_HEAP_Alloc((u16)((*sBmpWinHeapRecord & 0x7fff) | 0x8000),
                               charCount * 2, 0, bmpWin_File, 0x133);

        cells = chars;
        for (index = 0; index < charCount; index++) {
            chars[index] = tile | paletteBits;
            tile = tile + 1;
        }
    } else {
        u8 *chars = GFL_HEAP_Alloc((u16)((*sBmpWinHeapRecord & 0x7fff) | 0x8000),
                              charCount, 0, bmpWin_File, 0x13e);

        cells = chars;
        for (index = 0; index < charCount; index++) {
            chars[index] = (u8)tile;
            tile = tile + 1;
        }
    }

    BG_SYS_DrawTileEx(win->bgLayer, win->posX, win->posY, win->dispWidth,
                  win->dispHeight, (u32)cells, 0, 0, win->width, win->height);
    GFL_HEAP_Free(cells);
}

/*
 * The eight-piece frame around a window: base tile + 0..7 drawn at the
 * corners and edges one cell outside the on-screen extent (+7/+8), with the
 * palette nibble in the top of each cell unless the layer is 8bpp
 * (BG_SYS_GetType answers 1).
 *
 * Closed in wave 15 from a 2-byte residue (`mov r6, r2` against `mov r4,
 * r2`, the image gives pal and the palette bits one register).  Two facts,
 * each flat alone: the palette bits are computed IN PLACE in the pal
 * parameter as two compound statements (`pal &= 0xf; pal <<= 12;`), which
 * is what coalesces pal with its shifted value; and base is a u16
 * parameter (tile number), which restores the image's scheduling of the
 * sixth and seventh calls that the in-place form otherwise disturbs.  A
 * single-expression `pal = (pal & 0xf) << 12` or a separate pn local keeps
 * the 2-byte tie.  Found by tools/permuter.py hill (type:p base u32->u16)
 * from the in-place source.
 */
void BMP_WIN_DrawFrame(struct BmpWin *win, u16 baseTile, u32 palette)
{
    if (BG_SYS_GetType(win->bgLayer) != 1) {
        palette &= 0xf;
        palette <<= 12;
    } else {
        palette = 0;
    }

    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | baseTile), (u8)(win->posX - 1),
                  (u8)(win->posY - 1), 1, 1, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 1)), win->posX,
                  (u8)(win->posY - 1), win->dispWidth, 1, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 2)),
                  (u8)(win->posX + win->dispWidth), (u8)(win->posY - 1),
                  1, 1, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 3)),
                  (u8)(win->posX - 1), win->posY, 1, win->dispHeight, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 4)),
                  (u8)(win->posX + win->dispWidth), win->posY,
                  1, win->dispHeight, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 5)),
                  (u8)(win->posX - 1), (u8)(win->posY + win->dispHeight),
                  1, 1, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 6)), win->posX,
                  (u8)(win->posY + win->dispHeight), win->dispWidth, 1, 0x11);
    BG_SYS_SetTileEntry(win->bgLayer, (u16)(palette | (baseTile + 7)),
                  (u8)(win->posX + win->dispWidth),
                  (u8)(win->posY + win->dispHeight), 1, 1, 0x11);
}

/*
 * A seven-argument forwarder over the descriptor object whose leaf
 * accessor bank is src/matched/unit_02045730.c: it unpacks six u8 fields
 * and a constant zero out of the descriptor and hands them to
 * BG_SYS_SetTileEntry, which is where the actual work happens.
 *
 *   BG_SYS_SetTileEntry(win->bgLayer, 0, win->posX, win->posY, win->width, win->height, 0)
 *
 * Register arguments are r0..r3, and the remaining three ride the 12-byte
 * stack frame the prologue carves out with `sub sp, sp, #0xc`. The
 * compiler spots that the last two stack slots are adjacent and writes
 * win->width (already in r0) and the zero (already in r1) with a single
 * `stmib sp, {r0, r1}` rather than two stores, which is what makes the
 * second and third stack argument order legible: had the zero been
 * anywhere but last, the store pair would not have fused.
 *
 * The single-register prologue is `stmdb sp!, {lr}` / `ldm sp!, {pc}`
 * rather than push/pop of a pair, because nothing here needs a
 * callee-saved register: every field load feeds its argument slot
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_ClearScreen.c \
 *       --func BMP_WIN_ClearScreen --addr 0x020456F8 --cc 1.1p1 --arm
 */
void BMP_WIN_ClearScreen(struct BmpWin *win)
{
    BG_SYS_SetTileEntry(win->bgLayer, 0, win->posX, win->posY, win->width, win->height, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset,
 *           BMP_WIN_GetBmp, BMP_WIN_GetPalette, BMP_WIN_SetPosX, BMP_WIN_SetPosY,
 *           BMP_WIN_SetDispHeight, BMP_WIN_SetPalette
 *
 * The leaf accessor bank of the allocator family's descriptor object.
 * Fourteen relocation-free 8-byte functions in a row, each one load or
 * store of a single field, which is why they can be folded into one unit
 * with no witnesses required at all.
 *
 * The descriptor they read is the argument block the surrounding
 * constructors carry around (BMP_WIN_TransferChars, at the head of this packet,
 * uses the same offsets: +2, +5, +6, +0xa, +0xc). The fields this bank
 * exposes:
 *
 *   +0x02  u8   BMP_WIN_GetBgLayer get
 *   +0x03  u8   BMP_WIN_GetPosX get / BMP_WIN_SetPosX set
 *   +0x04  u8   BMP_WIN_GetPosY get / BMP_WIN_SetPosY set
 *   +0x05  u8   BMP_WIN_GetWidth get
 *   +0x06  u8   BMP_WIN_GetHeight get
 *   +0x07  u8   BMP_WIN_GetDispWidth get
 *   +0x08  u8   BMP_WIN_GetDispHeight get / BMP_WIN_SetDispHeight set
 *   +0x09  u8   BMP_WIN_GetPalette get / BMP_WIN_SetPalette set
 *   +0x0a  u16  BMP_WIN_GetCharOffset get
 *   +0x0c  void *  BMP_WIN_GetBmp get
 *
 * BMP_WIN_GetBmp is the heap-handle getter of this family: the pointer it
 * returns at +0xc is what BMP_WIN_TransferChars feeds to BMP_GetPixels before the
 * allocation call at 0x02040B1C, so +0xc is the descriptor's heap /
 * owning-context handle rather than a payload pointer. It carries the
 * largest fan-in of the whole bank (1149 branch references image-wide),
 * which is consistent with every user of a descriptor reaching for its
 * heap handle.
 *
 * Only BMP_WIN_GetBgLayer, BMP_WIN_GetWidth, BMP_WIN_GetHeight, BMP_WIN_GetDispWidth,
 * BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset, BMP_WIN_GetBmp,
 * BMP_WIN_GetPalette and BMP_WIN_SetPalette carry labels in the listing.
 * BMP_WIN_SetPosX, BMP_WIN_SetPosY and BMP_WIN_SetDispHeight are unlabelled followers:
 * they save no lr, so disasm.py folds them into BMP_WIN_GetPalette's extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). They
 * should be seeded into layout/function_starts.txt by the integrator.
 *
 * Field names are left descriptive rather than semantic: this whole
 * family is scheduled for a semantic rename once the allocator's argument
 * shapes settle.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045730.c \
 *       --addr 0x02045730 --arm --cc 1.1p1
 */
u8 BMP_WIN_GetBgLayer(struct BmpWin *win)
{
    return win->bgLayer;
}

u8 BMP_WIN_GetWidth(struct BmpWin *win)
{
    return win->width;
}

u8 BMP_WIN_GetHeight(struct BmpWin *win)
{
    return win->height;
}

u8 BMP_WIN_GetDispWidth(struct BmpWin *win)
{
    return win->dispWidth;
}

u8 BMP_WIN_GetDispHeight(struct BmpWin *win)
{
    return win->dispHeight;
}

u8 BMP_WIN_GetPosX(struct BmpWin *win)
{
    return win->posX;
}

u8 BMP_WIN_GetPosY(struct BmpWin *win)
{
    return win->posY;
}

u16 BMP_WIN_GetCharOffset(struct BmpWin *win)
{
    return win->charOffset;
}

struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win)
{
    return win->bmp;
}

u8 BMP_WIN_GetPalette(struct BmpWin *win)
{
    return win->palette;
}

void BMP_WIN_SetPosX(struct BmpWin *win, u8 posX)
{
    win->posX = posX;
}

void BMP_WIN_SetPosY(struct BmpWin *win, u8 posY)
{
    win->posY = posY;
}

void BMP_WIN_SetDispHeight(struct BmpWin *win, u8 dispHeight)
{
    win->dispHeight = dispHeight;
}

void BMP_WIN_SetPalette(struct BmpWin *win, u8 palette)
{
    win->palette = palette;
}
