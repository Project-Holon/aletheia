/*
 * function: func_020691E0
 * address:  0x020691E0
 * packet:   pkt_02069078
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_020A18F4     0x020A18F4  data  a1
 *   func_020682DC  0x020682DC  arm
 *   func_020691E0  0x020691E0  arm
 *
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

static inline u32 MATH_CountLeadingZeros(u32 x)
{
    asm { clz x, x }
    return x;
}
typedef struct GXOamAttr
{
  u32 attr01;
  u16 attr2;
  u16 attr3;
} GXOamAttr;
extern const u8 g_020A18F4[4][4][2];
extern u32 func_020682DC(const u8 *pair);
inline static int MATH_ILog2(u32 x)
{
  return (int) (31 - MATH_CountLeadingZeros(x));
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


