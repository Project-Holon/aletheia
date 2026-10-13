/*
 * file:     fldeff_bubble.c
 * unit:     yes
 * function: FLDEFF_BUBBLE_Start, FLDEFF_BUBBLE_CreateRes, FLDEFF_BUBBLE_DeleteRes, FLDEFF_BUBBLE_LoadResources, FLDEFF_BUBBLE_FreeResources, FLDEFF_BUBBLE_Init, FLDEFF_BUBBLE_Exit, FLDEFF_BUBBLE_Update, FLDEFF_BUBBLE_Draw, FLDEFF_BUBBLE_FindFreeBubble, FLDEFF_BUBBLE_SpawnBubble, FLDEFF_BUBBLE_ClearBubble, FLDEFF_BUBBLE_UpdateBubble, FLDEFF_BUBBLE_DrawBubble, FLDEFF_BUBBLE_GetFacingVector
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   abs_id_39      0x00000039  data
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   d_021DB968     0x021DB968  data  ov021  a4
 *   d_021DE664     0x021DE664  data  ov021  a4
 *   G3D_SYSTEM_CheckResourceType  0x02046F50  arm
 *   d_021DB95C     0x021DB95C  data  a4
 *   d_021DB950     0x021DB950  data  ov021  a4
 *   d_021DB954     0x021DB954  data  ov021  a4
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   G3D_SYSTEM_GetObjectAnimeFrameMax  0x02047888  arm
 *   d_021DE628     0x021DE628  data  ov021  a4
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   FLD_BTL_INST_TOOL_LookupKeyValue  0x02168AEC  thumb  ov010
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

/* Resources of the bubble effect (allocated 0x20 bytes by FLDEFF_BUBBLE_CreateRes). */
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

extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);
extern u32 G3D_SYSTEM_CheckResourceType(G3dResource *res, u32 kind);
extern int G3D_SYSTEM_TransVramTexture(G3dResource *res);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_GetObjectAnimeFrameMax(G3dObject *obj, int anmIdx, int *out);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 anmIdx, s32 *frame);
extern int G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);
extern void *FIELD_EFFECT_GetResource(FieldEffectSys *fieldEffect, u32 effectId);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *out);
extern int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern int FLDMMDL_CheckStatusBit(Mmdl *mmdl, int bits);
extern int FLDMMDL_MOVE_GetDirAddGridX(int dir);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int dir);
extern void FLDMMDL_RAIL_GetDrawOffsetByDir(Mmdl *mmdl, u32 dir, s16 *out);
extern void VEC_Fx16Normalize(s16 *in, s16 *out);

void FLDEFF_BUBBLE_Start(Mmdl *mmdl, FieldEffectSys *fieldEffect);
BubbleRes *FLDEFF_BUBBLE_CreateRes(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_BUBBLE_DeleteRes(FieldEffectSys *fieldEffect, BubbleRes *res);
void FLDEFF_BUBBLE_LoadResources(BubbleRes *res);
void FLDEFF_BUBBLE_FreeResources(BubbleRes *res);
void FLDEFF_BUBBLE_Init(FieldEffectObj *effect, BubbleWork *work);
void FLDEFF_BUBBLE_Exit(void);
void FLDEFF_BUBBLE_Update(FieldEffectObj *effect, BubbleWork *work);
void FLDEFF_BUBBLE_Draw(FieldEffectObj *effect, BubbleWork *work);
BubbleParticle *FLDEFF_BUBBLE_FindFreeBubble(BubbleWork *work);
void FLDEFF_BUBBLE_SpawnBubble(BubbleParticle *bubble, Mmdl *mmdl);
void FLDEFF_BUBBLE_ClearBubble(BubbleParticle *bubble);
void FLDEFF_BUBBLE_UpdateBubble(BubbleParticle *bubble, int endFrame);
void FLDEFF_BUBBLE_DrawBubble(BubbleParticle *bubble, G3dObject *object);
int FLDEFF_BUBBLE_GetFacingVector(Mmdl *mmdl, s16 *dirVec);

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
void FLDEFF_BUBBLE_Start(Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    BubbleStartParam param;
    VecFx32 pos;

    param.res = FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_BUBBLE);
    param.mmdl = mmdl;
    FLDMMDL_GetPos(mmdl, &pos);
    FIELD_EFFECT_AddObject(fieldEffect, &d_021DB968, &pos, 0, &param, 0);
}

/* Loads the resources of the bubble effect. */
BubbleRes *FLDEFF_BUBBLE_CreateRes(FieldEffectSys *fieldEffect, u32 heapId)
{
    BubbleRes *res = func_02030734(heapId, 0x20, 1, d_021DE664, 0xd5);

    res->fieldEffect = fieldEffect;
    FLDEFF_BUBBLE_LoadResources(res);
    return res;
}

void FLDEFF_BUBBLE_DeleteRes(FieldEffectSys *fieldEffect, BubbleRes *res)
{
    FLDEFF_BUBBLE_FreeResources(res);
    func_020307B0(res);
}

void FLDEFF_BUBBLE_LoadResources(BubbleRes *res)
{
    ArcHandle *arc;
    int i;

    arc = FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    for (i = 0; i < BUBBLE_RES_COUNT; i++) {
        res->res[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, d_021DB95C[i]);
        if (G3D_SYSTEM_CheckResourceType(res->res[i], 2)) {
            G3D_SYSTEM_TransVramTexture(res->res[i]);
        }
    }
    res->render = G3D_SYSTEM_CreateRender(res->res[d_021DB950], 0, res->res[d_021DB950]);
    for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
        res->anime[i] = G3D_SYSTEM_CreateAnime(res->render, res->res[d_021DB954[i]], 0);
    }
    res->object = G3D_SYSTEM_CreateObject(res->render, res->anime, BUBBLE_ANIME_COUNT);
    for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
        G3D_SYSTEM_EnableObjectAnime(res->object, (u16)i);
    }
}

void FLDEFF_BUBBLE_FreeResources(BubbleRes *res)
{
    int i;

    G3D_SYSTEM_DeleteObject(res->object);
    for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
        G3D_SYSTEM_DeleteAnime(res->anime[i]);
    }
    G3D_SYSTEM_DeleteRender(res->render);
    for (i = 0; i < BUBBLE_RES_COUNT; i++) {
        if (G3D_SYSTEM_CheckResourceType(res->res[i], 2)) {
            G3D_SYSTEM_FreeVramTexture(res->res[i]);
        }
        func_02046EFC(res->res[i]);
    }
}

/* Effect init. */
void FLDEFF_BUBBLE_Init(FieldEffectObj *effect, BubbleWork *work)
{
    BubbleStartParam *param = FIELD_EFFECT_GetObjectParam(effect);

    work->param = *param;
    work->idleTimer = BUBBLE_SPAWN_INTERVAL;
    work->lastMoveState = FLDMMDL_CheckPossibleAcmd(work->param.mmdl);
    work->moveCount = BUBBLE_SPAWN_STEPS;
}

/* Effect exit (nothing to release). */
void FLDEFF_BUBBLE_Exit(void) {}

/*
 * Effect update: starts a bubble every BUBBLE_SPAWN_INTERVAL frames and every
 * BUBBLE_SPAWN_STEPS changes of the move state, then ages all bubbles.
 *
 * G3D_SYSTEM_GetObjectAnimeFrameMax (arm9 ARM leaf) is filed as src/matched/arm9/G3D_SYSTEM_GetObjectAnimeFrameMax.c
 * to give the witness.  EXACT*: the listing extent includes 2 pad bytes.
 */
void FLDEFF_BUBBLE_Update(FieldEffectObj *effect, BubbleWork *work)
{
    int endFrame;
    int i;
    BubbleParticle *bubble;

    work->idleTimer++;
    if (work->idleTimer >= BUBBLE_SPAWN_INTERVAL) {
        bubble = FLDEFF_BUBBLE_FindFreeBubble(work);
        if (bubble) {
            FLDEFF_BUBBLE_SpawnBubble(bubble, work->param.mmdl);
        }
        work->idleTimer = 0;
    }
    if (work->lastMoveState != FLDMMDL_CheckPossibleAcmd(work->param.mmdl)) {
        work->moveCount++;
        if (work->moveCount >= BUBBLE_SPAWN_STEPS) {
            bubble = FLDEFF_BUBBLE_FindFreeBubble(work);
            if (bubble) {
                FLDEFF_BUBBLE_SpawnBubble(bubble, work->param.mmdl);
            }
            work->moveCount = 0;
        }
        work->lastMoveState = FLDMMDL_CheckPossibleAcmd(work->param.mmdl);
    }
    G3D_SYSTEM_GetObjectAnimeFrameMax(work->param.res->object, 0, &endFrame);
    for (i = 0; i < BUBBLE_MAX; i++) {
        FLDEFF_BUBBLE_UpdateBubble(&work->bubbles[i], endFrame);
    }
}

/* Effect draw. */
void FLDEFF_BUBBLE_Draw(FieldEffectObj *effect, BubbleWork *work)
{
    int i;

    for (i = 0; i < BUBBLE_MAX; i++) {
        FLDEFF_BUBBLE_DrawBubble(&work->bubbles[i], work->param.res->object);
    }
}

/* Returns an unused bubble slot, or 0. */
BubbleParticle *FLDEFF_BUBBLE_FindFreeBubble(BubbleWork *work)
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
void FLDEFF_BUBBLE_SpawnBubble(BubbleParticle *bubble, Mmdl *mmdl)
{
    s16 dirVec[3];
    int distance;

    bubble->active = 1;
    bubble->age = 0;
    FLDMMDL_GetPos(mmdl, &bubble->pos);
    if (FLDEFF_BUBBLE_GetFacingVector(mmdl, dirVec) == 0) {
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
void FLDEFF_BUBBLE_ClearBubble(BubbleParticle *bubble)
{
    MI_CpuFill8(bubble, 0, BUBBLE_CLEAR_SIZE);
}

/* Ages a bubble and ends it when the animation is over. */
void FLDEFF_BUBBLE_UpdateBubble(BubbleParticle *bubble, int endFrame)
{
    if (bubble->active != 0) {
        bubble->age += BUBBLE_AGE_STEP;
        if (bubble->age > endFrame) {
            FLDEFF_BUBBLE_ClearBubble(bubble);
        }
    }
}

/* Draws a bubble at its position with the animations at its age. */
void FLDEFF_BUBBLE_DrawBubble(BubbleParticle *bubble, G3dObject *object)
{
    int i;

    if (bubble->active != 0) {
        d_021DE628.trans = bubble->pos;
        for (i = 0; i < BUBBLE_ANIME_COUNT; i++) {
            G3D_SYSTEM_SetObjectAnimeFrame(object, (u16)i, &bubble->age);
        }
        G3D_SYSTEM_DrawObjectCulling(object, &d_021DE628);
    }
}

/* Writes the unit vector of the facing of the model; returns the facing. */
int FLDEFF_BUBBLE_GetFacingVector(Mmdl *mmdl, s16 *dirVec)
{
    int facing;

    facing = FLDMMDL_GetDirDisp(mmdl);
    if (FLDMMDL_CheckStatusBit(mmdl, 0x1000 * 2) == 0) {
        dirVec[1] = 0;
        dirVec[0] = FLDMMDL_MOVE_GetDirAddGridX(facing);
        dirVec[2] = FLDMMDL_MOVE_GetDirAddGridZ(facing);
        dirVec[0] = dirVec[0] << 16;
        dirVec[2] = dirVec[2] << 16;
    } else {
        FLDMMDL_RAIL_GetDrawOffsetByDir(mmdl, facing, dirVec);
        dirVec[1] = 0;
    }
    VEC_Fx16Normalize(dirVec, dirVec);
    return facing;
}
