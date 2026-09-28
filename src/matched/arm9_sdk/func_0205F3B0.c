/*
 * function: func_0205F3B0
 * address:  0x0205F3B0
 * packet:   pkt_0205F3B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MakeSOCConfig (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   MI_CpuCopy8                      0x02082d44 arm
 *   DWCi_ConvConnectAPType           0x0205c4c8 arm
 *   ConvAddress                      0x0205f504 arm
 *   ConvNetMask                      0x0205f558 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   DWC_AC_SOC_CONFIG                0x020a16a0 data
 *   g_020A16A0                       0x020A16A0 data
 */

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

typedef struct NCFGSlotInfoEx {
    NCFGApInfo ap;
    unsigned char rest0[0x92];
    unsigned char exFlag;
    unsigned char rest1[0x7d];
} NCFGSlotInfoEx;

typedef struct tagACFL {
    unsigned char state;
    unsigned char pad[3];
} tagACFL;

typedef struct tagACWORK {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
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

extern unsigned char DWCi_ConvConnectAPType(unsigned char type);
extern int OS_IsRunOnTwl(void);

typedef struct tagACHOLD {
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
} tagACHOLD;

typedef struct SOCConfig {
    unsigned long vendor;
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
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

extern SOCConfig g_020A16A0;
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern unsigned long ConvAddress(unsigned char *add);
extern unsigned long ConvNetMask(unsigned char netmask);

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
