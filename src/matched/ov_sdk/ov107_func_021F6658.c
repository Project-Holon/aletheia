/*
 * function: MBi_SetTask
 * address:  0x021F6658
 * packet:   pkt_ov107_021F6658
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_task.o).  Queue one MBiTaskInfo on the
 * multi-boot task list (the mb_task.o archive member is byte-identical to the
 * image, so this is a transcription, not a search).  356/356 bytes.
 *
 * Three shape levers, none of them semantic, and none of them reachable by
 * re-spelling the parked body (which sat at 348 bytes / 163 concrete):
 *
 * 1. `task` volatile.  With a plain member mwcc fuses `pt->task = task` and
 *    the `pt->active/priority` store into `stmib r8,{r1,r7}` and sinks the
 *    bak_cpsr move, 348 B.  The image has `mov r5,r0; str r7,[r8,#8];
 *    str r1,[r8,#4]`.  A `volatile` destination member defeats the stmib
 *    (HANDOFF: "volatile on one destination field defeats an unwanted stmib
 *    merge"); the store to a volatile member cannot join a run.
 * 2. `head` volatile.  The image loads `p_work->head` twice: once for the
 *    empty-list test (+00AC) and again for the shared pos (+00E0), which the
 *    second and third arms then share.  With a plain member mwcc treats the
 *    pre-branch load as partially redundant and keeps ONE load for all three
 *    arms (-4 B).  Volatile blocks that PRE, and the two loads land exactly
 *    where the image has them.
 * 3. `pos = p_work->head;` hoisted once into the else block, with
 *    `pt == &p_work->fieldC4` tested INSIDE it.  Written as the parked
 *    `else if (pt == &p_work->fieldC4) { pos = head; ... } else { pos = head;
 *    ... }` the two arms each carry their own volatile load and the third arm
 *    reloads (+4 B, 360 total).  One shared volatile load for both arms gives
 *    the image's single reload at +00E0 feeding both, and the branch order
 *    `cmp r8,r0; bne` falls out of it.
 *
 * With only levers 1+3 (348+4 = 352) the arm-2/3 reload is missing; with only
 * lever 2 the stmib is back (356 B but 103 concrete).  All three together:
 * EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov107_func_021F6658.c \
 *       --func MBi_SetTask --addr 0x021F6658 --region ov107 \
 *       --cc dsi/1.1p1 --arm --lang c99 --diff
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
    void (*volatile task)(struct MBiTaskInfo_tag *);
    void (*callback)(struct MBiTaskInfo_tag *);
};

typedef struct MBiTaskWork {
    char _0[0xC0];
    struct MBiTaskInfo_tag * volatile head;
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
    } else {
        pos = p_work->head;
        if (pt == &p_work->fieldC4) {
            while (pos->next != 0)
                pos = pos->next;
            pos->next = pt;
            mbi_task_work = 0;
        } else if (priority < pos->priority) {
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
