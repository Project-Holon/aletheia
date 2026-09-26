/*
 * function: func_027021E4
 * address:  0x027021E4
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

asm void func_027021E4(void)
{
    stmdb   sp!, {r3, lr}
    bl      OS_DisableInterrupts
    ldr     r2, =data_02004200
    ldrh    r1, [r2]
    orr     r1, r1, #0x20
    strh    r1, [r2]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r3, pc}
}
