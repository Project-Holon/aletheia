/*
 * file:     mb_task.c
 * unit:     yes
 * function: MBi_TaskThread, MBi_InitTaskThread, MBi_IsTaskAvailable, MBi_InitTaskInfo, MBi_IsTaskBusy, MBi_SetTask, MBi_EndTaskThread
 * address:  0x021F6480
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_SetThreadPriority 0x02085988 arm
 *   OS_SleepThread 0x020857B0 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   OS_ExitThread 0x020854B0 arm
 *   MBi_InitTaskInfo 0x021F662C arm ov107
 *   OS_CreateThread 0x020853C0 arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   ctrdgi_task_work 0x021f7004 data
 *   OS_GetThreadPriority             0x02085a30 arm
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   mbi_task_work                    0x021f7004 data
 */
struct MBiTaskInfo_tag;
typedef unsigned long u32;

typedef struct Task {
    struct Task *next;
    u32 flags;
    void (*task)(struct Task *);
    void (*callback)(struct Task *);
    u32 param[4];
} Task;

typedef struct
{
    u32 pad0;
    u32 busy : 1;
} MBiTaskInfo;

struct MBiTaskInfo_tag {
    struct MBiTaskInfo_tag *next;
    unsigned active : 1;
    unsigned priority : 31;
    void (*volatile task)(struct MBiTaskInfo_tag *);
    void (*callback)(struct MBiTaskInfo_tag *);
};

/* One thread-work object, seen two ways: MBi_TaskThread walks a list of Task
 * records, MBi_SetTask walks a list of MBiTaskInfo_tag records.  Both views
 * live at 0xC0 (list/head) and 0xC4 (end/info), so the words are unions. */
typedef struct MBiTaskWork {
    char _0[0xC0];
    union {
        Task *volatile list;                    /* MBi_TaskThread view */
        struct MBiTaskInfo_tag * volatile head; /* MBi_SetTask view */
    } tasks;
    union {
        Task end;                               /* MBi_TaskThread view */
        struct MBiTaskInfo_tag info;         /* MBi_SetTask view */
    } last;
} MBiTaskWork;

extern u32 OS_DisableInterrupts(void);
extern void OS_SetThreadPriority(void *thread, u32 prio);
extern void OS_SleepThread(void *q);
extern void OS_RestoreInterrupts(u32 mode);
extern void OS_ExitThread(void);
extern void MBi_InitTaskInfo(void *pt);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void MI_CpuFill8(void *dst, int val, u32 len);
extern u32 OS_GetThreadPriority(void *thread);



void MBi_TaskThread(void *arg);
void MBi_InitTaskThread(void *p_work, unsigned long size);
int MBi_IsTaskAvailable(void);
void MBi_InitTaskInfo(void *pt);
int MBi_IsTaskBusy(MBiTaskInfo *pt);
void MBi_SetTask(struct MBiTaskInfo_tag *pt, void (*task)(struct MBiTaskInfo_tag *), void (*callback)(struct MBiTaskInfo_tag *), u32 priority);
void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo_tag *));
extern MBiTaskWork *mbi_task_work;
extern void *ctrdgi_task_work;


/*
 * sdk:      MBi_TaskThread (libmb.TWL.HYB.a(mb_task.o))
 */
void MBi_TaskThread(void *arg)
{
    MBiTaskWork *p;
    Task *trg;

    p = (MBiTaskWork *)arg;
    while (1) {
        {
            u32 bak_cpsr;

            bak_cpsr = OS_DisableInterrupts();
            while (p->tasks.list == 0) {
                OS_SetThreadPriority(p, 0);
                OS_SleepThread(0);
            }
            trg = p->tasks.list;
        p->tasks.list = p->tasks.list->next;
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

                cur_priority = OS_GetThreadPriority((void *)p);
                if (p->tasks.list == 0) {
                    new_priority = 0;
                } else {
                    new_priority = cur_priority < (p->tasks.list->flags >> 1) ? (p->tasks.list->flags >> 1) : cur_priority;
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
            if (trg == &p->last.end) {
                break;
            }
            OS_RestoreInterrupts(bak_cpsr);
        }
    }
    OS_ExitThread();
}


void MBi_InitTaskThread(void *p_work, unsigned long size)
{
    unsigned long bak_cpsr = OS_DisableInterrupts();

    if (mbi_task_work == 0) {
        MBiTaskWork *p = (MBiTaskWork *)p_work;
        mbi_task_work = p;
        MBi_InitTaskInfo((char *)p + 0xC4);
        p->tasks.head = 0;
        OS_CreateThread(p, MBi_TaskThread, p, (char *)p + 0xE4 + ((size - 0xE4) & ~3), (size - 0xE4) & ~3, 0);
        OS_WakeupThreadDirect(p);
    }
    OS_RestoreInterrupts(bak_cpsr);
}


int MBi_IsTaskAvailable(void)
{
    return ctrdgi_task_work != 0;
}


void MBi_InitTaskInfo(void *pt)
{
    MI_CpuFill8(pt, 0, 0x20);
}


int MBi_IsTaskBusy(MBiTaskInfo *pt)
{
    return pt->busy != 0;
}


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
    if (p_work->tasks.head == 0) {
        if (pt == &p_work->last.info)
            mbi_task_work = 0;
        p_work->tasks.head = pt;
        OS_WakeupThreadDirect(p_work);
    } else {
        pos = p_work->tasks.head;
        if (pt == &p_work->last.info) {
            while (pos->next != 0)
                pos = pos->next;
            pos->next = pt;
            mbi_task_work = 0;
        } else if (priority < pos->priority) {
            p_work->tasks.head = pt;
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


void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo_tag *))
{
    u32 bak_cpsr = OS_DisableInterrupts();

    if (MBi_IsTaskAvailable())
        MBi_SetTask((struct MBiTaskInfo_tag *)((char *)mbi_task_work + 0xC4), 0, callback, 0);
    OS_RestoreInterrupts(bak_cpsr);
}
