/*
 * file:     unit_02704328.c
 * function: func_02704328
 * address:  0x02704328
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027041E8  0x027041E8  arm twl
 *   func_02704258  0x02704258  arm twl
 *   func_02704264  0x02704264  arm twl
 *   func_02704230  0x02704230  arm twl
 */

typedef unsigned int u32;

extern u32 func_027041E8(u32);
extern void func_02704258(void);
extern void func_02704264(u32);
extern void func_02704230(u32);

asm void func_02704328(void) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r0, #0x1a
    bl func_027041E8
    mov r4, r0
    bl func_02704258
    mov r0, r4
    bl func_02704264
    ldr r0, [r4, #4]
    mov r5, #1
    cmp r0, #0
    mov r0, r4
    movne r5, #0
    bl func_02704230
    mov r0, r5
    ldmfd sp!, {r3, r4, r5, pc}
}
