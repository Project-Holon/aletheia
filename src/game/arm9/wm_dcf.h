#ifndef GAME_ARM9_WM_DCF_H
#define GAME_ARM9_WM_DCF_H

/* Public functions of wm_dcf.c, prototypes copied from their definitions. */

struct WMDcfRecvBuf;

#include "../sdk_wm.h"
#include "../types.h"

WMErrCode WM_StartDCF(WMCallbackFunc callback, struct WMDcfRecvBuf *recvBuf, u16 recvBufSize);
WMErrCode WM_SetDCFData(WMCallbackFunc callback, const u8 *destAdr, const u16 *sendData, u16 sendDataSize);
WMErrCode WM_EndDCF(WMCallbackFunc callback);

#endif
