/*
 * function: func_0205A558
 * address:  0x0205A558
 * packet:   pkt_0205A558
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_End (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   WM_End                           0x0208f43c arm
 *   gWdsWork                         0x02146abc data
 */

typedef struct WMScanExParam {
    unsigned char data[0x44];
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

extern int WM_End(void (*callback)(void *));

int func_0205A558(void (*callback)(void *))
{
    int errcode;

    if (callback == 0) {
        return -1;
    }
    gWdsWork->status = 3;
    gWdsWork = 0;
    errcode = WM_End(callback);
    if (errcode == 2) {
        errcode = 0;
    }
    return errcode;
}
