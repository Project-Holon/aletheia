/*
 * file:     wcm_wmif.c
 * unit:     yes
 * function: WCMi_WmifStartupAsync, func_021669B8, WCMi_WmifBeginSearchAsync, WCMi_WmifConnectAsync, func_02166BD8, WCMi_WmifTerminateAsync, WCMi_WmifSetDCFData, func_02166DE4, func_02166E5C, func_02166EB0, WcmWmcbCommon, WcmWmcbScanEx, WcmWmcbEndScan, WcmWmcbConnect, WcmWmcbDisconnect, WcmWmcbStartDCF, WcmWmcbEndDCF, func_021679C0, func_02167CB4, func_02167DE0, WcmWmcbSetDCFDataAsync
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
 * WM disconnect completion callback: on success finishes the reset or reports the disconnect result, otherwise moves to the failure phase and notifies.
 * symbols:
 *   WCMi_GetSystemWork    0x021657C8  arm  ov009
 *   WM_Init          0x0208E010  arm
 *   WCMi_SetPhase    0x02165A4C  arm  ov009
 *   WM_SetIndCallback    0x0208EAC8  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 *   func_021665CC    0x021665CC  arm  ov009
 *   WM_Enable    0x0208F224  arm
 *   func_02166EB0    0x02166EB0  arm  ov009
 *   func_02166F24    0x02166F24  arm  ov009
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WM_PowerOff                      0x0208f328 arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WcmWmcbCommon                    0x02166f24 arm
 *   func_02167CB4    0x02167CB4  arm  ov009
 *   DC_InvalidateRange 0x020862B8  arm
 *   WM_StartScanEx   0x0208F698  arm
 *   WcmWmcbScanEx    0x021671C0  arm  ov009
 *   WM_SetLifeTime  0x02090DEC  arm
 *   WM_EndDCF                        0x0208ffdc arm
 *   WcmWmcbEndDCF                    0x021678ac arm
 *   WMi_GetStatusAddress  0x0208E9C8  arm
 *   WM_Finish  0x0208E2B8  arm
 *   WM_Disable  0x0208F2A0  arm
 *   WM_PowerOff  0x0208F328  arm
 *   WM_Reset  0x0208F400  arm
 *   func_021679C0  0x021679C0  arm  ov009
 *   WCMi_GetCpsifWork  0x02166378  arm  ov009
 *   WM_SetDCFData  0x0208FF0C  arm
 *   OS_SleepThread  0x020857B0  arm
 *   func_02167DE0  0x02167DE0  arm  ov009
 *   WcmWmcbSetDCFDataAsync  0x02167E20  arm  ov009
 *   WM_GetAllowedChannel            0x0208ee60 arm
 *   WM_Reset                         0x0208f400 arm
 *   WCMi_Notify                      0x021659b4 arm
 *   WcmWmcbReset                     0x021679c0 arm
 *   WM_PowerOn          0x0208f2e4 arm
 *   WM_Disable          0x0208f2a0 arm
 *   WM_SetBeaconIndication 0x02090d98 arm
 *   WM_SetWEPKeyEx      0x02090c40 arm
 *   WM_StartConnectEx   0x0208f84c arm
 *   WcmWmcbConnect      0x021674bc arm ov009
 *   WCMi_EntryApList          0x02165d04 arm ov009
 *   WCMi_NotifyEx             0x021659f8 arm ov009
 *   MATH_CountPopulation      0x02080d24 arm
 *   _u32_div_f                0x0209c2b0 arm
 *   WCMi_GetNextScanChannel   0x02165918 arm ov009
 *   DC_StoreRange             0x020862d4 arm
 *   WM_EndScan                0x0208f808 arm
 *   WcmWmReset                0x02166e5c arm ov009
 *   WcmWmcbScanEx             0x021671c0 arm ov009
 *   WcmWmcbEndScan            0x02167448 arm ov009
 *   WM_StartDCF         0x0208fe64 arm
 *   WcmWmcbStartDCF     0x021677a4 arm ov009
 *   func_02166E5C  0x02166E5C  arm  ov009
 *   func_021659B4  0x021659B4  arm  ov009
 *   WCMi_ShelterRssi    0x02166804  arm  ov009
 *   WCMi_CpsifRecvCallback    0x02166358  arm  ov009
 *   WM_Disconnect    0x0208F938  arm
 *   WcmWmcbDisconnect    0x021676E4  arm  ov009
 *   WCM_UpdateOption    0x021656D0  arm  ov009
 *   WCMi_GetNextScanChannel    0x02165918  arm  ov009
 *   WM_GetDispersionScanPeriod    0x0208EFC4  arm
 *   MI_CpuCopy8      0x02082D44  arm
 *   g_021A1988       0x021A1988  data  ov009
 *   g_021A1990       0x021A1990  data  ov009
 *   WCMi_GetCpsifWork                0x02166378 arm
 *   WCMi_ResetKeepAliveAlarm         0x02165af4 arm
 *   OS_WakeupThread                  0x02085800 arm
 *   WCMi_CpsifUnlockMutexInIRQ       0x02166594 arm
 */
#include "wcm_types.h"

typedef struct WMStatus {
    unsigned short state;
} WMStatus;

typedef struct WMCallback {
    unsigned short apiid;
    unsigned short errcode;
} WMCallback;

typedef struct WMIndicationCallback {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short state;
    unsigned short reason;
} WMIndicationCallback;

typedef struct WMStartScanExCallback {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short wlCmdID;
    unsigned short wlResult;
    unsigned short state;
    unsigned short channelList;
    unsigned char reserved[2];
    unsigned short bssDescCount;
    void *bssDesc[16];
    unsigned short linkLevel[16];
} WMStartScanExCallback;

typedef struct WMStartConnectCallback {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short wlCmdID;
    unsigned short wlResult;
    unsigned short state;
    unsigned short aid;
    unsigned short reason;
    unsigned short wlStatus;
    unsigned char macAddress[6];
    unsigned short parentSize;
    unsigned short childSize;
} WMStartConnectCallback;

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

extern WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern long WM_Init(void *wmSysBuf, unsigned short dmaNo);
extern long WM_SetIndCallback(void (*callback)(void *));
extern void OS_GetMacAddress(unsigned char *macAddress);
extern void func_021665CC(unsigned char *macAddress);
extern int WM_Enable(char *path);
extern int WM_PowerOff(void (*callback)(void *));
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern long WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern long WM_SetLifeTime(void (*callback)(void *), unsigned short tableNumber, unsigned short camLifeTime, unsigned short frameLifeTime, unsigned short mpLifeTime);
extern int WM_EndDCF(void (*callback)(void *));
extern WMStatus *WMi_GetStatusAddress(void);
extern long WM_Finish(void);
extern long WM_Disable(void (*callback)(void *));
extern long WM_Reset(void (*callback)(void *));
extern WCMCpsifWork *WCMi_GetCpsifWork(void);
extern long WM_SetDCFData(void (*callback)(void *), unsigned char *destAdr, unsigned short *sendData, unsigned short sendDataSize);
extern void OS_SleepThread(void *queue);
extern unsigned short WM_GetAllowedChannel(void);
extern long WM_PowerOn(void (*callback)(void *));
extern long WM_SetBeaconIndication(void (*callback)(void *), unsigned short flag);
extern long WM_SetWEPKeyEx(void (*callback)(void *), unsigned short wepmode,
                           unsigned short wepkeyid, unsigned char *wepkey);
extern long WM_StartConnectEx(void (*callback)(void *), void *pInfo,
                              unsigned char *ssid, int powerSave, unsigned short authMode);
struct WMBssDesc;
extern void WCMi_EntryApList(struct WMBssDesc *bssDesc, unsigned short linkLevel);
extern void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
extern unsigned char MATH_CountPopulation(unsigned long x);
extern void _u32_div_f(void);
extern unsigned short WCMi_GetNextScanChannel(unsigned short channel);
extern void DC_StoreRange(void *startAddr, unsigned long nBytes);
extern long WM_EndScan(void (*callback)(void *));
extern long WM_StartDCF(void (*callback)(void *), void *recvBuf, unsigned short recvBufSize);
extern void WCMi_ShelterRssi(unsigned char rssi);
extern void WCMi_CpsifRecvCallback(unsigned char *srcAdrs, unsigned char *destAdrs, unsigned char *data, long length);
extern long WM_Disconnect(void (*callback)(void *), unsigned long arg);
extern unsigned long WCM_UpdateOption(unsigned long option);
extern unsigned short WM_GetDispersionScanPeriod(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void WCMi_ResetKeepAliveAlarm(void);
extern void OS_WakeupThread(void *queue);
extern void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex);
extern unsigned char g_021A1988[];
extern unsigned char g_021A1990[];

static void WcmWmReset(void);
static void WcmWmcbIndication(void *arg);
static void WcmWmcbCommon(void *arg);
static void WcmWmcbScanEx(void *arg);
static void WcmWmcbEndScan(void *arg);
static void WcmWmcbConnect(void *arg);
static void WcmWmcbReset(void *arg);
static void WcmWmcbSetDCFData(void *arg);
static void WcmWmcbSetDCFDataAsync(void *arg);
long WCMi_WmifStartupAsync(void);
long WCMi_WmifCleanupAsync(void);
long WCMi_WmifBeginSearchAsync(void *bssid, void *essid, unsigned long option);
long WCMi_WmifConnectAsync(void);
long WCMi_WmifDisconnectAsync(void);
long WCMi_WmifTerminateAsync(void);
long WCMi_WmifSetDCFData(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long));
unsigned short WCMi_WmifGetAllowedChannel(void);
void WcmWmcbDisconnect(void *arg);
void WcmWmcbStartDCF(void *arg);
void WcmWmcbEndDCF(void *arg);
void func_02167CB4(unsigned char *bssid, unsigned char *essid, unsigned long option);

/*
 * sdk:      WCMi_WmifStartupAsync (libwcm.TWL.HYB.a wmif.o)
 */
long WCMi_WmifStartupAsync(void)
{
    unsigned char macAddress[6];
    WCMWork *wcmw;
    long wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_Init(wcmw->wmSysBuf, wcmw->config.dmano);
    switch (wmResult) {
    case 3:
        WCMi_SetPhase(0xb);
        return 7;
    case 4:
        return 5;
    case 1:
    case 2:
    case 5:
    case 6:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    case 0:
        break;
    }
    if (WM_SetIndCallback(WcmWmcbIndication) != 0) {
        WCMi_SetPhase(0xb);
        return 7;
    }
    OS_GetMacAddress(macAddress);
    func_021665CC(macAddress);
    wmResult = WM_Enable((char *)WcmWmcbCommon);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(2);
        wcmw->notifyId = 1;
        break;
    case 8:
        WCMi_SetPhase(0xc);
        return 1;
    case 3:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    }
    return 3;
}

long WCMi_WmifCleanupAsync(void)
{
    WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_PowerOff(WcmWmcbCommon);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(4);
        wcmw->notifyId = 2;
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
long WCMi_WmifBeginSearchAsync(void *bssid, void *essid, unsigned long option)
{
    WCMWork *wcmw;
    long wmResult;

    wcmw = WCMi_GetSystemWork();
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
    wmResult = WM_StartScanEx(WcmWmcbScanEx, &wcmw->scanParam);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(5);
        wcmw->notifyId = 3;
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

long WCMi_WmifConnectAsync(void)
{
    WCMWork *wcmw;
    long wmResult;

    wcmw = WCMi_GetSystemWork();
    if (wcmw->phase == 3) {
        *(unsigned short *)(wcmw->bssDesc + 0x30) = *(unsigned short *)(wcmw->bssDesc + 0x2e) | 3;
    }
    wmResult = WM_SetLifeTime(WcmWmcbCommon, 0xFFFF, 0x50, 0xFFFF, 0xFFFF);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(8);
        wcmw->notifyId = 5;
        break;
    case 8:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}

long WCMi_WmifDisconnectAsync(void)
{
    WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_EndDCF(WcmWmcbEndDCF);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(0xa);
        wcmw->notifyId = 6;
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
 * sdk:      WCMi_WmifTerminateAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * Terminates the WM link by walking the WM state down: finish, disable, power off or reset, then maps the result to a WCM result.
 */
long WCMi_WmifTerminateAsync(void)
{
    WCMWork *wcmw;
    long wmResult;
    WMStatus *ws;

    wcmw = WCMi_GetSystemWork();
    ws = WMi_GetStatusAddress();
    DC_InvalidateRange(ws, 2);
    switch (ws->state) {
    case 0:
        wmResult = WM_Finish();
        if (wmResult == 0) {
            WCMi_SetPhase(1);
            wcmw->notifyId = 0;
            return 0;
        }
        break;
    case 1:
        wmResult = WM_Disable(WcmWmcbCommon);
        break;
    case 2:
        wmResult = WM_PowerOff(WcmWmcbCommon);
        break;
    default:
        wcmw->resetting = 1;
        wmResult = WM_Reset(WcmWmcbReset);
        break;
    }
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(13);
        wcmw->notifyId = 9;
        break;
    case 8:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}

/*
 * sdk:      WCMi_WmifSetDCFData (libwcm.TWL.HYB.a wmif.o)
 *
 * Sends a DCF frame through WM; with a callback the send is asynchronous, otherwise the caller sleeps until the completion callback.
 */
long WCMi_WmifSetDCFData(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long))
{
    WCMCpsifWork *wcmiw;
    long wmResult;

    wcmiw = WCMi_GetCpsifWork();
    if (callback == 0) {
        wmResult = WM_SetDCFData(WcmWmcbSetDCFData, dstAddr, buf, len);
    } else {
        wcmiw->sendCallback = callback;
        wmResult = WM_SetDCFData(WcmWmcbSetDCFDataAsync, dstAddr, buf, len);
    }
    switch (wmResult) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        return -5;
    case 2:
        if (callback == 0) {
            OS_SleepThread(&wcmiw->sendQ);
            if (wcmiw->sendResult != 0) {
                return -5;
            }
        }
        return len;
    }
}

unsigned short WCMi_WmifGetAllowedChannel(void)
{
    unsigned short val = WM_GetAllowedChannel();
    unsigned short low, high, tmp;

    high = 0x8000;
    low = 1;
    if (val == 0)
        return 0;
    if ((val & 0x8000) == 0) {
        do {
            high = (high >> 1) | 0x8000;
        } while ((high & val) == 0);
    }
    if ((val & 1) == 0) {
        do {
            low = (low << 1) | 1;
        } while ((low & val) == 0);
    }
    tmp = (unsigned short)~((unsigned short)((unsigned int)high << 1) | ((unsigned int)low >> 1));
    return tmp;
}

static void WcmWmReset(void)
{
    WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    if (wcmw->resetting != 0)
        return;
    wcmw->resetting = 1;
    wmResult = WM_Reset(WcmWmcbReset);
    if (wmResult == 2)
        return;
    WCMi_SetPhase(0xb);
    WCMi_Notify(7, 0, 0, 0x24f);
}

static void WcmWmcbIndication(void *arg)
{
    WCMWork *wcmw = WCMi_GetSystemWork();

    if (((WMIndicationCallback *)arg)->errcode != 8 ||
        ((WMIndicationCallback *)arg)->state != 0x16 ||
        ((WMIndicationCallback *)arg)->reason != 0x25)
        return;
    switch (wcmw->phase - 8) {
    case 0:
        WCMi_SetPhase(0xc);
        break;
    case 1:
    case 4:
        WcmWmReset();
        break;
    case 2:
        WCMi_SetPhase(0xc);
        break;
    case 3:
        break;
    }
}

static void WcmWmcbCommon(void *arg)
{
    WCMWork *wcmw;
    long wmResult;

    wmResult = 0x14;
    wcmw = WCMi_GetSystemWork();
    switch (((WMCallback *)arg)->errcode) {
    case 0:
        switch (((WMCallback *)arg)->apiid) {
        case 3:
            wmResult = WM_PowerOn(WcmWmcbCommon);
            break;
        case 4:
            if (WM_Finish() == 0) {
                WCMi_SetPhase(1);
                WCMi_Notify(0, 0, 0, 0x2a4);
            } else {
                WCMi_SetPhase(0xb);
                WCMi_Notify(7, 0, 0, 0x2ad);
            }
            return;
        case 5:
            WCMi_SetPhase(3);
            WCMi_Notify(0, 0, 0, 0x2b4);
            return;
        case 6:
            wmResult = WM_Disable(WcmWmcbCommon);
            break;
        case 0x1d:
            wmResult = WM_SetBeaconIndication(WcmWmcbCommon, 0);
            break;
        case 0x19:
            wmResult = WM_SetWEPKeyEx(WcmWmcbCommon, wcmw->privacyDesc.mode,
                                      wcmw->privacyDesc.u.keyId, wcmw->privacyDesc.key);
            break;
        case 0x27:
            wmResult = WM_StartConnectEx(WcmWmcbConnect, wcmw->bssDesc, 0,
                                         (wcmw->option & 0x30000) == 0x30000 ? 0 : 1,
                                         (wcmw->option & 0xc0000) == 0xc0000 ? 1 : 0);
            break;
        default:
            break;
        }
        switch (wmResult) {
        case 2:
            return;
        case 8:
            WCMi_SetPhase(0xc);
            WCMi_Notify(1, (wcmw->notifyId == 5) ? wcmw->bssDesc : 0, 0, 0x2f0);
            return;
        case 3:
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, (wcmw->notifyId == 5) ? wcmw->bssDesc : 0, 0, 0x2f9);
            return;
        }
        break;
    case 1:
        WCMi_SetPhase(0xc);
        WCMi_Notify(1, (wcmw->notifyId == 5) ? wcmw->bssDesc : 0, 0, 0x31f);
        return;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, (wcmw->notifyId == 5) ? wcmw->bssDesc : 0, 0, 0x329);
        return;
    }
}

/*
 * The `clz r0,r0; rsb r0,r0,#0x20` bit scan is an inline-asm `clz32` (the
 * idiom doc "a clz means hand-written asm" is about the BODY being asm; a
 * `static inline` wrapper inlines the bare `clz` for free, as in
 * ov013_func_021B11E8.c).  The trailing wmResult switch must be NESTED in
 * errcode case 0: every other errcode returns, so it is semantically the
 * same, and nesting is what puts that switch ahead of the errcode case 1
 * and default blocks.
 *
 * sdk:      WcmWmcbScanEx (libwcm.TWL.HYB.a(wmif.o))
 */
static inline unsigned long clz32(unsigned long x)
{
    asm { clz x, x }
    return x;
}

static void WcmWmcbScanEx(void *arg)
{
    unsigned long channels;
    WCMWork *wcmw;
    long i;
    long wmResult;
    WMStartScanExCallback *cb;

    wmResult = 0x14;
    wcmw = WCMi_GetSystemWork();
    cb = (WMStartScanExCallback *)arg;
    switch (cb->errcode) {
    case 0:
        if (wcmw->phase == 5) {
            WCMi_SetPhase(6);
            WCMi_Notify(0, 0, 0, 0x346);
        }
        switch (wcmw->phase) {
        case 6:
            wcmw->notifyId = 7;
            if (cb->state == 5) {
                DC_InvalidateRange(wcmw->scanParam.scanBuf, wcmw->scanParam.scanBufSize);
                for (i = 0; i < cb->bssDescCount; i++) {
                    WCMi_EntryApList((struct WMBssDesc *)cb->bssDesc[i], cb->linkLevel[i]);
                    WCMi_NotifyEx(7, 0, cb->bssDesc[i], cb, 0x35c);
                }
            }
            if ((wcmw->option & 0xc00000) == 0xc00000) {
                channels = MATH_CountPopulation(wcmw->option & 0x3ffe);
                if (channels != 0 &&
                    (wcmw->notifyCount % channels) == 0) {
                    WCMi_NotifyEx(8, 0, (void *)wcmw->notifyCount, 0, 0x36a);
                }
            }
            wcmw->scanParam.channelList =
                (1 << WCMi_GetNextScanChannel(32 - clz32(cb->channelList))) >> 1;
            DC_StoreRange(wcmw->scanParam.scanBuf, wcmw->scanParam.scanBufSize);
            wcmw->notifyCount++;
            wmResult = WM_StartScanEx(WcmWmcbScanEx, &wcmw->scanParam);
            break;
        case 7:
            wmResult = WM_EndScan(WcmWmcbEndScan);
            break;
        case 0xd:
            WcmWmReset();
            return;
        default:
            break;
        }
        switch (wmResult) {
        case 2:
            return;
        case 8:
            WCMi_SetPhase(0xc);
            WCMi_Notify(1, 0, 0, 0x395);
            return;
        case 3:
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, 0, 0, 0x39e);
            return;
        }
        break;
    case 1:
        WcmWmReset();
        return;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, 0, 0, 0x3af);
        return;
    }
}

static void WcmWmcbEndScan(void *arg)
{
    switch (((WMCallback *)arg)->errcode) {
    case 0:
        WCMi_SetPhase(3);
        WCMi_Notify(0, 0, 0, 0x3c5);
        break;
    case 1:
        WcmWmReset();
        break;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, 0, 0, 0x3d5);
        break;
    }
}

static void WcmWmcbConnect(void *arg)
{
    WCMWork *wcmw;
    WMStartConnectCallback *cb;
    long wmResult;

    cb = (WMStartConnectCallback *)arg;
    wcmw = WCMi_GetSystemWork();
    switch (cb->errcode) {
    case 0:
        switch (cb->state) {
        case 8:
        case 9:
            switch (wcmw->phase) {
            case 10:
                wcmw->aid = 0;
            case 8:
                WCMi_SetPhase(0xc);
                return;
            case 9:
                wcmw->aid = 0;
                wcmw->notifyId = 6;
            case 12:
                WcmWmReset();
                return;
            case 11:
                goto ret11;
            default:
                goto retdef;
            }
        case 7:
            if (wcmw->phase == 0xc) {
                WCMi_SetPhase(8);
                WcmWmReset();
                return;
            }
            if (cb->aid >= 1 && cb->aid <= 0x7d7) {
                wcmw->aid = cb->aid;
                wmResult = WM_StartDCF(WcmWmcbStartDCF, wcmw->recvBuf, 0x620);
                switch (wmResult) {
                case 2:
                    return;
                case 8:
                    WCMi_SetPhase(0xc);
                    WCMi_Notify(1, wcmw->bssDesc, 0, 0x430);
                    return;
                case 3:
                default:
                    WCMi_SetPhase(0xb);
                    WCMi_Notify(7, wcmw->bssDesc, 0, 0x439);
                    return;
                }
            }
            WcmWmReset();
            return;
        case 6:
            goto ret6;
        case 0x1a:
            return;
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, wcmw->bssDesc, (void *)cb->state, 0x447);
            return;
        }
    case 1:
        wcmw->wlStatus = cb->wlStatus;
    case 6:
    case 0xb:
    case 0xc:
        WCMi_SetPhase(8);
        WcmWmReset();
        return;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, wcmw->bssDesc, 0, 0x45e);
        break;
    }
    ret6:
        return;
    ret11:
        return;
    retdef:
        return;
}

void WcmWmcbDisconnect(void *arg)
{
    WCMWork *wcmw;

    wcmw = WCMi_GetSystemWork();
    switch (((WMCallback *)arg)->errcode) {
    case 0:
        if (wcmw->phase == 12) {
            WCMi_SetPhase(10);
            WcmWmReset();
            return;
        }
        wcmw->aid = 0;
        WCMi_SetPhase(3);
        WCMi_Notify(0, wcmw->bssDesc, 0, 0x481);
        return;
    case 1:
    case 3:
        WCMi_SetPhase(10);
        WcmWmReset();
        return;
    case 2:
    case 4:
    default:
        WCMi_SetPhase(11);
        WCMi_Notify(7, wcmw->bssDesc, 0, 0x493);
        return;
    }
}

/*
 * sdk:      WcmWmcbStartDCF (libwcm.TWL.HYB.a wmif.o)
 */
void WcmWmcbStartDCF(void *arg)
{
    WCMWork *wcmw;
    WMStartDCFCallback *cb;

    cb = arg;
    wcmw = WCMi_GetSystemWork();
    if (cb->errcode == 0) {
        switch (cb->state) {
        case 0xe:
            if (wcmw->phase == 0xc) {
                WCMi_SetPhase(8);
                WcmWmReset();
                return;
            }
            WCMi_SetPhase(9);
            WCMi_Notify(0, wcmw->bssDesc, 0, 0x4b7);
            return;
        case 0xf:
            WCMi_ShelterRssi((cb->recv->rateRssi >> 8) & 0xff);
            DC_InvalidateRange(cb->recv, 0x620);
            WCMi_CpsifRecvCallback(cb->recv->srcAdrs, cb->recv->destAdrs, cb->recv->data, cb->recv->length);
            return;
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, wcmw->bssDesc, (void *)cb->state, 0x4c6);
            return;
        }
    } else {
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, wcmw->bssDesc, 0, 0x4d1);
    }
}

/*
 * sdk:      WcmWmcbEndDCF (libwcm.TWL.HYB.a wmif.o)
 */
void WcmWmcbEndDCF(void *arg)
{
    WCMWork *wcmw;
    long wmResult;
    WMCallback *cb;

    cb = arg;
    wcmw = WCMi_GetSystemWork();
    switch (cb->errcode) {
    case 0:
        if (wcmw->phase == 0xc) {
            WCMi_SetPhase(0xa);
            WcmWmReset();
            return;
        }
        wmResult = WM_Disconnect(WcmWmcbDisconnect, 0);
        switch (wmResult) {
        case 2:
            return;
        case 8:
            WCMi_SetPhase(0xc);
            WCMi_Notify(1, wcmw->bssDesc, 0, 0x4fa);
            return;
        case 3:
            WCMi_SetPhase(0xa);
            WcmWmReset();
            return;
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, wcmw->bssDesc, 0, 0x506);
            return;
        }
    case 1:
    case 3:
        WCMi_SetPhase(0xa);
        WcmWmReset();
        return;
    case 2:
    case 4:
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, wcmw->bssDesc, 0, 0x519);
        return;
    }
}

static void WcmWmcbReset(void *arg)
{
    WCMWork *wcmw;
    unsigned short wlStatus;
    long wmResult;

    wcmw = WCMi_GetSystemWork();
    switch (((WMCallback *)arg)->errcode) {
    case 0:
        wcmw->resetting = 0;
        wcmw->aid = 0;
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
            wlStatus = wcmw->wlStatus;
            wcmw->wlStatus = 0;
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
    WCMWork *wcmw;
    long len;
    unsigned short t;

    wcmw = WCMi_GetSystemWork();
    WCM_UpdateOption(option);
    wcmw->scanParam.scanBuf = wcmw->recvBuf;
    wcmw->scanParam.scanBufSize = 0x400;
    wcmw->scanParam.channelList = (1 << WCMi_GetNextScanChannel(0)) >> 1;
    t = wcmw->maxScanTime;
    if (t == 0) {
        t = WM_GetDispersionScanPeriod();
    }
    wcmw->scanParam.maxChannelTime = t;
    wcmw->scanParam.scanType = (wcmw->option & 0x300000) == 0x300000 ? 0 : 1;
    if (bssid == 0) {
        MI_CpuCopy8(g_021A1988, wcmw->scanParam.bssid, 6);
    } else {
        MI_CpuCopy8(bssid, wcmw->scanParam.bssid, 6);
    }
    if (essid == 0 || essid == g_021A1990) {
        MI_CpuCopy8(g_021A1990, wcmw->scanParam.ssid, 32);
        wcmw->scanParam.ssidLength = 0;
    } else {
        MI_CpuCopy8(essid, wcmw->scanParam.ssid, 32);
        for (len = 0; len < 32; len++) {
            if (essid[len] == 0) {
                break;
            }
        }
        wcmw->scanParam.ssidLength = len;
    }
    wcmw->notifyCount = 0;
}

static void WcmWmcbSetDCFData(void *arg)
{
    WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();

    if (((WMCallback *)arg)->apiid != 0x12)
        return;
    wcmiw->sendResult = ((WMCallback *)arg)->errcode;
    if (((WMCallback *)arg)->errcode == 0)
        WCMi_ResetKeepAliveAlarm();
    OS_WakeupThread(&wcmiw->sendQ);
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
static void WcmWmcbSetDCFDataAsync(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
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
