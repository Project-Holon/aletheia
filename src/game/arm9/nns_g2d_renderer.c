/*
 * file:     nns_g2d_renderer.c
 * unit:     yes
 * function: NNSi_G2dRendererPreDrawOam, NNSi_G2dRendererCallSurfaceOamFunc, NNSi_G2dRendererDrawCellToSurfaces, NNSi_G2dRendererDrawCellTransformed, NNSi_G2dRendererDrawCellEntryTransformed, NNS_G2dInitRenderer, NNS_G2dSetRendererTargetSurface, NNS_G2dInitRenderSurface, NNS_G2dBeginRendering, NNS_G2dEndRendering, NNSi_G2dRendererDrawCellZOffset, NNSi_G2dRendererDrawCellTransformedZOffset, NNS_G2dDrawMultiCell, NNSi_G2dRendererDrawMultiCellTransformed, NNS_G2dPushMtx, NNS_G2dPopMtx, NNS_G2dTranslate, NNS_G2dScale, NNS_G2dRotZ, NNSi_G2dGetCurrentInstanceVramHandle, NNSi_G2dSetRndCoreImageProxyVeneer, NNSi_G2dMtxConcat32
 * address:  0x020651B8
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Own object: EXACT only with ../2.0/sp2; DIFF with 1.1p1 and dsi/1.2 (the
 * builds of nns_g2d_renderer_1.c before it) and with ../1.2/sp2.
 * Stand-in left: NNS_G2dTranslate reads the manager through a second symbol at the
 * same address, g_02147B88_head (struct RendererBssHead, the first 0x14 bytes).
 * With the full RendererBss the 2.0 scheduler hoists the stackPos_ load above
 * the stores to the local matrix (44 bytes out); a static inline accessor and
 * plain fields of the full struct give the same 44 bytes.
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_02147B88_head 0x02147B88  data  a4
 *   g_02147D18     0x02147D18  data  a4
 *   g_020A81F8     0x020A81F8  data  a4
 *   NNSi_G2dGetVramHandle  0x02063784  arm
 *   g_02148718     0x02148718  data  a4
 *   g_02147C18     0x02147C18  data  a4
 *   g_02148318     0x02148318  data  a4
 *   g_02147B98     0x02147B98  data  a4
 *   NNSi_G2dMCMLoadCurrentMtxToCache  0x02064EDC  arm
 *   NNS_G2dSetRndCoreCurrentMtx2D  0x02067B28  arm
 *   NNS_G2dSetRndCoreCurrentMtx3D  0x02067AC0  arm
 *   NNS_G2dRndCoreDrawCellVramTransfer  0x02067DC8  arm
 *   NNS_G2dRndCoreDrawCell  0x02067D14  arm
 *   NNS_G2dSetRndCore3DSoftSpriteZvalue  0x02067B40  arm
 *   NNS_G2dSetRndCoreSurface  0x02067B48  arm
 *   NNS_G2dSetRndCoreOamRegisterFunc  0x02067AAC  arm
 *   NNS_G2dRndCoreBeginRendering  0x02067BA4  arm
 *   NNS_G2dRndCoreEndRendering  0x02067CB0  arm
 *   NNSi_G2dIsRndCoreFlipH  0x02067B50  arm
 *   NNSi_G2dIsRndCoreFlipV  0x02067B64  arm
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   NNS_G2dInitRndCore  0x02067A60  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   MIi_CpuClear16   0x02082A48  arm
 *   NNSi_G2dRendererBeforeDrawCell    0x02065020  arm
 *   NNSi_G2dRendererAfterDrawCell    0x02065134  arm
 *   NNSi_G2dRendererResetMtxSlot  0x02064E3C  arm
 *   NNS_G2dGetOamSoftEmuAutoZOffsetStep  0x02066E20  arm
 *   NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled  0x02066DEC  arm
 *   NNS_G2dSetOamSoftEmuAutoZOffsetStep  0x02066E10  arm
 *   NNS_G2dResetOamSoftEmuAutoZOffset  0x02066DFC  arm
 *   g_02148018     0x02148018  data  a4
 *   FX_Inv  0x0207C778  arm
 *   NNS_G2dSetRndCoreImageProxy  0x02067AA0  arm
 */
#define FX32_SHIFT 12
struct Ctx;
struct G2dOamState;
struct Src02067AC0;
struct CellDrawCmd;
struct RndOamCell;
struct Host;
struct Cmd020659D4;
struct NNSG2dMultiCellInstance;
#include "../types.h"

#include "../sdk_fx.h"

#include "nns_g2d_renderer_types.h"

struct RendererBss {
    u16 currentMtxCachePos_;
    u16 groupID_;
    BOOL bDonotUseSRTransform;
    NNSG2dRendererInstance *pCurrentInstance_;
    s32 stackPos_;
    fx32 fxZStack_[32];
    MCMMtxState mtxStateStack_[32];
    MtxFx32 mtxStack_[32];
    MtxFx32 mtxStackFor2DHW_[32];
};

struct RendererData {
    u16 firstSRTransformedMtxIdx_;
    u32 currenVramTransferHandle_;
    MtxFx32 mtxI_;
};

typedef struct MCRenderState {
    u16 currentCellAnimIdx;
    u16 pad16_;
    void *cellAnimMtxCacheTbl[256];
    BOOL bDrawMC;
} MCRenderState;

typedef union {
    u32 attr01;
    struct {
        u32 y:8;
        u32 rsMode:2;
        u32 objMode:2;
        u32 mosaic:1;
        u32 colorMode:1;
        u32 shape:2;
        u32 x:9;
        u32 rsParam:5;
        u32 size:2;
        u32 charNo:10;
        u32 priority:2;
        u32 cParam:4;
        u32 _2:16;
    };
    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 attr3;
    };
} OamAttr;

struct RndOamCell {
    u8      pad_00[0x38];
    OamAttr oam;
};

/* The inline transform record at +0x30 of a cell-animation instance: the same
 * DrawCmd layout the +0x34 (multi-cell) and +0x00 (entry) records use, shifted.
 * handle +0x30, alternate-surface id +0x38, scale +0x40/+0x44, translate
 * +0x48/+0x4a, angle +0x4c, flags +0x4e. */
struct CellDrawCmd {
    u8   pad_00[0x30];
    void *handle;     /* 0x30  the cell handle re-passed to the draw */
    u8   pad_34[4];
    int  drawFlag;    /* 0x38  alternate-surface id, -1 = none */
    u8   pad_3c[4];
    fx32 scaleX;      /* 0x40  flag 2 */
    fx32 scaleY;      /* 0x44  flag 2 */
    s16  transX;      /* 0x48  flag 8, shifted <<12 */
    s16  transY;      /* 0x4a  flag 8, shifted <<12 */
    u16  angle;       /* 0x4c  flag 4, >>4 indexes FX_SinCosTable_ */
    u16  flags;       /* 0x4e  bit 8 translate, 4 rotate, 2 scale */
};

struct Cmd020659D4 {
    int  pContent;
    u8   pad_04[4];
    int  bVisible;
    u8   pad_0c[4];
    fx32 scaleX;
    fx32 scaleY;
    s16  transX;
    s16  transY;
    u16  rotZ;
    u16  dirtyFlags;
};


typedef struct NNSG2dMultiCellHierarchyData {
    u16 animSequenceIdx;
    s16 posX;
    s16 posY;
    u16 nodeAttr;
} NNSG2dMultiCellHierarchyData;

typedef struct NNSG2dMultiCellData {
    u16 numNodes;
    u16 numCellAnim;
    NNSG2dMultiCellHierarchyData *pHierDataArray;
} NNSG2dMultiCellData;

typedef struct NNSG2dCellAnimation { u8 data[0x5c]; } NNSG2dCellAnimation;

typedef struct NNSG2dMCCellAnimation { NNSG2dCellAnimation cellAnim; } NNSG2dMCCellAnimation;

typedef struct NNSG2dNode { u8 data[0x28]; } NNSG2dNode;

typedef struct NNSG2dMultiCellInstance {
    const NNSG2dMultiCellData *pCurrentMultiCell;
    const void *pAnimDataBank;
    u32 mcType;
    void *pCellAnimInstasnces;
} NNSG2dMultiCellInstance;

/* The inline transform record at +0x34 of a multi-cell instance: an embedded
 * NNSG2dMultiCellInstance at +0x34, then the same transform fields as
 * CellDrawCmd at +0x4c..+0x5a. */
struct MultiCellDrawCmd {
    u8   pad_00[0x34];
    NNSG2dMultiCellInstance multiCell;  /* 0x34  embedded multi-cell instance */
    u8   pad_44[8];                     /* 0x44..0x4c */
    fx32 scaleX;      /* 0x4c  flag 2 */
    fx32 scaleY;      /* 0x50  flag 2 */
    s16  transX;      /* 0x54  flag 8, shifted <<12 */
    s16  transY;      /* 0x56  flag 8, shifted <<12 */
    u16  angle;       /* 0x58  flag 4, >>4 indexes FX_SinCosTable_ */
    u16  flags;       /* 0x5a  bit 8 translate, 4 rotate, 2 scale */
};

struct RendererBssHead {
    u16 currentMtxCachePos_;
    u16 groupID_;
    BOOL bDonotUseSRTransform;
    NNSG2dRendererInstance *pCurrentInstance_;
    s32 stackPos_;
};

#include "nns_g2d_oam_manager.h"
#include "nns_g2d_renderer_mtx_cache.h"
#include "mi_memory.h"
struct CellDrawState;
#include "fx_cp.h"
struct NNSG2dPaletteProxy;
struct NNSG2dImageProxy;
void NNSi_G2dRendererPreDrawOam(struct RndOamCell *c, void *pCellData, void *pOam);
void NNSi_G2dRendererCallSurfaceOamFunc(void *pRend, void *pCellData, void *pOam);
void NNSi_G2dRendererDrawCellToSurfaces(void *a);
void NNSi_G2dRendererDrawCellTransformed(struct CellDrawCmd *c);
void NNSi_G2dRendererDrawCellEntryTransformed(struct Cmd020659D4 *c);
void NNS_G2dInitRenderer(NNSG2dRendererInstance *pRend);
void NNS_G2dSetRendererTargetSurface(NNSG2dRendererInstance *pRend, NNSG2dRenderSurface *pNew);
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
int NNSi_G2dGetCurrentInstanceVramHandle(int *p);
void NNSi_G2dSetRndCoreImageProxyVeneer(int *pRnd, int pImgProxy, int pPltProxy);
void NNSi_G2dMtxConcat32(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab);
extern struct RendererBss g_02147B88;
/* stand-in: second name for g_02147B88, used by NNS_G2dTranslate only; with the full struct the 2.0 scheduler hoists the stackPos_ load (44 bytes off) */
extern struct RendererBssHead g_02147B88_head;
extern MtxFx32 g_02147D18[];
extern struct RendererData g_020A81F8;
extern MCRenderState g_02148718;
extern MCMMtxState g_02147C18[];
extern NNSG2dRndCore2DMtxCache g_02148318[];
extern fx32 g_02147B98[];
extern s16 FX_SinCosTable_[];
extern MtxFx32 g_02148018[];

static inline int GetColorParam(const OamAttr *oam)
{
    return (oam->attr2 & 0xF000) >> 12;
}

static inline void SetObjMode(OamAttr *oam, int mode, int cParam)
{
    oam->attr01 = (oam->attr01 & ~0xC00) | (mode << 10);
    oam->attr2 = (u16)((oam->attr2 & ~0xF000) | (cParam << 12));
}

void NNSi_G2dRendererPreDrawOam(struct RndOamCell *c, void *pCellData, void *pOam)
{
    void *map;
    NNSG2dRendererInstance *o;
    NNSG2dRenderSurface *v;
    MtxFx32 *m;
    u32 i;

    map = (void *)NNSi_G2dGetCurrentInstanceVramHandle((int *)g_02147B88.pCurrentInstance_);
    if (map != 0)
        c->oam.cParam = NNSi_G2dGetVramHandle(map, (u16)((c->oam.attr2 & 0xF000) >> 12));

    if (g_02147B88.pCurrentInstance_->overwriteEnableFlag != 0) {
        if (((volatile NNSG2dRendererInstance *)g_02147B88.pCurrentInstance_)->overwriteEnableFlag & 1)
            c->oam.priority = g_02147B88.pCurrentInstance_->overwritePriority;
        if (g_02147B88.pCurrentInstance_->overwriteEnableFlag & 2)
            c->oam.cParam = g_02147B88.pCurrentInstance_->overwritePlttNo;
        if (g_02147B88.pCurrentInstance_->overwriteEnableFlag & 0x10)
            c->oam.cParam = c->oam.cParam + g_02147B88.pCurrentInstance_->overwritePlttNoOffset;
        if (g_02147B88.pCurrentInstance_->overwriteEnableFlag & 4) {
            if (g_02147B88.pCurrentInstance_->overwriteMosaicFlag != 0)
                c->oam.attr01 |= 0x1000;
            else
                c->oam.attr01 &= ~0x1000;
        }
        if (g_02147B88.pCurrentInstance_->overwriteEnableFlag & 8) {
            SetObjMode(&c->oam, ((volatile NNSG2dRendererInstance *)g_02147B88.pCurrentInstance_)->overwriteObjMode, GetColorParam(&c->oam));
        }
    }

    o = g_02147B88.pCurrentInstance_;
    v = o->pCurrentTargetSurface;
    if (v->pBeforeDrawOamBackFunc == 0)
        return;

    if (g_02147B88.bDonotUseSRTransform == 0) {
        m = &g_02147D18[g_02147B88.stackPos_];
    } else {
        g_020A81F8.mtxI_._20 = g_02147D18[g_02147B88.stackPos_]._20;
        g_020A81F8.mtxI_._21 = g_02147D18[g_02147B88.stackPos_]._21;
        m = &g_020A81F8.mtxI_;
    }

    v->pBeforeDrawOamBackFunc(o, v, pCellData, pOam, m);
}

static inline MtxFx32 *GetMtx(void)
{
    if (g_02147B88.bDonotUseSRTransform != 0) {
        g_020A81F8.mtxI_._20 = g_02147D18[g_02147B88.stackPos_]._20;
        g_020A81F8.mtxI_._21 = g_02147D18[g_02147B88.stackPos_]._21;
        return &g_020A81F8.mtxI_;
    }
    return &g_02147D18[g_02147B88.stackPos_];
}

void NNSi_G2dRendererCallSurfaceOamFunc(void *pRend, void *pCellData, void *pOam)
{
    NNSG2dRendererInstance *o = g_02147B88.pCurrentInstance_;
    NNSG2dRenderSurface *v = o->pCurrentTargetSurface;

    if (v->pAfterDrawOamBackFunc == 0)
        return;

    v->pAfterDrawOamBackFunc(o, v, pCellData, pOam, GetMtx());
}

static inline NNSG2dRndCore2DMtxCache *GetAff(void)
{
    NNSG2dRndCore2DMtxCache *aff = 0;
    int r;

    if (g_02147B88.bDonotUseSRTransform == 0 && g_020A81F8.firstSRTransformedMtxIdx_ != 0xFFFE)
        r = 1;
    else
        r = 0;
    if (r != 0) {
        if (g_02148718.bDrawMC != 0) {
            aff = g_02148718.cellAnimMtxCacheTbl[g_02148718.currentCellAnimIdx];
            if (aff == 0) {
                NNSi_G2dMCMLoadCurrentMtxToCache();
                aff = &g_02148318[g_02147C18[(u16)g_02147B88.stackPos_].mtxCacheIdx];
                g_02148718.cellAnimMtxCacheTbl[g_02148718.currentCellAnimIdx] = aff;
            }
        } else {
            NNSi_G2dMCMLoadCurrentMtxToCache();
            aff = &g_02148318[g_02147C18[(u16)g_02147B88.stackPos_].mtxCacheIdx];
        }
    }
    return aff;
}

static inline void Finish(void *a)
{
    int r = !(g_020A81F8.currenVramTransferHandle_ == -1);

    if (r != 0)
        NNS_G2dRndCoreDrawCellVramTransfer((const NNSG2dCellData *)a, g_020A81F8.currenVramTransferHandle_);
    else
        NNS_G2dRndCoreDrawCell((const NNSG2dCellData *)a);
}

static inline void DrawA(void *a, NNSG2dRenderSurface *p)
{
    NNSG2dRendererInstance *q = g_02147B88.pCurrentInstance_;
    NNSG2dRndCore2DMtxCache *aff;

    q->pCurrentTargetSurface = p;
    NNS_G2dSetRndCoreSurface((NNSG2dRndCoreInstance *)q, (NNSG2dRndCoreSurface *)p);
    NNS_G2dSetRndCoreOamRegisterFunc((NNSG2dRndCoreInstance *)q, (OamRegisterFunc)p->pFuncOamRegister, (OamAffineRegisterFunc)p->pFuncOamAffineRegister);
    NNS_G2dRndCoreBeginRendering((struct NNSG2dRndCoreInstance *)q);
    aff = GetAff();
    NNS_G2dSetRndCoreCurrentMtx2D(GetMtx(), aff);
    Finish(a);
    g_02147B88.pCurrentInstance_->pCurrentTargetSurface = 0;
    NNS_G2dRndCoreEndRendering();
}

static inline void DrawB(void *a, NNSG2dRendererInstance *o, NNSG2dRenderSurface *p)
{
    NNSG2dRendererInstance *q = g_02147B88.pCurrentInstance_;

    q->pCurrentTargetSurface = p;
    NNS_G2dSetRndCoreSurface((NNSG2dRndCoreInstance *)q, (NNSG2dRndCoreSurface *)p);
    NNS_G2dRndCoreBeginRendering((struct NNSG2dRndCoreInstance *)q);
    NNS_G2dSetRndCore3DSoftSpriteZvalue((struct NNSG2dRndCoreInstance *)o, g_02147B98[g_02147B88.stackPos_]);
    NNS_G2dSetRndCoreCurrentMtx3D(GetMtx());
    Finish(a);
    g_02147B88.pCurrentInstance_->pCurrentTargetSurface = 0;
    NNS_G2dRndCoreEndRendering();
}

void NNSi_G2dRendererDrawCellToSurfaces(void *a)
{
    NNSG2dRendererInstance *o = g_02147B88.pCurrentInstance_;
    NNSG2dRenderSurface *p = o->pTargetSurfaceList;

    if ((o->flag & 2) != 0) {
        if (p->type != 0) {
            NNSG2dRndCore2DMtxCache *aff = GetAff();
            NNS_G2dSetRndCoreCurrentMtx2D(GetMtx(), aff);
            Finish(a);
        } else {
            NNS_G2dSetRndCore3DSoftSpriteZvalue((struct NNSG2dRndCoreInstance *)o, g_02147B98[g_02147B88.stackPos_]);
            NNS_G2dSetRndCoreCurrentMtx3D(GetMtx());
            Finish(a);
        }
        return;
    }

    for (; p != 0; p = p->pNextSurface) {
        if (p->isActive != 0) {
            if (p->type != 0)
                DrawA(a, p);
            else
                DrawB(a, o, p);
        }
    }
}

static inline void Draw(struct CellDrawCmd *c, void *a)
{
    int r;
    r = !(c->drawFlag == -1);
    if (r != 0) {
        g_020A81F8.currenVramTransferHandle_ = c->drawFlag;
        NNSi_G2dRendererDrawCellToSurfaces(a);
        g_020A81F8.currenVramTransferHandle_ = -1;
    } else {
        NNSi_G2dRendererDrawCellToSurfaces(a);
    }
}

/*
 * The plain draw of one cell actor with its inline transform record, the
 * sibling of src/matched/NNSi_G2dRendererDrawMultiCellTransformed.c (record at +0x30 here, laid out
 * exactly as struct DrawCmd of docs/families/cluster_02064B68.h shifted by
 * 0x30: handle +0x30, alternate-surface id +0x38, scale +0x40/+0x44,
 * translate +0x48/+0x4a, angle +0x4c, flags +0x4e).  The draw itself is an
 * inline bracket: with a surface id other than -1 the id is published in
 * g_020A81F8+4 around NNSi_G2dRendererDrawCellToSurfaces and reset to -1 afterwards.  The
 * bracket is written out twice in the image (untransformed early exit and
 * the transformed tail), which is what an inline helper gives.
 *
 * Pinned to ../2.0/sp2: the image rematerialises the -1 (`mvn r0, #0` for
 * the compare, `mvn r1, #0` for the reset) and keeps a MATERIALISED boolean
 * (`movne r0, #1` / `moveq r0, #0` / `cmp r0, #0`) in front of each bracket.
 * THE LEVER is the spelling of that boolean: `r = !(c->unk_38 == -1);`.
 * Under the pin, `c->unk_38 != -1` (as an inline return, a named local, a
 * ternary, `!!(...)` or an if/else pair of assignments) folds the test into
 * a branch and is 324 bytes against 348; `r = 0; if (...) r = 1;` is size-
 * exact but 36 out; only the negated equality is EXACT.  Under dsi/1.1p1
 * every spelling is 308..340 bytes.
 */
void NNSi_G2dRendererDrawCellTransformed(struct CellDrawCmd *c)
{
    void *a = c->handle;

    if (c->flags == 0) {
        Draw(c, a);
        return;
    }

    NNS_G2dPushMtx();

    if ((c->flags & 8) != 0) {
        int x, y;

        y = c->transY;
        x = c->transX;

        if (NNSi_G2dIsRndCoreFlipH((struct NNSG2dRndCoreInstance *)g_02147B88.pCurrentInstance_) != 0)
            x = -x;
        if (NNSi_G2dIsRndCoreFlipV((struct NNSG2dRndCoreInstance *)g_02147B88.pCurrentInstance_) != 0)
            y = -y;

        NNS_G2dTranslate(x << 12, y << 12, 0);
    }

    if ((c->flags & 4) != 0) {
        int i = c->angle >> 4;

        NNS_G2dRotZ(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    }

    if ((c->flags & 2) != 0)
        NNS_G2dScale(c->scaleX, c->scaleY, 0x1000);

    Draw(c, a);
    NNS_G2dPopMtx(1);
}

void NNSi_G2dRendererDrawCellEntryTransformed(struct Cmd020659D4 *c)
{
    sptr a;

    if (c->bVisible == 0)
        return;

    a = c->pContent;
    NNS_G2dPushMtx();

    if ((c->dirtyFlags & 8) != 0) {
        int x, y;

        y = c->transY;
        x = c->transX;

        if (NNSi_G2dIsRndCoreFlipH((struct NNSG2dRndCoreInstance *)g_02147B88.pCurrentInstance_) != 0)
            x = -x;
        if (NNSi_G2dIsRndCoreFlipV((struct NNSG2dRndCoreInstance *)g_02147B88.pCurrentInstance_) != 0)
            y = -y;

        NNS_G2dTranslate(x << 12, y << 12, 0);
    }

    if ((c->dirtyFlags & 4) != 0) {
        int i = c->rotZ >> 4;

        NNS_G2dRotZ(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    }

    if ((c->dirtyFlags & 2) != 0)
        NNS_G2dScale(c->scaleX, c->scaleY, 0x1000);

    NNSi_G2dRendererDrawCellTransformed((struct CellDrawCmd *)a);
    NNS_G2dPopMtx(1);
}

static inline void MI_CpuFillFast(void *dest, u32 data, u32 size)
{
    MIi_CpuClearFast(data, dest, size);
}

static inline void NNS_G2dInitRndCore2DMtxCache(NNSG2dRndCore2DMtxCache *pMtxCache)
{
    MI_CpuFillFast(pMtxCache->affineIndex, 0xFFFFFFFF, sizeof(pMtxCache->affineIndex));
}

/*
 * Byte-correct under the ../2.0/sp2 pin (0 concrete mismatches at the
 * original's 188 bytes); 1.1p1 is 184 bytes and 62 out.  Parked, not filed:
 * the PC24 site at +0x0008 needs NNS_G2dInitRndCore, whose only branch anywhere
 * in the image is this function's own bl, so `label` has no outside witness.
 */

void NNS_G2dInitRenderer(NNSG2dRendererInstance *pRend)
{
    int i;

    NNS_G2dInitRndCore(&pRend->rendererCore);
    pRend->pTargetSurfaceList = 0;
    pRend->pCurrentTargetSurface = 0;
    pRend->currentCell = 0;
    pRend->flag = 0;
    pRend->spriteZoffsetStep = 0;
    pRend->overwriteEnableFlag = 0;
    pRend->overwritePriority = 0;
    pRend->overwritePlttNo = 0;
    pRend->overwriteObjMode = 0;
    pRend->overwriteMosaicFlag = 0;
    pRend->overwritePlttNoOffset = 0;
    g_02147B88.stackPos_ = 0;
    g_020A81F8.firstSRTransformedMtxIdx_ = 0xFFFE;
    for (i = 0; i < 32; i++) {
        NNS_G2dInitRndCore2DMtxCache(&g_02148318[i]);
    }
    g_02147B88.currentMtxCachePos_ = 0;
    g_02147B88.groupID_ = 0;
    MI_CpuFillFast(g_02147C18, 0, 0x100);
    g_02147B88.bDonotUseSRTransform = 0;
}

void NNS_G2dSetRendererTargetSurface(NNSG2dRendererInstance *pRend, NNSG2dRenderSurface *pNew)
{
    pNew->pNextSurface = pRend->pTargetSurfaceList;
    pRend->pTargetSurfaceList = pNew;
}

/*
 * Wipe and initialise a 0x48-byte object: MIi_CpuClear16(0, p, 0x48) first,
 * then the state word at +0x10, the mode word at +0x14 and four function
 * pointers at +0x18..+0x24 -- a vtable laid out in the object itself, in pool
 * order, not an array of addresses.
 *
 * Pinned to ../2.0/sp2 on the "kept constants" tell: the image interleaves
 * load/store and rematerialises 1 and 3 into r0 between the stores, where
 * dsi/1.1p1 -O4,p hoists all four address loads to the top of the body and
 * holds the two constants live in lr/ip, 92 bytes and 31 concrete out at the
 * same size.  Under the pin the same C is 0 mismatches.  See
 * docs/FRONTEND-PINS.md.
 *
 * The four ABS32 pool words resolve by sole-ref/code (each is exactly a
 * traced func_ label); the earlier MATCH cap recorded in
 * docs/notes/pkt_02065B74.c.txt predates that class being widened.
 */
void NNS_G2dInitRenderSurface(NNSG2dRenderSurface *p)
{
    MIi_CpuClear16(0, p, 0x48);

    p->isActive = 1;
    p->type = 3;

    p->pBeforeDrawCellFunc = NNSi_G2dRendererBeforeDrawCell;
    p->pAfterDrawCellFunc = NNSi_G2dRendererAfterDrawCell;
    p->pBeforeDrawOamFunc = NNSi_G2dRendererPreDrawOam;
    p->pCallOamFunc = NNSi_G2dRendererCallSurfaceOamFunc;
}

/*
 * Resets the cell-actor manager g_02147B88: attaches the object, clears the
 * matrix slot, writes the 0xFFFE sentinel to g_020A81F8, fills the 0x10-byte
 * tail of every live 0x20-byte record at g_02148318 with -1, zeroes the
 * count pair, clears the 0x100-byte slot table g_02147C18, writes the GX
 * MTX_PUSH / MTX_IDENTITY command registers (0x04000444 / 0x04000454, plain
 * hardware addresses, no relocation) and rebuilds the slot-0 matrices via
 * NNSi_G2dRendererResetMtxSlot.  The body is the one docs/notes/NNS_G2dBeginRendering.c.txt
 * recorded at 144/168; the loop shape (guarded do-while, cursor p) is
 * that note's.
 *
 * What closed it:
 *   - Compiler pin ../2.0/sp2.  The note's whole 24-byte residue was the
 *     tail zero: 1.1p1 keeps it in r4 across the fill call, the image
 *     rematerialises it (`mov r0, #0` before, `mov r1, #0` after) -- the
 *     "kept constants" tell.  The note probed the pin before the head was
 *     right and read it as worse; with the head below the pin is EXACT.
 *   - Head order: the 0xFFFE store is volatile AND the loop guard's count
 *     read is volatile, which keeps the count load below the sentinel store
 *     (the image's ldr / ldr / str / strh / ldrh order).  Either alone is
 *     21 bytes out.
 */
void NNS_G2dBeginRendering(NNSG2dRendererInstance *obj)
{
    NNSG2dRndCore2DMtxCache *p;
    s32 i;

    g_02147B88.pCurrentInstance_ = obj;
    g_02147B88.stackPos_ = 0;
    *(volatile u16 *)&g_020A81F8.firstSRTransformedMtxIdx_ = 0xfffe;

    i = 0;
    if (i < ((volatile struct RendererBss *)&g_02147B88)->currentMtxCachePos_) {
        p = g_02148318;
        do {
            MIi_CpuClearFast((u32)-1, p->affineIndex, 0x10);
            i++;
            p++;
        } while (i < g_02147B88.currentMtxCachePos_);
    }

    g_02147B88.currentMtxCachePos_ = 0;
    g_02147B88.groupID_ = 0;
    MIi_CpuClearFast(0, g_02147C18, 0x100);

    *(volatile u32 *)0x04000444 = 0;
    *(volatile u32 *)0x04000454 = 0;
    NNSi_G2dRendererResetMtxSlot();
}

/*
 * Teardown tail of the cell-actor / OAM manager: raises the capture-enable
 * bit at 0x04000448, then, if the attached object still carries work bits at
 * +0x7c, clears the two per-bit slots and drops the object pointer.
 *
 * Decompiled as a leaf so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x64 (src/pending/CLACT_DrawActor.c); it reads no argument, the r0
 * the caller passes is a leftover.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dEndRendering.c \
 *       --func NNS_G2dEndRendering --addr 0x02065C78 --cc 1.1p1 --arm
 */
void NNS_G2dEndRendering(void)
{
    u32 f;
    NNSG2dRendererInstance *o;

    *(volatile u32 *)0x04000448 = 1;

    o = g_02147B88.pCurrentInstance_;
    f = o->flag;
    if (f != 0) {
        if (f & 1)
            g_02147B88.bDonotUseSRTransform = 0;
        if (f & 2) {
            o->pCurrentTargetSurface = 0;
            NNS_G2dRndCoreEndRendering();
        }
        g_02147B88.pCurrentInstance_->flag = 0;
    }
    g_02147B88.pCurrentInstance_ = 0;
}

/*
 * Draws one cell actor.  Exact twin of src/matched/NNSi_G2dRendererDrawCellTransformedZOffset.c with
 * NNSi_G2dRendererDrawCellToSurfaces in place of NNSi_G2dRendererDrawCellTransformed: the bank at 0x02147B88 carries an
 * object pointer at +0x08 whose secondary render surface is at +0x80.  With
 * no secondary surface the body is the plain draw; with one, the draw is
 * bracketed save / switch / bind / draw / switch back / rebind / close.
 *
 * Pinned to ../2.0/sp2 on the same "kept constants" tell its twin carries:
 * the image loads the &g_02147B88 pool word TWICE (r1 at 0x02065CE8, r0 again
 * at 0x02065D10) and so spends only two callee-saved registers, padding the
 * frame with r3 (push {r3, r4, r5, lr}); dsi/1.1p1 -O4,p CSEs the two reads,
 * holds the base in a third callee-saved register and comes out 96 bytes
 * against the original 100 of code.  docs/notes/NNSi_G2dRendererDrawCellZOffset.c.txt records
 * that four-byte residue and asks what makes mwccarm emit two separate
 * materialisations of one extern address; the answer is the front end, not
 * the C.  The `volatile` cast on each read is what keeps 2.0 from folding
 * them back together.  See docs/FRONTEND-PINS.md.
 */
void NNSi_G2dRendererDrawCellZOffset(void *pCell)
{
    int saved;

    if (((volatile struct RendererBss *)&g_02147B88)->pCurrentInstance_->spriteZoffsetStep != 0)
    {
        saved = NNS_G2dGetOamSoftEmuAutoZOffsetStep();
        NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(1);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(((volatile struct RendererBss *)&g_02147B88)->pCurrentInstance_->spriteZoffsetStep);
        NNSi_G2dRendererDrawCellToSurfaces(pCell);
        NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(0);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(saved);
        NNS_G2dResetOamSoftEmuAutoZOffset();
    }
    else
    {
        NNSi_G2dRendererDrawCellToSurfaces(pCell);
    }
}

void NNSi_G2dRendererDrawCellTransformedZOffset(void *pCell)
{
    int saved;

    if (((volatile struct RendererBss *)&g_02147B88)->pCurrentInstance_->spriteZoffsetStep != 0)
    {
        saved = NNS_G2dGetOamSoftEmuAutoZOffsetStep();
        NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(1);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(((volatile struct RendererBss *)&g_02147B88)->pCurrentInstance_->spriteZoffsetStep);
        NNSi_G2dRendererDrawCellTransformed(pCell);
        NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(0);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(saved);
        NNS_G2dResetOamSoftEmuAutoZOffset();
    }
    else
    {
        NNSi_G2dRendererDrawCellTransformed(pCell);
    }
}

static inline u16 NNSi_G2dGetMC2NodeCellAinmIdx(const NNSG2dMultiCellHierarchyData *pNodeData)
{
    return (u16)((0xFF00 & pNodeData->nodeAttr) >> 8);
}

static inline void FlipTranslate_(int x, int y)
{
    const int x_ = NNSi_G2dIsRndCoreFlipH((struct NNSG2dRndCoreInstance *)(&g_02147B88.pCurrentInstance_->rendererCore)) ? -x : x;
    const int y_ = NNSi_G2dIsRndCoreFlipV((struct NNSG2dRndCoreInstance *)(&g_02147B88.pCurrentInstance_->rendererCore)) ? -y : y;

    NNS_G2dTranslate(x_ << 12, y_ << 12, 0);
}

static inline void DrawNode2_(const NNSG2dMultiCellInstance *pMC, const NNSG2dMultiCellHierarchyData *pNodeData)
{
    const u16 cellAnimIdx = NNSi_G2dGetMC2NodeCellAinmIdx(pNodeData);
    const NNSG2dMCCellAnimation *cellAnimArray = pMC->pCellAnimInstasnces;
    g_02148718.currentCellAnimIdx = cellAnimIdx;

    NNS_G2dPushMtx();
    FlipTranslate_(pNodeData->posX, pNodeData->posY);
    {
        NNSi_G2dRendererDrawCellTransformed((struct CellDrawCmd *)(&cellAnimArray[cellAnimIdx].cellAnim));
    }
    NNS_G2dPopMtx(1);
}

static inline BOOL IsAutoZoffsetEnable_(void)
{
    return (BOOL)g_02147B88.pCurrentInstance_->spriteZoffsetStep;
}

void NNS_G2dDrawMultiCell(const NNSG2dMultiCellInstance *pMC)
{
    u16 i;
    if (pMC->mcType == 1) {
        for (i = 0; i < pMC->pCurrentMultiCell->numCellAnim; i++) {
            g_02148718.cellAnimMtxCacheTbl[i] = 0;
        }

        g_02148718.bDrawMC = 1;

        if (IsAutoZoffsetEnable_()) {
            const fx32 offset = NNS_G2dGetOamSoftEmuAutoZOffsetStep();
            NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(1);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(g_02147B88.pCurrentInstance_->spriteZoffsetStep);

            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                DrawNode2_(pMC, &pMC->pCurrentMultiCell->pHierDataArray[i]);
            }

            NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(0);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(offset);
            NNS_G2dResetOamSoftEmuAutoZOffset();
        } else {
            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                DrawNode2_(pMC, &pMC->pCurrentMultiCell->pHierDataArray[i]);
            }
        }

        g_02148718.bDrawMC = 0;

    } else {
        const NNSG2dNode *pNode = pMC->pCellAnimInstasnces;
        if (IsAutoZoffsetEnable_()) {
            const fx32 offset = NNS_G2dGetOamSoftEmuAutoZOffsetStep();

            NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(1);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(g_02147B88.pCurrentInstance_->spriteZoffsetStep);

            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                NNSi_G2dRendererDrawCellEntryTransformed((struct Cmd020659D4 *)(&pNode[i]));
            }

            NNSi_G2dSetOamSoftEmuAutoZOffsetEnabled(0);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(offset);
            NNS_G2dResetOamSoftEmuAutoZOffset();
        } else {
            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                NNSi_G2dRendererDrawCellEntryTransformed((struct Cmd020659D4 *)(&pNode[i]));
            }
        }
    }
}

void NNSi_G2dRendererDrawMultiCellTransformed(struct MultiCellDrawCmd *c)
{
    if (c->flags == 0) {
        NNS_G2dDrawMultiCell(&c->multiCell);
        return;
    }

    NNS_G2dPushMtx();

    if ((c->flags & 8) != 0) {
        int x, y;

        y = c->transY;
        x = c->transX;

        if (NNSi_G2dIsRndCoreFlipH((struct NNSG2dRndCoreInstance *)g_02147B88.pCurrentInstance_) != 0)
            x = -x;
        if (NNSi_G2dIsRndCoreFlipV((struct NNSG2dRndCoreInstance *)g_02147B88.pCurrentInstance_) != 0)
            y = -y;

        NNS_G2dTranslate(x << 12, y << 12, 0);
    }

    if ((c->flags & 4) != 0) {
        int i = c->angle >> 4;

        NNS_G2dRotZ(FX_SinCosTable_[i * 2], FX_SinCosTable_[i * 2 + 1]);
    }

    if ((c->flags & 2) != 0)
        NNS_G2dScale(c->scaleX, c->scaleY, 0x1000);

    NNS_G2dDrawMultiCell(&c->multiCell);
    NNS_G2dPopMtx(1);
}

static inline void CopySlot(int next)
{
    if (g_02147B88.bDonotUseSRTransform != 0) {
        int cur = ((volatile struct RendererBss *)&g_02147B88)->stackPos_;
        g_02147D18[next]._20 = g_02147D18[cur]._20;
        g_02147D18[next]._21 = g_02147D18[cur]._21;
        g_02147B98[next] = g_02147B98[cur];
    } else {
        int cur = ((volatile struct RendererBss *)&g_02147B88)->stackPos_;
        g_02147D18[next] = g_02147D18[cur];
        g_02148018[next] = g_02148018[cur];
        g_02147B98[next] = g_02147B98[cur];
    }
    g_02147B88.stackPos_ = next;
}

/*
 * The matrix-slot PUSH, the counterpart of src/matched/NNS_G2dPopMtx.c.
 * The slot index g_02147B88.stackPos_ (+0x0c) is advanced if it stays below 0x20,
 * copying the current slot of every per-slot table into the next one: in
 * the translate-only mode (g_02147B88.bDonotUseSRTransform != 0) just tx/ty of g_02147D18
 * plus the u32 in g_02147B98; otherwise the whole 0x18-byte matrix of
 * g_02147D18 and g_02148018 plus g_02147B98.  Unless the live actor's +0x7c
 * bit 0 is set, the 8-byte slot record g_02147C18[(u16)slot] is then
 * copied from the old slot to the (possibly unchanged) current one with its
 * state promoted 1 -> 2.  r0 is never read (every caller passes the flag
 * word it tested), so the parameter is kept, unused.
 *
 * Levers, all needed:
 *   - Compiler pin ../2.0/sp2 ("kept constants": the image reloads the
 *     g_02147B88 pool word in each arm and after the store); 1.1p1 is 524
 *     bytes against 548, 381 out.
 *   - 0x02147D28 / 0x02147D2C are &g_02147D18[0]._20 / ._21 (member offset in
 *     the relocation addend), and 0x02147C1C is &g_02147C18[0].stateType, the
 *     same reading for the state reload of the promote step.
 *   - The flag test is written `(flags & 1) == 0` first: the image falls
 *     through into the long arm.
 *   - The copy helper re-reads the slot through a volatile cast in each
 *     arm (the image reloads it after the unk_04 test; plain, 394 out).
 *   - Copy order is tx, ty, g_02147B98 in the translate arm and g_02147D18,
 *     g_02148018, g_02147B98 in the full arm; the other eight orders of the
 *     two arms measured 30..118 out.
 *   - The promote is an if/else that stores in both arms (strheq/strhne);
 *     the ternary costs a second pool word.
 */
void NNS_G2dPushMtx(void)
{
    if ((g_02147B88.pCurrentInstance_->flag & 1) == 0) {
        int cur = g_02147B88.stackPos_;
        u16 old = cur;
        int next = cur + 1;
        int r = !(next >= 0x20);
        u16 nw;

        if (r != 0)
            CopySlot(next);

        nw = g_02147B88.stackPos_;
        g_02147C18[nw] = g_02147C18[old];
        if (g_02147C18[old].stateType == 1)
            g_02147C18[nw].stateType = 2;
        else
            g_02147C18[nw].stateType = g_02147C18[old].stateType;
    } else {
        int next = g_02147B88.stackPos_ + 1;
        int r = !(next >= 0x20);
        if (r == 0)
            return;
        CopySlot(next);
    }
}

/*
 * The matrix-slot POP, the counterpart of NNS_G2dPushMtx.  Returns at once
 * when the slot index g_02147B88.stackPos_ (+0x0c) is already 0; otherwise
 * decrements it and, if the "first modified slot" halfword g_020A81F8 now
 * lies above the new index, resets it to the 0xFFFE sentinel.  Every
 * caller passes 1 in r0 (NNSi_G2dRendererDrawCellEntryTransformed, NNSi_G2dRendererDrawCellTransformed, NNSi_G2dRendererDrawMultiCellTransformed) and
 * the body never reads it, so the parameter is kept, unused.
 *
 * TWO LEVERS, both needed (EXACT under dsi/1.1p1 and equally under
 * ../2.0/sp2; the default is kept):
 *   1. The guard's MATERIALISED boolean (`movle r0, #1` / `movgt r0, #0` /
 *      `cmp r0, #0` / `bxne lr`) is `int r = !(g_02147B88.stackPos_ > 0);`.
 *      Every spelling of `slot <= 0` (plain, named local, inline helper,
 *      if/else, ternary) folds to a predicated body 24 bytes short, which is
 *      why the earlier drafts in docs/notes/pkt_02065D4C.c.txt and
 *      docs/notes/pkt_02065020.c.txt needed a fake `u16 *` return.  Same
 *      lever as src/matched/NNSi_G2dRendererDrawCellTransformed.c's `!(x == -1)`.
 *   2. The image loads g_020A81F8 BETWEEN the slot load and the subtract
 *      (`ldr r3, [r1, #0xc]` / `ldrh r2, [r0]` / `sub` / `str` / `cmp r2,
 *      r3`).  Without volatile both compilers sink the ldrh below the store
 *      (14 bytes out, immovable by permuter hill 80 and anneal 1200).  The
 *      read-modify-write through `(volatile Manager *)` with the halfword
 *      read through `*(volatile u16 *)` between them pins the order.
 */
void NNS_G2dPopMtx(int n)
{
    int r = !(g_02147B88.stackPos_ > 0);
    if (r != 0)
        return;
    {
    int s = ((volatile struct RendererBss *)&g_02147B88)->stackPos_ - 1;
    u16 c = (*(volatile u16 *)&g_020A81F8);
    ((volatile struct RendererBss *)&g_02147B88)->stackPos_ = s;
    if (c > s)
        g_020A81F8.firstSRTransformedMtxIdx_ = 0xFFFE;
    }
}

/*
 * Matrix translate.  With the manager's mode word (+0x04) set, the current
 * slot's tx/ty are bumped in place; otherwise the translate matrix
 * (1, 0, 0, 1, x, y) is concatenated by NNSi_G2dMtxConcat32 into the slot of both
 * matrix tables, g_02147D18 and g_02148018.  z accumulates into the u32
 * per-slot table g_02147B98 either way.
 *
 * TWO READINGS closed this after four spellings in
 * docs/notes/pkt_02065D4C.c.txt stalled at 244 bytes:
 *   - 0x02147D28 and 0x02147D2C are NOT separate tables: they are
 *     &g_02147D18[0]._20 and &g_02147D18[0]._21.  A field of table[i] with a
 *     run-time i puts the member offset in the relocation addend (register-
 *     offset ldr has no immediate), so the pool words are g_02147D18+0x10 and
 *     g_02147D18+0x14.  Written as ._20/._21 of the Mtx array the pool order
 *     and the load/add/store interleave come out as the image has them.
 *   - Compiler pin ../2.0/sp2 on the "kept constants" tell of
 *     docs/families/cluster_02064B68.h: the image reloads the g_02147B88
 *     pool word after each call and recomputes slot*0x18 for each argument
 *     (add r1 / add r2 from the same sum), with a four-register push.  Under
 *     dsi/1.1p1 the same C is 244 bytes, 134 out, push {r3-r7, lr}; under the
 *     pin it is EXACT on the first compile.
 */
void NNS_G2dTranslate(fx32 x, fx32 y, fx32 z)
{
    MtxFx32 m;

    if (g_02147B88_head.bDonotUseSRTransform != 0) {
        g_02147D18[g_02147B88_head.stackPos_]._20 += x;
        g_02147D18[g_02147B88_head.stackPos_]._21 += y;
        g_02147B98[g_02147B88_head.stackPos_] += z;
        return;
    }

    m._00 = 0x1000;
    m._01 = 0;
    m._10 = 0;
    m._11 = 0x1000;
    m._20 = x;
    m._21 = y;
    NNSi_G2dMtxConcat32(&m, &g_02147D18[g_02147B88_head.stackPos_], &g_02147D18[g_02147B88_head.stackPos_]);
    NNSi_G2dMtxConcat32(&m, &g_02148018[g_02147B88_head.stackPos_], &g_02148018[g_02147B88_head.stackPos_]);
    g_02147B98[g_02147B88_head.stackPos_] += z;
}

static inline void NNSi_G2dSetScale(MtxFx32 *m, fx32 sx, fx32 sy)
{
    m->_00 = sx;
    m->_01 = 0;
    m->_10 = 0;
    m->_11 = sy;
    m->_20 = 0;
    m->_21 = 0;
}

static inline void NNSi_G2dSetScaleFor2DHW(MtxFx32 *m, fx32 sx, fx32 sy)
{
    m->_00 = FX_Inv(sx);
    m->_01 = 0;
    m->_10 = 0;
    m->_11 = FX_Inv(sy);
    m->_20 = 0;
    m->_21 = 0;
}

static inline u16 NNSi_G2dGetMtxStackPos(void)
{
    return (u16)(g_02147B88.stackPos_);
}

static inline void NNSi_G2dScale(fx32 sx, fx32 sy)
{
    {
        MtxFx32 temp;
        NNSi_G2dSetScale(&temp, sx, sy);
        NNSi_G2dMtxConcat32(&temp, &g_02147B88.mtxStack_[g_02147B88.stackPos_], &g_02147B88.mtxStack_[g_02147B88.stackPos_]);
        NNSi_G2dSetScaleFor2DHW(&temp, sx, sy);
        NNSi_G2dMtxConcat32(&temp, &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_], &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_]);
    }
}

static inline void NNSi_G2dSetRndMtxStackSRTransformed(void)
{
    g_020A81F8.firstSRTransformedMtxIdx_ = NNSi_G2dGetMtxStackPos();
}

static inline BOOL NNSi_G2dIsRndCurrentMtxSRTransformed(void)
{
    return (BOOL)(!g_02147B88.bDonotUseSRTransform &&
                  g_020A81F8.firstSRTransformedMtxIdx_ != 0xFFFE);
}

static inline void SetMtxStateGroupID_(MCMMtxState *pMtxState, u16 groupID)
{
    pMtxState->groupID = groupID;
}

static inline u16 GetNewGroupID_(void)
{
    return g_02147B88.groupID_++;
}

static inline MCMMtxState *GetCuurentMtxState_(void)
{
    return &g_02147B88.mtxStateStack_[NNSi_G2dGetMtxStackPos()];
}

static inline void NNSi_G2dMCMSetCurrentMtxSRChanged(void)
{
    MCMMtxState *pCurrMtxState = GetCuurentMtxState_();

    switch (pCurrMtxState->stateType) {
    case 1:
        return;
    case 0:
    case 2:
    case 3:
    {
        SetMtxStateGroupID_(pCurrMtxState, GetNewGroupID_());

        pCurrMtxState->stateType = 1;
    }
    break;
    }
}

/*
 * NitroSystem g2d_Renderer.c NNS_G2dScale(x, y, z) (z unused): NNSi_G2dScale
 * concatenates NNSi_G2dSetScale onto mtxStack_[stackPos_] and
 * NNSi_G2dSetScaleFor2DHW (FX_Inv of each factor, FX_Inv) onto
 * mtxStackFor2DHW_[stackPos_] with NNSi_G2dMtxConcat32 (NNSi_G2dMtxConcat32), then
 * the SR-transformed latch and NNSi_G2dMCMSetCurrentMtxSRChanged.  Library
 * shape verbatim; closed by the same lever as NNS_G2dRotZ (NNS_G2dRotZ):
 * the renderer's file statics are ONE pooled object at 0x02147B88 (see that
 * file's header for the member map).  ../2.0/sp2 and sp2p2 identical;
 * 1.1p1 is 320 bytes.
 */
void NNS_G2dScale(fx32 x, fx32 y, fx32 z)
{
    NNSi_G2dScale(x, y);

    if (!NNSi_G2dIsRndCurrentMtxSRTransformed()) {
        NNSi_G2dSetRndMtxStackSRTransformed();
    }

    NNSi_G2dMCMSetCurrentMtxSRChanged();
}

static inline void NNSi_G2dSetRotate(MtxFx32 *m, fx32 sin, fx32 cos)
{
    m->_00 = cos;
    m->_01 = sin;
    m->_10 = -sin;
    m->_11 = cos;
    m->_20 = 0;
    m->_21 = 0;
}

static inline void NNSi_G2dRotate(fx32 sin, fx32 cos)
{
    {
        MtxFx32 temp;
        NNSi_G2dSetRotate(&temp, sin, cos);

        NNSi_G2dMtxConcat32(&temp, &g_02147B88.mtxStack_[g_02147B88.stackPos_], &g_02147B88.mtxStack_[g_02147B88.stackPos_]);
        NNSi_G2dMtxConcat32(&temp, &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_], &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_]);
    }
}

/*
 * NitroSystem g2d_Renderer.c NNS_G2dRotZ(sin, cos): NNSi_G2dRotate (the
 * rotation MtxFx32 concatenated onto mtxStack_[stackPos_] and
 * mtxStackFor2DHW_[stackPos_] through NNSi_G2dMtxConcat32 = NNSi_G2dMtxConcat32),
 * then the SR-transformed latch and NNSi_G2dMCMSetCurrentMtxSRChanged.
 * Written as the library writes it (g2di_RendererMtxStack.hpp,
 * g2di_RendererMtxState.h, g2di_Mtx32.h inlines).
 *
 * THE LEVER (wave 13): the renderer's file statics are ONE object.  mwccarm
 * pools a translation unit's .bss statics behind one base, so
 * currentMtxCachePos_ (+0x00), groupID_ (+0x02), bDonotUseSRTransform
 * (+0x04), pCurrentInstance_ (+0x08), stackPos_ (+0x0c), fxZStack_ (+0x10),
 * mtxStateStack_ (+0x90 = 0x02147C18), mtxStack_ (+0x190 = 0x02147D18) and
 * mtxStackFor2DHW_ (+0x490 = 0x02148018) are members of the block at
 * 0x02147B88, and the pool words 0x02147C18 / D18 / 8018 are that symbol
 * plus an addend.  Declared as separate externs, the compiler proves
 * mtxStateStack_ and groupID_ distinct and schedules the state store above
 * the groupID_++ store (tail 17 bytes out, three waves); as one object the
 * store order and every register are the image's.  g_020A81F8 is the .data
 * twin: firstSRTransformedMtxIdx_ (u16, 0xFFFE = NNS_G2D_OAM_AFFINE_IDX_NONE).
 * ../2.0/sp2 and sp2p2 identical; 1.1p1 is 276 bytes.
 */
void NNS_G2dRotZ(fx32 sin, fx32 cos)
{
    NNSi_G2dRotate(sin, cos);

    if (!NNSi_G2dIsRndCurrentMtxSRTransformed()) {
        NNSi_G2dSetRndMtxStackSRTransformed();
    }

    NNSi_G2dMCMSetCurrentMtxSRChanged();
}

int NNSi_G2dGetCurrentInstanceVramHandle(int *p){ return p[0x1e]; }

void NNSi_G2dSetRndCoreImageProxyVeneer(int *pRnd, int pImgProxy, int pPltProxy){ NNS_G2dSetRndCoreImageProxy((struct NNSG2dRndCoreInstance *)pRnd, (struct NNSG2dImageProxy *)pImgProxy, (struct NNSG2dPaletteProxy *)pPltProxy); }

void NNSi_G2dMtxConcat32(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab)
{
    MtxFx32 tmp;
    MtxFx32 *p;

    if (ab == b)
        p = &tmp;
    else
        p = ab;

    p->_00 = (fx32)(((fx64)a->_00 * b->_00 + (fx64)a->_01 * b->_10) >> FX32_SHIFT);
    p->_01 = (fx32)(((fx64)a->_00 * b->_01 + (fx64)a->_01 * b->_11) >> FX32_SHIFT);
    p->_10 = (fx32)(((fx64)a->_10 * b->_00 + (fx64)a->_11 * b->_10) >> FX32_SHIFT);
    p->_11 = (fx32)(((fx64)a->_10 * b->_01 + (fx64)a->_11 * b->_11) >> FX32_SHIFT);
    p->_20 = (fx32)(((fx64)a->_20 * b->_00 + (fx64)a->_21 * b->_10) >> FX32_SHIFT) + b->_20;
    p->_21 = (fx32)(((fx64)a->_20 * b->_01 + (fx64)a->_21 * b->_11) >> FX32_SHIFT) + b->_21;

    if (p == &tmp)
        *ab = tmp;
}
