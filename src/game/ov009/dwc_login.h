#ifndef GAME_OV009_DWC_LOGIN_H
#define GAME_OV009_DWC_LOGIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_login.c, prototypes copied from their definitions. */

#include "../ov009/dwc_login_types.h"
#include "../arm9/dwc_account.h"
#include "../types.h"
#include "../ov009/gpi_types.h"

void DWCi_LoginInit(DWCstLoginControl *logcnt, DWCstAccUserData *userdata, void **pGpObj, int productID, u32 gamecode, u16 *playerName, void (*callback)(int, int, void *), void *param);
int DWCi_LoginAsync(void);
void DWCi_LoginProcess(void);
DWCstAccUserData *DWCi_GetUserData(void);
void DWCi_StopLogin(int error, int errorCode);
void DWCi_ShutdownLogin(void);
void DWCi_CloseLogin(void);
void DWCi_GPConnectCallback(void **pconnection, void *argp, void *unused);
void DWCi_GPConnect(GPCallback callback, int next_state);
int DWCi_RemoteLogin(void);
void DWCi_RemoteLoginProcess(void);
void DWCi_GPGetInfoCallback(void **pconnection, void *argp, void *unused);
int DWCi_CheckLogin(void);
int DWCi_GetAuthInfo(char **authToken, char **partnerChallenge);
int DWCi_GetLoginTicket(char *loginTicket);
/* END mkheaders: generated region */

#endif
