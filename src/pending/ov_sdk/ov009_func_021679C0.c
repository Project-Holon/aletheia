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
 * blocker:  the wlStatus seed.  Re-measured 2026-09-30 (lane U52).
 *
 *           FIRST: the guard's shape matters more than the seed.  With the
 *           parked `if (((WMCallback *)arg)->errcode != 0) { ...; return; }`
 *           1.1p1 lays the guard body out FIRST and inverts the branch
 *           (`cmp r1,#0; beq +0x44`), which shifts the whole body: 594
 *           concrete bytes, and the "one 4-byte move" claim in the previous
 *           header is wrong for that spelling.  Spelled as
 *           `if (...) { goto fail; }` with `fail:` on a labelled tail at the
 *           end of the function, the layout matches the image exactly
 *           (`bne #0x2167c6c` to the guard block at the end, main body
 *           fallthrough) and the residue drops to 386 bytes, all of it the
 *           seed below.  That spelling is now in the body.
 *
 *           Residue (386 concrete bytes, all one instruction): the image
 *           materialises the `wlStatus = 3` seed in the entry block before
 *           `bl WCMi_GetSystemWork` (`+000C mov r5, #3`, r5 = wlStatus live
 *           across the call, DWARF confirms `unsigned short wlStatus r5`),
 *           and every arm that needs it does `mov r0, r5`.  1.1p1 refuses to
 *           allocate the register: it rematerialises `mov r0, #3` at the
 *           case 5/6, 7 and 9/12 arms and sinks a single `mov r5, #3` into
 *           the case 10 block (the only arm with two uses, so the only one
 *           where the register pays).  Size stays 756 because the two
 *           spellings cost the same.
 *
 *           Tried this lane: `unsigned short wlStatus = 3;` initialiser in
 *           four declaration orders (and with the other locals before and
 *           after it), the seed as a statement before the call, `register`,
 *           `int`, and replacing the variable with the literal 3 in every
 *           arm (to trigger the repeated-constant pool) - all byte-identical
 *           to one of the two shapes above; the constant is always folded or
 *           rematerialised.  The template for the seed is WcmWmcbCommon
 *           (0x02166F24, matched) whose `wmResult = 0x14;` before the call
 *           DOES keep r5 - but there the register is forced anyway because
 *           the final `switch (wmResult)` can also see a call result, which
 *           is not true of any wlStatus arm here.
 *
 *           Re-measured 2026-09-30 (wave 8): the image's case-8 guard-fail
 *           body does `mov r0, #3` (SetPhase literal 3), NOT the loaded
 *           field; `WCMi_SetPhase(wlStatus)` there compiles to
 *           `and r0, r5, #0xff` and is a genuine second residue, so the body
 *           now passes the literal `3`.  The case-8 store to 0x1310 is also
 *           spelled differently from the image: the image computes
 *           `r0 = wcmw + 0x1300; strh [r0, #0x10]` once and reuses it, while
 *           `*(u16 *)((char*)wcmw + 0x1310) |= 0x24` recomputes
 *           `wcmw + 0x310 + 0x1000` at the store.  See
 *           `a-repeated-constant-pools-only-within-one-block...`: the
 *           1.1p1 pooler works per basic block, so a constant whose uses span
 *           distinct switch arms is rematerialised per arm; the image's r5 is
 *           kept because its source's uses were in one block (or a variable
 *           whose value the front end could not fold).  `../2.0/sp2` compiles
 *           700 bytes (56 short), so this is not a pin reachable by that
 *           spelling either.  Residue: the whole switch body (register r5 for
 *           wlStatus) plus the case-8 0x1310 store spelling.
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
    case 8:
        wlStatus = *(unsigned short *)((char *)wcmw + 0x22ea);
        *(unsigned short *)((char *)wcmw + 0x22ea) = 0;
        if (wlStatus != 0x12 ||
            (*(unsigned short *)((char *)wcmw + 0x1310) & 0x24) == 0x24) {
            WCMi_SetPhase(3);
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
fail:
    WCMi_SetPhase(0xb);
    WCMi_Notify(7, 0, 0, 0x5a7);
}
