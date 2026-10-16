#ifndef PRINTSYS_SHARED_TYPES_H
#define PRINTSYS_SHARED_TYPES_H

#include "gf_font_shared_types.h"

struct ArcFile;

typedef signed   char  s8;

struct FontInfo {
    u8  fontType;
    u8  lineHeight;
    u16 nullGlyphIndex;
    u8  defaultLeft;
    u8  defaultGlyphWidth;
    u8  defaultCharWidth;
    u8  encoding;
    u32 glyphBlockOffset;
    u32 widthBlockOffset;
    u32 mapBlockOffset;
};

struct GlyphInfo {
    u8  cellWidth;
    u8  cellHeight;
    u16 cellSize;
    s8  baseline;
    u8  maxCharWidth;
    u8  bitsPerPixel;
    u8  flags;
};

struct GlyphWidthTable {
    u8  defaultWidths[3];
    u8  pad3;
    u32 classOffset;
    u32 hashOffset;
    u32 chainOffset;
};

struct GfFont;

typedef void (*GlyphReadFunc)(const struct GfFont *font, u32 glyphIndex, void *dst, u8 *metrics);

typedef void (*GlyphDecodeFunc)(const u8 *src, u32 lastGroupBits, u16 *dst);

typedef u32 (*CharWidthFunc)(struct GfFont *font, u32 glyphIndex);

struct GfFont {
    u32 format;
    GlyphReadFunc readGlyph;
    GlyphDecodeFunc decodeGlyph;
    u8 *glyphData;
    u8 pad10[0x40];
    struct ArcFile *arc;
    u32 fileId;
    struct FontInfo info;
    CharWidthFunc getCharWidth;
    u16 missingGlyphIndex;
    u8  isFixedWidth;
    u8  pad73;
    struct GlyphInfo glyph;
    u16 lastGroupBits;
    u8  tilesWide;
    u8  tilesHigh;
    u32 arcBase;
    struct GlyphWidthTable *widthTable;
    u8 *charMap;
    u32 glyphDataOffset;
    void *scratch;
};

#endif
