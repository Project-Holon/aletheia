/*
 * function: func_021F6590
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
 *   func_02087988 0x02087988 arm
 *   func_021F662C 0x021F662C arm ov107
 *   func_020853C0 0x020853C0 arm
 *   func_02085868 0x02085868 arm
 *   func_0208799C 0x0208799C arm
 *   g_021F7004 0x021F7004 data
 *   func_021F6480 0x021F6480 arm ov107
 */

typedef struct {
    char pad[0xC0];
    int f_c0;
} TaskWork;

extern TaskWork *g_021F7004;

extern unsigned long func_02087988(void);
extern void func_021F662C(void *pt);
extern void func_020853C0(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void func_02085868(void *thread);
extern unsigned long func_0208799C(unsigned long state);
extern void func_021F6480(void *arg);

void func_021F6590(void *p_work, unsigned long size)
{
    unsigned long bak_cpsr = func_02087988();

    if (g_021F7004 == 0) {
        TaskWork *p = (TaskWork *)p_work;
        g_021F7004 = p;
        func_021F662C((char *)p + 0xC4);
        p->f_c0 = 0;
        func_020853C0(p, func_021F6480, p, (char *)p + 0xE4 + ((size - 0xE4) & ~3), (size - 0xE4) & ~3, 0);
        func_02085868(p);
    }
    func_0208799C(bak_cpsr);
}
