/*
 * function: FSi_NextCommand
 * address:  0x02077AD8
 * packet:   pkt_02077AD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_archive.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: first ends every command in the archive's list that
 * has been marked for cancellation, then picks the next command to run. When
 * the archive is neither suspending nor suspended and has work, it activates
 * an idle archive and marks the head command busy (waking its owner when the
 * call is blocking); otherwise it idles a running archive and completes a
 * pending suspend.  Each arm restores interrupts itself: the two copies are
 * cross-jumped, which leaves the then arm's inner branches on a `b` hop.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   FSi_EndCommand        0x0207765C  arm
 *   FSi_InvokeCommand     0x02077758  arm
 *   OS_WakeupThread       0x02085800  arm
 *   FS_InitFile           0x020788AC  arm
 */

typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef int FSResult;

#define FS_RESULT_CANCELED 3

#define FS_COMMAND_ACTIVATE 9
#define FS_COMMAND_IDLE     10

#define FS_FILE_STATUS_CANCEL    0x00000002
#define FS_FILE_STATUS_BLOCKING  0x00000004
#define FS_FILE_STATUS_BUSY      0x00000040

#define FS_ARCHIVE_FLAG_SUSPEND    0x00000008
#define FS_ARCHIVE_FLAG_RUNNING    0x00000010
#define FS_ARCHIVE_FLAG_CANCELING  0x00000020
#define FS_ARCHIVE_FLAG_SUSPENDING 0x00000040

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
    u32 name;
    struct FSArchive *next;
    FSFile *list;
    OSThreadQueue queue;
    u32 flag;
} FSArchive;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void FS_InitFile(FSFile *file);
extern void FSi_EndCommand(FSFile *file, FSResult ret);
extern FSResult FSi_InvokeCommand(FSFile *file, u32 command);

static inline BOOL FS_IsCanceling(const FSFile *file)
{
    return (file->stat & FS_FILE_STATUS_CANCEL) ? 1 : 0;
}

FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner)
{
    FSFile *next = 0;

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if ((arc->flag & FS_ARCHIVE_FLAG_CANCELING) != 0) {
            FSFile *p;
            FSFile *q;
            arc->flag &= ~FS_ARCHIVE_FLAG_CANCELING;
            p = arc->list;
            while (p != 0) {
                BOOL c;
                q = p->next;
                c = FS_IsCanceling(p);
                if (c != 0) {
                    FSi_EndCommand(p, FS_RESULT_CANCELED);
                    if (q == 0) {
                        q = arc->list;
                    }
                }
                p = q;
            }
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (((arc->flag & FS_ARCHIVE_FLAG_SUSPENDING) == 0) &&
            ((arc->flag & FS_ARCHIVE_FLAG_SUSPEND) == 0) && (arc->list != 0)) {
            BOOL is_start = (owner && ((arc->flag & FS_ARCHIVE_FLAG_RUNNING) == 0));
            if (is_start) {
                arc->flag |= FS_ARCHIVE_FLAG_RUNNING;
            }
            (void)OS_RestoreInterrupts(bak_psr);
            if (is_start) {
                (void)FSi_InvokeCommand(arc->list, FS_COMMAND_ACTIVATE);
            }
            bak_psr = OS_DisableInterrupts();
            if (owner || is_start) {
                next = arc->list;
                next->stat |= FS_FILE_STATUS_BUSY;
            }
            if (owner && ((next->stat & FS_FILE_STATUS_BLOCKING) != 0)) {
                OS_WakeupThread(next->queue);
                next = 0;
            }
            (void)OS_RestoreInterrupts(bak_psr);
        } else {
            if (owner) {
                if ((arc->flag & FS_ARCHIVE_FLAG_RUNNING) != 0) {
                    FSFile tmp;
                    FS_InitFile(&tmp);
                    tmp.arc = arc;
                    arc->flag &= ~FS_ARCHIVE_FLAG_RUNNING;
                    (void)FSi_InvokeCommand(&tmp, FS_COMMAND_IDLE);
                }
                if ((arc->flag & FS_ARCHIVE_FLAG_SUSPENDING) != 0) {
                    arc->flag &= ~FS_ARCHIVE_FLAG_SUSPENDING;
                    arc->flag |= FS_ARCHIVE_FLAG_SUSPEND;
                    OS_WakeupThread(&arc->queue);
                }
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
    }
    return next;
}
