/*
 * file:     field_gimmick_switch_toggle.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK45_Exit, GIMMICK45_Update, GIMMICK45_StartSecondarySwitchEvent, GIMMICK45_StartSwitchToggleEvent, GIMMICK45_ReplacePlayerIfRequirementMet, GIMMICK45_IsRequirementMet, GIMMICK45_SetSwitchModelPose, GIMMICK45_IsSwitchOn, GIMMICK45_SecondarySwitchEventProc, GIMMICK45_SwitchToggleEventProc
 * address:  0x021F36C0
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B50     0x021F3B50  data  ov045
 *   d_021F3B80     0x021F3B80  data  ov045  a4
 *   d_021F3BA4     0x021F3BA4  data  ov045  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GIMMICK45_SwitchToggleEventProc 0x021F3A68 thumb ov045
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCtrlType  0x02188CF0  thumb  ov021
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   FIELDMAP_CTRL_HYBRID_ReplacePlayer  0x021A6DC4  thumb  ov021
 *   d_021F3B60  0x021F3B60  data  ov045
 *   d_021F3B62  0x021F3B62  data
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   GIMMICK45_IsSwitchOn  0x021F39A8  thumb  ov045
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   GIMMICK45_SetSwitchModelPose  0x021F3938  thumb  ov045
 */
#include "field_gimmick_switch_toggle_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldSave;
struct FldExpObj;
struct FldExpAnime;
struct FldExpUnitDesc;
struct GameEvent;

typedef int (*GameEventFunc)(struct GameEvent *event, int *state);

extern struct FldExpObj *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct FieldSave *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern Gimmick45Save *GIMMICK_WORK_GetSaveArea(struct FieldSave *fieldSave, u32 blockId);
extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(struct FieldMap *fieldMap, int workId, int heapId, int size);
extern void FLD_EXP_OBJ_AddUnitFromArchive(struct FldExpObj *expObj, struct FldExpUnitDesc *desc, int unitIndex);
extern Vec3Fx *FLD_EXP_OBJ_GetModelStatus(struct FldExpObj *expObj, int unitIndex, u16 modelIndex);
extern void FLD_EXP_OBJ_SetModelCullDraw(struct FldExpObj *expObj, int unitIndex, int modelIndex, int cullDraw);
extern struct FldExpAnime *FLD_EXP_OBJ_GetAnime(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex);
extern void FLD_EXP_OBJ_SetAnimeLoop(struct FldExpAnime *anime, int loop);
extern void FLD_EXP_OBJ_SetAnimePaused(struct FldExpAnime *anime, int paused);
extern Gimmick45Work *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int workId);
extern void FIELDMAP_FreeCommonWork(struct FieldMap *fieldMap, int workId);
extern void FLD_EXP_OBJ_RemoveUnit(struct FldExpObj *expObj, u16 unitIndex);
extern void FLD_EXP_OBJ_UpdateAnimes(struct FldExpObj *expObj);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc proc, u32 size);
extern int GIMMICK45_SwitchToggleEventProc(struct GameEvent *event, int *state);
extern int FIELDMAP_GetCtrlType(struct FieldMap *fieldMap);
extern void *FIELDMAP_GetCtrlWork(struct FieldMap *fieldMap);
extern void FIELDMAP_CTRL_HYBRID_ReplacePlayer(void *ctrlWork, struct FieldMap *fieldMap);
extern void FLD_EXP_OBJ_SetAnimeEnabled(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int enabled);
extern void FLD_EXP_OBJ_SetAnimeFrame(struct FldExpObj *expObj, int unitIndex, u16 modelIndex, u16 animIndex, int frame);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern int FLD_EXP_OBJ_IsAnimeStopped(struct FldExpAnime *anime);

void func_021F36C0(struct FieldMap *fieldMap);
void GIMMICK45_Exit(struct FieldMap *fieldMap);
void GIMMICK45_Update(struct FieldMap *fieldMap);
struct GameEvent *GIMMICK45_StartSecondarySwitchEvent(struct GameSystem *gameSystem, int switchIndex);
struct GameEvent *GIMMICK45_StartSwitchToggleEvent(struct GameSystem *gameSystem, int switchIndex);
void GIMMICK45_ReplacePlayerIfRequirementMet(struct GameSystem *gameSystem, int requirementIndex);
int GIMMICK45_IsRequirementMet(Gimmick45Save *save, int requirementIndex);
void GIMMICK45_SetSwitchModelPose(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel);
int GIMMICK45_IsSwitchOn(Gimmick45Save *save, int switchIndex);
int GIMMICK45_SecondarySwitchEventProc(struct GameEvent *event, int *state);

extern struct FldExpUnitDesc d_021F3B50;
extern Vec3Fx d_021F3B80[];
extern Vec3Fx d_021F3BA4[];
/* Requirement table: entry n is (switch index, required state). The ROM
 * data layout splits the two columns into two objects, so the code reaches
 * them through two symbols. */
extern u16 d_021F3B60[];
extern u16 d_021F3B62[];
extern int GIMMICK45_IsSwitchOn(Gimmick45Save *save, int switchIndex);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void GIMMICK45_SetSwitchModelPose(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel);

void func_021F36C0(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;
    Gimmick45Save *save;
    struct FldExpAnime *anime;
    Vec3Fx *modelPos;
    int switchIdx;
    int secondaryIdx;
    int animIdx;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), sizeof(Gimmick45Work));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &d_021F3B50, 0);
    for (switchIdx = 0; switchIdx < GIMMICK45_SWITCH_COUNT; switchIdx++) {
        modelPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, switchIdx);
        *modelPos = d_021F3B80[switchIdx];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)switchIdx, 1);
        for (animIdx = 0; animIdx < 2; animIdx++) {
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, switchIdx, animIdx);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        }
        secondaryIdx = switchIdx + GIMMICK45_SECONDARY_MODEL_OFFSET;
        modelPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, secondaryIdx);
        *modelPos = d_021F3BA4[switchIdx];
        FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, (u16)secondaryIdx, 1);
        for (animIdx = 0; animIdx < 2; animIdx++) {
            anime = FLD_EXP_OBJ_GetAnime(expObj, 0, secondaryIdx, animIdx);
            FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
            FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        }
        GIMMICK45_SetSwitchModelPose(expObj, save->switchOn[switchIdx], switchIdx, 1);
        GIMMICK45_SetSwitchModelPose(expObj, save->switchOn[switchIdx], switchIdx, 0);
    }
}

void GIMMICK45_Exit(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj = FIELDMAP_GetExpObj(fieldMap);

    FIELDMAP_GetCommonWork(fieldMap, 1);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

void GIMMICK45_Update(struct FieldMap *fieldMap)
{
    struct FldExpObj *expObj;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
}

struct GameEvent *GIMMICK45_StartSecondarySwitchEvent(struct GameSystem *gameSystem, int switchIndex)
{
    struct FieldMap *fieldMap;
    Gimmick45Work *work;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    if (switchIndex >= GIMMICK45_SWITCH_COUNT)
        return 0;
    work->switchIndex = switchIndex;
    return func_020122C0(gameSystem, 0, GIMMICK45_SecondarySwitchEventProc, 0);
}

struct GameEvent *GIMMICK45_StartSwitchToggleEvent(struct GameSystem *gameSystem, int switchIndex)
{
    struct FieldMap *fieldMap;
    Gimmick45Work *work;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    if (switchIndex >= GIMMICK45_SWITCH_COUNT)
        return 0;
    work->switchIndex = switchIndex;
    return func_020122C0(gameSystem, 0, GIMMICK45_SwitchToggleEventProc, 0);
}


void GIMMICK45_ReplacePlayerIfRequirementMet(struct GameSystem *gameSystem, int requirementIndex)
{
    struct FieldMap *fieldMap;
    int ctrlType;
    Gimmick45Save *save;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    ctrlType = FIELDMAP_GetCtrlType(fieldMap);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    if (requirementIndex < GIMMICK45_REQUIREMENT_COUNT && ctrlType == GIMMICK45_CTRL_TYPE_HYBRID) {
        if (GIMMICK45_IsRequirementMet(save, requirementIndex)) {
            FIELDMAP_CTRL_HYBRID_ReplacePlayer(FIELDMAP_GetCtrlWork(fieldMap), fieldMap);
        }
    }
}


int GIMMICK45_IsRequirementMet(Gimmick45Save *save, int requirementIndex)
{
    u16 switchIsOn = (u16)(save->switchOn[d_021F3B60[requirementIndex * 2]] != 0);

    return switchIsOn == d_021F3B62[requirementIndex * 2];
}


void GIMMICK45_SetSwitchModelPose(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel)
{
    int onAnim, offAnim;

    if (switchOn) {
        onAnim = 1;
        offAnim = 0;
    } else {
        onAnim = 0;
        offAnim = 1;
    }
    if (usePrimaryModel != 1) {
        switchIndex += GIMMICK45_SECONDARY_MODEL_OFFSET;
    }
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, switchIndex, onAnim, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, switchIndex, offAnim, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, (u16)switchIndex, (u16)onAnim, 0);
    FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, switchIndex, onAnim), 1);
}

int GIMMICK45_IsSwitchOn(Gimmick45Save *save, int switchIndex)
{
    return save->switchOn[switchIndex] != 0;
}


int GIMMICK45_SecondarySwitchEventProc(struct GameEvent *event, int *state)
{
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick45Work *work;
    Gimmick45Save *save;
    int newState;
    int switchIdx;
    u8 curState;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    newState = 1;
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        switchIdx = work->switchIndex;
        curState = GIMMICK45_IsSwitchOn(save, switchIdx);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)(switchIdx + GIMMICK45_SECONDARY_MODEL_OFFSET), curState), 0);
        *state = *state + 1;
        break;
    case 1:
        switchIdx = work->switchIndex;
        curState = GIMMICK45_IsSwitchOn(save, switchIdx);
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)(switchIdx + GIMMICK45_SECONDARY_MODEL_OFFSET), curState))) {
            if (save->switchOn[work->switchIndex]) {
                newState = 0;
            }
            GIMMICK45_SetSwitchModelPose(expObj, newState, work->switchIndex, 0);
            return 1;
        }
        break;
    }
    return 0;
}

int GIMMICK45_SwitchToggleEventProc(struct GameEvent *event, int *state)
{
    int newState;
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick45Work *work;
    Gimmick45Save *save;
    int switchIdx;
    u8 curState;

    fieldMap = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    newState = 1;
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        switchIdx = work->switchIndex;
        curState = GIMMICK45_IsSwitchOn(save, switchIdx);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)switchIdx, (u8)curState), 0);
        GFL_USE_PlaySeDefaultVolume(GIMMICK45_SE_SWITCH_PRESS);
        (*state)++;
        break;
    case 1:
        switchIdx = work->switchIndex;
        curState = GIMMICK45_IsSwitchOn(save, switchIdx);
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)switchIdx, (u8)curState))) {
            GFL_USE_StopAllSe();
            GFL_USE_PlaySeDefaultVolume(GIMMICK45_SE_SWITCH_DONE);
            if (save->switchOn[work->switchIndex] != 0)
                newState = 0;
            GIMMICK45_SetSwitchModelPose(expObj, newState, work->switchIndex, 1);
            save->switchOn[work->switchIndex] = save->switchOn[work->switchIndex] ? 0 : 1;
            return 1;
        }
        break;
    }
    return 0;
}
