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
#include "cell_anim_types.h"

struct NNSG2dAnimController;
typedef unsigned short u16;

typedef unsigned int u32;

typedef int BOOL;

typedef int fx32;

typedef struct NNSG2dAnimFrameData {
    void *pContent;
    u16 frames;
    u16 pad16;
} NNSG2dAnimFrameData;

typedef struct NNSG2dAnimSequence {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    u32 animPlayMode;
    NNSG2dAnimFrameData *pAnmFrameArray;
} NNSG2dAnimSequence;

typedef struct NNSG2dAnimController {
    const NNSG2dAnimFrameData *pCurrent;
    const NNSG2dAnimFrameData *pActiveCurrent;
    BOOL bReverse;
    BOOL bActive;
    fx32 currentTime;
    fx32 speed;
    u32 overriddenPlayMode;
    const NNSG2dAnimSequence *pAnimSequence;
} NNSG2dAnimController;

typedef unsigned char  u8;

typedef signed int     s32;

extern BOOL NNS_G2dTickAnimCtrl(NNSG2dAnimController *pAnimCtrl, fx32 frames);
void NNS_G2dResetCellAnimation(NNSG2dAnimController *pAnimCtrl);
void NNS_G2dSetCellAnimationBank(struct CellAnim *anim, void *bank);
void NNS_G2dSetCellAnimationParam(struct CellAnim *anim, int p1, int p2, int p3);
void NNS_G2dSetCellAnimationParamTagged(struct CellAnim *anim, u32 a, u32 b, u16 tag);
s32 NNS_G2dIsCellAnimationBoundingBox(struct CellAnim *anim);


static inline BOOL IsForward_(const NNSG2dAnimController *pAnimCtrl)
{
    return (BOOL)((pAnimCtrl->speed > 0) ^ pAnimCtrl->bReverse);
}


static inline const NNSG2dAnimFrameData *GetFrameBegin_(const NNSG2dAnimSequence *pSeq)
{
    return pSeq->pAnmFrameArray + pSeq->loopStartFrameIdx;
}


static inline const NNSG2dAnimFrameData *GetFrameEnd_(const NNSG2dAnimSequence *pSeq)
{
    return pSeq->pAnmFrameArray + pSeq->numFrames;
}


void NNS_G2dResetCellAnimation(NNSG2dAnimController *pAnimCtrl)
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
void NNS_G2dSetCellAnimationBank(struct CellAnim *anim, void *bank)
{
    anim->bank = bank;
    NNS_G2dResetCellAnimation((struct NNSG2dAnimController *)anim);
}



void NNS_G2dSetCellAnimationParam(struct CellAnim *anim, int p1, int p2, int p3)
{
    anim->unk28 = p3;
    anim->unk24 = p2;
    anim->unk20 = p1;
    anim->unk2C = 0;
}



/*
 * *
 * The variant of NNS_G2dSetCellAnimationParam that pins the kind word at +0x20 to 2 and takes
 * the u16 tag as an argument instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationParamTagged.c  *       --func NNS_G2dSetCellAnimationParamTagged --addr 0x02063018 --cc 1.1p1
 */
void NNS_G2dSetCellAnimationParamTagged(struct CellAnim *anim, u32 a, u32 b, u16 tag)
{
    anim->unk20 = 2;
    anim->unk28 = b;
    anim->unk24 = a;
    anim->unk2C = tag;
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
s32 NNS_G2dIsCellAnimationBoundingBox(struct CellAnim *anim)
{
    u32 attr = anim->attrOverride;

    if (attr == 0) {
        attr = anim->bank->attr;
    }

    if (attr == 2 || attr == 4) {
        return 1;
    }

    return 0;
}
