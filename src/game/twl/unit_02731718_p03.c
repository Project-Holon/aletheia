/*
 * file:     unit_02731718_p03.c
 * unit:     yes
 * function: func_02731774, func_0273184C, func_02731868, func_02731920, func_0273199C, func_02731A84, func_02731AF0
 * address:  0x02731774
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
 *   func_02731770  0x02731770  thumb
 *   func_02731754  0x02731754  thumb
 *   func_02731760  0x02731760  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02731764  0x02731764  thumb
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02702434  0x02702434  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02702B08  0x02702B08  arm  twl
 *   func_027320D0  0x027320D0  arm  twl
 *   func_02702FE8  0x02702FE8  arm  twl
 */
typedef unsigned int u32;

extern void func_02731770(void);
extern void func_02731754(void);
extern void func_02731760(void *a, void *b, void *c);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_02731764(void);
extern int func_021657C8(void);
extern u32 func_02702434(u32 a0, u32 a1, u32 a2);
extern void func_02165A4C(unsigned char phase);
extern u32 func_02702B08(void *arg);
extern void func_027320D0(void);
extern u32 func_02702FE8(void *arg);
asm void func_02731774(void *ctx, const void *key, u32 key_len);
void func_0273184C(void *a, void *b, void *c);
asm void func_02731868(void *ctx, void *digest);
asm void func_02731920(void *digest, const void *data, u32 data_len, const void *key, u32 key_len);
asm u32 func_0273199C(void);
asm u32 func_02731A84(void);
asm void func_02731AF0(void);


#pragma thumb on

#pragma thumb reset


asm void func_02731774(void *ctx, const void *key, u32 key_len)
{
    stmdb   sp!, {r3, r4, r5, lr}
    sub     sp, sp, #0x40
    movs    r4, r0
    mov     r5, r2
    addeq   sp, sp, #0x40
    ldmeqfd sp!, {r3, r4, r5, pc}
    cmp     r5, #0
    beq     @loc_027317A0
    cmp     r1, #0
    addeq   sp, sp, #0x40
    ldmeqfd sp!, {r3, r4, r5, pc}

@loc_027317A0:
    cmp     r5, #0x40
    bls     @loc_027317C0
    mov     r2, r5
    add     r0, r4, #0x64
    bl      func_02731770
    mov     r0, #0x14
    str     r0, [r4, #0xa4]
    b       @loc_027317D4

@loc_027317C0:
    mov     r0, r1
    mov     r2, r5
    add     r1, r4, #0x64
    bl      MI_CpuCopy8
    str     r5, [r4, #0xa4]

@loc_027317D4:
    ldr     r0, [r4, #0xa4]
    mov     r1, #0
    cmp     r0, #0
    bls     @loc_02731808
    add     r2, sp, #0

@loop_ipad:
    add     r0, r4, r1
    ldrb    r0, [r0, #0x64]
    add     r1, r1, #1
    eor     r0, r0, #0x36
    strb    r0, [r2], #1
    ldr     r0, [r4, #0xa4]
    cmp     r1, r0
    blo     @loop_ipad

@loc_02731808:
    cmp     r1, #0x40
    bge     @loc_0273182C
    add     r0, sp, #0
    add     r2, r0, r1
    mov     r0, #0x36

@loop_pad:
    add     r1, r1, #1
    cmp     r1, #0x40
    strb    r0, [r2], #1
    blt     @loop_pad

@loc_0273182C:
    mov     r0, r4
    bl      func_02731754
    add     r1, sp, #0
    mov     r0, r4
    mov     r2, #0x40
    bl      func_02731760
    add     sp, sp, #0x40
    ldmfd   sp!, {r3, r4, r5, pc}
}




#pragma thumb on




#pragma thumb reset





void func_0273184C(void *a, void *b, void *c)
{
    if (a != 0 && c != 0 && b != 0) {
        func_02731760(a, b, c);
    }
}




#pragma thumb on




#pragma thumb reset





asm void func_02731868(void *ctx, void *digest)
{
    stmdb   sp!, {r4, r5, lr}
    sub     sp, sp, #0x54
    mov     r4, r1
    movs    r5, r0
    cmpne   r4, #0
    addeq   sp, sp, #0x54
    ldmeqfd sp!, {r4, r5, pc}
    add     r1, sp, #0
    bl      func_02731764
    ldr     r0, [r5, #0xa4]
    mov     r1, #0
    cmp     r0, #0
    bls     @loc_027318C0
    add     r2, sp, #0x14

@loc_027318A0:
    add     r0, r5, r1
    ldrb    r0, [r0, #0x64]
    add     r1, r1, #1
    eor     r0, r0, #0x5c
    strb    r0, [r2], #1
    ldr     r0, [r5, #0xa4]
    cmp     r1, r0
    blo     @loc_027318A0

@loc_027318C0:
    cmp     r1, #0x40
    bge     @loc_027318E4
    add     r0, sp, #0x14
    add     r2, r0, r1
    mov     r0, #0x5c

@loc_027318D4:
    add     r1, r1, #1
    cmp     r1, #0x40
    strb    r0, [r2], #1
    blt     @loc_027318D4

@loc_027318E4:
    mov     r0, r5
    bl      func_02731754
    add     r1, sp, #0x14
    mov     r0, r5
    mov     r2, #0x40
    bl      func_02731760
    add     r1, sp, #0
    mov     r0, r5
    mov     r2, #0x14
    bl      func_02731760
    mov     r0, r5
    mov     r1, r4
    bl      func_02731764
    add     sp, sp, #0x54
    ldmfd   sp!, {r4, r5, pc}
}





asm void func_02731920(void *digest, const void *data, u32 data_len, const void *key, u32 key_len)
{
    stmdb   sp!, {r4, r5, r6, lr}
    sub     sp, sp, #0xa8
    movs    r6, r0
    mov     r5, r1
    mov     r4, r2
    addeq   sp, sp, #0xa8
    ldmeqfd sp!, {r4, r5, r6, pc}
    cmp     r4, #0
    beq     @loc_02731950
    cmp     r5, #0
    addeq   sp, sp, #0xa8
    ldmeqfd sp!, {r4, r5, r6, pc}

@loc_02731950:
    ldr     r0, [sp, #0xb8]
    cmp     r0, #0
    beq     @loc_02731968
    cmp     r3, #0
    addeq   sp, sp, #0xa8
    ldmeqfd sp!, {r4, r5, r6, pc}

@loc_02731968:
    ldr     r2, [sp, #0xb8]
    add     r0, sp, #0
    mov     r1, r3
    bl      func_02731774
    add     r0, sp, #0
    mov     r1, r5
    mov     r2, r4
    bl      func_0273184C
    add     r0, sp, #0
    mov     r1, r6
    bl      func_02731868
    add     sp, sp, #0xa8
    ldmfd   sp!, {r4, r5, r6, pc}
}





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


asm void func_02731AF0(void)
{
}
