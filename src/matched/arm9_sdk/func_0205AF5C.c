/*
 * function: SortList
 * address:  0x0205AF5C
 * packet:   pkt_0205AF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SortList (beacon.o)
 *
 * symbols:
 *   DWCi_AC_IsSupportWPA 0x0205AB54 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   MIi_CpuClear32 0x02082A7C arm
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

extern int DWCi_AC_IsSupportWPA(WMBssDesc *bssDesc);
extern void MIi_CpuCopy32(const void *srcp, void *destp, unsigned long size);
extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);

void SortList(int no, ACWORK *wk)
{
    int i;
    ACFL list_buf;
    WMBssDesc bssdesc_buf;
    ACFL *list = wk->findList;
    WMBssDesc *bssdesc = wk->bssDesc;
    int swap;

    for (i = no - 1; i >= 0; i--) {
        swap = 0;
        if (wk->wpaSetting == 1 && DWCi_AC_IsSupportWPA(&bssdesc[no]) == 1) {
            if (list[no].rssi < list[i].rssi) {
                if (DWCi_AC_IsSupportWPA(&bssdesc[i]) == 0)
                    swap = 1;
            } else {
                swap = 1;
            }
        } else if (list[no].type >= 0x13 && list[no].type <= 0x16) {
            if (list[no].rssi >= list[i].rssi) {
                if ((list[i].type >= 0x13 && list[i].type <= 0x16)
                    || list[i].state + list[i].type + list[i].rssi + list[i].channel + list[i].find == 0)
                    swap = 1;
            }
        } else {
            if (list[no].rssi >= list[i].rssi) {
                if (wk->wpaSetting == 1) {
                    if (DWCi_AC_IsSupportWPA(&bssdesc[i]) == 0)
                        swap = 1;
                } else {
                    swap = 1;
                }
            } else if (list[i].type >= 0x13 && list[i].type <= 0x16) {
                swap = 1;
            }
        }
        if (swap == 1) {
            MIi_CpuCopy32(&list[i], &list_buf, sizeof(ACFL));
            MIi_CpuCopy32(&list[no], &list[i], sizeof(ACFL));
            MIi_CpuCopy32(&list_buf, &list[no], sizeof(ACFL));
            MIi_CpuCopy32(&bssdesc[i], &bssdesc_buf, sizeof(WMBssDesc));
            MIi_CpuCopy32(&bssdesc[no], &bssdesc[i], sizeof(WMBssDesc));
            MIi_CpuCopy32(&bssdesc_buf, &bssdesc[no], sizeof(WMBssDesc));
            no = i;
        }
    }
    MIi_CpuClear32(0, &list[10], sizeof(ACFL));
    MIi_CpuClear32(0, &bssdesc[10], sizeof(WMBssDesc));
}
