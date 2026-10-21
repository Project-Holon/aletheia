/*
 * file:     fldeff_kemuri.c
 * unit:     yes
 * function: FLDEFF_KEMURI_Create, FLDEFF_KEMURI_Delete, FLDEFF_KEMURI_LoadResource, FLDEFF_KEMURI_FreeResource, FLDEFF_KEMURI_Start, FLDEFF_KEMURI_StartFacing, FLDEFF_KEMURI_Init, FLDEFF_KEMURI_Exit, FLDEFF_KEMURI_Update, FLDEFF_KEMURI_Draw
 * address:  0x021AC494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AC494: __FILE__ fldeff_kemuri.c on 0x021AC494 (init, first
 * function).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FX_SinCosTable_   0x020A1B38  data  a2
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   d_021DE038  0x021DE038  data
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   gFldeffKemuriObjFuncs     0x021D90AC  data  a4
 *   FLDMMDL_SysGetAreaId  0x0216D538  thumb  ov010
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_IncAnimeFrame  0x021C6694  thumb  ov021
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 */
#include "field_effect_types.h"
#include "field_g3dobj_types.h"
#include "../ov010/fldmmdl_types.h"

/* Id of the smoke (kemuri) resource in the field effect system. */
#define FLDEFF_ID_KEMURI 1

/* Files of the smoke model and its animation in the effect archive. */
#define FLDEFF_KEMURI_MODEL_FILE 0x30
#define FLDEFF_KEMURI_ANIME_FILE 0x60

/* The smoke appears this far above the model and this far in front of it. */
#define FLDEFF_KEMURI_RAISE   0x1000
#define FLDEFF_KEMURI_FORWARD 0x6000

/* Fixed-point step added to the animation frame each update (one frame). */
#define FLDEFF_KEMURI_ANIME_STEP 0x1000



/* Resource of the smoke effect (8 bytes): the G3D resource of the smoke model. */
typedef struct FldeffKemuri {
    FieldEffectSys *fieldEffect;          /* 0x00 */
    u16 resIdx;                           /* 0x04 resource index in the G3D object control */
    u8 pad06[2];
} FldeffKemuri;

/* Start parameter of one smoke (0x10 bytes). */
typedef struct FldeffKemuriParam {
    FldeffKemuri *kemuri;
    VecFx32 pos;
} FldeffKemuriParam;

/* Work of one smoke (0x0C bytes). */
typedef struct FldeffKemuriWork {
    FldeffKemuri *kemuri;                 /* 0x00 */
    FieldG3dObjCtrl *g3dObjCtrl;          /* 0x04 */
    u16 objIdx;                           /* 0x08 object index in the G3D object control */
} FldeffKemuriWork;

#include "../arm9/gfl_heap_wrap.h"
struct VecFx32;
struct Mmdl;
#include "../ov010/fldmmdl.h"
struct MmdlSys;
#include "field_g3dobj.h"
#include "field_effect.h"
struct FieldEffectSys;
FldeffKemuri *FLDEFF_KEMURI_Create(FieldEffectSys *sys, int heapId);
void FLDEFF_KEMURI_Delete(FieldEffectSys *sys, FldeffKemuri *kemuri);
void FLDEFF_KEMURI_LoadResource(FldeffKemuri *kemuri);
void FLDEFF_KEMURI_FreeResource(FldeffKemuri *kemuri);
void FLDEFF_KEMURI_Start(Mmdl *mmdl, FieldEffectSys *sys);
void FLDEFF_KEMURI_StartFacing(Mmdl *mmdl, FieldEffectSys *sys);
void FLDEFF_KEMURI_Init(FieldEffectObj *obj, FldeffKemuriWork *work);
void FLDEFF_KEMURI_Exit(FieldEffectObj *obj, FldeffKemuriWork *work);
void FLDEFF_KEMURI_Update(FieldEffectObj *obj, FldeffKemuriWork *work);
void FLDEFF_KEMURI_Draw(void);
extern s16 FX_SinCosTable_[];
extern char d_021DE038[];
extern FieldEffectObjFuncs gFldeffKemuriObjFuncs;

/* Resource creation: allocates the resource and loads the smoke model. */
FldeffKemuri *FLDEFF_KEMURI_Create(FieldEffectSys *sys, int heapId)
{
    FldeffKemuri *kemuri;

    kemuri = GFL_HEAP_Alloc(heapId, sizeof(FldeffKemuri), 1, d_021DE038, 0x52);
    kemuri->fieldEffect = sys;
    FLDEFF_KEMURI_LoadResource(kemuri);
    return kemuri;
}








/* Resource deletion: frees the G3D resource and the resource. */
void FLDEFF_KEMURI_Delete(FieldEffectSys *sys, FldeffKemuri *kemuri)
{
    FLDEFF_KEMURI_FreeResource(kemuri);
    GFL_HEAP_Free(kemuri);
}








/* Loads the smoke model and its animation into the G3D object control. */
void FLDEFF_KEMURI_LoadResource(FldeffKemuri *kemuri)
{
    FieldG3dObjResDesc desc;
    FieldG3dObjCtrl *g3dObjCtrl = FIELD_EFFECT_GetFieldMapData(kemuri->fieldEffect);
    struct ArcHandle *arcHandle = FIELD_EFFECT_GetArcHandle(kemuri->fieldEffect);
    FIELD_G3DOBJ_InitResDesc(&desc);
    FIELD_G3DOBJ_SetResDescModel(&desc, arcHandle, FLDEFF_KEMURI_MODEL_FILE);
    FIELD_G3DOBJ_SetResDescAnimeArc(&desc, arcHandle);
    FIELD_G3DOBJ_AddResDescAnimeFile(&desc, FLDEFF_KEMURI_ANIME_FILE);
    kemuri->resIdx = FIELD_G3DOBJ_AddResourceDefaultPal(g3dObjCtrl, &desc, 0);
}








/* Frees the G3D resource of the smoke model. */
void FLDEFF_KEMURI_FreeResource(FldeffKemuri *kemuri)
{
    FIELD_G3DOBJ_DeleteResource(FIELD_EFFECT_GetFieldMapData(kemuri->fieldEffect), kemuri->resIdx);
}








/* Starts a smoke in front of a model. */
void FLDEFF_KEMURI_Start(Mmdl *mmdl, FieldEffectSys *sys)
{
    VecFx32 pos;
    FldeffKemuriParam param;
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&pos));
    pos.y += FLDEFF_KEMURI_RAISE;
    pos.z += FLDEFF_KEMURI_FORWARD;
    param.kemuri = (struct FldeffKemuri *)FIELD_EFFECT_GetResource(sys, FLDEFF_ID_KEMURI);
    param.pos = pos;
    FIELD_EFFECT_AddObject(sys, &gFldeffKemuriObjFuncs, 0, 0, &param, 0);
}






/* Starts a smoke on the side a model faces. */
void FLDEFF_KEMURI_StartFacing(Mmdl *mmdl, FieldEffectSys *sys)
{
    VecFx32 pos;
    FldeffKemuriParam param;
    int dirIndex;
    dirIndex = FLDMMDL_SysGetAreaId(FLDMMDL_GetMmdlSys(mmdl));
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&pos));
    pos.y += FLDEFF_KEMURI_RAISE;
    dirIndex = (dirIndex >> 4) * 2;
    pos.z += (s32)(((long long)FX_SinCosTable_[dirIndex + 1] * FLDEFF_KEMURI_FORWARD + 0x800) >> 12);
    pos.x += (s32)(((long long)FX_SinCosTable_[dirIndex] * FLDEFF_KEMURI_FORWARD + 0x800) >> 12);
    param.kemuri = (struct FldeffKemuri *)FIELD_EFFECT_GetResource(sys, FLDEFF_ID_KEMURI);
    param.pos = pos;
    FIELD_EFFECT_AddObject(sys, &gFldeffKemuriObjFuncs, 0, 0, &param, 0);
}






/* Smoke effect: init, puts the smoke object at the start position. */
void FLDEFF_KEMURI_Init(FieldEffectObj *obj, FldeffKemuriWork *work)
{
    FldeffKemuriParam *param = FIELD_EFFECT_GetObjectParam(obj);
    work->kemuri = param->kemuri;
    work->g3dObjCtrl = FIELD_EFFECT_GetFieldMapData(work->kemuri->fieldEffect);
    FIELD_EFFECT_SetObjectPos(obj, &param->pos);
    work->objIdx = FIELD_G3DOBJ_AddObject(work->g3dObjCtrl, work->kemuri->resIdx, 0, &param->pos);
}




/* Smoke effect: exit, deletes the smoke object. */
void FLDEFF_KEMURI_Exit(FieldEffectObj *obj, FldeffKemuriWork *work)
{
    FIELD_G3DOBJ_DeleteObject(work->g3dObjCtrl, work->objIdx);
}




/* Smoke effect: update, plays the animation and ends the effect when it is over. */
void FLDEFF_KEMURI_Update(FieldEffectObj *obj, FldeffKemuriWork *work)
{
    if (FIELD_G3DOBJ_IncAnimeFrame(work->g3dObjCtrl, work->objIdx, FLDEFF_KEMURI_ANIME_STEP) == 0)
        FIELD_EFFECT_DeleteObject(obj);
}




/* Smoke effect: draw, nothing to do (the G3D object control draws the object). */
void FLDEFF_KEMURI_Draw(void)
{
}
