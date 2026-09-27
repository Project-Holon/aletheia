/*
 * function: CTRDGi_IsTaskAvailable_02010054
 * address:  0x02010054
 * packet:   pkt_02010054
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     TwlSDK libctrdg.TWL.HYB.thumb.a(ctrdg_task.o) CTRDGi_IsTaskAvailable;
 *           reads the task-available flag at 0x0214617C.
 */

asm void CTRDGi_IsTaskAvailable_02010054(void)
{
    ldr r0, =0x0214617C
    ldr r0, [r0]
    cmp r0, #0
    beq _zero
    mov r0, #1
    bx lr
_zero:
    mov r0, #0
    bx lr
}
