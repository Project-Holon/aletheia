/*
 * file:     unit_02067FE4_p02.c
 * unit:     yes
 * function: func_02068FF0, func_02069078, func_02069128, func_02069184, func_020691E0, func_020694D8, func_0206958C, func_020696F4, func_02069818
 * address:  0x02068FF0
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
 *   func_02068E78  0x02068E78  arm
 *   g_020A18F4     0x020A18F4  data
 *   g_020A18E8     0x020A18E8  data
 *   func_020682DC  0x020682DC  arm
 *   func_02068EA0    0x02068EA0  arm
 *   func_02068030    0x02068030  arm
 *   func_02068150    0x02068150  arm
 *   func_020680DC    0x020680DC  arm
 */
struct NNSG2dFont;
struct Ctx;
struct Pen;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef union {
    u32 raw;
    struct {
        u32 w    : 8;
        u32 h    : 8;
        u32 rest : 16;
    };
} Param;

typedef struct GXOamAttr
{
  u32 attr01;
  u16 attr2;
  u16 attr3;
} GXOamAttr;

typedef signed int s32;

typedef signed char s8;

typedef struct {
    signed char dx;
    signed char dy;
} Step;

typedef s32 (*NextFn)(const void **cursor);

typedef struct {
    u8 b00;
    signed char b01;
} Hdr;

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

typedef struct {
    struct Ctx *f00;
    NNSG2dFont *f04;
    s32 f08;
    s32 f0C;
} Ctx;

typedef NNSG2dTextRect Ext;

extern void func_02068E78(struct Pen *p, void *charBase, int areaWidth, int areaHeight,
                          int colorMode, const void *vtable, int param);
extern u32 func_020682DC(const u8 *pair);
extern s32 func_02068EA0(struct Ctx *ctx, NNSG2dFont *font, s32 x, s32 y, s32 w2, s32 c);
extern int func_02068030(const struct NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos);
extern NNSG2dTextRect func_02068150(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt);
extern int func_020680DC(const NNSG2dFont *pFont, int vSpace, const void *txt);
void func_02068FF0(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode);
void func_02069078(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
void func_02069128(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt);
u32 func_02069184(u32 areaWidth, u32 areaHeight);
int func_020691E0(GXOamAttr *oam, int areaWidth, int areaHeight, int x, int y, int color, int charName, int vramShift);
void func_020694D8(Ctx *ctx, s32 x, s32 y, s32 w2, const void *s, const void **last, Step st);
void func_0206958C(Ctx *ctx, s32 x, s32 y, s32 w, s32 w2, u32 flags, const void *s, Step st);
void func_020696F4(Ctx *ctx, s32 x, s32 y, s32 w, u32 flags, u32 s, Step st);
void func_02069818(Ctx *ctx, s32 x, s32 y, s32 w, u32 a4, u32 a5, u32 flags, u32 s, Step st);
extern const u8 g_020A18F4[4][4][2];
extern const u8 g_020A18E8[];




static inline u32 MATH_CountLeadingZeros(u32 x)
{
    asm { clz x, x }
    return x;
}




inline static int MATH_ILog2(u32 x)
{
    return (int)(31 - MATH_CountLeadingZeros(x));
}




inline static int SizeToShift(int size)
{
    return (size >= 8) ? 3 : MATH_ILog2((u32)size);
}




/*
 * NitroSystem g2d_CharCanvas.c, the OBJ-1D canvas initialiser: derive the
 * log2 of each area dimension saturated at 3 (MATH_ILog2 over the SDK's
 * inline-asm MATH_CountLeadingZeros, which is how the image's predicated
 * clz/rsb #0x1f pairs arise), look the OBJ shift pair up in g_020A18F4
 * [shiftH][shiftW], and hand everything to the common initialiser
 * func_02068E78 with the vtable-like object g_020A18E8.
 *
 * Two readings closed it.  (1) The word the image reads uninitialised from
 * [sp, #0xc], edits in bytes 0 and 1 and stores to both [sp, #0xc] and
 * [sp, #8] is a 4-byte BITFIELD STRUCT local passed BY VALUE as the seventh
 * argument, not an eighth argument: its home is [sp, #0xc] and the by-value
 * copy is the argument slot.  (2) The pair is read through a pointer local
 * `const u8 *p = g_020A18F4[shiftH][shiftW];`; subscripting the table twice
 * leaves shiftW/shiftH in swapped registers (10 bytes).  1.1p1 compiles 132 bytes;
 * the pin is ../2.0/sp2.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02068FF0.c \
 *       --func func_02068FF0 --addr 0x02068FF0 --arm --cc ../2.0/sp2
 */
void func_02068FF0(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode)
{
    Param param;
    const int shiftW = SizeToShift(areaWidth);
    const int shiftH = SizeToShift(areaHeight);
    const u8 *p = g_020A18F4[shiftH][shiftW];

    param.w = p[0];
    param.h = p[1];
    func_02068E78((struct Pen *)pCC, charBase, areaWidth, areaHeight, colorMode, g_020A18E8, param.raw);
}




/*
 * NitroSystem NNS_G2dMapScrToCharText (g2d_CharCanvas): map a rectangle of
 * a text-BG screen to consecutive character numbers.  A screen no wider
 * than 32 entries is linear and goes to func_02069128; a 64-wide screen is
 * two 32x32 blocks side by side, so row y >= 32 skips the right-hand block
 * (y + 32) and column x >= 32 lands in it (x + 32 * 31).
 *
 * Levers: `scnWidth * areaTop + areaLeft` in that order and parenthesised
 * (the image's `mla r4, r5, lr, r3`; the unparenthesised sum is two adds,
 * and the other product order is 2 bytes out); `const u16 cpltMask` and the
 * post-increment inside the store, as in func_02069128.
 *
 * COMPILER PIN ../2.0/sp2 (docs/FRONTEND-PINS.md): both 32-block selects are
 * true conditional-move pairs in the image, `cmp lr, #0x20` / `movlt r2, lr`
 * / `addge r2, lr, #0x20` at 0x020690D0..0x020690D8 and `cmp r7, #0x20` /
 * `movlt r2, r7` / `addge r2, r7, #0x3e0` at 0x020690EC..0x020690F4; dsi/1.1p1
 * emits an unconditional `mov r2, lr` before the `cmp` (and `mov r2, r7`),
 * 16 concrete bytes out at 176.  0 mismatches under the pin.
 */
void func_02069078(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop,
                   int scnWidth, int charNo, int cplt)
{
    if (scnWidth <= 32) {
        func_02069128((u16 *)scnBase + (scnWidth * areaTop + areaLeft), areaWidth, areaHeight,
                      scnWidth, charNo, cplt);
    } else {
        const int areaRight = areaLeft + areaWidth;
        const int areaBottom = areaTop + areaHeight;
        const u16 cpltMask = (u16)(cplt << 12);
        int x, y;

        for (y = areaTop; y < areaBottom; y++) {
            u16 *pLine = (u16 *)scnBase + ((y < 32) ? y : y + 32) * 32;
            for (x = areaLeft; x < areaRight; x++) {
                pLine[(x < 32) ? x : x + 32 * 31] = (u16)(charNo++ | cpltMask);
            }
        }
    }
}



/*
 * The linear half of NitroSystem's NNS_G2dMapScrToCharText (g2d_CharCanvas):
 * fill an areaWidth x areaHeight block of a text-BG screen whose rows are
 * scnWidth entries apart with consecutive character numbers, palette
 * `cplt` in the top four bits of every entry.  func_02069078 calls it for
 * screens no wider than 32 entries.
 *
 * Three spellings decide it, all measured:
 *   - the palette field is a `const u16 cpltMask = (u16)(cplt << 12)`: the
 *     compiler keeps it as `cplt << 28` and ORs it in with `lsr #16`;
 *   - the store is `*pScr++ = (u16)(charNo++ | cpltMask)` with the
 *     post-increment INSIDE the store expression (a separate `charNo++`
 *     statement is 8 bytes out, the old `top = hi << 28` reading 15);
 *   - `x` and `y` declared together at function scope, x first.
 * The same C is EXACT under dsi/1.1p1 and ../2.0/sp2; no pin.
 */
void func_02069128(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt)
{
    int x, y;
    const u16 cpltMask = (u16)(cplt << 12);

    for (y = 0; y < h; y++) {
        u16 *pScr = pScrBase;
        for (x = 0; x < w; x++) {
            *pScr++ = (u16)(charNo++ | cpltMask);
        }
        pScrBase += scnWidth;
    }
}







/*
 * Number of OBJs NitroSystem's 1D OBJ arrangement (func_020691E0) spends on
 * an areaWidth x areaHeight character area: 8x8-char OBJs over the aligned
 * part, then per 8-char strip one OBJ for a 4-char remainder and two for
 * each of the 2- and 1-char remainders (a 1x8 or 2x8 OBJ does not exist),
 * and the remainder corner.  Exported; nothing in the image calls it.
 *
 * Levers, from the permuter (docs/notes/permuter.md): the bit pair is
 * `((v & 2) >> 1) + (v & 1)` (bit 1 first), the declarations run
 * X8, Y8, X2, num, X4, Y4, Y2, and the corner product is bound to its own
 * local before the return.
 *
 * COMPILER PIN ../2.0/sp2, "kept constants" (docs/FRONTEND-PINS.md): the
 * image seeds the product chain with a materialised zero, `mov r2, #0` at
 * 0x02069190 then `mla lr, r3, r5, r2` at 0x02069194; dsi/1.1p1 folds the
 * same C to a bare `mul lr, r3, r5` (every spelling of the zero the earlier
 * notes list does the same), 25 concrete bytes out.  0 under the pin.
 */
u32 func_02069184(u32 areaWidth, u32 areaHeight)
{
    u32 numX8 = areaWidth >> 3;
    u32 numY8 = areaHeight >> 3;
    u32 numX2 = ((areaWidth & 2) >> 1) + (areaWidth & 1);
    u32 num = 0;
    u32 numX4 = (areaWidth & 4) >> 2;
    u32 numY4 = (areaHeight & 4) >> 2;
    u32 numY2 = ((areaHeight & 2) >> 1) + (areaHeight & 1);
    u32 corner;

    num += numX8 * numY8;
    num += numY8 * (numX2 * 2 + numX4);
    num += numX8 * (numY2 * 2 + numY4);
    corner = (numX2 + numX4) * (numY2 + numY4);
    return num + corner;
}








inline static void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
  oam->attr01 = ((oam->attr01 & (~(0x000000FFu | 0x01FF0000u))) | (y & 0x000000FFu)) | ((x & (0x01FF0000u >> 16)) << 16);
}







inline static void G2_SetOBJShape(GXOamAttr *oam, u32 shape)
{
  oam->attr01 = (oam->attr01 & (~(0x0000C000u | 0xC0000000u))) | shape;
}







inline static void G2_SetOBJCharName(GXOamAttr *oam, int name)
{
  oam->attr2 = (u16) ((oam->attr2 & (~0x03FF)) | name);
}







inline static void G2_SetOBJColorMode(GXOamAttr *oam, int color)
{
  oam->attr01 = (oam->attr01 & (~0x2000u)) | (color << 13);
}







/*
 * NitroSystem g2d_CharCanvas.c, NNS_G2dArrangeOBJ1D(oam, areaWidth,
 * areaHeight, x, y, color, charName, vramShift): pick the OBJ shape for the
 * area from g_020A18F4[log2 h][log2 w] (func_020682DC turns the pair into
 * the attr01 shape/size bits), lay the aligned block out with the SDK OAM
 * inlines, then recurse on the right strip, the bottom strip and the
 * corner; returns the number of OBJs written.  The log2 is the SDK's
 * inline-asm MATH_CountLeadingZeros behind a `>= 8 ? 3 :` ternary.
 *
 * Levers (wave 11): the three post-lookup locals are DECLARED
 * charPerOBJ, numX, numY (uninitialised) and assigned numX, numY,
 * charPerOBJ afterwards -- declaration order, not assignment order, is
 * what gives numX sb and charPerOBJ r8 (initialised consts in assignment
 * order swap the pair, 5 bytes out; assigning charPerOBJ first fixes the
 * registers but moves the schedule).  The right-strip x is bound to a
 * named local before the recursive call.
 *
 * COMPILER PIN ../2.0/sp2: dsi/1.1p1 is 768 bytes with a wider push.
 */
int func_020691E0(GXOamAttr *oam, int areaWidth, int areaHeight, int x, int y, int color, int charName, int vramShift)
{
  const int shiftI = (areaWidth >= 8) ? (3) : (MATH_ILog2((u32) areaWidth));
  const int shiftJ = (areaHeight >= 8) ? (3) : (MATH_ILog2((u32) areaHeight));
  const u8 *pair = g_020A18F4[shiftJ][shiftI];
  const int objShiftW = pair[0];
  const int objShiftH = pair[1];
  const u32 alignedW = ((u32) areaWidth) & (0xFFFFFFFFu << objShiftW);
  const u32 alignedH = ((u32) areaHeight) & (0xFFFFFFFFu << objShiftH);
  const int charUnit = (color == 0) ? (1) : (2);
  int numOBJ = 0;
  const u32 shape = func_020682DC(pair);
  int charPerOBJ;
  int numX;
  int numY;
  int ix;
  int iy;
  numX = areaWidth >> objShiftW;
  numY = areaHeight >> objShiftH;
  charPerOBJ = (charUnit << objShiftW) << objShiftH;
  for (iy = 0; iy < numY; iy++)
  {
    const int py = y + ((iy << objShiftH) << 3);
    for (ix = 0; ix < numX; ix++)
    {
      const int px = x + ((ix << objShiftW) << 3);
      G2_SetOBJPosition(oam, px, py);
      G2_SetOBJShape(oam, shape);
      G2_SetOBJCharName(oam, charName);
      G2_SetOBJColorMode(oam, color);
      charName += charPerOBJ >> vramShift;
      oam++;
    }

  }

  numOBJ += numX * numY;
  if (alignedW < ((u32) areaWidth))
  {
    const int restW = areaWidth - alignedW;
    const int tmp = x + (alignedW << 3);
    const int n = func_020691E0(oam, restW, alignedH, tmp, y, color, charName, vramShift);
    oam += n;
    charName += ((u32) (alignedH * (charUnit * restW))) >> vramShift;
    numOBJ += n;
  }
  if (alignedH < ((u32) areaHeight))
  {
    const int restH = areaHeight - alignedH;
    const int n = func_020691E0(oam, alignedW, restH, x, y + (alignedH << 3), color, charName, vramShift);
    oam += n;
    charName += ((u32) (restH * (charUnit * alignedW))) >> vramShift;
    numOBJ += n;
  }
  if ((alignedW < ((u32) areaWidth)) && (alignedH < ((u32) areaHeight)))
  {
    numOBJ += func_020691E0(oam, areaWidth - alignedW, areaHeight - alignedH, x + (alignedW << 3), y + (alignedH << 3), color, charName, vramShift);
  }
  return numOBJ;
}






/*
 * The innermost draw step of the text renderer, the function
 * src/matched/func_0206958C.c calls once per line as
 * `func_020694D8(ctx, px, py, w2, cur, &cur, st)`.  It walks one LINE of the
 * string: a character iterator is fetched out of the font object
 * (`ctx->f04`, callback at +4, taking a `const void **` cursor and returning
 * the character code), each character is drawn with func_02068EA0, and the
 * pen is stepped along the step vector by the glyph's advance plus the
 * inter-character gap `ctx->f08`.  The walk stops at NUL or at '\n' (0xa),
 * and the `last` out-parameter receives the cursor position when the stop was
 * a newline and 0 when it was the end of the string -- the identical tail
 * func_02068030 (the measure-one-line sibling at 0x02068030) carries at
 * 0x020680AC..0x020680C0, which is what fixes the polarity here.
 *
 * TWO C LEVERS, both needed, both found by measurement:
 *
 * 1. DECLARATION ORDER `gap` BEFORE `fnt`
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *    The image opens `ldr r4, [fp, #8]` / `ldr r5, [fp, #4]` -- the two
 *    context fields loaded as SEPARATE instructions in DESCENDING offset
 *    order, which is the one order mwccarm's ldm coalescer cannot merge.
 *    Declared the other way round the same two loads fold to a single
 *    `ldmib fp, {r4, r5}`, the whole body shifts one slot earlier and 94 of
 *    180 bytes differ.  Re-ordering the two ASSIGNMENTS does not help (every
 *    permutation was measured: 94, 95 and 97 bytes out); it is the
 *    declaration order that picks r4 for the gap and r5 for the font, and
 *    having picked them the scheduler emits the loads in that order.
 *
 * 2. THE LOOP MUST BE AN EXPLICIT `goto`, NOT A `while`
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *    The image's back edge is `bne #0x206951c` at 0x02069554: it tests only
 *    `c != 0` and jumps back to the `cmp r0, #0xa` at 0x0206951C, so the
 *    newline test is the LOOP TOP and the NUL test is the BOTTOM.  Written as
 *    `while (c != 0xa) { ...; c = next(&cur); if (c == 0) break; }` the
 *    compiler fuses the bottom pair into `cmp r0, #0 / cmpne r0, #0xa`, which
 *    is one instruction and four bytes too many (184 bytes, 59 out) and moves
 *    the `ldrsb r7, [sp, #0x40]` load of st.dx from between the two compares
 *    to after them.  The explicit two-label form below keeps them apart.
 *
 * The compiler pin is the cluster's, `../2.0/sp2`, shared with its packet
 * mates func_0206958C, func_020696F4 and func_02069AC4; see the "kept
 * branches" tell in docs/FRONTEND-PINS.md.  Under dsi/1.1p1 this same source
 * loses the 0x10 frame and the ten-register push.
 *
 * The two trailing `signed char`s are ONE 2-byte struct passed by value, the
 * same Step the whole cluster forwards (see func_02069818's header).
 */
void func_020694D8(Ctx *ctx, s32 x, s32 y, s32 w2,
                   const void *s, const void **last, Step st)
{
    const void *cur;
    s32 gap;
    NNSG2dFont *fnt;
    NextFn next;
    s32 c;
    s32 adv;
    s32 dx;
    s32 dy;

    gap = ctx->f08;
    fnt = ctx->f04;
    cur = s;
    next = ((NextFn *)fnt)[1];
    dy = st.dy;
    c = next(&cur);
    if (c == 0) goto done;
    dx = st.dx;
loop:
    if (c == 0xa) goto done;
    adv = gap + func_02068EA0(ctx->f00, fnt, x, y, w2, c);
    x = x + adv * dx;
    y = y + adv * dy;
    c = next(&cur);
    if (c != 0) goto loop;
done:
    if (last != 0) {
        *last = (c == 0xa) ? cur : 0;
    }
}





/*
 * The line loop of the text renderer, sitting between func_02069818 /
 * func_020696F4 (which pre-align the pen) and func_020694D8 (which draws one
 * line). Per line it optionally re-aligns the pen horizontally within the
 * measured line box -- bit 11 of the flags word right-aligns by the full
 * measured width, bit 10 centres by half -- then draws the line and steps the
 * pen down by one line height along the step normal.
 *
 * Per-file compiler pin, the "kept branches" tell in its CROSS-JUMP form
 * (docs/FRONTEND-PINS.md). The image writes the pen-delta tail out in BOTH
 * arms of the alignment dispatch: `mla r4, r0, sb, r4` / `mla r5, r0, r8, r5`
 * at 0x02069658/0x0206965C closed by `b 0x0206969C` (`0d 00 00 ea`) at
 * 0x02069660 for the bit-11 arm, and the byte-identical `mla r4, r0, sb, r4`
 * / `mla r5, r0, r8, r5` at 0x02069694/0x02069698 for the bit-10 arm.
 * dsi/1.1p1 -O4,p cross-jumps the two, branching the bit-11 arm straight
 * into the bit-10 arm's pair and dropping both instructions plus the join
 * branch: 352 bytes against the original's 360, 130 concrete bytes out with
 * everything before 0x020695F4 already identical. Under the pin the same C
 * is 360 bytes, 0 mismatches.
 *
 * One C lever needed under the pin: `px`/`py` must be declared BEFORE
 * `sx`/`sy`, which is what puts the per-line pen in r4/r5 and the running
 * line offset in r6/r7. Declared the other way round the same 360 bytes come
 * out with those four registers swapped, 21 concrete bytes out.
 */
void func_0206958C(Ctx *ctx, s32 x, s32 y, s32 w,
                   s32 w2, u32 flags, const void *s, Step st)
{
    const void *cur;
    s32 lead;
    s32 dx;
    s32 dy;
    s32 bit11;
    s32 bit10;
    s32 half;
    s32 px;
    s32 py;
    s32 sx;
    s32 sy;
    s32 n;

    lead = ctx->f0C + ctx->f04->pRes->linefeed;
    dx = lead * -st.dy;
    dy = lead * st.dx;

    cur = s;
    if (cur == 0) return;

    sx = 0;
    bit11 = flags & 0x800;
    half = (w + 1) / 2;
    bit10 = flags & 0x400;
    sy = 0;

    do {
        px = x + sx;
        py = y + sy;
        if (bit11 != 0) {
            n = w - func_02068030(ctx->f04, ctx->f08, cur, 0);
            px = px + n * st.dx;
            py = py + n * st.dy;
        } else if (bit10 != 0) {
            n = half - (func_02068030(ctx->f04, ctx->f08, cur, 0) + 1) / 2;
            px = px + n * st.dx;
            py = py + n * st.dy;
        }
        func_020694D8(ctx, px, py, w2, cur, &cur, st);
        sx = sx + dx;
        sy = sy + dy;
    } while (cur != 0);
}




/*
 * The block-alignment pre-pass, the two-dimensional counterpart of
 * func_02069818's single-line one. It measures the whole multi-line extent
 * with func_02068150 into a two-word local, copies that pair into a second
 * local (the one the caller-visible {w,h} box keeps), and then backs the pen
 * off along the step vector according to two pairs of flag bits:
 *   0x10 centre vertically, 0x20 bottom-align (measured width, +0x18)
 *   0x02 centre horizontally, 0x04 right-align (box height, +0x24)
 * Everything is then forwarded verbatim to func_0206958C, the same Step
 * struct by value that func_02069818 forwards.
 *
 * Per-file compiler pin, the "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r4, #0x20` at 0x02069768 (`20 00 14 e3`) and
 * `beq 0x02069784` at 0x0206976C (`04 00 00 0a`) over the FIVE-instruction
 * bottom-align arm at 0x02069770..0x02069780 (two `ldrsb` of the step pair,
 * `rsb r2, r2, #0`, and the two `mla`). dsi/1.1p1 -O4,p predicates the whole
 * arm to `ldrsbne/rsbne/ldrsbne/mlane/mlane`, and having done so schedules
 * the head one slot differently (`ldr r3, [r8, #0xc]` split out of the
 * `ldmib r8, {r1, r2, r3}`): the same 292 bytes, 93 concrete bytes out, with
 * everything from 0x02069784 onward already byte-identical. Under the pin
 * the same C is 292 bytes, 0 mismatches.
 *
 * The three {w,h} pairs at sp+0x10, sp+0x18 and sp+0x20 are three distinct
 * stack objects: the out buffer func_02068150 fills and two copies of it,
 * only one of which is read again. Both copies must be `volatile` or 1.1p1
 * and 2.0 alike dead-store-eliminate them and the frame comes out 0x18.
 */
void func_020696F4(Ctx *ctx, s32 x, s32 y, s32 w,
                   u32 flags, u32 s, Step st)
{
    volatile Ext box2;
    Ext e;
    volatile Ext box;
    s32 d;

    e = func_02068150(ctx->f04, ctx->f08, ctx->f0C, (const void *)s);
    box.width = e.width;
    box.height = e.height;
    box2.width = e.width;
    box2.height = e.height;

    if (flags & 0x10) {
        d = -(e.width + 1) / 2;
        x = x + d * st.dx;
        y = y + d * st.dy;
    } else if (flags & 0x20) {
        d = -e.width;
        x = x + d * st.dx;
        y = y + d * st.dy;
    }

    if (flags & 2) {
        d = -(box2.height + 1) / 2;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    } else if (flags & 4) {
        d = -box2.height;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    }

    func_0206958C(ctx, x, y, box2.width, w, flags, (const void *)s, st);
}


/*
 * The two trailing `signed char` parameters are ONE 2-byte struct passed by
 * value, not two separate char arguments. Spelled as two arguments the ABI
 * gives each its own word slot and the image's `ldrsb r2, [sp, #0x39]` /
 * `strb ip, [sp, #0xd]` become +0x3C and +0x10; the struct form packs them
 * adjacently and is what makes the file byte-correct. The same pair is
 * forwarded verbatim to func_0206958C, which therefore takes it the same
 * way.
 *
 * VERDICT: MATCH. Byte-correct -- 224 bytes, ZERO concrete mismatches, the
 * full extent -- and capped only for lack of an outside witness.
 *
 * BLOCKING EVIDENCE CLASS: none available for the two calls to 0x020680DC
 * at +0x0030 and +0x0068. `label` refuses it: 0x020680DC has exactly two
 * branch witnesses anywhere in the image (arm9 and every overlay), at
 * 0x02069848 and 0x02069880, and BOTH are the two `bl`s in this function,
 * so every witness is inside the compared range. There is no `matched`
 * manifest entry for 0x020680DC either (it is in another packet), and it
 * is ordinary compiled C, so neither `runtime` nor `veneer` applies.
 * `--suggest-split` was run and reports "the whole range as one file is
 * NOT viable / best partition: 0 piece(s), 1 function(s) left out": both
 * sites are calls from a single function section, so there is no cut that
 * leaves either one a witness outside a smaller range.
 *
 * The third site, the tail call to 0x0206958C at +0x00D4, IS resolved
 * (`label x3, e.g. 0206980C`). Unblocking this file therefore needs one
 * thing only: an EXACT manifest entry covering 0x020680DC, which would
 * give both sites the `matched` class. That address is outside
 * pkt_020694D8 and cannot be filed from here.
 *
 * The horizontal/vertical alignment pre-pass for the text renderer.
 * Depending on two bits of the flags word (the third stack argument) it
 * measures the string with func_020680DC and shifts the pen:
 *   bit 8  (0x100): right/bottom align -- back the pen off by the full
 *                   measured extent, `(limit - measured)`;
 *   bit 7  (0x080): centre align -- back it off by half, with the
 *                   +1/asr-1 rounding pair on BOTH operands, which is what
 *                   produces the four `add rN, rM, rM, lsr #31` / `asr #1`
 *                   instructions at 0x02069888..0x020698A4.
 * The pen delta is applied as `pen += extent * (-dy)` and
 * `pen += extent * dx` through the two `mla`s, then everything is
 * forwarded verbatim to func_0206958C.
 */
void func_02069818(Ctx *ctx, s32 x, s32 y, s32 w,
                   u32 a4, u32 a5, u32 flags, u32 s, Step st)
{
    s32 n;
    s32 d;

    if (flags & 0x100) {
        n = func_020680DC(ctx->f04, ctx->f0C, (const void *)s);
        d = (s32)a4 - n;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    } else if (flags & 0x80) {
        n = func_020680DC(ctx->f04, ctx->f0C, (const void *)s);
        d = ((s32)a4 + 1) / 2 - (n + 1) / 2;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    }
    func_0206958C(ctx, x, y, w, a5, flags, (const void *)s, st);
}
