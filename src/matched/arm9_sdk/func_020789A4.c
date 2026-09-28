/*
 * function: func_020789A4
 * address:  0x020789A4
 * packet:   pkt_020789A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_OpenFileFast (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
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

typedef struct FSArgumentForOpenFileFast
{
    u32 id;
    u32 mode;
} FSArgumentForOpenFileFast;

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
