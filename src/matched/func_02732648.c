/*
 * function: func_02732648
 * address:  0x02732648
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
 *   func_027028B0  0x027028B0  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02731F14  0x02731F14  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 */

typedef unsigned int u32;

extern void *func_021657C8(void);
extern u32 func_027028B0(void);
extern void func_02165A4C(u32 phase);
extern void func_02731F14(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);

asm void func_02732648(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r6, r0
    mov     r4, #0
    bl      func_021657C8
    mov     r5, r0
    bl      func_027028B0
    ldrh    r1, [r6, #2]
    cmp     r1, #5
    addls   pc, pc, r1, lsl #2
    b       @loc_02732840

    b       @loc_02732688
    b       @loc_02732704
    b       @loc_02732840
    b       @loc_02732840
    b       @loc_02732840
    b       @loc_02732830

@loc_02732688:
    cmp     r0, #4
    bne     @loc_027326E0
    add     r0, r5, #0x1000
    ldrb    r0, [r0, #0x2de]
    cmp     r0, #0xc
    bne     @loc_027326B0
    mov     r0, #8
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027326B0:
    ldrh    r2, [r6, #0xe]
    add     r1, r5, #0x4300
    mov     r0, #9
    strh    r2, [r1, #0xe4]
    bl      func_02165A4C
    add     r1, r5, #0x2e0
    mov     r0, r4
    ldr     r3, =0x436
    mov     r2, r0
    add     r1, r1, #0x1000
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027326E0:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r5, #0x2e0
    add     r1, r0, #0x1000
    ldr     r3, =0x43C
    mov     r0, #7
    mov     r2, r4
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732704:
    ldrh    r0, [r6, #0x10]
    cmp     r0, #0xd
    addls   pc, pc, r0, lsl #2
    b       @loc_0273280C

    b       @loc_0273280C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_027327EC
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C

@loc_0273274C:
    add     r0, r5, #0x1000
    ldrb    r0, [r0, #0x2de]
    sub     r0, r0, #8
    cmp     r0, #4
    addls   pc, pc, r0, lsl #2
    ldmfd   sp!, {r4, r5, r6, pc}

    b       @loc_02732784
    b       @loc_02732778
    b       @loc_02732778
    ldmfd   sp!, {r4, r5, r6, pc}
    b       @loc_027327E4

@loc_02732778:
    add     r0, r5, #0x1200
    mov     r1, #6
    strh    r1, [r0, #0xda]

@loc_02732784:
    add     r0, r5, #0x4300
    strh    r4, [r0, #0xe4]
    ldrh    r1, [r6, #0x10]
    cmp     r1, #0xb
    addls   pc, pc, r1, lsl #2
    b       @loc_027327E4

    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327CC
    b       @loc_027327E4
    b       @loc_027327DC
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327D4
    b       @loc_027327D4

@loc_027327CC:
    mov     r1, #0xd
    b       @loc_027327E0

@loc_027327D4:
    mov     r1, #0xf
    b       @loc_027327E0

@loc_027327DC:
    mov     r1, #0x11

@loc_027327E0:
    strh    r1, [r0, #0xe6]

@loc_027327E4:
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027327EC:
    add     r0, r5, #0x1000
    ldrb    r0, [r0, #0x2de]
    cmp     r0, #8
    ldmnefd sp!, {r4, r5, r6, pc}
    add     r0, r5, #0x4300
    strh    r4, [r0, #0xe4]
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273280C:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r5, #0x2e0
    add     r1, r0, #0x1000
    ldrh    r2, [r6, #0x10]
    ldr     r3, =0x481
    mov     r0, #7
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732830:
    mov     r0, #8
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732840:
    mov     r4, #0xb
    mov     r0, r4
    bl      func_02165A4C
    add     r0, r5, #0x2e0
    add     r1, r0, #0x1000
    rsb     r3, r4, #0x4a0
    mov     r0, #7
    mov     r2, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}
}
