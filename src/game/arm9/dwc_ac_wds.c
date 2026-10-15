/*
 * file:     dwc_ac_wds.c
 * unit:     yes
 * function: func_0205A2C8, WDSScanCallback, func_0205A4C8, WDS_Initialize, WDS_End, WDS_StartScan, WDS_EndScan, WDS_GetApInfoByIndex, WDS_GetApInfoAll, WDS_DecryptWMBssDesc, IsValidApnum, WDS_IsAvailableForAutoConnect
 * address:  0x0205A2C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DC_InvalidateRange               0x020862b8 arm
 *   WDS_DecryptWMBssDesc             0x0205a7cc arm
 *   gWdsWork                         0x02146abc data
 *   MI_CpuFill8                      0x02082bcc arm
 *   MATHi_CRC16InitTableRev          0x020819fc arm
 *   WM_Initialize                    0x0208f370 arm
 *   WM_End                           0x0208f43c arm
 *   WM_GetAllowedChannel             0x0208ee60 arm
 *   WM_GetDispersionScanPeriod       0x0208efc4 arm
 *   WM_StartScanEx                   0x0208f698 arm
 *   WDSScanCallback                  0x0205a2dc arm
 *   WM_EndScan                       0x0208f808 arm
 *   MI_CpuCopy8                      0x02082d44 arm
 *   WDS_GetApInfoByIndex             0x0205a688 arm
 *   CRYPTO_RC4Init                   0x0202fab4 arm
 *   CRYPTO_RC4Encrypt                0x0202fb34 arm
 *   MATHi_CRC16UpdateRev             0x02081a80 arm
 *   MATH_CalcCRC16                   0x02081b64 arm
 *   _ZZ20WDS_DecryptWMBssDescP16CRYPTORC4ContextPtP14MATHCRC16TablePK9WMBssDescP9WDSApInfoE5magic 0x020a1618 data
 *   g_020A1618                       0x020A1618 data
 *   IsValidApnum                     0x0205a8c8 arm
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
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern int WM_Initialize(void *wmSysBuf, void (*callback)(void *), unsigned short dmaNo);
extern int WM_End(void (*callback)(void *));
extern unsigned short WM_GetAllowedChannel(void);
extern unsigned short WM_GetDispersionScanPeriod(void);
extern int WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern void WDSScanCallback(void *arg);
extern int WM_EndScan(void (*callback)(void *));
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern int WDS_GetApInfoByIndex(int index, WDSBriefApInfo *briefapinfo);
extern void CRYPTO_RC4Init(CRYPTORC4Context *context, const void *key, unsigned long key_len);
extern void CRYPTO_RC4Encrypt(CRYPTORC4Context *context, const void *in, unsigned long length, void *out);
extern void MATHi_CRC16UpdateRev(MATHCRC16Table *table, unsigned short *context, const void *input, unsigned long length);
extern unsigned short MATH_CalcCRC16(MATHCRC16Table *table, const void *data, unsigned long dataLength);
extern int IsValidApnum(unsigned char *apnum);
unsigned char WDSGetRssi8(unsigned char rssi);
unsigned long WDS_GetWorkAreaSize(void);
int WDS_Initialize(void *wdsWork, void (*callback)(void *), unsigned short dmaNo);
int WDS_End(void (*callback)(void *));
int WDS_StartScan(void (*callback)(void *));
int WDS_EndScan(void (*callback)(void *));
int WDS_GetApInfoAll(WDSBriefApInfo *briefapinfo);
int WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo);
extern WDSWork *gWdsWork;
extern const unsigned char g_020A1618[4];





unsigned char WDSGetRssi8(unsigned char rssi)
{
    int v = rssi >> 2;
    if ((rssi & 2) == 0)
        v += 25;
    return (unsigned char)v;
}






/*
 * sdk:      WDSScanCallback (libdwcac.TWL.HYB.a(wds.o))
 */
void WDSScanCallback(void *arg)
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





unsigned long WDS_GetWorkAreaSize(void)
{
    return 0x1da0;
}





/*
 * sdk:      WDS_Initialize (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_Initialize(void *wdsWork, void (*callback)(void *), unsigned short dmaNo)
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




/*
 * sdk:      WDS_End (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_End(void (*callback)(void *))
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



/*
 * sdk:      WDS_StartScan (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_StartScan(void (*callback)(void *))
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



/*
 * sdk:      WDS_EndScan (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_EndScan(void (*callback)(void *))
{
    int errcode;

    if (callback == 0) {
        return -1;
    }
    gWdsWork->status = 2;
    errcode = WM_EndScan(callback);
    if (errcode == 2) {
        errcode = 0;
    }
    return errcode;
}



/*
 * sdk:      WDS_GetApInfoByIndex (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_GetApInfoByIndex(int index, WDSBriefApInfo *briefapinfo)
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



/*
 * sdk:      WDS_GetApInfoAll (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_GetApInfoAll(WDSBriefApInfo *briefapinfo)
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



/*
 * sdk:      WDS_DecryptWMBssDesc (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_DecryptWMBssDesc(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable,
                  const WMBssDesc *bssDesc, WDSApInfo *apinfo)
{
    unsigned char rc4key[8];
    unsigned char *pCrcData;
    unsigned short crc;

    if (bssDesc == 0 || rc4context == 0 || crcContext == 0 || crcTable == 0 || apinfo == 0) {
        return 0;
    }
    MI_CpuCopy8(bssDesc->gameInfo.userGameInfo, apinfo, sizeof(WDSApInfo));
    MI_CpuCopy8(g_020A1618, rc4key, 4);
    MI_CpuCopy8(&bssDesc->bssid[2], &rc4key[4], 4);
    CRYPTO_RC4Init(rc4context, rc4key, sizeof(rc4key));
    CRYPTO_RC4Encrypt(rc4context, apinfo, sizeof(WDSApInfo), apinfo);
    pCrcData = (unsigned char *)apinfo;
    MATHi_CRC16UpdateRev(crcTable, crcContext, pCrcData, 0x6e);
    crc = MATH_CalcCRC16(crcTable, pCrcData, 0x6e);
    if (crc == apinfo->crc || apinfo->crc == 0) {
        return 1;
    }
    MI_CpuFill8(apinfo, 0, sizeof(WDSApInfo));
    return 0;
}


/*
 * sdk:      IsValidApnum (libdwcac.TWL.HYB.a(wds.o))
 */
int IsValidApnum(unsigned char *apnum)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (apnum[i] < 0x20 || apnum[i] > 0x7e) {
            return 0;
        }
    }
    return 1;
}



/*
 * sdk:      WDS_IsAvailableForAutoConnect (libdwcac.TWL.HYB.a(wds.o))
 */
int WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo)
{
    if ((apinfo->infoflag & 2) && IsValidApnum(apinfo->apnum) && apinfo->encryptflag <= 3) {
        return 1;
    }
    return 0;
}
