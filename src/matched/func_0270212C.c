/*
 * function: func_0270212C
 * address:  0x0270212C
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

asm void func_0270212C(void)
{
    stmdb   sp!, {r3, lr}
    bl      OS_DisableInterrupts
    ldr     r3, =data_04004202
    ldr     r1, =0x00007fff
    ldrh    r2, [r3]
    and     r1, r2, r1
    strh    r1, [r3]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r3, pc}
}
