/*
 * file:     fs_archive.c
 * unit:     yes
 * function: func_02077634, func_0207765C, FSi_WaitForArchiveCompletion, FSi_InvokeCommand, FSi_NextCommand, func_02077C78, func_02077CFC, FSi_SendCommand, func_02077EB8, func_02077F44, func_02078018, func_02078078, FS_InitArchive, FS_RegisterArchiveName, func_02078484, func_02078530, func_02078540, func_02078588, func_02078648, func_020786D8, func_02078734
 * address:  0x02077634
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
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   OS_WakeupThread        0x02085800  arm
 *   OS_SleepThread         0x020857B0  arm
 *   FS_InitFile           0x020788AC  arm
 *   FSi_ExecuteAsyncCommand  0x02077C78  arm
 *   OS_Terminate                 0x02088234  arm
 *   FSi_ExecuteSyncCommand       0x02077CFC  arm
 *   FS_GetArchiveName  0x02078530  arm
 *   STD_CompareNString  0x0208CE4C  arm
 *   arc_list  0x02150B0C  data
 *   FS_NormalizePath  0x02078078  arm
 *   STD_CopyLString  0x0208CB10  arm
 *   current_dir_path  0x02150C1C  data
 *   g_02150B0C                     0x02150B0C  data
 *   g_020A84A0                     0x020A84A0  data
 *   FSi_CopySafeString             0x02078018  arm
 *   FS_FindArchive                 0x02077EB8  arm
 *   FSi_DecrementSjisPositionToSlash 0x02078834  arm
 *   FSi_TrimSjisTrailingSlash      0x02078868  arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   fsi_archive_state  0x02150B0C  data
 *   FSiLongNameTable  0x02150B1C  data
 *   FS_SuspendArchive  0x02078648  arm
 *   FS_ResumeArchive  0x020786D8  arm
 */
struct FSArchive;
struct FSFile;
struct FSArchiveInterface;
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

typedef int FSResult;

typedef u32 FSCommandType;

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
    union {
        char ptr[4];
        u32 pack;
        char *name;
    } name;
    struct FSArchive *next;
    struct FSFile *list;
    OSThreadQueue queue;
    u32 flag;
    u32 command;
    FSResult result;
    void *userdata;
    const struct FSArchiveInterface *vtbl;
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

typedef enum FSSeekFileMode {
    FS_SEEK_SET,
    FS_SEEK_CUR,
    FS_SEEK_END
} FSSeekFileMode;

typedef struct FSDirectoryEntryInfo FSDirectoryEntryInfo;

typedef struct FSPathInfo FSPathInfo;

typedef struct FSArchiveResource FSArchiveResource;

typedef struct FSArchiveInterface {
    FSResult (*ReadFile)(FSArchive *, FSFile *, void *, u32 *);
    FSResult (*WriteFile)(FSArchive *, FSFile *, const void *, u32 *);
    FSResult (*SeekDirectory)(FSArchive *, FSFile *, u32, u32);
    FSResult (*ReadDirectory)(FSArchive *, FSFile *, FSDirectoryEntryInfo *);
    FSResult (*FindPath)(FSArchive *, u32, const char *, u32 *, BOOL);
    FSResult (*GetPath)(FSArchive *, FSFile *, BOOL, char *, u32 *);
    FSResult (*OpenFileFast)(FSArchive *, FSFile *, u32, u32);
    FSResult (*OpenFileDirect)(FSArchive *, FSFile *, u32, u32, u32 *);
    FSResult (*CloseFile)(FSArchive *, FSFile *);
    void (*Activate)(FSArchive *);
    void (*Idle)(FSArchive *);
    void (*Suspend)(FSArchive *);
    void (*Resume)(FSArchive *);
    FSResult (*OpenFile)(FSArchive *, FSFile *, u32, const char *, u32);
    FSResult (*SeekFile)(FSArchive *, FSFile *, int *, FSSeekFileMode);
    FSResult (*GetFileLength)(FSArchive *, FSFile *, u32 *);
    FSResult (*GetFilePosition)(FSArchive *, FSFile *, u32 *);
    void (*Mount)(FSArchive *);
    void (*Unmount)(FSArchive *);
    FSResult (*GetArchiveCaps)(FSArchive *, u32 *);
    FSResult (*CreateFile)(FSArchive *, u32, const char *, u32);
    FSResult (*DeleteFile)(FSArchive *, u32, const char *);
    FSResult (*RenameFile)(FSArchive *, u32, const char *, u32, const char *);
    FSResult (*GetPathInfo)(FSArchive *, u32, const char *, FSPathInfo *);
    FSResult (*SetPathInfo)(FSArchive *, u32, const char *, FSPathInfo *);
    FSResult (*CreateDirectory)(FSArchive *, u32, const char *, u32);
    FSResult (*DeleteDirectory)(FSArchive *, u32, const char *);
    FSResult (*RenameDirectory)(FSArchive *, u32, const char *, u32, const char *);
    FSResult (*GetArchiveResource)(FSArchive *, FSArchiveResource *);
    void *unused29;
    FSResult (*FlushFile)(FSArchive *, FSFile *);
    FSResult (*SetFileLength)(FSArchive *, FSFile *, u32);
    FSResult (*OpenDirectory)(FSArchive *, FSFile *, u32, const char *, u32);
    FSResult (*CloseDirectory)(FSArchive *, FSFile *);
    FSResult (*SetSeekCache)(FSArchive *, FSFile *, void *, u32);
} FSArchiveInterface;

typedef struct FSiArchiveBss {
    FSArchive *list;
    FSDirPos current_dir_pos;
} FSiArchiveBss;

typedef struct FSArgumentForReadFile { void *buffer; u32 length; } FSArgumentForReadFile;

typedef struct FSArgumentForWriteFile { const void *buffer; u32 length; } FSArgumentForWriteFile;

typedef struct FSArgumentForSeekDirectory { u32 id; u32 position; } FSArgumentForSeekDirectory;

typedef struct FSArgumentForReadDirectory { FSDirectoryEntryInfo *info; } FSArgumentForReadDirectory;

typedef struct FSArgumentForFindPath_0 { u32 baseid; const char *relpath; u32 target_id; BOOL target_is_directory; } FSArgumentForFindPath_0;

typedef struct FSArgumentForGetPath { BOOL is_directory; char *buffer; u32 length; } FSArgumentForGetPath;

typedef struct FSArgumentForOpenFileFast { u32 id; u32 mode; } FSArgumentForOpenFileFast;

typedef struct FSArgumentForOpenFileDirect { u32 id; u32 top; u32 bottom; u32 mode; } FSArgumentForOpenFileDirect;

typedef struct FSArgumentForOpenFile { u32 baseid; const char *relpath; u32 mode; } FSArgumentForOpenFile;

typedef struct FSArgumentForSeekFile { int offset; FSSeekFileMode from; } FSArgumentForSeekFile;

typedef struct FSArgumentForGetFileLength { u32 length; } FSArgumentForGetFileLength;

typedef struct FSArgumentForGetFilePosition { u32 position; } FSArgumentForGetFilePosition;

typedef struct FSArgumentForGetArchiveCaps { u32 caps; } FSArgumentForGetArchiveCaps;

typedef struct FSArgumentForCreateFile { u32 baseid; const char *relpath; u32 permit; } FSArgumentForCreateFile;

typedef struct FSArgumentForDeleteFile { u32 baseid; const char *relpath; } FSArgumentForDeleteFile;

typedef struct FSArgumentForRenameFile { u32 baseid_src; const char *relpath_src; u32 baseid_dst; const char *relpath_dst; } FSArgumentForRenameFile;

typedef struct FSArgumentForGetPathInfo { u32 baseid; const char *relpath; FSPathInfo *info; } FSArgumentForGetPathInfo;

typedef struct FSArgumentForSetPathInfo { u32 baseid; const char *relpath; FSPathInfo *info; } FSArgumentForSetPathInfo;

typedef struct FSArgumentForGetArchiveResource { FSArchiveResource *resource; } FSArgumentForGetArchiveResource;

typedef struct FSArgumentForSetFileLength { u32 length; } FSArgumentForSetFileLength;

typedef struct FSArgumentForSetSeekCache { void *buf; u32 buf_size; } FSArgumentForSetSeekCache;

typedef struct FSArgumentForFindPath_02077634
{
    u32 baseid;
    const char *path;
    u32 target_id;
    BOOL target_is_directory;
} FSArgumentForFindPath_02077634;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void OS_SleepThread(OSThreadQueue *queue);
extern void FS_InitFile(FSFile *file);
extern void FSi_ExecuteAsyncCommand(FSFile *file);
extern void OS_Terminate(void);
extern void FSi_ExecuteSyncCommand(FSFile *file);
extern const char *FS_GetArchiveName(const FSArchive *arc);
extern int STD_CompareNString(const char *str1, const char *str2, int len);
extern FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
extern int STD_CopyLString(char *destp, const char *srcp, int siz);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
void FS_InitArchive(FSArchive *p_arc);
extern FSArchive *FS_FindArchive(const char *name, int name_len);
BOOL FS_RegisterArchiveName(FSArchive *p_arc, const char *name, u32 name_len);
void func_02078484(FSArchive *p_arc);
char *func_02078530(FSArchive *arc);
BOOL func_02078540(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl);
extern BOOL FS_SuspendArchive(FSArchive *p_arc);
extern BOOL FS_ResumeArchive(FSArchive *arc);
BOOL func_02078588(FSArchive *arc);
BOOL func_02078648(FSArchive *p_arc);
BOOL func_020786D8(FSArchive *arc);
BOOL FSi_IsEventCommand(FSCommandType command);
void FSi_EndCommand(FSFile *file, FSResult ret);
FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result);
FSResult FSi_InvokeCommand(FSFile *file, FSCommandType command);
FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);
void func_02077C78(FSFile *file);
void func_02077CFC(FSFile *file);
BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking);
FSArchive *func_02077EB8(const char *name, int name_len);
BOOL func_02077F44(const char *path);
int func_02078018(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure);
void func_02078734(FSArchive *arc, int ret);
extern FSiArchiveBss g_02150B0C;
extern char current_dir_path[260];
extern FSiArchiveBss fsi_archive_state;
extern FSArchive *arc_list;
extern char FSiLongNameTable[16][16];











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










#define FS_RESULT_MEDIA_NOTHING      12










#define FS_RESULT_MEDIA_UNKNOWN      13










#define FS_RESULT_BAD_FORMAT         14










#define FS_RESULT_MAX                15










#define FS_RESULT_PROC_ASYNC         256










#define FS_RESULT_PROC_DEFAULT       257










#define FS_RESULT_PROC_UNKNOWN       258











enum {
    FS_COMMAND_READFILE = 0,
    FS_COMMAND_WRITEFILE,
    FS_COMMAND_SEEKDIR,
    FS_COMMAND_READDIR,
    FS_COMMAND_FINDPATH,
    FS_COMMAND_GETPATH,
    FS_COMMAND_OPENFILEFAST,
    FS_COMMAND_OPENFILEDIRECT,
    FS_COMMAND_CLOSEFILE,
    FS_COMMAND_ACTIVATE,
    FS_COMMAND_IDLE,
    FS_COMMAND_SUSPEND,
    FS_COMMAND_RESUME,
    FS_COMMAND_OPENFILE,
    FS_COMMAND_SEEKFILE,
    FS_COMMAND_GETFILELENGTH,
    FS_COMMAND_GETFILEPOSITION,
    FS_COMMAND_MOUNT,
    FS_COMMAND_UNMOUNT,
    FS_COMMAND_GETARCHIVECAPS,
    FS_COMMAND_CREATEFILE,
    FS_COMMAND_DELETEFILE,
    FS_COMMAND_RENAMEFILE,
    FS_COMMAND_GETPATHINFO,
    FS_COMMAND_SETPATHINFO,
    FS_COMMAND_CREATEDIRECTORY,
    FS_COMMAND_DELETEDIRECTORY,
    FS_COMMAND_RENAMEDIRECTORY,
    FS_COMMAND_GETARCHIVERESOURCE,
    FS_COMMAND_29,                  /* has a table slot, never dispatched here */
    FS_COMMAND_FLUSHFILE,
    FS_COMMAND_SETFILELENGTH,
    FS_COMMAND_OPENDIRECTORY,
    FS_COMMAND_CLOSEDIRECTORY,
    FS_COMMAND_SETSEEKCACHE,
    FS_COMMAND_MAX,
    FS_COMMAND_INVALID = 35
};











#define FS_FILE_STATUS_BUSY          0x00000001










#define FS_FILE_STATUS_CANCEL        0x00000002










#define FS_FILE_STATUS_BLOCKING      0x00000004










#define FS_FILE_STATUS_OPERATION_DONE 0x00000008










#define FS_FILE_STATUS_CMD_SHIFT     8










#define FS_FILE_STATUS_CMD_MASK      0x000000FF











#define FS_ARCHIVE_FLAG_SUSPEND      0x00000008










#define FS_ARCHIVE_FLAG_RUNNING      0x00000010










#define FS_ARCHIVE_FLAG_CANCELING    0x00000020










#define FS_ARCHIVE_FLAG_SUSPENDING   0x00000040










#define FS_ARCHIVE_FLAG_UNLOADING    0x00000080












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












FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result)
{
    if (result == FS_RESULT_PROC_ASYNC) {
        OSIntrMode bak_psr = OS_DisableInterrupts();

        while ((file->stat & FS_FILE_STATUS_OPERATION_DONE) == 0)
            OS_SleepThread(file->queue);
        (void)OS_RestoreInterrupts(bak_psr);
        file->stat &= ~FS_FILE_STATUS_OPERATION_DONE;
        result = file->error;
    }
    return result;
}














































#define FS_DECLARE_ARGUMENT_(type) type *arg = (type *)file->argument











FSResult FSi_InvokeCommand(FSFile *file, FSCommandType command)
{
    FSResult result;
    FSArchive *const arc = file->arc;
    {
        const void **table = (const void **)arc->vtbl;

        if (command >= FS_COMMAND_MAX) {
            result = FS_RESULT_UNSUPPORTED;
        } else if (table[command] == 0) {
            result = FS_RESULT_UNSUPPORTED;
        } else {
            switch (command) {
            case FS_COMMAND_READFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForReadFile);
                result = arc->vtbl->ReadFile(arc, file, arg->buffer, &arg->length);
            } break;
            case FS_COMMAND_WRITEFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForWriteFile);
                result = arc->vtbl->WriteFile(arc, file, arg->buffer, &arg->length);
            } break;
            case FS_COMMAND_SEEKDIR: {
                FS_DECLARE_ARGUMENT_(FSArgumentForSeekDirectory);
                result = arc->vtbl->SeekDirectory(arc, file, arg->id, arg->position);
            } break;
            case FS_COMMAND_READDIR:
                result = arc->vtbl->ReadDirectory(arc, file, ((FSArgumentForReadDirectory *)file->argument)->info);
                break;
            case FS_COMMAND_FINDPATH: {
                FS_DECLARE_ARGUMENT_(FSArgumentForFindPath_0);
                result = arc->vtbl->FindPath(arc, arg->baseid, arg->relpath, &arg->target_id, arg->target_is_directory);
            } break;
            case FS_COMMAND_GETPATH: {
                FS_DECLARE_ARGUMENT_(FSArgumentForGetPath);
                result = arc->vtbl->GetPath(arc, file, arg->is_directory, arg->buffer, &arg->length);
            } break;
            case FS_COMMAND_OPENFILEFAST: {
                FS_DECLARE_ARGUMENT_(FSArgumentForOpenFileFast);
                result = arc->vtbl->OpenFileFast(arc, file, arg->id, arg->mode);
            } break;
            case FS_COMMAND_OPENFILEDIRECT: {
                FS_DECLARE_ARGUMENT_(FSArgumentForOpenFileDirect);
                result = arc->vtbl->OpenFileDirect(arc, file, arg->top, arg->bottom, &arg->id);
            } break;
            case FS_COMMAND_CLOSEFILE:
                result = arc->vtbl->CloseFile(arc, file);
                break;
            case FS_COMMAND_ACTIVATE:
                arc->vtbl->Activate(arc);
                return FS_RESULT_SUCCESS;
            case FS_COMMAND_IDLE:
                arc->vtbl->Idle(arc);
                return FS_RESULT_SUCCESS;
            case FS_COMMAND_SUSPEND:
                arc->vtbl->Suspend(arc);
                return FS_RESULT_SUCCESS;
            case FS_COMMAND_RESUME:
                arc->vtbl->Resume(arc);
                return FS_RESULT_SUCCESS;
            case FS_COMMAND_OPENFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForOpenFile);
                result = arc->vtbl->OpenFile(arc, file, arg->baseid, arg->relpath, arg->mode);
            } break;
            case FS_COMMAND_SEEKFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForSeekFile);
                result = arc->vtbl->SeekFile(arc, file, &arg->offset, arg->from);
            } break;
            case FS_COMMAND_GETFILELENGTH:
                result = arc->vtbl->GetFileLength(arc, file, &((FSArgumentForGetFileLength *)file->argument)->length);
                break;
            case FS_COMMAND_GETFILEPOSITION:
                result = arc->vtbl->GetFilePosition(arc, file, &((FSArgumentForGetFilePosition *)file->argument)->position);
                break;
            case FS_COMMAND_MOUNT:
                arc->vtbl->Mount(arc);
                return FS_RESULT_SUCCESS;
            case FS_COMMAND_UNMOUNT:
                arc->vtbl->Unmount(arc);
                return FS_RESULT_SUCCESS;
            case FS_COMMAND_GETARCHIVECAPS:
                result = arc->vtbl->GetArchiveCaps(arc, &((FSArgumentForGetArchiveCaps *)file->argument)->caps);
                break;
            case FS_COMMAND_CREATEFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForCreateFile);
                result = arc->vtbl->CreateFile(arc, arg->baseid, arg->relpath, arg->permit);
            } break;
            case FS_COMMAND_DELETEFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForDeleteFile);
                result = arc->vtbl->DeleteFile(arc, arg->baseid, arg->relpath);
            } break;
            case FS_COMMAND_RENAMEFILE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForRenameFile);
                result = arc->vtbl->RenameFile(arc, arg->baseid_src, arg->relpath_src, arg->baseid_dst, arg->relpath_dst);
            } break;
            case FS_COMMAND_GETPATHINFO: {
                FS_DECLARE_ARGUMENT_(FSArgumentForGetPathInfo);
                result = arc->vtbl->GetPathInfo(arc, arg->baseid, arg->relpath, arg->info);
            } break;
            case FS_COMMAND_SETPATHINFO: {
                FS_DECLARE_ARGUMENT_(FSArgumentForSetPathInfo);
                result = arc->vtbl->SetPathInfo(arc, arg->baseid, arg->relpath, arg->info);
            } break;
            case FS_COMMAND_CREATEDIRECTORY: {
                FS_DECLARE_ARGUMENT_(FSArgumentForCreateFile);
                result = arc->vtbl->CreateDirectory(arc, arg->baseid, arg->relpath, arg->permit);
            } break;
            case FS_COMMAND_DELETEDIRECTORY: {
                FS_DECLARE_ARGUMENT_(FSArgumentForDeleteFile);
                result = arc->vtbl->DeleteDirectory(arc, arg->baseid, arg->relpath);
            } break;
            case FS_COMMAND_RENAMEDIRECTORY: {
                FS_DECLARE_ARGUMENT_(FSArgumentForRenameFile);
                result = arc->vtbl->RenameDirectory(arc, arg->baseid_src, arg->relpath_src, arg->baseid_dst, arg->relpath_dst);
            } break;
            case FS_COMMAND_GETARCHIVERESOURCE:
                result = arc->vtbl->GetArchiveResource(arc, ((FSArgumentForGetArchiveResource *)file->argument)->resource);
                break;
            case FS_COMMAND_FLUSHFILE:
                result = arc->vtbl->FlushFile(arc, file);
                break;
            case FS_COMMAND_SETFILELENGTH:
                result = arc->vtbl->SetFileLength(arc, file, ((FSArgumentForSetFileLength *)file->argument)->length);
                break;
            case FS_COMMAND_OPENDIRECTORY: {
                FS_DECLARE_ARGUMENT_(FSArgumentForOpenFile);
                result = arc->vtbl->OpenDirectory(arc, file, arg->baseid, arg->relpath, arg->mode);
            } break;
            case FS_COMMAND_CLOSEDIRECTORY:
                result = arc->vtbl->CloseDirectory(arc, file);
                break;
            case FS_COMMAND_SETSEEKCACHE: {
                FS_DECLARE_ARGUMENT_(FSArgumentForSetSeekCache);
                result = arc->vtbl->SetSeekCache(arc, file, arg->buf, arg->buf_size);
            } break;
            default:
                result = FS_RESULT_UNSUPPORTED;
                break;
            }
        }
    }
    if (!FSi_IsEventCommand(command)) {
        if ((file->stat & FS_FILE_STATUS_BLOCKING) != 0)
            result = FSi_WaitForArchiveCompletion(file, result);
        else if (result != FS_RESULT_PROC_ASYNC)
            FSi_EndCommand(file, result);
    }
    return result;
}














































#define FS_COMMAND_ACTIVATE 9









#define FS_COMMAND_IDLE     10










#define FS_FILE_STATUS_ACTIVE        0x00000040










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
                next->stat |= FS_FILE_STATUS_ACTIVE;
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













































/*
 * sdk:      FSi_ExecuteAsyncCommand (libfs.TWL.HYB.a fs_archive.o)
 */
void func_02077C78(FSFile *file)
{
    FSArchive *const arc = file->arc;

    while (file)
    {
        u32 bak_psr = OS_DisableInterrupts();

        file->stat |= 0x40;
        if ((file->stat & 4) != 0)
        {
            OS_WakeupThread(file->queue);
            file = 0;
        }
        (void)OS_RestoreInterrupts(bak_psr);
        if (!file)
        {
            break;
        }
        if (FSi_InvokeCommand(file, (file->stat >> 8) & 0xFF) == 0x100)
        {
            break;
        }
        file = FSi_NextCommand(arc, 1);
    }
}










static inline u32 FSi_GetCurrentCommand(const FSFile *file)
{
    return (file->stat >> 8) & 0xFF;
}










/*
 * sdk:      FSi_ExecuteSyncCommand (libfs.TWL.HYB.a fs_archive.o)
 */
void func_02077CFC(FSFile *file)
{
    u32 bak_psr = OS_DisableInterrupts();

    while (((file->stat & 0x40) == 0) && ((file->stat & 1) != 0))
    {
        OS_SleepThread(file->queue);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    if ((file->stat & 0x40) != 0)
    {
        FSArchive *const arc = file->arc;
        int result = FSi_InvokeCommand(file, FSi_GetCurrentCommand(file));

        FSi_EndCommand(file, result);
        file = FSi_NextCommand(arc, 1);
        if (file)
        {
            FSi_ExecuteAsyncCommand(file);
        }
    }
}












































#define FS_COMMAND_READFILE        0








#define FS_COMMAND_WRITEFILE       1








#define FS_COMMAND_SEEKDIR         2








#define FS_COMMAND_READDIR         3








#define FS_COMMAND_FINDPATH        4








#define FS_COMMAND_GETPATH         5








#define FS_COMMAND_OPENFILEFAST    6








#define FS_COMMAND_OPENFILEDIRECT  7








#define FS_COMMAND_CLOSEFILE       8












#define FS_COMMAND_SUSPEND         11








#define FS_COMMAND_RESUME          12








#define FS_COMMAND_OPENFILE        13








#define FS_COMMAND_SEEKFILE        14








#define FS_COMMAND_GETFILELENGTH   15








#define FS_COMMAND_GETFILEPOSITION 16








#define FS_COMMAND_MOUNT           17








#define FS_COMMAND_UNMOUNT         18









static inline BOOL FS_IsBusy(volatile const FSFile *file)
{
    return (file->stat & FS_FILE_STATUS_BUSY) ? 1 : 0;
}









BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking)
{
    BOOL retval = 0;
    FSArchive *arc = file->arc;

    if (FS_IsBusy(file)) {
        OS_Terminate();
    }
    if (arc == 0) {
        file->error = FS_RESULT_INVALID_PARAMETER;
        return 0;
    }

    file->error = FS_RESULT_BUSY;
    file->stat &= ~(FS_FILE_STATUS_CMD_MASK << FS_FILE_STATUS_CMD_SHIFT);
    file->stat |= (command << FS_FILE_STATUS_CMD_SHIFT);
    file->stat |= FS_FILE_STATUS_BUSY;
    file->next = 0;
    if (blocking) {
        file->stat |= FS_FILE_STATUS_BLOCKING;
    }

    {
        BOOL owner;
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if ((arc->flag & FS_ARCHIVE_FLAG_UNLOADING) != 0) {
            FSi_EndCommand(file, FS_RESULT_CANCELED);
        } else {
            FSFile **pp;
            for (pp = &arc->list; *pp; pp = &(*pp)->next) {
            }
            *pp = file;
        }
        owner = (arc->list == file) && ((arc->flag & FS_ARCHIVE_FLAG_RUNNING) == 0);
        (void)OS_RestoreInterrupts(bak_psr);

        if (file->error != FS_RESULT_CANCELED) {
            FSFile *next = FSi_NextCommand(arc, owner);
            if (blocking) {
                FSi_ExecuteSyncCommand(file);
                retval = (file->error == FS_RESULT_SUCCESS);
            } else {
                if (next != 0) {
                    FSi_ExecuteAsyncCommand(next);
                }
                retval = 1;
            }
        }
    }
    return retval;
}









static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}









/*
 * sdk:      FS_FindArchive (libfs.TWL.HYB.a fs_archive.o)
 */
FSArchive *func_02077EB8(const char *name, int name_len)
{
    u32 bak_psr = OS_DisableInterrupts();
    FSArchive *arc;

    for (arc = g_02150B0C.list; arc; arc = arc->next)
    {
        if (FS_IsArchiveLoaded(arc))
        {
            const char *arcname = FS_GetArchiveName(arc);

            if ((STD_CompareNString(arcname, name, name_len) == 0) && (arcname[name_len] == 0))
            {
                break;
            }
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return arc;
}











































/*
 * sdk:      FS_SetCurrentDirectory (libfs.TWL.HYB.a fs_archive.o)
 */
BOOL func_02077F44(const char *path)
{
    BOOL retval = 0;
    u32 baseid = 0;
    FSArgumentForFindPath_02077634 arg[1];
    char relpath[260];
    FSFile dir[1];
    FSArchive *arc = FS_NormalizePath(path, &baseid, relpath);

    if (arc)
    {
        g_02150B0C.current_dir_pos.arc = arc;
        g_02150B0C.current_dir_pos.own_id = 0;
        g_02150B0C.current_dir_pos.index = 0;
        g_02150B0C.current_dir_pos.pos = 0;
        (void)STD_CopyLString(current_dir_path, relpath, sizeof(current_dir_path));
        if (arc->vtbl->FindPath)
        {
            FS_InitFile(dir);
            dir->arc = arc;
            dir->argument = arg;
            arg->baseid = baseid;
            arg->path = relpath;
            arg->target_is_directory = 1;
            if (FSi_SendCommand(dir, 4, 1))
            {
                g_02150B0C.current_dir_pos.own_id = (u16)arg->target_id;
                (void)STD_CopyLString(current_dir_path, relpath, sizeof(current_dir_path));
            }
        }
        retval = 1;
    }
    return retval;
}








/*
 * sdk:      FSi_CopySafeString (libfs.TWL.HYB.a fs_archive.o)
 */
int func_02078018(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure)
{
    int i;
    int n = (dstlen - 1 < srclen) ? (dstlen - 1) : srclen;

    for (i = 0; (i < n) && src[i]; ++i)
    {
        dst[i] = src[i];
    }
    if ((i < srclen) && src[i])
    {
        *stickyFailure = 1;
    }
    dst[i] = '\0';
    return i;
}








extern char current_dir_path[260];    /* current_dir_path */
extern const char g_020A84A0[]; /* "/" */

extern int FSi_CopySafeString(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure);
extern int FSi_DecrementSjisPositionToSlash(const char *str, int pos);
extern int FSi_TrimSjisTrailingSlash(char *str);

static inline BOOL FSi_IsSlash(u32 c)
{
    return (c == '/') || (c == '\\');
}

static inline BOOL STD_IsSjisLeadByte(u32 c)
{
    return ((c ^ 0x20) - 0xA1) < 0x3C;
}

static inline BOOL STD_IsSjisTrailByte(int c)
{
    return (c != 0x7F) && ((u8)(c - 0x40) <= 0xBC);
}

static inline BOOL STD_IsSjisCharacter(const char *s)
{
    return STD_IsSjisLeadByte((u8)s[0]) && STD_IsSjisTrailByte(s[1]);
}

FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath)
{
    FSArchive *arc = 0;
    int pathlen = 0;
    BOOL stickyFailure = 0;

    if (g_02150B0C.current_dir_pos.arc == 0) {
        g_02150B0C.current_dir_pos.arc = g_02150B0C.list;
        g_02150B0C.current_dir_pos.own_id = 0;
        g_02150B0C.current_dir_pos.pos = 0;
        g_02150B0C.current_dir_pos.index = 0;
        current_dir_path[0] = '\0';
    }

    if (FSi_IsSlash((u8)*path)) {
        arc = g_02150B0C.current_dir_pos.arc;
        ++path;
        if (baseid) {
            *baseid = 0;
        }
    } else {
        int i;

        for (i = 0;;) {
            u32 c = (u8)path[i];

            if ((c == '\0') || FSi_IsSlash(c)) {
                arc = g_02150B0C.current_dir_pos.arc;
                if (baseid) {
                    *baseid = g_02150B0C.current_dir_pos.own_id;
                }
                if (relpath && (g_02150B0C.current_dir_pos.own_id == 0) && (current_dir_path[0] != '\0')) {
                    pathlen += FSi_CopySafeString(relpath, 0x104, current_dir_path, 0x104, &stickyFailure);
                    pathlen += FSi_CopySafeString(&relpath[pathlen], 0x104 - pathlen, g_020A84A0, 1, &stickyFailure);
                }
                break;
            } else if (c == ':') {
                arc = FS_FindArchive(path, i);
                path += i + 1;
                if (FSi_IsSlash((u8)*path)) {
                    ++path;
                }
                if (baseid) {
                    *baseid = 0;
                }
                break;
            }
            i = i + 1 + STD_IsSjisLeadByte(c);
        }
    }

    if (relpath) {
        int curlen = 0;

        while (!stickyFailure) {
            char c = path[curlen];

            if ((c != '\0') && !FSi_IsSlash((u8)c)) {
                curlen += STD_IsSjisCharacter(&path[curlen]) ? 2 : 1;
            } else {
                if (curlen == 0) {
                } else if ((curlen == 1) && (path[0] == '.')) {
                } else if ((curlen == 2) && (path[0] == '.') && (path[1] == '.')) {
                    if (pathlen > 0) {
                        --pathlen;
                    }
                    pathlen = FSi_DecrementSjisPositionToSlash(relpath, pathlen) + 1;
                } else {
                    pathlen += FSi_CopySafeString(&relpath[pathlen], 0x104 - pathlen, path, curlen, &stickyFailure);
                    if (c != '\0') {
                        pathlen += FSi_CopySafeString(&relpath[pathlen], 0x104 - pathlen, g_020A84A0, 1, &stickyFailure);
                    }
                }
                if (c == '\0') {
                    break;
                }
                path += curlen + 1;
                curlen = 0;
            }
        }
        relpath[pathlen] = '\0';
        pathlen = FSi_TrimSjisTrailingSlash(relpath);
    }

    return stickyFailure ? 0 : arc;
}

#define NULL ((void *)0)


/*
 * sdk:      FS_InitArchive (fs_archive.o)
 */
void FS_InitArchive(FSArchive *p_arc)
{
    MI_CpuFill8(p_arc, 0, sizeof(FSArchive));
    p_arc->queue.head = p_arc->queue.tail = NULL;
}





































/*
 * sdk:      FS_RegisterArchiveName (libfs.TWL.HYB.a fs_archive.o)
 */
BOOL FS_RegisterArchiveName(FSArchive *p_arc, const char *name, u32 name_len)
{
    BOOL retval = 0;
    u32 bak_intr = OS_DisableInterrupts();

    if (!FS_FindArchive(name, (int)name_len))
    {
        FSArchive **pp = &arc_list;
        FSArchive *cur;

        for (cur = fsi_archive_state.list; cur; cur = cur->next)
        {
            pp = &cur->next;
        }
        *pp = p_arc;
        if (name_len <= 3)
        {
            p_arc->name.pack = 0;
            (void)STD_CopyLString(p_arc->name.ptr, name, (int)(name_len + 1));
        }
        else if (name_len <= 15)
        {
            int i;

            for (i = 0;; ++i)
            {
                if (i >= 16)
                {
                    OS_Terminate();
                }
                else if (FSiLongNameTable[i][0] == 0)
                {
                    (void)STD_CopyLString(FSiLongNameTable[i], name, (int)(name_len + 1));
                    p_arc->name.name = FSiLongNameTable[i];
                    break;
                }
            }
        }
        else
        {
            OS_Terminate();
        }
        p_arc->flag |= 1;
        retval = 1;
    }
    (void)OS_RestoreInterrupts(bak_intr);
    return retval;
}






































/*
 * sdk:      FS_ReleaseArchiveName (libfs.TWL.HYB.a fs_archive.o)
 */
void func_02078484(FSArchive *p_arc)
{
    if (p_arc == fsi_archive_state.list)
    {
        OS_Terminate();
    }
    if (p_arc->name.pack)
    {
        FSArchive **pp;
        u32 bak_psr = OS_DisableInterrupts();

        FSArchive *cur;

        pp = &arc_list;
        for (cur = fsi_archive_state.list; cur; cur = *pp)
        {
            if (cur == p_arc)
            {
                *pp = cur->next;
                break;
            }
            pp = &cur->next;
        }
        if (p_arc->name.ptr[3] != '\0')
        {
            *p_arc->name.name = '\0';
        }
        p_arc->name.pack = 0;
        p_arc->next = 0;
        p_arc->flag &= ~1;
        if (fsi_archive_state.current_dir_pos.arc == p_arc)
        {
            fsi_archive_state.current_dir_pos.arc = 0;
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }
}



char *func_02078530(FSArchive *arc)
{
    if (arc->name.ptr[3] != 0) {
        return arc->name.name;
    }
    return arc->name.ptr;
}



/*
 * sdk:      FS_MountArchive (libfs.TWL.HYB.a fs_archive.o)
 */
BOOL func_02078540(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl)
{
    FSFile tmp[1];

    arc->userdata = userdata;
    arc->vtbl = vtbl;
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_InvokeCommand(tmp, 17);
    arc->flag |= 2;
    return 1;
}









































/*
 * sdk:      FS_UnmountArchive (libfs.TWL.HYB.a fs_archive.o)
 */
BOOL func_02078588(FSArchive *arc)
{
    u32 bak_psr = OS_DisableInterrupts();

    if (FS_IsArchiveLoaded(arc))
    {
        BOOL bak_state = FS_SuspendArchive(arc);

        arc->flag |= 0x80;
        {
            FSFile *file = arc->list;

            while (file)
            {
                FSFile *next = file->next;

                FSi_EndCommand(file, 3);
                file = next;
            }
        }
        arc->list = 0;
        if (bak_state)
        {
            (void)FS_ResumeArchive(arc);
        }
        {
            FSFile tmp[1];

            FS_InitFile(tmp);
            tmp->arc = arc;
            (void)FSi_InvokeCommand(tmp, 18);
        }
        arc->flag &= ~(0x80 | 0x20 | 0x02);
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return 1;
}



static inline BOOL FS_IsArchiveSuspended(const FSArchive *arc)
{
    return (arc->flag & 8) ? 1 : 0;
}



/*
 * sdk:      FS_SuspendArchive (libfs.TWL.HYB.a fs_archive.o)
 */
BOOL func_02078648(FSArchive *p_arc)
{
    BOOL retval;
    u32 bak_psr = OS_DisableInterrupts();

    retval = (FS_IsArchiveSuspended(p_arc) == 0);
    if (retval)
    {
        if ((p_arc->flag & 0x10) == 0)
        {
            p_arc->flag |= 8;
        }
        else
        {
            u32 bak_psr2;

            p_arc->flag |= 0x40;
            bak_psr2 = OS_DisableInterrupts();
            while ((p_arc->flag & 0x40) != 0)
            {
                OS_SleepThread(&p_arc->queue);
            }
            (void)OS_RestoreInterrupts(bak_psr2);
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return retval;
}







































/*
 * sdk:      FS_ResumeArchive (libfs.TWL.HYB.a fs_archive.o)
 */
BOOL func_020786D8(FSArchive *arc)
{
    BOOL retval;
    FSFile *file;
    u32 bak_irq = OS_DisableInterrupts();

    retval = (FS_IsArchiveSuspended(arc) == 0);
    if (!retval)
    {
        arc->flag &= ~8;
    }
    (void)OS_RestoreInterrupts(bak_irq);
    file = FSi_NextCommand(arc, 1);
    if (file)
    {
        FSi_ExecuteAsyncCommand(file);
    }
    return retval;
}





































/*
 * sdk:      FS_NotifyArchiveAsyncEnd (libfs.TWL.HYB.a fs_archive.o)
 */
void func_02078734(FSArchive *arc, int ret)
{
    FSFile *file = arc->list;

    if ((file->stat & 4) != 0)
    {
        u32 bak_psr = OS_DisableInterrupts();

        file->stat |= 8;
        file->error = ret;
        OS_WakeupThread(file->queue);
        (void)OS_RestoreInterrupts(bak_psr);
    }
    else
    {
        FSi_EndCommand(file, ret);
        file = FSi_NextCommand(arc, 1);
        if (file)
        {
            FSi_ExecuteAsyncCommand(file);
        }
    }
}
