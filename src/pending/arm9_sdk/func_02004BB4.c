/*
 * function: func_02004BB4
 * address:  0x02004BB4
 * packet:   pkt_02004BB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * notes:    byte-correct asm; the tail branch to _start_AutoloadDoneCallback (0x02004EA8) is unresolved because that address has no witness outside this body; matching 0x02004EA8 (crt0, next pass) should make this EXACT.
 *
 * sdk:      INITi_DoAutoload (crt0.HYB.TWL.o)
 * asm:      crt0 code that runs before C (no C runtime yet, fixed-register
 *           stack juggling around its calls) and needs mcr p15 cache ops.
 *
 * symbols:
 *   MIi_UncompressBackward          0x02004DF4  arm
 *   INITi_Copy32                    0x02004ED4  arm
 *   INITi_ShelterStaticInitializer  0x02004D50  arm
 *   INITi_Fill32                    0x02004F20  arm
 *   INITi_IsRunOnTwl                0x02004EB4  arm
 *   _start_AutoloadDoneCallback     0x02004EA8  arm
 *   _start_ModuleParams             0x02004FB0  data
 *   SDK_AUTOLOAD_DTCM_START         0x02FE0000  data
 *   _start_LtdModuleParams          0x02004F7C  data
 */

extern void MIi_UncompressBackward(void *bottom);
extern void INITi_Copy32(void);
extern void INITi_ShelterStaticInitializer(void);
extern void INITi_Fill32(void);
extern void INITi_IsRunOnTwl(void);
extern void _start_AutoloadDoneCallback(void);
extern unsigned long _start_ModuleParams[];
extern unsigned long _start_LtdModuleParams[];
extern char SDK_AUTOLOAD_DTCM_START[];

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
