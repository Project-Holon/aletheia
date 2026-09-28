/*
 * function: func_0205C81C
 * address:  0x0205C81C
 * packet:   pkt_0205C81C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_DebugConnectInetExAsync (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_ConnectInetAsync 0x0205C758 arm
 *   DWC_GetInetStatus 0x0205CA20 arm
 *   DWC_AC_SetSpecifyApEx 0x0205BEA8 arm
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
} DWCstInetControl;

/* dwc_connectinet.o .bss: stateOld (DWC_GetInetStatus static) then stpInetCntl */
typedef struct {
    int stateOld;
    DWCstInetControl *stpInetCntl;
} INETBSS;

extern INETBSS g_02146AD4;

extern void DWC_ConnectInetAsync(void);
extern int DWC_GetInetStatus(void);
extern void DWC_AC_SetSpecifyApEx(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);

void func_0205C81C(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType)
{
    DWC_ConnectInetAsync();
    if (g_02146AD4.stpInetCntl != 0) {
        g_02146AD4.stpInetCntl->wontExecuteWDS = 1;
    }
    if (DWC_GetInetStatus() != 2) {
        return;
    }
    DWC_AC_SetSpecifyApEx(ssid, wep, wepMode, mtu, apSpotInfo, overrideType);
}
