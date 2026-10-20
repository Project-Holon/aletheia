#ifndef GAME_ARM9_GF_FONT_H
#define GAME_ARM9_GF_FONT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gf_font.c, prototypes copied from their definitions. */

struct GfFont;
struct BitReader;
struct WordSet;

#include "../types.h"

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
/* END mkheaders: generated region */

#endif
