/*
 * function: func_02085D94
 * address:  0x02085D94
 * packet:   pkt_02085D94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitMessageQueue (os_message.o)
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

void func_02085D94(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount)
{
    mq->queueSend.head = mq->queueSend.tail = 0;
    mq->queueReceive.head = mq->queueReceive.tail = 0;
    mq->msgArray = msgArray;
    mq->msgCount = msgCount;
    mq->firstIndex = 0;
    mq->usedCount = 0;
}
