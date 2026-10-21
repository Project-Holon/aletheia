#ifndef GAME_OV021_BSUBWAY_SCR_H
#define GAME_OV021_BSUBWAY_SCR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bsubway_scr.c, prototypes copied from their definitions. */

struct GameSystem;
struct SaveControl;
struct PokemonParam;
struct ScriptVm;
struct ScrcmdWork;
struct GameEvent;
struct Mmdl;
struct BattleSetupParam;

#include "../ov020/event_mapchange_types.h"
#include "../ov021/bsubway_scr_types.h"
#include "../types.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"

int BSUBWAY_SCR_ClearWorkPtr(GameSystem *gameSystem);
BsubwayScrWork *BSUBWAY_SCR_CreateWork(GameSystem *gameSystem, int resume, u32 playMode);
void BSUBWAY_SCR_DeleteWork(GameSystem *gameSystem, BsubwayScrWork *work);
void BSUBWAY_SCR_ChangeCommMultiMode(BsubwayScrWork *work);
void BSUBWAY_SCR_SaveRestPlayData(BsubwayScrWork *work);
void BSUBWAY_SCR_LoadMembers(BsubwayScrWork *work, struct GameSystem *gameSystem);
void BSUBWAY_SCR_SavePlayDataMembers(BsubwayScrWork *work);
u32 BSUBWAY_SCR_ResetPlayMode(const struct GameSystem *gameSystem);
void BSUBWAY_SCR_SetLoseScore(struct GameSystem *gameSystem, BsubwayScrWork *work);
u32 BSUBWAY_SCR_AddBattlePoint(BsubwayScrWork *work);
void BSUBWAY_SCR_DrawTrainerNos(BsubwayScrWork *work);
u32 BSUBWAY_SCR_SetSelectedMembers(BsubwayScrWork *work, struct GameSystem *gameSystem);
int BSUBWAY_SCR_IsWinMax(BsubwayScrWork *work);
void BSUBWAY_SCR_SetClearScore(BsubwayScrWork *work, struct GameSystem *gameSystem);
int BSUBWAY_SCR_ClearStateBits(BsubwayScrWork *work, struct GameSystem *gameSystem);
void BSUBWAY_SCR_CreateRoundTrainers(BsubwayScrWork *work);
u32 BSUBWAY_SCR_GetTrainerObjCode(BsubwayScrWork *work, int i);
int BSUBWAY_SCR_UpdateStageRank(void *scoreData, struct GameSystem *gameSystem, int mode);
void BSUBWAY_SCR_LoadPartyCopy(BsubwayScrWork *work);
void *BSUBWAY_SCR_GetParty(BsubwayScrWork *work);
u16 BSUBWAY_SCR_GetWinCount(BsubwayScrWork *work);
void BSUBWAY_SCR_SetWinCount(BsubwayScrWork *work, u16 winCount);
void BSUBWAY_SCR_IncWinCount(BsubwayScrWork *work);
int BSUBWAY_SCR_ClearWinCount(BsubwayScrWork *work);
void BSUBWAY_SCR_SetWinCountFromRound(BsubwayScrWork *work, u32 stage, u32 round);
int BSUBWAY_SCR_GetMemberNum(u16 playMode);
int BSUBWAY_SCR_IsTrainerNoUsed(const u16 *list, u16 value, u16 count);
u16 BSUBWAY_SCR_GetStageNo(u16 winCount);
void BSUBWAY_SCR_SaveRecordParty(BsubwayScrWork *work, struct SaveControl *saveControl, int unused, u16 winCount);
void BSUBWAY_SCR_CreatePartners(BsubwayScrWork *work, u8 isAltRom);
void BSUBWAY_SCR_PackBattleMon(BattleMon *mon, struct PokemonParam *pokeParam);
void BSUBWAY_SCR_SaveMemberParty(BsubwayScrWork *work, struct SaveControl *saveControl, int slot);
int BSUBWAY_SCR_CmdCreateWork(struct ScriptVm *script, struct ScrcmdWork *scriptCtx);
int BSUBWAY_SCR_CmdClearWorkPtr(struct ScriptVm *script, struct ScrcmdWork *scriptCtx);
int BSUBWAY_SCR_CmdDeleteWork(struct ScriptVm *script, struct ScrcmdWork *scriptCtx);
int BSUBWAY_SCR_CmdTool(struct ScriptVm *scriptCtx, struct ScrcmdWork *script);
int BSUBWAY_SCR_WaitCommSend(struct ScriptVm *vm, void *script);
int BSUBWAY_SCR_WaitTimingSync(struct ScriptVm *vm, void *script);
int BSUBWAY_SCR_WaitCommEntryMenu(struct ScriptVm *vm, void *script);
int BSUBWAY_SCR_WaitCommEntryMenuSimple(struct ScriptVm *vm, void *script);
int BSUBWAY_SCR_WaitCommRecvEnd(struct ScriptVm *vm, void *script);
int BSUBWAY_SCR_CommShutdownMain(struct GameEvent *event, u32 *state, void *eventWork);
void *BSUBWAY_SCR_CreateCommShutdownTask(struct GameSystem *gameSystem, BsubwayScrWork *work);
int BSUBWAY_SCR_YesNoMenuMain(struct GameEvent *event, u32 *state, void *eventWork);
void *BSUBWAY_SCR_CreateYesNoMenuTask(struct GameSystem *gameSystem, struct ScrcmdWork *script, u16 *resultDst, u32 arg);
void BSUBWAY_SCR_CreateMarkerObjects(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap);
u32 BSUBWAY_SCR_GetMmdlParam(struct Mmdl *mapObj);
u32 BSUBWAY_SCR_IsNpcEntryAvailable(BsubwayScrWork *work, u32 idx);
void BSUBWAY_SCR_GetNpcEntryInfo(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird);
int BSUBWAY_SCR_WaitBeginSave(struct ScriptVm *vm, void *script);
int BSUBWAY_SCR_GetRegulationNo(u32 playMode);
int BSUBWAY_SCR_GetTrainNo(void *fieldMap);
struct BattleSetupParam *BSUBWAY_SCR_CreateBtlSetup(BsubwayScrWork *work, struct GameSystem *gameSystem);
void *BSUBWAY_SCR_GetNameinEncounterWork(void *work);
u16 BSUBWAY_SCR_DrawTrainerNo(BsubwayScrWork *work, u32 round, u32 stage, u32 line, u8 alt);
u8 BSUBWAY_SCR_CreateTrainer(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
u8 BSUBWAY_SCR_GetMonIv(u32 trainerNo);
void BSUBWAY_SCR_CreatePartnerMons(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, int useItem, BtlInstDraw *draw, u16 heapId);
u16 BSUBWAY_SCR_Random(void *unused);
/* END mkheaders: generated region */

#endif
