/*
 * file:     os_message.c
 * unit:     yes
 * function: func_02085D94, OS_SendMessage, OS_ReceiveMessage, func_02085EF0, func_02085F8C
 * address:  0x02085D94
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
extern void OS_WakeupThread(OSThreadQueue *queue);
void func_02085D94(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount);
BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
BOOL func_02085F8C(OSMessageQueue *mq, OSMessage *msg, s32 flags);

/*
 * sdk:      OS_InitMessageQueue (os_message.o)
 */
void func_02085D94(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount)
{
    mq->queueSend.head = mq->queueSend.tail = 0;
    mq->queueReceive.head = mq->queueReceive.tail = 0;
    mq->msgArray = msgArray;
    mq->msgCount = msgCount;
    mq->firstIndex = 0;
    mq->usedCount = 0;
}

BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    while (mq->msgCount <= mq->usedCount) {
        if (!(flags & 1)) {
            (void)OS_RestoreInterrupts(enabled);
            return 0;
        }
        OS_SleepThread(&mq->queueSend);
    }

    mq->msgArray[(mq->firstIndex + mq->usedCount) % mq->msgCount] = msg;
    mq->usedCount++;
    OS_WakeupThread(&mq->queueReceive);
    (void)OS_RestoreInterrupts(enabled);
    return 1;
}

BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags)
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
    mq->firstIndex = (mq->firstIndex + 1) % mq->msgCount;
    mq->usedCount--;
    OS_WakeupThread(&mq->queueSend);
    (void)OS_RestoreInterrupts(enabled);
    return 1;
}

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

/*
 * sdk:      OS_ReadMessage (os_message.o)
 */
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
