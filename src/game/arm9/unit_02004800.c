/*
 * file:     unit_02004800.c
 * unit:     yes
 * function: func_02004800, func_02004A00, func_02004A14, func_02004A98, func_02004BB4, func_02004D50, func_02004DA0
 * address:  0x02004800
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   INITi_IsRunOnTwl           0x02004EB4  arm
 *   INITi_Fill32               0x02004F20  arm
 *   INITi_DoAutoload           0x02004BB4  arm
 *   func_0209D724              0x0209D724  arm
 *   TwlStartUp                 0x02004EAC  arm
 *   func_0209D820              0x0209D820  arm
 *   MIi_UncompressBackward          0x02004DF4  arm
 *   INITi_Copy32                    0x02004ED4  arm
 *   _start_AutoloadDoneCallback     0x02004EA8  arm
 *   _start_ModuleParams             0x02004FB0  data
 *   SDK_AUTOLOAD_DTCM_START         0x02FE0000  data
 *   _start_LtdModuleParams          0x02004F7C  data
 */
extern void INITi_IsRunOnTwl(void);
extern void INITi_Fill32(void *, unsigned int, unsigned int);
extern void INITi_DoAutoload(void);
extern void func_0209D724(void);
extern void TwlStartUp(void);
extern void func_0209D820(void);
extern void MIi_UncompressBackward(void *bottom);
extern void INITi_Copy32(void);
extern void _start_AutoloadDoneCallback(void);
asm void _start(void);
asm void INITi_CpuClear32(void);
asm void INITi_InitCoprocessor(void);
asm void INITi_InitRegion(void);
asm void func_02004BB4(void);
asm void INITi_ShelterStaticInitializer(void);
asm void INITi_CallStaticInitializers(void);
extern unsigned long _start_ModuleParams[];
extern unsigned long _start_LtdModuleParams[];
extern char SDK_AUTOLOAD_DTCM_START[];


asm void _start(void)
{
    mov r12, #0x4000000
    str r12, [r12, #0x208]

    bl INITi_InitCoprocessor

    mov r0, #0
    ldr r1, =0x02FFFF80
    ldr r2, =0x00000068
    bl INITi_CpuClear32
    mov r0, #0
    ldr r1, =0x02FFFFF0
    ldr r2, =0x00000010
    bl INITi_CpuClear32

    ldr r1, =0x02FFFC40
    ldrh r2, [r1]
    cmp r2, #0
    moveq r2, #1
    streqh r2, [r1]

    ldr r1, =0x02004FD4
    ldr r2, =0x01FF8000
    add r3, r2, #0x28
_001:
    ldr r0, [r1], #4
    str r0, [r2], #4
    cmp r2, r3
    blt _001

    ldr r0, =0x02FFFC28
    mov r1, #1
    strh r1, [r0]
    ldr r0, =0x02FFFC24
    ldr r1, =0x02FFFC26
    ldr r2, =0x01FF8000
    blx r2

    ldr r1, =0x02004F94
    ldr r2, =0x01FF8000
    add r3, r2, #0x1c
_002:
    ldr r0, [r1], #4
    str r0, [r2], #4
    cmp r2, r3
    blt _002

    ldr r0, =0x02FFFC28
    mov r1, #4
    ldr r2, =0x01FF8000
    blx r2

    bl INITi_IsRunOnTwl
    bne _020

    ldr r1, =0x02004FFC
    ldr r2, =0x01FF8000
    add r2, r2, #0x1c
    mov r3, #0x34
_011:
    subs r3, r3, #4
    ldr r0, [r1, r3]
    str r0, [r2, r3]
    bgt _011
    mov r0, #1
    mov r1, #8
    blx r2

_020:
    bl INITi_InitRegion

    mov r0, #0x13
    msr cpsr_c, r0
    ldr r1, =0x02FE0000
    add r1, r1, #0x4000
    sub sp, r1, #0x40
    sub r1, sp, #0x40
    mov r0, #0x12
    msr cpsr_c, r0
    sub sp, r1, #4
    tst sp, #4
    subeq sp, sp, #4
    ldr r0, =0x00000800
    sub r1, r1, r0
    mov r0, #0x1f
    msr cpsr_fsxc, r0
    sub sp, r1, #4
    tst sp, #4
    subne sp, sp, #4

    mov r0, #0
    ldr r1, =0x02FE0000
    mov r2, #0x4000
    bl INITi_CpuClear32

    mov r1, #0
    ldr r0, =0x05000000
    mov r2, #0x400
    bl INITi_Fill32
    ldr r0, =0x07000000
    mov r2, #0x400
    bl INITi_Fill32

    bl INITi_DoAutoload

    mov r1, #0
    ldr r3, =0x02004FB0
    ldr r0, [r3, #0xc]
    ldr r2, [r3, #0x10]
    subs r2, r2, r0
    blgt INITi_Fill32

    ldr r1, =0x02FE0000
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    ldr r0, =0x01FF80F0
    str r0, [r1]

    bl func_0209D724
    bl TwlStartUp
    bl func_0209D820
    bl INITi_CallStaticInitializers

    ldr r1, =0x04000006
_022:
    ldrh r0, [r1]
    cmp r0, #0
    bne _022

    ldr r1, =0x02005125
    ldr lr, =0xFFFF0000
    bx r1
}

asm void INITi_CpuClear32(void)
{
    add r12, r1, r2
_loop:
    cmp r1, r12
    strlt r0, [r1], #4
    blt _loop
    bx lr
}

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


/*
 * notes:    byte-correct asm; the tail branch to _start_AutoloadDoneCallback (0x02004EA8) resolves now that 0x02004EA8 is a seeded function start matched as func_02004EA8.
 *
 * sdk:      INITi_DoAutoload (crt0.HYB.TWL.o)
 * asm:      crt0 code that runs before C (no C runtime yet, fixed-register
 *           stack juggling around its calls) and needs mcr p15 cache ops.
 */
asm void func_02004BB4(void)
{
    stmdb sp!, {lr}
    ldr r1, =_start_ModuleParams
    ldr r0, [r1, #20]
    bl MIi_UncompressBackward
    ldr r0, =_start_ModuleParams
    ldr r12, [r0, #0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]
_s_loop:
    cmp r12, r3
    bge _s_end
    stmdb sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmdb sp!, {r0}
    bl INITi_Copy32
    stmdb sp!, {r0, r1}
    ldr r0, [r12], #4
    stmdb sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmia sp!, {r12}
    ldmia sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmia sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt _s_next
    ldr r3, =SDK_AUTOLOAD_DTCM_START
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt _s_next
    bic r2, r2, #0x1f
_s_flush:
    cmp r2, r0
    bge _s_next
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b _s_flush
_s_next:
    ldmia sp!, {r3}
    b _s_loop
_s_end:
    bl INITi_IsRunOnTwl
    bne _done
    ldr r1, =0x02FFE1CC
    ldr r0, [r1]
    cmp r0, #0
    beq _done
    ldr r1, =_start_LtdModuleParams
    ldr r0, [r1, #12]
    bl MIi_UncompressBackward
    ldr r0, =_start_LtdModuleParams
    ldr r12, [r0, #0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]
_l_loop:
    cmp r12, r3
    bge _l_end
    stmdb sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmdb sp!, {r0}
    bl INITi_Copy32
    stmdb sp!, {r0, r1}
    ldr r0, [r12], #4
    stmdb sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmia sp!, {r12}
    ldmia sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmia sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt _l_next
    ldr r3, =SDK_AUTOLOAD_DTCM_START
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt _l_next
    bic r2, r2, #0x1f
_l_flush:
    cmp r2, r0
    bge _l_next
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b _l_flush
_l_next:
    ldmia sp!, {r3}
    b _l_loop
_l_end:
_done:
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    ldr r0, =_start_ModuleParams
    ldr r1, =_start_LtdModuleParams
    ldmia sp!, {lr}
    b _start_AutoloadDoneCallback
}

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

asm void INITi_CallStaticInitializers(void)
{
    stmfd sp!, {lr}
    ldr r1, =0x02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x00000800
    sub r1, r1, r2
    add r1, r1, #4
_loop:
    ldr r0, [r1]
    cmp r0, #0
    beq _end
    stmfd sp!, {r1}
    blx r0
    ldmfd sp!, {r1}
    mov r0, #0
    str r0, [r1], #4
    b _loop
_end:
    ldmfd sp!, {lr}
    bx lr
}
