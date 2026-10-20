#ifndef GAME_OV009_WCM_UTIL_H
#define GAME_OV009_WCM_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wcm_util.c, prototypes copied from their definitions. */

int WcmCompareMemory(unsigned char *a, unsigned char *b, unsigned int n);
int WCM_CompareBssID(unsigned char *a, unsigned char *b);
WMLinkLevel WCM_GetLinkLevel(void);
WMLinkLevel WCM_CalcLinkLevel(unsigned char rssi);
unsigned char WCMi_GetRssiAverage(void);
void WCMi_ShelterRssi(unsigned char rssi);
/* END mkheaders: generated region */

#endif
