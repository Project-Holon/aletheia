/*
 * file:     fs_proc_mem.c
 * unit:     yes
 * function: FS_GetFileImageTop, FSi_MemArchiveProc, FSi_InitMemArchive, FS_CreateFileFromMemory
 * address:  0x0207A7BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FS_GetArchiveName 0x02078530 arm
 *   STD_GetStringLength 0x0208CC78 arm
 *   STD_TSPrintf 0x0208D7E0 arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_InitArchive  0x02078360  arm
 *   FS_SetArchiveProc  0x0207A5A8  arm
 *   FS_LoadArchive  0x0207A4B0  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   fsi_mem_init  0x02150D40  data
 *   fsi_arc_mem  0x02150D44  data
 *   FSi_InitMemArchive  0x0207A890  arm
 *   FS_OpenFileDirect  0x02078964  arm
 *   @12205        0x020A84AC data
 */

#include "../types.h"

#include "../sdk_fs.h"

#include "fs_archive.h"
#include "std_string.h"
#include "std_sprintf.h"
#include "os_system.h"
#include "fs_proc_default.h"
#include "os_terminate_processor.h"
#include "fs_file.h"
u32 FS_GetFileImageTop(FSFile *file);
int FSi_MemArchiveProc(FSFile *p_file, u32 cmd);
void FSi_InitMemArchive(void);
BOOL FS_CreateFileFromMemory(FSFile *p_file, void *buf, u32 size);
extern BOOL fsi_mem_init;
extern FSArchive fsi_arc_mem;

u32 FS_GetFileImageTop(FSFile *file)
{
    return file->prop.file.top;
}

int FSi_MemArchiveProc(FSFile *p_file, u32 cmd)
{
    switch (cmd) {
    case 3: {
        FSDirEntry *entry;
        FSArchive *arc;
        char *name;
        arc = (FSArchive *)p_file->prop.dir.pos.pos;
        entry = p_file->arg.readdir.p_entry;
        if (arc == 0) {
            entry->name_len = 0;
            entry->is_directory = 0;
            return 1;
        }
        name = FS_GetArchiveName(arc);
        entry->name_len = STD_GetStringLength(name) + 1;
        entry->is_directory = 1;
        if (p_file->arg.readdir.skip_string == 0) {
            STD_TSPrintf(entry->name, "%s:", name);
            entry->dir_id.arc = p_file->arc;
            entry->dir_id.own_id = 0;
            entry->dir_id.index = 0;
            entry->dir_id.pos = 0;
        }
        p_file->prop.dir.pos.pos = (uptr)arc->next;
        return 0;
    }
    case 2:
    case 4:
    case 5:
    case 6:
        return 4;
    default:
        return 0x102;
    }
}

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}

/*
 * sdk:      FSi_InitMemArchive (libfs.TWL.HYB.a fs_proc_mem.o)
 */
void FSi_InitMemArchive(void)
{
    u32 bak_cpsr = OS_DisableInterrupts();

    if (!fsi_mem_init || !FS_IsArchiveLoaded(&fsi_arc_mem))
    {
        FS_InitArchive(&fsi_arc_mem);
        FS_SetArchiveProc(&fsi_arc_mem, (uptr)FSi_MemArchiveProc, 0xFFFFFFFF);
        if (!FS_LoadArchive(&fsi_arc_mem, 0, 0, 0, 0, 0, 0, 0))
        {
            OS_Terminate();
        }
        fsi_mem_init = 1;
    }
    (void)OS_RestoreInterrupts(bak_cpsr);
}

/*
 * sdk:      FS_CreateFileFromMemory (libfs.TWL.HYB.a fs_proc_mem.o)
 */
BOOL FS_CreateFileFromMemory(FSFile *p_file, void *buf, u32 size)
{
    FSi_InitMemArchive();
    return FS_OpenFileDirect(p_file, &fsi_arc_mem, (uptr)buf, (uptr)buf + size, 0);
}
