/*
 * file:     unit_02702080_p02.c
 * unit:     yes
 * function: func_027021E4, func_02702208, func_0270223C, func_02702268
 * address:  0x027021E4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_04004202         0x04004202  data twl a2
 */
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
asm void func_027021E4(void);
asm void func_02702208(unsigned int enable);
asm void func_0270223C(unsigned int val);
asm void func_02702268(unsigned int enable);
extern unsigned short data_04004202;


asm void func_027021E4(void)
{
    stmdb   sp!, {r3, lr}
    bl      OS_DisableInterrupts
    ldr     r2, =data_04004202
    ldrh    r1, [r2]
    orr     r1, r1, #0x20
    strh    r1, [r2]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r3, pc}
}


asm void func_02702208(unsigned int enable)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    bl      OS_DisableInterrupts
    ldr     r1, =data_04004202
    cmp     r4, #0
    ldrh    r1, [r1]
    orrne   r2, r1, #0x800
    biceq   r2, r1, #0x800
    ldr     r1, =data_04004202
    strh    r2, [r1]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}


asm void func_0270223C(unsigned int val)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    bl      OS_DisableInterrupts
    ldr     r2, =data_04004202
    ldrh    r1, [r2]
    bic     r1, r1, #0x300
    orr     r1, r1, r4
    strh    r1, [r2]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}


asm void func_02702268(unsigned int enable)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    bl      OS_DisableInterrupts
    ldr     r1, =data_04004202
    cmp     r4, #0
    ldrh    r1, [r1]
    orrne   r2, r1, #0x400
    biceq   r2, r1, #0x400
    ldr     r1, =data_04004202
    strh    r2, [r1]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}
