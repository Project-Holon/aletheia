#ifndef GAME_OV009_NATNEG_H
#define GAME_OV009_NATNEG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of natneg.c, prototypes copied from their definitions. */

struct _NATNegotiator;
typedef struct _NATNegotiator NATNegotiator;

#include "../types.h"
#include "../sdk_soc.h"

int GetClientUniqueID(void);
NATNegotiator *FindNegotiatorForCookie(int cookie);
NATNegotiator *AddNegotiator(void);
void RemoveNegotiator(NATNegotiator *neg);
void NNFreeNegotiateList(void);
int CheckMagic(const u8 *a);
void SendReportPacket(NATNegotiator *neg);
void StartReport(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
void SendPreinitPacket(NATNegotiator *neg);
void SendInitPackets(NATNegotiator *neg);
void SendPingPacket(NATNegotiator *neg);
int CheckNatifyStatus(int sock);
unsigned int NameToIp(char *name);
unsigned int ResolveServer(char *overrideHostname, char *defaultHostname);
int ResolveServers(void);
int NNBeginNegotiationWithSocket(int gamesocket, int cookie, int clientindex, void (*progresscallback)(int, void *), void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
void NNCancel(int cookie);
void RemoveFinishedNegotiator(int *p);
void NegotiateThink(NATNegotiator *neg);
void NNThink(void);
void SendConnectAck(NATNegotiator *neg, SOCSockAddrIn *toaddr);
void NNProcessData(char *data, int len, SOCSockAddrIn *fromaddr);
/* END mkheaders: generated region */

#endif
