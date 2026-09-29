/*
 * function: WcmWmcbReset
 * address:  0x021679C0
 * packet:   pkt_ov009_021679C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  codegen residue, 756 B == 756 B, the whole difference is the
 *           placement of one instruction.  The image materialises the
 *           `wlStatus = 3` seed in the entry block, before the
 *           `bl WCMi_GetSystemWork` (`0x021679CC mov r5, #3`), so r5 is live
 *           across the call; dsi/1.1p1 sinks it to the first use (the case
 *           5/6 `WCMi_SetPhase(wlStatus)` at +0x210) and rematerialises the
 *           constant there.  The two-column diff is that one 4-byte move and
 *           the resulting +4 shift through the body and literal pool (the
 *           branch opcodes themselves line up).  Tried:  declaration order,
 *           `unsigned short wlStatus = 3` initializer, `register`,
 *           assignment before vs after the call, `int` type; all fold or
 *           sink the same way.
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
    wlStatus = 3;
    if (((WMCallback *)arg)->errcode != 0) {
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, 0, 0, 0x5a7);
        return;
    }
    wcmw->resetting = 0;
    wcmw->field22E8 = 0;
    switch (wcmw->phase) {
    case 5:
    case 6:
        WCMi_SetPhase(wlStatus);
        WCMi_Notify(1, 0, 0, 0x53c);
        return;
    case 7:
        WCMi_SetPhase(wlStatus);
        WCMi_Notify(0, 0, 0, 0x542);
        return;
    case 8:
        wlStatus = *(unsigned short *)((char *)wcmw + 0x22ea);
        *(unsigned short *)((char *)wcmw + 0x22ea) = 0;
        if (wlStatus != 0x12 ||
            (*(unsigned short *)((char *)wcmw + 0x1310) & 0x24) == 0x24) {
            WCMi_SetPhase(wlStatus);
            WCMi_Notify(1, (char *)wcmw + 0x12e0, (void *)wlStatus, 0x574);
            return;
        }
        *(unsigned short *)((char *)wcmw + 0x1310) |= 0x24;
        wmResult = WM_StartConnectEx(WcmWmcbConnect, (char *)wcmw + 0x12e0, 0,
                                     (wcmw->option & 0x30000) == 0x30000 ? 0 : 1,
                                     (wcmw->option & 0xc0000) == 0xc0000 ? 1 : 0);
        switch (wmResult) {
        case 2:
            return;
        case 8:
            WCMi_SetPhase(0xc);
            WCMi_Notify(1, (char *)wcmw + 0x12e0, (void *)wlStatus, 0x563);
            return;
        case 3:
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, (char *)wcmw + 0x12e0, (void *)wlStatus, 0x56c);
            return;
        }
    case 9:
    case 12:
        WCMi_SetPhase(wlStatus);
        WCMi_Notify(0, (char *)wcmw + 0x12e0, (void *)1, 0x57c);
        return;
    case 10:
        WCMi_SetPhase(wlStatus);
        WCMi_Notify(0, (char *)wcmw + 0x12e0, 0, wlStatus + 0x580);
        return;
    case 13:
        wmResult = WM_PowerOff(WcmWmcbCommon);
        switch (wmResult) {
        case 2:
            return;
        case 8:
            WCMi_SetPhase(0xc);
            WCMi_Notify(1, 0, 0, 0x591);
            return;
        case 3:
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, 0, 0, 0x59a);
            return;
        }
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, 0, (void *)wcmw->phase, 0x5a0);
        return;
    }
}
