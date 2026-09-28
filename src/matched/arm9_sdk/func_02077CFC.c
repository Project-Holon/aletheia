/*
 * function: func_02077CFC
 * address:  0x02077CFC
 * packet:   pkt_02077CFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_ExecuteSyncCommand (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   FSi_InvokeCommand  0x02077758  arm
 *   FSi_EndCommand  0x0207765C  arm
 *   FSi_NextCommand  0x02077AD8  arm
 *   FSi_ExecuteAsyncCommand  0x02077C78  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive FSArchive;

typedef struct FSFile
{
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32 stat;
    void *argument;
    int error;
    OSThreadQueue queue[1];
    u8 prop[16];
    u8 arg[24];
} FSFile;


extern u32 OS_DisableInterrupts(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern int FSi_InvokeCommand(FSFile *file, u32 command);
extern void FSi_EndCommand(FSFile *file, int ret);
extern FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);
extern void FSi_ExecuteAsyncCommand(FSFile *file);

static inline u32 FSi_GetCurrentCommand(const FSFile *file)
{
    return (file->stat >> 8) & 0xFF;
}

void func_02077CFC(FSFile *file)
{
    u32 bak_psr = OS_DisableInterrupts();

    while (((file->stat & 0x40) == 0) && ((file->stat & 1) != 0))
    {
        OS_SleepThread(file->queue);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    if ((file->stat & 0x40) != 0)
    {
        FSArchive *const arc = file->arc;
        int result = FSi_InvokeCommand(file, FSi_GetCurrentCommand(file));

        FSi_EndCommand(file, result);
        file = FSi_NextCommand(arc, 1);
        if (file)
        {
            FSi_ExecuteAsyncCommand(file);
        }
    }
}
