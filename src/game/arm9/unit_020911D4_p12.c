/*
 * file:     unit_020911D4_p12.c
 * unit:     yes
 * function: _ll_divmod_entry_signed, _ll_divmod_body, _ll_divmod_entry_flag0,, func_0209C054, func_0209C0A4
 * address:  0x0209BE4C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_not_0_f    0x0209C2B8  arm
 */
extern void _u32_div_not_0_f(void);
asm void _ll_divmod_entry_signed(void);
asm void _ll_mul(void);
asm void _ll_shl(void);
asm void _s32_div_f(void);
asm void _div_by_zero_check(void);


asm void _ll_divmod_entry_signed(void)
{
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, r1
    orr r4, r4, #1
    b L_0209BE6C

_ll_divmod_body:
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    eor r4, r1, r3
    mov r4, r4, asr #1
    mov r4, r4, lsl #1
L_0209BE6C:
    orrs r5, r3, r2
    bne L_0209BE7C
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BE7C:
    mov r5, r0, lsr #0x1f
    add r5, r5, r1
    mov r6, r2, lsr #0x1f
    add r6, r6, r3
    orrs r6, r5, r6
    bne L_0209BEB0
    mov r1, r2
    bl _s32_div_f
    ands r4, r4, #1
    movne r0, r1
    mov r1, r0, asr #0x1f
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BEB0:
    cmp r1, #0
    bge L_0209BEC0
    rsbs r0, r0, #0
    rsc r1, r1, #0
L_0209BEC0:
    cmp r3, #0
    bge L_0209BED0
    rsbs r2, r2, #0
    rsc r3, r3, #0
L_0209BED0:
    orrs r5, r1, r0
    beq L_0209BFF4
    mov r5, #0
    mov r6, #1
    cmp r3, #0
    bmi L_0209BEFC
L_0209BEE8:
    add r5, r5, #1
    adds r2, r2, r2
    adcs r3, r3, r3
    bpl L_0209BEE8
    add r6, r6, r5
L_0209BEFC:
    cmp r1, #0
    blt L_0209BF1C
L_0209BF04:
    cmp r6, #1
    beq L_0209BF1C
    sub r6, r6, #1
    adds r0, r0, r0
    adcs r1, r1, r1
    bpl L_0209BF04
L_0209BF1C:
    mov r7, #0
    mov ip, #0
    mov r11, #0
    b L_0209BF44
L_0209BF2C:
    orr ip, ip, #1
    subs r6, r6, #1
    beq L_0209BF9C
    adds r0, r0, r0
    adcs r1, r1, r1
    adcs r7, r7, r7
L_0209BF44:
    subs r0, r0, r2
    sbcs r1, r1, r3
    sbcs r7, r7, #0
    adds ip, ip, ip
    adc r11, r11, r11
    cmp r7, #0
    bge L_0209BF2C
L_0209BF60:
    subs r6, r6, #1
    beq L_0209BF94
    adds r0, r0, r0
    adcs r1, r1, r1
    adc r7, r7, r7
    adds r0, r0, r2
    adcs r1, r1, r3
    adc r7, r7, #0
    adds ip, ip, ip
    adc r11, r11, r11
    cmp r7, #0
    bge L_0209BF2C
    b L_0209BF60
L_0209BF94:
    adds r0, r0, r2
    adc r1, r1, r3
L_0209BF9C:
    ands r7, r4, #1
    moveq r0, ip
    moveq r1, r11
    beq L_0209BFD4
    subs r7, r5, #0x20
    movge r0, r1, lsr r7
    bge L_0209BFF8
    rsb r7, r5, #0x20
    mov r0, r0, lsr r5
    orr r0, r0, r1, lsl r7
    mov r1, r1, lsr r5
    b L_0209BFD4
    mov r0, r1, lsr r7
    mov r1, #0
L_0209BFD4:
    cmp r4, #0
    blt L_0209BFE4
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BFE4:
    rsbs r0, r0, #0
    rsc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BFF4:
    mov r0, #0
L_0209BFF8:
    mov r1, #0
    cmp r4, #0
    blt L_0209BFE4
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr

_ll_divmod_entry_flag0:
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, #0
    b L_0209C020
_ll_divmod_entry_flag1:
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, #1
L_0209C020:
    orrs r5, r3, r2
    bne L_0209C030
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209C030:
    orrs r5, r1, r3
    bne L_0209BED0
    mov r1, r2
    bl _u32_div_not_0_f
    cmp r4, #0
    movne r0, r1
    mov r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
}


asm void _ll_mul(void)
{
    stmdb sp!, {r4, r5, lr}
    umull r5, r4, r0, r2
    mla r4, r0, r3, r4
    mla r4, r2, r1, r4
    mov r1, r4
    mov r0, r5
    ldmia sp!, {r4, r5, lr}
    bx lr
}



asm void _ll_shl(void)
{
    ands r2, r2, #0x3f
    bxeq lr
    subs r3, r2, #0x20
    bge L_0209C098
    rsb r3, r2, #0x20
    mov r1, r1, lsl r2
    orr r1, r1, r0, lsr r3
    mov r0, r0, lsl r2
    bx lr
L_0209C098:
    mov r1, r0, lsl r3
    mov r0, #0
    bx lr
}


asm void _s32_div_f(void)
{
    eor ip, r0, r1
    and ip, ip, #0x80000000
    cmp r0, #0
    rsblt r0, r0, #0
    addlt ip, ip, #1
    cmp r1, #0
    rsblt r1, r1, #0
    beq L_0209C29C
    cmp r0, r1
    movlo r1, r0
    movlo r0, #0
    blo L_0209C29C
    mov r2, #0x1c
    mov r3, r0, lsr #4
    cmp r1, r3, lsr #12
    suble r2, r2, #0x10
    movle r3, r3, lsr #0x10
    cmp r1, r3, lsr #4
    suble r2, r2, #8
    movle r3, r3, lsr #8
    cmp r1, r3
    suble r2, r2, #4
    movle r3, r3, lsr #4
    mov r0, r0, lsl r2
    rsb r1, r1, #0
    adds r0, r0, r0
    add r2, r2, r2, lsl #1
    add pc, pc, r2, lsl #2
    mov r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    mov r1, r3
L_0209C29C:
    ands r3, ip, #0x80000000
    rsbne r0, r0, #0
    ands r3, ip, #1
    rsbne r1, r1, #0
    bx lr
}



asm void _div_by_zero_check(void)
{
    cmp r1, #0
    bxeq lr
_u32_div_not_0_f:
    cmp r0, r1
    movlo r1, r0
    movlo r0, #0
    bxlo lr
    mov r2, #0x1c
    mov r3, r0, lsr #4
    cmp r1, r3, lsr #12
    suble r2, r2, #0x10
    movle r3, r3, lsr #0x10
    cmp r1, r3, lsr #4
    suble r2, r2, #8
    movle r3, r3, lsr #8
    cmp r1, r3
    suble r2, r2, #4
    movle r3, r3, lsr #4
    mov r0, r0, lsl r2
    rsb r1, r1, #0
    adds r0, r0, r0
    add r2, r2, r2, lsl #1
    add pc, pc, r2, lsl #2
    mov r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    adcs r3, r1, r3, lsl #1
    sublo r3, r3, r1
    adcs r0, r0, r0
    mov r1, r3
    bx lr
}
