/*
 * function: func_02064EDC
 * address:  0x02064EDC
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02147B88     0x02147B88  data  a4
 *   g_020A81F8     0x020A81F8  data  a4
 *   g_02147C18     0x02147C18  data  a4
 *   g_02148318     0x02148318  data  a4
 *   func_02082AC0  0x02082AC0  arm
 *
 * NitroSystem g2di_RendererMtxState.h NNSi_G2dMCMStoreCurrentMtxToMtxCache
 * (static in g2d_Renderer.c): when the current stack level's MCMMtxState is
 * SR-changed and not yet cached (state 1 or 2), take a new cache slot
 * (NNSi_RMCUseNewMtxCache, capped at 31), reset its affine indices
 * (NNS_G2dInitRndCore2DMtxCache: MI_CpuFillFast -> MIi_CpuClearFast
 * func_02082AC0 with 0xFFFFFFFF), copy the 2x2 part of the current 2D-HW
 * matrix into it (NNSi_G2dGetCurrentMtxFor2DHW, which refreshes mtxI_'s
 * translation when bDonotUseSRTransform is set), and mark every parent
 * level of the same group as loaded (state 3).  Library shape verbatim.
 *
 * Objects: g_02147B88 is the renderer's pooled .bss statics (see
 * src/matched/func_02066620.c); here mtxStateStack_ (0x02147C18) and
 * mtxCacheBuffer_ (0x02148318, 32 x 0x20-byte NNSG2dRndCore2DMtxCache) are
 * declared as their OWN objects, which is what lets the image hoist the
 * stackPos_ re-read above the cache stores and keep a separate base for the
 * parent loop; folded into the block the function is 320 bytes / 140 out.
 * g_020A81F8 is the .data statics { firstSRTransformedMtxIdx_,
 * currenVramTransferHandle_, mtxI_ }.  EXACT under ../2.0/sp2, sp2p2 and
 * 1.1p1 alike; the compiler line keeps the family's 2.0 row.
 */

#include "../include/G_Aff.h"
#include "../include/G_SlotRec.h"

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;
typedef s32 fx32;

typedef struct { fx32 _00, _01, _10, _11; } MtxFx22;
typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;

typedef struct { MtxFx22 m22; u16 affineIndex[4][2]; } NNSG2dRndCore2DMtxCache;

typedef struct MCMMtxState {
    u16 mtxCacheIdx;
    u16 groupID;
    u16 stateType;
    u16 pad16;
} MCMMtxState;

struct RendererBss {
    u16 currentMtxCachePos_;
    u16 groupID_;
    BOOL bDonotUseSRTransform;
    void *pCurrentInstance_;
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

extern struct RendererBss g_02147B88;
extern struct RendererData g_020A81F8;
extern struct Aff g_02148318[32];
extern struct SlotRec g_02147C18[32];
extern void func_02082AC0(u32 data, void *dest, u32 size);

static inline void MI_CpuFillFast(void *dest, u32 data, u32 size)
{
    func_02082AC0(data, dest, size);
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
    return &((NNSG2dRndCore2DMtxCache *)g_02148318)[idx];
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
    return &((MCMMtxState *)g_02147C18)[NNSi_G2dGetMtxStackPos()];
}

static inline void SetParentMtxStateLoaded_(u16 mtxCacheIdx, u16 groupID)
{
    int i;
    const u16 currntStackPos = NNSi_G2dGetMtxStackPos();

    for (i = currntStackPos; i >= 0; i--) {
        if (GetMtxStateGroupID_(&((MCMMtxState *)g_02147C18)[i]) != groupID) {
            break;
        } else {
            g_02147C18[i].state = 3;
            SetMtxStateMtxCacheIdx_(&((MCMMtxState *)g_02147C18)[i], mtxCacheIdx);
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

void func_02064EDC(void)
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
