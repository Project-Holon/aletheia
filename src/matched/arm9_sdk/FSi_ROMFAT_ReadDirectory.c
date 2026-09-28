/*
 * function: FSi_ROMFAT_ReadDirectory
 * address:  0x02079DAC
 * packet:   pkt_02079DAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_proc_default.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: reads the next entry of a directory handle
 * into an FSDirectoryEntryInfo, taking a file's size from the FAT and
 * flagging files whose image is not readable from this ROM as offline.
 *
 * symbols:
 *   MI_CpuCopy8                  0x02082D44  arm
 *   FSi_ReadTable                0x02079304  arm
 *   FSi_TranslateCommand         0x02079BFC  arm
 *   FSi_IsUnreadableRomOffset    0x0207A980  arm
 */

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

typedef struct FSDateTime {
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;
} FSDateTime;

typedef struct FSDirectoryEntryInfo {
    char shortname[16];
    u32 shortname_length;
    char longname[260];
    u32 longname_length;
    u32 attributes;
    FSDateTime atime;
    FSDateTime mtime;
    FSDateTime ctime;
    u32 filesize;
    u32 id;
} FSDirectoryEntryInfo;

#define FS_ATTRIBUTE_IS_DIRECTORY 0x00000100
#define FS_ATTRIBUTE_IS_OFFLINE   0x00000400

extern FSResult FSi_TranslateCommand(FSFile *file, u32 command, BOOL block);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
extern BOOL FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);

FSResult FSi_ROMFAT_ReadDirectory(FSArchive *arc, FSFile *file, FSDirectoryEntryInfo *info)
{
    FSResult result;
    FSDirEntry entry[1];

    {
        FSROMFATCommandInfo *arg = &file->arg;
        arg->readdir.p_entry = entry;
        arg->readdir.skip_string = 0;
        result = FSi_TranslateCommand(file, FS_COMMAND_READDIR, 1);
    }
    if (result == FS_RESULT_SUCCESS) {
        info->shortname_length = 0;
        info->longname_length = entry->name_len;
        MI_CpuCopy8(entry->name, info->longname, info->longname_length);
        info->longname[info->longname_length] = 0;
        if (entry->is_directory) {
            info->attributes = FS_ATTRIBUTE_IS_DIRECTORY;
            info->id = (u32)(entry->dir_id.own_id | (entry->dir_id.index << 16));
            info->filesize = 0;
        } else {
            info->attributes = 0;
            info->id = entry->file_id.file_id;
            info->filesize = 0;
            {
                FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)arc->userdata;
                const u32 pos = info->id * sizeof(FSArchiveFAT);
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
        }
        info->mtime.year = 0;
        info->mtime.month = 0;
        info->mtime.day = 0;
        info->mtime.hour = 0;
        info->mtime.minute = 0;
        info->mtime.second = 0;
    }
    return result;
}
