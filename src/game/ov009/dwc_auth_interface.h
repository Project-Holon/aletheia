#ifndef GAME_OV009_DWC_AUTH_INTERFACE_H
#define GAME_OV009_DWC_AUTH_INTERFACE_H

#include "../sdk_dwc.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_auth_interface.c, prototypes copied from their definitions. */

int DWCi_Auth_InitInterface(int authServer);
void DWCi_Auth_InitAdapterParam(void);
int DWCi_Auth_StartAuthentication(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, DWCAuthAlloc allocator, DWCAuthFree deallocator);
void DWCi_Auth_AbortAuthentication(void);
void DWCi_Auth_ProcessAuthentication(void);
int DWCi_Auth_IsFinished(void);
int DWCi_Auth_IsSucceeded(void);
int DWCi_Auth_GetErrorCode(void);
void DWCi_Auth_GetGameSpyToken(char *authtoken, char *partnerchallenge);
void DWCi_Auth_ShutdownAuthentication(void);
unsigned long long DWCi_Auth_GetConsoleUserId(void);
int DWCi_Auth_IsConsoleUserIdAuthentic(void);
/* END mkheaders: generated region */

#endif
