/*
 * file:     union_eff.c
 * unit:     yes
 * function: UNION_EFF_Create, UNION_EFF_Delete, UNION_EFF_Main, UNION_EFF_Draw, UNION_EFF_AddAnimEffect, UNION_EFF_AddIcon, UNION_EFF_DeleteIcon, UNION_EFF_InitAnimGroup, UNION_EFF_ExitAnimGroup, UNION_EFF_AddAnimObj, UNION_EFF_CreateAnimObj, UNION_EFF_DeleteAnimObj, UNION_EFF_UpdateAnimObj, UNION_EFF_DrawAnimObj, UNION_EFF_DeleteAnimGroupObjs, UNION_EFF_UpdateAnimGroup, UNION_EFF_DrawAnimGroup, UNION_EFF_GetFreeAnimObj, UNION_EFF_InitIconGroup, UNION_EFF_ExitIconGroup, UNION_EFF_AddIconObj, UNION_EFF_CreateIconObj, UNION_EFF_DeleteIconObj, UNION_EFF_UpdateIconObj, UNION_EFF_DrawIconObj, UNION_EFF_DeleteIconGroupObjs, UNION_EFF_UpdateIconGroup, UNION_EFF_DrawIconGroup, UNION_EFF_GetFreeIconObj
 * address:  0x0217F8C0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   d_02180808     0x02180808  data   ov019 a4
 *   ARC_TOOL_CreateHandle   0x020490F4  arm
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   GF_PANIC_Fail   0x02034714  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_02180814     0x02180814  data  ov019 a4
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   G3D_SYSTEM_DrawObjectCulling 0x02047AC8 arm
 *   FLDMMDL_CheckStatusBitUse 0x0216DA30 thumb ov010
 *   MTX_Identity33_  0x0207ADC4  arm
 *   d_0218071C       0x0218071C  data   ov019 a4
 *   d_02180758       0x02180758  data   ov019 a4
 */

#include "../sdk_fx.h"

#include "../types.h"

#include "../ov012/union_comm_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

#define UNION_EFF_ANIM_MAX    1
#define UNION_EFF_ICON_MAX    10
#define UNION_EFF_ANIM_FRAMES 90

/* One effect model over a field model (0x14 bytes, union_eff.c). */
typedef struct UnionEffObj {
    void *mmdl;      /* 0x00 field model the effect follows; NULL when free */
    void *render;    /* 0x04 G3D render object */
    void *anime;     /* 0x08 G3D animation (anim group only) */
    void *object;    /* 0x0C G3D object; NULL when the slot is free */
    u16 serial;      /* 0x10 creation order, the oldest is reused when full */
    u16 frame;       /* 0x12 frames played (anim group) */
} UnionEffObj;

/* Animated reaction effect (0x20 bytes). */
typedef struct UnionEffAnimGroup {
    UnionEffObj obj[UNION_EFF_ANIM_MAX];  /* 0x00 */
    void *resModel;                       /* 0x14 arc 0x59 file 0x14 */
    void *resAnime;                       /* 0x18 arc 0x59 file 0x15 */
    u16 serial;                           /* 0x1C next serial */
    u8 pad1E[2];
} UnionEffAnimGroup;

/* Still icons over players (0xD4 bytes). */
typedef struct UnionEffIconGroup {
    UnionEffObj obj[UNION_EFF_ICON_MAX];  /* 0x00 */
    void *resModel[2];                    /* 0xC8 arc 0x59 files 0x16, 0x17 */
    u16 serial;                           /* 0xD0 next serial */
    u8 padD2[2];
} UnionEffIconGroup;

/* union_eff work (0xF4 bytes, heap tag 0x8E). */
typedef struct UnionEffWork {
    UnionEffAnimGroup anim;   /* 0x00 */
    UnionEffIconGroup icon;   /* 0x20 */
} UnionEffWork;

/* Draw parameters of G3D_SYSTEM_DrawObjectCulling (0x3C bytes). */
typedef struct UnionEffDrawStatus {
    VecFx32 trans;     /* 0x00 */
    VecFx32 scale;     /* 0x0C */
    MtxFx33 rotate;    /* 0x18 3x3 matrix */
} UnionEffDrawStatus;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/arc_tool.h"
struct ArcHandle;
struct G3dResource;
#include "../arm9/g3d_system.h"
#include "../arm9/gf_panic.h"
#include "../arm9/mi_memory.h"
struct G3dRender;
struct G3dAnime;
struct G3dObject;
struct VecFx32;
struct Mmdl;
#include "../ov010/fldmmdl.h"
struct G3dObjectStatus;
#include "../arm9/fx_mtx33.h"
UnionEffWork *UNION_EFF_Create(u16 heapId);
void UNION_EFF_Delete(UnionEffWork *work);
void UNION_EFF_Main(UnionEffWork *work);
void UNION_EFF_Draw(UnionEffWork *work);
void UNION_EFF_AddAnimEffect(UnionEffWork *work, void *mmdl);
void UNION_EFF_AddIcon(UnionEffWork *work, void *mmdl, u32 iconKind);
void UNION_EFF_DeleteIcon(UnionEffWork *work, void *mmdl);
void UNION_EFF_InitAnimGroup(UnionEffAnimGroup *anim, u32 heapId);
void UNION_EFF_ExitAnimGroup(UnionEffAnimGroup *anim);
void UNION_EFF_AddAnimObj(UnionEffAnimGroup *anim, void *mmdl);
void UNION_EFF_CreateAnimObj(UnionEffAnimGroup *anim, UnionEffObj *obj, void *mmdl, u16 serial);
void UNION_EFF_DeleteAnimObj(UnionEffObj *obj);
void UNION_EFF_UpdateAnimObj(UnionEffObj *obj);
void UNION_EFF_DrawAnimObj(UnionEffObj *obj, UnionEffDrawStatus *status);
void UNION_EFF_DeleteAnimGroupObjs(UnionEffAnimGroup *anim);
void UNION_EFF_UpdateAnimGroup(UnionEffAnimGroup *anim);
void UNION_EFF_DrawAnimGroup(UnionEffAnimGroup *anim);
UnionEffObj *UNION_EFF_GetFreeAnimObj(UnionEffObj *objs);
void UNION_EFF_InitIconGroup(UnionEffIconGroup *icon, u32 heapId);
void UNION_EFF_ExitIconGroup(UnionEffIconGroup *icon);
void UNION_EFF_AddIconObj(UnionEffIconGroup *icon, void *mmdl, u32 iconKind);
void UNION_EFF_CreateIconObj(UnionEffIconGroup *icon, UnionEffObj *obj, void *mmdl, u16 serial, int iconKind);
void UNION_EFF_DeleteIconObj(UnionEffObj *obj);
void UNION_EFF_UpdateIconObj(UnionEffObj *obj);
void UNION_EFF_DrawIconObj(UnionEffObj *obj, UnionEffDrawStatus *status);
void UNION_EFF_DeleteIconGroupObjs(UnionEffIconGroup *icon);
void UNION_EFF_UpdateIconGroup(UnionEffIconGroup *icon);
void UNION_EFF_DrawIconGroup(UnionEffIconGroup *icon);
UnionEffObj *UNION_EFF_GetFreeIconObj(UnionEffObj *objs);
extern u32 d_02180808[];
extern const char d_02180814[];
extern const UnionEffDrawStatus d_0218071C;
extern const UnionEffDrawStatus d_02180758;

/*
 * union_eff.c part (anchor 0x0217F8C0): reaction effects drawn over the field
 * models of the union room.  The anim group plays one animated model (arc
 * 0x59 files 0x14/0x15) for 90 frames; the icon group keeps up to ten still
 * models (files 0x16/0x17) over players until they are removed.
 */
UnionEffWork *UNION_EFF_Create(u16 heapId)
{
    UnionEffWork *work = GFL_HEAP_Alloc(heapId, sizeof(UnionEffWork), 1, (char *)d_02180808, 0x8e);
    UNION_EFF_InitAnimGroup(&work->anim, heapId);
    UNION_EFF_InitIconGroup(&work->icon, heapId);
    return work;
}

void UNION_EFF_Delete(UnionEffWork *work)
{
    if (work) {
        UNION_EFF_DeleteIconGroupObjs(&work->icon);
        UNION_EFF_ExitIconGroup(&work->icon);
        UNION_EFF_DeleteAnimGroupObjs(&work->anim);
        UNION_EFF_ExitAnimGroup(&work->anim);
        GFL_HEAP_Free(work);
    }
}

void UNION_EFF_Main(UnionEffWork *work)
{
    if (work) {
        UNION_EFF_UpdateIconGroup(&work->icon);
        UNION_EFF_UpdateAnimGroup(&work->anim);
    }
}

void UNION_EFF_Draw(UnionEffWork *work)
{
    if (work) {
        UNION_EFF_DrawIconGroup(&work->icon);
        UNION_EFF_DrawAnimGroup(&work->anim);
    }
}

void UNION_EFF_AddAnimEffect(UnionEffWork *work, void *mmdl)
{
    if (work != NULL)
        UNION_EFF_AddAnimObj(&work->anim, mmdl);
}

void UNION_EFF_AddIcon(UnionEffWork *work, void *mmdl, u32 iconKind)
{
    if (work)
        UNION_EFF_AddIconObj(&work->icon, mmdl, iconKind);
}

void UNION_EFF_DeleteIcon(UnionEffWork *work, void *mmdl)
{
    UnionEffIconGroup *icon = &work->icon;
    int i;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        void *objMmdl = icon->obj[i].mmdl;
        if (objMmdl == mmdl) {
            UNION_EFF_DeleteIconObj(&icon->obj[i]);
            return;
        }
    }
}

/*
 * Loads the animated model and its animation from arc 0x59, then sends the
 * texture to VRAM (an error there goes to the GFL assert, d_02180814).
 */
void UNION_EFF_InitAnimGroup(UnionEffAnimGroup *anim, u32 heapId)
{
    void *arc = ARC_TOOL_CreateHandle(0x59, heapId);

    anim->resModel = G3D_SYSTEM_CreateResourceArcHandle(arc, 0x14);
    anim->resAnime = G3D_SYSTEM_CreateResourceArcHandle(arc, 0x15);
    if (G3D_SYSTEM_TransVramTexture(anim->resModel) == 0) {
        GF_PANIC_Fail(d_02180814, 0, d_02180814);
    }
    ARC_TOOL_DeleteHandle(arc);
}

void UNION_EFF_ExitAnimGroup(UnionEffAnimGroup *anim)
{
    G3D_SYSTEM_FreeVramTexture(anim->resModel);
    G3D_SYSTEM_DeleteResource(anim->resAnime);
    anim->resAnime = NULL;
    G3D_SYSTEM_DeleteResource(anim->resModel);
    anim->resModel = NULL;
}

void UNION_EFF_AddAnimObj(UnionEffAnimGroup *anim, void *mmdl)
{
    UnionEffObj *obj;
    if (anim->resModel == NULL) GF_PANIC_Fail(d_02180814, 0, d_02180814);
    obj = UNION_EFF_GetFreeAnimObj(anim->obj);
    UNION_EFF_CreateAnimObj(anim, obj, mmdl, anim->serial);
    (anim->serial)++;
}

void UNION_EFF_CreateAnimObj(UnionEffAnimGroup *anim, UnionEffObj *obj, void *mmdl, u16 serial)
{
    MI_CpuFill8(obj, 0, sizeof(UnionEffObj));
    obj->mmdl = mmdl;
    obj->serial = serial;
    obj->render = G3D_SYSTEM_CreateRender(anim->resModel, 0, anim->resModel);
    obj->anime = G3D_SYSTEM_CreateAnime(obj->render, anim->resAnime, 0);
    obj->object = G3D_SYSTEM_CreateObject(obj->render, (struct G3dAnime **)(&obj->anime), 1);
    G3D_SYSTEM_EnableObjectAnime(obj->object, 0);
}

void UNION_EFF_DeleteAnimObj(UnionEffObj *obj)
{
    G3D_SYSTEM_DeleteAnime(obj->anime);
    G3D_SYSTEM_DeleteObject(obj->object);
    G3D_SYSTEM_DeleteRender(obj->render);
    MI_CpuFill8(obj, 0, sizeof(UnionEffObj));
}

void UNION_EFF_UpdateAnimObj(UnionEffObj *obj)
{
    G3D_SYSTEM_LoopObjectAnimeFrame(obj->object, 0, 0x1000);
    (obj->frame)++;
    if (obj->frame > UNION_EFF_ANIM_FRAMES) UNION_EFF_DeleteAnimObj(obj);
}

void UNION_EFF_DrawAnimObj(UnionEffObj *obj, UnionEffDrawStatus *status)
{
    FLDMMDL_GetPos(obj->mmdl, (struct VecFx32 *)(&status->trans));
    status->trans.y -= 0x6000;
    G3D_SYSTEM_DrawObjectCulling(obj->object, (struct G3dObjectStatus *)status);
}

void UNION_EFF_DeleteAnimGroupObjs(UnionEffAnimGroup *anim)
{
    if (anim->obj[0].object != NULL) UNION_EFF_DeleteAnimObj(anim->obj);
}

void UNION_EFF_UpdateAnimGroup(UnionEffAnimGroup *anim)
{
    if (anim->obj[0].object != NULL) {
        if (FLDMMDL_CheckStatusBitUse(anim->obj[0].mmdl) == 1) UNION_EFF_UpdateAnimObj(anim->obj);
        else UNION_EFF_DeleteAnimObj(anim->obj);
    }
}

void UNION_EFF_DrawAnimGroup(UnionEffAnimGroup *anim)
{
    UnionEffDrawStatus status = d_0218071C;
    MTX_Identity33_(&status.rotate);
    if (anim->obj[0].object != NULL && FLDMMDL_CheckStatusBitUse(anim->obj[0].mmdl) == 1) {
        UNION_EFF_DrawAnimObj(anim->obj, &status);
    }
}

/* A free object, else the oldest one (lowest serial), deleted for reuse. */
UnionEffObj *UNION_EFF_GetFreeAnimObj(UnionEffObj *objs)
{
    int i, oldest = 0;
    for (i = 0; i < UNION_EFF_ANIM_MAX; i++) {
        UnionEffObj *obj = &objs[i];
        if (obj->object == NULL) {
            return obj;
        }
        if (obj->serial < objs[oldest].serial) {
            oldest = i;
        }
    }
    UNION_EFF_DeleteAnimObj(&objs[oldest]);
    return &objs[oldest];
}

/* Loads the two icon models from arc 0x59 and sends their textures to VRAM. */
void UNION_EFF_InitIconGroup(UnionEffIconGroup *icon, u32 heapId)
{
    void *arc = ARC_TOOL_CreateHandle(0x59, heapId);
    icon->resModel[0] = G3D_SYSTEM_CreateResourceArcHandle(arc, 0x16);
    icon->resModel[1] = G3D_SYSTEM_CreateResourceArcHandle(arc, 0x17);
    if (G3D_SYSTEM_TransVramTexture(icon->resModel[0]) == 0) {
        GF_PANIC_Fail(d_02180814, 0, d_02180814);
    }
    if (G3D_SYSTEM_TransVramTexture(icon->resModel[1]) == 0) {
        GF_PANIC_Fail(d_02180814, 0, d_02180814);
    }
    ARC_TOOL_DeleteHandle(arc);
}

void UNION_EFF_ExitIconGroup(UnionEffIconGroup *icon)
{
    G3D_SYSTEM_FreeVramTexture(icon->resModel[0]);
    G3D_SYSTEM_FreeVramTexture(icon->resModel[1]);
    G3D_SYSTEM_DeleteResource(icon->resModel[0]);
    G3D_SYSTEM_DeleteResource(icon->resModel[1]);
    icon->resModel[0] = NULL;
    icon->resModel[1] = NULL;
}

void UNION_EFF_AddIconObj(UnionEffIconGroup *icon, void *mmdl, u32 iconKind)
{
    if (icon->resModel[0] == NULL) {
        GF_PANIC_Fail(d_02180814, 0, d_02180814);
    }
    if (icon->resModel[1] == NULL) {
        GF_PANIC_Fail(d_02180814, 0, d_02180814);
    }
    UNION_EFF_CreateIconObj(icon, UNION_EFF_GetFreeIconObj(icon->obj), mmdl, icon->serial, iconKind);
    icon->serial = icon->serial + 1;
}

/*
 * stand-in: the reload of obj->render before the last call is spelled with a
 * volatile read (the plain read keeps the value in a register).
 */
void UNION_EFF_CreateIconObj(UnionEffIconGroup *icon, UnionEffObj *obj, void *mmdl, u16 serial, int iconKind)
{
    void **resModel;
    MI_CpuFill8(obj, 0, sizeof(UnionEffObj));
    obj->mmdl = mmdl;
    obj->serial = serial;
    if (iconKind == 0) {
        resModel = &icon->resModel[0];
    } else {
        resModel = &icon->resModel[1];
    }
    obj->render = G3D_SYSTEM_CreateRender(*resModel, 0, *resModel);
    obj->object = G3D_SYSTEM_CreateObject(*(void *volatile *)&obj->render, NULL, 0);
}

void UNION_EFF_DeleteIconObj(UnionEffObj *obj)
{
    G3D_SYSTEM_DeleteObject(obj->object);
    G3D_SYSTEM_DeleteRender(obj->render);
    MI_CpuFill8(obj, 0, sizeof(UnionEffObj));
}

void UNION_EFF_UpdateIconObj(UnionEffObj *obj)
{
}

void UNION_EFF_DrawIconObj(UnionEffObj *obj, UnionEffDrawStatus *status)
{
    FLDMMDL_GetPos(obj->mmdl, (struct VecFx32 *)(&status->trans));
    status->trans.y -= 0x6800;
    G3D_SYSTEM_DrawObjectCulling(obj->object, (struct G3dObjectStatus *)status);
}

void UNION_EFF_DeleteIconGroupObjs(UnionEffIconGroup *icon)
{
    int i;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        UnionEffObj *obj = &icon->obj[i];
        if (obj->object != NULL) UNION_EFF_DeleteIconObj(obj);
    }
}

void UNION_EFF_UpdateIconGroup(UnionEffIconGroup *icon)
{
    int i;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        UnionEffObj *obj = &icon->obj[i];
        if (obj->object != NULL) {
            if (FLDMMDL_CheckStatusBitUse(obj->mmdl) == 1) UNION_EFF_UpdateIconObj(obj);
            else UNION_EFF_DeleteIconObj(obj);
        }
    }
}

void UNION_EFF_DrawIconGroup(UnionEffIconGroup *icon)
{
    UnionEffDrawStatus status = d_02180758;
    int i;
    MTX_Identity33_(&status.rotate);
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        UnionEffObj *obj = &icon->obj[i];
        if (obj->object != NULL && FLDMMDL_CheckStatusBitUse(obj->mmdl) == 1) {
            UNION_EFF_DrawIconObj(obj, &status);
        }
    }
}

/* A free object, else the oldest one (lowest serial), deleted for reuse. */
UnionEffObj *UNION_EFF_GetFreeIconObj(UnionEffObj *objs)
{
    int i;
    int oldest = 0;
    UnionEffObj *obj;
    for (i = 0; i < UNION_EFF_ICON_MAX; i++) {
        obj = &objs[i];
        if (obj->object == NULL)
            return obj;
        if (obj->serial < objs[oldest].serial)
            oldest = i;
    }
    obj = &objs[oldest];
    UNION_EFF_DeleteIconObj(obj);
    return obj;
}
