#ifndef GAME_OV101_COMPATIBLE_IRC_SYS_H
#define GAME_OV101_COMPATIBLE_IRC_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of compatible_irc_sys.c, prototypes copied from their definitions. */

#include "../ov101/compatible_irc_sys_types.h"
#include "../types.h"
#include "../arm9/net_types.h"

void *COMPATIBLE_IRC_SYS_Create(int context,int playerRecords,int heapId,int offline);
void COMPATIBLE_IRC_SYS_Delete(void *sys);
int COMPATIBLE_IRC_SYS_StepStartSession(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepShutdown(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepConnectChild(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepSyncTiming(IrcSys *sys);
int COMPATIBLE_IRC_SYS_IsPartnerReady(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepShareValue(IrcSys *sys,int value);
void COMPATIBLE_IRC_SYS_ResetStep(IrcSys *sys);
void COMPATIBLE_IRC_SYS_ClearValues(IrcSys *sys);
void COMPATIBLE_IRC_SYS_SetOwnValue(IrcSys *sys,int value);
int COMPATIBLE_IRC_SYS_UpdateValueSync(IrcSys *sys);
int COMPATIBLE_IRC_SYS_SendOwnValue(IrcSys *sys);
int COMPATIBLE_IRC_SYS_GetValueDifference(IrcSys *sys);
int COMPATIBLE_IRC_SYS_SendToHandle(IrcSys *sys,u32 commandId,u32 size,u32 data);
u32 COMPATIBLE_IRC_SYS_SendData(IrcSys *sys,u32 commandId,u32 size,u32 data,u8 target,u32 e,u32 f,u32 g);
void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys,u32 a,NetCommandEntry *b,u32 c,void *d);
void COMPATIBLE_IRC_SYS_DeleteCommandTable(IrcSys *sys,u32 a);
int COMPATIBLE_IRC_SYS_SendProfileRequest(IrcSys *sys,u32 a,u32 b);
int COMPATIBLE_IRC_SYS_PollProfileRequest(IrcSys *sys);
int COMPATIBLE_IRC_SYS_SendProfileAck(IrcSys *sys);
int COMPATIBLE_IRC_SYS_PollProfileAck(IrcSys *sys);
int COMPATIBLE_IRC_SYS_StepSendProfile(IrcSys *sys,int resource);
void COMPATIBLE_IRC_SYS_GetPartnerProfile(IrcSys *sys,IrcCompatibleProfile *out);
void COMPATIBLE_IRC_SYS_BuildProfile(void *playerData,IrcCompatibleProfile *out);
void COMPATIBLE_IRC_SYS_SetPlayerReady(IrcSys *sys, int index);
int COMPATIBLE_IRC_SYS_GetRecvBuffer(void);
int COMPATIBLE_IRC_SYS_GetRecvSize(void);
int COMPATIBLE_IRC_SYS_IsEqual(int a, int b);
void COMPATIBLE_IRC_SYS_ClearPartnerReady(IrcSys *sys);
void COMPATIBLE_IRC_SYS_StartSessionCallback(void *userArg);
void COMPATIBLE_IRC_SYS_ExitCallback(void *userArg);
void COMPATIBLE_IRC_SYS_RecvValueHandler(unsigned aid,int size,void *data,unsigned char *work);
void COMPATIBLE_IRC_SYS_RecvValueAckHandler(int aid,int size,int data,IrcSys *work,unsigned handle);
void COMPATIBLE_IRC_SYS_RecvOwnValueHandler(unsigned aid,int size,void *data,unsigned char *work,unsigned handle);
void COMPATIBLE_IRC_SYS_ProfileSyncInit(IrcProfileSync *sync, IrcSys *sys, int heapId);
void COMPATIBLE_IRC_SYS_ProfileSyncExit(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncSendRequest(IrcProfileSync *sync,int first,int second);
int COMPATIBLE_IRC_SYS_ProfileSyncPollRequest(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncSendAck(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncPollAck(IrcProfileSync *sync);
int COMPATIBLE_IRC_SYS_ProfileSyncStepSend(IrcProfileSync *sync,int resource);
void COMPATIBLE_IRC_SYS_ProfileSyncGetPartnerProfile(IrcProfileSync *sync,IrcCompatibleProfile *out);
void COMPATIBLE_IRC_SYS_RecvRequestHandler(u32 aid,int size,void *data,IrcProfileSync *work,void *handle);
void COMPATIBLE_IRC_SYS_RecvAckHandler(u32 aid,int size,int data,IrcProfileSync *work,void *handle);
void COMPATIBLE_IRC_SYS_RecvDoneHandler(u32 aid,int size,int data,IrcProfileSync *work,void *handle);
void COMPATIBLE_IRC_SYS_RecvProfileHandler(u32 aid, int size, int data, IrcProfileSync *work, u32 handle);
u32 COMPATIBLE_IRC_SYS_ProfileSyncGetProfileForAid(u32 aid,IrcProfileSync *sync);
/* END mkheaders: generated region */

#endif
