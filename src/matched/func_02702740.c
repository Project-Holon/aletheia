/*
 * function: func_02702740
 * address:  0x02702740
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   DAT_027341a4   0x027341a4  data twl
 *   func_020862B8  0x020862B8  code twl
 *   func_02702A78  0x02702A78  code twl
 *   func_02731590  0x02731590  code twl
 *   DAT_027341a8   0x027341a8  data twl
 *   func_02082BCC  0x02082BCC  code twl
 *   func_020862D4  0x020862D4  code twl
 *   func_027026EC  0x027026EC  code twl
 */

typedef unsigned int u32;

extern u32 DAT_027341a4[];
extern void func_020862B8(u32, u32);
extern void func_02702A78(void);
extern void func_02731590(u32);
extern u32 DAT_027341a8[];
extern void func_02082BCC(u32, u32, u32);
extern void func_020862D4(u32, u32);
extern void func_027026EC(void);

asm void func_02702740(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r0, =DAT_027341a4
    mov r5, r1
    ldr r4, [r0]
    cmp r4, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    cmp r2, #0
    ldmnefd sp!, {r4, r5, r6, pc}
    cmp r5, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldrh r0, [r5]
    cmp r0, #0x14
    ldmhsfd sp!, {r4, r5, r6, pc}
    add r0, r4, #0x2000
    mov r6, #0x100
    ldr r0, [r0, #0x27c]
    mov r1, r6
    bl func_020862B8
    add r0, r4, #0x2000
    ldr r0, [r0, #0x278]
    mov r1, #0xc0
    bl func_020862B8
    add r0, r4, #0x2000
    ldr r0, [r0, #0x27c]
    cmp r5, r0
    beq @lbl_027027B4
    mov r0, r5
    mov r1, r6
    bl func_020862B8
@lbl_027027B4:
    ldrh r1, [r5]
    cmp r1, #3
    bne @lbl_027027CC
    ldrh r0, [r5, #2]
    cmp r0, #0
    bne @lbl_027027E4
@lbl_027027CC:
    cmp r1, #4
@dcd1:
    dcd 0x01d500b2
@dcd2:
    dcd 0x03500000
    beq @lbl_027027E4
    cmp r1, #0x13
    bne @lbl_027027E8
@lbl_027027E4:
    bl func_02702A78
@lbl_027027E8:
    ldrh r0, [r5]
    cmp r0, #0xb
    bne @lbl_02702810
    ldrh r0, [r5, #2]
    cmp r0, #0xc
@dcd3:
    dcd 0x15951004
@dcd4:
    dcd 0x13510000
    beq @lbl_02702810
    mov r0, r5
    blx r1
@lbl_02702810:
    ldrh r0, [r5]
    cmp r0, #0xb
    beq @lbl_02702878
    cmp r0, #4
    cmpne r0, #0x13
    beq @lbl_0270283C
    cmp r0, #3
    bne @lbl_02702844
    ldrh r0, [r5, #2]
    cmp r0, #0
    beq @lbl_02702844
@lbl_0270283C:
    ldr r0, =DAT_027341a8
    bl func_02731590
@lbl_02702844:
    ldrh r1, [r5]
    add r0, r4, r1, lsl #2
    add r0, r0, #0x2000
    cmp r1, #7
    ldr r6, [r0, #0x284]
    bne @lbl_02702868
    ldr r0, [r5, #0x10]
    ldr r1, [r5, #0xc]
    bl func_020862B8
@lbl_02702868:
    cmp r6, #0
    beq @lbl_02702878
    mov r0, r5
    blx r6
@lbl_02702878:
    mov r6, #0x100
    mov r0, r5
    mov r2, r6
    mov r1, #0
    bl func_02082BCC
    mov r0, r5
    mov r1, r6
    bl func_020862D4
    cmp r4, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    bl func_027026EC
    ldmfd sp!, {r4, r5, r6, pc}
}
