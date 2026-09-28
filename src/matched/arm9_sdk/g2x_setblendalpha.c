/*
 * function: G2x_SetBlendAlpha_
 * address:  0x0207D63C
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
 *   ldr ip, [sp]
 *   orr r1, r1, #0x40
 *   orr r2, r1, r2, lsl #8
 *   orr r1, r3, ip, lsl #8
 *   orr r1, r2, r1, lsl #16
 *   str r1, [r0]
 *   bx  lr
 *
 * Blend control word: (a | 0x40) | (b << 8) | (c << 16) | (d << 24).
 */

void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b,
                        unsigned int c, unsigned int d)
{
    *reg = (a | 0x40) | (b << 8) | ((c | (d << 8)) << 16);
}
