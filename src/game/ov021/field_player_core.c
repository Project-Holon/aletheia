/*
 * file:     field_player_core.c
 * unit:     yes
 * function: FIELD_PLAYER_CORE_Create, FIELD_PLAYER_CORE_Delete, FIELD_PLAYER_CORE_UpdateStepPhase, FIELD_PLAYER_CORE_GetPos, FIELD_PLAYER_CORE_SetPos, FIELD_PLAYER_CORE_GetDirDisp, FIELD_PLAYER_CORE_SetDirDisp, FIELD_PLAYER_CORE_SetObjCode, FIELD_PLAYER_CORE_ClearRememberedObjCode, FIELD_PLAYER_CORE_GetFieldMap, FIELD_PLAYER_CORE_GetMmdl, FIELD_PLAYER_CORE_SetStepKind, FIELD_PLAYER_CORE_GetStepKind, FIELD_PLAYER_CORE_SetStepPhase, FIELD_PLAYER_CORE_GetStepPhase, FIELD_PLAYER_CORE_GetFormCode, FIELD_PLAYER_CORE_SetFormCode, FIELD_PLAYER_CORE_GetSex, FIELD_PLAYER_CORE_GetGameSystem, FIELD_PLAYER_CORE_GetPlayerWork, FIELD_PLAYER_CORE_ApplyFormCodeModel, FIELD_PLAYER_CORE_SetFormSlotModel, FIELD_PLAYER_CORE_WaitModelReady, FIELD_PLAYER_CORE_GetFormSlot, FIELD_PLAYER_CORE_CheckFormModel, FIELD_PLAYER_CORE_CheckAnimePaused, FIELD_PLAYER_CORE_CheckAcmdPossible, FIELD_PLAYER_CORE_ChooseMoveDirFromKeys, FIELD_PLAYER_CORE_RememberKeyDirs, FIELD_PLAYER_CORE_SetRideEffect, FIELD_PLAYER_CORE_GetRideEffect, FIELD_PLAYER_CORE_ChangeModel, FIELD_PLAYER_CORE_SetFormCodeModel, FIELD_PLAYER_CORE_CheckPlainModel, FIELD_PLAYER_CORE_CheckDrawProcReady, FIELD_PLAYER_CORE_SelectMoveDir, FIELD_PLAYER_CORE_StoreKeyDirs, FIELD_PLAYER_CORE_GetHorzDirFromKeys, FIELD_PLAYER_CORE_GetVertDirFromKeys, FIELD_PLAYER_CORE_RunFormSteps, FIELD_PLAYER_CORE_GetLowestFormSlot, FIELD_PLAYER_CORE_StartFormChange, FIELD_PLAYER_CORE_StepFormChange, FIELD_PLAYER_CORE_FinishFormChange, FIELD_PLAYER_CORE_ChangeToObjCode, FIELD_PLAYER_CORE_ChangeToFormSlot, FIELD_PLAYER_CORE_FinishFormSlotChange, FIELD_PLAYER_CORE_FormStepNormal, FIELD_PLAYER_CORE_FormStepCycle, FIELD_PLAYER_CORE_FormStepCycleDone, FIELD_PLAYER_CORE_FormStepSurf, FIELD_PLAYER_CORE_FormStepRestoreModel, FIELD_PLAYER_CORE_FormStepRestoreModelDone, FIELD_PLAYER_CORE_FormStepSlot4, FIELD_PLAYER_CORE_FormStepSlot4Done, FIELD_PLAYER_CORE_FormStepSlot5, FIELD_PLAYER_CORE_FormStepSlot5Done, FIELD_PLAYER_CORE_FormStepSlot6, FIELD_PLAYER_CORE_FormStepSlot6Done, FIELD_PLAYER_CORE_FormStepSlot9, FIELD_PLAYER_CORE_FormStepSlot9Done, FIELD_PLAYER_CORE_FormStepDive, FIELD_PLAYER_CORE_FormStepSlot8, FIELD_PLAYER_CORE_FormStepSlot8Done, FIELD_PLAYER_CORE_PostZoneBgmChange
 * address:  0x021A36E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A3804 (gFieldPlayerCoreFileName "field_player_core.c"); 021A36E4 is the core constructor called by field_player.c 021A2E50.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   GAME_DATA_GetPlayerPalaceZoneId  0x02012B34  thumb
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetStatusBitZoneDeleteOff  0x0216DB80  thumb  ov010
 *   gFieldPlayerCoreFileName     0x021DDEB8  data  a1
 *   gFieldPlayerAvatarHeaderTemplate     0x021D89A0  data  a4
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   GAME_DATA_SetPlayerPalaceZoneId  0x02012B30  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb
 *   FLDMMDL_ACMD_CheckAnimePaused  0x02197C9C  thumb
 *   FLDMMDL_BLACT_GetEntryHookFlag  0x0219C648  thumb
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDMMDL_BLACT_ChangeObjCode  0x0219D208  thumb  ov021
 *   FLDMMDL_SysWaitBlActResLoad  0x0216CD88  thumb  ov010
 *   FLDMMDL_ChangeObjCode  0x0216E204  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   gFieldPlayerFormStepTables  0x021D89C4  data  a4
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_NAMIPOKE_Start  0x021ACB38  thumb  ov021
 *   FLDEFF_BUBBLE_Start  0x021D05D8  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetWakeEnabled  0x021ACBC8  thumb  ov021
 *   FLDMMDL_MOVE_AddDirGrid  0x02164240  thumb  ov010
 *   FLDMMDL_DRAW_SetState  0x0219F5C8  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade  0x02029D8C  thumb
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FIELD_PLAYER_GetFormObjCode  0x021A3190  thumb  ov021
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb  ov021
 *   FIELD_PLAYER_GetFormSlotOfObjCode  0x021A31D0  thumb  ov021
 */
#include "fldeff_namipoke.h"
#include "field_player_types.h"

#include "../types.h"

/* Pad keys the avatar direction is read from, and the direction ids. */
#define FIELD_PLAYER_KEY_RIGHT 0x10
#define FIELD_PLAYER_KEY_LEFT  0x20
#define FIELD_PLAYER_KEY_UP    0x40
#define FIELD_PLAYER_KEY_DOWN  0x80
#define FIELD_PLAYER_DIR_UP    0
#define FIELD_PLAYER_DIR_DOWN  1
#define FIELD_PLAYER_DIR_LEFT  2
#define FIELD_PLAYER_DIR_RIGHT 3
#define FIELD_PLAYER_DIR_NONE  9

/* The form codes the player work stores (FieldPlayerFormEntry.formCode). */
#define FIELD_PLAYER_FORM_CODE_SURF 2
#define FIELD_PLAYER_FORM_CODE_DIVE 3

struct GameData;

#include "../arm9/gfl_heap_wrap.h"
#include "../ov010/fldmmdl.h"
struct VecFx32;
struct Mmdl;
#include "fieldmap.h"
#include "../arm9/gamesystem.h"
extern u16 GAME_DATA_GetPlayerPalaceZoneId(const struct PlayerWork *playerWork);
struct MmdlHeader;
extern u32 GAME_DATA_SetPlayerPalaceZoneId(struct PlayerWork *playerWork, u32 objCode);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *playerWork);
extern void GAME_DATA_SetPlayerObjectCode(struct PlayerWork *playerWork, u32 formCode);
struct BlactSys;
struct BbActSys;
#include "fldmmdl_blact.h"
#include "fldmmdl_acmd.h"
#include "../arm9/billboard_act.h"
struct FieldEffectObj;
#include "field_effect.h"
struct FieldMap;
struct FieldEffectSys;
struct FieldEffectSys;
#include "fldeff_bubble.h"
#include "../ov010/fldmmdl_move.h"
#include "fldmmdl_draw.h"
extern u32 GAME_DATA_GetBgmInfo(struct GameData *gameData);
struct FieldSoundSystem;
#include "../arm9/field_sound_system.h"

#include "field_player.h"

extern FieldPlayerCore *FIELD_PLAYER_CORE_Create(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId);
void FIELD_PLAYER_CORE_Delete(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_UpdateStepPhase(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_GetPos(FieldPlayerCore *core, VecFx32 *out);
void FIELD_PLAYER_CORE_SetPos(FieldPlayerCore *core, VecFx32 *pos);
u16 FIELD_PLAYER_CORE_GetDirDisp(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetDirDisp(FieldPlayerCore *core, int dir);
void FIELD_PLAYER_CORE_SetObjCode(FieldPlayerCore *core, u32 objCode);
void FIELD_PLAYER_CORE_ClearRememberedObjCode(FieldPlayerCore *core);
FieldMap *FIELD_PLAYER_CORE_GetFieldMap(FieldPlayerCore *core);
Mmdl *FIELD_PLAYER_CORE_GetMmdl(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetStepKind(FieldPlayerCore *core, u32 stepKind);
u32 FIELD_PLAYER_CORE_GetStepKind(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetStepPhase(FieldPlayerCore *core, u32 stepPhase);
u32 FIELD_PLAYER_CORE_GetStepPhase(FieldPlayerCore *core);
u32 FIELD_PLAYER_CORE_GetFormCode(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetFormCode(FieldPlayerCore *core, u32 formCode);
u32 FIELD_PLAYER_CORE_GetSex(FieldPlayerCore *core);
struct GameSystem *FIELD_PLAYER_CORE_GetGameSystem(FieldPlayerCore *core);
struct PlayerWork *FIELD_PLAYER_CORE_GetPlayerWork(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_ApplyFormCodeModel(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_SetFormSlotModel(FieldPlayerCore *core, int formSlot);
int FIELD_PLAYER_CORE_WaitModelReady(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_GetFormSlot(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckFormModel(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckAnimePaused(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckAcmdPossible(FieldPlayerCore *core);
u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(FieldPlayerCore *core, u32 keys);
void FIELD_PLAYER_CORE_RememberKeyDirs(FieldPlayerCore *core, u32 keys);
void FIELD_PLAYER_CORE_SetRideEffect(FieldPlayerCore *core, struct FieldEffectObj *rideEffect);
struct FieldEffectObj *FIELD_PLAYER_CORE_GetRideEffect(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_ChangeModel(FieldPlayerCore *core, int objCode);
void FIELD_PLAYER_CORE_SetFormCodeModel(FieldPlayerCore *core, int formCode);
int FIELD_PLAYER_CORE_CheckPlainModel(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_CheckDrawProcReady(FieldPlayerCore *core);
u16 FIELD_PLAYER_CORE_SelectMoveDir(FieldPlayerCore *core, u32 keys);
void FIELD_PLAYER_CORE_StoreKeyDirs(FieldPlayerCore *core, int keys);
int FIELD_PLAYER_CORE_GetHorzDirFromKeys(u32 keys);
int FIELD_PLAYER_CORE_GetVertDirFromKeys(u32 keys);
u16 FIELD_PLAYER_CORE_RunFormSteps(FieldPlayerCore *core, int formSlot);
int FIELD_PLAYER_CORE_GetLowestFormSlot(u32 mask);
FieldPlayerCore *FIELD_PLAYER_CORE_StartFormChange(FieldPlayerCore *core, u32 mask);
int FIELD_PLAYER_CORE_StepFormChange(FieldPlayerCore *core);
void FIELD_PLAYER_CORE_FinishFormChange(FieldPlayerCore *core);
int FIELD_PLAYER_CORE_ChangeToObjCode(FieldPlayerCore *core, u32 objCode);
int FIELD_PLAYER_CORE_ChangeToFormSlot(FieldPlayerCore *core, u32 formSlot);
int FIELD_PLAYER_CORE_FinishFormSlotChange(FieldPlayerCore *core, int formSlot);
void FIELD_PLAYER_CORE_PostZoneBgmChange(FieldPlayerCore *core);

extern const char gFieldPlayerCoreFileName[];
extern FieldPlayerMmdlHeader gFieldPlayerAvatarHeaderTemplate;
extern FieldPlayerFormStepFunc *const gFieldPlayerFormStepTables[];

/*
 * Addresses are Black-image addresses.
 */
FieldPlayerCore *FIELD_PLAYER_CORE_Create(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId)
{
    FieldPlayerCore *core;
    struct MmdlSys *mmdlSys;
    int objCodeOverride;
    Mmdl *mmdl;

    core = GFL_HEAP_Alloc(heapId, 0x34, 1, gFieldPlayerCoreFileName, 0x97);
    core->playerWork = playerWork;
    core->fieldMap = fieldMap;
    core->gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    core->lastHorzDir = FIELD_PLAYER_DIR_NONE;
    core->lastVertDir = FIELD_PLAYER_DIR_NONE;
    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    core->mmdl = FLDMMDL_SysSearchObjId(mmdlSys, 0xff);
    core->sex = sex;
    objCodeOverride = GAME_DATA_GetPlayerPalaceZoneId(core->playerWork);
    mmdl = core->mmdl;
    if (mmdl == 0) {
        FieldPlayerMmdlHeader header = gFieldPlayerAvatarHeaderTemplate;
        FieldPlayerGridPos *gridPos = &header.pos;

        gridPos->x = (pos->x >> 4) / 4096;
        gridPos->z = (pos->z >> 4) / 4096;
        gridPos->y = pos->y;
        if (objCodeOverride == 0xFFFF)
            header.objCode = FIELD_PLAYER_GetObjCodeOfFormCode(sex, FIELD_PLAYER_CORE_GetFormCode(core));
        else
            header.objCode = objCodeOverride;
        core->mmdl = FLDMMDL_AddMmdl(mmdlSys, (struct MmdlHeader *)(&header), 0);
    } else {
        int gridY;
        int gridZ;
        gridY = (pos->y >> 4) / 4096;
        gridZ = (pos->z >> 4) / 4096;
        FLDMMDL_SetGridNowX(mmdl, (pos->x >> 4) / 4096);
        FLDMMDL_SetGridNowY(mmdl, (s16)gridY);
        FLDMMDL_SetGridNowZ(mmdl, (s16)gridZ);
        FLDMMDL_SetPos(mmdl, (struct VecFx32 *)pos);
        if (objCodeOverride == 0xFFFF)
            FIELD_PLAYER_CORE_ApplyFormCodeModel(core);
    }
    FLDMMDL_SetStatusBitZoneDeleteOff(core->mmdl, 1);
    return core;
}

void FIELD_PLAYER_CORE_Delete(FieldPlayerCore *core)
{
    GFL_HEAP_Free(core);
}

/* Moves the step phase on after a step: 1 and 2 are the two halves, 3 the end. */
void FIELD_PLAYER_CORE_UpdateStepPhase(FieldPlayerCore *core)
{
    Mmdl *mmdl = core->mmdl;
    u32 stepKind;
    u32 oldPhase = core->stepPhase;

    core->stepPhase = 0;
    stepKind = core->stepKind;
    if (FLDMMDL_CheckPossibleAcmd(mmdl) == 0) {
        switch (stepKind) {
        case 0:
            break;
        case 1:
            if (oldPhase == 0 || oldPhase == 3)
                core->stepPhase = 1;
            else
                core->stepPhase = 2;
            break;
        case 2:
            core->stepPhase = 2;
            break;
        }
    } else if (FLDMMDL_CheckEndAcmd(mmdl) == 1) {
        switch (stepKind) {
        case 0:
            break;
        case 1:
            if (oldPhase == 0)
                break;
            if (oldPhase == 3)
                core->stepPhase = 0;
            else
                core->stepPhase = 3;
            break;
        case 2:
            if (oldPhase == 0)
                break;
            if (oldPhase == 3)
                core->stepPhase = 0;
            else
                core->stepPhase = 3;
            break;
        }
    }
}

void FIELD_PLAYER_CORE_GetPos(FieldPlayerCore *core, VecFx32 *out)
{
    FLDMMDL_GetPos(core->mmdl, (struct VecFx32 *)out);
}

void FIELD_PLAYER_CORE_SetPos(FieldPlayerCore *core, VecFx32 *pos)
{
    int gridX = (pos->x >> 4) / 4096;
    int gridY = (pos->y >> 4) / 4096;
    int gridZ = (pos->z >> 4) / 4096;
    Mmdl *mmdl = core->mmdl;

    FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
    FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
    FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
    FLDMMDL_SetGridNowX(mmdl, (short)gridX);
    FLDMMDL_SetGridNowY(mmdl, (short)gridY);
    FLDMMDL_SetGridNowZ(mmdl, (short)gridZ);
    FLDMMDL_SetPos(mmdl, (struct VecFx32 *)pos);
}

u16 FIELD_PLAYER_CORE_GetDirDisp(FieldPlayerCore *core)
{
    return FLDMMDL_GetDirDisp(core->mmdl);
}

void FIELD_PLAYER_CORE_SetDirDisp(FieldPlayerCore *core, int dir)
{
    FLDMMDL_SetDirDispCheckPause(core->mmdl, dir);
}

/* Changes the avatar model and remembers it in the player work. */
void FIELD_PLAYER_CORE_SetObjCode(FieldPlayerCore *core, u32 objCode)
{
    FIELD_PLAYER_CORE_ChangeModel(core, objCode);
    GAME_DATA_SetPlayerPalaceZoneId(core->playerWork, objCode);
}

/* Forgets the remembered model (0xFFFF). */
void FIELD_PLAYER_CORE_ClearRememberedObjCode(FieldPlayerCore *core)
{
    GAME_DATA_SetPlayerPalaceZoneId(core->playerWork, 0xFFFF);
}

FieldMap *FIELD_PLAYER_CORE_GetFieldMap(FieldPlayerCore *core)
{
    return core->fieldMap;
}

Mmdl *FIELD_PLAYER_CORE_GetMmdl(FieldPlayerCore *core)
{
    return core->mmdl;
}

void FIELD_PLAYER_CORE_SetStepKind(FieldPlayerCore *core, u32 stepKind)
{
    core->stepKind = stepKind;
}

u32 FIELD_PLAYER_CORE_GetStepKind(FieldPlayerCore *core)
{
    return core->stepKind;
}

void FIELD_PLAYER_CORE_SetStepPhase(FieldPlayerCore *core, u32 stepPhase)
{
    core->stepPhase = stepPhase;
}

u32 FIELD_PLAYER_CORE_GetStepPhase(FieldPlayerCore *core)
{
    return core->stepPhase;
}

u32 FIELD_PLAYER_CORE_GetFormCode(FieldPlayerCore *core)
{
    return GAME_DATA_GetPlayerObjectCode(core->playerWork);
}

void FIELD_PLAYER_CORE_SetFormCode(FieldPlayerCore *core, u32 formCode)
{
    GAME_DATA_SetPlayerObjectCode(core->playerWork, formCode);
}

u32 FIELD_PLAYER_CORE_GetSex(FieldPlayerCore *core)
{
    return core->sex;
}

struct GameSystem *FIELD_PLAYER_CORE_GetGameSystem(FieldPlayerCore *core)
{
    return core->gameSystem;
}

struct PlayerWork *FIELD_PLAYER_CORE_GetPlayerWork(FieldPlayerCore *core)
{
    return core->playerWork;
}

/* Puts the avatar model of the stored form code on. */
void FIELD_PLAYER_CORE_ApplyFormCodeModel(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_SetFormCodeModel(core, FIELD_PLAYER_CORE_GetFormCode(core));
}

/* Puts the model of a form slot on without changing the stored form code. */
void FIELD_PLAYER_CORE_SetFormSlotModel(FieldPlayerCore *core, int formSlot)
{
    u32 sex = FIELD_PLAYER_CORE_GetSex(core);
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    int objCode = FIELD_PLAYER_GetFormObjCode(sex, formSlot);

    if (objCode != FLDMMDL_GetObjCode(mmdl))
        FIELD_PLAYER_CORE_ChangeModel(core, objCode);
    core->animeWait = 0;
}

/* Waits one call after the model draw proc is ready; 1 when the wait is over. */
int FIELD_PLAYER_CORE_WaitModelReady(FieldPlayerCore *core)
{
    if (FLDMMDL_CallDrawGetProc(FIELD_PLAYER_CORE_GetMmdl(core), 0) != 0xFFFF) {
        if (core->animeWait == 1)
            return 1;
        (core->animeWait)++;
    }
    return 0;
}

/* Form slot of the model the avatar has now. */
int FIELD_PLAYER_CORE_GetFormSlot(FieldPlayerCore *core)
{
    return FIELD_PLAYER_GetFormSlotOfObjCode(FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl(core)));
}

/* 1 when the avatar model belongs to a form slot. */
int FIELD_PLAYER_CORE_CheckFormModel(FieldPlayerCore *core)
{
    if (FIELD_PLAYER_GetFormSlotOfObjCode(FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl(core))) != FIELD_PLAYER_AVATAR_FORM_COUNT) {
        return 1;
    }
    return 0;
}

/* 1 when the avatar animation is paused on its last frame. */
int FIELD_PLAYER_CORE_CheckAnimePaused(FieldPlayerCore *core)
{
    u16 lastCommand;
    u32 bbActSys;
    u32 drawAnimeId;

    bbActSys = (u32)FLDMMDL_BLACT_GetBbActSys(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(core->mmdl)));
    if (FLDMMDL_ACMD_CheckAnimePaused(core->mmdl) == 1 && FLDMMDL_BLACT_GetEntryHookFlag(core->mmdl) == 1)
        return 1;
    drawAnimeId = FLDMMDL_CallDrawGetProc(core->mmdl, 0);
    if (drawAnimeId != 0xFFFF && (struct BbActSys *)BILLBOARD_ACT_GetEntryLastCommand((struct BbActSys *)bbActSys, (u16)drawAnimeId, &lastCommand) != 0 && lastCommand == (0xFFFF >> 2))
        return 1;
    return 0;
}

int FIELD_PLAYER_CORE_CheckAcmdPossible(FieldPlayerCore *core)
{
    if (FLDMMDL_CheckPossibleAcmd(FIELD_PLAYER_CORE_GetMmdl(core)) == 1) {
        return 1;
    }
    return 0;
}

/* Widens the keys to 16 bits before the call. */
u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(FieldPlayerCore *core, u32 keys)
{
    return FIELD_PLAYER_CORE_SelectMoveDir(core, (u16)keys);
}

void FIELD_PLAYER_CORE_RememberKeyDirs(FieldPlayerCore *core, u32 keys)
{
    FIELD_PLAYER_CORE_StoreKeyDirs(core, (u16)keys);
}

void FIELD_PLAYER_CORE_SetRideEffect(FieldPlayerCore *core, struct FieldEffectObj *rideEffect)
{
    core->rideEffect = rideEffect;
}

struct FieldEffectObj *FIELD_PLAYER_CORE_GetRideEffect(FieldPlayerCore *core)
{
    return core->rideEffect;
}

/*
 * Changes the avatar model. A change from or to the plain hero or heroine
 * model is direct; any other change goes through the plain model first.
 */
void FIELD_PLAYER_CORE_ChangeModel(FieldPlayerCore *core, int objCode)
{
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    struct MmdlSys *mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    int nowObjCode = FLDMMDL_GetObjCode(mmdl);

    if (objCode == FIELD_PLAYER_OBJ_CODE_HERO || objCode == FIELD_PLAYER_OBJ_CODE_HEROINE
        || nowObjCode == FIELD_PLAYER_OBJ_CODE_HERO || nowObjCode == FIELD_PLAYER_OBJ_CODE_HEROINE) {
        FLDMMDL_BLACT_ChangeObjCode(mmdl, objCode);
        FLDMMDL_SysWaitBlActResLoad(mmdlSys);
        return;
    }
    FLDMMDL_ChangeObjCode(mmdl, FIELD_PLAYER_GetObjCodeOfFormCode(FIELD_PLAYER_CORE_GetSex(core), FIELD_PLAYER_AVATAR_FORM_NORMAL));
    FLDMMDL_SysWaitBlActResLoad(mmdlSys);
    FLDMMDL_BLACT_ChangeObjCode(mmdl, objCode);
    FLDMMDL_SysWaitBlActResLoad(mmdlSys);
}

/* Puts on the model of a form code and stores the code in the player work. */
void FIELD_PLAYER_CORE_SetFormCodeModel(FieldPlayerCore *core, int formCode)
{
    u32 sex = FIELD_PLAYER_CORE_GetSex(core);
    Mmdl *mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    int objCode = FIELD_PLAYER_GetObjCodeOfFormCode(sex, formCode);

    if (objCode != FLDMMDL_GetObjCode(mmdl))
        FIELD_PLAYER_CORE_ChangeModel(core, objCode);
    FIELD_PLAYER_CORE_SetFormCode(core, formCode);
}

/* 1 while the avatar wears the plain hero or heroine model. */
int FIELD_PLAYER_CORE_CheckPlainModel(FieldPlayerCore *core)
{
    int objCode = FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl(core));

    if (objCode == FIELD_PLAYER_OBJ_CODE_HERO || objCode == FIELD_PLAYER_OBJ_CODE_HEROINE)
        return 1;
    return 0;
}

/* 1 when the model draw proc is ready. */
int FIELD_PLAYER_CORE_CheckDrawProcReady(FieldPlayerCore *core)
{
    int ready = 0;

    if ((u16)FLDMMDL_CallDrawGetProc(core->mmdl, 0) != 0xFFFF)
        ready = 1;
    return ready;
}

/*
 * Picks the move direction from the pad keys when two directions are held:
 * the one that changed since the last call wins, and a held direction that
 * is the model's current direction is kept.
 */
u16 FIELD_PLAYER_CORE_SelectMoveDir(FieldPlayerCore *core, u32 keys)
{
    u32 horzDir;
    u32 vertDir;
    u32 nowDir;
    u32 lastHorzDir;
    u32 lastVertDir;

    horzDir = FIELD_PLAYER_CORE_GetHorzDirFromKeys(keys);
    vertDir = FIELD_PLAYER_CORE_GetVertDirFromKeys(keys);
    if (horzDir == FIELD_PLAYER_DIR_NONE) {
        return vertDir;
    }
    if (vertDir == FIELD_PLAYER_DIR_NONE) {
        return horzDir;
    }
    nowDir = FLDMMDL_GetDirMove(FIELD_PLAYER_CORE_GetMmdl(core));
    lastHorzDir = core->lastHorzDir;
    lastVertDir = core->lastVertDir;
    if (nowDir != FIELD_PLAYER_DIR_NONE) {
        if (horzDir == lastHorzDir && vertDir == lastVertDir) {
            if (vertDir == nowDir) {
                return vertDir;
            }
            if (horzDir == nowDir) {
                return horzDir;
            }
        }
        if (vertDir != lastVertDir) {
            return vertDir;
        }
        return horzDir;
    }
    return vertDir;
}

/* Stores the held directions for the next call of the direction choice. */
void FIELD_PLAYER_CORE_StoreKeyDirs(FieldPlayerCore *core, int keys)
{
    core->lastHorzDir = FIELD_PLAYER_CORE_GetHorzDirFromKeys(keys);
    core->lastVertDir = FIELD_PLAYER_CORE_GetVertDirFromKeys(keys);
}

/* Left or right direction of the held keys, FIELD_PLAYER_DIR_NONE for none. */
int FIELD_PLAYER_CORE_GetHorzDirFromKeys(u32 keys)
{
    if (keys & FIELD_PLAYER_KEY_LEFT) {
        return FIELD_PLAYER_DIR_LEFT;
    }
    if (keys & FIELD_PLAYER_KEY_RIGHT) {
        return FIELD_PLAYER_DIR_RIGHT;
    }
    return FIELD_PLAYER_DIR_NONE;
}

/* Up or down direction of the held keys, FIELD_PLAYER_DIR_NONE for none. */
int FIELD_PLAYER_CORE_GetVertDirFromKeys(u32 keys)
{
    if (keys & FIELD_PLAYER_KEY_UP) {
        return FIELD_PLAYER_DIR_UP;
    }
    if (keys & FIELD_PLAYER_KEY_DOWN) {
        return FIELD_PLAYER_DIR_DOWN;
    }
    return FIELD_PLAYER_DIR_NONE;
}

/* Runs the steps of the sequence for a form slot until one stops or the change is done. */
u16 FIELD_PLAYER_CORE_RunFormSteps(FieldPlayerCore *core, int formSlot)
{
    FieldPlayerFormStepFunc *steps;

    if (core->formChangeDone == 0) {
        steps = gFieldPlayerFormStepTables[formSlot];
        while (steps[core->formChangeStep](core) == 1)
            ;
    }
    return core->formChangeDone;
}

/* Index of the lowest set bit among the first FIELD_PLAYER_AVATAR_FORM_COUNT, else that count. */
int FIELD_PLAYER_CORE_GetLowestFormSlot(u32 mask)
{
    int slot = FIELD_PLAYER_AVATAR_FORM_COUNT;

    if (mask != 0) {
        for (slot = 0; slot < FIELD_PLAYER_AVATAR_FORM_COUNT; slot++) {
            if (mask & 1)
                break;
            mask >>= 1;
        }
    }
    return slot;
}

/* Starts a form change to the slots in mask. */
FieldPlayerCore *FIELD_PLAYER_CORE_StartFormChange(FieldPlayerCore *core, u32 mask)
{
    core->formChangeMask = mask;
    core->formChangeStep = 0;
    core->formChangeDone = 0;
    core->animeWait = 0;
    core->formChangeCount = 0;
    return core;
}

/* Runs the form change one slot at a time; 1 when no slot is left or the slot is done. */
int FIELD_PLAYER_CORE_StepFormChange(FieldPlayerCore *core)
{
    int formSlot = FIELD_PLAYER_CORE_GetLowestFormSlot(core->formChangeMask);

    if (formSlot >= FIELD_PLAYER_AVATAR_FORM_COUNT)
        return 1;
    if (FIELD_PLAYER_CORE_RunFormSteps(core, formSlot) == 1)
        return 1;
    return 0;
}

/* Runs the form change of the lowest requested slot to its end. */
void FIELD_PLAYER_CORE_FinishFormChange(FieldPlayerCore *core)
{
    int formSlot = FIELD_PLAYER_CORE_GetLowestFormSlot(core->formChangeMask);

    if (formSlot < FIELD_PLAYER_AVATAR_FORM_COUNT) {
        while (FIELD_PLAYER_CORE_RunFormSteps(core, formSlot) == 0)
            ;
    }
}

/* Changes to an object code; 1 when the change is done, 0 while it goes through the plain model. */
int FIELD_PLAYER_CORE_ChangeToObjCode(FieldPlayerCore *core, u32 objCode)
{
    if (objCode == FLDMMDL_GetObjCode(FIELD_PLAYER_CORE_GetMmdl(core))) {
        core->formChangeDone = 1;
        return 1;
    }
    if (FIELD_PLAYER_CORE_CheckPlainModel(core) == 1) {
        FIELD_PLAYER_CORE_ChangeModel(core, objCode);
        core->formChangeDone = 1;
        return 1;
    }
    FIELD_PLAYER_CORE_ChangeModel(core, FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_CORE_GetSex(core), 0));
    return 0;
}

int FIELD_PLAYER_CORE_ChangeToFormSlot(FieldPlayerCore *core, u32 formSlot)
{
    return FIELD_PLAYER_CORE_ChangeToObjCode(core, FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_CORE_GetSex(core), formSlot));
}

/* Ends the change to a form slot once the model draw proc is ready. */
int FIELD_PLAYER_CORE_FinishFormSlotChange(FieldPlayerCore *core, int formSlot)
{
    if (FIELD_PLAYER_CORE_CheckDrawProcReady(core) == 1) {
        core->formChangeCount++;
        FIELD_PLAYER_CORE_ChangeModel(core, FIELD_PLAYER_GetFormObjCode(FIELD_PLAYER_CORE_GetSex(core), formSlot));
        core->formChangeDone = 1;
        return 1;
    }
    return 0;
}

/* Step of the sequence to the normal form: model, form code, no ride effect. */
int FIELD_PLAYER_CORE_FormStepNormal(FieldPlayerCore *core)
{
    VecFx32 zeroOffset = { 0, 0, 0 };
    u32 sex;
    Mmdl *mmdl;
    struct FieldEffectObj *rideEffect;

    sex = FIELD_PLAYER_CORE_GetSex(core);
    mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    sex = FIELD_PLAYER_GetFormObjCode(sex, 0);
    if (sex != FLDMMDL_GetObjCode(mmdl)) {
        FIELD_PLAYER_CORE_ChangeModel(core, sex);
    }
    FIELD_PLAYER_CORE_SetFormCode(core, 0);
    FIELD_PLAYER_CORE_PostZoneBgmChange(core);
    if ((rideEffect = FIELD_PLAYER_CORE_GetRideEffect(core)) != 0) {
        FIELD_EFFECT_DeleteObject(rideEffect);
        FIELD_PLAYER_CORE_SetRideEffect(core, 0);
    }
    FLDMMDL_SetDrawOffsetOutside(mmdl, (struct VecFx32 *)(&zeroOffset));
    core->formChangeDone = 1;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepCycle(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_GetSex(core);
    FIELD_PLAYER_CORE_GetMmdl(core);
    FIELD_PLAYER_CORE_SetFormCode(core, 1);
    FIELD_PLAYER_CORE_PostZoneBgmChange(core);
    if (FIELD_PLAYER_CORE_ChangeToFormSlot(core, 1) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepCycleDone(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_FinishFormSlotChange(core, 1);

    return 0;
}

/* Step of the sequence to the surf form: model, form code, surf effect. */
int FIELD_PLAYER_CORE_FormStepSurf(FieldPlayerCore *core)
{
    VecFx32 pos;
    u32 sex;
    Mmdl *mmdl;
    struct FieldEffectSys *fieldEffect;
    u32 dir;

    sex = FIELD_PLAYER_CORE_GetSex(core);
    mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    sex = FIELD_PLAYER_GetFormObjCode(sex, 2);
    if (sex != FLDMMDL_GetObjCode(mmdl)) {
        FIELD_PLAYER_CORE_ChangeModel(core, sex);
    }
    if (FIELD_PLAYER_CORE_GetFormCode(core) != FIELD_PLAYER_FORM_CODE_SURF) {
        FIELD_PLAYER_CORE_SetFormCode(core, FIELD_PLAYER_FORM_CODE_SURF);
    }
    FIELD_PLAYER_CORE_PostZoneBgmChange(core);
    if (FIELD_PLAYER_CORE_GetRideEffect(core) == 0) {
        fieldEffect = FIELDMAP_GetEffect(core->fieldMap);
        dir = FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&pos));
        FIELD_PLAYER_CORE_SetRideEffect(core, FLDEFF_NAMIPOKE_Start(fieldEffect, dir, &pos, mmdl, 1));
    }
    core->formChangeDone = 1;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepRestoreModel(FieldPlayerCore *core)
{
    int formCode = FIELD_PLAYER_CORE_GetFormCode(core);

    if (FIELD_PLAYER_CORE_ChangeToObjCode(core, FIELD_PLAYER_GetObjCodeOfFormCode(FIELD_PLAYER_CORE_GetSex(core), formCode)) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepRestoreModelDone(FieldPlayerCore *core)
{
    int formCode;

    if (FIELD_PLAYER_CORE_CheckDrawProcReady(core) == 1) {
        core->formChangeCount++;
        formCode = FIELD_PLAYER_CORE_GetFormCode(core);
        FIELD_PLAYER_CORE_ChangeModel(core, FIELD_PLAYER_GetObjCodeOfFormCode(FIELD_PLAYER_CORE_GetSex(core), formCode));
        core->formChangeDone = 1;
    }
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot4(FieldPlayerCore *core)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot(core, 4) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot4Done(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_FinishFormSlotChange(core, 4);

    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot5(FieldPlayerCore *core)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot(core, 5) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot5Done(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_FinishFormSlotChange(core, 5);

    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot6(FieldPlayerCore *core)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot(core, 6) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot6Done(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_FinishFormSlotChange(core, 6);

    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot9(FieldPlayerCore *core)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot(core, 9) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot9Done(FieldPlayerCore *core)
{
    FIELD_PLAYER_CORE_FinishFormSlotChange(core, 9);

    return 0;
}

/* Step of the sequence to the dive form: model, form code, dive effect, bubbles. */
int FIELD_PLAYER_CORE_FormStepDive(FieldPlayerCore *core)
{
    VecFx32 pos;
    u32 sex;
    Mmdl *mmdl;
    struct FieldEffectSys *fieldEffect;
    u32 dir;
    struct FieldEffectSys *bubbleEffect;

    bubbleEffect = FIELDMAP_GetEffect(core->fieldMap);
    sex = FIELD_PLAYER_CORE_GetSex(core);
    mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
    sex = FIELD_PLAYER_GetFormObjCode(sex, 3);
    if (sex != FLDMMDL_GetObjCode(mmdl)) {
        FIELD_PLAYER_CORE_ChangeModel(core, sex);
    }
    if (FIELD_PLAYER_CORE_GetFormCode(core) != FIELD_PLAYER_FORM_CODE_DIVE) {
        FIELD_PLAYER_CORE_SetFormCode(core, FIELD_PLAYER_FORM_CODE_DIVE);
    }
    if (FIELD_PLAYER_CORE_GetRideEffect(core) == 0) {
        fieldEffect = FIELDMAP_GetEffect(core->fieldMap);
        dir = FLDMMDL_GetDirDisp(mmdl);
        FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&pos));
        FIELD_PLAYER_CORE_SetRideEffect(core, FLDEFF_NAMIPOKE_Start(fieldEffect, dir, &pos, mmdl, 1));
    }
    FLDEFF_BUBBLE_Start(core->mmdl, (struct FieldEffectSys *)bubbleEffect);
    if (core->rideEffect != 0) {
        FLDEFF_NAMIPOKE_SetWakeEnabled(core->rideEffect, 0);
    }
    core->formChangeDone = 1;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot8(FieldPlayerCore *core)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot(core, 8) != 1)
        core->formChangeStep++;
    return 0;
}

int FIELD_PLAYER_CORE_FormStepSlot8Done(FieldPlayerCore *core)
{
    s16 grid[2];
    int blocked;
    Mmdl *mmdl;
    struct MmdlSys *mmdlSys;

    FIELD_PLAYER_CORE_FinishFormSlotChange(core, 8);
    if (core->formChangeDone == 1 && FIELD_PLAYER_CORE_GetFormCode(core) == FIELD_PLAYER_FORM_CODE_SURF) {
        blocked = 0;
        mmdl = FIELD_PLAYER_CORE_GetMmdl(core);
        mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
        grid[1] = FLDMMDL_GetGridNowX(mmdl);
        grid[0] = FLDMMDL_GetGridNowZ(mmdl);
        FLDMMDL_MOVE_AddDirGrid(1, &grid[1], &grid[0], 1);
        if (FLDMMDL_SysSearchGridPos(mmdlSys, grid[1], grid[0], 1) != 0) {
            blocked = 1;
        }
        FLDMMDL_DRAW_SetState(mmdl, blocked);
    }
    return 0;
}

/* Posts the BGM change for the zone the field map shows. */
void FIELD_PLAYER_CORE_PostZoneBgmChange(FieldPlayerCore *core)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(core->fieldMap));
    u32 bgmId = GAME_DATA_GetBgmInfo(gameData);

    FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade((struct FieldSoundSystem *)bgmId, gameData, (u16)(int)FIELDMAP_GetZoneId(core->fieldMap));
}
