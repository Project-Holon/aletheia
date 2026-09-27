/*
 * function: _start
 * address:  0x02004800
 * packet:   pkt_02004800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   INITi_InitCoprocessor      0x02004A14  arm
 *   INITi_CpuClear32           0x02004A00  arm
 *   INITi_IsRunOnTwl           0x02004EB4  arm
 *   INITi_InitRegion           0x02004A98  arm
 *   INITi_Fill32               0x02004F20  arm
 *   INITi_DoAutoload           0x02004BB4  arm
 *   func_0209D724              0x0209D724  arm
 *   TwlStartUp                 0x02004EAC  arm
 *   func_0209D820              0x0209D820  arm
 *   INITi_CallStaticInitializers  0x02004DA0  arm
 */

extern void INITi_InitCoprocessor(void);
extern void INITi_CpuClear32(unsigned int, void *, unsigned int);
extern void INITi_IsRunOnTwl(void);
extern void INITi_InitRegion(void);
extern void INITi_Fill32(void *, unsigned int, unsigned int);
extern void INITi_DoAutoload(void);
extern void func_0209D724(void);
extern void TwlStartUp(void);
extern void func_0209D820(void);
extern void INITi_CallStaticInitializers(void);

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
