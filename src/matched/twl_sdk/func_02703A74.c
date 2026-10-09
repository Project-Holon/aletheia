/*
 * function: func_02703A74
 * address:  0x02703A74
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC  0x027026DC  arm twl
 *   func_02703B98  0x02703B98  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   func_02088610  0x02088610  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern u32 func_02703B98(void);
extern void func_020862D4(u32, u32);
extern u32 func_02088610(u32, u32, u32);
extern void func_02085DBC(u32, u32, u32);

asm void func_02703A74(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    bl func_027026DC
    mov r5, r0
    bl func_02703B98
    movs r4, r0
    moveq r0, #6
    ldmeqfd sp!, {r4, r5, r6, lr}
    addeq sp, sp, #0x10
    bxeq lr
    strh r6, [r4]
    ldrh r6, [sp, #0x14]
    add r0, sp, #0x14
    bic r0, r0, #3
    mov r3, #0
    cmp r6, #0
    add r2, r0, #4
    ble @lbl_02703ADC
@lbl_02703AC0:
    add r2, r2, #4
    ldr r1, [r2, #-4]
    add r0, r4, r3, lsl #2
    add r3, r3, #1
    str r1, [r0, #4]
    cmp r3, r6
@lbl_dcd:
    dcd 0xbafffff8
@lbl_02703ADC:
    mov r0, r4
    mov r1, #0x100
    bl func_020862D4
    mov r1, r4
    mov r0, #0x16
    mov r2, #0
    bl func_02088610
    mov r6, r0
    mov r1, r4
    add r0, r5, #0x2000
    mov r2, #1
    bl func_02085DBC
    mov r0, #6
    cmp r6, #0
    movge r0, #2
    ldmfd sp!, {r4, r5, r6, lr}
    add sp, sp, #0x10
    bx lr
}
