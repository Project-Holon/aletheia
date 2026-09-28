/*
 * function: func_0205A724
 * address:  0x0205A724
 * packet:   pkt_0205A724
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_GetApInfoAll (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 *   WDS_GetApInfoByIndex             0x0205a688 arm
 *   gWdsWork                         0x02146abc data
 */

typedef struct WMBssDesc WMBssDesc;

typedef struct WMScanExParam {
    WMBssDesc *scanBuf;
    unsigned short scanBufSize;
    unsigned short channelList;
    unsigned short maxChannelTime;
    unsigned char bssid[6];
    unsigned short scanType;
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned short ssidMatchLength;
    unsigned char rsv[14];
} WMScanExParam;

typedef struct MATHCRC16Table {
    unsigned short table[256];
} MATHCRC16Table;

typedef struct CRYPTORC4Context {
    unsigned char data[0x108];
} CRYPTORC4Context;

typedef struct WDSApInfo {
    unsigned char ssid[32];
    unsigned char apnum[10];
    unsigned short hotspotid;
    unsigned char hotspotname[24];
    unsigned char wepkey[32];
    unsigned char channel;
    unsigned char encryptflag;
    unsigned char infoflag;
    unsigned char reserve[5];
    unsigned short mtu;
    unsigned short crc;
} WDSApInfo;

typedef struct WDSWork {
    unsigned char wmwork[3840];
    unsigned char scanbuf[1024];
    WMScanExParam scanparam;
    void (*scancb)(void *);
    WDSApInfo apinfo[16];
    unsigned short rssi[16];
    unsigned short tgid[16];
    long apnum;
    long apindex;
    unsigned long status;
    unsigned short crcContext;
    MATHCRC16Table crcTable;
    CRYPTORC4Context rc4context;
} WDSWork;

extern WDSWork *gWdsWork;

typedef struct WDSBriefApInfo {
    int isvalid;
    unsigned short rssi;
    WDSApInfo apinfo;
} WDSBriefApInfo;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int WDS_GetApInfoByIndex(int index, WDSBriefApInfo *briefapinfo);

int func_0205A724(WDSBriefApInfo *briefapinfo)
{
    int index;

    if (gWdsWork->status != 2) {
        return -1;
    }
    MI_CpuFill8(briefapinfo, 0, sizeof(WDSBriefApInfo) * 16);
    for (index = 0; index < 16; index++) {
        briefapinfo[index].isvalid = 0;
    }
    for (index = 0; index < gWdsWork->apnum; index++) {
        if (WDS_GetApInfoByIndex(index, &briefapinfo[index]) == -1) {
            break;
        }
    }
    return 0;
}
