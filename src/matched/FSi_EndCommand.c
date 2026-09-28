/*
 * function: FSi_EndCommand
 * address:  0x0207765C
 * packet:   pkt_0207765C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_archive.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: unlinks the file from its archive's list,
 * records the command and result on the archive unless it is an event
 * command, clears the busy flags and wakes the waiting threads.
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   OS_WakeupThread        0x02085800  arm
 *   FSi_IsEventCommand     0x02077634  arm
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

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern BOOL FSi_IsEventCommand(FSCommandType command);

void FSi_EndCommand(FSFile *file, FSResult ret)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    FSArchive *arc = file->arc;

    if (arc) {
        FSFile **pp;

        for (pp = &arc->list; *pp; pp = &(*pp)->next) {
            if (*pp == file) {
                *pp = file->next;
                break;
            }
        }
        file->next = 0;
    }
    {
        FSCommandType command = (file->stat >> FS_FILE_STATUS_CMD_SHIFT) & FS_FILE_STATUS_CMD_MASK;

        if (!FSi_IsEventCommand(command)) {
            if (arc) {
                arc->command = command;
                arc->result = ret;
            }
        }
    }
    file->error = ret;
    file->stat &= ~0xCF;   /* busy, cancel, blocking, done and the two top flags */
    OS_WakeupThread(file->queue);
    (void)OS_RestoreInterrupts(bak_psr);
}
