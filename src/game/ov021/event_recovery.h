#ifndef GAME_OV021_EVENT_RECOVERY_H
#define GAME_OV021_EVENT_RECOVERY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_recovery.c, prototypes copied from their definitions. */

struct RecoveryBallsWork;
struct PartyRecoveryWork;
typedef struct RecoveryBallsWork RecoveryBallsWork;
typedef struct PartyRecoveryWork PartyRecoveryWork;

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"

GameEvent *EVENT_RECOVERY_CreateBallsEvent(GameSystem *gameSystem, GameEvent *parent, u32 count);
int EVENT_RECOVERY_RunBalls(GameEvent *event, int *seq, void *eventWork);
void EVENT_RECOVERY_InitBalls(RecoveryBallsWork *work, GameSystem *gameSystem, u32 count);
void EVENT_RECOVERY_DeleteBalls(RecoveryBallsWork *work);
void EVENT_RECOVERY_SetBallsStep(RecoveryBallsWork *work, int *seq, int nextStep);
void EVENT_RECOVERY_PlaceBall(RecoveryBallsWork *work);
void EVENT_RECOVERY_StartBallsAnime(RecoveryBallsWork *work);
void EVENT_RECOVERY_FinishBalls(RecoveryBallsWork *work);
int EVENT_RECOVERY_AreBallsIdle(RecoveryBallsWork *work);
GameEvent *EVENT_RECOVERY_CreatePartyEvent(GameSystem *gameSystem, GameEvent *parent);
int EVENT_RECOVERY_RunParty(GameEvent *event, int *seq, void *eventWork);
void EVENT_RECOVERY_InitParty(PartyRecoveryWork *work, GameSystem *gameSystem);
void EVENT_RECOVERY_DeleteMachineNode(PartyRecoveryWork *work);
void EVENT_RECOVERY_PlacePartyBall(PartyRecoveryWork *work);
void EVENT_RECOVERY_ActivateParty(PartyRecoveryWork *work);
int EVENT_RECOVERY_IsMachineAnimeDone(PartyRecoveryWork *work);
u32 EVENT_RECOVERY_GetPartyBallCount(GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
