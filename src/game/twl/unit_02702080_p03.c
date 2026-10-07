/*
 * file:     unit_02702080_p03.c
 * unit:     yes
 * function: func_0270229C, func_027022E0
 * address:  0x0270229C
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
typedef unsigned short u16;

typedef signed int s32;

extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
asm void func_0270229C(int mode);
s32 func_027022E0(void);
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


s32 func_027022E0(void)
{
    return (data_04004202 & 0xf) + 1;
}
