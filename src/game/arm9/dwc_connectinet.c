/*
 * file:     dwc_connectinet.c
 * unit:     yes
 * function: DWC_InitInetEx, DWC_SetRwinSize, DWC_ConnectInetAsync, DWC_DebugConnectInetExAsync, DWC_CheckInet, DWC_ProcessInet, DWC_GetInetStatus, DWC_CleanupInet, DWCi_CheckDisconnected, DWC_GetLinkLevel, DWCi_DivideFullApinfo, DWC_GetApInfo, DWC_CheckWiFiStation, DWC_GetCheckNintendoZoneWorkSize, DWC_CheckNintendoZone, DWC_GetParseWMBssDescWorkSize, DWC_ParseWMBssDesc, DWC_UpdateConnection
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
 * Tail call to WCM_GetLinkLevel (WCM_GetLinkLevel, ov009) through a pool word;
 * called from func_021F4EB4.
 * blocker:  +0008 ABS32 func_0205CF24          -> unresolved: 0205CF24 (arm, from name) has no witness outside 0205D010..0205D01C
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
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
 *   WCM_GetLinkLevel  0x021666C8  arm  ov009
 *   MI_CpuCopy8 0x02082D44 arm
 *   DWC_AC_GetApType 0x0205BDD0 arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   WCM_GetApMacAddress 0x02166384 arm
 *   DC_InvalidateRange 0x020862B8 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   WCM_GetApEssid 0x021663C8 arm
 *   DWC_AC_GetApSpotInfo 0x0205BE00 arm
 *   DWC_AC_GetSecuritySetting 0x0205BE58 arm
 *   DWC_AC_CheckWiFiStation 0x0205BFD4 arm
 *   DWCi_AC_GetPostalCode 0x0205EA70 arm
 *   MATHi_CRC16InitTableRev 0x020819FC arm
 *   WDS_DecryptWMBssDesc 0x0205A7CC arm
 *   WDS_IsAvailableForAutoConnect 0x0205A8FC arm
 *   DWC_CheckWiFiStation 0x0205CE84 arm
 *   DWC_CheckNintendoZone 0x0205CF30 arm
 *   DWC_ProcessInet 0x0205C8E0 arm
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

typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

typedef struct {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
} WMGameInfo;

typedef struct {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned short capaInfo;
    unsigned short rateSet[2];
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc_0205CCE4;

typedef struct { unsigned char data[0x104]; } CRYPTORC4Context;

typedef struct { unsigned short table[256]; } MATHCRC16Table;

typedef struct {
    unsigned char head[0x20];
    char fullapinfo[0x50];
} WDSApInfo;

typedef struct {
    CRYPTORC4Context rc4context;
    unsigned short crcContext;
    MATHCRC16Table crcTable;
    WDSApInfo apinfo;
} DWCCheckNintendoZoneWork;

typedef struct {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
} WMBssDesc_0205D01C;

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
extern int WCM_GetLinkLevel(void);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern unsigned char DWC_AC_GetApType(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned char *WCM_GetApMacAddress(void);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned char *WCM_GetApEssid(unsigned short *length);
extern int DWC_AC_GetApSpotInfo(unsigned char *apSpotInfo);
extern int DWC_AC_GetSecuritySetting(void);
extern int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len);
extern int DWCi_AC_GetPostalCode(char *ssid, unsigned char *pos);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern int WDS_DecryptWMBssDesc(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable, WMBssDesc_0205CCE4 *bssdesc, WDSApInfo *apinfo);
extern int WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo);
extern void func_0205CF24(void);
extern int DWC_CheckWiFiStation(void *ssid, unsigned short len, DWCApInfo *apinfo);
extern int DWC_CheckNintendoZone(void *work, WMBssDesc_0205CCE4 *bssdesc, DWCApInfo *apinfo);
extern void DWC_ProcessInet(void);
void DWC_InitInetEx(DWCstInetControl *inetCntl, unsigned short dmaNo, unsigned short unused, unsigned short ssl_priority);
void DWC_SetRwinSize(long size);
void DWC_DebugConnectInetExAsync(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);
int DWC_CheckInet(void);
void DWC_CleanupInet(void);
int DWCi_CheckDisconnected(void);
int DWC_GetLinkLevel(void);
void DWCi_DivideFullApinfo(char *fullapinfo, DWCApInfo *apinfo);
int DWC_GetApInfo(DWCApInfo *apinfo);
unsigned long DWC_GetCheckNintendoZoneWorkSize(void);
void DWC_GetParseWMBssDescWorkSize(void);
int DWC_ParseWMBssDesc(void *work, WMBssDesc_0205D01C *bssdesc, DWCApInfo *apinfo);
int DWC_UpdateConnection(void);
extern INETBSS g_02146AD4;






/*
 * sdk:      DWC_InitInetEx (dwc_connectinet.o)
 *
 * The DWARF prototype lists three parameters, but ssl_priority is read from r3:
 * the second argument slot (r2) is an unused parameter.
 */
void DWC_InitInetEx(DWCstInetControl *inetCntl, unsigned short dmaNo, unsigned short unused, unsigned short ssl_priority)
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
void DWC_SetRwinSize(long size)
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
void DWC_ConnectInetAsync(void)
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
void DWC_DebugConnectInetExAsync(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType)
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
int DWC_CheckInet(void)
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
void DWC_ProcessInet(void)
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
        DWC_DebugConnectInetExAsync(g_02146AD4.stpInetCntl->nspotInfo.ssid, g_02146AD4.stpInetCntl->nspotInfo.wep,
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
    switch (g_02146AD4.stpInetCntl->processWDSstate) {
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        DWC_ProcessInet();
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
            DWC_CleanupInet();
            DWC_InitInetEx(cntl, dmaNoTemp, 1, (unsigned short)ssl_priority_Temp);
            g_02146AD4.stpInetCntl->wontExecuteEULACheck = wontExecuteEULACheck_Temp;
            if (rwin_Temp != 0) {
                DWC_SetRwinSize(rwin_Temp);
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
void DWC_CleanupInet(void)
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
int DWCi_CheckDisconnected(void)
{
    if (g_02146AD4.stpInetCntl != 0 && g_02146AD4.stpInetCntl->state == 6) {
        return 1;
    }
    return 0;
}


int DWC_GetLinkLevel(void)
{
    return WCM_GetLinkLevel();
}






/*
 * sdk:      DWCi_DivideFullApinfo (dwc_connectinet.o)
 */
void DWCi_DivideFullApinfo(char *fullapinfo, DWCApInfo *apinfo)
{
    int isdigit = 0;

    if (fullapinfo[0] >= '0' && fullapinfo[0] <= '9') {
        isdigit = 1;
    }
    apinfo->area = isdigit ? fullapinfo[0] - '0' : 0xff;
    MI_CpuCopy8(fullapinfo + 1, apinfo->spotinfo, 9);
}






/*
 * sdk:      DWC_GetApInfo (dwc_connectinet.o)
 */
int DWC_GetApInfo(DWCApInfo *apinfo)
{
    unsigned short essidlen;
    unsigned char apSpotInfo[10];
    unsigned char *wcmapbssid;
    unsigned char *wcmapessid;
    unsigned long preirq;

    MI_CpuFill8(apinfo, 0, sizeof(DWCApInfo));
    apinfo->area = 0xff;
    if (DWC_GetInetStatus() != 4) {
        return 0;
    }
    apinfo->aptype = DWC_AC_GetApType();
    if (apinfo->aptype == 0xff || apinfo->aptype > 99) {
        apinfo->aptype = 99;
        return 0;
    }
    preirq = OS_DisableInterrupts();
    wcmapbssid = WCM_GetApMacAddress();
    DC_InvalidateRange(wcmapbssid, 6);
    if (wcmapbssid == 0) {
        OS_RestoreInterrupts(preirq);
        return 0;
    }
    MI_CpuCopy8(wcmapbssid, apinfo->bssid, 6);
    if (apinfo->aptype == 0 || apinfo->aptype == 1 || apinfo->aptype == 2
        || (OS_IsRunOnTwl() && (unsigned int)(apinfo->aptype - 10) <= 2)) {
        wcmapessid = WCM_GetApEssid(&essidlen);
        DC_InvalidateRange(wcmapessid, 0x20);
        if (wcmapessid == 0) {
            OS_RestoreInterrupts(preirq);
            return 0;
        }
        MI_CpuCopy8(wcmapessid, apinfo->essid, essidlen);
    }
    OS_RestoreInterrupts(preirq);
    if (DWC_AC_GetApSpotInfo(apSpotInfo)) {
        DWCi_DivideFullApinfo((char *)apSpotInfo, apinfo);
    } else {
        apinfo->area = 0xff;
    }
    apinfo->security = DWC_AC_GetSecuritySetting();
    return 1;
}





/*
 * sdk:      DWC_CheckWiFiStation (dwc_connectinet.o)
 */
int DWC_CheckWiFiStation(void *ssid, unsigned short len, DWCApInfo *apinfo)
{
    unsigned char apSpotInfo[10];

    MI_CpuFill8(apSpotInfo, 0, 10);
    if (ssid == 0) {
        return 0;
    }
    if (DWC_AC_CheckWiFiStation(ssid, len)) {
        if (apinfo == 0) {
            return 1;
        }
        if (DWCi_AC_GetPostalCode(ssid, apSpotInfo)) {
            apinfo->aptype = 4;
            DWCi_DivideFullApinfo((char *)apSpotInfo, apinfo);
            return 1;
        }
    }
    return 0;
}



unsigned long DWC_GetCheckNintendoZoneWorkSize(void)
{
    return 0x376;
}



/*
 * sdk:      DWC_CheckNintendoZone (dwc_connectinet.o)
 */
int DWC_CheckNintendoZone(void *work, WMBssDesc_0205CCE4 *bssdesc, DWCApInfo *apinfo)
{
    DWCCheckNintendoZoneWork *pwork;

    if (work == 0 || bssdesc == 0) {
        return 0;
    }
    MI_CpuFill8(work, 0, 0x376);
    if (bssdesc->gameInfo.userGameInfoLength + 0x10 == 0x80
        && bssdesc->gameInfo.magicNumber == 1
        && bssdesc->gameInfo.ggid == 0x857) {
        pwork = (DWCCheckNintendoZoneWork *)work;
        pwork->crcContext = 0;
        MATHi_CRC16InitTableRev(&pwork->crcTable, 0xa001);
        if (WDS_DecryptWMBssDesc(&pwork->rc4context, &pwork->crcContext, &pwork->crcTable, bssdesc, &pwork->apinfo)
            && WDS_IsAvailableForAutoConnect(&pwork->apinfo)) {
            if (apinfo != 0) {
                apinfo->aptype = 8;
                DWCi_DivideFullApinfo(pwork->apinfo.fullapinfo, apinfo);
            }
            return 1;
        }
    }
    return 0;
}

void DWC_GetParseWMBssDescWorkSize(void)
{
    func_0205CF24();
}



/*
 * sdk:      DWC_ParseWMBssDesc (dwc_connectinet.o)
 */
int DWC_ParseWMBssDesc(void *work, WMBssDesc_0205D01C *bssdesc, DWCApInfo *apinfo)
{
    if (work == 0 || bssdesc == 0 || apinfo == 0) {
        return 0;
    }
    if (DWC_CheckWiFiStation(bssdesc->ssid, bssdesc->ssidLength, apinfo)) {
        return 1;
    }
    return DWC_CheckNintendoZone(work, (WMBssDesc_0205CCE4 *)bssdesc, apinfo) ? 1 : 0;
}



/*
 * sdk:      DWC_UpdateConnection (dwc_connectinet.o)
 */
int DWC_UpdateConnection(void)
{
    unsigned char aptype;

    DWC_ProcessInet();
    if (DWCi_CheckDisconnected()) {
        aptype = DWC_AC_GetApType();
        if (aptype == 0xff || aptype > 99) {
            aptype = 99;
        }
        if (WCM_GetPhase() == 11) {
            DWCi_SetError(9, -54900 - aptype);
        } else {
            DWCi_SetError(8, -54000 - aptype);
        }
        return 1;
    }
    return 0;
}
