/*
 * function: func_0204B084
 * address:  0x0204B084
 * packet:   pkt_0204B084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0204BE28 0x0204BE28 arm
 */

extern void func_020307B0(void *p);
extern void func_0204BE28(int *p);

asm void func_0204B084(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_0204BE28
    mov	r0, r4
    bl func_020307B0
    ldmfd sp!, {r4, pc}
}
