#ifndef GAME_ARM9_NNS_G2D_RENDERER_MTX_CACHE_H
#define GAME_ARM9_NNS_G2D_RENDERER_MTX_CACHE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_renderer_mtx_cache.c, prototypes copied from their definitions. */

struct CellDrawState;

void NNSi_G2dRendererResetMtxSlot(void);
void NNSi_G2dMCMLoadCurrentMtxToCache(void);
void NNSi_G2dRendererBeforeDrawCell(struct CellDrawState *pDrawState, void *pCellData);
void NNSi_G2dRendererAfterDrawCell(void *pDrawState, void *pCellData);
/* END mkheaders: generated region */

#endif
