/*
 * function: NNS_G2dFontGetTextRect
 * address:  0x02068150
 * packet:   pkt_02067FE4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dFontGetStringWidth    0x02068030  arm
 *
 * NNS_G2dFontGetTextRect (NitroSystem g2d_Font.c), struct return through the
 * hidden r0 pointer: widest line via NNS_G2dFontGetStringWidth (threading its pPos back
 * in as the next line), height = (lines - 1) * (vSpace + linefeed) - vSpace
 * with the counter starting at ONE (`mov r4, #1` / `sub r2, r4, #1`); a
 * counter from zero is 140 bytes against 148.
 *
 * COMPILER PIN ../2.0/sp2 (docs/FRONTEND-PINS.md): the same C under
 * dsi/1.1p1 is 148 bytes with exactly 8 out, the two stores at the tail
 * swapped: the image writes the height into the local first, `str r1,
 * [sp, #4]` at 0x020681D4, then `stm r8, {r0, r1}` at 0x020681D8; 1.1p1
 * issues the stm first.  0 mismatches under the pin.
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* NitroSystem g2d font resource (NNSG2dFontInformation, the FINF block) and
 * the runtime font handle.  Offsets pinned by this file's own loads. */
typedef struct NNSG2dCharWidths {
    s8 left;            /* +0 */
    u8 glyphWidth;      /* +1 */
    s8 charWidth;       /* +2  ldrsb */
} NNSG2dCharWidths;

typedef struct NNSG2dFontWidth {
    u16 indexBegin;                     /* +0 */
    u16 indexEnd;                       /* +2 */
    struct NNSG2dFontWidth *pNext;      /* +4 */
    NNSG2dCharWidths widthTable[1];     /* +8, 3-byte entries */
} NNSG2dFontWidth;

typedef struct NNSG2dFontInformation {
    u8  fontType;                   /* +0x00 */
    s8  linefeed;                   /* +0x01  ldrsb */
    u16 alterCharIndex;             /* +0x02 */
    NNSG2dCharWidths defaultWidth;  /* +0x04 */
    u8  encoding;                   /* +0x07 */
    void *pGlyph;                   /* +0x08 */
    NNSG2dFontWidth *pWidth;        /* +0x0C */
    void *pMap;                     /* +0x10 */
} NNSG2dFontInformation;

typedef struct NNSG2dFont {
    NNSG2dFontInformation *pRes;                /* +0 */
    u16 (*cbCharSpliter)(const void **ppChar);  /* +4, called through blx */
} NNSG2dFont;

typedef struct NNSG2dTextRect { int width; int height; } NNSG2dTextRect;

extern int NNS_G2dFontGetStringWidth(const NNSG2dFont *pFont, int hSpace, const void *str, const void **pPos);

NNSG2dTextRect NNS_G2dFontGetTextRect(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt)
{
    NNSG2dTextRect rect = { 0, 0 };
    int numLine = 1;

    while (txt != 0) {
        const int width = NNS_G2dFontGetStringWidth(pFont, hSpace, txt, &txt);
        if (width > rect.width)
            rect.width = width;
        numLine++;
    }
    rect.height = (numLine - 1) * (vSpace + pFont->pRes->linefeed) - vSpace;
    return rect;
}
