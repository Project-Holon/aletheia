#ifndef GAME_ARM9_OS_THREAD_H
#define GAME_ARM9_OS_THREAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_thread.c, prototypes copied from their definitions. */

#include "../sdk_os_thread.h"
#include "../sdk_os_thread.h"
#include "../sdk_os.h"
#include "../sdk_os.h"
#include "../types.h"

int OSi_GetUnusedThreadId(void);
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
OSThread *OSi_RemoveSpecifiedLinkFromQueue(OSThreadQueue *queue, OSThread *thread);
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue);
void OSi_InsertThreadToList(OSThread *thread);
void OSi_RemoveThreadFromList(OSThread *thread);
void OSi_RescheduleThread(void);
void OS_InitThread(void);
BOOL OS_IsThreadAvailable(void);
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
void OS_ExitThread(void);
void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg);
void OSi_ExitThread(void *arg);
void OSi_ExitThread_Destroy(void);
void OS_DestroyThread(OSThread *thread);
void OS_KillThread(void *thread, void *arg);
void OS_KillThreadWithPriority(OSThread *thread, void *arg, u32 prio);
void OSi_CancelThreadAlarmForSleep(OSThread *thread);
void OS_JoinThread(OSThread *thread);
int OS_IsThreadTerminated(const OSThread *thread);
void OS_SleepThreadDirect(OSThread *thread, OSThreadQueue *queue);
void OS_SleepThread(OSThreadQueue *queue);
void OS_WakeupThread(OSThreadQueue *queue);
void OS_WakeupThreadDirect(OSThread *thread);
OSThread *OS_SelectThread(void);
void OS_RescheduleThread(void);
void OS_YieldThread(void);
BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
u32 OS_GetThreadPriority(const OSThread *thread);
void OS_Sleep(u32 msec);
void OSi_SleepAlarmCallback(void *arg);
void OSi_IdleThreadProc(void);
u32 OS_DisableScheduler(void);
u32 OS_EnableScheduler(void);
void OS_SetThreadDestructor(OSThread *thread, void (*dtor)(void *));
/* END mkheaders: generated region */

#endif
