#ifndef GAME_ARM9_DWC_AC_H
#define GAME_ARM9_DWC_AC_H

#include "../types.h"

/* Auto-connect configuration. The callbacks use long, as the DWC headers do. */

typedef void *(*ACAllocFunc)(unsigned long name, long size);
typedef void (*ACFreeFunc)(unsigned long name, void *ptr, long size);

typedef struct tagDWCACOption
{
    u8 connectType;
    u8 skipNetCheck : 4;
    u8 useDSWireless : 4;
} DWCACOption;

typedef struct tagDWCACConfig
{
    ACAllocFunc alloc;
    ACFreeFunc free;
    u8 dmaNo;
    u8 powerMode;
    DWCACOption option;
    long rwin;
    u8 wontExecuteEULACheck;
} DWCACConfig;

#include "../sdk_ncfg.h"
BOOL DWC_AC_Create(DWCACConfig *config);
int DWC_AC_Process(void);
int DWC_AC_GetStatus(void);
u8 DWC_AC_GetApType(void);
BOOL DWC_AC_GetApSpotInfo(u8 *apSpotInfo);
unsigned int DWC_AC_GetSecuritySetting(void);
BOOL DWC_AC_Destroy(void);
void DWC_AC_SetSpecifyApEx(void *ssid, void *wep, int wepMode, u16 mtu, char *apSpotInfo, int overrideType);
void DWC_AC_SetSpecifyAp(void *ssid, void *wep, int wepMode);
int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len);
void DWCi_AC_InsertApInfo(int no, NCFGApInfo *info);
void DWCi_AC_InvalidatePriorityWPA(void);
void *DWCi_AC_Alloc(u32 name, s32 size);
void DWCi_AC_Free(u32 name, void *ptr, s32 size);
void DWCi_AC_FreeAll(void);
void *DWCi_AC_GetMemPtr(u32 name);
void DWCi_AC_SetPhase(u8 phase);
unsigned char DWCi_AC_GetPhase(void);
void DWCi_AC_SetError(int error);
int DWCi_AC_GetError(void);
void DWCi_AC_SetApType(u8 type);
void DWCi_AC_CopyExSetting(u8 type);
u8 DWCi_ConvConnectAPType(u8 type);
void Free_Disused(void);
BOOL CheckDuplicate(void);
BOOL CheckEULA(void);
BOOL CheckWirelessPowerON(void);

#endif
