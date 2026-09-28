/*
 * function: SND_SetTrackPitch
 * address:  0x0208941C
 * packet:   pkt_0208941C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020897DC 0x020897DC arm
 */

extern void func_020897DC(void);

asm void SND_SetTrackPitch(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #2
    mov	r2, #0xc
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}
