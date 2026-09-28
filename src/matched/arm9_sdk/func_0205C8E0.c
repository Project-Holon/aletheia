/*
 * function: func_0205C8E0
 * address:  0x0205C8E0
 * packet:   pkt_0205C8E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ProcessInet (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_AC_ProcessGetWDSInfo 0x0205D98C arm
 *   DWC_AC_CleanupGetWDSInfo 0x0205DC74 arm
 *   func_0205C81C 0x0205C81C arm
 *   DWCi_AC_InvalidatePriorityWPA 0x0205C018 arm
 *   DWC_AC_Process 0x0205BC78 arm
 *   WCM_GetPhase 0x021656A0 arm
 *   g_02146AD4 0x02146AD4 data
 */

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

extern INETBSS g_02146AD4;

extern int DWC_AC_ProcessGetWDSInfo(void);
extern void DWC_AC_CleanupGetWDSInfo(void);
extern void func_0205C81C(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);
extern void DWCi_AC_InvalidatePriorityWPA(void);
extern int DWC_AC_Process(void);
extern long WCM_GetPhase(void);

void func_0205C8E0(void)
{
    if (g_02146AD4.stpInetCntl == 0) {
        return;
    }
    switch (g_02146AD4.stpInetCntl->processWDSstate) {
    case 1:
        g_02146AD4.stpInetCntl->ac_state = 0;
        g_02146AD4.stpInetCntl->processWDSstate = DWC_AC_ProcessGetWDSInfo();
        return;
    case 2:
        DWC_AC_CleanupGetWDSInfo();
        func_0205C81C(g_02146AD4.stpInetCntl->nspotInfo.ssid, g_02146AD4.stpInetCntl->nspotInfo.wep,
                      g_02146AD4.stpInetCntl->nspotInfo.wepMode, g_02146AD4.stpInetCntl->nspotInfo.mtu,
                      g_02146AD4.stpInetCntl->nspotInfo.apSpotInfo, 8);
        DWCi_AC_InvalidatePriorityWPA();
        g_02146AD4.stpInetCntl->processWDSstate = 0;
        return;
    case 3:
        DWC_AC_CleanupGetWDSInfo();
        g_02146AD4.stpInetCntl->ac_state = -1;
        g_02146AD4.stpInetCntl->wontExecuteWDS = 1;
        return;
    case 4:
    case 5:
        return;
    }
    if (g_02146AD4.stpInetCntl->state == 2) {
        g_02146AD4.stpInetCntl->ac_state = DWC_AC_Process();
    } else if (g_02146AD4.stpInetCntl->state == 4 && g_02146AD4.stpInetCntl->online != 0) {
        if (WCM_GetPhase() != 9) {
            g_02146AD4.stpInetCntl->online = 0;
            g_02146AD4.stpInetCntl->state = 6;
        }
    }
}
