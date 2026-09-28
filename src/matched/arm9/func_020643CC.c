/*
 * function: func_020643CC
 * address:  0x020643CC
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f          0x0209C2B0  arm
 *   func_020627D8       0x020627D8  arm
 *   func_0206434C       0x0206434C  arm
 *   func_02064364       0x02064364  arm
 *   func_02063030       0x02063030  arm
 *   func_020640DC       0x020640DC  arm
 *
 * NitroSystem g2d SetMCDataToMCInstanceImpl_ (g2d_MultiCellAnimation.c):
 * bind a multi-cell data record to an instance and (re)start every node's
 * cell animation, seeking CONTINUE-mode nodes to the multi-cell's total
 * frame (modulo the sequence length when the animation loops, clamped
 * otherwise).  mcType 1 = cell animations shared through a 0x5c-byte
 * { NNSG2dCellAnimation, bInited } array; otherwise a 0x28-byte node array
 * whose pContent is the cell animation.  Callees: func_020627D8
 * GetAnimSequenceByIdx, func_0206434C SetCellAnimationSequence,
 * func_02063030 IsAnimCtrlLoopAnim, func_02064364 TickCellAnimation,
 * func_020640DC SrtcSetTrans.
 *
 * Closed in wave 12 by writing the library's own shape: ONE u16 counter at
 * function scope shared by all three loops, the per-node work as the
 * SetNodeDataToCellAnim_ inline, the frame sum as the
 * CalcAnimSequenceTotalVideoFrames inline, and bInited re-indexed through
 * the array (not a held pointer).  The wave-11 hand-scoped source stuck at
 * 7 bytes out (cells/counter swap) is in docs/notes/pkt_020643CC.c.txt.
 * Front end: ../2.0/sp2 and ../2.0/sp2p2 give identical bytes; 1.1p1 is
 * 620 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef int            BOOL;
typedef s32            fx32;

typedef struct AnimFrameData { void *pContent; u16 frames; u16 pad; } AnimFrameData;
typedef struct AnimSequenceData {
    u16 numFrames; u16 loopStartFrameIdx; u32 animType; u32 playMode;
    AnimFrameData *pAnmFrameArray;
} AnimSequenceData;

typedef struct AnimCtrl { u8 pad00[0xC]; BOOL bActive; u8 pad10[0x2C]; } AnimCtrl;
typedef struct CellAnimation { AnimCtrl animCtrl; u8 pad3c[0x1C]; } CellAnimation; /* 0x58 */
typedef struct MCCellAnimation { CellAnimation cellAnim; BOOL bInited; } MCCellAnimation;

typedef struct SRTControl { u32 type; u32 srt[4]; } SRTControl;
typedef struct Node { void *pContent; u32 type; BOOL bVisible; SRTControl srtCtrl; u8 pad20[8]; } Node;

typedef struct HierData { u16 animSequenceIdx; s16 posX; s16 posY; u16 nodeAttr; } HierData;
typedef struct MultiCellData { u16 numNodes; u16 numCellAnim; HierData *pHierDataArray; } MultiCellData;

typedef struct MCInstance {
    const MultiCellData *pCurrentMultiCell;
    const void *pAnimDataBank;
    u32 mcType;
    void *pCellAnimInstasnces;
} MCInstance;

extern const AnimSequenceData *func_020627D8(const void *bank, u16 idx);
extern void func_0206434C(CellAnimation *p, const AnimSequenceData *seq);
extern BOOL func_02063030(const AnimCtrl *c);
extern void func_02064364(CellAnimation *p, fx32 f);
extern void func_020640DC(SRTControl *s, s16 x, s16 y);

static inline u32 CalcTotal(const AnimSequenceData *pAnimSeq)
{
    u32 i;
    u32 total = 0;

    for (i = 0; i < pAnimSeq->numFrames; i++) {
        total += pAnimSeq->pAnmFrameArray[i].frames;
    }
    return total;
}

static inline u32 GetPlayMode(const HierData *pNode)
{
    const u32 mode = (u32)((pNode->nodeAttr >> 0) & 0xF);
    return mode;
}

static inline u16 GetCellAnimIdx(const HierData *pNodeData)
{
    return (u16)((0xFF00 & pNodeData->nodeAttr) >> 8);
}

static inline void SetNodeDataToCellAnim_(CellAnimation *pCellAnim, const HierData *pNodeData,
                                          const void *pAnimBank, u16 mcTotalFrame)
{
    const AnimSequenceData *pAnimSeq = 0;

    pAnimSeq = func_020627D8(pAnimBank, pNodeData->animSequenceIdx);

    func_0206434C(pCellAnim, pAnimSeq);
    pCellAnim->animCtrl.bActive = 1;

    if (GetPlayMode(pNodeData) == 1) {
        const u32 animSeqLength = CalcTotal(pAnimSeq);

        if (func_02063030(&pCellAnim->animCtrl)) {
            const u32 frameToMove = (mcTotalFrame % animSeqLength);
            func_02064364(pCellAnim, (fx32)(frameToMove << 12));
        } else {
            const u32 frameToMove = (mcTotalFrame >= animSeqLength) ? animSeqLength : mcTotalFrame;
            func_02064364(pCellAnim, (fx32)(frameToMove << 12));
        }
    }
}

void func_020643CC(MCInstance *pMCInst, const MultiCellData *pMcData, u16 mcTotalFrame)
{
    u16 i;

    pMCInst->pCurrentMultiCell = pMcData;

    if (pMCInst->mcType == 1) {
        MCCellAnimation *pCellAnimArray = (MCCellAnimation *)pMCInst->pCellAnimInstasnces;

        for (i = 0; i < pMcData->numCellAnim; i++) {
            pCellAnimArray[i].bInited = 0;
        }

        for (i = 0; i < pMcData->numNodes; i++) {
            const HierData *pNodeData = &pMcData->pHierDataArray[i];
            const u16 cellAnimIdx = GetCellAnimIdx(pNodeData);

            if (!pCellAnimArray[cellAnimIdx].bInited) {
                CellAnimation *pCellAnim = &pCellAnimArray[cellAnimIdx].cellAnim;

                SetNodeDataToCellAnim_(pCellAnim, pNodeData, pMCInst->pAnimDataBank, mcTotalFrame);

                pCellAnimArray[cellAnimIdx].bInited = 1;
            }
        }
    } else {
        Node *pNodeArray = (Node *)(pMCInst->pCellAnimInstasnces);

        for (i = 0; i < pMcData->numNodes; i++) {
            const HierData *pNodeData = &pMcData->pHierDataArray[i];
            CellAnimation *pCellAnim = (CellAnimation *)pNodeArray[i].pContent;

            SetNodeDataToCellAnim_(pCellAnim, pNodeData, pMCInst->pAnimDataBank, mcTotalFrame);

            pNodeArray[i].bVisible = 1;
            func_020640DC(&pNodeArray[i].srtCtrl, pNodeData->posX, pNodeData->posY);
        }
    }
}
