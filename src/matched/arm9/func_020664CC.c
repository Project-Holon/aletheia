/*
 * function: func_020664CC
 * address:  0x020664CC
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
 *   g_020A81F8     0x020A81F8  data  a2
 *   func_02066754  0x02066754  arm
 *   FX_Inv  0x0207C778  arm
 *
 * NitroSystem g2d_Renderer.c NNS_G2dScale(x, y, z) (z unused): NNSi_G2dScale
 * concatenates NNSi_G2dSetScale onto mtxStack_[stackPos_] and
 * NNSi_G2dSetScaleFor2DHW (FX_Inv of each factor, FX_Inv) onto
 * mtxStackFor2DHW_[stackPos_] with NNSi_G2dMtxConcat32 (func_02066754), then
 * the SR-transformed latch and NNSi_G2dMCMSetCurrentMtxSRChanged.  Library
 * shape verbatim; closed by the same lever as func_02066620 (NNS_G2dRotZ):
 * the renderer's file statics are ONE pooled object at 0x02147B88 (see that
 * file's header for the member map).  ../2.0/sp2 and sp2p2 identical;
 * 1.1p1 is 320 bytes.
 */

#include "../include/G_Scr.h"

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;
typedef s32 fx32;

typedef struct { fx32 _00, _01, _10, _11, _20, _21; } MtxFx32;

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

extern struct RendererBss g_02147B88;
extern struct Scr g_020A81F8;
extern void func_02066754(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab);
extern fx32 FX_Inv(fx32 v);

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
        func_02066754(&temp, &g_02147B88.mtxStack_[g_02147B88.stackPos_], &g_02147B88.mtxStack_[g_02147B88.stackPos_]);
        NNSi_G2dSetScaleFor2DHW(&temp, sx, sy);
        func_02066754(&temp, &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_], &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_]);
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

void func_020664CC(fx32 x, fx32 y, fx32 z)
{
    NNSi_G2dScale(x, y);

    if (!NNSi_G2dIsRndCurrentMtxSRTransformed()) {
        NNSi_G2dSetRndMtxStackSRTransformed();
    }

    NNSi_G2dMCMSetCurrentMtxSRChanged();
}
