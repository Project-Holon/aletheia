/*
 * function: FSi_ROMFAT_GetFileLength
 * address:  0x0207A1FC
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
 * Original (28 bytes, no relocation):
 *   ldr r1, [r1, #4]
 *   mov r0, #0
 *   ldr r3, [r1, #8]
 *   ldr r1, [r1, #4]
 *   sub r1, r3, r1
 *   str r1, [r2]
 *   bx  lr
 *
 * The file's descriptor pointer at +4 addresses a record whose [2] and [1]
 * words bracket the file length.
 */

typedef unsigned int u32;

int FSi_ROMFAT_GetFileLength(void *arc, void *file, u32 *length)
{
    u32 *p = *(u32 **)((char *)file + 4);
    *length = p[2] - p[1];
    return 0;
}
