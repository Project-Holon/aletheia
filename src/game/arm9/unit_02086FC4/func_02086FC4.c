/*
 * function: func_02086FC4
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

extern u16 OSi_TimerReserved;

void func_02086FC4(int timerNum)
{
    OSi_TimerReserved |= (u16)(1 << timerNum);
}
