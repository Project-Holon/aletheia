/*
 * function: func_02087B04
 * address:  0x02087B04
 * packet:   pkt_02087B04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087B14    0x02087B14  arm
*/

extern void func_02087B14(void);

asm void func_02087B04(void)
{
    stmdb	sp!, {r3, lr}
    bl	func_02087B14
    ldrh	r0, [r0]
    ldmia	sp!, {r3, pc}
}
