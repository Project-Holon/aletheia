#ifndef GAME_ARM9_NET_HANDLE_H
#define GAME_ARM9_NET_HANDLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_handle.c, prototypes copied from their definitions. */

struct NetTimingVoteMsg;
struct NetTimingNoMsg;
struct NetNegotiationMsg;

#include "../arm9/net_types.h"
#include "../types.h"

int GFL_NET_HANDLE_GetNetHandleID(GFLNetHandle *handle);
void GFL_NET_HANDLE_ResetHandle(GFLNetHandle *handle, u32 netID);
void GFL_NET_HANDLE_ClearTimingMask(GFLNetHandle *handle, u32 netID);
GFLNetHandle *GFL_NET_HANDLE_CreateHandle(u32 netID);
void GFL_NET_HANDLE_InitWork(GFLNetSession *unused);
void GFL_NET_HANDLE_ExitWork(GFLNetSession *unused);
GFLNetHandle *GFL_NET_HANDLE_GetNetHandle(s32 netID);
GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_HANDLE_IsNegotiationDone(GFLNetHandle *handle);
int GFL_NET_HANDLE_GetNegotiationState(GFLNetHandle *handle);
int GFL_NET_HANDLE_GetNegotiationNum(void);
void GFL_NET_HANDLE_RequestNegotiation(int timingNo);
void GFL_NET_HANDLE_SendNegotiation(void);
int GFL_NET_HANDLE_CheckNegotiation(void);
void GFL_NET_HANDLE_RecvTimingSync(u32 netID, u32 size, struct NetTimingVoteMsg *msg, u32 work, GFLNetHandle *handle);
void GFL_NET_HANDLE_RecvTimingTag(u32 netID, u32 size, struct NetTimingNoMsg *msg, u32 work, GFLNetHandle *handle);
void GFL_NET_HANDLE_StartTimingSync(GFLNetHandle *handle, u16 timingNo);
void GFL_NET_HANDLE_SetTimingSyncRange(GFLNetHandle *handle, u32 timingLow, u32 timingHigh);
u32 GFL_NET_HANDLE_IsTimingSync(GFLNetHandle *handle, u32 timingNo);
u32 GFL_NET_HANDLE_IsTimingSyncRange(GFLNetHandle *handle, u32 timingLow, u32 timingHigh);
int GFL_NET_HANDLE_SendTimingSyncAll(GFLNetHandle *handle);
void GFL_NET_HANDLE_Main(void);
void GFL_NET_HANDLE_RecvNegotiation(u32 netID, u32 size, const struct NetNegotiationMsg *msg, u32 work, GFLNetHandle *handle);
void GFL_NET_HANDLE_SetNegotiationEnd(GFLNetHandle *handle);
void GFL_NET_HANDLE_RecvNegotiationReturn(int senderID, int size, NetMemberRec *msg, int localNetID, GFLNetHandle *peer);
void GFL_NET_HANDLE_RecvRemoveHandle(u32 netID, u32 size, u8 *data, u32 work, u32 handle);
u16 GFL_NET_HANDLE_SetBitMask(u16 bitMask, u32 netID, u32 enable);
u32 GFL_NET_HANDLE_IsBitSet(u32 bitMask, u32 netID);
void GFL_NET_HANDLE_RemoveHandle(u32 netID);
void GFL_NET_HANDLE_RecvInfoData(int netID, u32 size, const void *data, u32 work, GFLNetHandle *handle);
void GFL_NET_HANDLE_SetUserInfo(GFLNetHandle *handle, int timingLow, int timingHigh, int netID);
void GFL_NET_HANDLE_SetAllTimingValue(GFLNetHandle *handle, u32 timing);
/* END mkheaders: generated region */

#endif
