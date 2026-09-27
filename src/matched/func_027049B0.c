/*
 * function: func_027049B0
 * address:  0x027049B0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_02704C5C  0x02704C5C  arm twl
 *   func_02704D48  0x02704D48  arm twl
 *   DAT_02734450   0x02734450  data twl
 *   func_02704CC4  0x02704CC4  arm twl
 */

typedef unsigned int u32;

extern u32 func_02704C5C(void);
extern void func_02704D48(u32, u32, u32, u32);
extern u32 DAT_02734450[];
extern void func_02704CC4(u32);

asm void func_027049B0(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    and r3, r1, #0xff0000
    mov r4, r3, lsr #16
    and r3, r1, #0xff00
    and r4, r4, #0xff
    mov r3, r3, lsr #8
    mov r8, r0
    mov r7, r2
    cmp r4, #0xfd
    and r5, r3, #0xff
    and r6, r1, #0xff
    bne @lbl_02704A00
    bl func_02704C5C
    cmp r0, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, #0
    mov r1, r0
    mov r2, r0
    mov r3, #0xfd
    bl func_02704D48
@lbl_02704A00:
    cmp r8, #0x18
    bne @lbl_02704A40
    cmp r7, #1
    beq @lbl_02704A40
    ldr r0, =DAT_02734450
    ldr r1, [r0, #0xc]
    cmp r1, #3
    ldrne r1, [r0, #0xc]
    cmpne r1, #4
    ldrne r0, [r0, #0xc]
    cmpne r0, #5
    bne @lbl_02704A40
    ldr r0, =DAT_02734450
    ldrb r1, [r0, #0x58]
    cmp r1, r4
    beq @lbl_02704A4C
@lbl_02704A40:
    mov r0, #7
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704A4C:
    cmp r5, #5
    addls pc, pc, r5, lsl #2
    b @lbl_02704B48
    b @lbl_02704A70
    b @lbl_02704B48
    b @lbl_02704B00
    b @lbl_02704B0C
    b @lbl_02704B18
    b @lbl_02704B24
@lbl_02704A70:
    cmp r4, #0xfd
    bgt @lbl_02704AA0
    bge @lbl_02704AC8
    cmp r4, #5
    addls pc, pc, r4, lsl #2
    b @lbl_02704AF4
    b @lbl_02704AF4
    b @lbl_02704AAC
    b @lbl_02704AB0
    b @lbl_02704AB4
    b @lbl_02704AB4
    b @lbl_02704AC4
@lbl_02704AA0:
    cmp r4, #0xfe
    beq @lbl_02704AE4
    b @lbl_02704AF4
@lbl_02704AAC:
    b @lbl_02704AE8
@lbl_02704AB0:
    b @lbl_02704AE8
@lbl_02704AB4:
    ldr r0, [r0, #0x54]
    cmp r0, #0
    dcd 0x15c06000
    b @lbl_02704AF4
@lbl_02704AC4:
    b @lbl_02704AE8
@lbl_02704AC8:
    ldr r2, [r0, #0x2c]
    cmp r2, #0
    beq @lbl_02704AF4
    ldr r1, [r0, #0x30]
    mov r0, r5
    blx r2
    b @lbl_02704AF4
@lbl_02704AE4:
    ldr r0, =DAT_02734450
@lbl_02704AE8:
    ldr r0, [r0, #0x54]
    cmp r0, #0
    strne r6, [r0]
@lbl_02704AF4:
    mov r0, #0
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704B00:
    mov r0, #2
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704B0C:
    mov r0, #3
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704B18:
    mov r0, #4
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704B24:
    cmp r4, #4
    bne @lbl_02704B3C
    ldr r1, [r0, #0x54]
    cmp r1, #0
    movne r0, #0
    dcd 0x15c10000
@lbl_02704B3C:
    mov r0, #6
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02704B48:
    mov r0, #7
    bl func_02704CC4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
