/*
 * function: func_02077C78
 * address:  0x02077C78
 * packet:   pkt_02077C78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_ExecuteAsyncCommand (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_WakeupThread  0x02085800  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   FSi_InvokeCommand  0x02077758  arm
 *   FSi_NextCommand  0x02077AD8  arm
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
extern void OS_WakeupThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern int FSi_InvokeCommand(FSFile *file, u32 command);
extern FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);

void func_02077C78(FSFile *file)
{
    FSArchive *const arc = file->arc;

    while (file)
    {
        u32 bak_psr = OS_DisableInterrupts();

        file->stat |= 0x40;
        if ((file->stat & 4) != 0)
        {
            OS_WakeupThread(file->queue);
            file = 0;
        }
        (void)OS_RestoreInterrupts(bak_psr);
        if (!file)
        {
            break;
        }
        if (FSi_InvokeCommand(file, (file->stat >> 8) & 0xFF) == 0x100)
        {
            break;
        }
        file = FSi_NextCommand(arc, 1);
    }
}
