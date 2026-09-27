/*
 * function: SND_SetTrackModSpeed
 * address:  0x02089470
 * packet:   pkt_02089470
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

asm void SND_SetTrackModSpeed(void)
{
    stmfd sp!, {r3, lr}
    mov	r3, r2
    mov	ip, #1
    mov	r2, #0x19
    str	ip, [sp]
    bl	func_020897DC
    ldmfd sp!, {r3, pc}
}
