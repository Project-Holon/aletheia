/*
 * function: CompareListDiff
 * address:  0x0205AC50
 * packet:   pkt_0205AC50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CompareListDiff (beacon.o)
 *
 * symbols:
 *   DWCi_AC_CheckNintendoSSID 0x0205AAB0 arm
 *   strncmp 0x020949F4 arm
 *
 * strncmp is declared pure: the object keeps loads of *bssdesc (and of wk)
 * live across the call, which only a side-effect-free callee allows.
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
    unsigned char ssid[2][0x20];
    unsigned char unk80;
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

extern int DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc);
extern int strncmp(const char *s1, const char *s2, unsigned long n) __attribute__((pure));

int CompareListDiff(WMBssDesc *bssdesc, ACWORK *wk)
{
    int i;
    int type;

    if (bssdesc->ssidLength == 32 && (type = DWCi_AC_CheckNintendoSSID(bssdesc)) > 0) {
        return type;
    }
    for (i = 0; i < wk->findListNum; i++) {
        if (bssdesc->ssidLength == wk->bssDesc[i].ssidLength
            && strncmp((char *)bssdesc->ssid, (char *)wk->bssDesc[i].ssid, bssdesc->ssidLength) == 0) {
            return wk->findList[i].type;
        }
    }
    return -1;
}
