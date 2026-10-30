#ifndef GAME_OV015_IRCNET_H
#define GAME_OV015_IRCNET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_irc.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov015/net_irc_types.h"

int IRCNET_CbInit(void);
int IRCNET_CbConnect(void);
int IRCNET_CbResend(void);
int IRCNET_CbReturnTrue(void);
int IRCNET_CbStop(void);
unsigned char IRCNET_CbIsRunning(void);
int IRCNET_IsNotRunning(void);
int IRCNET_SendAndNotify(void *dst, int a, int unused, void (*cb)(int));
int IRCNET_CbSetRecvCallback(IRCNetRecvFn v);
int IRCNET_CbIsLinkedReceiver(void);
int IRCNET_CbIsLinkLost(void);
void IRCNET_CbUpdate(void);
int IRCNET_CbCanSend(void);
unsigned char IRCNET_CbIsSendReady(void);
unsigned char IRCNET_CbHasPeer(void);
int IRCNET_CbIsConnected(void);
int IRCNET_CbIsLinkAlive(void);
unsigned char IRCNET_CbGetRunning(void);
int IRCNET_CbGetLinkState(void);
unsigned char IRCNET_CbIsClosing(void);
void IRCNET_CbOnConnect(void);
void IRCNET_CbSetTimeoutLimit(int v);
void IRCNET_CbSetFilter(IRCNetFilterFn a);
void *IRCNET_GetHandlerTable(void);
void IRCNET_SendPacket(void *dst, int n, u8 a, u8 b);
void IRCNET_InitWork(u32 a, u8 b);
void IRCNET_SetTimeoutLimit(int v);
void IRCNET_Stop(void);
void IRCNET_SetRecvCallback(IRCNetRecvFn v);
void IRCNET_SetFilter(IRCNetFilterFn a);
void IRCNET_Start(void);
unsigned char IRCNET_IsRunning(void);
u8 IRCNET_IsSendReady(void);
u8 IRCNET_IsClosing(void);
int IRCNET_IsIdle(void);
void IRCNET_QueueSend(void *dst, u8 a, u8 b);
void IRCNET_ResendPending(void);
int IRCNET_IsReceiver(void);
void IRCNET_OnRecv(u8 *rawPacket, u8 len, u8 type, u8 id);
int IRCNET_IsSender(void);
int IRCNET_IsLinkLost(void);
void IRCNET_OnConnect(void);
void IRCNET_OnPeerFound(void);
u8 IRCNET_GetSenderFlag(void);
int IRCNET_IsLinkAlive(void);
u8 IRCNET_HasPeer(void);
int IRCNET_IsConnected(void);
void IRCNET_Update(void);
/* END mkheaders: generated region */

#endif
