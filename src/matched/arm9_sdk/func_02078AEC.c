/*
 * function: FS_GetFilePosition
 * address:  0x02078AEC
 * packet:   pkt_02078AEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_GetFilePosition (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   FSi_GetFilePositionIfProc  0x0207A568  arm
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

typedef struct FSArgumentForGetFilePosition
{
    u32 position;
} FSArgumentForGetFilePosition;

extern BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);

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
