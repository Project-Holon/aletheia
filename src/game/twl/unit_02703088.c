/*
 * file:     unit_02703088.c
 * unit:     yes
 * function: func_02703088, func_02703208, func_02703250
 * address:  0x02703088
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
 *   func_027028E4 0x027028E4 arm twl
 *   func_027026DC 0x027026DC arm twl
 *   func_020862B8 0x020862B8 arm twl
 *   func_02082BCC 0x02082BCC arm twl
 *   func_020862D4 0x020862D4 arm twl
 *   func_02703A34 0x02703A34 arm twl
 *   func_02082D44 0x02082D44 arm twl
 *   func_02703B24 0x02703B24 arm twl
 *   func_02082E74 0x02082E74 arm twl
 */
typedef unsigned int u32;

typedef unsigned char u8;

extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02082BCC(u32, u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02082D44(u32, u32, u32);
extern u32 func_02703B24(u32, u32);
extern u32 func_02082E74(u32, u32, u32);
asm void func_02703088(u32 a0, u32 a1);
asm u8 *func_02703208(u8 *a0, u8 a1);
asm void func_02703250(u32 a0, u32 a1, u32 a2);



asm void func_02703088(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x38
    mov r6, r0
    mov r5, r1
    mov r0, #1
    mov r1, #3
    bl func_027028E4
    cmp r0, #0
    beq @lbl_027030B8
    cmp r0, #2
    addne sp, sp, #0x38
    ldmnefd sp!, {r3, r4, r5, r6, r7, pc}
@lbl_027030B8:
    bl func_027026DC
    movs r7, r0
    beq @lbl_027030F4
    add r0, r7, #0x2000
    ldr r0, [r0, #0x278]
    mov r4, #1
    mov r1, r4
    add r0, r0, #7
    bl func_020862B8
    add r0, r7, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #7]
    cmp r0, #1
    movne r4, #0
    b @lbl_027030F8
@lbl_027030F4:
    mov r4, #0
@lbl_027030F8:
    cmp r4, #1
    addeq sp, sp, #0x38
    moveq r0, #3
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    cmp r5, #0
    addeq sp, sp, #0x38
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    ldr r0, [r5]
    cmp r0, #0
    addeq sp, sp, #0x38
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    ldrh r1, [r5, #0x12]
    cmp r1, #0x20
    addhi sp, sp, #0x38
    movhi r0, #5
    ldmhifd sp!, {r3, r4, r5, r6, r7, pc}
    ldrh r1, [r5, #0x34]
    cmp r1, #0x20
    addhi sp, sp, #0x38
    movhi r0, #5
    ldmhifd sp!, {r3, r4, r5, r6, r7, pc}
    ldrh r2, [r5, #4]
    mov r1, #0
    add r2, r2, #3
    bic r2, r2, #3
    bl func_02082BCC
    ldrh r1, [r5, #4]
    ldr r0, [r5]
    add r1, r1, #3
    bic r1, r1, #3
    bl func_020862D4
    mov r4, #7
    mov r0, r4
    mov r1, r6
    bl func_02703A34
    ldrh r2, [r5, #6]
    ldrh r3, [r5, #4]
    ldrh r1, [r5, #8]
    ldrh r0, [r5, #0xa]
    strh r2, [sp, #2]
    ldrh r2, [r5, #0x12]
    strh r3, [sp, #4]
    ldrh r3, [r5, #0x34]
    strh r4, [sp]
    ldr r4, [r5]
    strh r1, [sp, #6]
    strh r0, [sp, #0xc]
    strh r2, [sp, #0xe]
    add r1, sp, #0x12
    add r0, r5, #0x14
    mov r2, #0x20
    str r4, [sp, #8]
    strh r3, [sp, #0x10]
    bl func_02082D44
    add r1, sp, #0x32
    add r0, r5, #0xc
    mov r2, #6
    bl func_02082D44
    add r0, sp, #0
    mov r1, #0x38
    bl func_02703B24
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    add sp, sp, #0x38
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}



asm u8 *func_02703208(u8 *a0, u8 a1) {
    stmdb sp!, {r3, lr}
    ldrh r2, [r0], #0x40
    add r2, r0, r2
    sub r3, r2, #0x40
    b @lbl_02703224
@lbl_0270321C:
    add r2, ip, #2
    add r0, r0, r2
@lbl_02703224:
    ldrb lr, [r0]
    cmp lr, r1
    beq @lbl_02703244
    ldrb ip, [r0, #1]
    add r2, r0, ip
    add r2, r2, #2
    cmp r2, r3
    bls @lbl_0270321C
@lbl_02703244:
    cmp lr, r1
    movne r0, #0
    ldmfd sp!, {r3, pc}
}


asm void func_02703250(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    ldrh r3, [r0]
    add r5, r0, #0x40
    mov r8, r1
    add r0, r5, r3
    mov r7, r2
    sub r6, r0, #0x40
    cmp r8, #0xdd
    movne r0, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    ldrb r0, [r5, #1]
    add r0, r5, r0
    add r0, r0, #2
    cmp r0, r6
    bhi @lbl_027032D8
    mov r4, #4
@lbl_02703290:
    ldrb r0, [r5]
    cmp r0, r8
    bne @lbl_027032B8
    mov r1, r7
    mov r2, r4
    add r0, r5, #2
    bl func_02082E74
    cmp r0, #0
    moveq r0, r5
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_027032B8:
    ldrb r0, [r5, #1]
    add r0, r0, #2
    add r5, r5, r0
    ldrb r0, [r5, #1]
    add r0, r5, r0
    add r0, r0, #2
    cmp r0, r6
    bls @lbl_02703290
@lbl_027032D8:
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}
