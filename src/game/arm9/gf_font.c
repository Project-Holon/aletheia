/*
 * file:     gf_font.c
 * unit:     yes
 * function: GF_FONT_Create, GF_FONT_Delete, GF_FONT_LoadResource, GF_FONT_FreeBuffers, GF_FONT_SetFormat, GF_FONT_InitPreloadedGlyphs, GF_FONT_InitStreamedGlyphs, GF_FONT_ExitFormat, GF_FONT_FreeGlyphData, GF_FONT_ExitStreamedGlyphs, GF_FONT_ReadGlyph, GF_FONT_GetGlyphIndex, GF_FONT_ReadPreloadedGlyph, GF_FONT_ReadStreamedGlyph, GF_FONT_DecodeGlyph, GF_FONT_GetCharWidth, GF_FONT_GetLineHeight, GF_FONT_GetProportionalWidth, GF_FONT_GetFixedWidth, GF_FONT_InitTextColor, GF_FONT_SetDefaultTextColor, GF_FONT_SetTextColor, GF_FONT_GetTextColor, GF_FONT_IsTextColorDifferent, GF_FONT_DecodeGlyph8x8, GF_FONT_InitBitReader, GF_FONT_ReadBits, GF_FONT_DecodeGlyph8x16, GF_FONT_DecodeGlyph16x8, GF_FONT_DecodeGlyph16x16, WORDSET_CreateDefault
 * address:  0x0201D7EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gf_font.c by tools/splitfile.py.
 *
 * symbols:
 *   GF_FONT_GetCharWidth  0x0201DC6C  thumb
 *   GF_FONT_GetLineHeight  0x0201DC80  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   gGfFontFileName  0x020A7358 data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GF_FONT_GetProportionalWidth       0x0201DC88  thumb
 *   ARC_TOOL_GetHandleMemberOffsetOut       0x020494F4  arm
 *   ARC_TOOL_GetHandleMemberSize       0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange        0x0204944C  arm
 *   gFontFormatInitFuncs  0x0209E73C  data
 *   gFontFormatExitFuncs  0x0209E744  data
 *   ARC_TOOL_SeekHandle  0x0204960C  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   gFontState   0x02146578  data
 *   gGlyphExpandTable   0x02146588  data
 *   gTopBitMasks   0x0209E74C  data
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   WORDSET_Create 0x0201EC74 thumb arm9
 */
#include "../version.h"
#include "gf_font_shared_types.h"
#include "printsys_shared_types.h"

struct CMap {
    u16 ccodeBegin;
    u16 ccodeEnd;
    u16 mappingMethod;
    u16 reserved;
    struct CMap *pNext;
    u16 mapInfo[1];
};

struct BitReader {
    const u8 *src;
    u32       bitsLeft;
    u8        current;
};

struct FontState {
    u8               textColor[3];
    u8               pad;
    struct BitReader reader;
};

typedef void (*FormatInitFunc)(struct GfFont *font, u32 tilesWide, u32 tilesHigh, u32 heapId);

typedef void (*FormatExitFunc)(struct GfFont *font);

#include "mi_memory.h"

#include "gfl_heap_wrap.h"

#ifdef __MWERKS__
extern struct ArcFile *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap); /* original prototype; the definition differs in pointer type, return type */
#else
#include "arc_tool.h"
#endif

struct ArcHandle;

#ifdef __MWERKS__
extern void ARC_TOOL_SeekHandle(struct ArcFile *arc, u32 offset); /* original prototype; the definition differs in pointer type, return type */
#endif
struct ArcHandleRaw;


struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);

u32 GF_FONT_Delete(struct GfFont *font);

void GF_FONT_LoadResource(struct GfFont *font, int fileId, u32 isFixedWidth, u32 heapId);

void GF_FONT_FreeBuffers(struct GfFont *font);

void GF_FONT_SetFormat(struct GfFont *font, u32 format, u32 heapId);

void GF_FONT_InitPreloadedGlyphs(struct GfFont *font, u32 tilesWide, u32 tilesHigh, u8 heapId);

void GF_FONT_InitStreamedGlyphs(struct GfFont *font, int tilesWide, int tilesHigh);

void GF_FONT_ExitFormat(struct GfFont *font);

void GF_FONT_FreeGlyphData(struct GfFont *font);

void GF_FONT_ExitStreamedGlyphs(struct GfFont *font);

void GF_FONT_ReadGlyph(struct GfFont *font, u16 ch, void *dst, u8 *metrics);

u32 GF_FONT_GetGlyphIndex(struct GfFont *font, u16 ch);

void GF_FONT_ReadPreloadedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics);

void GF_FONT_ReadStreamedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics);

void GF_FONT_DecodeGlyph(const struct GfFont *font, const u8 *glyph, u32 lastGroupBits, void *dst, u8 *metrics);

u32 GF_FONT_GetCharWidth(struct GfFont *font, u16 ch);

u32 GF_FONT_GetLineHeight(struct GfFont *font);

u32 GF_FONT_GetProportionalWidth(struct GfFont *font, u32 glyphIndex);

u32 GF_FONT_GetFixedWidth(struct GfFont *font, u32 glyphIndex);

void GF_FONT_InitTextColor(void);

void GF_FONT_SetDefaultTextColor(void);

void GF_FONT_SetTextColor(u32 red, u32 green, u32 blue);

void GF_FONT_GetTextColor(u8 *red, u8 *green, u8 *blue);

u32 GF_FONT_IsTextColorDifferent(u32 red, u32 green, u32 blue);

void GF_FONT_DecodeGlyph8x8(const u8 *src, u32 lastGroupBits, u16 *dst);

void GF_FONT_InitBitReader(struct BitReader *reader, const u8 *src);

u8 GF_FONT_ReadBits(struct BitReader *reader, u8 count);

void GF_FONT_DecodeGlyph8x16(const u8 *src, u32 lastGroupBits, u16 *dst);

void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 lastGroupBits, u16 *dst);

void GF_FONT_DecodeGlyph16x16(const u8 *src, u32 lastGroupBits, u16 *dst);

struct WordSet *WORDSET_CreateDefault(u16 heapId);

#include "wordset.h"

extern const char gGfFontFileName[];

extern const char gGfFontFileName[];

extern FormatInitFunc gFontFormatInitFuncs[];

extern const char gGfFontFileName[];

extern FormatExitFunc gFontFormatExitFuncs[];

extern struct FontState gFontState;

extern u16 gGlyphExpandTable[256];

extern const u8         gTopBitMasks[];

/*
 * gf_font.c's constructor: allocates the 0x94-byte font object, opens the
 * resource handle for `a0`, records the archive id at +0x54, then hands the
 * object to GF_FONT_LoadResource (metrics and buffers) and GF_FONT_SetFormat (the format
 * selector).  A null allocation returns straight out, which is why both calls
 * sit inside the one guard.
 *
 * Promoted 2026-09-21 from src/pending/GF_FONT_Create.c with no change to the
 * C: both calls now resolve on the `matched` class from
 * src/matched/GF_FONT_LoadResource.c and src/matched/GF_FONT_SetFormat.c, which were
 * MATCH-parked when this file was written.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_Create.c \
 *       --func GF_FONT_Create --addr 0x0201D7EC --cc 1.1p1 --thumb
 *   EXACT, 80 bytes, 5 relocation sites, all 5 resolved.
 */
struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId)
{
    struct GfFont *font = GFL_HEAP_Alloc(heapId, sizeof(*font), 0, gGfFontFileName, 0xC0);

    if (font != 0) {
        font->arc = ARC_TOOL_CreateHandle(archiveId, heapId);
        font->fileId = fileId;
        GF_FONT_LoadResource(font, fileId, isFixedWidth, heapId);
        GF_FONT_SetFormat(font, format, heapId);
    }
    return font;
}

u32 GF_FONT_Delete(struct GfFont *font)
{
    GF_FONT_ExitFormat(font);
    GF_FONT_FreeBuffers(font);
    return GFL_HEAP_Free(font);
}

/*
 * note:     promoted 2026-09-21: the +0x16C ABS32 to 0x0201DC88 is now
 *           attested `matched` by src/matched/GF_FONT_GetProportionalWidth.c, which closed
 *           this file's last unresolved site.  13 of 13 relocations resolve.
 *
 * gf_font.c's metrics and buffer initialiser, 372 bytes, the largest function
 * in the file and the one GF_FONT_Create calls right after the allocation.  It
 * pulls five sections out of the font resource: the 0x14-byte header block at
 * +0x58, the glyph directory at +0x80, either the whole glyph body (preloaded,
 * into a buffer at +0x84) or nothing (streamed), the eight metric bytes at
 * +0x74, and the character map at +0x88.  The hook at +0x6C is set to
 * GF_FONT_GetProportionalWidth for the streamed case and GF_FONT_GetFixedWidth for the preloaded one,
 * and that is the pointer src/matched/unit_0201DC6C.c calls through.  It
 * finishes by priming the fallback advance at +0x70 from the glyph for '?'
 * (0x3F).
 *
 * Three details cost time:
 *
 *   - **`x / 8` and `x % 8` on the same `u8` field get different signedness
 *     treatment.**  The division is a bare `lsrs #3` and the modulo is the
 *     full signed `lsls #29` / `subs` / `rors #29` sequence, in the same
 *     expression, on the same `ldrb`.  Writing the field into a `u32` local
 *     first makes mwcc lower the modulo test to `movs #7` / `tst` and the
 *     function is sixteen bytes short; writing the field expression out twice
 *     keeps the `int` promotion and reproduces both.  An `s32` local does not
 *     compile at all here.
 *   - **248, 266 and 271 are three `__LINE__` arguments and only two pool
 *     words.**  248 is small enough for `movs`; 266 takes a pool word and 271
 *     is that word plus a constant `adds #5`
 *     (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *   - **The fallback advance is stored twice.**  `font->missingGlyphIndex = 0;` then the
 *     result of GF_FONT_GetGlyphIndex over it; the first store is not dead, because
 *     GF_FONT_GetGlyphIndex reads the field on the path where no block matches.
 *
 * Every concrete byte is reproduced.  Three relocations stay wildcarded:
 *
 *   - ARC_TOOL_GetHandleMemberOffsetOut is an ARM SDK entry point whose only call site in the
 *     image is the one in this function, so the `label` class has nothing
 *     outside the range to point at.  This alone caps the function.
 *   - GF_FONT_GetProportionalWidth is a 64-byte unlabelled Thumb leaf, the streamed-glyph
 *     hook, and this pool word is its only reference image-wide.  It is not in
 *     any manifest entry: unit_0201DC6C stops at 0x0201DC88.  Matching it
 *     would convert this site to the `matched` class.
 *   - GF_FONT_GetFixedWidth resolves on `matched` from src/matched/unit_0201DD58.c and
 *     is listed here only because the pool word sits inside the compared
 *     range.
 *
 * The fields at +0x60, +0x64 and +0x68 are declared `u32` here rather than the
 * `void *` src/matched/unit_0201DC6C.c gives them, because this function does
 * arithmetic on all three; the loads are identical either way.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GF_FONT_LoadResource.c  *       --func GF_FONT_LoadResource --addr 0x0201D854 --cc 1.1p1 --thumb
 */
void GF_FONT_LoadResource(struct GfFont *font, int fileId, u32 isFixedWidth, u32 heapId)
{
    u32 size;

    if (font->arc == 0) {
        return;
    }
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)font->arc, fileId, 0x18, 0x14, &font->info);
    ARC_TOOL_GetHandleMemberOffsetOut((struct ArcHandle *)font->arc, fileId, &font->arcBase);
    font->isFixedWidth = (u8)isFixedWidth;
    if (isFixedWidth != 0) {
        font->widthTable = 0;
        font->getCharWidth = GF_FONT_GetFixedWidth;
    } else {
        size = font->info.mapBlockOffset - font->info.widthBlockOffset;
        font->widthTable = GFL_HEAP_Alloc(heapId, size, 0, gGfFontFileName, 248);
        font->getCharWidth = GF_FONT_GetProportionalWidth;
        ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)font->arc, fileId, font->info.widthBlockOffset, size, font->widthTable);
    }
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)font->arc, fileId, font->info.glyphBlockOffset, 8, &font->glyph);
    font->tilesWide = (u8)(font->glyph.cellWidth / 8 + ((font->glyph.cellWidth % 8) ? 1 : 0));
    font->tilesHigh = (u8)(font->glyph.cellHeight / 8 + ((font->glyph.cellHeight % 8) ? 1 : 0));
    font->lastGroupBits = (u16)((font->glyph.cellWidth * 2) % 8);
    if (font->lastGroupBits == 0) {
        font->lastGroupBits = 8;
    }
    font->glyphDataOffset = font->info.glyphBlockOffset + 8;
    font->scratch = GFL_HEAP_Alloc(heapId, font->glyph.cellSize, 0, gGfFontFileName, 266);
    size = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)font->arc, fileId) - font->info.mapBlockOffset;
    font->charMap = GFL_HEAP_Alloc(heapId, size, 0, gGfFontFileName, 271);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)font->arc, fileId, font->info.mapBlockOffset, size, font->charMap);
    font->missingGlyphIndex = 0;
    font->missingGlyphIndex = (u16)GF_FONT_GetGlyphIndex(font, 0x3F);
}

/*
 * gf_font.c's buffer release: frees the three heap blocks the constructor hung
 * off the object at +0x90, +0x84 and +0x88 and closes the resource handle at
 * +0x50, each guarded by its own null check.
 *
 * All three offsets are past the reach of a Thumb `ldr` immediate, so each
 * access costs an `adds rN, #imm` that is an encoding artefact rather than a
 * pointer in the source (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D9C8.c \
 *       --addr 0x0201D9C8 --thumb
 */
void GF_FONT_FreeBuffers(struct GfFont *font)
{
    if (font->scratch != 0) {
        GFL_HEAP_Free(font->scratch);
    }
    if (font->widthTable != 0) {
        GFL_HEAP_Free(font->widthTable);
    }
    if (font->charMap != 0) {
        GFL_HEAP_Free(font->charMap);
    }
    if (font->arc != 0) {
        ARC_TOOL_DeleteHandle(font->arc);
    }
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * gf_font.c's format selector: it records the requested glyph format in the
 * object's first word and dispatches on it through a four-entry table of
 * initialisers, handing each the cell width and height the constructor left at
 * +0x7E and +0x7F.  GF_FONT_ExitFormat, src/pending/GF_FONT_ExitFormat.c, is the matching
 * teardown and dispatches on the same word through the neighbouring table.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table base 0x0209E73C: the pool word inside this function is the only word
 * in the image that holds it, so the `literal` class has no witness left once
 * the compared range is excluded, and no cut helps because the function is
 * twenty bytes of dispatch with nothing to cut away.  It needs a second
 * reference to the table, most likely from an overlay, to move.
 *
 * This is also what keeps GF_FONT_Create, src/pending/GF_FONT_Create.c, out of
 * src/matched: its only witness for the call to this function would be having
 * it local in the same unit, and a unit that spans it inherits this same
 * unresolved table word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GF_FONT_SetFormat.c \
 *       --func GF_FONT_SetFormat --addr 0x0201DA00 --cc 1.1p1 --thumb
 */
void GF_FONT_SetFormat(struct GfFont *font, u32 format, u32 heapId)
{
    font->format = format;
    gFontFormatInitFuncs[format](font, font->tilesWide, font->tilesHigh, heapId);
}

void GF_FONT_InitPreloadedGlyphs(struct GfFont *font, u32 tilesWide, u32 tilesHigh, u8 heapId)
{
    u32 size;
    GlyphDecodeFunc decode;

    size = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)font->arc, font->fileId) - font->glyphDataOffset;
    font->glyphData = GFL_HEAP_Alloc(heapId, size, 0, gGfFontFileName, 363);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)font->arc, font->fileId, font->glyphDataOffset, size, font->glyphData);
    font->readGlyph = GF_FONT_ReadPreloadedGlyph;
    if (tilesWide == 1) {
        decode = GF_FONT_DecodeGlyph8x8;
        if (tilesHigh != 1) {
            decode = GF_FONT_DecodeGlyph8x16;
        }
        font->decodeGlyph = decode;
    } else {
        decode = GF_FONT_DecodeGlyph16x8;
        if (tilesHigh != 1) {
            decode = GF_FONT_DecodeGlyph16x16;
        }
        font->decodeGlyph = decode;
    }
}

/*
 * gf_font.c's format-1 hook installer: clears +0xC, plants the shared measure
 * hook GF_FONT_ReadStreamedGlyph at +4, and picks one of four glyph decoders for +8 on the
 * 2x2 cross of the two flags (a == 1 selects the first pair, b == 1 the first
 * of each pair).  src/matched/GF_FONT_DecodeGlyph8x8.c is the (1,1) decoder.
 *
 * Promoted 2026-09-21.  The file was parked at MATCH with the last pool word
 * declared under the address name of 0x0201E938, an address that is NOT a function start: it is
 * the first `bl` inside GF_FONT_DecodeGlyph16x16.  Because the naming convention derives
 * the address from the identifier, the extern was pinned sixteen bytes into
 * the fourth decoder, where nothing can attest it (and, being a `bl`, it was
 * even guessed ARM).  The pool word is 0x0201E929, i.e. thumb GF_FONT_DecodeGlyph16x16;
 * renaming the extern is the whole fix and the concrete bytes never changed.
 * The lesson is that a wildcarded relocation hides a wrong address as
 * effectively as a missing witness does.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_InitStreamedGlyphs.c \
 *       --func GF_FONT_InitStreamedGlyphs --addr 0x0201DAA4 --cc 1.1p1 --thumb
 *   EXACT, 56 bytes, 5 relocation sites, all 5 resolved.
 */
void GF_FONT_InitStreamedGlyphs(struct GfFont *font, int tilesWide, int tilesHigh)
{
    font->glyphData = 0;
    font->readGlyph = GF_FONT_ReadStreamedGlyph;
    if (tilesWide == 1)
        font->decodeGlyph = (tilesHigh == 1) ? GF_FONT_DecodeGlyph8x8 : GF_FONT_DecodeGlyph8x16;
    else
        font->decodeGlyph = (tilesHigh == 1) ? GF_FONT_DecodeGlyph16x8 : GF_FONT_DecodeGlyph16x16;
}

/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * gf_font.c's format teardown, the mirror of GF_FONT_SetFormat: it dispatches on
 * the format word the selector stored at +0 through a second four-entry table
 * that sits two words after the first one.  Twenty bytes, one indirect call.
 *
 * Every concrete byte is reproduced.  The unresolved relocation is the table
 * base 0x0209E744 and the pool word here is its only witness image-wide, the
 * same dead end as src/pending/GF_FONT_SetFormat.c.  Note that the two tables being
 * eight bytes apart is *not* usable as evidence: expressing one as an offset
 * from the other would be a claim that they are one object, and the image does
 * not say so.
 *
 * This is in turn what keeps GF_FONT_Delete, src/pending/GF_FONT_Delete.c, out of
 * src/matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GF_FONT_ExitFormat.c \
 *       --func GF_FONT_ExitFormat --addr 0x0201DADC --cc 1.1p1 --thumb
 */
void GF_FONT_ExitFormat(struct GfFont *font)
{
    gFontFormatExitFuncs[font->format](font);
}

/*
 * gf_font.c's glyph-buffer release, an empty hook, and the entry point every
 * text routine in the region reaches a glyph through.
 *
 * GF_FONT_ExitStreamedGlyphs is two bytes, `bx lr`, which is `void f(void) {}`, a hook that
 * was never filled in.  It carries no label because it has no prologue.
 *
 * GF_FONT_ReadGlyph looks up the glyph with GF_FONT_GetGlyphIndex and dispatches through the
 * function pointer at +4 of the font object.  GF_FONT_GetGlyphIndex itself, the glyph
 * index lookup at 0x0201DB20, is still open: it reproduces all 154 bytes bar a
 * consistent interchange of r4 with r6, the run cursor against the two binary
 * search bounds, and no declaration order, scope or type tried moves it.  Its
 * one non-obvious detail is worth recording anyway: the base pointer at +0x88
 * has to be spelled `*(struct FontRun **)((u8 *)p + 0x88)` at the top of the
 * function and `font->charMap` at the rebasing site, or the compiler keeps one copy
 * in a register across the loop and spends an extra move; the original
 * rematerialises the address in the cold path instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DAF0.c \
 *       --addr 0x0201DAF0 --thumb
 */
void GF_FONT_FreeGlyphData(struct GfFont *font)
{
    GFL_HEAP_Free(font->glyphData);
    font->glyphData = 0;
}

void GF_FONT_ExitStreamedGlyphs(struct GfFont *font)
{
}

void GF_FONT_ReadGlyph(struct GfFont *font, u16 ch, void *dst, u8 *metrics)
{
    font->readGlyph(font, GF_FONT_GetGlyphIndex(font, ch), dst, metrics);
}

/*
 * gf_font.c's character-to-glyph-index lookup: NitroSystem's character-map
 * search (NNSG2dFontCodeMap: ccodeBegin, ccodeEnd, mappingMethod, reserved,
 * pNext, mapInfo[]) walked Game Freak style.  The chain pointer is stored as
 * an address in the resource file and is rebased from the load address
 * (+0x68) onto the copy (+0x88); +0x70 is the font's default glyph.  Method
 * 0 is a direct run, 1 a table, 2 a binary search over (code, index) pairs.
 *
 * Two details closed it (docs/notes/GF_FONT_GetGlyphIndex.c.txt has every
 * measurement):
 *
 *   - the rebase re-reads +0x88 as `*(u8 **)((u8 *)f + 0x88)`, so it is not
 *     CSE'd with the first read (wave 15, 139 -> 15 bytes out);
 *   - the chain step goes through a second pointer local `n` and ends in the
 *     copy `m = n;`.  When m's loop-carried definition is an arithmetic
 *     result (`m = rebase(m)`, even `m = m + 4`), mwcc colours m after every
 *     other local whatever the declaration order, and m takes r6.  With the
 *     copy, m, lo and hi colour in declaration order, which is the image's
 *     m r4, lo r5, hi r6 (wave 21 lane F2, 15 -> 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_GetGlyphIndex.c \
 *       --func GF_FONT_GetGlyphIndex --addr 0x0201DB20 --cc 1.1p1 --thumb
 */
u32 GF_FONT_GetGlyphIndex(struct GfFont *font, u16 ch)
{
    struct CMap *map;
    s32 low;
    s32 high;
    struct CMap *next;

    map = (struct CMap *)font->charMap;
    for (;;) {
        if (map->ccodeBegin <= ch && map->ccodeEnd >= ch) {
            switch (map->mappingMethod) {
            case 0:
                return map->mapInfo[0] + (ch - map->ccodeBegin);
            case 1:
                return map->mapInfo[(u16)(ch - map->ccodeBegin)];
            case 2: {
                low = 0;
                high = map->mapInfo[0] - 1;
                while (low <= high) {
                    s32 middle = low + (high - low) / 2;
                    s32 pairIndex = 2 * middle + 1;
                    if (map->mapInfo[pairIndex] < ch)
                        low = middle + 1;
                    else if (ch < map->mapInfo[pairIndex])
                        high = middle - 1;
                    else
                        return map->mapInfo[pairIndex + 1];
                }
                break;
            }
            }
            return font->missingGlyphIndex;
        }
        next = map->pNext;
        if (next != 0)
            next = (struct CMap *)(*(u8 **)&font->charMap + ((uptr)next - font->info.mapBlockOffset));
        else
            return 0;
        map = next;
    }
}

/*
 * gf_font.c's glyph fetch for a preloaded font: copy glyph record i
 * (mapSize bytes) out of the resident body into the scratch buffer, then
 * hand it to GF_FONT_DecodeGlyph with the last-tile column count.
 *
 * The lever (wave 16) is `const` on the font parameter, which is only read
 * here.  With a plain pointer the outgoing stack argument `out` was stored
 * third in the final call's setup; with `const struct GfFont *` it is stored
 * last, as in the image (12 bytes out before, every spelling and 3000
 * permuter compiles flat: docs/notes/GF_FONT_ReadPreloadedGlyph.c.txt).  Field names
 * follow docs/families/gf_font.h.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_ReadPreloadedGlyph.c \
 *       --func GF_FONT_ReadPreloadedGlyph --addr 0x0201DBBC --cc 1.1p1 --thumb
 */
void GF_FONT_ReadPreloadedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics)
{
    MI_CpuCopy8(font->glyphData + glyphIndex * font->glyph.cellSize, font->scratch, font->glyph.cellSize);
    GF_FONT_DecodeGlyph(font, font->scratch, font->lastGroupBits, dst, metrics);
}

/*
 * gf_font.c's glyph fetch for a streamed font: seek the resource handle to
 * the header base plus the glyph directory plus record i, read mapSize bytes
 * into the scratch buffer, then hand it to GF_FONT_DecodeGlyph with the last-tile
 * column count.
 *
 * The lever (wave 16) is `const` on the font parameter, exactly as in its
 * sibling src/matched/GF_FONT_ReadPreloadedGlyph.c: it moves the outgoing stack argument
 * `out` from third to last in the final call's setup (12 bytes out before,
 * docs/notes/GF_FONT_ReadPreloadedGlyph.c.txt).  The listing extent includes the two-byte
 * alignment pad at 0x0201DC42, hence EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_ReadPreloadedGlyph.c \
 *       --func GF_FONT_ReadStreamedGlyph --addr 0x0201DBF4 --cc 1.1p1 --thumb
 */
void GF_FONT_ReadStreamedGlyph(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics)
{
#ifdef __MWERKS__
    ARC_TOOL_SeekHandle(font->arc, font->arcBase + (font->glyphDataOffset + glyphIndex * font->glyph.cellSize));
#else
    ARC_TOOL_SeekHandle((struct FSFile *)font->arc, font->arcBase + (font->glyphDataOffset + glyphIndex * font->glyph.cellSize));
#endif
    ARC_TOOL_ReadHandle((struct ArcHandleRaw *)font->arc, font->glyph.cellSize, font->scratch);
    GF_FONT_DecodeGlyph(font, font->scratch, font->lastGroupBits, dst, metrics);
}

/*
 * gf_font.c's glyph hand-off: the rendering hook installed at +8 of the font
 * object is called on the glyph bitmap, which starts three bytes into the
 * glyph record, and the record's own three metric bytes plus the byte at +0x59
 * of the font object are copied into the caller's four-byte descriptor.
 *
 * The width is a `u32` parameter and the hook takes it as `u16`, which is what
 * the single `lsls #16` / `lsrs #16` pair before the call is: a `u16`
 * parameter here would make the caller truncate instead and both callers in
 * this packet are two bytes short.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph.c \
 *       --func GF_FONT_DecodeGlyph --addr 0x0201DC44 --cc 1.1p1 --thumb
 */
void GF_FONT_DecodeGlyph(const struct GfFont *font, const u8 *glyph, u32 lastGroupBits, void *dst, u8 *metrics)
{
    font->decodeGlyph(glyph + 3, (u16)lastGroupBits, dst);
    metrics[0] = glyph[0];
    metrics[1] = glyph[1];
    metrics[2] = glyph[2];
    metrics[3] = font->info.lineHeight;
}

/*
 * The gf_font.c width query and the accessor for the byte at +0x59.
 *
 * GF_FONT_GetCharWidth returns whatever the function pointer at +0x6C returns, and the
 * tail call shape (`ldr r2, [r4, #0x6c]`, `blx r2`, `pop {r4, pc}`) is the same
 * bytes whether the C declares a return value or not, so the return type is
 * fixed by the caller instead: PRINTSYS_MeasureText adds the result to a running width.
 *
 * GF_FONT_GetLineHeight has no label in the listing; it is three halfwords between two
 * literal pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DC6C.c \
 *       --addr 0x0201DC6C --thumb
 */
u32 GF_FONT_GetCharWidth(struct GfFont *font, u16 ch)
{
    return font->getCharWidth(font, GF_FONT_GetGlyphIndex(font, ch));
}

u32 GF_FONT_GetLineHeight(struct GfFont *font)
{
    return font->info.lineHeight;
}

/*
 * gf_font.c streamed-glyph lookup: classify glyph `id` through a
 * 2-bit-per-glyph table, fall back to a 9-bit hash, then walk a run of
 * variable-length records for a matching 2-byte code.  See
 * docs/notes/GF_FONT_GetProportionalWidth.c.txt for the full structural derivation.
 *
 * No relocations: every table is reached through offsets stored in the
 * resource header at obj+0x84.
 *
 * EXACT*, not EXACT: GF_FONT_GetFixedWidth immediately after this one is an
 * unlabelled leaf, so the inferred extent runs long (240 vs 208).  Report
 * the unlabelled follower at 0x0201DD58 rather than editing
 * layout/function_starts.txt.
 *
 * The closing lever (2026-09-21): the record header must be read with a
 * fused post-increment, `cnt = *p++;`.  Spelling it as the two statements
 * `cnt = *p; p++;` swaps the cursor and the scan counter between r2 and r3
 * for the whole tail, which is the 17-byte residue the note records.
 */
u32 GF_FONT_GetProportionalWidth(struct GfFont *font, u32 glyphIndex)
{
    struct GlyphWidthTable *table = font->widthTable;
    u32 bitPos = glyphIndex * 2;
    u8  packed = ((u8 *)table + table->classOffset)[bitPos >> 3];
    u8  widthClass = (u8)((packed >> (6 - (bitPos & 7))) & 3);
    u16 slot;
    s8  entry;
    u16 skip;
    u8 *record;
    u8  count;
    u8  index;

    if (widthClass < 3)
        return ((u8 *)table)[widthClass];

    slot = (u16)(((glyphIndex & 0x1ff) ^ (u16)(((((glyphIndex >> 12) ^ (glyphIndex >> 11)) ^ (glyphIndex >> 10)) ^ (glyphIndex >> 9)) & 1) << 3) & 0x1ff);

    entry = ((s8 *)((u8 *)table + table->hashOffset))[slot];
    if (entry >= 0)
        return (u8)entry;

    skip = (u16)((u16)(-entry) - 1);
    record = (u8 *)table + table->chainOffset;
    while (skip != 0) {
        u8 recordCount = *record;
        u16 remaining = (u16)(skip - 1);
        record += recordCount + recordCount * 2 + 1;
        skip = remaining;
    }

    count = *record++;
    index = 0;
    while (index < count) {
        u16 key = (u16)((record[0] << 8) | record[1]);
        if (glyphIndex == key)
            return record[2];
        index = (u8)(index + 1);
        record += 3;
    }
    return font->info.defaultCharWidth;
}

/*
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * GF_FONT_InitTextColor and GF_FONT_SetDefaultTextColor are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: GF_FONT_InitTextColor tail-calls GF_FONT_SetDefaultTextColor, which tail-calls
 * GF_FONT_SetTextColor with three constants.  Writing it as one function that calls
 * GF_FONT_SetTextColor directly loses eight bytes.
 *
 * GF_FONT_SetTextColor itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 */
u32 GF_FONT_GetFixedWidth(struct GfFont *font, u32 glyphIndex)
{
    return font->info.defaultCharWidth;
}

void GF_FONT_InitTextColor(void)
{
    GF_FONT_SetDefaultTextColor();
}

void GF_FONT_SetDefaultTextColor(void)
{
    GF_FONT_SetTextColor(1, 2, 0);
}

/*
 * gf_font.c's text-colour setter, 136 bytes.  It records the three requested
 * palette indices in gFontState (the three bytes src/matched/unit_0201DE00.c
 * reads back) and then rebuilds the 256-entry expansion table at 0x02146588: a
 * byte of four 2-bit pixels indexes it and the halfword it yields is the same
 * four pixels widened to a nibble each.  The four nested loops enumerate the
 * four pixels; the local array is { 0, r, g, b }, so pixel value 0 stays 0 and
 * 1..3 map to the three requested indices.
 *
 * Two details cost time:
 *
 *   - **The disjunction is written innermost-term-first.**  Spelled
 *     `c[i] | c[j] << 4 | c[k] << 8 | c[l] << 12` the left-associated prefix
 *     `c[i] | c[j] << 4` is invariant in the two inner loops, mwcc hoists it,
 *     and the function is four bytes short with the partial results living in
 *     `ip` and `lr`.  Written the other way round, `c[l] << 12` leads and no
 *     prefix of the chain is loop-invariant, so only the three shifted terms
 *     are hoisted, one per loop level, which is what the original does.
 *   - **The four loop counters are signed.**  The back edges are `blt`, not
 *     `blo`; `u32` counters cost four wrong bytes and nothing else.
 *
 * The store order in the prologue is also load-bearing: the four array slots
 * are written first, the three global bytes after them, and the flat output
 * index last.  Any other order leaves the `strb`s and the `str`s interleaved
 * differently and up to eighteen bytes differ, with the instruction multiset
 * unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_SetTextColor.c \
 *       --func GF_FONT_SetTextColor --addr 0x0201DD78 --cc 1.1p1 --thumb
 */
void GF_FONT_SetTextColor(u32 red, u32 green, u32 blue)
{
    u32 palette[4];
    s32 pixel0;
    s32 pixel1;
    s32 pixel2;
    s32 pixel3;
    u32 entry;

    palette[0] = 0;
    palette[1] = red;
    palette[2] = green;
    palette[3] = blue;
    gFontState.textColor[0] = (u8)red;
    gFontState.textColor[1] = (u8)green;
    gFontState.textColor[2] = (u8)blue;
    entry = 0;
    for (pixel0 = 0; pixel0 < 4; pixel0++) {
        for (pixel1 = 0; pixel1 < 4; pixel1++) {
            for (pixel2 = 0; pixel2 < 4; pixel2++) {
                for (pixel3 = 0; pixel3 < 4; pixel3++) {
                    gGlyphExpandTable[entry] = (u16)((palette[pixel3] << 12) | (palette[pixel2] << 8) |
                                              (palette[pixel1] << 4) | palette[pixel0]);
                    entry++;
                }
            }
        }
    }
}

/*
 * The current text colour, read back and compared.  gFontState is the three
 * bytes GF_FONT_SetTextColor stores the last requested colour into.
 *
 * GF_FONT_IsTextColorDifferent returns 1 when the colour differs, and its shape is the
 * disjunction form rather than the conjunction: the first two comparisons branch
 * to one shared `movs r0, #1` block and only the last one branches past it,
 * which is what `if (r != c[0] || g != c[1] || b != c[2]) return 1;` gives.
 * Written as `if (all equal) return 0; return 1;` the arms swap and ten of the
 * forty bytes are wrong
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DE00.c \
 *       --addr 0x0201DE00 --thumb
 */
void GF_FONT_GetTextColor(u8 *red, u8 *green, u8 *blue)
{
    *red = gFontState.textColor[0];
    *green = gFontState.textColor[1];
    *blue = gFontState.textColor[2];
}

u32 GF_FONT_IsTextColorDifferent(u32 red, u32 green, u32 blue)
{
    if (red != gFontState.textColor[0] || green != gFontState.textColor[1] || blue != gFontState.textColor[2]) {
        return 1;
    }
    return 0;
}

static inline u8 ReadBits(struct BitReader *reader, u8 count)
{
    u8  highBits;
    u32 lowBits;
    u8  current;
    u32 bitsTaken;

    if (reader->bitsLeft < count) {
        highBits = reader->current;
        highBits &= gTopBitMasks[reader->bitsLeft];
        bitsTaken = reader->bitsLeft;
        count = (u8)(count - (u8)bitsTaken);
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        highBits = 0;
        bitsTaken = 0;
    }

    current = reader->current;
    lowBits = gTopBitMasks[count] & current;
    reader->bitsLeft = reader->bitsLeft - count;
    if (reader->bitsLeft == 0) {
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        reader->current = (u8)(current << count);
    }
    return (u8)((lowBits >> bitsTaken) | highBits);
}

/*
 * gf_font.c's format-1 glyph decoder, one of the four hooks GF_FONT_InitStreamedGlyphs
 * installs at font->decodeGlyph (src/pending/GF_FONT_InitStreamedGlyphs.c): the one for format 1
 * with b == 1.
 *
 * Sixteen 4-pixel groups of a compressed 2bpp 8x8 glyph.  Every even group is
 * a whole literal byte (read_bits of 8 bits) and every odd one is `n` bits
 * wide; each group's byte then indexes the 256-entry 2bpp->4bpp expansion
 * table at 0x02146588 that GF_FONT_SetTextColor rebuilds (src/matched/GF_FONT_SetTextColor.c),
 * so the sixteen halfwords written to dst are the glyph in 4bpp.  `n` is the
 * caller's bit depth and is a runtime value, which is why the even and odd
 * reads are the same inlined reader with a constant and a variable count.
 *
 * The reader is the source of GF_FONT_ReadBits (src/matched/GF_FONT_ReadBits.c), the
 * out-of-line copy of it that sits just past this function, inlined here
 * sixteen times; `static inline` is load-bearing, plain `static` compiles to
 * sixteen `bl`s and 260 bytes.  Its state is the second half of the global at
 * 0x02146578, whose first three bytes are the text colour GF_FONT_SetTextColor
 * stores and src/matched/unit_0201DE00.c reads back; that is why the inlined
 * field accesses sit at +4/+8/+12 rather than at +0/+4/+8 as they do in the
 * out-of-line call.
 *
 * What cost the last eight bytes: the outer parameter must be `u32 n`, not
 * `u8 n`.  With a u8 parameter mwcc treats the register as an already
 * zero-extended byte, so the inlined expansions compare `r->avail` against
 * the raw argument and keep `n` alive in two registers; the original
 * re-materialises `(u8)n` once per expansion, before the `avail < n`
 * comparison, which is what a conversion from a wider argument gives you.
 * Every block is the same length either way, so the whole difference is one
 * register choice and a pool 8 bytes further along.
 *
 * Extent note: the listing's 1672 bytes for this function run to 0x0201E4C8,
 * eight bytes past the last code byte (0x0201E4BE) - the two-word literal
 * pool at 0x0201E4C0 (gTopBitMasks, gGlyphExpandTable) is this function's own.  It is
 * inside this packet, not the neighbouring 0x0201E000..0x0202E000 lane; the
 * next function starts at 0x0201E4C8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph8x8.c \
 *       --func GF_FONT_DecodeGlyph8x8 --addr 0x0201DE40 --cc 1.1p1 --thumb
 *   EXACT, 1672 bytes, 5 relocation sites, all 5 resolved.
 */
void GF_FONT_DecodeGlyph8x8(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    gFontState.reader.src = src;
    gFontState.reader.current = *src;
    gFontState.reader.bitsLeft = 8;

    dst[0] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * Opens the bit reader the glyph decompressor in this packet runs on: the
 * cursor at +0 is the byte pointer, +4 is the number of bits still unread out
 * of the byte cached at +8, and the first byte is latched on the spot.
 *
 * Twelve bytes, no prologue: the function saves nothing, so disasm.py's
 * prologue sweep never labels it and it prints as part of the `.word` run in
 * front of GF_FONT_ReadBits
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The bit count is assigned last.  Written before the cached byte the two
 * stores swap and the constant 8 is materialised earlier, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_InitBitReader.c \
 *       --func GF_FONT_InitBitReader --addr 0x0201E4C8 --cc 1.1p1 --thumb
 */
void GF_FONT_InitBitReader(struct BitReader *reader, const u8 *src)
{
    reader->src = src;
    reader->current = src[0];
    reader->bitsLeft = 8;
}

/*
 * The bit reader behind the compressed glyph stream: pulls `n` bits out of a
 * byte stream, most significant bit first.  The state is three fields, the
 * read pointer at +0, the number of bits still unconsumed in the byte at +4,
 * and that byte itself at +8; gTopBitMasks is the 0..8 entry table of top-bit
 * masks.  When the request straddles a byte boundary the leading bits are
 * taken first, the next byte is fetched, and the two halves are OR'd back
 * together.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_ReadBits.c
 *       --func GF_FONT_ReadBits --addr 0x0201E4D4 --cc 1.1p1 --thumb
 */
u8 GF_FONT_ReadBits(struct BitReader *reader, u8 count)
{
    u8  highBits;
    u32 lowBits;
    u8  current;
    u32 bitsTaken;

    if (reader->bitsLeft < count) {
        highBits = reader->current;
        highBits &= gTopBitMasks[reader->bitsLeft];
        bitsTaken = reader->bitsLeft;
        count = (u8)(count - (u8)bitsTaken);
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        highBits = 0;
        bitsTaken = 0;
    }

    current = reader->current;
    lowBits = gTopBitMasks[count] & current;
    reader->bitsLeft = reader->bitsLeft - count;
    if (reader->bitsLeft == 0) {
        reader->src++;
        reader->current = *reader->src;
        reader->bitsLeft = 8;
    } else {
        reader->current = (u8)(current << count);
    }
    return (u8)((lowBits >> bitsTaken) | highBits);
}

/*
 * One of the four compressed-glyph decoders src/matched/GF_FONT_InitStreamedGlyphs.c and
 * src/matched/GF_FONT_InitPreloadedGlyphs.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/GF_FONT_InitBitReader.c
 * opens it, src/matched/GF_FONT_ReadBits.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/GF_FONT_SetTextColor.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/GF_FONT_DecodeGlyph8x8.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords, one flat 8x8-at-4bpp glyph in address order, with the
 * widths alternating 8, n, 8, n, ...  The simplest of the four: one cursor,
 * dst[0] through dst[31] in order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph8x16.c \
 *       --func GF_FONT_DecodeGlyph8x16 --addr 0x0201E538 --cc 1.1p1 --thumb
 *   EXACT, 512 bytes, 35 relocation sites, all 35 resolved.
 */
void GF_FONT_DecodeGlyph8x16(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[16] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[17] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[18] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[19] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[20] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[21] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[22] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[23] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[24] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[25] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[26] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[27] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[28] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[29] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[30] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[31] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * One of the four compressed-glyph decoders src/matched/GF_FONT_InitStreamedGlyphs.c and
 * src/matched/GF_FONT_InitPreloadedGlyphs.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/GF_FONT_InitBitReader.c
 * opens it, src/matched/GF_FONT_ReadBits.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/GF_FONT_SetTextColor.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/GF_FONT_DecodeGlyph8x8.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords in TWO interleaved cursors, `dst` and `dst2 = dst + 16`,
 * written four at a time: dst[2i], dst[2i+1], dst2[2i], dst2[2i+1], with widths
 * 8, 8, 8, n.  The second cursor is what puts dst+0x20 in r7 for the whole
 * body; written as dst[16 + k] instead the compiler recomputes the base from
 * dst at every far store and the function is longer.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph16x8.c \
 *       --func GF_FONT_DecodeGlyph16x8 --addr 0x0201E738 --cc 1.1p1 --thumb
 *   EXACT, 496 bytes, 35 relocation sites, all 35 resolved.
 */
#if LANGUAGE == LANGUAGE_FRENCH || LANGUAGE == LANGUAGE_ITALIAN || LANGUAGE == LANGUAGE_GERMAN
/* In the French, Italian and German fonts the last halfword of each row group is always blank:
 * the decoder reads three groups and stores the empty entry itself. */
void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    u16 *dst2 = dst + 16;

    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[1] = gGlyphExpandTable[0];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[3] = gGlyphExpandTable[0];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[5] = gGlyphExpandTable[0];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[7] = gGlyphExpandTable[0];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[9] = gGlyphExpandTable[0];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[11] = gGlyphExpandTable[0];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[13] = gGlyphExpandTable[0];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst2[15] = gGlyphExpandTable[0];
}
#else
void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    u16 *dst2 = dst + 16;

    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
}
#endif

/*
 * One of the four compressed-glyph decoders src/matched/GF_FONT_InitStreamedGlyphs.c and
 * src/matched/GF_FONT_InitPreloadedGlyphs.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/GF_FONT_InitBitReader.c
 * opens it, src/matched/GF_FONT_ReadBits.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/GF_FONT_SetTextColor.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/GF_FONT_DecodeGlyph8x8.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Forty-eight halfwords across FOUR 8x8 tiles, the widest of the four decoders.
 * The tiles are written three halfwords at a time, dst[k], dst[k+1], dst2[k],
 * with widths 8, 8, n, where `dst2 = dst + 16` is the tile below.
 *
 * WHICH INDEX GOES THROUGH WHICH CURSOR IS LOAD-BEARING, and it is what cost
 * the time here.  The second tile pair lives at halfword 32..63, and its low
 * tile (32..47) must be written as `dst[32..47]`, i.e. through the FIRST
 * cursor, while its high tile (48..63) goes through `dst2[32..47]`.  Routing
 * the whole second pair through `dst2` (dst2[16..47], which is the same
 * address arithmetic) lets mwcc keep one base live across both blocks: sixty
 * bytes short, 413 bytes out, and a clean r5/r6/r7 rotation in the permuter's
 * --explain map.  Splitting them back restores the original's recomputed
 * `adds r0, r5, #0 / adds r0, #0x40 / strh` at every far store, which is the
 * shape the image actually has.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_FONT_DecodeGlyph16x16.c \
 *       --func GF_FONT_DecodeGlyph16x16 --addr 0x0201E928 --cc 1.1p1 --thumb
 *   EXACT, 828 bytes, 51 relocation sites, all 51 resolved.
 */
void GF_FONT_DecodeGlyph16x16(const u8 *src, u32 lastGroupBits, u16 *dst)
{
    u16 *dst2 = dst + 16;

    GF_FONT_InitBitReader(&gFontState.reader, src);
    dst[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[1] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[0] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[3] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[2] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[5] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[4] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[7] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[6] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[9] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[8] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[11] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[10] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[13] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[12] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[15] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[14] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[32] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[33] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[32] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[34] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[35] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[34] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[36] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[37] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[36] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[38] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[39] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[38] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[40] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[41] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[40] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[42] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[43] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[42] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[44] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[45] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[44] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
    dst[46] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst[47] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, 8)];
    dst2[46] = gGlyphExpandTable[GF_FONT_ReadBits(&gFontState.reader, lastGroupBits)];
}

/*
 * The first function of wordset.c.  The file identity is in the image: the
 * constructor at 0x0201EC74, immediately after this, passes 0x020A7364 to the
 * debug allocator at 0x02030734, and the bytes there spell "wordset.c".  The
 * string before it is "gf_font.c", whose terminator at 0x020A7360 plus three
 * bytes of padding fixes 0x020A7364 by construction, so the `string` class
 * carries the address; see src/matched/unit_0201ED04.c for the rest of the
 * file and the near miss at 0x0201EC74 that keeps this function on its own.
 *
 * Sixteen bytes: a pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that fills in the default
 * entry count 8 and the default per-entry string size 0x20.  It cannot be one
 * unit with 0x0201EC74 because that function is 14 bytes of prologue
 * scheduling away from EXACT and csrc.py refuses anything less.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201EC64.c \
 *       --addr 0x0201EC64 --thumb
 */
struct WordSet *WORDSET_CreateDefault(u16 heapId)
{
    return WORDSET_Create(8, 0x20, heapId);
}
