/*
 * function: func_02731774
 * address:  0x02731774
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02731770  0x02731770  thumb
 *   func_02731754  0x02731754  thumb
 *   func_02731760  0x02731760  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 */

typedef unsigned int u32;

#pragma thumb on
extern void func_02731770(void);
extern void func_02731754(void);
extern void func_02731760(void);
#pragma thumb reset

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

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
