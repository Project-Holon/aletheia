/*
 * function: func_0208F224
 * address:  0x0208F224
 * packet:   pkt_0208F224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FATFS_FormatDrive (libfatfs.TWL.HYB.a fatfs_api.o)
 *
 * symbols:
 *   FATFSi_FormatDriveEx  0x0208F234  arm
 */

extern int func_0208F234(char *path, int formatMedia);

int func_0208F224(char *path)
{
    return func_0208F234(path, 0);
}
