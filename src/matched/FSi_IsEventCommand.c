/*
 * function: FSi_IsEventCommand
 * address:  0x02077634
 * packet:   pkt_02077634
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_archive.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: the commands that notify an archive of a
 * state change and complete without a result (activate, idle, suspend,
 * resume, mount, unmount, invalid).
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

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    struct FSArchive *arc;
    u32 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    unsigned char reserved1[16];
    unsigned char reserved2[24];
} FSFile;

typedef struct FSArchive {
    u32 header[2];
    FSFile *list;
    u32 opaque[3];
    FSCommandType command;
    FSResult result;
    u32 opaque2[1];
    const void *vtbl;
} FSArchive;

enum {
    FS_COMMAND_ACTIVATE = 9,
    FS_COMMAND_IDLE = 10,
    FS_COMMAND_SUSPEND = 11,
    FS_COMMAND_RESUME = 12,
    FS_COMMAND_MOUNT = 17,
    FS_COMMAND_UNMOUNT = 18,
    FS_COMMAND_INVALID = 35
};

BOOL FSi_IsEventCommand(FSCommandType command)
{
    return ((command == FS_COMMAND_ACTIVATE) ||
            (command == FS_COMMAND_IDLE) ||
            (command == FS_COMMAND_SUSPEND) ||
            (command == FS_COMMAND_RESUME) ||
            (command == FS_COMMAND_MOUNT) ||
            (command == FS_COMMAND_UNMOUNT) ||
            (command == FS_COMMAND_INVALID));
}
