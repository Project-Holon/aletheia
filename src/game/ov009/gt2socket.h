#ifndef GAME_OV009_GT2SOCKET_H
#define GAME_OV009_GT2SOCKET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2socket.c, prototypes copied from their definitions. */

#include "../ov009/gt2main_types.h"
#include "../ov009/gt2main_types.h"
#include "../types.h"

GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket, u32 ip, u16 port);
int gti2CreateSocket(GTI2Socket **sock, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void (*callback)(GTI2Socket *), int type);
void gti2CloseSocket(GTI2Socket *socket);
void gti2SetConnectAttemptCallback(GTI2Socket *socket, void *connectAttemptCallback);
void *gti2CreateConnectionObject(void);
int gti2NewSocketConnection(GTI2Socket *socket, GTI2Connection **connection, unsigned int ip, unsigned short port);
void gti2FreeSocketConnection(GTI2Connection *connection);
int gti2SocketSend(GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len);
int gti2SocketConnectionsThink(GTI2Socket *socket);
void gti2FreeClosedConnections(GTI2Socket *socket);
void gti2SocketError(GTI2Socket *socket);
/* END mkheaders: generated region */

#endif
