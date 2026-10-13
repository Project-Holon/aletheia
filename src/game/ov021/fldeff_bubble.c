/*
 * file:     fldeff_bubble.c
 * unit:     yes
 * function: func_021D05D8, func_021D0610, func_021D0634, func_021D0648, func_021D06E0, func_021D072C, func_021D074C, func_021D0750, func_021D07D8, func_021D07FC, func_021D0824, func_021D08B0, func_021D08BC, func_021D08D8, func_021D0914
 * address:  0x021D05D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021D05D8 (lane L136, __FILE__ anchor fldeff_bubble.c at 021D0610 (d_021DE664); 021D05D8 registers callback table g_021DB968 (targets 072C/074C/0750/07D8) which sits after the bubble data g_021DB950..95C).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   abs_id_39      0x00000039  data
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_020477A4  0x020477A4  arm
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   d_021DB968     0x021DB968  data  ov021  a4
 *   d_021DE664     0x021DE664  data  ov021  a4
 *   func_02046F50  0x02046F50  arm
 *   d_021DB95C     0x021DB95C  data  a4
 *   d_021DB950     0x021DB950  data  ov021  a4
 *   d_021DB954     0x021DB954  data  ov021  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02047888  0x02047888  arm
 *   d_021DE628     0x021DE628  data  ov021  a4
 *   func_0204784C  0x0204784C  arm
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0201A954  0x0201A954  thumb
 *   func_02168AEC  0x02168AEC  thumb  ov010
 */
#include "../ov010/fldmmdl_types.h"
#include "field_effect_types.h"

typedef signed char s8;
typedef long long s64;

/* Opaque types of other files. */
typedef struct MtxFx33 { fx32 m[3][3]; } MtxFx33;
typedef struct ArcHandle ArcHandle;
typedef struct G3dResource G3dResource;                 /* layouts in arm9/g3d_system_types.h */
typedef struct G3dRender G3dRender;
typedef struct G3dAnime G3dAnime;
typedef struct G3dObject G3dObject;

/* Position, scale and rotation an object is drawn with. */
typedef struct G3dObjectStatus {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rotate;
} G3dObjectStatus;

/* Id of the bubble resources in the field effect system. */
#define FLDEFF_ID_BUBBLE 0x10

#define BUBBLE_RES_COUNT   3
#define BUBBLE_ANIME_COUNT 2
#define BUBBLE_MAX         6

/* Frames between two bubbles, and move state changes that start one more. */
#define BUBBLE_SPAWN_INTERVAL 0x78
#define BUBBLE_SPAWN_STEPS    5

/* Fixed-point step added to the age of a bubble each update (one frame). */
#define BUBBLE_AGE_STEP 0x1000

/* Rise of a new bubble above the model, and its distance along the facing. */
#define BUBBLE_OFFSET_Y            0x7000
#define BUBBLE_FACING_DISTANCE     (1 << 14)
#define BUBBLE_FACING_DISTANCE_ALT 0xE000

/* Bytes cleared when a bubble ends (sizeof(BubbleParticle)). */
#define BUBBLE_CLEAR_SIZE 20

/* Resources of the bubble effect (allocated 0x20 bytes by func_021D0610). */
typedef struct BubbleRes {
    FieldEffectSys *fieldEffect;               /* 0x00 */
    G3dResource *res[BUBBLE_RES_COUNT];        /* 0x04 model file and animation files */
    G3dRender *render;                         /* 0x10 */
    G3dAnime *anime[BUBBLE_ANIME_COUNT];       /* 0x14 */
    G3dObject *object;                         /* 0x1C */
} BubbleRes;

/* Start parameter of the effect. */
typedef struct BubbleStartParam {
    BubbleRes *res;
    Mmdl *mmdl;
} BubbleStartParam;

/* One bubble: active flag, age in animation frames (fixed point) and position. */
typedef struct BubbleParticle {
    u32 active;     /* 0x00 */
    fx32 age;       /* 0x04 */
    VecFx32 pos;    /* 0x08 */
} BubbleParticle;

/* Work of the bubble effect (0x84 bytes, the first word of the callback table). */
typedef struct BubbleWork {
    BubbleStartParam param;                /* 0x00 */
    u8 lastMoveState;                      /* 0x08 move state of the model at the last update */
    s8 moveCount;                          /* 0x09 changes of the move state since the last bubble */
    s8 idleTimer;                          /* 0x0A frames since the last bubble */
    u8 pad0B;
    BubbleParticle bubbles[BUBBLE_MAX];    /* 0x0C */
} BubbleWork;

extern void func_02082BCC(void *dst, u32 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *func_021ABE24(FieldEffectSys *fieldEffect);
extern G3dResource *func_02046E24(ArcHandle *arc, u32 fileId);
extern u32 func_02046F50(G3dResource *res, u32 kind);
extern int func_02046FF8(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern G3dRender *func_02047400(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *func_02047564(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *func_0204767C(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 func_020477A4(G3dObject *obj, u32 anmIdx);
extern void func_0204762C(G3dAnime *anime);
extern void func_02047738(G3dObject *obj);
extern void func_02047504(G3dRender *render);
extern int func_02047888(G3dObject *obj, int anmIdx, int *out);
extern u32 func_0204784C(G3dObject *obj, u16 anmIdx, s32 *frame);
extern int func_02047AC8(G3dObject *obj, G3dObjectStatus *status);
extern void *func_021ABEA0(FieldEffectSys *fieldEffect, u32 effectId);
extern void func_021ABFA8(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *func_021AC1AC(FieldEffectObj *effect);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *out);
extern int func_0216D3CC(Mmdl *mmdl);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern int func_0216D55C(Mmdl *mmdl, int bits);
extern int func_021641E8(int dir);
extern int func_021641F8(int dir);
extern void func_0219E784(Mmdl *mmdl, u32 dir, s16 *out);
extern void func_0207CDB8(s16 *in, s16 *out);

void func_021D05D8(Mmdl *mmdl, FieldEffectSys *fieldEffect);
BubbleRes *func_021D0610(FieldEffectSys *fieldEffect, u32 heapId);
void func_021D0634(FieldEffectSys *fieldEffect, BubbleRes *res);
void func_021D0648(BubbleRes *res);
void func_021D06E0(BubbleRes *res);
void func_021D072C(FieldEffectObj *effect, BubbleWork *work);
void func_021D074C(void);
void func_021D0750(FieldEffectObj *effect, BubbleWork *work);
void func_021D07D8(FieldEffectObj *effect, BubbleWork *work);
BubbleParticle *func_021D07FC(BubbleWork *work);
void func_021D0824(BubbleParticle *bubble, Mmdl *mmdl);
void func_021D08B0(BubbleParticle *bubble);
void func_021D08BC(BubbleParticle *bubble, int endFrame);
void func_021D08D8(BubbleParticle *bubble, G3dObject *object);
int func_021D0914(Mmdl *mmdl, s16 *dirVec);

extern const FieldEffectObjFuncs d_021DB968;           /* bubble effect callbacks */
extern char d_021DE664[];                              /* source file name for the heap allocator */
extern int d_021DB95C[BUBBLE_RES_COUNT];               /* file ids of the model and the animations */
extern int d_021DB950;                                 /* index in res of the model */
extern int d_021DB954[BUBBLE_ANIME_COUNT];             /* indices in res of the animations */
extern G3dObjectStatus d_021DE628;                     /* draw status shared by all bubbles */

/* ------------------------------------------------------------------ */
/* fldeff_bubble.c                                                     */
/* ------------------------------------------------------------------ */

/* Starts the effect at the model position. */
void func_021D05D8(Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    BubbleStartParam param;
    VecFx32 pos;

    param.res = func_021ABEA0(fieldEffect, FLDEFF_ID_BUBBLE);
    param.mmdl = mmdl;
    func_0216D88C(mmdl, &pos);
    func_021ABFA8(fieldEffect, &d_021DB968, &pos, 0, &param, 0);
}

/* Loads the resources of the bubble effect. */
BubbleRes *func_021D0610(FieldEffectSys *fieldEffect, u32 heapId)
{
    BubbleRes *res = func_02030734(heapId, 0x20, 1, d_021DE664, 0xd5);

    res->fieldEffect = fieldEffect;
    func_021D0648(res);
    return res;
}

void func_021D0634(FieldEffectSys *fieldEffect, BubbleRes *res)
{
    func_021D06E0(res);
    func_020307B0(res);
}

void func_021D0648(BubbleRes *res)
{
    ArcHandle *arc;
    int i;

    arc = func_021ABE24(res->fieldEffect);
    for (i = 0; i < BUBBLE_RES_COUNT; i++) {
        res->res[i] = func_02046E24(arc, d_021DB95C[i]);
        if (func_02046F50(res->res[i], 2)) {
            func_02046FF8(res->res[i]);
        }
    }
    res->render = func_02047400(res->res[d_021DB950], 0, res->res[d_021DB950]);
    for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
        res->anime[i] = func_02047564(res->render, res->res[d_021DB954[i]], 0);
    }
    res->object = func_0204767C(res->render, res->anime, BUBBLE_ANIME_COUNT);
    for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
        func_020477A4(res->object, (u16)i);
    }
}

void func_021D06E0(BubbleRes *res)
{
    int i;

    func_02047738(res->object);
    for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
        func_0204762C(res->anime[i]);
    }
    func_02047504(res->render);
    for (i = 0; i < BUBBLE_RES_COUNT; i++) {
        if (func_02046F50(res->res[i], 2)) {
            func_020470D0(res->res[i]);
        }
        func_02046EFC(res->res[i]);
    }
}

/* Effect init. */
void func_021D072C(FieldEffectObj *effect, BubbleWork *work)
{
    BubbleStartParam *param = func_021AC1AC(effect);

    work->param = *param;
    work->idleTimer = BUBBLE_SPAWN_INTERVAL;
    work->lastMoveState = func_0216D3CC(work->param.mmdl);
    work->moveCount = BUBBLE_SPAWN_STEPS;
}

/* Effect exit (nothing to release). */
void func_021D074C(void) {}

/*
 * Effect update: starts a bubble every BUBBLE_SPAWN_INTERVAL frames and every
 * BUBBLE_SPAWN_STEPS changes of the move state, then ages all bubbles.
 *
 * func_02047888 (arm9 ARM leaf) is filed as src/matched/arm9/func_02047888.c
 * to give the witness.  EXACT*: the listing extent includes 2 pad bytes.
 */
void func_021D0750(FieldEffectObj *effect, BubbleWork *work)
{
    int endFrame;
    int i;
    BubbleParticle *bubble;

    work->idleTimer++;
    if (work->idleTimer >= BUBBLE_SPAWN_INTERVAL) {
        bubble = func_021D07FC(work);
        if (bubble) {
            func_021D0824(bubble, work->param.mmdl);
        }
        work->idleTimer = 0;
    }
    if (work->lastMoveState != func_0216D3CC(work->param.mmdl)) {
        work->moveCount++;
        if (work->moveCount >= BUBBLE_SPAWN_STEPS) {
            bubble = func_021D07FC(work);
            if (bubble) {
                func_021D0824(bubble, work->param.mmdl);
            }
            work->moveCount = 0;
        }
        work->lastMoveState = func_0216D3CC(work->param.mmdl);
    }
    func_02047888(work->param.res->object, 0, &endFrame);
    for (i = 0; i < BUBBLE_MAX; i++) {
        func_021D08BC(&work->bubbles[i], endFrame);
    }
}

/* Effect draw. */
void func_021D07D8(FieldEffectObj *effect, BubbleWork *work)
{
    int i;

    for (i = 0; i < BUBBLE_MAX; i++) {
        func_021D08D8(&work->bubbles[i], work->param.res->object);
    }
}

/* Returns an unused bubble slot, or 0. */
BubbleParticle *func_021D07FC(BubbleWork *work)
{
    int i;

    for (i = 0; i < BUBBLE_MAX; i++) {
        if (work->bubbles[i].active == 0) {
            return &work->bubbles[i];
        }
    }
    return 0;
}

/* Starts a bubble above the model, in front of its facing. */
void func_021D0824(BubbleParticle *bubble, Mmdl *mmdl)
{
    s16 dirVec[3];
    int distance;

    bubble->active = 1;
    bubble->age = 0;
    func_0216D88C(mmdl, &bubble->pos);
    if (func_021D0914(mmdl, dirVec) == 0) {
        distance = BUBBLE_FACING_DISTANCE_ALT;
    } else {
        distance = BUBBLE_FACING_DISTANCE;
    }
    bubble->pos.y += BUBBLE_OFFSET_Y;
    bubble->pos.x += (int)(((s64)dirVec[0] * distance + 0x800) >> 12);
    bubble->pos.z += (int)(((s64)dirVec[2] * distance + 0x800) >> 12);
}

/*
 * Tail-call thunk: ends a bubble by clearing its BUBBLE_CLEAR_SIZE bytes.
 *
 * Addresses are Black-image addresses.
 */
void func_021D08B0(BubbleParticle *bubble)
{
    func_02082BCC(bubble, 0, BUBBLE_CLEAR_SIZE);
}

/* Ages a bubble and ends it when the animation is over. */
void func_021D08BC(BubbleParticle *bubble, int endFrame)
{
    if (bubble->active != 0) {
        bubble->age += BUBBLE_AGE_STEP;
        if (bubble->age > endFrame) {
            func_021D08B0(bubble);
        }
    }
}

/* Draws a bubble at its position with the animations at its age. */
void func_021D08D8(BubbleParticle *bubble, G3dObject *object)
{
    int i;

    if (bubble->active != 0) {
        d_021DE628.trans = bubble->pos;
        for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
            func_0204784C(object, (u16)i, &bubble->age);
        }
        func_02047AC8(object, &d_021DE628);
    }
}

/* Writes the unit vector of the facing of the model; returns the facing. */
int func_021D0914(Mmdl *mmdl, s16 *dirVec)
{
    int facing;

    facing = func_0216D5F8(mmdl);
    if (func_0216D55C(mmdl, 0x1000 * 2) == 0) {
        dirVec[1] = 0;
        dirVec[0] = func_021641E8(facing);
        dirVec[2] = func_021641F8(facing);
        dirVec[0] = dirVec[0] << 16;
        dirVec[2] = dirVec[2] << 16;
    } else {
        func_0219E784(mmdl, facing, dirVec);
        dirVec[1] = 0;
    }
    func_0207CDB8(dirVec, dirVec);
    return facing;
}
