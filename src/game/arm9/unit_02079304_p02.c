/*
 * file:     unit_02079304_p02.c
 * unit:     yes
 * function: func_0207942C, func_02079558
 * address:  0x0207942C
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
 *   FSi_TranslateCommand             0x02079BFC  arm
 *   FSi_IncrementSjisPositionToSlash 0x020787E0  arm
 *   FSi_SeekDirDirect                0x02079364  arm
 */
struct FSArchive_0;
struct FSFile_0;
struct FSDirEntry_1;
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

typedef struct FSFileID_0 {
    FSArchive_0 *arc;
    u32 file_id;
} FSFileID_0;

typedef struct FSDirPos_0 {
    FSArchive_0 *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos_0;

typedef struct FSDirEntry_0 {
    union {
        FSFileID_0 file_id;
        FSDirPos_0 dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
} FSDirEntry_0;

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

typedef union FSROMFATProperty_0 {
    FSROMFATFileProperty file;
    FSROMFATDirProperty dir;
} FSROMFATProperty_0;

typedef struct FSReadFileInfo { void *dst; u32 len_org; u32 len; } FSReadFileInfo;

typedef struct FSWriteFileInfo { const void *src; u32 len_org; u32 len; } FSWriteFileInfo;

typedef struct FSSeekDirInfo { FSDirPos_0 pos; } FSSeekDirInfo;

typedef struct FSReadDirInfo { FSDirEntry_0 *p_entry; BOOL skip_string; } FSReadDirInfo;

typedef struct FSFindPathInfo { FSDirPos_0 pos; const char *path; BOOL find_directory; union { FSFileID_0 *file; FSDirPos_0 *dir; } result; } FSFindPathInfo;

typedef struct FSGetPathInfo_0 { u8 *buf; u32 buf_len; u16 total_len; u16 dir_id; } FSGetPathInfo_0;

typedef struct FSOpenFileFastInfo { FSFileID_0 id; } FSOpenFileFastInfo;

typedef struct FSOpenFileDirectInfo { u32 top; u32 bottom; u32 index; } FSOpenFileDirectInfo;

typedef struct FSCloseFileInfo { u32 reserved; } FSCloseFileInfo;

typedef union FSROMFATCommandInfo_0 {
    FSReadFileInfo readfile;
    FSWriteFileInfo writefile;
    FSSeekDirInfo seekdir;
    FSReadDirInfo readdir;
    FSFindPathInfo findpath;
    FSGetPathInfo_0 getpath;
    FSOpenFileFastInfo openfilefast;
    FSOpenFileDirectInfo openfiledirect;
    FSCloseFileInfo closefile;
    u8 reserved2[24];
} FSROMFATCommandInfo_0;

typedef struct FSFile_0 {
    struct FSFile_0 *next;
    void *userdata;
    FSArchive_0 *arc;
    u32 stat;
    void *argument;
    FSResult_0 error;
    OSThreadQueue queue[1];
    FSROMFATProperty_0 prop;
    FSROMFATCommandInfo_0 arg;
} FSFile_0;

typedef struct FSiSyncReadParam {
    FSArchive_0 *arc;
    u32 pos;
} FSiSyncReadParam;

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

typedef struct FSArchive_1 FSArchive_1;

typedef struct FSDirPos_1 {
    struct FSArchive_1 *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos_1;

typedef union FSROMFATProperty_1 {
    struct {
        u32 own_id;
        u32 top;
        u32 bottom;
        u32 pos;
    } file;
    struct {
        FSDirPos_1 pos;
        u32 parent;
    } dir;
} FSROMFATProperty_1;

typedef struct FSGetPathInfo_ {
    u8 *buf;
    u32 buf_len;
    u16 total_len;
    u16 dir_id;
} FSGetPathInfo_;

typedef union FSROMFATCommandInfo_1 {
    struct {
        struct FSDirEntry_1 *p_entry;
        BOOL skip_string;
    } readdir;
    FSGetPathInfo_ getpath;
    struct {
        FSDirPos_1 pos;
    } seekdir;
    struct {
        FSDirPos_1 pos;
        const char *path;
        BOOL find_directory;
        union {
            struct FSFileID_1 *file;
            FSDirPos_1 *dir;
        } result;
    } findpath;
    unsigned char reserved[24];
} FSROMFATCommandInfo_1;

typedef struct FSFile_1 {
    struct FSFile_1 *next;
    void *userdata;
    struct FSArchive_1 *arc;
    u32 stat;
    void *argument;
    FSResult_1 error;
    OSThreadQueue queue[1];
    FSROMFATProperty_1 prop;
    FSROMFATCommandInfo_1 arg;
} FSFile_1;

typedef struct FSFileID_1 {
    struct FSArchive_1 *arc;
    u32 file_id;
} FSFileID_1;

struct FSDirEntry_1 {
    union {
        FSFileID_1 file_id;
        FSDirPos_1 dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
};

typedef struct FSDirEntry_1 FSDirEntry_1;

typedef FSGetPathInfo_ FSGetPathInfo_1;

extern FSResult_0 FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
extern void FSi_SeekDirDirect(FSFile_1 *file, u32 id);
extern FSResult_1 FSi_TranslateCommand(FSFile_1 *file, FSCommandType command, BOOL block);
extern int FSi_IncrementSjisPositionToSlash(const char *str, int pos);
FSResult_0 FSi_ReadDirDefault(FSFile_0 *file);

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


FSResult_0 FSi_ReadDirDefault(FSFile_0 *file)
{
    FSResult_0 result;
    FSDirEntry_0 *entry = file->arg.readdir.p_entry;
    u8 len;
    FSiSyncReadParam param;
    u16 id;

    param.arc = file->arc;
    param.pos = file->prop.dir.pos.pos;
    result = FSi_ReadTable(&param, &len, sizeof(len));
    if (result == FS_RESULT_SUCCESS) {
        entry->name_len = (u32)(len & 0x7f);
        entry->is_directory = (u32)((len >> 7) & 1);
        if (entry->name_len == 0) {
            result = FS_RESULT_FAILURE;
        } else {
            if (!file->arg.readdir.skip_string) {
                result = FSi_ReadTable(&param, entry->name, entry->name_len);
                if (result != FS_RESULT_SUCCESS) {
                    return result;
                }
                entry->name[entry->name_len] = 0;
            } else {
                param.pos += entry->name_len;
            }
            if (!entry->is_directory) {
                entry->file_id.arc = file->arc;
                entry->file_id.file_id = file->prop.dir.pos.index;
                ++file->prop.dir.pos.index;
            } else {
                result = FSi_ReadTable(&param, &id, sizeof(id));
                if (result == FS_RESULT_SUCCESS) {
                    entry->dir_id.arc = file->arc;
                    entry->dir_id.own_id = (u16)(id & 0x0FFF);
                    entry->dir_id.index = 0;
                    entry->dir_id.pos = 0;
                }
            }
            if (result == FS_RESULT_SUCCESS) {
                file->prop.dir.pos.pos = param.pos;
            }
        }
    }
    return result;
}

#define TRUE 1

#define FALSE 0



#define FS_COMMAND_SEEKDIR 2

#define FS_COMMAND_READDIR 3


static inline int FSi_StrNICmp(const char *str1, const char *str2, u32 len)
{
    int retval = 0;
    u32 i;

    for (i = 0; i < len; ++i) {
        u32 c = (u8)(str1[i] - 'A');
        u32 d = (u8)(str2[i] - 'A');
        if (c <= 'Z' - 'A') {
            c += 'a' - 'A';
        }
        if (d <= 'Z' - 'A') {
            d += 'a' - 'A';
        }
        retval = (int)(c - d);
        if (retval != 0) {
            break;
        }
    }
    return retval;
}


static FSResult_1 FSi_FindPathDefault(FSFile_1 *p_dir)
{
    const char *path = p_dir->arg.findpath.path;
    BOOL is_dir = p_dir->arg.findpath.find_directory;

    (void)FSi_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);

    while (*path != '\0') {
        int name_len;
        u32 is_directory;
        FSDirEntry_1 etr;

        name_len = FSi_IncrementSjisPositionToSlash(path, 0);
        is_directory = ((path[name_len] != '\0') || is_dir);

        if (name_len == 0) {
            return FS_RESULT_INVALID_PARAMETER;
        }

        if (*path == '.') {
            if (name_len == 1) {
                path += 1;
                goto next;
            } else if ((name_len == 2) && (path[1] == '.')) {
                if (p_dir->prop.dir.pos.own_id != 0) {
                    FSi_SeekDirDirect(p_dir, p_dir->prop.dir.parent);
                }
                path += 2;
                goto next;
            }
        } else if (*path == '*') {
            break;
        }

        if (name_len > 127) {
            return FS_RESULT_NO_ENTRY;
        }

        p_dir->arg.readdir.p_entry = &etr;
        p_dir->arg.readdir.skip_string = FALSE;
        for (;;) {
            if (FSi_TranslateCommand(p_dir, FS_COMMAND_READDIR, TRUE) != FS_RESULT_SUCCESS) {
                return FS_RESULT_NO_ENTRY;
            }
            if ((is_directory == etr.is_directory) && (name_len == etr.name_len)
                && (FSi_StrNICmp(path, etr.name, (u32)name_len) == 0)) {
                break;
            }
        }

        if (is_directory) {
            p_dir->arg.seekdir.pos = etr.dir_id;
            path += name_len;
            (void)FSi_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);
        } else {
            if (is_dir) {
                return FS_RESULT_NO_ENTRY;
            }
            *p_dir->arg.findpath.result.file = etr.file_id;
            return FS_RESULT_SUCCESS;
        }
next:
        path += (*path != '\0');
    }

    if (!is_dir) {
        return FS_RESULT_NO_ENTRY;
    }
    *p_dir->arg.findpath.result.dir = p_dir->prop.dir.pos;
    return FS_RESULT_SUCCESS;
}
