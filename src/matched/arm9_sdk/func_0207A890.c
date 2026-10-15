/*
 * function: FSi_InitMemArchive
 * address:  0x0207A890
 * packet:   pkt_0207A890
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_InitMemArchive (libfs.TWL.HYB.a fs_proc_mem.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_InitArchive  0x02078360  arm
 *   FS_SetArchiveProc  0x0207A5A8  arm
 *   FS_LoadArchive  0x0207A4B0  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   fsi_mem_init  0x02150D40  data
 *   fsi_arc_mem  0x02150D44  data
 *   FSi_MemArchiveProc  0x0207A7C4  arm
 */

#include "../include/G_FSArchive.h"

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct FSFile FSFile;

typedef struct FSArchive FSArchive;

extern BOOL fsi_mem_init;
extern struct FSArchive fsi_arc_mem;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void FS_InitArchive(FSArchive *p_arc);
extern void FS_SetArchiveProc(FSArchive *arc, int (*proc)(FSFile *, u32), u32 flags);
extern BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                           int (*read_func)(FSArchive *, void *, u32, u32),
                           int (*write_func)(FSArchive *, void *, u32, u32));
extern void OS_Terminate(void);
extern int FSi_MemArchiveProc(FSFile *p_file, u32 cmd);

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}

void FSi_InitMemArchive(void)
{
    u32 bak_cpsr = OS_DisableInterrupts();

    if (!fsi_mem_init || !FS_IsArchiveLoaded(&fsi_arc_mem))
    {
        FS_InitArchive(&fsi_arc_mem);
        FS_SetArchiveProc(&fsi_arc_mem, FSi_MemArchiveProc, 0xFFFFFFFF);
        if (!FS_LoadArchive(&fsi_arc_mem, 0, 0, 0, 0, 0, 0, 0))
        {
            OS_Terminate();
        }
        fsi_mem_init = 1;
    }
    (void)OS_RestoreInterrupts(bak_cpsr);
}
