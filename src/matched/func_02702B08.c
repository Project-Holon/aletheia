/*
 * function: func_02702B08
 * address:  0x02702B08
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: func_02702D7C (ABS32 at +0xE8) has no witness.  It is a twl bss
 *   object (0x02732DA0..0x02735B40) with no ROM content, so sole-ref/self has
 *   no word to compare, no pool word names it outside this range, and there is
 *   no layout/data_objects.txt row for it.
 *
 * symbols:
 *   func_027028E4  0x027028E4  arm twl
 *   func_027026DC  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   func_02703C28  0x02703C28  arm twl
 *   func_02703A34  0x02703A34  arm twl
 *   func_02702A40  0x02702A40  arm twl
 *   func_0273156C  0x0273156C  arm twl
 *   func_02703A74  0x02703A74  arm twl
 *   func_02702D7C  0x02702D7C  arm twl
 *   DAT_027341a8   0x027341a8  data twl
 */

typedef unsigned int u32;

extern u32 func_027028E4(u32, u32);
extern u32 func_027026DC(void);
extern void func_020862B8(u32, u32);
extern void func_02703C28(void);
extern void func_02703A34(u32, u32);
extern void func_02702A40(void);
extern void func_0273156C(u32);
extern u32 func_02703A74(u32, u32, u32, u32);
extern u32 func_02702D7C[];
extern u32 DAT_027341a8[];

asm void func_02702B08(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #8
    mov r6, r0
    bl func_027026DC
    mov r4, r0
    mov r0, #1
    mov r1, r0
    bl func_027028E4
    cmp r0, #0
    beq @lbl_02702B40
    cmp r0, #2
    addne sp, sp, #8
    ldmnefd sp!, {r3, r4, r5, r6, r7, pc}
@lbl_02702B40:
    bl func_027026DC
    movs r7, r0
    beq @lbl_02702B78
    add r0, r7, #0x2000
    ldr r0, [r0, #0x278]
    mov r5, #1
    mov r1, r5
    add r0, r0, #3
    bl func_020862B8
    add r0, r7, #0x2000
    ldr r0, [r0, #0x278]
    ldrb r0, [r0, #3]
    cmp r0, #1
    movne r5, #0
    b @lbl_02702B7C
@lbl_02702B78:
    mov r5, #0
@lbl_02702B7C:
    cmp r5, #1
    addeq sp, sp, #8
    moveq r0, #3
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    bl func_02703C28
    mov r7, #3
    mov r0, r7
    mov r1, r6
    bl func_02703A34
    bl func_02702A40
    ldr r1, =func_02702D7C
    ldr r0, =DAT_027341a8
    mov r5, #0
    stmia r0, {r1, r5}
    ldr r1, =0xffff
    bl func_0273156C
    add r3, r4, #0x2000
    ldr r2, [r3, #0x27c]
    mov r0, r7
    stmia sp, {r2, r5}
    ldr r2, [r3, #0x274]
    ldr r3, [r3, #0x278]
    mov r1, #4
    bl func_02703A74
    cmp r0, #0
    cmpne r0, #2
    moveq r0, #2
    add sp, sp, #8
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}
}
