/*
 * function: FSi_FindPathDefault
 * address:  0x02079558
 * packet:   pkt_02079558
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_proc_default.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: the ROM FAT default handler for FINDPATH.
 * Walks the path one component at a time from the directory in
 * arg.findpath.pos, handling "." and "..", reading directory entries until
 * one matches the component case-insensitively, and stores the file id or
 * directory position found.
 *
 * symbols:
 *   FSi_TranslateCommand             0x02079BFC  arm
 *   FSi_IncrementSjisPositionToSlash 0x020787E0  arm
 *   FSi_SeekDirDirect                0x02079364  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

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

struct FSArchive;
typedef struct FSArchive FSArchive;
struct FSDirEntry;

typedef struct FSDirPos {
    struct FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos;

typedef union FSROMFATProperty {
    struct {
        u32 own_id;
        u32 top;
        u32 bottom;
        u32 pos;
    } file;
    struct {
        FSDirPos pos;
        u32 parent;
    } dir;
} FSROMFATProperty;

typedef struct FSGetPathInfo_ {
    u8 *buf;
    u32 buf_len;
    u16 total_len;
    u16 dir_id;
} FSGetPathInfo_;

typedef union FSROMFATCommandInfo {
    struct {
        struct FSDirEntry *p_entry;
        BOOL skip_string;
    } readdir;
    FSGetPathInfo_ getpath;
    struct {
        FSDirPos pos;
    } seekdir;
    struct {
        FSDirPos pos;
        const char *path;
        BOOL find_directory;
        union {
            struct FSFileID *file;
            FSDirPos *dir;
        } result;
    } findpath;
    unsigned char reserved[24];
} FSROMFATCommandInfo;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    struct FSArchive *arc;
    u32 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    FSROMFATProperty prop;
    FSROMFATCommandInfo arg;
} FSFile;

typedef struct FSFileID {
    struct FSArchive *arc;
    u32 file_id;
} FSFileID;

struct FSDirEntry {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
};
typedef struct FSDirEntry FSDirEntry;

typedef FSGetPathInfo_ FSGetPathInfo;


#define FS_COMMAND_SEEKDIR 2
#define FS_COMMAND_READDIR 3

extern void FSi_SeekDirDirect(FSFile *file, u32 id);
extern FSResult FSi_TranslateCommand(FSFile *file, FSCommandType command, BOOL block);
extern int FSi_IncrementSjisPositionToSlash(const char *str, int pos);

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

static FSResult FSi_FindPathDefault(FSFile *p_dir)
{
    const char *path = p_dir->arg.findpath.path;
    BOOL is_dir = p_dir->arg.findpath.find_directory;

    (void)FSi_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);

    while (*path != '\0') {
        int name_len;
        u32 is_directory;
        FSDirEntry etr;

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
