#ifndef GAME_OV009_GP_H
#define GAME_OV009_GP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gp.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
void gpDestroy(int **p);
int gpProcess(void **connection);
int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
int gpConnectPreAuthenticatedA(void **connection, char *authtoken, char *partnerchallenge, int firewall, int blocking, void (*callback)(void **, void *, void *), void *param);
void gpDisconnect(void **connection);
int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int blocking, GPCallback callback, void *param);
int gpGetInfo(void **connection, int profile, int checkCache, int blocking, GPCallback callback, void *param);
int gpSetInfosA(void **connection, int info, char *value);
int gpSendBuddyRequestA(void **connection, int profile, char *reason);
int gpAuthBuddyRequest(void **connection, int profile);
int gpDenyBuddyRequest(void **connection, int profile);
int gpGetNumBuddies(void **connection, int *numBuddies);
int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
int gpGetBuddyIndex(void **connection, int profile, int *index);
int gpIsBuddy(void **connection, int profile);
int gpDeleteBuddy(void **connection, int profile);
int gpSetStatusA(GPConnection *connection, int status, const char *statusString, const char *locationString);
int gpSendBuddyMessageA(void **connection, int profile, char *message);
int gpGetReversBuddiesList(void **connection, int *targets, int numOfTargets, int blocking, GPCallback callback, void *param);
int gpGetLoginTicket(void **connection, char *loginTicket);
/* END mkheaders: generated region */

#endif
