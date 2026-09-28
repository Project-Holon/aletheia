/*
 * function: func_0205D318
 * address:  0x0205D318
 * packet:   pkt_0205D318
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_MakeSearchList (makelist.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   func_0205D470 0x0205D470 arm
 *   func_0205D848 0x0205D848 arm
 *   func_0205D8D4 0x0205D8D4 arm
 *   func_0205D4D8 0x0205D4D8 arm
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

extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
extern unsigned char func_0205D470(ACWORK *wk);
extern unsigned char func_0205D848(ACWORK *wk);
extern unsigned char func_0205D8D4(ACWORK *wk);
extern unsigned char func_0205D4D8(ACWORK *wk);
extern int OS_IsRunOnTwl(void);

int func_0205D318(int type)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    switch (type) {
    case 0:
        MIi_CpuClear32(0, wk->searchList, sizeof(wk->searchList));
        wk->searchListNum = func_0205D470(wk);
        break;
    case 1:
        wk->searchListNum = func_0205D848(wk);
        wk->searchListNo = func_0205D8D4(wk);
        if (wk->searchListNum == 0) {
            return 0;
        }
        break;
    case 2:
        MIi_CpuClear32(0, wk->searchList, sizeof(wk->searchList));
        wk->searchListNo = 0;
        wk->searchListNum = func_0205D4D8(wk);
        if (wk->searchListNum == 0) {
            return 0;
        }
        break;
    }
    OS_IsRunOnTwl();
    return 1;
}
