/*
 * function: func_02731A84
 * address:  0x02731A84
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
 *   func_02702FE8  0x02702FE8  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_027320D0  0x027320D0  arm  twl
 */

typedef unsigned int u32;

extern void *func_021657C8(void);
extern u32 func_02702FE8(void *arg);
extern void func_02165A4C(u32 phase);
extern void func_027320D0(void);

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
