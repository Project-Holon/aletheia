#ifndef GAME_OV009_DWC_NETCHECK_H
#define GAME_OV009_DWC_NETCHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_netcheck.c, prototypes copied from their definitions. */

#include "../sdk_dwc.h"

int DWC_Netcheck_Create(DWCNetcheckParam *param);
void DWC_Netcheck_Destroy(void);
void DWC_Netcheck_Abort(void);
int DWC_Netcheck_GetError(void);
int DWC_Netcheck_GetReturnCode(void);
void DWCi_Netcheck_StartThread(void);
void DWCi_Netcheck_SetError(int error);
/* END mkheaders: generated region */

#endif
