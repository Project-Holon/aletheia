/*
 * file:     fs_file.c
 * unit:     yes
 * function: func_020787A0, FSi_IncrementSjisPositionToSlash, func_02078834, func_02078868, FS_InitFile, func_020788D8, func_02078964, func_020789A4, func_020789FC, FS_CloseFile, func_02078A94, func_02078AEC, func_02078B44, FS_ReadFile, func_02078BC4, FS_OpenFile, FS_GetLength, FS_ChangeDir
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
 *   func_02077F44  0x02077F44  arm
 *
 * symbols:
 *   FS_NormalizePath  0x02078078  arm
 *   FSi_SendCommand  0x02077D80  arm
 *   func_02077D80 0x02077D80 arm
 *   FSi_GetFileLengthIfProc  0x0207A528  arm
 *   FSi_GetFilePositionIfProc  0x0207A568  arm
 *   func_02077F44  0x02077F44  arm
 */
#define FS_COMMAND_INVALID 35
#define FS_FILE_STATUS_CMD_SHIFT 8
struct FSFile;
typedef unsigned char u8;

typedef unsigned long u32_020787A0;

typedef long s32;

typedef int BOOL;

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

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive FSArchive;

typedef struct FSFile
{
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32_020787A0 stat;
    void *argument;
    FSResult error;
    OSThreadQueue queue[1];
    u8 prop[16];
    u8 arg[24];
} FSFile;

typedef struct FSFileID
{
    FSArchive *arc;
    u32_020787A0 file_id;
} FSFileID;

typedef struct FSArgumentForFindPath
{
    u32_020787A0 baseid;
    const char *path;
    u32_020787A0 target_id;
    BOOL target_is_directory;
} FSArgumentForFindPath;

typedef struct FSArgumentForOpenFileDirect
{
    u32_020787A0 id;
    u32_020787A0 top;
    u32_020787A0 bottom;
    u32_020787A0 mode;
} FSArgumentForOpenFileDirect;

typedef struct FSArgumentForOpenFileFast
{
    u32_020787A0 id;
    u32_020787A0 mode;
} FSArgumentForOpenFileFast;

typedef struct FSArgumentForOpenFile
{
    u32_020787A0 baseid;
    const char *relpath;
    u32_020787A0 mode;
} FSArgumentForOpenFile;

typedef struct FSArgumentForGetFileLength
{
    u32_020787A0 length;
} FSArgumentForGetFileLength;

typedef struct FSArgumentForGetFilePosition
{
    u32_020787A0 position;
} FSArgumentForGetFilePosition;

typedef enum FSSeekFileMode {
    FS_SEEK_SET,
    FS_SEEK_CUR,
    FS_SEEK_END
} FSSeekFileMode;

typedef struct FSArgumentForSeekFile {
    long offset;
    FSSeekFileMode from;
} FSArgumentForSeekFile;

typedef struct FSArgumentForReadFile
{
    void *buffer;
    s32 length;
} FSArgumentForReadFile;

typedef struct FSArgumentForWriteFile
{
    void *buffer;
    s32 length;
} FSArgumentForWriteFile;

typedef unsigned int   u32_02078C28;

extern int FSi_DecrementSjisPosition(const char *str, int pos);
extern int STD_GetStringLength(const char *str);
extern BOOL FSi_SendCommand(FSFile *file, u32_020787A0 command, BOOL blocking);
extern FSArchive *FS_NormalizePath(const char *path, u32_020787A0 *baseid, char *relpath);
extern void func_02077D80(void);
extern BOOL FSi_GetFileLengthIfProc(FSFile *file, u32_020787A0 *length);
extern BOOL FSi_GetFilePositionIfProc(FSFile *file, u32_020787A0 *position);
extern int func_02077F44(const char *path);
int func_020787A0(const char *str, int pos);
int FSi_IncrementSjisPositionToSlash(const char *str, int pos);
int func_02078834(const char *str, int pos);
int func_02078868(char *str);
void FS_InitFile(FSFile *file);
BOOL func_020788D8(FSFileID *p_fileid, const char *path);
BOOL func_02078964(FSFile *file, FSArchive *arc, u32_020787A0 image_top, u32_020787A0 image_bottom, u32_020787A0 id);
BOOL func_020789A4(FSFile *file, FSFileID id);
BOOL func_020789FC(FSFile *file, const char *path, u32_020787A0 mode);
asm void FS_CloseFile(void);
u32_020787A0 func_02078A94(FSFile *file);
u32_020787A0 func_02078AEC(FSFile *file);
int func_02078B44(FSFile *file, long offset, FSSeekFileMode origin);
s32 FS_ReadFile(FSFile *file, void *buffer, s32 length);
s32 func_02078BC4(FSFile *file, void *buffer, s32 length);
BOOL FS_OpenFile(FSFile *file, const char *path);
u32_02078C28 FS_GetLength(struct FSFile *file);
int FS_ChangeDir(const char *path);


static inline BOOL FSi_IsSlash(u32_020787A0 c)
{
    return (c == '/') || (c == 0x5C);
}


static inline BOOL STD_IsSjisLeadByte(u32_020787A0 c)
{
    return ((c ^ 0x20) - 0xA1) < 0x3C;
}


/*
 * sdk:      FSi_DecrementSjisPosition (libfs.TWL.HYB.a fs_file.o)
 */
int func_020787A0(const char *str, int pos)
{
    int prev = pos - 1;

    while ((prev > 0) && STD_IsSjisLeadByte((u32_020787A0)str[prev - 1] & 0xFF))
    {
        --prev;
    }
    return pos - 1 - ((pos - 1 - prev) & 1);
}



int FSi_IncrementSjisPositionToSlash(const char *str, int pos)
{
    while ((str[pos] != '\0') && !FSi_IsSlash((u8)str[pos])) {
        pos = pos + 1 + STD_IsSjisLeadByte((u32_020787A0)str[pos] & 0xFF);
    }
    return pos;
}



/*
 * sdk:      FSi_DecrementSjisPositionToSlash (libfs.TWL.HYB.a fs_file.o)
 */
int func_02078834(const char *str, int pos)
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
int func_02078868(char *str)
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
BOOL func_020788D8(FSFileID *p_fileid, const char *path)
{
    BOOL retval = 0;
    u32_020787A0 baseid = 0;
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
        arg->path = relpath;
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
BOOL func_02078964(FSFile *file, FSArchive *arc, u32_020787A0 image_top, u32_020787A0 image_bottom, u32_020787A0 id)
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
BOOL func_020789A4(FSFile *file, FSFileID id)
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
BOOL func_020789FC(FSFile *file, const char *path, u32_020787A0 mode)
{
    BOOL retval = 0;
    u32_020787A0 baseid = 0;
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



asm void FS_CloseFile(void)
{
    ldr ip, =func_02077D80
    mov	r1, #8
    mov	r2, #1
    bx	ip
}



/*
 * sdk:      FS_GetFileLength (libfs.TWL.HYB.a fs_file.o)
 */
u32_020787A0 func_02078A94(FSFile *file)
{
    u32_020787A0 retval = 0;
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
u32_020787A0 func_02078AEC(FSFile *file)
{
    u32_020787A0 retval = 0;
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
int func_02078B44(FSFile *file, long offset, FSSeekFileMode origin)
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
s32 func_02078BC4(FSFile *file, void *buffer, s32 length)
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
    return func_020789FC(file, path, 1);
}

u32_02078C28 FS_GetLength(struct FSFile *file){ return func_02078A94(file); }


int FS_ChangeDir(const char *path)
{
    return func_02077F44(path);
}
