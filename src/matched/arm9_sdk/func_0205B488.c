/*
 * function: ConnectAP
 * address:  0x0205B488
 * packet:   pkt_0205B488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectAP (connect.o)
 *
 * symbols:
 *   WCM_GetPhase 0x021656A0 arm
 *   GetPowerMode 0x0205B790 arm
 *   GetAuthMode 0x0205B7B0 arm
 *   WCM_ConnectAsync 0x021652A4 arm
 *   OS_GetTick 0x020870D0 arm
 *   DWCi_AC_SetError 0x0205C2E4 arm
 */

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
    unsigned char gameInfo[0x80];
} WMBssDesc;

typedef struct {
    unsigned char state;
    unsigned char type;
    unsigned char rssi;
    unsigned char channel:7;
    unsigned char find:1;
} ACFL;

typedef struct {
    unsigned char data[36];
} ACSL;

typedef struct {
    unsigned char mode;
    unsigned char keyId;
    unsigned char key[80];
} WCMWepDesc;

typedef struct {
    unsigned char userInfo[3][0x100];
    unsigned char userInfoEx[3][0x200];
    ACSL searchList[21];
    ACFL findList[11];
    WMBssDesc bssDesc[11];
    unsigned long long timeOut;
    WCMWepDesc wepKey;
    unsigned char dmaNo;
    unsigned char powerMode:2;
    unsigned char authMode:2;
    unsigned char aroundCount:4;
    unsigned char flags;
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

extern long WCM_GetPhase(void);
extern unsigned long GetPowerMode(ACWORK *wk);
extern unsigned long GetAuthMode(ACWORK *wk);
extern long WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
extern unsigned long long OS_GetTick(void);
extern void DWCi_AC_SetError(int error);

static unsigned char ConnectAP(ACWORK *wk)
{
    int phase;
    WMBssDesc *bssdesc;
    unsigned long power_mode;
    unsigned long auth_mode;

    phase = WCM_GetPhase();
    bssdesc = &wk->bssDesc[wk->connectNo];
    if (phase == 3) {
        power_mode = GetPowerMode(wk);
        if (++wk->count > 3) {
            wk->count = 0;
            wk->findList[wk->connectNo].state = 1;
            return 9;
        }
        if (wk->count != 1) {
            if (wk->connectResult == 1) {
                wk->authMode = 0;
            } else if (wk->connectResult == 2) {
                wk->count = 0;
                wk->findList[wk->connectNo].state = 3;
                return 9;
            } else if (wk->connectResult == 3) {
                wk->count = 0;
                wk->findList[wk->connectNo].state = 4;
                return 9;
            } else if (wk->count == 3) {
                wk->authMode = 0;
            }
        }
        auth_mode = GetAuthMode(wk);
        WCM_ConnectAsync(bssdesc, &wk->wepKey, power_mode | auth_mode);
    } else if (phase == 9) {
        wk->count = 0;
        wk->timeOut = OS_GetTick();
        return 10;
    } else if (phase == 11) {
        DWCi_AC_SetError(0);
        return 0x11;
    } else if (phase > 11) {
        DWCi_AC_SetError(4);
        return 0x11;
    }
    return 8;
}
