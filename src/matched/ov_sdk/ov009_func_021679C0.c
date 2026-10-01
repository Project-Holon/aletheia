/*
 * function: WcmWmcbReset
 * address:  0x021679C0
 * packet:   pkt_ov009_021679C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed (wave 3 lane25, 2026-10-01): the rate-retry `if` has no `else`; it
 *        ends in `return;` after the WM_StartConnectEx result switch, and the
 *        0x574 failure Notify follows the `if` as straight-line code.  That
 *        alone moves the 0x56c arm's pool load between the two bssDesc adds
 *        (break, else, and every argument spelling were inert).  The old
 *        `wlStatus = 3` stand-in is gone: SetPhase(3) and 0x583 are plain
 *        literals and 1.1p1 hoists the 3 into r5 itself.
 *
 * sdk:      WcmWmcbReset (libwcm.TWL.HYB.a(wmif.o))
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657c8 arm ov009
 *   WCMi_SetPhase       0x02165a4c arm ov009
 *   WCMi_Notify         0x021659b4 arm ov009
 *   WM_StartConnectEx   0x0208f84c arm
 *   WM_PowerOff         0x0208f328 arm
 *   WcmWmcbConnect      0x021674bc arm ov009
 *   WcmWmcbCommon       0x02166f24 arm ov009
 */

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

typedef struct WMCallback {
    unsigned short apiid;
    unsigned short errcode;
} WMCallback;

extern WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern long WM_StartConnectEx(void (*callback)(void *), void *pInfo,
                              unsigned char *ssid, int powerSave, unsigned short authMode);
extern long WM_PowerOff(void (*callback)(void *));
extern void WcmWmcbConnect(void *arg);
extern void WcmWmcbCommon(void *arg);

static void WcmWmcbReset(void *arg)
{
    WCMWork *wcmw;
    unsigned short wlStatus;
    long wmResult;

    wcmw = WCMi_GetSystemWork();
    switch (((WMCallback *)arg)->errcode) {
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
