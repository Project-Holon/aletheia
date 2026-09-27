/*
 * function: OSi_GetAndDisplayContext
 * address:  0x02086EB4
 * packet:   pkt_02086EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02086EC8 0x02086EC8 arm
 *   func_02086F48 0x02086F48 arm
 */

extern void func_02086EC8(void);
extern void func_02086F48(void);
asm void OSi_GetAndDisplayContext(void)
{
    stmfd sp!, {r0, lr}
    bl func_02086EC8
    bl func_02086F48
    ldmfd sp!, {r0, lr}
    bx lr
}
