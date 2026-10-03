/*
 * function: func_0205A148
 * address:  0x0205A148
 * packet:   pkt_0205A148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0205A12C    0x0205A12C  arm
*/

extern void *func_0205A12C(char *p);

asm void func_0205A148(void)
{
    stmdb	sp!, {r3, lr}
    bl	func_0205A12C
    ldr	r0, [r0, #4]
    ldmia	sp!, {r3, pc}
}
