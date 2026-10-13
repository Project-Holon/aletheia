/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: PRINTSYS_SetupJob
 * address:  0x0201C808
 * note:     156 bytes including five pool words, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * printsys.c's render-context set-up: it records the surface and the string,
 * picks the blitter, packs the pen position into two ten bit fields of the
 * word at +4 and snapshots the current text colour into +0xC and +0xE.
 *
 * The two blitter addresses are the reason this is parked.  0x0201CA2C and
 * 0x0201CA78 are reached only through the two pool words in this function's
 * own literal pool, so `literal` discards both witnesses under the honesty
 * rule and no cut helps.  The `matched` class covers 0x0201CA2C now
 * (src/matched/unit_0201CA2C.c) but not 0x0201CA78, which is parked in
 * src/pending/PRINTSYS_PutGlyph8bpp.c for a reason of its own.  This file graduates
 * with that one.
 *
 * Two details worth keeping.  The three edits of the word at +4 are plain
 * integer mask-and-or arithmetic, the same spelling
 * src/matched/unit_0201C8A4.c uses, and the compiler writes the field only
 * twice for three statements because it keeps the value in a register across
 * the last two.  And the pen coordinates are read back out of the halfwords
 * that were just stored, with `ldrsh` and a register offset, which is the only
 * evidence that +0 and +2 are signed
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/PRINTSYS_SetupJob.c \
 *       --addr 0x0201C808 --thumb
 *
 * symbols:
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   BMP_GetTileBytes  0x02043994  arm
 *   PRINTSYS_PutGlyph4bpp  0x0201CA2C  thumb
 *   PRINTSYS_PutGlyph8bpp  0x0201CA78  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct PrintCtx {
    s16 unk00;
    s16 unk02;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

typedef signed int     s32;
struct Bmp;
extern u8 BMP_GetTileBytes(struct Bmp *b);
extern void GF_FONT_GetTextColor(u8 *r, u8 *g, u8 *b);
extern void PRINTSYS_PutGlyph4bpp(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f);
extern void PRINTSYS_PutGlyph8bpp(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f);

void PRINTSYS_SetupJob(struct PrintCtx *p, void *w, void *x, u32 y, s16 z)
{
    u8 t[3];

    p->unk14 = x;
    if (BMP_GetTileBytes(x) == 0x20) {
        p->unk18 = (void *)PRINTSYS_PutGlyph4bpp;
    } else {
        p->unk18 = (void *)PRINTSYS_PutGlyph8bpp;
    }
    p->unk10 = w;
    p->unk00 = y;
    p->unk04 = (p->unk04 & 0xFFFFFC00u) | (p->unk00 & 0x3FF);
    p->unk02 = z;
    p->unk04 = (p->unk04 & 0xFFF003FFu) | ((p->unk02 & 0x3FF) << 10);
    p->unk04 = (p->unk04 & 0xFF0FFFFFu) | (1u << 20);
    GF_FONT_GetTextColor(&t[2], &t[1], &t[0]);
    p->unk0C = (u16)(((t[2] & 0x1F) << 10) | ((t[1] & 0x1F) << 5)
                     | (t[0] & 0x1F));
    p->unk0E = p->unk0C;
}
