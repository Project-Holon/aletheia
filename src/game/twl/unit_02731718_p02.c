/*
 * file:     unit_02731718_p02.c
 * unit:     yes
 * function: func_0273184C, func_02731868, func_02731920
 * address:  0x0273184C
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
 *   func_02731760  0x02731760  thumb
 *   func_02731764  0x02731764  thumb
 *   func_02731754  0x02731754  thumb
 *   func_02731774  0x02731774  arm  twl
 */
typedef unsigned int u32;

extern void func_02731760(void *a, void *b, void *c);
extern void func_02731764(void);
extern void func_02731754(void);
extern void func_02731774(void *ctx, const void *key, u32 key_len);
void func_0273184C(void *a, void *b, void *c);
asm void func_02731868(void *ctx, void *digest);
asm void func_02731920(void *digest, const void *data, u32 data_len, const void *key, u32 key_len);

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
