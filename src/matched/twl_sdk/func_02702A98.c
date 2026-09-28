/*
 * function: func_02702A98
 * address:  0x02702A98
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
 *   func_02087988  0x02087988  arm twl
 *   func_027026EC  0x027026EC  arm twl
 *   func_020885A0  0x020885A0  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   DAT_027341a4   0x027341a4  data twl
 *   DAT_027341a0   0x027341a0  data twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern void func_02087988(void);
extern void func_027026EC(void);
extern void func_020885A0(u32, u32);
extern void func_0208799C(void);
extern u32 DAT_027341a4[];
extern u32 DAT_027341a0[];

asm void func_02702A98(void) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r0, #1
    mov r1, r0
    bl func_027028E4
    cmp r0, #0
    cmpne r0, #2
    ldmnefd sp!, {r4, r5, r6, pc}
    bl func_02087988
    ldr r4, =DAT_027341a4
    mov r5, #0
    ldr r1, [r4]
    mov r6, r0
    add r0, r1, #0x2000
    ldr r0, [r0, #0x278]
    strh r5, [r0, #0x24]
    bl func_027026EC
    mov r1, r5
    mov r0, #0x16
    bl func_020885A0
    ldr r1, =DAT_027341a0
    mov r0, r6
    str r5, [r4]
    strb r5, [r1]
    bl func_0208799C
    mov r0, r5
    ldmfd sp!, {r4, r5, r6, pc}
}
