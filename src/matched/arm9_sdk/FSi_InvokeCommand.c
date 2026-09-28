/*
 * function: FSi_InvokeCommand
 * address:  0x02077758
 * packet:   pkt_02077758
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_archive.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: dispatches one command through the archive's
 * procedure table, then completes it (wait when blocking, else end the
 * command unless it went asynchronous).  The six event commands return
 * FS_RESULT_SUCCESS from their own arms and skip the completion step.
 *
 * symbols:
 *   FSi_IsEventCommand            0x02077634  arm
 *   FSi_WaitForArchiveCompletion  0x02077700  arm
 *   FSi_EndCommand                0x0207765C  arm
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
    const struct FSArchiveInterface *vtbl;
} FSArchive;

typedef enum FSSeekFileMode {
    FS_SEEK_SET,
    FS_SEEK_CUR,
    FS_SEEK_END
} FSSeekFileMode;

typedef struct FSDirectoryEntryInfo FSDirectoryEntryInfo;
typedef struct FSPathInfo FSPathInfo;
typedef struct FSArchiveResource FSArchiveResource;

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
    FS_COMMAND_MAX
};

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

typedef struct FSArgumentForReadFile { void *buffer; u32 length; } FSArgumentForReadFile;
typedef struct FSArgumentForWriteFile { const void *buffer; u32 length; } FSArgumentForWriteFile;
typedef struct FSArgumentForSeekDirectory { u32 id; u32 position; } FSArgumentForSeekDirectory;
typedef struct FSArgumentForReadDirectory { FSDirectoryEntryInfo *info; } FSArgumentForReadDirectory;
typedef struct FSArgumentForFindPath { u32 baseid; const char *relpath; u32 target_id; BOOL target_is_directory; } FSArgumentForFindPath;
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

extern BOOL FSi_IsEventCommand(FSCommandType command);
extern FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result);
extern void FSi_EndCommand(FSFile *file, FSResult ret);

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
                FS_DECLARE_ARGUMENT_(FSArgumentForFindPath);
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
