/*
 * file:     unit_02166880_p01.c
 * unit:     yes
 * function: func_02166880, func_021669B8, func_02166A24, func_02166B2C, func_02166BD8
 * address:  0x02166880
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021657C8    0x021657C8  arm  ov009
 *   WM_Init          0x0208E010  arm
 *   func_02165A4C    0x02165A4C  arm  ov009
 *   func_0208EAC8    0x0208EAC8  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 *   func_021665CC    0x021665CC  arm  ov009
 *   func_0208F224    0x0208F224  arm
 *   func_02166EB0    0x02166EB0  arm  ov009
 *   func_02166F24    0x02166F24  arm  ov009
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WM_PowerOff                      0x0208f328 arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WcmWmcbCommon                    0x02166f24 arm
 *   func_02167CB4    0x02167CB4  arm  ov009
 *   DC_InvalidateRange 0x020862B8  arm
 *   WM_StartScanEx   0x0208F698  arm
 *   func_021671C0    0x021671C0  arm  ov009
 *   func_02090DEC  0x02090DEC  arm
 *   WM_EndDCF                        0x0208ffdc arm
 *   WcmWmcbEndDCF                    0x021678ac arm
 */
struct WCMWork;
typedef struct WCMWork_02166880 {
    unsigned char pad0[0x12C0];
    unsigned long dmaNo;
    unsigned char pad1[0x12DA - 0x12C4];
    unsigned short wmState;
    unsigned char pad3;
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad2[0x13A0 - 0x12DF];
    unsigned char wmSysBuf[1];
} WCMWork_02166880;

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

typedef struct WCMWork_02166A24 {
    unsigned char pad0[0x12DA];
    unsigned short wmState;
    unsigned char pad3;
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad1[0x22A0 - 0x12DF];
    WMScanExParam scanParam;
    unsigned char pad2[0x22E4 - 0x22D4];
    unsigned long notifyCount;
} WCMWork_02166A24;

typedef struct WCMWork_02166B2C {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[1];
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad2[0x2F];
    unsigned short field130E;
    unsigned short field1310;
} WCMWork_02166B2C;

extern int func_021657C8(void);
extern long WM_Init(void *wmSysBuf, unsigned short dmaNo);
extern void func_02165A4C(unsigned char phase);
extern long func_0208EAC8(void (*callback)(void *));
extern void OS_GetMacAddress(unsigned char *macAddress);
extern void func_021665CC(unsigned char *macAddress);
extern int func_0208F224(char *path);
extern void func_02166EB0(void *arg);
extern void func_02166F24(void *arg);
extern struct WCMWork *WCMi_GetSystemWork(void);
extern int WM_PowerOff(void (*callback)(void *));
extern void WCMi_SetPhase(unsigned char phase);
extern void WcmWmcbCommon(void *arg);
extern void func_02167CB4(unsigned char *bssid, unsigned char *essid, unsigned long option);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern long WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern void func_021671C0(void *arg);
extern long func_02090DEC(void (*callback)(void *), unsigned short tableNumber, unsigned short camLifeTime, unsigned short frameLifeTime, unsigned short mpLifeTime);
extern int WM_EndDCF(void (*callback)(void *));
extern void WcmWmcbEndDCF(void *arg);
long func_02166880(void);
long WCMi_WmifCleanupAsync(void);
long func_02166A24(void *bssid, void *essid, unsigned long option);
long func_02166B2C(void);
long WCMi_WmifDisconnectAsync(void);


/*
 * sdk:      WCMi_WmifStartupAsync (libwcm.TWL.HYB.a wmif.o)
 */
long func_02166880(void)
{
    unsigned char macAddress[6];
    WCMWork_02166880 *wcmw;
    long wmResult;

    wcmw = (WCMWork_02166880 *)func_021657C8();
    wmResult = WM_Init(wcmw->wmSysBuf, wcmw->dmaNo);
    switch (wmResult) {
    case 3:
        func_02165A4C(0xb);
        return 7;
    case 4:
        return 5;
    case 1:
    case 2:
    case 5:
    case 6:
    default:
        func_02165A4C(0xb);
        return 7;
    case 0:
        break;
    }
    if (func_0208EAC8(func_02166EB0) != 0) {
        func_02165A4C(0xb);
        return 7;
    }
    OS_GetMacAddress(macAddress);
    func_021665CC(macAddress);
    wmResult = func_0208F224((char *)func_02166F24);
    switch (wmResult) {
    case 2:
        func_02165A4C(2);
        wcmw->wmState = 1;
        break;
    case 8:
        func_02165A4C(0xc);
        return 1;
    case 3:
    default:
        func_02165A4C(0xb);
        return 7;
    }
    return 3;
}


long WCMi_WmifCleanupAsync(void)
{
    struct WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_PowerOff(WcmWmcbCommon);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(4);
        *(unsigned short *)((char *)wcmw + 0x12da) = 2;
        break;
    case 8:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    }
    return 3;
}


/*
 * sdk:      WCMi_WmifBeginSearchAsync (libwcm.TWL.HYB.a wmif.o)
 */
long func_02166A24(void *bssid, void *essid, unsigned long option)
{
    WCMWork_02166A24 *wcmw;
    long wmResult;

    wcmw = (WCMWork_02166A24 *)func_021657C8();
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


long func_02166B2C(void)
{
    WCMWork_02166B2C *wcmw;
    long wmResult;

    wcmw = (WCMWork_02166B2C *)func_021657C8();
    if (wcmw->phase == 3) {
        wcmw->field1310 = wcmw->field130E | 3;
    }
    wmResult = func_02090DEC(func_02166F24, 0xFFFF, 0x50, 0xFFFF, 0xFFFF);
    switch (wmResult) {
    case 2:
        func_02165A4C(8);
        wcmw->notify = 5;
        break;
    case 8:
        return 4;
    case 3:
    default:
        func_02165A4C(11);
        return 7;
    }
    return 3;
}


long WCMi_WmifDisconnectAsync(void)
{
    struct WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_EndDCF(WcmWmcbEndDCF);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(0xa);
        *(unsigned short *)((char *)wcmw + 0x12da) = 6;
        break;
    case 8:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    }
    return 3;
}
