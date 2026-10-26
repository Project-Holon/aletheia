#ifndef GAME_TWL_NWMIF_H
#define GAME_TWL_NWMIF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nwmif.c, prototypes copied from their definitions. */

struct SendPkt;
struct Pkt;
typedef struct SendPkt SendPkt;
typedef struct Pkt Pkt;

#include "../types.h"

u32 WCMi_NwmifStartupAsync(void);
u32 WCMi_NwmifCleanupAsync(void);
int WCMi_NwmifBeginSearchAsync(u8 *bssid, u8 *essid, u32 option);
u32 WCMi_NwmifConnectAsync(void);
u32 WCMi_NwmifDisconnectAsync(void);
u32 WCMi_NwmifTerminateAsync(void);
u32 WCMi_NwmifSetDCFData(u8 *destMac, u8 *frame, u32 length, u32 asyncArg);
u32 WCMi_NwmifGetAllowedChannel(void);
void WcmNwmReset(void);
void WcmNwmcbCommon(void *argp);
void WcmNwmcbScanEx(void *arg);
void WcmNwmcbConnect(void *argp);
void WcmNwmcbDisconnect(void *argp);
void WcmNwmcbSetRecvFrmBuf(void *arg);
void WcmNwmcbUnsetRecvFrmBuf(void *arg);
void WcmNwmcbSetDCFData(void *argp);
void WcmNwmcbSetDCFDataAsync(void *arg);
/* END mkheaders: generated region */

#endif
