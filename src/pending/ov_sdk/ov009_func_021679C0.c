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
 * blocker:  12 concrete bytes, one scheduling swap at +0184 in the 0x56c
 *           (Notify 7) arm: image `add r0; ldr r3,[pc]; mov r2,r5; add r1,r0`,
 *           ours `add r0; add r1,r0; ldr r3,[pc]; mov r2,r5`.
 *
 *           opus (2026-10-01): rewritten in the vendor's switch/break shape
 *           (outer switch on errcode, `break` out of every arm, case 8 as
 *           `if (wlStatus == 0x12 && (rateSet & 0x24) != 0x24) {...} else {...}`
 *           with the 0x24 bits read and or-ed straight through
 *           `*(u16 *)(wcmw->bssDesc + 0x30)`). That closes the r0/r3 swap in
 *           the bit test (19 -> 12 B), so it was a source-shape artefact of the
 *           `p`/`v` locals, not an allocator tie. Inert on the +0184 swap:
 *           break vs return on every arm, an explicit break or return after
 *           the 0x56c call, case 3 removed or split (796 B), `case 2` moved
 *           last, if/else in place of the inner switch (748 B), goto to tail
 *           labels (shared or distinct), `&wcmw->bssDesc` / `&bssDesc[0]` /
 *           cast forms of the pointer argument.

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
    switch (((WMCallback *)arg)->errcode) {
    case 0:
        wcmw->resetting = 0;
        wcmw->field22E8 = 0;
        switch (wcmw->phase) {
        case 5:
        case 6:
            WCMi_SetPhase(wlStatus);
            WCMi_Notify(1, 0, 0, 0x53c);
            break;
        case 7:
            WCMi_SetPhase(wlStatus);
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
            } else {
                WCMi_SetPhase(3);
                WCMi_Notify(1, wcmw->bssDesc, (void *)wlStatus, 0x574);
            }
            break;
        case 9:
        case 12:
            WCMi_SetPhase(wlStatus);
            WCMi_Notify(0, wcmw->bssDesc, (void *)1, 0x57c);
            break;
        case 10:
            WCMi_SetPhase(wlStatus);
            WCMi_Notify(0, wcmw->bssDesc, 0, wlStatus + 0x580);
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
