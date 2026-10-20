/*
 * file:     nns_g2d_multi_cell_animation.c
 * unit:     yes
 * function: NNSi_G2dInitMCNode, NNSi_G2dRefreshCellAnimation, NNS_G2dInitCellAnimation, NNS_G2dInitCellAnimationVramTransfered, NNS_G2dSetCellAnimationSequence, NNS_G2dTickCellAnimation, NNS_G2dSetCellAnimationCurrentFrame, NNS_G2dRestartCellAnimation, NNS_G2dSetCellAnimationSpeed, NNSi_G2dSetMCDataToMCInstanceImpl, NNS_G2dGetMCBankNumCellAnimRequired, NNS_G2dSetAnimSequenceToMCAnimation, NNS_G2dInitMCAnimation, NNS_G2dGetMCWorkAreaSize, NNS_G2dGetMCBankNumNodesRequired, NNSi_G2dTickMCInstance, NNS_G2dTickMCAnimation, NNS_G2dSetMCAnimationCurrentFrame, NNS_G2dSetMCAnimationSpeed, NNSi_G2dSetMCInstanceCurrentFrameZero, NNS_G2dRestartMCAnimation
 * address:  0x02064178
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * The single-step twin of NNSi_G2dTickMCInstance: walks every node of the multi-cell
 * bank and advances its cell animation by one frame.  Same two layouts
 * (kind 1 is the 0x5C-stride node array with its count at header +2, anything
 * else the 0x28-stride cell array with its count at header +0 and each
 * record's pointer in its word 0).
 * The second argument NNS_G2dSetCellAnimationCurrentFrame receives is the constant 0, materialised
 * into r4 once outside the loop and never refreshed: the register that holds it
 * is rematerialised off the counter's own zero.
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dSetMCInstanceCurrentFrameZero.c \
 *       --func NNSi_G2dSetMCInstanceCurrentFrameZero --addr 0x02064C10 --arm --cc 1.1p1
 * The reset twin of NNSi_G2dSetMCInstanceCurrentFrameZero / NNS_G2dSetMCAnimationSpeed: clears the u16 at +0x30,
 * runs NNS_G2dSetAnimSequenceToMCAnimation over the object with its +0x1c word, raises the +0x0c
 * state to 1, then walks every record of the multi-cell bank and resets its
 * cell animation.  Same two layouts as the rest of the family (kind 1 is the
 * 0x5c-stride node array with its count at header +2, anything else the
 * 0x28-stride cell array with its count at header +0 and each record's
 * pointer in its word 0).
 * Pinned to ../2.0/sp2 on the "kept constants" tell: the image rematerialises
 * each loop's stride into a fresh register inside the loop body (`mov r7,
 * #0x5c` at 0x02064D00, `mov r7, #0x28` at 0x02064D40) and re-reads the header
 * pointer at +0x34 on every back edge; dsi/1.1p1 -O4,p keeps stride and header
 * live in callee-saved registers, 168 bytes against the original's 180 and 135
 * concrete out.  Under the pin the same C is 180 bytes, 0 mismatches.  See
 * docs/FRONTEND-PINS.md.
 *
 * symbols:
 *   NNSi_G2dSrtcInitControl  0x02064140  arm
 *   NNSi_G2dRequestCellTransferState  0x02066ABC  arm
 *   NNS_G2dInitAnimCtrl  0x02062F38  arm
 *   NNS_G2dSetCellAnimationSequence  0x0206434C  arm
 *   NNS_G2dSetCellTransferState  0x02066890  arm
 *   NNS_G2dSetCellAnimationBank   0x02062FF0  arm
 *   NNS_G2dTickAnimCtrl  0x02062D4C  arm
 *   NNSi_G2dSetCellAnimationCurrentFrame  0x02062F00  arm
 *   NNS_G2dResetCellAnimation  0x02062F90  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   NNS_G2dGetAnimSequenceByIdx       0x020627D8  arm
 *   NNS_G2dIsCellAnimationBoundingBox       0x02063030  arm
 *   NNS_G2dSetSRTTranslate       0x020640DC  arm
 *   NNS_G2dGetMultiCellDataByIdx  0x020629E8  arm
 *   NNSi_G2dGetCellAnimationCurrentSequence   0x02062D40  arm
 *   NNS_G2dSetSRTRotate   0x02064100  arm
 *   NNS_G2dSetSRTScale   0x02064120  arm
 *   NNS_G2dSetCellAnimationSpeed  0x020643C4  arm
 *   NNS_G2dGetCellDataByIdx  0x0206285C  arm
 */
struct AnimBank;
#include "../types.h"

#include "nns_g2d_anim_types.h"

#include "nns_g2d_anim_bank.h"
#include "nns_g2d_load.h"
#include "nns_g2d_cell_animation.h"
#include "nns_g2d_srt_control.h"
struct CellTransferState;
#include "nns_g2d_cell_transfer.h"
void NNSi_G2dInitMCNode(Node *pNode, u32 type);
void NNSi_G2dRefreshCellAnimation(CellAnim *pCellAnim);
void NNS_G2dInitCellAnimation(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq, CellDataBank *pCellDataBank);
void NNS_G2dInitCellAnimationVramTransfered(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq, CellDataBank *pCellDataBank, u32 stateIdx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void NNS_G2dSetCellAnimationSequence(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq);
void NNS_G2dTickCellAnimation(CellAnim *pCellAnim, fx32 frames);
void NNS_G2dSetCellAnimationCurrentFrame(CellAnim *pCellAnim, u32 frameIdx);
void NNS_G2dRestartCellAnimation(CellAnim *pCellAnim);
void NNS_G2dSetCellAnimationSpeed(CellAnim *pCellAnim, fx32 speed);
void NNSi_G2dSetMCDataToMCInstanceImpl(MCInstance *pMCInst, const MultiCellData *pMcData, u16 mcTotalFrame);
u16 NNS_G2dGetMCBankNumCellAnimRequired(MultiCellBank *pBank);
void NNS_G2dSetAnimSequenceToMCAnimation(MultiCellAnim *pMCAnim, const AnimSequenceData *pAnimSeq);
void NNS_G2dInitMCAnimation(MultiCellAnim *pMCAnim, void *pBuf, const struct AnimBank *pAnimBank, CellDataBank *pCellDataBank, MultiCellBank *pBank, int kind);
int NNS_G2dGetMCWorkAreaSize(MultiCellBank *pBank, u32 kind);
u16 NNS_G2dGetMCBankNumNodesRequired(MultiCellBank *pBank);
void NNSi_G2dTickMCInstance(MCInstance *pMCInst, fx32 frames);
void NNS_G2dTickMCAnimation(MultiCellAnim *pMCAnim, fx32 frames);
void NNS_G2dSetMCAnimationCurrentFrame(MultiCellAnim *pMCAnim, u32 frameIdx);
void NNS_G2dSetMCAnimationSpeed(MultiCellAnim *pMCAnim, fx32 speed);
void NNSi_G2dSetMCInstanceCurrentFrameZero(MCInstance *pMCInst);
void NNS_G2dRestartMCAnimation(MultiCellAnim *pMCAnim);

/*
 * Opens one 0x28-byte group header of the two-level cell-array shape: clears
 * the header's first word, stores the cell pointer at +0x04, sets the "in use"
 * word at +0x08 and tail-calls NNSi_G2dSrtcInitControl on the SRT block at +0x0c.
 * NNS_G2dInitMCAnimation drives it once per group.
 *
 * PIN ../2.0/sp2: the tail-call scheduling form of the "kept constants" tell.
 * The image materialises the zero FIRST and stores it first -- `mov r2,#0` at
 * 0x02064178 / `str r2,[r0]` / `str r1,[r0,#4]` / `mov r1,#1` / `str r1,[r0,#8]`
 * -- and only then loads the tail-call pool word (`ldr ip,[pc,#4]` at
 * 0x0206418C).  1.1p1 -O4,p hoists that pool load ABOVE the three stores and
 * posts the zero store after them, which lets it drop one instruction: 32
 * bytes against the original's 36, 23 concrete out.  An earlier lane measured
 * the array spelling `((u32 *)o)[0] = 0; ...`, the named-field spelling and a
 * `(u8 *)o + 0xc` call argument and found all three byte-identical to each
 * other, i.e. the scheduling is not source-driven
 * (docs/notes/pkt_02064178.c.txt).  Under the pin this SAME C is 36 bytes, 0
 * mismatches.
 */
void NNSi_G2dInitMCNode(Node *pNode, u32 type)
{
    pNode->pContent = 0;
    pNode->type = type;
    pNode->bVisible = 1;
    NNSi_G2dSrtcInitControl((SRTControl *)(&pNode->srtCtrl), 1);
}

void NNSi_G2dRefreshCellAnimation(CellAnim *pCellAnim)
{
    NodeRec *pNodeRec;
    CellDataBank *pCellDataBank;
    int kind;
    CellVramTransferData *pTransfer;
    int hasTransferData;
    int hasHandle;

    if (pCellAnim->animCtrl.pActiveCurrent->frames == 0)
        return;

    NNSi_G2dGetCellAnimationCurrentSequence(&pCellAnim->animCtrl);
    pNodeRec = NNSi_G2dGetCellAnimationCurrentSequence(&pCellAnim->animCtrl);

    pCellDataBank = pCellAnim->pCellDataBank;
    pCellAnim->pCurrentCell = NNS_G2dGetCellDataByIdx(pCellDataBank, pNodeRec->index);

    kind = pCellAnim->animCtrl.pAnimSequence->animType & 0xff;

    NNSi_G2dSrtcInitControl((SRTControl *)(&pCellAnim->srtCtrl), 1);

    switch (kind) {
    case 0:
        break;
    case 2:
        NNS_G2dSetSRTTranslate(&pCellAnim->srtCtrl, pNodeRec->transOnlyX, pNodeRec->transOnlyY);
        break;
    default:
        NNS_G2dSetSRTScale((SRTControl *)(&pCellAnim->srtCtrl), pNodeRec->scaleX, pNodeRec->scaleY);
        NNS_G2dSetSRTRotate((SRTControl *)(&pCellAnim->srtCtrl), pNodeRec->rotZ);
        NNS_G2dSetSRTTranslate(&pCellAnim->srtCtrl, pNodeRec->transX, pNodeRec->transY);
        break;
    }

    pTransfer = pCellDataBank->pVramTransferData;
    hasTransferData = !!pTransfer;
    if (hasTransferData == 0) return;

    if (*(volatile int *)&pCellAnim->transferStateHandle != -1) hasHandle = 1; else hasHandle = 0;
    if (hasHandle == 0) return;

    {
        VramTransferEntry *pEntry = (VramTransferEntry *)(pTransfer->pTransferDataArray + pNodeRec->index * 8);
        NNSi_G2dRequestCellTransferState(pCellAnim->transferStateHandle, pEntry->srcOffset, pEntry->szByte);
    }
}

/*
 * Binds one cell-bank row to an animation object: stores the row pointer at
 * +0x34, writes the "no cell bound" sentinel -1 at +0x38, opens the SRT block
 * at +0x3c through NNSi_G2dSrtcInitControl and finishes with the object's own two-call
 * tail.  The sibling of NNS_G2dInitCellAnimationVramTransfered, which does the same fixups after an
 * eight-argument forward.
 *
 * PIN ../2.0/sp2: the "kept constants" tell in its allocation form.  The image
 * materialises the sentinel into r2 and stores it SECOND, between the +0x34
 * store and the `add r0, r5, #0x3c` argument setup -- `str r2,[r5,#0x34]` at
 * 0x02064298 / `mvn r2,#0` at 0x0206429C / `add r0,r5,#0x3c` / `mov r1,#1` /
 * `str r2,[r5,#0x38]` at 0x020642A8.  1.1p1 -O4,p allocates the -1 into r3
 * instead and sinks its store below the whole argument setup, giving
 * `mvn r3,#0` / `add r0,r5,#0x3c` / `mov r1,#1` / `str r2,[r5,#0x34]` /
 * `str r3,[r5,#0x38]`: the same 60 bytes, 17 concrete out.  An earlier lane
 * measured `0xffffffffu`, `(u32)-1` and a named `u32` local for the sentinel
 * and every one allocates r3 the same way (docs/notes/pkt_02064178.c.txt).
 * Under the pin this SAME C is 60 bytes, 0 mismatches, all three sites label.
 */
void NNS_G2dInitCellAnimation(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq, CellDataBank *pCellDataBank)
{
    pCellAnim->pCellDataBank = pCellDataBank;
    pCellAnim->transferStateHandle = -1;
    NNSi_G2dSrtcInitControl((SRTControl *)(&pCellAnim->srtCtrl), 1);
    NNS_G2dInitAnimCtrl((&pCellAnim->animCtrl));
    NNS_G2dSetCellAnimationSequence(pCellAnim, pAnimSeq);
}

/*
 * The eight-argument forwarder into NNS_G2dSetCellTransferState (four in registers, four
 * on the stack at [sp]..[sp,#0xc], re-read from the caller's own stacked
 * arguments at [sp,#0x28]..[sp,#0x3c]), followed by the object fixups.
 *
 * Two levers, both needed, both `volatile`:
 *   1. The image stores self+0x38 TWICE, at 0x02064318 and again at
 *      0x02064328, with the self+0x34 store between them.  Written as plain
 *      assignments mwcc drops the first and the function is 128 bytes
 *      against 132, 64 concrete out.  Marking that field `volatile` is what
 *      keeps both stores.
 *   2. With only (1), the self+0x34 store sinks below the `add r0, r7, #0x3c`
 *      / `mov r1, #1` argument setup for NNSi_G2dSrtcInitControl (11 concrete bytes at
 *      the right size).  Marking that field `volatile` too pins it above
 *      them, matching 0x0206431C.
 * Both are plain field stores in the real source; `volatile` here is standing
 * in for whatever ordering the original had, and is the spelling that
 * reproduces the bytes.
 *
 * Byte-correct: 132 bytes, 0 concrete mismatches, under the DEFAULT 1.1p1
 * (no pin needed; ../2.0/sp2 also gives 132/0 with the same C).
 *
 * Blocked on: `label`.  Three of the four PC24 sites resolve, but NNS_G2dSetCellTransferState
 * has no branch anywhere in the image outside this function's own `bl` at
 * 0x02064314, and no matched entry, so the site stays wildcarded and the file
 * caps at MATCH.  It promotes as soon as 0x02066890 or a second caller of it
 * is filed.
 */
void NNS_G2dInitCellAnimationVramTransfered(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq, CellDataBank *pCellDataBank, u32 stateIdx,
                   u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    NNS_G2dSetCellTransferState(stateIdx, a, b, c, pCellDataBank->pVramTransferData->szByteMax, d, e, f);
    *(volatile int *)&pCellAnim->transferStateHandle = stateIdx;
    *(CellDataBank *volatile *)&pCellAnim->pCellDataBank = pCellDataBank;
    *(volatile int *)&pCellAnim->transferStateHandle = stateIdx;
    NNSi_G2dSrtcInitControl((SRTControl *)(&pCellAnim->srtCtrl), 1);
    NNS_G2dInitAnimCtrl((&pCellAnim->animCtrl));
    NNS_G2dSetCellAnimationSequence(pCellAnim, pAnimSeq);
}

void NNS_G2dSetCellAnimationSequence(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq)
{
    NNS_G2dSetCellAnimationBank((CellAnim *)(&pCellAnim->animCtrl), (void *)pAnimSeq);
    NNSi_G2dRefreshCellAnimation(pCellAnim);
}

/*
 * Advances one multi-cell node's cell animation by a fx32 tick and, only if
 * that actually changed the displayed frame, marks the node's OAM cache dirty
 * through NNSi_G2dRefreshCellAnimation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dTickCellAnimation.c  *       --func NNS_G2dTickCellAnimation --addr 0x02064364 --cc 1.1p1
 */
void NNS_G2dTickCellAnimation(CellAnim *pCellAnim, fx32 frames)
{
    if (NNS_G2dTickAnimCtrl(&pCellAnim->animCtrl, frames) != 0) {
        NNSi_G2dRefreshCellAnimation(pCellAnim);
    }
}

/*
 * The single-step form of NNS_G2dTickCellAnimation: steps the node's cell animation by
 * one frame instead of by a tick, and marks the cache dirty if it moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationCurrentFrame.c  *       --func NNS_G2dSetCellAnimationCurrentFrame --addr 0x02064384 --cc 1.1p1
 */
void NNS_G2dSetCellAnimationCurrentFrame(CellAnim *pCellAnim, u32 frameIdx)
{
    if (NNSi_G2dSetCellAnimationCurrentFrame(&pCellAnim->animCtrl, frameIdx) != 0) {
        NNSi_G2dRefreshCellAnimation(pCellAnim);
    }
}

/*
 * Restarts one node's cell animation from frame 0, forces its active flag at
 * +0x0C on and marks the node's OAM cache dirty unconditionally.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dRestartCellAnimation.c  *       --func NNS_G2dRestartCellAnimation --addr 0x020643A4 --cc 1.1p1
 */
void NNS_G2dRestartCellAnimation(CellAnim *pCellAnim)
{
    NNS_G2dResetCellAnimation((AnimCtrl *)(&pCellAnim->animCtrl));
    pCellAnim->animCtrl.bActive = 1;
    NNSi_G2dRefreshCellAnimation(pCellAnim);
}

/*
 * Stores the playback speed (fx32) into the animation controller at +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationSpeed.c  *       --func NNS_G2dSetCellAnimationSpeed --addr 0x020643C4 --cc 1.1p1
 */
void NNS_G2dSetCellAnimationSpeed(CellAnim *pCellAnim, fx32 speed)
{
    pCellAnim->animCtrl.speed = speed;
}

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

static inline void SetNodeDataToCellAnim_(CellAnim *pCellAnim, const HierData *pNodeData,
                                          const struct AnimBank *pAnimBank, u16 mcTotalFrame)
{
    const AnimSequenceData *pAnimSeq = 0;

    pAnimSeq = NNS_G2dGetAnimSequenceByIdx(pAnimBank, pNodeData->animSequenceIdx);

    NNS_G2dSetCellAnimationSequence(pCellAnim, pAnimSeq);
    pCellAnim->animCtrl.bActive = 1;

    if (GetPlayMode(pNodeData) == 1) {
        const u32 animSeqLength = CalcTotal(pAnimSeq);

        if (NNS_G2dIsCellAnimationBoundingBox((CellAnim *)(&pCellAnim->animCtrl))) {
            const u32 frameToMove = (mcTotalFrame % animSeqLength);
            NNS_G2dTickCellAnimation(pCellAnim, (fx32)(frameToMove << 12));
        } else {
            const u32 frameToMove = (mcTotalFrame >= animSeqLength) ? animSeqLength : mcTotalFrame;
            NNS_G2dTickCellAnimation(pCellAnim, (fx32)(frameToMove << 12));
        }
    }
}

/*
 * NitroSystem g2d SetMCDataToMCInstanceImpl_ (g2d_MultiCellAnimation.c):
 * bind a multi-cell data record to an instance and (re)start every node's
 * cell animation, seeking CONTINUE-mode nodes to the multi-cell's total
 * frame (modulo the sequence length when the animation loops, clamped
 * otherwise).  mcType 1 = cell animations shared through a 0x5c-byte
 * { NNSG2dCellAnimation, bInited } array; otherwise a 0x28-byte node array
 * whose pContent is the cell animation.  Callees: NNS_G2dGetAnimSequenceByIdx
 * GetAnimSequenceByIdx, NNS_G2dSetCellAnimationSequence SetCellAnimationSequence,
 * NNS_G2dIsCellAnimationBoundingBox IsAnimCtrlLoopAnim, NNS_G2dTickCellAnimation TickCellAnimation,
 * NNS_G2dSetSRTTranslate SrtcSetTrans.
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
void NNSi_G2dSetMCDataToMCInstanceImpl(MCInstance *pMCInst, const MultiCellData *pMcData, u16 mcTotalFrame)
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
                CellAnim *pCellAnim = &pCellAnimArray[cellAnimIdx].cellAnim;

                SetNodeDataToCellAnim_(pCellAnim, pNodeData, pMCInst->pAnimDataBank, mcTotalFrame);

                pCellAnimArray[cellAnimIdx].bInited = 1;
            }
        }
    } else {
        Node *pNodeArray = (Node *)(pMCInst->pCellAnimInstasnces);

        for (i = 0; i < pMcData->numNodes; i++) {
            const HierData *pNodeData = &pMcData->pHierDataArray[i];
            CellAnim *pCellAnim = (CellAnim *)pNodeArray[i].pContent;

            SetNodeDataToCellAnim_(pCellAnim, pNodeData, pMCInst->pAnimDataBank, mcTotalFrame);

            pNodeArray[i].bVisible = 1;
            NNS_G2dSetSRTTranslate(&pNodeArray[i].srtCtrl, pNodeData->posX, pNodeData->posY);
        }
    }
}

/*
 * Returns the largest per-multi-cell "cell animation slot count" (the u16 at
 * +0x02 of the 8-byte multi-cell descriptor) across a whole multi-cell bank.
 * The caller sizes its array of 0x5C-byte cell-animation states with this, and
 * each node's byte at +0x07 is the index into that array -- which is why that
 * byte runs 0, 1, 2, ... across a multi-cell's nodes rather than naming a cell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetMCBankNumCellAnimRequired.c  *       --func NNS_G2dGetMCBankNumCellAnimRequired --addr 0x02064648 --cc 1.1p1
 */
u16 NNS_G2dGetMCBankNumCellAnimRequired(MultiCellBank *pBank)
{
    u16 max = 0;
    u16 i = 0;

    for (i = 0; i < pBank->numMultiCell; i++) {
        u16 n = NNS_G2dGetMultiCellDataByIdx(pBank, i)->numCellAnim;

        if (n > max) {
            max = n;
        }
    }

    return max;
}

/*
 * Rebuilds one multi-cell node's SRT block from its current NANR frame record.
 * The node record comes through NNSi_G2dGetCellAnimationCurrentSequence and its descriptor through
 * NNS_G2dGetMultiCellDataByIdx; the frame's kind byte (a word masked with 0xff, not a ldrb)
 * selects the arm: 0 does nothing, 2 is translation-only, anything else is the
 * full SRT form (scale, rotation, translation).  The walk finishes by handing
 * the descriptor and the node's own u16 counter at +0x30 to NNSi_G2dSetMCDataToMCInstanceImpl.
 *
 * PIN ../2.0/sp2: the "kept branches" tell in its CROSS-JUMP form, the same
 * one src/matched/NNS_G2dSetMCAnimationCurrentFrame.c and src/matched/NNSi_G2dRefreshCellAnimation.c carry.  The
 * image writes the kind==2 arm's `add r0, r4, #0x48` / `bl NNS_G2dSetSRTTranslate` tail
 * out in its own arm although the other arm's LAST call is a byte-identical
 * pair; 1.1p1 -O4,p cross-jumps the two and lands at 176 bytes against the
 * original's 184, 73 concrete bytes out (docs/notes/pkt_0206469C.c.txt, which
 * measured the goto/if-else/switch spellings and found them all folding).
 * Under the pin this SAME C is 184 bytes, 0 mismatches, all 9 sites by label.
 */
void NNS_G2dSetAnimSequenceToMCAnimation(MultiCellAnim *pMCAnim, const AnimSequenceData *pAnimSeq)
{
    NodeRec *pNodeRec;
    u32 kind;
    uptr pMultiCellData;

    NNS_G2dSetCellAnimationBank((CellAnim *)(&pMCAnim->animCtrl), (void *)pAnimSeq);
    pMCAnim->totalFrames = 0;

    if (pMCAnim->animCtrl.pActiveCurrent->frames == 0) {
        return;
    }

    pNodeRec = NNSi_G2dGetCellAnimationCurrentSequence(&pMCAnim->animCtrl);
    pMultiCellData = (uptr)NNS_G2dGetMultiCellDataByIdx(pMCAnim->pMultiCellBank, pNodeRec->index);
    kind = pMCAnim->animCtrl.pAnimSequence->animType & 0xff;

    NNSi_G2dSrtcInitControl((SRTControl *)(&pMCAnim->srtCtrl), 1);

    if (kind == 0) {
        goto done;
    }

    if (kind == 2) {
        NNS_G2dSetSRTTranslate(&pMCAnim->srtCtrl, pNodeRec->transOnlyX, pNodeRec->transOnlyY);
    } else {
        NNS_G2dSetSRTScale((SRTControl *)(&pMCAnim->srtCtrl), pNodeRec->scaleX, pNodeRec->scaleY);
        NNS_G2dSetSRTRotate((SRTControl *)(&pMCAnim->srtCtrl), pNodeRec->rotZ);
        NNS_G2dSetSRTTranslate(&pMCAnim->srtCtrl, pNodeRec->transX, pNodeRec->transY);
    }

done:
    NNSi_G2dSetMCDataToMCInstanceImpl(&pMCAnim->mc, (const MultiCellData *)pMultiCellData, pMCAnim->totalFrames);
}

/*
 * Build a multi-cell animation's cell array (docs/families/cluster_020640DC.h,
 * section 3): kind == 1 is the flat 0x5c-stride array sized by
 * NNS_G2dGetMCBankNumCellAnimRequired(bank), anything else the two-level shape of
 * NNS_G2dGetMCBankNumNodesRequired(bank) 0x28-byte group headers followed by 0x58-stride cells.
 *
 * Three things closed it after docs/notes/pkt_02064754.c.txt stalled at 70
 * out:
 *   - DATA FLOW.  The NMCR bank handed to both sizing calls is the FIFTH
 *     argument (loaded from [sp,#0x28] into r0 before the kind test and
 *     respilled to its own slot), and the second argument is the cell
 *     buffer stored at +0x40 and used as the group-header base.  The note's
 *     body passed the second argument to NNS_G2dGetMCBankNumNodesRequired; with the flow
 *     corrected no `volatile` is needed for the respill.
 *   - Arm 2 runs the four-call tail TWICE (it falls into the shared copy),
 *     so the tail is written in the arm and again after the if.
 *   - The count and index are declared PER ARM (u16 n, i inside each
 *     block); function-scope n / i are 18 out (a register swap in both
 *     loops), a separate j for arm 2 is 4 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dInitMCAnimation.c \
 *       --func NNS_G2dInitMCAnimation --addr 0x02064754 --arm --cc ../2.0/sp2
 */
void NNS_G2dInitMCAnimation(MultiCellAnim *pMCAnim, void *pBuf, const struct AnimBank *pAnimBank, CellDataBank *pCellDataBank, MultiCellBank *pBank, int kind)
{
  if (kind == 1)
  {
    MCCellAnimation *cells;
    u16 n;
    u16 i;
    pMCAnim->mc.mcType = 1;
    pMCAnim->mc.pAnimDataBank = pAnimBank;
    pMCAnim->mc.pCellAnimInstasnces = pBuf;
    n = NNS_G2dGetMCBankNumCellAnimRequired(pBank);
    cells = (MCCellAnimation *)pMCAnim->mc.pCellAnimInstasnces;
    for (i = 0; i < n; i++)
    {
      MCCellAnimation *cell = &cells[i];
      NNS_G2dInitCellAnimation(&cell->cellAnim, NNS_G2dGetAnimSequenceByIdx(pAnimBank, 0), pCellDataBank);
      cell->bInited = 1;
    }
  }
  else
  {
    char *base;
    u16 n;
    u16 i;
    n = NNS_G2dGetMCBankNumNodesRequired(pBank);
    base = (char *)pBuf + n * 0x28;
    pMCAnim->mc.mcType = 0;
    pMCAnim->mc.pCurrentMultiCell = 0;
    pMCAnim->mc.pAnimDataBank = pAnimBank;
    pMCAnim->mc.pCellAnimInstasnces = pBuf;
    for (i = 0; i < n; i++)
    {
      Node *pNode = (Node *)pBuf + i;
      CellAnim *cell;
      NNSi_G2dInitMCNode(pNode, 1);
      cell = (CellAnim *)(base + i * 0x58);
      pNode->pContent = cell;
      NNS_G2dInitCellAnimation(cell, NNS_G2dGetAnimSequenceByIdx(pAnimBank, 0), pCellDataBank);
    }
    NNS_G2dInitAnimCtrl((&pMCAnim->animCtrl));
    pMCAnim->pMultiCellBank = pBank;
    NNSi_G2dSrtcInitControl((SRTControl *)(&pMCAnim->srtCtrl), 1);
    pMCAnim->totalFrames = 0;
  }
  NNS_G2dInitAnimCtrl((&pMCAnim->animCtrl));
  pMCAnim->pMultiCellBank = pBank;
  NNSi_G2dSrtcInitControl((SRTControl *)(&pMCAnim->srtCtrl), 1);
  pMCAnim->totalFrames = 0;
}

int NNS_G2dGetMCWorkAreaSize(MultiCellBank *pBank, u32 kind)
{
    u32 size;

    if (kind == 1) {
        size = NNS_G2dGetMCBankNumCellAnimRequired(pBank) * 0x5c;
    } else {
        size = NNS_G2dGetMCBankNumNodesRequired(pBank) << 7;
    }
    return size;
}

/*
 * Returns the largest node count among the multi-cell descriptors of the bank,
 * 0 for an empty bank.  The counter is a u16 (the `lsl #16` / `lsr #16` pair
 * per iteration) and the count is re-read from the bank every iteration, which
 * is why the guard at the top is a rotated `cmp count, #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetMCBankNumNodesRequired.c \
 *       --func NNS_G2dGetMCBankNumNodesRequired --addr 0x020648E0 --arm --cc 1.1p1
 */
u16 NNS_G2dGetMCBankNumNodesRequired(MultiCellBank *pBank)
{
    u16 max = 0;
    u16 i;

    for (i = 0; i < pBank->numMultiCell; i++) {
        u16 n = NNS_G2dGetMultiCellDataByIdx(pBank, i)->numNodes;

        if (n > max) {
            max = n;
        }
    }

    return max;
}

/*
 * Step every node of the multi-cell walk block (struct Root of
 * docs/families/cluster_020640DC.h) by `arg` ticks: kind == 1 walks the
 * flat 0x5c-stride array for data->numCellAnims, anything else the
 * 0x28-stride group headers' first word for data->numNodes.
 *
 * The lever that closed the note's last 4 bytes (two head loads swapped,
 * docs/notes/NNSi_G2dTickMCInstance.c.txt): declare the index and the array base
 * INSIDE EACH ARM.  A function-scope `u16 i = 0; char *base = p->f0c;`
 * issues the base load before the data-pointer load; per-arm locals let
 * the front end hoist the arms' common data-pointer load first, which is
 * the image.  No dead local needed.  Identical bytes under dsi/1.1p1 and
 * ../2.0/sp2 (not a pin).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dTickMCInstance.c \
 *       --func NNSi_G2dTickMCInstance --addr 0x02064934 --arm --cc 1.1p1
 */
void NNSi_G2dTickMCInstance(MCInstance *pMCInst, fx32 frames)
{
    if (pMCInst->mcType == 1) {
        u16 i;
        MCCellAnimation *cells = (MCCellAnimation *)pMCInst->pCellAnimInstasnces;
        for (i = 0; i < pMCInst->pCurrentMultiCell->numCellAnim; i++) NNS_G2dTickCellAnimation(&cells[i].cellAnim, frames);
    } else {
        u16 i;
        Node *nodes = (Node *)pMCInst->pCellAnimInstasnces;
        for (i = 0; i < pMCInst->pCurrentMultiCell->numNodes; i++) NNS_G2dTickCellAnimation((CellAnim *)nodes[i].pContent, frames);
    }
}

/*
 * The tick-driven form of NNS_G2dSetMCAnimationCurrentFrame: steps the multi-cell animation by a
 * fx32 tick through NNS_G2dTickAnimCtrl and, when that reports no advance, hands the
 * whole walk block at +0x34 to NNSi_G2dTickMCInstance instead.  From the header test
 * down the body is NNS_G2dSetMCAnimationCurrentFrame's verbatim.
 *
 * PIN ../2.0/sp2, inherited from the sibling src/matched/NNS_G2dSetMCAnimationCurrentFrame.c: the
 * same case-2 cross-jump.  1.1p1 -O4,p shares case 2's
 * `add r0, r4, #0x48` / `bl NNS_G2dSetSRTTranslate` tail with the default arm's
 * identical pair at 0x02064A88/0x02064A8C and lands at 220 bytes against the
 * original's 224 (docs/notes/pkt_02064934.NNS_G2dTickMCAnimation.c.txt).
 *
 * THREE C LEVERS, all needed and all found in this pass:
 *  1. NNS_G2dTickAnimCtrl IS ARITY TWO, not three.  The note's body declared a third
 *     parameter and passed the latched halfword `t`; that costs a `mov r2, r5`
 *     at 0x020649E8 and the compile is 228 bytes.  The image sets only r0/r1.
 *  2. THE MISS ARM MUST BE A `goto` TO THE FUNCTION'S TAIL.  Written inline as
 *     `{ NNSi_G2dTickMCInstance(...); return; }` the compiler emits it in place under a
 *     `bne` where the image emits `beq #0x2064aa4` over the whole body to an
 *     arm placed AFTER the main epilogue.  Size-exact either way; the inline
 *     form is 140 concrete bytes out because everything after +0x1C is shifted
 *     by one instruction.
 *  3. `int kind;` MUST BE DECLARED BEFORE `int r7;`.  Declaration order is
 *     stack/colour order here: the reverse puts the masked kind in r7 and the
 *     descriptor in r6, where the image has kind in r6 and the descriptor in
 *     r7 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * The +0x2C PC24 to NNSi_G2dTickMCInstance resolves by `sole-ref/code`: 0x02064934 is a
 * traced function start and this `bl` is its only branch image-wide, which is
 * exactly the single-caller shape `label` cannot reach.
 */
void NNS_G2dTickMCAnimation(MultiCellAnim *pMCAnim, fx32 frames)
{
    unsigned short stepFrames = pMCAnim->animCtrl.pCurrent->frames;
    NodeRec *pNodeRec;
    int kind;
    sptr pMultiCellData;

    if (NNS_G2dTickAnimCtrl(&pMCAnim->animCtrl, frames) == 0) {
        goto miss;
    }
    pMCAnim->totalFrames += stepFrames;
    if (pMCAnim->animCtrl.pActiveCurrent->frames == 0)
        return;
    pNodeRec = NNSi_G2dGetCellAnimationCurrentSequence(&pMCAnim->animCtrl);
    pMultiCellData = (sptr)NNS_G2dGetMultiCellDataByIdx(pMCAnim->pMultiCellBank, pNodeRec->index);
    kind = pMCAnim->animCtrl.pAnimSequence->animType & 0xff;
    NNSi_G2dSrtcInitControl((SRTControl *)(&pMCAnim->srtCtrl), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        NNS_G2dSetSRTTranslate(&pMCAnim->srtCtrl, pNodeRec->transOnlyX, pNodeRec->transOnlyY);
        break;
    default:
        NNS_G2dSetSRTScale((SRTControl *)(&pMCAnim->srtCtrl), pNodeRec->scaleX, pNodeRec->scaleY);
        NNS_G2dSetSRTRotate((SRTControl *)(&pMCAnim->srtCtrl), pNodeRec->rotZ);
        NNS_G2dSetSRTTranslate(&pMCAnim->srtCtrl, pNodeRec->transX, pNodeRec->transY);
        break;
    }
    NNSi_G2dSetMCDataToMCInstanceImpl(&pMCAnim->mc, (const MultiCellData *)pMultiCellData, pMCAnim->totalFrames);
    return;
miss:
    NNSi_G2dTickMCInstance(&pMCAnim->mc, frames);
}

/*
 * PIN ../2.0/sp2: the "kept branches" tell.  The image writes the case-2
 * call tail out in its own arm -- `add r0, r4, #0x48` (0x02064B20) /
 * `bl NNS_G2dSetSRTTranslate` (0x02064B24) / `b 0x02064B54` (0x02064B28) -- although
 * the default arm ends in a byte-identical `add r0, r4, #0x48` /
 * `bl NNS_G2dSetSRTTranslate` pair at 0x02064B4C/0x02064B50.  1.1p1 -O4,p cross-jumps
 * the two, branching case 2 into the default arm's pair and giving 172 bytes
 * against the original's 180, 64 concrete bytes out.  Two independent lanes
 * measured a dozen spellings (switch arm order, if-chain, goto tail, named
 * s16 locals, nested switch) and all cross-jump.  Under the pin the same C
 * is 180 bytes, 0 mismatches.
 *
 * Same body as NNS_G2dTickMCAnimation from the header test down, but with a guard
 * that returns early instead of the missed-lookup arm, and no call to
 * NNSi_G2dTickMCInstance.  The early-out is ONE expression: the two tests are
 * predicated onto a single `popeq` (`ldrne`/`cmpne`/`popeq`), which is what
 * makes it a `||` inside a single `if` rather than two `if`s (two separate
 * guards would each need their own `pop`).
 */
void NNS_G2dSetMCAnimationCurrentFrame(MultiCellAnim *pMCAnim, u32 frameIdx)
{
    NodeRec *pNodeRec;
    int kind;
    sptr pMultiCellData;

    if (NNSi_G2dSetCellAnimationCurrentFrame(&pMCAnim->animCtrl, frameIdx) == 0 || pMCAnim->animCtrl.pActiveCurrent->frames == 0)
        return;
    pNodeRec = NNSi_G2dGetCellAnimationCurrentSequence(&pMCAnim->animCtrl);
    pMultiCellData = (sptr)NNS_G2dGetMultiCellDataByIdx(pMCAnim->pMultiCellBank, pNodeRec->index);
    kind = pMCAnim->animCtrl.pAnimSequence->animType & 0xff;
    NNSi_G2dSrtcInitControl((SRTControl *)(&pMCAnim->srtCtrl), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        NNS_G2dSetSRTTranslate(&pMCAnim->srtCtrl, pNodeRec->transOnlyX, pNodeRec->transOnlyY);
        break;
    default:
        NNS_G2dSetSRTScale((SRTControl *)(&pMCAnim->srtCtrl), pNodeRec->scaleX, pNodeRec->scaleY);
        NNS_G2dSetSRTRotate((SRTControl *)(&pMCAnim->srtCtrl), pNodeRec->rotZ);
        NNS_G2dSetSRTTranslate(&pMCAnim->srtCtrl, pNodeRec->transX, pNodeRec->transY);
        break;
    }
    NNSi_G2dSetMCDataToMCInstanceImpl(&pMCAnim->mc, (const MultiCellData *)pMultiCellData, pMCAnim->totalFrames);
}

/*
 * PART 1 bank walker of docs/families/cluster_02064B68.h: publish `arg` at
 * +0x14, then step every record of the walk block at +0x34 (the same
 * struct Root NNSi_G2dTickMCInstance takes) through NNS_G2dSetCellAnimationSpeed -- kind 1 the flat
 * 0x5c-stride array for numCellAnims, else the 0x28-stride headers' first
 * word for numNodes.
 *
 * Two levers closed docs/notes/NNS_G2dSetMCAnimationSpeed.c.txt's last 11 bytes:
 *   - the index and base are PER-ARM locals (as in NNSi_G2dTickMCInstance);
 *   - the +0x14 store is written IN EACH ARM.  The front end hoists the
 *     common store above the branch but schedules it below the `cmp` and
 *     the index zero, which is the image; a single store before the `if`
 *     issues it above the `cmp` (11 out), and with it the volatile hdr
 *     the note needed is no longer necessary (the per-arm store is what
 *     keeps each arm's +0x34 load in its arm).
 * 1.1p1 gives 168 bytes / 24 out on the same C: pinned ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetMCAnimationSpeed.c \
 *       --func NNS_G2dSetMCAnimationSpeed --addr 0x02064B68 --arm --cc ../2.0/sp2
 */
void NNS_G2dSetMCAnimationSpeed(MultiCellAnim *pMCAnim, fx32 speed)
{
    if (pMCAnim->mc.mcType == 1) {
        u16 i;
        MCCellAnimation *cells = (MCCellAnimation *)pMCAnim->mc.pCellAnimInstasnces;
        pMCAnim->animCtrl.speed = speed;
        for (i = 0; i < pMCAnim->mc.pCurrentMultiCell->numCellAnim; i++) NNS_G2dSetCellAnimationSpeed(&cells[i].cellAnim, speed);
    } else {
        u16 i;
        Node *nodes = (Node *)pMCAnim->mc.pCellAnimInstasnces;
        pMCAnim->animCtrl.speed = speed;
        for (i = 0; i < pMCAnim->mc.pCurrentMultiCell->numNodes; i++) NNS_G2dSetCellAnimationSpeed((CellAnim *)nodes[i].pContent, speed);
    }
}

void NNSi_G2dSetMCInstanceCurrentFrameZero(MCInstance *pMCInst)
{
    u16 i;

    if (pMCInst->mcType == 1) {
        MCCellAnimation *cells = (MCCellAnimation *)pMCInst->pCellAnimInstasnces;

        for (i = 0; i < pMCInst->pCurrentMultiCell->numCellAnim; i++) {
            NNS_G2dSetCellAnimationCurrentFrame(&cells[i].cellAnim, 0);
        }
    } else {
        Node *nodes = (Node *)pMCInst->pCellAnimInstasnces;

        for (i = 0; i < pMCInst->pCurrentMultiCell->numNodes; i++) {
            NNS_G2dSetCellAnimationCurrentFrame((CellAnim *)nodes[i].pContent, 0);
        }
    }
}

void NNS_G2dRestartMCAnimation(MultiCellAnim *pMCAnim)
{
    u16 i;

    pMCAnim->totalFrames = 0;
    NNS_G2dSetAnimSequenceToMCAnimation(pMCAnim, pMCAnim->animCtrl.pAnimSequence);
    pMCAnim->animCtrl.bActive = 1;

    if (pMCAnim->mc.mcType == 1) {
        MCCellAnimation *cells = (MCCellAnimation *)pMCAnim->mc.pCellAnimInstasnces;

        for (i = 0; i < pMCAnim->mc.pCurrentMultiCell->numCellAnim; i++) {
            NNS_G2dRestartCellAnimation(&cells[i].cellAnim);
        }
    } else {
        Node *nodes = (Node *)pMCAnim->mc.pCellAnimInstasnces;

        for (i = 0; i < pMCAnim->mc.pCurrentMultiCell->numNodes; i++) {
            NNS_G2dRestartCellAnimation((CellAnim *)nodes[i].pContent);
        }
    }
}
