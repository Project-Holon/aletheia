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

typedef unsigned char u8;

typedef unsigned long u32;

typedef int BOOL;

typedef struct FSFile FSFile;

typedef struct FSArchive
{
    u8 pad00[4];
    struct FSArchive *next;
    u8 pad08[0xc];
    u32 flag;
} FSArchive;

typedef struct FSDirEntryOut
{
    u32 id;
    unsigned short attr;
    unsigned short reserved;
    u32 size;
    u32 is_directory;
    u32 name_len;
    char name[1];
} FSDirEntryOut;

struct FSFile
{
    u8 pad00[8];
    u32 id;
    u8 pad0c[0x18];
    u32 imageTop;
    FSArchive *cur_arc;
    u8 pad2c[4];
    FSDirEntryOut *entry;
    u32 skip_string;
};

extern char *FS_GetArchiveName(FSArchive *arc);
extern int STD_GetStringLength(const char *s);
extern int STD_TSPrintf(char *dst, char *fmt, ...);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void FS_InitArchive(FSArchive *p_arc);
extern void FS_SetArchiveProc(FSArchive *arc, int (*proc)(FSFile *, u32), u32 flags);
extern BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                           int (*read_func)(FSArchive *, void *, u32, u32),
                           int (*write_func)(FSArchive *, void *, u32, u32));
extern void OS_Terminate(void);
extern BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
u32 FS_GetFileImageTop(FSFile *file);
int FSi_MemArchiveProc(FSFile *p_file, u32 cmd);
void FSi_InitMemArchive(void);
BOOL FS_CreateFileFromMemory(FSFile *p_file, void *buf, u32 size);
extern BOOL fsi_mem_init;
extern FSArchive fsi_arc_mem;


u32 FS_GetFileImageTop(FSFile *file)
{
    return file->imageTop;
}


int FSi_MemArchiveProc(FSFile *p_file, u32 cmd)
{
    switch (cmd) {
    case 3: {
        FSDirEntryOut *entry;
        FSArchive *arc;
        char *name;
        arc = p_file->cur_arc;
        entry = p_file->entry;
        if (arc == 0) {
            entry->name_len = 0;
            entry->is_directory = 0;
            return 1;
        }
        name = FS_GetArchiveName(arc);
        entry->name_len = STD_GetStringLength(name) + 1;
        entry->is_directory = 1;
        if (p_file->skip_string == 0) {
            STD_TSPrintf(entry->name, "%s:", name);
            entry->id = p_file->id;
            entry->attr = 0;
            entry->reserved = 0;
            entry->size = 0;
        }
        p_file->cur_arc = arc->next;
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
        FS_SetArchiveProc(&fsi_arc_mem, FSi_MemArchiveProc, 0xFFFFFFFF);
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
    return FS_OpenFileDirect(p_file, &fsi_arc_mem, (u32)buf, (u32)buf + size, 0);
}
