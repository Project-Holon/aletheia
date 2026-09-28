/*
 * function: func_0205F1B8
 * address:  0x0205F1B8
 * packet:   pkt_0205F1B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetIPAddress (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   SOC_GetHostID                    0x0215f7b0 arm
 *   CheckSetDNS                      0x0205f5ac arm
 *   DWCi_ConvConnectAPType           0x0205c4c8 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   OS_GetTick                       0x020870d0 arm
 *   _ll_udiv                         0x0209c00c arm
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

extern long SOC_GetHostID(void);
extern void CheckSetDNS(tagACWORK *wk);
extern unsigned long long OS_GetTick(void);

unsigned char func_0205F1B8(tagACWORK *wk)
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
