#ifndef GAME_OV009_WCM_CPSIF_H
#define GAME_OV009_WCM_CPSIF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wcm_cpsif.c, prototypes copied from their definitions. */

#include "../sdk_os.h"

void WCMi_InitCpsif(void);
void WCMi_CpsifRecvCallback(unsigned char *s, unsigned char *d, unsigned char *dat, long len);
void *WCMi_GetCpsifWork(void);
unsigned char *WCM_GetApMacAddress(void);
unsigned char *WCM_GetApEssid(unsigned short *length);
void WCM_SetRecvDCFCallback(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
long WCM_SendDCFDataEx(unsigned char *dstAddr, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);
void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex);
void WCMi_CpsifSetMacAddress(void *mac);
void WCM_GetMacAddress(unsigned char *a);
unsigned long WCMi_MergeToBuffer(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen);
/* END mkheaders: generated region */

#endif
