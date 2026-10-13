/*
 * function: func_02165164
 * address:  0x02165164
 * packet:   pkt_ov009_02165164
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_BeginSearchAsync (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02166A24  0x02166A24  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_NwmifBeginSearchAsync  0x02731AF0  arm  twl
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Starts an AP search on the active device (WM or NWM), returning a WCM result code.
 */

#include "../include/G_WCMState.h"

typedef struct WCMWork {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork;

typedef struct WCMState WCMState;

extern struct WCMState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern long func_02166A24(void *bssid, void *essid, unsigned long option);
extern int OS_IsRunOnTwl(void);
extern long WCMi_NwmifBeginSearchAsync(void *bssid, void *essid, unsigned long option);

long func_02165164(void *bssid, void *essid, unsigned long option)
{
    long wcmResult;
    unsigned long e;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork *)g_021AA7D4.work)->deviceId) {
    case 1:
        wcmResult = func_02166A24(bssid, essid, option);
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifBeginSearchAsync(bssid, essid, option);
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
