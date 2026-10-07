/*
 * function: func_0205C710
 * address:  0x0205C710
 * packet:   pkt_0205C710
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SetRwinSize (dwc_connectinet.o)
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
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

extern int OS_IsRunOnTwl(void);

void func_0205C710(long size)
{
    if (g_02146AD4.stpInetCntl == 0) {
        return;
    }
    if (size < 0x10c0 || size > 0xffff) {
        return;
    }
    if (OS_IsRunOnTwl()) {
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->rwin = size;
    }
}
