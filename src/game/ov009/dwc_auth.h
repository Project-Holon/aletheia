#ifndef GAME_OV009_DWC_AUTH_H
#define GAME_OV009_DWC_AUTH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_auth.c, prototypes copied from their definitions. */

#include "../sdk_dwc.h"
#include "../ov009/dwc_http_types.h"

void DWC_Auth_SetCustomNas(char *v);
char *DWC_Auth_GetCustomNas(void);
int DWC_Auth_Create(DWCAuthParam *param, DWCHttp *http);
void DWCi_Auth_StartThread(void);
void DWC_Auth_Abort(void);
void DWC_Auth_Destroy(void);
void DWC_Auth_Join(void);
int DWC_Auth_GetError(void);
void DWC_Auth_GetResult(int *result);
int DWCi_Auth_Start(int getwifiinfofromflash);
void DWCi_Auth_Thread(void *arg);
int DWCi_Auth_ParseHttp(void);
int DWCi_Auth_FillResult(void);
int DWCi_Auth_Prepare_FirstPost(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn);
void DWCi_Auth_SetError(int error);
/* END mkheaders: generated region */

#endif
