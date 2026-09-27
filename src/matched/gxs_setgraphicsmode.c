/*
 * function: GXS_SetGraphicsMode
 * address:  0x0207D518
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
 *   ldr r2, [pc, #0x10]   ; 0x04001000
 *   ldr r1, [r2]
 *   bic r1, r1, #7
 *   orr r0, r1, r0
 *   str r0, [r2]
 *   bx  lr
 *   .word 0x04001000
 *
 * Read-modify-write of the low three bits of the sub-engine DISPCNT.  The
 * address does not fit a rotated immediate, so it is pooled.
 */

typedef unsigned int u32;

void GXS_SetGraphicsMode(u32 mode)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~7) | mode;
}
