/*
 * file:     dsp_pipe.c
 * unit:     yes
 * function: DSPi_FileIOProc, DSPi_NotifyFileIOUpdation, DSPi_PipeCallbackToConsole, DSPi_WaitForPipe, DSP_InitPipe, DSP_SetPipeCallback, DSP_LoadPipe, DSP_SyncPipe, DSP_FlushPipe, DSP_GetPipeReadableSize, DSP_ReadPipe, DSP_WritePipe, DSP_HookPipeNotification
 * address:  0x027067B4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libdsp.TWL.HYB.a dsp_pipe.o
 *
 * DSPi_FileIOProc was written from the bytes.
 *
 * symbols:
 *   DSP_SendDataCore  0x0270502C  arm
 *   DSP_RecvDataCore  0x0270505C  arm
 *   DSP_ClearSemaphoreCore  0x02705294  arm
 *   DSP_LoadData  0x0270633C  arm
 *   DSP_StoreData  0x02706694  arm
 *   FS_CloseFile  0x02078A80  arm  arm9
 *   FS_ReadFile  0x02078B70  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   FS_OpenFileEx  0x020789FC  arm  arm9
 *   FS_GetFileLength  0x02078A94  arm  arm9
 *   FS_GetFilePosition  0x02078AEC  arm  arm9
 *   FS_SeekFile  0x02078B44  arm  arm9
 *   FS_WriteFile  0x02078BC4  arm  arm9
 *   FS_CreateFileFromMemory  0x0207A940  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 *   data_02734528                0x02734528  data
 *   data_0273452C                0x0273452C  data
 *   data_02734534                0x02734534  data
 *   data_02734554                0x02734554  data
 *   data_02734574                0x02734574  data
 *   data_02734614                0x02734614  data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    void *arc;
    u32 stat;
    void *argument;
    int error;
    void *queue[2];
    u8 prop[16];
    u8 arg[24];
} FSFile;

static inline BOOL FS_IsFile(FSFile *f)
{
    return (f->stat & 0x10) ? 1 : 0;
}

/* Pipe control block of the DSP data RAM, 10 bytes. */
typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

typedef struct DspPipeInfo {
    DspRing ring[8][2];
} DspPipeInfo;

typedef void (*DspCb)(void *, int, int);

/* The first words of the object at 0x02734528. Its callback word at +0xC is
   the same address as data_02734534[0]; the original code names both. */
typedef struct DspIoState {
    DspPipeInfo *base;
    u32 pad4;
    u32 pad8;
    DspCb callback;
} DspIoState;

/* The file I/O task: thread, message queue and the eight open files. */
typedef struct DspFileTask {
    int started;
    u8 thread[0xC0];
    void *msgbuf[1];
    u8 queue[0x20];
    u32 pending;
    FSFile files[8];
    u8 stack[0x1000];
} DspFileTask;

extern DspFileTask data_02734614;
extern DspIoState data_02734528;
extern u32 data_0273452C;
extern DspCb data_02734534[8];
extern void *data_02734554[8];
extern DspRing data_02734574[8][2];
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern BOOL OS_IsRunOnTwl(void);
extern void OS_SleepThread(void *);
extern void OS_WakeupThread(void *);
extern void FS_InitFile(FSFile *file);
struct OSMessageQueue;
extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern void OS_CreateThread(void *, void (*)(void *), void *, void *, u32, u32);
extern void OS_WakeupThreadDirect(void *);
extern BOOL OS_SendMessage(struct OSMessageQueue *mq, void *msg, s32 flags);
extern BOOL OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, s32 flags);
extern BOOL FS_OpenFileEx(FSFile *file, const char *path, u32 mode);
extern s32 FS_CloseFile(FSFile *file);
extern u32 FS_GetFileLength(FSFile *file);
extern u32 FS_GetFilePosition(FSFile *file);
extern BOOL FS_SeekFile(FSFile *file, long offset, int origin);
extern s32 FS_ReadFile(FSFile *file, void *dst, s32 len);
extern s32 FS_WriteFile(FSFile *file, const void *src, s32 len);
extern BOOL FS_CreateFileFromMemory(FSFile *file, void *buf, u32 size);
extern void DSP_SendDataCore(u32, u32);
extern u16 DSP_GetSemaphoreCore(void);
extern u32 DSP_RecvDataIsReadyCore(u32 ch);
extern u16 DSP_RecvDataCore(u32 ch);
extern void DSP_ClearSemaphoreCore(u16 v);
extern void DSP_StoreData(u32, u8 *, u32);
extern void DSP_LoadData(u32, u8 *, u32);

void DSPi_FileIOProc(void *arg);
void DSPi_NotifyFileIOUpdation(u32 ch);
void DSPi_PipeCallbackToConsole(void *userdata, int port, int peer);
static void DSPi_WaitForPipe(DspRing *r);
void DSP_InitPipe(void);
void DSP_SetPipeCallback(int i, DspCb a, void *b);
DspRing *DSP_LoadPipe(DspRing *out, int ch, int dir);
DspRing *DSP_SyncPipe(DspRing *r);
void DSP_FlushPipe(DspRing *r);
u16 DSP_GetPipeReadableSize(DspRing *r);
void DSP_ReadPipe(DspRing *r, void *dst, u16 count);
void DSP_WritePipe(DspRing *r, void *src, u16 count);
void DSP_HookPipeNotification(u32 arg);

void DSPi_FileIOProc(void *arg)
{
    DspFileTask *p = arg;
    u8 path[0x108];
    u8 rbuf[0x100];
    u8 wbuf[0x100];
    DspRing in;
    DspRing out;
    u32 msg[1];
    u32 readA;
    u32 readB;
    u32 seekPos;
    u32 seekOut;
    u16 cmd;
    u16 openMode;
    u16 pathLen;
    u16 openRes;
    u16 memRes;
    u16 closeRes;
    u16 seekMode;
    u16 readLen;
    u16 readHalf;
    u16 writeLen;
    u32 state;
    u32 bits;
    int index;
    FSFile *file;

    for (;;) {
        state = OS_DisableInterrupts();
        for (;;) {
            bits = p->pending;
            bits = ~bits & (bits - 1);
            asm { clz bits, bits }
            index = 32 - bits;
            if (index < 8) {
                break;
            }
            OS_ReceiveMessage((struct OSMessageQueue *)p->queue, (void **)msg, 1);
        }
        p->pending &= ~(1 << index);
        OS_RestoreInterrupts(state);
        file = &p->files[index];
        DSP_LoadPipe(&in, index, 0);
        DSP_LoadPipe(&out, index, 1);

        while (DSP_GetPipeReadableSize(&in) >= 2) {
            DSP_ReadPipe(&in, &cmd, 2);
            switch (cmd) {
            case 0:
                DSP_ReadPipe(&in, &openMode, 2);
                DSP_ReadPipe(&in, &pathLen, 2);
                pathLen = pathLen * 2;
                DSP_ReadPipe(&in, path, pathLen);
                path[pathLen] = 0;
                FS_OpenFileEx(file, (const char *)path, openMode);
                openRes = FS_IsFile(file) ? 1 : 0;
                DSP_WritePipe(&out, &openRes, 2);
                break;
            case 5:
                DSP_ReadPipe(&in, &readA, 4);
                DSP_ReadPipe(&in, &readB, 4);
                readA = (readA >> 16) | (readA << 16);
                readB = ((readB >> 16) | (readB << 16)) << 1;
                FS_CreateFileFromMemory(file, (void *)readA, readB);
                memRes = FS_IsFile(file) ? 1 : 0;
                DSP_WritePipe(&out, &memRes, 2);
                break;
            case 1:
                FS_CloseFile(file);
                closeRes = 1;
                DSP_WritePipe(&out, &closeRes, 2);
                break;
            case 2:
                DSP_ReadPipe(&in, &seekPos, 4);
                DSP_ReadPipe(&in, &seekMode, 2);
                seekPos = (seekPos >> 16) | (seekPos << 16);
                FS_SeekFile(file, seekPos, seekMode);
                seekOut = FS_GetFilePosition(file);
                seekOut = (seekOut >> 16) | (seekOut << 16);
                DSP_WritePipe(&out, &seekOut, 4);
                break;
            case 3:
                DSP_ReadPipe(&in, &readLen, 2);
                readLen = readLen << 1;
                {
                    u32 rest = FS_GetFileLength(file) - FS_GetFilePosition(file);
                    u32 t = readLen;
                    if (t > rest) {
                        t = rest;
                    }
                    readLen = t;
                }
                readHalf = readLen >> 1;
                DSP_WritePipe(&out, &readHalf, 2);
                while (readLen != 0) {
                    u16 n = readLen > 0x100 ? 0x100 : readLen;
                    FS_ReadFile(file, rbuf, n);
                    DSP_WritePipe(&out, rbuf, n);
                    readLen = readLen - n;
                }
                break;
            case 4:
                DSP_ReadPipe(&in, &writeLen, 2);
                writeLen = writeLen << 1;
                while (writeLen != 0) {
                    u16 n = writeLen > 0x100 ? 0x100 : writeLen;
                    DSP_ReadPipe(&in, wbuf, n);
                    FS_WriteFile(file, wbuf, n);
                    writeLen = writeLen - n;
                }
                break;
            }
        }
    }
}

void DSPi_NotifyFileIOUpdation(u32 ch)
{
    DspFileTask *t = &data_02734614;
    u32 ints;
    int i;

    ints = OS_DisableInterrupts();
    if (t->started == 0) {
        for (i = 0; i < 8; i++) {
            FS_InitFile(&t->files[i]);
        }
        OS_InitMessageQueue((struct OSMessageQueue *)t->queue, t->msgbuf, 1);
        t->pending = 0;
        t->started = 1;
        OS_CreateThread(t->thread, DSPi_FileIOProc, t, t->stack + 0x1000, 0x1000, 13);
        OS_WakeupThreadDirect(t->thread);
    }
    t->pending |= 1 << ch;
    OS_SendMessage((struct OSMessageQueue *)t->queue, (void *)ch, 0);
    OS_RestoreInterrupts(ints);
}

void DSPi_PipeCallbackToConsole(void *userdata, int port, int peer)
{
    DspRing ring;
    u8 buf[0x80];
    u16 done;
    u16 n;
    int left;
    u32 total;

    if (peer != 0) {
        return;
    }
    DSP_LoadPipe(&ring, port, peer);
    total = DSP_GetPipeReadableSize(&ring);
    done = 0;
    if (total == 0) {
        return;
    }
    while (done < total) {
        left = total - done;
        if (left >= 0x80) {
            left = 0x80;
        }
        n = left;
        DSP_ReadPipe(&ring, buf, n);
        done = done + n;
    }
}

static void DSPi_WaitForPipe(DspRing *pipe)
{
    OS_SleepThread(&data_0273452C);
    DSP_SyncPipe(pipe);
}

void DSP_InitPipe(void)
{
    int i;

    data_02734528.base = 0;
    data_02734528.pad8 = 0;
    data_02734528.pad4 = 0;
    for (i = 0; i < 8; i++) {
        data_02734534[i] = 0;
        data_02734554[i] = 0;
    }
    data_02734528.callback = DSPi_PipeCallbackToConsole;
}

void DSP_SetPipeCallback(int index, DspCb callback, void *userdata)
{
    data_02734534[index] = callback;
    data_02734554[index] = userdata;
}

DspRing *DSP_LoadPipe(DspRing *out, int ch, int dir)
{
    u32 ints = OS_DisableInterrupts();
    while (data_02734528.base == 0) {
        OS_SleepThread(&data_0273452C);
    }
    OS_RestoreInterrupts(ints);
    if (ch >= 0 && ch < 8 && dir >= 0 && dir < 2) {
        u32 addr = (u32)&data_02734528.base->ring[ch][dir];
        if (out == 0) {
            out = &data_02734574[ch][dir];
        }
        DSP_LoadData(addr, (u8 *)out, sizeof(DspRing));
    }
    return out;
}

DspRing *DSP_SyncPipe(DspRing *pipe)
{
    return DSP_LoadPipe(pipe, (pipe->id & 0xFF) >> 1, pipe->id & 1);
}

void DSP_FlushPipe(DspRing *pipe)
{
    int id = pipe->id;
    u32 addr = (u32)data_02734528.base + ((id & 0xFF) >> 1) * 0x14;
    u32 dir = id & 1;
    u32 n;

    addr += dir * 0xA;
    if (dir == 0) {
        DSP_StoreData(addr + 4, (u8 *)&pipe->rd, 2);
    } else {
        DSP_StoreData(addr + 6, (u8 *)&pipe->wr, 2);
    }
    n = pipe->id & 0xFF;
    if (OS_IsRunOnTwl() == 1) {
        DSP_SendDataCore(2, n);
    }
}

u16 DSP_GetPipeReadableSize(DspRing *pipe)
{
    int t = pipe->rd ^ pipe->wr;
    int d;

    if (t < 0x8000) {
        t = 0;
    } else {
        t = pipe->size;
    }
    d = pipe->wr - pipe->rd;
    return (d + t) & ~0x8000;
}

void DSP_ReadPipe(DspRing *pipe, void *dst, u16 count)
{
    u8 *buf = dst;
    u32 ints;
    int dirty;
    int rd;
    int wr;
    u32 diff;
    u16 rdIdx;
    int limit;
    u16 chunk;
    int n;
    int next;

    ints = OS_DisableInterrupts();
    dirty = 0;
    DSP_SyncPipe(pipe);
    if (count != 0) {
        do {
            wr = pipe->wr;
            rd = pipe->rd;
            diff = (u16)(rd ^ wr);
            if (diff == 0) {
                if (dirty != 0) {
                    DSP_FlushPipe(pipe);
                    dirty = 0;
                }
                DSPi_WaitForPipe(pipe);
            } else {
                rdIdx = rd & ~0x8000;
                if (diff < 0x8000) {
                    limit = wr & ~0x8000;
                } else {
                    limit = pipe->size;
                }
                n = (u16)limit - rdIdx;
                if (count < n) {
                    n = count;
                }
                n = (u16)n;
                chunk = n;
                DSP_LoadData(pipe->base * 2 + rdIdx, buf, chunk);
                count = count - chunk;
                buf += chunk;
                next = chunk + rdIdx;
                if (next < pipe->size) {
                    next = rd + chunk;
                } else {
                    next = ~rd & 0x8000;
                }
                dirty = 1;
                pipe->rd = next;
            }
        } while (count != 0);
    }
    if (dirty != 0) {
        DSP_FlushPipe(pipe);
    }
    OS_RestoreInterrupts(ints);
}

void DSP_WritePipe(DspRing *pipe, void *src, u16 count)
{
    u8 *buf = src;
    u32 ints;
    int dirty;
    int rd;
    int wr;
    u32 diff;
    u16 wrIdx;
    int limit;
    u16 chunk;
    int n;
    int next;

    ints = OS_DisableInterrupts();
    dirty = 0;
    DSP_SyncPipe(pipe);
    if (count != 0) {
        do {
            wr = pipe->wr;
            rd = pipe->rd;
            diff = (u16)(rd ^ wr);
            if (diff == 0x8000) {
                if (dirty != 0) {
                    DSP_FlushPipe(pipe);
                    dirty = 0;
                }
                DSPi_WaitForPipe(pipe);
            } else {
                wrIdx = wr & ~0x8000;
                if (diff < 0x8000) {
                    limit = pipe->size;
                } else {
                    limit = rd & ~0x8000;
                }
                n = (u16)limit - wrIdx;
                if (count < n) {
                    n = count;
                }
                n = (u16)n;
                chunk = n;
                DSP_StoreData(pipe->base * 2 + wrIdx, buf, chunk);
                count = count - chunk;
                buf += chunk;
                next = chunk + wrIdx;
                if (next < pipe->size) {
                    next = wr + chunk;
                } else {
                    next = ~wr & 0x8000;
                }
                dirty = 1;
                pipe->wr = next;
            }
        } while (count != 0);
    }
    if (dirty != 0) {
        DSP_FlushPipe(pipe);
    }
    OS_RestoreInterrupts(ints);
}

void DSP_HookPipeNotification(u32 arg)
{
    DspRing req;
    int ch;
    int flag;
    int v;
    while ((OS_IsRunOnTwl() == 1 ? DSP_GetSemaphoreCore() : 0) & 0x8000
           || (OS_IsRunOnTwl() == 1 ? DSP_RecvDataIsReadyCore(2) : 0)) {
        if (OS_IsRunOnTwl() == 1) {
            DSP_ClearSemaphoreCore(0x8000);
        }
        while (OS_IsRunOnTwl() == 1 ? DSP_RecvDataIsReadyCore(2) : 0) {
            if (data_02734528.base == 0) {
                data_02734528.base = (DspPipeInfo *)((OS_IsRunOnTwl() == 1 ? DSP_RecvDataCore(2) : 0) << 1);
            } else {
                v = OS_IsRunOnTwl() == 1 ? DSP_RecvDataCore(2) : 0;
                ch = v >> 1;
                flag = v & 1;
                if (ch >= 0 && ch < 8) {
                    if (data_02734534[ch] != 0) {
                        data_02734534[ch](data_02734554[ch], ch, flag);
                    } else {
                        DSP_LoadPipe(&req, ch, flag);
                        if (flag == 0 && (req.id & 0x100)) {
                            DSPi_NotifyFileIOUpdation(ch);
                        }
                    }
                }
            }
            OS_WakeupThread(&data_0273452C);
        }
    }
}
