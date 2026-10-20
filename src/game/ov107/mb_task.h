#ifndef GAME_OV107_MB_TASK_H
#define GAME_OV107_MB_TASK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_task.c, prototypes copied from their definitions. */

struct MBiTaskInfo;

#include "../sdk_mb.h"
#include "../types.h"

void MBi_TaskThread(void *arg);
void MBi_InitTaskThread(void *p_work, unsigned long size);
int MBi_IsTaskAvailable(void);
void MBi_InitTaskInfo(void *pt);
int MBi_IsTaskBusy(MBiTaskInfo *pt);
void MBi_SetTask(struct MBiTaskInfo *pt, void (*task)(struct MBiTaskInfo *), void (*callback)(struct MBiTaskInfo *), u32 priority);
void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo *));
/* END mkheaders: generated region */

#endif
