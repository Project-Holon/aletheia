#ifndef GAME_OV014_WIH_H
#define GAME_OV014_WIH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wih.c, prototypes copied from their definitions. */

struct WihPortSendCallback;
struct WihPortRecvCallback;
struct WihMeasureChannelCallback;
typedef struct WihPortSendCallback WihPortSendCallback;
typedef struct WihPortRecvCallback WihPortRecvCallback;
typedef struct WihMeasureChannelCallback WihMeasureChannelCallback;

#include "../sdk_wm.h"
#include "../types.h"

void WIH_ChangeSysState(int state);
void WIH_SetError(int error);
int WIH_StateInSetParentParam(void);
int WIH_StateInStartParent(void);
void WIH_StateOutStartParent(WMStartParentCallback *arg);
BOOL WIH_StateInStartParentMP(void);
void WIH_StateOutStartParentMP(WMStartMPCallback *arg);
int WIH_StateInEndParentMP(void);
int DWCi_MOV_WH_StateInEndParent(void);
int DWCi_MOV_WH_ChildConnectAuto(u32 mode, const u16 *macAddr, u32 channel);
int DWCi_MOV_WH_StartScan(u32 judgeScanFunc, u16 *macAddr, u32 channel);
BOOL DWCi_MOV_WH_StateInStartScan(void);
void WIH_SetScanTarget(u16 channel, void *macAddr);
int WIH_IsMatchingParent(WMBssDesc *bssDesc);
void DWCi_MOV_WH_StateOutStartScan(void *arg);
int DWCi_MOV_WH_EndScan(void);
int DWCi_MOV_WH_StateInStartChild(void);
void DWCi_MOV_WH_StateOutStartChild(WMStartConnectCallback *arg);
BOOL DWCi_MOV_WH_StateInStartChildMP(void);
void DWCi_MOV_WH_StateOutStartChildMP(WMStartMPCallback *arg);
int WIH_StateInEndChildMP(void);
int WIH_StateInEndChild(void);
int WIH_StateInReset(void);
int DWCi_MOV_WH_StateInSetMPData(u32 data, u16 size, u32 userCallback);
void WIH_StateOutSetMPData(WihPortSendCallback *arg);
void DWCi_MOV_WH_PortReceiveCallback(WihPortRecvCallback *arg);
void WIH_SetGgid(u32 ggid);
void DWCi_MOV_WH_SetUserGameInfo(void *userGameInfo, unsigned short length);
u16 WIH_GetBitmap(void);
int WIH_GetSysState(void);
int DWCi_MOV_WH_GetLastError(void);
int WIH_StartMeasureChannel(void);
int WIH_StateInMeasureChannel(u16 channel);
void WIH_StateOutMeasureChannel(const WihMeasureChannelCallback *arg);
int WHi_MeasureChannel(void *callback, unsigned short channel);
u16 WIH_FinishMeasureChannel(void);
int WIH_PickRandomChannel(u16 channelBitmap);
BOOL WIH_Initialize(u32 heapId, int unused, int listening);
void WIH_FreeWork(void);
BOOL WIH_StateInInitialize(int unused, int listening);
void DWCi_MOV_WH_StateOutSetLifeTime(void);
BOOL WIH_ParentConnect(int mode, u16 tgid, int channel, u16 maxEntry);
void WIH_SetJudgeAcceptFunc(void *judgeAcceptFunc);
void DWCi_MOV_WH_SetReceiver(void *recvCallback);
BOOL DWCi_MOV_WH_SendData(int data, u16 size, int userCallback);
int WIH_GetSharedDataAdr(u16 aid);
BOOL WIH_StepDS(int sendData);
void WIH_UpdateScanTimer(void);
void DWCi_MOV_WH_StateInEndKeyShare(void);
BOOL WIH_Finalize(void);
int WIH_End(void (*callback)(int));
unsigned short WIH_GetOwnAid(void);
void WIH_SetJudgeScanFunc(unsigned judgeScanFunc);
void WIH_SetBeaconGameInfo(int userGameInfo, int size, int ggid, int tgid);
unsigned short WIH_GetBeaconSendCount(void);
void WIH_SetConnectCallback(unsigned connectCallback);
void WIH_SetBeaconFoundCallback(u32 beaconFoundCallback);
void WIH_SetScanWaitFrames(u16 scanWaitFrames);
void WIH_SetScanTimerPaused(unsigned char paused);
/* END mkheaders: generated region */

#endif
