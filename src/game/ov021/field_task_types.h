#ifndef FIELD_TASK_TYPES_H
#define FIELD_TASK_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* One queued field task: a state, a work block and a per-frame check callback. */
typedef int (*FieldTaskCheckFunc)(u32 *work);

typedef struct FieldTask {
    u32 state;                 /* 0 created, 1 running, 2 finished */
    u32 *work;                 /* heap block owned by the task */
    FieldTaskCheckFunc check;  /* returns 1 when the task is done */
} FieldTask;

/* Fixed-size table of tasks. A task with a prerequisite starts only
 * after the prerequisite task has finished. */
typedef struct FieldTaskManager {
    u8 count;
    u8 pad[3];
    FieldTask **tasks;
    FieldTask **prerequisites;
} FieldTaskManager;

#endif
