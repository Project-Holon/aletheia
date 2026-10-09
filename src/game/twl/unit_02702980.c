/*
 * file:     unit_02702980.c
 * unit:     yes
 * function: func_02702980, func_02702998, func_02702A40
 * address:  0x02702980
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl a2
 *   func_02087C6C  0x02087C6C  arm twl
 *   data_02FFFC3C   0x02FFFC3C  data
 *   data_02702A8C  0x02702A8C  arm twl a2
 *   data_027341A4  0x027341A4  data twl a2
 *   data_027341B8  0x027341B8  data twl a2
 *   func_0208C848  0x0208C848  arm twl a2
 */
typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern void func_02087C6C(u32);
extern void func_0208C848(u32 *, u32, u32);
u32 func_02702980(void);
asm void func_02702998(u32 a0);
asm void func_02702A40(void);
extern u32 data_02FFFC3C[];
extern u32 data_02702A8C[];
extern u32 data_027341A4[];
extern u32 data_027341B8[];



u32 func_02702980(void) {
    u32 base = func_027026DC();
    u32 ptr = *(u32 *)(base + 0x2278);
    return *(u16 *)(ptr + 0x9E);
}



/*
 *   object (0x02732DA0..0x02735B40) with no ROM content, so sole-ref/self has
 *   no word to compare, and no pool word names it outside this range; there is
 *   no layout/data_objects.txt row for it either.
 */
asm void func_02702998(u32 a0) {
    stmdb sp!, {r3, r4, r5, lr}
    sub sp, sp, #8
    add r5, sp, #0
    mov r4, r0
    mov r0, r5
    bl func_02087C6C
    mov r1, #0
    mov r2, r1
@lbl_027029B8:
    ldrb r0, [r5, r1]
    add r1, r1, #1
    cmp r1, #6
    add r0, r2, r0
    mov r0, r0, lsl #0x10
    mov r2, r0, lsr #0x10
@lbl_dcd:
    dcd 0xbafffff8
    ldr r0, =data_02FFFC3C
    mov r1, #0xd
    ldr r0, [r0]
    ldr r3, =0x66666667
    mov r0, r0, lsl #0x10
    add r0, r2, r0, lsr #16
    mov r0, r0, lsl #0x10
    mov r2, r0, lsr #0x10
    mul r0, r2, r1
    cmp r4, #1
    smull r2, r4, r3, r0
    mov r1, r0, lsr #0x1f
    mov r3, #0xa
    addeq r4, r1, r4, asr #2
    smulleq r1, r2, r3, r4
    subeq r4, r0, r1
    addeq r0, r4, #0x1e
    addne r4, r1, r4, asr #2
    smullne r1, r2, r3, r4
    subne r4, r0, r1
    addne r0, r4, #0x69
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    add sp, sp, #8
    ldmfd sp!, {r3, r4, r5, pc}
}


asm void func_02702A40(void) {
    ldr r3, =data_02702A8C
    ldr r2, =data_027341A4
    ldr r0, =data_027341B8
    str r3, [r2, #0x14]
    mov r3, #0
    ldr r1, =0x0000ffff
    ldr ip, =func_0208C848
    str r3, [r2, #0x18]
    bx ip
}
