/*
 * function: DSPi_NotifyFileIOUpdation
 * address:  0x02706B60
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02734614  0x02734614  data twl a2
 *   DSPi_FileIOProc  0x027067B4  arm twl a2
 *   FS_InitFile  0x020788AC  arm
 *   OS_InitMessageQueue  0x02085D94  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_SendMessage  0x02085DBC  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef struct DspFileTask {
    int started;
    u8 thread[0xC0];
    void *msgbuf[1];
    u8 queue[0x20];
    u32 pending;
    u8 files[8][0x48];
    u8 stack[0x1000];
} DspFileTask;

extern DspFileTask data_02734614;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern void FS_InitFile(void *);
extern void OS_InitMessageQueue(void *, void **, int);
extern void OS_CreateThread(void *, void (*)(void *), void *, void *, u32, u32);
extern void OS_WakeupThreadDirect(void *);
extern BOOL OS_SendMessage(void *, void *, int);
extern void DSPi_FileIOProc(void *);

void DSPi_NotifyFileIOUpdation(u32 ch)
{
    DspFileTask *t = &data_02734614;
    u32 ints;
    int i;

    ints = OS_DisableInterrupts();
    if (t->started == 0) {
        for (i = 0; i < 8; i++) {
            FS_InitFile(t->files[i]);
        }
        OS_InitMessageQueue(t->queue, t->msgbuf, 1);
        t->pending = 0;
        t->started = 1;
        OS_CreateThread(t->thread, DSPi_FileIOProc, t, t->stack + 0x1000, 0x1000, 13);
        OS_WakeupThreadDirect(t->thread);
    }
    t->pending |= 1 << ch;
    OS_SendMessage(t->queue, (void *)ch, 0);
    OS_RestoreInterrupts(ints);
}
