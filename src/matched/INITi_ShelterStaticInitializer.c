/*
 * function: INITi_ShelterStaticInitializer
 * address:  0x02004D50
 * packet:   pkt_02004D50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void INITi_ShelterStaticInitializer(void)
{
    cmp r0, #0
    bxeq lr
    ldr r1, =0x02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x00000800
    sub r1, r1, r2
    add r1, r1, #4
_scan:
    ldr r2, [r1]
    cmp r2, #0
    addne r1, r1, #4
    bne _scan
_copy:
    ldr r2, [r0], #4
    str r2, [r1], #4
    cmp r2, #0
    bne _copy
    bx lr
}
