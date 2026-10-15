/*
 * function: FS_OpenFileEx
 * address:  0x020789FC
 * packet:   pkt_020789FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_OpenFileEx (libfs.TWL.HYB.a fs_file.o)
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

typedef struct FSArgumentForOpenFile
{
    u32 baseid;
    const char *relpath;
    u32 mode;
} FSArgumentForOpenFile;

extern FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
extern void FS_InitFile(FSFile *file);

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
