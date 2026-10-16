/*
 * file:     nns_g2d_renderer_core.c
 * unit:     yes
 * function: NNSi_G2dCalcSpriteParams, NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled, NNS_G2dResetOamSoftEmuAutoZOffset, NNS_G2dSetOamSoftEmuAutoZOffsetStep, NNS_G2dGetOamSoftEmuAutoZOffsetStep, NNSi_G2dDrawSoftEmuSprite, NNSi_G2dDoAffineTransforme, NNSi_G2dDrawCellToSurface2D, NNSi_G2dDrawOam3D, NNSi_G2dDrawCellToSurface3D, NNS_G2dInitRndCore, NNS_G2dSetRndCoreImageProxy, NNS_G2dSetRndCoreOamRegisterFunc, NNS_G2dSetRndCoreAffineOverwriteMode, NNS_G2dSetRndCoreCurrentMtx3D, NNS_G2dSetRndCoreCurrentMtx2D, NNS_G2dSetRndCore3DSoftSpriteZvalue, NNS_G2dSetRndCoreSurface, NNSi_G2dIsRndCoreFlipH, NNSi_G2dIsRndCoreFlipV, NNS_G2dSetRndCoreFlipMode, NNS_G2dRndCoreBeginRendering, NNS_G2dRndCoreEndRendering, NNS_G2dRndCoreDrawCell, NNS_G2dRndCoreDrawCellVramTransfer
 * address:  0x02066B84
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Constructor: clear 0x70 bytes, then seven field stores (0x24, 0x30, 0x28 in
 * image order; the +4/+8 pair merges into `stmib`).  The kept-constants tell
 * (docs/FRONTEND-PINS.md): the image passes the clear's zero as an immediate
 * (`mov r0, #0` at 0x02067A6C) and rematerialises it after the call
 * (`mov r1, #0` at 0x02067A78) under `push {r4, lr}`; 1.1p1 keeps one zero
 * live across the call in r4 and needs `push {r3, r4, r5, lr}` (42 bytes out,
 * docs/notes/pkt_02066E30.c.txt).  Under ../2.0/sp2 the same C is 64 bytes,
 * 0 mismatches.  Sole caller: src/matched/NNS_G2dInitRenderer.c (+0x08).
 * PIN: ../2.0/sp2, the "kept constants" tell.  The image rematerialises the
 * index-0 argument fresh at each of the four table calls (`mov r1, #0` at
 * 0x02067BC8, 0x02067C18, 0x02067C2C, 0x02067C4C) and stores each call's
 * result straight from r0 (`str r0, [r4, #0x14]` / `str r0, [r4, #0x18]`),
 * which is why the frame is `push {r3, r4, r5, lr}` (`38 40 2d e9`).
 * 1.1p1 -O4,p CSEs the zero into a callee-saved register, needing a fourth
 * (`push {r4, r5, r6, lr}`) and spending `mov r4, r0` / `mov r6, r0` copies
 * before each store: 276 bytes against the original's 268, 191 concrete out
 * with the whole tail shifted by eight.  Under the pin the same C is 268
 * bytes, 0 mismatches.
 * The rig-step entry of the NNS G2D cell composer, the sibling of
 * NNS_G2dRndCoreDrawCell (src/pending/NNS_G2dRndCoreDrawCell.c) that also takes a part
 * index.  Reads the singleton rig at sRndCoreInstance, raises its +0x30 gate,
 * runs the caller's +0x18 pre hook, and while the gate survives the hook
 * dispatches on the inner object's +0x14 mode through a four-entry table:
 * mode 0 -> NNSi_G2dDrawCellToSurface3D, modes 1 and 2 -> NNSi_G2dDrawCellToSurface2D, mode 3 empty
 * (the empty arm is what makes the `addls pc, pc, r0, lsl #2` table exist
 * at all).  When a1 is not the -1 sentinel it first sets the part's own
 * bit in NNSi_G2dGetCellTransferState(a1)->f20.  The +0x1c post hook closes it.
 * BYTE-CORRECT: 232 bytes, 0 concrete mismatches, under the pin below.
 * blocked:  label, no outside witness.  Two of the four relocation sites
 *   stay wildcarded: the +0x00B0 PC24 to NNSi_G2dDrawCellToSurface3D and the +0x00C0
 *   PC24 to NNSi_G2dDrawCellToSurface2D.  Each of those two callees is branched to from
 *   exactly two places image-wide, this function and NNS_G2dRndCoreDrawCell
 *   (0x02067D14), and that file is itself parked at MATCH, so neither
 *   caller attests the other and `label` refuses both.  Being one
 *   function, no `--suggest-split` cut exists.  It promotes with NO edit
 *   the moment 0x02067998 or 0x02067340 has a `matched` entry; both live
 *   in pkt_02066E30 (see docs/notes/pkt_02066E30.c.txt).
 * compiler pin, ../2.0/sp2, the "kept constants" tell of
 * src/matched/NNSi_G2dIsVramHandleSetEx.c measured again on this row: the image
 * materialises the -1 sentinel in a register, `mvn r0, #0` (`00 00 e0 e3`)
 * at 0x02067E20 followed by `cmp r4, r0` (`00 00 54 e1`) at 0x02067E24,
 * where dsi/1.1p1 -O4,p folds the constant into the compare as
 * `cmn r5, #1` and drops the separate materialisation: 228 bytes against
 * the original's 232, 117 concrete bytes out with everything after
 * 0x02067E20 shifted by four.  Twelve sentinel spellings are recorded as
 * measured in docs/notes/pkt_02067D14.c.txt and every one folds under
 * 1.1p1.  Under the pin the same C is 232 bytes, 0 mismatches.
 * The one C lever needed under the pin is declaration order
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md):
 * `u32 idx;` must be declared BEFORE `struct Inner *o;`, which is what
 * puts the inner object in r5 and the bit index in r4.  With `idx`
 * declared inside the `a1 != -1` arm the two callee-saved registers come
 * out swapped and 13 instructions differ at the same 232 bytes.
 *
 * symbols:
 *   NNSi_objSizeWTbl    0x020A17F0  data
 *   NNSi_objSizeHTbl    0x020A17D8  data
 *   sTexCharCountTbl    0x020A1824  data
 *   sGxTexSizeSTbl    0x020A1844  data
 *   sGxTexSizeTTbl    0x020A1874  data
 *   sPltFmtTbl    0x020A181C  data
 *   sUVFlipState      0x02148B2C  data
 *   sOamSoftEmuAutoZOffsetStep 0x020A8218 data
 *   sRndCoreInstance      0x02148B48  data
 *   sMtxIdentity      0x020A18AC  data
 *   G3_LoadMtx43   0x0207D8E0  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   NNSi_G2dIsVramHandleSet 0x020637BC  arm
 *   NNSi_G2dGetVramHandleValue 0x020637B4  arm
 *   NNSi_G2dIsVramHandleSetEx 0x0206380C  arm
 *   NNSi_G2dGetVramHandleEx 0x02063800  arm
 *   NNSi_G2dGetCellTransferState 0x02066878  arm
 */
#define reg_G3_TEXIMAGE_PARAM (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE   (*(volatile u32 *)0x040004AC)
#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr) \
    ((u32)(((addr) >> 3) | \
           ((texFmt) << 26) | \
           ((texGen) << 30) | \
           ((s) << 20) | \
           ((t) << 23) | \
           ((repeat) << 16) | \
           ((flip) << 18) | \
           ((pltt0) << 29)))
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
struct NNSG2dRndCoreInstance;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef long           s32;

typedef int            BOOL;

typedef s32            fx32;

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

typedef struct NNSG2dImageProxy {
    u32 baseAddrOfVram[3];      /* +0x00, indexed by VRAM type */
    NNSG2dImageAttr attr;       /* +0x0C */
} NNSG2dImageProxy;

typedef struct NNSG2dPaletteProxy NNSG2dPaletteProxy;

typedef struct SpriteParams {
    fx32 u0;
    fx32 v0;
    fx32 u1;
    fx32 v1;
    int sx;
    int sy;
} SpriteParams;

typedef void (*UVFlipCorrectFunc)(fx32 *pU0, fx32 *pV0, fx32 *pU1, fx32 *pV1, BOOL bFlipH, BOOL bFlipV);

struct UVFlipState { UVFlipCorrectFunc pFunc; fx32 zOffset; u32 zOffsetEnabled; };

typedef s16            fx16;

typedef enum {
    GX_OAM_EFFECT_NONE = 0x0000,
    GX_OAM_EFFECT_AFFINE = 0x0100,
    GX_OAM_EFFECT_NODISPLAY = 0x0200,
    GX_OAM_EFFECT_AFFINE_DOUBLE = 0x0300
} GXOamEffect;

typedef long long      s64;

typedef struct { fx32 x; fx32 y; } NNSG2dFVec2;

typedef struct { fx32 _00; fx32 _01; fx32 _10; fx32 _11; } MtxFx22;

typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;

typedef struct { fx32 _00, _01, _02, _10, _11, _12, _20, _21, _22, _30, _31, _32; } MtxFx43;

typedef enum { OAM_FLIP_NONE = 0, OAM_FLIP_H = 1, OAM_FLIP_V = 2, OAM_FLIP_HV = 3 } OAM_FLIP;

typedef struct { u16 attr0; u16 attr1; u16 attr2; } NNSG2dCellOAMAttrData;

typedef struct { u16 numOAMAttrs; u16 cellAttr; NNSG2dCellOAMAttrData *pOamAttrArray; } NNSG2dCellData;

typedef struct { MtxFx22 m22; u16 affineIndex[4][2]; } NNSG2dRndCore2DMtxCache;

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

typedef struct CellTransferState {
    u32          baseAddrOfVram[3]; /* +0x00 */
    u32          szDst;             /* +0x0c */
    const void  *pSrcNCGR;          /* +0x10 */
    const void  *pSrcNCBR;          /* +0x14 */
    u32          szSrcData;         /* +0x18 */
    BOOL         bActive;           /* +0x1c */
    u32          bDrawn;            /* +0x20 */
    u32          bTransferRequested;/* +0x24 */
    u32          srcOffset;         /* +0x28 */
    u32          szByte;            /* +0x2c */
} CellTransferState;

extern void G3_LoadMtx43(const MtxFx43 *m);
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);
extern BOOL NNSi_G2dIsVramHandleSet(const NNSG2dImageProxy *pImgProxy, u32 vramType);
extern u32 NNSi_G2dGetVramHandleValue(const NNSG2dImageProxy *pImgProxy, u32 vramType);
extern BOOL NNSi_G2dIsVramHandleSetEx(const NNSG2dPaletteProxy *pPltProxy, u32 vramType);
extern u32 NNSi_G2dGetVramHandleEx(const NNSG2dPaletteProxy *pPltProxy, u32 vramType);
extern CellTransferState *NNSi_G2dGetCellTransferState(u32 stateIdx);
void NNSi_G2dCalcSpriteParams(const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr, SpriteParams *pResult);
void NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(u32 enabled);
void NNS_G2dResetOamSoftEmuAutoZOffset(void);
void NNS_G2dSetOamSoftEmuAutoZOffsetStep(fx32 step);
int NNS_G2dGetOamSoftEmuAutoZOffsetStep(void);
void NNSi_G2dDrawSoftEmuSprite(int x, int y, int z, const GXOamAttr *oam, u32 a4, u32 a5, u32 a6);
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
extern struct UVFlipState sUVFlipState;          /* s_pUVFlipCorrectFunc and the draw state after it */
extern const u16 NNSi_objSizeWTbl[3][4];           /* NNSi_objSizeWTbl */
extern const u16 NNSi_objSizeHTbl[3][4];           /* NNSi_objSizeHTbl */
extern const u32 sTexCharCountTbl[8];              /* GetNumTexChar_::texSize_ */
extern const GXTexSizeS sGxTexSizeSTbl[3][4];    /* gxTexSizeSTbl */
extern const GXTexSizeT sGxTexSizeTTbl[3][4];    /* gxTexSizeTTbl */
extern const GXTexFmt sPltFmtTbl[2];         /* pltFmtTbl */
extern NNSG2dRndCoreInstance *sRndCoreInstance;     /* pTheInstance_ */
extern fx32 sOamSoftEmuAutoZOffsetStep;
extern const MtxFx32 sMtxIdentity;              /* mtxIdentity_ */




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




static inline u32 GetNumTexChar_(GXTexSizeS texSize)
{
    return sTexCharCountTbl[texSize];
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

        if (sUVFlipState.pFunc) {
            (*sUVFlipState.pFunc)(pRetU0, pRetV0, pRetU1, pRetV1, bFlipH, bFlipV);
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
                                     sGxTexSizeSTbl[shapeBit][sizeBit],
                                     sGxTexSizeTTbl[shapeBit][sizeBit],
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
        const GXTexFmt pltFmt = sPltFmtTbl[pOam->colorMode];

        const u32 pltOffs
            = GetOffsetByteSizeOfPlt_(pltFmt,
                                      pTexImageAttr->bExtendedPlt,
                                      (u16)pOam->cParam);

        G3_TexPlttBase(pltBaseAddr + pltOffs, pltFmt);
    }
}




/*
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
void NNSi_G2dCalcSpriteParams(const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr, SpriteParams *pResult)
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




void NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(u32 enabled)
{
    sUVFlipState.zOffsetEnabled = enabled;
}






void NNS_G2dResetOamSoftEmuAutoZOffset(void)
{
    sUVFlipState.zOffset = 0;
}





void NNS_G2dSetOamSoftEmuAutoZOffsetStep(fx32 step)
{
    sOamSoftEmuAutoZOffsetStep = step;
}





int NNS_G2dGetOamSoftEmuAutoZOffsetStep(void){ return *(int *)(0x20A8218); }



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
 * NNSi_G2dCalcSpriteParams fills a six-word UV/extent buffer from the OAM entry; an
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
void NNSi_G2dDrawSoftEmuSprite(int x, int y, int z, const GXOamAttr *oam, u32 a4, u32 a5, u32 a6)
{
    fx32 uv[6];

    NNSi_G2dCalcSpriteParams(oam, (const NNSG2dImageAttr *)a4, a5, a6, (SpriteParams *)uv);
    if (G2_GetOBJEffect(oam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        GXOamShape shape;
        int h;
        int w;
        shape = G2_GetOBJShape(oam);
        w = *(u16 *)((u8 *)NNSi_objSizeWTbl + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2);
        h = *(u16 *)((u8 *)NNSi_objSizeHTbl + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2);
        G3_Translate((x + (w >> 1)) << 12, (y + (h >> 1)) << 12,
                     sUVFlipState.zOffsetEnabled ? sUVFlipState.zOffset + (z << 12) : z << 12);
    } else {
        G3_Translate(x << 12, y << 12,
                     sUVFlipState.zOffsetEnabled ? sUVFlipState.zOffset + (z << 12) : z << 12);
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
    if (sUVFlipState.zOffsetEnabled)
        sUVFlipState.zOffset += sOamSoftEmuAutoZOffsetStep;
}




/*
 * NitroSystem g2d DoAffineTransforme_ (g2d_RendererCore.c): read the OBJ
 * position back as fx32, undo the double-affine centring, rotate it by the
 * 2x2 SR matrix, apply the renderer's affine overwrite mode, correct for the
 * rotation centre (NNSi_G2dAdjustDifferenceOfRotateOrientation) and add the
 * base translation.  sRndCoreInstance is pTheInstance_; the two u16 [3][4] tables
 * are NNSi_objSizeWTbl / NNSi_objSizeHTbl.  Only caller: NNSi_G2dDrawCellToSurface2D
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
 *   python3 tools/match.py one --src src/matched/NNSi_G2dDoAffineTransforme.c \
 *       --func NNSi_G2dDoAffineTransforme --addr 0x02067080 --arm --cc ../2.0/sp2
 */
void NNSi_G2dDoAffineTransforme(const MtxFx22 *pMtxSR, GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans)
{
    NNSG2dFVec2 objTrans;
    GXOamEffect effectTypeAfter;

    NNS_G2dGetOamTransFx32(pOam, &objTrans);
    NNSi_G2dRemovePositionAdjustmentFromDoubleAffineOBJ(pOam, &objTrans);
    MulMtx22(pMtxSR, &objTrans, &objTrans);

    if (sRndCoreInstance->affineOverwriteMode != 0) {
        if (sRndCoreInstance->affineOverwriteMode == 2) {
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
        const BOOL bFlipH = NNSi_G2dIsRndCoreFlipH(sRndCoreInstance) ^ NNSi_G2dGetOamFlipH(pOam);
        const BOOL bFlipV = NNSi_G2dIsRndCoreFlipV(sRndCoreInstance) ^ NNSi_G2dGetOamFlipV(pOam);

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

        if (NNSi_G2dIsRndCoreFlipH(sRndCoreInstance)) {
            pOam->x = -pOam->x - NNS_G2dGetOamSizeX(&shape);
        }

        if (NNSi_G2dIsRndCoreFlipV(sRndCoreInstance)) {
            pOam->y = (u8)(-pOam->y - NNS_G2dGetOamSizeY(&shape));
        }
    }

    pOam->x += pBaseTrans->x >> 12;
    pOam->y += pBaseTrans->y >> 12;
}



/*
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
    if (NNSi_G2dIsRndCoreFlipH(sRndCoreInstance)) {
        int x = OamX(oam);
        return -(x + *(u16 *)((u8 *)NNSi_objSizeWTbl + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2));
    } else
        return OamX(oam);
}



static inline u16 PosY_(const GXOamAttr *oam, GXOamShape shape)
{
    if (NNSi_G2dIsRndCoreFlipV(sRndCoreInstance)) {
        int y = OamY(oam);
        return -(y + *(u16 *)((u8 *)NNSi_objSizeHTbl + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2));
    } else
        return OamY(oam);
}



/*
 * NitroSystem g2d renderer core, the 3D (software sprite) per-OAM draw:
 * load the instance's 3D matrix (G3_LoadMtx43 on rig +0x40), and when the
 * rig's flip flag (+0x24) is set, mirror x/y about the sprite's own extent
 * (NNSi_G2dIsRndCoreFlipH / NNSi_G2dIsRndCoreFlipV are IsFlipH / IsFlipV), write the combined
 * flip bits back into the OAM, then draw it through NNSi_G2dDrawSoftEmuSprite with
 * z = -1, &imageProxy->attr (rig +0x08, +0xc) and the two VRAM bases at
 * rig +0x14 / +0x18.  Sibling of NNSi_G2dDrawCellToSurface2D (the 2D path).
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
void NNSi_G2dDrawOam3D(GXOamAttr *oam)
{
    G3_LoadMtx43(&sRndCoreInstance->mtx);
    if (sRndCoreInstance->flipFlag != 0) {
        GXOamShape shape = G2_GetOBJShape(oam);
        s16 x = PosX_(oam, shape);
        s16 y = PosY_(oam, shape);
        int hf; u32 vf;
        hf = oam->flipH;
        hf = NNSi_G2dIsRndCoreFlipH(sRndCoreInstance) ^ hf;
        vf = oam->flipV;
        vf = NNSi_G2dIsRndCoreFlipV(sRndCoreInstance) ^ vf;
        oam->attr01 &= ~0x10000000;
        oam->attr01 |= hf << 28;
        oam->attr01 &= ~0x20000000;
        oam->attr01 |= vf << 29;
        NNSi_G2dDrawSoftEmuSprite(x, y, -1, oam, (u32)&sRndCoreInstance->pImgProxy->attr, sRndCoreInstance->baseTexAddr3D, sRndCoreInstance->basePltAddr3D);
    } else {
        NNSi_G2dDrawSoftEmuSprite(OamX(oam), OamY(oam), -1, oam, (u32)&sRndCoreInstance->pImgProxy->attr, sRndCoreInstance->baseTexAddr3D, sRndCoreInstance->basePltAddr3D);
    }
}


/*
 * Draw every OAM entry of a cell through the two per-OAM hooks of the
 * surface: copy the entry into the renderer's scratch OAM, let the before
 * hook veto it, draw it, then run the after hook.
 */
/*
 * OAM affine composer, list driver.  Walks the u16-counted list at `lst`,
 * copying each six-byte row into the global rig's +0x38..+0x3c scratch
 * triple, invoking the caller's optional pre hook (+0x20) and post hook
 * (+0x24) around the composer NNSi_G2dDrawOam3D, which runs only while the
 * rig's +0x30 gate is still set.  The gate is re-armed to 1 at the top of
 * every iteration, so a hook may clear it to skip one row.
 *
 * BYTE-CORRECT: 200 bytes, 0 concrete mismatches.  PARKED, not filed.
 * blocking: label, no outside witness.  The sole wildcard is the +0x0088
 *   PC24 to NNSi_G2dDrawOam3D, whose ONLY branch anywhere in the image is the
 *   `bl` at 0x02067A20 inside this very function (verified by grep over
 *   asm/arm9/).  No cut helps: the site is inside the one function.  It
 *   converts with no edit the moment 0x0206775C has a `matched` entry;
 *   docs/notes/pkt_02066E30.c.txt records how close that row now is.
 *
 * Two levers, both needed:
 *   - the gate store `sRndCoreInstance->gate = 1;` must precede the read of
 *     `lst->rows`, or the row base is loaded first and the first 0x10
 *     bytes of the loop body permute.
 *   - the entry test is `lst->count <= i` on the ZERO counter, not
 *     `count == 0`: the image's `popls` is the unsigned compare of the
 *     loop's own pre-test, hoisted, and `== 0` gives `popeq`.
 */
void NNSi_G2dDrawCellToSurface3D(const NNSG2dRndCoreSurface *pSurface, const NNSG2dCellData *pCell)
{
    NNSG2dRndCoreInstance *pRnd = sRndCoreInstance;
    u16 i;

    for (i = 0; i < pCell->numOAMAttrs; i++) {
        sRndCoreInstance->bDrawEnable = 1;
        NNS_G2dCopyCellAsOamAttr(pCell, i, &pRnd->currentOam);

        HandleCellOamBackFunc_(pSurface->pBeforeDrawOamBackFunc, pCell, i);

        if (sRndCoreInstance->bDrawEnable != 0)
            NNSi_G2dDrawOam3D(&pRnd->currentOam);

        HandleCellOamBackFunc_(pSurface->pAfterDrawOamBackFunc, pCell, i);
    }
}


void NNS_G2dInitRndCore(NNSG2dRndCoreInstance *pRnd)
{
    MIi_CpuClear16(0, pRnd, 0x70);
    pRnd->pCurrentTargetSurface = 0;
    pRnd->affineOverwriteMode = 2;
    pRnd->pImgProxy = 0;
    pRnd->pPltProxy = 0;
    pRnd->flipFlag = 0;
    pRnd->bDrawEnable = 1;
    pRnd->pCurrentMtxCacheFor2D = 0;
}




/*
 * Stores the image and palette proxies the renderer core draws from (+0x08,
 * +0x0C of the instance).
 */
void NNS_G2dSetRndCoreImageProxy(NNSG2dRndCoreInstance *pRnd, const NNSG2dImageProxy *pImgProxy, const NNSG2dPaletteProxy *pPltProxy)
{
    pRnd->pImgProxy = pImgProxy;
    pRnd->pPltProxy = pPltProxy;
}




/*
 * Stores the OAM register callbacks (+0x1C, +0x20 of the instance).
 */
void NNS_G2dSetRndCoreOamRegisterFunc(NNSG2dRndCoreInstance *pRnd, OamRegisterFunc pFuncOamRegister, OamAffineRegisterFunc pFuncOamAffineRegister)
{
    pRnd->pFuncOamRegister = pFuncOamRegister;
    pRnd->pFuncOamAffineRegister = pFuncOamAffineRegister;
}





/*
 * Unlabelled two-instruction leaf of the NNS G2D cell-to-OAM composer
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): the setter
 * for the mode word at +0x04 of the composer state whose flip lane is
 * src/matched/unit_02067B40.c.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CBB0+0x1c (src/matched/CLACT_SetupActorDraw.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetRndCoreAffineOverwriteMode.c \
 *       --func NNS_G2dSetRndCoreAffineOverwriteMode --addr 0x02067AB8 --cc 1.1p1 --arm
 */
void NNS_G2dSetRndCoreAffineOverwriteMode(NNSG2dRndCoreInstance *pRnd, u32 mode)
{
    pRnd->affineOverwriteMode = mode;
}



/*
 * Makes a 2x3 matrix the current 3D transform of the renderer core: the matrix
 * pointer goes to +0x2C and its six words are expanded into the 4x3 matrix at
 * +0x40 (the unused entries zero, the diagonal entry 0x1000), with the
 * software-sprite Z value copied into the last word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetRndCoreCurrentMtx3D.c \
 *       --func NNS_G2dSetRndCoreCurrentMtx3D --addr 0x02067AC0 --arm --cc 1.1p1
 */
void NNS_G2dSetRndCoreCurrentMtx3D(const MtxFx32 *pMtx)
{
    NNSG2dRndCoreInstance *pRnd = sRndCoreInstance;

    pRnd->pCurrentMxt = pMtx;
    pRnd->mtx._00 = pMtx->_00;
    pRnd->mtx._01 = pMtx->_01;
    pRnd->mtx._02 = 0;
    pRnd->mtx._10 = pMtx->_10;
    pRnd->mtx._11 = pMtx->_11;
    pRnd->mtx._12 = 0;
    pRnd->mtx._20 = 0;
    pRnd->mtx._21 = 0;
    pRnd->mtx._22 = 0x1000;
    pRnd->mtx._30 = pMtx->_20;
    pRnd->mtx._31 = pMtx->_21;
    pRnd->mtx._32 = pRnd->zFor3DSoftwareSprite;
}




/*
 * Makes a 2x3 matrix and its affine cache the current 2D transform of the
 * renderer core (+0x2C, +0x28).
 */
void NNS_G2dSetRndCoreCurrentMtx2D(const MtxFx32 *pMtx, NNSG2dRndCore2DMtxCache *pMtxCache)
{
    NNSG2dRndCoreInstance *pRnd = sRndCoreInstance;

    pRnd->pCurrentMxt = pMtx;
    pRnd->pCurrentMtxCacheFor2D = pMtxCache;
}






/*
 * The H/V flip lane of the NNS G2D cell-to-OAM composer: two setters, a
 * pair of predicates, and the one word the predicates read.
 *
 * The renderer core instance's +0x24 word carries the two flip bits:
 *   bit0  flip horizontally
 *   bit1  flip vertically
 * NNS_G2dSetRndCoreFlipMode (0x02067B78, not in this file, see
 * docs/notes/g2d_flip_setter.c.txt) sets both from two BOOLs;
 * NNSi_G2dIsRndCoreFlipH and NNSi_G2dIsRndCoreFlipV answer them one at a time.  The functions that consume them are
 * NNSi_G2dDrawOam3D and NNSi_G2dDrawCellToSurface3D, and the arithmetic there is the whole
 * reason this lane matters to a rig composer: with the flip bit set, the
 * OAM entry's own position field is replaced by
 *
 *     x' = -(x + objWidth [shape][size])       (attr1 bits 0-8,  9-bit)
 *     y' = -(y + objHeight[shape][size])       (attr0 bits 0-7,  8-bit)
 *
 * with shape from attr0 bits 14-15, size from attr1 bits 14-15, and the
 * two tables at 0x020A17F0 (width) and 0x020A17D8 (height), three rows of
 * four u16 on an 8-byte row stride.  An OAM composer that flips the pixels
 * but leaves the entry's x/y alone lands every flipped part at the wrong
 * place by its own width or height.
 *
 * NNS_G2dSetRndCore3DSoftSpriteZvalue and NNS_G2dSetRndCoreSurface are plain word stores and none of these
 * saves lr, so they all print as a `.word` run in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02067B40.c \
 *       --addr 0x02067B40 --arm
 */
void NNS_G2dSetRndCore3DSoftSpriteZvalue(NNSG2dRndCoreInstance *pRnd, fx32 zFor3DSoftwareSprite)
{
    pRnd->zFor3DSoftwareSprite = zFor3DSoftwareSprite;
}


void NNS_G2dSetRndCoreSurface(NNSG2dRndCoreInstance *pRnd, NNSG2dRndCoreSurface *pSurface)
{
    pRnd->pCurrentTargetSurface = pSurface;
}


u32 NNSi_G2dIsRndCoreFlipH(const NNSG2dRndCoreInstance *pRnd)
{
    return (pRnd->flipFlag & 1) != 0;
}


u32 NNSi_G2dIsRndCoreFlipV(const NNSG2dRndCoreInstance *pRnd)
{
    return (pRnd->flipFlag & 2) != 0;
}



/*
 * The NNS G2D cell-to-OAM flip setter: bit 0 of the renderer core instance's +0x24
 * word is flip-H and bit 1 is flip-V, both set or cleared from a BOOL.  Its
 * four neighbours in the same `.word` run are src/matched/unit_02067B40.c.
 *
 * The second `ldr r1, [r0, #0x24]` is the plain re-read of the field the
 * first half just stored.  The NITRO 2.0 compiler keeps it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetRndCoreFlipMode.c  *       --func NNS_G2dSetRndCoreFlipMode --addr 0x02067B78 --cc ../2.0/sp2 --arm
 */
void NNS_G2dSetRndCoreFlipMode(NNSG2dRndCoreInstance *pRnd, BOOL bFlipH, BOOL bFlipV)
{
    if (bFlipH) pRnd->flipFlag |= 1;
    else        pRnd->flipFlag &= ~1u;

    if (bFlipV) pRnd->flipFlag |= 2;
    else        pRnd->flipFlag &= ~2u;
}


void NNS_G2dRndCoreBeginRendering(NNSG2dRndCoreInstance *pRnd)
{
    volatile u32 *reg = (volatile u32 *)0x04000440;
    NNSG2dRndCoreInstance *p = pRnd;
    int type;

    sRndCoreInstance = p;

    type = p->pCurrentTargetSurface->type;
    if (type == 0) {
        NNSG2dRndCoreSurface *pSurface;
        const NNSG2dImageProxy *pImgProxy;
        const NNSG2dPaletteProxy *pPltProxy;

        reg[0] = 0;
        reg[1] = 0;
        pSurface = p->pCurrentTargetSurface;
        {
            int x = pSurface->viewRect.posTopLeft.x;
            int y = pSurface->viewRect.posTopLeft.y;
            reg[12] = -x;
            reg[12] = -y;
        }
        reg[12] = 0;
        reg[0] = 1;

        pImgProxy = sRndCoreInstance->pImgProxy;
        p->baseTexAddr3D = NNSi_G2dIsVramHandleSet(pImgProxy, 0) ? NNSi_G2dGetVramHandleValue(pImgProxy, 0) : 0;

        pPltProxy = sRndCoreInstance->pPltProxy;
        p->basePltAddr3D = NNSi_G2dIsVramHandleSetEx(pPltProxy, 0) ? NNSi_G2dGetVramHandleEx(pPltProxy, 0) : 0;
    } else {
        const NNSG2dImageProxy *pImgProxy = p->pImgProxy;
        int r;

        if (NNSi_G2dIsVramHandleSet(pImgProxy, type)) {
            r = NNSi_G2dGetVramHandleValue(pImgProxy, type);
            r = (int)((u32)r >> ((int)((pImgProxy->attr.mappingType & 0x700000) >> 20) + 5));
        } else {
            r = 0;
        }
        sRndCoreInstance->base2DCharOffset = r;
    }
}



void NNS_G2dRndCoreEndRendering(void)
{
    NNSG2dRndCoreInstance *pRnd = sRndCoreInstance;

    if (pRnd->pCurrentTargetSurface->type == 0) {
        volatile u32 *reg = (volatile u32 *)0x04000440;
        reg[0] = 0;
        reg[2] = 1;
        reg[0] = 1;
    } else {
        pRnd->base2DCharOffset = 0;
        sRndCoreInstance->pCurrentMxt = 0;
        sRndCoreInstance->pCurrentMtxCacheFor2D = 0;
    }
    sRndCoreInstance = 0;
}



void NNS_G2dRndCoreDrawCell(const NNSG2dCellData *pCell)
{
    NNSG2dRndCoreInstance *pRnd = sRndCoreInstance;
    NNSG2dRndCoreSurface *pSurface = pRnd->pCurrentTargetSurface;

    if (pSurface->bActive == 0) {
        return;
    }

    pRnd->bDrawEnable = 1;

    if (pSurface->pBeforeDrawCellBackFunc != 0) {
        pSurface->pBeforeDrawCellBackFunc(sRndCoreInstance, pCell);
    }

    if (sRndCoreInstance->bDrawEnable != 0) {
        switch (pSurface->type) {
        case 0:
            NNSi_G2dDrawCellToSurface3D(pSurface, pCell);
            break;
        case 1:
        case 2:
            NNSi_G2dDrawCellToSurface2D(pSurface, pCell);
            break;
        case 3:
            break;
        }
    }

    if (pSurface->pAfterDrawCellBackFunc != 0) {
        pSurface->pAfterDrawCellBackFunc(sRndCoreInstance, pCell);
    }
}


void NNS_G2dRndCoreDrawCellVramTransfer(const NNSG2dCellData *pCell, s32 cellTransferHandle)
{
    u32 idx;
    NNSG2dRndCoreSurface *pSurface;
    NNSG2dRndCoreInstance *pRnd = sRndCoreInstance;

    pSurface = pRnd->pCurrentTargetSurface;
    if (pSurface->bActive == 0) return;

    pRnd->bDrawEnable = 1;
    if (pSurface->pBeforeDrawCellBackFunc != 0) pSurface->pBeforeDrawCellBackFunc(sRndCoreInstance, pCell);

    if (sRndCoreInstance->bDrawEnable != 0) {
        if (cellTransferHandle != -1) {
            CellTransferState *pState;
            idx = pSurface->type;
            pState = NNSi_G2dGetCellTransferState(cellTransferHandle);
            pState->bDrawn = (pState->bDrawn & ~(1 << idx)) | (1 << idx);
        }
        switch (pSurface->type) {
        case 0: NNSi_G2dDrawCellToSurface3D(pSurface, pCell); break;
        case 1:
        case 2: NNSi_G2dDrawCellToSurface2D(pSurface, pCell); break;
        case 3: break;
        }
    }
    if (pSurface->pAfterDrawCellBackFunc != 0) pSurface->pAfterDrawCellBackFunc(sRndCoreInstance, pCell);
}
