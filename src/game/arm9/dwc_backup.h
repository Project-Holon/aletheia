#ifndef GAME_ARM9_DWC_BACKUP_H
#define GAME_ARM9_DWC_BACKUP_H

#include "../sdk_ncfg.h"

typedef struct tagDWCMemMap {
    NCFGSlotInfo page[4];
} DWCMemMap;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_backup.c, prototypes copied from their definitions. */

#include "../sdk_dwc.h"
#include "../sdk_ncfg.h"
#include "../types.h"

int DWCi_BM_GetApInfo(void *buf);
int DWCi_BM_GetApInfoEx(void *buf);
void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
int ReadSlotInfo(NCFGSlotInfo *buf, int offset, u32 num);
int WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work);
int ReadSlotInfoEx(NCFGSlotInfoEx *buf, int offset, u32 num);
int DWCi_BM_SetWiFiInfo(DWCWiFiInfo *info, void *work);
int DWCi_BACKUPlRead(void *mem);
int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work);
void DWCi_BACKUPlSetWiFi(unsigned char *wifi);
u8 DWCi_BACKUPlConvMaskCidr(u8 *mask);
void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf);
int DWC_BACKUPlCheckIp(u8 *ip, u8 *mask);
int DWC_BACKUPlCheckAddress(unsigned char *address);
int writeDisable(void);
u8 *DWCi_BACKUPlConvWifiInfo(const DWCWiFiInfo *info);
void *DWCi_BACKUPlGetWifi(void);
/* END mkheaders: generated region */

#endif
