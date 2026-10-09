/*
 * file:     unit_02062F90.c
 * function: func_02062F90
 * address:  0x02062F90
 * packet:   pkt_02062F90
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02062D4C  0x02062D4C  arm
 *
 * NitroSystem g2d animation controller reset: pCurrent goes to the loop
 * start frame when playing forward ((speed > 0) ^ bReverse) and to the last
 * frame otherwise; pActiveCurrent follows, currentTime clears, then a tail
 * call into func_02062D4C.  Written in the library's shape (controller and
 * sequence structs, forward test and frame-begin/end as inlines).  The kept
 * branches tell (docs/FRONTEND-PINS.md): the image branches over the two
 * three-instruction arms at 0x02062FB0..0x02062FCC where 1.1p1 predicates
 * both (88 bytes).  Under ../2.0/sp2 the same C is 92 bytes + pool,
 * 0 mismatches.
 */

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

extern BOOL func_02062D4C(NNSG2dAnimController *pAnimCtrl, fx32 frames);

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

void func_02062F90(NNSG2dAnimController *pAnimCtrl)
{
    if (IsForward_(pAnimCtrl)) {
        pAnimCtrl->pCurrent = GetFrameBegin_(pAnimCtrl->pAnimSequence);
    } else {
        pAnimCtrl->pCurrent = GetFrameEnd_(pAnimCtrl->pAnimSequence) - 1;
    }
    pAnimCtrl->pActiveCurrent = pAnimCtrl->pCurrent;
    pAnimCtrl->currentTime = 0;
    func_02062D4C(pAnimCtrl, 0);
}
