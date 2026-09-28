
/*
 * function: func_0270218C
 * address:  0x0270218C
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

asm void func_0270218C(int mode)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    bl      OS_DisableInterrupts
    ldr     r2, =data_04004202
    cmp     r4, #0
    ldrh    r1, [r2]
    beq     _eq
    cmp     r4, #1
    orreq   r1, r1, #0x2000
    streqh r1, [r2]
    b       _end
_eq:
    bic     r1, r1, #0x2000
    strh    r1, [r2]
_end:
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}
