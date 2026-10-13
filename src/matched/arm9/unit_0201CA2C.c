/*
 * unit:     yes
 * address:  0x0201CA2C
 * packet:   pkt_0201C8BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PRINTSYS_PutGlyph4bpp
 *
 * symbols:
 *   _pGlyphBmp   0x02146558  data
 *   GF_FONT_ReadGlyph  0x0201DB04  thumb
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_Blit  0x020439A0  arm
 *
 * One of the two printsys.c glyph blitters, both of which forward the caller's
 * pen record to GF_FONT_ReadGlyph and then hand the result to a renderer reached
 * through the module object at 0x02146558.  The pair is cut here rather than
 * matched as one range because GF_FONT_ReadGlyph is reached from exactly two places
 * in the image, 0x0201CA4C and 0x0201CA98, one in each function: matched
 * together neither site has a witness, matched apart each is the other's `label`
 * witness.  That is
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Its sibling at 0x0201CA78 stays parked (src/pending/PRINTSYS_PutGlyph8bpp.c): it calls
 * 0x02043AAC, and 0x0201CABC is the only branch to that address anywhere in the
 * image, so no cut reaches it.
 *
 * f is a four-byte pen record: f[0] is an x bias added to the caller's x, f[1]
 * and f[3] are passed straight through.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CA2C.c \
 *       --addr 0x0201CA2C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *_pGlyphBmp;

struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
struct Font;
extern void GF_FONT_ReadGlyph(struct Font *p, u16 ch, void *c, void *d);

void PRINTSYS_PutGlyph4bpp(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f)
{
    GF_FONT_ReadGlyph((struct Font *)d, e, BMP_GetPixels(_pGlyphBmp), (void *)f);
    BMP_Blit(_pGlyphBmp, a, 0, 0, b + f[0], c, f[1], f[3], 0);
}

