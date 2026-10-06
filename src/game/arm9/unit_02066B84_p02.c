/*
 * file:     unit_02066B84_p02.c
 * unit:     yes
 * function: func_02066E30, func_02067080, func_02067340, func_0206775C
 * address:  0x02066E30
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
 *   func_02066B84   0x02066B84  arm
 *   g_02148B2C      0x02148B2C  data
 *   tbl_020A17F0    0x020A17F0  data
 *   tbl_020A17D8    0x020A17D8  data
 *   g_020A8218      0x020A8218  data
 *   g_02148B48      0x02148B48  data
 *   g_020A18AC      0x020A18AC  data
 *   func_02067080   0x02067080  arm
 *   func_02067B50   0x02067B50  arm
 *   func_02067B64   0x02067B64  arm
 *   func_0207D8E0   0x0207D8E0  arm
 */
struct NNSG2dRndCoreInstance;
struct G2dOamState;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef long           s32;

typedef s32            fx32;

typedef s16            fx16;

typedef enum {
    GX_OAM_EFFECT_NONE = 0x0000,
    GX_OAM_EFFECT_AFFINE = 0x0100,
    GX_OAM_EFFECT_NODISPLAY = 0x0200,
    GX_OAM_EFFECT_AFFINE_DOUBLE = 0x0300
} GXOamEffect;

typedef enum {
    GX_OAM_SHAPE_8x8 = 0
} GXOamShape;


struct Ctx { u32 f00; fx32 f04; u32 f08; };
typedef long long      s64;
typedef int            BOOL;

typedef struct { fx32 x; fx32 y; } NNSG2dFVec2;
typedef struct { fx32 _00; fx32 _01; fx32 _10; fx32 _11; } MtxFx22;

typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;

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

typedef enum { OAM_FLIP_NONE = 0, OAM_FLIP_H = 1, OAM_FLIP_V = 2, OAM_FLIP_HV = 3 } OAM_FLIP;

typedef struct { u16 attr0; u16 attr1; u16 attr2; } NNSG2dCellOAMAttrData;

typedef struct { u16 numOAMAttrs; u16 cellAttr; NNSG2dCellOAMAttrData *pOamAttrArray; } NNSG2dCellData;

typedef struct { MtxFx22 m22; u16 affineIndex[4][2]; } NNSG2dRndCore2DMtxCache;

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
    u32 mtx[12];
} NNSG2dRndCoreInstance;

extern NNSG2dRndCoreInstance *g_02148B48;     /* pTheInstance_ */

extern const u16 tbl_020A17F0[3][4];   /* NNSi_objSizeWTbl */
extern const u16 tbl_020A17D8[3][4];   /* NNSi_objSizeHTbl */

static inline GXOamEffect G2_GetOBJEffect(const GXOamAttr *oam)
{
    GXOamEffect effect;
    effect = (GXOamEffect)(oam->attr01 & 0x0300);
    if (effect == GX_OAM_EFFECT_AFFINE || effect == GX_OAM_EFFECT_AFFINE_DOUBLE)
        return effect;
    return (GXOamEffect)(effect | (oam->attr01 & 0x30000000));
}
static inline void G2_SetOBJEffect(GXOamAttr *oam, GXOamEffect eff, int rsParam)
{
    if (GX_OAM_EFFECT_AFFINE != eff && GX_OAM_EFFECT_AFFINE_DOUBLE != eff)
    {
        oam->attr01 = ((oam->attr01 & ~(0x00000300 | 0x3e000000)) |
                       eff);
    }
    else
    {
        oam->attr01 = ((oam->attr01 & ~(0x00000300 | 0x3e000000)) |
                       eff | (rsParam << 25));
    }
}
static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = ((oam->attr01 & ~(0x000000ff | 0x01ff0000)) |
                   (y & 0x000000ff) |
                   ((x & (0x01ff0000 >> 16)) << 16));
}

static inline GXOamShape NNS_G2dGetOAMSize(const GXOamAttr *oamAttr)
{
    const GXOamShape result = (GXOamShape)((0x0000c000 | 0xc0000000) & oamAttr->attr01);
    return result;
}
static inline int NNS_G2dGetOamSizeX(const GXOamShape *oamShape)
{
    return tbl_020A17F0[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
static inline int NNS_G2dGetOamSizeY(const GXOamShape *oamShape)
{
    return tbl_020A17D8[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
static inline s16 NNS_G2dRepeatXinCellSpace(s16 srcX)
{
    if (srcX > 255) {
        srcX |= 0xFF00;
    }
    return srcX;
}
static inline s16 NNS_G2dRepeatYinCellSpace(s16 srcY)
{
    if (srcY > 127) {
        srcY |= 0xFF00;
    }
    return srcY;
}
static inline s16 NNSi_G2dGetOamX(const GXOamAttr *oamAttr)
{
    {
        s16 val = (s16)((0x01ff0000 & oamAttr->attr01) >> 16);
        return val;
    }
}
static inline s16 NNSi_G2dGetOamY(const GXOamAttr *oamAttr)
{
    {
        s16 val = (s16)((0x000000ff & oamAttr->attr01) >> 0);
        return val;
    }
}
static inline void NNS_G2dGetOamTransFx32(const GXOamAttr *pOam, NNSG2dFVec2 *pRet)
{
    pRet->x = (fx32)(NNS_G2dRepeatXinCellSpace(NNSi_G2dGetOamX(pOam)) * 0x1000);
    pRet->y = (fx32)(NNS_G2dRepeatYinCellSpace(NNSi_G2dGetOamY(pOam)) * 0x1000);
}
static inline void NNSi_G2dRemovePositionAdjustmentFromDoubleAffineOBJ(const GXOamAttr *pOam, NNSG2dFVec2 *pV)
{
    if (G2_GetOBJEffect(pOam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        const GXOamShape oamShape = NNS_G2dGetOAMSize(pOam);
        const int halfW = NNS_G2dGetOamSizeX(&oamShape) << (12 - 1);
        const int halfH = NNS_G2dGetOamSizeY(&oamShape) << (12 - 1);

        pV->x += halfW;
        pV->y += halfH;
    }
}
static inline void NNSi_G2dAdjustDifferenceOfRotateOrientation(const GXOamAttr *pOam, const MtxFx22 *pM, NNSG2dFVec2 *pV, BOOL adjustDoubleAffine)
{
    {
        const GXOamShape oamShape = NNS_G2dGetOAMSize(pOam);
        const int halfW = NNS_G2dGetOamSizeX(&oamShape) >> 1;
        const int halfH = NNS_G2dGetOamSizeY(&oamShape) >> 1;

        pV->x += -(halfW << 12) + pM->_00 * halfW + pM->_10 * halfH;
        pV->y += -(halfH << 12) + pM->_01 * halfW + pM->_11 * halfH;

        if (adjustDoubleAffine) {
            pV->x -= halfW << 12;
            pV->y -= halfH << 12;
        }
    }
}
static inline void MulMtx22(const MtxFx22 *m, const NNSG2dFVec2 *pSrc, NNSG2dFVec2 *pDst)
{
    NNSG2dFVec2 temp;
    NNSG2dFVec2 *pV = pDst;
    if (pDst == pSrc) {
        pV = &temp;
    }

    pV->x = (fx32)((((s64)(m->_00) * pSrc->x + 0x800LL)
                    + ((s64)(m->_10) * pSrc->y + 0x800LL)) >> 12);
    pV->y = (fx32)((((s64)(m->_01) * pSrc->x + 0x800LL)
                    + ((s64)(m->_11) * pSrc->y + 0x800LL)) >> 12);

    if (pV == &temp) {
        *pDst = temp;
    }
}


extern void func_02066B84(const GXOamAttr *oam, u32 a, u32 b, u32 c, fx32 *uv);
extern void func_0207D8E0(const void *m);
extern u32 func_02067B50(const struct G2dOamState *p);
extern u32 func_02067B64(const struct G2dOamState *p);
void func_02066E30(int x, int y, int z, const GXOamAttr *oam, u32 a4, u32 a5, u32 a6);
void func_0206775C(GXOamAttr *oam);
extern struct Ctx g_02148B2C;
extern const u16 tbl_020A17F0[3][4];
extern const u16 tbl_020A17D8[3][4];
extern const fx32 g_020A8218;


#define reg_G3_MTX_SCALE   (*(volatile u32 *)0x0400046C)

#define reg_G3_MTX_TRANS   (*(volatile u32 *)0x04000470)

#define reg_G3_TEXCOORD    (*(volatile u32 *)0x04000488)

#define reg_G3_VTX_10      (*(volatile u32 *)0x04000490)

#define reg_G3_BEGIN_VTXS  (*(volatile u32 *)0x04000500)

#define reg_G3_END_VTXS    (*(volatile u32 *)0x04000504)


#define GX_FX16ST(x)  ((s16)((x) >> 8))

#define GX_ST(s, t)   ((u32)((u16)GX_FX16ST(s) | ((u16)GX_FX16ST(t) << 16)))

#define GX_VECVTX10(x, y, z) \
    ((u32)(((((x) >> 6) & 0x3ff) << 0) | ((((y) >> 6) & 0x3ff) << 10) | ((((z) >> 6) & 0x3ff) << 20)))

#define FX32_ONE 0x1000

#define FX16_ONE ((fx16)0x1000)


static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}

static inline void G3_TexCoord(fx32 s, fx32 t) { reg_G3_TEXCOORD = GX_ST(s, t); }

static inline void G3_Vtx10(fx16 x, fx16 y, fx16 z) { reg_G3_VTX_10 = GX_VECVTX10(x, y, z); }

static inline void G3_Begin(int prim) { reg_G3_BEGIN_VTXS = (u32)prim; }

static inline void G3_End(void) { reg_G3_END_VTXS = 0; }


static inline GXOamShape G2_GetOBJShape(const GXOamAttr *oam)
{
    return (GXOamShape)(oam->attr01 & (0x0000c000 | 0xc0000000));
}


/*
 * The composer's 3D-geometry emitter: one textured unit quad per call.
 * func_02066B84 fills a six-word UV/extent buffer from the OAM entry; an
 * affine-double entry is re-centred by half its object extent (objWidth /
 * objHeight tables at 0x020A17F0 / 0x020A17D8); then MTX_TRANSLATE (depth
 * biased by the render context's polygon counter when its gate is set),
 * MTX_SCALE, BEGIN_VTXS(QUADS), four TEXCOORD/VTX_10 pairs, END_VTXS, and the
 * counter advance.  Written with the TwlSDK inlines (G3_Translate, G3_Scale,
 * G3_TexCoord, G3_Vtx10, G3_Begin, G3_End, G2_GetOBJEffect, G2_GetOBJShape)
 * reproduced locally, since sources here are self-contained.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * ends `addeq sp, sp, #0x1c` / `popeq {r4, r5, r6, r7, pc}` at
 * 0x02067040/0x02067044 ahead of the five-instruction counter update at
 * 0x02067048..0x02067058; 1.1p1 -O4,p predicates the update
 * (ldrne/ldrne/ldrne/addne/strne), 584 bytes against 592.
 *
 * Levers, against docs/notes/pkt_02066E30.c.txt (576/386 under 1.1p1, pin
 * refused there on a different source): the SDK inline spellings; w and h
 * as named locals, h declared before w; and the two table reads written as
 * byte offsets, `tbl + shape * 8 + size * 2`, which gives the image's
 * shape-in-ip / size-in-lr assignment (the `[shape][size]` subscript form is
 * the same instructions with those two registers swapped, 10 bytes out).
 */
void func_02066E30(int x, int y, int z, const GXOamAttr *oam, u32 a4, u32 a5, u32 a6)
{
    fx32 uv[6];

    func_02066B84(oam, a4, a5, a6, uv);
    if (G2_GetOBJEffect(oam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        GXOamShape shape;
        int h;
        int w;
        shape = G2_GetOBJShape(oam);
        w = *(u16 *)((u8 *)tbl_020A17F0 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2);
        h = *(u16 *)((u8 *)tbl_020A17D8 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2);
        G3_Translate((x + (w >> 1)) << 12, (y + (h >> 1)) << 12,
                     g_02148B2C.f08 ? g_02148B2C.f04 + (z << 12) : z << 12);
    } else {
        G3_Translate(x << 12, y << 12,
                     g_02148B2C.f08 ? g_02148B2C.f04 + (z << 12) : z << 12);
    }
    G3_Scale(uv[4] << 12, uv[5] << 12, FX32_ONE);
    G3_Begin(1);
    G3_TexCoord(uv[0], uv[3]);
    G3_Vtx10(0, FX16_ONE, 0);
    G3_TexCoord(uv[2], uv[3]);
    G3_Vtx10(FX16_ONE, FX16_ONE, 0);
    G3_TexCoord(uv[2], uv[1]);
    G3_Vtx10(FX16_ONE, 0, 0);
    G3_TexCoord(uv[0], uv[1]);
    G3_Vtx10(0, 0, 0);
    G3_End();
    if (g_02148B2C.f08)
        g_02148B2C.f04 += g_020A8218;
}


/*
 * NitroSystem g2d DoAffineTransforme_ (g2d_RendererCore.c): read the OBJ
 * position back as fx32, undo the double-affine centring, rotate it by the
 * 2x2 SR matrix, apply the renderer's affine overwrite mode, correct for the
 * rotation centre (NNSi_G2dAdjustDifferenceOfRotateOrientation) and add the
 * base translation.  g_02148B48 is pTheInstance_; the two u16 [3][4] tables
 * are NNSi_objSizeWTbl / NNSi_objSizeHTbl.  Only caller: func_02067340
 * (DrawCellToSurface2D_).
 *
 * Closed 2026-09-24 (wave 21, online research lane) from DIFF 2
 * (docs/notes/pkt_02066E30.c.txt).  Two things together, neither enough on
 * its own:
 *   - s32 (and so fx32) typedef'd `long`, as NitroSDK's own types.h does
 *     (`typedef signed long s32;`); int gives 696 bytes with the sum below;
 *   - the rotation-centre correction written as one sum per axis,
 *     `pV->x += -(halfW << 12) + _00 * halfW + _10 * halfH`, instead of the
 *     wave-13 split accumulator (which is 2 out under either s32).
 * Provenance: the shape was read off the public NitroSystem reconstruction
 * that pret/pokeplatinum builds against (github.com/ntrtwl/NitroSystem,
 * libraries/g2d/include/g2di_OamUtil.h, and NitroSDK's include/nitro/types.h
 * from github.com/ntrtwl/NitroSDK); that library's own g2d_RendererCore.c,
 * preprocessed and compiled here, is EXACT at this address, and a reduction
 * of it isolated the two points above.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02067080.c \
 *       --func func_02067080 --addr 0x02067080 --arm --cc ../2.0/sp2
 */
void func_02067080(const MtxFx22 *pMtxSR, GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans)
{
    NNSG2dFVec2 objTrans;
    GXOamEffect effectTypeAfter;

    NNS_G2dGetOamTransFx32(pOam, &objTrans);
    NNSi_G2dRemovePositionAdjustmentFromDoubleAffineOBJ(pOam, &objTrans);
    MulMtx22(pMtxSR, &objTrans, &objTrans);

    if (g_02148B48->affineOverwriteMode != 0) {
        if (g_02148B48->affineOverwriteMode == 2) {
            effectTypeAfter = GX_OAM_EFFECT_AFFINE_DOUBLE;
        } else {
            effectTypeAfter = GX_OAM_EFFECT_AFFINE;
        }

        G2_SetOBJEffect(pOam, effectTypeAfter, 0);
    }

    {
        const BOOL bShouldAdjust = G2_GetOBJEffect(pOam) == GX_OAM_EFFECT_AFFINE_DOUBLE;

        NNSi_G2dAdjustDifferenceOfRotateOrientation(pOam, pMtxSR, &objTrans, bShouldAdjust);
    }

    objTrans.x += pBaseTrans->x;
    objTrans.y += pBaseTrans->y;
    G2_SetOBJPosition(pOam, objTrans.x >> 12, objTrans.y >> 12);
}
extern const MtxFx32 g_020A18AC;              /* mtxIdentity_ */
struct G2dOamState;
extern u32 func_02067B50(const struct G2dOamState *p);
extern u32 func_02067B64(const struct G2dOamState *p);

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
    if (g_02148B48->pCurrentMxt) {
        return g_02148B48->pCurrentMxt;
    } else {
        return &g_020A18AC;
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
        (*pFunc)(g_02148B48, pCell, oamIdx);
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
                affineIdx = (*g_02148B48->pFuncOamAffineRegister)(&pMtxCache->m22);
            } else {
                MtxFx22 mtxTemp;
                MakeFlipMtx_(&pMtxCache->m22, &mtxTemp, type);
                affineIdx = (*g_02148B48->pFuncOamAffineRegister)(&mtxTemp);
            }

            SetMtxCacheAffineIndex_(pMtxCache, pSurface->type, type, affineIdx);
        }
    }

    return affineIdx;
}
static inline void OverwriteOamFlipFlag_(GXOamAttr *pOam)
{
    {
        const BOOL bFlipH = func_02067B50((const struct G2dOamState *)g_02148B48) ^ NNSi_G2dGetOamFlipH(pOam);
        const BOOL bFlipV = func_02067B64((const struct G2dOamState *)g_02148B48) ^ NNSi_G2dGetOamFlipV(pOam);

        pOam->attr01 &= ~0x10000000;
        pOam->attr01 |= bFlipH << 28;

        pOam->attr01 &= ~0x20000000;
        pOam->attr01 |= bFlipV << 29;
    }
}
static inline void DoFlipTransforme_(GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans)
{
    if (g_02148B48->flipFlag != 0) {
        const GXOamShape shape = NNS_G2dGetOAMSize(pOam);

        OverwriteOamFlipFlag_(pOam);

        if (func_02067B50((const struct G2dOamState *)g_02148B48)) {
            pOam->x = -pOam->x - NNS_G2dGetOamSizeX(&shape);
        }

        if (func_02067B64((const struct G2dOamState *)g_02148B48)) {
            pOam->y = (u8)(-pOam->y - NNS_G2dGetOamSizeY(&shape));
        }
    }

    pOam->x += pBaseTrans->x >> 12;
    pOam->y += pBaseTrans->y >> 12;
}

/*
 * NitroSystem g2d DrawCellToSurface2D_ (g2d_RendererCore.c): the 2D (OAM)
 * cell draw loop.  g_02148B48 is pTheInstance_ (NNSG2dRndCoreInstance),
 * g_020A18AC mtxIdentity_, func_02067080 DoAffineTransforme_,
 * func_02067B50 / func_02067B64 NNS_G2dIsRndCoreFlipH / FlipV, the two
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
 * at a four-register rotation, 46-48 out (docs/notes/func_02067340.c.txt).
 * Front end: ../2.0/sp2 and ../2.0/sp2p2 identical; 1.1p1 is 1040 bytes.
 */
void func_02067340(const NNSG2dRndCoreSurface *pSurface, const NNSG2dCellData *pCell)
{
    NNSG2dFVec2 baseTrans;
    MtxFx22 mtxSR;
    const MtxFx32 *pCurrMtx = RndCoreGetCurrentMtx_();

    NNSi_G2dGetMtxTrans(pCurrMtx, &baseTrans);

    baseTrans.x -= pSurface->viewRect.posTopLeft.x;
    baseTrans.y -= pSurface->viewRect.posTopLeft.y;

    {
        const u32 baseCharOffset = g_02148B48->base2DCharOffset;
        const BOOL bAffined = IsRndCore2DAffineTransformed_(g_02148B48);

        u16 i;
        GXOamAttr *pTempOam = &g_02148B48->currentOam;
        u16 oamAffinIdx = 0xFFFE;

        for (i = 0; i < pCell->numOAMAttrs; i++) {
            g_02148B48->bDrawEnable = 1;
            NNS_G2dCopyCellAsOamAttr(pCell, i, pTempOam);

            HandleCellOamBackFunc_(pSurface->pBeforeDrawOamBackFunc, pCell, i);

            if (!g_02148B48->bDrawEnable) {
                continue;
            }

            pTempOam->charNo += baseCharOffset;

            if (bAffined) {
                oamAffinIdx =
                    LoadMtxCacheAsAffineParams_(g_02148B48->pCurrentMtxCacheFor2D,
                                                pSurface,
                                                (OAM_FLIP)((NNSi_G2dGetOamFlipV(pTempOam) << 1) | NNSi_G2dGetOamFlipH(pTempOam)));
                NNSi_G2dGetMtxRS(pCurrMtx, &mtxSR);
                func_02067080(&mtxSR, pTempOam, &baseTrans);
            } else {
                oamAffinIdx = 0xFFFE;
                DoFlipTransforme_(pTempOam, &baseTrans);
            }

            if (1 != (*g_02148B48->pFuncOamRegister)(pTempOam, oamAffinIdx, 0)) {
                return;
            }

            HandleCellOamBackFunc_(pSurface->pAfterDrawOamBackFunc, pCell, i);
        }
    }
}



static inline int OamX(const GXOamAttr *oam)
{
    int x = oam->x;
    if (x > 0xff)
        x = (s16)(x | 0xff00);
    return x;
}


static inline int OamY(const GXOamAttr *oam)
{
    int y = oam->y;
    if (y > 0x7f)
        y = (s16)(y | 0xff00);
    return y;
}


static inline u16 PosX_(const GXOamAttr *oam, GXOamShape shape)
{
    if (func_02067B50((const struct G2dOamState *)g_02148B48)) {
        int x = OamX(oam);
        return -(x + *(u16 *)((u8 *)tbl_020A17F0 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2));
    } else
        return OamX(oam);
}

static inline u16 PosY_(const GXOamAttr *oam, GXOamShape shape)
{
    if (func_02067B64((const struct G2dOamState *)g_02148B48)) {
        int y = OamY(oam);
        return -(y + *(u16 *)((u8 *)tbl_020A17D8 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2));
    } else
        return OamY(oam);
}

/*
 * NitroSystem g2d renderer core, the 3D (software sprite) per-OAM draw:
 * load the instance's 3D matrix (func_0207D8E0 on rig +0x40), and when the
 * rig's flip flag (+0x24) is set, mirror x/y about the sprite's own extent
 * (func_02067B50 / func_02067B64 are IsFlipH / IsFlipV), write the combined
 * flip bits back into the OAM, then draw it through func_02066E30 with
 * z = -1, &imageProxy->attr (rig +0x08, +0xc) and the two VRAM bases at
 * rig +0x14 / +0x18.  Sibling of func_02067340 (the 2D path).
 *
 * FRONT END: a ../2.0/sp2 pin row (sp2p2 gives the same bytes; 1.1p1 is
 * 556 bytes).  Levers, each measured against the wave-10 572/95 source:
 *   - the mirrored positions come from two inlines RETURNING u16, bound
 *     to s16 locals: that is the image's (s16)(u16) pair at each join and
 *     the deferred sign extension of y at the call (95 -> 65);
 *   - inside each inline the OAM coordinate is first read into its own
 *     local, then the table extent is added, which gives `add r0, x, w`
 *     rather than `add r0, w, x` (65 -> 61);
 *   - the flip write-back is FOUR compound statements, clear-H, or-H,
 *     clear-V, or-V (61 -> EXACT).  The front end drops the store between
 *     each pair and keeps two, the first already carrying the cleared V
 *     bit; every two- or three-statement spelling leaves the value in a
 *     different register and moves the y argument's first shift.
 */
void func_0206775C(GXOamAttr *oam)
{
    func_0207D8E0(g_02148B48->mtx);
    if (g_02148B48->flipFlag != 0) {
        GXOamShape shape = G2_GetOBJShape(oam);
        s16 x = PosX_(oam, shape);
        s16 y = PosY_(oam, shape);
        int hf; u32 vf;
        hf = oam->flipH;
        hf = func_02067B50((const struct G2dOamState *)g_02148B48) ^ hf;
        vf = oam->flipV;
        vf = func_02067B64((const struct G2dOamState *)g_02148B48) ^ vf;
        oam->attr01 &= ~0x10000000;
        oam->attr01 |= hf << 28;
        oam->attr01 &= ~0x20000000;
        oam->attr01 |= vf << 29;
        func_02066E30(x, y, -1, oam, (u32)g_02148B48->pImgProxy + 0xc, g_02148B48->baseTexAddr3D, g_02148B48->basePltAddr3D);
    } else {
        func_02066E30(OamX(oam), OamY(oam), -1, oam, (u32)g_02148B48->pImgProxy + 0xc, g_02148B48->baseTexAddr3D, g_02148B48->basePltAddr3D);
    }
}