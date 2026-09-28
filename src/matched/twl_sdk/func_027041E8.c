/*
 * function: func_027041E8
 * address:  0x027041E8
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020879EC  0x020879EC  arm twl
 *   func_0270410C  0x0270410C  arm twl
 *   DAT_027343e0   0x027343e0  data twl
 */

typedef unsigned int u32;

extern u32 func_020879EC(void);
extern void func_0270410C(u32);
extern u32 DAT_027343e0[];

asm void func_027041E8(u32 a0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    bl func_020879EC
    cmp r0, #0x12
    beq @lbl_02704208
    mov r0, r4
    bl func_0270410C
    ldmfd sp!, {r4, pc}
@lbl_02704208:
    ldr r0, =DAT_027343e0
    mov r2, #2
    ldr r0, [r0, #0x68]
    mov r1, #0
    str r4, [r0]
    str r2, [r0, #4]
    str r1, [r0, #0xc]
    str r1, [r0, #8]
    ldmfd sp!, {r4, pc}
}
