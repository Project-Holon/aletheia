/*
 * function: WcmWmcbScanEx
 * address:  0x021671C0
 * packet:   pkt_ov009_021671C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  the image has an inlined `clz r0,r0` reached from the
 *           `cb->channelList` bit scan (0x0216732C, feeding
 *           WCMi_GetNextScanChannel); dsi/1.1p1 maps no C spelling of a
 *           count-leading-zeros to the ARM `clz` instruction (see
 *           docs/idioms/a-clz-means-a-hand-written-asm-body-not-an-intrinsic.md),
 *           so no plain C body can emit that pair, and this is not a MATCH
 *           (a concrete byte, not a wildcarded relocation).  The honest
 *           options are an `asm void` transcription or leaving these bytes.
 *           This draft still reproduces the three-level dispatch, the
 *           callback/register allocation (cb r4, wcmw r8, i sb) and every
 *           call; the residual is the clz pair plus a `for`-loop pre-check
 *           the image does not emit (compiled 636 vs 648 bytes).
 *
 * sdk:      WcmWmcbScanEx (libwcm.TWL.HYB.a(wmif.o))
 *
 * symbols:
 *   WCMi_GetSystemWork        0x021657c8 arm ov009
 *   WCMi_SetPhase             0x02165a4c arm ov009
 *   WCMi_Notify               0x021659b4 arm ov009
 *   DC_InvalidateRange        0x020862b8 arm
 *   WCMi_EntryApList          0x02165d04 arm ov009
 *   WCMi_NotifyEx             0x021659f8 arm ov009
 *   MATH_CountPopulation      0x02080d24 arm
 *   _u32_div_f                0x0209c2b0 arm
 *   WCMi_GetNextScanChannel   0x02165918 arm ov009
 *   DC_StoreRange             0x020862d4 arm
 *   WM_StartScanEx            0x0208f698 arm
 *   WM_EndScan                0x0208f808 arm
 *   WcmWmReset                0x02166e5c arm ov009
 *   WcmWmcbScanEx             0x021671c0 arm ov009
 *   WcmWmcbEndScan            0x02167448 arm ov009
 */

typedef struct WMScanExParam {
    unsigned char *scanBufPtr;
    unsigned short scanBufSize;
    unsigned short channelList;
    unsigned short maxChannelTime;
    unsigned char bssid[6];
    unsigned short scanType;
    unsigned short ssidLength;
    unsigned char ssid[32];
} WMScanExParam;

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
    unsigned char bssDesc[0x22A0 - 0x12E0];
    WMScanExParam scanExParam;
    unsigned char pad2[0x22E4 - 0x22D4];
    unsigned long notifyCount;
} WCMWork;

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

struct WMBssDesc;

extern WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern void WCMi_EntryApList(struct WMBssDesc *bssDesc, unsigned short linkLevel);
extern void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
extern unsigned char MATH_CountPopulation(unsigned long x);
extern void _u32_div_f(void);
extern unsigned short WCMi_GetNextScanChannel(unsigned short channel);
extern void DC_StoreRange(void *startAddr, unsigned long nBytes);
extern long WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern long WM_EndScan(void (*callback)(void *));
extern void WcmWmReset(void);
extern void WcmWmcbEndScan(void *arg);
extern int __cntlzw(int);

static void WcmWmcbScanEx(void *arg);

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
                DC_InvalidateRange(wcmw->scanExParam.scanBufPtr, wcmw->scanExParam.scanBufSize);
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
            wcmw->scanExParam.channelList =
                (1 << WCMi_GetNextScanChannel(32 - __cntlzw(cb->channelList))) >> 1;
            DC_StoreRange(wcmw->scanExParam.scanBufPtr, wcmw->scanExParam.scanBufSize);
            wcmw->notifyCount++;
            wmResult = WM_StartScanEx(WcmWmcbScanEx, &wcmw->scanExParam);
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
}
