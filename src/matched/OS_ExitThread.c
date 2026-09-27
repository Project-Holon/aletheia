/*
 * function: OS_ExitThread
 * address:  0x020854B0
 * packet:   pkt_020854B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020854D0 0x020854D0 arm
 *   func_02087988 0x02087988 arm
 *   g_02150FD0 0x02150FD0 data
 */

extern void func_020854D0(void);
extern void func_02087988(void);
extern void g_02150FD0(void);

asm void OS_ExitThread(void)
{
    stmfd sp!, {r3, lr}
    bl	func_02087988
    ldr r0, =g_02150FD0
    mov	r1, #0
    ldr	r0, [r0, #0x20]
    bl	func_020854D0
    ldmfd sp!, {r3, pc}
}
