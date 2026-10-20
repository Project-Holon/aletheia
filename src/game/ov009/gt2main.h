#ifndef GAME_OV009_GT2MAIN_H
#define GAME_OV009_GT2MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2main.c, prototypes copied from their definitions. */

struct GTI2Socket;

#include "../ov009/gt2main_types.h"
#include "../types.h"

int gt2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback);
void gt2CloseSocket(void *p);
void gt2Think(struct GTI2Socket *socket);
void gt2Listen(GTI2Socket *socket, void *connectAttemptCallback);
int gt2Accept(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);
void gt2Reject(GTI2Connection *connection, unsigned char *message, int len);
int gt2Connect(void *socket, GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking);
int gt2Send(void *connection, unsigned char *message, int len, int reliable);
void gt2CloseConnectionHard(int a);
void gt2CloseAllConnectionsHard(GTI2Socket *socket);
int gt2GetConnectionState(const int *p);
unsigned int gt2GetRemoteIP(const GTI2Connection *connection);
unsigned short gt2GetRemotePort(const GTI2Connection *connection);
unsigned int gt2GetLocalIP(const GTI2Socket *socket);
unsigned short gt2GetLocalPort(const GTI2Socket *socket);
int gt2GetOutgoingBufferSize(const GTI2Connection *connection);
int gt2GetOutgoingBufferFreeSpace(const int *p);
int gt2GetSocketSOCKET(const GTI2Socket *socket);
void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, void *callback);
void gt2SetConnectionData(GTI2Connection *connection, void *data);
void *gt2GetConnectionData(const GTI2Connection *connection);
/* END mkheaders: generated region */

#endif
