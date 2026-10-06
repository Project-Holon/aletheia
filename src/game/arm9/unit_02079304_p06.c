/*
 * file:     unit_02079304_p06.c
 * unit:     yes
 * function: func_0207A2E0, func_0207A40C, func_0207A45C, func_0207A484, FS_LoadArchive
 * address:  0x0207A2E0
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
 *   FSi_ReadTable                0x02079304  arm
 *   MI_CpuFill8                  0x02082BCC  arm
 *   FSi_ROMFAT_FindPath          0x02079ED4  arm
 *   FSi_IsUnreadableRomOffset    0x0207A980  arm
 *   CARD_GetRomHeader            0x02075DEC  arm
 *   MI_CpuCopy8                  0x02082D44  arm
 *   FS_GetArchiveOffset          0x0207A798  arm
 *   FS_MountArchive              0x02078540  arm
 *   FSiArchiveProcInterface      0x020A1A38  data
 */
struct FSArchive;
struct FSFile;
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

typedef struct FSDateTime {
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;
} FSDateTime;

typedef struct FSPathInfo {
    u32 attributes;
    FSDateTime ctime;
    FSDateTime mtime;
    FSDateTime atime;
    u32 filesize;
    u32 id;
} FSPathInfo;

typedef struct CARDRomHeader {
    u8 pad[0x80];
    u32 rom_size;
} CARDRomHeader;

typedef struct FSArchiveResource {
    u64 totalSize;
    u64 availableSize;
    u32 maxFileHandles;
    u32 currentFileHandles;
    u32 maxDirectoryHandles;
    u32 currentDirectoryHandles;
    u32 bytesPerSector;
    u32 sectorsPerCluster;
    u32 totalClusters;
    u32 availableClusters;
} FSArchiveResource;

typedef struct FSArchiveInterface FSArchiveInterface;

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory);
extern FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
extern BOOL FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);
extern const CARDRomHeader *CARD_GetRomHeader(void);
extern u32 FS_GetArchiveOffset(const FSArchive *arc, u32 pos);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern BOOL FS_MountArchive(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl, u32 reserved);
FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info);
FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResource *resource);
FSResult FSi_ReadMemCallback(FSArchive *p_arc, void *dst, u32 pos, u32 size);
FSResult FSi_WriteMemCallback(FSArchive *p_arc, const void *src, u32 pos, u32 size);
BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func);
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




#define FS_ATTRIBUTE_IS_DIRECTORY 0x00000100



#define FS_ATTRIBUTE_IS_PROTECTED 0x00000200



#define FS_ATTRIBUTE_IS_OFFLINE   0x00000400




FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info)
{
    FSResult result = FS_RESULT_ERROR;
    u32 id = 0;

    MI_CpuFill8(info, 0x00, sizeof(*info));
    if (FSi_ROMFAT_FindPath(arc, baseid, path, &id, 1) == FS_RESULT_SUCCESS) {
        info->attributes = FS_ATTRIBUTE_IS_DIRECTORY;
        info->id = id;
        result = FS_RESULT_SUCCESS;
    } else if (FSi_ROMFAT_FindPath(arc, baseid, path, &id, 0) == FS_RESULT_SUCCESS) {
        info->attributes = 0;
        info->id = id;
        info->filesize = 0;
        {
            FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)arc->userdata;
            const u32 pos = id * sizeof(FSArchiveFAT);
            if (pos < context->fat_size) {
                FSArchiveFAT fat;
                FSiSyncReadParam param;
                param.arc = arc;
                param.pos = context->fat + pos;
                if (FSi_ReadTable(&param, &fat, sizeof(fat)) == FS_RESULT_SUCCESS) {
                    info->filesize = fat.bottom - fat.top;
                    if (FSi_IsUnreadableRomOffset(arc, fat.top)) {
                        info->attributes |= FS_ATTRIBUTE_IS_OFFLINE;
                    }
                }
            }
        }
        result = FS_RESULT_SUCCESS;
    }
    info->attributes |= FS_ATTRIBUTE_IS_PROTECTED;
    return result;
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




FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResource *resource)
{
    const CARDRomHeader *header = CARD_GetRomHeader();

    resource->bytesPerSector = 0;
    resource->sectorsPerCluster = 0;
    resource->totalClusters = 0;
    resource->availableClusters = 0;
    resource->totalSize = header->rom_size;
    resource->availableSize = 0;
    resource->maxFileHandles = 0x7FFFFFFF;
    resource->currentFileHandles = 0;
    resource->maxDirectoryHandles = 0x7FFFFFFF;
    resource->currentDirectoryHandles = 0;
    return FS_RESULT_SUCCESS;
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




FSResult FSi_ReadMemCallback(FSArchive *p_arc, void *dst, u32 pos, u32 size)
{
    MI_CpuCopy8((const void *)FS_GetArchiveOffset(p_arc, pos), dst, size);
    return FS_RESULT_SUCCESS;
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




FSResult FSi_WriteMemCallback(FSArchive *p_arc, const void *src, u32 pos, u32 size)
{
    MI_CpuCopy8(src, (void *)FS_GetArchiveOffset(p_arc, pos), size);
    return FS_RESULT_SUCCESS;
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


BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func)
{
    FSROMFATArchiveContext *context = &arc->context;

    context->base = base;
    context->fat_size = fat_size;
    context->fat_bak = context->fat = fat;
    context->fnt_size = fnt_size;
    context->fnt_bak = context->fnt = fnt;
    context->read_func = read_func ? read_func : FSi_ReadMemCallback;
    context->write_func = write_func ? write_func : (FS_ARCHIVE_WRITE_FUNC)FSi_WriteMemCallback;
    context->load_mem = 0;
    return FS_MountArchive(arc, context, &FSiArchiveProcInterface, 0);
}
