/*
 * function: DWCi_CMNlFontFlag
 * address:  0x02085D0C
 * packet:   pkt_02085D0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087B04 0x02087B04 arm
 *   g_020A5CD4 0x020A5CD4 data
 */

extern void func_02087B04(void);
extern void g_020A5CD4(void);
asm void DWCi_CMNlFontFlag(void)
{
    stmfd sp!, {r3, lr}
    bl func_02087B04
    ldr r1, =g_020A5CD4
    ldr r0, [r1, r0, lsl #2]
    ldmfd sp!, {r3, pc}
}
