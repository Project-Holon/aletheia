/*
 * file:     unit_02067FE4_p01.c
 * unit:     yes
 * function: func_02067FE4, func_02068030, func_020680DC, func_02068150, func_020681E4, func_020682DC, func_020682F8, func_02068430, func_02068670, func_02068808, func_02068A18, func_02068A68, func_02068AE8, func_02068C84, func_02068E78, func_02068EA0, func_02068FC4
 * address:  0x02067FE4
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
 *   func_02067F9C    0x02067F9C  arm
 *   g_020A18F4     0x020A18F4  data
 *   g_020A1914     0x020A1914  data
 *   func_02082AC0    0x02082AC0  arm
 *   func_02069BA0  0x02069BA0  arm
 */
struct BitReader;
struct Pen;
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
    u8  fontType;                   /* +0x00 */
    s8  linefeed;                   /* +0x01  ldrsb */
    u16 alterCharIndex;             /* +0x02 */
    NNSG2dCharWidths defaultWidth;  /* +0x04 */
    u8  encoding;                   /* +0x07 */
    NNSG2dFontGlyph *pGlyph;        /* +0x08 */
    NNSG2dFontWidth *pWidth;        /* +0x0C */
    void *pMap;                     /* +0x10 */
} NNSG2dFontInformation;

typedef struct NNSG2dFont {
    NNSG2dFontInformation *pRes;                /* +0 */
    u16 (*cbCharSpliter)(const void **ppChar);  /* +4, called through blx */
} NNSG2dFont;

typedef struct NNSG2dTextRect { int width; int height; } NNSG2dTextRect;

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

typedef union OBJ1DParam {
    u32 packed;
    struct {
        unsigned baseWidthShift :8;
        unsigned baseHeightShift :8;
    };
} OBJ1DParam;

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

struct Surface_02068AE8 {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C */
    int   f10;    /* +0x10 stride in tiles */
};

struct Swz { u32 x : 8; u32 y : 8; u32 rest : 16; };

struct Surface_02068C84 {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C */
    struct Swz f10; /* +0x10 */
};

struct Pen {
    void *f00;
    int  f04;
    int  f08;
    u8   f0c;
    u8   pad0d[3];
    int  f10;
    const void *f14;
};

struct Ctx { u8 pad[0x14]; void **vt; };

extern u16 func_02067F9C(const NNSG2dFont *pFont, u16 c);
extern void func_02082AC0(u32 data, void *dst, int size);
extern u32 func_02069BA0(struct BitReader *reader, int nBits);   /* NNSi_G2dBitReaderRead */
const NNSG2dCharWidths *func_02067FE4(const NNSG2dFont *pFont, u32 idx);
int func_02068030(const NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos);
int func_020680DC(const NNSG2dFont *pFont, int vSpace, const void *txt);
NNSG2dTextRect func_02068150(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt);
int func_020681E4(int x, int y, int w, int h, int sw0, int sh0);
u32 func_020682DC(const u8 *p);
void func_020682F8(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);
void func_02068430(LC_INFO *i);
void func_02068670(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void func_02068808(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void func_02068A18(struct Surface *s, u32 arg);
void func_02068A68(struct Surface *s, u32 arg);
void func_02068AE8(struct Surface_02068AE8 *s, u32 arg, int x, int y, int w, int h);
void func_02068C84(struct Surface_02068C84 *s, u32 arg, int x, int y, int w, int h);
void func_02068E78(struct Pen *p, void *a1, int a2, int a3, int a5, const void *a6, int a7);
s8 func_02068EA0(struct Ctx *ctx, NNSG2dFont *font, int x, int y, int a6, u16 code);
void func_02068FC4(int a, int b, int c, int d, int e);
extern const u8 g_020A18F4[4][4][2];
extern u32 g_020A1914[][4];







/*
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







static inline int GetCharWidth(const NNSG2dFont *pFont, u16 c)
{
    u16 index = func_02067F9C(pFont, c);
    if (index == 0xFFFF)
        index = pFont->pRes->alterCharIndex;
    return func_02067FE4(pFont, index)->charWidth;
}







/*
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







/*
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






/*
 * NNS_G2dFontGetTextRect (NitroSystem g2d_Font.c), struct return through the
 * hidden r0 pointer: widest line via func_02068030 (threading its pPos back
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
NNSG2dTextRect func_02068150(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt)
{
    NNSG2dTextRect rect = { 0, 0 };
    int numLine = 1;

    while (txt != 0) {
        const int width = func_02068030(pFont, hSpace, txt, &txt);
        if (width > rect.width)
            rect.width = width;
        numLine++;
    }
    rect.height = (numLine - 1) * (vSpace + pFont->pRes->linefeed) - vSpace;
    return rect;
}





/*
 * NitroSystem g2d_CharCanvas.c GetCharIndex1D(cx, cy, areaWidth,
 * areaHeight, objWidth, objHeight): the character index of (x, y) inside
 * an OBJ-1D canvas tiled greedily with the largest OBJ that fits.  The last
 * two arguments are the current OBJ width/height shifts, rewritten each
 * round from GetMaxObjectSize's table g_020A18F4[log_h][log_w] (u8 pairs
 * widthShift, heightShift), with each log saturated at 3 and taken with an
 * in-place clz (MATH_ILog2 over MATH_CountLeadingZeros' `asm { clz x, x }`).
 *
 * Closed in wave 19 after 18 -> 10 in wave 11: the w log is computed IN
 * PLACE in the dying h-shift local `sh`, not in a fresh local.  With a named
 * log_w the two logs take each other's registers (18 out, in every
 * declaration order and with int, u32 or long logs); reusing sh puts log_w
 * in r6 with sh and log_h in r7, where the row pointer coalesces with the
 * next objWidth, as the image does.  1.1p1 is 240 bytes on this shape.
 */
int func_020681E4(int x, int y, int w, int h, int sw0, int sh0)
{
  int base = 0;
  int sh;
  int sw;
  int tmp;
  int tmp1;
  sw = sw0;
  sh = sh0;
  for (;;)
  {
    u32 ww;
    u32 hh;
    tmp = 0xFFFFFFFFu << sw;
    ww = ((u32) w) & tmp;
    hh = ((u32) h) & (0xFFFFFFFFu << sh);
    if (hh <= ((u32) y))
    {
      base += w * hh;
      if (ww <= ((u32) x))
      {
        h -= hh;
        base += ww * h;
        x -= ww;
        y -= hh;
        w -= ww;
      }
      else
      {
        w = ww;
        y -= hh;
        h -= hh;
      }
    }
    else
    {
      const u32 hinv = ~(0xFFFFFFFFu << sh);
      if (ww <= ((u32) x))
      {
        base += ww * hh;
        h = hh;
        x -= ww;
        w -= ww;
      }
      else
      {
        const u32 winv = ~(0xFFFFFFFFu << sw);
        base += ww * (y & (0xFFFFFFFFu << sh));
        tmp1 = x & (0xFFFFFFFFu << sw);
        base += tmp1 << sh;
        base += (y & hinv) << sw;
        return base + (x & winv);
      }
    }
    {
      int lh;
      const u8 *p;
      if (w >= 8) sh = 3; else { sh = w; asm { clz sh, sh } sh = 31 - sh; }
      if (h >= 8) lh = 3; else { lh = h; asm { clz lh, lh } lh = 31 - lh; }
      p = g_020A18F4[lh][sh];
      sw = (sw0 = p[0]);
      sh = (sh0 = p[1]);
    }
  }
}




/*
 *           in the image is this function's own literal at 0x020682F4, so the
 *           `literal`/`data_table` classes both refuse; written as an integer
 *           constant the pool word needs no witness but the front end then
 *           synthesises the address with two `add`s and loses the whole body.
 *
 * A 2-D table of four-word rows indexed by the byte at +1 then the byte at +0,
 * which is what makes the first index a `lsl #4` on the base and the second a
 * `lsl #2` inside the load's addressing mode.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020682DC.c \
 *       --func func_020682DC --addr 0x020682DC --cc 1.1p1 --arm
 */
u32 func_020682DC(const u8 *p)
{
    return g_020A1914[p[1]][p[0]];
}






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





/*
 * Fill a rectangle of a LINEAR tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles and hand every covered tile to
 * func_020682F8 with its own sub-rectangle, walking the grid with
 * `p += tilesz` per tile and `row += stride * tilesz` per tile row.
 *
 * Levers (docs/notes/pkt_02068808.c.txt has the earlier passes):
 *   - ../2.0/sp2 pin (1.1p1 is 408 bytes on this source);
 *   - the func_02068C84 loop shape: yo as `(cy < y) ? y - cy : 0`, p = row
 *     after it, th through a clamped temporary, loop locals declared
 *     `cx, th, xe, p, yo` at function scope (image r4..r8);
 *   - wave 10: the tile size reads the field again,
 *     `tilesz = (s->bpp << 6) / 8;` (CSE'd into the one `ldrb`).  From the
 *     bpp local, bpp is the spilled value and the tile size takes fp; from
 *     the field, the image's choice (bpp in fp, tile size at [sp,#0x14]);
 *   - wave 10: the two rounded bounds come BEFORE the row pointer:
 *     `xe, ye, row, rowadv` (found by permuting the four statements; the
 *     permuter's reorder(+2) from the old order reached 412/72, and only
 *     xe-ye-first orders are exact).
 */
void func_02068AE8(struct Surface_02068AE8 *s, u32 arg, int x, int y, int w, int h)
{
    int cy;
    int x1;
    int y1;
    int ye;
    char *row;
    int x0;
    int tilesz;
    int rowadv;
    u8 bpp;
    int cx;
    int th;
    int xe;
    char *p;
    int yo;

    bpp = s->bpp;
    x1 = x + w;
    y1 = y + h;
    if (bpp == 4) { u32 t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
    else { u32 t = arg | (arg << 8); arg = t | (t << 16); }
    cy = y & ~7;
    tilesz = (s->bpp << 6) / 8;
    x0 = x & ~7;
    xe = (x1 + 7) & ~7;
    ye = (y1 + 7) & ~7;
    row = s->base + tilesz * ((cy / 8) * s->f10 + (x0 / 8));
    rowadv = s->f10 * tilesz;
    if (cy >= ye)
        return;
    do {
        int t;
        yo = (cy < y) ? y - cy : 0;
        p = row;
        t = y1 - cy;
        if (t > 8)
            t = 8;
        th = t - yo;
        for (cx = x0; cx < xe; cx += 8) {
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            func_020682F8((u32 *)p, xo, yo, tw, th, arg, bpp);
            p = p + tilesz;
        }
        row = row + rowadv;
        cy = cy + 8;
    } while (cy < ye);
}




/*
 * Fill a rectangle of a SWIZZLED tile grid with one pixel value
 * (docs/families/cluster_020682DC.h): expand the pixel to a word, round the
 * rectangle out to whole 8x8 tiles, ask func_020681E4 for each tile's index
 * (tx, ty, w, h and the two swizzle bytes of the +0x10 word) and hand every
 * covered tile to func_020682F8 with its own sub-rectangle.
 *
 * Levers, in the order they were found (docs/notes/pkt_02068808.c.txt):
 *   - ../2.0/sp2 pin (1.1p1 is 492 bytes);
 *   - yo as `(cy < y) ? y - cy : 0`, tx = tx0 after it, th through a
 *     clamped temporary; loop registers declared `cx, th, tx, xe, ty`;
 *   - THE LAST 8 BYTES (wave 10): the tile size is computed from a fresh
 *     read of the field, `tilesz = (s->bpp << 6) / 8;`, not from the bpp
 *     local.  The two loads CSE to the one `ldrb`, but the tile size then
 *     becomes its own value in the IR and the image's `stm sp, {r5, fp}` is
 *     scheduled before `sub r3, r2, r1` (tw - xo).  The same lever closes
 *     func_02068AE8, where it decides whether bpp or the tile size is the
 *     spilled value.  (Declaring func_020682F8's bpp parameter u8 in this
 *     caller also closes C84 alone, but the callee's own definition,
 *     src/matched/func_020682F8.c, is EXACT only with `int bpp`, so the
 *     re-read is the reading kept.)  The permuter (hill 800 + anneal 2000,
 *     --types) never moved this residue.
 */
void func_02068C84(struct Surface_02068C84 *s, u32 arg, int x, int y, int w, int h)
{
    struct Swz f10;
    int cy;
    int x1;
    int y1;
    int ye;
    char *base;
    int tx0;
    int x0;
    int sy;
    int sx;
    int sh;
    int sw;
    int tilesz;
    u8 bpp;
    int cx;
    int th;
    int tx;
    int xe;
    int ty;

    bpp = s->bpp;
    x1 = x + w;
    y1 = y + h;
    if (bpp == 4) { u32 t = arg | (arg << 4); t = t | (t << 8); arg = t | (t << 16); }
    else { u32 t = arg | (arg << 8); arg = t | (t << 16); }
    x0 = x & ~7;
    cy = y & ~7;
    ye = (y1 + 7) & ~7;
    tilesz = (s->bpp << 6) / 8;
    tx0 = x0 / 8;
    f10 = s->f10;
    ty = cy / 8;
    xe = (x1 + 7) & ~7;
    sw = s->w;
    sh = s->h;
    base = s->base;
    sx = f10.x;
    sy = f10.y;
    if (cy >= ye)
        return;
    do {
        int yo, t;
        yo = (cy < y) ? y - cy : 0;
        tx = tx0;
        t = y1 - cy;
        if (t > 8)
            t = 8;
        th = t - yo;
        for (cx = x0; cx < xe; cx += 8) {
            int off = func_020681E4(tx, ty, sw, sh, sx, sy);
            int xo = (cx < x) ? x - cx : 0;
            int tw = x1 - cx;
            if (tw > 8)
                tw = 8;
            tw -= xo;
            func_020682F8((u32 *)(base + tilesz * off), xo, yo, tw, th, arg, bpp);
            tx = tx + 1;
        }
        ty = ty + 1;
        cy = cy + 8;
    } while (cy < ye);
}





/*
 * The text-context initialiser: seven arguments straight into six fields of a
 * 0x18-byte pen/draw context, with no computation at all.  A leaf, and the
 * image proves it -- it never pushes and returns with a bare `bx lr`.
 *
 * TWO THINGS THE BYTES FORCED:
 *
 *   1. THE STORE ORDER IS THE SOURCE ORDER, and it is deliberately not the
 *      field order: +0x04, +0x08, +0x0c, +0x00, +0x14, +0x10.  Writing the
 *      fields in ascending order instead lets the front end fuse the first two
 *      into `stm r0, {r1, r2}` (which is what 1.1p1 does even with the source
 *      order, see the pin below), and the function changes shape.  This
 *      compiler never reorders independent stores to the same object, so the
 *      image's order IS the original statement order -- the same reading rule
 *      as docs/idioms/the-fall-through-arm-is-the-source-order.md applied to
 *      straight-line code.
 *
 *   2. +0x0c IS A BYTE.  `strb r2, [r0, #0xc]` with the value arriving as a
 *      full stack word, so the parameter is an `int` and the field is `u8`;
 *      the narrowing is at the store, not at the call.
 *
 * THE ARITY AND THE ARGUMENT ORDER are not guessed: the caller
 * src/matched/func_02068FC4.c (already EXACT) spells the call as
 *
 *     func_02068E78((char *)a, b, c, d, e, 0x020A18DC, c);
 *
 * which fixes seven arguments, three in registers and four on the stack at
 * [sp+0], [sp+4], [sp+8], and shows the last argument repeating the third.
 * The other caller, func_02068FF0 at 0x02069064, agrees.
 *
 * THE `../2.0/sp2` PIN.  dsi/1.1p1 cannot produce a leaf here at all: it
 * spends `r4` and `lr` on the three stack arguments and therefore opens
 * `push {r4, lr}` and returns through `pop {r4, pc}`, which also shifts every
 * stack-argument displacement by 8 and lets it fuse `str r1, [r0]` with
 * `str r2, [r0, #4]` into one `stm`.  Nine of the ten instructions differ.
 * ../2.0/sp2 and ../1.2/sp2 both reproduce the image byte for byte with the
 * same C.  ../2.0/sp2 is recorded because the adjacent matched member of this
 * cluster, src/matched/func_02068EA0.c, is independently pinned to it (on the
 * "kept constants" re-read tell) and because the other function filed into
 * this cluster in the same pass, src/matched/func_02068FF0.c, is 2.0 and NOT
 * 1.2.  Since two front ends agree on this row it is not usable as evidence
 * for either pin on its own, and it is deliberately not offered as one in
 * docs/FRONTEND-PINS.md -- but the symptom is worth naming: A LEAF THAT GROWS
 * A PROLOGUE is a front-end question, not a spelling one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068E78.c \
 *       --func func_02068E78 --addr 0x02068E78 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 40 = original 40, 0 relocation sites
 */
void func_02068E78(struct Pen *p, void *a1, int a2, int a3, int a5, const void *a6, int a7)
{
    p->f04 = a2;
    p->f08 = a3;
    p->f0c = (u8)a5;
    p->f00 = a1;
    p->f14 = a6;
    p->f10 = a7;
}




/*
 * Per-file compiler pin, the re-read/forward form of the "kept constants"
 * family (docs/FRONTEND-PINS.md, the func_02070BD8 row). The image RE-READS
 * the font's header chain a second time before the switch dispatch,
 * `ldr r1, [r7]` at 0x02068F00 (`00 10 97 e5`) then `ldr r3, [r1, #8]` at
 * 0x02068F04 (`08 30 91 e5`), although the same chain was already loaded at
 * 0x02068EE8/0x02068EEC for the stride computation two instructions earlier.
 * dsi/1.1p1 -O4,p forwards the register it still has live and collapses the
 * pair to a single `ldr r3, [r3, #8]`, giving 284 bytes against the original's
 * 292 with everything from the dispatch onward shifted by four. A volatile
 * qualifier on the outer load, struct-typed field chains, binding the header
 * to a local before or after out[1], and a fresh `(*font)->hdr` chain spelled
 * out in every switch arm all CSE identically at 284. Under the pin the same C
 * is 292 bytes, 0 mismatches.
 *
 * Draw one glyph: look the character up in the font's range table, fall back
 * to the font's default glyph when the lookup returns its 0xFFFF "not found"
 * sentinel (the pool word at 0x02068FC0), then adjust the pen position by the
 * glyph's own bearings according to the header's layout kind before handing
 * both the glyph record and the metrics record to the context's draw hook.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068EA0.c \
 *       --func func_02068EA0 --addr 0x02068EA0 --cc ../2.0/sp2 --arm
 */
s8 func_02068EA0(struct Ctx *ctx, NNSG2dFont *font, int x, int y, int a6, u16 code)
{
    s8 *out[2];
    u32 idx;
    s8 *g;
    u8 k;

    idx = func_02067F9C(font, code);
    if (idx == 0xffff)
        idx = font->pRes->alterCharIndex;
    out[0] = (s8 *)func_02067FE4(font, idx);
    out[1] = (s8 *)((char *)font->pRes->pGlyph + 8 + idx * font->pRes->pGlyph->cellSize);
    g = out[0];
    k = font->pRes->pGlyph->flags;

    switch (k) {
    case 0:
    case 7:
        x += g[0];
        break;
    case 1:
    case 2:
        x -= font->pRes->pGlyph->cellWidth;
        y += g[0];
        break;
    case 3:
    case 4:
        x -= g[0] + (u8)g[1];
        y -= font->pRes->pGlyph->cellHeight;
        break;
    case 5:
    case 6:
        y -= g[0] + font->pRes->pGlyph->cellHeight;
        break;
    }
    ((void (*)(struct Ctx *, void *, int, int, int, s8 **))ctx->vt[0])(ctx, font, x, y, a6, out);
    return out[0][2];
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068FC4.c \
 *       --func func_02068FC4 --addr 0x02068FC4 --cc 1.1p1 --arm
 */
void func_02068FC4(int a, int b, int c, int d, int e)
{
    func_02068E78((struct Pen *)a, (void *)b, c, d, e, (const void *)0x020A18DC, c);
}
