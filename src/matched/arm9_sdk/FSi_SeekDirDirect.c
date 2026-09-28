/*
 * function: FSi_SeekDirDirect
 * address:  0x02079364
 * packet:   pkt_02079364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_proc_default.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: positions a directory handle at the start of
 * directory `id` of the file's own archive through the default handler.
 *
 * symbols:
 *   FSi_TranslateCommand                                   0x02079BFC  arm
 */

typedef unsigned long u32;
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

#define FS_FILE_STATUS_BLOCKING        0x00000004
#define FS_FILE_STATUS_OPERATION_DONE  0x00000008
#define FS_FILE_STATUS_CMD_SHIFT       8
#define FS_FILE_STATUS_CMD_MASK        0x000000FF

struct FSArchive;

typedef struct FSDirPos {
    struct FSArchive *arc;
    unsigned short own_id;
    unsigned short index;
    u32 pos;
} FSDirPos;

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    struct FSArchive *arc;
    u32 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    unsigned char reserved1[16];
    union {
        unsigned char reserved2[24];
        struct {
            FSDirPos pos;
        } seekdir;
    } arg;
} FSFile;

typedef struct FSArchive {
    u32 header[2];
    FSFile *list;
    u32 opaque[3];
    FSCommandType command;
    FSResult result;
    void *userdata;
    const void *vtbl;
} FSArchive;

extern FSResult FSi_TranslateCommand(FSFile *file, FSCommandType command, BOOL block);

void FSi_SeekDirDirect(FSFile *file, u32 id)
{
    file->arg.seekdir.pos.arc = file->arc;
    file->arg.seekdir.pos.own_id = (unsigned short)id;
    file->arg.seekdir.pos.index = 0;
    file->arg.seekdir.pos.pos = 0;
    (void)FSi_TranslateCommand(file, 2, 1);
}
