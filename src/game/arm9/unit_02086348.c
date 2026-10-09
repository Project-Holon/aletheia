/*
 * file:     unit_02086348.c
 * function: func_02086348
 * address:  0x02086348
 * packet:   pkt_02086348
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_WaitVCount0 (libos.TWL.HYB.a os_init.o)
 * asm:      no-prologue code on r12 that writes the register base itself (0x04000000, bit 0 clear) to IME to disable interrupts; the DWARF subprogram has no DW_TAG_variable children.
 *
 * symbols:
 *   (none)
 */

asm void func_02086348(void)
{
    mov r12, #0x4000000
    ldr r1, [r12, #0x208]
    str r12, [r12, #0x208]
@_wait:
    ldrh r0, [r12, #6]
    cmp r0, #0
    bne @_wait
    str r1, [r12, #0x208]
    bx lr
}
