#ifndef GAME_OV009_GSUDPENGINE_H
#define GAME_OV009_GSUDPENGINE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsudpengine.c, prototypes copied from their definitions. */

#include "../ov009/gsudp_types.h"

void gsUdpMsgHandlerFree(GSUdpMsgHandler *theHandler);
int gsUdpMsgHandlerCompare(void *theFirst, void *theSecond);
int gsUdpMsgHandlerCompare2(void *theFirst, void *theSecond);
int gsUdpRemotePeerCompare(void *theFirstPeer, void *theSecondPeer);
int gsUdpRemotePeerCompare2(void *theFirstPeer, void *theSecondPeer);
void gsUdpSocketError(void);
void gsUdpClosedRoutingCB(void *theConnection, int reason);
void gsUdpConnectedRoutingCB(void *theConnection, int theResult);
void gsUdpPingRoutingCB(void *theConnection, int theLatency);
void gsUdpReceivedRoutingCB(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
int gsUdpUnrecognizedMsgCB(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen);
void gsUdpConnAttemptCB(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
int gsUdpEngineIsInitialized(void);
int gsUdpEngineInitialize(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize, void (*theAppNetworkError)(int, void *), void (*theAppConnected)(unsigned int, unsigned short, int, int, void *), void (*theAppClosed)(unsigned int, unsigned short, int, void *), void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *), void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *), void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *), void *theAppUserData);
int gsUdpEngineGetPeerState(unsigned int theIp, unsigned short thePort, int *thePeerState);
int gsUdpEngineStartTalkingToPeer(unsigned int theIp, unsigned short thePort, char *theInitMsg, int timeOut);
int gsUdpEngineSendMessage(unsigned int theIp, unsigned short thePort, char *theHeader, unsigned char *theMsg, unsigned int theMsgLen, int theReliable);
int gsUdpEngineThink(void);
int gsUdpEngineShutdown(void);
unsigned short gsUdpEngineGetLocalPort(void);
int gsUdpEngineAddMsgHandler(char *theInitMsg, char *theHeader, void (*theMsgHandlerError)(int, void *), void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *), void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *), void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *), void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), void *theUserData);
int gsUdpEngineRemoveMsgHandler(char *theHeader);
int gsUdpEngineNoMoreMsgHandlers(void);
int gsUdpEngineNoApp(void);
int gsUdpEngineGetPeerOutBufferFreeSpace(unsigned int theIp, unsigned short thePort);
/* END mkheaders: generated region */

#endif
