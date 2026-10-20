#ifndef GAME_ARM9_CARD_TASK_H
#define GAME_ARM9_CARD_TASK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of card_task.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/card_common.h"

BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
void CARDi_OldTypeTaskThread(void *arg);
BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg);
void CARDi_EndTask(CARDiCommon *p);
/* END mkheaders: generated region */

#endif
