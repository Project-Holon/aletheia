/*
 * file:     unit_02064D70_p04.c
 * unit:     yes
 * function: func_020664CC, func_02066620, func_02066740, func_02066748, func_02066754
 * address:  0x020664CC
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
 *   g_02147B88     0x02147B88  data  a4
 *   g_020A81F8     0x020A81F8  data  a2
 *   func_0207C778  0x0207C778  arm
 */
#define FX32_SHIFT 12
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
    u8   pad_00[0x10];
    int  f10;
    int  f14;
    u8   pad_18[0x10];
    int  f28;
    int  f2c;
    NNSG2dRenderSurface *pNextSurface;
    int  (*fn34)(void *a, MtxFx32 *m, void *b);
    void (*fn38)(void *a, void *b, void *c, MtxFx32 *m);
    void (*fn3c)(void *a, void *b, void *c, MtxFx32 *m);
    void (*fn40)(void *a, void *b, void *c, void *d, MtxFx32 *m);
    void (*fn44)(void *a, void *b, void *c, void *d, MtxFx32 *m);
};

typedef struct NNSG2dRndCoreInstance {
    u8   pad_00[0x70];
    NNSG2dRenderSurface *pTargetSurfaceList;
    NNSG2dRenderSurface *pCurrentTargetSurface;
    int  unk_78;
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

typedef long long fx64;

extern fx32 func_0207C778(fx32 v);
extern void func_02067AA0(int *p, int a, int b);
void func_020664CC(fx32 x, fx32 y, fx32 z);
void func_02066620(fx32 sin, fx32 cos);
int func_02066740(int *p);
void func_02066748(int *a0, int a1, int a2);
void func_02066754(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab);
extern struct RendererBss g_02147B88;
extern struct RendererData g_020A81F8;


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
    m->_00 = func_0207C778(sx);
    m->_01 = 0;
    m->_10 = 0;
    m->_11 = func_0207C778(sy);
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




/*
 * NitroSystem g2d_Renderer.c NNS_G2dScale(x, y, z) (z unused): NNSi_G2dScale
 * concatenates NNSi_G2dSetScale onto mtxStack_[stackPos_] and
 * NNSi_G2dSetScaleFor2DHW (FX_Inv of each factor, func_0207C778) onto
 * mtxStackFor2DHW_[stackPos_] with NNSi_G2dMtxConcat32 (func_02066754), then
 * the SR-transformed latch and NNSi_G2dMCMSetCurrentMtxSRChanged.  Library
 * shape verbatim; closed by the same lever as func_02066620 (NNS_G2dRotZ):
 * the renderer's file statics are ONE pooled object at 0x02147B88 (see that
 * file's header for the member map).  ../2.0/sp2 and sp2p2 identical;
 * 1.1p1 is 320 bytes.
 */
void func_020664CC(fx32 x, fx32 y, fx32 z)
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

        func_02066754(&temp, &g_02147B88.mtxStack_[g_02147B88.stackPos_], &g_02147B88.mtxStack_[g_02147B88.stackPos_]);
        func_02066754(&temp, &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_], &g_02147B88.mtxStackFor2DHW_[g_02147B88.stackPos_]);
    }
}




/*
 * NitroSystem g2d_Renderer.c NNS_G2dRotZ(sin, cos): NNSi_G2dRotate (the
 * rotation MtxFx32 concatenated onto mtxStack_[stackPos_] and
 * mtxStackFor2DHW_[stackPos_] through NNSi_G2dMtxConcat32 = func_02066754),
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
void func_02066620(fx32 sin, fx32 cos)
{
    NNSi_G2dRotate(sin, cos);

    if (!NNSi_G2dIsRndCurrentMtxSRTransformed()) {
        NNSi_G2dSetRndMtxStackSRTransformed();
    }

    NNSi_G2dMCMSetCurrentMtxSRChanged();
}



int func_02066740(int *p){ return p[0x1e]; }



void func_02066748(int *a0, int a1, int a2){ func_02067AA0(a0, a1, a2); }



void func_02066754(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab)
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
