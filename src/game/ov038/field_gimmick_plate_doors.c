/*
 * file:     field_gimmick_plate_doors.c
 * unit:     yes
 * function: FIELD_GIMMICK_PLATE_DOORS_Init, FIELD_GIMMICK_PLATE_DOORS_Exit, FIELD_GIMMICK_PLATE_DOORS_Update, FIELD_GIMMICK_PLATE_DOORS_FindDoor, FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent, FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor, FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor, FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide, FIELD_GIMMICK_PLATE_DOORS_EventBumpClosedDoor, FIELD_GIMMICK_PLATE_DOORS_StartSwitchEvent, FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent, FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent, FIELD_GIMMICK_PLATE_DOORS_EventPressSwitch, FIELD_GIMMICK_PLATE_DOORS_EventPressPlate, FIELD_GIMMICK_PLATE_DOORS_EventScripted
 * address:  0x021F36C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gPlateDoorsUnitDef     0x021F464C  data  a4
 *   gPlateDoorsSwitchPos     0x021F46E8  data  a4
 *   gPlateDoorsPlatePos     0x021F4748  data  a4
 *   gPlateDoorsDoorPos     0x021F4694  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
 *   GFL_HEAP_GetTotalFreeSize  0x02030344  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb
 *   FIELD_PLAYER_GetDirDisp 0x021A3050 thumb ov021
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb  ov021
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb  ov021
 *   EVENT_FIELD_PROCLINK_CreateObjAnimEvent  0x021618A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   gPlateDoorsPullAcmdSide1     0x021F45F8  data  a4
 *   gPlateDoorsReleaseAcmdSide1     0x021F4600  data  a4
 *   gPlateDoorsReleaseAcmdSide0     0x021F4608  data  a4
 *   gPlateDoorsPullAcmdSide0     0x021F4620  data  a4
 *   FIELD_GIMMICK_PLATE_DOORS_EventScripted 0x021F44C0 thumb ov038
 *   GIMMICK_WORK_GetSubWork 0x0200B3A8 thumb
 *   gPlateDoorsPlatePrerequisite    0x021F4628 data a1
 *   gPlateDoorsPlateDoor    0x021F4632 data a1
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   gPlateDoorsEffectPos 0x021F465C data a4
 */
#include "../ov037/gimmick_save_types.h"
#include "field_gimmick_plate_doors_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;
struct GameEvent;
struct FieldMap;
#include "../types.h"

struct FldExpObjCnt;

extern struct FldExpObjCnt *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern u8 *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern s32 *GIMMICK_WORK_GetWork(struct GimmickWork *gimmickSave, u32 gimmickId);
extern void *GFL_HEAP_GetTotalFreeSize(u32 heapId);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, s32 id, s32 heapId, s32 size);
struct G3dUtilSetup;
extern void  FLD_EXP_OBJ_AddUnitFromArchive(struct FldExpObjCnt *cnt, struct G3dUtilSetup *setup, u16 unitIdx);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, int unitIdx, u16 modelIdx);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *expObj, int unitIdx, int modelIdx, int cullDraw);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unitIdx, u16 modelIdx, int hidden);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx);
struct FldExpObjAnime;
extern void FLD_EXP_OBJ_SetAnimeLoop(struct FldExpObjAnime *anime, s32 loop);
extern void FLD_EXP_OBJ_SetAnimePaused(struct FldExpObjAnime *anime, s32 paused);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx, int enable);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *expObj, int unitIdx, u16 modelIdx, u16 animeIdx, int frame);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(struct FldExpObjAnime *anime);
extern void *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, s32 id);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, s32 id);
extern void FLD_EXP_OBJ_RemoveUnit(struct FldExpObjCnt *cnt, u16 unitIdx);
extern void FLD_EXP_OBJ_UpdateAnimes(struct FldExpObjCnt *cnt);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
struct FieldPlayer;
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
extern struct GameEvent *GAME_EVENT_Create(void *owner, void *work, void *run, u32 size);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *fieldPlayer);
struct Mmdl;
extern int FLDMMDL_CheckEndAcmd(struct Mmdl *mmdl);
extern int FLDMMDL_CheckPossibleAcmd(struct Mmdl *mmdl);
extern void FIELD_PLAYER_GetPos(unsigned char *fieldPlayer, VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *fieldPlayer, VecFx32 *pos);
extern int FLD_EXP_OBJ_IsAnimeStopped(struct FldExpObjAnime *anime);
extern int FLD_EXP_OBJ_GetAnimeFrame(struct FldExpObjCnt *cnt, s32 unitIdx, s32 modelIdx, s32 animeIdx);
extern unsigned int KEY_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *now, struct GameEvent *next);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(struct GameSystem *gameSystem, void *source, int fieldObjectId, char *animName);
extern int FLDMMDL_ACMD_ListCheckEnd(u32 acmdList);
extern void FLDMMDL_ACMD_ListDelete(void *acmdList);
extern int FLDMMDL_ACMD_ListCreate(void *mmdl, void *acmdTable);
extern int FIELD_GIMMICK_PLATE_DOORS_EventScripted(void *, int *);
extern u8 *GIMMICK_WORK_GetSubWork(struct GimmickWork *gimmickSave, u32 gimmickId);
void FIELD_GIMMICK_PLATE_DOORS_Init(void *fieldMap);
void FIELD_GIMMICK_PLATE_DOORS_Exit(void *fieldMap);
void FIELD_GIMMICK_PLATE_DOORS_Update(void *fieldMap);
int FIELD_GIMMICK_PLATE_DOORS_FindDoor(FieldGimmickPlateDoorsWork *work, int cellX, int cellZ, int *doorOpen, int *exactCell);
int FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(int gameSystem, int cellX, int cellZ);
int FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventBumpClosedDoor(int event, int *state);
void *FIELD_GIMMICK_PLATE_DOORS_StartSwitchEvent(void *gameSystem, int switchIdx);
void *FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(void *gameSystem, int plateIdx);
void *FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(void *gameSystem, int variant);
int FIELD_GIMMICK_PLATE_DOORS_EventPressSwitch(int event, int *state);
int FIELD_GIMMICK_PLATE_DOORS_EventPressPlate(int event, int *state);
extern int gPlateDoorsUnitDef;
extern VecFx32 gPlateDoorsSwitchPos[];
extern VecFx32 gPlateDoorsPlatePos[];
extern VecFx32 gPlateDoorsDoorPos[];
extern u32 gPlateDoorsPullAcmdSide1[];
extern u32 gPlateDoorsReleaseAcmdSide1[];
extern u32 gPlateDoorsReleaseAcmdSide0[];
extern u32 gPlateDoorsPullAcmdSide0[];
extern const s8 gPlateDoorsPlatePrerequisite[];
extern const u8 gPlateDoorsPlateDoor[];
/* The enum type keeps the narrowing of the script event ids, see the note above. */
typedef enum { SCRIPT_EVENT_ID_ZERO } ScriptEventId;
extern void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved);
extern void *SCRIPT_SYS_ChangeScriptEvent(void *event, u16 scriptId, void *target, s32 reserved);
extern const VecFx32 gPlateDoorsEffectPos[];

/*
 * Init: places the eight switches, ten plates and seven doors, and sets the
 * look of each from the saved state.
 */
void FIELD_GIMMICK_PLATE_DOORS_Init(void *fieldMap)
{
    void *expObj;
    int i;
    FieldGimmickPlateDoorsWork *save;
    int doorIdx;
    int j;
    int plateModel;
    int closedModel;
    int openModel;
    void *anime;
    VecFx32 *status;
    VecFx32 pos;

    expObj = (void *)FIELDMAP_GetExpObj(fieldMap);
    save = (struct FieldGimmickPlateDoorsWork *)GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 6);
    GFL_HEAP_GetTotalFreeSize(0x15);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), 0x24);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, (struct G3dUtilSetup *)(&gPlateDoorsUnitDef), 0);
    GFL_HEAP_GetTotalFreeSize(0x15);
    for (i = 0; i < 8; i++) {
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, i);
        *status = gPlateDoorsSwitchPos[i];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, i, j);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, i, j, 1);
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
            if (save->switchFound[i] != 0)
                FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, i, j, FLD_EXP_OBJ_GetAnimeLastFrame((struct FldExpObjAnime *)anime));
        }
    }
    for (i = 0; i < 10; i++) {
        plateModel = i + 8;
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, plateModel);
        *status = gPlateDoorsPlatePos[i];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)plateModel, 1);
        for (j = 0; j < 2; j++) {
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, plateModel, j);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, plateModel, j, 1);
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
            if (save->platePressed[i] != 0)
                FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, plateModel, j, FLD_EXP_OBJ_GetAnimeLastFrame((struct FldExpObjAnime *)anime));
        }
    }
    for (doorIdx = 0; doorIdx < 7; doorIdx++) {
        closedModel = doorIdx + 0x12;
        openModel = doorIdx + 0x19;
        status = FLD_EXP_OBJ_GetModelStatus(expObj, 0, closedModel);
        pos = gPlateDoorsDoorPos[doorIdx];
        *status = pos;
        *FLD_EXP_OBJ_GetModelStatus(expObj, 0, openModel) = pos;
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)closedModel, 1);
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)openModel, 1);
        switch (save->doorOpen[doorIdx]) {
        case 0:
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, openModel, 1);
            break;
        case 1:
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, closedModel, 1);
            break;
        }
    }
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)0x20, 1);
    for (i = 0; i < 2; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0x20, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    }
    for (i = 0; i < 8; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0x21, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0x21, i, 0);
    }
    for (i = 0; i < 4; i++) {
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0x22, i);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
    }
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0x21, 1);
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0x22, 1);
    GFL_HEAP_GetTotalFreeSize(0x15);
}

/* Exit: frees the runtime state and the expansion object unit. */
void FIELD_GIMMICK_PLATE_DOORS_Exit(void *fieldMap)
{
    int expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit((struct FldExpObjCnt *)expObj, 0);
}

/*
 * extent: two bytes of alignment padding at 021F3A06.
 */
void FIELD_GIMMICK_PLATE_DOORS_Update(void *fieldMap)
{
    int expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 6);
    FLD_EXP_OBJ_UpdateAnimes((void *)expObj);
}

/*
 * Finds the door at the cell or one cell to its left or right.  exactCell is
 * 1 when the cell is the door's own, doorOpen gets the saved state of the
 * door.  Returns the door index, or 7 when there is none.
 */
int FIELD_GIMMICK_PLATE_DOORS_FindDoor(FieldGimmickPlateDoorsWork *work, int cellX, int cellZ, int *doorOpen, int *exactCell)
{
    int found;
    int doorX;
    int doorZ;
    int i;
    VecFx32 *door;

    for (i = 0; i < 7; i++) {
        door = &gPlateDoorsDoorPos[i];
        doorX = door->x / 0x10000;
        doorZ = door->z / 0x10000;
        found = 0;
        if (doorX == cellX && doorZ == cellZ) {
            *exactCell = 1;
            found = 1;
        } else if (doorX - 1 == cellX && doorZ == cellZ) {
            *exactCell = 0;
            found = 1;
        } else if (doorX + 1 == cellX && doorZ == cellZ) {
            *exactCell = 0;
            found = 1;
        }
        if (found != 0) {
            *doorOpen = work->doorOpen[i];
            return i;
        }
    }
    *exactCell = 0;
    *doorOpen = 0;
    return 7;
}

/*
 * Starts the event for the door that the player faces: pushing the open door,
 * or bumping the closed one or the side of a door.
 */
int FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(int gameSystem, int cellX, int cellZ)
{
    int doorOpen;
    int exactCell;
    int fieldInfo; /* int-typed on purpose: pointer local changes codegen; holds the field map, the player, then the facing */
    int workOrDoor;
    FieldGimmickPlateDoorsRuntime *runtime;

    fieldInfo = (int)GAMESYSTEM_GetFieldMap((void *)gameSystem);
    runtime = FIELDMAP_GetCommonWork((struct FieldMap *)((void *)fieldInfo), 1);
    fieldInfo = (int)FIELDMAP_GetFieldPlayer((void *)fieldInfo);
    workOrDoor = (int)GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData((const struct GameSystem *)(int)FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap((void *)gameSystem)))), 6);
    fieldInfo = FIELD_PLAYER_GetDirDisp((struct FieldPlayer *)fieldInfo);
    if (fieldInfo != 0 && fieldInfo != 1)
        return 0;
    workOrDoor = FIELD_GIMMICK_PLATE_DOORS_FindDoor((FieldGimmickPlateDoorsWork *)workOrDoor, cellX, cellZ, &doorOpen, &exactCell);
    if (workOrDoor < 7) {
        if (exactCell != 0) {
            if (doorOpen == 1)
                GAME_EVENT_Create((void *)gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor, 0);
            else
                GAME_EVENT_Create((void *)gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventBumpClosedDoor, 0);
        } else {
            GAME_EVENT_Create((void *)gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide, 0);
        }
    } else {
        return 0;
    }
    runtime->slideFrames = 0;
    runtime->holdFrames = 0;
    runtime->side = fieldInfo;
    runtime->doorIdx = workOrDoor;
    runtime->acmdList = 0;
    runtime->acmdDone = 0;
    runtime->acmdActive = 0;
}

/*
 * Event: the player slides an open door by holding up or down, then lets go.
 * note:     u8 side and u8 j locals as in FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide.  Case 1 keeps the pressed
 *           path in the if body (the release path, a task swap to
 *           FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor, is the else) so case 0's two failed tests reuse
 *           its `b` to the shared tail; slideUnits = (u32)slideFrames >> 1 gives the plain lsrs.
 */
int FIELD_GIMMICK_PLATE_DOORS_EventSlideDoor(int event, int *state)
{
    void *gameSystem;
    void *fieldMap;
    int expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    void *fieldPlayer;
    u8 openModel;
    u8 side;
    void *anime;
    void *mmdl;
    VecFx32 *srcStatus;
    int keyMask;
    int direction;
    u32 slideUnits;
    VecFx32 pos;

    gameSystem = GAME_EVENT_GetGameSystem((struct GameEvent *)event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork(fieldMap, 1);
    fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 6);
    side = 0;
    openModel = runtime->doorIdx + 0x19;
    if (runtime->side == 1)
        side++;
    anime = FLD_EXP_OBJ_GetAnime((char *)expObj, 0, 0x22, side);
    switch (*state) {
    case 0:
        mmdl = FIELD_PLAYER_GetMmdl((void *)fieldPlayer);
        if ((struct Mmdl *)(struct Mmdl *)FLDMMDL_CheckEndAcmd((struct Mmdl *)mmdl) != 0 && (struct Mmdl *)FLDMMDL_CheckPossibleAcmd((struct Mmdl *)mmdl) != 0) {
            runtime->acmdActive = 1;
            FIELD_PLAYER_GetPos(fieldPlayer, &runtime->doorPos);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, openModel, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, 0x22, 0);
            srcStatus = FLD_EXP_OBJ_GetModelStatus((char *)expObj, 0, openModel);
            *FLD_EXP_OBJ_GetModelStatus((char *)expObj, 0, 0x22) = *srcStatus;
            FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, 0x22, side, 1);
            FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, 0x22, side, 0);
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
            runtime->slideSePlayed = 0;
            *state = *state + 1;
        }
        break;
    case 1:
        if (runtime->side == 0) {
            keyMask = 0x40;
            direction = -1;
        } else {
            keyMask = 0x80;
            direction = 1;
        }
        if ((KEY_GetCont() & keyMask) != 0) {
            runtime->holdFrames++;
            if (runtime->holdFrames >= 2) {
                runtime->holdFrames = 0;
                runtime->slideFrames++;
                FIELD_PLAYER_GetPos(fieldPlayer, &pos);
                pos.z += direction << 12;
                FIELD_PLAYER_SetPos(fieldPlayer, &pos);
                slideUnits = (u32)runtime->slideFrames >> 1;
                if (runtime->slideSePlayed == 0 && slideUnits != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x6C2);
                    runtime->slideSePlayed = 1;
                }
                FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, 0x22, side, slideUnits << 12);
                if (runtime->slideFrames >= 0x20)
                    *state = *state + 1;
            }
        } else {
            GAME_EVENT_ChangeEvent((struct GameEvent *)event, (struct GameEvent *)GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor, 0));
            return 0;
        }
        break;
    case 2:
        if (runtime->acmdList != 0) {
            if (FLDMMDL_ACMD_ListCheckEnd(runtime->acmdList) == 1) {
                FLDMMDL_ACMD_ListDelete((void *)(runtime->acmdList));
                runtime->acmdList = 0;
                runtime->acmdDone = 1;
                *state = *state + 1;
            }
        } else {
            runtime->acmdDone = 1;
            *state = *state + 1;
        }
        if (runtime->acmdDone != 0) {
            FLD_EXP_OBJ_SetAnimePaused(anime, 0);
            GAME_EVENT_CallEvent((struct GameEvent *)event, EVENT_FIELD_PROCLINK_CreateObjAnimEvent(gameSystem, (void *)fieldMap, 0xff, (char *)(runtime->side == 0 ? gPlateDoorsReleaseAcmdSide0 : gPlateDoorsReleaseAcmdSide1)));
            GFL_USE_StopAllSe();
            GFL_USE_PlaySeDefaultVolume(0x6C3);
        }
        break;
    case 3:
        (struct FldExpObjCnt *)FLD_EXP_OBJ_GetAnimeFrame((struct FldExpObjCnt *)expObj, 0, 0x22, side);
        if (FLD_EXP_OBJ_IsAnimeStopped(anime)) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, 0x22, side, 0);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, 0x22, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, openModel, 0);
            return 1;
        }
        break;
    }
    if (runtime->acmdActive != 0 && runtime->acmdDone == 0) {
        mmdl = FIELD_PLAYER_GetMmdl((void *)fieldPlayer);
        if (runtime->acmdList == 0) {
            runtime->acmdList = FLDMMDL_ACMD_ListCreate(mmdl, runtime->side == 0 ? gPlateDoorsPullAcmdSide0 : gPlateDoorsPullAcmdSide1);
        } else if (FLDMMDL_ACMD_ListCheckEnd(runtime->acmdList) == 1) {
            FLDMMDL_ACMD_ListDelete((void *)(runtime->acmdList));
            runtime->acmdList = 0;
        }
    }
    return 0;
}

/*
 * Event: the open door slides back to its home position.
 * note:     same u8 side spelling as FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide (side++ on a u8 local;
 *           the 0x021BE6xx callees take u16 parameters).
 */
int FIELD_GIMMICK_PLATE_DOORS_EventReturnDoor(int event, int *state)
{
    void *fieldMap;
    int expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    void *fieldPlayer;
    u8 openModel;
    u8 side;
    int done;
    int slideUnits;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)event));
    expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork(fieldMap, 1);
    fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    side = 0;
    openModel = runtime->doorIdx + 0x19;
    if (runtime->side == 1)
        side++;
    switch (*state) {
    case 0:
        GFL_USE_StopAllSe();
        *state = *state + 1;
    case 1:
        if (runtime->acmdList != 0) {
            if (FLDMMDL_ACMD_ListCheckEnd(runtime->acmdList) == 1) {
                FLDMMDL_ACMD_ListDelete((void *)(runtime->acmdList));
                runtime->acmdList = 0;
                runtime->slideFrames = 0;
                *state = *state + 1;
            }
        } else {
            runtime->slideFrames = 0;
            *state = *state + 1;
        }
        if (*state == 2)
            runtime->slideSePlayed = 0;
        break;
    case 2:
        FIELD_PLAYER_GetPos(fieldPlayer, &pos);
        done = 0;
        runtime->slideFrames++;
        if (runtime->side == 0) {
            pos.z += runtime->slideFrames << 12;
            if (pos.z >= runtime->doorPos.z) {
                pos.z = runtime->doorPos.z;
                done = 1;
            }
            slideUnits = (runtime->doorPos.z - pos.z) / 2;
        } else {
            pos.z += -runtime->slideFrames << 12;
            if (pos.z <= runtime->doorPos.z) {
                pos.z = runtime->doorPos.z;
                done = 1;
            }
            slideUnits = (pos.z - runtime->doorPos.z) / 2;
        }
        if (runtime->slideSePlayed == 0 && slideUnits != 0) {
            GFL_USE_PlaySeDefaultVolume(0x6C4);
            runtime->slideSePlayed = 1;
        }
        FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, 0x22, side, slideUnits);
        FIELD_PLAYER_SetPos(fieldPlayer, &pos);
        if (done) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, 0x22, side, 0);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, 0x22, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, openModel, 0);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Event: the player bumps the side of a door (shake animation on the open or
 * closed door model).
 * note:     animeIdx and tempModel (0x021BE674/0x021BE700/0x021BE6CC arguments) are u8 locals,
 *           so the u16 parameters add no narrowing at the call; animeIdx++ keeps the
 *           unfolded increment of the stored value.
 */
int FIELD_GIMMICK_PLATE_DOORS_EventBumpDoorSide(int event, int *state)
{
    void *fieldMap;
    int expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    FieldGimmickPlateDoorsWork *save;
    u8 srcModel;
    u8 tempModel;
    u8 animeIdx;
    void *anime;
    VecFx32 *srcStatus;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)event));
    expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_GetFieldPlayer(fieldMap);
    save = (struct FieldGimmickPlateDoorsWork *)GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 6);
    if (save->doorOpen[runtime->doorIdx] == 0) {
        srcModel = runtime->doorIdx + 0x12;
        tempModel = 0x21;
    } else {
        srcModel = runtime->doorIdx + 0x19;
        tempModel = 0x22;
    }
    animeIdx = 2;
    if (runtime->side == 1)
        animeIdx++;
    anime = FLD_EXP_OBJ_GetAnime((char *)expObj, 0, tempModel, animeIdx);
    switch (*state) {
    case 0:
        FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, srcModel, 1);
        FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, tempModel, 0);
        srcStatus = FLD_EXP_OBJ_GetModelStatus((char *)expObj, 0, srcModel);
        *FLD_EXP_OBJ_GetModelStatus((char *)expObj, 0, tempModel) = *srcStatus;
        FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, tempModel, animeIdx, 1);
        FLD_EXP_OBJ_SetAnimePaused(anime, 0);
        FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, tempModel, animeIdx, 0);
        GFL_USE_PlaySeDefaultVolume(0x6C5);
        *state = *state + 1;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(anime)) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, tempModel, animeIdx, 0);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, tempModel, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, srcModel, 0);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Event: the player bumps a closed door (shake animation on the closed model).
 * note:     `animeIdx++` on the u8 local keeps the increment of the stored zero
 *           (adds; lsls; lsrs); `animeIdx = animeIdx + 1` folds it to `movs #1` and swaps
 *           state/fieldMap between r5 and r6.
 */
int FIELD_GIMMICK_PLATE_DOORS_EventBumpClosedDoor(int event, int *state)
{
    void *fieldMap;
    char *expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    u8 closedModel;
    u8 animeIdx;
    void *anime;
    VecFx32 *srcStatus;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)event));
    expObj = (char *)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork((struct FieldMap *)fieldMap, 1);
    FIELDMAP_GetFieldPlayer(fieldMap);
    animeIdx = 0;
    closedModel = runtime->doorIdx + 0x12;
    if (runtime->side == 1) {
        animeIdx++;
    }
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, 0x21, animeIdx);
    switch (*state) {
    case 0:
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, closedModel, 1);
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0x21, 0);
        srcStatus = FLD_EXP_OBJ_GetModelStatus(expObj, 0, closedModel);
        *FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0x21) = *srcStatus;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0x21, animeIdx, 1);
        FLD_EXP_OBJ_SetAnimePaused(anime, 0);
        FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, 0x21, animeIdx, 0);
        GFL_USE_PlaySeDefaultVolume(0x6C5);
        *state = *state + 1;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(anime)) {
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0x21, animeIdx, 0);
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0x21, 1);
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, closedModel, 0);
            return 1;
        }
        break;
    }
    return 0;
}

/* Script command: starts the press event of a switch. */
void *FIELD_GIMMICK_PLATE_DOORS_StartSwitchEvent(void *gameSystem, int switchIdx)
{
    FieldGimmickPlateDoorsRuntime *runtime = FIELDMAP_GetCommonWork((struct FieldMap *)GAMESYSTEM_GetFieldMap(gameSystem), 1);
    if (switchIdx >= 8) return 0;
    runtime->switchIdx = switchIdx;
    return GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventPressSwitch, 0);
}

/* Script command: starts the press event of a plate. */
void *FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(void *gameSystem, int plateIdx)
{
    FieldGimmickPlateDoorsRuntime *runtime = FIELDMAP_GetCommonWork((struct FieldMap *)GAMESYSTEM_GetFieldMap(gameSystem), 1);
    if (plateIdx >= 10) return 0;
    runtime->plateIdx = plateIdx;
    return GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventPressPlate, 0);
}

/* Script command: starts the scripted event, whose script depends on the variant. */
void *FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(void *gameSystem, int variant)
{
    FieldGimmickPlateDoorsRuntime *runtime = FIELDMAP_GetCommonWork((struct FieldMap *)GAMESYSTEM_GetFieldMap(gameSystem), 1);
    runtime->scriptVariant = variant;
    return GAME_EVENT_Create(gameSystem, 0, FIELD_GIMMICK_PLATE_DOORS_EventScripted, 0);
}

/*
 * Event: plays the press animation of a switch and saves it as found.
 * note:     the case-0 byte must be held in a u8 (or u16) local: an int local
 *           swaps the 0x0201210C result and the 0x021897BC pointer between r4
 *           and r5.  GAME_EVENT_GetGameSystem/GAMESYSTEM_GetFieldMap are argless as in the twin
 *           ov045_func_021F39B8.  FLD_EXP_OBJ_SetAnimeEnabled/FLD_EXP_OBJ_GetAnime take their
 *           fourth argument as u16 (the caller truncates it before the bl).
 *           FLD_EXP_OBJ_GetAnime's third parameter must be `int` here, as for
 *           FLD_EXP_OBJ_SetAnimeEnabled: its own file's `unsigned int j` brings the r4/r5
 *           swap back even with the u8 local.
 */
int FIELD_GIMMICK_PLATE_DOORS_EventPressSwitch(int event, int *state)
{
    void *fieldMap;
    int expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    FieldGimmickPlateDoorsWork *save;
    unsigned int gimmickSave;
    u16 *progress;
    int i;
    u8 switchModel;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)event));
    expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork(fieldMap, 1);
    gimmickSave = (unsigned int)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData((const struct GameSystem *)FIELDMAP_GetGameSystem(fieldMap)));
    save = (struct FieldGimmickPlateDoorsWork *)GIMMICK_WORK_GetWork((struct GimmickWork *)gimmickSave, 6);
    progress = (u16 *)GIMMICK_WORK_GetSubWork((struct GimmickWork *)gimmickSave, 6);
    switch (*state) {
    case 0:
        switchModel = runtime->switchIdx;
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, switchModel, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)expObj, 0, switchModel, i), 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)expObj, 0, runtime->switchIdx, 0))) {
            save->switchFound[runtime->switchIdx] = 1;
            progress[runtime->switchIdx] = 1;
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Event: plays the press animation of a plate; when the plate it depends on is
 * pressed and its door is still closed, the door lights up and opens.
 * note:     the work block's two int arrays are struct fields (index*4 then
 *           [#0x20]/[#0x48]); the flag test is `if (n != -1) { if (a[n])
 *           f = 1; } else f = 1;`, whose cross-jumped else arm gives the
 *           `beq SET ... beq SKIP; b SET` shape (an `||` or else-if does not).
 */
int FIELD_GIMMICK_PLATE_DOORS_EventPressPlate(int event, int *state)
{
    void *fieldMap;
    int expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    FieldGimmickPlateDoorsWork *save;
    int i;
    int ready;
    u8 plateModel;
    u8 doorIdx;
    s8 prerequisite;
    VecFx32 *srcStatus;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)event));
    expObj = (s32)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork((struct FieldMap *)fieldMap, 1);
    save = (struct FieldGimmickPlateDoorsWork *)GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData((const struct GameSystem *)FIELDMAP_GetGameSystem(fieldMap))), 6);
    switch (*state) {
    case 0:
        plateModel = runtime->plateIdx + 8;
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, plateModel, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)expObj, 0, plateModel, i), 0);
        }
        *state = *state + 1;
        break;
    case 1:
        ready = 0;
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)expObj, 0, (u8)(runtime->plateIdx + 8), 0))) {
            save->platePressed[runtime->plateIdx] = 1;
            prerequisite = gPlateDoorsPlatePrerequisite[runtime->plateIdx];
            if (prerequisite != -1) {
                if (save->platePressed[prerequisite] != 0) {
                    ready = 1;
                }
            } else {
                ready = 1;
            }
            if (ready) {
                doorIdx = gPlateDoorsPlateDoor[runtime->plateIdx];
                if (save->doorOpen[doorIdx] == 0) {
                    runtime->plateDoorIdx = doorIdx;
                    plateModel = doorIdx + 0x12;
                    FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, (u16)plateModel, 1);
                    FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, (u16)0x21, 0);
                    srcStatus = FLD_EXP_OBJ_GetModelStatus((char *)expObj, 0, plateModel);
                    *FLD_EXP_OBJ_GetModelStatus((char *)expObj, 0, 0x21) = *srcStatus;
                    for (i = 0; i < 4; i++) {
                        plateModel = i + 4;
                        FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, 0x21, (u16)plateModel, 1);
                        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)expObj, 0, 0x21, plateModel), 0);
                        FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, 0x21, plateModel, 0);
                    }
                    GFL_USE_PlaySeDefaultVolume(0x6C8);
                    *state = *state + 1;
                    break;
                }
                return 1;
            }
            return 1;
        }
        break;
    case 2:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)expObj, 0, 0x21, 4))) {
            for (i = 0; i < 4; i++) {
                FLD_EXP_OBJ_SetAnimeEnabled((void *)expObj, 0, 0x21, (u16)((u8)(i + 4)), 0);
            }
            save->doorOpen[runtime->plateDoorIdx] = 1;
            doorIdx = runtime->plateDoorIdx;
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, (u16)(doorIdx + 0x12), 1);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, (u16)(doorIdx + 0x19), 0);
            FLD_EXP_OBJ_SetModelHidden((char *)expObj, 0, (u16)0x21, 1);
            GFL_USE_PlaySeDefaultVolume(0x6DC);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Event: shows the effect model at the position of the variant, calls the
 * first script event, waits for the effect animation and calls the second.
 */
int FIELD_GIMMICK_PLATE_DOORS_EventScripted(void *event, int *state)
{
    void *fieldMap;
    void *expObj;
    FieldGimmickPlateDoorsRuntime *runtime;
    u8 *anime;
    int i;
    ScriptEventId scriptId;

    fieldMap = (void *)GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = (void *)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(fieldMap))), 6);
    switch (*state) {
    case 0:
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0x20, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, 0x20, i), 0);
            FLD_EXP_OBJ_SetAnimeFrame((void *)expObj, 0, 0x20, i, 0);
        }
        *FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0x20) = gPlateDoorsEffectPos[runtime->scriptVariant];
        *state = *state + 1;
        break;
    case 1:
        scriptId = 4;
        if (runtime->scriptVariant == 0)
            scriptId = 3;
        SCRIPT_SYS_CallScriptEvent(event, (u16)scriptId, 0, 0, 0x8015);
        *state = *state + 1;
        break;
    case 2:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, 0x20, 0))) {
            scriptId = 6;
            if (runtime->scriptVariant == 0)
                scriptId = 5;
            SCRIPT_SYS_ChangeScriptEvent((void *)event, (u16)scriptId, 0, 0x8015);
            *state = *state + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
