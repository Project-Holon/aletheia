/*
 * function: func_02078588
 * address:  0x02078588
 * packet:   pkt_02078588
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_UnmountArchive (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_SuspendArchive  0x02078648  arm
 *   FSi_EndCommand  0x0207765C  arm
 *   FS_ResumeArchive  0x020786D8  arm
 *   FS_InitFile  0x020788AC  arm
 *   FSi_InvokeCommand  0x02077758  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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
    u8 pad0C[8];
    u32 flag;
};

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern BOOL FS_SuspendArchive(FSArchive *p_arc);
extern BOOL FS_ResumeArchive(FSArchive *arc);
extern void FSi_EndCommand(FSFile *file, int ret);
extern void FS_InitFile(FSFile *file);
extern int FSi_InvokeCommand(FSFile *file, u32 command);

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}

BOOL func_02078588(FSArchive *arc)
{
    u32 bak_psr = OS_DisableInterrupts();

    if (FS_IsArchiveLoaded(arc))
    {
        BOOL bak_state = FS_SuspendArchive(arc);

        arc->flag |= 0x80;
        {
            FSFile *file = arc->list;

            while (file)
            {
                FSFile *next = file->next;

                FSi_EndCommand(file, 3);
                file = next;
            }
        }
        arc->list = 0;
        if (bak_state)
        {
            (void)FS_ResumeArchive(arc);
        }
        {
            FSFile tmp[1];

            FS_InitFile(tmp);
            tmp->arc = arc;
            (void)FSi_InvokeCommand(tmp, 18);
        }
        arc->flag &= ~(0x80 | 0x20 | 0x02);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return 1;
}
