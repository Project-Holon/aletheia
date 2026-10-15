/*
 * function: FS_IsAvailable
 * address:  0x0207AD30
 * packet:   pkt_0207AD30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_IsAvailable (libfs.TWL.HYB.a fs_api.o)
 *
 * symbols:
 *   is_init  0x02150E04  data
 */

extern int is_init;

int FS_IsAvailable(void)
{
    return is_init;
}
