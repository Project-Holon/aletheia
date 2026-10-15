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
 *   OSi_SetExContext 0x02086EC8 arm
 *   OSi_DisplayExContext 0x02086F48 arm
 */

extern void OSi_SetExContext(void);
extern void OSi_DisplayExContext(void);
asm void OSi_GetAndDisplayContext(void)
{
    stmfd sp!, {r0, lr}
    bl OSi_SetExContext
    bl OSi_DisplayExContext
    ldmfd sp!, {r0, lr}
    bx lr
}
