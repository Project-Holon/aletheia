/*
 * function: WcmWmcbCommon
 * address:  0x02166F24
 * packet:   pkt_ov009_02166F24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbCommon (libwcm.TWL.HYB.a(wmif.o))
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657c8 arm ov009
 *   WCMi_SetPhase       0x02165a4c arm ov009
 *   WCMi_Notify         0x021659b4 arm ov009
 *   WM_PowerOn          0x0208f2e4 arm
 *   WM_Finish           0x0208e2b8 arm
 *   WM_Disable          0x0208f2a0 arm
 *   WM_SetBeaconIndication 0x02090d98 arm
 *   WM_SetWEPKeyEx      0x02090c40 arm
 *   WM_StartConnectEx   0x0208f84c arm
 *   WcmWmcbCommon       0x02166f24 arm ov009
 *   WcmWmcbConnect      0x021674bc arm ov009
 */

typedef struct WCMPrivacyDesc {
    unsigned char wepKey[0x50];
    unsigned char wepMode;
    unsigned char wepKeyId;
    unsigned char pad[2];
} WCMPrivacyDesc;

typedef struct WCMWork {
    unsigned char sendBuf[0x600];
    unsigned char recvBuf[0xC40];
    WCMPrivacyDesc privacyDesc;
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
    unsigned char bssDesc[0xC0];
} WCMWork;

typedef struct WMCallback {
    unsigned short apiid;
    unsigned short errcode;
} WMCallback;

extern WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern long WM_PowerOn(void (*callback)(void *));
extern long WM_Finish(void);
extern long WM_Disable(void (*callback)(void *));
extern long WM_SetBeaconIndication(void (*callback)(void *), unsigned short flag);
extern long WM_SetWEPKeyEx(void (*callback)(void *), unsigned short wepmode,
                           unsigned short wepkeyid, unsigned char *wepkey);
extern long WM_StartConnectEx(void (*callback)(void *), void *pInfo,
                              unsigned char *ssid, int powerSave, unsigned short authMode);
static void WcmWmcbCommon(void *arg);
extern void WcmWmcbConnect(void *arg);

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
            wmResult = WM_SetWEPKeyEx(WcmWmcbCommon, wcmw->privacyDesc.wepMode,
                                      wcmw->privacyDesc.wepKeyId, wcmw->privacyDesc.wepKey);
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
