/*
 * function: func_0205C88C
 * address:  0x0205C88C
 * packet:   pkt_0205C88C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckInet (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_GetInetStatus 0x0205CA20 arm
 *   g_02146AD4 0x02146AD4 data
 */

#include "../include/G_INETBSS.h"

typedef struct {
    int ac_state;
    unsigned short state;
    unsigned short online;
    unsigned short dmaNo;
    unsigned short powerMode;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned char wontExecuteWDS;
    int processWDSstate;
} DWCstInetControl;

/* dwc_connectinet.o .bss: stateOld (DWC_GetInetStatus static) then stpInetCntl */
typedef struct {
    int stateOld;
    DWCstInetControl *stpInetCntl;
} INETBSS;

extern struct INETBSS g_02146AD4;

extern int DWC_GetInetStatus(void);

int func_0205C88C(void)
{
    if (g_02146AD4.stpInetCntl == 0) {
        return 0;
    }
    if (((DWCstInetControl *)g_02146AD4.stpInetCntl)->ac_state != 0) {
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 3;
        DWC_GetInetStatus();
        return ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteWDS ? 1 : 0;
    }
    return 0;
}
