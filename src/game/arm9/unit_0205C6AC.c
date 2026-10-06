/*
 * file:     unit_0205C6AC.c
 * unit:     yes
 * function: func_0205C6AC, func_0205C710, func_0205C758, func_0205C81C, func_0205C88C, func_0205C8E0, func_0205CA20, func_0205CC20, func_0205CCAC
 * address:  0x0205C6AC
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
 *   MI_CpuFill8 0x02082BCC arm
 *   CPS_SetSslHandshakePriority 0x0216008C arm
 *   g_02146AD4 0x02146AD4 data
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   DWC_AC_Create 0x0205B98C arm
 *   DWCi_SetError 0x02059F54 arm
 *   DWC_Alloc 0x0205A16C arm
 *   DWC_Free 0x0205A1B0 arm
 *   DWC_ConnectInetAsync 0x0205C758 arm
 *   DWC_GetInetStatus 0x0205CA20 arm
 *   DWC_AC_SetSpecifyApEx 0x0205BEA8 arm
 *   DWC_AC_ProcessGetWDSInfo 0x0205D98C arm
 *   DWC_AC_CleanupGetWDSInfo 0x0205DC74 arm
 *   DWCi_AC_InvalidatePriorityWPA 0x0205C018 arm
 *   DWC_AC_Process 0x0205BC78 arm
 *   WCM_GetPhase 0x021656A0 arm
 *   DWC_AC_GetStatus 0x0205BD64 arm
 *   CPS_GetSslHandshakePriority 0x0216007C arm
 *   DWC_AC_StartupGetWDSInfo 0x0205D91C arm
 *   DWC_AC_CancelGetWDSInfo 0x0205DC58 arm
 *   DWC_AC_Destroy 0x0205BE6C arm
 *   OS_Sleep 0x02085A38 arm
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

typedef struct {
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    unsigned char dmaNo;
    unsigned char powerMode;
    unsigned char option[2];
    long rwin;
    unsigned char wontExecuteEULACheck;
} DWCACConfig;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CPS_SetSslHandshakePriority(unsigned short priority);
extern int OS_IsRunOnTwl(void);
extern int DWC_AC_Create(DWCACConfig *config);
extern void DWCi_SetError(int error, int errorCode);
extern void *DWC_Alloc(unsigned long name, long size);
extern void DWC_Free(unsigned long name, void *ptr, long size);
extern void DWC_ConnectInetAsync(void);
extern int DWC_GetInetStatus(void);
extern void DWC_AC_SetSpecifyApEx(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);
extern int DWC_AC_ProcessGetWDSInfo(void);
extern void DWC_AC_CleanupGetWDSInfo(void);
extern void DWCi_AC_InvalidatePriorityWPA(void);
extern int DWC_AC_Process(void);
extern long WCM_GetPhase(void);
extern int DWC_AC_GetStatus(void);
extern unsigned long CPS_GetSslHandshakePriority(void);
extern int DWC_AC_StartupGetWDSInfo(void *nspotInfo, unsigned short dmaNo);
extern void DWC_AC_CancelGetWDSInfo(void);
extern int DWC_AC_Destroy(void);
extern void OS_Sleep(unsigned long msec);
void func_0205C6AC(DWCstInetControl *inetCntl, unsigned short dmaNo, unsigned short unused, unsigned short ssl_priority);
void func_0205C710(long size);
void func_0205C758(void);
void func_0205C81C(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);
int func_0205C88C(void);
void func_0205C8E0(void);
int func_0205CA20(void);
void func_0205CC20(void);
int func_0205CCAC(void);
extern INETBSS g_02146AD4;





/*
 * sdk:      DWC_InitInetEx (dwc_connectinet.o)
 *
 * The DWARF prototype lists three parameters, but ssl_priority is read from r3:
 * the second argument slot (r2) is an unused parameter.
 */
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





/*
 * sdk:      DWC_SetRwinSize (dwc_connectinet.o)
 */
void func_0205C710(long size)
{
    if (g_02146AD4.stpInetCntl == 0) {
        return;
    }
    if (size < 0x10c0 || size > 0xffff) {
        return;
    }
    if (OS_IsRunOnTwl()) {
        g_02146AD4.stpInetCntl->rwin = size;
    }
}





/*
 * sdk:      DWC_ConnectInetAsync (dwc_connectinet.o)
 */
void func_0205C758(void)
{
    DWCACConfig inp;

    if (g_02146AD4.stpInetCntl != 0) {
        if (g_02146AD4.stpInetCntl->state != 1) {
            return;
        }
        MI_CpuFill8(&inp, 0, sizeof(inp));
        inp.dmaNo = g_02146AD4.stpInetCntl->dmaNo;
        inp.powerMode = g_02146AD4.stpInetCntl->powerMode;
        inp.rwin = g_02146AD4.stpInetCntl->rwin;
        inp.alloc = DWC_Alloc;
        inp.free = DWC_Free;
        inp.wontExecuteEULACheck = g_02146AD4.stpInetCntl->wontExecuteEULACheck;
        g_02146AD4.stpInetCntl->state = 2;
        if (!DWC_AC_Create(&inp)) {
            DWCi_SetError(9, -50199);
        }
    } else {
        DWCi_SetError(9, -50199);
    }
}





/*
 * sdk:      DWC_DebugConnectInetExAsync (dwc_connectinet.o)
 */
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




/*
 * sdk:      DWC_CheckInet (dwc_connectinet.o)
 */
int func_0205C88C(void)
{
    if (g_02146AD4.stpInetCntl == 0) {
        return 0;
    }
    if (g_02146AD4.stpInetCntl->ac_state != 0) {
        g_02146AD4.stpInetCntl->state = 3;
        DWC_GetInetStatus();
        return g_02146AD4.stpInetCntl->wontExecuteWDS ? 1 : 0;
    }
    return 0;
}



/*
 * sdk:      DWC_ProcessInet (dwc_connectinet.o)
 */
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



/*
 * sdk:      DWC_GetInetStatus (dwc_connectinet.o)
 */
int func_0205CA20(void)
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
    switch (g_02146AD4.stpInetCntl->processWDSstate) {
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        func_0205C8E0();
        DWCi_SetError(5, g_02146AD4.stateOld);
        g_02146AD4.stpInetCntl->state = 7;
        g_02146AD4.stpInetCntl->processWDSstate = 4;
        return 7;
    case 4:
        return 7;
    case 5:
        return 5;
    }
    result = g_02146AD4.stpInetCntl->state;
    if (result == 1) {
        return result;
    }
    state = DWC_AC_GetStatus();
    if (state == 5) {
        g_02146AD4.stpInetCntl->state = 4;
        g_02146AD4.stpInetCntl->online = 1;
        g_02146AD4.stpInetCntl->wontExecuteWDS = 1;
        return 4;
    }
    if (state < 0) {
        if (state >= -10) {
            g_02146AD4.stpInetCntl->wontExecuteWDS = 1;
            DWCi_SetError(9, -50199);
            g_02146AD4.stpInetCntl->state = 8;
            return 8;
        }
        if (state == -50599 || state == -50699) {
            g_02146AD4.stpInetCntl->wontExecuteWDS = 1;
            DWCi_SetError(5, state);
            g_02146AD4.stpInetCntl->state = 7;
            return 7;
        }
        cntl = g_02146AD4.stpInetCntl;
        if (cntl->wontExecuteWDS == 0) {
            dmaNoTemp = cntl->dmaNo;
            ssl_priority_Temp = CPS_GetSslHandshakePriority();
            wontExecuteEULACheck_Temp = g_02146AD4.stpInetCntl->wontExecuteEULACheck;
            rwin_Temp = g_02146AD4.stpInetCntl->rwin;
            g_02146AD4.stateOld = state;
            func_0205CC20();
            func_0205C6AC(cntl, dmaNoTemp, 1, (unsigned short)ssl_priority_Temp);
            g_02146AD4.stpInetCntl->wontExecuteEULACheck = wontExecuteEULACheck_Temp;
            if (rwin_Temp != 0) {
                func_0205C710(rwin_Temp);
            }
            DWC_AC_StartupGetWDSInfo(&g_02146AD4.stpInetCntl->nspotInfo, dmaNoTemp);
            g_02146AD4.stpInetCntl->processWDSstate = 1;
            g_02146AD4.stpInetCntl->ac_state = 0;
            return 2;
        }
        if (g_02146AD4.stateOld < state) {
            state = g_02146AD4.stateOld;
        }
        DWCi_SetError(5, state);
        g_02146AD4.stpInetCntl->state = 7;
        return 7;
    }
    return 2;
}



/*
 * sdk:      DWC_CleanupInet (dwc_connectinet.o)
 */
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



/*
 * sdk:      DWCi_CheckDisconnected (dwc_connectinet.o)
 */
int func_0205CCAC(void)
{
    if (g_02146AD4.stpInetCntl != 0 && g_02146AD4.stpInetCntl->state == 6) {
        return 1;
    }
    return 0;
}
