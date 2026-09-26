/*
 * function: func_01FF80F0
 * address:  0x01FF80F0
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_01FF80F0(void)
{
    stmdb   sp!, {lr}
    mov     ip, #0x4000000
    add     ip, ip, #0x210
    ldr     r1, [ip, #-8]
    cmp     r1, #0
    ldmeqfd sp!, {pc}
    ldmia   ip, {r1, r2}
    ands    r1, r1, r2
    ldmeqfd sp!, {pc}
    mov     r3, #0x80000000
@loop1:
    clz     r0, r1
    bics    r1, r1, r3, lsr r0
    bne     @loop1
    mov     r1, r3, lsr r0
    str     r1, [ip, #4]
    rsbs    r0, r0, #0x1f
    ldr     r1, [pc, #8]
    ldr     r0, [r1, r0, lsl #2]
    ldr     lr, [pc, #4]
    bx      r0

@pool_01FF8140:
    dcd     0x02FE0020
@pool_01FF8144:
    dcd     0x01FF8148

@OS_IrqHandler_ThreadSwitch:
    ldr     ip, [pc, #0x148]
    mov     r3, #0
    ldr     ip, [ip]
    mov     r2, #1
    cmp     ip, #0
    beq     @loc_01FF8198
@loc_01FF8160:
    str     r2, [ip, #0x64]
    str     r3, [ip, #0x78]
    str     r3, [ip, #0x7c]
    ldr     r0, [ip, #0x80]
    str     r3, [ip, #0x80]
    mov     ip, r0
    cmp     ip, #0
    bne     @loc_01FF8160
    ldr     ip, [pc, #0x110]
    str     r3, [ip]
    str     r3, [ip, #4]
    ldr     ip, [pc, #0x108]
    mov     r1, #1
    strh    r1, [ip]
@loc_01FF8198:
    ldr     ip, [pc, #0xfc]
    ldrh    r1, [ip]
    cmp     r1, #0
    ldreq   pc, [sp], #4
    mov     r1, #0
    strh    r1, [ip]
    mov     r3, #0xd2
    msr     cpsr_c, r3
    add     r2, ip, #8
    ldr     r1, [r2]
@loc_01FF81C0:
    cmp     r1, #0
    ldrneh  r0, [r1, #0x64]
    cmpne   r0, #1
    ldrne   r1, [r1, #0x68]
    bne     @loc_01FF81C0
    cmp     r1, #0
    bne     @loc_01FF81E8
@loc_01FF81DC:
    mov     r3, #0x92
    msr     cpsr_c, r3
    ldr     pc, [sp], #4
@loc_01FF81E8:
    ldr     r0, [ip, #4]
    cmp     r1, r0
    beq     @loc_01FF81DC
    ldr     r3, [ip, #0xc]
    cmp     r3, #0
    beq     @loc_01FF8210
    stmdb   sp!, {r0, r1, ip}
    mov     lr, pc
    bx      r3
    ldmfd   sp!, {r0, r1, ip}
@loc_01FF8210:
    str     r1, [ip, #4]
    mrs     r2, spsr
    str     r2, [r0, #0]!
    stmdb   sp!, {r0, r1}
    add     r0, r0, #0
    add     r0, r0, #0x48
    ldr     r1, [pc, #0x70]
    blx     r1
    ldmfd   sp!, {r0, r1}
    ldmib   sp!, {r2, r3}
    stmib   r0!, {r2, r3}
    ldmib   sp!, {r2, r3, ip, lr}
    stmib   r0, {r2-r14}^
    add     r0, r0, #0x34
    stmib   r0!, {lr}
    mov     r3, #0xd3
    msr     cpsr_c, r3
    stmib   r0!, {sp}
    stmdb   sp!, {r1}
    add     r0, r1, #0
    add     r0, r0, #0x48
    ldr     r1, [pc, #0x38]
    blx     r1
    ldmfd   sp!, {r1}
    ldr     sp, [r1, #0x44]
    mov     r3, #0xd2
    msr     cpsr_c, r3
    ldr     r2, [r1, #0]!
    msr     spsr_all, r2
    ldr     lr, [r1, #0x40]
    ldmib   r1, {r0-r14}^
    mov     r0, r0
    stmda   sp!, {r0, r1, r2, r3, ip, lr}
    ldmfd   sp!, {pc}

@pool_01FF8298:
    dcd     0x02FE00A0
@pool_01FF829C:
    dcd     0x02150FEC
@pool_01FF82A0:
    dcd     0x020775B8
@pool_01FF82A4:
    dcd     0x020775F8
}
