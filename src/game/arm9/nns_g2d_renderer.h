#ifndef GAME_ARM9_NNS_G2D_RENDERER_H
#define GAME_ARM9_NNS_G2D_RENDERER_H

typedef struct NNSG2dMultiCellInstance NNSG2dMultiCellInstance;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_renderer.c, prototypes copied from their definitions. */

struct RndOamCell;
struct CellDrawCmd;
struct Cmd020659D4;
struct NNSG2dMultiCellInstance;
struct MultiCellDrawCmd;
typedef struct NNSG2dMultiCellInstance NNSG2dMultiCellInstance;

#include "../arm9/nns_g2d_renderer_types.h"
#include "../types.h"
#include "../arm9/nns_g2d_renderer_core.h"
#include "../arm9/nns_g2d_renderer_core.h"
#include "../arm9/nns_g2d_renderer_core.h"

void NNSi_G2dRendererPreDrawOam(struct RndOamCell *c, void *pCellData, void *pOam);
void NNSi_G2dRendererCallSurfaceOamFunc(void *pRend, void *pCellData, void *pOam);
void NNSi_G2dRendererDrawCellToSurfaces(void *a);
void NNSi_G2dRendererDrawCellTransformed(struct CellDrawCmd *c);
void NNSi_G2dRendererDrawCellEntryTransformed(struct Cmd020659D4 *c);
void NNS_G2dInitRenderer(NNSG2dRendererInstance *pRend);
void NNS_G2dSetRendererTargetSurface(NNSG2dRendererInstance *pRend, NNSG2dRenderSurface *pNew);
void NNS_G2dInitRenderSurface(NNSG2dRenderSurface *p);
void NNS_G2dBeginRendering(NNSG2dRendererInstance *obj);
void NNS_G2dEndRendering(void);
void NNSi_G2dRendererDrawCellZOffset(void *pCell);
void NNSi_G2dRendererDrawCellTransformedZOffset(void *pCell);
void NNS_G2dDrawMultiCell(const NNSG2dMultiCellInstance *pMC);
void NNSi_G2dRendererDrawMultiCellTransformed(struct MultiCellDrawCmd *c);
void NNS_G2dPushMtx(void);
void NNS_G2dPopMtx(int n);
void NNS_G2dTranslate(fx32 x, fx32 y, fx32 z);
void NNS_G2dScale(fx32 x, fx32 y, fx32 z);
void NNS_G2dRotZ(fx32 sin, fx32 cos);
void *NNSi_G2dGetCurrentInstanceVramHandle(NNSG2dRendererInstance *p);
void NNSi_G2dSetRndCoreImageProxyVeneer(NNSG2dRndCoreInstance *pRnd, NNSG2dImageProxy *pImgProxy, NNSG2dPaletteProxy *pPltProxy);
void NNSi_G2dMtxConcat32(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab);
/* END mkheaders: generated region */

#endif
