/*
 * function: func_02702108
 * address:  0x02702108
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

asm void func_02702108(void)
{
    stmdb   sp!, {r3, lr}
    bl      OS_DisableInterrupts
    ldr     r2, =data_04004202
    ldrh    r1, [r2]
    orr     r1, r1, #0x8000
    strh    r1, [r2]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r3, pc}
}
