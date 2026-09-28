/*
 * function: func_0205A688
 * address:  0x0205A688
 * packet:   pkt_0205A688
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_GetApInfoByIndex (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 *   MI_CpuCopy8                      0x02082d44 arm
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
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);

int func_0205A688(int index, WDSBriefApInfo *briefapinfo)
{
    if (gWdsWork->status != 2) {
        return -1;
    }
    if (index < 0 || index >= gWdsWork->apnum) {
        return -1;
    }
    MI_CpuFill8(briefapinfo, 0, sizeof(WDSBriefApInfo));
    briefapinfo->isvalid = 1;
    briefapinfo->rssi = gWdsWork->rssi[index];
    MI_CpuCopy8(&gWdsWork->apinfo[index], &briefapinfo->apinfo, sizeof(WDSApInfo));
    return 0;
}
