/*
 * file:     unit_02062BAC_p03.c
 * unit:     yes
 * function: func_02062D4C
 * address:  0x02062D4C
 * packet:   pkt_02062D4C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * The cell-animation controller tick (NitroSystem g2d NNS_G2dTickAnimCtrl
 * shape): if active, advance currentTime by |FX_Mul(speed, frames)| (the
 * callee at 0x02091588 is abs), then while the controller is active and the
 * time has passed the current frame's length, step the frame pointer in the
 * play direction, hand the edge case to func_02062BF4, latch the last frame
 * with a non-zero length, and fire the +0x20 callback functor (type 2: on one
 * frame index, type 3: every frame).  Returns whether a frame changed.
 *
 * Struct layout agrees with src/matched/func_02062BF4.c (the edge handler),
 * func_02062D08.c and sub_02062F1C.c (the u16 frame index).
 *
 * Levers, each measured:
 *   - ../2.0/sp2: every per-inline 0/1 constant hoisted to its own callee-
 *     saved register (r8/r7, r6/r5, r4/fp) and the ten-register push.
 *     dsi/1.1p1 is 408 bytes and pushes six.
 *   - the loop test is `if (active && time >= len) return 1; return 0;`
 *     (value materialised with movge #1 / bge / mov #0).
 *   - the edge test binds only `cur = p->pCurrent` before the direction
 *     test; the sequence and frame array are read inside each arm (the
 *     compiler hoists them after the teq).  A local for the array too moves
 *     the sequence load ahead of the direction test (16 bytes out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02062D4C.c \
 *       --func func_02062D4C --addr 0x02062D4C --arm --cc ../2.0/sp2
 *   EXACT, 436 bytes, 2 of 2 relocation sites resolved (sp2p2 also EXACT).
 *
 * symbols:
 *   func_02091588  0x02091588  arm
 *   func_02062BF4  0x02062BF4  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef long long s64;
typedef int BOOL;

typedef struct {
    void *pContent;
    u16 frames;
    u16 pad;
} Frame;

typedef struct {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    u32 playMode;
    Frame *pFrameArray;
} Seq;

typedef struct {
    u32 type;
    u32 param;
    void (*pFunc)(u32 param, u32 idx);
    u16 frameIdx;
} Functor;

typedef struct {
    Frame *pCurrent;
    Frame *pActiveCurrent;
    BOOL bReverse;
    BOOL bActive;
    s32 currentTime;
    s32 speed;
    u32 overriddenPlayMode;
    Seq *pAnimSequence;
    Functor callback;
} Ctrl;

extern s32 func_02091588(s32 x);
struct Slider;
extern void func_02062BF4(struct Slider *s);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline BOOL IsForward_(const Ctrl *p)
{
    return (BOOL)((p->speed > 0) ^ p->bReverse);
}

static inline BOOL IsReachEndEdge_(const Frame *cur, const Frame *arr, u16 n)
{
    return (BOOL)(cur >= arr + n);
}

static inline BOOL IsReachStartEdge_(const Frame *cur, const Frame *arr, u16 idx)
{
    return (BOOL)(cur <= arr + idx - 1);
}

static inline BOOL IsReachedEdge_(const Ctrl *p)
{
    const Frame *cur = p->pCurrent;
    if (IsForward_(p))
        return IsReachEndEdge_(cur, p->pAnimSequence->pFrameArray, p->pAnimSequence->numFrames);
    else
        return IsReachStartEdge_(cur, p->pAnimSequence->pFrameArray, p->pAnimSequence->loopStartFrameIdx);
}

static inline u16 GetCurrentFrameIdx_(const Ctrl *p)
{
    return (u16)(((u32)p->pCurrent - (u32)p->pAnimSequence->pFrameArray) >> 3);
}

static inline BOOL ShouldAdvance_(const Ctrl *p)
{
    if (p->bActive && p->currentTime >= (s32)(p->pCurrent->frames << 12))
        return 1;
    return 0;
}

static inline void CallbackFuncHandling_(const Functor *f, u16 idx)
{
    switch (f->type) {
    case 2:
        if (idx == f->frameIdx)
            f->pFunc(f->param, idx);
        break;
    case 3:
        f->pFunc(f->param, idx);
        break;
    }
}

/*
 * The cell-animation controller tick (NitroSystem g2d NNS_G2dTickAnimCtrl
 * shape): if active, advance currentTime by |FX_Mul(speed, frames)| (the
 * callee at 0x02091588 is abs), then while the controller is active and the
 * time has passed the current frame's length, step the frame pointer in the
 * play direction, hand the edge case to func_02062BF4, latch the last frame
 * with a non-zero length, and fire the +0x20 callback functor (type 2: on one
 * frame index, type 3: every frame).  Returns whether a frame changed.
 *
 * Struct layout agrees with src/matched/func_02062BF4.c (the edge handler),
 * func_02062D08.c and sub_02062F1C.c (the u16 frame index).
 *
 * Levers, each measured:
 *   - ../2.0/sp2: every per-inline 0/1 constant hoisted to its own callee-
 *     saved register (r8/r7, r6/r5, r4/fp) and the ten-register push.
 *     dsi/1.1p1 is 408 bytes and pushes six.
 *   - the loop test is `if (active && time >= len) return 1; return 0;`
 *     (value materialised with movge #1 / bge / mov #0).
 *   - the edge test binds only `cur = p->pCurrent` before the direction
 *     test; the sequence and frame array are read inside each arm (the
 *     compiler hoists them after the teq).  A local for the array too moves
 *     the sequence load ahead of the direction test (16 bytes out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02062D4C.c \
 *       --func func_02062D4C --addr 0x02062D4C --arm --cc ../2.0/sp2
 *   EXACT, 436 bytes, 2 of 2 relocation sites resolved (sp2p2 also EXACT).
 */
BOOL func_02062D4C(Ctrl *p, s32 frames)
{
    BOOL bChanged = 0;

    if (p->bActive != 1)
        return 0;
    p->currentTime += func_02091588(FX_Mul(p->speed, frames));
    while (ShouldAdvance_(p)) {
        bChanged = 1;
        p->currentTime -= p->pCurrent->frames << 12;
        if (IsForward_(p))
            p->pCurrent++;
        else
            p->pCurrent--;
        if (IsReachedEdge_(p))
            func_02062BF4((struct Slider *)p);
        if (p->pCurrent->frames != 0)
            p->pActiveCurrent = p->pCurrent;
        if (p->callback.type != 0)
            CallbackFuncHandling_(&p->callback, GetCurrentFrameIdx_(p));
    }
    return bChanged;
}
