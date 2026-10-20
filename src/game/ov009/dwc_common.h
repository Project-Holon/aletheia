#ifndef GAME_OV009_DWC_COMMON_H
#define GAME_OV009_DWC_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_common.c, prototypes copied from their definitions. */

#include "../types.h"

int DWC_SetCommonKeyValueString(const char *key, const char *value, char *string, char sep);
int DWC_AddCommonKeyValueString(const char *key, const char *value, char *string, char sep);
int DWC_GetCommonValueString(char *key, char *value, char *string, char separator);
u32 DWCi_GetMathRand32(u32 max);
int DWCi_WStrLen(unsigned short *p);
/* END mkheaders: generated region */

#endif
