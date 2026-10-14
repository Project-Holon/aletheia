/*
 * function: MBi_TaskThread
 * address:  0x021F6480
 * packet:   pkt_ov107_021F6480
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_TaskThread (libmb.TWL.HYB.a(mb_task.o))
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_SetThreadPriority 0x02085988 arm
 *   OS_SleepThread 0x020857B0 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   OS_GetThreadPriority 0x02085A30 arm
 *   OS_ExitThread 0x020854B0 arm
 */

typedef unsigned long u32;

typedef struct Task {
    struct Task *next;
    u32 flags;
    void (*task)(struct Task *);
    void (*callback)(struct Task *);
    u32 param[4];
} Task;

typedef struct {
    char thread[0xc0];
    Task *volatile list;
    Task end;
} TaskWork;

extern u32 OS_DisableInterrupts(void);
extern void OS_SetThreadPriority(void *thread, u32 prio);
extern void OS_SleepThread(void *q);
extern void OS_RestoreInterrupts(u32 mode);
extern void *OS_GetThreadPriority(char *p);
extern void OS_ExitThread(void);

void MBi_TaskThread(void *arg)
{
    TaskWork *p;
    Task *trg;

    p = (TaskWork *)arg;
    while (1) {
        {
            u32 bak_cpsr;

            bak_cpsr = OS_DisableInterrupts();
            while (p->list == 0) {
                OS_SetThreadPriority(p, 0);
                OS_SleepThread(0);
            }
            trg = p->list;
        p->list = p->list->next;
            OS_SetThreadPriority(p, trg->flags >> 1);
            OS_RestoreInterrupts(bak_cpsr);
        }
        if (trg->task) {
            trg->task(trg);
        }
        {
            u32 bak_cpsr;
            void (*callback)(Task *);

            bak_cpsr = OS_DisableInterrupts();
            callback = trg->callback;
            {
                u32 cur_priority;
                u32 new_priority;

                cur_priority = (u32)OS_GetThreadPriority((char *)p);
                if (p->list == 0) {
                    new_priority = 0;
                } else {
                    new_priority = cur_priority < (p->list->flags >> 1) ? (p->list->flags >> 1) : cur_priority;
                }
                if (new_priority != cur_priority) {
                    OS_SetThreadPriority(p, new_priority);
                }
            }
            trg->next = 0;
            trg->flags &= ~1;
            if (callback) {
                callback(trg);
            }
            if (trg == &p->end) {
                break;
            }
            OS_RestoreInterrupts(bak_cpsr);
        }
    }
    OS_ExitThread();
}
