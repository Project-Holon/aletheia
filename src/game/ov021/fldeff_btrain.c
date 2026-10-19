/*
 * file:     fldeff_btrain.c
 * unit:     yes
 * function: FLDEFF_BTRAIN_Create, FLDEFF_BTRAIN_Delete, FLDEFF_BTRAIN_LoadResources, FLDEFF_BTRAIN_FreeResources, FLDEFF_BTRAIN_Start, FLDEFF_BTRAIN_SetAnime, FLDEFF_BTRAIN_SetHidden, FLDEFF_BTRAIN_Init, FLDEFF_BTRAIN_Exit, FLDEFF_BTRAIN_Update, FLDEFF_BTRAIN_Draw
 * address:  0x021D0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021D0140 (lane L136, __FILE__ anchor fldeff_btrain.c at 021D0140 (sFldeffBtrainFileName); callback table g_021DB8DC targets 029C/0308/0328/034C).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sFldeffBtrainFileName     0x021DE608  data  ov021  a4
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   sBtrainAnimeFiles  0x021DB8C4  data  a2
 *   sBtrainModelFiles  0x021DB8CC  data  a2
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   sBtrainFuncs     0x021DB8DC  data  ov021  a4
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   sBtrainDrawStatus  0x021DB8F0  data  ov021  a4
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 */
#include "../ov010/fldmmdl_types.h"
#include "field_effect_types.h"

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

/* Id of the Battle Subway train resources in the field effect system. */
#define FLDEFF_ID_BTRAIN 14

/* Train models (one per train kind) and animations shared by all of them. */
#define BTRAIN_MODEL_COUNT 8
#define BTRAIN_ANIME_COUNT 4

/* Animation index of the work while no animation is selected. */
#define BTRAIN_ANIME_NONE BTRAIN_ANIME_COUNT

/* Fixed-point step added to the animation frame each update (one frame). */
#define BTRAIN_ANIME_STEP 0x1000

/* Resources of the train effect (allocated 0x54 bytes by FLDEFF_BTRAIN_Create). The models load one by one. */
typedef struct BtrainRes {
    FieldEffectSys *fieldEffect;                    /* 0x00 */
    G3dResource *model[BTRAIN_MODEL_COUNT];         /* 0x04 */
    G3dResource *anime[BTRAIN_ANIME_COUNT];         /* 0x24 */
    G3dRender *render[BTRAIN_MODEL_COUNT];          /* 0x34 */
} BtrainRes;

/* Start parameter of the effect. */
typedef struct BtrainStartParam {
    BtrainRes *res;
    u32 modelIndex;                                 /* train kind */
} BtrainStartParam;

/* Work of the train effect (0x20 bytes, the first word of the callback table). */
typedef struct BtrainWork {
    u8 pad00;
    u8 hidden;                                      /* 0x01 1 = not drawn */
    u8 animeIndex;                                  /* 0x02 playing animation, BTRAIN_ANIME_NONE = none */
    u8 animeFinished;                               /* 0x03 1 = the playing animation reached its end */
    BtrainStartParam param;                         /* 0x04 */
    G3dObject *object;                              /* 0x0C */
    G3dAnime *anime[BTRAIN_ANIME_COUNT];            /* 0x10 */
} BtrainWork;

extern void MTX_Identity33_(MtxFx33 *mtx);
extern void FIELD_EFFECT_GetObjectPos(FieldEffectObj *effect, VecFx32 *out);
extern int G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
struct FieldEffectSys;
extern u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);
extern int G3D_SYSTEM_TransVramTexture(G3dResource *res);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
extern void G3D_SYSTEM_DeleteResource(G3dResource *res);
extern s32 FIELD_EFFECT_GetResource(struct FieldEffectSys *sys, s32 id);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void *FIELD_EFFECT_GetObjectWork(FieldEffectObj *effect);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *G3D_SYSTEM_CreateAnime(struct G3dRender *render, struct G3dResource *anmRes, u32 anmIdx);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern s32 G3D_SYSTEM_ResetObjectAnimeFrame(G3dObject *obj, u16 anmIdx);
extern s32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
extern int G3D_SYSTEM_DisableObjectAnime(G3dObject *obj, u32 anmIdx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);

BtrainRes *FLDEFF_BTRAIN_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_BTRAIN_Delete(FieldEffectSys *fieldEffect, BtrainRes *res);
void FLDEFF_BTRAIN_LoadResources(BtrainRes *res, int modelIndex);
void FLDEFF_BTRAIN_FreeResources(BtrainRes *res);
void FLDEFF_BTRAIN_Start(FieldEffectSys *fieldEffect, u32 modelIndex, const VecFx32 *pos);
void FLDEFF_BTRAIN_SetAnime(FieldEffectObj *effect, u32 animeIndex);
void FLDEFF_BTRAIN_SetHidden(FieldEffectObj *effect, u32 hidden);
void FLDEFF_BTRAIN_Init(FieldEffectObj *effect, BtrainWork *work);
void FLDEFF_BTRAIN_Exit(FieldEffectObj *effect, BtrainWork *work);
void FLDEFF_BTRAIN_Update(FieldEffectObj *effect, BtrainWork *work);
void FLDEFF_BTRAIN_Draw(FieldEffectObj *effect, BtrainWork *work);

extern char sFldeffBtrainFileName[];                              /* source file name for the heap allocator */
extern const u16 sBtrainModelFiles[BTRAIN_MODEL_COUNT];    /* model file ids */
extern const u16 sBtrainAnimeFiles[BTRAIN_ANIME_COUNT];    /* animation file ids */
extern const FieldEffectObjFuncs sBtrainFuncs;           /* train effect callbacks */
extern const G3dObjectStatus sBtrainDrawStatus;            /* draw status template */

/* ------------------------------------------------------------------ */
/* fldeff_btrain.c                                                     */
/* ------------------------------------------------------------------ */

/* Allocates the resources of the Battle Subway train effect; nothing loads yet. */
BtrainRes *FLDEFF_BTRAIN_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    BtrainRes *res = GFL_HEAP_Alloc(heapId, sizeof(BtrainRes), 1, sFldeffBtrainFileName, 0x5f);

    res->fieldEffect = fieldEffect;
    return res;
}

void FLDEFF_BTRAIN_Delete(FieldEffectSys *fieldEffect, BtrainRes *res)
{
    FLDEFF_BTRAIN_FreeResources(res);
    GFL_HEAP_Free(res);
}

/* Loads the model of one train kind (once) and the shared animations. */
void FLDEFF_BTRAIN_LoadResources(BtrainRes *res, int modelIndex)
{
    ArcHandle *arc;
    const u16 *modelFile;
    const u16 *animeFile;
    int i;

    arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    modelFile = sBtrainModelFiles;
    if (res->model[modelIndex] == 0) {
        res->model[modelIndex] = G3D_SYSTEM_CreateResourceArcHandle(arc, modelFile[modelIndex]);
        G3D_SYSTEM_TransVramTexture(res->model[modelIndex]);
        res->render[modelIndex] = G3D_SYSTEM_CreateRender(res->model[modelIndex], 0, res->model[modelIndex]);
    }
    animeFile = sBtrainAnimeFiles;
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++, animeFile++) {
        if (res->anime[i] == 0) {
            res->anime[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, *animeFile);
        }
    }
}

void FLDEFF_BTRAIN_FreeResources(BtrainRes *res)
{
    int i;

    for (i = 0; i < BTRAIN_MODEL_COUNT; i++) {
        if (res->model[i] != 0) {
            G3D_SYSTEM_DeleteRender(res->render[i]);
            G3D_SYSTEM_FreeVramTexture(res->model[i]);
            G3D_SYSTEM_DeleteResource(res->model[i]);
        }
    }
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++) {
        if (res->anime[i] != 0) {
            G3D_SYSTEM_DeleteResource(res->anime[i]);
        }
    }
}

/* Starts the train effect of one train kind at pos. */
void FLDEFF_BTRAIN_Start(FieldEffectSys *fieldEffect, u32 modelIndex, const VecFx32 *pos)
{
    BtrainStartParam param;

    param.res = (struct BtrainRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_BTRAIN);
    param.modelIndex = modelIndex;
    FLDEFF_BTRAIN_LoadResources(param.res, modelIndex);
    FIELD_EFFECT_AddObject(fieldEffect, &sBtrainFuncs, pos, 0, &param, 0);
}

/*
 * Selects the animation of the train (the doors, see the Battle Subway script
 * command) and restarts it. A null effect is ignored.
 */
void FLDEFF_BTRAIN_SetAnime(FieldEffectObj *effect, u32 animeIndex)
{
    int i;
    BtrainWork *work;

    if (effect == 0)
        return;
    work = FIELD_EFFECT_GetObjectWork(effect);
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++) {
        G3D_SYSTEM_ResetObjectAnimeFrame(work->object, (u16)i);
        if (i == animeIndex)
            G3D_SYSTEM_EnableObjectAnime(work->object, (u16)i);
        else
            G3D_SYSTEM_DisableObjectAnime(work->object, (u16)i);
    }
    work->animeIndex = animeIndex;
    work->animeFinished = 0;
}

/* Shows or hides the train. A null effect is ignored. */
void FLDEFF_BTRAIN_SetHidden(FieldEffectObj *effect, u32 hidden)
{
    if (effect != 0)
        ((BtrainWork *)FIELD_EFFECT_GetObjectWork(effect))->hidden = hidden;
}

/* Effect init: one animation object per animation, all disabled. */
void FLDEFF_BTRAIN_Init(FieldEffectObj *effect, BtrainWork *work)
{
    BtrainStartParam *param = FIELD_EFFECT_GetObjectParam(effect);
    BtrainRes *res;
    int modelIndex;
    int j;
    int i;

    work->param = *param;
    res = work->param.res;
    modelIndex = work->param.modelIndex;
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++)
        work->anime[i] = G3D_SYSTEM_CreateAnime(res->render[modelIndex], res->anime[i], 0);
    work->animeIndex = BTRAIN_ANIME_NONE;
    work->object = G3D_SYSTEM_CreateObject(res->render[modelIndex], work->anime, BTRAIN_ANIME_COUNT);
    for (j = 0; j < BTRAIN_ANIME_COUNT; j++)
        G3D_SYSTEM_DisableObjectAnime(work->object, (u16)j);
}

/* Effect exit. */
void FLDEFF_BTRAIN_Exit(FieldEffectObj *effect, BtrainWork *work)
{
    int i;

    G3D_SYSTEM_DeleteObject(work->object);
    for (i = 0; i < BTRAIN_ANIME_COUNT; i++) {
        G3D_SYSTEM_DeleteAnime(work->anime[i]);
    }
}

/* Effect update: plays the selected animation and notes when it ends. */
void FLDEFF_BTRAIN_Update(FieldEffectObj *effect, BtrainWork *work)
{
    if (work->animeIndex != BTRAIN_ANIME_NONE) {
        work->animeFinished = 0;
        if (G3D_SYSTEM_IncObjectAnimeFrame(work->object, work->animeIndex, BTRAIN_ANIME_STEP) == 0) {
            work->animeFinished = 1;
        }
    }
}

/* Effect draw. */
void FLDEFF_BTRAIN_Draw(FieldEffectObj *effect, BtrainWork *work)
{
    G3dObjectStatus status;

    if (work->hidden == 0) {
        status = sBtrainDrawStatus;
        MTX_Identity33_(&status.rotate);
        FIELD_EFFECT_GetObjectPos(effect, &status.trans);
        G3D_SYSTEM_DrawObjectCulling(work->object, &status);
    }
}
