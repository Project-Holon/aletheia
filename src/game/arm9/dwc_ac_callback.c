/*
 * file:     dwc_ac_callback.c
 * function: DWCi_AC_CallBackWCM
 * address:  0x0205B148
 * packet:   pkt_0205B148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_CallBackWCM (callback.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   DWCi_AC_GetBeacon 0x0205A938 arm
 */

#include "../sdk_wm.h"

typedef struct ACWORK {
    unsigned char pad[0x14C4];
    unsigned char wcmResult;
} ACWORK;

#include "dwc_ac.h"
#include "dwc_ac_beacon.h"

void DWCi_AC_CallBackWCM(WCMNotice *notice)
{
    ACWORK *wk;

    wk = DWCi_AC_GetMemPtr(0x10);
    if (notice->notify == 5) {
        if (notice->result == 0)
            return;
        switch (notice->parameter[1].n) {
        case 0xD:
            wk->wcmResult = 1;
            break;
        case 0xF:
            wk->wcmResult = 2;
            break;
        case 0x11:
            wk->wcmResult = 3;
            break;
        default:
            wk->wcmResult = 4;
            break;
        }
    } else if (notice->notify == 7) {
        DWCi_AC_GetBeacon((WMBssDesc *)notice->parameter[0].p);
    }
}
