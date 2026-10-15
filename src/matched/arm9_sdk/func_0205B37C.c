/*
 * function: ConnectStart
 * address:  0x0205B37C
 * packet:   pkt_0205B37C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectStart (connect.o)
 *
 * symbols:
 *   GetConnectType 0x0205B5EC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GetWepKey 0x0205B7D0 arm
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

extern unsigned char GetConnectType(ACWORK *wk);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int GetWepKey(ACWORK *wk, unsigned char type, WCMWepDesc *wepkey);

unsigned char ConnectStart(ACWORK *wk)
{
    WMBssDesc *bssdesc = &wk->bssDesc[wk->connectNo];

    wk->connectApType = GetConnectType(wk);
    MI_CpuFill8(&wk->wepKey, 0, sizeof(WCMWepDesc));
    if (GetWepKey(wk, wk->connectApType, &wk->wepKey)) {
        wk->authMode = 1;
        if (((bssdesc->capaInfo >> 4) & 1) == 0) {
            wk->findList[wk->connectNo].state = 3;
            return 9;
        }
        if (wk->connectApType == 0x12 && bssdesc->ssid[9] == 0) {
            wk->findList[wk->connectNo].state = 3;
            return 9;
        }
    } else {
        wk->authMode = 0;
        if (((bssdesc->capaInfo >> 4) & 1) == 1) {
            wk->findList[wk->connectNo].state = 3;
            return 9;
        }
    }
    wk->count = 0;
    wk->connectResult = 0;
    return 8;
}
