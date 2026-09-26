/*
 * function: func_0273199C
 * address:  0x0273199C
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
 *   func_02702434  0x02702434  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02702B08  0x02702B08  arm  twl
 *   func_027320D0  0x027320D0  arm  twl
 */

typedef unsigned int u32;

extern void *func_021657C8(void);
extern u32 func_02702434(void *a, u32 b, u32 c);
extern void func_02165A4C(u32 phase);
extern u32 func_02702B08(void *arg);
extern void func_027320D0(void);

asm u32 func_0273199C(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    add     r0, r4, #0x1000
    ldr     r1, [r0, #0x2c0]
    add     r0, r4, #0x3a0
    and     r2, r1, #0xff
    add     r0, r0, #0x1000
    mov     r1, #0x3000
    bl      func_02702434
    cmp     r0, #5
    addls   pc, pc, r0, lsl #2
    b       @loc_02731A00

    b       @loc_02731A10
    b       @loc_02731A00
    b       @loc_02731A00
    b       @loc_027319E8
    b       @loc_027319F8
    b       @loc_02731A00

@loc_027319E8:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_027319F8:
    mov     r0, #5
    ldmfd   sp!, {r4, pc}

@loc_02731A00:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731A10:
    ldr     r0, =func_027320D0
    add     r1, r4, #0x4300
    mov     r2, #0
    strh    r2, [r1, #0xe6]
    bl      func_02702B08
    cmp     r0, #2
    beq     @loc_02731A40
    cmp     r0, #3
    beq     @loc_02731A68
    cmp     r0, #6
    beq     @loc_02731A58
    b       @loc_02731A68

@loc_02731A40:
    mov     r0, #2
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #1
    strh    r1, [r0, #0xda]
    b       @loc_02731A78

@loc_02731A58:
    mov     r0, #0xc
    bl      func_02165A4C
    mov     r0, #1
    ldmfd   sp!, {r4, pc}

@loc_02731A68:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731A78:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}
