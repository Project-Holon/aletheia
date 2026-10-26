#ifndef GAME_ARM9_WIH_DWC_H
#define GAME_ARM9_WIH_DWC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wih_dwc.c, prototypes copied from their definitions. */

struct WihContext;

#include "../sdk_wm.h"
#include "../types.h"

int WIH_DWC_PollSystem(void);
struct WihContext *WIH_DWC_Create(int maxBeacons, u32 heapId);
void WIH_DWC_Delete(struct WihContext *context);
void WIH_DWC_PauseTimers(void);
void WIH_DWC_ResumeTimers(void);
void WIH_DWC_AddBeacon(void *beacon, void *userArg, u16 linkLevel);
void WIH_DWC_TickTimers(void);
int WIH_DWC_IsSsidInFilterList(WMBssDesc *beacon);
int WIH_DWC_IsOpenTaggedBeacon(const WMBssDesc *beacon);
u32 WIH_DWC_IsPrivacyBeacon(const WMBssDesc *beacon);
u32 WIH_DWC_PollStatus(void *searchKey);
void WIH_DWC_CreateFilterBuffer(u32 heapId);
void WIH_DWC_ResetFilterState(void);
int WIH_DWC_FindSlotByKey(void *searchKey);
u16 WIH_DWC_GetAlertLevel(void);
void WIH_DWC_RequestAlertLevel(u32 level);
void WIH_DWC_Dummy(void);
/* END mkheaders: generated region */

#endif
