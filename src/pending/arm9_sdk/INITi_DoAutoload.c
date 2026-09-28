/*
 * function: INITi_DoAutoload
 * address:  0x02004BB4
 * packet:   pkt_02004BB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MIi_UncompressBackward            0x02004DF4  arm
 *   INITi_Copy32                      0x02004ED4  arm
 *   INITi_ShelterStaticInitializer    0x02004D50  arm
 *   INITi_Fill32                      0x02004F20  arm
 *   INITi_IsRunOnTwl                  0x02004EB4  arm
 *   _start_AutoloadDoneCallback       0x02004EA8  arm
 */

extern void MIi_UncompressBackward(void *);
extern void INITi_Copy32(void *, void *, unsigned int);
extern void INITi_ShelterStaticInitializer(unsigned int *);
extern void INITi_Fill32(void *, unsigned int, unsigned int);
extern void INITi_IsRunOnTwl(void);
extern void _start_AutoloadDoneCallback(void *);

asm void INITi_DoAutoload(void)
{
    stmfd sp!, {lr}

_01_uncompress:
    ldr r1, =0x02004FB0
    ldr r0, [r1, #0x14]
    bl MIi_UncompressBackward

_01_autoload:
    ldr r0, =0x02004FB0
    ldr r12, [r0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]

_01_segments_loop:
    cmp r12, r3
    bge _02_start
    stmfd sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmfd sp!, {r0}
    bl INITi_Copy32
    stmfd sp!, {r0, r1}
    ldr r0, [r12], #4
    stmfd sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmfd sp!, {r12}
    ldmfd sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmfd sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt _01_next_segment
    ldr r3, =0x02FE0000
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt _01_next_segment
    bic r2, r2, #0x1f

_01_cache_store_loop:
    cmp r2, r0
    bge _01_next_segment
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b _01_cache_store_loop

_01_next_segment:
    ldmfd sp!, {r3}
    b _01_segments_loop

_02_start:
    bl INITi_IsRunOnTwl
    bne _03_start

    ldr r1, =0x02FFE1CC
    ldr r0, [r1]
    cmp r0, #0
    beq _03_start

_02_uncompress:
    ldr r1, =0x02004F7C
    ldr r0, [r1, #0xc]
    bl MIi_UncompressBackward

_02_autoload:
    ldr r0, =0x02004F7C
    ldr r12, [r0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]

_02_segments_loop:
    cmp r12, r3
    bge _03_start
    stmfd sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmfd sp!, {r0}
    bl INITi_Copy32
    stmfd sp!, {r0, r1}
    ldr r0, [r12], #4
    stmfd sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmfd sp!, {r12}
    ldmfd sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmfd sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt _02_next_segment
    ldr r3, =0x02FE0000
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt _02_next_segment
    bic r2, r2, #0x1f

_02_cache_store_loop:
    cmp r2, r0
    bge _02_next_segment
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b _02_cache_store_loop

_02_next_segment:
    ldmfd sp!, {r3}
    b _02_segments_loop

_03_start:
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    ldr r0, =0x02004FB0
    ldr r1, =0x02004F7C
    ldmfd sp!, {lr}
    b _start_AutoloadDoneCallback
}
