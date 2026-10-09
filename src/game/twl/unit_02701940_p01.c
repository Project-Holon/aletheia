/*
 * file:     unit_02701940_p01.c
 * unit:     yes
 * function: func_02701940, func_027019B4, func_02701A60, func_02701AA0
 * address:  0x02701940
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
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   func_02087988  0x02087988  code twl a2
 *   func_0208799C  0x0208799C  code twl a2
 *   func_02087A04  0x02087A04  code twl a2
 *   func_02088610  0x02088610  code twl a2
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef signed int s32;

extern void func_02087988(void);
extern void func_0208799C(void);
extern void func_02087A04(u32);
extern int func_02088610(u32, u32, u32);
extern unsigned int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(unsigned int enable);
extern void func_02701FE8(unsigned int);
extern void func_027001F0(void);
asm void func_02701940(void);
asm void func_027019B4(u32 a0, u32 a1, u32 a2);
asm void func_02701A60(const u8 *ptr);
asm void func_02701AA0(int a0);
extern u32 data_02732FC8[];
extern u32 data_02733FC8[];



asm void func_02701940(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    bl func_02087988
    ldr r4, =data_02732FC8
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02701970
    bl func_0208799C
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02701970:
    mov r5, #1
    str r5, [r4]
    bl func_0208799C
    str r7, [r4, #4]
    ldr r3, =data_02733FC8
    str r6, [r4, #0xc]
    mov r1, r5
    and r2, r8, #0xff
    mov r0, #0x40
    str r8, [r3, #0x1a8]
    bl func_027019B4
    cmp r0, #0
    movne r0, #0
    moveq r0, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}



asm void func_027019B4(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r0, r0, lsl #8
    and r3, r0, #0x7f00
    mov r0, r1, lsl #0x10
    orr r1, r3, #0x2000000
    and r0, r0, #0xff0000
    and r2, r2, #0xff
    orr r0, r1, r0
    orr r5, r2, r0
    bl func_02087988
    ldr r2, [pc, #0x74]
    ldrh r4, [r2]
    orr r1, r4, #0x100
    strh r1, [r2]
    bl func_0208799C
    ands r6, r4, #0x100
    bne @lbl_02701A00
    mov r0, #0x14
    bl func_02087A04
@lbl_02701A00:
    ldr r4, =data_02732FC8
    mov r3, r6, asr #8
    mov r1, r5
    mov r0, #0x15
    mov r2, #0
    str r3, [r4, #0x24]
    bl func_02088610
    cmp r0, #0
    bge @lbl_02701A50
    ldr r0, [r4, #0x24]
    cmp r0, #0
    bne @lbl_02701A48
    bl func_02087988
    ldr r2, [pc, #0x1c]
    ldrh r1, [r2]
    bic r1, r1, #0x100
    strh r1, [r2]
    bl func_0208799C
@lbl_02701A48:
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_02701A50:
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, pc}
    streq r4, [r0], #-4
}



asm void func_02701A60(const u8 *ptr)
{
    stmdb   sp!, {r4, r5, r6, lr}
    ldrb    r1, [r0, #1]
    ldrb    r2, [r0, #0]
    ldrb    r3, [r0, #2]
    mov     r0, r1, lsl #8
    orr     r0, r0, r2, lsl #16
    orr     r6, r3, r0
    mov     r5, #0x15
    mov     r4, #0
loop:
    mov     r0, r5
    mov     r1, r6
    mov     r2, r4
    bl      func_02088610
    cmp     r0, #0
    blt     loop
    ldmfd   sp!, {r4, r5, r6, pc}
}


asm void func_02701AA0(int a0)
{
}
