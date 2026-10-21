/*
 * file:     fldeff_hide.c
 * unit:     yes
 * function: FLDEFF_HIDE_CreateResources, FLDEFF_HIDE_DeleteResources, FLDEFF_HIDE_LoadResources, FLDEFF_HIDE_FreeResources, FLDEFF_HIDE_Start, FLDEFF_HIDE_RequestEnd, FLDEFF_HIDE_IsFinished, FLDEFF_HIDE_Init, FLDEFF_HIDE_Exit, FLDEFF_HIDE_Update, FLDEFF_HIDE_Draw
 * address:  0x021D038C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021D038C (lane L136, __FILE__ anchor fldeff_hide.c at 021D038C (sFldeffHideFileName); callback table g_021DB93C targets 04D8/0504/0520/0568).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   sFldeffHideFileName     0x021DE618  data  ov021  a4
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectManualDraw  0x021C67D8  thumb  ov021
 *   sHideFiles  0x021DB92C  data  ov021  a2
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 *   sHideFuncs     0x021DB93C  data  ov021  a4
 *   sHideEndSeIds     0x021DB934  data  a4
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_G3DOBJ_SetAnimeFrame  0x021C6744  thumb  ov021
 *   FIELD_G3DOBJ_IncAnimeFrame  0x021C6694  thumb  ov021
 *   FIELD_G3DOBJ_GetAnimeFrame  0x021C67A8  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectTrans  0x021C6664  thumb  ov021
 *   FIELD_G3DOBJ_DrawObject  0x021C67F4  thumb  ov021
 */
#include "../ov010/fldmmdl_types.h"
#include "field_effect_types.h"

/* Opaque types of other files. */
typedef struct FieldG3dObjCtrl FieldG3dObjSys;           /* field 3D object system (arm9/ov021 field_g3dobj) */
typedef struct ArcHandle ArcHandle;

/* Resource description the field 3D object system builds a model from (9 words). */
typedef struct FieldG3dResDesc {
    u32 w[9];
} FieldG3dResDesc;

/* Id of the hide resources in the field effect system. */
#define FLDEFF_ID_HIDE 15

/* Kinds of the hide effect: one model with one animation each. */
#define HIDE_KIND_COUNT 2

/* Fixed-point step added to the animation frame each draw (one frame). */
#define HIDE_ANIME_STEP 0x1000

/* Model and animation file of one hide kind in the effect archive. */
typedef struct HideFiles {
    u16 modelFile;
    u16 animeFile;
} HideFiles;

/* Resources of the hide effect (allocated 0xC bytes by FLDEFF_HIDE_CreateResources). */
typedef struct HideRes {
    u16 resId[HIDE_KIND_COUNT];                  /* 0x00 model resource of each kind */
    FieldEffectSys *fieldEffect;                 /* 0x04 */
    u16 objId[HIDE_KIND_COUNT];                  /* 0x08 object of each kind, drawn by the effect */
} HideRes;

/* Start parameter of the effect. */
typedef struct HideStartParam {
    HideRes *res;
    FieldG3dObjSys *g3dObjSys;
    Mmdl *mmdl;                                  /* hidden model the effect follows */
    u32 kind;
} HideStartParam;

/* Work of the hide effect (0x24 bytes, the first word of the callback table). */
typedef struct HideWork {
    HideStartParam param;                        /* 0x00 */
    MmdlCheckInfo mmdlInfo;                      /* 0x10 identity of the model, taken at the start */
    u16 pad16;
    u16 objId;                                   /* 0x18 */
    u16 endRequested;                            /* 0x1A 1 = play the animation to its end */
    u16 finished;                                /* 0x1C 1 = the animation reached its end */
    u16 pad1E;
    u32 animeFrame;                              /* 0x20 */
} HideWork;

#include "../arm9/gfl_heap_wrap.h"
struct FieldEffectSys;
#include "field_effect.h"
struct FieldG3dObjResDesc;
#include "field_g3dobj.h"
struct FieldG3dObjCtrl;
#include "../arm9/gfl_use.h"
#include "../ov010/fldmmdl.h"
struct Mmdl;
#include "fldmmdl_movecode.h"
struct VecFx32;
#include "../ov010/fldmmdl_move.h"

HideRes *FLDEFF_HIDE_CreateResources(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_HIDE_DeleteResources(FieldEffectSys *fieldEffect, HideRes *res);
void FLDEFF_HIDE_LoadResources(HideRes *res);
void FLDEFF_HIDE_FreeResources(HideRes *res);
FieldEffectObj *FLDEFF_HIDE_Start(FieldEffectSys *fieldEffect, Mmdl *mmdl, u32 kind);
void FLDEFF_HIDE_RequestEnd(FieldEffectObj *effect);
int FLDEFF_HIDE_IsFinished(FieldEffectObj *effect);
void FLDEFF_HIDE_Init(FieldEffectObj *effect, HideWork *work);
void FLDEFF_HIDE_Exit(FieldEffectObj *effect, HideWork *work);
void FLDEFF_HIDE_Update(FieldEffectObj *effect, HideWork *work);
void FLDEFF_HIDE_Draw(FieldEffectObj *effect, HideWork *work);

extern char sFldeffHideFileName[];                              /* source file name for the heap allocator */
extern const HideFiles sHideFiles[HIDE_KIND_COUNT]; /* model and animation file of each kind */
extern const FieldEffectObjFuncs sHideFuncs;           /* hide effect callbacks */
extern u32 sHideEndSeIds[HIDE_KIND_COUNT];                /* sound effect played when the effect ends */

/* ------------------------------------------------------------------ */
/* fldeff_hide.c                                                       */
/* ------------------------------------------------------------------ */

/* Loads the resources of the hide effect. */
HideRes *FLDEFF_HIDE_CreateResources(FieldEffectSys *fieldEffect, u32 heapId)
{
    HideRes *res = GFL_HEAP_Alloc(heapId, sizeof(HideRes), 1, sFldeffHideFileName, 0x6b);

    res->fieldEffect = fieldEffect;
    FLDEFF_HIDE_LoadResources(res);
    return res;
}

void FLDEFF_HIDE_DeleteResources(FieldEffectSys *fieldEffect, HideRes *res)
{
    FLDEFF_HIDE_FreeResources(res);
    GFL_HEAP_Free(res);
}

/* Loads the model of each kind and adds its object (drawn by the effect itself). */
void FLDEFF_HIDE_LoadResources(HideRes *res)
{
    FieldG3dResDesc desc;
    ArcHandle *arc;
    FieldG3dObjSys *g3dObjSys;
    int i = 0;
    const HideFiles *files = sHideFiles;

    arc = FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    g3dObjSys = (struct FieldG3dObjCtrl *)FIELD_EFFECT_GetFieldMapData(res->fieldEffect);
    for (; i < HIDE_KIND_COUNT; i++, files++) {
        FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)(&desc));
        FIELD_G3DOBJ_SetResDescModel((struct FieldG3dObjResDesc *)(&desc), arc, files->modelFile);
        FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)(&desc), arc);
        FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)(&desc), files->animeFile);
        res->resId[i] = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)g3dObjSys, (struct FieldG3dObjResDesc *)(&desc), 0);
        res->objId[i] = FIELD_G3DOBJ_AddObject(g3dObjSys, res->resId[i], 0, 0);
        FIELD_G3DOBJ_SetObjectManualDraw((struct FieldG3dObjCtrl *)g3dObjSys, res->objId[i], 1);
    }
}

void FLDEFF_HIDE_FreeResources(HideRes *res)
{
    int i = 0;
    FieldG3dObjSys *g3dObjSys = (struct FieldG3dObjCtrl *)FIELD_EFFECT_GetFieldMapData(res->fieldEffect);

    for (; i < HIDE_KIND_COUNT; i++) {
        FIELD_G3DOBJ_DeleteObject((struct FieldG3dObjCtrl *)g3dObjSys, res->objId[i]);
        FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)g3dObjSys, res->resId[i]);
    }
}

/* Starts the hide effect of one kind on a model; returns the effect. */
FieldEffectObj *FLDEFF_HIDE_Start(FieldEffectSys *fieldEffect, Mmdl *mmdl, u32 kind)
{
    HideStartParam param;

    param.res = (struct HideRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_HIDE);
    param.g3dObjSys = (struct FieldG3dObjCtrl *)FIELD_EFFECT_GetFieldMapData(fieldEffect);
    param.mmdl = mmdl;
    param.kind = kind;
    return FIELD_EFFECT_AddObject(fieldEffect, &sHideFuncs, 0, 0, &param, 0);
}

/*
 * Blocked: sHideEndSeIds (u32 table indexed by the kind) is contested: another
 * overlay in the window starts an object at 0x021DB934 and this function has
 * no overlay_id site, so the ABS32 word stays wildcarded.
 */
/* Asks the effect to play its animation to the end and plays the sound. A null effect is ignored. */
void FLDEFF_HIDE_RequestEnd(FieldEffectObj *effect)
{
    HideWork *work;

    if (effect != 0) {
        work = FIELD_EFFECT_GetObjectWork(effect);
        work->endRequested = 1;
        GFL_USE_PlaySeDefaultVolume(sHideEndSeIds[work->param.kind]);
    }
}

/* 1 when the animation has played to its end, or when there is no effect. */
int FLDEFF_HIDE_IsFinished(FieldEffectObj *effect)
{
    if (effect != 0) {
        return ((HideWork *)FIELD_EFFECT_GetObjectWork(effect))->finished;
    }
    return 1;
}

/* Effect init. */
void FLDEFF_HIDE_Init(FieldEffectObj *effect, HideWork *work)
{
    work->param = *(HideStartParam *)FIELD_EFFECT_GetObjectParam(effect);
    FLDMMDL_GetCheckInfo(work->param.mmdl, &work->mmdlInfo);
    work->objId = work->param.res->objId[work->param.kind];
}

/* Effect exit: the model no longer holds the effect. */
void FLDEFF_HIDE_Exit(FieldEffectObj *effect, HideWork *work)
{
    if (FLDMMDL_CheckCheckInfo(work->param.mmdl, &work->mmdlInfo) == 1) {
        FLDMMDL_MOVE_SetHideEffect(work->param.mmdl, 0);
    }
}

/* Effect update: follows the model on the map height and ends when the model is gone. */
void FLDEFF_HIDE_Update(FieldEffectObj *effect, HideWork *work)
{
    int mapHeight;
    VecFx32 pos;

    if (FLDMMDL_CheckCheckInfo(work->param.mmdl, &work->mmdlInfo) == 0) {
        FIELD_EFFECT_DeleteObject(effect);
        return;
    }
    FLDMMDL_GetPos(work->param.mmdl, (struct VecFx32 *)(&pos));
    if (FLDMMDL_MOVE_GetMapHeight(work->param.mmdl, &pos, &mapHeight) == 1) {
        pos.y = mapHeight;
    }
    FIELD_EFFECT_SetObjectPos(effect, &pos);
}

/* Effect draw: plays the animation once the end is requested, then draws at the effect position. */
void FLDEFF_HIDE_Draw(FieldEffectObj *effect, HideWork *work)
{
    VecFx32 pos;

    if (work->endRequested == 1 && work->finished == 0) {
        FIELD_G3DOBJ_SetAnimeFrame((struct FieldG3dObjCtrl *)work->param.g3dObjSys, work->objId, 0, work->animeFrame);
        if (FIELD_G3DOBJ_IncAnimeFrame((struct FieldG3dObjCtrl *)work->param.g3dObjSys, work->objId, HIDE_ANIME_STEP) == 0) {
            work->finished = 1;
        }
        work->animeFrame = FIELD_G3DOBJ_GetAnimeFrame((struct FieldG3dObjCtrl *)work->param.g3dObjSys, work->objId, 0);
    } else {
        FIELD_G3DOBJ_SetAnimeFrame((struct FieldG3dObjCtrl *)work->param.g3dObjSys, work->objId, 0, work->animeFrame);
    }
    FIELD_EFFECT_GetObjectPos(effect, &pos);
    FIELD_G3DOBJ_SetObjectTrans(work->param.g3dObjSys, work->objId, &pos);
    FIELD_G3DOBJ_DrawObject((struct FieldG3dObjCtrl *)work->param.g3dObjSys, work->objId);
}
