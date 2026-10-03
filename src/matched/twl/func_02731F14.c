/*
 * function: func_02731F14
 * address:  0x02731F14
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
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_021659B4  0x021659B4  arm  ov009
 *   func_02702FE8  0x02702FE8  arm  twl
 *   func_027320D0  0x027320D0  arm  twl
 */

typedef unsigned int u32;

extern int func_021657C8(void);
extern void func_02165A4C(unsigned char phase);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern u32 func_02702FE8(void *arg);
extern void func_027320D0(void);

asm void func_02731F14(void)
{
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov     r4, #3
    bl      func_021657C8
    mov     r7, r0
    add     r0, r7, #0x1000
    ldrb    r1, [r0, #0x2dd]
    cmp     r1, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    mov     r5, #0
    strb    r5, [r0, #0x2dd]
    add     r1, r7, #0x4300
    strh    r5, [r1, #0xe4]
    ldrb    r0, [r0, #0x2de]
    mov     r6, #1
    cmp     r0, #0xd
    addls   pc, pc, r0, lsl #2
    b       @loc_027320A4

    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_02731F90
    b       @loc_02731F90
    b       @loc_02731FB0
    b       @loc_02731FD0
    b       @loc_02731FFC
    b       @loc_02732020
    b       @loc_027320A4
    b       @loc_02731FFC
    b       @loc_02732044

@loc_02731F90:
    mov     r0, r4
    bl      func_02165A4C
    mov     r0, r6
    mov     r1, r5
    mov     r2, r5
    add     r3, r4, #0x298
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FB0:
    mov     r0, r4
    bl      func_02165A4C
    mov     r0, r5
    mov     r1, r5
    mov     r2, r5
    rsb     r3, r4, #0x2a4
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FD0:
    ldrh    r8, [r1, #0xe6]
    mov     r0, r4
    strh    r5, [r1, #0xe6]
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    mov     r0, r6
    mov     r2, r8
    add     r1, r1, #0x1000
    add     r3, r4, #0x2a8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FFC:
    mov     r0, r4
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    mov     r0, r5
    mov     r2, r6
    add     r1, r1, #0x1000
    add     r3, r4, #0x2b0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732020:
    mov     r0, r4
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    ldr     r3, =0x2BA
    mov     r0, r5
    mov     r2, r5
    add     r1, r1, #0x1000
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732044:
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    cmp     r0, #2
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    cmp     r0, #3
    beq     @loc_02732084
    cmp     r0, #6
    bne     @loc_02732084
    mov     r0, #0xc
    bl      func_02165A4C
    mov     r0, r6
    mov     r1, r5
    mov     r2, r5
    mov     r3, #0x2c8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732084:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    mov     r1, #0
    mov     r2, r1
    rsb     r3, r0, #0x2d8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_027320A4:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r1, r7, #0x1000
    mov     r0, #7
    ldrb    r2, [r1, #0x2de]
    add     r3, r0, #0x2d0
    mov     r1, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}
}
