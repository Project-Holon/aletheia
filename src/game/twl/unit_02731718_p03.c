/*
 * file:     unit_02731718_p03.c
 * unit:     yes
 * function: func_0273199C, func_02731A84
 * address:  0x0273199C
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
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02702434  0x02702434  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02702B08  0x02702B08  arm  twl
 *   func_027320D0  0x027320D0  arm  twl
 *   func_02702FE8  0x02702FE8  arm  twl
 */
typedef unsigned int u32;

extern int func_021657C8(void);
extern u32 func_02702434(u32 a0, u32 a1, u32 a2);
extern void func_02165A4C(unsigned char phase);
extern u32 func_02702B08(void *arg);
extern void func_027320D0(void);
extern u32 func_02702FE8(void *arg);
asm u32 func_0273199C(void);
asm u32 func_02731A84(void);


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


asm u32 func_02731A84(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    cmp     r0, #2
    beq     @loc_02731AB4
    cmp     r0, #3
    beq     @loc_02731AD4
    cmp     r0, #6
    beq     @loc_02731ACC
    b       @loc_02731AD4

@loc_02731AB4:
    mov     r0, #4
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #2
    strh    r1, [r0, #0xda]
    b       @loc_02731AE4

@loc_02731ACC:
    mov     r0, #4
    ldmfd   sp!, {r4, pc}

@loc_02731AD4:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731AE4:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}
