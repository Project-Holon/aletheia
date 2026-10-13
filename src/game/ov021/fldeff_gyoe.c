/*
 * file:     fldeff_gyoe.c
 * unit:     yes
 * function: FLDEFF_GYOE_Init, FLDEFF_GYOE_Delete, FLDEFF_GYOE_InitResource, FLDEFF_GYOE_DeleteResource, FLDEFF_GYOE_SetMMdl
 * address:  0x021BB484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Split by lane CL115 from field_nogrid_mapper.c at the __FILE__ anchor cuts.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
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
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned short u16;
typedef unsigned int   u32;

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
    u32 gyoe;                  /* 0x08: the FldeffGyoe of the effect control */
    Mmdl *mmdl;                /* 0x0C: model the mark appears over */
    MmdlCheckInfo mmdlInfo;    /* 0x10: identity check of that model */
    u32 fieldMap;              /* 0x18 */
} FldeffGyoeTaskParam;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *p);
extern void *FIELD_EFFECT_GetArcHandle(void *fieldEffectCtrl);
extern void *G3D_SYSTEM_CreateResourceArcHandle(void *g3dHeap, u32 resId);
extern int G3D_SYSTEM_TransVramTexture(void *resource);
extern void *G3D_SYSTEM_CreateRender(void *resource, u32 index, void *texResource);
extern void *G3D_SYSTEM_CreateObject(void *renderObj, u32 *anime, int animeCount);
extern void G3D_SYSTEM_DeleteObject(void *object);
extern void G3D_SYSTEM_DeleteRender(void *renderObj);
extern void G3D_SYSTEM_DeleteResource(void *resource);
extern u32 FIELD_EFFECT_GetResource(void *fieldEffectCtrl, u32 effectId);
extern void FLDMMDL_GetCheckInfo(Mmdl *mmdl, MmdlCheckInfo *info);
extern u32 FIELD_EFFECT_GetFieldMap(void *fieldEffectCtrl);
extern void FLDEFF_GYOE_PlaySe(int type);
extern void *FIELD_EFFECT_AddObject(void *fieldEffectCtrl, const void *taskHeader, int a2, int a3, FldeffGyoeTaskParam *param, int a5);

FldeffGyoe *FLDEFF_GYOE_Init(void *fieldEffectCtrl, int heapId);
void FLDEFF_GYOE_Delete(void *fieldEffectCtrl, FldeffGyoe *gyoe);
void FLDEFF_GYOE_InitResource(FldeffGyoe *gyoe);
void FLDEFF_GYOE_DeleteResource(FldeffGyoe *gyoe);

extern u32 sGyoeResIds[FLDEFF_GYOE_RES_MAX];
extern int sGyoeTaskHeader;
extern int d_021DE2E8;

FldeffGyoe *FLDEFF_GYOE_Init(void *fieldEffectCtrl, int heapId)
{
    FldeffGyoe *gyoe = func_02030734(heapId, sizeof(FldeffGyoe), 1, (const char *)&d_021DE2E8, 0x6F);
    gyoe->fieldEffectCtrl = fieldEffectCtrl;
    FLDEFF_GYOE_InitResource(gyoe);
    return gyoe;
}

void FLDEFF_GYOE_Delete(void *fieldEffectCtrl, FldeffGyoe *gyoe)
{
    FLDEFF_GYOE_DeleteResource(gyoe);
    func_020307B0(gyoe);
}

void FLDEFF_GYOE_InitResource(FldeffGyoe *gyoe)
{
    void *g3dHeap = FIELD_EFFECT_GetArcHandle(gyoe->fieldEffectCtrl);
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
    param.gyoe = FIELD_EFFECT_GetResource(fieldEffectCtrl, 4);
    param.mmdl = mmdl;
    FLDMMDL_GetCheckInfo(mmdl, &param.mmdlInfo);
    param.fieldMap = FIELD_EFFECT_GetFieldMap(fieldEffectCtrl);
    if (sePlay == 1)
        FLDEFF_GYOE_PlaySe(type);
    return FIELD_EFFECT_AddObject(fieldEffectCtrl, &sGyoeTaskHeader, 0, 0, &param, 0);
}
