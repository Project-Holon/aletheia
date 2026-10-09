/*
 * function: func_02703088
 * address:  0x02703088
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027028E4  0x027028E4  arm twl
 *   func_027026DC  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   func_02082BCC  0x02082BCC  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   func_02703A34  0x02703A34  arm twl
 *   func_02082D44  0x02082D44  arm twl
 *   func_02703B24  0x02703B24  arm twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02082BCC(u32, u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02082D44(u32, u32, u32);
extern u32 func_02703B24(u32, u32);

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
