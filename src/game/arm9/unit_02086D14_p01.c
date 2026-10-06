/*
 * file:     unit_02086D14_p01.c
 * unit:     yes
 * function: OS_SetProtectionRegionParam
 * address:  0x02086D14
 * packet:   pkt_02086D14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_020A86B4 0x020A86B4 data
 */

extern void g_020A86B4(void);
asm void OS_SetProtectionRegionParam(int regionNo, unsigned long param)
{
    stmfd sp!, {r3, lr}
    ldr r2, =g_020A86B4
    ldr r2, [r2, r0, lsl #2]
    mov r0, r1
    blx r2
    ldmfd sp!, {r3, pc}
}
