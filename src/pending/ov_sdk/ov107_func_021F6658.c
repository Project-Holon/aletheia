/*
 * function: MBi_SetTask
 * address:  0x021F6658
 * packet:   pkt_ov107_021F6658
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_task.o).
 *
 * BLOCKER: bytes 0x0000-0x009C are identical; the sole residue is a
 * scheduler/peephole difference at +0x00A0. mwcc 1.1p1 (-O4,p) coalesces the
 * "pt->task = task" (+8) and "pt->field4 = ..." (+4) stores into
 * `stmib r8,{r1,r7}` and sinks the bak_cpsr move, 348 B vs the original's
 * separate `mov r5,r0; str r7,[r8,#8]; str r1,[r8,#4]`, 356 B. The linked-list
 * tail is then identical modulo the 4-byte shift. Bitfield vs explicit-mask
 * spellings and all store orderings tried; none defeat the stmib.
 *
 * symbols:
 *   MBi_IsTaskAvailable              0x021f6610 arm
 *   OS_GetThreadPriority             0x02085a30 arm
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   mbi_task_work                    0x021f7004 data
 */
typedef unsigned long u32;

struct MBiTaskInfo_tag {
    struct MBiTaskInfo_tag *next;
    unsigned active : 1;
    unsigned priority : 31;
    void (*task)(struct MBiTaskInfo_tag *);
    void (*callback)(struct MBiTaskInfo_tag *);
};

typedef struct MBiTaskWork {
    char _0[0xC0];
    struct MBiTaskInfo_tag *head;
    struct MBiTaskInfo_tag fieldC4;
} MBiTaskWork;

extern MBiTaskWork *mbi_task_work;
extern int MBi_IsTaskAvailable(void);
extern u32 OS_GetThreadPriority(void *thread);
extern u32 OS_DisableInterrupts(void);
extern void OS_WakeupThreadDirect(void *thread);
extern u32 OS_RestoreInterrupts(u32 state);

void MBi_SetTask(struct MBiTaskInfo_tag *pt, void (*task)(struct MBiTaskInfo_tag *), void (*callback)(struct MBiTaskInfo_tag *), u32 priority)
{
    MBiTaskWork *p_work;
    struct MBiTaskInfo_tag *pos;
    u32 bak_cpsr;
    u32 cur_priority;

    p_work = mbi_task_work;
    if (!MBi_IsTaskAvailable())
        return;
    if (pt->active)
        return;
    if (priority > 0x1F) {
        cur_priority = OS_GetThreadPriority(p_work);
        if (priority == 0x20) {
            priority = cur_priority - 1;
            if (cur_priority == 0)
                priority = 0;
        } else if (priority == 0x21) {
            priority = cur_priority + 1;
            if (cur_priority >= 0x1F)
                priority = 0x1F;
        } else {
            if (priority == 0x22)
                priority = cur_priority;
            else
                priority = 0x1F;
        }
    }
    bak_cpsr = OS_DisableInterrupts();
    pt->callback = callback;
    pt->task = task;
    pt->active = 1;
    pt->priority = priority;
    if (p_work->head == 0) {
        if (pt == &p_work->fieldC4)
            mbi_task_work = 0;
        p_work->head = pt;
        OS_WakeupThreadDirect(p_work);
    } else if (pt == &p_work->fieldC4) {
        pos = p_work->head;
        while (pos->next != 0)
            pos = pos->next;
        pos->next = pt;
        mbi_task_work = 0;
    } else {
        pos = p_work->head;
        if (priority < pos->priority) {
            p_work->head = pt;
            pt->next = pos;
        } else {
            while (pos->next != 0 && priority >= pos->next->priority)
                pos = pos->next;
            pt->next = pos->next;
            pos->next = pt;
        }
    }
    OS_RestoreInterrupts(bak_cpsr);
}
