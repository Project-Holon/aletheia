/*
 * file:     fldeff_gyoe.c
 * unit:     yes
 * function: FLDEFF_GYOE_Init, FLDEFF_GYOE_Delete, FLDEFF_GYOE_InitResource, FLDEFF_GYOE_DeleteResource, FLDEFF_GYOE_SetMMdl, FLDEFF_GYOE_StartHeld, FLDEFF_GYOE_IsFinished, FLDEFF_GYOE_InitHeldTask, FLDEFF_GYOE_DeleteTask, FLDEFF_GYOE_UpdateHeldTask, FLDEFF_GYOE_UpdateTask, FLDEFF_GYOE_DrawTask, FLDEFF_GYOE_PlaySe, FLDEFF_GYOE_RotateByCamera, FLDEFF_GYOE_StepAnimation
 * address:  0x021BB484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): the rest of the FLDEFF_GYOE_ effect (021BB578..021BB88F) was merged in from fieldmap_func.c. Evidence: one prefix run with FLDEFF_GYOE_Init..SetMMdl (__FILE__ anchor fldeff_gyoe.c at 021BB484, string 0x021DE2E8); its data sGyoeResIds, sGyoeTaskHeader, gGyoeHeldTaskHeader and gGyoeDrawTransformInit (0x021D9A6C..) form one run; the struct definitions of the two halves were duplicated and are now one.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   d_021DE2E8     0x021DE2E8  data  a4
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   sGyoeResIds     0x021D9A6C  data  a4
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FLDEFF_GYOE_PlaySe  0x021BB778  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sGyoeTaskHeader     0x021D9A7C  data  a4
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm  arm9
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm  arm9
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm  arm9
 *   gGyoeHeldTaskHeader     0x021D9A90  data  a4
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   gGyoeDrawTransformInit       0x021D9AA4  data  a4
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   NNS_G3dGlbFlush    0x0206A854  arm
 *   NNS_G3dGeFlushBuffer    0x0206DB80  arm
 *   MTX_Identity33_    0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos    0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling    0x02047AC8  arm
 *   g_DefaultProjectionMtx       0x02148B54  data
 *   SCREENTEX_CameraState       0x02148BCC  data
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetCamUp  0x02048B0C  arm
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   MTX_LookAt  0x0207BCA0  arm
 *   MI_Copy36B  0x02082B60  arm
 *   MTX_Inverse33  0x0207B0A4  arm
 *   MTX_MultVec33  0x0207B51C  arm
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   VEC_Add  0x0207C9D0  arm
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "../ov010/fldmmdl_types.h"

#include "../types.h"

#include "../sdk_fx.h"

#include "../ov012/union_comm_types.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

#define FLDEFF_GYOE_RES_MAX 4

/* Exclamation-mark ("gyoe") effect resources (0x38 bytes, fldeff_gyoe.c
 * line 0x6F allocation): one model resource, render object and object per
 * mark kind. */
typedef struct FldeffGyoe {
    void *fieldEffectCtrl;                 /* 0x00 */
    void *resource[FLDEFF_GYOE_RES_MAX];   /* 0x04 */
    void *renderObj[FLDEFF_GYOE_RES_MAX];  /* 0x14 */
    void *object[FLDEFF_GYOE_RES_MAX];     /* 0x24 */
    u16 resourceCount;                     /* 0x34 */
} FldeffGyoe;

/* Parameters handed to the effect task (copied by the task create call). */
typedef struct FldeffGyoeTaskParam {
    u32 type;                  /* 0x00: which mark */
    u32 sePlay;                /* 0x04: 1 plays the mark's sound */
    FldeffGyoe *gyoe;          /* 0x08: the FldeffGyoe of the effect control */
    Mmdl *mmdl;                /* 0x0C: model the mark appears over */
    MmdlCheckInfo mmdlInfo;    /* 0x10: identity check of that model */
    void *fieldMap;            /* 0x18 */
} FldeffGyoeTaskParam;

#include "../arm9/gfl_heap_wrap.h"

struct FieldEffectSys;

#include "field_effect.h"
struct ArcHandle;
struct G3dResource;

#include "../arm9/g3d_system.h"

struct G3dRender;

struct G3dAnime;
struct G3dObject;





/* ---- externs ---- */

#include "../ov010/fldmmdl.h"


void FLDEFF_GYOE_PlaySe(int type);


FldeffGyoe *FLDEFF_GYOE_Init(void *fieldEffectCtrl, u16 heapId);

void FLDEFF_GYOE_Delete(void *fieldEffectCtrl, FldeffGyoe *gyoe);

void FLDEFF_GYOE_InitResource(FldeffGyoe *gyoe);

void FLDEFF_GYOE_DeleteResource(FldeffGyoe *gyoe);

extern u32 sGyoeResIds[FLDEFF_GYOE_RES_MAX];

extern const struct FieldEffectObjFuncs sGyoeTaskHeader;

extern int d_021DE2E8;

FldeffGyoe *FLDEFF_GYOE_Init(void *fieldEffectCtrl, u16 heapId)
{
    FldeffGyoe *gyoe = GFL_HEAP_Alloc(heapId, sizeof(FldeffGyoe), 1, (const char *)&d_021DE2E8, 0x6F);
    gyoe->fieldEffectCtrl = fieldEffectCtrl;
    FLDEFF_GYOE_InitResource(gyoe);
    return gyoe;
}

void FLDEFF_GYOE_Delete(void *fieldEffectCtrl, FldeffGyoe *gyoe)
{
    FLDEFF_GYOE_DeleteResource(gyoe);
    GFL_HEAP_Free(gyoe);
}

void FLDEFF_GYOE_InitResource(FldeffGyoe *gyoe)
{
    void *g3dHeap = (void *)FIELD_EFFECT_GetArcHandle(gyoe->fieldEffectCtrl);
    int i;
    for (i = 0; i < FLDEFF_GYOE_RES_MAX; i++) {
        gyoe->resource[i] = G3D_SYSTEM_CreateResourceArcHandle(g3dHeap, sGyoeResIds[i]);
        G3D_SYSTEM_TransVramTexture(gyoe->resource[i]);
        gyoe->renderObj[i] = G3D_SYSTEM_CreateRender(gyoe->resource[i], 0, gyoe->resource[i]);
        gyoe->object[i] = G3D_SYSTEM_CreateObject(gyoe->renderObj[i], 0, 0);
    }
    gyoe->resourceCount = FLDEFF_GYOE_RES_MAX;
}

void FLDEFF_GYOE_DeleteResource(FldeffGyoe *gyoe)
{
    int i;
    for (i = 0; i < FLDEFF_GYOE_RES_MAX; i++) {
        G3D_SYSTEM_DeleteObject(gyoe->object[i]);
        G3D_SYSTEM_DeleteRender(gyoe->renderObj[i]);
        G3D_SYSTEM_DeleteResource(gyoe->resource[i]);
    }
}

void *FLDEFF_GYOE_SetMMdl(void *fieldEffectCtrl, Mmdl *mmdl, u32 type, u32 sePlay)
{
    FldeffGyoeTaskParam param;
    param.type = type;
    param.sePlay = sePlay;
    param.gyoe = (FldeffGyoe *)FIELD_EFFECT_GetResource(fieldEffectCtrl, 4);
    param.mmdl = mmdl;
    FLDMMDL_GetCheckInfo(mmdl, &param.mmdlInfo);
    param.fieldMap = (void *)FIELD_EFFECT_GetFieldMap(fieldEffectCtrl);
    if (sePlay == 1)
        FLDEFF_GYOE_PlaySe(type);
    return FIELD_EFFECT_AddObject(fieldEffectCtrl, &sGyoeTaskHeader, 0, 0, &param, 0);
}

/* ---- fldeff_gyoe.c (exclamation mark effect) ---- */

/* Position, scale and rotation of a drawn G3D object (0x48 bytes). */
typedef struct G3dObjectTransform {
    VecFx32 pos;
    VecFx32 scale;
    MtxFx33 rotation;
} G3dObjectTransform;

/* Work of one mark task (0x30 bytes). */
typedef struct FldeffGyoeTaskWork {
    FldeffGyoeTaskParam param; /* 0x00 */
    int state;                 /* 0x1C 0 hop, 1 wait, 2 shown */
    int timer;                 /* 0x20 frames spent waiting */
    int finished;              /* 0x24 set to 1 when the mark is done */
    fx32 yOffset;              /* 0x28 height above the model's head */
    fx32 yVelocity;            /* 0x2C */
} FldeffGyoeTaskWork;

/* State registers of the geometry engine (only the dirty bits are used). */
typedef struct GxState {
    u8 pad0[0x7C];
    u32 matrixDirtyFlags;      /* 0x7C */
} GxState;
struct FieldEffectObj;




struct VecFx32;
struct Mmdl;




#include "../arm9/mi_memory.h"

#include "../arm9/nns_g3d_glb.h"

#include "../arm9/nns_g3d_ge.h"

#include "../arm9/fx_mtx33.h"

struct G3dObjectStatus;


#include "../arm9/gfl_use.h"
struct G3dCamera;

#include "../arm9/g3d_camera.h"



#include "../arm9/fx_mtx43.h"



struct FieldMap;
struct FieldCamera;

#include "fieldmap.h"
struct G3dCamera;

#include "field_camera.h"

#include "../arm9/fx_vec.h"

struct FieldEffectObj *FLDEFF_GYOE_StartHeld(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay);

int FLDEFF_GYOE_IsFinished(void *task);

void FLDEFF_GYOE_InitHeldTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_DeleteTask(void);

void FLDEFF_GYOE_UpdateHeldTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_UpdateTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_DrawTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_RotateByCamera(void *g3dCamera, VecFx32 *src, VecFx32 *dst);

void FLDEFF_GYOE_StepAnimation(FldeffGyoeTaskWork *work, VecFx32 *out);

extern const struct FieldEffectObjFuncs gGyoeHeldTaskHeader;

extern const G3dObjectTransform gGyoeDrawTransformInit;

extern MtxFx44 g_DefaultProjectionMtx;

extern GxState SCREENTEX_CameraState;

/* Starts a mark that stays until its owner reads the finished flag. */
struct FieldEffectObj *FLDEFF_GYOE_StartHeld(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay)
{
    FldeffGyoeTaskParam param;

    param.type = type;
    param.sePlay = sePlay;
    param.gyoe = (FldeffGyoe *)FIELD_EFFECT_GetResource(fieldEffectCtrl, 4);
    param.mmdl = mmdl;
    FLDMMDL_GetCheckInfo(mmdl, &param.mmdlInfo);
    param.fieldMap = (void *)FIELD_EFFECT_GetFieldMap(fieldEffectCtrl);
    if (sePlay == 1) {
        FLDEFF_GYOE_PlaySe(type);
    }
    return FIELD_EFFECT_AddObject(fieldEffectCtrl, &gGyoeHeldTaskHeader, 0, 0, &param, 0);
}

/* Returns 1 when the task is gone or its mark is finished. */
int FLDEFF_GYOE_IsFinished(void *task)
{
    if (task != 0) {
        return ((FldeffGyoeTaskWork *)FIELD_EFFECT_GetObjectWork(task))->finished;
    }
    return 1;
}

void FLDEFF_GYOE_InitHeldTask(void *task, FldeffGyoeTaskWork *work)
{
    work->param = *(FldeffGyoeTaskParam *)FIELD_EFFECT_GetObjectParam(task);
    work->yVelocity = 0x6000;
    FIELD_EFFECT_UpdateObject(task);
}

void FLDEFF_GYOE_DeleteTask(void) {}

void FLDEFF_GYOE_UpdateHeldTask(void *task, FldeffGyoeTaskWork *work)
{
    VecFx32 pos;

    if (FLDMMDL_CheckCheckInfo(work->param.mmdl, &work->param.mmdlInfo) == 0) {
        work->finished = 1;
        return;
    }
    FLDMMDL_GetPos(work->param.mmdl, (struct VecFx32 *)(&pos));
    FLDEFF_GYOE_StepAnimation(work, &pos);
    FIELD_EFFECT_SetObjectPos(task, &pos);
}

void FLDEFF_GYOE_UpdateTask(void *task, FldeffGyoeTaskWork *work)
{
    VecFx32 pos;

    if (work->finished == 1 || FLDMMDL_CheckCheckInfo(work->param.mmdl, &work->param.mmdlInfo) == 0) {
        FIELD_EFFECT_DeleteObject(task);
        return;
    }
    FLDMMDL_GetPos(work->param.mmdl, (struct VecFx32 *)(&pos));
    FLDEFF_GYOE_StepAnimation(work, &pos);
    FIELD_EFFECT_SetObjectPos(task, &pos);
}

/*
 * Twin of FIELDMAP_Draw3dNormal (save/modify/restore of the projection matrix
 * g_DefaultProjectionMtx).  Here the matrix is read through a pointer local initialised
 * at its declaration, which is what loads its address before the soft-float
 * conversion; `saved = g_DefaultProjectionMtx` loads it after (22 bytes off with the
 * pointer declared first, r4/r5 swapped with it declared last).
 */
void FLDEFF_GYOE_DrawTask(void *task, FldeffGyoeTaskWork *work)
{
    G3dObjectTransform transform = gGyoeDrawTransformInit;
    MtxFx44 *projection = &g_DefaultProjectionMtx;
    MtxFx44 saved;
    MtxFx44 shifted;
    fx32 zBias;

    zBias = FX_F32_TO_FX32(work->param.gyoe->resourceCount);
    saved = *projection;
    shifted = saved;
    shifted.m[3][2] += FX_MUL(shifted.m[2][2], zBias);
    MIi_CpuCopyFast(&shifted, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.matrixDirtyFlags &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
    MTX_Identity33_(&transform.rotation);
    FIELD_EFFECT_GetObjectPos(task, (VecFx32 *)&transform);
    G3D_SYSTEM_DrawObjectCulling(work->param.gyoe->object[work->param.type], (struct G3dObjectStatus *)(&transform));
    MIi_CpuCopyFast(&saved, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.matrixDirtyFlags &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
}

void FLDEFF_GYOE_PlaySe(int type)
{
    int seId = 0;

    switch (type) {
    case 0:
        seId = 0x678;
        break;
    case 1:
        seId = 0x730;
        break;
    case 2:
        seId = 0x731;
        break;
    case 3:
        return;
    }
    GFL_USE_PlaySeDefaultVolume(seId);
}

/* Rotates src by the inverse of the camera's orientation. */
void FLDEFF_GYOE_RotateByCamera(void *g3dCamera, VecFx32 *src, VecFx32 *dst)
{
    VecFx32 eye;
    VecFx32 target;
    VecFx32 up;
    union MtxFx43 lookAt;
    union MtxFx33 inverse;

    G3D_CAMERA_GetEye(g3dCamera, &eye);
    G3D_CAMERA_GetCamUp(g3dCamera, &target);
    G3D_CAMERA_GetCamTarget(g3dCamera, &up);
    MTX_LookAt(&eye, &target, &up, &lookAt);
    MI_Copy36B(&lookAt, &inverse);
    MTX_Inverse33(&inverse, &inverse);
    MTX_MultVec33(src, &inverse, dst);
}

/* Steps the hop and wait animation and returns the mark position in out. */
void FLDEFF_GYOE_StepAnimation(FldeffGyoeTaskWork *work, VecFx32 *out)
{
    void *g3dCamera;
    VecFx32 offset;

    switch (work->state) {
    case 0:
        work->yOffset += work->yVelocity;
        if (work->yOffset != 0) {
            work->yVelocity = work->yVelocity - 0x2000;
        } else {
            work->yVelocity = 0;
            work->state = work->state + 1;
        }
        break;
    case 1:
        work->timer = work->timer + 1;
        if (work->timer >= 30) {
            work->state = work->state + 1;
            work->finished = 1;
        }
        break;
    }
    g3dCamera = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera(work->param.fieldMap));
    {
        VecFx32 above = {0, 0, 0};

        above.y = work->yOffset + 0x16000;
        offset = above;
    }
    FLDEFF_GYOE_RotateByCamera(g3dCamera, &offset, &offset);
    VEC_Add(&offset, out, out);
}
