/*
 * file:     fldeff_iwakudaki.c
 * unit:     yes
 * function: FLDEFF_IWAKUDAKI_Create, FLDEFF_IWAKUDAKI_Delete, FLDEFF_IWAKUDAKI_LoadResources, FLDEFF_IWAKUDAKI_FreeResources, FLDEFF_IWAKUDAKI_UploadTexturesTask, FLDEFF_IWAKUDAKI_Start, FLDEFF_IWAKUDAKI_Init, FLDEFF_IWAKUDAKI_Exit, FLDEFF_IWAKUDAKI_Update, FLDEFF_IWAKUDAKI_Draw
 * address:  0x021ADCB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   sFldeffIwakudakiFileName  0x021DE10C  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_AllocVramTexture  0x02047180  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   sIwakudakiAnimeFiles     0x021DE0FC  data  a4
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_IsResourceLoaded  0x021ABE8C  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sIwakudakiFuncs     0x021D9290  data  a4
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   sIwakudakiDrawStatus  0x021D92A4  data
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   G3D_SYSTEM_TransAllocatedTexture  0x02047204  arm  arm9
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm  arm9
 *   TCB_DeleteTask  0x02030EAC  arm  arm9
 */
#include "../ov010/fldmmdl_types.h"
#include "field_effect_types.h"

/* Opaque types of other files. */
#include "../sdk_fx.h"

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

/* Id of the Rock Smash resources in the field effect system. */
#define FLDEFF_ID_IWAKUDAKI 10

#define IWAKUDAKI_ANIME_COUNT 4

/* File of the model in the effect archive. */
#define IWAKUDAKI_MODEL_FILE 0x4d

/* Offset of the effect from the smashed rock's model position. */
#define IWAKUDAKI_OFFSET_Y 0x1000
#define IWAKUDAKI_OFFSET_Z 0xc000

/* Fixed-point step added to the animation frame each update (one frame). */
#define IWAKUDAKI_ANIME_STEP 0x1000

/* Resources of the Rock Smash effect (allocated 0x20 bytes by FLDEFF_IWAKUDAKI_Create). */
typedef struct IwakudakiRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model;                            /* 0x04 */
    G3dResource *anime[IWAKUDAKI_ANIME_COUNT];     /* 0x08 */
    void *uploadTask;                              /* 0x18 uploads the textures once */
    u32 texturesUploaded;                          /* 0x1C */
} IwakudakiRes;

/* Start parameter of the effect. */
typedef struct IwakudakiStartParam {
    IwakudakiRes *res;
    VecFx32 pos;
} IwakudakiStartParam;

/* Work of the Rock Smash effect: four animations of one model that play to their end. */
typedef struct IwakudakiWork {
    IwakudakiRes *res;                             /* 0x00 */
    G3dObject *object;                             /* 0x04 */
    G3dAnime *anime[IWAKUDAKI_ANIME_COUNT];        /* 0x08 */
    G3dRender *render;                             /* 0x18 */
} IwakudakiWork;

/* Position of a model on the map grid. */
typedef struct GridPos {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
} GridPos;

typedef int (*TrainerEyeSightFunc)(int range, const GridPos *trainerPos, const GridPos *targetPos);

extern void MTX_Identity33_(MtxFx33 *mtx);
extern void FIELD_EFFECT_GetObjectPos(FieldEffectObj *effect, VecFx32 *out);
extern int G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
struct FieldEffectSys;
extern u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);
extern int G3D_SYSTEM_AllocVramTexture(G3dResource *res);
struct Tcb;
extern struct Tcb *GFL_USE_AddMainTask(void (*func)(void *task, void *work), void *work, u32 priority);
extern void G3D_SYSTEM_DeleteResource(G3dResource *res);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern int G3D_SYSTEM_TransAllocatedTexture(G3dResource *res);
struct MmdlVec;
struct Mmdl;
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern int FIELD_EFFECT_IsResourceLoaded(FieldEffectSys *fieldEffect, int effectId);
extern void FIELD_EFFECT_LoadResources(FieldEffectSys *fieldEffect, int *effectIds, int count);
extern s32 FIELD_EFFECT_GetResource(struct FieldEffectSys *sys, s32 id);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern void FIELD_EFFECT_SetObjectPos(FieldEffectObj *effect, const VecFx32 *pos);
extern void FIELD_EFFECT_DeleteObject(FieldEffectObj *effect);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *G3D_SYSTEM_CreateAnime(struct G3dRender *render, struct G3dResource *anmRes, u32 anmIdx);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern s32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);

IwakudakiRes *FLDEFF_IWAKUDAKI_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_IWAKUDAKI_Delete(FieldEffectSys *fieldEffect, IwakudakiRes *res);
void FLDEFF_IWAKUDAKI_LoadResources(IwakudakiRes *res);
void FLDEFF_IWAKUDAKI_FreeResources(IwakudakiRes *res);
void FLDEFF_IWAKUDAKI_UploadTexturesTask(void *task, void *work);
void FLDEFF_IWAKUDAKI_Start(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void FLDEFF_IWAKUDAKI_Init(FieldEffectObj *effect, IwakudakiWork *work);
void FLDEFF_IWAKUDAKI_Exit(void *task, IwakudakiWork *work);
void FLDEFF_IWAKUDAKI_Update(FieldEffectObj *effect, IwakudakiWork *work);
void FLDEFF_IWAKUDAKI_Draw(FieldEffectObj *effect, IwakudakiWork *work);

extern char sFldeffIwakudakiFileName[];                              /* source file name for the heap allocator */
extern int sIwakudakiAnimeFiles[IWAKUDAKI_ANIME_COUNT];          /* animation file ids */
extern const FieldEffectObjFuncs sIwakudakiFuncs;           /* Rock Smash effect callbacks */
extern G3dObjectStatus sIwakudakiDrawStatus;                     /* draw status template */

/* ------------------------------------------------------------------ */
/* fldeff_iwakudaki.c                                                  */
/* ------------------------------------------------------------------ */

/* Loads the resources of the Rock Smash effect. */
IwakudakiRes *FLDEFF_IWAKUDAKI_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    IwakudakiRes *res = GFL_HEAP_Alloc(heapId, 0x20, 1, sFldeffIwakudakiFileName, 0x67);
    res->fieldEffect = fieldEffect;
    FLDEFF_IWAKUDAKI_LoadResources(res);
    return res;
}

void FLDEFF_IWAKUDAKI_Delete(FieldEffectSys *fieldEffect, IwakudakiRes *res)
{
    FLDEFF_IWAKUDAKI_FreeResources(res);
    GFL_HEAP_Free(res);
}

void FLDEFF_IWAKUDAKI_LoadResources(IwakudakiRes *res)
{
    ArcHandle *arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    int i;

    res->model = G3D_SYSTEM_CreateResourceArcHandle(arc, IWAKUDAKI_MODEL_FILE);
    G3D_SYSTEM_AllocVramTexture(res->model);
    res->uploadTask = GFL_USE_AddMainTask(FLDEFF_IWAKUDAKI_UploadTexturesTask, res, 0);
    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        res->anime[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, sIwakudakiAnimeFiles[i]);
}

void FLDEFF_IWAKUDAKI_FreeResources(IwakudakiRes *res)
{
    int i;

    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        G3D_SYSTEM_DeleteResource(res->anime[i]);
    G3D_SYSTEM_FreeVramTexture(res->model);
    G3D_SYSTEM_DeleteResource(res->model);
    TCB_DeleteTask(res->uploadTask);
}

/* Task: uploads the model textures to VRAM once. */
void FLDEFF_IWAKUDAKI_UploadTexturesTask(void *task, void *work)
{
    IwakudakiRes *res = work;

    if (res->texturesUploaded == 0) {
        G3D_SYSTEM_TransAllocatedTexture(res->model);
        res->texturesUploaded = 1;
    }
}

/* Starts the effect at the model position. */
void FLDEFF_IWAKUDAKI_Start(const Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    VecFx32 pos;
    IwakudakiStartParam param;
    int effectId;

    FLDMMDL_GetPos((struct Mmdl *)mmdl, (struct MmdlVec *)(&pos));
    pos.y += IWAKUDAKI_OFFSET_Y;
    pos.z += IWAKUDAKI_OFFSET_Z;
    if (FIELD_EFFECT_IsResourceLoaded(fieldEffect, FLDEFF_ID_IWAKUDAKI) == 0) {
        effectId = FLDEFF_ID_IWAKUDAKI;
        FIELD_EFFECT_LoadResources(fieldEffect, &effectId, 1);
    }
    param.res = (struct IwakudakiRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_IWAKUDAKI);
    param.pos = pos;
    FIELD_EFFECT_AddObject(fieldEffect, &sIwakudakiFuncs, 0, 0, &param, 0);
}

/* Effect init. */
void FLDEFF_IWAKUDAKI_Init(FieldEffectObj *effect, IwakudakiWork *work)
{
    IwakudakiStartParam *param = FIELD_EFFECT_GetObjectParam(effect);
    int i;

    work->res = param->res;
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
    work->render = G3D_SYSTEM_CreateRender(work->res->model, 0, work->res->model);
    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        work->anime[i] = G3D_SYSTEM_CreateAnime(work->render, work->res->anime[i], 0);
    work->object = G3D_SYSTEM_CreateObject(work->render, work->anime, IWAKUDAKI_ANIME_COUNT);
    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        G3D_SYSTEM_EnableObjectAnime(work->object, (u16)i);
}

/* Effect exit. */
void FLDEFF_IWAKUDAKI_Exit(void *task, IwakudakiWork *work)
{
    int i;

    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++)
        G3D_SYSTEM_DeleteAnime(work->anime[i]);
    G3D_SYSTEM_DeleteObject(work->object);
    G3D_SYSTEM_DeleteRender(work->render);
}

/* Effect update: advances the animations and ends the effect when all are done. */
void FLDEFF_IWAKUDAKI_Update(FieldEffectObj *effect, IwakudakiWork *work)
{
    int done = 1;
    int i;

    for (i = 0; i < IWAKUDAKI_ANIME_COUNT; i++) {
        if (G3D_SYSTEM_IncObjectAnimeFrame(work->object, (u16)i, IWAKUDAKI_ANIME_STEP) == 1)
            done = 0;
    }
    if (done)
        FIELD_EFFECT_DeleteObject(effect);
}

/* Effect draw. */
void FLDEFF_IWAKUDAKI_Draw(FieldEffectObj *effect, IwakudakiWork *work)
{
    G3dObjectStatus status = sIwakudakiDrawStatus;

    MTX_Identity33_(&status.rotate);
    FIELD_EFFECT_GetObjectPos(effect, &status.trans);
    G3D_SYSTEM_DrawObjectCulling(work->object, &status);
}
