/*
 * function: func_02085F8C
 * address:  0x02085F8C
 * packet:   pkt_02085F8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_ReadMessage (os_message.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_SleepThread        0x020857B0  arm
 */

typedef unsigned long u32;
typedef long s32;
typedef int BOOL;
typedef u32 OSIntrMode;
typedef void *OSMessage;

typedef struct OSThreadQueue {
    void *head;
    void *tail;
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

BOOL func_02085F8C(OSMessageQueue *mq, OSMessage *msg, s32 flags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    while (mq->usedCount == 0) {
        if (!(flags & 1)) {
            (void)OS_RestoreInterrupts(enabled);
            return 0;
        }
        OS_SleepThread(&mq->queueReceive);
    }

    if (msg != 0) {
        *msg = mq->msgArray[mq->firstIndex];
    }
    (void)OS_RestoreInterrupts(enabled);
    return 1;
}
