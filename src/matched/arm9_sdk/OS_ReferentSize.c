/*
 * function: OS_ReferentSize
 * address:  0x02086C54
 * packet:   pkt_02086C54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */

extern void func_02087988(void);
extern void func_0208799C(void);

asm void OS_ReferentSize(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r1
    bl	func_02087988
    bl	func_0208799C
    ldr	r0, [r4, #-0x18]
    sub	r0, r0, #0x20
    ldmfd sp!, {r4, pc}
}
