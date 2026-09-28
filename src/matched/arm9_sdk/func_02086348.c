/*
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
 * TwlSDK libos os_init.o, symbol OSi_WaitVCount0 (internal). DWARF has no
 * formals and no locals, so the original is hand-written assembly.
 */

asm void func_02086348(void)
{
    mov ip, #0x4000000
    ldr r1, [ip, #0x208]
    str ip, [ip, #0x208]
loc_02086354:
    ldrh r0, [ip, #6]
    cmp r0, #0
    bne loc_02086354
    str r1, [ip, #0x208]
    bx lr
}
