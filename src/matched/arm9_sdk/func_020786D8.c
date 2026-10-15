/*
 * function: FS_ResumeArchive
 * address:  0x020786D8
 * packet:   pkt_020786D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_ResumeArchive (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   FSi_NextCommand  0x02077AD8  arm
 *   FSi_ExecuteAsyncCommand  0x02077C78  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct FSFile FSFile;

typedef struct FSArchive
{
    u8 pad00[0x14];
    u32 flag;
} FSArchive;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);
extern void FSi_ExecuteAsyncCommand(FSFile *file);

static inline BOOL FS_IsArchiveSuspended(const FSArchive *arc)
{
    return (arc->flag & 8) ? 1 : 0;
}

BOOL FS_ResumeArchive(FSArchive *arc)
{
    BOOL retval;
    FSFile *file;
    u32 bak_irq = OS_DisableInterrupts();

    retval = (FS_IsArchiveSuspended(arc) == 0);
    if (!retval)
    {
        arc->flag &= ~8;
    }
    (void)OS_RestoreInterrupts(bak_irq);
    file = FSi_NextCommand(arc, 1);
    if (file)
    {
        FSi_ExecuteAsyncCommand(file);
    }
    return retval;
}
