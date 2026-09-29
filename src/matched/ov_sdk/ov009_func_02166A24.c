/*
 * function: func_02166A24
 * address:  0x02166A24
 * packet:   pkt_ov009_02166A24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifBeginSearchAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   func_021657C8    0x021657C8  arm  ov009
 *   func_02167CB4    0x02167CB4  arm  ov009
 *   DC_InvalidateRange 0x020862B8  arm
 *   WM_StartScanEx   0x0208F698  arm
 *   func_02165A4C    0x02165A4C  arm  ov009
 *   func_021671C0    0x021671C0  arm  ov009
 */

typedef struct WMScanExParam {
    unsigned char *scanBuf;
    unsigned short scanBufSize;
    unsigned short channelList;
    unsigned short maxChannelTime;
    unsigned char bssid[6];
    unsigned short scanType;
    unsigned short ssidLength;
    unsigned char ssid[32];
} WMScanExParam;

typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    unsigned short wmState;
    unsigned char pad3;
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad1[0x22A0 - 0x12DF];
    WMScanExParam scanParam;
    unsigned char pad2[0x22E4 - 0x22D4];
    unsigned long notifyCount;
} WCMWork;

extern WCMWork *func_021657C8(void);
extern void func_02167CB4(void *bssid, void *essid, unsigned long option);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern long WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern void func_02165A4C(unsigned char phase);
extern void func_021671C0(void *arg);

long func_02166A24(void *bssid, void *essid, unsigned long option)
{
    WCMWork *wcmw;
    long wmResult;

    wcmw = func_021657C8();
    switch (wcmw->phase) {
    case 5:
        func_02167CB4(bssid, essid, option);
        return 2;
    case 6:
        func_02167CB4(bssid, essid, option);
        return 0;
    default:
        return 1;
    case 3:
        func_02167CB4(bssid, essid, option);
        break;
    }
    DC_InvalidateRange(wcmw->scanParam.scanBuf, wcmw->scanParam.scanBufSize);
    wcmw->notifyCount++;
    wmResult = WM_StartScanEx(func_021671C0, &wcmw->scanParam);
    switch (wmResult) {
    case 2:
        func_02165A4C(5);
        wcmw->wmState = 3;
        break;
    case 8:
        return 4;
    case 3:
    default:
        func_02165A4C(0xb);
        return 7;
    }
    return 3;
}
