/*
 * file:     unit_02166880_p07.c
 * unit:     yes
 * function: func_021677A4, func_021678AC, func_021679C0, func_02167CB4, func_02167DE0, func_02167E20
 * address:  0x021677A4
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
 *   func_02165A4C    0x02165A4C  arm  ov009
 *   func_02166E5C    0x02166E5C  arm  ov009
 *   func_021659B4    0x021659B4  arm  ov009
 *   func_02166804    0x02166804  arm  ov009
 *   DC_InvalidateRange 0x020862B8  arm
 *   func_02166358    0x02166358  arm  ov009
 *   func_0208F938    0x0208F938  arm
 *   func_021676E4    0x021676E4  arm  ov009
 *   WCMi_GetSystemWork  0x021657c8 arm ov009
 *   WCMi_SetPhase       0x02165a4c arm ov009
 *   WCMi_Notify         0x021659b4 arm ov009
 *   WM_StartConnectEx   0x0208f84c arm
 *   WM_PowerOff         0x0208f328 arm
 *   WcmWmcbConnect      0x021674bc arm ov009
 *   WcmWmcbCommon       0x02166f24 arm ov009
 *   func_021656D0    0x021656D0  arm  ov009
 *   func_02165918    0x02165918  arm  ov009
 *   func_0208EFC4    0x0208EFC4  arm
 *   MI_CpuCopy8      0x02082D44  arm
 *   g_021A1988       0x021A1988  data  ov009
 *   g_021A1990       0x021A1990  data  ov009
 *   WCMi_GetCpsifWork                0x02166378 arm
 *   WCMi_ResetKeepAliveAlarm         0x02165af4 arm
 *   OS_WakeupThread                  0x02085800 arm
 *   WCMi_CpsifUnlockMutexInIRQ       0x02166594 arm
 */
struct WCMCpsifWork;
typedef struct WMDcfRecvBuf {
    unsigned char pad0[6];
    unsigned short length;
    unsigned char pad1[6];
    unsigned short rateRssi;
    unsigned char pad2[8];
    unsigned char destAdrs[6];
    unsigned char srcAdrs[6];
    unsigned char pad3[8];
    unsigned char data[1];
} WMDcfRecvBuf;

typedef struct WMStartDCFCallback {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short state;
    unsigned char pad[2];
    WMDcfRecvBuf *recv;
} WMStartDCFCallback;

typedef struct WCMWork_021677A4 {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char pad1[0x12E0 - 0x12DF];
    unsigned char notifyParam[1];
} WCMWork_021677A4;

typedef struct WMEndDCFCallback {
    unsigned short apiid;
    unsigned short errcode;
} WMEndDCFCallback;

typedef struct WCMWork_021678AC {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char pad1[0x12E0 - 0x12DF];
    unsigned char notifyParam[1];
} WCMWork_021678AC;

typedef struct WCMWork {
    unsigned char sendBuf[0x600];
    unsigned char recvBuf[0xC40];
    unsigned char privacyDesc[0x54];
    unsigned char keepAliveAlarm[0x2C];
    unsigned char config[0x10];
    void (*notify)(void *);
    unsigned long option;
    unsigned short maxScanTime;
    short notifyId;
    unsigned char apListLock;
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
    unsigned char bssDesc[0x22E8 - 0x12E0];
    unsigned short field22E8;
    unsigned short field22EA;
} WCMWork;

typedef struct WMCallback_021679C0 {
    unsigned short apiid;
    unsigned short errcode;
} WMCallback_021679C0;

typedef struct WCMWork_02167CB4 {
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
} WCMWork_02167CB4;

typedef struct OSThreadQueue { void *head; void *tail; } OSThreadQueue;

typedef struct OSMutex { OSThreadQueue queue; void *thread; long count; void *prev; void *next; } OSMutex;

typedef struct WCMCpsifWork {
    unsigned char initialized;
    unsigned char reserved[3];
    OSThreadQueue sendQ;
    OSMutex sendMutex;
    unsigned short sendResult;
    unsigned short padding1;
    void (*recvCallback)(unsigned char *, unsigned char *, unsigned char *, long);
    void (*sendCallback)(long);
    unsigned char macAddress[6];
    unsigned short padding2;
} WCMCpsifWork;

typedef struct WMCallback_02167E20 { unsigned short apiid; unsigned short errcode; unsigned short wlCmdID; unsigned short wlResult; } WMCallback_02167E20;

extern int func_021657C8(void);
extern void func_02165A4C(unsigned char phase);
extern void func_02166E5C(void);
extern void func_021659B4(short result, void *para0, void *para1, long para2);
extern void func_02166804(unsigned char rssi);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern void func_02166358(unsigned char *srcAdrs, unsigned char *destAdrs, unsigned char *data, long length);
extern long func_0208F938(void (*callback)(void *), unsigned long arg);
extern void func_021676E4(void *arg);
extern WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern long WM_StartConnectEx(void (*callback)(void *), void *pInfo,
                              unsigned char *ssid, int powerSave, unsigned short authMode);
extern long WM_PowerOff(void (*callback)(void *));
extern void WcmWmcbConnect(void *arg);
extern void WcmWmcbCommon(void *arg);
extern unsigned long func_021656D0(unsigned long option);
extern unsigned short func_02165918(unsigned short channel);
extern unsigned short func_0208EFC4(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern struct WCMCpsifWork *WCMi_GetCpsifWork(void);
extern void WCMi_ResetKeepAliveAlarm(void);
extern void OS_WakeupThread(void *queue);
extern void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex);
void func_021677A4(void *arg);
void func_021678AC(void *arg);
void func_02167CB4(unsigned char *bssid, unsigned char *essid, unsigned long option);
extern unsigned char g_021A1988[];
extern unsigned char g_021A1990[];


/*
 * sdk:      WcmWmcbStartDCF (libwcm.TWL.HYB.a wmif.o)
 */
void func_021677A4(void *arg)
{
    WCMWork_021677A4 *wcmw;
    WMStartDCFCallback *cb;

    cb = arg;
    wcmw = (WCMWork_021677A4 *)func_021657C8();
    if (cb->errcode == 0) {
        switch (cb->state) {
        case 0xe:
            if (wcmw->phase == 0xc) {
                func_02165A4C(8);
                func_02166E5C();
                return;
            }
            func_02165A4C(9);
            func_021659B4(0, wcmw->notifyParam, 0, 0x4b7);
            return;
        case 0xf:
            func_02166804((cb->recv->rateRssi >> 8) & 0xff);
            DC_InvalidateRange(cb->recv, 0x620);
            func_02166358(cb->recv->srcAdrs, cb->recv->destAdrs, cb->recv->data, cb->recv->length);
            return;
        default:
            func_02165A4C(0xb);
            func_021659B4(7, wcmw->notifyParam, (void *)cb->state, 0x4c6);
            return;
        }
    } else {
        func_02165A4C(0xb);
        func_021659B4(7, wcmw->notifyParam, 0, 0x4d1);
    }
}


/*
 * sdk:      WcmWmcbEndDCF (libwcm.TWL.HYB.a wmif.o)
 */
void func_021678AC(void *arg)
{
    WCMWork_021678AC *wcmw;
    long wmResult;
    WMEndDCFCallback *cb;

    cb = arg;
    wcmw = (WCMWork_021678AC *)func_021657C8();
    switch (cb->errcode) {
    case 0:
        if (wcmw->phase == 0xc) {
            func_02165A4C(0xa);
            func_02166E5C();
            return;
        }
        wmResult = func_0208F938(func_021676E4, 0);
        switch (wmResult) {
        case 2:
            return;
        case 8:
            func_02165A4C(0xc);
            func_021659B4(1, wcmw->notifyParam, 0, 0x4fa);
            return;
        case 3:
            func_02165A4C(0xa);
            func_02166E5C();
            return;
        default:
            func_02165A4C(0xb);
            func_021659B4(7, wcmw->notifyParam, 0, 0x506);
            return;
        }
    case 1:
    case 3:
        func_02165A4C(0xa);
        func_02166E5C();
        return;
    case 2:
    case 4:
    default:
        func_02165A4C(0xb);
        func_021659B4(7, wcmw->notifyParam, 0, 0x519);
        return;
    }
}


static void WcmWmcbReset(void *arg)
{
    WCMWork *wcmw;
    unsigned short wlStatus;
    long wmResult;

    wcmw = WCMi_GetSystemWork();
    switch (((WMCallback_021679C0 *)arg)->errcode) {
    case 0:
        wcmw->resetting = 0;
        wcmw->field22E8 = 0;
        switch (wcmw->phase) {
        case 5:
        case 6:
            WCMi_SetPhase(3);
            WCMi_Notify(1, 0, 0, 0x53c);
            break;
        case 7:
            WCMi_SetPhase(3);
            WCMi_Notify(0, 0, 0, 0x542);
            break;
        case 8:
            wlStatus = wcmw->field22EA;
            wcmw->field22EA = 0;
            if (wlStatus == 0x12 && (*(unsigned short *)(wcmw->bssDesc + 0x30) & 0x24) != 0x24) {
                *(unsigned short *)(wcmw->bssDesc + 0x30) |= 0x24;
                wmResult = WM_StartConnectEx(WcmWmcbConnect, wcmw->bssDesc, 0,
                                             (wcmw->option & 0x30000) == 0x30000 ? 0 : 1,
                                             (wcmw->option & 0xc0000) == 0xc0000 ? 1 : 0);
                switch (wmResult) {
                case 2:
                    break;
                case 8:
                    WCMi_SetPhase(0xc);
                    WCMi_Notify(1, wcmw->bssDesc, (void *)wlStatus, 0x563);
                    break;
                case 3:
                default:
                    WCMi_SetPhase(0xb);
                    WCMi_Notify(7, wcmw->bssDesc, (void *)wlStatus, 0x56c);
                }
                return;
            }
            WCMi_SetPhase(3);
            WCMi_Notify(1, wcmw->bssDesc, (void *)wlStatus, 0x574);
            break;
        case 9:
        case 12:
            WCMi_SetPhase(3);
            WCMi_Notify(0, wcmw->bssDesc, (void *)1, 0x57c);
            break;
        case 10:
            WCMi_SetPhase(3);
            WCMi_Notify(0, wcmw->bssDesc, 0, 0x583);
            break;
        case 13:
            wmResult = WM_PowerOff(WcmWmcbCommon);
            switch (wmResult) {
            case 2:
                break;
            case 8:
                WCMi_SetPhase(0xc);
                WCMi_Notify(1, 0, 0, 0x591);
                break;
            case 3:
            default:
                WCMi_SetPhase(0xb);
                WCMi_Notify(7, 0, 0, 0x59a);
            }
            break;
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, 0, (void *)wcmw->phase, 0x5a0);
        }
        break;
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, 0, 0, 0x5a7);
    }
}


void func_02167CB4(unsigned char *bssid, unsigned char *essid, unsigned long option)
{
    WCMWork_02167CB4 *wcmw;
    long len;
    unsigned short t;
    unsigned char *src;

    wcmw = (WCMWork_02167CB4 *)func_021657C8();
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


static void WcmWmcbSetDCFData(void *arg)
{
    struct WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();

    if (*(unsigned short *)arg != 0x12)
        return;
    *(unsigned short *)((char *)wcmiw + 0x24) = *(unsigned short *)((char *)arg + 2);
    if (*(unsigned short *)((char *)arg + 2) == 0)
        WCMi_ResetKeepAliveAlarm();
    OS_WakeupThread((char *)wcmiw + 4);
}


/*
 * sdk:      WcmWmcbSetDCFDataAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * WM completion callback for an asynchronous DCF send: record the WM error
 * code, re-arm the keep-alive alarm on success, map the result to the WCM
 * cpsif code (0 or -5), release the send mutex and call the user callback.
 *
 * 2026-10-01 (w3 lane28): closed. The earlier "front-end predication wall"
 * was source shape. The vendor .debug_line puts `mov r5,#0` on line 1574 and
 * `mvn r5,#4` on line 1580, both after the line-1570 test, so the result is
 * set in two arms of a switch on sendResult. A dead case label sharing the
 * default arm (`case 1: default:`, WM_ERRCODE_FAILED) keeps the -5 arm a
 * real block reached by two edges, so 1.1p1 does not if-convert it: the
 * image's `mov r5,#0 / cmp / beq / mvn r5,#4`. Plain `case 0 / default`,
 * if/else and the guard-after-default spellings all give `mvnne` (100 B).
 * Outer `switch (cb->apiid)` and the DWARF `cb` local as in the vendor.
 */
static void func_02167E20(void *arg)
{
    WMCallback_02167E20 *cb = (WMCallback_02167E20 *)arg;
    WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();
    long wcmResult;
    void (*sendCallback)(long);

    switch (cb->apiid) {
    case 0x12:
        wcmiw->sendResult = cb->errcode;
        if (cb->errcode == 0) {
            WCMi_ResetKeepAliveAlarm();
        }
        switch (wcmiw->sendResult) {
        case 0:
            wcmResult = 0;
            break;
        case 1:
        default:
            wcmResult = -5;
            break;
        }
        sendCallback = wcmiw->sendCallback;
        wcmiw->sendCallback = 0;
        WCMi_CpsifUnlockMutexInIRQ(&wcmiw->sendMutex);
        sendCallback(wcmResult);
        break;
    }
}
