/*
 * file:     fldeff_fishing.c
 * unit:     yes
 * function: FLDEFF_FISHING_Create, FLDEFF_FISHING_Delete, FLDEFF_FISHING_LoadResources, FLDEFF_FISHING_FreeResources, FLDEFF_FISHING_Start, FLDEFF_FISHING_SetAnimeSpeed, FLDEFF_FISHING_Init, FLDEFF_FISHING_Exit, FLDEFF_FISHING_Update, FLDEFF_FISHING_Draw
 * address:  0x021ADEDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_iwakudaki.c at 0x021ADEDC (lane FXC, CL126: __FILE__ fldeff_fishing.c on 0x021ADEFC, resources 0x18, caller field_g3dobj.c is the fishing event).
 *
 * symbols:
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   sFldeffFishingFileName  0x021DE124  data
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   sFishingAnimeFile     0x021DE120  data  a2
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   _s32_to_float  0x0209BDBC  arm
 *   __fadd  0x0209C95C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   sFishingRodOffsets     0x021D92E0  data  a1
 *   sFishingFuncs     0x021D92E8  data  a4
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   sFishingDrawStatus  0x021D92FC  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   _fadd                        0x0209C95C  arm
 *   _fflt                        0x0209BDBC  arm
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

/* Converts a float constant to 20.12 fixed point, rounding away from zero. */
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

/* Id of the fishing rod resources in the field effect system. */
#define FLDEFF_ID_FISHING 13

/* File of the model in the effect archive. */
#define FISHING_MODEL_FILE 0x54

/* Depth offset of the rod per rod kind, for each side of the cast. */
typedef struct FishingRodOffsets {
    u8 offset[2][4];
} FishingRodOffsets;

/* Resources of the fishing rod effect (allocated 0x18 bytes by FLDEFF_FISHING_Create). */
typedef struct FishingRodRes {
    FieldEffectSys *fieldEffect;                   /* 0x00 */
    G3dResource *model;                            /* 0x04 */
    G3dResource *anime;                            /* 0x08 */
    G3dObject *object;                             /* 0x0C */
    G3dAnime *animeObj;                            /* 0x10 */
    G3dRender *render;                             /* 0x14 */
} FishingRodRes;

/* Start parameter of the effect. */
typedef struct FishingRodStartParam {
    FishingRodRes *res;
    VecFx32 pos;
} FishingRodStartParam;

/* Work of the fishing rod effect. */
typedef struct FishingRodWork {
    FishingRodRes *res;                               /* 0x00 */
    u16 animeSpeed;                                /* 0x04 frame step is 2 * animeSpeed + 1 */
    u16 animeSpeedSet;                             /* 0x06 */
} FishingRodWork;

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
extern int G3D_SYSTEM_TransVramTexture(G3dResource *res);
extern void G3D_SYSTEM_DeleteResource(G3dResource *res);
extern int G3D_SYSTEM_FreeVramTexture(G3dResource *res);
extern s32 FIELD_EFFECT_GetResource(struct FieldEffectSys *sys, s32 id);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *effect);
extern void FIELD_EFFECT_SetObjectPos(FieldEffectObj *effect, const VecFx32 *pos);
extern void *FIELD_EFFECT_GetObjectWork(FieldEffectObj *effect);
extern G3dRender *G3D_SYSTEM_CreateRender(G3dResource *mdlRes, u32 mdlIdx, G3dResource *texRes);
extern G3dAnime *G3D_SYSTEM_CreateAnime(struct G3dRender *render, struct G3dResource *anmRes, u32 anmIdx);
extern G3dObject *G3D_SYSTEM_CreateObject(G3dRender *render, G3dAnime **anmTbl, int anmCount);
extern s32 G3D_SYSTEM_EnableObjectAnime(G3dObject *obj, u32 anmIdx);
extern void G3D_SYSTEM_DeleteAnime(G3dAnime *anime);
extern void G3D_SYSTEM_DeleteObject(G3dObject *obj);
extern void G3D_SYSTEM_DeleteRender(G3dRender *render);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(G3dObject *obj, int anmIdx, fx32 step);
FishingRodRes *FLDEFF_FISHING_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_FISHING_Delete(FieldEffectSys *fieldEffect, FishingRodRes *res);
void FLDEFF_FISHING_LoadResources(FishingRodRes *res);
void FLDEFF_FISHING_FreeResources(FishingRodRes *res);
void FLDEFF_FISHING_Start(FieldEffectSys *fieldEffect, const VecFx32 *pos, u32 rodKind, u32 side);
void FLDEFF_FISHING_SetAnimeSpeed(FieldEffectObj *effect, u16 animeSpeed);
void FLDEFF_FISHING_Init(FieldEffectObj *effect, FishingRodWork *work);
void FLDEFF_FISHING_Exit(void);
void FLDEFF_FISHING_Update(FieldEffectObj *effect, FishingRodWork *work);
void FLDEFF_FISHING_Draw(FieldEffectObj *effect, FishingRodWork *work);

extern char sFldeffFishingFileName[];                              /* source file name for the heap allocator */
extern u16 sFishingAnimeFile;                                 /* animation file id */
extern FishingRodOffsets sFishingRodOffsets;                   /* rod depth offsets */
extern const FieldEffectObjFuncs sFishingFuncs;           /* fishing rod effect callbacks */
extern G3dObjectStatus sFishingDrawStatus;                     /* draw status template */
/* Loads the resources of the fishing rod effect. */
FishingRodRes *FLDEFF_FISHING_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    FishingRodRes *res = GFL_HEAP_Alloc(heapId, 0x18, 1, sFldeffFishingFileName, 0x60);
    res->fieldEffect = fieldEffect;
    FLDEFF_FISHING_LoadResources(res);
    return res;
}

void FLDEFF_FISHING_Delete(FieldEffectSys *fieldEffect, FishingRodRes *res)
{
    FLDEFF_FISHING_FreeResources(res);
    GFL_HEAP_Free(res);
}

void FLDEFF_FISHING_LoadResources(FishingRodRes *res)
{
    ArcHandle *arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(res->fieldEffect);

    res->model = G3D_SYSTEM_CreateResourceArcHandle(arc, FISHING_MODEL_FILE);
    G3D_SYSTEM_TransVramTexture(res->model);
    res->anime = G3D_SYSTEM_CreateResourceArcHandle(arc, sFishingAnimeFile);
    res->render = G3D_SYSTEM_CreateRender(res->model, 0, res->model);
    res->animeObj = G3D_SYSTEM_CreateAnime(res->render, res->anime, 0);
    res->object = G3D_SYSTEM_CreateObject(res->render, &res->animeObj, 1);
    G3D_SYSTEM_EnableObjectAnime(res->object, 0);
}

void FLDEFF_FISHING_FreeResources(FishingRodRes *res)
{
    G3D_SYSTEM_DeleteObject(res->object);
    G3D_SYSTEM_DeleteAnime(res->animeObj);
    G3D_SYSTEM_DeleteRender(res->render);
    G3D_SYSTEM_DeleteResource(res->anime);
    G3D_SYSTEM_FreeVramTexture(res->model);
    G3D_SYSTEM_DeleteResource(res->model);
}

/* Starts the rod effect; the depth depends on the rod kind and the side of the cast. */
void FLDEFF_FISHING_Start(FieldEffectSys *fieldEffect, const VecFx32 *pos, u32 rodKind, u32 side)
{
    FishingRodOffsets offsets = sFishingRodOffsets;
    FishingRodStartParam param;
    int offset;
    float fixed;

    param.res = (struct FishingRodRes *)FIELD_EFFECT_GetResource(fieldEffect, FLDEFF_ID_FISHING);
    param.pos = *pos;
    offset = offsets.offset[side][rodKind];
    if (offset != 0) {
        fixed = (0.5f + (float)(offset << 12));
    } else {
        fixed = ((float)(offset << 12) - 0.5f);
    }
    param.pos.z += (int)fixed;
    FIELD_EFFECT_AddObject(fieldEffect, &sFishingFuncs, 0, 0, &param, 0);
}

/* Sets the animation speed level of the rod effect (1 when a fish bites). */
void FLDEFF_FISHING_SetAnimeSpeed(FieldEffectObj *effect, u16 animeSpeed)
{
    FishingRodWork *work;

    if (effect != 0) {
        work = FIELD_EFFECT_GetObjectWork(effect);
        work->animeSpeedSet = 1;
        work->animeSpeed = animeSpeed;
    }
}

/* Effect init. */
void FLDEFF_FISHING_Init(FieldEffectObj *effect, FishingRodWork *work)
{
    FishingRodStartParam *param = FIELD_EFFECT_GetObjectParam(effect);

    work->res = param->res;
    FIELD_EFFECT_SetObjectPos(effect, &param->pos);
}

/* Effect exit. */
void FLDEFF_FISHING_Exit(void)
{
}

/* Effect update: loops the animation at a speed of 2 * animeSpeed + 1 frames. */
void FLDEFF_FISHING_Update(FieldEffectObj *effect, FishingRodWork *work)
{
    FishingRodRes *res = work->res;
    G3D_SYSTEM_LoopObjectAnimeFrame(res->object, 0, FX_F32_TO_FX32(work->animeSpeed * 2 + 1));
}

/* Effect draw. */
void FLDEFF_FISHING_Draw(FieldEffectObj *effect, FishingRodWork *work)
{
    FishingRodRes *res = work->res;
    G3dObjectStatus status = sFishingDrawStatus;

    MTX_Identity33_(&status.rotate);
    FIELD_EFFECT_GetObjectPos(effect, &status.trans);
    G3D_SYSTEM_DrawObjectCulling(res->object, &status);
}
