#ifndef GAME_OV012_COLOSSEUM_H
#define GAME_OV012_COLOSSEUM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of colosseum.c, prototypes copied from their definitions. */

struct GameData;
struct MyStatus;
struct GameSystem;
struct ColosseumBattleInfo;
struct ColosseumBattleMember;
typedef struct ColosseumBattleInfo ColosseumBattleInfo;
typedef struct ColosseumBattleMember ColosseumBattleMember;

#include "../ov012/union_comm_types.h"
#include "../types.h"
#include "../ov010/comm_player_types.h"

ColosseumWork *COLOSSEUM_Create(const struct GameData *gameData, void *gameSystem, const struct MyStatus *myStatus, u32 modeFlag);
void COLOSSEUM_Delete(ColosseumWork *work, void *gameSystem);
void COLOSSEUM_SetStartFlag(ColosseumWork *work, int flag);
void COLOSSEUM_SetMyChoice(ColosseumWork *work, int choice);
u8 COLOSSEUM_GetMyChoice(ColosseumWork *work);
void COLOSSEUM_SetMyChoiceReply(ColosseumWork *work, int reply);
u8 COLOSSEUM_GetMyChoiceReply(ColosseumWork *work);
int COLOSSEUM_AssignChoice(ColosseumWork *work, int netId, int value);
void COLOSSEUM_FlushChoiceReplies(ColosseumWork *work);
void COLOSSEUM_UpdateReadyState(ColosseumWork *work);
void COLOSSEUM_StorePackage(ColosseumWork *work, int netId, const CommPlayerPackage *package);
int COLOSSEUM_TakePackage(ColosseumWork *work, int netId, CommPlayerPackage *out);
void COLOSSEUM_ClearConfirmCount(ColosseumWork *work);
int COLOSSEUM_AllPartiesReceived(ColosseumWork *work);
void COLOSSEUM_ResetParties(ColosseumWork *work, int keepOwn);
void COLOSSEUM_SetupBattleInfo(ColosseumWork *work, struct GameSystem *gameSystem, ColosseumBattleInfo *out, int heapId);
void COLOSSEUM_ClearBattleInfo(ColosseumBattleInfo *out);
void COLOSSEUM_SetupBattleMember(ColosseumWork *colosseum, ColosseumBattleMember *member, u8 playerIndex, int heapId);
/* END mkheaders: generated region */

#endif
