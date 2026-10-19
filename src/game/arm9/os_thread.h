#ifndef GAME_ARM9_OS_THREAD_H
#define GAME_ARM9_OS_THREAD_H

/* Public functions of os_thread.c, prototypes copied from their definitions. */

struct OSMutex;
struct _OSMutexQueue;
typedef struct OSMutex OSMutex;
typedef struct _OSMutexQueue OSMutexQueue;

int OSi_GetUnusedThreadId(void);
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue);
void OSi_RescheduleThread(void);
void OS_InitThread(void);
BOOL OS_IsThreadAvailable(void);
void OS_ExitThread(void);
void OSi_ExitThread(void *arg);
void OSi_ExitThread_Destroy(void);
void OS_KillThread(void *thread, void *arg);
void OS_RescheduleThread(void);
void OS_YieldThread(void);
void OS_Sleep(u32 msec);
void OSi_SleepAlarmCallback(void *arg);
void OSi_IdleThreadProc(void);
u32 OS_DisableScheduler(void);
u32 OS_EnableScheduler(void);

#endif
