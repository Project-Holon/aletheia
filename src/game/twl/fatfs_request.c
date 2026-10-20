/*
 * file:     fatfs_request.c
 * unit:     yes
 * function: FATFSi_SendToPXI, FATFSi_GetThreadHandle, FATFSi_AllocateCommandBuffer, FATFSi_AllocateEmergencyCommandBuffer, FATFSi_FreeCommandBuffer, FATFSi_PostRequest, FATFSi_WaitForRequest
 * address:  0x027040B4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * sdk:      libfatfs.TWL.HYB.a fatfs_request.o
 * status:   EXACT
 *
 * symbols:
 *   SVC_WaitByLoop  0x02004490  thumb  arm9
 *   OS_SleepThread  0x020857B0  arm  arm9
 *   DC_FlushRange  0x020862F0  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   PXIi_HandlerRecvFifoNotEmpty  0x02088688  arm  arm9
 *   OS_UnlockMutex  0x02086078  arm  arm9
 *   OS_GetProcMode  0x020879EC  arm  arm9
 *   DAT_02734420                 0x02734420  data
 *   DAT_02734428                 0x02734428  data
 *   OSi_ThreadInfo                0x02150FEC  data
 *   data_027343E0                0x027343E0  data
 *   data_0273442C                0x0273442C  data
 */
#include "../types.h"
#include "fatfs_request.h"

typedef struct FsWait {
    struct FsWait *next;
    u32 key;
    struct FATFSCommandBuffer *slot;
} FsWait;

typedef struct FsRoot {
    u32 pad00;
    FsWait *waiters;
    u32 pad08[6];
    FATFSCommandBuffer *busy;
    u32 pad24[16];
    FATFSCommandBuffer *spare;
    FATFSCommandBuffer *cur;
} FsRoot;

#include "../arm9/os_cache.h"
#include "../arm9/pxi_fifo.h"
typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#include "../sdk_os.h"

#include "../arm9/os_mutex.h"
#include "../arm9/svc_wait_by_loop.h"
#include "../arm9/os_thread.h"
extern FsRoot data_027343E0;
extern OSMutex data_0273442C;
extern FATFSCommandBuffer *DAT_02734428;
extern OSThreadQueue DAT_02734420;

void FATFSi_SendToPXI(FATFSCommandBuffer *command);
u32 FATFSi_GetThreadHandle(void);
FATFSCommandBuffer *FATFSi_AllocateCommandBuffer(u32 arg);
FATFSCommandBuffer *FATFSi_AllocateEmergencyCommandBuffer(u32 arg);
void FATFSi_FreeCommandBuffer(FATFSCommandBuffer *command);
void FATFSi_PostRequest(FATFSCommandBuffer *request);
void FATFSi_WaitForRequest(FATFSCommandBuffer *request);

void FATFSi_SendToPXI(FATFSCommandBuffer *command) {
    DC_FlushRange(command, 0x800);
    while (PXI_SendWordByFifo(0x14, (u32)command >> 5, 0) < 0) {
    }
}

/*
 *   witness.  The address is a real arm9 bss object (layout/data_objects.txt
 *   row `arm9 0x02150FEC pool`, 160+ ARM9 pool referrers), but sole-ref
 *   refuses it here because its only referrer inside this compared range IS
 *   the site under test, and a bss address has no ROM word for sole-ref/self.
 */
u32 FATFSi_GetThreadHandle(void) {
    if (OS_GetProcMode() == 0x12) {
        return 0x80000000u;
    }
    return (u32)OSi_ThreadInfo.current;
}

FATFSCommandBuffer *FATFSi_AllocateCommandBuffer(u32 arg) {
    FATFSCommandBuffer *e = 0;
    u32 ime = OS_DisableInterrupts();
    u32 key = FATFSi_GetThreadHandle();
    FATFSCommandBuffer *p;
    for (p = data_027343E0.busy; (p != 0) ? 1 : 0; p = p->next) {
        if (p->key == key) {
            p->key = 0;
            e = p;
            p->mode = 2;
            break;
        }
    }
    OS_RestoreInterrupts(ime);
    if (e == 0) {
        OS_LockMutex(&data_0273442C);
        e = data_027343E0.spare;
        e->mode = 0;
    }
    {
        FsWait *w;
        ime = OS_DisableInterrupts();
        key = FATFSi_GetThreadHandle();
        for (w = data_027343E0.waiters; (w != 0) ? 1 : 0; w = w->next) {
            if (w->key == key) {
                w->slot = e;
                break;
            }
        }
        OS_RestoreInterrupts(ime);
    }
    e->arg = arg;
    e->state = 2;
    e->qnext = 0;
    return e;
}

FATFSCommandBuffer *FATFSi_AllocateEmergencyCommandBuffer(u32 arg) {
    if (OS_GetProcMode() != 0x12) {
        return FATFSi_AllocateCommandBuffer(arg);
    } else {
        FATFSCommandBuffer *e = data_027343E0.cur;
        e->arg = arg;
        e->state = 2;
        e->qnext = 0;
        e->mode = 0;
        return e;
    }
}

void FATFSi_FreeCommandBuffer(FATFSCommandBuffer *command) {
    if (command == data_027343E0.spare) {
        OS_UnlockMutex(&data_0273442C);
    }
}

void FATFSi_PostRequest(FATFSCommandBuffer *request)
{
    FATFSi_SendToPXI(request);
}

void FATFSi_WaitForRequest(FATFSCommandBuffer *request) {
    u32 busy = 1;
    while ((busy != 0) ? 1 : 0) {
        u32 ime = OS_DisableInterrupts();
        /* the list is shared: every access rereads it */
        FATFSCommandBuffer * volatile *pp = &DAT_02734428;
        FATFSCommandBuffer *p;
        while (((p = *pp) != 0) ? 1 : 0) {
            if (*pp == request) {
                busy = 0;
                *pp = (*pp)->qnext;
                request->qnext = 0;
                break;
            }
            pp = &(*pp)->qnext;
        }
        if (busy != 0) {
            if (OS_GetProcMode() == 0x12) {
                PXIi_HandlerRecvFifoNotEmpty();
                SVC_WaitByLoop(10000);
            } else {
                OS_SleepThread(&DAT_02734420);
            }
        }
        OS_RestoreInterrupts(ime);
    }
}
