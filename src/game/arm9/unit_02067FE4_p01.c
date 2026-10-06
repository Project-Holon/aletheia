/*
 * file:     unit_02067FE4_p01.c
 * unit:     yes
 * function: func_02067FE4, func_02068030, func_020680DC, func_02068150, func_020681E4
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

struct Shift
{
  int w;
  int h;
};

extern u16 func_02067F9C(const NNSG2dFont *pFont, u16 c);
const NNSG2dCharWidths *func_02067FE4(const NNSG2dFont *pFont, u32 idx);
int func_02068030(const NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos);
int func_020680DC(const NNSG2dFont *pFont, int vSpace, const void *txt);
NNSG2dTextRect func_02068150(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt);
extern const u8 g_020A18F4[4][4][2];




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
int func_020681E4(int x, int y, int w, int h, struct Shift s)
{
  int base = 0;
  int sh;
  int sw;
  int tmp;
  int tmp1;
  sw = s.w;
  sh = s.h;
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
      sw = (s.w = p[0]);
      sh = (s.h = p[1]);
    }
  }
}
