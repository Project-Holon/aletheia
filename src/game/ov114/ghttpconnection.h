#ifndef GAME_OV114_GHTTPCONNECTION_H
#define GAME_OV114_GHTTPCONNECTION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpconnection.c, prototypes copied from their definitions. */

#include "../ov114/ghttp_types.h"

int ghiFindFreeSlot(void);
GHIConnection *ghiNewConnection(void);
int ghiCloseConnection(GHIConnection *connection);
int ghiFreeConnectionData(GHIConnection *connection);
int ghiFreeConnection(GHIConnection *connection);
GHIConnection *ghiRequestToConnection(int request);
void ghiEnumConnections(int (*callback)(GHIConnection *));
void ghiRedirectConnection(GHIConnection *connection);
void ghiCleanupConnections(void);
char *ghiGetServerAddressFromUrl(char *serverUrl);
/* END mkheaders: generated region */

#endif
