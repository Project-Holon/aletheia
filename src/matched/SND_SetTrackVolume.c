/*
 * function: SND_SetTrackVolume
 * address:  0x02089400
 * packet:   pkt_02089400
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

asm void SND_SetTrackVolume(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #2
    mov	r2, #0xa
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}
