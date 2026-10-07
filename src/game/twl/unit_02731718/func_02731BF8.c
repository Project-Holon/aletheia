/*
 * function: func_02731BF8
 * address:  0x02731BF8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_027034C0  0x027034C0  arm  twl
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02703960  0x02703960  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_027320D0  0x027320D0  arm  twl
 */

typedef unsigned int u32;

extern int func_021657C8(void);
extern u32 func_027034C0(void *a, u32 b, u32 c, void *d);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_02703960(void *a, void *b);
extern void func_02165A4C(unsigned char phase);
extern void func_027320D0(void);

asm u32 func_02731BF8(void)
{
    stmdb   sp!, {r3, r4, r5, lr}
    sub     sp, sp, #0x28
    bl      func_021657C8
    mov     r4, r0
    add     r0, r4, #0x1000
    ldrb    r1, [r0, #0x290]
    cmp     r1, #7
    addls   pc, pc, r1, lsl #2
    b       @loc_02731C98

    b       @loc_02731C3C
    b       @loc_02731C3C
    b       @loc_02731C3C
    b       @loc_02731C3C
    b       @loc_02731C6C
    b       @loc_02731C6C
    b       @loc_02731C6C
    b       @loc_02731C6C

@loc_02731C3C:
    ldr     r0, [r0, #0x2d4]
    mov     r2, #0
    and     r0, r0, #0xc0000
    cmp     r0, #0xc0000
    moveq   r2, #1
    add     r0, r4, #0x1000
    str     r2, [sp, #0]
    ldrb    r2, [r0, #0x291]
    ldr     r0, =func_027320D0
    add     r3, r4, #0x1240
    bl      func_027034C0
    b       @loc_02731C94

@loc_02731C6C:
    add     r1, sp, #6
    add     r0, r4, #0x1240
    mov     r2, #0x20
    bl      MI_CpuCopy8
    add     r0, r4, #0x1000
    ldrb    r2, [r0, #0x290]
    ldr     r0, =func_027320D0
    add     r1, sp, #4
    strh    r2, [sp, #4]
    bl      func_02703960

@loc_02731C94:
    mov     r5, r0

@loc_02731C98:
    cmp     r5, #2
    beq     @loc_02731CB4
    cmp     r5, #3
    beq     @loc_02731CD8
    cmp     r5, #6
    beq     @loc_02731CCC
    b       @loc_02731CD8

@loc_02731CB4:
    mov     r0, #8
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #5
    strh    r1, [r0, #0xda]
    b       @loc_02731CEC

@loc_02731CCC:
    add     sp, sp, #0x28
    mov     r0, #4
    ldmfd   sp!, {r3, r4, r5, pc}

@loc_02731CD8:
    mov     r0, #0xb
    bl      func_02165A4C
    add     sp, sp, #0x28
    mov     r0, #7
    ldmfd   sp!, {r3, r4, r5, pc}

@loc_02731CEC:
    mov     r0, #3
    add     sp, sp, #0x28
    ldmfd   sp!, {r3, r4, r5, pc}
}
