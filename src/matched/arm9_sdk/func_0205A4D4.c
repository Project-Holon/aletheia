/*
 * function: func_0205A4D4
 * address:  0x0205A4D4
 * packet:   pkt_0205A4D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_Initialize (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   WDS_GetWorkAreaSize              0x0205a4c8 arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   MATHi_CRC16InitTableRev          0x020819fc arm
 *   WM_Initialize                    0x0208f370 arm
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

extern unsigned long WDS_GetWorkAreaSize(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern int WM_Initialize(void *wmSysBuf, void (*callback)(void *), unsigned short dmaNo);

int func_0205A4D4(void *wdsWork, void (*callback)(void *), unsigned short dmaNo)
{
    int errcode;

    if (callback == 0) {
        return -1;
    }
    gWdsWork = (WDSWork *)wdsWork;
    MI_CpuFill8(gWdsWork, 0, WDS_GetWorkAreaSize());
    gWdsWork->status = 0;
    gWdsWork->crcContext = 0;
    MATHi_CRC16InitTableRev(&gWdsWork->crcTable, 0xa001);
    errcode = WM_Initialize(gWdsWork, callback, dmaNo);
    if (errcode == 2) {
        errcode = 0;
    }
    return errcode;
}
