#ifndef GAME_ARM9_NNS_G2D_RENDERER_TYPES_H
#define GAME_ARM9_NNS_G2D_RENDERER_TYPES_H

#include "../types.h"
#include "../sdk_fx.h"
#include "../arm9/nns_g2d_renderer_core.h"

/* The renderer layer above the renderer core (nns_g2d_renderer.c, nns_g2d_renderer_mtx_cache.c). */

typedef struct MCMMtxState {
    u16 mtxCacheIdx;
    u16 groupID;
    u16 stateType;
    u16 pad16;
} MCMMtxState;

struct CellDrawState;
struct RndOamCell;
typedef struct NNSG2dRenderSurface NNSG2dRenderSurface;

/* A render surface starts with the core surface (view rectangle, active flag, type). */
struct NNSG2dRenderSurface {
    u8   pad_00[0x10];
    int  isActive;
    int  type;
    void (*pBeforeDrawCellFunc)(struct CellDrawState *pDrawState, void *pCellData);
    void (*pAfterDrawCellFunc)(void *pDrawState, void *pCellData);
    void (*pBeforeDrawOamFunc)(struct RndOamCell *c, void *pCellData, void *pOam);
    void (*pCallOamFunc)(void *pRend, void *pCellData, void *pOam);
    OamRegisterFunc pFuncOamRegister;
    OamAffineRegisterFunc pFuncOamAffineRegister;
    NNSG2dRenderSurface *pNextSurface;
    int  (*pFuncVisibilityCulling)(void *pCellData, MtxFx32 *pMtx, void *pSurface);
    void (*pBeforeDrawCellBackFunc)(void *pRend, void *pSurface, void *pCellData, MtxFx32 *pMtx);
    void (*pAfterDrawCellBackFunc)(void *pRend, void *pSurface, void *pCellData, MtxFx32 *pMtx);
    void (*pBeforeDrawOamBackFunc)(void *pRend, void *pSurface, void *pCellData, void *pOam, MtxFx32 *pMtx);
    void (*pAfterDrawOamBackFunc)(void *pRend, void *pSurface, void *pCellData, void *pOam, MtxFx32 *pMtx);
};

/* The renderer: the core (0x70 bytes) followed by the surface list and the overwrite parameters. */
typedef struct NNSG2dRendererInstance {
    NNSG2dRndCoreInstance rendererCore;     /* +0x00 */
    NNSG2dRenderSurface *pTargetSurfaceList; /* +0x70 */
    NNSG2dRenderSurface *pCurrentTargetSurface; /* +0x74 */
    void *currentCell;                      /* +0x78 */
    u32  flag;                              /* +0x7c */
    fx32 spriteZoffsetStep;
    u32  overwriteEnableFlag;
    u16  overwritePriority;
    u16  overwritePlttNo;
    int  overwriteObjMode;
    int  overwriteMosaicFlag;
    u16  overwritePlttNoOffset;
} NNSG2dRendererInstance;

#endif
