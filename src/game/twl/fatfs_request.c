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
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int BOOL;

typedef struct FsWait {
    struct FsWait *next;
    u32 key;
    struct Big *slot;
} FsWait;

/* One command buffer.  qnext (0x0C) links it into the list that
 * FATFSi_WaitForRequest waits on; next (0x808) links the busy list. */
typedef struct Big {
    u32 arg;
    u32 state;
    u32 mode;
    struct Big *qnext;
    u8 buf[0x7F0];
    u32 key;
    u32 pad804;
    u32 pad808;
    struct Big *next;
} Big;

typedef struct FsRoot {
    u32 pad00;
    FsWait *waiters;
    u32 pad08[6];
    Big *busy;
    u32 pad24[16];
    Big *spare;
    Big *cur;
} FsRoot;

extern void DC_FlushRange(u32, u32);
extern int PXI_SendWordByFifo(u32, u32, u32);
extern u32 OS_GetProcMode(void);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enable);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern void SVC_WaitByLoop(u32);
extern void OS_SleepThread(u32 *);
extern u32 data_02150FEC[];
extern FsRoot data_027343E0;
extern u32 data_0273442C[];
extern Big *DAT_02734428;
extern u32 DAT_02734420[];

void FATFSi_SendToPXI(Big *command);
u32 FATFSi_GetThreadHandle(void);
Big *FATFSi_AllocateCommandBuffer(u32 arg);
Big *FATFSi_AllocateEmergencyCommandBuffer(u32 arg);
void FATFSi_FreeCommandBuffer(Big *command);
void FATFSi_PostRequest(Big *request);
void FATFSi_WaitForRequest(Big *request);

void FATFSi_SendToPXI(Big *command) {
    DC_FlushRange((u32)command, 0x800);
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
    return data_02150FEC[1];
}

Big *FATFSi_AllocateCommandBuffer(u32 arg) {
    Big *e = 0;
    u32 ime = OS_DisableInterrupts();
    u32 key = FATFSi_GetThreadHandle();
    Big *p;
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
        OS_LockMutex(data_0273442C);
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

Big *FATFSi_AllocateEmergencyCommandBuffer(u32 arg) {
    if (OS_GetProcMode() != 0x12) {
        return FATFSi_AllocateCommandBuffer(arg);
    } else {
        Big *e = data_027343E0.cur;
        e->arg = arg;
        e->state = 2;
        e->qnext = 0;
        e->mode = 0;
        return e;
    }
}

void FATFSi_FreeCommandBuffer(Big *command) {
    if (command == data_027343E0.spare) {
        OS_UnlockMutex(data_0273442C);
    }
}

void FATFSi_PostRequest(Big *request)
{
    FATFSi_SendToPXI(request);
}

void FATFSi_WaitForRequest(Big *request) {
    u32 busy = 1;
    while ((busy != 0) ? 1 : 0) {
        u32 ime = OS_DisableInterrupts();
        /* the list is shared: every access rereads it */
        Big * volatile *pp = &DAT_02734428;
        Big *p;
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
                OS_SleepThread(DAT_02734420);
            }
        }
        OS_RestoreInterrupts(ime);
    }
}
