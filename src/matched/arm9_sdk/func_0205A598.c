/*
 * function: func_0205A598
 * address:  0x0205A598
 * packet:   pkt_0205A598
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_StartScan (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   WM_GetAllowedChannel             0x0208ee60 arm
 *   WM_GetDispersionScanPeriod       0x0208efc4 arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   WM_StartScanEx                   0x0208f698 arm
 *   gWdsWork                         0x02146abc data
 *   WDSScanCallback                  0x0205a2dc arm
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

extern unsigned short WM_GetAllowedChannel(void);
extern unsigned short WM_GetDispersionScanPeriod(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern void WDSScanCallback(void *arg);

int func_0205A598(void (*callback)(void *))
{
    int errcode;

    if (callback == 0) {
        return -1;
    }
    gWdsWork->scanparam.scanBuf = (WMBssDesc *)gWdsWork->scanbuf;
    gWdsWork->scanparam.scanBufSize = 0x400;
    gWdsWork->scanparam.channelList = WM_GetAllowedChannel();
    gWdsWork->scanparam.maxChannelTime = WM_GetDispersionScanPeriod();
    gWdsWork->scanparam.scanType = 1;
    MI_CpuFill8(gWdsWork->scanparam.bssid, 0xff, 6);
    gWdsWork->scancb = callback;
    gWdsWork->status = 1;
    errcode = WM_StartScanEx(WDSScanCallback, &gWdsWork->scanparam);
    if (errcode == 2) {
        errcode = 0;
    }
    return errcode;
}
