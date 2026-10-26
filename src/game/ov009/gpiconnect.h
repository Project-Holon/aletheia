#ifndef GAME_OV009_GPICONNECT_H
#define GAME_OV009_GPICONNECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpiconnect.c, prototypes copied from their definitions. */

struct GPIConnectData;
typedef struct GPIConnectData GPIConnectData;

#include "../ov009/gpi_types.h"

void randomString(char *buffer, int numChars);
int gpiStartConnect(void **connection, GPIOperation *operation);
int gpiConnect(void **connection, char *nick, char *uniquenick, char *email, char *password, char *authtoken, char *partnerchallenge, char *cdkey, int firewall, int newuser, int blocking, void (*callback)(void **, void *, void *), void *param);
int gpiSendLogin(void **connection, GPIConnectData *data);
int gpiSendNewuser(void **connection, GPIConnectData *data);
int gpiProcessConnect(void **connection, GPIOperation *operation, char *input);
int gpiCheckConnect(void **connection);
int gpiDisconnectCleanupProfile(void * connectionArg, GPIProfile * profile, void * unused2);
void gpiDisconnect(void **connection, int tellServer);
int gpiProcessRemoteAuthResponse(void **connection, char *input);
/* END mkheaders: generated region */

#endif
