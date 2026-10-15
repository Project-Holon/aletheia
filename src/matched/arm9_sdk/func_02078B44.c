/*
 * function: FS_SeekFile
 * address:  0x02078B44
 * packet:   pkt_02078B44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_SeekFile (fs_file.o)
 *
 * symbols:
 *   FSi_SendCommand                  0x02077d80 arm
 */

typedef enum FSSeekFileMode {
    FS_SEEK_SET,
    FS_SEEK_CUR,
    FS_SEEK_END
} FSSeekFileMode;

typedef struct FSArgumentForSeekFile {
    long offset;
    FSSeekFileMode from;
} FSArgumentForSeekFile;

typedef struct FSFile {
    unsigned char head[0x10];
    void *argument;
} FSFile;

extern int FSi_SendCommand(FSFile *file, unsigned long command, int blocking);

int FS_SeekFile(FSFile *file, long offset, FSSeekFileMode origin)
{
    FSArgumentForSeekFile arg[1];
    int retval;

    file->argument = arg;
    arg->offset = offset;
    arg->from = origin;
    retval = FSi_SendCommand(file, 14, 1);
    return retval;
}
