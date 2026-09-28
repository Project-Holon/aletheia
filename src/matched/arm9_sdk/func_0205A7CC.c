/*
 * function: func_0205A7CC
 * address:  0x0205A7CC
 * packet:   pkt_0205A7CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_DecryptWMBssDesc (libdwcac.TWL.HYB.a(wds.o))
 *
 * symbols:
 *   MI_CpuCopy8                      0x02082d44 arm
 *   CRYPTO_RC4Init                   0x0202fab4 arm
 *   CRYPTO_RC4Encrypt                0x0202fb34 arm
 *   MATHi_CRC16UpdateRev             0x02081a80 arm
 *   MATH_CalcCRC16                   0x02081b64 arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   _ZZ20WDS_DecryptWMBssDescP16CRYPTORC4ContextPtP14MATHCRC16TablePK9WMBssDescP9WDSApInfoE5magic 0x020a1618 data
 *   g_020A1618                       0x020A1618 data
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

struct WMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned char pad[0x46];
    unsigned char gameInfo[0x70];
};

extern const unsigned char g_020A1618[4];

extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void CRYPTO_RC4Init(CRYPTORC4Context *context, const void *key, unsigned long key_len);
extern void CRYPTO_RC4Encrypt(CRYPTORC4Context *context, const void *in, unsigned long length, void *out);
extern void MATHi_CRC16UpdateRev(MATHCRC16Table *table, unsigned short *context, const void *input, unsigned long length);
extern unsigned short MATH_CalcCRC16(MATHCRC16Table *table, const void *data, unsigned long dataLength);

int func_0205A7CC(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable,
                  const WMBssDesc *bssDesc, WDSApInfo *apinfo)
{
    unsigned char rc4key[8];
    unsigned char *pCrcData;
    unsigned short crc;

    if (bssDesc == 0 || rc4context == 0 || crcContext == 0 || crcTable == 0 || apinfo == 0) {
        return 0;
    }
    MI_CpuCopy8(bssDesc->gameInfo, apinfo, sizeof(WDSApInfo));
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
