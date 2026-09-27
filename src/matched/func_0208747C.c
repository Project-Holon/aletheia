/*
 * function: func_0208747C
 * address:  0x0208747C
 * packet:   pkt_0208747C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208748C    0x0208748C  arm
*/

extern void func_0208748C(void);

asm void func_0208747C(void)
{
    stmdb	sp!, {r0, lr}
    bl	func_0208748C
    ldmia	sp!, {r0, lr}
    bx	lr
}
