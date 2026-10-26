#ifndef GAME_OV021_TRIAL_HOUSE_H
#define GAME_OV021_TRIAL_HOUSE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of trial_house.c, prototypes copied from their definitions. */

struct TrialHouseWork;
struct GameSystem;
struct TrialHouseSave;
typedef struct TrialHouseWork TrialHouseWork;
typedef struct TrialHouseSave TrialHouseSave;

#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"

TrialHouseWork *TRIAL_HOUSE_CreateWork(GameSystem *gameSystem);
void TRIAL_HOUSE_LoadDeliveryState(GameSystem *gameSystem, TrialHouseWork *work);
void TRIAL_HOUSE_DeleteWork(GameSystem *gameSystem, TrialHouseWork **slot);
void TRIAL_HOUSE_SetBattleMode(TrialHouseWork *work, u32 mode);
void TRIAL_HOUSE_SetUseDeliveredTrainers(TrialHouseWork *work, int useDeliveredTrainers);
u16 TRIAL_HOUSE_LoadTrainer(GameSystem *gameSystem, TrialHouseWork *work, u32 index);
void TRIAL_HOUSE_BuildTrainerFromMode(TrialHouseWork *work, u32 mode);
void TRIAL_HOUSE_LoadDeliveredTrainer(GameSystem *gameSystem, BtlInstTrainer *dst, int index);
u16 TRIAL_HOUSE_GetTrainerObjCode(TrialHouseWork *work);
GameEvent *TRIAL_HOUSE_CreateTrainerMsgEvent(GameSystem *gameSystem, TrialHouseWork *work, u32 index, u32 mmdlId);
GameEvent *TRIAL_HOUSE_CreateDeliveryTask(GameSystem *gameSystem, TrialHouseWork *work, u16 *result);
int TRIAL_HOUSE_DeliveryTaskMain(struct GameEvent *event, int *seq, void *work);
void TRIAL_HOUSE_ComputeScoreAndRank(GameSystem *gameSystem, TrialHouseWork *work, u16 *outRank, u16 *outScore);
int TRIAL_HOUSE_GetDeliveryState(struct GameSystem *unused, TrialHouseWork *work);
GameEvent *TRIAL_HOUSE_CreateSaveTask(GameSystem *gameSystem, struct TrialHouseWork *unused, int mode);
int TRIAL_HOUSE_GetRecordSlotsState(GameSystem *gameSystem);
u8 TRIAL_HOUSE_IsDeliveryIdReceived(TrialHouseSave *save, u32 id);
void TRIAL_HOUSE_MarkDeliveryIdReceived(TrialHouseSave *save, u32 id);
int TRIAL_HOUSE_SaveTaskMain(struct GameEvent *event, int *seq, void *work);
/* END mkheaders: generated region */

#endif
