/*
 * function: OSi_CountUpTick
 * address:  0x02087068
 * packet:   pkt_02087068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_CountUpTick (os_tick.o)
 *
 * symbols:
 *   OSi_EnterTimerCallback  0x020848F8  arm
 *   OSi_CountUpTick         0x02087068  arm
 *   g_02151330              0x02151330  data
 */

#include "../include/G_OsTickBss.h"

typedef unsigned long long u64;
typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;

/* os_tick.o .bss from 0x02151330, addressed from one pool word. */
typedef struct OsTickBss OsTickBss;

extern struct OsTickBss g_02151330;

#define reg_OS_TM0CNT_L (*(volatile u16 *)0x04000100)
#define reg_OS_TM0CNT_H (*(volatile u16 *)0x04000102)

extern void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void), void *arg);
extern void OSi_CountUpTick(void);

void OSi_CountUpTick(void)
{
    g_02151330.OSi_TickCounter++;

    if (g_02151330.OSi_NeedResetTimer) {
        reg_OS_TM0CNT_H = 0;
        reg_OS_TM0CNT_L = 0;
        reg_OS_TM0CNT_H = 0xC1;
        g_02151330.OSi_NeedResetTimer = 0;
    }

    OSi_EnterTimerCallback(0, OSi_CountUpTick, 0);
}
