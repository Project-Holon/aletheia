/*
 * function: WCM_TerminateAsync
 * address:  0x02165560
 * packet:   pkt_ov009_02165560
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_TerminateAsync (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   WCMi_WmifTerminateAsync  0x02166C44  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_NwmifTerminateAsync  0x02731D6C  arm  twl
 *   g_021AA7D4     0x021AA7D4  data ov009
 *
 * Starts asynchronous termination of the WCM state machine: switches on the phase and dispatches to the WM or NWM terminate call by device id.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    short notifyId;
    unsigned char apListLock;
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

extern struct WcmState {
    int pad;
    WCMWork *wcmw;
} g_021AA7D4;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void WCMi_SetPhase(unsigned char phase);
extern long WCMi_WmifTerminateAsync(void);
extern int OS_IsRunOnTwl(void);
extern long WCMi_NwmifTerminateAsync();

long WCM_TerminateAsync(void)
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    wcmResult = 0;
    if (g_021AA7D4.wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (g_021AA7D4.wcmw->phase) {
    case 13:
        OS_RestoreInterrupts(e);
        return 2;
    case 1:
        OS_RestoreInterrupts(e);
        return wcmResult;
    case 6:
        WCMi_SetPhase(13);
        g_021AA7D4.wcmw->notifyId = 9;
        OS_RestoreInterrupts(e);
        return 3;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    case 3:
    case 9:
    case 12:
        if (g_021AA7D4.wcmw->resetting == 1) {
            WCMi_SetPhase(13);
            g_021AA7D4.wcmw->notifyId = 9;
        } else {
            switch (g_021AA7D4.wcmw->deviceId) {
            case 1:
                wcmResult = WCMi_WmifTerminateAsync();
                break;
            case 2:
                if (OS_IsRunOnTwl()) {
                    wcmResult = WCMi_NwmifTerminateAsync();
                    break;
                }
            default:
                wcmResult = 7;
                break;
            }
        }
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
