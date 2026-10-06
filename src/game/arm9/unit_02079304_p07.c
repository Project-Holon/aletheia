/*
 * file:     unit_02079304_p07.c
 * unit:     yes
 * function: func_0207A528, func_0207A568, func_0207A5A8, func_0207A5C8, func_0207A708, func_0207A78C, func_0207A798, func_0207A7A8
 * address:  0x0207A528
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
 *   FSiArchiveProcInterface      0x020A1A38  data
 *   FSi_ROMFAT_GetFileLength     0x0207A1FC  arm
 *   FSi_ROMFAT_GetFilePosition   0x0207A218  arm
 *   FS_InitFile                  0x020788AC  arm
 *   FS_OpenFileDirect            0x02078964  arm
 *   FS_ReadFile                  0x02078B70  arm
 *   MI_CpuFill8                  0x02082BCC  arm
 *   FS_CloseFile                 0x02078A80  arm
 *   FS_SuspendArchive            0x02078648  arm
 *   FS_ResumeArchive             0x020786D8  arm
 */
struct FSArchive_02079304;
struct FSFile_02079304;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef long s32;

typedef unsigned long long u64;

typedef int BOOL;

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef int FSResult;

typedef FSResult (*FS_ARCHIVE_READ_FUNC_02079304)(struct FSArchive_02079304 *p, void *dst, u32 pos, u32 size);

typedef FSResult (*FS_ARCHIVE_WRITE_FUNC_02079304)(struct FSArchive_02079304 *p, const void *src, u32 pos, u32 size);

typedef FSResult (*FS_ARCHIVE_PROC_FUNC_02079304)(struct FSFile_02079304 *file, u32 command);

typedef struct FSROMFATArchiveContext_02079304 {
    u32 base;
    u32 fat;
    u32 fat_size;
    u32 fnt;
    u32 fnt_size;
    u32 fat_bak;
    u32 fnt_bak;
    void *load_mem;
    FS_ARCHIVE_READ_FUNC_02079304 read_func;
    FS_ARCHIVE_WRITE_FUNC_02079304 write_func;
    u8 reserved3[4];
    FS_ARCHIVE_PROC_FUNC_02079304 proc;
    u32 proc_flag;
} FSROMFATArchiveContext_02079304;

typedef struct FSArchive_02079304 {
    u32 name;
    struct FSArchive_02079304 *next;
    struct FSFile_02079304 *list;
    OSThreadQueue queue;
    u32 flag;
    u32 command;
    FSResult result;
    void *userdata;
    const void *vtbl;
    FSROMFATArchiveContext_02079304 context;
} FSArchive_02079304;

typedef struct FSFileID_02079304 {
    FSArchive_02079304 *arc;
    u32 file_id;
} FSFileID_02079304;

typedef struct FSDirPos_02079304 {
    FSArchive_02079304 *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos_02079304;

typedef struct FSDirEntry_02079304 {
    union {
        FSFileID_02079304 file_id;
        FSDirPos_02079304 dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
} FSDirEntry_02079304;

typedef struct FSArchiveFAT_02079304 {
    u32 top;
    u32 bottom;
} FSArchiveFAT_02079304;

typedef struct FSArchiveFNT_02079304 {
    u32 start;
    u16 index;
    u16 parent;
} FSArchiveFNT_02079304;

typedef struct FSROMFATFileProperty_02079304 {
    u32 own_id;
    u32 top;
    u32 bottom;
    u32 pos;
} FSROMFATFileProperty_02079304;

typedef struct FSROMFATDirProperty_02079304 {
    FSDirPos_02079304 pos;
    u32 parent;
} FSROMFATDirProperty_02079304;

typedef union FSROMFATProperty {
    FSROMFATFileProperty_02079304 file;
    FSROMFATDirProperty_02079304 dir;
} FSROMFATProperty;

typedef struct FSReadFileInfo_02079304 { void *dst; u32 len_org; u32 len; } FSReadFileInfo_02079304;

typedef struct FSWriteFileInfo_02079304 { const void *src; u32 len_org; u32 len; } FSWriteFileInfo_02079304;

typedef struct FSSeekDirInfo { FSDirPos_02079304 pos; } FSSeekDirInfo;

typedef struct FSReadDirInfo { FSDirEntry_02079304 *p_entry; BOOL skip_string; } FSReadDirInfo;

typedef struct FSFindPathInfo { FSDirPos_02079304 pos; const char *path; BOOL find_directory; union { FSFileID_02079304 *file; FSDirPos_02079304 *dir; } result; } FSFindPathInfo;

typedef struct FSGetPathInfo_02079304 { u8 *buf; u32 buf_len; u16 total_len; u16 dir_id; } FSGetPathInfo_02079304;

typedef struct FSOpenFileFastInfo { FSFileID_02079304 id; } FSOpenFileFastInfo;

typedef struct FSOpenFileDirectInfo_02079304 { u32 top; u32 bottom; u32 index; } FSOpenFileDirectInfo_02079304;

typedef struct FSCloseFileInfo_02079304 { u32 reserved; } FSCloseFileInfo_02079304;

typedef union FSROMFATCommandInfo {
    FSReadFileInfo_02079304 readfile;
    FSWriteFileInfo_02079304 writefile;
    FSSeekDirInfo seekdir;
    FSReadDirInfo readdir;
    FSFindPathInfo findpath;
    FSGetPathInfo_02079304 getpath;
    FSOpenFileFastInfo openfilefast;
    FSOpenFileDirectInfo_02079304 openfiledirect;
    FSCloseFileInfo_02079304 closefile;
    u8 reserved2[24];
} FSROMFATCommandInfo;

typedef struct FSFile_02079304 {
    struct FSFile_02079304 *next;
    void *userdata;
    FSArchive_02079304 *arc;
    u32 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    FSROMFATProperty prop;
    FSROMFATCommandInfo arg;
} FSFile_02079304;

typedef struct FSiSyncReadParam_02079304 {
    FSArchive_02079304 *arc;
    u32 pos;
} FSiSyncReadParam_02079304;

typedef struct FSArchiveInterface FSArchiveInterface;

typedef unsigned int u32_0;

typedef unsigned long u32_1;

typedef unsigned long u32_2;

typedef unsigned int u32_3;

typedef unsigned int u32_4;

typedef unsigned int u32_5;

extern FSResult FSi_ROMFAT_GetFileLength(FSArchive_02079304 *arc, FSFile_02079304 *file, u32 *length);
extern FSResult FSi_ROMFAT_GetFilePosition(FSArchive_02079304 *arc, FSFile_02079304 *file, u32 *position);
extern void FS_InitFile(FSFile_02079304 *file);
extern BOOL FS_OpenFileDirect(FSFile_02079304 *file, FSArchive_02079304 *arc, u32_1 image_top, u32_1 image_bottom, u32_1 id);
extern s32 FS_ReadFile(FSFile_02079304 *file, void *buffer, s32 length);
extern void MI_CpuFill8(void *dstp, u8 data, u32_1 size);
extern BOOL FS_CloseFile(FSFile_02079304 *file);
extern BOOL FS_SuspendArchive(FSArchive_02079304 *arc);
extern BOOL FS_ResumeArchive(FSArchive_02079304 *arc);
BOOL FSi_GetFileLengthIfProc(FSFile_02079304 *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile_02079304 *file, u32 *position);
void FS_SetArchiveProc(void *arc, u32_0 proc, u32_0 flags);
u32_1 FS_LoadArchiveTables(FSArchive_02079304 *p_arc, void *p_mem, u32_1 max_size);
void *FS_UnloadArchiveTables(FSArchive_02079304 *arc);
void *FS_GetArchiveBase(void *arc);
u32_4 FS_GetArchiveOffset(void *arc, u32_4 pos);
int FS_IsArchiveTableLoaded(void *arc);
extern const FSArchiveInterface FSiArchiveProcInterface;


#define FS_RESULT_SUCCESS            0


#define FS_RESULT_FAILURE            1


#define FS_RESULT_BUSY               2


#define FS_RESULT_CANCELED           3


#define FS_RESULT_UNSUPPORTED        4


#define FS_RESULT_ERROR              5


#define FS_RESULT_INVALID_PARAMETER  6


#define FS_RESULT_NO_MORE_RESOURCE   7


#define FS_RESULT_ALREADY_DONE       8


#define FS_RESULT_PERMISSION_DENIED  9


#define FS_RESULT_MEDIA_FATAL        10


#define FS_RESULT_NO_ENTRY           11


#define FS_RESULT_PROC_ASYNC         256


#define FS_RESULT_PROC_DEFAULT       257


#define FS_RESULT_PROC_UNKNOWN       258



#define FS_COMMAND_READFILE        0


#define FS_COMMAND_WRITEFILE       1


#define FS_COMMAND_SEEKDIR         2


#define FS_COMMAND_READDIR         3


#define FS_COMMAND_FINDPATH        4


#define FS_COMMAND_GETPATH         5


#define FS_COMMAND_OPENFILEFAST    6


#define FS_COMMAND_OPENFILEDIRECT  7


#define FS_COMMAND_CLOSEFILE       8


#define FS_COMMAND_ACTIVATE        9


#define FS_COMMAND_IDLE            10


#define FS_COMMAND_SUSPEND         11


#define FS_COMMAND_RESUME          12


#define FS_COMMAND_OPENFILE        13


#define FS_COMMAND_SEEKFILE        14


#define FS_COMMAND_GETFILELENGTH   15


#define FS_COMMAND_GETFILEPOSITION 16


#define FS_COMMAND_MOUNT           17


#define FS_COMMAND_UNMOUNT         18



BOOL FSi_GetFileLengthIfProc(FSFile_02079304 *file, u32 *length)
{
    return (file->arc->vtbl == &FSiArchiveProcInterface) &&
           (FSi_ROMFAT_GetFileLength(file->arc, file, length) == FS_RESULT_SUCCESS);
}


#define FS_RESULT_SUCCESS            0


#define FS_RESULT_FAILURE            1


#define FS_RESULT_BUSY               2


#define FS_RESULT_CANCELED           3


#define FS_RESULT_UNSUPPORTED        4


#define FS_RESULT_ERROR              5


#define FS_RESULT_INVALID_PARAMETER  6


#define FS_RESULT_NO_MORE_RESOURCE   7


#define FS_RESULT_ALREADY_DONE       8


#define FS_RESULT_PERMISSION_DENIED  9


#define FS_RESULT_MEDIA_FATAL        10


#define FS_RESULT_NO_ENTRY           11


#define FS_RESULT_PROC_ASYNC         256


#define FS_RESULT_PROC_DEFAULT       257


#define FS_RESULT_PROC_UNKNOWN       258



#define FS_COMMAND_READFILE        0


#define FS_COMMAND_WRITEFILE       1


#define FS_COMMAND_SEEKDIR         2


#define FS_COMMAND_READDIR         3


#define FS_COMMAND_FINDPATH        4


#define FS_COMMAND_GETPATH         5


#define FS_COMMAND_OPENFILEFAST    6


#define FS_COMMAND_OPENFILEDIRECT  7


#define FS_COMMAND_CLOSEFILE       8


#define FS_COMMAND_ACTIVATE        9


#define FS_COMMAND_IDLE            10


#define FS_COMMAND_SUSPEND         11


#define FS_COMMAND_RESUME          12


#define FS_COMMAND_OPENFILE        13


#define FS_COMMAND_SEEKFILE        14


#define FS_COMMAND_GETFILELENGTH   15


#define FS_COMMAND_GETFILEPOSITION 16


#define FS_COMMAND_MOUNT           17


#define FS_COMMAND_UNMOUNT         18



BOOL FSi_GetFilePositionIfProc(FSFile_02079304 *file, u32 *position)
{
    return (file->arc->vtbl == &FSiArchiveProcInterface) &&
           (FSi_ROMFAT_GetFilePosition(file->arc, file, position) == FS_RESULT_SUCCESS);
}



void FS_SetArchiveProc(void *arc, u32_0 proc, u32_0 flags)
{
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    *(u32_0 *)((char *)arc + 0x54) = proc;
    *(u32_0 *)((char *)arc + 0x58) = flags;
}


#define FS_RESULT_SUCCESS            0


#define FS_RESULT_FAILURE            1


#define FS_RESULT_BUSY               2


#define FS_RESULT_CANCELED           3


#define FS_RESULT_UNSUPPORTED        4


#define FS_RESULT_ERROR              5


#define FS_RESULT_INVALID_PARAMETER  6


#define FS_RESULT_NO_MORE_RESOURCE   7


#define FS_RESULT_ALREADY_DONE       8


#define FS_RESULT_PERMISSION_DENIED  9


#define FS_RESULT_MEDIA_FATAL        10


#define FS_RESULT_NO_ENTRY           11


#define FS_RESULT_PROC_ASYNC         256


#define FS_RESULT_PROC_DEFAULT       257


#define FS_RESULT_PROC_UNKNOWN       258



#define FS_COMMAND_READFILE        0


#define FS_COMMAND_WRITEFILE       1


#define FS_COMMAND_SEEKDIR         2


#define FS_COMMAND_READDIR         3


#define FS_COMMAND_FINDPATH        4


#define FS_COMMAND_GETPATH         5


#define FS_COMMAND_OPENFILEFAST    6


#define FS_COMMAND_OPENFILEDIRECT  7


#define FS_COMMAND_CLOSEFILE       8


#define FS_COMMAND_ACTIVATE        9


#define FS_COMMAND_IDLE            10


#define FS_COMMAND_SUSPEND         11


#define FS_COMMAND_RESUME          12


#define FS_COMMAND_OPENFILE        13


#define FS_COMMAND_SEEKFILE        14


#define FS_COMMAND_GETFILELENGTH   15


#define FS_COMMAND_GETFILEPOSITION 16


#define FS_COMMAND_MOUNT           17


#define FS_COMMAND_UNMOUNT         18



#define FS_ARCHIVE_FLAG_TABLE_LOAD 0x00000004



u32_1 FS_LoadArchiveTables(FSArchive_02079304 *p_arc, void *p_mem, u32_1 max_size)
{
    FSROMFATArchiveContext_02079304 *context;
    u32_1 total_size;
    u8 *p_cache;
    FSFile_02079304 tmp;

    if ((p_mem != 0) && FS_IsArchiveTableLoaded(p_arc)) {
        (void)FS_UnloadArchiveTables(p_arc);
    }
    context = (FSROMFATArchiveContext_02079304 *)p_arc->userdata;
    total_size = (u32_1)((context->fat_size + context->fnt_size + 32 + 31) & ~31);
    if (total_size <= max_size) {
        p_cache = (u8 *)(((u32_1)p_mem + 31) & ~31);
        FS_InitFile(&tmp);
        if (FS_OpenFileDirect(&tmp, p_arc, context->fat, context->fat + context->fat_size, (u32_1)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (s32)context->fat_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fat_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fat = (u32_1)p_cache;
        p_cache += context->fat_size;
        if (FS_OpenFileDirect(&tmp, p_arc, context->fnt, context->fnt + context->fnt_size, (u32_1)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (s32)context->fnt_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fnt_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fnt = (u32_1)p_cache;
        context->load_mem = p_mem;
        p_arc->flag |= FS_ARCHIVE_FLAG_TABLE_LOAD;
    }
    return total_size;
}


#define FS_RESULT_SUCCESS            0


#define FS_RESULT_FAILURE            1


#define FS_RESULT_BUSY               2


#define FS_RESULT_CANCELED           3


#define FS_RESULT_UNSUPPORTED        4


#define FS_RESULT_ERROR              5


#define FS_RESULT_INVALID_PARAMETER  6


#define FS_RESULT_NO_MORE_RESOURCE   7


#define FS_RESULT_ALREADY_DONE       8


#define FS_RESULT_PERMISSION_DENIED  9


#define FS_RESULT_MEDIA_FATAL        10


#define FS_RESULT_NO_ENTRY           11


#define FS_RESULT_PROC_ASYNC         256


#define FS_RESULT_PROC_DEFAULT       257


#define FS_RESULT_PROC_UNKNOWN       258



#define FS_COMMAND_READFILE        0


#define FS_COMMAND_WRITEFILE       1


#define FS_COMMAND_SEEKDIR         2


#define FS_COMMAND_READDIR         3


#define FS_COMMAND_FINDPATH        4


#define FS_COMMAND_GETPATH         5


#define FS_COMMAND_OPENFILEFAST    6


#define FS_COMMAND_OPENFILEDIRECT  7


#define FS_COMMAND_CLOSEFILE       8


#define FS_COMMAND_ACTIVATE        9


#define FS_COMMAND_IDLE            10


#define FS_COMMAND_SUSPEND         11


#define FS_COMMAND_RESUME          12


#define FS_COMMAND_OPENFILE        13


#define FS_COMMAND_SEEKFILE        14


#define FS_COMMAND_GETFILELENGTH   15


#define FS_COMMAND_GETFILEPOSITION 16


#define FS_COMMAND_MOUNT           17


#define FS_COMMAND_UNMOUNT         18



#define FS_ARCHIVE_FLAG_LOADED     0x00000002


#define FS_ARCHIVE_FLAG_TABLE_LOAD 0x00000004



static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive_02079304 *arc)
{
    return (arc->flag & FS_ARCHIVE_FLAG_LOADED) ? 1 : 0;
}



void *FS_UnloadArchiveTables(FSArchive_02079304 *arc)
{
    void *retval = 0;

    if (FS_IsArchiveLoaded(arc)) {
        FSROMFATArchiveContext_02079304 *const context = (FSROMFATArchiveContext_02079304 *)arc->userdata;
        BOOL bak_stat = FS_SuspendArchive(arc);
        if (FS_IsArchiveTableLoaded(arc)) {
            arc->flag &= ~FS_ARCHIVE_FLAG_TABLE_LOAD;
            retval = context->load_mem;
            context->fat = context->fat_bak;
            context->fnt = context->fnt_bak;
            context->load_mem = 0;
        }
        if (bak_stat) {
            (void)FS_ResumeArchive(arc);
        }
    }
    return retval;
}



void *FS_GetArchiveBase(void *arc)
{
    u32_3 **p = (u32_3 **)((char *)arc + 0x20);
    return (void *)**p;
}



u32_4 FS_GetArchiveOffset(void *arc, u32_4 pos)
{
    u32_4 *p = *(u32_4 **)((char *)arc + 0x20);
    return *p + pos;
}



int FS_IsArchiveTableLoaded(void *arc)
{
    u32_5 flag = *(u32_5 *)((char *)arc + 0x14);
    return (flag & 4) ? 1 : 0;
}
