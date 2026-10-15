/*
 * function: DWCi_AC_GetBeacon
 * address:  0x0205A938
 * packet:   pkt_0205A938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_GetBeacon (beacon.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   DWCi_AC_GetPhase 0x0205C2C4 arm
 *   DWCi_AC_SetStealthChannel 0x0205DF6C arm
 *   CompareList 0x0205ABD4 arm
 *   CompareListDiff 0x0205AC50 arm
 *   AddList 0x0205ACE4 arm
 *   SortList 0x0205AF5C arm
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

typedef struct {
    unsigned char pad[0xb];
    unsigned char beacon:4;
} ACHOLD;

extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern unsigned char DWCi_AC_GetPhase(void);
extern void DWCi_AC_SetStealthChannel(unsigned short channel);
extern int CompareList(WMBssDesc *bssdesc, unsigned char num, ACSL *list);
extern int CompareListDiff(WMBssDesc *bssdesc, ACWORK *wk);
extern int AddList(int type, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk);
extern void SortList(int no, ACWORK *wk);

void DWCi_AC_GetBeacon(WMBssDesc *bssdesc)
{
    int ap_type = -1;
    unsigned char channel;
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    int no;

    hd->beacon = 1;
    switch (DWCi_AC_GetPhase()) {
    case 3:
        channel = wk->searchChannel;
        if (bssdesc->ssidLength == 0 || bssdesc->ssid[0] == 0) {
            DWCi_AC_SetStealthChannel(bssdesc->channel);
        } else if (bssdesc->ssidLength == 1 && bssdesc->ssid[0] == 0x20) {
            DWCi_AC_SetStealthChannel(bssdesc->channel);
            ap_type = CompareList(bssdesc, wk->searchListNum, wk->searchList);
        } else {
            ap_type = CompareList(bssdesc, wk->searchListNum, wk->searchList);
        }
        break;
    case 4:
        channel = wk->bssDesc[wk->searchListNo].channel - 1;
        ap_type = CompareListDiff(bssdesc, wk);
        if (ap_type >= 0) {
            wk->findList[wk->searchListNo].find = 1;
        }
        break;
    case 5:
        channel = wk->searchChannel;
        ap_type = CompareList(bssdesc, 1, &wk->searchList[wk->searchListNo]);
        if (ap_type >= 0) {
            wk->searchList[wk->searchListNo].find = 1;
        }
        break;
    default:
        return;
    }
    if (ap_type >= 0) {
        no = AddList(ap_type, bssdesc, channel, wk);
        SortList(no, wk);
    }
}
