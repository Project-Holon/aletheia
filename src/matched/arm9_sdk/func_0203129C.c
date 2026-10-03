/*
 * function: func_0203129C
 * address:  0x0203129C
 * packet:   pkt_0203129C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02031354 0x02031354 arm
 *   g_02146990 0x02146990 data
 */

extern void *func_02031354(int a0);
extern void g_02146990(void);

asm void func_0203129C(void)
{
    stmfd sp!, {r3, lr}
    bl func_02031354
    ldr r1, =g_02146990
    str r0, [r1]
    ldmfd sp!, {r3, pc}
}
