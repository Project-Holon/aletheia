/*
 * function: AESi_Unlock
 * address:  0x02707BDC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02735B20  0x02735B20  data
 *   gMslRefToken  0x02150FEC  data
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
extern ThreadInfoLike gMslRefToken;
extern int OS_DisableInterrupts(void);
extern int OS_RestoreInterrupts(int);
extern void OS_SleepThread(void *queue);
extern void OS_WakeupThread(void *queue);

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
