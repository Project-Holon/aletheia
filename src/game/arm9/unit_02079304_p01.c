/*
 * file:     unit_02079304_p01.c
 * unit:     yes
 * function: func_02079304, func_02079364
 * address:  0x02079304
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
 *   MI_CpuCopy8                  0x02082D44  arm
 *   FSi_WaitForArchiveCompletion 0x02077700  arm
 *   FSi_TranslateCommand                                   0x02079BFC  arm
 */
struct FSArchive_0;
struct FSFile_0;
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

typedef int FSResult_0;

typedef FSResult_0 (*FS_ARCHIVE_READ_FUNC)(struct FSArchive_0 *p, void *dst, u32 pos, u32 size);

typedef FSResult_0 (*FS_ARCHIVE_WRITE_FUNC)(struct FSArchive_0 *p, const void *src, u32 pos, u32 size);

typedef FSResult_0 (*FS_ARCHIVE_PROC_FUNC)(struct FSFile_0 *file, u32 command);

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

typedef struct FSArchive_0 {
    u32 name;
    struct FSArchive_0 *next;
    struct FSFile_0 *list;
    OSThreadQueue queue;
    u32 flag;
    u32 command;
    FSResult_0 result;
    void *userdata;
    const void *vtbl;
    FSROMFATArchiveContext context;
} FSArchive_0;

typedef struct FSFileID {
    FSArchive_0 *arc;
    u32 file_id;
} FSFileID;

typedef struct FSDirPos_0 {
    FSArchive_0 *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos_0;

typedef struct FSDirEntry {
    union {
        FSFileID file_id;
        FSDirPos_0 dir_id;
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
    FSDirPos_0 pos;
    u32 parent;
} FSROMFATDirProperty;

typedef union FSROMFATProperty {
    FSROMFATFileProperty file;
    FSROMFATDirProperty dir;
} FSROMFATProperty;

typedef struct FSReadFileInfo { void *dst; u32 len_org; u32 len; } FSReadFileInfo;

typedef struct FSWriteFileInfo { const void *src; u32 len_org; u32 len; } FSWriteFileInfo;

typedef struct FSSeekDirInfo { FSDirPos_0 pos; } FSSeekDirInfo;

typedef struct FSReadDirInfo { FSDirEntry *p_entry; BOOL skip_string; } FSReadDirInfo;

typedef struct FSFindPathInfo { FSDirPos_0 pos; const char *path; BOOL find_directory; union { FSFileID *file; FSDirPos_0 *dir; } result; } FSFindPathInfo;

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

typedef struct FSFile_0 {
    struct FSFile_0 *next;
    void *userdata;
    FSArchive_0 *arc;
    u32 stat;
    void *argument;
    FSResult_0 error;
    OSThreadQueue queue[1];
    FSROMFATProperty prop;
    FSROMFATCommandInfo arg;
} FSFile_0;

typedef struct FSiSyncReadParam {
    FSArchive_0 *arc;
    u32 pos;
} FSiSyncReadParam;

typedef u32 OSIntrMode;

typedef enum FSResult_1 {
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
} FSResult_1;

typedef u32 FSCommandType;

typedef struct FSDirPos_1 {
    struct FSArchive_1 *arc;
    unsigned short own_id;
    unsigned short index;
    u32 pos;
} FSDirPos_1;

typedef struct FSFile_1 {
    struct FSFile_1 *next;
    void *userdata;
    struct FSArchive_1 *arc;
    u32 stat;
    void *argument;
    FSResult_1 error;
    OSThreadQueue queue[1];
    unsigned char reserved1[16];
    union {
        unsigned char reserved2[24];
        struct {
            FSDirPos_1 pos;
        } seekdir;
    } arg;
} FSFile_1;

typedef struct FSArchive_1 {
    u32 header[2];
    FSFile_1 *list;
    u32 opaque[3];
    FSCommandType command;
    FSResult_1 result;
    void *userdata;
    const void *vtbl;
} FSArchive_1;

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern FSResult_0 FSi_WaitForArchiveCompletion(FSFile_0 *file, FSResult_0 result);
extern FSResult_1 FSi_TranslateCommand(FSFile_1 *file, FSCommandType command, BOOL block);
FSResult_0 FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
void FSi_SeekDirDirect(FSFile_1 *file, u32 id);

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


FSResult_0 FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len)
{
    FSResult_0 result;
    FSArchive_0 *const arc = p->arc;
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;

    if (context->load_mem != 0) {
        MI_CpuCopy8((const void *)p->pos, dst, len);
        result = FS_RESULT_SUCCESS;
    } else {
        result = (*context->read_func)(arc, dst, p->pos, len);
        result = FSi_WaitForArchiveCompletion(arc->list, result);
    }
    p->pos += len;
    return result;
}


#define FS_FILE_STATUS_BLOCKING        0x00000004

#define FS_FILE_STATUS_OPERATION_DONE  0x00000008

#define FS_FILE_STATUS_CMD_SHIFT       8

#define FS_FILE_STATUS_CMD_MASK        0x000000FF


void FSi_SeekDirDirect(FSFile_1 *file, u32 id)
{
    file->arg.seekdir.pos.arc = file->arc;
    file->arg.seekdir.pos.own_id = (unsigned short)id;
    file->arg.seekdir.pos.index = 0;
    file->arg.seekdir.pos.pos = 0;
    (void)FSi_TranslateCommand(file, 2, 1);
}
