/*
 * function: PMi_FinalizeDebugger
 * address:  0x02731500
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OSi_SyncWithOtherProc 0x02084AB0 arm
 *   OS_DisableInterrupts 0x02087988 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void OSi_SyncWithOtherProc(int a0, volatile u8 *p);
extern void OS_DisableInterrupts(void);

void PMi_FinalizeDebugger(void)
{
    volatile u8 *a = (volatile u8 *)0x02FFFFF0;
    *(volatile u8 *)0x02FFFFF4 = 0;
    OSi_SyncWithOtherProc(0, a);
    OSi_SyncWithOtherProc(1, a);
    OS_DisableInterrupts();
    *(volatile u8 *)0x02FFFFF4 = 1;
}
