/*
 * function: func_02702208
 * address:  0x02702208
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
 *   data_02004200         0x02004200  data twl a2
 */

extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
extern unsigned short data_02004200;

asm void func_02702208(unsigned int enable)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    bl      OS_DisableInterrupts
    ldr     r1, =data_02004200
    cmp     r4, #0
    ldrh    r1, [r1]
    orrne   r2, r1, #0x800
    biceq   r2, r1, #0x800
    ldr     r1, =data_02004200
    strh    r2, [r1]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}
