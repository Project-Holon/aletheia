/*
 * function: FS_SuspendArchive
 * address:  0x02078648
 * packet:   pkt_02078648
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_SuspendArchive (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive
{
    u8 pad00[0xC];
    OSThreadQueue queue[1];
    u32 flag;
} FSArchive;

extern u32 OS_DisableInterrupts(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);

static inline BOOL FS_IsArchiveSuspended(const FSArchive *arc)
{
    return (arc->flag & 8) ? 1 : 0;
}

BOOL FS_SuspendArchive(FSArchive *p_arc)
{
    BOOL retval;
    u32 bak_psr = OS_DisableInterrupts();

    retval = (FS_IsArchiveSuspended(p_arc) == 0);
    if (retval)
    {
        if ((p_arc->flag & 0x10) == 0)
        {
            p_arc->flag |= 8;
        }
        else
        {
            u32 bak_psr2;

            p_arc->flag |= 0x40;
            bak_psr2 = OS_DisableInterrupts();
            while ((p_arc->flag & 0x40) != 0)
            {
                OS_SleepThread(p_arc->queue);
            }
            (void)OS_RestoreInterrupts(bak_psr2);
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return retval;
}
