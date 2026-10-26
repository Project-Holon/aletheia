#ifndef GAME_OV021_SCRCMD_OTID_H
#define GAME_OV021_SCRCMD_OTID_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_otid.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct GameEvent;
struct OtCountTask;
struct GameData;
struct OtIdList;
typedef struct OtCountTask OtCountTask;
typedef struct OtIdList OtIdList;

#include "../types.h"

int SCRCMD_StartCountOtherOtIdsTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_CountOtherOtIdsTaskMain(struct GameEvent *event, int *seq, void *work);
int SCRCMD_CountPartyOtherOtIds(u32 playerId, struct GameData *gameData, OtIdList *list);
int SCRCMD_CountBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list);
int SCRCMD_CountBattleBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list);
int SCRCMD_AddOtherOtId(int playerId, int otId, OtIdList *list);
int SCRCMD_AddUniqueOtId(int otId, OtIdList *list);
int SCRCMD_StartSubProcOv057(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetPlayerLocationValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
/* END mkheaders: generated region */

#endif
