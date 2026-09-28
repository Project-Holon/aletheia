/*
 * function: func_0205D588
 * address:  0x0205D588
 * packet:   pkt_0205D588
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MakeUserList (makelist.o)
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
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

extern int OS_IsRunOnTwl(void);

static inline int SetList(ACSL *list, const unsigned char *ssid, unsigned char type)
{
    unsigned char len;

    for (len = 0; len < 32; len++) {
        if (ssid[len] == 0) {
            break;
        }
        list->ssid[len] = ssid[len];
    }
    if (len != 0) {
        list->length = len;
        list->type = type;
        return 1;
    }
    return 0;
}

unsigned char func_0205D588(ACWORK *wk)
{
    int i;
    unsigned char num;
    NCFGSlotInfo *info;
    NCFGSlotInfoEx *info2;
    ACSL *list;

    num = 0;
    info = wk->userInfo;
    info2 = wk->userInfoEx;
    list = wk->searchList;
    for (i = 0; i < 3; i++, info++) {
        if ((wk->connectType == 0 || wk->connectType == i + 1) && info->ap.setType != 0xff) {
            if (SetList(list, info->ap.ssid[0], i)) {
                num++;
                list++;
            }
            if (info->ap.setType == 1) {
                if (SetList(list, info->ap.ssid[1], i + 3)) {
                    num++;
                    list++;
                }
            }
        }
    }
    if (OS_IsRunOnTwl()) {
        for (i = 0; i < 3; i++, info2++) {
            if ((wk->connectType == 0 || wk->connectType == i + 11) && info2->ap.setType != 0xff) {
                if (SetList(list, info2->ap.ssid[0], i + 6)) {
                    num++;
                    list++;
                }
                if (info2->ap.setType == 1 || info2->ap.setType == 0x11) {
                    if (SetList(list, info2->ap.ssid[1], i + 9)) {
                        num++;
                        list++;
                    }
                    if (SetList(list, info2->apEx.ssid[0], i + 12)) {
                        num++;
                        list++;
                    }
                    if (SetList(list, info2->apEx.ssid[1], i + 15)) {
                        num++;
                        list++;
                    }
                }
            }
        }
    }
    return num;
}
