/*
 * file:     unit_027028E8.c
 * function: func_027028E8
 * address:  0x027028E8
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC 0x027026DC arm twl
 *   func_02702698 0x02702698 arm twl
 *   func_020862B8 0x020862B8 arm twl
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern u32 func_02702698(void);
extern void func_020862B8(u32, u32);

asm void func_027028E8(void) {
    stmdb sp!, {r4, lr}
    bl func_027026DC
    mov r4, r0
    bl func_02702698
    cmp r0, #0
    beq @lbl_02702910
    cmp r0, #2
    ldmnefd sp!, {r4, lr}
    addne sp, sp, #0x10
    bxne lr
@lbl_02702910:
    add r0, r4, #0x2000
    ldr r0, [r0, #0x278]
    mov r1, #2
    add r0, r0, #0x24
    bl func_020862B8
    add r0, r4, #0x2000
    ldr r2, [r0, #0x278]
    add r1, sp, #8
    ldr r3, [sp, #8]
    bic r0, r1, #3
    add ip, r0, #4
    ldrh r4, [r2, #0x24]
    cmp r3, #0
    mov r0, #3
    ldmeqfd sp!, {r4, lr}
    addeq sp, sp, #0x10
    bxeq lr
    mov r1, #0
@lbl_02702958:
    add ip, ip, #4
    ldr r2, [ip, #-4]
    cmp r2, r4
    moveq r0, r1
    subs r3, r3, #1
    str r3, [sp, #8]
    bne @lbl_02702958
    ldmfd sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
