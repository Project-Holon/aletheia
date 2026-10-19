/*
 * file:     fs_file.c
 * unit:     yes
 * function: FSi_DecrementSjisPosition, FSi_IncrementSjisPositionToSlash, FSi_DecrementSjisPositionToSlash, FSi_TrimSjisTrailingSlash, FS_InitFile, FS_ConvertPathToFileID, FS_OpenFileDirect, FS_OpenFileFast, FS_OpenFileEx, FS_CloseFile, FS_GetFileLength, FS_GetFilePosition, FS_SeekFile, FS_ReadFile, FS_WriteFile, FS_OpenFile, FS_GetLength, FS_ChangeDir
 * address:  0x020787A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 *   FS_SetCurrentDirectory  0x02077F44  arm
 *
 * symbols:
 *   FS_NormalizePath  0x02078078  arm
 *   FSi_SendCommand  0x02077D80  arm
 *   FSi_SendCommand 0x02077D80 arm
 *   FSi_GetFileLengthIfProc  0x0207A528  arm
 *   FSi_GetFilePositionIfProc  0x0207A568  arm
 *   FS_SetCurrentDirectory  0x02077F44  arm
 */
#define FS_COMMAND_INVALID 35
#define FS_FILE_STATUS_CMD_SHIFT 8
#include "../types.h"

#include "../sdk_fs.h"

extern int FSi_DecrementSjisPosition(const char *str, int pos);
extern int STD_GetStringLength(const char *str);
extern BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking);
extern FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
extern BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
extern BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);
extern int FS_SetCurrentDirectory(const char *path);
int FSi_IncrementSjisPositionToSlash(const char *str, int pos);
int FSi_DecrementSjisPositionToSlash(const char *str, int pos);
int FSi_TrimSjisTrailingSlash(char *str);
void FS_InitFile(FSFile *file);
BOOL FS_ConvertPathToFileID(FSFileID *p_fileid, const char *path);
BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
BOOL FS_OpenFileFast(FSFile *file, FSFileID id);
BOOL FS_OpenFileEx(FSFile *file, const char *path, u32 mode);
BOOL FS_CloseFile(FSFile *file);
u32 FS_GetFileLength(FSFile *file);
u32 FS_GetFilePosition(FSFile *file);
int FS_SeekFile(FSFile *file, long offset, FSSeekFileMode origin);
s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
s32 FS_WriteFile(FSFile *file, void *buffer, s32 length);
BOOL FS_OpenFile(FSFile *file, const char *path);
u32 FS_GetLength(struct FSFile *file);
int FS_ChangeDir(const char *path);

static inline BOOL FSi_IsSlash(u32 c)
{
    return (c == '/') || (c == 0x5C);
}

static inline BOOL STD_IsSjisLeadByte(u32 c)
{
    return ((c ^ 0x20) - 0xA1) < 0x3C;
}

/*
 * sdk:      FSi_DecrementSjisPosition (libfs.TWL.HYB.a fs_file.o)
 */
int FSi_DecrementSjisPosition(const char *str, int pos)
{
    int prev = pos - 1;

    while ((prev > 0) && STD_IsSjisLeadByte((u32)str[prev - 1] & 0xFF))
    {
        --prev;
    }
    return pos - 1 - ((pos - 1 - prev) & 1);
}

int FSi_IncrementSjisPositionToSlash(const char *str, int pos)
{
    while ((str[pos] != '\0') && !FSi_IsSlash((u8)str[pos])) {
        pos = pos + 1 + STD_IsSjisLeadByte((u32)str[pos] & 0xFF);
    }
    return pos;
}

/*
 * sdk:      FSi_DecrementSjisPositionToSlash (libfs.TWL.HYB.a fs_file.o)
 */
int FSi_DecrementSjisPositionToSlash(const char *str, int pos)
{
    for (;;)
    {
        pos = FSi_DecrementSjisPosition(str, pos);
        if ((pos < 0) || ((unsigned char)str[pos] == '/') || ((unsigned char)str[pos] == 0x5C))
        {
            break;
        }
    }
    return pos;
}

/*
 * sdk:      FSi_TrimSjisTrailingSlash (libfs.TWL.HYB.a fs_file.o)
 */
int FSi_TrimSjisTrailingSlash(char *str)
{
    int length = STD_GetStringLength(str);
    int lastpos = FSi_DecrementSjisPosition(str, length);

    if ((lastpos >= 0) && (((unsigned char)str[lastpos] == '/') || ((unsigned char)str[lastpos] == 0x5C)))
    {
        length = lastpos;
        str[length] = '\0';
    }
    return length;
}

void FS_InitFile(FSFile *file)
{
    file->arc = 0;
    file->userdata = 0;
    file->next = 0;
    file->queue->head = file->queue->tail = 0;
    file->stat = 0;
    file->stat |= (FS_COMMAND_INVALID << FS_FILE_STATUS_CMD_SHIFT);
    file->argument = 0;
    file->error = FS_RESULT_SUCCESS;
}

/*
 * sdk:      FS_ConvertPathToFileID (libfs.TWL.HYB.a fs_file.o)
 */
BOOL FS_ConvertPathToFileID(FSFileID *p_fileid, const char *path)
{
    BOOL retval = 0;
    u32 baseid = 0;
    FSArgumentForFindPath arg[1];
    char relpath[278];
    FSFile file[1];
    FSArchive *arc = FS_NormalizePath(path, &baseid, relpath);

    if (arc)
    {
        FS_InitFile(file);
        file->arc = arc;
        file->argument = arg;
        arg->baseid = baseid;
        arg->relpath = relpath;
        arg->target_is_directory = 0;
        if (FSi_SendCommand(file, 4, 1))
        {
            p_fileid->arc = arc;
            p_fileid->file_id = arg->target_id;
            retval = 1;
        }
    }
    return retval;
}

/*
 * sdk:      FS_OpenFileDirect (libfs.TWL.HYB.a fs_file.o)
 */
BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id)
{
    BOOL retval;
    FSArgumentForOpenFileDirect arg[1];

    file->arc = arc;
    file->argument = arg;
    arg->id = id;
    arg->top = image_top;
    arg->bottom = image_bottom;
    arg->mode = 0;
    retval = FSi_SendCommand(file, 7, 1);
    return retval;
}

/*
 * sdk:      FS_OpenFileFast (libfs.TWL.HYB.a fs_file.o)
 */
BOOL FS_OpenFileFast(FSFile *file, FSFileID id)
{
    BOOL retval = 0;

    if (id.arc)
    {
        FSArgumentForOpenFileFast arg[1];

        file->arc = id.arc;
        file->argument = arg;
        arg->id = id.file_id;
        arg->mode = 0;
        retval = FSi_SendCommand(file, 6, 1);
    }
    return retval;
}

/*
 * sdk:      FS_OpenFileEx (libfs.TWL.HYB.a fs_file.o)
 */
BOOL FS_OpenFileEx(FSFile *file, const char *path, u32 mode)
{
    BOOL retval = 0;
    u32 baseid = 0;
    FSArgumentForOpenFile arg[1];
    char relpath[278];
    FSArchive *arc = FS_NormalizePath(path, &baseid, relpath);

    if (arc)
    {
        FS_InitFile(file);
        file->argument = arg;
        file->arc = arc;
        arg->baseid = baseid;
        arg->relpath = relpath;
        arg->mode = mode;
        if (FSi_SendCommand(file, 13, 1))
        {
            retval = 1;
        }
        else
        {
            file->arc = 0;
        }
    }
    return retval;
}

BOOL FS_CloseFile(FSFile *file)
{
    return FSi_SendCommand(file, 8, 1);
}

/*
 * sdk:      FS_GetFileLength (libfs.TWL.HYB.a fs_file.o)
 */
u32 FS_GetFileLength(FSFile *file)
{
    u32 retval = 0;
    FSArgumentForGetFileLength arg[1];

    if (!FSi_GetFileLengthIfProc(file, &retval))
    {
        file->argument = arg;
        arg->length = 0;
        if (FSi_SendCommand(file, 15, 1))
        {
            retval = arg->length;
        }
    }
    return retval;
}

/*
 * sdk:      FS_GetFilePosition (libfs.TWL.HYB.a fs_file.o)
 */
u32 FS_GetFilePosition(FSFile *file)
{
    u32 retval = 0;
    FSArgumentForGetFilePosition arg[1];

    if (!FSi_GetFilePositionIfProc(file, &retval))
    {
        file->argument = arg;
        arg->position = 0;
        if (FSi_SendCommand(file, 16, 1))
        {
            retval = arg->position;
        }
    }
    return retval;
}

/*
 * sdk:      FS_SeekFile (fs_file.o)
 */
int FS_SeekFile(FSFile *file, long offset, FSSeekFileMode origin)
{
    FSArgumentForSeekFile arg[1];
    int retval;

    file->argument = arg;
    arg->offset = offset;
    arg->from = origin;
    retval = FSi_SendCommand(file, 14, 1);
    return retval;
}

/*
 * sdk:      FS_ReadFile (libfs.TWL.HYB.a fs_file.o)
 */
s32 FS_ReadFile(FSFile *file, void *buffer, s32 length)
{
    FSArgumentForReadFile arg[1];

    file->argument = arg;
    arg->buffer = buffer;
    arg->length = length;
    if (FSi_SendCommand(file, 0, 1))
    {
        length = arg->length;
    }
    else if (file->error == 6)
    {
        length = -1;
    }
    else
    {
        length = arg->length;
    }
    return length;
}

/*
 * sdk:      FS_WriteFile (libfs.TWL.HYB.a fs_file.o)
 */
s32 FS_WriteFile(FSFile *file, void *buffer, s32 length)
{
    FSArgumentForWriteFile arg[1];

    file->argument = arg;
    arg->buffer = buffer;
    arg->length = length;
    if (FSi_SendCommand(file, 1, 1))
    {
        length = arg->length;
    }
    else if (file->error == 6)
    {
        length = -1;
    }
    else
    {
        length = arg->length;
    }
    return length;
}

BOOL FS_OpenFile(FSFile *file, const char *path)
{
    return FS_OpenFileEx(file, path, 1);
}

u32 FS_GetLength(struct FSFile *file){ return FS_GetFileLength(file); }

int FS_ChangeDir(const char *path)
{
    return FS_SetCurrentDirectory(path);
}
