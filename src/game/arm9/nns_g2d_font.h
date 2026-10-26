#ifndef GAME_ARM9_NNS_G2D_FONT_H
#define GAME_ARM9_NNS_G2D_FONT_H

typedef struct NNSG2dFont NNSG2dFont;
typedef struct NNSG2dCharWidths NNSG2dCharWidths;
typedef struct NNSG2dTextRect NNSG2dTextRect;
typedef struct LC_INFO LC_INFO;
typedef struct NNSG2dCharCanvas NNSG2dCharCanvas;
typedef struct NNSG2dGlyph NNSG2dGlyph;
typedef struct CharCursor CharCursor;
typedef struct TaggedNode TaggedNode;

#include "../arm9/nns_g2d_font_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_font.c, prototypes copied from their definitions. */

struct FontCMap;
struct NNSG2dFont;
struct NNSG2dTextRect;
struct LC_INFO;
struct NNSG2dCharCanvas;
struct NNSG2dGlyph;
struct Surface;
struct SurfaceTiled;
struct SurfaceSwizzled;
struct Pen;
struct NNSG2dCanvas;
struct BitReader;
struct CharCursor;
struct TaggedNode;
typedef struct NNSG2dFont NNSG2dFont;
typedef struct NNSG2dTextRect NNSG2dTextRect;
typedef struct LC_INFO LC_INFO;
typedef struct NNSG2dCharCanvas NNSG2dCharCanvas;
typedef struct NNSG2dGlyph NNSG2dGlyph;
typedef struct CharCursor CharCursor;
typedef struct TaggedNode TaggedNode;

#include "../types.h"
#include "../arm9/nns_g2d_font_types.h"
#include "../sdk_gx.h"

u16 NNSi_G2dFontGetGlyphIndexFromCMap(struct FontCMap *tbl, u16 charCode);
void NNS_G2dFontInitUTF16(NNSG2dFont *pFont, void *pResource);
u16 NNS_G2dFontGetGlyphIndex(const NNSG2dFont *pFont, u16 charCode);
const NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(const NNSG2dFont *pFont, u32 idx);
int NNS_G2dFontGetStringWidth(const NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos);
int NNS_G2dFontGetTextHeight(const NNSG2dFont *pFont, int vSpace, const void *txt);
NNSG2dTextRect NNS_G2dFontGetTextRect(const NNSG2dFont *pFont, int hSpace, int vSpace, const void *txt);
int NNSi_G2dCalcRectMask(int x, int y, int w, int h, int sw0, int sh0);
u32 NNSi_G2dGetOamShapeCode(const u8 *p);
void NNSi_G2dCharCanvasFill(u32 *dst, int x, int y, int w, int h, u32 val, int bpp);
void NNSi_G2dBlitCharData(LC_INFO *i);
void NNSi_G2dCharCanvasDrawText(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void NNSi_G2dCharCanvasDrawTextForVRAM(const NNSG2dCharCanvas * pCC, const NNSG2dFont * pFont, int x, int y, int cl, const NNSG2dGlyph * pGlyph);
void NNSi_G2dSurfaceFill(struct Surface *s, u32 arg);
void NNSi_G2dSurfaceFillTiled(struct Surface *s, u32 arg);
void NNSi_G2dSurfaceFillRect(struct SurfaceTiled *s, u32 arg, int x, int y, int w, int h);
void NNSi_G2dSurfaceFillRectSwizzled(struct SurfaceSwizzled *s, u32 arg, int x, int y, int w, int h);
void NNSi_G2dInitPen(struct Pen *p, void *charBase, int areaWidth, int areaHeight, int dstBpp, const void *vtable, int param);
s8 NNSi_G2dCharCanvasDrawChar(struct NNSG2dCanvas *ctx, NNSG2dFont *font, int x, int y, int cl, u16 code);
void NNSi_G2dInitPenSimple(struct Pen *pen, void *charBase, int areaWidth, int areaHeight, int dstBpp);
void NNS_G2dCharCanvasInitForVRAM(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode);
void NNS_G2dMapScrToCharText(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
void NNSi_G2dFillScrCharArea(u16 *pScrBase, int w, int h, int scnWidth, int charNo, int cplt);
u32 NNSi_G2dCalcCharAreaSize(u32 areaWidth, u32 areaHeight);
int NNSi_G2dMakeCharObjArea(GXOamAttr *oam, int areaWidth, int areaHeight, int x, int y, int color, int charName, int vramShift);
u32 NNSi_G2dBitReaderRead(struct BitReader *reader, int nBits);
u16 NNSi_G2dReadCharUTF16(const void ** cursorArg);
u32 GetTaggedPayloadSize(const u8 *tag, const TaggedNode *node);
/* END mkheaders: generated region */

#endif
