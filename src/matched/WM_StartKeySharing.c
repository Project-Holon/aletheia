/*
 * function: WM_StartKeySharing
 * address:  0x02090B9C
 * packet:   pkt_02090B9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209004C 0x0209004C arm
 */

extern void func_0209004C(void);

asm void WM_StartKeySharing(void)
{
    stmfd sp!, {r3, lr}
    mov	ip, #1
    rsb	r2, ip, #0x10000
    mov	r3, #2
    str	ip, [sp]
    bl	func_0209004C
    ldmfd sp!, {r3, pc}
}
