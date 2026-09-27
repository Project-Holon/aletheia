/*
 * function: INITi_InitRegion
 * address:  0x02004A98
 * packet:   pkt_02004A98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   INITi_IsRunOnTwl  0x02004EB4  arm
 */

extern void INITi_IsRunOnTwl(void);

asm void INITi_InitRegion(void)
{
    mov r12, lr

    ldr r0, =0x04000033
    mcr p15, 0, r0, c6, c0, 0

    ldr r0, =0x02FE0000
    orr r0, r0, #0x1b
    mcr p15, 0, r0, c6, c4, 0

    ldr r0, =0x0100002F
    mcr p15, 0, r0, c6, c5, 0

    ldr r0, =0xFFFF001D
    mcr p15, 0, r0, c6, c6, 0

    bl INITi_IsRunOnTwl
    bne _002

_001:
    ldr r0, =0x02000031
    mcr p15, 0, r0, c6, c1, 0

    ldr r0, =0x02F80025
    mcr p15, 0, r0, c6, c2, 0

    ldr r0, =0x08000035
    mcr p15, 0, r0, c6, c3, 0

    ldr r0, =0x02FFC01B
    mcr p15, 0, r0, c6, c7, 0

    mov r0, #0x4a
    mcr p15, 0, r0, c2, c0, 1

    mov r0, #0x4a
    mcr p15, 0, r0, c2, c0, 0

    mov r0, #0xa
    mcr p15, 0, r0, c3, c0, 0

    ldr r0, =0x05101011
    mcr p15, 0, r0, c5, c0, 3

    ldr r0, =0x15111011
    mcr p15, 0, r0, c5, c0, 2

    b _003

_002:
    ldr r0, =0x02000031
    mcr p15, 0, r0, c6, c1, 0

    ldr r0, =0x027FF017
    mcr p15, 0, r0, c6, c2, 0

    ldr r0, =0x08000035
    mcr p15, 0, r0, c6, c3, 0

    ldr r0, =0x02FFF017
    mcr p15, 0, r0, c6, c7, 0

    mov r0, #0x42
    mcr p15, 0, r0, c2, c0, 1

    mov r0, #0x42
    mcr p15, 0, r0, c2, c0, 0

    mov r0, #2
    mcr p15, 0, r0, c3, c0, 0

    ldr r0, =0x05101011
    mcr p15, 0, r0, c5, c0, 3

    ldr r0, =0x15111111
    mcr p15, 0, r0, c5, c0, 2

_003:
    mrc p15, 0, r0, c1, c0, 0
    ldr r1, =0x00005005
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0

    mov r1, #0
    mcr p15, 0, r1, c7, c6, 0
    mcr p15, 0, r1, c7, c5, 0

    bx r12
}
