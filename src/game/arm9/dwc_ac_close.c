/*
 * file:     dwc_ac_close.c
 * unit:     yes
 * function: DWCi_AC_CloseNetwork, DisConnectAP, CloseSocket
 * address:  0x0205B1E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DisConnectAP 0x0205B264 arm
 *   DWC_Netcheck_Abort 0x0217AA20 arm
 *   DWC_Netcheck_Destroy 0x0217A950 arm
 *   WCM_GetPhase 0x021656A0 arm
 *   WCM_Finish 0x02164EE0 arm
 *   WCM_CleanupAsync 0x02165088 arm
 *   WCM_EndSearchAsync 0x02165204 arm
 *   WCM_DisconnectAsync 0x02165478 arm
 *   WCM_TerminateAsync 0x02165560 arm
 *   DWCi_AC_SetError 0x0205C2E4 arm
 *   SOCL_CalmDown   0x0215ED60  arm
 *   SOC_Cleanup     0x0215FA90  arm
 *   SOCLiConfigPtr  0x021A1CD8  data  ov009
 */
extern int DisConnectAP(void);
#include "../ov009/dwc_netcheck.h"
#include "../ov009/wcm_system.h"
#include "dwc_ac.h"
#include "../ov009/socl_cleanup.h"
#include "../ov009/soc.h"
int DWCi_AC_CloseNetwork(unsigned char *phase);
int DisConnectAP(void);
int CloseSocket(void);
extern void *SOCLiConfigPtr;


/*
 * sdk:      DWCi_AC_CloseNetwork (close.o)
 */
int DWCi_AC_CloseNetwork(unsigned char *phase)
{
    int result;

    if (*phase <= 10) {
        result = DisConnectAP();
        if (result == 1) {
            *phase = 0;
            return 1;
        } else if (result == -1) {
            *phase = 0x12;
            return 1;
        }
    } else if (*phase == 14) {
        DWC_Netcheck_Abort();
        DWC_Netcheck_Destroy();
        *phase = 12;
    } else if (*phase < 0x12) {
        if (CloseSocket() == 1)
            *phase = 10;
    }
    return 0;
}


int DisConnectAP(void)
{
    switch (WCM_GetPhase()) {
    case 0:
        return 1;
    case 1:
        WCM_Finish();
        break;
    case 3:
        WCM_CleanupAsync();
        break;
    case 6:
        WCM_EndSearchAsync();
        break;
    case 9:
        WCM_DisconnectAsync();
        break;
    case 12:
        WCM_TerminateAsync();
        break;
    case 11:
        DWCi_AC_SetError(0);
        return -1;
    }
    return 0;
}


/*
 * sdk:      CloseSocket (libdwcac.TWL.HYB.a close.o, static)
 */
int CloseSocket(void)
{
    int result;

    if (SOCLiConfigPtr == 0)
        return 1;
    if (SOCL_CalmDown() != 0)
        return 0;
    result = SOC_Cleanup();
    if (result == 0 || result == -39)
        return 1;
    return 0;
}
