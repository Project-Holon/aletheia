/*
 * file:     field_task.c
 * unit:     yes
 * function: FIELD_TASK_Create, FIELD_TASK_Delete, FIELD_TASK_Update, FIELD_TASK_Start, FIELD_TASK_GetWork, FIELD_TASK_IsFinished, FIELD_TASK_GetState, FIELD_TASK_SetRunning, FIELD_TASK_SetFinished, FIELD_TASK_RunCheck
 * address:  0x021C6C70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_task.c by tools/splitfile.py.
 *
 * symbols:
 *   d_021DE4D4  0x021DE4D4  data  ov021  a4
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "field_task_types.h"

enum {
    FIELD_TASK_STATE_CREATED = 0,
    FIELD_TASK_STATE_RUNNING = 1,
    FIELD_TASK_STATE_FINISHED = 2,
};

#include "../arm9/gfl_heap_wrap.h"


extern char d_021DE4D4[];

FieldTask *FIELD_TASK_Create(u32 heapId, u32 workSize, FieldTaskCheckFunc check);

void FIELD_TASK_Delete(FieldTask *task);

void FIELD_TASK_Update(FieldTask *task);

void FIELD_TASK_Start(FieldTask *task);

void *FIELD_TASK_GetWork(FieldTask *task);

int FIELD_TASK_IsFinished(FieldTask *task);

u32 FIELD_TASK_GetState(FieldTask *task);

void FIELD_TASK_SetRunning(FieldTask *task);

int FIELD_TASK_SetFinished(FieldTask *task);

void FIELD_TASK_RunCheck(FieldTask *task);

/* Allocates a task and its work block. */
FieldTask *FIELD_TASK_Create(u32 heapId, u32 workSize, FieldTaskCheckFunc check)
{
    FieldTask *task = GFL_HEAP_Alloc(heapId, 0xc, 0, d_021DE4D4, 0x3b);
    task->state = FIELD_TASK_STATE_CREATED;
    task->work = GFL_HEAP_Alloc(heapId, workSize, 1, d_021DE4D4, 0x3d);
    task->check = check;
    return task;
}

/* Frees the work block and the task. */
void FIELD_TASK_Delete(FieldTask *task)
{
    GFL_HEAP_Free(task->work);
    GFL_HEAP_Free(task);
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
void *FIELD_TASK_GetWork(FieldTask *task)
{
    return task->work;
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
    return (sptr)task;
}

/* While running, calls the check callback and finishes the task when it returns 1. */
void FIELD_TASK_RunCheck(FieldTask *task)
{
    if (task->state == FIELD_TASK_STATE_RUNNING) {
        if (task->check(task->work) == 1)
            FIELD_TASK_SetFinished(task);
    }
}
