/*
 * file:     field_g3dobj.c
 * unit:     yes
 * function: FIELD_G3DOBJ_Create, FIELD_G3DOBJ_Delete, FIELD_G3DOBJ_Update, FIELD_G3DOBJ_DrawAll, FIELD_G3DOBJ_SetPalTable, FIELD_G3DOBJ_AddResource, FIELD_G3DOBJ_AddResourceDefaultPal, FIELD_G3DOBJ_DeleteResource, FIELD_G3DOBJ_AddObject, FIELD_G3DOBJ_DeleteObject, FIELD_G3DOBJ_GetObjectTrans, FIELD_G3DOBJ_SetObjectTrans, FIELD_G3DOBJ_SetObjectHidden, FIELD_G3DOBJ_IncAnimeFrame, FIELD_G3DOBJ_LoopAnimeFrame, FIELD_G3DOBJ_SetAnimeFrame, FIELD_G3DOBJ_GetAnimeFrame, FIELD_G3DOBJ_SetObjectManualDraw, FIELD_G3DOBJ_DrawObject, FIELD_G3DOBJ_SetObjectRedrawFlag, FIELD_G3DOBJ_GetObjectRedrawFlag, FIELD_G3DOBJ_TransferResourceTexture, FIELD_G3DOBJ_LoadResource, FIELD_G3DOBJ_FreeResource, FIELD_G3DOBJ_CreateObject, FIELD_G3DOBJ_DestroyObject, FIELD_G3DOBJ_InitResDesc, FIELD_G3DOBJ_SetResDescModel, FIELD_G3DOBJ_SetResDescAnimeArc, FIELD_G3DOBJ_AddResDescAnimeFile
 * address:  0x021C63AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): starts at FIELD_G3DOBJ_Create 021C63AC; __FILE__ anchor field_g3dobj.c at 021C63FC (string 0x021DE4A8). The SWEET_SCENT_ code before it is event_sweet_scent.c.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gFieldG3dobjFileName     0x021DE4A8  data  ov021  a1
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateResourceArcHandle   0x02046E24  arm
 *   G3D_SYSTEM_CheckResourceType   0x02046F50  arm
 *   G3D_SYSTEM_GetResourceFile   0x02046F48  arm
 *   NNS_G3dGetTex   0x0206E964  arm
 *   PALANM_ConvertGrayTable   0x02022040  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   MI_CpuFill  0x02082C60  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 */
#include "../types.h"
#include "../arm9/g3d_system_types.h"
#include "field_g3dobj_types.h"

#include "../sdk_fx.h"

/* Opaque 3D system objects (layouts in arm9/g3d_system_types.h). */





#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/mi_memory.h"


#include "../arm9/fx_mtx33.h"

/* Palette block of a texture resource (NNSG3dResTex, only what is read here). */
typedef struct ResTexPltt {
    u8 pad00[0x30];
    u16 sizePltt;                          /* palette size in units of 8 bytes */
    u8 pad32[0x06];
    u32 ofsPlttData;
} ResTexPltt;

#include "../arm9/palanm.h"

#include "../arm9/nns_g3d_res.h"
struct G3dObjectStatus;

#include "../arm9/g3d_system.h"






struct ArcHandle;














extern char gFieldG3dobjFileName[];   /* source file name used as allocation site */

FieldG3dObjCtrl *FIELD_G3DOBJ_Create(u32 heapId, u32 resCount, u32 objCount);

void FIELD_G3DOBJ_Delete(FieldG3dObjCtrl *ctrl);

void FIELD_G3DOBJ_Update(FieldG3dObjCtrl *ctrl);

void FIELD_G3DOBJ_DrawAll(FieldG3dObjCtrl *ctrl);

void FIELD_G3DOBJ_SetPalTable(FieldG3dObjCtrl *ctrl, const u8 *palTable);

u16 FIELD_G3DOBJ_AddResource(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);

int FIELD_G3DOBJ_AddResourceDefaultPal(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode);

void FIELD_G3DOBJ_DeleteResource(FieldG3dObjCtrl *ctrl, int resIdx);

u16 FIELD_G3DOBJ_AddObject(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos);

void FIELD_G3DOBJ_DeleteObject(FieldG3dObjCtrl *ctrl, int objIdx);

struct G3dObjectStatus *FIELD_G3DOBJ_GetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx);

void FIELD_G3DOBJ_SetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos);

void FIELD_G3DOBJ_SetObjectHidden(FieldG3dObjCtrl *ctrl, int objIdx, int hidden);

int FIELD_G3DOBJ_IncAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed);

int FIELD_G3DOBJ_LoopAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed);

void FIELD_G3DOBJ_SetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame);

int FIELD_G3DOBJ_GetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx);

void FIELD_G3DOBJ_SetObjectManualDraw(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw);

void FIELD_G3DOBJ_DrawObject(FieldG3dObjCtrl *ctrl, int objIdx);

void FIELD_G3DOBJ_SetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag);

int FIELD_G3DOBJ_GetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx);

void FIELD_G3DOBJ_TransferResourceTexture(FieldG3dObjRes *res);

void FIELD_G3DOBJ_LoadResource(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable);

void FIELD_G3DOBJ_FreeResource(FieldG3dObjRes *res);

void FIELD_G3DOBJ_CreateObject(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults);

void FIELD_G3DOBJ_DestroyObject(FieldG3dObj *obj, FieldG3dObjRes *res);

void FIELD_G3DOBJ_InitResDesc(FieldG3dObjResDesc *desc);

void FIELD_G3DOBJ_SetResDescModel(FieldG3dObjResDesc *desc, u32 arc, u32 file);

void FIELD_G3DOBJ_SetResDescAnimeArc(FieldG3dObjResDesc *desc, u32 arc);

void FIELD_G3DOBJ_AddResDescAnimeFile(FieldG3dObjResDesc *desc, u16 file);

FieldG3dObjCtrl *FIELD_G3DOBJ_Create(u32 heapId, u32 resCount, u32 objCount)
{
    FieldG3dObjCtrl *ctrl;

    ctrl = GFL_HEAP_Alloc(heapId, sizeof(FieldG3dObjCtrl), 1, gFieldG3dobjFileName, 0x72);
    ctrl->resTbl = GFL_HEAP_Alloc(heapId, resCount * sizeof(FieldG3dObjRes), 1, gFieldG3dobjFileName, 0x75);
    ctrl->objTbl = GFL_HEAP_Alloc(heapId, objCount * sizeof(FieldG3dObj), 1, gFieldG3dobjFileName, 0x78);
    ctrl->heapId = heapId;
    ctrl->resCount = resCount;
    ctrl->objCount = objCount;
    ctrl->ready = 1;
    return ctrl;
}

void FIELD_G3DOBJ_Delete(FieldG3dObjCtrl *ctrl)
{
    u32 i;
    FieldG3dObj *obj;
    FieldG3dObjRes *res;

    i = 0;
    ctrl->ready = 0;
    obj = ctrl->objTbl;
    if (i < ctrl->objCount)
        for (; i < ctrl->objCount; i++) {
            if (obj->kind == FIELD_G3DOBJ_ACTIVE && obj->object != 0)
                FIELD_G3DOBJ_DestroyObject(obj, &ctrl->resTbl[obj->resIdx]);
            obj++;
        }
    GFL_HEAP_Free(ctrl->objTbl);
    i = 0;
    res = ctrl->resTbl;
    if (i < ctrl->resCount)
        for (; i < ctrl->resCount; i++) {
            FIELD_G3DOBJ_FreeResource(res);
            res++;
        }
    GFL_HEAP_Free(ctrl->resTbl);
    GFL_HEAP_Free(ctrl);
}

void FIELD_G3DOBJ_Update(FieldG3dObjCtrl *ctrl)
{
    int i;
    int j;
    FieldG3dObj *obj;
    FieldG3dObjRes *res;

    if (ctrl->ready == 1) {
        obj = ctrl->objTbl;
        res = ctrl->resTbl;
        for (i = 0; i < ctrl->resCount; i++) {
            if (res->state == FIELD_G3DOBJ_RES_PENDING)
                FIELD_G3DOBJ_TransferResourceTexture(res);
            res++;
        }
        res = ctrl->resTbl;
        for (j = 0; j < ctrl->objCount; j++) {
            if (obj->kind == FIELD_G3DOBJ_PENDING)
                FIELD_G3DOBJ_CreateObject(obj, &res[obj->resIdx], obj->resIdx, obj->modelIdx, ctrl->heapId, 0, 0);
            obj++;
        }
    }
}

void FIELD_G3DOBJ_DrawAll(FieldG3dObjCtrl *ctrl)
{
    u32 i;
    FieldG3dObj *obj;

    obj = ctrl->objTbl;
    for (i = 0; i < ctrl->objCount; i++) {
        if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
            if (obj->manualDraw == 0 && obj->hidden == 0) {
                if (obj->culling == 1)
                    G3D_SYSTEM_DrawObjectCulling(obj->object, &obj->status);
                else
                    G3D_SYSTEM_DrawObject(obj->object, &obj->status);
            }
            obj->redrawFlag = 0;
        }
        obj++;
    }
}

/*
 * Setter: stores the palette conversion table at +0x10.  Unlabelled in
 * the listing; called from FIELDMAP_SeqCreateSubsystems.
 */
void FIELD_G3DOBJ_SetPalTable(FieldG3dObjCtrl *ctrl, const u8 *palTable)
{
    ctrl->palTable = palTable;
}

u16 FIELD_G3DOBJ_AddResource(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode, const u8 *palTable)
{
    u16 i;
    FieldG3dObjRes *res = ctrl->resTbl;
    for (i = 0; i < ctrl->resCount; i++, res++) {
        if (res->model == 0) {
            FIELD_G3DOBJ_LoadResource(res, ctrl->heapId, desc, mode, palTable);
            return i;
        }
    }
    return 0;
}

int FIELD_G3DOBJ_AddResourceDefaultPal(FieldG3dObjCtrl *ctrl, FieldG3dObjResDesc *desc, int mode)
{
    return FIELD_G3DOBJ_AddResource(ctrl, desc, mode, ctrl->palTable);
}

/*
 * Tail call on a strided element of the resource table.
 */
void FIELD_G3DOBJ_DeleteResource(FieldG3dObjCtrl *ctrl, int resIdx)
{
    FIELD_G3DOBJ_FreeResource(&ctrl->resTbl[resIdx]);
}

u16 FIELD_G3DOBJ_AddObject(FieldG3dObjCtrl *ctrl, u16 resIdx, u16 modelIdx, VecFx32 *pos)
{
    u16 i;
    FieldG3dObj *obj;
    FieldG3dObjRes *res;

    obj = ctrl->objTbl;
    for (i = 0; i < ctrl->objCount; i++) {
        if (obj->kind == FIELD_G3DOBJ_FREE && obj->object == 0) {
            res = &ctrl->resTbl[resIdx];
            if (res->state == FIELD_G3DOBJ_RES_PENDING) {
                obj->resIdx = resIdx;
                obj->modelIdx = modelIdx;
                obj->kind = FIELD_G3DOBJ_PENDING;
                obj->culling = 1;
                obj->status.scale.x = 0x1000;
                obj->status.scale.y = 0x1000;
                obj->status.scale.z = 0x1000;
                if (pos != 0)
                    obj->status.trans = *pos;
                MTX_Identity33_(&obj->status.rotate);
            } else {
                FIELD_G3DOBJ_CreateObject(obj, res, resIdx, modelIdx, ctrl->heapId, pos, 1);
            }
            return i;
        }
        obj++;
    }
    return 0;
}

void FIELD_G3DOBJ_DeleteObject(FieldG3dObjCtrl *ctrl, int objIdx)
{
    FieldG3dObj *obj;
    obj = &ctrl->objTbl[objIdx];
    ctrl->ready = 0;
    if (obj->kind == FIELD_G3DOBJ_ACTIVE)
        FIELD_G3DOBJ_DestroyObject(obj, &ctrl->resTbl[obj->resIdx]);
    ctrl->ready = 1;
}

struct G3dObjectStatus *FIELD_G3DOBJ_GetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx)
{
    return &ctrl->objTbl[objIdx].status;
}

void FIELD_G3DOBJ_SetObjectTrans(FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos)
{
    ctrl->objTbl[objIdx].status.trans = *pos;
}

void FIELD_G3DOBJ_SetObjectHidden(FieldG3dObjCtrl *ctrl, int objIdx, int hidden)
{
    ctrl->objTbl[objIdx].hidden = hidden;
}

/*
 * Advances every animation of the object by speed, clamped at the ends.
 * Returns 1 when one of them moved or the object is not created yet.
 */
int FIELD_G3DOBJ_IncAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed)
{
    int result = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        for (i = result; i < count; i++) {
            if (G3D_SYSTEM_IncObjectAnimeFrame(obj->object, (u16)i, speed))
                result = 1;
        }
    } else if (obj->kind == FIELD_G3DOBJ_PENDING) {
        result = 1;
    }
    return result;
}

/* Same as FIELD_G3DOBJ_IncAnimeFrame, but the animations wrap at the ends. */
int FIELD_G3DOBJ_LoopAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int speed)
{
    int result = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        for (i = result; i < count; i++) {
            if (G3D_SYSTEM_LoopObjectAnimeFrame(obj->object, (u16)i, speed))
                result = 1;
        }
    } else if (obj->kind == FIELD_G3DOBJ_PENDING) {
        result = 1;
    }
    return result;
}

/*
 * push {r0-r3} entry (0x021C6744); the fourth parameter's address is taken.
 * animeIdx 8 sets every animation of the object.
 */
void FIELD_G3DOBJ_SetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx, s32 frame)
{
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    int count, i;

    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        count = ctrl->resTbl[obj->resIdx].animeCount;
        if (animeIdx == FIELD_G3DOBJ_ANIME_MAX) {
            i = 0;
            if (count > 0) {
                do {
                    G3D_SYSTEM_SetObjectAnimeFrame(obj->object, (u16)i, &frame);
                    i++;
                } while (i < count);
            }
        } else if (animeIdx < count) {
            G3D_SYSTEM_SetObjectAnimeFrame(obj->object, (u16)animeIdx, &frame);
        }
    }
}

int FIELD_G3DOBJ_GetAnimeFrame(FieldG3dObjCtrl *ctrl, int objIdx, int animeIdx)
{
    int frame = 0;
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    if (obj->kind == FIELD_G3DOBJ_ACTIVE) {
        if ((int)G3D_SYSTEM_GetObjectAnimeFrame(obj->object, (u16)animeIdx, &frame) == 0)
            frame = 0;
    }
    return frame;
}

void FIELD_G3DOBJ_SetObjectManualDraw(FieldG3dObjCtrl *ctrl, int objIdx, int manualDraw)
{
    ctrl->objTbl[objIdx].manualDraw = manualDraw;
}

/* Draws one object at once unless it is hidden. */
void FIELD_G3DOBJ_DrawObject(FieldG3dObjCtrl *ctrl, int objIdx)
{
    FieldG3dObj *obj = &ctrl->objTbl[objIdx];
    if (obj->kind == FIELD_G3DOBJ_ACTIVE && obj->hidden == 0) {
        if (obj->culling == 1)
            G3D_SYSTEM_DrawObjectCulling(obj->object, &obj->status);
        else
            G3D_SYSTEM_DrawObject(obj->object, &obj->status);
    }
}

void FIELD_G3DOBJ_SetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx, int redrawFlag)
{
    ctrl->objTbl[objIdx].redrawFlag = redrawFlag;
}

int FIELD_G3DOBJ_GetObjectRedrawFlag(FieldG3dObjCtrl *ctrl, int objIdx)
{
    return ctrl->objTbl[objIdx].redrawFlag;
}

/* Sends the texture of the resource to VRAM. */
void FIELD_G3DOBJ_TransferResourceTexture(FieldG3dObjRes *res)
{
    res->state = FIELD_G3DOBJ_RES_FREE;
    if (res->texture != 0)
        G3D_SYSTEM_TransVramTexture(res->texture);
    else
        G3D_SYSTEM_TransVramTexture(res->model);
    res->state = FIELD_G3DOBJ_RES_READY;
}

void FIELD_G3DOBJ_LoadResource(FieldG3dObjRes *res, int heapId, FieldG3dObjResDesc *desc, int mode, const u8 *palTable)
{
    G3dResource *palRes;
    ResTexPltt *tex;
    int i;

    if (desc->modelArc != 0)
        res->model = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)desc->modelArc, desc->modelFile);
    if (desc->texArc != 0)
        res->texture = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)desc->texArc, desc->texFile);
    if (palTable != 0) {
        palRes = 0;
        if (res->model != 0)
            palRes = res->model;
        if (res->texture != 0)
            palRes = res->texture;
        if (G3D_SYSTEM_CheckResourceType(palRes, 2)) {
            tex = (struct ResTexPltt *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(palRes));
            PALANM_ConvertGrayTable((u16 *)((u8 *)tex + tex->ofsPlttData), (u32)(tex->sizePltt << 3) / sizeof(u16), palTable);
        }
    }
    if (res->model != 0 || res->texture != 0) {
        if (mode == 1)
            FIELD_G3DOBJ_TransferResourceTexture(res);
        else
            res->state = FIELD_G3DOBJ_RES_PENDING;
    }
    if (desc->anmCount != 0) {
        res->animeCount = desc->anmCount;
        MIi_CpuClear32(0, res->anime, sizeof(res->anime));
        for (i = 0; i < res->animeCount; i++)
            res->anime[i] = G3D_SYSTEM_CreateResourceArcHandle((struct ArcHandle *)desc->anmArc, desc->anmFile[i]);
    }
}

void FIELD_G3DOBJ_FreeResource(FieldG3dObjRes *res)
{
    int i;
    u8 state = res->state;

    res->state = FIELD_G3DOBJ_RES_FREE;
    if (state == FIELD_G3DOBJ_RES_READY) {
        if (res->texture != 0)
            G3D_SYSTEM_FreeVramTexture(res->texture);
        else if (res->model != 0)
            G3D_SYSTEM_FreeVramTexture(res->model);
    }
    if (res->texture != 0)
        G3D_SYSTEM_DeleteResource(res->texture);
    if (res->model != 0)
        G3D_SYSTEM_DeleteResource(res->model);
    if (res->animeCount != 0) {
        for (i = 0; i < res->animeCount; i++)
            G3D_SYSTEM_DeleteResource(res->anime[i]);
    }
    MI_CpuFill(res, 0, sizeof(FieldG3dObjRes));
    res->state = FIELD_G3DOBJ_RES_READY;
}

/*
 * The unused 5th parameter (heapId) puts pos and initDefaults at sp+0x1c and
 * sp+0x20.  G3D_SYSTEM_CreateObject takes the animation count as a third argument
 * (the last animeCount load is reused in r2).
 */
void FIELD_G3DOBJ_CreateObject(FieldG3dObj *obj, FieldG3dObjRes *res, u16 resIdx, u16 modelIdx, u32 heapId, VecFx32 *pos, int initDefaults)
{
    int i;
    G3dRender *render;
    G3dResource *texRes;

    texRes = 0;
    obj->resIdx = resIdx;
    obj->modelIdx = modelIdx;
    if (res->state == FIELD_G3DOBJ_RES_READY) {
        texRes = res->model;
        if (res->texture != 0)
            texRes = res->texture;
    }
    render = G3D_SYSTEM_CreateRender(res->model, modelIdx, texRes);
    if (res->animeCount != 0) {
        MIi_CpuClear32(0, obj->anime, sizeof(obj->anime));
        for (i = 0; i < res->animeCount; i++)
            obj->anime[i] = G3D_SYSTEM_CreateAnime(render, res->anime[i], 0);
    }
    obj->object = G3D_SYSTEM_CreateObject(render, obj->anime, res->animeCount);
    if (res->animeCount != 0) {
        for (i = 0; i < res->animeCount; i++)
            G3D_SYSTEM_EnableObjectAnime(obj->object, (u16)i);
    }
    if (pos != 0)
        obj->status.trans = *pos;
    if (initDefaults != 0) {
        obj->culling = 1;
        obj->status.scale.x = 0x1000;
        obj->status.scale.y = 0x1000;
        obj->status.scale.z = 0x1000;
        MTX_Identity33_(&obj->status.rotate);
    }
    obj->kind = FIELD_G3DOBJ_ACTIVE;
}

void FIELD_G3DOBJ_DestroyObject(FieldG3dObj *obj, FieldG3dObjRes *res)
{
    G3dRender *render;
    int i;

    if (obj->anime) {
        for (i = 0; i < res->animeCount; i++)
            G3D_SYSTEM_DeleteAnime(obj->anime[i]);
    }
    if (obj->object != 0) {
        render = G3D_SYSTEM_GetObjectRender(obj->object);
        G3D_SYSTEM_DeleteObject(obj->object);
        G3D_SYSTEM_DeleteRender(render);
    }
    MI_CpuFill(obj, 0, sizeof(FieldG3dObj));
}

/*
 * Tail call with a zero first argument and a constant size.
 */
void FIELD_G3DOBJ_InitResDesc(FieldG3dObjResDesc *desc)
{
    MIi_CpuClear32(0, desc, sizeof(FieldG3dObjResDesc));
}

void FIELD_G3DOBJ_SetResDescModel(FieldG3dObjResDesc *desc, u32 arc, u32 file)
{
    desc->modelArc = arc;
    desc->modelFile = file;
}

void FIELD_G3DOBJ_SetResDescAnimeArc(FieldG3dObjResDesc *desc, u32 arc)
{
    desc->anmArc = arc;
}

void FIELD_G3DOBJ_AddResDescAnimeFile(FieldG3dObjResDesc *desc, u16 file)
{
    desc->anmFile[desc->anmCount] = file;
    desc->anmCount++;
}
