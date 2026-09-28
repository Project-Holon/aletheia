/*
 * function: func_02732CEC
 * address:  0x02732CEC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02166378  0x02166378  arm  ov009
 *   func_02165AF4  0x02165AF4  arm  ov009
 *   func_02166594  0x02166594  arm  ov009
 */

extern void *func_02166378(void);
extern void func_02165AF4(void);
extern void func_02166594(void *arg, int val);

asm void func_02732CEC(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r5, r0
    bl      func_02166378
    ldrh    r1, [r5]
    mov     r4, r0
    cmp     r1, #0xb
    ldmnefd sp!, {r4, r5, r6, pc}
    ldrh    r0, [r5, #2]
    strh    r0, [r4, #0x24]
    ldrh    r0, [r5, #2]
    cmp     r0, #0
    bne     @loc_02732D20
    bl      func_02165AF4

@loc_02732D20:
    ldrh    r0, [r4, #0x24]
    mov     r5, #0
    cmp     r0, #0
    beq     @loc_02732D34
    mvn     r5, #4

@loc_02732D34:
    ldr     r6, [r4, #0x2c]
    mov     r1, #0
    add     r0, r4, #0xc
    str     r1, [r4, #0x2c]
    bl      func_02166594
    mov     r0, r5
    blx     r6
    ldmfd   sp!, {r4, r5, r6, pc}
}
