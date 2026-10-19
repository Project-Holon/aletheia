/*
 * file:     nhttp_os_ntr.c
 * unit:     yes
 * function: NHTTPi_createCommThread, NHTTPi_destroyCommThread, NHTTPi_idleCommThread, NHTTPi_kickCommThread, NHTTPi_CheckCurrentThread, NHTTPi_CommThreadProc
 * address:  0x021B9B64
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_IsCreateCommThreadMessageQueue 0x021BBEB8 arm ov114
 *   OS_InitMessageQueue 0x02085D94 arm
 *   NHTTPi_IsCreateCommThreadMessageQueueOn 0x021BBEA0 arm ov114
 *   OS_CreateThread 0x020853C0 arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   NHTTPi_CommThreadProc 0x021B9C60 arm ov114
 *   OS_Terminate 0x02088234 arm
 *   gMslRefToken 0x02150FEC data
 *   NHTTPi_CommThreadProcMain  0x021BE4D4  arm  ov114
 *   OS_JoinThread  0x02085710  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 */
#include "nhttp_types.h"

#include "../types.h"

typedef struct {
    int pad;
    int *current;
} OSInfo;

extern int NHTTPi_IsCreateCommThreadMessageQueue(NHTTPThreadInfo *threadInfo_p);
#include "../sdk_os.h"

extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern void NHTTPi_IsCreateCommThreadMessageQueueOn(NHTTPThreadInfo *threadInfo_p);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void NHTTPi_CommThreadProc(void *);
extern void OS_JoinThread(void *);
extern s32 OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, s32 flags);
extern s32 OS_SendMessage(struct OSMessageQueue *mq, void *msg, s32 flags);
extern void OS_Terminate(void);
int NHTTPi_createCommThread(NHTTPThreadInfo *threadInfo_p, unsigned long priority, unsigned long *stack_p);
void NHTTPi_destroyCommThread(NHTTPThreadInfo *threadInfo_p, NHTTPBgnEndInfo *bgnEndInfo_p);
void NHTTPi_idleCommThread(NHTTPThreadInfo *threadInfo_p);
void NHTTPi_kickCommThread(NHTTPThreadInfo *threadInfo_p);
void NHTTPi_CheckCurrentThread(NHTTPThreadInfo *threadInfo_p, int isCommThread);
extern void NHTTPi_CommThreadProcMain(void);
extern OSInfo gMslRefToken;

int NHTTPi_createCommThread(NHTTPThreadInfo *threadInfo_p, unsigned long priority, unsigned long *stack_p)
{
    if (NHTTPi_IsCreateCommThreadMessageQueue(threadInfo_p) == 0) {
        OS_InitMessageQueue((struct OSMessageQueue *)threadInfo_p->msgQueue, threadInfo_p->msgArray, 3);
        NHTTPi_IsCreateCommThreadMessageQueueOn(threadInfo_p);
    }
    OS_CreateThread(threadInfo_p->commThread, NHTTPi_CommThreadProc, 0, (char *)stack_p + 0x2000, 0x2000, priority);
    OS_WakeupThreadDirect(threadInfo_p->commThread);
    return 1;
}

void NHTTPi_destroyCommThread(NHTTPThreadInfo *threadInfo_p, NHTTPBgnEndInfo *bgnEndInfo_p)
{
    bgnEndInfo_p->isThreadEnd = 1;
    NHTTPi_kickCommThread(threadInfo_p);
    OS_JoinThread(threadInfo_p->commThread);
}

void NHTTPi_idleCommThread(NHTTPThreadInfo *threadInfo_p)
{
    int message;

    OS_ReceiveMessage((struct OSMessageQueue *)threadInfo_p->msgQueue, (void **)(&message), 1);
}

void NHTTPi_kickCommThread(NHTTPThreadInfo *threadInfo_p)
{
    OS_SendMessage((struct OSMessageQueue *)threadInfo_p->msgQueue, 0, 0);
}

void NHTTPi_CheckCurrentThread(NHTTPThreadInfo *threadInfo_p, int isCommThread)
{
    int *commThread_p = (int *)threadInfo_p->commThread;
    int *currentThread_p = gMslRefToken.current;

    if (currentThread_p) {
        if ((isCommThread == 0 && currentThread_p != commThread_p) || (isCommThread != 0 && currentThread_p == commThread_p)) {
            OS_Terminate();
        }
    }
}

void NHTTPi_CommThreadProc(void *arg)
{
    NHTTPi_CommThreadProcMain();
}
