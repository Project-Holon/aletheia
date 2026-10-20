#ifndef GAME_OV093_BTL_NET_H
#define GAME_OV093_BTL_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_net.c, prototypes copied from their definitions. */

struct BtlRuleExchange;
struct Party;
struct BtlNetTrainerPacket;
struct BtlNetTrainerData;
struct BtlNetMsgSlot;

#include "../types.h"
#include "../ov093/btl_net_types.h"

void BTL_NET_Init(void *netHandle, u16 memberMask, u16 heapId);
int BTL_NET_IsInitialSyncDone(void);
void BTL_NET_Exit(void);
int BTL_NET_HasCommError(void);
int BTL_NET_SendEntry(u16 clientId);
void BTL_NET_RecvEntry(int netId, int unused, u16 *data);
u8 BTL_NET_HasEntry(int netId);
int BTL_NET_IsLeaderKnown(void);
int BTL_NET_IsLeader(void);
u8 BTL_NET_GetLeaderValue(void);
u8 BTL_NET_FindNetIdByClient(u32 clientId);
u32 BTL_NET_SendSetup(struct BtlRuleExchange *setup);
void BTL_NET_RecvSetup(int unused0, int unused1, BtlNetSetup *src);
int BTL_NET_GetSetup(BtlNetSetup *dst);
u8 BTL_NET_SendParty(struct Party *party);
void *BTL_NET_AllocPartyBuf(int netId, int unused, u32 size);
void BTL_NET_RecvPartyDone(int netId, void *buf);
int BTL_NET_IsPartyReceived(void);
void BTL_NET_ResetAfterParty(void);
u32 BTL_NET_SendPerapVoice(u32 *voice);
void *BTL_NET_AllocPerapVoiceBuf(int netId, int unused, u32 size);
void BTL_NET_RecvPerapVoiceDone(int netId, int doneOrSize);
int BTL_NET_IsPerapVoiceReceived(void);
u32 BTL_NET_GetPerapVoice(u32 clientId);
void BTL_NET_ResetAfterPerapVoice(void);
u32 BTL_NET_SendRelayedParty(u32 *packet);
void *BTL_NET_AllocRelayedPartyBuf(int unused0, int unused1, u32 size);
int BTL_NET_IsRelayedPartyReceived(u32 clientId);
void *BTL_NET_GetParty(u8 clientId);
void BTL_NET_FreeAfterPartyUse(void);
int BTL_NET_SendPlayerInfo(void *myStatus);
void *BTL_NET_AllocPlayerInfoBuf(int netId, int unused, u32 size);
void BTL_NET_RecvPlayerInfoDone(int netId, void *buf);
int BTL_NET_IsPlayerInfoReceived(void);
void *BTL_NET_GetPlayerInfo(u8 clientId);
u32 BTL_NET_SendRelayedPlayerInfo(void *trainerData);
u32 BTL_NET_AllocRelayedPlayerInfoBuf(void *unused0, int unused1, int size);
void BTL_NET_RecvRelayedPlayerInfoDone(int unused, void *buf);
int BTL_NET_IsRelayedPlayerInfoReceived(void);
void *BTL_NET_GetRelayedPlayerInfo(void);
void BTL_NET_FreeRelayedPlayerInfo(void);
void BTL_NET_FreeAfterPlayerInfoUse(void);
struct BtlNetTrainerPacket *BTL_NET_BuildPlayerInfoPacket(struct BtlNetTrainerData *trainerData, u32 heapId);
void BTL_NET_FreePlayerInfoPacket(void *packet);
void BTL_NET_FreeRecvBuffers(void);
void BTL_NET_BeginSync(int stage);
int BTL_NET_PollSync(int stage);
u32 BTL_NET_SendServerCmd(u32 clientId, u32 data, u32 size);
int BTL_NET_AreAllRepliesReceived(void);
u16 BTL_NET_GetClientReply(int clientId, u8 **data);
struct BtlNetMsgSlot *BTL_NET_GetReplySlot(int netId);
void BTL_NET_RecvClientReply(int netId, u32 size);
void BTL_NET_ExpectReplies(u32 unused);
unsigned char BTL_NET_HasServerCmd(void);
u16 BTL_NET_GetServerCmd(u8 **data);
u32 BTL_NET_SendClientReply(u32 data, u32 size);
void BTL_NET_RecvServerCmd(int unused, u32 size);
struct BtlNetMsgSlot *BTL_NET_GetServerCmdSlot(void);
void BTL_NET_ResetReplySlots(void);
void *BTL_NET_AllocRelayPacket(u32 size, u16 heapId);
void BTL_NET_FreeRelayPacket(void *packet);
void BTL_NET_FillRelayPacket(u32 *packet, const void *src, u32 clientId);
/* END mkheaders: generated region */

#endif
