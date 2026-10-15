/*
 * function: NNSi_G2dCharCanvasDrawTextForVRAM
 * address:  0x02068808
 * packet:   pkt_020682DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dBlitCharData  0x02068430  arm
 *   NNSi_G2dCalcRectMask  0x020681E4  arm
 *
 * NitroSystem g2d_CharCanvas.c DrawGlyph1D(pCC, pFont, x, y, cl, pGlyph):
 * the OBJ-1D glyph draw.  Same clip as DrawGlyphLine (NNSi_G2dCharCanvasDrawText), but
 * each covered character's slot comes from GetCharIndex1D (NNSi_G2dCalcRectMask)
 * with the two OBJ size shifts packed in the low bytes of pCC->param (the
 * OBJ1DParam union { packed; baseWidthShift:8; baseHeightShift:8 }), and
 * each character is drawn by LetterChar (NNSi_G2dBlitCharData).
 *
 * Closed in wave 13 on the first compile of the library body; the wave-11
 * transcription sat at 168 out.  ../2.0/sp2 and sp2p2 identical; 1.1p1 is
 * 520 bytes.
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

extern void NNSi_G2dBlitCharData(LC_INFO *i);      /* LetterChar */

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
extern u32 NNSi_G2dCalcRectMask(u32 cx, u32 cy, u32 areaWidth, u32 areaHeight, u32 objWidth, u32 objHeight);   /* GetCharIndex1D */

void NNSi_G2dCharCanvasDrawTextForVRAM(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph)
{
    int ofs_x_base;
    int ofs_x;
    int ofs_y;
    int ofs_x_end;
    int ofs_y_end;
    int cx, cx_base;
    int cy;
    u8 glyphWidth;
    u8 charHeight;
    int charSize;
    u16 * mapTable;

    charSize = GetCharacterSize(pCC);
    mapTable = (u16 *)(pCC->param);

    {
        int chara_x_num;
        int chara_y_num;
        const unsigned int areaWidth = (unsigned int)pCC->areaWidth;
        const unsigned int areaHeight = (unsigned int)pCC->areaHeight;
        const NNSG2dCharWidths * const pWidth = pGlyph->pWidths;

        u32 chara_x_begin;
        u32 chara_x_last;
        u32 chara_y_begin;
        u32 chara_y_last;

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

        cx_base = (int)chara_x_begin;
        cy = (int)chara_y_begin;

        ofs_x_base = (x < 0) ? x: x & 0x7;
        ofs_y = (y < 0) ? y: y & 0x7;
        ofs_x_end = ofs_x_base - 8 * chara_x_num;
        ofs_y_end = ofs_y - 8 * chara_y_num;
    }

    {
        LC_INFO i;
        u8 * const pCharBase = pCC->charBase;
        OBJ1DParam p;

        i.src = pGlyph->image;
        i.width = glyphWidth;
        i.height = charHeight;
        i.cl = (u32)(cl - 1);
        i.srcBpp = NNS_G2dFontGetBpp(pFont);
        i.dstBpp = pCC->dstBpp;
        i.dsrc = NNS_G2dFontGetCellWidth(pFont) * i.srcBpp;

        p.packed = pCC->param;

        {
            const u32 areaWidth = (u32)pCC->areaWidth;
            const u32 areaHeight = (u32)pCC->areaHeight;
            const u32 baseWidthShift = p.baseWidthShift;
            const u32 baseHeightShift = p.baseHeightShift;

            for ( ; ofs_y > ofs_y_end; ofs_y -= 8) {
                i.ofs_y = ofs_y;
                cx = cx_base;
                for (ofs_x = ofs_x_base; ofs_x > ofs_x_end; ofs_x -= 8) {
                    const unsigned int iChar = NNSi_G2dCalcRectMask((u32)cx, (u32)cy, areaWidth, areaHeight, baseWidthShift, baseHeightShift);

                    i.ofs_x = ofs_x;
                    i.dst = pCharBase + iChar * charSize;

                    NNSi_G2dBlitCharData(&i);
                    cx++;
                }
                cy++;
            }
        }
    }
}
