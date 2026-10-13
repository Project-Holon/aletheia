/*
 * function: GIMMICK45_SwitchToggleEventProc
 * address:  0x021F3A68
 * packet:   pkt_ov045_021F3A68
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: GIMMICK45_IsSwitchOn's result held in a u8 local curState (truncated in
 * place, lsls r0 / lsrs r3, where passing the call inline copies it to r3
 * first); newState = 1 written after work's assignment (before it, it takes
 * r0 and lands after the copy of expObj). The extent past 0x021F3B36 is rodata.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   GIMMICK45_IsSwitchOn  0x021F39A8  thumb  ov045
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   GIMMICK45_SetSwitchModelPose  0x021F3938  thumb  ov045
 */
#include "../unit_021F36C0_types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct FieldSave;
struct FldExpObj;
struct FldExpAnime;
struct GameEvent;

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct FldExpObj *FIELDMAP_GetExpObj(struct FieldMap *fieldMap);
extern Gimmick45Work *FIELDMAP_GetCommonWork(struct FieldMap *fieldMap, int workId);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct FieldSave *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern Gimmick45Save *GIMMICK_WORK_GetSaveArea(struct FieldSave *fieldSave, u32 blockId);
extern int GIMMICK45_IsSwitchOn(Gimmick45Save *save, int switchIndex);
extern struct FldExpAnime *FLD_EXP_OBJ_GetAnime(struct FldExpObj *expObj, int unitIndex, unsigned int modelIndex, int animIndex);
extern void FLD_EXP_OBJ_SetAnimePaused(struct FldExpAnime *anime, int paused);
extern int FLD_EXP_OBJ_IsAnimeStopped(struct FldExpAnime *anime);
extern void func_020061E4(u32 se);
extern void GFL_USE_StopAllSe(void);
extern void GIMMICK45_SetSwitchModelPose(struct FldExpObj *expObj, int switchOn, int switchIndex, int usePrimaryModel);

int GIMMICK45_SwitchToggleEventProc(struct GameEvent *event, int *state)
{
    int newState;
    struct FieldMap *fieldMap;
    struct FldExpObj *expObj;
    Gimmick45Work *work;
    Gimmick45Save *save;
    int switchIdx;
    u8 curState;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    newState = 1;
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK45_SAVE_BLOCK_ID);
    switch (*state) {
    case 0:
        switchIdx = work->switchIndex;
        curState = GIMMICK45_IsSwitchOn(save, switchIdx);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)switchIdx, (u8)curState), 0);
        func_020061E4(GIMMICK45_SE_SWITCH_PRESS);
        (*state)++;
        break;
    case 1:
        switchIdx = work->switchIndex;
        curState = GIMMICK45_IsSwitchOn(save, switchIdx);
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)switchIdx, (u8)curState))) {
            GFL_USE_StopAllSe();
            func_020061E4(GIMMICK45_SE_SWITCH_DONE);
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
