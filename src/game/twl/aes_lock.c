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
 *
 * symbols:
 *   gMslRefToken  0x02150FEC  data  arm9
 */
#include "../types.h"
#include "../sdk_os.h"

typedef struct {
    OSThread *owner;
    u32 count;
    OSThreadQueue queue;
} SysLockLike;
typedef struct {
    u32 reserved;
    OSThread *current;
} ThreadInfoLike;

extern SysLockLike g_02735B20;
extern ThreadInfoLike gMslRefToken;
#include "../arm9/os_system.h"
#include "../arm9/os_thread.h"

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
    OSThread *cur = gMslRefToken.current;
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
    OSThread *cur = gMslRefToken.current;
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
