/*
 * function: GF_FONT_InitStreamedGlyphs
 * address:  0x0201DAA4
 * packet:   pkt_0201DA24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_ReadStreamedGlyph  0x0201DBF4  thumb
 *   GF_FONT_DecodeGlyph8x8  0x0201DE40  thumb
 *   GF_FONT_DecodeGlyph8x16  0x0201E538  thumb
 *   GF_FONT_DecodeGlyph16x8  0x0201E738  thumb
 *   GF_FONT_DecodeGlyph16x16  0x0201E928  thumb
 *
 * gf_font.c's format-1 hook installer: clears +0xC, plants the shared measure
 * hook GF_FONT_ReadStreamedGlyph at +4, and picks one of four glyph decoders for +8 on the
 * 2x2 cross of the two flags (a == 1 selects the first pair, b == 1 the first
 * of each pair).  src/matched/GF_FONT_DecodeGlyph8x8.c is the (1,1) decoder.
 *
 * Promoted 2026-09-21.  The file was parked at MATCH with the last pool word
 * declared as `func_0201E938`, an address that is NOT a function start: it is
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
#include "../include/Obj06870.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
struct Font;
extern void GF_FONT_ReadStreamedGlyph(const struct Font *f, u32 i, void *d, u8 *out);
extern void GF_FONT_DecodeGlyph8x8(const u8 *src, u32 n, u16 *dst);
extern void GF_FONT_DecodeGlyph8x16(const u8 *src, u32 n, u16 *dst);
extern void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 n, u16 *dst);
extern void GF_FONT_DecodeGlyph16x16(const u8 *src, u32 n, u16 *dst);

void GF_FONT_InitStreamedGlyphs(char *p, int a, int b)
{
    ((struct Obj06870 *)p)->fC = 0;
    ((struct Obj06870 *)p)->f4 = (u32)GF_FONT_ReadStreamedGlyph;
    if (a == 1)
        ((struct Obj06870 *)p)->f8 = (b == 1) ? (u32)GF_FONT_DecodeGlyph8x8 : (u32)GF_FONT_DecodeGlyph8x16;
    else
        ((struct Obj06870 *)p)->f8 = (b == 1) ? (u32)GF_FONT_DecodeGlyph16x8 : (u32)GF_FONT_DecodeGlyph16x16;
}
