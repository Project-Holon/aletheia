/*
 * function: func_02700938
 * address:  0x02700938
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC0  0x02732FC0  data twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   data_02701AA0  0x02701AA0  code twl a2
 *   data_02702070  0x02702070  code twl a2
 *   data_02732FF8  0x02732FF8  data twl a2
 *   data_02733008  0x02733008  data twl a2
 *   data_02700078  0x02700078  code twl a2
 *   data_0273417C  0x0273417C  data twl a2
 *   data_0273419C  0x0273419C  data twl a2
 *   data_0273302C  0x0273302C  data twl a2
 *   data_02700824  0x02700824  code twl a2
 *   data_027340EC  0x027340EC  data twl a2
 *   func_02088498  0x02088498  code twl a2
 *   func_020885EC  0x020885EC  code twl a2
 *   func_020885A0  0x020885A0  code twl a2
 *   func_02702080  0x02702080  code twl a2
 *   func_0270212C  0x0270212C  code twl a2
 *   func_027021E4  0x027021E4  code twl a2
 *   func_0208C848  0x0208C848  code twl a2
 *   func_0273156C  0x0273156C  code twl a2
 *   func_0270223C  0x0270223C  code twl a2
 *   func_02702268  0x02702268  code twl a2
 *   func_02702208  0x02702208  code twl a2
 *   func_02084774  0x02084774  code twl a2
 *   func_02084968  0x02084968  code twl a2
 *   func_02085D94  0x02085D94  code twl a2
 *   func_020853C0  0x020853C0  code twl a2
 *   func_02085868  0x02085868  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC0[];
extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern u32 data_02701AA0[];
extern u32 data_02702070[];
extern u32 data_02732FF8[];
extern u32 data_02733008[];
extern u32 data_02700078[];
extern u32 data_0273417C[];
extern u32 data_0273419C[];
extern u32 data_0273302C[];
extern u32 data_02700824[];
extern u32 data_027340EC[];

extern void func_02088498(void);
extern u32 func_020885EC(u32, u32);
extern void func_020885A0(u32, u32);
extern void func_02702080(void);
extern void func_0270212C(void);
extern void func_027021E4(void);
extern void func_0208C848(u32, u32);
extern void func_0273156C(u32, u32);
extern void func_0270223C(u32);
extern void func_02702268(u32);
extern void func_02702208(u32);
extern void func_02084774(u32, u32);
extern void func_02084968(u32);
extern void func_02085D94(u32, u32, u32);
extern void func_020853C0(u32, u32, u32, u32);
extern void func_02085868(u32);

asm void func_02700938(void) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    sub sp, sp, #8
    ldr r0, [pc, #0x1b8]
    ldr r1, [r0]
    cmp r1, #0
    addne sp, sp, #8
    movne r0, #2
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    ldr r7, [pc, #0x1a4]
    mov r4, #0
    str r4, [r7, #0x58]
    str r4, [r7, #0x5c]
    str r4, [r7, #0x60]
    str r4, [r7]
    str r4, [r7, #4]
    str r4, [r7, #0x28]
    mov r5, #1
    ldr r6, [pc, #0x184]
    str r5, [r0]
    str r4, [r7, #0x2c]
    str r4, [r6, #0x124]
    str r4, [r6, #0x1ac]
    str r4, [r6, #0x1b0]
    bl func_02088498
    mov r8, #0x15
    mov r0, r8
    mov r1, r5
    bl func_020885EC
    cmp r0, #0
    addeq sp, sp, #8
    moveq r0, #7
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    ldr r1, [pc, #0x14c]
    mov r0, r8
    bl func_020885A0
    bl func_02702080
    bl func_0270212C
    bl func_027021E4
    ldr sb, [pc, #0x138]
    ldr r0, [pc, #0x138]
    str sb, [r7, #0x30]
    str r4, [r7, #0x34]
    mov r8, #0x3fc
    mov r1, r8
    bl func_0208C848
    str sb, [r7, #0x40]
    str r4, [r7, #0x44]
    mov r1, r8
    ldr r0, [pc, #0x118]
    bl func_0273156C
    mov r0, #0x200
    bl func_0270223C
    mov r0, r5
    bl func_02702268
    mov r0, r5
    bl func_02702208
    mov r7, #0x2000000
    mov r0, r7
    ldr r1, [pc, #0xf4]
    bl func_02084774
    mov r0, r7
    bl func_02084968
    mov r1, #5
    str r1, [r6, #0x128]
    str r4, [r6, #0x12c]
    str r4, [r6, #0x130]
    str r4, [r6, #0x134]
    mov r0, #2
    str r0, [r6, #0x138]
    str r0, [r6, #0x13c]
    sub r0, r0, #4
    str r5, [r6, #0x140]
    str r4, [r6, #0x144]
    str r4, [r6, #0x148]
    str r4, [r6, #0x14c]
    str r0, [r6, #0x150]
    str r5, [r6, #0x154]
    str r5, [r6, #0x158]
    str r5, [r6, #0x15c]
    str r4, [r6, #0x160]
    str r1, [r6, #0x164]
    str r4, [r6, #0x168]
    str r4, [r6, #0x16c]
    str r4, [r6, #0x170]
    str r4, [r6, #0x174]
    str r4, [r6, #0x178]
    str r4, [r6, #0x17c]
    str r4, [r6, #0x180]
    str r4, [r6, #0x184]
    str r4, [r6, #0x188]
    str r4, [r6, #0x18c]
    str r5, [r6, #0x190]
    str r5, [r6, #0x194]
    str r5, [r6, #0x198]
    str r4, [r6, #0x19c]
    mov r2, r5
    ldr r0, [pc, #0x60]
    ldr r1, [pc, #0x60]
    bl func_02085D94
    mov r0, #0x1000
    str r0, [sp]
    mov r0, #4
    str r0, [sp, #4]
    ldr r5, [pc, #0x4c]
    ldr r1, [pc, #0x4c]
    mov r0, r5
    mov r2, r4
    ldr r3, [pc, #0x44]
    bl func_020853C0
    mov r0, r5
    bl func_02085868
    mov r0, r4
    add sp, sp, #8
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    dcd data_02732FC0
    dcd data_02732FC8
    dcd data_02733FC8
    dcd data_02701AA0
    dcd data_02702070
    dcd data_02732FF8
    dcd data_02733008
    dcd data_02700078
    dcd data_0273417C
    dcd data_0273419C
    dcd data_0273302C
    dcd data_02700824
    dcd data_027340EC
}
