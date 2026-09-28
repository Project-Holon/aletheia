/*
 * function: FSi_ROMFAT_GetArchiveCaps
 * address:  0x0207A264
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (12 bytes, no relocation):
 *   mov r0, #0
 *   str r0, [r1]
 *   bx  lr
 *
 * The caller passes the destination pointer in r1; the return value is 0.
 */

typedef unsigned int u32;

int FSi_ROMFAT_GetArchiveCaps(void *arc, u32 *caps)
{
    *caps = 0;
    return 0;
}
