/*
 * file:     unit_020911D4_p10.c
 * unit:     yes
 * function: _double_arith_prelude, __dadd_dsub, func_0209B2E8, func_0209B64C
 * address:  0x0209AC04
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void _double_arith_prelude(void);
asm void __dmul(void);
asm void _d2f(void);

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
