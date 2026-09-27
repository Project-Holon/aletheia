/*
 * unit:     yes
 * function: _double_arith_prelude, __dadd_dsub
 * address:  0x0209AC04
 * packet:   pkt_0209AC04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PENDING, not filed to the manifest -- see converters.c in this same
 * scratchpad for the leak reason (tools/worklist.py's proven_game
 * short-circuit at a layout/runtime_arm9.txt address; no manifest kind
 * exists for hand-written runtime library code).
 *
 * __dadd_dsub's `bmi #0x209ac14` branches backward into the interior of
 * _double_arith_prelude (the double add/sub magnitude-swap and mantissa
 * add/subtract kernel), so the two layout/runtime_arm9.txt rows are filed
 * as one asm function; __dadd_dsub is kept as a label inside it for
 * documentation. IEEE-754 binary64 field split throughout: `lsr r1, #0x14`
 * (20) extracts the exponent, `lsl #11` renormalises the significand.  One
 * pool word (0x7FF00000, double +Infinity highword) is referenced twice
 * from inside the body (0x0209AF18) and once more at the very end
 * (0x0209B2E4); both copies are kept, exactly where the original bytes put
 * them, as `dcd`.
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func
 *     _double_arith_prelude --addr 0x0209AC04 --cc 1.1p1 --arm
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
