/*
 * function: SND_SetPlayerTempoRatio
 * address:  0x020893B8
 * packet:   pkt_020893B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020897B4 0x020897B4 arm
 */

extern void func_020897B4(void);

asm void SND_SetPlayerTempoRatio(void)
{
    ldr ip, =func_020897B4
    mov	r2, r1
    mov	r1, #0x1a
    mov	r3, #2
    bx	ip
}
