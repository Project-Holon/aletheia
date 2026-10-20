/*
 * file:     card_task.c
 * unit:     yes
 * function: CARDi_ExecuteOldTypeTask, CARDi_OldTypeTaskThread, CARDi_WaitForTask, CARDi_EndTask
 * address:  0x02076170
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_SetThreadPriority  0x02085988  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   CARDi_EndTask  0x020762A8  arm
 *   cardi_common  0x02150200  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
 *   OS_WakeupThread  0x02085800  arm
 */
#include "../types.h"

#include "../sdk_os.h"

#include "card_common.h"

#include "../sdk_card.h"

#include "os_thread.h"
extern void CARDi_EndTask(CARDiCommon *p);
#include "os_system.h"
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
void CARDi_OldTypeTaskThread(void *arg);
BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg);
extern CARDiCommon cardi_common;

/*
 * sdk:      CARDi_ExecuteOldTypeTask (libcard.TWL.HYB.a card_task.o)
 */
BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async)
{
    CARDiCommon *p = &cardi_common;

    if (async)
    {
        (void)OS_SetThreadPriority(p->thread.context, p->priority);
        p->task_func = task;
        p->flag |= 8;
        OS_WakeupThreadDirect(p->thread.context);
    }
    else
    {
        (*task)(p);
        CARDi_EndTask(p);
    }
    return async ? 1 : (p->cmd->result == 0);
}

/*
 * sdk:      CARDi_OldTypeTaskThread (libcard.TWL.HYB.a card_task.o)
 */
void CARDi_OldTypeTaskThread(void *arg)
{
    CARDiCommon *p = &cardi_common;

    for (;;)
    {
        u32 bak_psr = OS_DisableInterrupts();

        for (;;)
        {
            if ((p->flag & 0x8) != 0)
            {
                break;
            }
            OS_SleepThread(0);
        }
        (void)OS_RestoreInterrupts(bak_psr);
        (void)CARDi_ExecuteOldTypeTask(p->task_func, 0);
    }
}

/*
 * sdk:      CARDi_WaitForTask (libcard.TWL.HYB.a card_task.o)
 */
BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg)
{
    u32 bak_psr = OS_DisableInterrupts();

    while ((p->flag & 4) != 0)
    {
        OS_SleepThread(p->busy_q);
    }
    if (restart)
    {
        p->flag |= 4;
        p->callback = callback;
        p->callback_arg = callback_arg;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return (p->cmd->result == 0);
}

/*
 * sdk:      CARDi_EndTask (libcard.TWL.HYB.a card_task.o)
 */
void CARDi_EndTask(CARDiCommon *p)
{
    void (*const callback)(void *) = p->callback;
    void *const userdata = p->callback_arg;
    u32 bak_psr = OS_DisableInterrupts();

    p->flag &= ~(0x04 | 0x08 | 0x40);
    OS_WakeupThread(p->busy_q);
    (void)OS_RestoreInterrupts(bak_psr);
    if (callback)
    {
        (*callback)(userdata);
    }
}
