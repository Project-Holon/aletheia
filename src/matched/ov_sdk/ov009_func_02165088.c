/*
 * function: WCM_CleanupAsync
 * address:  0x02165088
 * packet:   pkt_ov009_02165088
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_CleanupAsync (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_021669B8  0x021669B8  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_NwmifCleanupAsync  0x02731A84  arm  twl
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Requests cleanup of the WCM: only valid in the idle phase, dispatched to the WM or NWM cleanup by device id.
 */

#include "../include/G_WCMState.h"

typedef struct WCMWork {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

typedef struct WCMState WCMState;

extern struct WCMState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern long func_021669B8(void);
extern int OS_IsRunOnTwl(void);
extern long WCMi_NwmifCleanupAsync(void);

long WCM_CleanupAsync(void)
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork *)g_021AA7D4.work)->phase) {
    case 4:
        OS_RestoreInterrupts(e);
        return 2;
    case 1:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    case 3:
        break;
    }
    switch (((WCMWork *)g_021AA7D4.work)->deviceId) {
    case 1:
        wcmResult = func_021669B8();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifCleanupAsync();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
