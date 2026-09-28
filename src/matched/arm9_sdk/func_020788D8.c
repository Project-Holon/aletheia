/*
 * function: func_020788D8
 * address:  0x020788D8
 * packet:   pkt_020788D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_ConvertPathToFileID (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   FS_NormalizePath  0x02078078  arm
 *   FS_InitFile  0x020788AC  arm
 *   FSi_SendCommand  0x02077D80  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

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
    u32 stat;
    void *argument;
    int error;
    OSThreadQueue queue[1];
    u8 prop[16];
    u8 arg[24];
} FSFile;

extern BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking);

typedef struct FSFileID
{
    FSArchive *arc;
    u32 file_id;
} FSFileID;

typedef struct FSArgumentForFindPath
{
    u32 baseid;
    const char *path;
    u32 target_id;
    BOOL target_is_directory;
} FSArgumentForFindPath;

extern FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
extern void FS_InitFile(FSFile *file);

BOOL func_020788D8(FSFileID *p_fileid, const char *path)
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
