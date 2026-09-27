/*
 * function: INITi_InitCoprocessor
 * address:  0x02004A14
 * packet:   pkt_02004A14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void INITi_InitCoprocessor(void)
{
    mrc p15, 0, r0, c1, c0, 0

    tst r0, #1
    beq _010
    tst r0, #4
    beq _003

    mov r1, #0
_001:
    mov r2, #0
_002:
    orr r3, r1, r2
    mcr p15, 0, r3, c7, c10, 2
    add r2, r2, #0x20
    cmp r2, #0x400
    blt _002
    adds r1, r1, #0x40000000
    bne _001

_003:
    mov r1, #0
    mcr p15, 0, r1, c7, c10, 4

_010:
    ldr r1, =0x000f9005
    bic r0, r0, r1
    ldr r1, =0x00002078
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0

    mov r1, #0x20
    mcr p15, 0, r1, c9, c1, 1
    ldr r1, =0x02fe0000
    orr r1, r1, #0xa
    mcr p15, 0, r1, c9, c1, 0

    mov r1, #0x50000
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0

    bx lr
}
