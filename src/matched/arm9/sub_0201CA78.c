/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: PRINTSYS_PutGlyph8bpp
 * address:  0x0201CA78
 * note:     80 bytes including two pool words, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * printsys.c's second glyph blitter, the twin of PRINTSYS_PutGlyph4bpp in
 * src/matched/unit_0201CA2C.c.  The two differ only in which renderer they
 * call and in the two extra stack arguments this one passes, 0xF and 0.
 *
 * Why it is capped: the `blx` at 0x0201CABC is the only branch to 0x02043AAC
 * anywhere in the image, checked over every Thumb BL/BLX pair and every ARM
 * branch in all 242 regions, and no pool word holds the address either.  The
 * `label` class therefore has no witness once the compared range holds that
 * call, and no cut helps, because the range cannot be smaller than this one
 * function.  Cutting it away from PRINTSYS_PutGlyph4bpp is what let that function come
 * out EXACT, since the two are the only callers of GF_FONT_ReadGlyph and each is
 * now the other's witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * It closes the day 0x02043AAC is matched (the `matched` class) or acquires a
 * second caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/PRINTSYS_PutGlyph8bpp.c \
 *       --addr 0x0201CA78 --thumb
 *
 * symbols:
 *   _pGlyphBmp   0x02146558  data
 *   GF_FONT_ReadGlyph  0x0201DB04  thumb
 *   BMP_BlitPaletteOffset  0x02043AAC  arm
 *   BMP_GetPixels  0x020437D4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *_pGlyphBmp;

struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
struct Font;
extern void BMP_BlitPaletteOffset(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);
extern void GF_FONT_ReadGlyph(struct Font *p, u16 ch, void *c, void *d);

void PRINTSYS_PutGlyph8bpp(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f)
{
    GF_FONT_ReadGlyph((struct Font *)d, e, BMP_GetPixels(_pGlyphBmp), (void *)f);
    BMP_BlitPaletteOffset(_pGlyphBmp, (u32)a, 0, 0, b + f[0], c, f[1], f[3], 0xF, 0);
}
