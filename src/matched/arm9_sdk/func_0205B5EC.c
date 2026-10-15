/*
 * function: GetConnectType
 * address:  0x0205B5EC
 * packet:   pkt_0205B5EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetConnectType (connect.o)
 *
 * symbols:
 *   DWCi_AC_GetSearchListNum 0x0205D434 arm
 *   DWCi_AC_CheckNintendoSSID 0x0205AAB0 arm
 *   DWCi_AC_CheckFreespot 0x0205D3E0 arm
 *   strncmp 0x020949F4 arm
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
    unsigned char find:4;
    unsigned char duplicate:4;
    unsigned char type;
    unsigned char channel;
    unsigned char length;
    unsigned char ssid[32];
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
    unsigned char connectType:4;
    unsigned char skipNetCheck:1;
    unsigned char useDSWireless:1;
    unsigned char duplicateFlag:1;
    unsigned char wpaSetting:1;
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

extern unsigned char DWCi_AC_GetSearchListNum(void);
extern int DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc);
extern unsigned char DWCi_AC_CheckFreespot(WMBssDesc *bssdesc);
extern int strncmp(const char *s1, const char *s2, unsigned long n);

unsigned char GetConnectType(ACWORK *wk)
{
    WMBssDesc *bssdesc;
    int type;
    int i;
    int j;
    unsigned char max;

    bssdesc = &wk->bssDesc[wk->connectNo];
    type = 0;
    j = 0;
    max = DWCi_AC_GetSearchListNum();
    if (!wk->duplicateFlag) {
        if (bssdesc->ssidLength == 32) {
            if ((type = DWCi_AC_CheckNintendoSSID(bssdesc)) > 0) {
                j++;
            } else {
                type = 0;
            }
        } else if (bssdesc->ssidLength == 8) {
            if ((type = DWCi_AC_CheckFreespot(bssdesc)) != 0) {
                j++;
            } else {
                type = 0;
            }
        }
        for (i = 0; i < max; i++) {
            if (bssdesc->ssidLength == wk->searchList[i].length
                && strncmp((char *)bssdesc->ssid, (char *)wk->searchList[i].ssid, bssdesc->ssidLength) == 0) {
                if (j == 0) {
                    type = wk->searchList[i].type;
                } else {
                    wk->searchList[i].duplicate = 1;
                    wk->duplicateFlag = 1;
                }
                j++;
            }
        }
    } else {
        j = 0;
        i = 0;
        for (; j < max; j++) {
            if (wk->searchList[j].duplicate == 1) {
                if (i == 0) {
                    wk->searchList[j].duplicate = 0;
                    type = wk->searchList[j].type;
                }
                i++;
            }
        }
        if (i == 1) {
            wk->duplicateFlag = 0;
        }
    }
    return (unsigned char)type;
}
