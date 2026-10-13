/*
 * file:     nns_g2d_renderer_mtx_cache.c
 * unit:     yes
 * function: NNSi_G2dMCEnumAnimBank, NNSi_G2dRendererResetMtxSlot, NNSi_G2dMCMLoadCurrentMtxToCache, NNSi_G2dRendererBeforeDrawCell, NNSi_G2dRendererAfterDrawCell
 * address:  0x02064D70
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Own object: EXACT with 1.1p1 and dsi/1.2, DIFF with ../2.0/sp2 (the build of
 * nns_g2d_renderer_2.c after it) and with ../1.2/sp2.
 *
 * symbols:
 *   g_02147B88   0x02147B88  data
 *   g_02147B98   0x02147B98  data
 *   g_02147D18   0x02147D18  data
 *   g_02147D28   0x02147D28  data
 *   g_02147D2C   0x02147D2C  data
 *   g_02148018   0x02148018  data
 *   g_020A81F8     0x020A81F8  data  a4
 *   g_02147C18     0x02147C18  data  a4
 *   g_02148318     0x02148318  data  a4
 *   MIi_CpuClearFast  0x02082AC0  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef int            s32;

typedef int            BOOL;

typedef s32            fx32;

typedef struct { fx32 _00, _01, _10, _11; } MtxFx22;

typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;

typedef struct { MtxFx22 m22; u16 affineIndex[4][2]; } NNSG2dRndCore2DMtxCache;

typedef struct MCMMtxState {
    u16 mtxCacheIdx;
    u16 groupID;
    u16 stateType;
    u16 pad16;
} MCMMtxState;

typedef struct NNSG2dRenderSurface NNSG2dRenderSurface;

struct NNSG2dRenderSurface {
    u8   viewRect[0x10];
    int  isActive;
    int  isSoftwareSprite;
    u8   pad_18[0x10];
    int  viewOffsetX;
    int  viewOffsetY;
    NNSG2dRenderSurface *pNextSurface;
    int  (*pFuncVisibilityCulling)(void *pCellData, MtxFx32 *pMtx, void *pSurface);
    void (*pBeforeDrawCellBackFunc)(void *pRend, void *pSurface, void *pCellData, MtxFx32 *pMtx);
    void (*pAfterDrawCellBackFunc)(void *pRend, void *pSurface, void *pCellData, MtxFx32 *pMtx);
    void (*pBeforeDrawOamBackFunc)(void *pRend, void *pSurface, void *pCellData, void *pOam, MtxFx32 *pMtx);
    void (*pAfterDrawOamBackFunc)(void *pRend, void *pSurface, void *pCellData, void *pOam, MtxFx32 *pMtx);
};

typedef struct NNSG2dRndCoreInstance {
    u8   pad_00[0x70];
    NNSG2dRenderSurface *pTargetSurfaceList;
    NNSG2dRenderSurface *pCurrentTargetSurface;
    int  currentCell;
    u32  flag;
} NNSG2dRndCoreInstance;

typedef struct NNSG2dRendererInstance {
    NNSG2dRndCoreInstance rendererCore;
    fx32 spriteZoffsetStep;
    u32  overwriteEnableFlag;
    u16  overwritePriority;
    u16  overwritePlttNo;
    int  overwriteObjMode;
    int  overwriteMosaicFlag;
    u16  overwritePlttNoOffset;
} NNSG2dRendererInstance;

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

typedef struct {
    u16  count;
    u8   pad_02[2];
    u8  *pEntries;     /* +0x04 */
} MCNameTable;

typedef struct {
    MCNameTable *pHeader;
    u8    pad_04[4];
    u32   kind;
    u8   *pRecords;
} MCAnimBank;

struct CellDrawState {
    u8  pad_00[0x30];
    u32 cullResult;
};

extern void MIi_CpuClearFast(u32 data, void *dest, u32 size);
void NNSi_G2dMCEnumAnimBank(MCAnimBank *bank, int (*visit)(void *, void *, void *, int), void *ctx);
void NNSi_G2dRendererResetMtxSlot(void);
void NNSi_G2dMCMLoadCurrentMtxToCache(void);
void NNSi_G2dRendererBeforeDrawCell(struct CellDrawState *pDrawState, void *pCellData);
void NNSi_G2dRendererAfterDrawCell(void *pDrawState, void *pCellData);
extern struct RendererBss g_02147B88;
extern fx32 g_02147B98[];
extern MtxFx32 g_02147D18[];
extern MtxFx32 g_02148018[];
extern struct RendererData g_020A81F8;
extern NNSG2dRndCore2DMtxCache g_02148318[32];
extern MCMMtxState g_02147C18[32];



/*
 * Name-record walker, the 0x5c / 0x28 stride pair of the cluster_02064B68
 * bank family.  A table with a u16 count at +0x00 and an 8-byte-record array
 * at +0x04: mode 1 hands the callback a pointer into the 0x5c-record array
 * indexed by the record's HIGH BYTE, every other mode the first word of the
 * 0x28-record array.  The callback gets (ctx, record, value, index) and a
 * zero return stops the walk.  This is a `void` function whose early exit is
 * a bare `return;`: an `int` return materialises a value and changes both
 * epilogues.
 *
 * Two levers closed the 4-byte residue docs/notes/NNSi_G2dMCEnumAnimBank.c.txt
 * records, and both are worth keeping:
 *
 *   The high-byte extract.  The image is three instructions,
 *   `and r2, r2, #0xff00` / `lsl r2, r2, #8` / `lsr ip, r2, #0x10`, and the
 *   note measured five spellings (`f >> 8`, `(u8)(f >> 8)`,
 *   `((f >> 8) & 0xff)`, `(f & 0xff00) >> 8`, f as u16 and as u32) that all
 *   fold to the single shift, which is the four bytes it was short.  The
 *   spelling that keeps all three is the mask assigned into a u16 and then
 *   shifted through u32: `(u32)((x & 0xff00) << 8) >> 16`.  The mask must be
 *   NARROWED to u16 before the pair, which is what makes the `lsl #8` survive
 *   instead of folding with the `lsr`.
 *
 *   Declaration order.  `i` must be declared FIRST, before `tab` and `n`;
 *   the note's register rotation (tab -> r8, count -> sb, i -> r7 in the
 *   image against r7/r8/sb in the compile) is entirely that, per
 *   docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *   The permuter named both levers: decl-order(i<->n), decl-order(i<->tab)
 *   and expand(f), 18 concrete bytes out -> 0.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G2dMCEnumAnimBank.c \
 *       --func NNSi_G2dMCEnumAnimBank --addr 0x02064D70 --arm --cc 1.1p1
 */
void NNSi_G2dMCEnumAnimBank(MCAnimBank *bank, int (*visit)(void *, void *, void *, int), void *ctx)
{
    u16  i;
    MCNameTable *table = bank->pHeader;
    u16  count = table->count;

    if (bank->kind == 1) {
        u8 *records = bank->pRecords;

        for (i = 0; i < count; i++) {
            if (visit(ctx, table->pEntries + i * 8,
                   records + ((u32)((*(u16 *)(table->pEntries + i * 8 + 6) & 0xff00) << 8) >> 16) * 0x5c,
                   i) == 0)
                return;
        }
    } else {
        u8 *records = bank->pRecords;

        for (i = 0; i < count; i++) {
            if (visit(ctx, table->pEntries + i * 8,
                   *(void **)(records + i * 0x28), i) == 0)
                return;
        }
    }
}




/*
 * Initialises one 0x18-byte slot of the renderer's per-slot tables, selected by
 * g_02147B88's +0xC field: either the two words at 0x02147D28 / 0x02147D2C are
 * cleared, or the six words of the template at 0x02147D18 are built
 * (0x1000, 0, 0, 0x1000, 0, 0) and copied whole into 0x02148018, which is the
 * 24-byte aggregate assignment the `ldm`/`stm` pair reproduces.  The slot's
 * entry in the u32 table at 0x02147B98 is cleared either way.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dRendererResetMtxSlot.c \
 *       --func NNSi_G2dRendererResetMtxSlot --addr 0x02064E3C --arm --cc 1.1p1
 */
void NNSi_G2dRendererResetMtxSlot(void)
{
    u32 i = g_02147B88.stackPos_;

    if (g_02147B88.bDonotUseSRTransform != 0) {
        g_02147D18[i]._20 = 0;
        g_02147D18[i]._21 = 0;
    } else {
        MtxFx32 *s = &g_02147D18[i];

        s->_00 = 0x1000;
        s->_01 = 0;
        s->_10 = 0;
        s->_11 = 0x1000;
        s->_20 = 0;
        s->_21 = 0;
        g_02148018[i] = *s;
    }

    g_02147B98[i] = 0;
}



static inline void MI_CpuFillFast(void *dest, u32 data, u32 size)
{
    MIi_CpuClearFast(data, dest, size);
}



static inline void NNS_G2dInitRndCore2DMtxCache(NNSG2dRndCore2DMtxCache *pMtxCache)
{
    MI_CpuFillFast(pMtxCache->affineIndex, 0xFFFFFFFF, sizeof(pMtxCache->affineIndex));
}



static inline u16 NNSi_G2dGetMtxStackPos(void)
{
    return (u16)(g_02147B88.stackPos_);
}



static inline const MtxFx32 *NNSi_G2dGetCurrentMtxFor2DHW(void)
{
    if (g_02147B88.bDonotUseSRTransform) {
        g_020A81F8.mtxI_._20 = g_02147B88.mtxStack_[g_02147B88.stackPos_]._20;
        g_020A81F8.mtxI_._21 = g_02147B88.mtxStack_[g_02147B88.stackPos_]._21;
        return &g_020A81F8.mtxI_;
    } else {
        return &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_];
    }
}



static inline void NNSi_G2dGetMtxRS(const MtxFx32 *m, MtxFx22 *pRet)
{
    pRet->_00 = m->_00;
    pRet->_01 = m->_01;
    pRet->_10 = m->_10;
    pRet->_11 = m->_11;
}



static inline NNSG2dRndCore2DMtxCache *NNSi_RMCGetMtxCacheByIdx(u16 idx)
{
    return &g_02148318[idx];
}



static inline u16 NNSi_RMCUseNewMtxCache(void)
{
    const u16 ret = g_02147B88.currentMtxCachePos_;

    if (g_02147B88.currentMtxCachePos_ < 32 - 1) {
        g_02147B88.currentMtxCachePos_++;
    }

    return ret;
}



static inline u16 GetMtxStateMtxCacheIdx_(const MCMMtxState *pMtxState)
{
    return pMtxState->mtxCacheIdx;
}



static inline void SetMtxStateMtxCacheIdx_(MCMMtxState *pMtxState, u16 cacheIdx)
{
    pMtxState->mtxCacheIdx = cacheIdx;
}



static inline u16 GetMtxStateGroupID_(const MCMMtxState *pMtxState)
{
    return pMtxState->groupID;
}



static inline MCMMtxState *GetCuurentMtxState_(void)
{
    return &g_02147C18[NNSi_G2dGetMtxStackPos()];
}



static inline void SetParentMtxStateLoaded_(u16 mtxCacheIdx, u16 groupID)
{
    int i;
    const u16 currntStackPos = NNSi_G2dGetMtxStackPos();

    for (i = currntStackPos; i >= 0; i--) {
        if (GetMtxStateGroupID_(&g_02147C18[i]) != groupID) {
            break;
        } else {
            g_02147C18[i].stateType = 3;
            SetMtxStateMtxCacheIdx_(&g_02147C18[i], mtxCacheIdx);
        }
    }
}



static inline NNSG2dRndCore2DMtxCache *NNSi_G2dMCMGetCurrentMtxCache(void)
{
    return NNSi_RMCGetMtxCacheByIdx(GetMtxStateMtxCacheIdx_(GetCuurentMtxState_()));
}



static inline BOOL NNSi_G2dMCMShouldCurrentMtxBeLoadedToMtxCache(void)
{
    MCMMtxState *pCurrMtxState = GetCuurentMtxState_();

    return (BOOL)(pCurrMtxState->stateType == 1 ||
                  pCurrMtxState->stateType == 2);
}



void NNSi_G2dMCMLoadCurrentMtxToCache(void)
{
    if (NNSi_G2dMCMShouldCurrentMtxBeLoadedToMtxCache()) {
        MCMMtxState *pCurrentState = GetCuurentMtxState_();
        const u16 mtxCacheIdx = NNSi_RMCUseNewMtxCache();
        const u16 groupID = GetMtxStateGroupID_(pCurrentState);

        SetMtxStateMtxCacheIdx_(pCurrentState, mtxCacheIdx);

        {
            NNS_G2dInitRndCore2DMtxCache(NNSi_RMCGetMtxCacheByIdx(mtxCacheIdx));

            NNSi_G2dGetMtxRS(NNSi_G2dGetCurrentMtxFor2DHW(),
                             &NNSi_G2dMCMGetCurrentMtxCache()->m22);
        }

        SetParentMtxStateLoaded_(mtxCacheIdx, groupID);
    }
}


static inline MtxFx32 *GetMtx(void)
{
    MtxFx32 *m;

    if (g_02147B88.bDonotUseSRTransform == 0) {
        m = &g_02147D18[g_02147B88.stackPos_];
    } else {
        g_020A81F8.mtxI_._20 = g_02147D18[g_02147B88.stackPos_]._20;
        g_020A81F8.mtxI_._21 = g_02147D18[g_02147B88.stackPos_]._21;
        m = &g_020A81F8.mtxI_;
    }
    return m;
}


static inline MtxFx32 *GetMtxEarly(void)
{
    if (g_02147B88.bDonotUseSRTransform != 0) {
        g_020A81F8.mtxI_._20 = g_02147D18[g_02147B88.stackPos_]._20;
        g_020A81F8.mtxI_._21 = g_02147D18[g_02147B88.stackPos_]._21;
        return &g_020A81F8.mtxI_;
    }
    return &g_02147D18[g_02147B88.stackPos_];
}


/*
 * First callback: runs the live actor vtable's +0x34 predicate with the
 * selected affine matrix, records its verdict in the host's +0x30 word (0
 * stops there), then dispatches the +0x38 slot with the matrix selected
 * afresh. The predicate is called (a1, matrix, vtbl). 0x02147D28 and
 * 0x02147D2C are &g_02147D18[0]._20 / ._21 and 0x020A8200 is the scratch
 * matrix at g_020A81F8+8.
 * EXACT under dsi/1.1p1; ../2.0/sp2 is 280 bytes (no predication).
 */
/*
 * The actor object's first in-object callback (NNS_G2dInitRenderSurface stores it at
 * +0x18): runs the live actor vtable's +0x34 predicate with the selected
 * affine matrix, records its verdict in the host's +0x30 word (0 stops
 * there), then dispatches the +0x38 slot with the matrix selected afresh.
 * The matrix selection is the PART 2 block of
 * docs/families/cluster_02064B68.h, written ONCE as an inline helper and
 * called at both sites.
 *
 * What closed it, after docs/notes/pkt_02065020.c.txt stalled at 35 out:
 *   - The +0x34 predicate is called (a1, matrix, vtbl): the matrix is in r1
 *     straight out of the selection (mlaeq r1 / ldr r1 = 0x020A8200) and
 *     the vtbl is moved into r2.  The note's (a1, vtbl, matrix) was the
 *     whole 35-byte residue.
 *   - 0x02147D28 / 0x02147D2C are &g_02147D18[0]._20 / ._21 and 0x020A8200 is
 *     the scratch matrix at g_020A81F8+8; with those declarations and the
 *     inline helper, the first selection reads the slot inside both arms
 *     and the second reads it once after the test, exactly as the image
 *     does, with no volatile casts.
 * EXACT under dsi/1.1p1; ../2.0/sp2 is 280 bytes (no predication).
 */
void NNSi_G2dRendererBeforeDrawCell(struct CellDrawState *pDrawState, void *pCellData)
{
    NNSG2dRenderSurface *v = g_02147B88.pCurrentInstance_->rendererCore.pCurrentTargetSurface;

    if (v->pFuncVisibilityCulling != 0) {
        if (v->pFuncVisibilityCulling(pCellData, GetMtx(), v) == 0) {
            pDrawState->cullResult = 0;
            return;
        }
        pDrawState->cullResult = 1;
    }

    if (v->pBeforeDrawCellBackFunc == 0)
        return;

    v->pBeforeDrawCellBackFunc(g_02147B88.pCurrentInstance_, v, pCellData, GetMtx());
}


/*
 * Second callback: dispatches the live actor vtable's +0x3c slot as
 * (obj, vtbl, a1, matrix); a null slot returns at once. The eq-first
 * spelling is a register-allocation tie here (2 bytes out), so the
 * else-first helper is used.
 */
/*
 * The actor object's second in-object callback (NNS_G2dInitRenderSurface stores it at
 * +0x1c): dispatches the live actor vtable's +0x3c slot as
 * (obj, vtbl, a1, matrix); a null slot returns at once.
 * The matrix selection is the PART 2 block of
 * docs/families/cluster_02064B68.h as an inline helper, but written
 * ELSE-FIRST with early returns: if (f04 != 0) copy tx/ty and return the
 * scratch matrix, else return &g_02147D18[slot].  The eq-first spelling (the
 * one NNSi_G2dRendererBeforeDrawCell matches with) is a register-allocation tie here: 2 bytes
 * out (lr/r4) on NNSi_G2dRendererAfterDrawCell and 31 out on NNSi_G2dRendererCallSurfaceOamFunc, where whether
 * the two arms' slot reads land in the same register decides whether they
 * are merged above the test.  Neither the permuter (hill + anneal 2000, no
 * single mutation moves it) nor any other compiler build closed the
 * eq-first form; the else-first form is EXACT on the first compile.
 */
void NNSi_G2dRendererAfterDrawCell(void *pDrawState, void *pCellData)
{
    NNSG2dRendererInstance *o = g_02147B88.pCurrentInstance_;
    NNSG2dRenderSurface *v = o->rendererCore.pCurrentTargetSurface;

    if (v->pAfterDrawCellBackFunc == 0)
        return;

    v->pAfterDrawCellBackFunc(o, v, pCellData, GetMtxEarly());
}
