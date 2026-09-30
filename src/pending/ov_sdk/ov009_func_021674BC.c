/*
 * function: WcmWmcbConnect
 * address:  0x021674BC
 * packet:   pkt_ov009_021674BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  codegen residue, 552 B == 552 B, 3 concrete mismatches, all the
 *           same shape: an empty `return;` arm of a switch whose body is only
 *           the epilogue.  The image puts a fresh `pop {r4,r5,r6,pc}` in the
 *           jump-table slot itself (state 6 slot 0x02167544, phase-switch
 *           default slot 0x02167574, phase 11 slot 0x02167584); dsi/1.1p1
 *           emits `b <shared pop>` there instead.  Tried:  case orderings
 *           (6 first / 6 last / 8-9 before 7), `break;`+trailing `return;`,
 *           `case 11:`/`default:` split vs grouped, `default:` first, a
 *           non-nested shallow probe reproduces the inline pop, so it is the
 *           nested (errcode>state>phase) context, not the arm, that defeats
 *           it.  Everything else (all 552 bytes) is byte-identical.
 *
 * measured (U23): arm-shape sweep (state case 6 as `break`, phase case 11/default split into
 *   two arms, default listed first, brace-wrapped empty arm, case 6 moved first) -- every
 *   spelling still emits `b <shared pop>` in those three slots; only the shared target moves
 *   (0x21675b8 / 0x2167670 / 0x2167698). 552 bytes == 552 bytes, 12 concrete bytes = the
 *   three 4-byte slots.
 * measured (wave8): `{ return; }` braces, a dead `break;` after each `return;`, phase case 11
 *   `break;` / default `return;` (and the inverse) with a trailing `return;` after the inner
 *   switch, and moving the empty arms to the front of their switch -- all still emit
 *   `b <shared pop>` in the three slots. Moving the phase empty arms first also reallocates
 *   the table (360 concrete bytes) with the shared target at 0x216758c; no spelling yields
 *   the image's per-slot `pop`. Consistent with the prior finding: a shallow, non-nested
 *   probe inlines the two empty-arm pops, so it is dsi/1.1p1 cross-jumping the empty returns
 *   across the errcode>state>phase nesting that keeps one epilogue.
 * sdk:      WcmWmcbConnect (libwcm.TWL.HYB.a(wmif.o))
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657c8 arm ov009
 *   WCMi_SetPhase       0x02165a4c arm ov009
 *   WcmWmReset          0x02166e5c arm ov009
 *   WCMi_Notify         0x021659b4 arm ov009
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

extern WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WcmWmReset(void);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern long WM_StartDCF(void (*callback)(void *), void *recvBuf, unsigned short recvBufSize);
extern void WcmWmcbStartDCF(void *arg);

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
            default:
                return;
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
            return;
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
        return;
    }
}
