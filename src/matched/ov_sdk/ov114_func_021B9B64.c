/*
 * function: NHTTPi_createCommThread
 * address:  0x021B9B64
 * packet:   pkt_ov114_021B9B64
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_createCommThread (libnhttp.TWL.HYB.a(nhttp_os_ntr.o))
 *
 * symbols:
 *   NHTTPi_IsCreateCommThreadMessageQueue 0x021BBEB8 arm ov114
 *   func_02085D94 0x02085D94 arm
 *   NHTTPi_IsCreateCommThreadMessageQueueOn 0x021BBEA0 arm ov114
 *   OS_CreateThread 0x020853C0 arm
 *   OS_WakeupThreadDirect 0x02085868 arm
 *   NHTTPi_CommThreadProc 0x021B9C60 arm ov114
 */

typedef struct {
    char pad[0x20];
    void *msgArray[3];
    char commThread[0x2c];
    char mq[0x1c];
} ThreadInfo;

typedef unsigned char  u8;
extern int NHTTPi_IsCreateCommThreadMessageQueue(u8 *p);
typedef signed int     s32;
struct OSMessageQueue;
extern void func_02085D94(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern void NHTTPi_IsCreateCommThreadMessageQueueOn(u8 *p);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void NHTTPi_CommThreadProc(void *);

int NHTTPi_createCommThread(ThreadInfo *threadInfo_p, unsigned long priority, unsigned long *stack_p)
{
    if (NHTTPi_IsCreateCommThreadMessageQueue((u8 *)threadInfo_p) == 0) {
        func_02085D94((struct OSMessageQueue *)threadInfo_p, threadInfo_p->msgArray, 3);
        NHTTPi_IsCreateCommThreadMessageQueueOn((u8 *)threadInfo_p);
    }
    OS_CreateThread((char *)threadInfo_p + 0x2c, NHTTPi_CommThreadProc, 0, (char *)stack_p + 0x2000, 0x2000, priority);
    OS_WakeupThreadDirect((char *)threadInfo_p + 0x2c);
    return 1;
}
