/*
 * file:     unit_02702080.c
 * unit:     yes
 * function: func_02702080, func_027020F0, func_02702108, func_0270212C, func_02702158, func_0270218C, func_027021CC, func_027021E4, func_02702208, func_0270223C, func_02702268, func_0270229C, func_027022E0, func_027022F8, func_0270234C
 * address:  0x02702080
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087A04  0x02087A04  code twl a2
 *   data_04004202  0x04004202  data twl a2
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_0209C0A4  0x0209C0A4  code twl a2
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef unsigned long long u64;

extern void func_02087A04(u32);
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
extern u64 func_0209C0A4(u32, u32);
asm void func_02702080(void);
s32 func_027020F0(void);
asm void func_02702108(void);
asm void func_0270212C(void);
asm void func_02702158(unsigned int enable);
asm void func_0270218C(int mode);
s32 func_027021CC(void);
asm void func_027021E4(void);
asm void func_02702208(unsigned int enable);
asm void func_0270223C(unsigned int val);
asm void func_02702268(unsigned int enable);
asm void func_0270229C(int mode);
s32 func_027022E0(void);
u32 func_027022F8(u32 a0, u32 a1);
asm void func_0270234C(u32 a0);
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



u32 func_027022F8(u32 a0, u32 a1) {
    u32 r4 = (u32)func_0209C0A4(0x400, a0);
    if ((s32)r4 > 0x10) r4 = 0x10;
    if ((s32)r4 > 1) {
        do {
            u64 res = func_0209C0A4(a1, r4);
            if ((u32)(res >> 32) == 0) return r4;
            r4--;
        } while ((s32)r4 > 1);
    }
    return 1;
}


asm void func_0270234C(u32 a0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    bl func_027022E0
    mov r1, r4, lsl #1
    mul r0, r1, r0
    ldmfd sp!, {r4, pc}
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b @lbl_027023C4
    b @lbl_0270238C
    b @lbl_02702394
    b @lbl_0270239C
    b @lbl_027023A4
    b @lbl_027023AC
    b @lbl_027023B4
    b @lbl_027023BC
@lbl_0270238C:
    mov r0, #0x280
    bx lr
@lbl_02702394:
    mov r0, #0x140
    bx lr
@lbl_0270239C:
    mov r0, #0xa0
    bx lr
@lbl_027023A4:
    mov r0, #0x160
    bx lr
@lbl_027023AC:
    mov r0, #0xb0
    bx lr
@lbl_027023B4:
    mov r0, #0x100
    bx lr
@lbl_027023BC:
    mov r0, #0x200
    bx lr
@lbl_027023C4:
    mov r0, #0
    bx lr
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b @lbl_0270242C
    b @lbl_027023F4
    b @lbl_027023FC
    b @lbl_02702404
    b @lbl_0270240C
    b @lbl_02702414
    b @lbl_0270241C
    b @lbl_02702424
@lbl_027023F4:
    mov r0, #0x1e0
    bx lr
@lbl_027023FC:
    mov r0, #0xf0
    bx lr
@lbl_02702404:
    mov r0, #0x78
    bx lr
@lbl_0270240C:
    mov r0, #0x120
    bx lr
@lbl_02702414:
    mov r0, #0x90
    bx lr
@lbl_0270241C:
    mov r0, #0xc0
    bx lr
@lbl_02702424:
    mov r0, #0x180
    bx lr
@lbl_0270242C:
    mov r0, #0
    bx lr
}
