/*
 * function: FATFSi_AllocateCommandBuffer
 * address:  0x0270410C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   FATFSi_GetThreadHandle         0x027040EC  arm  twl
 *   data_027343E0         0x027343E0  data twl a4
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_0273442C         0x0273442C  data twl a4
 *   OS_LockMutex          0x02086028  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct FsWait {
    struct FsWait *next;
    u32 key;
    struct Big *slot;
} FsWait;

typedef struct Big {
    u32 arg;
    u32 state;
    u32 mode;
    u32 f0C;
    u8 buf[0x7F0];
    u32 key;
    u32 f804;
    u32 f808;
    struct Big *next;
} Big;

typedef struct FsRoot {
    u32 f00;
    FsWait *waiters;
    u32 f08[6];
    Big *busy;
    u32 f24[16];
    Big *spare;
    Big *cur;
} FsRoot;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enable);
extern void OS_LockMutex(void *mutex);
extern u32 FATFSi_GetThreadHandle(void);
extern FsRoot data_027343E0;
extern u32 data_0273442C[];

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
    e->f0C = 0;
    return e;
}
