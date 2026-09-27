/*
 * function: func_0205911C
 * address:  0x0205911C
 * packet:   pkt_0205911C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02059108    0x02059108  arm
*/

extern void func_02059108(void);

asm void func_0205911C(void)
{
    stmdb	sp!, {r3, lr}
    bl	func_02059108
    and	r0, r0, #3
    ldmia	sp!, {r3, pc}
}
