/*
 * function: WCMi_SetPhase
 * address:  0x02165A4C
 * packet:   pkt_ov009_02165A4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_SetPhase (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_CancelAlarm  0x020873F8  arm
 *   OS_SetAlarm  0x0208738C  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA7D4  0x021AA7D4  data ov009
 *   func_02165B5C  0x02165B5C  arm  ov009
 *
 * Sets the WCM phase under a critical section, managing the keep-alive alarm when entering or leaving the connected phase.
 */

#include "../include/G_WCMState.h"

typedef struct WCMWork {
    unsigned char pad0[0x1294];
    unsigned char keepAlive[0x4A];
    unsigned char phase;
} WCMWork;

typedef struct WCMState WCMState;

extern struct WCMState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern void OS_CancelAlarm(void *alarm);
extern void OS_SetAlarm(void *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_02165B5C(void *arg);

void WCMi_SetPhase(unsigned char phase)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (((WCMWork *)g_021AA7D4.work)->phase == 9 && phase != 9) {
        OS_CancelAlarm(((WCMWork *)g_021AA7D4.work)->keepAlive);
    }
    if (((WCMWork *)g_021AA7D4.work)->phase != 0xB) {
        ((WCMWork *)g_021AA7D4.work)->phase = phase;
    }
    if (phase == 9) {
        OS_CancelAlarm(((WCMWork *)g_021AA7D4.work)->keepAlive);
        OS_SetAlarm(((WCMWork *)g_021AA7D4.work)->keepAlive, 0x022F5341ULL, func_02165B5C, 0);
    }
    OS_RestoreInterrupts(e);
}
