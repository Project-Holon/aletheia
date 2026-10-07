/*
 * function: func_02066B84
 * address:  0x02066B84
 * packet:   pkt_02066740
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   tbl_020A17F0    0x020A17F0  data
 *   tbl_020A17D8    0x020A17D8  data
 *   tbl_020A1824    0x020A1824  data
 *   tbl_020A1844    0x020A1844  data
 *   tbl_020A1874    0x020A1874  data
 *   tbl_020A181C    0x020A181C  data
 *   g_02148B2C      0x02148B2C  data
 *
 * NitroSystem g2d CalcSpriteParams_ (g2d_OamSoftwareSpriteDraw.c): the
 * software-sprite texture setup for one OAM.  Writes TEXIMAGE_PARAM for the
 * 2D- or 1D-mapped character layout, computes the quad's UV rectangle and
 * extent into a SpriteParams { u0, v0, u1, v1, sx, sy }, applies the OAM
 * flips (and the optional UV flip-correct hook s_pUVFlipCorrectFunc, the
 * word at 0x02148B2C), and writes TEXPLTT_BASE.  Tables: 0x020A1824
 * GetNumTexChar_'s texSize_, 0x020A1844 / 0x020A1874 gxTexSizeSTbl /
 * gxTexSizeTTbl, 0x020A181C pltFmtTbl, 0x020A17F0 / 0x020A17D8
 * NNSi_objSizeWTbl / HTbl.
 *
 * Closed in wave 12 on the first compile of the library's own shape: the
 * seven NNS inlines as written (CalcUVFor3DDirect2DMap_ with charName as a
 * u16 PARAMETER shifted in place, SetTextureParamsFor3DDirect1DMap_ with
 * u16 shapeBit/sizeBit, GX_PACK_TEXIMAGE_PARAM, DoFlip_ through pointers,
 * GetOffsetByteSizeOfPlt_), a SpriteParams struct instead of an fx32
 * array, and the NitroSDK GXOamAttr union.  The hand transcription sat at
 * 144 out (docs/notes/pkt_02066B84.c.txt).  Front end: ../2.0/sp2 and
 * ../2.0/sp2p2 identical; 1.1p1 is 600 bytes.
 */

#include "../include/G_02148B2C.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;
typedef int            BOOL;
typedef s32            fx32;

#define reg_G3_TEXIMAGE_PARAM (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE   (*(volatile u32 *)0x040004AC)

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
typedef enum {
    GX_TEXFMT_NONE = 0, GX_TEXFMT_A3I5 = 1, GX_TEXFMT_PLTT4 = 2, GX_TEXFMT_PLTT16 = 3,
    GX_TEXFMT_PLTT256 = 4, GX_TEXFMT_COMP4x4 = 5, GX_TEXFMT_A5I3 = 6, GX_TEXFMT_DIRECT = 7
} GXTexFmt;
typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;
typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;
typedef enum { GX_TEXPLTTCOLOR0_USE = 0 } GXTexPlttColor0;
typedef enum { GX_OBJVRAMMODE_CHAR_2D = 0 } GXOBJVRamModeChar;

typedef struct {
    GXTexSizeS sizeS;
    GXTexSizeT sizeT;
    GXTexFmt fmt;
    BOOL bExtendedPlt;
    GXTexPlttColor0 plttUse;
    GXOBJVRamModeChar mappingType;
} NNSG2dImageAttr;

typedef struct SpriteParams {
    fx32 u0;
    fx32 v0;
    fx32 u1;
    fx32 v1;
    int sx;
    int sy;
} SpriteParams;

typedef void (*UVFlipCorrectFunc)(fx32 *pU0, fx32 *pV0, fx32 *pU1, fx32 *pV1, BOOL bFlipH, BOOL bFlipV);

extern struct G_02148B2C g_02148B2C;           /* s_pUVFlipCorrectFunc */
extern const u16 tbl_020A17F0[3][4];           /* NNSi_objSizeWTbl */
extern const u16 tbl_020A17D8[3][4];           /* NNSi_objSizeHTbl */
extern const u32 tbl_020A1824[8];              /* GetNumTexChar_::texSize_ */
extern const GXTexSizeS tbl_020A1844[3][4];    /* gxTexSizeSTbl */
extern const GXTexSizeT tbl_020A1874[3][4];    /* gxTexSizeTTbl */
extern const GXTexFmt tbl_020A181C[2];         /* pltFmtTbl */

#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr) \
    ((u32)(((addr) >> 3) | \
           ((texFmt) << 26) | \
           ((texGen) << 30) | \
           ((s) << 20) | \
           ((t) << 23) | \
           ((repeat) << 16) | \
           ((flip) << 18) | \
           ((pltt0) << 29)))

static inline void G3_TexPlttBase(u32 addr, GXTexFmt texfmt)
{
    reg_G3_TEXPLTT_BASE = (u32)((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4)));
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
static inline BOOL NNSi_G2dGetOamFlipH(const GXOamAttr *oamAttr)
{
    return (BOOL)(oamAttr->flipH);
}
static inline BOOL NNSi_G2dGetOamFlipV(const GXOamAttr *oamAttr)
{
    return (BOOL)(oamAttr->flipV);
}

static inline u32 GetNumTexChar_(GXTexSizeS texSize)
{
    return tbl_020A1824[texSize];
}

static inline void DoFlip_(BOOL bFlipH, BOOL bFlipV, fx32 *pRetU0, fx32 *pRetU1, fx32 *pRetV0, fx32 *pRetV1)
{
    {
        fx32 temp;
        if (bFlipH) {
            temp = *pRetU0;
            *pRetU0 = *pRetU1;
            *pRetU1 = temp;
        }

        if (bFlipV) {
            temp = *pRetV0;
            *pRetV0 = *pRetV1;
            *pRetV1 = temp;
        }

        if ((*(UVFlipCorrectFunc *)&g_02148B2C)) {
            (*(*(UVFlipCorrectFunc *)&g_02148B2C))(pRetU0, pRetV0, pRetU1, pRetV1, bFlipH, bFlipV);
        }
    }
}

static inline void CalcUVFor3DDirect2DMap_(const NNSG2dImageAttr *pTexImageAttr, u16 charName, fx32 *pRetU0, fx32 *pRetV0)
{
    if (pTexImageAttr->fmt == GX_TEXFMT_PLTT256) {
        charName >>= 1;
    }

    {
        {
            const u32 numCharPerOneLine = GetNumTexChar_(pTexImageAttr->sizeS);

            *pRetU0 = (fx32)(((charName & (numCharPerOneLine - 1)) << 3) << 12);
            *pRetV0 = ((charName >> pTexImageAttr->sizeS) << 3) << 12;
        }
    }
}

static inline void CalcUVFor3DDirect1DMap_(fx32 *pRetU0, fx32 *pRetV0)
{
    {
        *pRetU0 = 0;
        *pRetV0 = 0;
    }
}

static inline u32 GetOffsetByteSizeOfPlt_(GXTexFmt pltFmt, BOOL bExtendedPlt, u16 pltNo)
{
    if (bExtendedPlt) {
        return (u32)(pltNo << 9);
    } else {
        if (pltFmt == GX_TEXFMT_PLTT256) {
            return 0;
        } else {
            return (u32)(pltNo << 5);
        }
    }
}

static inline int GetCharacterNameShiftBit_(GXOBJVRamModeChar objMappingMode)
{
    return (objMappingMode & 0x00700000) >> 20;
}

static inline void SetTextureParamsFor3DDirect1DMap_(const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, GXOamShape shape, u16 charName)
{
    {
        const u16 shapeBit = (u16)((shape & 0x0000c000) >> 14);
        const u16 sizeBit = (u16)((shape & 0xc0000000) >> 30);
        const int shiftBit = (5 + GetCharacterNameShiftBit_(pTexImageAttr->mappingType));

        reg_G3_TEXIMAGE_PARAM
            = GX_PACK_TEXIMAGE_PARAM(pTexImageAttr->fmt,
                                     1,
                                     tbl_020A1844[shapeBit][sizeBit],
                                     tbl_020A1874[shapeBit][sizeBit],
                                     0,
                                     0,
                                     pTexImageAttr->plttUse,
                                     texBaseAddr + (charName << shiftBit));
    }
}

static inline void SetTextureParamsFor3DDirect2DMap_(const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr)
{
    {
        reg_G3_TEXIMAGE_PARAM
            = GX_PACK_TEXIMAGE_PARAM(pTexImageAttr->fmt,
                                     1,
                                     pTexImageAttr->sizeS,
                                     pTexImageAttr->sizeT,
                                     0,
                                     0,
                                     pTexImageAttr->plttUse,
                                     texBaseAddr);
    }
}

static inline void SetPaletteParamsFor3DDirect_(const NNSG2dImageAttr *pTexImageAttr, u32 pltBaseAddr, const GXOamAttr *pOam)
{
    {
        const GXTexFmt pltFmt = tbl_020A181C[pOam->colorMode];

        const u32 pltOffs
            = GetOffsetByteSizeOfPlt_(pltFmt,
                                      pTexImageAttr->bExtendedPlt,
                                      (u16)pOam->cParam);

        G3_TexPlttBase(pltBaseAddr + pltOffs, pltFmt);
    }
}

void func_02066B84(const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr, SpriteParams *pResult)
{
    const GXOamShape shapeOam = NNS_G2dGetOAMSize(pOam);
    const u16 charName = (u16)pOam->charNo;

    pResult->sx = NNS_G2dGetOamSizeX(&shapeOam);
    pResult->sy = NNS_G2dGetOamSizeY(&shapeOam);

    if (pTexImageAttr->mappingType == GX_OBJVRAMMODE_CHAR_2D) {
        SetTextureParamsFor3DDirect2DMap_(pTexImageAttr, texBaseAddr);
        CalcUVFor3DDirect2DMap_(pTexImageAttr, charName, &pResult->u0, &pResult->v0);
    } else {
        SetTextureParamsFor3DDirect1DMap_(pTexImageAttr, texBaseAddr, shapeOam, charName);
        CalcUVFor3DDirect1DMap_(&pResult->u0, &pResult->v0);
    }

    pResult->u1 = pResult->u0 + (pResult->sx << 12);
    pResult->v1 = pResult->v0 + (pResult->sy << 12);

    DoFlip_(NNSi_G2dGetOamFlipH(pOam),
            NNSi_G2dGetOamFlipV(pOam),
            &pResult->u0, &pResult->u1,
            &pResult->v0, &pResult->v1);

    SetPaletteParamsFor3DDirect_(pTexImageAttr, pltBaseAddr, pOam);
}
