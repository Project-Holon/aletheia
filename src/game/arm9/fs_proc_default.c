/*
 * file:     fs_proc_default.c
 * unit:     yes
 * function: FSi_ReadTable, FSi_SeekDirDirect, FSi_SeekDirDefault, FSi_ReadDirDefault, FSi_FindPathDefault, FSi_GetPathDefault, FSi_OpenFileFastDefault, FSi_OpenFileDirectDefault, FSi_ReadFileDefault, FSi_WriteFileDefault, FSi_NoOpCommandDefault, FSi_TranslateCommand, FSi_ROMFAT_ReadFile, FSi_ROMFAT_WriteFile, FSi_ROMFAT_SeekDirectory, FSi_ROMFAT_ReadDirectory, FSi_ROMFAT_FindPath, FSi_ROMFAT_GetPath, FSi_ROMFAT_OpenFileFast, FSi_ROMFAT_OpenFileDirect, FSi_ROMFAT_CloseFile, FSi_ROMFAT_Activate, FSi_ROMFAT_Idle, FSi_ROMFAT_Suspend, FSi_ROMFAT_Resume, FSi_ROMFAT_OpenFile, FSi_ROMFAT_SeekFile, FSi_ROMFAT_GetFileLength, FSi_ROMFAT_GetFilePosition, FSi_ROMFAT_Unmount, FSi_ROMFAT_GetArchiveCaps, FSi_ROMFAT_OpenDirectory, FSi_ROMFAT_CloseDirectory, FSi_ROMFAT_GetPathInfo, FSi_ROMFAT_GetArchiveResource, FSi_ReadMemCallback, FSi_WriteMemCallback, FS_LoadArchive, FS_UnloadArchive, FSi_GetFileLengthIfProc, FSi_GetFilePositionIfProc, FS_SetArchiveProc, FS_LoadArchiveTables, FS_UnloadArchiveTables, FS_GetArchiveBase, FS_GetArchiveOffset, FS_IsArchiveTableLoaded
 * address:  0x02079304
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
 *   MI_CpuCopy8                  0x02082D44  arm
 *   FSi_WaitForArchiveCompletion 0x02077700  arm
 *   FSi_IncrementSjisPositionToSlash 0x020787E0  arm
 *   FS_InitFile            0x020788AC  arm
 *   FS_GetArchiveName      0x02078530  arm
 *   STD_GetStringLength    0x0208CC78  arm
 *   fsi_str_colon_slash             0x020A84A8  data
 *   _ZZ20FSi_TranslateCommandP6FSFilemiE13default_table    0x020A1A04  data
 *   FSi_IsUnreadableRomOffset    0x0207A980  arm
 *   MI_CpuFill8                  0x02082BCC  arm
 *   CARD_GetRomHeader            0x02075DEC  arm
 *   FS_MountArchive              0x02078540  arm
 *   FSiArchiveProcInterface      0x020A1A38  data
 *   FS_UnmountArchive  0x02078588  arm
 *   FS_OpenFileDirect            0x02078964  arm
 *   FS_ReadFile                  0x02078B70  arm
 *   FS_CloseFile                 0x02078A80  arm
 *   FS_SuspendArchive            0x02078648  arm
 *   FS_ResumeArchive             0x020786D8  arm
 */
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
#define FS_FILE_STATUS_BLOCKING        0x00000004
#define FS_FILE_STATUS_OPERATION_DONE  0x00000008
#define FS_FILE_STATUS_CMD_SHIFT       8
#define FS_FILE_STATUS_CMD_MASK        0x000000FF
#define TRUE 1
#define FALSE 0
#define FS_FILE_STATUS_IS_DIR 0x00000020
#define FS_FILE_STATUS_IS_FILE 0x00000010
#define FS_ATTRIBUTE_IS_DIRECTORY 0x00000100
#define FS_ATTRIBUTE_IS_OFFLINE   0x00000400
#define FS_ATTRIBUTE_IS_PROTECTED 0x00000200
#define FS_ARCHIVE_FLAG_TABLE_LOAD 0x00000004
#define FS_ARCHIVE_FLAG_LOADED     0x00000002
#define GAME_TYPES_U32_LONG
#define GAME_TYPES_S32_LONG
#include "../types.h"

#include "../sdk_fs.h"

#include "../sdk_os.h"

#include "../sdk_os_thread.h"

typedef struct CARDRomHeader {
    u8 pad[0x80];
    u32 rom_size;
} CARDRomHeader;

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result);
extern int FSi_IncrementSjisPositionToSlash(const char *str, int pos);
extern void FS_InitFile(FSFile *file);
extern char *FS_GetArchiveName(FSArchive *arc);
extern int STD_GetStringLength(const char *str);
extern BOOL FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void *CARD_GetRomHeader(void);
extern BOOL FS_MountArchive(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl, u32 reserved);
extern BOOL FS_UnmountArchive(FSArchive *arc);
extern BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
extern s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
extern BOOL FS_CloseFile(FSFile *file);
extern BOOL FS_SuspendArchive(FSArchive *arc);
extern BOOL FS_ResumeArchive(FSArchive *arc);
FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len);
void FSi_SeekDirDirect(FSFile *file, u32 id);
FSResult FSi_SeekDirDefault(FSFile *file);
FSResult FSi_ReadDirDefault(FSFile *file);
FSResult FSi_GetPathDefault(FSFile *file);
FSResult FSi_OpenFileFastDefault(FSFile *p_file);
FSResult FSi_OpenFileDirectDefault(FSFile *p_file);
FSResult FSi_ReadFileDefault(FSFile *file);
FSResult FSi_WriteFileDefault(FSFile *file);
FSResult FSi_NoOpCommandDefault(FSFile *file);
FSResult FSi_TranslateCommand(FSFile *file, FSCommandType command, BOOL block);
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
FSResult FSi_ROMFAT_SeekFile(FSArchive *arc, FSFile *file, int *offset, FSSeekFileMode from);
int FSi_ROMFAT_GetFileLength(void *arc, void *file, u32 *length);
int FSi_ROMFAT_GetFilePosition(void *arc, void *file, u32 *position);
void FSi_ROMFAT_Unmount(FSArchive *arc);
int FSi_ROMFAT_GetArchiveCaps(void *arc, u32 *caps);
FSResult FSi_ROMFAT_OpenDirectory(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode);
int FSi_ROMFAT_CloseDirectory(void *arc, void *file);
FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info);
FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResource *resource);
FSResult FSi_ReadMemCallback(FSArchive *p_arc, void *dst, u32 pos, u32 size);
FSResult FSi_WriteMemCallback(FSArchive *p_arc, const void *src, u32 pos, u32 size);
BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func);
BOOL FS_UnloadArchive(FSArchive *arc);
BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);
void FS_SetArchiveProc(void *arc, u32 proc, u32 flags);
u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size);
void *FS_UnloadArchiveTables(FSArchive *arc);
void *FS_GetArchiveBase(void *arc);
u32 FS_GetArchiveOffset(void *arc, u32 pos);
int FS_IsArchiveTableLoaded(void *arc);
extern const char fsi_str_colon_slash[];   /* ":/" */
extern const FSROMFATDefaultProc _ZZ20FSi_TranslateCommandP6FSFilemiE13default_table[13];
extern const FSArchiveInterface FSiArchiveProcInterface;

FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len)
{
    FSResult result;
    FSArchive *const arc = p->arc;
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;

    if (context->load_mem != 0) {
        MI_CpuCopy8((const void *)p->pos, dst, len);
        result = FS_RESULT_SUCCESS;
    } else {
        result = (*context->read_func)(arc, dst, p->pos, len);
        result = FSi_WaitForArchiveCompletion(arc->list, result);
    }
    p->pos += len;
    return result;
}

void FSi_SeekDirDirect(FSFile *file, u32 id)
{
    file->arg.seekdir.pos.arc = file->arc;
    file->arg.seekdir.pos.own_id = (unsigned short)id;
    file->arg.seekdir.pos.index = 0;
    file->arg.seekdir.pos.pos = 0;
    (void)FSi_TranslateCommand(file, 2, 1);
}

FSResult FSi_SeekDirDefault(FSFile *file)
{
    FSResult result;
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;
    const FSDirPos *const arg = &file->arg.seekdir.pos;
    FSArchiveFNT fnt;
    FSiSyncReadParam param;

    param.arc = arc;
    param.pos = context->fnt + arg->own_id * sizeof(fnt);
    result = FSi_ReadTable(&param, &fnt, sizeof(fnt));
    if (result == FS_RESULT_SUCCESS) {
        file->prop.dir.pos = *arg;
        if ((arg->index == 0) && (arg->pos == 0)) {
            file->prop.dir.pos.index = fnt.index;
            file->prop.dir.pos.pos = context->fnt + fnt.start;
        }
        file->prop.dir.parent = (u32)(fnt.parent & 0x0FFF);
    }
    return result;
}

FSResult FSi_ReadDirDefault(FSFile *file)
{
    FSResult result;
    FSDirEntry *entry = file->arg.readdir.p_entry;
    u8 len;
    FSiSyncReadParam param;
    u16 id;

    param.arc = file->arc;
    param.pos = file->prop.dir.pos.pos;
    result = FSi_ReadTable(&param, &len, sizeof(len));
    if (result == FS_RESULT_SUCCESS) {
        entry->name_len = (u32)(len & 0x7f);
        entry->is_directory = (u32)((len >> 7) & 1);
        if (entry->name_len == 0) {
            result = FS_RESULT_FAILURE;
        } else {
            if (!file->arg.readdir.skip_string) {
                result = FSi_ReadTable(&param, entry->name, entry->name_len);
                if (result != FS_RESULT_SUCCESS) {
                    return result;
                }
                entry->name[entry->name_len] = 0;
            } else {
                param.pos += entry->name_len;
            }
            if (!entry->is_directory) {
                entry->file_id.arc = file->arc;
                entry->file_id.file_id = file->prop.dir.pos.index;
                ++file->prop.dir.pos.index;
            } else {
                result = FSi_ReadTable(&param, &id, sizeof(id));
                if (result == FS_RESULT_SUCCESS) {
                    entry->dir_id.arc = file->arc;
                    entry->dir_id.own_id = (u16)(id & 0x0FFF);
                    entry->dir_id.index = 0;
                    entry->dir_id.pos = 0;
                }
            }
            if (result == FS_RESULT_SUCCESS) {
                file->prop.dir.pos.pos = param.pos;
            }
        }
    }
    return result;
}

static inline int FSi_StrNICmp(const char *str1, const char *str2, u32 len)
{
    int retval = 0;
    u32 i;

    for (i = 0; i < len; ++i) {
        u32 c = (u8)(str1[i] - 'A');
        u32 d = (u8)(str2[i] - 'A');
        if (c <= 'Z' - 'A') {
            c += 'a' - 'A';
        }
        if (d <= 'Z' - 'A') {
            d += 'a' - 'A';
        }
        retval = (int)(c - d);
        if (retval != 0) {
            break;
        }
    }
    return retval;
}

static FSResult FSi_FindPathDefault(FSFile *p_dir)
{
    const char *path = p_dir->arg.findpath.path;
    BOOL is_dir = p_dir->arg.findpath.find_directory;

    (void)FSi_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);

    while (*path != '\0') {
        int name_len;
        u32 is_directory;
        FSDirEntry etr;

        name_len = FSi_IncrementSjisPositionToSlash(path, 0);
        is_directory = ((path[name_len] != '\0') || is_dir);

        if (name_len == 0) {
            return FS_RESULT_INVALID_PARAMETER;
        }

        if (*path == '.') {
            if (name_len == 1) {
                path += 1;
                goto next;
            } else if ((name_len == 2) && (path[1] == '.')) {
                if (p_dir->prop.dir.pos.own_id != 0) {
                    FSi_SeekDirDirect(p_dir, p_dir->prop.dir.parent);
                }
                path += 2;
                goto next;
            }
        } else if (*path == '*') {
            break;
        }

        if (name_len > 127) {
            return FS_RESULT_NO_ENTRY;
        }

        p_dir->arg.readdir.p_entry = &etr;
        p_dir->arg.readdir.skip_string = FALSE;
        for (;;) {
            if (FSi_TranslateCommand(p_dir, FS_COMMAND_READDIR, TRUE) != FS_RESULT_SUCCESS) {
                return FS_RESULT_NO_ENTRY;
            }
            if ((is_directory == etr.is_directory) && (name_len == etr.name_len)
                && (FSi_StrNICmp(path, etr.name, (u32)name_len) == 0)) {
                break;
            }
        }

        if (is_directory) {
            p_dir->arg.seekdir.pos = etr.dir_id;
            path += name_len;
            (void)FSi_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);
        } else {
            if (is_dir) {
                return FS_RESULT_NO_ENTRY;
            }
            *p_dir->arg.findpath.result.file = etr.file_id;
            return FS_RESULT_SUCCESS;
        }
next:
        path += (*path != '\0');
    }

    if (!is_dir) {
        return FS_RESULT_NO_ENTRY;
    }
    *p_dir->arg.findpath.result.dir = p_dir->prop.dir.pos;
    return FS_RESULT_SUCCESS;
}

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

FSResult FSi_OpenFileFastDefault(FSFile *p_file)
{
    FSResult result;
    FSArchive *const p_arc = p_file->arc;
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)p_arc->userdata;
    const u32 index = p_file->arg.openfilefast.id.file_id;
    const u32 pos = index * sizeof(FSArchiveFAT);
    FSArchiveFAT fat;
    FSiSyncReadParam param;

    if (pos >= context->fat_size) {
        return FS_RESULT_NO_ENTRY;
    }
    param.arc = p_arc;
    param.pos = context->fat + pos;
    result = FSi_ReadTable(&param, &fat, sizeof(fat));
    if (result != FS_RESULT_SUCCESS) {
        return result;
    }
    p_file->arg.openfiledirect.top = fat.top;
    p_file->arg.openfiledirect.bottom = fat.bottom;
    p_file->arg.openfiledirect.index = index;
    return FSi_TranslateCommand(p_file, FS_COMMAND_OPENFILEDIRECT, 1);
}

FSResult FSi_OpenFileDirectDefault(FSFile *p_file)
{
    p_file->prop.file.top = p_file->arg.openfiledirect.top;
    p_file->prop.file.pos = p_file->arg.openfiledirect.top;
    p_file->prop.file.bottom = p_file->arg.openfiledirect.bottom;
    p_file->prop.file.own_id = p_file->arg.openfiledirect.index;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ReadFileDefault(FSFile *file)
{
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;
    const u32 pos = file->prop.file.pos;
    const u32 len = file->arg.readfile.len;
    void *const dst = file->arg.readfile.dst;

    file->prop.file.pos += len;
    return (*context->read_func)(arc, dst, pos, len);
}

FSResult FSi_WriteFileDefault(FSFile *file)
{
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;
    const u32 pos = file->prop.file.pos;
    const u32 len = file->arg.writefile.len;
    const void *const src = file->arg.writefile.src;

    file->prop.file.pos += len;
    return (*context->write_func)(arc, src, pos, len);
}

/* 0x02079BF4: default handler of the two do-nothing commands in default_table\n * (table slots at 0x020A1A24 and 0x020A1A28); it only reports success. */
FSResult FSi_NoOpCommandDefault(FSFile *file)
{
    return FS_RESULT_SUCCESS;
}

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

FSResult FSi_ROMFAT_CloseFile(FSArchive *arc, FSFile *file)
{
    FSResult result = FSi_TranslateCommand(file, FS_COMMAND_CLOSEFILE, 1);
    FS_DetachHandle(file);
    return result;
}

void FSi_ROMFAT_Activate(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_ACTIVATE, 0);
}

void FSi_ROMFAT_Idle(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_IDLE, 0);
}

void FSi_ROMFAT_Suspend(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_SUSPEND, 0);
}

void FSi_ROMFAT_Resume(FSArchive *arc)
{
    FSFile tmp[1];

    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_RESUME, 0);
}

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

FSResult FSi_ROMFAT_SeekFile(FSArchive *arc, FSFile *file, int *offset, FSSeekFileMode from)
{
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    int pos = *offset;

    switch (from) {
    case FS_SEEK_SET:
        pos += prop->file.top;
        break;
    case FS_SEEK_CUR:
    default:
        pos += prop->file.pos;
        break;
    case FS_SEEK_END:
        pos += prop->file.bottom;
        break;
    }
    if ((pos < (int)prop->file.top) || (pos > (int)prop->file.bottom)) {
        return FS_RESULT_INVALID_PARAMETER;
    }
    prop->file.pos = (u32)pos;
    *offset = pos;
    return FS_RESULT_SUCCESS;
}

int FSi_ROMFAT_GetFileLength(void *arc, void *file, u32 *length)
{
    u32 *p = *(u32 **)((char *)file + 4);
    *length = p[2] - p[1];
    return 0;
}

int FSi_ROMFAT_GetFilePosition(void *arc, void *file, u32 *position)
{
    u32 *p = *(u32 **)((char *)file + 4);
    *position = p[3] - p[1];
    return 0;
}

void FSi_ROMFAT_Unmount(FSArchive *arc)
{
    FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;

    (void)FS_IsArchiveTableLoaded(arc);
    context->base = 0;
    context->fat = 0;
    context->fat_size = 0;
    context->fnt = 0;
    context->fnt_size = 0;
    context->fat_bak = 0;
    context->fnt_bak = 0;
}

int FSi_ROMFAT_GetArchiveCaps(void *arc, u32 *caps)
{
    *caps = 0;
    return 0;
}

FSResult FSi_ROMFAT_OpenDirectory(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode)
{
    FSResult result;
    u32 id = 0;

    result = FSi_ROMFAT_FindPath(arc, baseid, path, &id, 1);
    if (result == FS_RESULT_SUCCESS) {
        result = FSi_ROMFAT_SeekDirectory(arc, file, id, 0);
    }
    return result;
}

int FSi_ROMFAT_CloseDirectory(void *arc, void *file)
{
    u32 *p = (u32 *)file;
    u32 flags = p[3];
    p[1] = 0;
    p[3] = flags & ~0x30;
    return 0;
}

FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info)
{
    FSResult result = FS_RESULT_ERROR;
    u32 id = 0;

    MI_CpuFill8(info, 0x00, sizeof(*info));
    if (FSi_ROMFAT_FindPath(arc, baseid, path, &id, 1) == FS_RESULT_SUCCESS) {
        info->attributes = FS_ATTRIBUTE_IS_DIRECTORY;
        info->id = id;
        result = FS_RESULT_SUCCESS;
    } else if (FSi_ROMFAT_FindPath(arc, baseid, path, &id, 0) == FS_RESULT_SUCCESS) {
        info->attributes = 0;
        info->id = id;
        info->filesize = 0;
        {
            FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)arc->userdata;
            const u32 pos = id * sizeof(FSArchiveFAT);
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
        result = FS_RESULT_SUCCESS;
    }
    info->attributes |= FS_ATTRIBUTE_IS_PROTECTED;
    return result;
}

FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResource *resource)
{
    const CARDRomHeader *header = CARD_GetRomHeader();

    resource->bytesPerSector = 0;
    resource->sectorsPerCluster = 0;
    resource->totalClusters = 0;
    resource->availableClusters = 0;
    resource->totalSize = header->rom_size;
    resource->availableSize = 0;
    resource->maxFileHandles = 0x7FFFFFFF;
    resource->currentFileHandles = 0;
    resource->maxDirectoryHandles = 0x7FFFFFFF;
    resource->currentDirectoryHandles = 0;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ReadMemCallback(FSArchive *p_arc, void *dst, u32 pos, u32 size)
{
    MI_CpuCopy8((const void *)FS_GetArchiveOffset(p_arc, pos), dst, size);
    return FS_RESULT_SUCCESS;
}

FSResult FSi_WriteMemCallback(FSArchive *p_arc, const void *src, u32 pos, u32 size)
{
    MI_CpuCopy8(src, (void *)FS_GetArchiveOffset(p_arc, pos), size);
    return FS_RESULT_SUCCESS;
}

BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func)
{
    FSROMFATArchiveContext *context = &arc->context;

    context->base = base;
    context->fat_size = fat_size;
    context->fat_bak = context->fat = fat;
    context->fnt_size = fnt_size;
    context->fnt_bak = context->fnt = fnt;
    context->read_func = read_func ? read_func : FSi_ReadMemCallback;
    context->write_func = write_func ? write_func : (FS_ARCHIVE_WRITE_FUNC)FSi_WriteMemCallback;
    context->load_mem = 0;
    return FS_MountArchive(arc, context, &FSiArchiveProcInterface, 0);
}

BOOL FS_UnloadArchive(FSArchive *arc)
{
    return FS_UnmountArchive(arc);
}

BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length)
{
    return (file->arc->vtbl == &FSiArchiveProcInterface) &&
           (FSi_ROMFAT_GetFileLength(file->arc, file, length) == FS_RESULT_SUCCESS);
}

BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position)
{
    return (file->arc->vtbl == &FSiArchiveProcInterface) &&
           (FSi_ROMFAT_GetFilePosition(file->arc, file, position) == FS_RESULT_SUCCESS);
}

void FS_SetArchiveProc(void *arc, u32 proc, u32 flags)
{
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    *(u32 *)((char *)arc + 0x54) = proc;
    *(u32 *)((char *)arc + 0x58) = flags;
}

u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size)
{
    FSROMFATArchiveContext *context;
    u32 total_size;
    u8 *p_cache;
    FSFile tmp;

    if ((p_mem != 0) && FS_IsArchiveTableLoaded(p_arc)) {
        (void)FS_UnloadArchiveTables(p_arc);
    }
    context = (FSROMFATArchiveContext *)p_arc->userdata;
    total_size = (u32)((context->fat_size + context->fnt_size + 32 + 31) & ~31);
    if (total_size <= max_size) {
        p_cache = (u8 *)(((u32)p_mem + 31) & ~31);
        FS_InitFile(&tmp);
        if (FS_OpenFileDirect(&tmp, p_arc, context->fat, context->fat + context->fat_size, (u32)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (s32)context->fat_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fat_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fat = (u32)p_cache;
        p_cache += context->fat_size;
        if (FS_OpenFileDirect(&tmp, p_arc, context->fnt, context->fnt + context->fnt_size, (u32)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (s32)context->fnt_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fnt_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fnt = (u32)p_cache;
        context->load_mem = p_mem;
        p_arc->flag |= FS_ARCHIVE_FLAG_TABLE_LOAD;
    }
    return total_size;
}

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & FS_ARCHIVE_FLAG_LOADED) ? 1 : 0;
}

void *FS_UnloadArchiveTables(FSArchive *arc)
{
    void *retval = 0;

    if (FS_IsArchiveLoaded(arc)) {
        FSROMFATArchiveContext *const context = (FSROMFATArchiveContext *)arc->userdata;
        BOOL bak_stat = FS_SuspendArchive(arc);
        if (FS_IsArchiveTableLoaded(arc)) {
            arc->flag &= ~FS_ARCHIVE_FLAG_TABLE_LOAD;
            retval = context->load_mem;
            context->fat = context->fat_bak;
            context->fnt = context->fnt_bak;
            context->load_mem = 0;
        }
        if (bak_stat) {
            (void)FS_ResumeArchive(arc);
        }
    }
    return retval;
}

void *FS_GetArchiveBase(void *arc)
{
    u32 **p = (u32 **)((char *)arc + 0x20);
    return (void *)**p;
}

u32 FS_GetArchiveOffset(void *arc, u32 pos)
{
    u32 *p = *(u32 **)((char *)arc + 0x20);
    return *p + pos;
}

int FS_IsArchiveTableLoaded(void *arc)
{
    u32 flag = *(u32 *)((char *)arc + 0x14);
    return (flag & 4) ? 1 : 0;
}
