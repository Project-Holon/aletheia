#ifndef GAME_ARM9_WM_SYSTEM_H
#define GAME_ARM9_WM_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_system.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_wm.h"

WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo);
WMErrCode WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize);
WMErrCode WM_Finish(void);
void WMi_SetCallbackTable(int id, WMCallbackFunc callback);
u32 *WmGetCommandBuffer4Arm7(void);
WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...);
WMErrCode WMi_SendCommandDirect(void *data, u32 length);
WMArm9Buf *WMi_GetSystemWork(void);
WMErrCode WMi_CheckInitialized(void);
WMErrCode WMi_CheckIdle(void);
WMErrCode WMi_CheckStateEx(s32 paramNum, ...);
void WmReceiveFifo(int tag, u32 fifo_buf_adr, BOOL err);
void WmClearFifoRecvFlag(void);
WMStatus *WMi_GetStatusAddress(void);
u16 WM_GetAID(void);
u16 WM_GetConnectedAIDs(void);
void WMi_RegisterSleepCallback(void);
void WMi_DeleteSleepCallback(void);
void WmSleepCallback(void *arg);
BOOL WMi_CheckEnableFlag(void);
/* END mkheaders: generated region */

#endif
