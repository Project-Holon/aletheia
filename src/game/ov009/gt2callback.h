#ifndef GAME_OV009_GT2CALLBACK_H
#define GAME_OV009_GT2CALLBACK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2callback.c, prototypes copied from their definitions. */

#include "../ov009/gt2main_types.h"

int gti2SocketErrorCallback(GTI2Socket *socket);
int gti2ConnectAttemptCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len);
int gti2ConnectedCallback(GTI2Connection *c, int result, unsigned char *msg, int len);
int gti2ReceivedCallback(GTI2Connection *c, unsigned char *msg, int len, int reliable);
int gti2ClosedCallback(GTI2Connection *connection, int reason);
int gti2PingCallback(GTI2Connection *c, int latency);
int gti2SendFilterCallback(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable);
int gti2ReceiveFilterCallback(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable);
int gti2DumpCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int reset, unsigned char *msg, int len, int send);
int gti2UnrecognizedMessageCallback(GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len, int *handled);
/* END mkheaders: generated region */

#endif
