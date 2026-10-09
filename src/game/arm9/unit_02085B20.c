/*
 * file:     unit_02085B20.c
 * function: func_02085B20
 * address:  0x02085B20
 * packet:   pkt_02085B20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_IdleThreadProc (os_thread.o, static; no catalogue row)
 *
 * symbols:
 *   OS_EnableInterrupts  0x02087974  arm
 *   OS_Halt              0x020882D0  arm
 */

typedef unsigned long u32;
typedef u32 OSIntrMode;

extern OSIntrMode OS_EnableInterrupts(void);
extern void OS_Halt(void);

void func_02085B20(void)
{
    (void)OS_EnableInterrupts();
    while (1) {
        OS_Halt();
    }
}
