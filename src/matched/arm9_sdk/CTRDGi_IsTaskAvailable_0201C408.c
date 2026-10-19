/*
 * function: WAZA_TOOL_IsCacheCreated
 * address:  0x0201C408
 * packet:   pkt_0201C408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     second copy of TwlSDK libctrdg.TWL.HYB.thumb.a(ctrdg_task.o)
 *           CTRDGi_IsTaskAvailable; reads the task-available flag at
 *           0x02146530.
 */

asm void WAZA_TOOL_IsCacheCreated(void)
{
    ldr r0, =0x02146530
    ldr r0, [r0]
    cmp r0, #0
    beq _zero
    mov r0, #1
    bx lr
_zero:
    mov r0, #0
    bx lr
}
