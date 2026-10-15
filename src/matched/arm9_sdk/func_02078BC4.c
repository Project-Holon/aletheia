/*
 * function: FS_WriteFile
 * address:  0x02078BC4
 * packet:   pkt_02078BC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_WriteFile (libfs.TWL.HYB.a fs_file.o)
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

typedef struct FSArgumentForWriteFile
{
    void *buffer;
    s32 length;
} FSArgumentForWriteFile;

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
