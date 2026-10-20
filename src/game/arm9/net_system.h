#ifndef GAME_ARM9_NET_SYSTEM_H
#define GAME_ARM9_NET_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_system.c, prototypes copied from their definitions. */

struct NetRecvCursor;
struct NetPacketHeader;

#include "../types.h"
#include "../arm9/net_types.h"

void GFL_NET_SYSTEM_SetDebugByte(u8 phase, int line);
void GFL_NET_SYSTEM_InitRecvState(struct NetRecvCursor *cursor);
u32 GFL_NET_SYSTEM_GetSendSize(void);
int GFL_NET_SYSTEM_InitWork(u32 packetSize, u32 heapId, u32 useParentSize);
void GFL_NET_SYSTEM_ResetBuffers(void);
void GFL_NET_SYSTEM_ResetRecvBuffer(int netId);
int GFL_NET_SYSTEM_InitDevice(u32 packetSize, u32 heapId);
u32 GFL_NET_SYSTEM_SetDeviceOption(u32 arg);
u32 GFL_NET_SYSTEM_RecvCallback(u32 netId, u8 *packet, u32 length);
u32 GFL_NET_SYSTEM_ConnectDevice(u8 renewTgid);
void GFL_NET_SYSTEM_ParentConnectHook(u32 netId);
void GFL_NET_SYSTEM_ChildConnectHook(u32 netId);
u32 GFL_NET_SYSTEM_StartParent(u8 renewTgid, u16 packetSize, u32 sendArg0, u32 sendArg1);
u32 GFL_NET_SYSTEM_StartBeaconScan(u32 sendArg, u16 packetSize);
int GFL_NET_SYSTEM_EndDevice(u32 packetSize);
void GFL_NET_SYSTEM_SetDeviceMode(int interval);
u32 GFL_NET_SYSTEM_ConnectToParent(u32 beaconArg0, u32 beaconArg1, u16 packetSize, u32 beaconArg2);
void GFL_NET_SYSTEM_FreeWork(void);
void GFL_NET_SYSTEM_FreeWorkIfAuto(void);
void GFL_NET_SYSTEM_ResetMachineBuffer(u32 netId);
int GFL_NET_SYSTEM_Main(void);
void GFL_NET_SYSTEM_ResetAll(void);
int GFL_NET_SYSTEM_PackSendData(int checkPending);
void GFL_NET_SYSTEM_SendParentData(void);
void GFL_NET_SYSTEM_SendWireless(void);
void GFL_NET_SYSTEM_SendWifi(void);
u32 GFL_NET_SYSTEM_RecvData(u32 netId, u8 *packet, u32 length);
void GFL_NET_SYSTEM_RecvParentCallback(u32 buffer, u32 size);
void GFL_NET_SYSTEM_SendIrc(void);
void GFL_NET_SYSTEM_SendMP(void);
void GFL_NET_SYSTEM_SendMPParent(void);
int GFL_NET_SYSTEM_CheckAllChildRecv(void);
void GFL_NET_SYSTEM_ClearChildRecv(void);
void GFL_NET_SYSTEM_UpdateMPParent(void);
int GFL_NET_SYSTEM_RecvChildData(u32 netId, NetPacketHeader *packet, s32 length);
int GFL_NET_SYSTEM_RecvParentData(u32 netId, NetPacketHeader *packet, s32 length);
int GFL_NET_SYSTEM_SendCallback(int success);
int GFL_NET_SYSTEM_SendEndCallback(u32 success);
s32 GFL_NET_SYSTEM_BuildSendPacket(struct NetPacketHeader *header, NetQueue *queue, s32 packetSize, u8 seq);
int GFL_NET_SYSTEM_SetSendQueue(u32 command, const void *data, u32 size, u32 sendArg, u32 destNetId, u32 queueArg, u32 noRing);
int GFL_NET_SYSTEM_GetChildRingDataSize(void);
int GFL_NET_SYSTEM_GetParentRingDataSize(void);
void GFL_NET_SYSTEM_DispatchRecv(int command, u32 size, u32 data, struct NetRecvCursor *cursor);
void GFL_NET_SYSTEM_ProcessRecvRing(NetRingBuff *ring, s32 senderID, u8 *buf, struct NetRecvCursor *cursor, u32 maxSize);
void GFL_NET_SYSTEM_ProcessParentRecv(void);
void GFL_NET_SYSTEM_ProcessChildRecv(void);
int GFL_NET_SYSTEM_IsConnectMember(u32 netId);
int GFL_NET_SYSTEM_GetConnectNum(void);
int GFL_NET_SYSTEM_IsDeviceReady(void);
u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int GFL_NET_SYSTEM_GetChildBitmap(void);
int GFL_NET_SYSTEM_IsError(void);
u32 GFL_NET_SYSTEM_CheckError(void);
int GFL_NET_SYSTEM_IsSendQueueEntry(u32 command, u32 destNetId);
int GFL_NET_SYSTEM_IsSendQueueEmpty(void);
void GFL_NET_SYSTEM_SetNoChildError(u8 v);
void GFL_NET_SYSTEM_SetWaitMode(u32 mode);
void GFL_NET_SYSTEM_SetError(void);
void GFL_NET_SYSTEM_ResetError(void);
void GFL_NET_SYSTEM_SetNoSend(void);
int GFL_NET_SYSTEM_IsSendEnable(void);
int GFL_NET_SYSTEM_ClampNetId(int netId);
/* END mkheaders: generated region */

#endif
