#ifndef GAME_ARM9_CARD_COMMON_H
#define GAME_ARM9_CARD_COMMON_H

#include "../types.h"
#include "../sdk_os.h"
#include "../sdk_card.h"

/* Shared card library state. */

typedef struct CARDiCommandArg
{
    int result;
    CARDBackupType type;
    u32 id;
    u32 src;
    u32 dst;
    u32 len;
    CARDBackupTypeInfo spec;
} CARDiCommandArg;

typedef struct CARDDmaInterface
{
    void (*Recv)(u32 channel, const void *src, void *dst, u32 len);
    void (*Stop)(u32 channel);
} CARDDmaInterface;

typedef struct CARDiCommon
{
    CARDiCommandArg *cmd;
    volatile u32 flag;
    u32 priority;
    u32 flush_threshold_ic;
    u32 flush_threshold_dc;
    s32 lock_owner;
    int lock_ref;
    OSThreadQueue lock_queue[1];
    CARDTarget lock_target;
    struct
    {
        OSThread context[1];
        u8 stack[0x400];
    } thread;
    void (*task_func)(struct CARDiCommon *);
    void (*callback)(void *);
    void *callback_arg;
    OSThreadQueue busy_q[1];
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    const CARDDmaInterface *DmaCall;
    int req_type;
    int req_retry;
    int req_mode;
    OSThread *current_thread_9;
} CARDiCommon;

void CARDi_LockResource(s32 owner, CARDTarget target);
void CARDi_UnlockResource(s32 owner, CARDTarget target);
u32 CARDi_GetAccessLevel(void);
BOOL CARDi_WaitAsync(void);
int CARDi_TryWaitAsync(void);
void CARDi_InitResourceLock(void);
void CARDi_InitCommand(void);

#endif
