#ifndef GAME_OV021_FIELD_TASK_H
#define GAME_OV021_FIELD_TASK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_task.c, prototypes copied from their definitions. */

#include "../ov021/field_task_types.h"
#include "../types.h"
#include "../ov021/field_task_types.h"

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
/* END mkheaders: generated region */

#endif
