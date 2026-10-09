/*
 * file:     unit_0205B98C.c
 * unit:     yes
 * function: func_0205B98C, func_0205BC78, func_0205BD64, func_0205BDD0, func_0205BE00, func_0205BE58, func_0205BE6C, func_0205BEA8, func_0205BF1C, func_0205BFD4, func_0205BFEC, func_0205C018, func_0205C038, func_0205C080, func_0205C0EC, func_0205C214, func_0205C25C, func_0205C2C4, func_0205C2E4, func_0205C308, func_0205C31C, func_0205C3B0, func_0205C4C8, func_0205C528, func_0205C55C, func_0205C600, func_0205C670
 * address:  0x0205B98C
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
 *   s_ac_work  0x02146AC0  data  a4
 *   WCM_InitEx  0x02164D74  arm
 *   WCM_Init    0x02164D64  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   CheckEULA             0x0205C600  arm
 *   CheckWirelessPowerON  0x0205C670  arm
 *   CheckDuplicate        0x0205C55C  arm
 *   Free_Disused          0x0205C528  arm
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   MIi_CpuCopy32                    0x02082a90 arm
 *   strncmp  0x020949F4  arm
 */
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef long s32;

typedef unsigned long long u64;

typedef int BOOL;

typedef void *(*ACAllocFunc)(u32 name, s32 size);

typedef void (*ACFreeFunc)(u32 name, void *ptr, s32 size);

typedef struct tagACHOLD {
    ACAllocFunc alloc;
    ACFreeFunc free;
    u8 allocState;
    u8 phase;
    u8 phaseError;
    u8 findAP_ipCollision;
    int error;
    int errorTest;
    u8 endState;
    u8 endType;
    u8 endSequence;
    u8 type;
    char apSpotInfo[10];
    u8 overrideType;
    u8 security;
    u8 proxyMode;
    u8 proxyAuthType;
    u16 proxyPort;
    u8 proxyHost[100];
    u8 proxyId[32];
    u8 proxyPass[32];
} ACHOLD;

typedef struct tagACFL {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} ACFL;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u8 rest[0xc0 - 0x2c];
} WMBssDesc;

typedef struct NCFGSlotInfo {
    u8 pad0[0x40];
    u8 ssid[32];
    u8 pad1[0x20];
    u8 wep[0x50];
    u8 pad2[0x16];
    u8 wepMode : 2;
    u8 wepNotation : 6;
    u8 pad3[3];
    u16 mtu;
    u8 pad4[0x100 - 0xec];
} NCFGSlotInfo;

typedef struct NCFGSlotInfoEx {
    u8 f000[0x20];
    u8 f020[0x20];
    u8 pad0[0xe6 - 0x40];
    u8 wepMode : 2;
    u8 wepNotation : 6;
    u8 wpaMode;
    u8 pad1[0x181 - 0xe8];
    u8 wpaSecurity;
    u8 proxyMode;
    u8 proxyAuthType;
    u8 proxyHost[100];
    u16 proxyPort;
    u8 pad2[0x200 - 0x1ea];
} NCFGSlotInfoEx;

typedef struct tagACWORK {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
    u8 searchList[21][36];
    ACFL findList[11];
    WMBssDesc bssDesc[11];
    u64 timeOut;
    u8 wepKey[0x52];
    u8 dmaNo;
    u8 powerMode : 2;
    u8 authMode : 2;
    u8 aroundCount : 4;
    u8 connectType : 4;
    u8 skipNetCheck : 1;
    u8 useDSWireless : 1;
    u8 duplicateFlag : 1;
    u8 wpaSetting : 1;
    u8 connectApType;
    u8 phaseBak;
    u8 searchListNo;
    u8 searchListNum;
    s8 searchChannel;
    u8 findListNum;
    u8 connectNo;
    u8 connectResult;
    u8 count;
    u16 stealthChannel;
    s32 rwin;
    u8 wontExecuteEULACheck;
    u16 maxChannel;
    u8 padding;
    u16 passiveScanTime;
    u16 activeScanTime;
} ACWORK;

typedef struct tagDWCACOption {
    u8 connectType;
    u8 skipNetCheck : 4;
    u8 useDSWireless : 4;
} DWCACOption;

typedef struct tagDWCACConfig {
    ACAllocFunc alloc;
    ACFreeFunc free;
    u8 dmaNo;
    u8 powerMode;
    DWCACOption option;
    s32 rwin;
    u8 wontExecuteEULACheck;
} DWCACConfig;

typedef struct DWCNetcheckParam {
    ACAllocFunc alloc;
    ACFreeFunc free;
    void *bmworkarea;
} DWCNetcheckParam;

typedef struct ACMem {
    void *wcmBuffer;
    void *socConfig;
    void *netCheck;
    ACHOLD *acHold;
    ACWORK *acWork;
} ACMem;

typedef struct NCFGApInfo {
    unsigned char data[0xF0];
} NCFGApInfo;

extern void *DWCi_AC_GetMemPtr(u32 name);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void *DWCi_AC_Alloc(u32 name, s32 size);
extern BOOL DWCi_BM_GetApInfo(NCFGSlotInfo *buf);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL DWCi_BM_GetApInfoEx(NCFGSlotInfoEx *buf);
extern s32 WCM_InitEx(void *buf, s32 len, u8 deviceId);
extern s32 WCM_Init(void *buf, s32 len);
extern void DWCi_AC_FreeAll(void);
extern BOOL CheckEULA(void);
extern BOOL CheckWirelessPowerON(void);
extern u8 DWCi_AC_Start(void);
extern void DWCi_AC_SetError(int error);
extern u32 OS_DisableInterrupts(void);
extern u8 DWCi_AC_SearchAP(void);
extern void DWCi_AC_SetPhase(u8 phase);
extern u32 OS_RestoreInterrupts(u32 state);
extern u8 DWCi_AC_ConnectAP(void);
extern u8 DWCi_AC_ConnectRetryAP(void);
extern u8 DWCi_AC_ConnectTest(void);
extern u8 DWCi_AC_Error(void);
extern BOOL CheckDuplicate(void);
extern void Free_Disused(void);
extern int DWCi_AC_GetResult(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern int DWCi_AC_CloseNetwork(u8 *phase);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void DWC_AC_SetSpecifyAp(void *ssid, void *wep, int wepMode);
extern int DWCi_AC_CheckNintendoShopAP(void *ssid, int len);
extern void MIi_CpuCopy32(const void *srcp, void *destp, unsigned long size);
extern u8 DWCi_ConvConnectAPType(u8 type);
extern u8 *WCM_GetApEssid(u16 *length);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern BOOL DWCi_AC_GetPostalCode(char *ssid, u8 *pos);
extern void DWCi_AC_Free(u32 name, void *ptr, s32 size);
extern int strncmp(const char *s1, const char *s2, u32 n);
extern BOOL OS_IsAgreeEULA(void);
extern u8 OS_GetAgreedEULAVersion(void);
extern u8 OS_GetROMHeaderEULAVersion(void);
extern BOOL OS_IsAvailableWireless(void);
extern BOOL OS_IsForceDisableWireless(void);
BOOL func_0205B98C(DWCACConfig *config);
int func_0205BC78(void);
int func_0205BD64(void);
u8 func_0205BDD0(void);
BOOL func_0205BE00(u8 *apSpotInfo);
unsigned int DWC_AC_GetSecuritySetting(void);
BOOL func_0205BE6C(void);
void func_0205BEA8(void *ssid, void *wep, int wepMode, u16 mtu, char *apSpotInfo, int overrideType);
void func_0205BF1C(void *ssid, void *wep, int wepMode);
int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len);
void func_0205BFEC(int no, NCFGApInfo *info);
void func_0205C018(void);
void *func_0205C038(u32 name, s32 size);
void func_0205C080(u32 name, void *ptr, s32 size);
void func_0205C0EC(void);
void *func_0205C214(u32 name);
void func_0205C25C(u8 phase);
unsigned char DWCi_AC_GetPhase(void);
void func_0205C2E4(int error);
int DWCi_AC_GetError(void);
void func_0205C31C(u8 type);
void func_0205C3B0(u8 type);
u8 func_0205C4C8(u8 type);
void func_0205C528(void);
BOOL func_0205C55C(void);
BOOL func_0205C600(void);
BOOL func_0205C670(void);



static ACMem s_ac_work;




/*
 * sdk:      DWC_AC_Create (dwc_ac.o)
 */
BOOL func_0205B98C(DWCACConfig *config)
{
    int result;
    ACHOLD *hd;
    ACWORK *wk;
    DWCNetcheckParam *nc;

    s_ac_work.acHold = config->alloc(1, sizeof(ACHOLD));
    MIi_CpuClear32(0, s_ac_work.acHold, sizeof(ACHOLD));
    hd = s_ac_work.acHold;
    hd->alloc = config->alloc;
    hd->free = config->free;
    hd->phase = 1;
    hd->endSequence = 1;
    hd->allocState = 1;

    s_ac_work.acWork = DWCi_AC_Alloc(0x10, sizeof(ACWORK));
    s_ac_work.wcmBuffer = DWCi_AC_Alloc(2, 0x4800);
    s_ac_work.socConfig = DWCi_AC_Alloc(4, 0x58);
    s_ac_work.netCheck = DWCi_AC_Alloc(8, sizeof(DWCNetcheckParam));
    MIi_CpuClear32(0, s_ac_work.acWork, sizeof(ACWORK));
    MIi_CpuClear32(0, s_ac_work.wcmBuffer, 0x4800);
    MIi_CpuClear32(0, s_ac_work.socConfig, 0x58);
    MIi_CpuClear32(0, s_ac_work.netCheck, sizeof(DWCNetcheckParam));

    wk = s_ac_work.acWork;
    wk->dmaNo = config->dmaNo;
    wk->powerMode = config->powerMode;
    wk->rwin = config->rwin;
    wk->wontExecuteEULACheck = config->wontExecuteEULACheck;
    nc = s_ac_work.netCheck;
    nc->alloc = config->alloc;
    nc->free = config->free;
    nc->bmworkarea = 0;
    wk->connectType = config->option.connectType;
    wk->skipNetCheck = config->option.skipNetCheck;
    wk->useDSWireless = config->option.useDSWireless;

    DWCi_BM_GetApInfo(wk->userInfo);
    if (OS_IsRunOnTwl()) {
        wk->wpaSetting = 0;
        DWCi_BM_GetApInfoEx(wk->userInfoEx);
        if (wk->connectType == 0) {
            if ((wk->userInfoEx[0].wpaMode >= 0x10 && wk->userInfoEx[0].wpaMode != 0xff) ||
                (wk->userInfoEx[1].wpaMode >= 0x10 && wk->userInfoEx[1].wpaMode != 0xff) ||
                (wk->userInfoEx[2].wpaMode >= 0x10 && wk->userInfoEx[2].wpaMode != 0xff)) {
                wk->wpaSetting = 1;
            }
        } else if (wk->connectType == 0xb) {
            if (wk->userInfoEx[0].wpaMode >= 0x10 && wk->userInfoEx[0].wpaMode != 0xff) {
                wk->wpaSetting = 1;
            }
        } else if (wk->connectType == 0xc) {
            if (wk->userInfoEx[1].wpaMode >= 0x10 && wk->userInfoEx[1].wpaMode != 0xff) {
                wk->wpaSetting = 1;
            }
        } else if (wk->connectType == 0xd) {
            if (wk->userInfoEx[2].wpaMode >= 0x10 && wk->userInfoEx[1].wpaMode != 0xff) {
                wk->wpaSetting = 1;
            }
        }
    }

    if (OS_IsRunOnTwl()) {
        if (wk->useDSWireless == 1) {
            result = WCM_Init(s_ac_work.wcmBuffer, 0x4800);
        } else {
            result = WCM_InitEx(s_ac_work.wcmBuffer, 0x4800, 2);
        }
    } else {
        result = WCM_Init(s_ac_work.wcmBuffer, 0x4800);
    }
    if (result == 1 || result > 4) {
        DWCi_AC_FreeAll();
        return 0;
    }
    return 1;
}






/*
 * sdk:      DWC_AC_Process (dwc_ac.o)
 */
int func_0205BC78(void)
{
    int ret;
    u32 irq;
    u8 phase = DWCi_AC_GetPhase();

    if (phase == 1) {
        if (CheckEULA()) {
            if (CheckWirelessPowerON()) {
                phase = DWCi_AC_Start();
            } else {
                DWCi_AC_SetError(8);
                phase = DWCi_AC_Error();
            }
        } else {
            DWCi_AC_SetError(7);
            phase = DWCi_AC_Error();
        }
    } else if (phase < 7) {
        irq = OS_DisableInterrupts();
        phase = DWCi_AC_SearchAP();
        DWCi_AC_SetPhase(phase);
        OS_RestoreInterrupts(irq);
    } else if (phase < 9) {
        phase = DWCi_AC_ConnectAP();
    } else if (phase < 0xa) {
        phase = DWCi_AC_ConnectRetryAP();
    } else if (phase < 0x10) {
        phase = DWCi_AC_ConnectTest();
    } else if (phase == 0x11) {
        phase = DWCi_AC_Error();
    }
    DWCi_AC_SetPhase(phase);
    if (phase == 0x10) {
        ret = CheckDuplicate();
        Free_Disused();
        return ret;
    }
    if (phase == 0x12) {
        Free_Disused();
        return -1;
    }
    return 0;
}






/*
 * sdk:      DWC_AC_GetStatus (dwc_ac.o)
 */
int func_0205BD64(void)
{
    u8 phase = DWCi_AC_GetPhase();

    if (phase <= 1) return 0;
    if (phase < 7) return 1;
    if (phase == 9) return 4;
    if (phase < 0xa) return 2;
    if (phase == 0xb) return 4;
    if (phase < 0x10) return 3;
    if (phase == 0x10) return 5;
    if (phase == 0x11) return 4;
    return DWCi_AC_GetResult();
}






/*
 * sdk:      DWC_AC_GetApType (dwc_ac.o)
 */
u8 func_0205BDD0(void)
{
    u8 type = 0xff;
    u8 phase = DWCi_AC_GetPhase();

    if (phase >= 0xa && phase <= 0x10) {
        type = s_ac_work.acHold->type;
    }
    return type;
}






/*
 * sdk:      DWC_AC_GetApSpotInfo (dwc_ac.o)
 */
BOOL func_0205BE00(u8 *apSpotInfo)
{
    BOOL result = 0;
    u8 phase = DWCi_AC_GetPhase();

    if (phase >= 0xa && phase <= 0x10) {
        if (s_ac_work.acHold->type == 4 || s_ac_work.acHold->type == 8) {
            MI_CpuCopy8(s_ac_work.acHold->apSpotInfo, apSpotInfo, 10);
            result = 1;
        }
    }
    return result;
}






unsigned int DWC_AC_GetSecuritySetting(void)
{
    unsigned char *hd = (unsigned char *)DWCi_AC_GetMemPtr(1);
    return hd[35];
}





/*
 * sdk:      DWC_AC_Destroy (dwc_ac.o)
 */
BOOL func_0205BE6C(void)
{
    u8 phase = DWCi_AC_GetPhase();

    if (phase == 0 || phase == 0x12) {
        DWCi_AC_FreeAll();
        return 1;
    }
    DWCi_AC_CloseNetwork(&phase);
    DWCi_AC_SetPhase(phase);
    return 0;
}





/*
 * sdk:      DWC_AC_SetSpecifyApEx (dwc_ac.o)
 */
void func_0205BEA8(void *ssid, void *wep, int wepMode, u16 mtu, char *apSpotInfo, int overrideType)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    if (apSpotInfo) {
        MI_CpuCopy8(apSpotInfo, hd->apSpotInfo, 10);
    } else {
        MI_CpuFill8(hd->apSpotInfo, 0, 10);
    }
    hd->overrideType = (u8)overrideType;
    DWC_AC_SetSpecifyAp(ssid, wep, wepMode);
    wk->userInfo[0].mtu = mtu;
}





/*
 * sdk:      DWC_AC_SetSpecifyAp (dwc_ac.o)
 */
void func_0205BF1C(void *ssid, void *wep, int wepMode)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    int i;
    u32 len;

    wk->connectType = 1;
    MI_CpuFill8(&wk->userInfo[0], 0, 0xf0);
    for (i = 0; i < 0x20; i++) {
        if (((u8 *)ssid)[i] == 0) {
            break;
        }
        wk->userInfo[0].ssid[i] = ((u8 *)ssid)[i];
    }
    if (wep == 0 || wepMode == 0) {
        wk->userInfo[0].wepMode = 0;
        return;
    }
    if (wepMode == 1) {
        len = 5;
    } else if (wepMode == 2) {
        len = 0xd;
    } else {
        len = 0x10;
    }
    MI_CpuCopy8(wep, wk->userInfo[0].wep, len);
    wk->userInfo[0].wepMode = (u8)wepMode;
}





int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len)
{
    if (len != 32)
        return 0;
    return DWCi_AC_CheckNintendoShopAP(ssid, len);
}





/*
 * sdk:      DWCi_AC_InsertApInfo (dwc_ac.o)
 */
void func_0205BFEC(int no, NCFGApInfo *info)
{
    ACWORK *wk = func_0205C214(0x10);

    MIi_CpuCopy32(info, &wk->userInfo[no], sizeof(NCFGApInfo));
}





/*
 * sdk:      DWCi_AC_InvalidatePriorityWPA (dwc_ac.o)
 */
void func_0205C018(void)
{
    ACWORK *wk = func_0205C214(0x10);

    wk->wpaSetting = 0;
}





/*
 * sdk:      DWCi_AC_Alloc (dwc_ac.o)
 */
void *func_0205C038(u32 name, s32 size)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (hd->allocState & name) {
        return 0;
    }
    hd->allocState |= name;
    return hd->alloc(1, size);
}





/*
 * sdk:      DWCi_AC_Free (dwc_ac.o)
 */
void func_0205C080(u32 name, void *ptr, s32 size)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (hd == 0) {
        return;
    }
    if ((hd->allocState & name) == 0) {
        return;
    }
    hd->allocState &= ~name;
    hd->free(1, ptr, size);
    if (name == 1) {
        s_ac_work.acHold = 0;
    }
}





/*
 * sdk:      DWCi_AC_FreeAll (dwc_ac.o)
 */
void func_0205C0EC(void)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (hd == 0) {
        return;
    }
    if (hd->allocState & 0x10) {
        ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
        hd->allocState &= ~0x10;
        hd->free(1, wk, sizeof(ACWORK));
    }
    if (hd->allocState & 8) {
        void *wk = DWCi_AC_GetMemPtr(8);
        hd->allocState &= ~8;
        hd->free(1, wk, 0xc);
    }
    if (hd->allocState & 4) {
        void *wk = DWCi_AC_GetMemPtr(4);
        hd->allocState &= ~4;
        hd->free(1, wk, 0x58);
    }
    if (hd->allocState & 2) {
        void *wk = DWCi_AC_GetMemPtr(2);
        hd->allocState &= ~2;
        hd->free(1, wk, 0x4800);
    }
    if (hd->allocState & 1) {
        hd->allocState &= ~1;
        hd->free(1, hd, sizeof(ACHOLD));
        s_ac_work.acHold = 0;
    }
}





/*
 * sdk:      DWCi_AC_GetMemPtr (dwc_ac.o)
 */
void *func_0205C214(u32 name)
{
    if (name & 1) return s_ac_work.acHold;
    if (name & 2) return s_ac_work.wcmBuffer;
    if (name & 4) return s_ac_work.socConfig;
    if (name & 8) return s_ac_work.netCheck;
    if (name & 0x10) return s_ac_work.acWork;
    return 0;
}





/*
 * sdk:      DWCi_AC_SetPhase (dwc_ac.o)
 */
void func_0205C25C(u8 phase)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    hd->phase = phase;
    if (phase < 0x10 && phase > hd->endSequence) {
        hd->endSequence = phase;
        if (phase > 7) {
            hd->endType = DWCi_ConvConnectAPType(wk->connectApType);
            hd->endState = wk->findList[wk->connectNo].b0;
        }
    }
}





unsigned char DWCi_AC_GetPhase(void)
{
    return s_ac_work.acHold ? s_ac_work.acHold->phase : 0;
}





/*
 * sdk:      DWCi_AC_SetError (dwc_ac.o)
 */
void func_0205C2E4(int error)
{
    ACHOLD *hd = func_0205C214(1);

    hd->error = error;
    hd->phaseError = DWCi_AC_GetPhase();
}





int DWCi_AC_GetError(void)
{
    return s_ac_work.acHold->error;
}




/*
 * sdk:      DWCi_AC_SetApType (dwc_ac.o)
 */
void func_0205C31C(u8 type)
{
    u8 *essid;

    if (s_ac_work.acHold->overrideType == 0) {
        type = DWCi_ConvConnectAPType(type);
    } else {
        type = s_ac_work.acHold->overrideType;
    }
    s_ac_work.acHold->type = type;
    essid = WCM_GetApEssid(0);
    if (essid) {
        DC_InvalidateRange(essid, 0x20);
        if (DWCi_AC_GetPostalCode((char *)essid, (u8 *)s_ac_work.acHold->apSpotInfo)) {
            return;
        }
        MI_CpuFill8(s_ac_work.acHold->apSpotInfo, 0, 10);
    } else {
        MI_CpuFill8(s_ac_work.acHold->apSpotInfo, 0, 10);
    }
}




/*
 * sdk:      DWCi_AC_CopyExSetting (dwc_ac.o)
 */
void func_0205C3B0(u8 type)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u8 ap_type = DWCi_ConvConnectAPType(type);

    if (ap_type >= 0xa && ap_type <= 0xc && OS_IsRunOnTwl()) {
        ap_type -= 0xa;
        hd->proxyMode = wk->userInfoEx[ap_type].proxyMode;
        hd->proxyAuthType = wk->userInfoEx[ap_type].proxyAuthType;
        hd->proxyPort = wk->userInfoEx[ap_type].proxyPort;
        MI_CpuCopy8(wk->userInfoEx[ap_type].proxyHost, hd->proxyHost, 100);
        MI_CpuCopy8(wk->userInfoEx[ap_type].f000, hd->proxyId, 0x20);
        MI_CpuCopy8(wk->userInfoEx[ap_type].f020, hd->proxyPass, 0x20);
        if ((u8)(wk->userInfoEx[ap_type].wpaMode + 0xf0) <= 3) {
            hd->security = wk->userInfoEx[ap_type].wpaSecurity;
        } else {
            hd->security = wk->userInfoEx[ap_type].wepMode;
        }
    } else {
        if ((u8)(type + 0xee) <= 1) {
            hd->security = 2;
        } else {
            hd->security = wk->userInfo[ap_type].wepMode;
        }
    }
}




/*
 * sdk:      DWCi_ConvConnectAPType (dwc_ac.o)
 */
u8 func_0205C4C8(u8 type)
{
    if (type >= 0x12) return (u8)(type - 0xf);
    if (type >= 0xf) return (u8)(type - 5);
    if (type >= 0xc) return (u8)(type - 2);
    if (type >= 9) return (u8)(type + 1);
    if (type >= 6) return (u8)(type + 4);
    if (type >= 3) return (u8)(type - 3);
    return type;
}




/*
 * sdk:      Free_Disused (dwc_ac.o)
 */
void func_0205C528(void)
{
    DWCi_AC_Free(8, s_ac_work.netCheck, 0xc);
    DWCi_AC_Free(0x10, s_ac_work.acWork, sizeof(ACWORK));
}




/*
 * sdk:      CheckDuplicate (dwc_ac.o)
 */
BOOL func_0205C55C(void)
{
    u8 i;
    u8 *ssid1;
    u8 connectNo;
    ACWORK *wk;
    u8 num;

    wk = s_ac_work.acWork;
    connectNo = wk->connectNo;
    ssid1 = wk->bssDesc[connectNo].bssid;
    if (wk->connectApType >= 0x12) {
        return 1;
    }
    num = wk->findListNum;
    for (i = 0; i < num; i++) {
        if (i != connectNo && wk->findList[i].b1 < 0x12 &&
            strncmp((char *)ssid1, (char *)wk->bssDesc[i].bssid, wk->bssDesc[i].ssidLength) == 0) {
            return 2;
        }
    }
    return 1;
}




/*
 * sdk:      CheckEULA (dwc_ac.o)
 */
BOOL func_0205C600(void)
{
    if (OS_IsRunOnTwl()) {
        if (s_ac_work.acWork->wontExecuteEULACheck ||
            (OS_IsAgreeEULA() && OS_GetAgreedEULAVersion() != 0 &&
             OS_GetAgreedEULAVersion() >= OS_GetROMHeaderEULAVersion())) {
            return 1;
        }
        return 0;
    }
    return 1;
}




/*
 * sdk:      CheckWirelessPowerON (dwc_ac.o)
 */
BOOL func_0205C670(void)
{
    if (OS_IsRunOnTwl()) {
        if (OS_IsAvailableWireless() == 1 && OS_IsForceDisableWireless() == 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}
