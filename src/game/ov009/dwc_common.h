#ifndef GAME_OV009_DWC_COMMON_H
#define GAME_OV009_DWC_COMMON_H

/* Public functions of dwc_common.c, prototypes copied from their definitions. */

int DWC_SetCommonKeyValueString(const char *key, const char *value, char *string, char sep);
int DWC_AddCommonKeyValueString(const char *key, const char *value, char *string, char sep);
int DWC_GetCommonValueString(char *key, char *value, char *string, char separator);
u32 DWCi_GetMathRand32(u32 max);
int DWCi_WStrLen(unsigned short *p);

#endif
