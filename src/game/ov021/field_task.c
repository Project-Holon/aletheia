/*
 * file:     field_task.c
 * unit:     yes
 * function: func_021C6C70, func_021C6CA8, func_021C6CBC, func_021C6CC4, func_021C6CCC, func_021C6CD0, func_021C6CE0, func_021C6CE4, func_021C6CEC, func_021C6CF4, func_021C6D10, func_021C6D5C, func_021C6D90, func_021C6DE0, func_021C6E20, func_021C6E48
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
 *   func_021C6E20  0x021C6E20  thumb  ov021
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

FieldTask *func_021C6C70(u32 heapId, u32 workSize, FieldTaskCheckFunc check);
void func_021C6CA8(FieldTask *task);
void func_021C6CBC(FieldTask *task);
void func_021C6CC4(FieldTask *task);
u32 func_021C6CCC(FieldTask *task);
int func_021C6CD0(FieldTask *task);
u32 func_021C6CE0(FieldTask *task);
void func_021C6CE4(FieldTask *task);
int func_021C6CEC(FieldTask *task);
void func_021C6CF4(FieldTask *task);
FieldTaskManager *func_021C6D10(int count, int heapId);
void func_021C6D5C(FieldTaskManager *manager);
void func_021C6D90(FieldTaskManager *manager);
void func_021C6DE0(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);
u8 func_021C6E20(FieldTaskManager *manager);
int func_021C6E48(FieldTaskManager *manager);

/* Allocates a task and its work block. */
FieldTask *func_021C6C70(u32 heapId, u32 workSize, FieldTaskCheckFunc check)
{
    FieldTask *task = func_02030734(heapId, 0xc, 0, d_021DE4D4, 0x3b);
    task->state = FIELD_TASK_STATE_CREATED;
    task->work = func_02030734(heapId, workSize, 1, d_021DE4D4, 0x3d);
    task->check = check;
    return task;
}

/* Frees the work block and the task. */
void func_021C6CA8(FieldTask *task)
{
    func_020307B0(task->work);
    func_020307B0(task);
}

/* Runs the check callback once. */
void func_021C6CBC(FieldTask *task)
{
    func_021C6CF4(task);
}

/* Starts the task. */
void func_021C6CC4(FieldTask *task)
{
    func_021C6CE4(task);
}

/* Returns the work block. */
u32 func_021C6CCC(FieldTask *task)
{
    return (u32)task->work;
}

/* Returns 1 when the task has finished. */
int func_021C6CD0(FieldTask *task)
{
    if (task->state == FIELD_TASK_STATE_FINISHED) {
        return 1;
    }
    return 0;
}

/* Returns the task state. */
u32 func_021C6CE0(FieldTask *task)
{
    return task->state;
}

/* Sets the state to running. */
void func_021C6CE4(FieldTask *task)
{
    task->state = FIELD_TASK_STATE_RUNNING;
}

/* Sets the state to finished. */
int func_021C6CEC(FieldTask *task)
{
    task->state = FIELD_TASK_STATE_FINISHED;
    return (int)task;
}

/* While running, calls the check callback and finishes the task when it returns 1. */
void func_021C6CF4(FieldTask *task)
{
    if (task->state == FIELD_TASK_STATE_RUNNING) {
        if (task->check(task->work) == 1)
            func_021C6CEC(task);
    }
}

/* Allocates a manager with count slots. */
FieldTaskManager *func_021C6D10(int count, int heapId)
{
    FieldTaskManager *manager = func_02030734(heapId, 12, 0, (const char *)&d_021DE4E4, 0x34);

    manager->count = count;
    manager->tasks = func_02030734(heapId, count * 4, 1, (const char *)&d_021DE4E4, 0x36);
    manager->prerequisites = func_02030734(heapId, count * 4, 1, (const char *)&d_021DE4E4, 0x37);
    return manager;
}

/* Frees every task, both slot tables and the manager. */
void func_021C6D5C(FieldTaskManager *manager)
{
    int slot;
    for (slot = 0; slot < manager->count; slot++)
        func_021C6E74(manager, slot);
    func_020307B0(manager->tasks);
    func_020307B0(manager->prerequisites);
    func_020307B0(manager);
}

/* Per frame: run the running tasks, start tasks whose prerequisite finished, free finished tasks. */
void func_021C6D90(FieldTaskManager *manager)
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
void func_021C6DE0(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite)
{
    int slot;

    for (slot = 0; slot < manager->count; slot++) {
        if (manager->tasks[slot] == 0) {
            func_021C6E5C(manager, slot, task, prerequisite);
            if (prerequisite == 0)
                func_021C6CC4(task);
            return;
        }
    }
    func_021C6CA8(task);
}

/* Returns the number of used slots. */
u8 func_021C6E20(FieldTaskManager *manager)
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
int func_021C6E48(FieldTaskManager *manager)
{
    if (func_021C6E20(manager) == 0) {
        return 1;
    }
    return 0;
}
