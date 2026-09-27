/*
 * function: FSi_ROMFAT_CloseDirectory
 * address:  0x0207A2C8
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
 * Original (24 bytes, no relocation):
 *   ldr r2, [r1, #0xc]
 *   mov r0, #0
 *   bic r2, r2, #0x30
 *   str r0, [r1, #4]
 *   str r2, [r1, #0xc]
 *   bx  lr
 *
 * Clears the directory busy/mode bits and the position word.
 */

typedef unsigned int u32;

int FSi_ROMFAT_CloseDirectory(void *arc, void *file)
{
    u32 *p = (u32 *)file;
    u32 flags = p[3];
    p[1] = 0;
    p[3] = flags & ~0x30;
    return 0;
}
