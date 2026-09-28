/*
 * function: func_020680DC
 * address:  0x020680DC
 * packet:   pkt_02067FE4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NNS_G2dFontGetTextHeight (NitroSystem g2d_Font.c): count lines (1 plus one
 * per '\n') and return lines * (vSpace + linefeed) - vSpace.  FINF +0x01
 * linefeed is s8 (`ldrsb`).
 *
 * The two dead zero stores at [sp]/[sp+4] through `add r4, sp, #0` are an
 * unused `NNSG2dTextRect rect = {0, 0}`, the same aggregate initialiser
 * func_02068150 uses live.  `vSpace + linefeed` in that operand order
 * (`add r0, r4, r0`); the other order is 2 bytes out.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image rematerialises the cursor address, `add r0, sp, #8` at 0x02068100
 * and `add r5, sp, #8` at 0x02068118; dsi/1.1p1 hoists one `add r5, sp, #8`
 * and schedules the prologue differently, 49 concrete bytes out at 116.
 * 0 mismatches under the pin.  Supersedes src/pending/func_020680DC.c
 * (DIFF 5, a different reading).
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

int func_020680DC(const NNSG2dFont *pFont, int vSpace, const void *txt)
{
    const void *pos = txt;
    NNSG2dTextRect rect = { 0, 0 };
    int lines = 1;
    u16 (*getNextChar)(const void **);
    u16 c;

    getNextChar = pFont->cbCharSpliter;
    while ((c = getNextChar(&pos)) != 0) {
        if (c == '\n')
            lines++;
    }
    return lines * (vSpace + pFont->pRes->linefeed) - vSpace;
}
