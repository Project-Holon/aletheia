#ifndef GAME_ARM9_OS_MUTEX_H
#define GAME_ARM9_OS_MUTEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_mutex.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../sdk_os_thread.h"
#include "../types.h"

void OS_InitMutex(OSMutex *mutex);
void OS_LockMutex(OSMutex *mutex);
void OS_UnlockMutex(OSMutex *mutex);
void OSi_UnlockAllMutex(OSThread *thread);
BOOL OS_TryLockMutex(OSMutex *mutex);
void OSi_UnlockMutexCore(OSMutex *mutex, u32 type);
void OSi_EnqueueTail(OSThread *thread, OSMutex *mutex);
void OSi_DequeueItem(OSThread *thread, OSMutex *mutex);
/* END mkheaders: generated region */

#endif
