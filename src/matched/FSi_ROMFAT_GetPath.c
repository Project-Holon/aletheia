/*
 * function: FSi_ROMFAT_GetPath
 * address:  0x02079F60
 * packet:   pkt_02079F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_proc_default.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: builds the full path of a handle into buffer
 * and returns its length.
 *
 * symbols:
 *   FSi_TranslateCommand         0x02079BFC  arm
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

extern FSResult FSi_TranslateCommand(FSFile *file, u32 command, BOOL block);

FSResult FSi_ROMFAT_GetPath(FSArchive *arc, FSFile *file, BOOL is_directory, char *buffer, u32 *length)
{
    FSResult result;
    FSROMFATCommandInfo *arg = &file->arg;

    arg->getpath.total_len = 0;
    arg->getpath.dir_id = 0;
    arg->getpath.buf = (u8 *)buffer;
    arg->getpath.buf_len = *length;
    result = FSi_TranslateCommand(file, FS_COMMAND_GETPATH, 1);
    if (result == FS_RESULT_SUCCESS) {
        *length = arg->getpath.buf_len;
    }
    return result;
}
