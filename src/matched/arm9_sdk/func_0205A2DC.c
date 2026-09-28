/*
 * function: func_0205A2DC
 * address:  0x0205A2DC
 * packet:   pkt_0205A2DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDSScanCallback (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   DC_InvalidateRange               0x020862b8 arm
 *   WDS_DecryptWMBssDesc             0x0205a7cc arm
 *   WDSGetRssi8                      0x0205a2c8 arm
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

typedef struct WMGameInfo {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
    unsigned char attribute;
    unsigned short parentMaxSize;
    unsigned short childMaxSize;
    unsigned char userGameInfo[0x70];
} WMGameInfo;

struct WMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned char pad[0x36];
    WMGameInfo gameInfo;
};

typedef struct WMStartScanExCallback {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short wlCmdID;
    unsigned short wlResult;
    unsigned short state;
    unsigned short channelList;
    unsigned char reserved[2];
    unsigned short bssDescCount;
    WMBssDesc *bssDesc[16];
    unsigned short linkLevel[16];
} WMStartScanExCallback;

extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern int WDS_DecryptWMBssDesc(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable,
                                const WMBssDesc *bssDesc, WDSApInfo *apinfo);
extern unsigned char WDSGetRssi8(unsigned char rssi);

void func_0205A2DC(void *arg)
{
    WMStartScanExCallback *pParam;
    unsigned long i;
    unsigned long j;
    int duplicated;

    DC_InvalidateRange(gWdsWork->scanbuf, 0x400);
    pParam = (WMStartScanExCallback *)arg;
    if (pParam->errcode == 0 && pParam->state == 5) {
        for (i = 0; i < pParam->bssDescCount; i++) {
            if (pParam->bssDesc[i]->gameInfo.userGameInfoLength + 16 == 0x80
                && pParam->bssDesc[i]->gameInfo.magicNumber == 1
                && pParam->bssDesc[i]->gameInfo.ggid == 0x857) {
                duplicated = 0;
                for (j = 0; j < gWdsWork->apnum; j++) {
                    if (gWdsWork->tgid[j] == pParam->bssDesc[i]->gameInfo.tgid) {
                        duplicated = 1;
                        break;
                    }
                }
                if (duplicated == 1) {
                    continue;
                }
                if (WDS_DecryptWMBssDesc(&gWdsWork->rc4context, &gWdsWork->crcContext, &gWdsWork->crcTable,
                                         pParam->bssDesc[i], &gWdsWork->apinfo[gWdsWork->apindex])) {
                    gWdsWork->rssi[gWdsWork->apindex] = WDSGetRssi8((unsigned char)pParam->bssDesc[i]->rssi);
                    gWdsWork->tgid[gWdsWork->apindex] = pParam->bssDesc[i]->gameInfo.tgid;
                    gWdsWork->apindex = (gWdsWork->apindex + 1) % 16;
                    gWdsWork->apnum++;
                    if (gWdsWork->apnum > 16) {
                        gWdsWork->apnum = 16;
                    }
                }
            }
        }
    }
    gWdsWork->status = 2;
    if (gWdsWork->scancb != 0) {
        gWdsWork->scancb(arg);
    }
}
