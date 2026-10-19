/*
 * file:     fldeff_ripple.c
 * unit:     yes
 * function: FLDEFF_RIPPLE_Create, FLDEFF_RIPPLE_Delete, FLDEFF_RIPPLE_AddActor, FLDEFF_RIPPLE_RemoveActor, FLDEFF_RIPPLE_Start, FLDEFF_RIPPLE_InitObj, FLDEFF_RIPPLE_ExitObj, FLDEFF_RIPPLE_UpdateObj, FLDEFF_RIPPLE_DrawObj
 * address:  0x021C47B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): starts at FLDEFF_RIPPLE_Create 021C47B4 (__FILE__ anchor fldeff_ripple.c, string sFldeffRippleFileName 0x021DE468); the SCRCMD_/RAIL_SLIPDOWN_ code before it is scrcmd_player_events.c.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetGroundBbdAct  0x02188C90  thumb  ov021
 *   sFldeffRippleFileName     0x021DE468  data  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FIELD_EFFECT_ApplyPaletteTable  0x021AC1F0  thumb  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sRippleFuncs     0x021DA9F0  data  a4
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   gRippleBoardCommands     0x021DE464  data  a4
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 */
#include "../arm9/billboard_act_types.h"
#include "field_effect_types.h"

typedef struct ArcHandle ArcHandle;

typedef struct G3dResource G3dResource;                 /* layouts in arm9/g3d_system_types.h */

/* Resources of the ripple effect (allocated 0xC bytes by FLDEFF_RIPPLE_Create). */
typedef struct RippleWork {
    FieldEffectSys *fieldEffect;          /* 0x00 */
    struct BbActSys *bbActSys;            /* 0x04 */
    u16 actorId;                          /* 0x08 */
} RippleWork;

/* Start parameter of one ripple. */
typedef struct RippleStartParam {
    RippleWork *work;
    VecFx32 pos;
} RippleStartParam;

extern u32 GFL_HEAP_Free(void *p);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct FieldEffectSys;

extern u32 FIELD_EFFECT_GetFieldMap(FieldEffectSys *fieldEffect);

extern struct BbActSys *FIELDMAP_GetGroundBbdAct(struct FieldMap *fieldMap);

extern u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);

extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);

extern void FIELD_EFFECT_ApplyPaletteTable(struct FieldEffectSys *sys, void *model);

extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count);

extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count);

extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);

extern s32 FIELD_EFFECT_GetResource(struct FieldEffectSys *sys, s32 id);
struct FieldEffectObjFuncs;

extern void FIELD_EFFECT_AddObject(struct FieldEffectSys *sys, struct FieldEffectObjFuncs *funcs, VecFx32 *pos, u32 mode, void *param, u32 priority);

RippleWork *FLDEFF_RIPPLE_Create(FieldEffectSys *fieldEffect, u32 heapId);

void FLDEFF_RIPPLE_Delete(u32 unused, RippleWork *work);

void FLDEFF_RIPPLE_AddActor(RippleWork *work);

void FLDEFF_RIPPLE_RemoveActor(RippleWork *work);

void FLDEFF_RIPPLE_Start(FieldEffectSys *fieldEffect, int gridX, int gridZ, fx32 height);

extern char sFldeffRippleFileName[];

extern u8 sRippleFuncs[];

/* Work of one ripple effect object. */
typedef struct RippleObjWork {
    RippleWork *res;
    u16 entryId;
} RippleObjWork;

extern void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *obj);

extern void FIELD_EFFECT_SetObjectPos(FieldEffectObj *obj, VecFx32 *pos);

extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);

extern void FIELD_EFFECT_DeleteObject(FieldEffectObj *obj);
struct BbActCmd;

extern void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, s32 entryIndex, struct BbActCmd **cmdLists, u16 listCount);

extern void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, s32 entryIndex, u32 listIndex);

extern void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, s32 entryIndex, u32 enabled);

extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);

extern u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *p, int i, u16 *out);

void FLDEFF_RIPPLE_InitObj(FieldEffectObj *obj, RippleObjWork *work);

void FLDEFF_RIPPLE_ExitObj(FieldEffectObj *obj, RippleObjWork *work);

void FLDEFF_RIPPLE_UpdateObj(FieldEffectObj *obj, RippleObjWork *work);

void FLDEFF_RIPPLE_DrawObj(void);

extern u8 gRippleBoardCommands[];

/*
 * Allocates the 0xC-byte ripple record and registers its billboard actor.
 */
RippleWork *FLDEFF_RIPPLE_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    RippleWork *work = GFL_HEAP_Alloc(heapId, 0xC, 1, sFldeffRippleFileName, 0x56);

    work->fieldEffect = fieldEffect;
    work->bbActSys = FIELDMAP_GetGroundBbdAct((struct FieldMap *)FIELD_EFFECT_GetFieldMap(fieldEffect));
    FLDEFF_RIPPLE_AddActor(work);
    return work;
}

/* Removes the billboard actor and frees the ripple record. */
void FLDEFF_RIPPLE_Delete(u32 unused, RippleWork *work)
{
    FLDEFF_RIPPLE_RemoveActor(work);
    GFL_HEAP_Free(work);
}

/* Loads the ripple model and adds its billboard actor. */
void FLDEFF_RIPPLE_AddActor(RippleWork *work)
{
    struct BbActRec rec;
    G3dResource *res;
    ArcHandle *arc = (struct ArcHandle *)FIELD_EFFECT_GetArcHandle(work->fieldEffect);

    rec.format = 2;
    rec.sizeS = 0x13;
    rec.sizeT = 0x10;
    rec.paletteId = 0x10;
    rec.kind = 1;
    res = G3D_SYSTEM_CreateResourceArcHandle(arc, 0x2e);
    rec.resource = (u32)res;
    FIELD_EFFECT_ApplyPaletteTable(work->fieldEffect, (void *)rec.resource);
    work->actorId = BILLBOARD_ACT_CreateSlots(work->bbActSys, &rec, 1);
}

void FLDEFF_RIPPLE_RemoveActor(RippleWork *work)
{
    BILLBOARD_ACT_DeleteSlots(work->bbActSys, work->actorId, 1);
}

/* Starts a ripple on the tile at the given grid position and height. */
void FLDEFF_RIPPLE_Start(FieldEffectSys *fieldEffect, int gridX, int gridZ, fx32 height)
{
    VecFx32 pos;
    RippleStartParam param;

    FLDMMDL_MOVE_GridToVectorPos(gridX, gridZ, (int *)(&pos));
    pos.y = height - 0x8000;
    pos.z -= 0x5000;
    param.work = (struct RippleWork *)FIELD_EFFECT_GetResource(fieldEffect, 7);
    param.pos = pos;
    FIELD_EFFECT_AddObject(fieldEffect, (struct FieldEffectObjFuncs *)sRippleFuncs, 0, 0, &param, 0);
}

/* Ripple effect (fldeff_ripple.c): callbacks of its field effect object. */
void FLDEFF_RIPPLE_InitObj(FieldEffectObj *obj, RippleObjWork *work)
{
    RippleStartParam *param = (RippleStartParam *)FIELD_EFFECT_GetObjectParam(obj);
    RippleWork *bbRes;
    u32 actSys, entryId;
    struct BbActDesc desc;

    work->res = param->work;
    FIELD_EFFECT_SetObjectPos(obj, &param->pos);
    bbRes = work->res;
    actSys = (u32)bbRes->bbActSys;
    desc.slot = bbRes->actorId;
    desc.width = 0x1000;
    desc.height = 0x1000;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.pos = param->pos;
    desc.hook = 0;
    desc.hookArg = (u32)work;
    work->entryId = BILLBOARD_ACT_CreateEntries((struct BbActSys *)actSys, 0, &desc, 1, 3);
    if (work->entryId == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(obj);
        return;
    }
    BILLBOARD_ACT_SetEntryCommands((struct BbActSys *)actSys, work->entryId, (struct BbActCmd **)gRippleBoardCommands, 1);
    entryId = work->entryId;
    BILLBOARD_ACT_SetEntryList((struct BbActSys *)actSys, entryId, 0);
    BILLBOARD_ACT_SetEntryEnabled((struct BbActSys *)actSys, entryId, 1);
}

/* Exit: deletes the billboard entry unless the creation failed. */
void FLDEFF_RIPPLE_ExitObj(FieldEffectObj *obj, RippleObjWork *work)
{
    u32 actSys = (u32)work->res->bbActSys;

    if (work->entryId != 0xFFFF)
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)actSys, work->entryId, 1);
}

/* Update: ends the effect when the entry has run its last command. */
void FLDEFF_RIPPLE_UpdateObj(FieldEffectObj *obj, RippleObjWork *work)
{
    u32 lastCommand;

    if (BILLBOARD_ACT_GetEntryLastCommand(work->res->bbActSys, work->entryId, (u16 *)(&lastCommand)) != 0)
        FIELD_EFFECT_DeleteObject(obj);
}

/* Draw: nothing to do, the billboard system draws the entry. */
void FLDEFF_RIPPLE_DrawObj(void) {}
