/*
 * file:     fldeff_ripple.c
 * unit:     yes
 * function: SCRCMD_PLAYER_GRID_EVENT_WaitA, SCRCMD_PLAYER_GRID_EVENT_StartA, SCRCMD_PLAYER_GRID_EVENT_WaitB, SCRCMD_PLAYER_GRID_EVENT_StartB, SCRCMD_IAIGIRI_StartOnPlayer, SCRCMD_SAVEANIME_Start, FIELD_OV063_StartAtPlayer, FIELD_OV063_Start, FIELD_OV063_TaskUpdate, FLDEFF_RIPPLE_Create, FLDEFF_RIPPLE_Delete, FLDEFF_RIPPLE_AddActor, FLDEFF_RIPPLE_RemoveActor, FLDEFF_RIPPLE_Start, FLDEFF_RIPPLE_InitObj, FLDEFF_RIPPLE_ExitObj, FLDEFF_RIPPLE_UpdateObj, FLDEFF_RIPPLE_DrawObj
 * address:  0x021C457C
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
 *   func_020307B0  0x020307B0  arm
 *   gSpeciesNameBank     0x020A7370  data
 *   FIELD_PLAYER_GRID_EVENT_IsHopDone  0x021C1094  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_DeleteHopTask  0x021C10A0  thumb  ov021
 *   SCRCMD_WORK_GetTargetObject  0x0215A64C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_CreateHopTask  0x021C1024  thumb  ov021
 *   SCRCMD_WORK_SetTargetObject  0x0215A644  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   FIELD_PLAYER_GRID_EVENT_IsJumpDone  0x021C12C4  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_DeleteJumpTask  0x021C12D0  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_PLAYER_GRID_EVENT_CreateJumpTask  0x021C1228  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_IAIGIRI_Start  0x021C9550  thumb  ov021
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLDEFF_RIPPLE_CreateZoneStartWarpTask  0x021D2418  thumb  ov021
 *   FLDEFF_RIPPLE_CreateSpecialLocationWarpTask  0x021D2440  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   FIELD_PLAYER_SetDirDisp  0x021A305C  thumb  ov021
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov063_id       0x0000003F  data
 *   func_021F3758  0x021F3758  thumb  ov063
 *   func_021F376C  0x021F376C  thumb  ov063
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
 */
#include "../arm9/billboard_act_types.h"
#include "field_effect_types.h"

struct Pokemon;
struct Personal;
struct MyStatus;
struct BbActSys;
struct FieldMap;
struct MsgBank;
struct StrBuf;

typedef struct ArcHandle ArcHandle;
typedef struct G3dResource G3dResource;                 /* layouts in arm9/g3d_system_types.h */

/* Mon data ids read and written through the Pokemon data accessors. */
enum {
    MON_DATA_SPECIES = 5,
    MON_DATA_HELD_ITEM = 6,
    MON_DATA_OT_ID = 7,
    MON_DATA_FRIENDSHIP = 9,
    MON_DATA_ABILITY = 0xA,
    MON_DATA_LANGUAGE = 0xC,
    MON_DATA_MOVE1 = 0x36,
    MON_DATA_MOVE2 = 0x37,
    MON_DATA_MOVE3 = 0x38,
    MON_DATA_MOVE4 = 0x39,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_GENDER = 0x6E,
    MON_DATA_FORM = 0x6F,
    MON_DATA_NATURE = 0x70,
    MON_DATA_NICKNAME = 0x73,
    MON_DATA_OT_NAME = 0x8D,
    MON_DATA_ABILITY_SET = 0xB2
};

/* Day care work (same object as SodateyaWork in fld3d_ci_types.h). */
typedef struct SodateyaWork {
    u16 heapId;                           /* 0x00 */
    u16 pad02;
    struct FieldMap *fieldMap;            /* 0x04 */
    void *dayCare;                        /* 0x08 */
    u16 stepCount;                        /* 0x0C steps walked since the last egg check */
} SodateyaWork;

/* The four move slots of a Pokemon, as mon data ids. */
typedef struct MoveSlotIdTable { u32 ids[4]; } MoveSlotIdTable;

/* The six IVs or the six power items, in HP, Atk, Def, SpAtk, SpDef, Speed order. */
typedef struct StatTable { u32 ids[6]; } StatTable;

/* A baby species, the incense that lets it hatch, and the species hatched without it. */
typedef struct IncenseBabyEntry {
    u32 babySpecies;
    u32 incenseItem;
    u32 adultSpecies;
} IncenseBabyEntry;

typedef struct IncenseBabyTable { IncenseBabyEntry entries[12]; } IncenseBabyTable;

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

extern u32 func_020307B0(void *p);
extern void *SCRCMD_WORK_GetTargetObject(void *a);
extern int FIELD_PLAYER_GRID_EVENT_IsHopDone(void *x);
extern int FIELD_PLAYER_GRID_EVENT_DeleteHopTask(u32 a);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const void *p);
extern void *FIELDMAP_GetFieldPlayer(void *p);
extern void *FIELD_PLAYER_GetMmdl(void *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern u32 FIELDMAP_GetG3dMapper(void *p);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u32 FIELD_PLAYER_GRID_EVENT_CreateHopTask(void *a, u32 b, u32 c, u32 d);
extern void SCRCMD_WORK_SetTargetObject(void *p, u32 v);
extern void VM_SetWait(char *p, int val);
extern int FIELD_PLAYER_GRID_EVENT_IsJumpDone(void *x);
extern void FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(void *x);
extern u16 FIELD_PLAYER_GetDirDisp(void *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u32 FIELD_PLAYER_GRID_EVENT_CreateJumpTask(void *a, u32 b, u32 c, u32 d);
extern u32 FIELDMAP_GetEffect(void *p);
extern void FLDEFF_IAIGIRI_Start(u32 a, u32 b);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *FLDEFF_RIPPLE_CreateZoneStartWarpTask(void *a, u32 b);
extern void *FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern void *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *p);
extern int func_02034AC4(int a);
extern void FIELD_PLAYER_SetDirDisp(void *p, u32 b);
extern void *func_021F36C0(void *a, u32 b, u32 c, u32 d);
extern void func_02034A5C(s32 handle);
extern int func_021F376C(int *p);
extern void func_021F3758(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct FieldMap *FIELD_EFFECT_GetFieldMap(FieldEffectSys *fieldEffect);
extern struct BbActSys *FIELDMAP_GetGroundBbdAct(struct FieldMap *fieldMap);
extern ArcHandle *FIELD_EFFECT_GetArcHandle(FieldEffectSys *fieldEffect);
extern G3dResource *G3D_SYSTEM_CreateResourceArcHandle(ArcHandle *arc, u32 fileId);
extern void FIELD_EFFECT_ApplyPaletteTable(FieldEffectSys *fieldEffect, G3dResource *res);
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count);
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern void *FIELD_EFFECT_GetResource(FieldEffectSys *fieldEffect, u32 effectId);
extern void FIELD_EFFECT_AddObject(FieldEffectSys *fieldEffect, const void *funcs, const VecFx32 *pos, u32 arg4, void *param, u32 priority);
extern void *gSpeciesNameBank;

int SCRCMD_PLAYER_GRID_EVENT_WaitA(void *vm, void *scriptWork);
u32 SCRCMD_PLAYER_GRID_EVENT_StartA(u32 vm, void *scriptWork);
int SCRCMD_PLAYER_GRID_EVENT_WaitB(void *vm, void *scriptWork);
u32 SCRCMD_PLAYER_GRID_EVENT_StartB(u32 vm, void *scriptWork);
int SCRCMD_IAIGIRI_StartOnPlayer(void *vm, void *scriptWork);
int SCRCMD_SAVEANIME_Start(void *vm, void *scriptWork);
u32 FIELD_OV063_StartAtPlayer(u32 a, u32 b, u32 c);
void *FIELD_OV063_Start(void *a, u32 b, u32 c);
int FIELD_OV063_TaskUpdate(void *task);
RippleWork *FLDEFF_RIPPLE_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_RIPPLE_Delete(u32 unused, RippleWork *work);
void FLDEFF_RIPPLE_AddActor(RippleWork *work);
void FLDEFF_RIPPLE_RemoveActor(RippleWork *work);
void FLDEFF_RIPPLE_Start(FieldEffectSys *fieldEffect, int gridX, int gridZ, fx32 height);
extern unsigned char ov063_id[];
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
extern void BILLBOARD_ACT_SetEntryCommands(void *p, int idx, u32 v, u16 h);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *p, int i, u16 *out);
void FLDEFF_RIPPLE_InitObj(FieldEffectObj *obj, RippleObjWork *work);
void FLDEFF_RIPPLE_ExitObj(FieldEffectObj *obj, RippleObjWork *work);
void FLDEFF_RIPPLE_UpdateObj(FieldEffectObj *obj, RippleObjWork *work);
void FLDEFF_RIPPLE_DrawObj(void);
extern u8 gRippleBoardCommands[];

/*
 * Script wait callback of the first grid event command: done once
 * FIELD_PLAYER_GRID_EVENT_IsHopDone reports 1.
 */
int SCRCMD_PLAYER_GRID_EVENT_WaitA(void *vm, void *scriptWork)
{
    void *gridEvent = SCRCMD_WORK_GetTargetObject(scriptWork);

    if (FIELD_PLAYER_GRID_EVENT_IsHopDone(gridEvent) == 1) {
        FIELD_PLAYER_GRID_EVENT_DeleteHopTask((u32)gridEvent);
        return 1;
    }
    return 0;
}

/*
 * First grid event script command: starts the event on the player's grid
 * position and installs SCRCMD_PLAYER_GRID_EVENT_WaitA as the wait callback.
 */
u32 SCRCMD_PLAYER_GRID_EVENT_StartA(u32 vm, void *scriptWork)
{
    u32 pos[3];
    u32 playerWork, effectId, result;
    void *fieldMap;
    void *player;

    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)scriptWork));
    player = FIELDMAP_GetFieldPlayer((void *)fieldMap);
    playerWork = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(player));
    fieldMap = (void *)FIELDMAP_GetG3dMapper(fieldMap);
    effectId = SCRCMD_WORK_GetHeapId((void *)scriptWork);
    FIELD_PLAYER_GetPosInDir(player, playerWork, (int *)pos);
    result = MAP_ATTR_GetAt(fieldMap, pos);
    result = FIELD_PLAYER_GRID_EVENT_CreateHopTask(player, playerWork, result, effectId);
    SCRCMD_WORK_SetTargetObject((void *)scriptWork, result);
    VM_SetWait((char *)vm, (int)SCRCMD_PLAYER_GRID_EVENT_WaitA);
    return 1;
}

/*
 * Script wait callback of the second grid event command.
 */
int SCRCMD_PLAYER_GRID_EVENT_WaitB(void *vm, void *scriptWork)
{
    void *gridEvent = SCRCMD_WORK_GetTargetObject(scriptWork);

    if (FIELD_PLAYER_GRID_EVENT_IsJumpDone(gridEvent) == 1) {
        FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(gridEvent);
        return 1;
    }
    return 0;
}

/*
 * Second grid event script command (see SCRCMD_PLAYER_GRID_EVENT_StartA).
 */
u32 SCRCMD_PLAYER_GRID_EVENT_StartB(u32 vm, void *scriptWork)
{
    u32 effectId, playerWork, result;
    void *player;

    effectId = SCRCMD_WORK_GetHeapId(scriptWork);
    player = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)scriptWork)));
    playerWork = FIELD_PLAYER_GetDirDisp(player);
    result = SCRIPT_WORK_ReadWorkValue((void *)vm, (void *)scriptWork);
    result = FIELD_PLAYER_GRID_EVENT_CreateJumpTask(player, playerWork, result, effectId);
    SCRCMD_WORK_SetTargetObject((void *)scriptWork, result);
    VM_SetWait((char *)vm, (int)SCRCMD_PLAYER_GRID_EVENT_WaitB);
    return 1;
}

/*
 * Script command: starts the Cut effect on the player's field object.
 */
int SCRCMD_IAIGIRI_StartOnPlayer(void *vm, void *scriptWork)
{
    void *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scriptWork));
    void *playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)fieldMap));

    FLDEFF_IAIGIRI_Start((u32)playerMmdl, FIELDMAP_GetEffect(fieldMap));
    return 0;
}

/*
 * Script command: starts a saved animation chosen by the type SCRIPT_WORK_ReadWorkValue
 * returns. The shared SCRIPT_SYS_CallEvent call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills the script object instead of scriptWork.
 */
int SCRCMD_SAVEANIME_Start(void *vm, void *scriptWork)
{
    u32 type;
    void *fieldMap;
    void *saveAnimeArg;
    void *scriptObj;

    saveAnimeArg = SCRCMD_WORK_GetGameSystem(scriptWork);
    fieldMap = GAMESYSTEM_GetFieldMap(saveAnimeArg);
    scriptObj = SCRCMD_WORK_GetScriptWork(scriptWork);
    type = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    if (type == 0)
        SCRIPT_SYS_CallEvent(scriptObj, FLDEFF_RIPPLE_CreateZoneStartWarpTask(saveAnimeArg, (u32)fieldMap));
    else if (type == 1)
        SCRIPT_SYS_CallEvent(scriptObj, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(saveAnimeArg, (u32)fieldMap, 0));
    else
        SCRIPT_SYS_CallEvent(scriptObj, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(saveAnimeArg, (u32)fieldMap, 1));
    return 1;
}

/*
 * Starts the ov063 effect for the player's grid event with the player's
 * data and spawns the task that drives it.
 */
u32 FIELD_OV063_StartAtPlayer(u32 a, u32 b, u32 c)
{
    u32 task = (u32)func_020122C0((void *)a, 0, FIELD_OV063_TaskUpdate, 4);
    u32 *effectSlot = func_020124E8((void *)task);
    void *fieldMap;
    void *player;

    func_02034AC4((int)ov063_id);
    fieldMap = FIELDMAP_GetFieldPlayer((void *)b);
    player = FIELD_PLAYER_GetMmdl((void *)fieldMap);
    FIELD_PLAYER_SetDirDisp(fieldMap, c);
    *effectSlot = (u32)func_021F36C0((void *)a, b, (u32)player, 1);
    return task;
}

/*
 * Loads ov063 and spawns the task that drives its effect.
 */
void *FIELD_OV063_Start(void *a, u32 b, u32 c)
{
    void *task = func_020122C0(a, 0, FIELD_OV063_TaskUpdate, 4);
    void **effectSlot = func_020124E8(task);

    func_02034AC4((u32)ov063_id);
    *effectSlot = func_021F36C0(a, b, c, 0);
    return task;
}

/*
 * Task callback: when the ov063 effect reports done, frees it and unloads
 * ov063.
 */
int FIELD_OV063_TaskUpdate(void *task)
{
    void **effectSlot = func_020124E8(task);

    if (func_021F376C(*effectSlot) != 0) {
        func_021F3758(*effectSlot);
        func_02034A5C((u32)ov063_id);
        return 1;
    }
    return 0;
}

/*
 * Allocates the 0xC-byte ripple record and registers its billboard actor.
 */
RippleWork *FLDEFF_RIPPLE_Create(FieldEffectSys *fieldEffect, u32 heapId)
{
    RippleWork *work = func_02030734(heapId, 0xC, 1, sFldeffRippleFileName, 0x56);

    work->fieldEffect = fieldEffect;
    work->bbActSys = FIELDMAP_GetGroundBbdAct(FIELD_EFFECT_GetFieldMap(fieldEffect));
    FLDEFF_RIPPLE_AddActor(work);
    return work;
}

/* Removes the billboard actor and frees the ripple record. */
void FLDEFF_RIPPLE_Delete(u32 unused, RippleWork *work)
{
    FLDEFF_RIPPLE_RemoveActor(work);
    func_020307B0(work);
}

/* Loads the ripple model and adds its billboard actor. */
void FLDEFF_RIPPLE_AddActor(RippleWork *work)
{
    struct BbActRec rec;
    G3dResource *res;
    ArcHandle *arc = FIELD_EFFECT_GetArcHandle(work->fieldEffect);

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
    param.work = FIELD_EFFECT_GetResource(fieldEffect, 7);
    param.pos = pos;
    FIELD_EFFECT_AddObject(fieldEffect, sRippleFuncs, 0, 0, &param, 0);
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
    BILLBOARD_ACT_SetEntryCommands((struct BbActSys *)actSys, work->entryId, (u32)gRippleBoardCommands, 1);
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
