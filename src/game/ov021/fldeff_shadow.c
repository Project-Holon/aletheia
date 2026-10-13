/*
 * file:     fldeff_shadow.c
 * unit:     yes
 * function: FLDEFF_SHADOW_Create, FLDEFF_SHADOW_Delete, FLDEFF_SHADOW_CreateSlot, FLDEFF_SHADOW_DeleteSlot, FLDEFF_SHADOW_Start, FLDEFF_SHADOW_Init, FLDEFF_SHADOW_Exit, FLDEFF_SHADOW_Update, FLDEFF_SHADOW_Draw
 * address:  0x021AC218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AC218: __FILE__ fldeff_shadow.c on 0x021AC218 (init, first
 * function); 0x021AC1A0..0x021AC1F0 are field_effect.c accessors called from many fldeff files.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FIELDMAP_GetEffectBbdAct  0x02188C88  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   d_021DE028     0x021DE028  data  a1
 *   gFldeffShadowBaseOffset     0x021D908C  data  a4
 *   ENV_SetResourceSet  0x020307B0  arm
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   gFldeffShadowObjFuncs  0x021D9098  data
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysIsDrawEnable  0x0216D98C  thumb  ov010
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_GetModelOffset  0x0216D92C  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   BILLBOARD_SetElemVisible  0x0204F720  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   BILLBOARD_SetElemPolyId  0x0204F6DC  arm  arm9
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm  arm9
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 */
#include "field_effect_types.h"
#include "../arm9/billboard_act_types.h"
#include "../ov010/fldmmdl_types.h"

/* Id of the shadow resource in the field effect system. */
#define FLDEFF_ID_SHADOW 0

/* Shadow elevation above the model position. */
#define FLDEFF_SHADOW_RAISE 0x1000

/* Model flag that hides the shadow (moveBit). */
#define FLDEFF_SHADOW_HIDE_MOVE_BIT 0x8000

/* Billboard entry settings of one shadow. */
#define FLDEFF_SHADOW_ENTRY_SIZE   0x1000
#define FLDEFF_SHADOW_ENTRY_LAYER  0x13
#define FLDEFF_SHADOW_POLY_ID      2

/*
 * Resource of the shadow effect (0x1C bytes, allocated by
 * FLDEFF_SHADOW_Create). It owns one billboard slot that every shadow of the map
 * draws from.
 */
typedef struct FldeffShadow {
    FieldEffectSys *fieldEffect;          /* 0x00 */
    VecFx32 baseOffset;                   /* 0x04 copied from a data table, never read here */
    struct BbActSys *billboardAct;        /* 0x10 billboard system of the field map */
    struct BbBoard *board;                /* 0x14 */
    u32 slotId;                           /* 0x18 slot made by the creation call */
} FldeffShadow;

/* Start parameter of one shadow (8 bytes). */
typedef struct FldeffShadowParam {
    FldeffShadow *shadow;
    Mmdl *mmdl;                           /* model that casts the shadow */
} FldeffShadowParam;

/* Work of one shadow (0x18 bytes). */
typedef struct FldeffShadowWork {
    u32 hidden;                           /* 0x00 1 while the shadow is not drawn */
    FldeffShadow *shadow;                 /* 0x04 */
    Mmdl *mmdl;                           /* 0x08 */
    u16 mmdlCheck[4];                     /* 0x0C identity check of the model */
    u32 entryId;                          /* 0x14 billboard entry (0xFFFF: none) */
} FldeffShadowWork;

extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *out);
extern const MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(const Mmdl *mmdl);
extern struct BbActSys *FIELDMAP_GetEffectBbdAct(struct FieldMap *fieldmap);
extern struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *act);
extern void ENV_SetResourceSet(void *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(int arcHandle, u32 id);
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *act, const struct BbActRec *recs, u32 count);
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *act, u32 first, u32 count);
extern int FLDMMDL_GetCheckInfo(const Mmdl *mmdl, u16 *out);
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *act, u16 baseSlot, const struct BbActDesc *desc, u32 count, u32 mode);
extern void BILLBOARD_SetElemPolyId(struct BbBoard *board, int elemId, u8 *polyId);
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *act, u16 first, u32 count);
extern int FLDMMDL_CheckCheckInfo(const Mmdl *mmdl, const u16 *info);
extern void *FLDMMDL_GetMmdlSys(const Mmdl *mmdl);
extern int FLDMMDL_SysIsDrawEnable(void *mmdlSys);
extern int FLDMMDL_CheckStatusBitVanish(const Mmdl *mmdl);
extern u32 FLDMMDL_CheckMoveBit(const Mmdl *mmdl, u32 bit);
extern void FLDMMDL_GetModelOffset(const Mmdl *mmdl, VecFx32 *out);
extern void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void FLDMMDL_GetDrawOffset(const Mmdl *mmdl, VecFx32 *out);
extern void BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemId, u32 *visible);
extern void BILLBOARD_SetElemPos(struct BbBoard *board, int elemId, const VecFx32 *pos);
struct FieldMap *FIELD_EFFECT_GetFieldMap(FieldEffectSys *sys);
int FIELD_EFFECT_GetArcHandle(FieldEffectSys *sys);
void *FIELD_EFFECT_GetResource(FieldEffectSys *sys, int id);
void FIELD_EFFECT_AddObject(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void FIELD_EFFECT_DeleteObject(FieldEffectObj *obj);
void FIELD_EFFECT_UpdateObject(FieldEffectObj *obj);
void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *obj);
FldeffShadow *FLDEFF_SHADOW_Create(FieldEffectSys *sys, int heapId);
void FLDEFF_SHADOW_Delete(FieldEffectSys *sys, FldeffShadow *shadow);
void FLDEFF_SHADOW_CreateSlot(FldeffShadow *shadow);
void FLDEFF_SHADOW_DeleteSlot(FldeffShadow *shadow);
void FLDEFF_SHADOW_Start(Mmdl *mmdl, FieldEffectSys *sys);
void FLDEFF_SHADOW_Init(FieldEffectObj *obj, FldeffShadowWork *work);
void FLDEFF_SHADOW_Exit(FieldEffectObj *obj, FldeffShadowWork *work);
void FLDEFF_SHADOW_Update(FieldEffectObj *obj, FldeffShadowWork *work);
void FLDEFF_SHADOW_Draw(FieldEffectObj *obj, FldeffShadowWork *work);
extern char d_021DE028[];
extern VecFx32 gFldeffShadowBaseOffset;
extern FieldEffectObjFuncs gFldeffShadowObjFuncs;

/* Resource creation: allocates the resource and makes its billboard slot. */
FldeffShadow *FLDEFF_SHADOW_Create(FieldEffectSys *sys, int heapId)
{
    FldeffShadow *shadow;

    shadow = func_02030734(heapId, sizeof(FldeffShadow), 1, d_021DE028, 0x5c);
    shadow->fieldEffect = sys;
    shadow->baseOffset = gFldeffShadowBaseOffset;
    shadow->billboardAct = FIELDMAP_GetEffectBbdAct(FIELD_EFFECT_GetFieldMap(sys));
    shadow->board = BILLBOARD_ACT_GetBoard(shadow->billboardAct);
    FLDEFF_SHADOW_CreateSlot(shadow);
    return shadow;
}









/* Resource deletion: frees the billboard slot and the resource. */
void FLDEFF_SHADOW_Delete(FieldEffectSys *sys, FldeffShadow *shadow)
{
    FLDEFF_SHADOW_DeleteSlot(shadow);
    ENV_SetResourceSet(shadow);
}









/* Makes the billboard slot that holds the shadow image. */
void FLDEFF_SHADOW_CreateSlot(FldeffShadow *shadow)
{
    struct BbActRec rec;

    rec.resource = (u32)G3D_SYSTEM_CreateResourceArcHandle(FIELD_EFFECT_GetArcHandle(shadow->fieldEffect), 0x2f);
    rec.format = 2;
    rec.sizeS = 0x11;
    rec.sizeT = 0x10;
    rec.paletteId = 0x10;
    rec.kind = 1;
    shadow->slotId = BILLBOARD_ACT_CreateSlots(shadow->billboardAct, &rec, 1);
}









/* Frees the billboard slot of the shadow image. */
void FLDEFF_SHADOW_DeleteSlot(FldeffShadow *shadow)
{
    BILLBOARD_ACT_DeleteSlots(shadow->billboardAct, (u16)shadow->slotId, 1);
}









/* Starts the shadow effect of a model. */
void FLDEFF_SHADOW_Start(Mmdl *mmdl, FieldEffectSys *sys)
{
    FldeffShadowParam param;

    param.shadow = FIELD_EFFECT_GetResource(sys, FLDEFF_ID_SHADOW);
    param.mmdl = mmdl;
    FIELD_EFFECT_AddObject(sys, &gFldeffShadowObjFuncs, 0, 0, &param, 0);
}









/* Shadow effect: init, makes the billboard entry of the shadow. */
void FLDEFF_SHADOW_Init(FieldEffectObj *obj, FldeffShadowWork *work)
{
    FldeffShadowParam *param = FIELD_EFFECT_GetObjectParam(obj);
    u8 polyId;
    struct BbActDesc desc;

    work->shadow = param->shadow;
    work->mmdl = param->mmdl;
    FLDMMDL_GetCheckInfo(param->mmdl, work->mmdlCheck);
    desc.slot = 0;
    desc.width = FLDEFF_SHADOW_ENTRY_SIZE;
    desc.height = FLDEFF_SHADOW_ENTRY_SIZE;
    desc.layer = FLDEFF_SHADOW_ENTRY_LAYER;
    desc.flags = 1;
    desc.color = 1;
    {
        VecFx32 zero = {0, 0, 0};

        desc.pos = zero;
    }
    desc.hook = 0;
    desc.hookArg = (u32)work;
    work->entryId = BILLBOARD_ACT_CreateEntries(work->shadow->billboardAct, (u16)work->shadow->slotId, &desc, 1, 3);
    if (work->entryId == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    polyId = FLDEFF_SHADOW_POLY_ID;
    BILLBOARD_SetElemPolyId(work->shadow->board, work->entryId, &polyId);
    FIELD_EFFECT_UpdateObject(obj);
}








/* Shadow effect: exit, deletes the billboard entry. */
void FLDEFF_SHADOW_Exit(FieldEffectObj *obj, FldeffShadowWork *work)
{
    if (work->entryId != 0xFFFF)
        BILLBOARD_ACT_DeleteEntries(work->shadow->billboardAct, (u16)work->entryId, 1);
}








/* Shadow effect: update, ends the effect when the model is gone and tracks if it hides the shadow. */
void FLDEFF_SHADOW_Update(FieldEffectObj *obj, FldeffShadowWork *work)
{
    if (FLDMMDL_CheckCheckInfo(work->mmdl, work->mmdlCheck) == 0) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    if (FLDMMDL_SysIsDrawEnable(FLDMMDL_GetMmdlSys(work->mmdl)) == 0) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    if (FLDMMDL_CheckStatusBitVanish(work->mmdl) == 1 || FLDMMDL_CheckMoveBit(work->mmdl, FLDEFF_SHADOW_HIDE_MOVE_BIT) != 0)
        work->hidden = 1;
    else
        work->hidden = 0;
}








/* Shadow effect: draw, shows the entry below the model or hides it. */
void FLDEFF_SHADOW_Draw(FieldEffectObj *obj, FldeffShadowWork *work)
{
    VecFx32 pos;
    VecFx32 offset;
    u32 show;
    u32 hide;
    u32 entryId = work->entryId;
    const MmdlObjCodeParam *codeParam = FLDMMDL_GetObjCodeParam(work->mmdl);
    if (work->hidden == 0) {
        show = 1;
        FLDMMDL_GetPos(work->mmdl, &pos);
        FLDMMDL_GetModelOffset(work->mmdl, &offset);
        func_0207C9D0(&pos, &offset, &pos);
        if ((u8)(codeParam->drawProcNo + 246) <= 1) {
            FLDMMDL_GetDrawOffset(work->mmdl, &offset);
            if (codeParam->mdlSize == 0)
                offset.y = -0x800;
            func_0207C9D0(&pos, &offset, &pos);
        }
        BILLBOARD_SetElemVisible(work->shadow->board, entryId, &show);
        pos.y += FLDEFF_SHADOW_RAISE;
        BILLBOARD_SetElemPos(work->shadow->board, entryId, &pos);
    } else {
        hide = 0;
        BILLBOARD_SetElemVisible(work->shadow->board, entryId, &hide);
    }
}
