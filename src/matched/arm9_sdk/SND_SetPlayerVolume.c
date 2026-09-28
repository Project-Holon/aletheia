/*
 * function: SND_SetPlayerVolume
 * address:  0x020893D0
 * packet:   pkt_020893D0
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

asm void SND_SetPlayerVolume(void)
{
    ldr ip, =func_020897B4
    mov	r2, r1
    mov	r1, #6
    mov	r3, #2
    bx	ip
}
