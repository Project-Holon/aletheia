#ifndef GAME_OV012_UNION_COMM_H
#define GAME_OV012_UNION_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_comm.c, prototypes copied from their definitions. */

#include "../ov012/union_comm_types.h"
#include "../ov012/union_comm_types.h"
#include "../types.h"

UnionRoomWork *UNION_COMM_Create(UnionParentWork *parent);
void UNION_COMM_Delete(UnionParentWork *parent, UnionRoomWork *work);
UnionRoomWork *UNION_COMM_InitComm(int *seq, UnionParentWork *parent);
int UNION_COMM_InitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work);
void UNION_COMM_SessionStartCallback(void *userArg);
int UNION_COMM_Exit(int *seq, UnionParentWork *parent, UnionRoomWork *work);
int UNION_COMM_ExitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work);
void UNION_COMM_ExitCallback(void *userArg);
void UNION_COMM_RequestRestart(UnionRoomWork *work);
void UNION_COMM_RequestShutdown(UnionRoomWork *work);
void UNION_COMM_RequestStart(UnionRoomWork *work);
int UNION_COMM_IsResetting(UnionRoomWork *work);
int UNION_COMM_UpdateReset(UnionRoomWork *work);
void UNION_COMM_Update(int *seq, UnionParentWork *parent, UnionRoomWork *work);
void UNION_COMM_StartConnectSync(UnionRoomWork *work);
void UNION_COMM_UpdateConnectSync(UnionRoomWork *work);
void UNION_COMM_SendEntryReplies(UnionRoomWork *work);
void UNION_COMM_UpdateColosseum(UnionRoomWork *work);
void UNION_COMM_UpdateBeaconScan(UnionRoomWork *work);
int UNION_COMM_StoreBeacon(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac);
int UNION_COMM_IsNotGroupMember(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac);
UnionBeacon *UNION_COMM_GetBeacon(UnionRoomWork *work);
void UNION_COMM_BuildBeacon(UnionRoomWork *work, UnionBeacon *beacon);
int UNION_COMM_GetBeaconSize(void);
int UNION_COMM_CompareBeacon(u32 myServiceId, u32 beaconServiceId, UnionRoomWork *work);
void UNION_COMM_StateChangeCallback(void);
void UNION_COMM_ConnectEndCallback(void);
void UNION_COMM_ClearBeaconPcs(UnionRoomWork *work);
void UNION_COMM_ReleaseWorks(UnionRoomWork *work);
void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value);
void UNION_COMM_InitSituation(UnionRoomWork *work);
void UNION_COMM_ClearPartnerSelects(UnionConnectInfo *connect);
void UNION_COMM_InitConnectInfo(UnionRoomWork *work, UnionConnectInfo *connect);
int UNION_COMM_AddMember(UnionConnectInfo *connect, const u8 *mac, u8 trainerView, u8 sex);
int UNION_COMM_AddMemberFromBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc);
void UNION_COMM_RemoveMember(UnionConnectInfo *connect, const u8 *mac);
void UNION_COMM_RemoveMemberOfBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc);
void UNION_COMM_InitChatLog(UnionChatLog *log);
void UNION_COMM_SetChatPms(UnionRoomWork *work, const UnionPmsData *pms);
void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType);
void UNION_COMM_SetGameKindByStatus(u32 status);
/* END mkheaders: generated region */

#endif
