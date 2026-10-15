/*
 * function: WM_Enable
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
 *   WMi_EnableEx  0x0208F234  arm
 */

extern int WMi_EnableEx(char *path, int formatMedia);

int WM_Enable(char *path)
{
    return WMi_EnableEx(path, 0);
}
