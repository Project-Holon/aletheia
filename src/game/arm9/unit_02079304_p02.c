/*
 * file:     unit_02079304_p02.c
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef enum FSResult {
    FS_RESULT_SUCCESS = 0,
    FS_RESULT_FAILURE,
    FS_RESULT_BUSY,
    FS_RESULT_CANCELED,
    FS_RESULT_UNSUPPORTED,
    FS_RESULT_ERROR,
    FS_RESULT_INVALID_PARAMETER,
    FS_RESULT_NO_MORE_RESOURCE,
    FS_RESULT_ALREADY_DONE,
    FS_RESULT_PERMISSION_DENIED,
    FS_RESULT_MEDIA_FATAL,
    FS_RESULT_NO_ENTRY,
    FS_RESULT_MEDIA_NOTHING,
    FS_RESULT_MEDIA_UNKNOWN,
    FS_RESULT_BAD_FORMAT,
    FS_RESULT_MAX,
    FS_RESULT_PROC_ASYNC = 256,
    FS_RESULT_PROC_DEFAULT,
    FS_RESULT_PROC_UNKNOWN
} FSResult;

typedef u32 FSCommandType;

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

#define FS_FILE_STATUS_BLOCKING        0x00000004
#define FS_FILE_STATUS_OPERATION_DONE  0x00000008
#define FS_FILE_STATUS_CMD_SHIFT       8
#define FS_FILE_STATUS_CMD_MASK        0x000000FF

struct FSArchive;
struct FSFile;

typedef FSResult (*FS_ARCHIVE_READ_FUNC)(struct FSArchive *p, void *dst, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(struct FSArchive *p, const void *src, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(struct FSFile *file, u32 command);

typedef struct FSROMFATArchiveContext {
    u32 base;
    u32 fat;
    u32 fat_size;
    u32 fnt;
    u32 fnt_size;
    u32 fat_bak;
    u32 fnt_bak;
    void *load_mem;
    FS_ARCHIVE_READ_FUNC read_func;
    FS_ARCHIVE_WRITE_FUNC write_func;
    u8 reserved3[4];
    FS_ARCHIVE_PROC_FUNC proc;
    u32 proc_flag;
} FSROMFATArchiveContext;

typedef struct FSArchive {
    u32 name;
    struct FSArchive *next;
    struct FSFile *list;
    OSThreadQueue queue;
    u32 flag;
    u32 command;
    FSResult result;
    void *userdata;
    const void *vtbl;
    FSROMFATArchiveContext context;
} FSArchive;

typedef struct FSFileID {
    FSArchive *arc;
    u32 file_id;
} FSFileID;

typedef struct FSDirPos {
    FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos;

typedef struct FSDirEntry {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
} FSDirEntry;

typedef struct FSArchiveFAT {
    u32 top;
    u32 bottom;
} FSArchiveFAT;

typedef struct FSArchiveFNT {
    u32 start;
    u16 index;
    u16 parent;
} FSArchiveFNT;

typedef struct FSROMFATFileProperty {
    u32 own_id;
    u32 top;
    u32 bottom;
    u32 pos;
} FSROMFATFileProperty;

typedef struct FSROMFATDirProperty {
    FSDirPos pos;
    u32 parent;
} FSROMFATDirProperty;

typedef union FSROMFATProperty {
    FSROMFATFileProperty file;
    FSROMFATDirProperty dir;
} FSROMFATProperty;

typedef struct FSReadFileInfo { void *dst; u32 len_org; u32 len; } FSReadFileInfo;

typedef struct FSWriteFileInfo { const void *src; u32 len_org; u32 len; } FSWriteFileInfo;

typedef struct FSSeekDirInfo { FSDirPos pos; } FSSeekDirInfo;

typedef struct FSReadDirInfo { FSDirEntry *p_entry; BOOL skip_string; } FSReadDirInfo;

typedef struct FSFindPathInfo { FSDirPos pos; const char *path; BOOL find_directory; union { FSFileID *file; FSDirPos *dir; } result; } FSFindPathInfo;

typedef struct FSGetPathInfo { u8 *buf; u32 buf_len; u16 total_len; u16 dir_id; } FSGetPathInfo;

typedef struct FSOpenFileFastInfo { FSFileID id; } FSOpenFileFastInfo;

typedef struct FSOpenFileDirectInfo { u32 top; u32 bottom; u32 index; } FSOpenFileDirectInfo;

typedef struct FSCloseFileInfo { u32 reserved; } FSCloseFileInfo;

typedef union FSROMFATCommandInfo {
    FSReadFileInfo readfile;
    FSWriteFileInfo writefile;
    FSSeekDirInfo seekdir;
    FSReadDirInfo readdir;
    FSFindPathInfo findpath;
    FSGetPathInfo getpath;
    FSOpenFileFastInfo openfilefast;
    FSOpenFileDirectInfo openfiledirect;
    FSCloseFileInfo closefile;
    u8 reserved2[24];
} FSROMFATCommandInfo;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    FSROMFATProperty prop;
    FSROMFATCommandInfo arg;
} FSFile;

typedef struct FSiSyncReadParam {
    FSArchive *arc;
    u32 pos;
} FSiSyncReadParam;

typedef struct FSArchiveInterface FSArchiveInterface;

extern FSResult FSi_ROMFAT_GetFileLength(FSArchive *arc, FSFile *file, u32 *length);
extern FSResult FSi_ROMFAT_GetFilePosition(FSArchive *arc, FSFile *file, u32 *position);
extern void FS_InitFile(FSFile *file);
extern BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
extern s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern BOOL FS_CloseFile(FSFile *file);
extern BOOL FS_SuspendArchive(FSArchive *arc);
extern BOOL FS_ResumeArchive(FSArchive *arc);
BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);
void FS_SetArchiveProc(void *arc, u32 proc, u32 flags);
u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size);
void *FS_UnloadArchiveTables(FSArchive *arc);
void *FS_GetArchiveBase(void *arc);
u32 FS_GetArchiveOffset(void *arc, u32 pos);
int FS_IsArchiveTableLoaded(void *arc);
extern const FSArchiveInterface FSiArchiveProcInterface;

BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length)
{
    return (file->arc->vtbl == &FSiArchiveProcInterface) &&
           (FSi_ROMFAT_GetFileLength(file->arc, file, length) == FS_RESULT_SUCCESS);
}

BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position)
{
    return (file->arc->vtbl == &FSiArchiveProcInterface) &&
           (FSi_ROMFAT_GetFilePosition(file->arc, file, position) == FS_RESULT_SUCCESS);
}

void FS_SetArchiveProc(void *arc, u32 proc, u32 flags)
{
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    *(u32 *)((char *)arc + 0x54) = proc;
    *(u32 *)((char *)arc + 0x58) = flags;
}

#define FS_ARCHIVE_FLAG_TABLE_LOAD 0x00000004

u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size)
{
    FSROMFATArchiveContext *context;
    u32 total_size;
    u8 *p_cache;
    FSFile tmp;

    if ((p_mem != 0) && FS_IsArchiveTableLoaded(p_arc)) {
        (void)FS_UnloadArchiveTables(p_arc);
    }
    context = (FSROMFATArchiveContext *)p_arc->userdata;
    total_size = (u32)((context->fat_size + context->fnt_size + 32 + 31) & ~31);
    if (total_size <= max_size) {
        p_cache = (u8 *)(((u32)p_mem + 31) & ~31);
        FS_InitFile(&tmp);
        if (FS_OpenFileDirect(&tmp, p_arc, context->fat, context->fat + context->fat_size, (u32)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (s32)context->fat_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fat_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fat = (u32)p_cache;
        p_cache += context->fat_size;
        if (FS_OpenFileDirect(&tmp, p_arc, context->fnt, context->fnt + context->fnt_size, (u32)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (s32)context->fnt_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fnt_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fnt = (u32)p_cache;
        context->load_mem = p_mem;
        p_arc->flag |= FS_ARCHIVE_FLAG_TABLE_LOAD;
    }
    return total_size;
}

#define FS_ARCHIVE_FLAG_LOADED     0x00000002

#define FS_ARCHIVE_FLAG_TABLE_LOAD 0x00000004

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & FS_ARCHIVE_FLAG_LOADED) ? 1 : 0;
}

void *FS_UnloadArchiveTables(FSArchive *arc)
{
    void *retval = 0;

    if (FS_IsArchiveLoaded(arc)) {
        FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;
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
    u32 **p = (u32 **)((char *)arc + 0x20);
    return (void *)**p;
}

u32 FS_GetArchiveOffset(void *arc, u32 pos)
{
    u32 *p = *(u32 **)((char *)arc + 0x20);
    return *p + pos;
}

int FS_IsArchiveTableLoaded(void *arc)
{
    u32 flag = *(u32 *)((char *)arc + 0x14);
    return (flag & 4) ? 1 : 0;
}
