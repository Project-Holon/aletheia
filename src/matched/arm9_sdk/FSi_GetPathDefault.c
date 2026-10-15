/*
 * function: FSi_GetPathDefault
 * address:  0x0207976C
 * packet:   pkt_0207976C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_proc_default.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: the ROM FAT default handler for GETPATH.
 * Finds the directory holding the file (scanning every directory when the
 * handle is a file), measures "arcname:/dir/.../name", records the length
 * and directory, and when the caller's buffer is large enough writes the
 * path back to front.  ":/" is the object's anonymous string @13362, too
 * short for the string class, so it is declared at its address.
 *
 * symbols:
 *   FS_InitFile            0x020788AC  arm
 *   FSi_SeekDirDirect      0x02079364  arm
 *   FSi_TranslateCommand   0x02079BFC  arm
 *   FS_GetArchiveName      0x02078530  arm
 *   STD_GetStringLength    0x0208CC78  arm
 *   MI_CpuCopy8            0x02082D44  arm
 *   fsi_str_colon_slash             0x020A84A8  data
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

#define FS_FILE_STATUS_IS_DIR 0x00000020
#define FS_COMMAND_READDIR 3

extern void FS_InitFile(FSFile *file);
extern void FSi_SeekDirDirect(FSFile *file, u32 id);
extern FSResult FSi_TranslateCommand(FSFile *file, FSCommandType command, BOOL block);
extern char *FS_GetArchiveName(FSArchive *arc);
extern int STD_GetStringLength(const char *str);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern const char fsi_str_colon_slash[];   /* ":/" */

static inline BOOL FS_IsDir(const FSFile *file)
{
    return (BOOL)((file->stat & FS_FILE_STATUS_IS_DIR) ? TRUE : FALSE);
}

FSResult FSi_GetPathDefault(FSFile *file)
{
    FSResult result;
    FSArchive *arc = file->arc;
    FSGetPathInfo *p_info = &file->arg.getpath;
    FSDirEntry entry;
    u32 dir_id;
    u32 file_id;

    enum { INVALID_ID = 0x10000 };

    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;

    if (FS_IsDir(file)) {
        dir_id = file->prop.dir.pos.own_id;
        file_id = INVALID_ID;
    } else {
        file_id = file->prop.file.own_id;
        {
            u32 pos = 0;
            u32 num_dir = 0;

            dir_id = INVALID_ID;
            do {
                FSi_SeekDirDirect(tmp, pos);
                if (!pos)
                    num_dir = tmp->prop.dir.parent;
                tmp->arg.readdir.p_entry = &entry;
                tmp->arg.readdir.skip_string = TRUE;
                while (FSi_TranslateCommand(tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                    if (!entry.is_directory && (entry.file_id.file_id == file_id)) {
                        dir_id = tmp->prop.dir.pos.own_id;
                        break;
                    }
                }
            } while ((dir_id == INVALID_ID) && (++pos < num_dir));
        }
    }

    if (dir_id == INVALID_ID) {
        p_info->total_len = 0;
        result = FS_RESULT_NO_ENTRY;
    } else {
        {
            u32 id = dir_id;
            const char *arcname = FS_GetArchiveName(arc);
            u32 len = (u32)STD_GetStringLength(arcname);

            len += 2;
            FSi_SeekDirDirect(tmp, id);
            if (file_id != INVALID_ID)
                len += entry.name_len;
            if (id != 0) {
                do {
                    FSi_SeekDirDirect(tmp, tmp->prop.dir.parent);
                    tmp->arg.readdir.p_entry = &entry;
                    tmp->arg.readdir.skip_string = TRUE;
                    while (FSi_TranslateCommand(tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                        if (entry.is_directory && (entry.dir_id.own_id == id)) {
                            len += entry.name_len + 1;
                            break;
                        }
                    }
                    id = tmp->prop.dir.pos.own_id;
                } while (id != 0);
            }
            p_info->total_len = (u16)(len + 1);
            p_info->dir_id = (u16)dir_id;
        }

        if (p_info->buf && (p_info->buf_len >= p_info->total_len)) {
            u8 *dst = p_info->buf;
            u32 total = p_info->total_len;
            u32 pos = 0;
            u32 id = dir_id;

            {
                const char *arcname = FS_GetArchiveName(arc);
                u32 len = (u32)STD_GetStringLength(arcname);

                MI_CpuCopy8(arcname, dst + pos, len);
                pos += len;
                MI_CpuCopy8(fsi_str_colon_slash, dst + pos, 2);
            }
            FSi_SeekDirDirect(tmp, id);
            if (file_id != INVALID_ID) {
                tmp->arg.readdir.p_entry = &entry;
                tmp->arg.readdir.skip_string = FALSE;
                while (FSi_TranslateCommand(tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                    if (!entry.is_directory && (entry.file_id.file_id == file_id))
                        break;
                }
                {
                    u32 len = entry.name_len + 1;

                    MI_CpuCopy8(entry.name, dst + total - len, len);
                    total -= len;
                }
            } else {
                dst[total - 1] = '\0';
                total -= 1;
            }
            if (id != 0) {
                do {
                    FSi_SeekDirDirect(tmp, tmp->prop.dir.parent);
                    tmp->arg.readdir.p_entry = &entry;
                    tmp->arg.readdir.skip_string = FALSE;
                    dst[total - 1] = '/';
                    total -= 1;
                    while (FSi_TranslateCommand(tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                        if (entry.is_directory && (entry.dir_id.own_id == id)) {
                            u32 len = entry.name_len;

                            MI_CpuCopy8(entry.name, dst + total - len, len);
                            total -= len;
                            break;
                        }
                    }
                    id = tmp->prop.dir.pos.own_id;
                } while (id != 0);
            }
        }
        result = FS_RESULT_SUCCESS;
    }
    return result;
}
