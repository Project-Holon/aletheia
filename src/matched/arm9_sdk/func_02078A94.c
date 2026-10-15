/*
 * function: FS_GetFileLength
 * address:  0x02078A94
 * packet:   pkt_02078A94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_GetFileLength (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   FSi_GetFileLengthIfProc  0x0207A528  arm
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

typedef struct FSArgumentForGetFileLength
{
    u32 length;
} FSArgumentForGetFileLength;

extern BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);

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
