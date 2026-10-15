/*
 * function: FS_NotifyArchiveAsyncEnd
 * address:  0x02078734
 * packet:   pkt_02078734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_NotifyArchiveAsyncEnd (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_WakeupThread  0x02085800  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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


struct FSArchive
{
    u8 pad00[8];
    FSFile *list;
};

extern u32 OS_DisableInterrupts(void);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern void FSi_EndCommand(FSFile *file, int ret);
extern FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);
extern void FSi_ExecuteAsyncCommand(FSFile *file);

void FS_NotifyArchiveAsyncEnd(FSArchive *arc, int ret)
{
    FSFile *file = arc->list;

    if ((file->stat & 4) != 0)
    {
        u32 bak_psr = OS_DisableInterrupts();

        file->stat |= 8;
        file->error = ret;
        OS_WakeupThread(file->queue);
        (void)OS_RestoreInterrupts(bak_psr);
    }
    else
    {
        FSi_EndCommand(file, ret);
        file = FSi_NextCommand(arc, 1);
        if (file)
        {
            FSi_ExecuteAsyncCommand(file);
        }
    }
}
