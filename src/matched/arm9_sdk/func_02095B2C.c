/*
 * function: func_02095B2C
 * address:  0x02095B2C
 * packet:   pkt_02095B2C
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
 *   FATFSi_FormatDriveEx  0x02095AA4  arm
 */

extern int func_02095AA4(char *path, int formatMedia);

int func_02095B2C(char *path)
{
    return func_02095AA4(path, 0);
}
