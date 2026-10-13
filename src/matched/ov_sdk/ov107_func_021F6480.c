/*
 * function: func_021F6480
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
 *   func_02087988 0x02087988 arm
 *   func_02085988 0x02085988 arm
 *   func_020857B0 0x020857B0 arm
 *   func_0208799C 0x0208799C arm
 *   OS_GetThreadPriority 0x02085A30 arm
 *   func_020854B0 0x020854B0 arm
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

extern u32 func_02087988(void);
extern void func_02085988(void *thread, u32 prio);
extern void func_020857B0(void *q);
extern void func_0208799C(u32 mode);
extern void *OS_GetThreadPriority(char *p);
extern void func_020854B0(void);

void func_021F6480(void *arg)
{
    TaskWork *p;
    Task *trg;

    p = (TaskWork *)arg;
    while (1) {
        {
            u32 bak_cpsr;

            bak_cpsr = func_02087988();
            while (p->list == 0) {
                func_02085988(p, 0);
                func_020857B0(0);
            }
            trg = p->list;
        p->list = p->list->next;
            func_02085988(p, trg->flags >> 1);
            func_0208799C(bak_cpsr);
        }
        if (trg->task) {
            trg->task(trg);
        }
        {
            u32 bak_cpsr;
            void (*callback)(Task *);

            bak_cpsr = func_02087988();
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
                    func_02085988(p, new_priority);
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
            func_0208799C(bak_cpsr);
        }
    }
    func_020854B0();
}
