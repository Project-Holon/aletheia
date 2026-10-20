/*
 * file:     bmp_menuwork.c
 * unit:     yes
 * function: BMP_MENUWORK_GetCharFileId, BMP_MENUWORK_GetPlttFileId, BMP_MENUWORK_LoadChar, BMP_MENUWORK_LoadPltt, BMP_MENUWORK_LoadCharAndPltt, BMP_MENUWORK_LoadFrameGfx, BMP_MENUWORK_FreeTileRun, BMP_MENUWORK_DrawFrame, BMP_MENUWORK_DrawWindow, BMP_MENUWORK_DrawWindowEx, BMP_MENUWORK_DrawWindowBorder, BMP_MENUWORK_Create, BMP_MENUWORK_Delete, BMP_MENUWORK_AddMsgItem, BMP_MENUWORK_AddStrItem, BMP_MENUWORK_FindFreeEntry, BMP_MENUWORK_ReleaseItems, BMP_MENUWORK_CountItems
 * address:  0x0201F53C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bmp_menu.c by tools/splitfile.py.
 *
 * symbols:
 *   sub_0209E8C8_Map  0x0209E8C8  data
 *   sub_0209E8CA_Map  0x0209E8CA  data  a1
 *   BG_SYS_FreeTileRun  0x0203FB44  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   GFL_HEAP_Alloc        0x02030734  arm
 *   sBmpMenuWorkFile     0x020A7374  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Clone  0x02045874  arm
 *   STRBUF_Delete  0x02045808  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   ARC_UTIL_RegisterObjCharFromArchive  0x020496E4  arm
 *   ARC_UTIL_UploadBgCharFromArchive 0x02049624  arm
 */
#include "bmp_menuwork_shared_types.h"

struct U16Vec;

extern void ARC_UTIL_UploadBgCharFromArchive(u32 arcId, u32 fileId, u32 layer, u32 tileOffset, u32 flagA, u32 flagB, u32 heapId);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 archiveID, u32 memberIdx, u32 kind, u32 dest, u32 size, u16 flags);

extern u32 ARC_UTIL_RegisterObjCharFromArchive(u32 archiveID, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);

extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);

extern void BG_SYS_SetTileEntry(u32 bgId, u32 tile, u8 x, u8 y, u8 width, u8 height,
                          u32 palette);

#include "bmp_win.h"





extern void BG_SYS_PushTile(u32 index);

extern void BG_SYS_MarkTileDirty(u32 bit);

#include "gfl_heap_wrap.h"

struct MsgBank;
struct Strbuf;

#include "msgdata.h"

#include "strbuf.h"


u8 BMP_MENUWORK_GetCharFileId(int index);

u8 BMP_MENUWORK_GetPlttFileId(int index);

void BMP_MENUWORK_LoadChar(u32 layer, u32 tileOffset, u32 frameId, u32 heapId);

void BMP_MENUWORK_LoadPltt(u32 layer, u32 palSlot, u32 frameId, u16 heapId);

void BMP_MENUWORK_LoadCharAndPltt(u32 layer, u32 tileOffset, u32 palSlot, u32 frameId, u16 heapId);

void *BMP_MENUWORK_LoadFrameGfx(u32 layer, u32 palSlot, u32 frameId, u16 heapId);

void BMP_MENUWORK_FreeTileRun(int layer, u32 packedOffsets);

void BMP_MENUWORK_DrawFrame(u16 bgId, u8 x, u8 y, u8 width, u8 height, u32 palette, u16 tileBase);

void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int commitMode, u16 tileBase, u32 palette);

void BMP_MENUWORK_DrawWindowEx(struct BmpWin *desc, u32 commitMode, u32 tileBase, u32 palette);

void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, u32 commitMode);

BmpMenuWork *BMP_MENUWORK_Create(u32 count, u32 heapId);

u32 BMP_MENUWORK_Delete(void *items);

void BMP_MENUWORK_AddMsgItem(BmpMenuWork *items, struct MsgBank *bank, u32 msgId, u32 param, u32 heapId);

void BMP_MENUWORK_AddStrItem(BmpMenuWork *items, const struct U16Vec *src, u32 param, u32 heapId);

BmpMenuWork *BMP_MENUWORK_FindFreeEntry(BmpMenuWork *items, u32 *outTerminatorValue);

void BMP_MENUWORK_ReleaseItems(BmpMenuWork *items);

u32 BMP_MENUWORK_CountItems(BmpMenuWork *items);

extern u8 sub_0209E8C8_Map[];

extern u8 sub_0209E8CA_Map[];

extern char sBmpMenuWorkFile[];

u8 BMP_MENUWORK_GetCharFileId(int index)
{
    return sub_0209E8C8_Map[index];
}

/*
 * Promoted from src/pending/BMP_MENUWORK_GetPlttFileId.c on 2026-09-22 (family wave 5,
 * wordset.c).  Every concrete byte was already reproduced; only the one
 * relocation was open.
 *
 * The second of the two three-instruction byte-table lookups behind
 * src/matched/unit_0201F554.c -- BMP_MENUWORK_GetCharFileId reads the table at 0x0209E8C8
 * and this one the table at 0x0209E8CA, two bytes further on.  Both are
 * `return table[i];` and nothing else.
 *
 * WHAT CHANGED.  The blocker was the ABS32 against 0x0209E8CA.  Its only
 * literal-pool referrer anywhere in the image is the word at 0x0201F550
 * inside this very function (layout/data_objects.txt), which every
 * second-referrer class discards as lying inside the range under test, and
 * 0x0209E8CA is interior to the datum the listings start at 0x0209E8C8, so
 * `sole-ref/data` refuses it as not-a-start.  It is now carried by
 * `sole-ref/self`: the target is in a data section and the ROM word at the
 * relocation site already names exactly the address the relocation writes
 * there, which is the whole of that sub-kind's evidence.  The sibling
 * BMP_MENUWORK_GetCharFileId reaches EXACT by the stronger `sole-ref/data` instead,
 * because 0x0209E8C8 IS the datum start.
 *
 * Addresses are Black-image addresses.  The table's contents are a glyph
 * index map and are content data, not code shape; if it is ever sized
 * differently between Black and White that is a data-layout question, not a
 * code one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_GetPlttFileId.c \
 *       --func BMP_MENUWORK_GetPlttFileId --addr 0x0201F548 --cc 1.1p1 --thumb
 */
u8 BMP_MENUWORK_GetPlttFileId(int index)
{
    return sub_0209E8CA_Map[index];
}

/*
 * Two font-drawing wrappers, each turning a small id into a glyph-table index
 * through one of the two byte tables just before them and handing it to a
 * seven- and a six-argument SDK-style entry point.  The two table lookups are
 * BMP_MENUWORK_GetCharFileId and BMP_MENUWORK_GetPlttFileId, which are parked in
 * src/pending/BMP_MENUWORK_GetCharFileId.c because their tables have no outside witness;
 * the calls to them are ordinary `label` sites here, since BMP_MENUWORK_GetCharFileId is
 * also called from 0x0201F5EA outside this range and BMP_MENUWORK_GetPlttFileId from ten
 * overlays.
 *
 * BMP_MENUWORK_LoadPltt hoists the lookup above the `if`, so the source binds it to a
 * local once rather than calling it in both arms; written in both arms the
 * compiler emits the call twice.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F554.c  *       --addr 0x0201F554 --thumb
 */
void BMP_MENUWORK_LoadChar(u32 layer, u32 tileOffset, u32 frameId, u32 heapId)
{
    ARC_UTIL_UploadBgCharFromArchive(5, BMP_MENUWORK_GetCharFileId(frameId), layer, tileOffset, 0, 0, heapId);
}

void BMP_MENUWORK_LoadPltt(u32 layer, u32 palSlot, u32 frameId, u16 heapId)
{
    u32 palFileId = BMP_MENUWORK_GetPlttFileId(frameId);

    if (layer < 4) {
        ARC_UTIL_UploadPaletteFromArchiveWhole(5, palFileId, 0, palSlot * 32, 0x20, heapId);
    } else {
        ARC_UTIL_UploadPaletteFromArchiveWhole(5, palFileId, 4, palSlot * 32, 0x20, heapId);
    }
}

/*
 * Forwards one five-argument call to two four-argument workers, dropping the
 * second argument from the first call and the third from the second.  The
 * fifth argument arrives on the caller's stack and is re-read with `ldrh`
 * through a cached frame pointer (r7 = sp + 0x18) both times, once per call,
 * which is what fixes it as u16 rather than a word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_LoadCharAndPltt.c \
 *       --func BMP_MENUWORK_LoadCharAndPltt --addr 0x0201F5BC --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_LoadCharAndPltt(u32 layer, u32 tileOffset, u32 palSlot, u32 frameId, u16 heapId)
{
    BMP_MENUWORK_LoadChar(layer, tileOffset, frameId, heapId);
    BMP_MENUWORK_LoadPltt(layer, palSlot, frameId, heapId);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_LoadFrameGfx.c \
 *       --func BMP_MENUWORK_LoadFrameGfx --addr 0x0201F5DC --cc 1.1p1 --thumb
 */
void *BMP_MENUWORK_LoadFrameGfx(u32 layer, u32 palSlot, u32 frameId, u16 heapId)
{
    void *charResult = (void *)ARC_UTIL_RegisterObjCharFromArchive(5, BMP_MENUWORK_GetCharFileId(frameId), layer, 0, 0, heapId);

    BMP_MENUWORK_LoadPltt(layer, palSlot, frameId, heapId);
    return charResult;
}

void BMP_MENUWORK_FreeTileRun(int layer, u32 packedOffsets)
{
    BG_SYS_FreeTileRun(layer, (u16)packedOffsets, (u16)(packedOffsets >> 16));
}

/*
 * A nine-slice window frame draw, the worker behind BMP_MENUWORK_DrawWindow
 * (src/matched/BMP_MENUWORK_DrawWindow.c).  Eight calls to BG_SYS_SetTileEntry place tiles
 * base+0, +1, +2, +3, +5, +6, +7, +8 around the rectangle (x, y, w, h); the
 * centre tile base+4 is never emitted, which is why the sequence skips 4.
 * The four corners are 1x1, the top and bottom edges are w x 1, the left and
 * right edges are 1 x h, and every call carries the same palette word.
 *
 * SIGNATURE, pinned by the load widths.  The fifth argument is re-read with
 * `ldrb` from its home slot at sp+0x38 and the sixth with `ldr` from sp+0x3c,
 * so `h` is a byte and `pal` a full word; the seventh is read with `ldrh`
 * from sp+0x40, so `base` is u16.  Declaring `pal` as u8 costs fourteen bytes
 * (262 instead of 276).
 *
 * THREE LEVERS, the last of which closed it:
 *
 *  - **BG_SYS_SetTileEntry's second and third parameters are declared u8 here**,
 *    not u32 as src/pending/BG_SYS_SetTileEntry.c declares them.  With u32 the
 *    truncation of `x - 1` becomes a source-level expression, mwccarm CSEs
 *    the whole `(u8)(x - 1)` and spills the truncated byte to a stack slot;
 *    the image keeps the untruncated `x - 1` in r7 and re-runs the
 *    `lsls #24 / lsrs #24` pair at each of its four uses, which is the
 *    argument-conversion form.  That change alone moves the residue from 228
 *    bytes to 86.  Same tell as
 *    docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 *    seen through the prototype rather than through the call.
 *
 *  - **`x1` and `y1` are computed between the calls that first need them**,
 *    not hoisted to the top: the image interleaves the two `adds` with the
 *    call sequence exactly where the source order puts them.
 *
 *  - **`id` is `u16`, not `u32`.**  This is what the earlier write-up in
 *    docs/notes/BMP_MENUWORK_DrawFrame.c.txt read as a closed scheduler residue and
 *    told the next reader not to re-attempt.  It is not the scheduler: the
 *    remaining 86 bytes were three `str r5, [sp, #8]` palette stores and the
 *    top-of-function argument spill issued one slot late, and narrowing the
 *    first parameter moves all four.  The narrowing is real, not a trick --
 *    BMP_MENUWORK_DrawWindow hands this the result of BMP_WIN_GetBgLayer, which
 *    src/matched/BMP_MENUWORK_DrawWindowBorder.c (the sibling that calls BG_SYS_SetTileEntry
 *    directly) already declares as a narrow byte accessor, so the caller
 *    side agrees.  With u32 the value is a fresh full-word value in mwccarm's
 *    value numbering and is created before the three stack-argument stores;
 *    with u16 it is created after them, which is the image's order.
 *    `--explain` reports the whole u32 residue as `r5 -> r0 x2` -- a single
 *    swapped pair, the declaration-level signature of this class.
 *
 *    Found by tools/permuter.py (--mode hill --budget 800 --jobs 8 --types),
 *    which reported `type:p(id:u32->u16)` at compile 249 of 800:
 *      baseline  DIFF   asm=1220  bytes-out=86  size=276/276
 *      249       EXACT  asm=0     bytes-out=0   size=276/276
 *
 * CONSEQUENCE.  0x0201F628 has exactly one caller image-wide,
 * BMP_MENUWORK_DrawWindow, so it could never be attested by the `label` class and no
 * cut creates a witness; now that this file is EXACT the `matched` class
 * carries that site, which is what src/matched/BMP_MENUWORK_DrawWindow.c was waiting
 * on.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_DrawFrame.c \
 *       --func BMP_MENUWORK_DrawFrame --addr 0x0201F628 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_DrawFrame(u16 bgId, u8 x, u8 y, u8 width, u8 height, u32 palette, u16 tileBase)
{
    u32 top;
    u32 left;
    u32 right;
    u32 bottom;

    top = y - 1;
    left = x - 1;
    BG_SYS_SetTileEntry(bgId, tileBase,            left, top, 1, 1, palette);
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 1), x,      top, width, 1, palette);
    right = x + width;
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 2), right, top, 1, 1, palette);
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 3), left, y,      1, height, palette);
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 5), right, y,      1, height, palette);
    bottom = y + height;
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 6), left, bottom, 1, 1, palette);
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 7), x,      bottom, width, 1, palette);
    BG_SYS_SetTileEntry(bgId, (u16)(tileBase + 8), right, bottom, 1, 1, palette);
}

/*
 * note:     blocked on BMP_MENUWORK_DrawFrame (label class): its only image-wide
 *   caller is the +0040 site inside this same function, so no witness
 *   exists outside the range under test. --suggest-split confirms no
 *   partition frees it (best partition: 0 pieces, function left out).
 */
void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int commitMode, u16 tileBase, u32 palette)
{
    u8 bgId = BMP_WIN_GetBgLayer(win);
    u8 x = BMP_WIN_GetPosX(win);
    u8 y = BMP_WIN_GetPosY(win);
    u8 width = BMP_WIN_GetDispWidth(win);
    u8 height = BMP_WIN_GetDispHeight(win);

    BMP_MENUWORK_DrawFrame(bgId, x, y, width, height, palette, tileBase);

    if (commitMode == 0) {
        BG_SYS_PushTile(bgId);
    } else if (commitMode == 1) {
        BG_SYS_MarkTileDirty(bgId);
    }
}

/*
 * A width-narrowing wrapper on BMP_MENUWORK_DrawWindow, and the only evidence in the
 * image that BMP_MENUWORK_DrawWindow's third parameter is u16: the single
 * `lsls #16 / lsrs #16` pair here is the argument conversion, so the wrapper
 * takes the tile base as a full word and the worker takes it as a halfword.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_DrawWindowEx.c \
 *       --func BMP_MENUWORK_DrawWindowEx --addr 0x0201F79C --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_DrawWindowEx(struct BmpWin *desc, u32 commitMode, u32 tileBase, u32 palette)
{
    BMP_MENUWORK_DrawWindow(desc, commitMode, (u16)tileBase, palette);
}

/*
 * The sibling of BMP_MENUWORK_DrawWindow: the same five ARM byte accessors on the same
 * descriptor, but the four geometry bytes are adjusted before the call, the
 * two extents shrunk by one and the two origins grown by two, and the worker
 * is BG_SYS_SetTileEntry with a zero second argument and a zero trailing one.
 * The four `lsls #24 / lsrs #24` pairs are the u8 truncation of each adjusted
 * value, not bitfield extraction: they are equal-amount pairs on values that
 * already left the accessors as bytes, so they only survive because the
 * arithmetic promoted to int in between.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_DrawWindowBorder.c \
 *       --func BMP_MENUWORK_DrawWindowBorder --addr 0x0201F7A8 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, u32 commitMode)
{
    u8 bgId;
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    bgId = BMP_WIN_GetBgLayer(desc);
    x = BMP_WIN_GetPosX(desc);
    y = BMP_WIN_GetPosY(desc);
    width = BMP_WIN_GetDispWidth(desc);
    height = BMP_WIN_GetDispHeight(desc);
    BG_SYS_SetTileEntry(bgId, 0, (u8)(x - 1), (u8)(y - 1), (u8)(width + 2), (u8)(height + 2), 0);
    if (commitMode == 0) {
        BG_SYS_PushTile(bgId);
        return;
    }
    if (commitMode == 1) {
        BG_SYS_MarkTileDirty(bgId);
    }
}

/*
 * bmp_menuwork.c: allocate a menu item list of n cleared 8-byte entries plus
 * a terminator entry { 0xFFFFFFFF, heap } (line 0x29, __FILE__ anchor
 * 0x020A7374 "bmp_menuwork.c").  The previous reading
 * (docs/notes/pkt_0201F81C.c.txt) stored the index into both fields; the
 * loop stores ZERO (the `adds r1, r6, #0` before the loop is the zero
 * rematerialised off the index register and never updated), and with that
 * the index lands in r6 and the frame gets its own `sub sp, #4`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_Create.c \
 *       --func BMP_MENUWORK_Create --addr 0x0201F81C --thumb
 */
BmpMenuWork *BMP_MENUWORK_Create(u32 count, u32 heapId)
{
    BmpMenuWork *items;
    u32 idx;

    items = GFL_HEAP_Alloc((u16)heapId, (count + 1) * sizeof(BmpMenuWork), 1, sBmpMenuWorkFile, 0x29);
    if (items != 0) {
        for (idx = 0; idx < count; idx++) {
            items[idx].u.text = 0;
            items[idx].value = 0;
        }
        items[idx].u.raw = 0xFFFFFFFF;
        items[idx].value = heapId;
    }
    return items;
}

/*
 * Destructor pair: run the teardown at 0x0201F8F4, then release the object
 * itself through the allocator's free entry at 0x020307B0.  The pointer has
 * to survive the first call, which is what spends r4 and turns a two-call
 * leaf into a push/pop function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_Delete.c \
 *       --func BMP_MENUWORK_Delete --addr 0x0201F868 --cc 1.1p1 --thumb
 */
u32 BMP_MENUWORK_Delete(void *items)
{
    BMP_MENUWORK_ReleaseItems(items);
    return GFL_HEAP_Free(items);
}

/*
 * Claims a slot through BMP_MENUWORK_FindFreeEntry and, if one was free, fills it with the
 * handle MSGDATA_AllocString returns and the caller's tag.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_AddMsgItem.c  *       --func BMP_MENUWORK_AddMsgItem --addr 0x0201F878 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_AddMsgItem(BmpMenuWork *items, struct MsgBank *bank, u32 msgId, u32 param, u32 heapId)
{
    BmpMenuWork *entry;
    u32          unused;

    entry = BMP_MENUWORK_FindFreeEntry(items, &unused);
    if (entry != 0) {
        entry->u.handle = MSGDATA_AllocString(bank, msgId);
        entry->value = param;
    }
}

/*
 * Claims a slot through BMP_MENUWORK_FindFreeEntry and, if one was free, fills it with the
 * handle STRBUF_Clone returns and the caller's third argument.  Note the
 * argument roles are not the same as in the neighbouring BMP_MENUWORK_AddMsgItem: here
 * the builder takes the caller's *fourth* argument and the slot's tag word
 * comes from the third, the mirror of that function.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_AddStrItem.c  *       --func BMP_MENUWORK_AddStrItem --addr 0x0201F898 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_AddStrItem(BmpMenuWork *items, const struct U16Vec *src, u32 param, u32 heapId)
{
    BmpMenuWork *entry;
    u32          unusedTerminator;

    entry = BMP_MENUWORK_FindFreeEntry(items, &unusedTerminator);
    if (entry != 0) {
        entry->u.handle = STRBUF_Clone((struct Strbuf *)src, heapId);
        entry->value = param;
    }
}

/*
 * Claims a slot in the same eight-byte-stride table BMP_MENUWORK_ReleaseItems walks: it
 * scans for the first empty entry, gives up if the 0xFFFFFFFF terminator
 * arrives first, then runs on to the terminator record and hands its tag word
 * back through the out-parameter.  The empty slot is the return value, null on
 * a full table.
 *
 * Both loops read the word once per iteration and share the load between the
 * zero test and the terminator test, which is why this function needs no
 * union where BMP_MENUWORK_ReleaseItems does: here both tests are u32.  The terminator
 * constant is rematerialised with its own `movs`/`mvns` pair in each of the
 * two blocks that needs it rather than kept live across the first loop; see
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * It is a leaf, so `push {r3, r4}` / `pop {r3, r4}` + `bx lr` rather than a
 * pop into pc, and disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_FindFreeEntry.c \
 *       --func BMP_MENUWORK_FindFreeEntry --addr 0x0201F8B8 --cc 1.1p1 --thumb
 */
BmpMenuWork *BMP_MENUWORK_FindFreeEntry(BmpMenuWork *items, u32 *outTerminatorValue)
{
    BmpMenuWork *freeEntry;

    while (items->u.raw != 0) {
        if (items->u.raw == 0xFFFFFFFF)
            return 0;
        items++;
    }
    freeEntry = items;
    while (items->u.raw != 0xFFFFFFFF)
        items++;
    *outTerminatorValue = items->value;
    return freeEntry;
}

/*
 * Releases every live handle in an eight-byte-stride table and blanks its
 * slot.  The table is terminated by 0xFFFFFFFF and the walk also stops at the
 * first null slot.  0xFFFFFFFF is materialised as `movs`/`mvns`, not a pool
 * word.
 *
 * The first word is a union: the terminator test reads it as u32 and the
 * null test reads it as a pointer.  That is what keeps the second `ldr` in
 * the loop body alive, and it is the only spelling that does; with a single
 * u32 member the compiler forwards the guard's load into the body and the
 * function comes out two instructions short whether the loop is written as a
 * `while`, a `for`, or a guard plus `do`/`while`.  The call then has to take
 * the pointer member too, or the null test lands in r1 and the call argument
 * stays the stale guard value.  See
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * EXACT* is the extent walk running into the unlabelled leaf at 0x0201F91C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_ReleaseItems.c \
 *       --func BMP_MENUWORK_ReleaseItems --addr 0x0201F8F4 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_ReleaseItems(BmpMenuWork *items)
{
    if (items->u.raw == 0xFFFFFFFF)
        return;
    do {
        if (items->u.handle == 0)
            return;
        STRBUF_Delete(items->u.handle);
        items->u.raw = 0;
        items++;
    } while (items->u.raw != 0xFFFFFFFF);
}

/*
 * Counts the occupied entries of the same eight-byte-stride table
 * BMP_MENUWORK_FindFreeEntry claims from, stopping at the 0xFFFFFFFF terminator.  An empty
 * table returns zero without entering the loop.
 *
 * Two shape facts.  The terminator constant is `subs r1, r3, #1` off the
 * counter while it still holds zero rather than a `movs`/`mvns` pair, and it
 * is rematerialised that way twice, once per block.  And the occupancy test
 * has to read the word as a pointer while the terminator tests read it as
 * u32, or the guard's load is forwarded into the loop body and two
 * instructions disappear; see
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_CountItems.c \
 *       --func BMP_MENUWORK_CountItems --addr 0x0201F91C --cc 1.1p1 --thumb
 */
u32 BMP_MENUWORK_CountItems(BmpMenuWork *items)
{
    u32 count;

    count = 0;
    if (items->u.raw != 0xFFFFFFFF) {
        do {
            if (items->u.handle != 0)
                count++;
            items++;
        } while (items->u.raw != 0xFFFFFFFF);
    }
    return count;
}
