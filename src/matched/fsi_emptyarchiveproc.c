/*
 * function: FSi_EmptyArchiveProc
 * address:  0x0207AAE4
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
 * Original (20 bytes, no relocation):
 *   mov   r0, #4
 *   cmp   r1, #1
 *   ldrne r0, [pc]
 *   bx    lr
 *   .word 0x102
 *
 * One command answers 4, everything else the error code 0x102.
 */

typedef unsigned int u32;

u32 FSi_EmptyArchiveProc(void *arc, u32 cmd)
{
    return (cmd == 1) ? 4 : 0x102;
}
