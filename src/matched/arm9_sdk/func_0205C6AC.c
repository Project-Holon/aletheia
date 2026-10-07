/*
 * function: func_0205C6AC
 * address:  0x0205C6AC
 * packet:   pkt_0205C6AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_InitInetEx (dwc_connectinet.o)
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CPS_SetSslHandshakePriority 0x0216008C arm
 *   g_02146AD4 0x02146AD4 data
 *
 * The DWARF prototype lists three parameters, but ssl_priority is read from r3:
 * the second argument slot (r2) is an unused parameter.
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

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SetSslHandshakePriority(unsigned short priority);

void func_0205C6AC(DWCstInetControl *inetCntl, unsigned short dmaNo, unsigned short unused, unsigned short ssl_priority)
{
    if (g_02146AD4.stpInetCntl != 0) {
        return;
    }
    MI_CpuFill8(inetCntl, 0, 0x68);
    inetCntl->dmaNo = dmaNo;
    inetCntl->powerMode = 1;
    inetCntl->state = 1;
    inetCntl->online = 0;
    inetCntl->wontExecuteWDS = 0;
    inetCntl->processWDSstate = 0;
    inetCntl->wontExecuteEULACheck = 0;
    g_02146AD4.stpInetCntl = inetCntl;
    CPS_SetSslHandshakePriority(ssl_priority);
}
