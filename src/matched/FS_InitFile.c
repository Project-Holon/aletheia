/*
 * function: FS_InitFile
 * address:  0x020788AC
 * packet:   pkt_020788AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_file.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Clears a file object; the status word carries FS_COMMAND_INVALID (35) in
 * its command field.  The status is cleared and then or-ed: the zero store
 * folds away but leaves `orr r1, zero, #0x2300`.
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

#define FS_COMMAND_INVALID 35

void FS_InitFile(FSFile *file)
{
    file->arc = 0;
    file->userdata = 0;
    file->next = 0;
    file->queue->head = file->queue->tail = 0;
    file->stat = 0;
    file->stat |= (FS_COMMAND_INVALID << FS_FILE_STATUS_CMD_SHIFT);
    file->argument = 0;
    file->error = FS_RESULT_SUCCESS;
}
