/*
 * function: FSi_TranslateCommand
 * address:  0x02079BFC
 * packet:   pkt_02079BFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_proc_default.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: offers a command to the archive's user
 * procedure when its bit is set in proc_flag, then runs the default ROM FAT
 * handler unless the procedure took it, and waits when `block` is set.  A
 * procedure that answers FS_RESULT_PROC_UNKNOWN is not asked again for that
 * command.  default_table is the function's own static handler table.
 *
 * symbols:
 *   FSi_WaitForArchiveCompletion                           0x02077700  arm
 *   _ZZ20FSi_TranslateCommandP6FSFilemiE13default_table    0x020A1A04  data
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

typedef struct FSROMFATArchiveContext {
    u32 opaque[11];
    FSResult (*proc)(FSFile *file, FSCommandType command);
    u32 proc_flag;
} FSROMFATArchiveContext;

typedef FSResult (*FSROMFATDefaultProc)(FSFile *file);

extern FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result);
extern const FSROMFATDefaultProc _ZZ20FSi_TranslateCommandP6FSFilemiE13default_table[13];

FSResult FSi_TranslateCommand(FSFile *file, FSCommandType command, BOOL block)
{
    FSResult result = FS_RESULT_PROC_DEFAULT;
    FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)file->arc->userdata;

    if ((context->proc_flag & (1 << command)) != 0) {
        result = (*context->proc)(file, command);
        switch (result) {
        case FS_RESULT_SUCCESS:
        case FS_RESULT_FAILURE:
        case FS_RESULT_UNSUPPORTED:
            break;
        case FS_RESULT_PROC_ASYNC:
            break;
        case FS_RESULT_PROC_UNKNOWN:
            result = FS_RESULT_PROC_DEFAULT;
            context->proc_flag &= ~(1 << command);
            break;
        }
    }
    if (result == FS_RESULT_PROC_DEFAULT) {
        if (command < 13)
            result = (*_ZZ20FSi_TranslateCommandP6FSFilemiE13default_table[command])(file);
        else
            result = FS_RESULT_UNSUPPORTED;
    }
    if (block)
        result = FSi_WaitForArchiveCompletion(file, result);
    return result;
}
