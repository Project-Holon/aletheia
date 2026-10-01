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
 * blocker:  19 concrete bytes, all in the case-8 body, byte-identical size
 *           (756).  Everything else, including the wlStatus=3 seed in r5
 *           (`+000C mov r5,#3` across `bl WCMi_GetSystemWork`) and the
 *           case-8 guard-fail tail at `+01A0`, now matches.
 *
 *           Re-measured 2026-10-01 (wave 8, lane DIFF ov009).
 *
 *           Fixed this lane: the wlStatus seed keeps r5 as soon as the case-8
 *           guard is spelled as `if (wlStatus != 0x12) goto fail8;` with the
 *           fail body on a labelled tail, instead of an inline `{ ...; return; }`
 *           (which 1.1p1 lays out body-first).  Also passing the bssDesc
 *           pointer as the struct member `wcmw->bssDesc` (offset 0x12e0) rather
 *           than `(char *)wcmw + 0x12e0` stopped 1.1p1 from strength-reducing
 *           `wcmw + 0x2e0` into r4 (+0118 `add r4,r4,#0x2e0`), which had been
 *           saving 2 instructions (748 vs 756).  The case-8 store is a local
 *           `p = (unsigned short *)((char *)wcmw + 0x1300); v = p[8];` reused
 *           for both the `(v & 0x24) == 0x24` test and `p[8] = v | 0x24`, and
 *           the guard-fail passes the literal `3` to WCMi_SetPhase.
 *
 *           Residue: pure register naming in the `p[8]` sequence.  The image
 *           has base in r0 and the AND scratch in r3 (`add r0,r4,#0x1300;
 *           ldrh r2,[r0,#0x10]; and r3,r2,#0x24; ... orr r2,r2,#0x24;
 *           strh r2,[r0,#0x10]`); 1.1p1 puts base in r3 and the scratch in r0
 *           (`add r3,r4,#0x1300; ldrh r2,[r3,#0x10]; and r0,r2,#0x24; ...
 *           orr r0,r2,#0x24; strh r0,[r3,#0x10]`), i.e. an r0<->r3 swap.
 *           Plus one scheduling swap at +0184: the image does `ldr r3,[pc];
 *           mov r2,r5; add r1,r0,#0x1000`, 1.1p1 does `add r1,r0,#0x1000;
 *           ldr r3,[pc]; mov r2,r5`.  Tried this lane: `p`/`v` declaration
 *           order both ways, `p[8] |= 0x24` (worse, 22 B), and `(char*)wcmw +
 *           0x12e0` (748 B).  The seed rematerialisation noted in the old
 *           header is gone once the guard has the goto-tail shape.
 *
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
        goto fail;
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
    case 8: {
        unsigned short v;
        unsigned short *p;

        wlStatus = *(unsigned short *)((char *)wcmw + 0x22ea);
        *(unsigned short *)((char *)wcmw + 0x22ea) = 0;
        if (wlStatus != 0x12) {
            goto fail8;
        }
        p = (unsigned short *)((char *)wcmw + 0x1300);
        v = p[8];
        if ((v & 0x24) == 0x24) {
            goto fail8;
        }
        p[8] = v | 0x24;
        wmResult = WM_StartConnectEx(WcmWmcbConnect, wcmw->bssDesc, 0,
                                     (wcmw->option & 0x30000) == 0x30000 ? 0 : 1,
                                     (wcmw->option & 0xc0000) == 0xc0000 ? 1 : 0);
        switch (wmResult) {
        case 2:
            return;
        case 8:
            WCMi_SetPhase(0xc);
            WCMi_Notify(1, wcmw->bssDesc, (void *)wlStatus, 0x563);
            return;
        case 3:
        default:
            WCMi_SetPhase(0xb);
            WCMi_Notify(7, wcmw->bssDesc, (void *)wlStatus, 0x56c);
            return;
        }
    fail8:
        WCMi_SetPhase(3);
        WCMi_Notify(1, wcmw->bssDesc, (void *)wlStatus, 0x574);
        return;
    }
    case 9:
    case 12:
        WCMi_SetPhase(wlStatus);
        WCMi_Notify(0, wcmw->bssDesc, (void *)1, 0x57c);
        return;
    case 10:
        WCMi_SetPhase(wlStatus);
        WCMi_Notify(0, wcmw->bssDesc, 0, wlStatus + 0x580);
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
fail:
    WCMi_SetPhase(0xb);
    WCMi_Notify(7, 0, 0, 0x5a7);
}
