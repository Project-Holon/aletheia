/*
 * function: func_02068030
 * address:  0x02068030
 * packet:   pkt_02067FE4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02067F9C    0x02067F9C  arm
 *   func_02067FE4    0x02067FE4  arm
 *
 * NNS_G2dFontGetStringWidth (NitroSystem g2d_Font.c): width of one line of
 * text, stopping at NUL or '\n'; the spliter callback advances a cursor held
 * in a stack slot.  *pPos gets the cursor after a newline, NULL at end of
 * string, and one trailing hSpace is removed.  func_02067F9C is
 * NNS_G2dFontGetGlyphIndex (0xFFFF = not found -> alterCharIndex),
 * func_02067FE4 NNS_G2dFontGetCharWidthsFromIndex.
 *
 * The cursor is a LOCAL COPY of the string argument (`str = txt`): taking
 * the address of the parameter itself spills all four argument registers
 * (`push {r0, r1, r2, r3}`), which the image does not have.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image rematerialises the cursor address, `add r0, sp, #0` at 0x02068044
 * and again `add sl, sp, #0` at 0x02068064; dsi/1.1p1 CSEs it into r4
 * (`add r4, sp, #0` / `mov r0, r4`), which permutes every callee-saved
 * register, 47 concrete bytes out at 172.  0 mismatches under the pin.
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

extern u16 func_02067F9C(const NNSG2dFont *pFont, u16 c);
extern const struct NNSG2dCharWidths *func_02067FE4(const struct NNSG2dFont *pFont, u32 idx);

static inline int GetCharWidth(const NNSG2dFont *pFont, u16 c)
{
    u16 index = func_02067F9C(pFont, c);
    if (index == 0xFFFF)
        index = pFont->pRes->alterCharIndex;
    return func_02067FE4(pFont, index)->charWidth;
}

int func_02068030(const NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos)
{
    const void *str = txt;
    int width = 0;
    u16 (*getNextChar)(const void **);
    u16 c;

    getNextChar = pFont->cbCharSpliter;

    while ((c = getNextChar(&str)) != 0) {
        if (c == '\n')
            break;
        width += GetCharWidth(pFont, c) + hSpace;
    }
    if (pPos != 0)
        *pPos = (c == '\n') ? str : 0;
    if (width > 0)
        width -= hSpace;
    return width;
}
