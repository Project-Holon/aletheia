/*
 * function: func_02078B44
 * address:  0x02078B44
 * packet:   pkt_02078B44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: FS_SeekFile (TwlSDK libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   FSi_SendCommand   0x02077D80  arm
 */

typedef int BOOL;
typedef unsigned char u8;
typedef long s32;

typedef struct FSFile
{
    u8 pad[0x10];
    void *argument;
} FSFile;

typedef struct FSArgumentForSeekFile
{
    s32 offset;
    int from;
} FSArgumentForSeekFile;

extern BOOL FSi_SendCommand(FSFile *file, int command, BOOL blocking);

BOOL func_02078B44(FSFile *file, s32 offset, int origin)
{
    FSArgumentForSeekFile arg[1];

    file->argument = arg;
    arg->offset = (int)offset;
    arg->from = origin;
    return FSi_SendCommand(file, 0xe, 1);
}
