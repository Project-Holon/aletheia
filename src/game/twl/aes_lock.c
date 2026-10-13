/*
 * file:     aes_lock.c
 * unit:     yes
 * function: AESi_InitLock, AESi_TryLock, AESi_Lock, AESi_Unlock
 * address:  0x02707AEC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libaes.TWL.HYB.a aes_lock.o
 */
typedef unsigned int u32;
typedef struct OSThread OSThread;
typedef struct {
    OSThread *head;
    OSThread *tail;
} OSThreadQueueLike;
typedef struct {
    OSThread *owner;
    u32 count;
    OSThreadQueueLike queue;
} SysLockLike;
typedef struct {
    u32 reserved;
    OSThread *current;
} ThreadInfoLike;

extern SysLockLike g_02735B20;
extern ThreadInfoLike g_02150FEC;
extern int OS_DisableInterrupts(void);
extern int OS_RestoreInterrupts(int);
extern void OS_SleepThread(void *queue);
extern void OS_WakeupThread(void *queue);

void AESi_InitLock(void);
int AESi_TryLock(void);
void AESi_Lock(void);
void AESi_Unlock(void);

void AESi_InitLock(void)
{
    g_02735B20.queue.tail = 0;
    g_02735B20.queue.head = 0;
    g_02735B20.owner = 0;
    g_02735B20.count = 0;
}

int AESi_TryLock(void)
{
    int enabled = OS_DisableInterrupts();
    OSThread *cur = g_02150FEC.current;
    int ok;
    if ((*(OSThread * volatile *)&g_02735B20.owner) == 0) {
        (*(OSThread * volatile *)&g_02735B20.owner) = cur;
        ok = 1;
        g_02735B20.count = 1;
    } else if ((*(OSThread * volatile *)&g_02735B20.owner) == cur) {
        ok = 1;
        g_02735B20.count++;
    } else {
        ok = 0;
    }
    OS_RestoreInterrupts(enabled);
    return ok;
}

void AESi_Lock(void)
{
    int enabled = OS_DisableInterrupts();
    OSThread *cur = g_02150FEC.current;
    for (;;) {
        if (g_02735B20.owner == 0) {
            g_02735B20.owner = cur;
            g_02735B20.count = 1;
            break;
        }
        if (g_02735B20.owner == cur) {
            g_02735B20.count++;
            break;
        }
        OS_SleepThread(&g_02735B20.queue);
    }
    OS_RestoreInterrupts(enabled);
}

void AESi_Unlock(void)
{
    int enabled = OS_DisableInterrupts();
    if (g_02735B20.owner != 0) {
        if (--g_02735B20.count == 0) {
            g_02735B20.owner = 0;
            OS_WakeupThread(&g_02735B20.queue);
        }
    }
    OS_RestoreInterrupts(enabled);
}
