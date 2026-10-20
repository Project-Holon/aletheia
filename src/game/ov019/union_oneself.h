#ifndef GAME_OV019_UNION_ONESELF_H
#define GAME_OV019_UNION_ONESELF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_oneself.c, prototypes copied from their definitions. */

struct GameSystem;

#include "../ov012/union_comm_types.h"
#include "../types.h"

int UNION_ONESELF_TryStartSubEvent(struct GameSystem *gameSystem, void *fieldMap);
int UNION_ONESELF_GetFieldTalkEvent(void *gameSystem, void *pos);
int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap);
int UNION_ONESELF_SetNextPlayCategory(UnionRoomWork *work, int playCategory);
int UNION_ONESELF_SetNextPlayCategoryInMainPhase(UnionRoomWork *work, char playCategory);
int UNION_ONESELF_GetRegulationId(int status);
int UNION_ONESELF_GetRegulationFlag(int status);
int UNION_ONESELF_IsBattleStatus(unsigned int status);
void *UNION_ONESELF_CreateBattleTeamParty(UnionRoomWork *work);
void UNION_ONESELF_DeleteParty(void *party);
void UNION_ONESELF_LoadRegulation(UnionRoomWork *work, int status);
int UNION_ONESELF_CheckMyParty(UnionRoomWork *work, unsigned int *violationMask);
int UNION_ONESELF_CheckBattleTeamParty(UnionRoomWork *work, unsigned int *violationMask);
int UNION_ONESELF_CheckEntryParties(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask);
void UNION_ONESELF_SetFieldBusy(UnionRoomWork *work, void *fieldMap, unsigned int busy);
int UNION_ONESELF_HandleNetError(UnionRoomWork *work);
int UNION_ONESELF_HandleNetErrorExit(UnionRoomWork *work);
int UNION_ONESELF_IdleStart(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_IdleMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_ErrorMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step);
int UNION_ONESELF_NoOpMain(void);
int UNION_ONESELF_FieldExitMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step);
int UNION_ONESELF_ChatInputMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ConnectParentStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_ConnectParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ConnectParentEnd(UnionRoomWork *unisys);
int UNION_ONESELF_ConnectChildStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_ConnectChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ConnectChildEnd(UnionRoomWork *unisys);
int UNION_ONESELF_TalkParentStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkParentEnd(UnionRoomWork *unisys);
int UNION_ONESELF_TalkParentAnswerWaitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkChildStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkChildEnd(void);
int UNION_ONESELF_BattleMenuMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkPlayingMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TalkPlayingChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TrainerCardMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_TradeMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_JoinMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ConnectGroupMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_AppMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumEnterParentMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumEnterChildMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumEntryMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
void UNION_ONESELF_EntryMenuAddMember(UnionRoomWork *unisys, const void *myStatus, const u8 *mac);
void UNION_ONESELF_EntryMenuRemoveMember(UnionRoomWork *unisys, const void *myStatus, const u8 *mac);
int UNION_ONESELF_ColosseumSetupMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumFreeMoveStart(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_ColosseumFreeMoveMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumStandPosMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumLeavePosMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumPartySelectMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumReadyWaitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumPartyExchangeMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumBattleMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumLeaveConfirmMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumExitMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int UNION_ONESELF_ColosseumTrainerCardMain(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
/* END mkheaders: generated region */

#endif
