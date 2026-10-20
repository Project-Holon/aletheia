/*
 * file:     os_tick.c
 * unit:     yes
 * function: OS_InitTick, OS_IsTickAvailable, OSi_CountUpTick, OS_GetTick, OS_GetTickLo
 * address:  0x02086FE8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OSi_SetTimerReserved  0x02086FC4  arm
 *   OS_SetIrqFunction     0x02084774  arm
 *   OS_EnableIrqMask      0x02084968  arm
 *   OSi_CountUpTick       0x02087068  arm
 *   g_02151330            0x02151330  data
 *   OSi_EnterTimerCallback  0x020848F8  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
#include "../types.h"

#include "../sdk_os.h"

/* os_tick.o .bss from 0x02151330, addressed from one pool word. */
typedef struct OsTickBss {
    u16 OSi_UseTick;
    BOOL OSi_NeedResetTimer;
    vu64 OSi_TickCounter;
} OsTickBss;

#include "os_timer.h"
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
typedef unsigned int OSIrqMask;
#include "os_interrupt.h"
extern void OSi_CountUpTick(void);
void OS_InitTick(void);
BOOL OS_IsTickAvailable(void);
#include "os_system.h"
OSTick OS_GetTick(void);
unsigned short OS_GetTickLo(void);
extern OsTickBss g_02151330;

#define reg_OS_IF (*(vu32 *)0x04000214)

#define reg_OS_TM0CNT_L (*(volatile u16 *)0x04000100)

#define reg_OS_TM0CNT_H (*(volatile u16 *)0x04000102)

/*
 * sdk:      OS_InitTick (os_tick.o)
 */
void OS_InitTick(void)
{
    if (g_02151330.OSi_UseTick) {
        return;
    }
    g_02151330.OSi_UseTick = 1;

    OSi_SetTimerReserved(0);

    g_02151330.OSi_TickCounter = 0;

    reg_OS_TM0CNT_H = 0;
    reg_OS_TM0CNT_L = 0;
    reg_OS_TM0CNT_H = 0xC1;

    OS_SetIrqFunction(8, OSi_CountUpTick);
    (void)OS_EnableIrqMask(8);

    g_02151330.OSi_NeedResetTimer = 0;
}

BOOL OS_IsTickAvailable(void)
{
    return g_02151330.OSi_UseTick;
}

/*
 * sdk:      OSi_CountUpTick (os_tick.o)
 */
void OSi_CountUpTick(void)
{
    g_02151330.OSi_TickCounter++;

    if (g_02151330.OSi_NeedResetTimer) {
        reg_OS_TM0CNT_H = 0;
        reg_OS_TM0CNT_L = 0;
        reg_OS_TM0CNT_H = 0xC1;
        g_02151330.OSi_NeedResetTimer = 0;
    }

    OSi_EnterTimerCallback(0, (void (*)(void *))OSi_CountUpTick, 0);
}

OSTick OS_GetTick(void)
{
    vu16 countL;
    vu64 countH;

    OSIntrMode prev = OS_DisableInterrupts();
    countL = *(vu16 *)0x04000100;
    countH = g_02151330.OSi_TickCounter & 0xffffffffffffULL;

    if ((reg_OS_IF & 0x8) && !(countL & 0x8000)) {
        countH++;
    }
    (void)OS_RestoreInterrupts(prev);

    return (countH << 16) | countL;
}

/*
 * note:     os_tick.o OS_GetTickLo.
 */
unsigned short OS_GetTickLo(void)
{
    return *(volatile unsigned short *)0x04000100;
}
