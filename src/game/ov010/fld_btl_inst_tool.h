#ifndef GAME_OV010_FLD_BTL_INST_TOOL_H
#define GAME_OV010_FLD_BTL_INST_TOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_btl_inst_tool.c, prototypes copied from their definitions. */

struct PartySelectEventWork;
struct TrainerMsgEventWork;
struct BattleSetupParam;
struct BtlInstGroup;
struct CommResetWork;
struct BtlInstBattleRequest;
struct PartySelectStepWork;
struct BtlInstRecord;
typedef struct PartySelectEventWork PartySelectEventWork;
typedef struct TrainerMsgEventWork TrainerMsgEventWork;
typedef struct BtlInstGroup BtlInstGroup;
typedef struct CommResetWork CommResetWork;
typedef struct BtlInstBattleRequest BtlInstBattleRequest;
typedef struct PartySelectStepWork PartySelectStepWork;
typedef struct BtlInstRecord BtlInstRecord;

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"
#include "../types.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"

GameEvent *FLD_BTL_INST_TOOL_CreatePokeListEvent(GameSystem *gameSystem, int listArg, int listMode, int regulationId, Party *party, u8 *resultOrder, u32 *resultSlot, u32 *resultCommand, Party *resultParty);
int FLD_BTL_INST_TOOL_PokeListEventMain(struct GameEvent *event, int *seq, void *work);
GameEvent *FLD_BTL_INST_TOOL_CreateTrainerMsgEvent(GameSystem *gameSystem, BtlInstTrainer *trainers, int index, int mmdlId);
int FLD_BTL_INST_TOOL_TrainerMsgEventMain(struct GameEvent *event, int *seq, void *work);
struct BattleSetupParam *FLD_BTL_INST_TOOL_CreateBtlSetup(GameSystem *gameSystem, Party *playerParty, u32 battleMode, BtlInstTrainer *trainerA, BtlInstTrainer *trainerB, int monCount);
u32 FLD_BTL_INST_TOOL_BuildBattleMon(BattleMon *out, u32 memberId, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useTableItem, u16 heapId);
void FLD_BTL_INST_TOOL_ReadMonData(void *dest, u32 memberId);
void *FLD_BTL_INST_TOOL_LoadTrainerGroup(u32 group, u32 heapId);
int FLD_BTL_INST_TOOL_GetRandomU16(void);
u8 FLD_BTL_INST_TOOL_GetIvForRank(u32 rank);
int FLD_BTL_INST_TOOL_CreateTrainer(BtlInstTrainer *trainer, u16 trainerIndex, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId);
BtlInstGroup *FLD_BTL_INST_TOOL_InitTrainerHeader(BtlInstTrainer *trainer, int trainerIndex, int heapId);
int FLD_BTL_INST_TOOL_DrawTrainerParty(BtlInstGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, BtlInstDraw *draw, u16 heapId);
int FLD_BTL_INST_TOOL_HasBattleMsgs(BtlInstTrainer *trainer);
u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 key);
void FLD_BTL_INST_TOOL_SetDoneFlag(void * doneFlagArg);
int FLD_BTL_INST_TOOL_CommResetEventMain(struct GameEvent *event, int *step, void *work);
GameEvent *FLD_BTL_INST_TOOL_CreateCommResetEvent(GameSystem *gameSystem, int restoreAutoComm);
GameEvent *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(GameSystem *gameSystem, BtlInstBattleRequest *request, int regulationId, int useTempParty, u16 *resultOk);
int FLD_BTL_INST_TOOL_PartySelectStepEventMain(struct GameEvent *event, int *step, void *work);
GameEvent *FLD_BTL_INST_TOOL_CreateBattleEvent(GameSystem *gameSystem, BtlInstBattleRequest *request);
void FLD_BTL_INST_TOOL_AddBattleTally(BtlInstRecord *record, struct BattleSetupParam *result);
GameEvent *FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(GameSystem *gameSystem, int hasSecondEntry, int fadeOutBgm);
int FLD_BTL_INST_TOOL_TrialHouseAwardEventMain(struct GameEvent *event, int *step, void *eventWork);
/* END mkheaders: generated region */

#endif
