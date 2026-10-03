/*
 * function: func_02732874
 * address:  0x02732874
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
 *   func_02731F14  0x02731F14  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 */

typedef unsigned int u32;

extern int func_021657C8(void);
extern void func_02165A4C(unsigned char phase);
extern void func_02731F14(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);

asm void func_02732874(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r4, r0
    bl      func_021657C8
    ldrh    r1, [r4, #2]
    mov     r4, r0
    cmp     r1, #4
    addls   pc, pc, r1, lsl #2
    b       @loc_0273291C

    b       @loc_027328A8
    b       @loc_0273290C
    b       @loc_0273291C
    b       @loc_0273290C
    b       @loc_0273291C

@loc_027328A8:
    add     r0, r4, #0x1000
    ldrb    r0, [r0, #0x2de]
    cmp     r0, #0xc
    bne     @loc_027328C8
    mov     r0, #0xa
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027328C8:
    cmp     r0, #0xd
    bne     @loc_027328D8
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027328D8:
    mov     r5, #3
    mov     r0, r5
    add     r1, r4, #0x4300
    mov     r6, #0
    strh    r6, [r1, #0xe4]
    bl      func_02165A4C
    add     r1, r4, #0x2e0
    mov     r0, r6
    mov     r2, r6
    add     r1, r1, #0x1000
    rsb     r3, r5, #0x4c0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273290C:
    mov     r0, #0xa
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273291C:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x2e0
    ldr     r3, =0x4CF
    add     r1, r0, #0x1000
    mov     r0, #7
    mov     r2, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}
}
