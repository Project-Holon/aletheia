/*
 * function: NNSi_G2dDrawCellToSurface2D
 * address:  0x02067340
 * packet:   pkt_02066740
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sRndCoreInstance      0x02148B48  data
 *   sMtxIdentity      0x020A18AC  data
 *   NNSi_objSizeWTbl    0x020A17F0  data
 *   NNSi_objSizeHTbl    0x020A17D8  data
 *   NNSi_G2dDoAffineTransforme   0x02067080  arm
 *   NNSi_G2dIsRndCoreFlipH   0x02067B50  arm
 *   NNSi_G2dIsRndCoreFlipV   0x02067B64  arm
 *
 * NitroSystem g2d DrawCellToSurface2D_ (g2d_RendererCore.c): the 2D (OAM)
 * cell draw loop.  sRndCoreInstance is pTheInstance_ (NNSG2dRndCoreInstance),
 * sMtxIdentity mtxIdentity_, NNSi_G2dDoAffineTransforme DoAffineTransforme_,
 * NNSi_G2dIsRndCoreFlipH / NNSi_G2dIsRndCoreFlipV NNS_G2dIsRndCoreFlipH / FlipV, the two
 * u16 [3][4] tables NNSi_objSizeWTbl / NNSi_objSizeHTbl.
 *
 * Closed in wave 12 on the FIRST compile of the library's own shape: every
 * helper written as the NNS inline it is (RndCoreGetCurrentMtx_,
 * IsRndCore2DAffineTransformed_, NNS_G2dCopyCellAsOamAttr,
 * HandleCellOamBackFunc_, LoadMtxCacheAsAffineParams_ with MakeFlipMtx_,
 * DoFlipTransforme_ with OverwriteOamFlipFlag_), the NitroSDK GXOamAttr
 * union with anonymous bitfield structs, and the locals scoped as the
 * library scopes them (baseCharOffset / bAffined / i / pTempOam /
 * oamAffinIdx in an inner block).  The wave-10/11 hand transcription sat
 * at a four-register rotation, 46-48 out (docs/notes/NNSi_G2dDrawCellToSurface2D.c.txt).
 * Front end: ../2.0/sp2 and ../2.0/sp2p2 identical; 1.1p1 is 1040 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;
typedef int            BOOL;
typedef s32            fx32;

typedef struct { fx32 _00, _01, _10, _11; } MtxFx22;
typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;
typedef struct { fx32 x; fx32 y; } NNSG2dFVec2;

typedef union {
    struct { u16 attr0; u16 attr1; u16 attr2; u16 attr3; };
    struct { u32 attr01; u32 attr23; };
    struct {
        u32 y:8; u32 rsMode:2; u32 objMode:2; u32 mosaic:1; u32 colorMode:1; u32 shape:2;
        u32 x:9; u32 rsParam:5; u32 size:2;
        u32 charNo:10; u32 priority:2; u32 cParam:4; u32 _3:16;
    };
    struct { u32 _0:28; u32 flipH:1; u32 flipV:1; u32 _1:2; u32 _2:2; u32 _4:16; };
} GXOamAttr;

typedef enum { GX_OAM_SHAPE_8x8 = 0 } GXOamShape;
typedef enum { OAM_FLIP_NONE = 0, OAM_FLIP_H = 1, OAM_FLIP_V = 2, OAM_FLIP_HV = 3 } OAM_FLIP;

typedef struct { u16 attr0; u16 attr1; u16 attr2; } NNSG2dCellOAMAttrData;
typedef struct { u16 numOAMAttrs; u16 cellAttr; NNSG2dCellOAMAttrData *pOamAttrArray; } NNSG2dCellData;

typedef struct { MtxFx22 m22; u16 affineIndex[4][2]; } NNSG2dRndCore2DMtxCache;

struct NNSG2dRndCoreInstance;
typedef void (*DrawOamCB)(struct NNSG2dRndCoreInstance *pRend, const NNSG2dCellData *pCell, u16 oamIdx);

typedef struct {
    struct { NNSG2dFVec2 posTopLeft; NNSG2dFVec2 sizeView; } viewRect;
    BOOL bActive;
    u32 type;
    void *pBeforeDrawCellBackFunc;
    void *pAfterDrawCellBackFunc;
    DrawOamCB pBeforeDrawOamBackFunc;
    DrawOamCB pAfterDrawOamBackFunc;
} NNSG2dRndCoreSurface;

typedef struct NNSG2dRndCoreInstance {
    NNSG2dRndCoreSurface *pCurrentTargetSurface;
    u32 affineOverwriteMode;
    const void *pImgProxy;
    const void *pPltProxy;
    u32 base2DCharOffset;
    u32 baseTexAddr3D;
    u32 basePltAddr3D;
    BOOL (*pFuncOamRegister)(const GXOamAttr *pOam, u16 affineIndex, BOOL bDoubleAffine);
    u16 (*pFuncOamAffineRegister)(const MtxFx22 *mtx);
    u32 flipFlag;
    NNSG2dRndCore2DMtxCache *pCurrentMtxCacheFor2D;
    const MtxFx32 *pCurrentMxt;
    BOOL bDrawEnable;
    fx32 zFor3DSoftwareSprite;
    GXOamAttr currentOam;
} NNSG2dRndCoreInstance;

extern NNSG2dRndCoreInstance *sRndCoreInstance;     /* pTheInstance_ */
extern const MtxFx32 sMtxIdentity;              /* mtxIdentity_ */
extern const u16 NNSi_objSizeWTbl[3][4];
extern const u16 NNSi_objSizeHTbl[3][4];
extern void NNSi_G2dDoAffineTransforme(const MtxFx22 *pMtxSR, GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans);
struct G2dOamState;
extern u32 NNSi_G2dIsRndCoreFlipH(const struct G2dOamState *p);
extern u32 NNSi_G2dIsRndCoreFlipV(const struct G2dOamState *p);

static inline GXOamShape NNS_G2dGetOAMSize(const GXOamAttr *oamAttr)
{
    const GXOamShape result = (GXOamShape)((0x0000c000 | 0xc0000000) & oamAttr->attr01);
    return result;
}
static inline int NNS_G2dGetOamSizeX(const GXOamShape *oamShape)
{
    return NNSi_objSizeWTbl[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
static inline int NNS_G2dGetOamSizeY(const GXOamShape *oamShape)
{
    return NNSi_objSizeHTbl[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
static inline BOOL NNSi_G2dGetOamFlipH(const GXOamAttr *oamAttr)
{
    return (BOOL)(oamAttr->flipH);
}
static inline BOOL NNSi_G2dGetOamFlipV(const GXOamAttr *oamAttr)
{
    return (BOOL)(oamAttr->flipV);
}
static inline const MtxFx32 *RndCoreGetCurrentMtx_(void)
{
    if (sRndCoreInstance->pCurrentMxt) {
        return sRndCoreInstance->pCurrentMxt;
    } else {
        return &sMtxIdentity;
    }
}
static inline BOOL IsRndCore2DAffineTransformed_(const NNSG2dRndCoreInstance *pRnd)
{
    return (BOOL)(pRnd->flipFlag == 0 && pRnd->pCurrentMtxCacheFor2D != 0);
}
static inline void NNSi_G2dGetMtxTrans(const MtxFx32 *m, NNSG2dFVec2 *pRet)
{
    pRet->x = m->_20;
    pRet->y = m->_21;
}
static inline void NNSi_G2dGetMtxRS(const MtxFx32 *m, MtxFx22 *pRet)
{
    pRet->_00 = m->_00;
    pRet->_01 = m->_01;
    pRet->_10 = m->_10;
    pRet->_11 = m->_11;
}
static inline void NNS_G2dCopyCellAsOamAttr(const NNSG2dCellData *pCell, u16 idx, GXOamAttr *pDst)
{
    {
        const NNSG2dCellOAMAttrData *pSrc = pCell->pOamAttrArray + idx;

        pDst->attr0 = pSrc->attr0;
        pDst->attr1 = pSrc->attr1;
        pDst->attr2 = pSrc->attr2;
    }
}
static inline void HandleCellOamBackFunc_(DrawOamCB pFunc, const NNSG2dCellData *pCell, u16 oamIdx)
{
    if (pFunc) {
        (*pFunc)(sRndCoreInstance, pCell, oamIdx);
    }
}
static inline u16 GetMtxCacheAffineIndex_(const NNSG2dRndCore2DMtxCache *pMtxCache, u32 surfaceType, OAM_FLIP flipType)
{
    return pMtxCache->affineIndex[flipType][surfaceType - 1];
}
static inline void SetMtxCacheAffineIndex_(NNSG2dRndCore2DMtxCache *pMtxCache, u32 surfaceType, OAM_FLIP flipType, u16 affineIndex)
{
    pMtxCache->affineIndex[flipType][surfaceType - 1] = affineIndex;
}
static inline BOOL IsMtxCacheRegisteredAsAffineParams_(const u16 affineIdx)
{
    return (affineIdx != 0xFFFF) ? 1 : 0;
}
static inline void MakeFlipMtx_(const MtxFx22 *pMtxSrc, MtxFx22 *pMtxDst, OAM_FLIP type)
{
    {
        *pMtxDst = *pMtxSrc;

        if (type & OAM_FLIP_H) {
            pMtxDst->_00 = -pMtxDst->_00;
            pMtxDst->_01 = -pMtxDst->_01;
        }

        if (type & OAM_FLIP_V) {
            pMtxDst->_10 = -pMtxDst->_10;
            pMtxDst->_11 = -pMtxDst->_11;
        }
    }
}
static inline u16 LoadMtxCacheAsAffineParams_(NNSG2dRndCore2DMtxCache *pMtxCache, const NNSG2dRndCoreSurface *pSurface, OAM_FLIP type)
{
    u16 affineIdx = GetMtxCacheAffineIndex_(pMtxCache, pSurface->type, type);

    if (!IsMtxCacheRegisteredAsAffineParams_(affineIdx)) {
        {
            if (type == OAM_FLIP_NONE) {
                affineIdx = (*sRndCoreInstance->pFuncOamAffineRegister)(&pMtxCache->m22);
            } else {
                MtxFx22 mtxTemp;
                MakeFlipMtx_(&pMtxCache->m22, &mtxTemp, type);
                affineIdx = (*sRndCoreInstance->pFuncOamAffineRegister)(&mtxTemp);
            }

            SetMtxCacheAffineIndex_(pMtxCache, pSurface->type, type, affineIdx);
        }
    }

    return affineIdx;
}
static inline void OverwriteOamFlipFlag_(GXOamAttr *pOam)
{
    {
        const BOOL bFlipH = NNSi_G2dIsRndCoreFlipH((const struct G2dOamState *)sRndCoreInstance) ^ NNSi_G2dGetOamFlipH(pOam);
        const BOOL bFlipV = NNSi_G2dIsRndCoreFlipV((const struct G2dOamState *)sRndCoreInstance) ^ NNSi_G2dGetOamFlipV(pOam);

        pOam->attr01 &= ~0x10000000;
        pOam->attr01 |= bFlipH << 28;

        pOam->attr01 &= ~0x20000000;
        pOam->attr01 |= bFlipV << 29;
    }
}
static inline void DoFlipTransforme_(GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans)
{
    if (sRndCoreInstance->flipFlag != 0) {
        const GXOamShape shape = NNS_G2dGetOAMSize(pOam);

        OverwriteOamFlipFlag_(pOam);

        if (NNSi_G2dIsRndCoreFlipH((const struct G2dOamState *)sRndCoreInstance)) {
            pOam->x = -pOam->x - NNS_G2dGetOamSizeX(&shape);
        }

        if (NNSi_G2dIsRndCoreFlipV((const struct G2dOamState *)sRndCoreInstance)) {
            pOam->y = (u8)(-pOam->y - NNS_G2dGetOamSizeY(&shape));
        }
    }

    pOam->x += pBaseTrans->x >> 12;
    pOam->y += pBaseTrans->y >> 12;
}

void NNSi_G2dDrawCellToSurface2D(const NNSG2dRndCoreSurface *pSurface, const NNSG2dCellData *pCell)
{
    NNSG2dFVec2 baseTrans;
    MtxFx22 mtxSR;
    const MtxFx32 *pCurrMtx = RndCoreGetCurrentMtx_();

    NNSi_G2dGetMtxTrans(pCurrMtx, &baseTrans);

    baseTrans.x -= pSurface->viewRect.posTopLeft.x;
    baseTrans.y -= pSurface->viewRect.posTopLeft.y;

    {
        const u32 baseCharOffset = sRndCoreInstance->base2DCharOffset;
        const BOOL bAffined = IsRndCore2DAffineTransformed_(sRndCoreInstance);

        u16 i;
        GXOamAttr *pTempOam = &sRndCoreInstance->currentOam;
        u16 oamAffinIdx = 0xFFFE;

        for (i = 0; i < pCell->numOAMAttrs; i++) {
            sRndCoreInstance->bDrawEnable = 1;
            NNS_G2dCopyCellAsOamAttr(pCell, i, pTempOam);

            HandleCellOamBackFunc_(pSurface->pBeforeDrawOamBackFunc, pCell, i);

            if (!sRndCoreInstance->bDrawEnable) {
                continue;
            }

            pTempOam->charNo += baseCharOffset;

            if (bAffined) {
                oamAffinIdx =
                    LoadMtxCacheAsAffineParams_(sRndCoreInstance->pCurrentMtxCacheFor2D,
                                                pSurface,
                                                (OAM_FLIP)((NNSi_G2dGetOamFlipV(pTempOam) << 1) | NNSi_G2dGetOamFlipH(pTempOam)));
                NNSi_G2dGetMtxRS(pCurrMtx, &mtxSR);
                NNSi_G2dDoAffineTransforme(&mtxSR, pTempOam, &baseTrans);
            } else {
                oamAffinIdx = 0xFFFE;
                DoFlipTransforme_(pTempOam, &baseTrans);
            }

            if (1 != (*sRndCoreInstance->pFuncOamRegister)(pTempOam, oamAffinIdx, 0)) {
                return;
            }

            HandleCellOamBackFunc_(pSurface->pAfterDrawOamBackFunc, pCell, i);
        }
    }
}
