/*
 * function: FSi_ROMFAT_GetFilePosition
 * address:  0x0207A218
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
 *   ldr r3, [r1, #0xc]
 *   ldr r1, [r1, #4]
 *   sub r1, r3, r1
 *   str r1, [r2]
 *   bx  lr
 */

typedef unsigned int u32;

int FSi_ROMFAT_GetFilePosition(void *arc, void *file, u32 *position)
{
    u32 *p = *(u32 **)((char *)file + 4);
    *position = p[3] - p[1];
    return 0;
}
