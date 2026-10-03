/*
 * function: func_02700078
 * address:  0x02700078
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   func_02085D3C  0x02085D3C  code twl a2
 *   func_027021CC  0x027021CC  code twl a2
 *   func_020870D0  0x020870D0  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern u32 func_02085D3C(void);
typedef signed int     s32;
extern s32 func_027021CC(void);
extern u32 func_020870D0(void);

asm void func_02700078(void) {
    stmdb sp!, {r3, lr}
    ldr r0, [pc, #0x6c]
    add r0, r0, #0x3000
    ldr r1, [r0, #0xff8]
    orr r1, r1, #0x2000000
    str r1, [r0, #0xff8]
    bl func_02085D3C
    cmp r0, #1
    movne r0, #0
    bne @lbl_027000A4
    bl func_027021CC
@lbl_027000A4:
    cmp r0, #0
    beq @lbl_027000C8
    ldr r0, =data_02732FC8
    ldr r1, [r0, #0x5c]
    cmp r1, #0
    ldmeqfd sp!, {r3, pc}
    mov r0, #0
    blx r1
    ldmfd sp!, {r3, pc}
@lbl_027000C8:
    bl func_020870D0
    ldr r2, =data_02732FC8
    str r0, [r2, #0x50]
    str r1, [r2, #0x54]
    ldr r1, [r2, #0x58]
    cmp r1, #0
    ldmeqfd sp!, {r3, pc}
    mov r0, #0
    blx r1
    ldmfd sp!, {r3, pc}
    dcd 0x02fe0000
}

asm void func_027000F8(u32 a0) {
    ldr r1, =data_02732FC8
    str r0, [r1, #0x58]
    bx lr
}

asm void func_02700108(u32 a0) {
    ldr r1, =data_02732FC8
    str r0, [r1, #0x5c]
    bx lr
}

asm void func_02700118(u32 a0) {
    ldr r1, =data_02732FC8
    str r0, [r1, #0x60]
    bx lr
}

asm void func_02700128(u32 a0) {
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b @lbl_02700160
    b @lbl_02700148
    b @lbl_02700148
    b @lbl_02700150
    b @lbl_02700158
    b @lbl_02700158
@lbl_02700148:
    mov r0, #0
    bx lr
@lbl_02700150:
    mov r0, #3
    bx lr
@lbl_02700158:
    mov r0, #0
    bx lr
@lbl_02700160:
    mov r0, #0
    bx lr
}

asm void func_02700168(u32 a0) {
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b @lbl_027001B0
    b @lbl_02700188
    b @lbl_02700190
    b @lbl_02700198
    b @lbl_027001A0
    b @lbl_027001A8
@lbl_02700188:
    mov r0, #0
    bx lr
@lbl_02700190:
    mvn r0, #1
    bx lr
@lbl_02700198:
    mov r0, #1
    bx lr
@lbl_027001A0:
    mvn r0, #0
    bx lr
@lbl_027001A8:
    mov r0, #2
    bx lr
@lbl_027001B0:
    mov r0, #0
    bx lr
}

asm void func_027001B8(u32 a0) {
    cmp r0, #4
    addls pc, pc, r0, lsl #2
    b @lbl_027001E8
    b @lbl_027001D8
    b @lbl_027001D8
    b @lbl_027001D8
    b @lbl_027001E0
    b @lbl_027001E0
@lbl_027001D8:
    mov r0, #0
    bx lr
@lbl_027001E0:
    mov r0, #2
    bx lr
@lbl_027001E8:
    mov r0, #0
    bx lr
}
