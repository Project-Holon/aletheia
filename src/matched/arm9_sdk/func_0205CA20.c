/*
 * function: DWC_GetInetStatus
 * address:  0x0205CA20
 * packet:   pkt_0205CA20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetInetStatus (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_ProcessInet 0x0205C8E0 arm
 *   DWCi_SetError 0x02059F54 arm
 *   DWC_AC_GetStatus 0x0205BD64 arm
 *   CPS_GetSslHandshakePriority 0x0216007C arm
 *   DWC_CleanupInet 0x0205CC20 arm
 *   DWC_InitInetEx 0x0205C6AC arm
 *   DWC_SetRwinSize 0x0205C710 arm
 *   DWC_AC_StartupGetWDSInfo 0x0205D91C arm
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
    struct {
        unsigned char ssid[32];
        unsigned char wep[32];
        int wepMode;
        unsigned short mtu;
        char apSpotInfo[10];
    } nspotInfo;
} DWCstInetControl;

/* dwc_connectinet.o .bss: stateOld (DWC_GetInetStatus static) then stpInetCntl */
typedef struct {
    int stateOld;
    DWCstInetControl *stpInetCntl;
} INETBSS;

extern struct INETBSS g_02146AD4;

extern void DWC_ProcessInet(void);
extern void DWCi_SetError(int error, int errorCode);
extern int DWC_AC_GetStatus(void);
extern unsigned long CPS_GetSslHandshakePriority(void);
extern void DWC_CleanupInet(void);
extern void DWC_InitInetEx(DWCstInetControl *inetCntl, unsigned short dmaNo, unsigned short powerMode, unsigned short ssl_priority);
extern void DWC_SetRwinSize(long size);
extern int DWC_AC_StartupGetWDSInfo(void *nspotInfo, unsigned short dmaNo);

int DWC_GetInetStatus(void)
{
    int state;
    int result;
    unsigned short dmaNoTemp;
    unsigned long ssl_priority_Temp;
    unsigned char wontExecuteEULACheck_Temp;
    long rwin_Temp;
    DWCstInetControl *cntl;

    if (g_02146AD4.stpInetCntl == 0) {
        return 0;
    }
    switch (((DWCstInetControl *)g_02146AD4.stpInetCntl)->processWDSstate) {
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        DWC_ProcessInet();
        DWCi_SetError(5, g_02146AD4.stateOld);
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 7;
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->processWDSstate = 4;
        return 7;
    case 4:
        return 7;
    case 5:
        return 5;
    }
    result = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state;
    if (result == 1) {
        return result;
    }
    state = DWC_AC_GetStatus();
    if (state == 5) {
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 4;
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->online = 1;
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteWDS = 1;
        return 4;
    }
    if (state < 0) {
        if (state >= -10) {
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteWDS = 1;
            DWCi_SetError(9, -50199);
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 8;
            return 8;
        }
        if (state == -50599 || state == -50699) {
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteWDS = 1;
            DWCi_SetError(5, state);
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 7;
            return 7;
        }
        cntl = g_02146AD4.stpInetCntl;
        if (cntl->wontExecuteWDS == 0) {
            dmaNoTemp = cntl->dmaNo;
            ssl_priority_Temp = CPS_GetSslHandshakePriority();
            wontExecuteEULACheck_Temp = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteEULACheck;
            rwin_Temp = ((DWCstInetControl *)g_02146AD4.stpInetCntl)->rwin;
            g_02146AD4.stateOld = state;
            DWC_CleanupInet();
            DWC_InitInetEx(cntl, dmaNoTemp, 1, (unsigned short)ssl_priority_Temp);
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->wontExecuteEULACheck = wontExecuteEULACheck_Temp;
            if (rwin_Temp != 0) {
                DWC_SetRwinSize(rwin_Temp);
            }
            DWC_AC_StartupGetWDSInfo(&((DWCstInetControl *)g_02146AD4.stpInetCntl)->nspotInfo, dmaNoTemp);
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->processWDSstate = 1;
            ((DWCstInetControl *)g_02146AD4.stpInetCntl)->ac_state = 0;
            return 2;
        }
        if (g_02146AD4.stateOld < state) {
            state = g_02146AD4.stateOld;
        }
        DWCi_SetError(5, state);
        ((DWCstInetControl *)g_02146AD4.stpInetCntl)->state = 7;
        return 7;
    }
    return 2;
}
