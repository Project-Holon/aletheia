/*
 * file:     unit_02079304_p04.c
 * unit:     yes
 * function: func_02079CCC, func_02079D10, func_02079D54, func_02079DAC, func_02079ED4, func_02079F60, func_02079FA4, FSi_ROMFAT_OpenFileDirect, func_0207A040, func_0207A070, func_0207A0A4, func_0207A0D8, FSi_ROMFAT_Resume, FSi_ROMFAT_OpenFile
 * address:  0x02079CCC
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
 *   FSi_TranslateCommand         0x02079BFC  arm
 *   MI_CpuCopy8                  0x02082D44  arm
 *   FSi_ReadTable                0x02079304  arm
 *   FSi_IsUnreadableRomOffset    0x0207A980  arm
 *   FS_InitFile                  0x020788AC  arm
 */
struct FSArchive;
struct FSFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef long s32;

typedef unsigned long long u64;

typedef int BOOL;

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef int FSResult;

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

typedef struct FSDateTime {
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;
} FSDateTime;

typedef struct FSDirectoryEntryInfo {
    char shortname[16];
    u32 shortname_length;
    char longname[260];
    u32 longname_length;
    u32 attributes;
    FSDateTime atime;
    FSDateTime mtime;
    FSDateTime ctime;
    u32 filesize;
    u32 id;
} FSDirectoryEntryInfo;

extern FSResult FSi_TranslateCommand(FSFile *file, u32 command, BOOL block);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
extern BOOL FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);
extern void FS_InitFile(FSFile *file);
FSResult FSi_ROMFAT_ReadFile(FSArchive *arc, FSFile *file, void *buffer, u32 *length);
FSResult FSi_ROMFAT_WriteFile(FSArchive *arc, FSFile *file, const void *buffer, u32 *length);
FSResult FSi_ROMFAT_SeekDirectory(FSArchive *arc, FSFile *file, u32 id, u32 position);
FSResult FSi_ROMFAT_ReadDirectory(FSArchive *arc, FSFile *file, FSDirectoryEntryInfo *info);
FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory);
FSResult FSi_ROMFAT_GetPath(FSArchive *arc, FSFile *file, BOOL is_directory, char *buffer, u32 *length);
FSResult FSi_ROMFAT_OpenFileFast(FSArchive *arc, FSFile *file, u32 id, u32 mode);
FSResult FSi_ROMFAT_OpenFileDirect(FSArchive *arc, FSFile *file, u32 top, u32 bottom, u32 *id);
FSResult FSi_ROMFAT_CloseFile(FSArchive *arc, FSFile *file);
void FSi_ROMFAT_Activate(FSArchive *arc);
void FSi_ROMFAT_Idle(FSArchive *arc);
void FSi_ROMFAT_Suspend(FSArchive *arc);
void FSi_ROMFAT_Resume(FSArchive *arc);
FSResult FSi_ROMFAT_OpenFile(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode);







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








FSResult FSi_ROMFAT_ReadFile(FSArchive *arc, FSFile *file, void *buffer, u32 *length)
{
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    const u32 rest = prop->file.bottom - prop->file.pos;
    const u32 org = *length;

    if (org > rest) {
        *length = rest;
    }
    file->arg.readfile.dst = buffer;
    file->arg.readfile.len_org = org;
    file->arg.readfile.len = *length;
    return FSi_TranslateCommand(file, FS_COMMAND_READFILE, 0);
}







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








FSResult FSi_ROMFAT_WriteFile(FSArchive *arc, FSFile *file, const void *buffer, u32 *length)
{
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    const u32 rest = prop->file.bottom - prop->file.pos;
    const u32 org = *length;

    if (org > rest) {
        *length = rest;
    }
    file->arg.writefile.src = buffer;
    file->arg.writefile.len_org = org;
    file->arg.writefile.len = *length;
    return FSi_TranslateCommand(file, FS_COMMAND_WRITEFILE, 0);
}







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








#define FS_FILE_STATUS_IS_FILE 0x00000010







#define FS_FILE_STATUS_IS_DIR  0x00000020








static inline void FS_SetFileHandle(FSFile *file, FSArchive *arc, void *userdata)
{
    file->stat |= FS_FILE_STATUS_IS_FILE;
    file->stat &= ~FS_FILE_STATUS_IS_DIR;
    file->arc = arc;
    file->userdata = userdata;
}








static inline void FS_SetDirectoryHandle(FSFile *file, FSArchive *arc, void *userdata)
{
    file->stat |= FS_FILE_STATUS_IS_DIR;
    file->stat &= ~FS_FILE_STATUS_IS_FILE;
    file->arc = arc;
    file->userdata = userdata;
}








static inline void FS_DetachHandle(FSFile *file)
{
    file->userdata = 0;
    file->stat &= ~(FS_FILE_STATUS_IS_FILE | FS_FILE_STATUS_IS_DIR);
}








FSResult FSi_ROMFAT_SeekDirectory(FSArchive *arc, FSFile *file, u32 id, u32 position)
{
    FSResult result;
    FSROMFATCommandInfo *arg = &file->arg;

    file->arc = arc;
    arg->seekdir.pos.arc = arc;
    arg->seekdir.pos.own_id = (u16)(id >> 0);
    arg->seekdir.pos.index = (u16)(id >> 16);
    arg->seekdir.pos.pos = position;
    result = FSi_TranslateCommand(file, FS_COMMAND_SEEKDIR, 1);
    if (result == FS_RESULT_SUCCESS) {
        FS_SetDirectoryHandle(file, arc, &file->prop);
    }
    return result;
}







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








#define FS_ATTRIBUTE_IS_DIRECTORY 0x00000100







#define FS_ATTRIBUTE_IS_OFFLINE   0x00000400








FSResult FSi_ROMFAT_ReadDirectory(FSArchive *arc, FSFile *file, FSDirectoryEntryInfo *info)
{
    FSResult result;
    FSDirEntry entry[1];

    {
        FSROMFATCommandInfo *arg = &file->arg;
        arg->readdir.p_entry = entry;
        arg->readdir.skip_string = 0;
        result = FSi_TranslateCommand(file, FS_COMMAND_READDIR, 1);
    }
    if (result == FS_RESULT_SUCCESS) {
        info->shortname_length = 0;
        info->longname_length = entry->name_len;
        MI_CpuCopy8(entry->name, info->longname, info->longname_length);
        info->longname[info->longname_length] = 0;
        if (entry->is_directory) {
            info->attributes = FS_ATTRIBUTE_IS_DIRECTORY;
            info->id = (u32)(entry->dir_id.own_id | (entry->dir_id.index << 16));
            info->filesize = 0;
        } else {
            info->attributes = 0;
            info->id = entry->file_id.file_id;
            info->filesize = 0;
            {
                FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)arc->userdata;
                const u32 pos = info->id * sizeof(FSArchiveFAT);
                if (pos < context->fat_size) {
                    FSArchiveFAT fat;
                    FSiSyncReadParam param;
                    param.arc = arc;
                    param.pos = context->fat + pos;
                    if (FSi_ReadTable(&param, &fat, sizeof(fat)) == FS_RESULT_SUCCESS) {
                        info->filesize = fat.bottom - fat.top;
                        if (FSi_IsUnreadableRomOffset(arc, fat.top)) {
                            info->attributes |= FS_ATTRIBUTE_IS_OFFLINE;
                        }
                    }
                }
            }
        }
        info->mtime.year = 0;
        info->mtime.month = 0;
        info->mtime.day = 0;
        info->mtime.hour = 0;
        info->mtime.minute = 0;
        info->mtime.second = 0;
    }
    return result;
}







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory)
{
    FSResult result;
    union {
        FSFileID file;
        FSDirPos dir;
    } id;
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    tmp->arg.findpath.pos.arc = arc;
    tmp->arg.findpath.pos.own_id = (u16)base_dir_id;
    tmp->arg.findpath.pos.index = 0;
    tmp->arg.findpath.pos.pos = 0;
    tmp->arg.findpath.path = path;
    tmp->arg.findpath.find_directory = target_is_directory;
    tmp->arg.findpath.result.file = &id.file;
    result = FSi_TranslateCommand(tmp, FS_COMMAND_FINDPATH, 1);
    if (result == FS_RESULT_SUCCESS) {
        if (target_is_directory) {
            *target_id = id.dir.own_id;
        } else {
            *target_id = id.file.file_id;
        }
    }
    return result;
}







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








FSResult FSi_ROMFAT_GetPath(FSArchive *arc, FSFile *file, BOOL is_directory, char *buffer, u32 *length)
{
    FSResult result;
    FSROMFATCommandInfo *arg = &file->arg;

    arg->getpath.total_len = 0;
    arg->getpath.dir_id = 0;
    arg->getpath.buf = (u8 *)buffer;
    arg->getpath.buf_len = *length;
    result = FSi_TranslateCommand(file, FS_COMMAND_GETPATH, 1);
    if (result == FS_RESULT_SUCCESS) {
        *length = arg->getpath.buf_len;
    }
    return result;
}







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







#define FS_RESULT_PROC_ASYNC         256







#define FS_RESULT_PROC_DEFAULT       257







#define FS_RESULT_PROC_UNKNOWN       258








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








#define FS_FILE_STATUS_IS_FILE 0x00000010







#define FS_FILE_STATUS_IS_DIR  0x00000020








FSResult FSi_ROMFAT_OpenFileFast(FSArchive *arc, FSFile *file, u32 id, u32 mode)
{
    FSResult result;
    FSROMFATCommandInfo *arg = &file->arg;

    arg->openfilefast.id.arc = arc;
    arg->openfilefast.id.file_id = id;
    result = FSi_TranslateCommand(file, FS_COMMAND_OPENFILEFAST, 1);
    if (result == FS_RESULT_SUCCESS) {
        FS_SetFileHandle(file, arc, &file->prop);
    }
    return result;
}





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





#define FS_RESULT_PROC_ASYNC         256





#define FS_RESULT_PROC_DEFAULT       257





#define FS_RESULT_PROC_UNKNOWN       258






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






#define FS_FILE_STATUS_IS_FILE 0x00000010





#define FS_FILE_STATUS_IS_DIR  0x00000020






FSResult FSi_ROMFAT_OpenFileDirect(FSArchive *arc, FSFile *file, u32 top, u32 bottom, u32 *id)
{
    FSResult result;
    FSROMFATCommandInfo *arg = &file->arg;

    arg->openfiledirect.top = top;
    arg->openfiledirect.bottom = bottom;
    arg->openfiledirect.index = *id;
    result = FSi_TranslateCommand(file, FS_COMMAND_OPENFILEDIRECT, 1);
    if (result == FS_RESULT_SUCCESS) {
        FS_SetFileHandle(file, arc, &file->prop);
    }
    return result;
}





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





#define FS_RESULT_PROC_ASYNC         256





#define FS_RESULT_PROC_DEFAULT       257





#define FS_RESULT_PROC_UNKNOWN       258






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






#define FS_FILE_STATUS_IS_FILE 0x00000010





#define FS_FILE_STATUS_IS_DIR  0x00000020






FSResult FSi_ROMFAT_CloseFile(FSArchive *arc, FSFile *file)
{
    FSResult result = FSi_TranslateCommand(file, FS_COMMAND_CLOSEFILE, 1);
    FS_DetachHandle(file);
    return result;
}





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





#define FS_RESULT_PROC_ASYNC         256





#define FS_RESULT_PROC_DEFAULT       257





#define FS_RESULT_PROC_UNKNOWN       258






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






void FSi_ROMFAT_Activate(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_ACTIVATE, 0);
}




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




#define FS_RESULT_PROC_ASYNC         256




#define FS_RESULT_PROC_DEFAULT       257




#define FS_RESULT_PROC_UNKNOWN       258





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





void FSi_ROMFAT_Idle(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_IDLE, 0);
}




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




#define FS_RESULT_PROC_ASYNC         256




#define FS_RESULT_PROC_DEFAULT       257




#define FS_RESULT_PROC_UNKNOWN       258





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





void FSi_ROMFAT_Suspend(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_SUSPEND, 0);
}


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


#define FS_RESULT_PROC_ASYNC         256


#define FS_RESULT_PROC_DEFAULT       257


#define FS_RESULT_PROC_UNKNOWN       258



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



void FSi_ROMFAT_Resume(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_RESUME, 0);
}

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

#define FS_RESULT_PROC_ASYNC         256

#define FS_RESULT_PROC_DEFAULT       257

#define FS_RESULT_PROC_UNKNOWN       258


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


FSResult FSi_ROMFAT_OpenFile(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode)
{
    FSResult result;
    u32 fileid;

    result = FSi_ROMFAT_FindPath(arc, baseid, path, &fileid, 0);
    if (result == FS_RESULT_SUCCESS) {
        result = FSi_ROMFAT_OpenFileFast(arc, file, fileid, mode);
    }
    return result;
}
