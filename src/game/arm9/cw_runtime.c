/*
 * file:     cw_runtime.c
 * unit:     yes
 * function: _double_arith_prelude, __dadd_dsub, func_0209B2E8, func_0209B64C, _s32_to_double, _u32_to_double, __dcmp_1, __dcmp_2, __dcmp_3, __dcmp_4, __dcmp_5, __dcmp_6, _fgeq, __fcmp_1, __fcmp_2, __fcmp_3, __fcmp_4, _f2d, _s32_to_float, _u32_to_float, _ll_divmod_entry_signed, _ll_divmod_body, _ll_divmod_entry_flag0, func_0209C054, func_0209C0A4, _f2s, _f2u, _d2s, _d2u, func_0209C5E0, func_0209C77C, func_0209C95C, func_0209CE10, func_0209D1E0
 * address:  0x0209AC04
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * CodeWarrior runtime.a routines (layout/runtime_arm9.txt rows
 * 0x0209AC04..0x0209D1E0): soft double and float arithmetic, compares,
 * conversions and the 64-bit and 32-bit division helpers, in image order.
 * A different library from the MSL C on both sides, so its own file.
 *
 * symbols:
 *   _u32_div_not_0_f    0x0209C2B8  arm
 */

asm void _double_arith_prelude(void)
{
    stmdb sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    bmi L_0209AF44
L_0209AC14:
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs L_0209AC30
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
L_0209AC30:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq L_0209AD2C
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq L_0209AD74
L_0209AC68:
    subs r4, ip, r4
    beq L_0209ACC0
    cmp r4, #0x20
    ble L_0209ACA4
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    adds r0, r0, r2
    adcs r1, r1, #0
    blo L_0209ACE8
    b L_0209ACCC
L_0209ACA4:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
L_0209ACC0:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo L_0209ACE8
L_0209ACCC:
    add ip, ip, #1
    and r4, r0, #1
    movs r1, r1, rrx
    orr r0, r4, r0, rrx
    mov lr, ip, lsl #0x15
    cmn lr, #0x200000
    beq L_0209AEF8
L_0209ACE8:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #20
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209AD2C:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq L_0209AD98
    orrs r4, r0, r1, lsl #1
    bne L_0209AED4
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq L_0209AEC0
    cmn r4, #0x200000
    bne L_0209AEC0
    orrs r4, r2, r3, lsl #1
    beq L_0209AEC0
    b L_0209AED4
L_0209AD74:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq L_0209AE04
    orrs r4, r2, r3, lsl #1
    bne L_0209AED4
    b L_0209AEC0
L_0209AD98:
    orrs r4, r0, r1, lsl #1
    beq L_0209ADD8
    mov ip, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #20
    beq L_0209AD74
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b L_0209AC68
L_0209ADD8:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq L_0209AE8C
    cmn r4, #0x200000
    bne L_0209AE8C
    orrs r4, r0, r1, lsl #1
    beq L_0209AEC0
    b L_0209AED8
L_0209AE04:
    orrs r4, r2, r3, lsl #1
    beq L_0209AE9C
    mov r4, #1
    bic r3, r3, #0x80000000
    cmp r1, #0
    bpl L_0209AE28
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b L_0209AC68
L_0209AE28:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo L_0209AE48
    add ip, ip, #1
    and r4, r0, #1
    movs r1, r1, rrx
    mov r0, r0, rrx
    orr r0, r0, r4
L_0209AE48:
    cmp r1, #0
    subges ip, ip, #1
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmeqia sp!, {r4, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
L_0209AE8C:
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, lr}
    bx lr
L_0209AE9C:
    cmp r1, #0
    subges ip, ip, #1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
L_0209AEC0:
    ldr r1, [pc, #0x50]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209AED4:
    mov r1, r3
L_0209AED8:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
L_0209AEF8:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    ldr r1, [pc, #0xc]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
    dcd 0x7FF00000
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
__dadd_dsub:
    stmdb sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    bmi L_0209AC14
L_0209AF44:
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs L_0209AF64
    eor lr, lr, #0x80000000
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
L_0209AF64:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq L_0209B168
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq L_0209B1B0
L_0209AF9C:
    subs r4, ip, r4
    beq L_0209B044
    cmp r4, #0x20
    ble L_0209AFD8
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, #0
    bmi L_0209B000
    b L_0209B0F0
L_0209AFD8:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, r3
    bpl L_0209B0F0
L_0209B000:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #20
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209B044:
    subs r0, r0, r2
    sbc r1, r1, r3
    orrs lr, r1, r0
    beq L_0209B2D4
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bmi L_0209B0CC
    bne L_0209B07C
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi L_0209B098
L_0209B07C:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
L_0209B098:
    cmp ip, #0
    bgt L_0209B0D4
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmia sp!, {r4, lr}
    bx lr
L_0209B0CC:
    cmp r1, #0
    subges ip, ip, #1
L_0209B0D4:
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
L_0209B0F0:
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bne L_0209B114
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi L_0209B130
L_0209B114:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
L_0209B130:
    cmp ip, #0
    orrgt ip, ip, lr, lsr #20
    bgt L_0209B000
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmia sp!, {r4, lr}
    bx lr
L_0209B168:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq L_0209B1D4
    orrs r4, r0, r1, lsl #1
    bne L_0209B2B0
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq L_0209B29C
    cmn r4, #0x200000
    bne L_0209B29C
    orrs r4, r2, r3, lsl #1
    beq L_0209B2C4
    b L_0209B2B0
L_0209B1B0:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq L_0209B24C
    orrs r4, r2, r3, lsl #1
    bne L_0209B2B0
    b L_0209B29C
L_0209B1D4:
    orrs r4, r0, r1, lsl #1
    beq L_0209B214
    mov ip, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #20
    beq L_0209B1B0
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b L_0209AF9C
L_0209B214:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq L_0209B240
    cmn r4, #0x200000
    bne L_0209B268
    orrs r4, r0, r1, lsl #1
    bne L_0209B2B4
    b L_0209B29C
L_0209B240:
    orrs r4, r0, r1, lsl #1
    beq L_0209B2D4
    b L_0209B268
L_0209B24C:
    orrs r4, r2, r3, lsl #1
    beq L_0209B278
    mov r4, #1
    bic r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b L_0209AF9C
L_0209B268:
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, lr}
    bx lr
L_0209B278:
    cmp r1, #0
    subges ip, ip, #1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
L_0209B29C:
    ldr r1, [pc, #0x40]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209B2B0:
    mov r1, r3
L_0209B2B4:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
L_0209B2C4:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
L_0209B2D4:
    mov r1, #0
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
    dcd 0x7FF00000
}


asm void __dmul(void)
{
    stmdb sp!, {r4, r5, r6, r7, lr}
    eor lr, r1, r3
    and lr, lr, #0x80000000
    mov ip, r1, lsr #0x14
    mov r1, r1, lsl #0xb
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r6, ip, lsl #0x15
    cmnne r6, #0x200000
    beq L_0209B3F0
    orr r1, r1, #0x80000000
    bic ip, ip, #0x800
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq L_0209B438
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
L_0209B33C:
    add ip, r4, ip
    umull r5, r4, r0, r2
    umull r7, r6, r0, r3
    adds r4, r7, r4
    adc r6, r6, #0
    umull r7, r0, r1, r2
    adds r4, r7, r4
    adcs r0, r0, r6
    umull r7, r2, r1, r3
    adc r1, r2, #0
    adds r0, r0, r7
    adc r1, r1, #0
    orrs r4, r4, r5
    orrne r0, r0, #1
    cmp r1, #0
    blt L_0209B388
    sub ip, ip, #1
    adds r0, r0, r0
    adc r1, r1, r1
L_0209B388:
    add ip, ip, #2
    subs ip, ip, #0x400
    bmi L_0209B524
    beq L_0209B524
    mov r6, ip, lsl #0x14
    cmn r6, #0x100000
    bmi L_0209B624
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B3F0:
    bics ip, ip, #0x800
    beq L_0209B44C
    orrs r6, r0, r1, lsl #1
    bne L_0209B5D8
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq L_0209B42C
    cmn r5, #0x200000
    bne L_0209B5C4
    orrs r5, r2, r3, lsl #1
    beq L_0209B5C4
    b L_0209B5D8
L_0209B42C:
    orrs r5, r3, r2
    beq L_0209B5EC
    b L_0209B5C4
L_0209B438:
    bics r4, r4, #0x800
    beq L_0209B4E0
    orrs r6, r2, r3, lsl #1
    bne L_0209B5D8
    b L_0209B5C4
L_0209B44C:
    orrs r6, r0, r1, lsl #1
    beq L_0209B4B4
    mov ip, #1
    cmp r1, #0
    bne L_0209B470
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi L_0209B48C
L_0209B470:
    clz r6, r1
    movs r1, r1, lsl r6
    rsb r6, r6, #0x20
    orr r1, r1, r0, lsr r6
    rsb r6, r6, #0x20
    mov r0, r0, lsl r6
    sub ip, ip, r6
L_0209B48C:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq L_0209B438
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    b L_0209B33C
L_0209B4B4:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq L_0209B638
    cmn r5, #0x200000
    bne L_0209B638
    orrs r6, r2, r3, lsl #1
    beq L_0209B5EC
    b L_0209B5D8
L_0209B4E0:
    orrs r5, r2, r3, lsl #1
    beq L_0209B638
    mov r4, #1
    cmp r3, #0
    bne L_0209B504
    sub r4, r4, #0x20
    movs r3, r2
    mov r2, #0
    bmi L_0209B33C
L_0209B504:
    clz r6, r3
    movs r3, r3, lsl r6
    rsb r6, r6, #0x20
    orr r3, r3, r2, lsr r6
    rsb r6, r6, #0x20
    mov r2, r2, lsl r6
    sub r4, r4, r6
    b L_0209B33C
L_0209B524:
    cmn ip, #0x34
    beq L_0209B5BC
    bmi L_0209B614
    mov r2, r1
    mov r3, r0
    add r4, ip, #0x34
    cmp r4, #0x20
    movge r2, r3
    movge r3, #0
    subge r4, r4, #0x20
    rsb r5, r4, #0x20
    mov r2, r2, lsl r4
    orr r2, r2, r3, lsr r5
    movs r3, r3, lsl r4
    orrne r2, r2, #1
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    cmp r2, #0
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5BC:
    orr r0, r0, r1, lsl #1
    b L_0209B5FC
L_0209B5C4:
    ldr r1, [pc, #0x7c]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5D8:
    mov r1, r3
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5EC:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5FC:
    movs r2, r0
    mov r1, lr
    mov r0, #0
    addne r0, r0, #1
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B614:
    mov r1, lr
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B624:
    ldr r1, [pc, #0x1c]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B638:
    mov r1, lr
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
    dcd 0x7FF00000
}


asm void _d2f(void)
{
    and r2, r1, #0x80000000
    mov ip, r1, lsr #0x14
    bics ip, ip, #0x800
    beq L_0209B6C4
    mov r3, ip, lsl #0x15
    cmn r3, #0x200000
    bhs L_0209B6A8
    subs ip, ip, #0x380
    bls L_0209B6D4
    cmp ip, #0xff
    bge L_0209B744
    mov r1, r1, lsl #0xc
    orr r3, r2, r1, lsr #9
    orr r3, r3, r0, lsr #29
    movs r1, r0, lsl #3
    orr r0, r3, ip, lsl #23
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209B6A8:
    orrs r3, r0, r1, lsl #12
    bne L_0209B6BC
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209B6BC:
    mvn r0, #0x80000000
    bx lr
L_0209B6C4:
    orrs r3, r0, r1, lsl #12
    bne L_0209B73C
    mov r0, r2
    bx lr
L_0209B6D4:
    cmn ip, #0x17
    beq L_0209B728
    bmi L_0209B73C
    mov r1, r1, lsl #0xb
    orr r1, r1, #0x80000000
    mov r3, r1, lsr #8
    orr r3, r3, r0, lsr #29
    rsb ip, ip, #1
    movs r1, r0, lsl #3
    orr r0, r2, r3, lsr ip
    rsb ip, ip, #0x20
    mov r3, r3, lsl ip
    orrne r3, r3, #1
    movs r1, r3
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209B728:
    orr r0, r0, r1, lsl #12
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
L_0209B73C:
    mov r0, r2
    bx lr
L_0209B744:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
}
asm void _s32_to_double(void)
{
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #0x1e
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    movs r1, r0
    mov r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, r2, r1, lsr #12
    orr r1, r1, r3, lsl #20
    bx lr
}
asm void _u32_to_double(void)
{
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #0x1e
    bmi L_0209B7B4
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
L_0209B7B4:
    mov r1, r0
    mov r0, r1, lsl #0x15
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, r3, lsl #20
    bx lr
}

asm void __dcmp_1(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209B840
    cmn ip, r3, lsl #1
    bhs L_0209B854
L_0209B7E0:
    orrs ip, r3, r1
    bmi L_0209B810
    cmp r1, r3
    cmpeq r0, r2
    movhs r0, #1
    movlo r0, #0
    bx lr
L_0209B7FC:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B810:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhs r0, #1
    movlo r0, #0
    bx lr
L_0209B840:
    bne L_0209B7FC
    cmp r0, #0
    bhi L_0209B7FC
    cmn ip, r3, lsl #1
    blo L_0209B7E0
L_0209B854:
    bne L_0209B7FC
    cmp r2, #0
    bhi L_0209B7FC
    b L_0209B7E0
}
asm void __dcmp_2(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209B8D8
    cmn ip, r3, lsl #1
    bhs L_0209B8EC
L_0209B878:
    orrs ip, r3, r1
    bmi L_0209B8A8
    cmp r1, r3
    cmpeq r0, r2
    movhi r0, #1
    movls r0, #0
    bx lr
L_0209B894:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B8A8:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhi r0, #1
    movls r0, #0
    bx lr
L_0209B8D8:
    bne L_0209B894
    cmp r0, #0
    bhi L_0209B894
    cmn ip, r3, lsl #1
    blo L_0209B878
L_0209B8EC:
    bne L_0209B894
    cmp r2, #0
    bhi L_0209B894
    b L_0209B878
}
asm void __dcmp_3(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209B97C
    cmn ip, r3, lsl #1
    bhs L_0209B990
L_0209B910:
    orrs ip, r3, r1
    bmi L_0209B944
    cmp r1, r3
    cmpeq r0, r2
    movls r0, #1
    movhi r0, #0
    bx lr
L_0209B92C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B944:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bne L_0209B968
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    orr ip, ip, #0x40000000
    msr cpsr_flg, ip
    bxeq lr
L_0209B968:
    cmp r3, r1
    cmpeq r2, r0
    movls r0, #1
    movhi r0, #0
    bx lr
L_0209B97C:
    bne L_0209B92C
    cmp r0, #0
    bhi L_0209B92C
    cmn ip, r3, lsl #1
    blo L_0209B910
L_0209B990:
    bne L_0209B92C
    cmp r2, #0
    bhi L_0209B92C
    b L_0209B910
}
asm void __dcmp_4(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209BA18
    cmn ip, r3, lsl #1
    bhs L_0209BA2C
L_0209B9B4:
    orrs ip, r3, r1
    bmi L_0209B9E4
    cmp r1, r3
    cmpeq r0, r2
    movlo r0, #1
    movhs r0, #0
    bx lr
L_0209B9D0:
    mov r0, #0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B9E4:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bne L_0209BA04
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bxeq lr
L_0209BA04:
    cmp r3, r1
    cmpeq r2, r0
    movlo r0, #1
    movhs r0, #0
    bx lr
L_0209BA18:
    bne L_0209B9D0
    cmp r0, #0
    bhi L_0209B9D0
    cmn ip, r3, lsl #1
    blo L_0209B9B4
L_0209BA2C:
    bne L_0209B9D0
    cmp r2, #0
    bhi L_0209B9D0
    b L_0209B9B4
}
asm void __dcmp_5(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209BAA4
    cmn ip, r3, lsl #1
    bhs L_0209BAB8
L_0209BA50:
    orrs ip, r3, r1
    bmi L_0209BA80
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #1
    movne r0, #0
    bx lr
L_0209BA6C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BA80:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #1
    movne r0, #0
    bx lr
L_0209BAA4:
    bne L_0209BA6C
    cmp r0, #0
    bhi L_0209BA6C
    cmn ip, r3, lsl #1
    blo L_0209BA50
L_0209BAB8:
    bne L_0209BA6C
    cmp r2, #0
    bhi L_0209BA6C
    b L_0209BA50
}
asm void __dcmp_6(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209BB30
    cmn ip, r3, lsl #1
    bhs L_0209BB44
L_0209BADC:
    orrs ip, r3, r1
    bmi L_0209BB0C
    cmp r1, r3
    cmpeq r0, r2
    movne r0, #1
    moveq r0, #0
    bx lr
L_0209BAF8:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BB0C:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movne r0, #1
    moveq r0, #0
    bx lr
L_0209BB30:
    bne L_0209BAF8
    cmp r0, #0
    bhi L_0209BAF8
    cmn ip, r3, lsl #1
    blo L_0209BADC
L_0209BB44:
    bne L_0209BAF8
    cmp r2, #0
    bhi L_0209BAF8
    b L_0209BADC
}

asm void _fgeq(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BB9C
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movge r0, #1
    movlt r0, #0
    mrs ip, cpsr
    biclt ip, ip, #0x20000000
    orrge ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209BB9C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}
asm void __fcmp_1(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BBF8
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movgt r0, #1
    movle r0, #0
    mrs ip, cpsr
    bicle ip, ip, #0x20000000
    orrgt ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209BBF8:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}
asm void __fcmp_2(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BC5C
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movle r0, #1
    movgt r0, #0
    mrs ip, cpsr
    orrgt ip, ip, #0x20000000
    bicgt ip, ip, #0x40000000
    bicle ip, ip, #0x20000000
    orrle ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BC5C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}
asm void __fcmp_3(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BCBC
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movlt r0, #1
    movge r0, #0
    mrs ip, cpsr
    orrge ip, ip, #0x20000000
    biclt ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209BCBC:
    mov r0, #0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}
asm void __fcmp_4(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    blo L_0209BD24
    cmp r3, r1, lsl #1
    blo L_0209BD24
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #0
    bne L_0209BD04
    mrs ip, cpsr
    orr ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BD04:
    cmp r0, r1
    movne r0, #1
    moveq r0, #0
    mrs ip, cpsr
    bicne ip, ip, #0x40000000
    orreq ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BD24:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
}
asm void _f2d(void)
{
    and r2, r0, #0x80000000
    mov ip, r0, lsr #0x17
    mov r3, r0, lsl #9
    ands ip, ip, #0xff
    beq L_0209BD68
    cmp ip, #0xff
    beq L_0209BD94
L_0209BD54:
    add ip, ip, #0x380
    mov r0, r3, lsl #0x14
    orr r1, r2, r3, lsr #12
    orr r1, r1, ip, lsl #20
    bx lr
L_0209BD68:
    cmp r3, #0
    bne L_0209BD7C
    mov r1, r2
    mov r0, #0
    bx lr
L_0209BD7C:
    mov r3, r3, lsr #1
    clz ip, r3
    movs r3, r3, lsl ip
    rsb ip, ip, #1
    add r3, r3, r3
    b L_0209BD54
L_0209BD94:
    cmp r3, #0
    bhi L_0209BDAC
    ldr r1, [pc, #0x14]
    orr r1, r1, r2
    mov r0, #0
    bx lr
L_0209BDAC:
    mvn r0, #0
    bic r1, r0, #0x80000000
    bx lr
    dcd 0x7FF00000
}

asm void _s32_to_float(void)
{
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    bxeq lr
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #0x9e
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r3, r1, #0x7f
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
}
asm void _u32_to_float(void)
{
    cmp r0, #0
    bxeq lr
    mov r3, #0x9e
    bmi L_0209BE20
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
L_0209BE20:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
}
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
asm void _f2s(void)
{
    bic r1, r0, #0x80000000
    mov r2, #0x9e
    subs r2, r2, r1, lsr #23
    ble L_0209C4BC
    mov r1, r1, lsl #8
    orr r1, r1, #0x80000000
    cmp r0, #0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0
    bx lr
L_0209C4BC:
    mvn r0, r0, asr #31
    add r0, r0, #0x80000000
    bx lr
}
asm void _f2u(void)
{
    tst r0, #0x80000000
    bne L_0209C4EC
    mov r1, #0x9e
    subs r1, r1, r0, lsr #23
    blt L_0209C500
    mov r2, r0, lsl #8
    orr r0, r2, #0x80000000
    mov r0, r0, lsr r1
    bx lr
L_0209C4EC:
    mov r2, #0xff000000
    cmp r2, r0, lsl #1
    movhs r0, #0
    mvnlo r0, #0
    bx lr
L_0209C500:
    mvn r0, #0
    bx lr
}
asm void _d2s(void)
{
    bic r3, r1, #0x80000000
    ldr r2, [pc, #0x3c]
    subs r2, r2, r3, lsr #20
    ble L_0209C544
    cmp r2, #0x20
    bge L_0209C53C
    mov r3, r1, lsl #0xb
    orr r3, r3, #0x80000000
    orr r3, r3, r0, lsr #21
    cmp r1, #0
    mov r0, r3, lsr r2
    rsbmi r0, r0, #0
    bx lr
L_0209C53C:
    mov r0, #0
    bx lr
L_0209C544:
    mvn r0, r1, asr #31
    add r0, r0, #0x80000000
    bx lr
    dcd 0x0000041E
}
asm void _d2u(void)
{
    tst r1, #0x80000000
    bne L_0209C5B8
    ldr r2, [pc, #0x78]
    subs r2, r2, r1, lsr #20
    blt L_0209C5D0
    cmp r2, #0x40
    bge L_0209C5AC
    mov ip, r1, lsl #0xb
    orr ip, ip, #0x80000000
    orr ip, ip, r0, lsr #21
    cmp r2, #0x20
    ble L_0209C594
    sub r2, r2, #0x20
    mov r1, #0
    mov r0, ip, lsr r2
    bx lr
L_0209C594:
    mov r3, r0, lsl #0xb
    mov r1, ip, lsr r2
    mov r0, r3, lsr r2
    rsb r2, r2, #0x20
    orr r0, r0, ip, lsl r2
    bx lr
L_0209C5AC:
    mov r1, #0
    mov r0, #0
    bx lr
L_0209C5B8:
    cmn r1, #0x100000
    cmpeq r0, #0
    bhi L_0209C5D0
    mov r1, #0
    mov r0, #0
    bx lr
L_0209C5D0:
    mvn r1, #0
    mvn r0, #0
    bx lr
    dcd 0x0000043E
}
asm void _double_arith_body(void);
asm void __fmul(void);
asm void __fadd(void);
asm void __fdiv(void);

asm void _double_arith_body(void)
{
    stmdb sp!, {r4, r5, r6, lr}
    ldr r2, [pc, #0x184]
    cmp r1, r2
    bhs L_0209C72C
    movs ip, r1, lsr #0x14
    beq L_0209C6D8
    bic r1, r1, r2
    orr r1, r1, #0x100000
L_0209C600:
    movs ip, ip, asr #1
    bhs L_0209C614
    sub ip, ip, #1
    movs r0, r0, lsl #1
    adc r1, r1, r1
L_0209C614:
    movs r3, r0, lsl #1
    adc r1, r1, r1
    mov r2, #0
    mov r4, #0
    mov lr, #0x200000
L_0209C628:
    add r6, r4, lr
    cmp r6, r1
    addle r4, r6, lr
    suble r1, r1, r6
    addle r2, r2, lr
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne L_0209C628
    mov r0, #0
    mov r5, #0
    cmp r1, r4
    cmpeq r3, #0x80000000
    blo L_0209C670
    subs r3, r3, #0x80000000
    sbc r1, r1, r4
    add r4, r4, #1
    mov r0, #0x80000000
L_0209C670:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    mov lr, #0x40000000
L_0209C67C:
    add r6, r5, lr
    cmp r4, r1
    cmpeq r6, r3
    bhi L_0209C69C
    add r5, r6, lr
    subs r3, r3, r6
    sbc r1, r1, r4
    add r0, r0, lr
L_0209C69C:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne L_0209C67C
    orrs r1, r1, r3
    biceq r0, r0, #1
    movs r1, r2, lsr #1
    movs r0, r0, rrx
    adcs r0, r0, #0
    adc r1, r1, #0
    add r1, r1, #0x20000000
    sub r1, r1, #0x100000
    add r1, r1, ip, lsl #20
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209C6D8:
    cmp r1, #0
    bne L_0209C708
    cmp r0, #0
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    mvn ip, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub ip, ip, r5
    mov r1, r0, lsr #0xb
    mov r0, r0, lsl #0x15
    b L_0209C600
L_0209C708:
    clz r2, r1
    movs r1, r1, lsl r2
    rsb r2, r2, #0x2b
    mov r1, r1, lsr #0xb
    orr r1, r1, r0, lsr r2
    rsb r2, r2, #0x20
    mov r0, r0, lsl r2
    rsb ip, r2, #1
    b L_0209C600
L_0209C72C:
    tst r1, #0x80000000
    beq L_0209C748
    bics r3, r1, #0x80000000
    cmpeq r0, #0
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    b L_0209C754
L_0209C748:
    orrs r2, r0, r1, lsl #12
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
L_0209C754:
    ldr r2, [pc, #0x18]
    orr r1, r1, r2
    ldr r3, [pc, #0x14]
    mov r4, #0x21
    str r4, [r3]
    ldmia sp!, {r4, r5, r6, lr}
    bx lr

    dcd 0x7FF00000
    dcd 0x7FF80000
    dcd 0x02153FAC
}
asm void __fmul(void)
{
    eor r2, r0, r1
    and r2, r2, #0x80000000
    mov ip, #0xff
    ands r3, ip, r0, lsr #23
    mov r0, r0, lsl #8
    cmpne r3, #0xff
    beq L_0209C7F8
    orr r0, r0, #0x80000000
    ands ip, ip, r1, lsr #23
    mov r1, r1, lsl #8
    cmpne ip, #0xff
    beq L_0209C838
    orr r1, r1, #0x80000000
L_0209C7B0:
    add ip, r3, ip
    umull r1, r3, r0, r1
    movs r0, r3
    addpl r0, r0, r0
    subpl ip, ip, #1
    subs ip, ip, #0x7f
    bmi L_0209C8C4
    cmp ip, #0xfe
    bge L_0209C930
    ands r3, r0, #0xff
    orr r0, r2, r0, lsr #8
    add r0, r0, ip, lsl #23
    tst r3, #0x80
    bxeq lr
    orrs r1, r1, r3, lsl #25
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
L_0209C7F8:
    cmp r3, #0
    beq L_0209C84C
    movs r0, r0, lsl #1
    bne L_0209C920
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209C82C
    cmp ip, #0xff
    blt L_0209C914
    cmp r1, #0
    beq L_0209C914
    b L_0209C920
L_0209C82C:
    cmp r1, #0
    beq L_0209C928
    b L_0209C914
L_0209C838:
    cmp ip, #0
    beq L_0209C8A8
L_0209C840:
    movs r1, r1, lsl #1
    bne L_0209C920
    b L_0209C914
L_0209C84C:
    movs r0, r0, lsl #1
    beq L_0209C884
    mov r0, r0, lsr #1
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq L_0209C8A8
    cmp ip, #0xff
    beq L_0209C840
    orr r1, r1, #0x80000000
    b L_0209C7B0
L_0209C884:
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209C954
    cmp ip, #0xff
    blt L_0209C954
    cmp r1, #0
    beq L_0209C928
    b L_0209C920
L_0209C8A8:
    movs r1, r1, lsl #1
    beq L_0209C954
    mov r1, r1, lsr #1
    clz ip, r1
    movs r1, r1, lsl ip
    rsb ip, ip, #1
    b L_0209C7B0
L_0209C8C4:
    cmn ip, #0x18
    beq L_0209C90C
    bmi L_0209C94C
    cmp r1, #0
    orrne r0, r0, #1
    mov r3, r0
    mov r0, r0, lsr #8
    rsb ip, ip, #0
    orr r0, r2, r0, lsr ip
    rsb ip, ip, #0x18
    movs r1, r3, lsl ip
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209C90C:
    mov r0, r0, lsl #1
    b L_0209C93C
L_0209C914:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209C920:
    mvn r0, #0x80000000
    bx lr
L_0209C928:
    mvn r0, #0x80000000
    bx lr
L_0209C930:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209C93C:
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
L_0209C94C:
    mov r0, r2
    bx lr
L_0209C954:
    mov r0, r2
    bx lr
}
asm void __fadd(void)
{
__fadd:
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi L_0209CB98
L_0209C968:
    subs ip, r0, r1
    sublo r0, r0, ip
    addlo r1, r1, ip
    mov r2, #0x80000000
    mov r3, r0, lsr #0x17
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #0xff
    beq L_0209C9FC
    mov ip, r1, lsr #0x17
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq L_0209CA3C
L_0209C99C:
    subs ip, r3, ip
    beq L_0209C9B4
    rsb r2, ip, #0x20
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
L_0209C9B4:
    adds r0, r0, r1
    blo L_0209C9D4
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add r3, r3, #1
    and r2, r3, #0xff
    cmp r2, #0xff
    beq L_0209CB44
L_0209C9D4:
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209C9FC:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq L_0209CA60
    movs r0, r0, lsl #1
    bne L_0209CB70
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209CB64
    cmp ip, #0xff
    blt L_0209CB64
    cmp r1, #0
    beq L_0209CB64
    b L_0209CB70
L_0209CA3C:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq L_0209CABC
L_0209CA54:
    movs r1, r1, lsl #1
    bne L_0209CB70
    b L_0209CB64
L_0209CA60:
    movs r0, r0, lsl #1
    beq L_0209CA98
    mov r3, #1
    mov r0, r0, lsr #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq L_0209CABC
    cmp ip, #0xff
    beq L_0209CA54
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b L_0209C99C
L_0209CA98:
    mov r3, r1, lsr #0x17
    mov r0, r1, lsl #9
    ands r3, r3, #0xff
    beq L_0209CB24
    cmp r3, #0xff
    blt L_0209CB24
    cmp r0, #0
    beq L_0209CB64
    b L_0209CB5C
L_0209CABC:
    movs r1, r1, lsl #1
    beq L_0209CB2C
    mov r1, r1, lsr #1
    mov ip, #1
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    cmp r0, #0
    bmi L_0209C99C
    adds r0, r0, r1
    blo L_0209CAF0
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add ip, ip, #1
L_0209CAF0:
    cmp r0, #0
    subge ip, ip, #1
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, ip, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209CB24:
    mov r0, r1
    bx lr
L_0209CB2C:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CB44:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209CB5C:
    mvn r0, #0x80000000
    bx lr
L_0209CB64:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209CB70:
    mvn r0, #0x80000000
    bx lr
    mvn r0, #0x80000000
    bx lr
    eor r0, r0, r1
    eor r1, r0, r1
    eor r0, r0, r1
__fsub:
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi L_0209C968
L_0209CB98:
    subs ip, r0, r1
    eorlo ip, ip, #0x80000000
    sublo r0, r0, ip
    addlo r1, r1, ip
    mov r2, #0x80000000
    mov r3, r0, lsr #0x17
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #0xff
    beq L_0209CCB4
    mov ip, r1, lsr #0x17
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq L_0209CCF4
L_0209CBD0:
    subs ip, r3, ip
    beq L_0209CC18
    rsb r2, ip, #0x20
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
    subs r0, r0, r1
    bpl L_0209CC5C
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209CC18:
    subs r0, r0, r1
    beq L_0209CDC0
    mov r2, r3, lsl #0x17
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt L_0209CC4C
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    bx lr
L_0209CC4C:
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CC5C:
    mov r2, r3, lsl #0x17
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt L_0209CC88
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    bx lr
L_0209CC88:
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209CCB4:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq L_0209CD1C
    movs r0, r0, lsl #1
    bne L_0209CDF4
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209CDE8
    cmp ip, #0xff
    blt L_0209CDE8
    cmp r1, #0
    beq L_0209CDFC
    b L_0209CDF4
L_0209CCF4:
    cmp ip, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq L_0209CD84
L_0209CD0C:
    eor r2, r2, #0x80000000
    movs r1, r1, lsl #1
    bne L_0209CDF4
    b L_0209CDE8
L_0209CD1C:
    movs r0, r0, lsl #1
    beq L_0209CD54
    mov r0, r0, lsr #1
    mov r3, #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq L_0209CD84
    cmp ip, #0xff
    beq L_0209CD0C
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b L_0209CBD0
L_0209CD54:
    mov r3, r1, lsr #0x17
    mov r0, r1, lsl #9
    ands r2, r3, #0xff
    beq L_0209CD78
    cmp r2, #0xff
    blt L_0209CDA0
    cmp r0, #0
    bne L_0209CDE0
    b L_0209CDE8
L_0209CD78:
    cmp r0, #0
    beq L_0209CDC0
    b L_0209CDA0
L_0209CD84:
    movs r1, r1, lsl #1
    beq L_0209CDA8
    mov r1, r1, lsr #1
    mov ip, #1
    orr ip, ip, r2, lsr #23
    orr r3, r3, r2, lsr #23
    b L_0209CBD0
L_0209CDA0:
    mov r0, r1
    bx lr
L_0209CDA8:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CDC0:
    mov r0, #0
    bx lr
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CDE0:
    mvn r0, #0x80000000
    bx lr
L_0209CDE8:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209CDF4:
    mvn r0, #0x80000000
    bx lr
L_0209CDFC:
    mvn r0, #0x80000000
    bx lr
    eor r0, r0, r1
    eor r1, r0, r1
    eor r0, r0, r1
}
asm void __fdiv(void)
{
    stmdb sp!, {lr}
    mov ip, #0xff
    ands r3, ip, r0, lsr #23
    cmpne r3, #0xff
    beq L_0209CFE4
    ands ip, ip, r1, lsr #23
    cmpne ip, #0xff
    beq L_0209D020
    orr r1, r1, #0x800000
    orr r0, r0, #0x800000
    bic r2, r0, #0xff000000
    bic lr, r1, #0xff000000
L_0209CE40:
    cmp r2, lr
    movlo r2, r2, lsl #1
    sublo r3, r3, #1
    teq r0, r1
    sub r0, pc, #0x94
    ldrb r1, [r0, lr, lsr #15]
    rsb lr, lr, #0
    mov r0, lr, asr #1
    mul r0, r1, r0
    add r0, r0, #0x80000000
    mov r0, r0, lsr #6
    mul r0, r1, r0
    mov r0, r0, lsr #0xe
    mul r1, lr, r0
    sub ip, r3, ip
    mov r1, r1, lsr #0xc
    mul r1, r0, r1
    mov r0, r0, lsl #0xe
    add r0, r0, r1, lsr #15
    umull r1, r0, r2, r0
    mov r3, r0
    orrmi r0, r0, #0x80000000
    adds ip, ip, #0x7e
    bmi L_0209D0E8
    cmp ip, #0xfe
    bge L_0209D19C
    add r0, r0, ip, lsl #23
    mov ip, r1, lsr #0x1c
    cmp ip, #7
    beq L_0209CFC4
    add r0, r0, r1, lsr #31
    ldmia sp!, {lr}
    bx lr
    dcd 0xFDFEFFFF
    dcd 0xF9FAFBFC
    dcd 0xF5F6F7F8
    dcd 0xF1F2F3F4
    dcd 0xEEEFF0F0
    dcd 0xEAEBECED
    dcd 0xE7E8E9EA
    dcd 0xE4E5E6E6
    dcd 0xE1E2E2E3
    dcd 0xDEDFDFE0
    dcd 0xDBDCDCDD
    dcd 0xD8D9D9DA
    dcd 0xD5D6D7D7
    dcd 0xD2D3D4D4
    dcd 0xD0D0D1D2
    dcd 0xCDCECECF
    dcd 0xCBCBCCCC
    dcd 0xC8C9C9CA
    dcd 0xC6C6C7C8
    dcd 0xC3C4C5C5
    dcd 0xC1C2C2C3
    dcd 0xBFBFC0C0
    dcd 0xBDBDBEBE
    dcd 0xBABBBCBC
    dcd 0xB8B9B9BA
    dcd 0xB6B7B7B8
    dcd 0xB4B5B5B6
    dcd 0xB2B3B3B4
    dcd 0xB0B1B1B2
    dcd 0xAFAFAFB0
    dcd 0xADADAEAE
    dcd 0xABABACAC
    dcd 0xA9AAAAAA
    dcd 0xA7A8A8A9
    dcd 0xA6A6A7A7
    dcd 0xA4A4A5A5
    dcd 0xA2A3A3A4
    dcd 0xA1A1A2A2
    dcd 0x9FA0A0A0
    dcd 0x9E9E9E9F
    dcd 0x9C9D9D9D
    dcd 0x9B9B9B9C
    dcd 0x999A9A9A
    dcd 0x98989999
    dcd 0x96979798
    dcd 0x95959696
    dcd 0x94949495
    dcd 0x92939393
    dcd 0x91919292
    dcd 0x90909191
    dcd 0x8F8F8F90
    dcd 0x8D8E8E8E
    dcd 0x8C8C8D8D
    dcd 0x8B8B8C8C
    dcd 0x8A8A8A8B
    dcd 0x8989898A
    dcd 0x88888888
    dcd 0x86878787
    dcd 0x85868686
    dcd 0x84858585
    dcd 0x83838484
    dcd 0x82828383
    dcd 0x81818282
    dcd 0x80808181
L_0209CFC4:
    mov r1, r3, lsl #1
    add r1, r1, #1
    rsb lr, lr, #0
    mul r1, lr, r1
    cmp r1, r2, lsl #24
    addmi r0, r0, #1
    ldmia sp!, {lr}
    bx lr
L_0209CFE4:
    eor lr, r0, r1
    and lr, lr, #0x80000000
    cmp r3, #0
    beq L_0209D03C
    movs r0, r0, lsl #9
    bne L_0209D184
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209D174
    cmp ip, #0xff
    blt L_0209D174
    cmp r1, #0
    beq L_0209D190
    b L_0209D16C
L_0209D020:
    eor lr, r0, r1
    and lr, lr, #0x80000000
    cmp ip, #0
    beq L_0209D0A0
L_0209D030:
    movs r1, r1, lsl #9
    bne L_0209D16C
    b L_0209D1BC
L_0209D03C:
    movs r2, r0, lsl #9
    beq L_0209D070
    clz r3, r2
    movs r2, r2, lsl r3
    rsb r3, r3, #0
    mov r2, r2, lsr #8
    ands ip, ip, r1, lsr #23
    beq L_0209D0C8
    cmp ip, #0xff
    beq L_0209D030
    orr r1, r1, #0x800000
    bic lr, r1, #0xff000000
    b L_0209CE40
L_0209D070:
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209D094
    cmp ip, #0xff
    blt L_0209D1BC
    cmp r1, #0
    beq L_0209D1BC
    b L_0209D16C
L_0209D094:
    cmp r1, #0
    beq L_0209D190
    b L_0209D1BC
L_0209D0A0:
    movs ip, r1, lsl #9
    beq L_0209D174
    mov lr, ip
    clz ip, lr
    movs lr, lr, lsl ip
    rsb ip, ip, #0
    mov lr, lr, lsr #8
    orr r0, r0, #0x800000
    bic r2, r0, #0xff000000
    b L_0209CE40
L_0209D0C8:
    movs ip, r1, lsl #9
    beq L_0209D174
    mov lr, ip
    clz ip, lr
    movs lr, lr, lsl ip
    rsb ip, ip, #0
    mov lr, lr, lsr #8
    b L_0209CE40
L_0209D0E8:
    and r0, r0, #0x80000000
    cmn ip, #0x18
    beq L_0209D15C
    bmi L_0209D1B4
    add r1, ip, #0x17
    mov r2, r2, lsl r1
    rsb ip, ip, #0
    mov r3, r3, lsr ip
    orr r0, r0, r3
    rsb lr, lr, #0
    mul r1, lr, r3
    cmp r1, r2
    ldmeqia sp!, {lr}
    bxeq lr
    add r1, r1, lr
    cmp r1, r2
    beq L_0209D150
    addmi r0, r0, #1
    subpl r1, r1, lr
    add r1, lr, r1, lsl #1
    cmp r1, r2, lsl #1
    and r3, r0, #1
    addmi r0, r0, #1
    addeq r0, r0, r3
    ldmia sp!, {lr}
    bx lr
L_0209D150:
    add r0, r0, #1
    ldmia sp!, {lr}
    bx lr
L_0209D15C:
    cmn r2, lr
    addne r0, r0, #1
    ldmia sp!, {lr}
    bx lr
L_0209D16C:
    mov r0, r1
    b L_0209D184
L_0209D174:
    mov r0, #0xff000000
    orr r0, lr, r0, lsr #1
    ldmia sp!, {lr}
    bx lr
L_0209D184:
    mvn r0, #0x80000000
    ldmia sp!, {lr}
    bx lr
L_0209D190:
    mvn r0, #0x80000000
    ldmia sp!, {lr}
    bx lr
L_0209D19C:
    tst r0, #0x80000000
    mov r0, #0xff000000
    movne r0, r0, asr #1
    moveq r0, r0, lsr #1
    ldmia sp!, {lr}
    bx lr
L_0209D1B4:
    ldmia sp!, {lr}
    bx lr
L_0209D1BC:
    mov r0, lr
    ldmia sp!, {lr}
    bx lr
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
}
asm void __ddiv(void)
{
    stmdb sp!, {r4, r5, r6, lr}
    ldr lr, [pc, #0x534]
    eor r4, r1, r3
    ands ip, lr, r1, lsr #19
    cmpne ip, lr
    beq L_0209D58C
    bic r1, r1, lr, lsl #20
    orr r1, r1, #0x100000
    add ip, ip, r4, lsr #31
L_0209D204:
    ands r4, lr, r3, lsr #19
    cmpne r4, lr
    beq L_0209D624
    bic r3, r3, lr, lsl #20
    orr r3, r3, #0x100000
L_0209D218:
    sub ip, ip, r4
    cmp r1, r3
    cmpeq r0, r2
    bhs L_0209D234
    adds r0, r0, r0
    adc r1, r1, r1
    sub ip, ip, #2
L_0209D234:
    sub r4, pc, #0x24
    ldrb lr, [r4, r3, lsr #12]
    rsbs r2, r2, #0
    rsc r3, r3, #0
    mov r4, #0x20000000
    mla r5, lr, r3, r4
    mov r6, r3, lsl #0xa
    mov r5, r5, lsr #7
    mul lr, r5, lr
    orr r6, r6, r2, lsr #22
    mov lr, lr, lsr #0xd
    mul r5, lr, r6
    mov r6, r1, lsl #0xa
    orr r6, r6, r0, lsr #22
    mov r5, r5, lsr #0x10
    mul r5, lr, r5
    mov lr, lr, lsl #0xe
    add lr, lr, r5, lsr #16
    umull r5, r6, lr, r6
    umull r4, r5, r6, r2
    mla r5, r3, r6, r5
    mov r4, r4, lsr #0x1a
    orr r4, r4, r5, lsl #6
    add r4, r4, r0, lsl #2
    umull lr, r5, r4, lr
    mov r4, #0
    adds r5, r5, r6, lsl #24
    adc r4, r4, r6, lsr #8
    cmp ip, #0x800
    bge L_0209D418
    add ip, ip, #0x7f0
    adds ip, ip, #0xc
    bmi L_0209D430
    orr r1, r4, ip, lsl #31
    bic ip, ip, #1
    add r1, r1, ip, lsl #19
    tst lr, #0x80000000
    bne L_0209D308
    rsbs r2, r2, #0
    mov r4, r4, lsl #1
    add r4, r4, r5, lsr #31
    mul lr, r2, r4
    mov r6, #0
    mov r4, r5, lsl #1
    orr r4, r4, #1
    umlal r6, lr, r4, r2
    rsc r3, r3, #0
    mla lr, r4, r3, lr
    cmp lr, r0, lsl #21
    bmi L_0209D308
    mov r0, r5
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D308:
    adds r0, r5, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
    dcd 0xFDFEFFFF
    dcd 0xF9FAFBFC
    dcd 0xF5F6F7F8
    dcd 0xF1F2F3F4
    dcd 0xEEEFF0F0
    dcd 0xEAEBECED
    dcd 0xE7E8E9EA
    dcd 0xE4E5E6E6
    dcd 0xE1E2E2E3
    dcd 0xDEDFDFE0
    dcd 0xDBDCDCDD
    dcd 0xD8D9D9DA
    dcd 0xD5D6D7D7
    dcd 0xD2D3D4D4
    dcd 0xD0D0D1D2
    dcd 0xCDCECECF
    dcd 0xCBCBCCCC
    dcd 0xC8C9C9CA
    dcd 0xC6C6C7C8
    dcd 0xC3C4C5C5
    dcd 0xC1C2C2C3
    dcd 0xBFBFC0C0
    dcd 0xBDBDBEBE
    dcd 0xBABBBCBC
    dcd 0xB8B9B9BA
    dcd 0xB6B7B7B8
    dcd 0xB4B5B5B6
    dcd 0xB2B3B3B4
    dcd 0xB0B1B1B2
    dcd 0xAFAFAFB0
    dcd 0xADADAEAE
    dcd 0xABABACAC
    dcd 0xA9AAAAAA
    dcd 0xA7A8A8A9
    dcd 0xA6A6A7A7
    dcd 0xA4A4A5A5
    dcd 0xA2A3A3A4
    dcd 0xA1A1A2A2
    dcd 0x9FA0A0A0
    dcd 0x9E9E9E9F
    dcd 0x9C9D9D9D
    dcd 0x9B9B9B9C
    dcd 0x999A9A9A
    dcd 0x98989999
    dcd 0x96979798
    dcd 0x95959696
    dcd 0x94949495
    dcd 0x92939393
    dcd 0x91919292
    dcd 0x90909191
    dcd 0x8F8F8F90
    dcd 0x8D8E8E8E
    dcd 0x8C8C8D8D
    dcd 0x8B8B8C8C
    dcd 0x8A8A8A8B
    dcd 0x8989898A
    dcd 0x88888888
    dcd 0x86878787
    dcd 0x85868686
    dcd 0x84858585
    dcd 0x83838484
    dcd 0x82828383
    dcd 0x81818282
    dcd 0x80808181
L_0209D418:
    movs r1, ip, lsl #0x1f
    orr r1, r1, #0x7f000000
    orr r1, r1, #0xf00000
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D430:
    mvn r6, ip, asr #1
    cmp r6, #0x34
    bgt L_0209D57C
    beq L_0209D558
    cmp r6, #0x14
    bge L_0209D478
    rsb r6, r6, #0x13
    mov lr, r0, lsl r6
    rsb r6, r6, #0x14
    mov r0, r5, lsr r6
    rsb r6, r6, #0x20
    orr r0, r0, r4, lsl r6
    rsb r6, r6, #0x20
    mov r4, r4, lsr r6
    orr r1, r4, ip, lsl #31
    mov ip, lr
    mov lr, #0
    b L_0209D4A8
L_0209D478:
    rsb r6, r6, #0x33
    mov lr, r1, lsl r6
    mov r1, ip, lsl #0x1f
    rsb r6, r6, #0x20
    orr ip, lr, r0, lsr r6
    rsb r6, r6, #0x20
    mov lr, r0, lsl r6
    mov r5, r5, lsr #0x15
    orr r5, r5, r4, lsl #11
    rsb r6, r6, #0x1f
    mov r0, r5, lsr r6
    mov r4, #0
L_0209D4A8:
    rsbs r2, r2, #0
    mul r4, r2, r4
    mov r5, #0
    umlal r5, r4, r2, r0
    rsc r3, r3, #0
    mla r4, r0, r3, r4
    cmp r4, ip
    cmpeq r5, lr
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    adds r5, r5, r2
    adc r4, r4, r3
    cmp r4, ip
    bmi L_0209D54C
    bne L_0209D4F0
    cmp r5, lr
    beq L_0209D53C
    blo L_0209D54C
L_0209D4F0:
    subs r5, r5, r2
    sbc r4, r4, r3
L_0209D4F8:
    adds r5, r5, r5
    adc r4, r4, r4
    adds r5, r5, r2
    adc r4, r4, r3
    adds lr, lr, lr
    adc ip, ip, ip
    cmp r4, ip
    bmi L_0209D53C
    ldmneia sp!, {r4, r5, r6, lr}
    bxne lr
    cmp r5, lr
    blo L_0209D53C
    ldmneia sp!, {r4, r5, r6, lr}
    bxne lr
    tst r0, #1
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
L_0209D53C:
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D54C:
    adds r0, r0, #1
    adc r1, r1, #0
    b L_0209D4F8
L_0209D558:
    rsbs r2, r2, #0
    rsc r3, r3, #0
    cmp r1, r3
    cmpeq r0, r2
    mov r1, ip, lsl #0x1f
    mov r0, #0
    movne r0, #1
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D57C:
    mov r1, ip, lsl #0x1f
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D58C:
    orrs r5, r0, r1, lsl #1
    beq L_0209D6B0
    cmp ip, lr
    beq L_0209D5F4
    movs r1, r1, lsl #0xc
    beq L_0209D5D0
    clz r5, r1
    movs r1, r1, lsl r5
    sub ip, ip, r5
    add r5, ip, #0x1f
    mov r1, r1, lsr #0xb
    orr r1, r1, r0, lsr r5
    rsb r5, r5, #0x20
    mov r0, r0, lsl r5
    mov ip, ip, lsl #1
    orr ip, ip, r4, lsr #31
    b L_0209D204
L_0209D5D0:
    mvn ip, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub ip, ip, r5
    mov r1, r0, lsr #0xb
    mov r0, r0, lsl #0x15
    mov ip, ip, lsl #1
    orr ip, ip, r4, lsr #31
    b L_0209D204
L_0209D5F4:
    orrs r5, r0, r1, lsl #12
    bne L_0209D6D8
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    bhs L_0209D618
    and r5, r3, #0x80000000
    eor r1, r5, r1
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D618:
    orrs r5, r2, r3, lsl #12
    bne L_0209D6F8
    b L_0209D710
L_0209D624:
    orrs r5, r2, r3, lsl #1
    beq L_0209D69C
    cmp r4, lr
    beq L_0209D684
    movs r3, r3, lsl #0xc
    beq L_0209D664
    clz r5, r3
    movs r3, r3, lsl r5
    sub r4, r4, r5
    add r5, r4, #0x1f
    mov r3, r3, lsr #0xb
    orr r3, r3, r2, lsr r5
    rsb r5, r5, #0x20
    mov r2, r2, lsl r5
    mov r4, r4, lsl #1
    b L_0209D218
L_0209D664:
    mvn r4, #0x13
    clz r5, r2
    movs r2, r2, lsl r5
    sub r4, r4, r5
    mov r3, r2, lsr #0xb
    mov r2, r2, lsl #0x15
    mov r4, r4, lsl #1
    b L_0209D218
L_0209D684:
    orrs r5, r2, r3, lsl #12
    bne L_0209D6F8
    mov r1, ip, lsl #0x1f
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D69C:
    mov r1, ip, lsl #0x1f
    orr r1, r1, lr, lsl #19
    mov r0, #0
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D6B0:
    orrs r5, r2, r3, lsl #1
    beq L_0209D710
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    cmpeq r2, #0
    bhi L_0209D6F8
    eor r1, r1, r3
    and r1, r1, #0x80000000
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D6D8:
    tst r1, #0x80000
    beq L_0209D710
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    cmpeq r2, #0
    bhi L_0209D6F8
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D6F8:
    tst r3, #0x80000
    beq L_0209D710
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209D710:
    orr r1, r1, #0x7f000000
    orr r1, r1, #0xf80000
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
    dcd 0x00000FFE
}
