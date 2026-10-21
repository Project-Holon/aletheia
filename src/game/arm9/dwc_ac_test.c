/*
 * file:     dwc_ac_test.c
 * unit:     yes
 * function: DWCi_AC_ConnectTest, ConnectTestStart, GetIPAddress, ConnectTestCreate, ConnectTestProcess, ConnectTestEnd, ConnectTestRetry, MakeSOCConfig, ConvAddress, ConvNetMask, CheckSetDNS
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
#include "../sdk_soc.h"

typedef struct ACFL {
    unsigned char state;
    unsigned char pad[3];
} ACFL;

typedef struct ACHOLD {
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
} ACHOLD;

#include "../sdk_ncfg.h"

#include "../sdk_dwc.h"

typedef struct ACWORK {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
    unsigned char searchList[0xbf4 - 0x900];
    ACFL findList[11];
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
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
    unsigned char padding;
    unsigned short passiveScanTime;
    unsigned short activeScanTime;
} ACWORK;

#include "../sdk_soc.h"

#include "dwc_ac.h"
#include "../ov009/wcm_system.h"
extern unsigned char ConnectTestStart(ACWORK *wk);
extern unsigned char GetIPAddress(ACWORK *wk);
static unsigned char ConnectTestCreate(void);
extern unsigned char ConnectTestProcess(ACWORK *wk);
static unsigned char ConnectTestEnd(ACWORK *wk);
static unsigned char ConnectTestRetry(void);
#include "../ov009/dwc_netcheck.h"
extern void MakeSOCConfig(ACHOLD *hd, ACWORK *wk, struct SOCConfig *sc);
#include "../ov009/soc.h"
#include "os_emulator.h"
extern void CheckSetDNS(ACWORK *wk);
#include "os_tick.h"
#include "../ov009/socl_cleanup.h"
#include "mi_memory.h"
extern unsigned long ConvAddress(unsigned char *add);
static unsigned long ConvNetMask(unsigned char netmask);
unsigned char DWCi_AC_ConnectTest(void);
extern int SOCLiYieldWait;
extern int CPSNoIpReason;
extern SOCConfig g_020A16A0;






/*
 * sdk:      DWCi_AC_ConnectTest (libdwcac.TWL.HYB.a(test.o))
 */
unsigned char DWCi_AC_ConnectTest(void)
{
    unsigned char phase;
    ACWORK *wk;

    phase = DWCi_AC_GetPhase();
    wk = (ACWORK *)DWCi_AC_GetMemPtr(0x10);
    if (WCM_GetPhase() == 9) {
        switch (phase) {
        case 10:
            phase = ConnectTestStart((ACWORK *)wk);
            break;
        case 12:
            phase = GetIPAddress((ACWORK *)wk);
            break;
        case 13:
            phase = ConnectTestCreate();
            break;
        case 14:
            phase = ConnectTestProcess((ACWORK *)wk);
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
unsigned char ConnectTestStart(ACWORK *wk)
{
    ACHOLD *hd;
    struct SOCConfig *sc;

    hd = (ACHOLD *)DWCi_AC_GetMemPtr(1);
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
unsigned char GetIPAddress(ACWORK *wk)
{
    unsigned char ap_type;
    unsigned long long t;

    if (SOC_GetHostID() != 0) {
        CheckSetDNS((ACWORK *)wk);
        if (wk->skipNetCheck == 1) {
            return 0xf;
        }
        ap_type = DWCi_ConvConnectAPType(wk->connectApType);
        if (ap_type >= 10 && ap_type <= 12 && OS_IsRunOnTwl()
            && wk->userInfoEx[(unsigned char)(ap_type - 10)].apEx.proxyMode != 0) {
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
static unsigned char ConnectTestCreate(void)
{
    DWCNetcheckParam *nc = (DWCNetcheckParam *)DWCi_AC_GetMemPtr(8);

    if (DWC_Netcheck_Create(nc) == 0) {
        return 0xE;
    }
    DWCi_AC_SetError(3);
    return 0x11;
}






/*
 * sdk:      ConnectTestProcess (libdwcac.TWL.HYB.a(test.o))
 */
unsigned char ConnectTestProcess(ACWORK *wk)
{
    ACHOLD *hd;
    int result;

    hd = (ACHOLD *)DWCi_AC_GetMemPtr(1);
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
static unsigned char ConnectTestEnd(ACWORK *wk)
{
    DWCi_AC_SetApType(wk->connectApType);
    DWCi_AC_CopyExSetting(wk->connectApType);
    return 0x10;
}




/*
 * sdk:      ConnectTestRetry (test.o)
 */
static unsigned char ConnectTestRetry(void)
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
void MakeSOCConfig(ACHOLD *hd, ACWORK *wk, SOCConfig *sc)
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
        sc->addr.addr = ConvAddress(info->ip);
        sc->netmask.addr = ConvNetMask(info->netmask);
        sc->router.addr = ConvAddress(info->gateway);
        sc->dns1.addr = ConvAddress(info->dns[0]);
        sc->dns2.addr = ConvAddress(info->dns[1]);
    } else {
        sc->flag = 1;
        sc->addr.addr = 0;
        sc->netmask.addr = 0;
        sc->router.addr = 0;
        sc->dns1.addr = 0;
        sc->dns2.addr = 0;
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
unsigned long ConvAddress(unsigned char *add)
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
static unsigned long ConvNetMask(unsigned char netmask)
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
void CheckSetDNS(ACWORK *wk)
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
    SOC_SetResolver((long unsigned int *)(unsigned int *)(&dns1), (long unsigned int *)(unsigned int *)(&dns2));
}
