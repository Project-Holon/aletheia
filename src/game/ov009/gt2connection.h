#ifndef GAME_OV009_GT2CONNECTION_H
#define GAME_OV009_GT2CONNECTION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2connection.c, prototypes copied from their definitions. */

struct GTI2Socket;
struct GTI2Connection;
struct GT2ConnectionCallbacks;

int gti2NewOutgoingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int gti2NewIncomingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int gti2StartConnectionAttempt(struct GTI2Connection *c, unsigned char *message, int len, struct GT2ConnectionCallbacks *callbacks);
int gti2AcceptConnection(struct GTI2Connection *connection, struct GT2ConnectionCallbacks *callbacks);
void gti2RejectConnection(struct GTI2Connection *connection, unsigned char *message, int len);
int gti2ConnectionSendData(struct GTI2Connection *connection, unsigned char *message, int len);
int gti2CheckTimeout(struct GTI2Connection *c, unsigned int now);
int gti2ConnectionThink(struct GTI2Connection *connection, unsigned int now);
void gti2CloseConnection(struct GTI2Connection *connection, int hard);
void gti2ConnectionClosed(struct GTI2Connection *connection);
void gti2ConnectionCleanup(struct GTI2Connection *c);
/* END mkheaders: generated region */

#endif
