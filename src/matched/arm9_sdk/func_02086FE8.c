/*
 * function: func_02086FE8
 * address:  0x02086FE8
 * packet:   pkt_02086FE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitTick (os_tick.o)
 *
 * symbols:
 *   OSi_SetTimerReserved  0x02086FC4  arm
 *   OS_SetIrqFunction     0x02084774  arm
 *   OS_EnableIrqMask      0x02084968  arm
 *   OSi_CountUpTick       0x02087068  arm
 *   g_02151330            0x02151330  data
 */

typedef unsigned long long u64;
typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;

/* os_tick.o .bss from 0x02151330, addressed from one pool word. */
typedef struct OsTickBss {
    u16 OSi_UseTick;
    BOOL OSi_NeedResetTimer;
    u64 OSi_TickCounter;
} OsTickBss;

extern OsTickBss g_02151330;

#define reg_OS_TM0CNT_L (*(volatile u16 *)0x04000100)
#define reg_OS_TM0CNT_H (*(volatile u16 *)0x04000102)

extern void OSi_SetTimerReserved(int timerNum);
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern u32 OS_EnableIrqMask(u32 intr);
extern void OSi_CountUpTick(void);

void func_02086FE8(void)
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
