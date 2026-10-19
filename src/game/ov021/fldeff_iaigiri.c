/*
 * file:     fldeff_iaigiri.c
 * unit:     yes
 * function: FLDEFF_IAIGIRI_Create, FLDEFF_IAIGIRI_Delete, FLDEFF_IAIGIRI_LoadResources, FLDEFF_IAIGIRI_FreeResources, FLDEFF_IAIGIRI_Start, FLDEFF_IAIGIRI_Init, FLDEFF_IAIGIRI_Exit, FLDEFF_IAIGIRI_Update, FLDEFF_IAIGIRI_Draw
 * address:  0x021C94BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C94BC: fldeff_iaigiri.c __FILE__ anchor at 0x021C94BC.
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   sFldeffIaigiriFileName  0x021DE578  data  ov021  a4
 *   sIaigiriAnimeFiles  0x021DE56C  data  ov021  a4
 *   sIaigiriFuncs     0x021DAC80  data  a4
 *   sIaigiriDrawStatus  0x021DAC94  data  ov021  a4
 */
#include "../ov010/fldmmdl_types.h"

#include "../types.h"

#include "../sdk_fx.h"

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

/* Id of the Cut resources in the field effect system. */
#define FLDEFF_ID_IAIGIRI 0xc

#define IAIGIRI_ANIME_COUNT 3

/* File of the model in the effect archive. */
#define IAIGIRI_MODEL_FILE 0x52

/* Facing directions of a field model. */
#define IAIGIRI_DIR_UP    0
#define IAIGIRI_DIR_DOWN  1
#define IAIGIRI_DIR_LEFT  2
#define IAIGIRI_DIR_RIGHT 3

/* One tile in fixed point. */
#define IAIGIRI_TILE_SIZE 0x10000

/* Fixed-point step added to the animation frame each update (one frame). */
#define IAIGIRI_ANIME_STEP 0x1000

/* Resources of the Cut effect (allocated 0x1C bytes by FLDEFF_IAIGIRI_Create). */
typedef struct IaigiriRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model;                            /* 0x04 */
    G3dResource *anime[IAIGIRI_ANIME_COUNT];       /* 0x08 */
    u8 pad14[0x1C - 0x14];
} IaigiriRes;

/* Start parameter of the effect. */
typedef struct IaigiriStartParam {
    IaigiriRes *res;
    VecFx32 pos;
} IaigiriStartParam;

/* Work of the Cut effect: three animations of one model that play to their end. */
typedef struct IaigiriTaskWork {
    IaigiriRes *res;                               /* 0x00 */
    G3dObject *object;                             /* 0x04 */
    G3dAnime *anime[IAIGIRI_ANIME_COUNT];          /* 0x08 */
    G3dRender *render;                             /* 0x14 */
} IaigiriTaskWork;

extern u16 FLDMMDL_GetDirDisp(const Mmdl *mmdl);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);
extern int G3D_SYSTEM_TransVramTexture(G3dResource *res);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *G3D_SYSTEM_CreateAnime(struct G3dRender *render, struct G3dResource *anmRes, u32 anmIdx);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern s32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
extern void G3D_SYSTEM_DeleteResource(G3dResource *res);
struct MmdlVec;
struct Mmdl;
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern s32 FIELD_EFFECT_GetResource(struct FieldEffectSys *sys, s32 id);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern void FIELD_EFFECT_SetObjectPos(FieldEffectObj *effect, const VecFx32 *pos);
extern void FIELD_EFFECT_DeleteObject(FieldEffectObj *effect);
extern int G3D_SYSTEM_IncObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
extern void MTX_Identity33_(MtxFx33 *mtx);
extern void FIELD_EFFECT_GetObjectPos(FieldEffectObj *effect, VecFx32 *out);
extern int G3D_SYSTEM_DrawObjectCulling(G3dObject *obj, G3dObjectStatus *status);

IaigiriRes *FLDEFF_IAIGIRI_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_IAIGIRI_Delete(FieldEffectSys *fieldEffect, IaigiriRes *res);
void FLDEFF_IAIGIRI_LoadResources(IaigiriRes *res);
void FLDEFF_IAIGIRI_FreeResources(IaigiriRes *res);
void FLDEFF_IAIGIRI_Start(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void FLDEFF_IAIGIRI_Init(FieldEffectObj *effect, IaigiriTaskWork *work);
void FLDEFF_IAIGIRI_Exit(void *task, IaigiriTaskWork *work);
void FLDEFF_IAIGIRI_Update(FieldEffectObj *effect, IaigiriTaskWork *work);
void FLDEFF_IAIGIRI_Draw(FieldEffectObj *effect, IaigiriTaskWork *work);
extern char sFldeffIaigiriFileName[];                              /* source file name for the heap allocator */
extern u32 sIaigiriAnimeFiles[IAIGIRI_ANIME_COUNT];            /* animation file ids */
extern const FieldEffectObjFuncs sIaigiriFuncs;           /* effect callbacks */
extern G3dObjectStatus sIaigiriDrawStatus;                     /* draw status template */

/* Loads the resources of the Cut effect. */
IaigiriRes *FLDEFF_IAIGIRI_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    IaigiriRes *res = GFL_HEAP_Alloc(heapId, 0x1c, 1, sFldeffIaigiriFileName, 0x66);
    res->fieldEffect = fieldEffect;
    FLDEFF_IAIGIRI_LoadResources(res);
    return res;
}

void FLDEFF_IAIGIRI_Delete(FieldEffectSys *fieldEffect, IaigiriRes *res)
{
    FLDEFF_IAIGIRI_FreeResources(res);
    GFL_HEAP_Free(res);
}

void FLDEFF_IAIGIRI_LoadResources(IaigiriRes *res)
{
    ArcHandle *arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(res->fieldEffect);
    int i;
    res->model = G3D_SYSTEM_CreateResourceArcHandle(arc, IAIGIRI_MODEL_FILE);
    G3D_SYSTEM_TransVramTexture(res->model);
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        res->anime[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, sIaigiriAnimeFiles[i]);
}

void FLDEFF_IAIGIRI_FreeResources(IaigiriRes *res)
{
    int i;
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        G3D_SYSTEM_DeleteResource(res->anime[i]);
    G3D_SYSTEM_FreeVramTexture(res->model);
    G3D_SYSTEM_DeleteResource(res->model);
}

/* Starts the effect on the tile in front of the model. */
void FLDEFF_IAIGIRI_Start(const Mmdl *mmdl, FieldEffectSys *fieldEffect)
{
    VecFx32 pos;
    IaigiriStartParam param;

    FLDMMDL_GetPos((struct Mmdl *)mmdl, (struct MmdlVec *)(&pos));
    switch (FLDMMDL_GetDirDisp(mmdl)) {
    case IAIGIRI_DIR_UP:
        pos.z -= IAIGIRI_TILE_SIZE;
        break;
    case IAIGIRI_DIR_DOWN:
        pos.z += IAIGIRI_TILE_SIZE;
        break;
    case IAIGIRI_DIR_LEFT:
        pos.x -= IAIGIRI_TILE_SIZE;
        break;
    case IAIGIRI_DIR_RIGHT:
        pos.x += IAIGIRI_TILE_SIZE;
        break;
    }
    param.res = (struct IaigiriRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_IAIGIRI);
    param.pos = pos;
    FIELD_EFFECT_AddObject(fieldEffect, &sIaigiriFuncs, 0, 0, &param, 0);
}

/*
 * Effect init. The `adds r4, r6, #0` before the first loop is the second
 * loop's counter initialised to 0 and shared as the first loop's constant 0
 * argument; both loops use one counter i.
 */
void FLDEFF_IAIGIRI_Init(FieldEffectObj *effect, IaigiriTaskWork *work)
{
    IaigiriStartParam *param = FIELD_EFFECT_GetObjectParam(effect);
    int i;

    work->res = param->res;
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
    work->render = G3D_SYSTEM_CreateRender(work->res->model, 0, work->res->model);
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        work->anime[i] = G3D_SYSTEM_CreateAnime(work->render, work->res->anime[i], 0);
    work->object = G3D_SYSTEM_CreateObject(work->render, work->anime, IAIGIRI_ANIME_COUNT);
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        G3D_SYSTEM_EnableObjectAnime(work->object, (u16)i);
}

/* Effect exit. */
void FLDEFF_IAIGIRI_Exit(void *task, IaigiriTaskWork *work)
{
    int i;
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++)
        G3D_SYSTEM_DeleteAnime(work->anime[i]);
    G3D_SYSTEM_DeleteObject(work->object);
    G3D_SYSTEM_DeleteRender(work->render);
}

/* Effect update: advances the animations and ends the effect when all are done. */
void FLDEFF_IAIGIRI_Update(FieldEffectObj *effect, IaigiriTaskWork *work)
{
    int done = 1;
    int i;
    for (i = 0; i < IAIGIRI_ANIME_COUNT; i++) {
        if (G3D_SYSTEM_IncObjectAnimeFrame(work->object, (u16)i, IAIGIRI_ANIME_STEP) == 1)
            done = 0;
    }
    if (done)
        FIELD_EFFECT_DeleteObject(effect);
}

/* Effect draw. */
void FLDEFF_IAIGIRI_Draw(FieldEffectObj *effect, IaigiriTaskWork *work)
{
    G3dObjectStatus status = sIaigiriDrawStatus;
    MTX_Identity33_(&status.rotate);
    FIELD_EFFECT_GetObjectPos(effect, &status.trans);
    G3D_SYSTEM_DrawObjectCulling(work->object, &status);
}
