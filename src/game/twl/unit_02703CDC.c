/*
 * file:     unit_02703CDC.c
 * unit:     yes
 * function: func_02703CDC, func_02703E90, func_02703F04, func_02703F7C, func_02704088
 * address:  0x02703CDC
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
 *   func_0208B7B0  0x0208B7B0  arm twl
 *   func_02087988  0x02087988  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   func_02085D94  0x02085D94  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   data_02150FEC  0x02150FEC  data a1
 *   func_02703F60  0x02703F60  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 *   func_02088610  0x02088610  code twl
 */
typedef unsigned int u32;

typedef signed int s32;

extern u32 func_0208B7B0(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern void func_02085D94(u32, u32, u32);
extern void func_02085E50(u32, u32, u32);
extern u32 func_02085DBC(u32, u32, u32);
extern s32 func_02088610(u32, u32, u32);
asm void func_02703CDC(u32 a0, u32 a1, u32 a2);
asm void func_02703E90(void);
asm void func_02703F04(u32 a0, u32 a1);
asm void func_02703F7C(u32 a0, u32 a1, u32 a2, u32 a3);
u32 func_02704088(void);
extern u32 data_02150FEC[];
extern u32 func_02703F60[];





asm void func_02703CDC(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    bl func_0208B7B0
    ldr r1, [r8, #8]
    mov r4, r0
    cmp r1, #0
    moveq r0, #2
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    ldr r0, [r8, #4]
    tst r0, #0x1f
    bne @lbl_02703D18
    tst r1, #0x1f
    beq @lbl_02703D20
@lbl_02703D18:
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703D20:
    ldr r0, [r8]
    cmp r0, #5
    addls pc, pc, r0, lsl #2
    b @lbl_02703D78
    b @lbl_02703D48
    b @lbl_02703D50
    b @lbl_02703D58
    b @lbl_02703D60
    b @lbl_02703D68
    b @lbl_02703D70
@lbl_02703D48:
    mov r2, #0
    b @lbl_02703D80
@lbl_02703D50:
    mov r2, #1
    b @lbl_02703D80
@lbl_02703D58:
    mov r2, #2
    b @lbl_02703D80
@lbl_02703D60:
    mov r2, #3
    b @lbl_02703D80
@lbl_02703D68:
    mov r2, #5
    b @lbl_02703D80
@lbl_02703D70:
    mov r2, #7
    b @lbl_02703D80
@lbl_02703D78:
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703D80:
    ldr r1, [r8, #0xc]
    cmp r1, #0x800
    bhi @lbl_02703DC0
    bhs @lbl_02703E04
    ldr r0, =0x3ff
    cmp r1, r0
    bhi @lbl_02703DB0
    bhs @lbl_02703E04
    sub r0, r0, #0x140
    cmp r1, r0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DB0:
    add r0, r0, #0x180
    cmp r1, r0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DC0:
    cmp r1, #0xb00
    bhi @lbl_02703DDC
    bhs @lbl_02703E04
    ldr r0, =0x83f
    cmp r1, r0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DDC:
    ldr r0, =0xbff
    cmp r1, r0
    bhi @lbl_02703DF0
    beq @lbl_02703E04
    b @lbl_02703DFC
@lbl_02703DF0:
    rsb r0, r0, #0x1c00
    cmp r1, r0
    beq @lbl_02703E04
@lbl_02703DFC:
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703E04:
    ldr r0, [r8, #0x10]
    cmp r0, #0
    orrne r0, r2, #0x10
    biceq r0, r2, #0x10
    and r0, r0, #0xff
    bic r0, r0, #0x20
    and r5, r0, #0xff
    bl func_02087988
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02703E3C
    bl func_0208799C
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02703E3C:
    mov r1, #1
    str r1, [r4]
    bl func_0208799C
    str r7, [r4, #4]
    str r6, [r4, #8]
    ldr r0, [r8, #0x14]
    ldr r6, [r8, #0x18]
    str r0, [r4, #0x10]
    ldr r2, [r8, #0xc]
    mov r3, r5
    ldmib r8, {r0, r1}
    str r6, [r4, #0x14]
    bl func_02703F7C
    cmp r0, #0
    mov r0, #0
    streq r0, [r4]
    moveq r0, #3
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}





/*
 *   witness.  Both are twl bss objects (0x02732DA0..0x02735B40) with no ROM
 *   content, so sole-ref/self has no word to compare, no pool word names them
 *   outside this range, and there is no layout/data_objects.txt row.
 */
asm void func_02703E90(void) {
    stmdb sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x28
    ldr r0, =data_02150FEC
    ldr r0, [r0, #4]
    cmp r0, #0
    addeq sp, sp, #0x28
    moveq r0, #5
    ldmeqfd sp!, {r3, r4, r5, pc}
    add r5, sp, #8
    mov r4, #1
    add r1, sp, #0
    mov r0, r5
    mov r2, r4
    bl func_02085D94
    ldr r0, =func_02703F60
    mov r1, r5
    bl func_02703F04
    str r0, [sp, #4]
    cmp r0, #0
    bne @lbl_02703EF0
    add r1, sp, #4
    mov r0, r5
    mov r2, r4
    bl func_02085E50
@lbl_02703EF0:
    ldr r0, [sp, #4]
    add sp, sp, #0x28
    ldmfd sp!, {r3, r4, r5, pc}
}




asm void func_02703F04(u32 a0, u32 a1) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r1
    bl func_0208B7B0
    mov r4, r0
    bl func_02087988
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02703F34
    bl func_0208799C
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_02703F34:
    mov r1, #1
    str r1, [r4]
    bl func_0208799C
    str r6, [r4, #4]
    str r5, [r4, #8]
    bl func_02704088
    cmp r0, #0
    mov r0, #0
    streq r0, [r4]
    moveq r0, #3
    ldmfd sp!, {r4, r5, r6, pc}
    mov r2, r0
    mov r0, r1
    mov r1, r2
    ldr ip, [pc, #4]
    mov r2, #0
    bx ip
    dcd func_02085DBC
}



asm void func_02703F7C(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r7, r1
    orr r1, r3, #0x4400
    mov r4, #9
    mov r8, r0
    mov r5, #0
    mov r6, r2
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x2000000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r1, r8, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x10000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r8, lsl #0x10
    mov r1, r0, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x20000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r1, r7, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x30000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r0, r7, lsl #0x10
    mov r1, r0, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x40000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    mov r1, r6, lsr #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r1, #0x50000
    bl func_02088610
    cmp r0, #0
    movlt r0, r5
    ldmltfd sp!, {r4, r5, r6, r7, r8, pc}
    ldr r3, =0x01060000
    mov r1, r6, lsl #0x10
    mov r0, r4
    mov r2, r5
    orr r1, r3, r1, lsr #16
    bl func_02088610
    cmp r0, #0
    movge r5, #1
    mov r0, r5
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}


/*
 * 0x03004500 is a fixed DSi main-RAM work buffer address used as a cast
 *   constant by the original source.  It is a literal pool word, not a
 *   relocation, and needs no witness.
 */
u32 func_02704088(void) {
    u32 res = 0;
    if (func_02088610(9, 0x03004500, 0) >= 0) {
        res = 1;
    }
    return res;
}
