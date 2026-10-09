/*
 * file:     unit_02166880_p05.c
 * unit:     yes
 * function: WcmWmcbEndScan, WcmWmcbConnect
 * address:  0x02167448
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
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WCMi_Notify                      0x021659b4 arm
 *   WcmWmReset                       0x02166e5c arm
 *   WCMi_GetSystemWork  0x021657c8 arm ov009
 *   WM_StartDCF         0x0208fe64 arm
 *   WcmWmcbStartDCF     0x021677a4 arm ov009
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

extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern void WcmWmReset(void);
extern WCMWork *WCMi_GetSystemWork(void);
extern long WM_StartDCF(void (*callback)(void *), void *recvBuf, unsigned short recvBufSize);
extern void WcmWmcbStartDCF(void *arg);


static void WcmWmcbEndScan(void *arg)
{
    switch (*(unsigned short *)((char *)arg + 2)) {
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
                wcmw->field22E8 = 0;
            case 8:
                WCMi_SetPhase(0xc);
                return;
            case 9:
                wcmw->field22E8 = 0;
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
                wcmw->field22E8 = cb->aid;
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
        wcmw->field22EA = cb->wlStatus;
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
