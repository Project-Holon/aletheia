/*
 * file:     unit_02702080_p01.c
 * unit:     yes
 * function: func_02702080, func_027020F0, func_02702108, func_0270212C, func_02702158, func_0270218C, func_027021CC
 * address:  0x02702080
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
 *   func_02087A04  0x02087A04  code twl a2
 *   data_04004202  0x04004202  data twl a2
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

extern void func_02087A04(u32);
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
asm void func_02702080(void);
s32 func_027020F0(void);
asm void func_02702108(void);
asm void func_0270212C(void);
asm void func_02702158(unsigned int enable);
asm void func_0270218C(int mode);
s32 func_027021CC(void);
extern u16 data_04004202;


asm void func_02702080(void) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r4, [pc, #0x58]
    mov r5, #0x1e
    ldrh r0, [r4]
    add r6, r4, #0x1fc
    mov r1, #0
    orr r0, r0, #4
    strh r0, [r4]
    mov r0, r5
    strh r1, [r6]
    bl func_02087A04
    ldrh r1, [r4]
    mov r0, r5
    orr r1, r1, #0x100
    strh r1, [r4]
    bl func_02087A04
    mov r1, #0x22
    ldr r0, [pc, #0x1c]
    strh r1, [r6]
    bl func_02087A04
    ldrh r1, [r4]
    ldr r0, [pc, #0x10]
    and r0, r1, r0
    strh r0, [r4]
    ldmfd sp!, {r4, r5, r6, pc}
    streq r4, [r0], #-4
    dcd 0x00002008
    dcd 0x0000FEFF
}


s32 func_027020F0(void)
{
    return (data_04004202 & 0x8000) >> 15;
}


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


asm void func_02702158(unsigned int enable)
{
    stmdb   sp!, {r4, lr}
    mov     r4, r0
    bl      OS_DisableInterrupts
    ldr     r1, =data_04004202
    cmp     r4, #0
    ldrh    r1, [r1]
    orrne   r2, r1, #0x4000
    biceq   r2, r1, #0x4000
    ldr     r1, =data_04004202
    strh    r2, [r1]
    bl      OS_RestoreInterrupts
    ldmfd   sp!, {r4, pc}
}


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


s32 func_027021CC(void)
{
    return (data_04004202 & 0x10) >> 4;
}
