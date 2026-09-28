/*
 * function: func_0205B7D0
 * address:  0x0205B7D0
 * packet:   pkt_0205B7D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetWepKey (connect.o)
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   DWCi_AC_GetNintendoUSBWepKey 0x0205EB20 arm
 *   DWCi_AC_GetNintendoShopWepKey 0x0205EA44 arm
 */

typedef struct {
    unsigned char ispId[0x40];
    unsigned char ssid[2][0x20];
    unsigned char wep[4][0x10];
    unsigned char unkC0[0x11];
    unsigned char wep40[5];
    unsigned char unkD6[0x10];
    unsigned char wepMode:2;
    unsigned char wepNotation:6;
    unsigned char setType;
    unsigned char unkE8[8];
} NCFGApInfo;

typedef struct {
    unsigned char passphrase[0x20];
    unsigned char pmk[0x20];
    unsigned char unk40[0x41];
    unsigned char wpaMode;
    unsigned char unk82[0x6e];
} NCFGApInfoEx;

typedef struct {
    NCFGApInfo ap;
    unsigned char wifi[14];
    unsigned short crc;
} NCFGSlotInfo;

typedef struct {
    NCFGApInfo ap;
    unsigned char wifi[14];
    unsigned short crc;
    NCFGApInfoEx apEx;
    unsigned char rsvEx[14];
    unsigned short crcEx;
} NCFGSlotInfoEx;

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
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
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

extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void DWCi_AC_GetNintendoUSBWepKey(char *ssid, unsigned char *wep);
extern void DWCi_AC_GetNintendoShopWepKey(char *ssid, unsigned char *wep);

int func_0205B7D0(ACWORK *wk, unsigned char type, WCMWepDesc *wepkey)
{
    NCFGSlotInfo *info;
    NCFGSlotInfoEx *info2;

    info = wk->userInfo;
    info2 = wk->userInfoEx;
    switch (type) {
    case 2:
        info++;
    case 1:
        info++;
    case 0:
        wepkey->mode = info->ap.wepMode;
        MI_CpuCopy8(info->ap.wep[0], wepkey->key, 0x10);
        break;
    case 5:
        info++;
    case 4:
        info++;
    case 3:
        wepkey->mode = 1;
        MI_CpuCopy8(info->ap.wep40, wepkey->key, 5);
        break;
    case 8:
        info2++;
    case 7:
        info2++;
    case 6:
        if (info2->ap.setType == 0x10 || info2->ap.setType == 0x12 || info2->ap.setType == 0x13) {
            wepkey->mode = info2->apEx.wpaMode;
            wepkey->keyId = 0x20;
            MI_CpuCopy8(info2->apEx.passphrase, wepkey->key, 0x20);
            wepkey->key[0x20] = 0;
        } else {
            wepkey->mode = info2->ap.wepMode;
            MI_CpuCopy8(info2->ap.wep[0], wepkey->key, 0x10);
        }
        break;
    case 11:
        info2++;
    case 10:
        info2++;
    case 9:
        wepkey->mode = 1;
        MI_CpuCopy8(info2->ap.wep40, wepkey->key, 5);
        break;
    case 14:
        info2++;
    case 13:
        info2++;
    case 12:
        wepkey->mode = 4;
        wepkey->keyId = 0x20;
        MI_CpuCopy8(info2->apEx.passphrase, wepkey->key, 0x20);
        wepkey->key[0x20] = 0;
        break;
    case 17:
        info2++;
    case 16:
        info2++;
    case 15:
        wepkey->mode = 6;
        wepkey->keyId = 0x20;
        MI_CpuCopy8(info2->apEx.pmk, wepkey->key, 0x20);
        wepkey->key[0x20] = 0;
        break;
    case 18:
        wepkey->mode = 2;
        DWCi_AC_GetNintendoUSBWepKey((char *)wk->bssDesc[wk->connectNo].ssid, wepkey->key);
        break;
    case 19:
        wepkey->mode = 2;
        DWCi_AC_GetNintendoShopWepKey((char *)wk->bssDesc[wk->connectNo].ssid, wepkey->key);
        break;
    case 20:
        break;
    }
    return wepkey->mode != 0;
}
