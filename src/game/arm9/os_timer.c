/*
 * file:     os_timer.c
 * function: OSi_SetTimerReserved
 * address:  0x02086FC4
 * packet:   pkt_02086FC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_SetTimerReserved (os_timer.o)
 *
 * symbols:
 *   OSi_TimerReserved  0x0215132C  data
 */

#include "../types.h"
#include "../sdk_ioreg.h"

/* os_tick.o .bss from 0x02151330, addressed from one pool word. */
typedef struct OsTickBss {
    u16 OSi_UseTick;
    BOOL OSi_NeedResetTimer;
    u64 OSi_TickCounter;
} OsTickBss;

extern OsTickBss g_02151330;

#define reg_OS_TM0CNT_L (*(volatile u16 *)REG_TM0CNT_L_ADDR)
#define reg_OS_TM0CNT_H (*(volatile u16 *)REG_TM0CNT_H_ADDR)

extern u16 OSi_TimerReserved;

void OSi_SetTimerReserved(int timerNum)
{
    OSi_TimerReserved |= (u16)(1 << timerNum);
}
