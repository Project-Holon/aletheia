/*
 * function: func_02700824
 * address:  0x02700824
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   data_0273417C  0x0273417C  data twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   func_02087988  0x02087988  code twl a2
 *   func_02085A38  0x02085A38  code twl a2
 *   func_02085E50  0x02085E50  code twl a2
 *   func_020870D0  0x020870D0  code twl a2
 *   func_027007C8  0x027007C8  code twl a2
 *   func_02087974  0x02087974  code twl a2
 *   func_02702080  0x02702080  code twl a2
 *   func_02700230  0x02700230  code twl a2
 */

typedef unsigned int u32;

extern u32 data_0273417C[];
extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern void func_02087988(void);
extern void func_02085A38(u32);
extern u32 func_02085E50(u32, u32, u32);
extern u32 func_020870D0(void);
extern u32 func_027007C8(void);
extern void func_02087974(void);
extern void func_02702080(void);
extern void func_02700230(u32, u32);

asm void func_02700824(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, r10, r11, lr}
    bl func_02087988
    ldr sb, [pc, #0xf4]
    ldr r5, [pc, #0xf4]
    ldr r6, [pc, #0xf4]
    ldr r4, [pc, #0xf4]
    mov r7, #1
    mov r10, #0x64
    add r11, sp, #0
    mov r8, #0
@lbl_0270084C:
    mov r0, r10
    bl func_02085A38
    mov r0, sb
    mov r1, r11
    mov r2, r8
    bl func_02085E50
    cmp r0, #0
    bne @lbl_027008D4
    ldr r0, [r6, #0x1ac]
    cmp r0, #0
    bne @lbl_0270084C
    ldr r0, [r6, #0x124]
    cmp r0, #0
    beq @lbl_0270084C
    ldr r0, [r5]
    cmp r0, #0
    bne @lbl_0270084C
    ldr r0, [r6, #0x1b0]
    add r0, r0, #1
    str r0, [r6, #0x1b0]
    cmp r0, #0xa
    dcd 0xbaffffe9
    str r8, [r6, #0x1b0]
    bl func_020870D0
    ldr r2, [r5, #0x50]
    subs r1, r0, r2
    mov r0, r1, asr #0x1f
    cmp r0, #0
    cmpeq r1, r4
    blo @lbl_0270084C
    str r7, [r5]
    ldr r0, [r6, #0x1ac]
    add r0, r0, #1
    str r0, [r6, #0x1ac]
@lbl_027008D4:
    bl func_027007C8
    cmp r0, #7
    bne @lbl_02700904
    ldr r0, [pc, #0x44]
    mov r1, #0
    str r1, [r0]
    ldr r1, [r0, #0x60]
    cmp r1, #0
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, r10, r11, pc}
    mov r0, #7
    blx r1
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, r10, r11, pc}
@lbl_02700904:
    bl func_02087974
    bl func_02702080
    bl func_02087988
    mov r0, #0
    mov r1, r0
    str r0, [r5]
    bl func_02700230
    b @lbl_0270084C
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, r10, r11, pc}
    dcd data_0273417C
    dcd data_02732FC8
    dcd data_02733FC8
    dcd 0x0007fd88
}
