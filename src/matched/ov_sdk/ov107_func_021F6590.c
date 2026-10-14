/*
 * function: MBi_InitTaskThread
 * address:  0x021F6590
 * packet:   pkt_ov107_021F6590
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_InitTaskThread (libmb.TWL.HYB.a(mb_task.o))
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   func_021F662C 0x021F662C arm ov107
 *   OS_CreateThread 0x020853C0 arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   g_021F7004 0x021F7004 data
 *   MBi_TaskThread 0x021F6480 arm ov107
 */

typedef struct {
    char pad[0xC0];
    int f_c0;
} TaskWork;

extern TaskWork *g_021F7004;

extern unsigned long OS_DisableInterrupts(void);
extern void func_021F662C(void *pt);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MBi_TaskThread(void *arg);

void MBi_InitTaskThread(void *p_work, unsigned long size)
{
    unsigned long bak_cpsr = OS_DisableInterrupts();

    if (g_021F7004 == 0) {
        TaskWork *p = (TaskWork *)p_work;
        g_021F7004 = p;
        func_021F662C((char *)p + 0xC4);
        p->f_c0 = 0;
        OS_CreateThread(p, MBi_TaskThread, p, (char *)p + 0xE4 + ((size - 0xE4) & ~3), (size - 0xE4) & ~3, 0);
        OS_WakeupThreadDirect(p);
    }
    OS_RestoreInterrupts(bak_cpsr);
}
