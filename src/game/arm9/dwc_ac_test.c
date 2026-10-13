/*
 * file:     dwc_ac_test.c
 * unit:     yes
 * function: func_0205F07C, func_0205F154, func_0205F1B8, func_0205F298, func_0205F2C4, func_0205F35C, func_0205F384, func_0205F3B0, func_0205F504, func_0205F558, func_0205F5AC
 * address:  0x0205F07C
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
 *   DWCi_AC_GetPhase                 0x0205c2c4 arm
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   WCM_GetPhase                     0x021656a0 arm
 *   ConnectTestStart                 0x0205f154 arm
 *   GetIPAddress                     0x0205f1b8 arm
 *   ConnectTestCreate                0x0205f298 arm
 *   ConnectTestProcess               0x0205f2c4 arm
 *   ConnectTestEnd                   0x0205f35c arm
 *   ConnectTestRetry                 0x0205f384 arm
 *   DWC_Netcheck_Abort               0x0217aa20 arm
 *   DWC_Netcheck_Destroy             0x0217a950 arm
 *   MakeSOCConfig                    0x0205f3b0 arm
 *   SOC_Startup                      0x0215f8fc arm
 *   DWCi_AC_SetError                 0x0205c2e4 arm
 *   SOCLiYieldWait                   0x021aa440 data
 *   g_021AA440                       0x021AA440 data
 *   SOC_GetHostID                    0x0215f7b0 arm
 *   CheckSetDNS                      0x0205f5ac arm
 *   DWCi_ConvConnectAPType           0x0205c4c8 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   OS_GetTick                       0x020870d0 arm
 *   _ll_udiv                         0x0209c00c arm
 *   DWC_Netcheck_Create              0x0217a880 arm
 *   DWC_Netcheck_GetError            0x0217aaa0 arm
 *   DWC_Netcheck_GetReturnCode       0x0217aadc arm
 *   CPSNoIpReason                    0x021a82b8 data
 *   g_021A82B8                       0x021A82B8 data
 *   DWCi_AC_SetApType                0x0205c31c arm
 *   DWCi_AC_CopyExSetting            0x0205c3b0 arm
 *   SOCL_CalmDown                    0x0215ed60 arm
 *   SOC_Cleanup                      0x0215fa90 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   ConvAddress                      0x0205f504 arm
 *   ConvNetMask                      0x0205f558 arm
 *   DWC_AC_SOC_CONFIG                0x020a16a0 data
 *   g_020A16A0                       0x020A16A0 data
 *   SOC_SetResolver                  0x0215f7e8 arm
 */
struct SOCConfig;
typedef struct tagACFL {
    unsigned char state;
    unsigned char pad[3];
} tagACFL;

typedef struct tagACWORK_0205F07C {
    unsigned char pad0[0xbf4];
    tagACFL findList[11];
    unsigned char pad1[0x14bd - 0xc20];
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
    unsigned char padding;
    unsigned short passiveScanTime;
    unsigned short activeScanTime;
} tagACWORK_0205F07C;

typedef void *(*SOCAlloc)(unsigned long, long);

typedef void (*SOCFree)(unsigned long, void *, long);

typedef struct tagACHOLD {
    SOCAlloc alloc;
    SOCFree free;
    unsigned char allocState;
    unsigned char phase;
    unsigned char phaseError;
    unsigned char findAP : 4;
    unsigned char ipCollision : 4;
    int error;
    int errorTest;
    unsigned char endState;
    unsigned char endType;
    unsigned char endSequence;
    unsigned char type;
    char apSpotInfo[10];
    unsigned char overrideType;
    unsigned char security;
    unsigned char proxyMode;
    unsigned char proxyAuthType;
    unsigned short proxyPort;
    unsigned char proxyHost[100];
    unsigned char proxyId[32];
    unsigned char proxyPass[32];
} tagACHOLD;

typedef struct NCFGApInfo {
    unsigned char ispId[32];
    unsigned char ispPass[32];
    unsigned char ssid[2][32];
    unsigned char wep[4][16];
    unsigned char ip[4];
    unsigned char gateway[4];
    unsigned char dns[2][4];
    unsigned char netmask;
    unsigned char wep2[4][5];
    unsigned char authType;
    unsigned char wepMode;
    unsigned char setType;
    unsigned char ssidLength[2];
    unsigned short mtu;
    unsigned char rsv[2];
    unsigned char flags;
    unsigned char state;
} NCFGApInfo;

typedef struct NCFGSlotInfo {
    NCFGApInfo ap;
    unsigned char rest[0x10];
} NCFGSlotInfo;

typedef struct NCFGSlotInfoEx_0205F07C {
    NCFGApInfo ap;
    unsigned char rest0[0x92];
    unsigned char exFlag;
    unsigned char rest1[0x7d];
} NCFGSlotInfoEx_0205F07C;

typedef struct tagACWORK_0205F1B8 {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx_0205F07C userInfoEx[3];
    unsigned char searchList[0xbf4 - 0x900];
    tagACFL findList[11];
    unsigned char bssDesc[0x1460 - 0xc20];
    unsigned long long timeOut;
    unsigned char wepKey[0x14ba - 0x1468];
    unsigned char dmaNo;
    unsigned char powerMode;
    unsigned char connectType : 4;
    unsigned char skipNetCheck : 1;
    unsigned char useDSWireless : 1;
    unsigned char duplicateFlag : 1;
    unsigned char wpaSetting : 1;
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
} tagACWORK_0205F1B8;

typedef struct DWCNetcheckParam DWCNetcheckParam;

typedef struct tagACWORK_0205F2C4 {
    unsigned char pad0[0xbf4];
    tagACFL findList[11];
    unsigned char pad1[0x14bd - 0xc20];
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
    unsigned char padding;
    unsigned short passiveScanTime;
    unsigned short activeScanTime;
} tagACWORK_0205F2C4;

typedef struct tagACWORK {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx_0205F07C userInfoEx[3];
    unsigned char searchList[0xbf4 - 0x900];
    tagACFL findList[11];
    unsigned char bssDesc[0x1460 - 0xc20];
    unsigned long long timeOut;
    unsigned char wepKey[0x14ba - 0x1468];
    unsigned char dmaNo;
    unsigned char powerMode;
    unsigned char connectType : 4;
    unsigned char skipNetCheck : 1;
    unsigned char useDSWireless : 1;
    unsigned char duplicateFlag : 1;
    unsigned char wpaSetting : 1;
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
} tagACWORK;

typedef struct SOCConfig {
    unsigned long vendor;
    SOCAlloc alloc;
    SOCFree free;
    unsigned long flag;
    unsigned long addr;
    unsigned long netmask;
    unsigned long router;
    unsigned long dns1;
    unsigned long dns2;
    unsigned long timeWaitBuffer;
    unsigned long reassemblyBuffer;
    unsigned long mtu;
    unsigned long rwin;
    unsigned char rest[0x58 - 0x34];
} SOCConfig;

typedef struct SOCInAddr {
    unsigned long addr;
} SOCInAddr;

extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern unsigned char DWCi_AC_GetPhase(void);
extern long WCM_GetPhase(void);
extern unsigned char ConnectTestStart(tagACWORK_0205F07C *wk);
extern unsigned char GetIPAddress(tagACWORK_0205F07C *wk);
extern unsigned char ConnectTestCreate(void);
extern unsigned char ConnectTestProcess(tagACWORK_0205F07C *wk);
extern unsigned char ConnectTestEnd(tagACWORK_0205F07C *wk);
extern unsigned char ConnectTestRetry(void);
extern void DWC_Netcheck_Abort(void);
extern void DWC_Netcheck_Destroy(void);
extern void MakeSOCConfig(tagACHOLD *hd, tagACWORK *wk, struct SOCConfig *sc);
extern int SOC_Startup(struct SOCConfig *config);
extern void DWCi_AC_SetError(int error);
extern unsigned char DWCi_ConvConnectAPType(unsigned char type);
extern int OS_IsRunOnTwl(void);
extern long SOC_GetHostID(void);
extern void CheckSetDNS(tagACWORK_0205F1B8 *wk);
extern unsigned long long OS_GetTick(void);
extern void *func_0205C214(unsigned long name);
extern int DWC_Netcheck_Create(DWCNetcheckParam *param);
extern void func_0205C2E4(int error);
extern int DWC_Netcheck_GetError(void);
extern int DWC_Netcheck_GetReturnCode(void);
extern void func_0205C31C(unsigned char type);
extern void func_0205C3B0(unsigned char type);
extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern unsigned long ConvAddress(unsigned char *add);
extern unsigned long ConvNetMask(unsigned char netmask);
extern int SOC_SetResolver(SOCInAddr *dns1, SOCInAddr *dns2);
unsigned char func_0205F07C(void);
unsigned char func_0205F154(tagACWORK *wk);
unsigned char func_0205F1B8(tagACWORK_0205F1B8 *wk);
unsigned char func_0205F2C4(tagACWORK_0205F2C4 *wk);
void func_0205F3B0(tagACHOLD *hd, tagACWORK *wk, SOCConfig *sc);
unsigned long func_0205F504(unsigned char *add);
void func_0205F5AC(tagACWORK *wk);
extern int SOCLiYieldWait;
extern int CPSNoIpReason;
extern SOCConfig g_020A16A0;






/*
 * sdk:      DWCi_AC_ConnectTest (libdwcac.TWL.HYB.a(test.o))
 */
unsigned char func_0205F07C(void)
{
    unsigned char phase;
    tagACWORK_0205F07C *wk;

    phase = DWCi_AC_GetPhase();
    wk = (tagACWORK_0205F07C *)DWCi_AC_GetMemPtr(0x10);
    if (WCM_GetPhase() == 9) {
        switch (phase) {
        case 10:
            phase = ConnectTestStart(wk);
            break;
        case 12:
            phase = GetIPAddress(wk);
            break;
        case 13:
            phase = ConnectTestCreate();
            break;
        case 14:
            phase = ConnectTestProcess(wk);
            break;
        case 15:
            phase = ConnectTestEnd(wk);
            break;
        case 11:
            phase = ConnectTestRetry();
            break;
        }
    } else {
        switch (phase) {
        case 15:
            phase = ConnectTestEnd(wk);
            break;
        case 11:
            phase = ConnectTestRetry();
            break;
        case 14:
            DWC_Netcheck_Abort();
            DWC_Netcheck_Destroy();
        default:
            wk->findList[wk->connectNo].state = 2;
            phase = 11;
            break;
        }
    }
    return phase;
}






/*
 * sdk:      ConnectTestStart (libdwcac.TWL.HYB.a(test.o))
 */
unsigned char func_0205F154(tagACWORK *wk)
{
    tagACHOLD *hd;
    struct SOCConfig *sc;

    hd = (tagACHOLD *)DWCi_AC_GetMemPtr(1);
    sc = (struct SOCConfig *)DWCi_AC_GetMemPtr(4);
    MakeSOCConfig(hd, wk, sc);
    SOCLiYieldWait = 4;
    if (SOC_Startup(sc) == 0) {
        return 0xc;
    }
    DWCi_AC_SetError(2);
    return 0x11;
}






/*
 * sdk:      GetIPAddress (libdwcac.TWL.HYB.a(test.o))
 */
unsigned char func_0205F1B8(tagACWORK_0205F1B8 *wk)
{
    unsigned char ap_type;
    unsigned long long t;

    if (SOC_GetHostID() != 0) {
        CheckSetDNS(wk);
        if (wk->skipNetCheck == 1) {
            return 0xf;
        }
        ap_type = DWCi_ConvConnectAPType(wk->connectApType);
        if (ap_type >= 10 && ap_type <= 12 && OS_IsRunOnTwl()
            && wk->userInfoEx[(unsigned char)(ap_type - 10)].exFlag != 0) {
            return 0xf;
        }
        return 0xd;
    }
    t = OS_GetTick();
    if ((t - wk->timeOut) * 64 / 0x1ff6210 < 10) {
        return 0xc;
    }
    wk->findList[wk->connectNo].state = 1;
    return 0xb;
}






/*
 * sdk:      ConnectTestCreate (test.o)
 */
static unsigned char func_0205F298(void)
{
    DWCNetcheckParam *nc = (DWCNetcheckParam *)func_0205C214(8);

    if (DWC_Netcheck_Create(nc) == 0) {
        return 0xE;
    }
    func_0205C2E4(3);
    return 0x11;
}






/*
 * sdk:      ConnectTestProcess (libdwcac.TWL.HYB.a(test.o))
 */
unsigned char func_0205F2C4(tagACWORK_0205F2C4 *wk)
{
    tagACHOLD *hd;
    int result;

    hd = (tagACHOLD *)DWCi_AC_GetMemPtr(1);
    result = DWC_Netcheck_GetError();
    if (result != 0) {
        if (hd->endType == DWCi_ConvConnectAPType(wk->connectApType)) {
            hd->errorTest = DWC_Netcheck_GetReturnCode();
        }
        DWC_Netcheck_Destroy();
        if (result != 11) {
            wk->findList[wk->connectNo].state = 1;
            if (CPSNoIpReason == 4) {
                hd->ipCollision = 1;
            } else {
                hd->ipCollision = 0;
            }
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}





/*
 * sdk:      ConnectTestEnd (test.o)
 */
static unsigned char func_0205F35C(tagACWORK *wk)
{
    func_0205C31C(wk->connectApType);
    func_0205C3B0(wk->connectApType);
    return 0x10;
}




/*
 * sdk:      ConnectTestRetry (test.o)
 */
static unsigned char func_0205F384(void)
{
    int result;

    result = SOCL_CalmDown();
    if (result != 0) {
        return 0xB;
    }
    result = SOC_Cleanup();
    if (result == 0 || result == -39) {
        return 9;
    }
    return 0xB;
}



/*
 * sdk:      MakeSOCConfig (libdwcac.TWL.HYB.a(test.o))
 */
void func_0205F3B0(tagACHOLD *hd, tagACWORK *wk, SOCConfig *sc)
{
    NCFGApInfo *info;
    unsigned char type;

    MI_CpuCopy8(&g_020A16A0, sc, sizeof(SOCConfig));
    sc->alloc = hd->alloc;
    sc->free = hd->free;
    if (wk->connectApType >= 0x12) {
        return;
    }
    type = DWCi_ConvConnectAPType(wk->connectApType);
    if (type <= 2) {
        info = &wk->userInfo[type].ap;
    } else {
        info = &wk->userInfoEx[type - 10].ap;
    }
    if (info->ip[0] != 0) {
        sc->flag = 0;
        sc->addr = ConvAddress(info->ip);
        sc->netmask = ConvNetMask(info->netmask);
        sc->router = ConvAddress(info->gateway);
        sc->dns1 = ConvAddress(info->dns[0]);
        sc->dns2 = ConvAddress(info->dns[1]);
    } else {
        sc->flag = 1;
        sc->addr = 0;
        sc->netmask = 0;
        sc->router = 0;
        sc->dns1 = 0;
        sc->dns2 = 0;
    }
    if (OS_IsRunOnTwl()) {
        if (info->mtu == 0) {
            sc->mtu = 0x578;
        } else if (info->mtu > 0x5dc) {
            sc->mtu = 0x5dc;
        } else if (info->mtu < 0x240) {
            sc->mtu = 0x240;
        } else {
            sc->mtu = info->mtu;
        }
    } else {
        sc->mtu = 0x240;
    }
    if (OS_IsRunOnTwl()) {
        if (info->mtu == 0x240) {
            sc->rwin = 0;
        } else {
            sc->rwin = wk->rwin;
        }
    } else {
        sc->rwin = 0;
    }
}


/*
 * sdk:      ConvAddress (libdwcac.TWL.HYB.a(test.o))
 */
unsigned long func_0205F504(unsigned char *add)
{
    unsigned long address;

    address = 0;
    address |= (unsigned long)add[0] << 24;
    address |= (unsigned long)add[1] << 16;
    address |= (unsigned long)add[2] << 8;
    address |= add[3];
    return ((address >> 24) & 0xff) | ((address >> 8) & 0xff00) | ((address << 8) & 0xff0000) | ((address << 24) & 0xff000000);
}


#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))



/*
 * sdk:      ConvNetMask (test.o)
 */
static unsigned long func_0205F558(unsigned char netmask)
{
    int i;
    int n;
    unsigned long netmask32;

    netmask32 = 0xFFFFFFFF;
    n = 32 - netmask;
    for (i = 0; i < n; i++) {
        netmask32 <<= 1;
    }
    return SWAP32(netmask32);
}



/*
 * sdk:      CheckSetDNS (libdwcac.TWL.HYB.a(test.o))
 */
void func_0205F5AC(tagACWORK *wk)
{
    NCFGApInfo *info;
    int dns;
    unsigned char type;
    SOCInAddr dns1;
    SOCInAddr dns2;

    if (wk->connectApType >= 0x12) {
        return;
    }
    type = DWCi_ConvConnectAPType(wk->connectApType);
    if (type <= 2) {
        info = &wk->userInfo[type].ap;
    } else {
        info = &wk->userInfoEx[type - 10].ap;
    }
    dns = info->dns[0][0] + info->dns[0][1] + info->dns[0][2] + info->dns[0][3];
    if (info->ip[0] != 0) {
        return;
    }
    if (dns == 0) {
        return;
    }
    dns1.addr = ConvAddress(info->dns[0]);
    dns2.addr = ConvAddress(info->dns[1]);
    SOC_SetResolver(&dns1, &dns2);
}
