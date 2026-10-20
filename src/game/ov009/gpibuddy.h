#ifndef GAME_OV009_GPIBUDDY_H
#define GAME_OV009_GPIBUDDY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpibuddy.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiSendAuthBuddyRequest(void **connection, GPIProfile *profile);
int gpiProcessRecvBuddyList(void **connection, char *input);
int gpiSendServerBuddyMessage(void **connection, int profileid, int type, char *message);
int gpiSendBuddyMessage(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp);
int gpiBuddyHandleKeyRequest(void **connection, GPIPeer *peer);
int gpiBuddyHandleKeyReply(void **connection, GPIPeer *peer, char *buffer);
int gpiAuthBuddyRequest(void **connection, int profile);
int gpiFixBuddyIndices(int unused, GPIProfile *profile, int baseIndex);
int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest);
int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
/* END mkheaders: generated region */

#endif
