#ifndef GAME_OV012_UNION_COMMAND_H
#define GAME_OV012_UNION_COMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_command.c, prototypes copied from their definitions. */

struct UnionAppMessage;
typedef struct UnionAppMessage UnionAppMessage;

#include "../types.h"
#include "../ov012/union_comm_types.h"
#include "../ov012/union_command_shared_types.h"

u8 *UNION_COMMAND_GetRecvBuffer(int netId, UnionRoomWork *work, int size);
void UNION_COMMAND_RecvConnectSync(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendConnectSync(void);
void UNION_COMMAND_RecvPartnerSelectA(u32 netId, int size, const u32 *data, UnionRoomWork *work);
int UNION_COMMAND_SendPartnerSelectA(int select);
void UNION_COMMAND_RecvPartnerSelectB(u32 netId, int size, const u32 *data, UnionRoomWork *work);
int UNION_COMMAND_SendPartnerSelectB(int select);
void UNION_COMMAND_RecvPartnerMac(u32 netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendMyMac(void);
void UNION_COMMAND_RecvPartnerMode(u32 netId, int size, const u32 *data, UnionRoomWork *work);
int UNION_COMMAND_SendPartnerMode(int mode);
void UNION_COMMAND_RecvMyStatus(u32 netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendMyStatus(UnionRoomWork *work);
void UNION_COMMAND_RecvTrainerCard(u32 netId, u32 size, const void *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendTrainerCard(UnionRoomWork *work);
void UNION_COMMAND_RecvColosseumEntry(int netId, int size, const ColosseumPlayer *player, UnionRoomWork *work);
void UNION_COMMAND_RecvColosseumSetting(int netId, int size, const u32 *value, UnionRoomWork *work);
void UNION_COMMAND_RecvColosseumCancel(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendColosseumCancel(void);
void UNION_COMMAND_RecvAppEntry(int netId, int size, const void *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppEntry(UnionRoomWork *work);
void UNION_COMMAND_RecvAppEntryRefused(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendAppEntryRefused(u32 sendMask);
void UNION_COMMAND_RecvAppEntryAccepted(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendAppEntryAccepted(int sendMask);
void UNION_COMMAND_RecvAppQuitRequest(int netId, int size, const void *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppQuitRequest(void);
void UNION_COMMAND_RecvAppQuitAccept(int netId, int size, const void *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppQuitAccept(u32 sendMask);
void UNION_COMMAND_RecvAppSettingRequest(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendAppSettingRequest(void);
void UNION_COMMAND_RecvAppSetting(int netId, int size, const void *value, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppSetting(const void *data, u32 sendMask);
void UNION_COMMAND_RecvAppJoinData(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendAppJoinData(u8 sendMask, const UnionAppData *src);
void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppData(u32 sendMask, const UnionAppMessage *message);
void UNION_COMMAND_RecvAppLeaveData(int netId, int size, const void *data, UnionRoomWork *work);
int UNION_COMMAND_SendAppLeaveData(u8 sendMask, const UnionAppData *src);
void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value);
/* END mkheaders: generated region */

#endif
