/*
 * file:     nns_g2d_cell_animation.c
 * unit:     yes
 * function: NNS_G2dResetCellAnimation, NNS_G2dSetCellAnimationBank, NNS_G2dSetCellAnimationParam, NNS_G2dSetCellAnimationParamTagged, NNS_G2dIsCellAnimationBoundingBox
 * address:  0x02062F90
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * NitroSystem g2d animation controller reset: pCurrent goes to the loop
 * start frame when playing forward ((speed > 0) ^ bReverse) and to the last
 * frame otherwise; pActiveCurrent follows, currentTime clears, then a tail
 * call into NNS_G2dTickAnimCtrl.  Written in the library's shape (controller and
 * sequence structs, forward test and frame-begin/end as inlines).  The kept
 * branches tell (docs/FRONTEND-PINS.md): the image branches over the two
 * three-instruction arms at 0x02062FB0..0x02062FCC where 1.1p1 predicates
 * both (88 bytes).  Under ../2.0/sp2 the same C is 92 bytes + pool,
 * 0 mismatches.
 *
 * symbols:
 *   NNS_G2dTickAnimCtrl  0x02062D4C  arm
 */
#include "nns_g2d_anim_types.h"

#include "../types.h"



#include "nns_g2d_load.h"
void NNS_G2dResetCellAnimation(AnimCtrl *pAnimCtrl);
void NNS_G2dSetCellAnimationBank(CellAnim *anim, void *bank);
void NNS_G2dSetCellAnimationParam(CellAnim *anim, int type, void *param, AnimCallBackFunc func);
void NNS_G2dSetCellAnimationParamTagged(CellAnim *anim, void *param, AnimCallBackFunc func, u16 frameIdx);
s32 NNS_G2dIsCellAnimationBoundingBox(CellAnim *anim);

static inline BOOL IsForward_(const AnimCtrl *pAnimCtrl)
{
    return (BOOL)((pAnimCtrl->speed > 0) ^ pAnimCtrl->bReverse);
}

static inline const AnimFrameData *GetFrameBegin_(const AnimSequenceData *pSeq)
{
    return pSeq->pAnmFrameArray + pSeq->loopStartFrameIdx;
}

static inline const AnimFrameData *GetFrameEnd_(const AnimSequenceData *pSeq)
{
    return pSeq->pAnmFrameArray + pSeq->numFrames;
}

void NNS_G2dResetCellAnimation(AnimCtrl *pAnimCtrl)
{
    if (IsForward_(pAnimCtrl)) {
        pAnimCtrl->pCurrent = GetFrameBegin_(pAnimCtrl->pAnimSequence);
    } else {
        pAnimCtrl->pCurrent = GetFrameEnd_(pAnimCtrl->pAnimSequence) - 1;
    }
    pAnimCtrl->pActiveCurrent = pAnimCtrl->pCurrent;
    pAnimCtrl->currentTime = 0;
    NNS_G2dTickAnimCtrl(pAnimCtrl, 0);
}

/*
 * Binds a cell data bank to a cell animation and restarts it. The bind is a
 * single store followed by a tail call, so it costs a pool word and a `bx`
 * rather than a branch (one section per function, no displacement branch).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationBank.c  *       --func NNS_G2dSetCellAnimationBank --addr 0x02062FF0 --cc 1.1p1
 */
void NNS_G2dSetCellAnimationBank(CellAnim *anim, void *bank)
{
    anim->animCtrl.pAnimSequence = bank;
    NNS_G2dResetCellAnimation(&anim->animCtrl);
}

void NNS_G2dSetCellAnimationParam(CellAnim *anim, int type, void *param, AnimCallBackFunc func)
{
    anim->animCtrl.callBack.pFunc = func;
    anim->animCtrl.callBack.param = param;
    anim->animCtrl.callBack.type = type;
    anim->animCtrl.callBack.frameIdx = 0;
}

/*
 * *
 * The variant of NNS_G2dSetCellAnimationParam that pins the kind word at +0x20 to 2 and takes
 * the u16 tag as an argument instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationParamTagged.c  *       --func NNS_G2dSetCellAnimationParamTagged --addr 0x02063018 --cc 1.1p1
 */
void NNS_G2dSetCellAnimationParamTagged(CellAnim *anim, void *param, AnimCallBackFunc func, u16 frameIdx)
{
    anim->animCtrl.callBack.type = 2;
    anim->animCtrl.callBack.pFunc = func;
    anim->animCtrl.callBack.param = param;
    anim->animCtrl.callBack.frameIdx = frameIdx;
}

/*
 * *
 * Returns true when the cell this animation is currently on is one of the two
 * "has a bounding box" cell kinds (attribute 2 or 4). The attribute comes from
 * the animation's own override word at +0x18 when that is non-zero, otherwise
 * from the bound cell data bank's +0x08 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dIsCellAnimationBoundingBox.c  *       --func NNS_G2dIsCellAnimationBoundingBox --addr 0x02063030 --cc 1.1p1
 */
s32 NNS_G2dIsCellAnimationBoundingBox(CellAnim *anim)
{
    u32 attr = anim->animCtrl.overriddenPlayMode;

    if (attr == 0) {
        attr = anim->animCtrl.pAnimSequence->playMode;
    }

    if (attr == 2 || attr == 4) {
        return 1;
    }

    return 0;
}
