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
int WCMi_NwmifBeginSearchAsync(u32 bssid, u32 essid, u32 option);
u32 WCMi_NwmifConnectAsync(void);
u32 WCMi_NwmifDisconnectAsync(void);
u32 WCMi_NwmifTerminateAsync(void);
u32 WCMi_NwmifSetDCFData(u32 destMac, u32 frame, u32 length, u32 asyncArg);
u32 WCMi_NwmifGetAllowedChannel(void);
void WcmNwmReset(void);
void WcmNwmcbCommon(u16 *arg);
void WcmNwmcbScanEx(SendPkt *p);
void WcmNwmcbConnect(u16 *arg);
void WcmNwmcbDisconnect(u16 *arg);
void WcmNwmcbSetRecvFrmBuf(Pkt *p);
void WcmNwmcbUnsetRecvFrmBuf(Pkt *p);
void WcmNwmcbSetDCFData(u16 *arg);
void WcmNwmcbSetDCFDataAsync(void *arg);
/* END mkheaders: generated region */

#endif
