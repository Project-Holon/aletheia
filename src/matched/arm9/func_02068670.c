/*
 * function: func_02068670
 * address:  0x02068670
 * packet:   pkt_020682DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02068430  0x02068430  arm
 *
 * NitroSystem g2d_CharCanvas.c DrawGlyphLine(pCC, pFont, x, y, cl, pGlyph):
 * the BG / OBJ-2D-rect glyph draw.  Clip the glyph to the canvas in whole
 * 8x8 characters, then walk the covered characters row by row on the
 * canvas's linear character grid (pCC->param = characters per row),
 * handing each to LetterChar (func_02068430) with an LC_INFO on the stack.
 * pCC is NNSG2dCharCanvas { charBase, areaWidth, areaHeight, u8 dstBpp,
 * param, vtable } (the "Surface" of docs/families/cluster_020682DC.h);
 * cell width / height / bpp come from pFont->pRes->pGlyph (FGLP).
 *
 * Closed in wave 13 on the first compile of the library body with its
 * inlines (GetCharacterSize, NNS_G2dFontGetCellHeight / CellWidth / Bpp);
 * the wave-11 transcription sat at 238 out on a spill choice.  ../2.0/sp2
 * and sp2p2 identical; 1.1p1 is 404 bytes.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct LC_INFO {
    const u8 *dst;
    const u8 *src;
    int ofs_x;
    int ofs_y;
    int width;
    int height;
    int dsrc;
    int srcBpp;
    int dstBpp;
    u32 cl;
} LC_INFO;

typedef union OBJ1DParam {
    u32 packed;
    struct {
        unsigned baseWidthShift :8;
        unsigned baseHeightShift :8;
    };
} OBJ1DParam;

typedef struct NNSG2dCharWidths {
    s8 left;
    u8 glyphWidth;
    s8 charWidth;
} NNSG2dCharWidths;

typedef struct NNSG2dFontGlyph {
    u8 cellWidth;
    u8 cellHeight;
    u16 cellSize;
    s8 baselinePos;
    u8 maxCharWidth;
    u8 bpp;
    u8 flags;
} NNSG2dFontGlyph;

typedef struct NNSG2dFontInformation {
    u8 fontType;
    s8 linefeed;
    u16 alterCharIndex;
    NNSG2dCharWidths defaultWidth;
    u8 encoding;
    NNSG2dFontGlyph *pGlyph;
    void *pWidth;
    void *pMap;
} NNSG2dFontInformation;

typedef struct NNSG2dFont {
    NNSG2dFontInformation *pRes;
    void *cbCharSpliter;
} NNSG2dFont;

typedef struct NNSG2dGlyph {
    const NNSG2dCharWidths *pWidths;
    const u8 *image;
} NNSG2dGlyph;

typedef struct NNSG2dCharCanvas {
    u8 *charBase;
    int areaWidth;
    int areaHeight;
    u8 dstBpp;
    u8 reserved[3];
    u32 param;
    const void *vtable;
} NNSG2dCharCanvas;

extern void func_02068430(LC_INFO *i);      /* LetterChar */

static inline int GetCharacterSize(const NNSG2dCharCanvas *pCC)
{
    return 8 * 8 * pCC->dstBpp / 8;
}

static inline u8 NNS_G2dFontGetCellHeight(const NNSG2dFont *pFont)
{
    return pFont->pRes->pGlyph->cellHeight;
}

static inline u8 NNS_G2dFontGetCellWidth(const NNSG2dFont *pFont)
{
    return pFont->pRes->pGlyph->cellWidth;
}

static inline u8 NNS_G2dFontGetBpp(const NNSG2dFont *pFont)
{
    return pFont->pRes->pGlyph->bpp;
}
void func_02068670(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph)
{
    int ofs_x_base;
    int ofs_x;
    int ofs_y;
    int ofs_x_end;
    int ofs_y_end;
    unsigned int nextLineOffset;
    u8 * pChar;
    u8 glyphWidth;
    u8 charHeight;
    int charSize;

    charSize = GetCharacterSize(pCC);

    {
        int chara_x_num;
        int chara_y_num;
        const unsigned int areaWidth = (unsigned int)pCC->areaWidth;
        const unsigned int areaHeight = (unsigned int)pCC->areaHeight;
        u8 * const charBase = pCC->charBase;
        const NNSG2dCharWidths * const pWidth = pGlyph->pWidths;

        unsigned int chara_x_begin;
        unsigned int chara_x_last;
        unsigned int chara_y_begin;
        unsigned int chara_y_last;

        glyphWidth = pWidth->glyphWidth;
        charHeight = NNS_G2dFontGetCellHeight(pFont);

        if ( glyphWidth <= 0 ) {
            return;
        }

        if ((x + glyphWidth < 0) || (y + charHeight) < 0 ) {
            return;
        }

        chara_x_begin = (x <= 0) ? 0: ((u32)x / 8);
        chara_y_begin = (y <= 0) ? 0: ((u32)y / 8);

        chara_x_last = (u32)(x + glyphWidth + (8 - 1)) / 8;
        if ( chara_x_last >= areaWidth ) {
            chara_x_last = areaWidth;
        }
        chara_y_last = (u32)(y + charHeight + (8 - 1)) / 8;
        if ( chara_y_last >= areaHeight ) {
            chara_y_last = areaHeight;
        }

        chara_x_num = (int)(chara_x_last - chara_x_begin);
        chara_y_num = (int)(chara_y_last - chara_y_begin);

        if ((chara_x_num < 0) || (chara_y_num < 0)) {
            return;
        }

        pChar = charBase + (pCC->param * chara_y_begin + chara_x_begin) * charSize;

        nextLineOffset = (pCC->param - chara_x_num) * charSize;

        ofs_x_base = (x < 0) ? x: x & 0x7;
        ofs_y = (y < 0) ? y: y & 0x7;
        ofs_x_end = ofs_x_base - 8 * chara_x_num;
        ofs_y_end = ofs_y - 8 * chara_y_num;
    }

    {
        LC_INFO i;

        i.src = pGlyph->image;
        i.width = glyphWidth;
        i.height = charHeight;
        i.cl = (u32)(cl - 1);
        i.srcBpp = NNS_G2dFontGetBpp(pFont);
        i.dstBpp = pCC->dstBpp;
        i.dsrc = NNS_G2dFontGetCellWidth(pFont) * i.srcBpp;

        for ( ; ofs_y > ofs_y_end; ofs_y -= 8) {
            i.ofs_y = ofs_y;
            for (ofs_x = ofs_x_base; ofs_x > ofs_x_end; ofs_x -= 8) {
                i.dst = pChar;
                i.ofs_x = ofs_x;
                func_02068430(&i);
                pChar += charSize;
            }
            pChar += nextLineOffset;
        }
    }
}
