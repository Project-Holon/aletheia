/*
 * function: func_02702268
 * address:  0x02702268
 * packet:   twl_wifi
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_04004202         0x04004202  data twl a2
 */

extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
extern unsigned short data_04004202;

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
