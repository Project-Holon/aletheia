/*
 * function: func_02731920
 * address:  0x02731920
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02731774  0x02731774  arm  twl
 *   func_0273184C  0x0273184C  arm  twl
 *   func_02731868  0x02731868  arm  twl
 */

typedef unsigned int u32;

extern void func_02731774(void *ctx, const void *key, u32 key_len);
extern void func_0273184C(void *ctx, const void *data, u32 data_len);
extern void func_02731868(void *ctx, void *digest);

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
