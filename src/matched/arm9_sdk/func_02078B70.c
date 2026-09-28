/*
 * function: func_02078B70
 * address:  0x02078B70
 * packet:   pkt_02078B70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_ReadFile (libfs.TWL.HYB.a fs_file.o)
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

typedef struct FSArgumentForReadFile
{
    void *buffer;
    s32 length;
} FSArgumentForReadFile;

s32 func_02078B70(FSFile *file, void *buffer, s32 length)
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
