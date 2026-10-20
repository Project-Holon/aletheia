#ifndef GAME_OV009_GT2MESSAGE_H
#define GAME_OV009_GT2MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2message.c, prototypes copied from their definitions. */

struct GTI2IncomingBufferMessage;

#include "../types.h"
#include "../ov009/gt2main_types.h"

unsigned short gti2UShortFromBuffer(unsigned char *buffer, int pos);
void gti2UShortToBuffer(char *p, int i, int v);
s16 gti2SNDiff(unsigned short a, unsigned short b);
int gti2ConnectionError(GTI2Connection *connection, GT2Result result, GT2CloseReason reason);
int gti2ConnectionCommunicationError(GTI2Connection *connection);
int gti2ConnectionMemoryError(GTI2Connection *connection);
int gti2HandleESN(GTI2Connection *connection, unsigned short ESN);
int gti2HandleAppUnreliable(GTI2Connection *c, unsigned char *msg, int len);
int gti2HandleAppReliable(GTI2Connection *c, unsigned char *message, int len);
int gti2HandleClientChallenge(GTI2Connection *c, unsigned char *message, int len);
int gti2HandleServerChallenge(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandleClientResponse(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandleAccept(GTI2Connection *connection);
int gti2HandleReject(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandleClose(GTI2Connection *connection);
int gti2DeliverReliableMessage(GTI2Connection *connection, int type, unsigned char *message, int len);
int gti2IncomingBufferMessageCompare(void *elem1, void *elem2);
int gti2BufferIncomingMessage(GTI2Connection *connection, int type, unsigned short SN, unsigned char *message, int len, int *overflow);
void gti2RemoveHoldMessage(GTI2Connection *c, struct GTI2IncomingBufferMessage *message, int index);
int gti2DeliverHoldMessages(GTI2Connection *c);
void gti2SetPendingAck(GTI2Connection *connection);
int gti2HandleReliableMessage(GTI2Connection *connection, int type, unsigned char *message, int len);
int gti2HandleAck(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandleNack(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandlePing(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandlePong(GTI2Connection *c, unsigned char *message, int len);
int gti2HandleUnreliableMessage(GTI2Connection *c, int type, unsigned char *message, int len);
int gti2HandleMessage(GTI2Socket *socket, unsigned char *message, int len, unsigned int ip, unsigned short port);
int gti2HandleConnectionReset(GTI2Socket *socket, u32 ip, u16 port);
int gti2HandleHostUnreachable(GTI2Socket *sock, unsigned int ip, unsigned short port, int send);
int gti2ReceiveMessages(GTI2Socket *socket);
int gti2SendAppReliable(GTI2Connection * connection, unsigned char * message, int len);
int gti2SendClientChallenge(GTI2Connection * connection, char * challenge);
int gti2SendServerChallenge(GTI2Connection *c, char *response, char *challenge);
int gti2SendClientResponse(GTI2Connection *c, char *response, char *message, int len);
int gti2SendAccept(GTI2Connection *connection);
int gti2SendReject(GTI2Connection *connection, unsigned char *message, int len);
int gti2SendClose(GTI2Connection *connection);
int gti2SendKeepAlive(GTI2Connection *connection);
int gti2SendAppUnreliable(GTI2Connection *connection, u8 *message, int len);
int gti2SendAck(GTI2Connection *connection);
int gti2SendNack(GTI2Connection *connection, unsigned short SNMin, unsigned short SNMax);
int gti2SendPong(GTI2Connection *connection, unsigned char *message, int len);
int gti2SendClosed(int *p);
int gti2SendClosedOnSocket(GTI2Socket *sock, unsigned int ip, unsigned short port);
int gti2ResendMessage(GTI2Connection *connection, GTI2OutgoingBufferMessage *message);
int gti2Send(GTI2Connection *a, unsigned char *b, int c, int d);
/* END mkheaders: generated region */

#endif
