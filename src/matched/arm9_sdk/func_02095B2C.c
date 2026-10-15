/*
 * function: atof
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
 *   strtod  0x02095AA4  arm
 */

typedef unsigned int   u32;
extern unsigned long long strtod(u32 a0, u32 *a1);

int atof(char *path)
{
    return strtod((u32)path, 0);
}
