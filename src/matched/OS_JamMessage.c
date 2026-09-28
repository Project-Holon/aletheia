/*
 * function: OS_JamMessage
 * address:  0x02085EF0
 * packet:   pkt_02085EF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_message.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Puts a message at the head of the queue, blocking while it is full when asked to.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_SleepThread        0x020857B0  arm
 *   OS_WakeupThread       0x02085800  arm
 *   _s32_div_f            0x0209C0A4  arm
 */

typedef unsigned long u32;
typedef long s32;
typedef int BOOL;
typedef u32 OSIntrMode;
typedef void *OSMessage;

typedef struct _OSThreadQueue {
    struct _OSThread *head;
    struct _OSThread *tail;
} OSThreadQueue;

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    s32 msgCount;
    s32 firstIndex;
    s32 usedCount;
} OSMessageQueue;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_SleepThread(OSThreadQueue *queue);
extern void OS_WakeupThread(OSThreadQueue *queue);

BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    while (mq->msgCount <= mq->usedCount) {
        if (!(flags & 1)) {
            (void)OS_RestoreInterrupts(enabled);
            return 0;
        }
        OS_SleepThread(&mq->queueSend);
    }

    mq->firstIndex = (mq->firstIndex + mq->msgCount - 1) % mq->msgCount;
    mq->msgArray[mq->firstIndex] = msg;
    mq->usedCount++;
    OS_WakeupThread(&mq->queueReceive);
    (void)OS_RestoreInterrupts(enabled);
    return 1;
}
