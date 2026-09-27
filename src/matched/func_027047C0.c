/*
 * function: func_027047C0
 * address:  0x027047C0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02150fec   0x02150fec  data twl
 *   func_02085D94  0x02085D94  arm twl
 *   func_02704B58  0x02704B58  arm twl
 *   func_027044F8  0x027044F8  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   DAT_02734450   0x02734450  data twl
 */

typedef unsigned int u32;

extern u32 DAT_02150fec[];
extern void func_02085D94(u32, u32, u32);
extern u32 func_02704B58(void);
extern u32 func_027044F8(u32, u32, u32, u32);
extern void func_02085E50(u32, u32, u32);
extern u32 DAT_02734450[];

asm void func_027047C0(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x28
    ldr r2, =DAT_02150fec
    mov r7, r0
    ldr r0, [r2, #4]
    mov r6, r1
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    add r5, sp, #8
    mov r4, #1
    add r1, sp, #0
    mov r0, r5
    mov r2, r4
    bl func_02085D94
    ldr r2, =func_02704B58
    mov r0, r7
    mov r1, r6
    mov r3, r5
    bl func_027044F8
    str r0, [sp, #4]
    cmp r0, #0
    bne @lbl_02704830
    add r1, sp, #4
    mov r0, r5
    mov r2, r4
    bl func_02085E50
@lbl_02704830:
    ldr r0, =DAT_02734450
    mov r1, #0
    str r1, [r0, #0x18]
    str r1, [r0, #4]
    ldr r0, [sp, #4]
    add sp, sp, #0x28
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}
