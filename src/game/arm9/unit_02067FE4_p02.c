/*
 * file:     unit_02067FE4_p02.c
 * unit:     yes
 * function: func_020682F8, func_02068430, func_02068670, func_02068808, func_02068A18, func_02068A68
 * address:  0x020682F8
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082AC0    0x02082AC0  arm
 *   func_02069BA0  0x02069BA0  arm
 *   func_020681E4  0x020681E4  arm
 */
struct BitReader;
typedef unsigned int u32;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned long long u64;

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

typedef struct NNSiG2dBitReader {
    const u8 *src;
    s8 availableBits;
    u8 bits;
    u8 padding_[2];
} NNSiG2dBitReader;

typedef unsigned short u16;

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

typedef struct NNSG2dFontWidth {
    u16 indexBegin;                     /* +0 */
    u16 indexEnd;                       /* +2 */
    struct NNSG2dFontWidth *pNext;      /* +4 */
    NNSG2dCharWidths widthTable[1];     /* +8, 3-byte entries */
} NNSG2dFontWidth;

	typedef struct NNSG2dFontInformation {
    u8 fontType;
    s8 linefeed;
    u16 alterCharIndex;
    NNSG2dCharWidths defaultWidth;
    u8 encoding;
    NNSG2dFontGlyph *pGlyph;
    NNSG2dFontWidth *pWidth;
    void *pMap;
} NNSG2dFontInformation;

typedef struct NNSG2dFont {
    NNSG2dFontInformation *pRes;
    u16 (*cbCharSpliter)(const void **ppChar);
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

struct Surface {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C  4 or 8 */
    int   stride; /* +0x10 */
};

extern void func_02082AC0(u32 data, void *dst, int size);
extern u32 func_02069BA0(struct BitReader *reader, int nBits);   /* NNSi_G2dBitReaderRead */
extern u32 func_020681E4(u32 cx, u32 cy, u32 areaWidth, u32 areaHeight, u32 objWidth, u32 objHeight);   /* GetCharIndex1D */
void func_020682F8(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);
void func_02068430(LC_INFO *i);
void func_02068670(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void func_02068808(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void func_02068A18(struct Surface *s, u32 arg);
void func_02068A68(struct Surface *s, u32 arg);




/*
 * Fill a sub-rectangle of ONE 8x8 tile with a pixel word.  dst is the tile,
 * (x, y) the sub-rectangle's offset inside it, (w, h) its extent, val the
 * expanded pixel word (func_02068A18's expansion) and bpp 4 or 8.  A whole
 * tile goes to func_02082AC0 (MIi_CpuClearFast) in one call; otherwise each
 * of the h rows is masked in place, one word per row at 4bpp and two at
 * 8bpp, where the 64-bit row mask is built longhand from two 32-bit halves
 * with the >= 32 shift cases spelled out.  Called seven-argument from
 * func_02068AE8 and func_02068C84.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * keeps `blo` over both four-instruction >= 32 blocks (0x020683A4,
 * 0x020683C8); 1.1p1 predicates them and is 304 bytes against 312.
 *
 * Levers, after the note docs/notes/pkt_020682F8.c.txt had the push one
 * register too wide under the pin (63 bytes out):
 *   - u and the 64 - (u + w*8) remainder are UNSIGNED (`blo`, not `blt`);
 *   - in the 8bpp arm the remainder is NOT held in a local across the arm:
 *     it is named once for the first test (`r`) and written out again at
 *     each later use.  Holding it live is what cost the third callee-saved
 *     register (found by tools/permuter.py, expand(v));
 *   - the 4bpp mask is built in two statements (m = ~0 >> u; m <<= ...);
 *   - declaration order `set` before `end` (4bpp) and `slo, shi, p, end`
 *     (8bpp) picks the image's registers for the fill values and the bound.
 */
void func_020682F8(u32 *dst, int x, int y, int w, int h, u32 val, int bpp)
{
    if (w == 8 && h == 8) {
        func_02082AC0(val, dst, bpp << 3);
        return;
    }
    if (bpp == 4) {
        int u = x << 2;
        int v = 0x20 - (u + (w << 2));
        u32 m = 0xFFFFFFFF >> u;
        u32 *p;
        u32 set;
        u32 *end;

        m = m << (v + (x << 2));
        p = dst + y;
        end = p + h;
        set = val & (m >> v);
        m = ~(m >> v);
        while (p < end) {
            *p = set | (*p & m);
            p++;
        }
    } else {
        u32 u = x << 3;
        u32 lo = 0xFFFFFFFF >> u;
        u32 hi;
        u32 slo;
        u32 shi;
        u32 *p;
        u32 *end;
        u32 e;
        u32 r;

        r = 0x40 - (u + (w << 3));
        if (r < 0x20) {
            lo = lo << u;
        } else {
            e = r - 0x20;
            lo = (lo << (u + e)) >> e;
        }
        hi = 0xFFFFFFFF << (0x40 - (u + (w << 3)));
        if (u < 0x20) {
            hi = hi >> (0x40 - (u + (w << 3)));
        } else {
            e = u - 0x20;
            hi = (hi >> (e + (0x40 - (u + (w << 3))))) << e;
        }
        p = dst + y * 2;
        end = p + h * 2;
        slo = val & lo;
        shi = val & hi;
        lo = ~lo;
        hi = ~hi;
        while (p < end) {
            p[0] = slo | (p[0] & lo);
            p[1] = shi | (p[1] & hi);
            p += 2;
        }
    }
}



static inline int MATH_IMax(int a, int b)
{
    return (a >= b) ? a : b;
}


static inline int MATH_IMin(int a, int b)
{
    return (a <= b) ? a : b;
}



static inline void NNSi_G2dBitReaderInit(NNSiG2dBitReader *reader, const void *src)
{
    reader->availableBits = 0;
    reader->src = (const u8 *)src;
    reader->bits = 0;
}



/*
 * NitroSystem g2d_CharCanvas.c LetterChar(LC_INFO *): blit one glyph's
 * bit-packed pixels into one 8x8 character, clipped to the character, at 4
 * or 8 bits per destination pixel, adding the colour base cl to every
 * non-zero source value.  Each row opens an NNSiG2dBitReader at
 * src + offset / 8 and discards offset % 8 bits first
 * (NNSi_G2dBitReaderRead = func_02069BA0).  The LC_INFO block is the
 * ten-word "Blit" struct of docs/families/cluster_020682DC.h.
 *
 * Closed in wave 13 on the first compile of the library body with the
 * TwlSDK MATH_IMax / MATH_IMin inlines and NNSi_G2dBitReaderInit; the
 * wave-11 transcription sat at 119 out.  ../2.0/sp2 and sp2p2 identical;
 * 1.1p1 is 564 bytes.
 */
void func_02068430(LC_INFO *i)
{
    const u8 *pSrc;
    u32 x_st;
    u32 x_ed;
    u32 y_st;
    u32 y_ed;
    u32 offset;

    {
        u32 bit_y_begin;

        x_st = (unsigned int)MATH_IMax(i->ofs_x, 0);
        y_st = (unsigned int)MATH_IMax(i->ofs_y, 0);
        x_ed = (unsigned int)MATH_IMin(8, i->ofs_x + i->width);
        y_ed = (unsigned int)MATH_IMin(8, i->ofs_y + i->height);

        bit_y_begin = (unsigned int)-MATH_IMin(i->ofs_y, 0);
        offset = -MATH_IMin(i->ofs_x, 0) * i->srcBpp + bit_y_begin * i->dsrc;

        pSrc = i->src;
    }

    {
        u32 x;
        const int dsrc = i->dsrc;
        const int srcBpp = i->srcBpp;
        const int dstBpp = i->dstBpp;

        x_st *= dstBpp;
        x_ed *= dstBpp;

        if ( dstBpp == 4 ) {
            u32 *pDst = (u32 *)i->dst + y_st;
            u32 *pDstEnd = (u32 *)i->dst + y_ed;
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst++) {
                NNSiG2dBitReader reader;
                u32 out_line = *pDst;

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)func_02069BA0((struct BitReader *)(&reader), (int)offset % 8);

                for (x = x_st; x < x_ed; x += 4) {
                    u32 bits = func_02069BA0((struct BitReader *)(&reader), srcBpp);

                    if ( bits != 0 ) {
                        out_line = (out_line & ~(0xF << x)) | ((cl + bits) << x);
                    }
                }

                *pDst = out_line;

                offset += dsrc;
            }
        } else {
            u32 *pDst = (u32 *)((u64 *)i->dst + y_st);
            u32 * const pDstEnd = (u32 *)((u64 *)i->dst + y_ed);
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst += 2) {
                NNSiG2dBitReader reader;
                u32 out_line_0 = *pDst;
                u32 out_line_1 = *(pDst + 1);

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)func_02069BA0((struct BitReader *)(&reader), (int)offset % 8);

                for (x = x_st; x < x_ed; x += 8) {
                    u32 bits = func_02069BA0((struct BitReader *)(&reader), srcBpp);

                    if ( bits != 0 ) {
                        if ( x < 32 ) {
                            out_line_0 = (out_line_0 & ~((u32)0xFF << x)) | ((u32)(cl + bits) << x);
                        } else {
                            const u32 x_32 = x - 32;
                            out_line_1 = (out_line_1 & ~((u32)0xFF << x_32)) | ((u32)(cl + bits) << x_32);
                        }
                    }
                }

                *pDst = out_line_0;
                *(pDst + 1) = out_line_1;

                offset += dsrc;
            }
        }
    }
}



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



/*
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



/*
 * NitroSystem g2d_CharCanvas.c DrawGlyph1D(pCC, pFont, x, y, cl, pGlyph):
 * the OBJ-1D glyph draw.  Same clip as DrawGlyphLine (func_02068670), but
 * each covered character's slot comes from GetCharIndex1D (func_020681E4)
 * with the two OBJ size shifts packed in the low bytes of pCC->param (the
 * OBJ1DParam union { packed; baseWidthShift:8; baseHeightShift:8 }), and
 * each character is drawn by LetterChar (func_02068430).
 *
 * Closed in wave 13 on the first compile of the library body; the wave-11
 * transcription sat at 168 out.  ../2.0/sp2 and sp2p2 identical; 1.1p1 is
 * 520 bytes.
 */
void func_02068808(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph)
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
                    const unsigned int iChar = func_020681E4((u32)cx, (u32)cy, areaWidth, areaHeight, baseWidthShift, baseHeightShift);

                    i.ofs_x = ofs_x;
                    i.dst = pCharBase + iChar * charSize;

                    func_02068430(&i);
                    cx++;
                }
                cy++;
            }
        }
    }
}



/*
 * Clear a linear surface to one pixel value: expand the value to a full word
 * (4bpp doubles the nibble, then the byte; 8bpp doubles the byte; both then
 * double the halfword) and hand w * h * bytes-per-pixel-row-unit to
 * func_02082AC0 (MIi_CpuClearFast(data, dest, size) in the SDK map).
 *
 * THE LEVER that closed this row after five DIFF passes
 * (docs/notes/pkt_02068808.c.txt): the final `| (t << 16)` step is written
 * INSIDE BOTH ARMS, not after the if/else.  Written once after the join, the
 * two arms' shared `| (x << 8)` step is tail-merged (68 bytes) or the arms
 * write the parameter in place and the orrne is sunk (76 bytes).  With the
 * <<16 duplicated, the compiler tail-merges exactly that one step back out
 * and the arms stay predicated into a temporary (orreq/orreq/orrne r0) with
 * the result landing in the parameter's own register (orr r1, r0, r0, lsl
 * #16), which is the image.  The `n = w * h` partial product must be its own
 * statement.
 */
void func_02068A18(struct Surface *s, u32 arg)
{
    int bpp = s->bpp;
    u32 t;
    int n;

    if (bpp == 4) {
        t = arg | (arg << 4);
        t = t | (t << 8);
        arg = t | (t << 16);
    } else {
        t = arg | (arg << 8);
        arg = t | (t << 16);
    }
    n = s->w * s->h;
    func_02082AC0(arg, s->base, n * ((bpp << 6) / 8));
}



/*
 * Row-by-row twin of func_02068A18: the same pixel expansion, then one
 * func_02082AC0 (MIi_CpuClearFast) per row of w * tile-size bytes, stepping
 * the destination by stride * tile-size.  The row count is re-read from +0x08
 * each iteration (the call may alias it) and compared signed.
 *
 * Two levers: the `| (t << 16)` step is written in BOTH arms (see
 * func_02068A18), and `dst = s->base` is assigned AFTER the two products,
 * immediately before the loop.  Initialising dst in its declaration gives the
 * same bytes with dst in r5 instead of sb (24 bytes out); the late assignment
 * is what makes it the last value the allocator colours.
 */
void func_02068A68(struct Surface *s, u32 arg)
{
    int i, n, adv, tsz;
    int bpp = s->bpp;
    char *dst;
    u32 t;

    if (bpp == 4) {
        t = arg | (arg << 4);
        t = t | (t << 8);
        arg = t | (t << 16);
    } else {
        t = arg | (arg << 8);
        arg = t | (t << 16);
    }
    tsz = (bpp << 6) / 8;
    adv = tsz * s->stride;
    n = tsz * s->w;
    dst = s->base;
    for (i = 0; i < s->h; i++) {
        func_02082AC0(arg, dst, n);
        dst += adv;
    }
}
