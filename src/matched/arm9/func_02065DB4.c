/*
 * function: NNS_G2dDrawMultiCell
 * address:  0x02065DB4
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
 *   g_02148718     0x02148718  data  a4
 *   NNS_G2dGetOamSoftEmuAutoZOffsetStep  0x02066E20  arm
 *   func_02066DEC  0x02066DEC  arm
 *   NNS_G2dSetOamSoftEmuAutoZOffsetStep  0x02066E10  arm
 *   func_02066DFC  0x02066DFC  arm
 *   NNS_G2dPushMtx  0x0206615C  arm
 *   NNS_G2dPopMtx  0x02066380  arm
 *   NNSi_G2dIsRndCoreFlipH  0x02067B50  arm
 *   NNSi_G2dIsRndCoreFlipV  0x02067B64  arm
 *   NNS_G2dTranslate  0x020663D0  arm
 *   NNSi_G2dRendererDrawCellTransformed  0x02065878  arm
 *   NNSi_G2dRendererDrawCellEntryTransformed  0x020659D4  arm
 *
 * NitroSystem g2d_Renderer.c NNS_G2dDrawMultiCell(pMC).  mcType 1
 * (NNS_G2D_MCTYPE_SHARE_CELLANIM): clear mcRenderState_'s per-cell-anim
 * matrix-cache table, raise bDrawMC, and draw every hierarchy node through
 * the DrawNode2_ inline (currentCellAnimIdx, NNS_G2dPushMtx, FlipTranslate_
 * over NNS_G2dIsRndCoreFlipH/V and NNS_G2dTranslate, DrawCellAnimationImpl_
 * = NNSi_G2dRendererDrawCellTransformed, NNS_G2dPopMtx(1)); otherwise draw each 0x28-byte
 * NNSG2dNode with DrawNode_ = NNSi_G2dRendererDrawCellEntryTransformed.  Both arms bracket the loop in
 * the auto-Z-offset save/restore when pCurrentInstance_->spriteZoffsetStep
 * (+0x80) is non-zero (NNS_G2dGetOamSoftEmuAutoZOffsetStep get step, func_02066DEC set flag,
 * NNS_G2dSetOamSoftEmuAutoZOffsetStep set step, func_02066DFC reset).
 *
 * Closed in wave 13 on the FIRST compile of the library body, after four
 * waves at 23 out: the duplicated loop arms the old notes read as "each arm
 * is a helper call" are exactly the library's IsAutoZoffsetEnable_ if/else
 * with DrawNode2_ inlined in both.  g_02147B88 is the renderer's pooled
 * .bss statics (pCurrentInstance_ at +0x08; src/matched/NNS_G2dRotZ.c),
 * g_02148718 is mcRenderState_ { u16 currentCellAnimIdx; u16 pad;
 * cellAnimMtxCacheTbl[256]; BOOL bDrawMC (+0x404) }.  NNS_G2dPopMtx is
 * declared with an empty parameter list, as NitroSystem declares it, and
 * called with 1.  ../2.0/sp2 and sp2p2 identical; 1.1p1 273 out.
 */

#include "../include/G_G18.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;
typedef s32 fx32;

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

typedef struct NNSG2dRndCoreInstance NNSG2dRndCoreInstance;
typedef struct NNSG2dRendererInstance {
    u8 rendererCore[0x80];
    fx32 spriteZoffsetStep;
} NNSG2dRendererInstance;

struct RendererBss {
    u16 currentMtxCachePos_;
    u16 groupID_;
    BOOL bDonotUseSRTransform;
    NNSG2dRendererInstance *pCurrentInstance_;
    s32 stackPos_;
};

extern struct RendererBss g_02147B88;
extern struct G18 g_02148718;        /* mcRenderState_ */

extern fx32 NNS_G2dGetOamSoftEmuAutoZOffsetStep(void);        /* NNSi_G2dGetOamSoftEmuAutoZOffsetStep */
extern void func_02066DEC(BOOL flag);   /* NNSi_G2dSetOamSoftEmuAutoZOffsetFlag */
extern void NNS_G2dSetOamSoftEmuAutoZOffsetStep(fx32 step);   /* NNSi_G2dSetOamSoftEmuAutoZOffsetStep */
extern void func_02066DFC(void);        /* NNSi_G2dResetOamSoftEmuAutoZOffset */
extern void NNS_G2dPushMtx(void);        /* NNS_G2dPushMtx */
extern void NNS_G2dPopMtx(int n);            /* NNS_G2dPopMtx */
struct Cmd020659D4;
struct G2dOamState;
struct Obj02065878;
extern u32 NNSi_G2dIsRndCoreFlipH(const struct G2dOamState *p);   /* NNS_G2dIsRndCoreFlipH */
extern u32 NNSi_G2dIsRndCoreFlipV(const struct G2dOamState *p);   /* NNS_G2dIsRndCoreFlipV */
extern void NNS_G2dTranslate(fx32 x, fx32 y, fx32 z);    /* NNS_G2dTranslate */
extern void NNSi_G2dRendererDrawCellTransformed(struct Obj02065878 *c);   /* DrawCellAnimationImpl_ */
extern void NNSi_G2dRendererDrawCellEntryTransformed(struct Cmd020659D4 *c);   /* DrawNode_ */

static inline u16 NNSi_G2dGetMC2NodeCellAinmIdx(const NNSG2dMultiCellHierarchyData *pNodeData)
{
    return (u16)((0xFF00 & pNodeData->nodeAttr) >> 8);
}

static inline void FlipTranslate_(int x, int y)
{
    const int x_ = NNSi_G2dIsRndCoreFlipH((const struct G2dOamState *)(&g_02147B88.pCurrentInstance_->rendererCore)) ? -x : x;
    const int y_ = NNSi_G2dIsRndCoreFlipV((const struct G2dOamState *)(&g_02147B88.pCurrentInstance_->rendererCore)) ? -y : y;

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
        NNSi_G2dRendererDrawCellTransformed((struct Obj02065878 *)(&cellAnimArray[cellAnimIdx].cellAnim));
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
            g_02148718.arr04[i] = 0;
        }

        g_02148718.bDrawMC = 1;

        if (IsAutoZoffsetEnable_()) {
            const fx32 offset = NNS_G2dGetOamSoftEmuAutoZOffsetStep();
            func_02066DEC(1);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(g_02147B88.pCurrentInstance_->spriteZoffsetStep);

            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                DrawNode2_(pMC, &pMC->pCurrentMultiCell->pHierDataArray[i]);
            }

            func_02066DEC(0);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(offset);
            func_02066DFC();
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

            func_02066DEC(1);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(g_02147B88.pCurrentInstance_->spriteZoffsetStep);

            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                NNSi_G2dRendererDrawCellEntryTransformed((struct Cmd020659D4 *)(&pNode[i]));
            }

            func_02066DEC(0);
            NNS_G2dSetOamSoftEmuAutoZOffsetStep(offset);
            func_02066DFC();
        } else {
            for (i = 0; i < pMC->pCurrentMultiCell->numNodes; i++) {
                NNSi_G2dRendererDrawCellEntryTransformed((struct Cmd020659D4 *)(&pNode[i]));
            }
        }
    }
}
