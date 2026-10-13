/*
 * file:     field_task.c
 * unit:     yes
 * function: FIELD_TASK_Create, FIELD_TASK_Delete, FIELD_TASK_Update, FIELD_TASK_Start, FIELD_TASK_GetWork, FIELD_TASK_IsFinished, FIELD_TASK_GetState, FIELD_TASK_SetRunning, FIELD_TASK_SetFinished, FIELD_TASK_RunCheck, FIELD_TASK_MANAGER_Create, FIELD_TASK_MANAGER_Delete, FIELD_TASK_MANAGER_Update, FIELD_TASK_MANAGER_AddTask, FIELD_TASK_MANAGER_CountUsedSlots, FIELD_TASK_MANAGER_IsEmpty
 * address:  0x021C6C70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes FIELD_TASK_MANAGER_IsEmpty (021C6E48) from unit_021C6E48.c (lane FXC3: contiguous, same FieldTaskManager).
 *
 * symbols:
 *   d_021DE4D4  0x021DE4D4  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   d_021DE4E4     0x021DE4E4  data  ov021  a4
 *   func_021C6E74  0x021C6E74  thumb  ov021
 *   func_021C6E94  0x021C6E94  thumb  ov021
 *   func_021C6EA8  0x021C6EA8  thumb  ov021
 *   func_021C6EDC  0x021C6EDC  thumb  ov021
 *   func_021C6E5C  0x021C6E5C  thumb  ov021
 *   FIELD_TASK_MANAGER_CountUsedSlots  0x021C6E20  thumb  ov021
 */
#include "field_task_types.h"

enum {
    FIELD_TASK_STATE_CREATED = 0,
    FIELD_TASK_STATE_RUNNING = 1,
    FIELD_TASK_STATE_FINISHED = 2,
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021C6E5C(FieldTaskManager *manager, u8 slot, FieldTask *task, FieldTask *prerequisite);
extern void func_021C6E74(FieldTaskManager *manager, u8 slot);
extern void func_021C6E94(FieldTaskManager *manager, u8 slot);
extern void func_021C6EA8(FieldTaskManager *manager, u8 slot);
extern void func_021C6EDC(FieldTaskManager *manager, u8 slot);
extern char d_021DE4D4[];
extern int d_021DE4E4;

FieldTask *FIELD_TASK_Create(u32 heapId, u32 workSize, FieldTaskCheckFunc check);
void FIELD_TASK_Delete(FieldTask *task);
void FIELD_TASK_Update(FieldTask *task);
void FIELD_TASK_Start(FieldTask *task);
u32 FIELD_TASK_GetWork(FieldTask *task);
int FIELD_TASK_IsFinished(FieldTask *task);
u32 FIELD_TASK_GetState(FieldTask *task);
void FIELD_TASK_SetRunning(FieldTask *task);
int FIELD_TASK_SetFinished(FieldTask *task);
void FIELD_TASK_RunCheck(FieldTask *task);
FieldTaskManager *FIELD_TASK_MANAGER_Create(int count, int heapId);
void FIELD_TASK_MANAGER_Delete(FieldTaskManager *manager);
void FIELD_TASK_MANAGER_Update(FieldTaskManager *manager);
void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);
u8 FIELD_TASK_MANAGER_CountUsedSlots(FieldTaskManager *manager);
int FIELD_TASK_MANAGER_IsEmpty(FieldTaskManager *manager);

/* Allocates a task and its work block. */
FieldTask *FIELD_TASK_Create(u32 heapId, u32 workSize, FieldTaskCheckFunc check)
{
    FieldTask *task = func_02030734(heapId, 0xc, 0, d_021DE4D4, 0x3b);
    task->state = FIELD_TASK_STATE_CREATED;
    task->work = func_02030734(heapId, workSize, 1, d_021DE4D4, 0x3d);
    task->check = check;
    return task;
}

/* Frees the work block and the task. */
void FIELD_TASK_Delete(FieldTask *task)
{
    func_020307B0(task->work);
    func_020307B0(task);
}

/* Runs the check callback once. */
void FIELD_TASK_Update(FieldTask *task)
{
    FIELD_TASK_RunCheck(task);
}

/* Starts the task. */
void FIELD_TASK_Start(FieldTask *task)
{
    FIELD_TASK_SetRunning(task);
}

/* Returns the work block. */
u32 FIELD_TASK_GetWork(FieldTask *task)
{
    return (u32)task->work;
}

/* Returns 1 when the task has finished. */
int FIELD_TASK_IsFinished(FieldTask *task)
{
    if (task->state == FIELD_TASK_STATE_FINISHED) {
        return 1;
    }
    return 0;
}

/* Returns the task state. */
u32 FIELD_TASK_GetState(FieldTask *task)
{
    return task->state;
}

/* Sets the state to running. */
void FIELD_TASK_SetRunning(FieldTask *task)
{
    task->state = FIELD_TASK_STATE_RUNNING;
}

/* Sets the state to finished. */
int FIELD_TASK_SetFinished(FieldTask *task)
{
    task->state = FIELD_TASK_STATE_FINISHED;
    return (int)task;
}

/* While running, calls the check callback and finishes the task when it returns 1. */
void FIELD_TASK_RunCheck(FieldTask *task)
{
    if (task->state == FIELD_TASK_STATE_RUNNING) {
        if (task->check(task->work) == 1)
            FIELD_TASK_SetFinished(task);
    }
}

/* Allocates a manager with count slots. */
FieldTaskManager *FIELD_TASK_MANAGER_Create(int count, int heapId)
{
    FieldTaskManager *manager = func_02030734(heapId, 12, 0, (const char *)&d_021DE4E4, 0x34);

    manager->count = count;
    manager->tasks = func_02030734(heapId, count * 4, 1, (const char *)&d_021DE4E4, 0x36);
    manager->prerequisites = func_02030734(heapId, count * 4, 1, (const char *)&d_021DE4E4, 0x37);
    return manager;
}

/* Frees every task, both slot tables and the manager. */
void FIELD_TASK_MANAGER_Delete(FieldTaskManager *manager)
{
    int slot;
    for (slot = 0; slot < manager->count; slot++)
        func_021C6E74(manager, slot);
    func_020307B0(manager->tasks);
    func_020307B0(manager->prerequisites);
    func_020307B0(manager);
}

/* Per frame: run the running tasks, start tasks whose prerequisite finished, free finished tasks. */
void FIELD_TASK_MANAGER_Update(FieldTaskManager *manager)
{
    int slot;

    for (slot = 0; slot < manager->count; slot++)
        func_021C6E94(manager, slot);
    for (slot = 0; slot < manager->count; slot++)
        func_021C6EA8(manager, slot);
    for (slot = 0; slot < manager->count; slot++)
        func_021C6EDC(manager, slot);
}

/* Puts a task in the first free slot; starts it now unless it has a prerequisite.
 * With no free slot the task is freed. */
void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite)
{
    int slot;

    for (slot = 0; slot < manager->count; slot++) {
        if (manager->tasks[slot] == 0) {
            func_021C6E5C(manager, slot, task, prerequisite);
            if (prerequisite == 0)
                FIELD_TASK_Start(task);
            return;
        }
    }
    FIELD_TASK_Delete(task);
}

/* Returns the number of used slots. */
u8 FIELD_TASK_MANAGER_CountUsedSlots(FieldTaskManager *manager)
{
    int slot;
    u8 used = 0;
    for (slot = 0; slot < manager->count; slot++) {
        if (manager->tasks[slot] != 0)
            used++;
    }
    return used;
}

/* TRUE when the manager has no task queued. */
int FIELD_TASK_MANAGER_IsEmpty(FieldTaskManager *manager)
{
    if (FIELD_TASK_MANAGER_CountUsedSlots(manager) == 0) {
        return 1;
    }
    return 0;
}
