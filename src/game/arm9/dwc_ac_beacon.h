#ifndef GAME_ARM9_DWC_AC_BEACON_H
#define GAME_ARM9_DWC_AC_BEACON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_ac_beacon.c, prototypes copied from their definitions. */

#include "../sdk_wm.h"

void DWCi_AC_GetBeacon(WMBssDesc *bssdesc);
int DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc);
int DWCi_AC_IsSupportWPA(WMBssDesc *bssDesc);
/* END mkheaders: generated region */

#endif
