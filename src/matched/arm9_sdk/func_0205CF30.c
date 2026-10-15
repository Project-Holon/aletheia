/*
 * function: DWC_CheckNintendoZone
 * address:  0x0205CF30
 * packet:   pkt_0205CF30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckNintendoZone (dwc_connectinet.o)
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   MATHi_CRC16InitTableRev 0x020819FC arm
 *   WDS_DecryptWMBssDesc 0x0205A7CC arm
 *   WDS_IsAvailableForAutoConnect 0x0205A8FC arm
 *   DWCi_DivideFullApinfo 0x0205CCE4 arm
 */

typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

typedef struct {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
} WMGameInfo;

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
    WMGameInfo gameInfo;
} WMBssDesc;

typedef struct { unsigned char data[0x104]; } CRYPTORC4Context;
typedef struct { unsigned short table[256]; } MATHCRC16Table;
typedef struct {
    unsigned char head[0x20];
    char fullapinfo[0x50];
} WDSApInfo;

typedef struct {
    CRYPTORC4Context rc4context;
    unsigned short crcContext;
    MATHCRC16Table crcTable;
    WDSApInfo apinfo;
} DWCCheckNintendoZoneWork;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern int WDS_DecryptWMBssDesc(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable, WMBssDesc *bssdesc, WDSApInfo *apinfo);
extern int WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo);
extern void DWCi_DivideFullApinfo(char *fullapinfo, DWCApInfo *apinfo);

int DWC_CheckNintendoZone(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo)
{
    DWCCheckNintendoZoneWork *pwork;

    if (work == 0 || bssdesc == 0) {
        return 0;
    }
    MI_CpuFill8(work, 0, 0x376);
    if (bssdesc->gameInfo.userGameInfoLength + 0x10 == 0x80
        && bssdesc->gameInfo.magicNumber == 1
        && bssdesc->gameInfo.ggid == 0x857) {
        pwork = (DWCCheckNintendoZoneWork *)work;
        pwork->crcContext = 0;
        MATHi_CRC16InitTableRev(&pwork->crcTable, 0xa001);
        if (WDS_DecryptWMBssDesc(&pwork->rc4context, &pwork->crcContext, &pwork->crcTable, bssdesc, &pwork->apinfo)
            && WDS_IsAvailableForAutoConnect(&pwork->apinfo)) {
            if (apinfo != 0) {
                apinfo->aptype = 8;
                DWCi_DivideFullApinfo(pwork->apinfo.fullapinfo, apinfo);
            }
            return 1;
        }
    }
    return 0;
}
