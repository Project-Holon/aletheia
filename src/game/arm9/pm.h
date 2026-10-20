#ifndef GAME_ARM9_PM_H
#define GAME_ARM9_PM_H

#include "../types.h"

/* Power management: sleep callback list entry. */

typedef struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
} PMGenCallbackInfo;

struct PMiGenCallbackInfo;
void PMi_WaitBusy(void);
void PMi_DummyCallback(u32 result, void *arg);
void PMi_CallCallbackAndUnlock(u32 result);
void PMi_WaitVBlank(void);
void PM_Init(void);
void PMi_CommonCallback(int tag, u32 data, BOOL err);
void PMi_TryToSendPxiDataTillSuccess(u32 *sendData, int num);
u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData);
u32 PM_SendUtilityCommand(u32 number, u16 parameter, u16 *retValue);
u32 PMi_SetLED(int status);
u32 PM_SetBackLight(int target, int sw);
u32 PMi_ForceToPowerOff(void);
u32 PM_ForceToPowerOff(void);
unsigned int PM_SetAmp(unsigned int status);
unsigned int PMi_SetAmp(unsigned int status);
unsigned int PM_SetAmpGain(unsigned int gain);
unsigned int PM_SetAmpGainLevel(u8 level);
u32 PM_GetBattery(int *batteryBuf);
unsigned int PM_GetBatteryLevel(void *isConnectedBuf);
u32 PM_GetBackLight(int *top, int *bottom);
u32 PM_GetAmp(int *swBuf);
void PMi_SendPxiData(u32 data);
void PMi_PreSleepForDma(void);
void PM_GoSleepMode(u32 trigger, u32 logic, u16 keyPattern);
BOOL PMi_SetLCDPower(int sw, int led, BOOL skip, BOOL isSync);
BOOL PM_SetLCDPower(int sw);
int PM_GetLCDPower(void);
unsigned int PMi_SendLEDPatternCommand(unsigned int pattern);
u32 PM_GetLEDPattern(int *patternBuf);
void PMi_InsertList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info, int priority, int method);
void PMi_DeleteList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info);
void PMi_ExecuteList(PMGenCallbackInfo *listp);
void PM_PrependPreSleepCallback(void *info);
void PM_AppendPostSleepCallback(void *info);
void PMi_InsertPreSleepCallbackEx(struct PMiGenCallbackInfo *info, int priority);
void PM_DeletePreSleepCallback(PMGenCallbackInfo *info);
void PM_DeletePostSleepCallback(PMGenCallbackInfo *info);
void PMi_LCDOnAvoidReset(void);
void PMi_SetDispOffCount(void);

#endif
