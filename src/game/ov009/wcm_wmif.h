#ifndef GAME_OV009_WCM_WMIF_H
#define GAME_OV009_WCM_WMIF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wcm_wmif.c, prototypes copied from their definitions. */

long WCMi_WmifStartupAsync(void);
long WCMi_WmifCleanupAsync(void);
long WCMi_WmifBeginSearchAsync(void *bssid, void *essid, unsigned long option);
long WCMi_WmifConnectAsync(void);
long WCMi_WmifDisconnectAsync(void);
long WCMi_WmifTerminateAsync(void);
long WCMi_WmifSetDCFData(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long));
unsigned short WCMi_WmifGetAllowedChannel(void);
void WcmWmcbDisconnect(void *arg);
void WcmWmcbStartDCF(void *arg);
void WcmWmcbEndDCF(void *arg);
/* END mkheaders: generated region */

#endif
