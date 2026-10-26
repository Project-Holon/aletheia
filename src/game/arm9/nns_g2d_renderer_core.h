#ifndef GAME_ARM9_NNS_G2D_RENDERER_CORE_H
#define GAME_ARM9_NNS_G2D_RENDERER_CORE_H

#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_gx.h"

/* Renderer core of the 2D graphics library. */

struct NNSG2dImageAttr;
typedef struct NNSG2dImageProxy NNSG2dImageProxy;
typedef struct NNSG2dPaletteProxy NNSG2dPaletteProxy;

typedef struct { fx32 x; fx32 y; } NNSG2dFVec2;

typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;

typedef struct { u16 attr0; u16 attr1; u16 attr2; } NNSG2dCellOAMAttrData;

typedef struct { u16 numOAMAttrs; u16 cellAttr; NNSG2dCellOAMAttrData *pOamAttrArray; } NNSG2dCellData;

typedef struct { MtxFx22 m22; u16 affineIndex[4][2]; } NNSG2dRndCore2DMtxCache;

struct NNSG2dRndCoreInstance;

typedef void (*DrawOamCB)(struct NNSG2dRndCoreInstance *pRend, const NNSG2dCellData *pCell, u16 oamIdx);

typedef void (*DrawCellCB)(struct NNSG2dRndCoreInstance *pRend, const NNSG2dCellData *pCell);

typedef struct {
    struct { NNSG2dFVec2 posTopLeft; NNSG2dFVec2 sizeView; } viewRect;
    BOOL bActive;
    u32 type;
    DrawCellCB pBeforeDrawCellBackFunc;
    DrawCellCB pAfterDrawCellBackFunc;
    DrawOamCB pBeforeDrawOamBackFunc;
    DrawOamCB pAfterDrawOamBackFunc;
} NNSG2dRndCoreSurface;

typedef BOOL (*OamRegisterFunc)(const GXOamAttr *pOam, u16 affineIndex, BOOL bDoubleAffine);

typedef u16 (*OamAffineRegisterFunc)(const MtxFx22 *mtx);

typedef struct NNSG2dRndCoreInstance {
    NNSG2dRndCoreSurface *pCurrentTargetSurface;
    u32 affineOverwriteMode;
    const NNSG2dImageProxy *pImgProxy;
    const NNSG2dPaletteProxy *pPltProxy;
    u32 base2DCharOffset;
    u32 baseTexAddr3D;
    u32 basePltAddr3D;
    OamRegisterFunc pFuncOamRegister;
    OamAffineRegisterFunc pFuncOamAffineRegister;
    u32 flipFlag;
    NNSG2dRndCore2DMtxCache *pCurrentMtxCacheFor2D;
    const MtxFx32 *pCurrentMxt;
    BOOL bDrawEnable;
    fx32 zFor3DSoftwareSprite;
    GXOamAttr currentOam;
    MtxFx43 mtx;
} NNSG2dRndCoreInstance;

struct NNSG2dImageProxy;
struct NNSG2dPaletteProxy;
void NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(u32 enabled);
void NNS_G2dResetOamSoftEmuAutoZOffset(void);
void NNS_G2dSetOamSoftEmuAutoZOffsetStep(fx32 step);
int NNS_G2dGetOamSoftEmuAutoZOffsetStep(void);
void NNSi_G2dDrawSoftEmuSprite(int x, int y, int z, const GXOamAttr *oam, const struct NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr);
void NNSi_G2dDoAffineTransforme(const MtxFx22 *pMtxSR, GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans);
void NNSi_G2dDrawCellToSurface2D(const NNSG2dRndCoreSurface *pSurface, const NNSG2dCellData *pCell);
void NNSi_G2dDrawOam3D(GXOamAttr *oam);
void NNSi_G2dDrawCellToSurface3D(const NNSG2dRndCoreSurface *pSurface, const NNSG2dCellData *pCell);
void NNS_G2dInitRndCore(NNSG2dRndCoreInstance *pRnd);
void NNS_G2dSetRndCoreImageProxy(NNSG2dRndCoreInstance *pRnd, const NNSG2dImageProxy *pImgProxy, const NNSG2dPaletteProxy *pPltProxy);
void NNS_G2dSetRndCoreOamRegisterFunc(NNSG2dRndCoreInstance *pRnd, OamRegisterFunc pFuncOamRegister, OamAffineRegisterFunc pFuncOamAffineRegister);
void NNS_G2dSetRndCoreAffineOverwriteMode(NNSG2dRndCoreInstance *pRnd, u32 mode);
void NNS_G2dSetRndCoreCurrentMtx3D(const MtxFx32 *pMtx);
void NNS_G2dSetRndCoreCurrentMtx2D(const MtxFx32 *pMtx, NNSG2dRndCore2DMtxCache *pMtxCache);
void NNS_G2dSetRndCore3DSoftSpriteZvalue(NNSG2dRndCoreInstance *pRnd, fx32 zFor3DSoftwareSprite);
void NNS_G2dSetRndCoreSurface(NNSG2dRndCoreInstance *pRnd, NNSG2dRndCoreSurface *pSurface);
u32 NNSi_G2dIsRndCoreFlipH(const NNSG2dRndCoreInstance *pRnd);
u32 NNSi_G2dIsRndCoreFlipV(const NNSG2dRndCoreInstance *pRnd);
void NNS_G2dSetRndCoreFlipMode(NNSG2dRndCoreInstance *pRnd, BOOL bFlipH, BOOL bFlipV);
void NNS_G2dRndCoreBeginRendering(NNSG2dRndCoreInstance *pRnd);
void NNS_G2dRndCoreEndRendering(void);
void NNS_G2dRndCoreDrawCell(const NNSG2dCellData *pCell);
void NNS_G2dRndCoreDrawCellVramTransfer(const NNSG2dCellData *pCell, s32 cellTransferHandle);

#endif
