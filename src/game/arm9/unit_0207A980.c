/*
 * file:     unit_0207A980.c
 * unit:     yes
 * function: func_0207A980, func_0207A9C8, func_0207A9EC, FSi_RomArchiveProc, FSi_EmptyArchiveProc
 * address:  0x0207A980
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
 *   FS_GetArchiveName                0x02078530 arm
 *   STD_CompareString                0x0208cd94 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   CARD_GetOwnRomHeader             0x02075df8 arm
 *   g_020A84B0                       0x020a84b0 data
 *   CARD_IsPulledOut                 0x020774b0 arm
 *   FS_NotifyArchiveAsyncEnd         0x02078734 arm
 *   CARDi_ReadRom                    0x020771b4 arm
 *   FSi_OnRomReadDone                0x0207a9c8 arm
 *   func_02075E10 0x02075E10 arm
 *   func_02075E80 0x02075E80 arm
 *   func_0207A980 0x0207A980 arm
 *   g_02150DA0 0x02150DA0 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
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

struct FSArchive;
struct FSFile;

typedef FSResult (*FS_ARCHIVE_READ_FUNC)(struct FSArchive *p, void *dst, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(struct FSArchive *p, const void *src, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(struct FSFile *file, u32 command);

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

typedef struct FSArchive {
    u32 name;
    struct FSArchive *next;
    struct FSFile *list;
    OSThreadQueue queue;
    u32 flag;
    u32 command;
    FSResult result;
    void *userdata;
    const void *vtbl;
    FSROMFATArchiveContext context;
} FSArchive;

typedef struct FSFileID {
    FSArchive *arc;
    u32 file_id;
} FSFileID;

typedef struct FSDirPos {
    FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos;

typedef struct FSDirEntry {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
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
    FSDirPos pos;
    u32 parent;
} FSROMFATDirProperty;

typedef union FSROMFATProperty {
    FSROMFATFileProperty file;
    FSROMFATDirProperty dir;
} FSROMFATProperty;

typedef struct FSReadFileInfo { void *dst; u32 len_org; u32 len; } FSReadFileInfo;

typedef struct FSWriteFileInfo { const void *src; u32 len_org; u32 len; } FSWriteFileInfo;

typedef struct FSSeekDirInfo { FSDirPos pos; } FSSeekDirInfo;

typedef struct FSReadDirInfo { FSDirEntry *p_entry; BOOL skip_string; } FSReadDirInfo;

typedef struct FSFindPathInfo { FSDirPos pos; const char *path; BOOL find_directory; union { FSFileID *file; FSDirPos *dir; } result; } FSFindPathInfo;

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

typedef struct FSFile {
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    FSROMFATProperty prop;
    FSROMFATCommandInfo arg;
} FSFile;

typedef struct FSiSyncReadParam {
    FSArchive *arc;
    u32 pos;
} FSiSyncReadParam;

typedef struct CARDRomHeader {
    u8 head[0x92];
    u16 twl_ltd_area_rom_offset;
} CARDRomHeader;

typedef struct FSiDefaultState {
    u32 dma_no;
    u32 lock_id;
} FSiDefaultState;

extern char *func_02078530(FSArchive *arc);
extern int func_0208CD94(const char *str1, const char *str2);
extern int OS_IsRunOnTwl(void);
extern void *func_020774B0(void);
extern void func_02078734(FSArchive *arc, FSResult ret);
extern void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len,
                          void (*callback)(void *), void *arg, int is_async);
extern void func_02075E10(u16 lock_id);
extern void func_02075E80(u16 lock_id);
extern FSiDefaultState g_02150DA0;
extern const char g_020A84B0[]; /* "rom", the vendor object's @12296 */
extern CARDRomHeader *CARD_GetOwnRomHeader(void);

int func_0207A980(FSArchive *arc, u32 offset);
static void func_0207A9C8(void *arg);
static FSResult func_0207A9EC(FSArchive *p_arc, void *dst, u32 src, u32 len);
FSResult FSi_RomArchiveProc(FSFile *file, FSCommandType cmd);
FSResult FSi_EmptyArchiveProc(FSFile *file, FSCommandType cmd);

/*
 * sdk:      FSi_IsUnreadableRomOffset (fs_proc_rom.o)
 */
int func_0207A980(FSArchive *arc, u32 offset)
{
    int result = 0;

    if (func_0208CD94(func_02078530(arc), g_020A84B0) == 0 && !OS_IsRunOnTwl()) {
        CARDRomHeader *header = CARD_GetOwnRomHeader();
        if (offset >= (u32)header->twl_ltd_area_rom_offset * 0x80000) {
            result = 1;
        }
    }
    return result;
}

/*
 * sdk:      FSi_OnRomReadDone (fs_proc_rom.o)
 */
static void func_0207A9C8(void *arg)
{
    func_02078734((FSArchive *)arg, func_020774B0() ? FS_RESULT_ERROR : FS_RESULT_SUCCESS);
}

/*
 * sdk:      FSi_ReadRomCallback (fs_proc_rom.o)
 */
static FSResult func_0207A9EC(FSArchive *p_arc, void *dst, u32 src, u32 len)
{
    CARDi_ReadRom(g_02150DA0.dma_no, (const void *)src, dst, len, func_0207A9C8, p_arc, 1);
    return FS_RESULT_PROC_ASYNC;
}

FSResult FSi_RomArchiveProc(FSFile *file, FSCommandType cmd)
{
    switch (cmd) {
    case FS_COMMAND_ACTIVATE:
        func_02075E10((u16)g_02150DA0.lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_IDLE:
        func_02075E80((u16)g_02150DA0.lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_OPENFILEDIRECT:
        if (func_0207A980(file->arc, file->arg.openfiledirect.top)) {
            return FS_RESULT_PERMISSION_DENIED;
        }
        return FS_RESULT_PROC_DEFAULT;
    case FS_COMMAND_WRITEFILE:
        return FS_RESULT_UNSUPPORTED;
    default:
        return FS_RESULT_PROC_UNKNOWN;
    }
}

FSResult FSi_EmptyArchiveProc(FSFile *file, FSCommandType cmd)
{
    return (cmd == FS_COMMAND_WRITEFILE) ? FS_RESULT_UNSUPPORTED : FS_RESULT_PROC_UNKNOWN;
}
