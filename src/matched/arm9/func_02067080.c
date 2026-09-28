/*
 * function: func_02067080
 * address:  0x02067080
 * packet:   pkt_02067080
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B48      0x02148B48  data
 *   tbl_020A17F0    0x020A17F0  data
 *   tbl_020A17D8    0x020A17D8  data
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef long           s32;   /* NitroSDK: signed long */
typedef long long      s64;
typedef int            BOOL;
typedef s32            fx32;

typedef enum {
    GX_OAM_EFFECT_NONE = 0x0000,
    GX_OAM_EFFECT_AFFINE = 0x0100,
    GX_OAM_EFFECT_NODISPLAY = 0x0200,
    GX_OAM_EFFECT_AFFINE_DOUBLE = 0x0300
} GXOamEffect;

typedef enum { GX_OAM_SHAPE_8x8 = 0 } GXOamShape;

typedef struct { u32 attr01; u16 attr2; u16 _3; } GXOamAttr;
typedef struct { fx32 x; fx32 y; } NNSG2dFVec2;
typedef struct { fx32 _00; fx32 _01; fx32 _10; fx32 _11; } MtxFx22;

typedef struct RndCore { u32 f00; u32 affineOverwriteMode; } RndCore;
extern RndCore *g_02148B48;
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
