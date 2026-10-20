#ifndef GAME_ARM9_DWC_AC_NINTENDOSPOT_H
#define GAME_ARM9_DWC_AC_NINTENDOSPOT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_ac_nintendospot.c, prototypes copied from their definitions. */

struct tagDWCWDSData;
typedef struct tagDWCWDSData DWCWDSData;

#include "../types.h"

BOOL DWC_AC_StartupGetWDSInfo(DWCWDSData *nspotInfo, u16 dmaNo);
int DWC_AC_ProcessGetWDSInfo(void);
void DWC_AC_CancelGetWDSInfo(void);
void DWC_AC_CleanupGetWDSInfo(void);
void WDS_Initialize_CB(void);
void WDS_StartScan_CB(void);
void WDS_EndScan_CB(void);
void WDS_End_CB(void);
void WDS_Error_End_CB(void);
/* END mkheaders: generated region */

typedef struct tagDWCWDSData DWCWDSData;

#endif
