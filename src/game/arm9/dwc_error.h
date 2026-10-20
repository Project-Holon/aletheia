#ifndef GAME_ARM9_DWC_ERROR_H
#define GAME_ARM9_DWC_ERROR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_error.c, prototypes copied from their definitions. */

int DWC_GetLastError(int *errorCode);
int DWC_GetLastErrorEx(int *errorCode, int *errorType);
void DWC_ClearError(void);
int DWCi_IsError(void);
void DWCi_SetError(int error, int errorCode);
/* END mkheaders: generated region */

#endif
