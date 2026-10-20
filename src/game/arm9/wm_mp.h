#ifndef GAME_ARM9_WM_MP_H
#define GAME_ARM9_WM_MP_H

typedef struct WMMPTmpParam WMMPTmpParam;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_mp.c, prototypes copied from their definitions. */

struct WMMPTmpParam;
typedef struct WMMPTmpParam WMMPTmpParam;

#include "../sdk_wm.h"
#include "../types.h"

WMErrCode WMi_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, WMMPTmpParam *tmpParam);
WMErrCode WM_StartMPEx(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode, BOOL ignoreFatalError);
WMErrCode WM_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq);
WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
WMErrCode WM_EndMP(WMCallbackFunc callback);
/* END mkheaders: generated region */

#endif
