/*
 * function: func_0270229C
 * address:  0x0270229C
 * packet:   twl_wifi
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * unit:     yes
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_04004202         0x04004202  data twl a2
 */

extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
extern unsigned short data_04004202;

asm void func_0270229C(int mode)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    cmp     r4, #1
    ldmltfd sp!, {r4, pc}
    cmp     r4, #0x10
    ldmgtfd sp!, {r4, pc}
    bl      OS_DisableInterrupts
    ldr     r3, =data_04004202
    sub     r1, r4, #1
    ldrh    r2, [r3]
    mov     r1, r1, lsl #16
    bic     r2, r2, #0xf
    orr     r1, r2, r1, lsr #16
    strh    r1, [r3]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}
