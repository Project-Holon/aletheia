#ifndef GAME_OV009_DWC_SVL_H
#define GAME_OV009_DWC_SVL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_svl.c, prototypes copied from their definitions. */

#include "../sdk_dwc.h"

void DWC_Svl_Cleanup(void);
int DWC_Svl_GetTokenAsync(char *svc, DWCSvlResult *result);
int DWC_Svl_Process(void);
int DWCi_Svl_ParseHttp(void);
/* END mkheaders: generated region */

#endif
