/*
 * function: func_02067FE4
 * address:  0x02067FE4
 * packet:   pkt_02067FE4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NNS_G2dFontGetCharWidthsFromIndex (NitroSystem g2d_Font.c): walk the
 * font's width-block chain (FINF +0x0C) and return the 3-byte width entry of
 * the block whose [indexBegin, indexEnd] holds idx, else &FINF->defaultWidth.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * keeps `bhi 0x0206801C` at 0x02068004 over the unpredicated four-instruction
 * return (sub/add/add/add + bx lr at 0x02068008..0x02068018); dsi/1.1p1
 * predicates it (subls/addls/addls/addls/bxls) and is 72 bytes against 76.
 * The same C is 76 bytes, 0 mismatches under the pin.
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

const NNSG2dCharWidths *func_02067FE4(const NNSG2dFont *pFont, u32 idx)
{
    const NNSG2dFontWidth *pWidth = pFont->pRes->pWidth;

    while (pWidth != 0) {
        if (pWidth->indexBegin <= idx && idx <= pWidth->indexEnd)
            return &pWidth->widthTable[idx - pWidth->indexBegin];
        pWidth = pWidth->pNext;
    }
    return &pFont->pRes->defaultWidth;
}
