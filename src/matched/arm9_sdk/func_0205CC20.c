/*
 * function: func_0205CC20
 * address:  0x0205CC20
 * packet:   pkt_0205CC20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CleanupInet (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_AC_CancelGetWDSInfo 0x0205DC58 arm
 *   DWC_AC_ProcessGetWDSInfo 0x0205D98C arm
 *   DWC_AC_CleanupGetWDSInfo 0x0205DC74 arm
 *   DWC_AC_Destroy 0x0205BE6C arm
 *   OS_Sleep 0x02085A38 arm
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

extern void DWC_AC_CancelGetWDSInfo(void);
extern int DWC_AC_ProcessGetWDSInfo(void);
extern void DWC_AC_CleanupGetWDSInfo(void);
extern int DWC_AC_Destroy(void);
extern void OS_Sleep(unsigned long msec);

void func_0205CC20(void)
{
    int state;

    if (g_02146AD4.stpInetCntl == 0) {
        return;
    }
    if (g_02146AD4.stpInetCntl->state == 1) {
        if (g_02146AD4.stpInetCntl->processWDSstate == 1) {
            DWC_AC_CancelGetWDSInfo();
            while (1) {
                state = DWC_AC_ProcessGetWDSInfo();
                if (state == 2 || state == 3 || state == 4) {
                    break;
                }
            }
            DWC_AC_CleanupGetWDSInfo();
        }
        g_02146AD4.stpInetCntl = 0;
        return;
    }
    while (!DWC_AC_Destroy()) {
        OS_Sleep(10);
    }
    g_02146AD4.stpInetCntl = 0;
}
