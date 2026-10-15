/*
 * file:     fldeff_d06denki.c
 * unit:     yes
 * function: FLDEFF_D06DENKI_Create, FLDEFF_D06DENKI_Delete, FLDEFF_D06DENKI_LoadResources, FLDEFF_D06DENKI_FreeResources, FLDEFF_D06DENKI_StartSpark, FLDEFF_D06DENKI_SparkInit, FLDEFF_D06DENKI_SparkExit, FLDEFF_D06DENKI_SparkUpdate, FLDEFF_D06DENKI_SparkDraw, FLDEFF_D06DENKI_StartFollow, FLDEFF_D06DENKI_FollowFreezeLoop, FLDEFF_D06DENKI_FollowStartEnding, FLDEFF_D06DENKI_FollowIsEnded, FLDEFF_D06DENKI_FollowInit, FLDEFF_D06DENKI_FollowExit, FLDEFF_D06DENKI_FollowUpdate, FLDEFF_D06DENKI_FollowDraw, FLDEFF_D06DENKI_StartPulse, FLDEFF_D06DENKI_PulseTrigger, FLDEFF_D06DENKI_PulseInit, FLDEFF_D06DENKI_PulseExit, FLDEFF_D06DENKI_PulseUpdate, FLDEFF_D06DENKI_PulseDraw
 * address:  0x021C8E68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C8E68: fldeff_d06denki.c __FILE__ anchor at 0x021C8E68.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   sFldeffD06DenkiFileName  0x021DE544  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   sD06DenkiModelFiles     0x021DAB6C  data  a4
 *   sD06DenkiAnimeFiles     0x021DAB7C  data  a4
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   sD06DenkiSparkFuncs  0x021DABA4  data  a4
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   sD06DenkiSparkDrawStatus     0x021DABCC  data  a4
 *   sD06DenkiFollowFuncs  0x021DABB8  data  ov021  a4
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 *   FLDMMDL_CheckStatusBitUse  0x0216DA30  thumb  ov010
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   sD06DenkiFollowDrawStatus     0x021DAC08  data  a4
 *   sD06DenkiPulseFuncs  0x021DAB90  data  ov021  a4
 *   sD06DenkiPulseDrawStatus  0x021DAC44  data  ov021  a4
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct VecFx32 { fx32 x, y, z; } VecFx32;
typedef struct MtxFx33 { fx32 m[3][3]; } MtxFx33;

/* Opaque types of other files. */
typedef struct ArcHandle ArcHandle;
typedef struct FieldEffectSys FieldEffectSys;           /* field effect system (field_effect.c) */
typedef struct FieldEffectObj FieldEffectObj;           /* one running effect (field_effect.c) */
typedef struct FieldEffectObjFuncs FieldEffectObjFuncs; /* callback table: unused, init, exit, update, draw */
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

/* Id of the D06 electric resources in the field effect system. */
#define FLDEFF_ID_D06DENKI 0xb

#define D06DENKI_MODEL_COUNT 4
#define D06DENKI_ANIME_COUNT 5

/* Sound effect of the spark. */
#define SE_D06DENKI_SPARK 0x6a2

/* Fixed-point step added to the animation frame each update (one frame). */
#define D06DENKI_ANIME_STEP 0x1000

/* D06DenkiSparkWork.state */
#define D06DENKI_SPARK_PLAYING  0
#define D06DENKI_SPARK_FINISHED 1

/* Files of the models and animations, read from data tables. */
typedef struct D06DenkiModelFiles { u32 fileId[D06DENKI_MODEL_COUNT]; } D06DenkiModelFiles;
typedef struct D06DenkiAnimeFiles { u32 fileId[D06DENKI_ANIME_COUNT]; } D06DenkiAnimeFiles;

/*
 * Resources shared by the three effects (0x34 bytes, allocated by
 * FLDEFF_D06DENKI_Create). model[0] and anime[0] build the spark object; model[1],
 * anime[1], anime[2] and model[3] belong to the follow effect; model[2],
 * anime[3] and anime[4] belong to the pulse effect.
 */
typedef struct D06DenkiRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model[D06DENKI_MODEL_COUNT];      /* 0x04 */
    G3dResource *anime[D06DENKI_ANIME_COUNT];      /* 0x14 */
    G3dAnime *sparkAnime;                          /* 0x28 */
    G3dRender *sparkRender;                        /* 0x2C */
    G3dObject *sparkObject;                        /* 0x30 */
} D06DenkiRes;

/* Start parameter of the spark and pulse effects (0x10 bytes). */
typedef struct D06DenkiStartParam {
    D06DenkiRes *res;
    VecFx32 pos;
} D06DenkiStartParam;

/* Start parameter of the follow effect (0x14 bytes). */
typedef struct D06DenkiFollowParam {
    D06DenkiRes *res;
    VecFx32 pos;
    Mmdl *mmdl;                                    /* model the effect follows */
} D06DenkiFollowParam;

/* Work of the spark effect (0x0C bytes): plays the shared spark animation once. */
typedef struct D06DenkiSparkWork {
    D06DenkiRes *res;                              /* 0x00 */
    fx32 animeFrame;                               /* 0x04 */
    u32 state;                                     /* 0x08, D06DENKI_SPARK_* */
} D06DenkiSparkWork;

/* Work of the follow effect (0x3C bytes): two objects that track a model. */
typedef struct D06DenkiFollowWork {
    D06DenkiFollowParam param;                     /* 0x00, copy of the start parameter */
    u8 loopFrozen;                                 /* 0x14, set: the looping animation stops */
    u8 ending;                                     /* 0x15, set: the ending animation plays */
    u8 ended;                                      /* 0x16, set: the ending animation is done */
    u8 pad17;
    G3dObject *object;                             /* 0x18 */
    G3dAnime *anime[2];                            /* 0x1C, loop and ending animation */
    G3dRender *render;                             /* 0x24 */
    VecFx32 subPos;                                /* 0x28, position of the second object */
    G3dObject *subObject;                          /* 0x34 */
    G3dRender *subRender;                          /* 0x38 */
} D06DenkiFollowWork;

/* Work of the pulse effect (0x24 bytes): one animation that restarts when triggered. */
typedef struct D06DenkiPulseWork {
    D06DenkiStartParam param;                      /* 0x00, copy of the start parameter */
    u8 triggered;                                  /* 0x10, set: the second animation plays */
    u8 pad11[3];
    G3dObject *object;                             /* 0x14 */
    G3dAnime *anime[2];                            /* 0x18 */
    G3dRender *render;                             /* 0x20 */
} D06DenkiPulseWork;

extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern ArcHandle *FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);
extern int G3D_SYSTEM_TransVramTexture(G3dResource *res);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *G3D_SYSTEM_CreateAnime(G3dRender *render, const G3dResource *anmRes, int anmIdx);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern u32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
extern void G3D_SYSTEM_DeleteResource(G3dResource *res);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *out);
extern void *FIELD_EFFECT_GetResource(FieldEffectSys *fieldEffect, u32 effectId);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern void FIELD_EFFECT_SetObjectPos(FieldEffectObj *effect, const VecFx32 *pos);
extern void FIELD_EFFECT_DeleteObject(FieldEffectObj *effect);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(G3dObject *obj, u16 anmIdx, const fx32 *frame);
extern int G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(G3dObject *obj, u32 anmIdx, fx32 *frame);
extern void MTX_Identity33_(MtxFx33 *mtx);
extern void FIELD_EFFECT_GetObjectPos(FieldEffectObj *effect, VecFx32 *out);
extern int G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);
extern void *FIELD_EFFECT_GetObjectWork(FieldEffectObj *effect);
extern int FLDMMDL_CheckStatusBitUse(Mmdl *mmdl);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);

D06DenkiRes *FLDEFF_D06DENKI_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_D06DENKI_Delete(FieldEffectSys *fieldEffect, D06DenkiRes *res);
void FLDEFF_D06DENKI_LoadResources(D06DenkiRes *res);
void FLDEFF_D06DENKI_FreeResources(D06DenkiRes *res);
void FLDEFF_D06DENKI_StartSpark(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void FLDEFF_D06DENKI_SparkInit(FieldEffectObj *effect, D06DenkiSparkWork *work);
void FLDEFF_D06DENKI_SparkExit(void);
void FLDEFF_D06DENKI_SparkUpdate(FieldEffectObj *effect, D06DenkiSparkWork *work);
void FLDEFF_D06DENKI_SparkDraw(FieldEffectObj *effect, D06DenkiSparkWork *work);
void FLDEFF_D06DENKI_StartFollow(FieldEffectSys *fieldEffect, const VecFx32 *pos, Mmdl *mmdl);
void FLDEFF_D06DENKI_FollowFreezeLoop(FieldEffectObj *effect);
void FLDEFF_D06DENKI_FollowStartEnding(FieldEffectObj *effect);
int FLDEFF_D06DENKI_FollowIsEnded(FieldEffectObj *effect, u32 unusedA, u32 unusedB, u32 unusedC);
void FLDEFF_D06DENKI_FollowInit(FieldEffectObj *effect, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_FollowExit(void *task, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_FollowUpdate(FieldEffectObj *effect, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_FollowDraw(FieldEffectObj *effect, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_StartPulse(FieldEffectSys *fieldEffect, const VecFx32 *pos);
void FLDEFF_D06DENKI_PulseTrigger(FieldEffectObj *effect);
void FLDEFF_D06DENKI_PulseInit(FieldEffectObj *effect, D06DenkiPulseWork *work);
void FLDEFF_D06DENKI_PulseExit(void *task, D06DenkiPulseWork *work);
void FLDEFF_D06DENKI_PulseUpdate(void *task, D06DenkiPulseWork *work);
void FLDEFF_D06DENKI_PulseDraw(FieldEffectObj *effect, D06DenkiPulseWork *work);
extern char sFldeffD06DenkiFileName[];                              /* source file name for the heap allocator */
extern const D06DenkiModelFiles sD06DenkiModelFiles;
extern const D06DenkiAnimeFiles sD06DenkiAnimeFiles;
extern const FieldEffectObjFuncs sD06DenkiSparkFuncs;           /* spark callbacks */
extern G3dObjectStatus sD06DenkiSparkDrawStatus;                     /* spark draw status template */
extern const FieldEffectObjFuncs sD06DenkiFollowFuncs;           /* follow callbacks */
extern G3dObjectStatus sD06DenkiFollowDrawStatus;                     /* follow draw status template */
extern const FieldEffectObjFuncs sD06DenkiPulseFuncs;           /* pulse callbacks */
extern G3dObjectStatus sD06DenkiPulseDrawStatus;                     /* pulse draw status template */






/* Loads the resources of the three effects. */
D06DenkiRes *FLDEFF_D06DENKI_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    D06DenkiRes *res = func_02030734(heapId, 0x34, 1, sFldeffD06DenkiFileName, 0xa9);
    res->fieldEffect = fieldEffect;
    FLDEFF_D06DENKI_LoadResources(res);
    return res;
}






void FLDEFF_D06DENKI_Delete(FieldEffectSys *fieldEffect, D06DenkiRes *res)
{
    FLDEFF_D06DENKI_FreeResources(res);
    func_020307B0(res);
}






void FLDEFF_D06DENKI_LoadResources(D06DenkiRes *res)
{
    D06DenkiModelFiles modelFiles;
    D06DenkiAnimeFiles animeFiles;
    ArcHandle *arc;
    u32 i;

    modelFiles = sD06DenkiModelFiles;
    animeFiles = sD06DenkiAnimeFiles;
    arc = FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    for (i = 0; i < D06DENKI_MODEL_COUNT; i++) {
        res->model[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, modelFiles.fileId[i]);
        G3D_SYSTEM_TransVramTexture(res->model[i]);
    }
    for (i = 0; i < D06DENKI_ANIME_COUNT; i++) {
        res->anime[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, animeFiles.fileId[i]);
    }
    res->sparkRender = G3D_SYSTEM_CreateRender(res->model[0], 0, res->model[0]);
    res->sparkAnime = G3D_SYSTEM_CreateAnime(res->sparkRender, res->anime[0], 0);
    res->sparkObject = G3D_SYSTEM_CreateObject(res->sparkRender, &res->sparkAnime, 1);
    G3D_SYSTEM_EnableObjectAnime(res->sparkObject, 0);
}






void FLDEFF_D06DENKI_FreeResources(D06DenkiRes *res)
{
    u32 i;

    G3D_SYSTEM_DeleteAnime(res->sparkAnime);
    G3D_SYSTEM_DeleteObject(res->sparkObject);
    G3D_SYSTEM_DeleteRender(res->sparkRender);
    for (i = 0; i < D06DENKI_MODEL_COUNT; i++) {
        G3D_SYSTEM_FreeVramTexture(res->model[i]);
        G3D_SYSTEM_DeleteResource(res->model[i]);
    }
    for (i = 0; i < D06DENKI_ANIME_COUNT; i++) {
        G3D_SYSTEM_DeleteResource(res->anime[i]);
    }
}




/* Starts a spark at the position of the model. */
void FLDEFF_D06DENKI_StartSpark(const Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    VecFx32 pos;
    D06DenkiStartParam param;
    FLDMMDL_GetPos(mmdl, &pos);
    param.res = FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_D06DENKI);
    param.pos = pos;
    FIELD_EFFECT_AddObject(fieldEffect, &sD06DenkiSparkFuncs, 0, 0, &param, 0);
}





/* Spark effect: init. */
void FLDEFF_D06DENKI_SparkInit(FieldEffectObj *effect, D06DenkiSparkWork *work)
{
    D06DenkiStartParam *param = FIELD_EFFECT_GetObjectParam(effect);
    work->res = param->res;
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
    GFL_USE_PlaySeDefaultVolume(SE_D06DENKI_SPARK);
}


/* Spark effect: exit, nothing to release. */
void FLDEFF_D06DENKI_SparkExit(void) {}






/* Spark effect: update, ends the effect when the animation is done. */
void FLDEFF_D06DENKI_SparkUpdate(FieldEffectObj *effect, D06DenkiSparkWork *work)
{
    if (work->state == D06DENKI_SPARK_FINISHED)
        FIELD_EFFECT_DeleteObject(effect);
}






/* Spark effect: draw, advances the shared spark animation. */
void FLDEFF_D06DENKI_SparkDraw(FieldEffectObj *effect, D06DenkiSparkWork *work)
{
    G3dObjectStatus status;
    G3dObject *object;

    if (work->state == D06DENKI_SPARK_PLAYING) {
        status = sD06DenkiSparkDrawStatus;
        object = work->res->sparkObject;
        G3D_SYSTEM_SetObjectAnimeFrame(object, 0, &work->animeFrame);
        if (G3D_SYSTEM_IncObjectAnimeFrame(object, 0, D06DENKI_ANIME_STEP) == 0) {
            work->state = D06DENKI_SPARK_FINISHED;
        }
        if (G3D_SYSTEM_GetObjectAnimeFrame(object, 0, &work->animeFrame) == 0) {
            work->state = D06DENKI_SPARK_FINISHED;
        }
        MTX_Identity33_(&status.rotate);
        FIELD_EFFECT_GetObjectPos(effect, &status.trans);
        G3D_SYSTEM_DrawObjectCulling(object, &status);
    }
}






/* Starts a follow effect at the position, tracking the model. */
void FLDEFF_D06DENKI_StartFollow(FieldEffectSys *fieldEffect, const VecFx32 *pos, Mmdl *mmdl)
{
    D06DenkiFollowParam param;
    param.res = FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_D06DENKI);
    param.pos = *pos;
    param.mmdl = mmdl;
    FIELD_EFFECT_AddObject(fieldEffect, &sD06DenkiFollowFuncs, 0, 0, &param, 0);
}






/* Freezes the looping animation of a follow effect. */
void FLDEFF_D06DENKI_FollowFreezeLoop(FieldEffectObj *effect)
{
    if (effect != 0)
        ((D06DenkiFollowWork *)FIELD_EFFECT_GetObjectWork(effect))->loopFrozen = 1;
}






/* Starts the ending animation of a follow effect. */
void FLDEFF_D06DENKI_FollowStartEnding(FieldEffectObj *effect)
{
    fx32 frame;
    D06DenkiFollowWork *work;
    if (effect != 0) {
        frame = 0;
        work = FIELD_EFFECT_GetObjectWork(effect);
        work->ending = 1;
        work->ended = 0;
        G3D_SYSTEM_SetObjectAnimeFrame(work->object, 1, &frame);
    }
}






/* Returns nonzero when the ending animation of a follow effect is done (or the effect is gone). */
int FLDEFF_D06DENKI_FollowIsEnded(FieldEffectObj *effect, u32 unusedA, u32 unusedB, u32 unusedC)
{
if (effect != 0) {
    return ((D06DenkiFollowWork *)FIELD_EFFECT_GetObjectWork(effect))->ended;
}
return 1;
}






/* Follow effect: init. */
void FLDEFF_D06DENKI_FollowInit(FieldEffectObj *effect, D06DenkiFollowWork *work)
{
    work->param = *(D06DenkiFollowParam *)FIELD_EFFECT_GetObjectParam(effect);
    FIELD_EFFECT_SetObjectPos(effect, &work->param.pos);
    work->render = G3D_SYSTEM_CreateRender(work->param.res->model[1], 0, work->param.res->model[1]);
    work->anime[0] = G3D_SYSTEM_CreateAnime(work->render, work->param.res->anime[1], 0);
    work->anime[1] = G3D_SYSTEM_CreateAnime(work->render, work->param.res->anime[2], 0);
    work->object = G3D_SYSTEM_CreateObject(work->render, work->anime, 2);
    G3D_SYSTEM_EnableObjectAnime(work->object, 0);
    G3D_SYSTEM_EnableObjectAnime(work->object, 1);
    work->subRender = G3D_SYSTEM_CreateRender(work->param.res->model[3], 0, work->param.res->model[3]);
    work->subObject = G3D_SYSTEM_CreateObject(work->subRender, 0, 0);
}






/* Follow effect: exit. */
void FLDEFF_D06DENKI_FollowExit(void *task, D06DenkiFollowWork *work)
{
    G3D_SYSTEM_DeleteAnime(work->anime[0]);
    G3D_SYSTEM_DeleteAnime(work->anime[1]);
    G3D_SYSTEM_DeleteObject(work->object);
    G3D_SYSTEM_DeleteRender(work->render);
    G3D_SYSTEM_DeleteObject(work->subObject);
    G3D_SYSTEM_DeleteRender(work->subRender);
}






/* Follow effect: update, tracks the model while it is in use. */
void FLDEFF_D06DENKI_FollowUpdate(FieldEffectObj *effect, D06DenkiFollowWork *work)
{
    VecFx32 pos;

    if (FLDMMDL_CheckStatusBitUse(work->param.mmdl) != 0) {
        FLDMMDL_GetPos(work->param.mmdl, &pos);
        work->subPos = pos;
        FIELD_EFFECT_SetObjectPos(effect, &pos);
        work->subPos.y -= 0x4000;
        work->subPos.z += 0x2800;
        if (work->loopFrozen == 0) {
            G3D_SYSTEM_LoopObjectAnimeFrame(work->object, 0, D06DENKI_ANIME_STEP);
        }
        if (work->ending == 1 && work->ended == 0) {
            if (G3D_SYSTEM_IncObjectAnimeFrame(work->object, 1, D06DENKI_ANIME_STEP) == 0) {
                work->ended = 1;
            }
        }
    }
}






/* Follow effect: draw. */
void FLDEFF_D06DENKI_FollowDraw(FieldEffectObj *effect, D06DenkiFollowWork *work)
{
    G3dObjectStatus status = sD06DenkiFollowDrawStatus;

    MTX_Identity33_(&status.rotate);
    FIELD_EFFECT_GetObjectPos(effect, &status.trans);
    G3D_SYSTEM_DrawObjectCulling(work->object, &status);
    status.trans = work->subPos;
    G3D_SYSTEM_DrawObjectCulling(work->subObject, &status);
}






/* Starts a pulse effect at the position. */
void FLDEFF_D06DENKI_StartPulse(FieldEffectSys *fieldEffect, const VecFx32 *pos)
{
    D06DenkiStartParam param;
    param.res = FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_D06DENKI);
    param.pos = *pos;
    FIELD_EFFECT_AddObject(fieldEffect, &sD06DenkiPulseFuncs, 0, 0, &param, 0);
}






/* Triggers the second animation of a pulse effect, once. */
void FLDEFF_D06DENKI_PulseTrigger(FieldEffectObj *effect)
{
    fx32 frame;
    D06DenkiPulseWork *work;
    if (effect != 0) {
        work = FIELD_EFFECT_GetObjectWork(effect);
        if (work->triggered == 0) {
            frame = 0;
            work->triggered = 1;
            G3D_SYSTEM_SetObjectAnimeFrame(work->object, 1, &frame);
        }
    }
}






/* Pulse effect: init. */
void FLDEFF_D06DENKI_PulseInit(FieldEffectObj *effect, D06DenkiPulseWork *work)
{
    work->param = *(D06DenkiStartParam *)FIELD_EFFECT_GetObjectParam(effect);
    FIELD_EFFECT_SetObjectPos(effect, &work->param.pos);
    work->render = G3D_SYSTEM_CreateRender(work->param.res->model[2], 0, work->param.res->model[2]);
    work->anime[0] = G3D_SYSTEM_CreateAnime(work->render, work->param.res->anime[3], 0);
    work->anime[1] = G3D_SYSTEM_CreateAnime(work->render, work->param.res->anime[4], 0);
    work->object = G3D_SYSTEM_CreateObject(work->render, work->anime, 2);
    G3D_SYSTEM_EnableObjectAnime(work->object, 0);
    G3D_SYSTEM_EnableObjectAnime(work->object, 1);
}






/* Pulse effect: exit. */
void FLDEFF_D06DENKI_PulseExit(void *task, D06DenkiPulseWork *work)
{
    G3D_SYSTEM_DeleteAnime(work->anime[0]);
    G3D_SYSTEM_DeleteAnime(work->anime[1]);
    G3D_SYSTEM_DeleteObject(work->object);
    G3D_SYSTEM_DeleteRender(work->render);
}






/* Pulse effect: update, loops the first animation; the second one runs once after a trigger. */
void FLDEFF_D06DENKI_PulseUpdate(void *task, D06DenkiPulseWork *work)
{
    G3D_SYSTEM_LoopObjectAnimeFrame(work->object, 0, D06DENKI_ANIME_STEP);
    if (work->triggered == 1 && G3D_SYSTEM_IncObjectAnimeFrame(work->object, 1, D06DENKI_ANIME_STEP) == 0)
        work->triggered = 0;
}






/* Pulse effect: draw. */
void FLDEFF_D06DENKI_PulseDraw(FieldEffectObj *effect, D06DenkiPulseWork *work)
{
    G3dObjectStatus status = sD06DenkiPulseDrawStatus;
    MTX_Identity33_(&status.rotate);
    FIELD_EFFECT_GetObjectPos(effect, &status.trans);
    G3D_SYSTEM_DrawObjectCulling(work->object, &status);
}
