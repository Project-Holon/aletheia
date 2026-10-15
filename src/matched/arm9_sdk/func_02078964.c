/*
 * function: FS_OpenFileDirect
 * address:  0x02078964
 * packet:   pkt_02078964
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_OpenFileDirect (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   FSi_SendCommand  0x02077D80  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct FSArchive FSArchive;

typedef struct FSFile
{
    u8 pad[8];
    FSArchive *arc;
    u32 unk0C;
    void *argument;
} FSFile;

typedef struct FSArgumentForOpenFileDirect
{
    u32 id;
    u32 top;
    u32 bottom;
    u32 mode;
} FSArgumentForOpenFileDirect;

extern BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking);

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
