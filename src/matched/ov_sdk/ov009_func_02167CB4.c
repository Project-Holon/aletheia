/*
 * function: func_02167CB4
 * address:  0x02167CB4
 * packet:   pkt_ov009_02167CB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmEditScanExParam (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   func_021657C8    0x021657C8  arm  ov009
 *   func_021656D0    0x021656D0  arm  ov009
 *   func_02165918    0x02165918  arm  ov009
 *   func_0208EFC4    0x0208EFC4  arm
 *   MI_CpuCopy8      0x02082D44  arm
 *   g_021A1988       0x021A1988  data  ov009
 *   g_021A1990       0x021A1990  data  ov009
 */

typedef struct WCMWork {
    unsigned char pad0[0x600];
    unsigned char scanBuf[0x12D4 - 0x600];
    unsigned long option;
    unsigned short maxScanTime;
    unsigned char pad1[0x22A0 - 0x12DA];
    unsigned char *scanBufPtr;
    unsigned short scanBufSize;
    unsigned short channelList;
    unsigned short maxChannelTime;
    unsigned char bssid[6];
    unsigned short scanType;
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned char pad2[0x22E4 - 0x22D4];
    unsigned long notifyCount;
} WCMWork;

extern unsigned char g_021A1988[];
extern unsigned char g_021A1990[];
extern WCMWork *func_021657C8(void);
extern unsigned long func_021656D0(unsigned long option);
extern unsigned short func_02165918(unsigned short channel);
extern unsigned short func_0208EFC4(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);

void func_02167CB4(unsigned char *bssid, unsigned char *essid, unsigned long option)
{
    WCMWork *wcmw;
    long len;
    unsigned short t;
    unsigned char *src;

    wcmw = func_021657C8();
    func_021656D0(option);
    wcmw->scanBufPtr = wcmw->scanBuf;
    wcmw->scanBufSize = 0x400;
    wcmw->channelList = (1 << func_02165918(0)) >> 1;
    t = wcmw->maxScanTime;
    if (t == 0) {
        t = func_0208EFC4();
    }
    wcmw->maxChannelTime = t;
    wcmw->scanType = (wcmw->option & 0x300000) == 0x300000 ? 0 : 1;
    if (bssid == 0) {
        MI_CpuCopy8(g_021A1988, wcmw->bssid, 6);
    } else {
        MI_CpuCopy8(bssid, wcmw->bssid, 6);
    }
    if (essid == 0 || essid == g_021A1990) {
        MI_CpuCopy8(g_021A1990, wcmw->ssid, 32);
        wcmw->ssidLength = 0;
    } else {
        MI_CpuCopy8(essid, wcmw->ssid, 32);
        for (len = 0; len < 32; len++) {
            if (essid[len] == 0) {
                break;
            }
        }
        wcmw->ssidLength = len;
    }
    wcmw->notifyCount = 0;
}
