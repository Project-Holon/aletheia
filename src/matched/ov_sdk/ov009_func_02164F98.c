/*
 * function: WCM_StartupAsync
 * address:  0x02164F98
 * packet:   pkt_ov009_02164F98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_StartupAsync (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WcmConfigure  0x021657D8  arm  ov009
 *   func_0208EE60  0x0208EE60  arm
 *   func_02166880  0x02166880  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_NwmifStartupAsync  0x0273199C  arm  twl
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Starts up the WCM: configures it in the idle phase, then starts the WM or NWM device if a channel is allowed.
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
struct WCMConfig;
extern void WcmConfigure(struct WCMConfig *config, void (*notify)(void *));
extern unsigned short func_0208EE60(void);
extern long func_02166880(void);
extern int OS_IsRunOnTwl(void);
extern long WCMi_NwmifStartupAsync(void);

long WCM_StartupAsync(void *config, void (*notify)(void *))
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork *)g_021AA7D4.work)->phase) {
    case 1:
        WcmConfigure(config, notify);
        break;
    case 2:
        OS_RestoreInterrupts(e);
        return 2;
    case 3:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (func_0208EE60() == 0) {
        return 5;
    }
    switch (((WCMWork *)g_021AA7D4.work)->deviceId) {
    case 1:
        wcmResult = func_02166880();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifStartupAsync();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
