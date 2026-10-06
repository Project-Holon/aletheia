/*
 * file:     unit_020911D4_p11.c
 * unit:     yes
 * function: func_0209C5E0, func_0209C77C, func_0209C95C, func_0209CE10, func_0209D1E0, func_0209D724, func_0209D728, func_0209D774, func_0209D778, func_0209D77C, func_0209D784, func_0209D7D4
 * address:  0x0209C5E0
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
 *   g_02153FB4  0x02153FB4  data
 *   g_02153FB8  0x02153FB8  data
 */
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

struct Node;
typedef unsigned char u8;

typedef struct
{
    u8 b[12];
} Ent;

typedef unsigned int   u32;

extern void func_0209D850(u32 a, u32 b, struct Node *node);
asm void __ddiv(void);
void func_0209D724(void);
int func_0209D728(int a);
void func_0209D774(void *p);
extern int   g_02153FB4;
extern Ent   g_02153FB8[];

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

/*
 * layout/runtime_arm9.txt lists 0x0209D724 as _runtime_null_stub and claims
 * it is hand-written assembly. It is a bare 4-byte `bx lr`, which an empty
 * compiled C function reproduces byte for byte, so the row is over-broad and
 * the integrator may drop it. Reported from the runtime-library audit lane
 * (0x0209C2B0..0x0209D724).
 */
void func_0209D724(void)
{
}

/*
 * blocked:  the only occurrences of 0x02153FB4 and 0x02153FB8 in the image are the two
 *           pool words at 0x0209D76C and 0x0209D770, inside this function's own compared
 *           range, so the data class has no outside witness. MATCH, byte-exact.
 */
int func_0209D728(int a)
{
    int r = 0;

    if (g_02153FB4 == 0x40)
        return -1;

    func_0209D850(r, a, (struct Node *)(&g_02153FB8[g_02153FB4++]));
    return r;
}

void func_0209D774(void *p){ }

void func_0209D778(void *str);
int func_0209D77C(void);

void func_0209D778(void *str){ }

int func_0209D77C(void){ return 0; }

extern int func_0209D77C(void);

u32 func_0209D784(u32 a, char *dest, u32 *count)
{
    u32 i;
    u32 n = *count;
    for (i = 0; i < n; i++)
    {
        int c = func_0209D77C();
        dest[i] = (char)c;
        if ((u8)c == '\r' || (u8)c == '\n')
        {
            *count = i + 1;
            break;
        }
    }
    return 0;
}

extern void func_0209D778(void *str);
extern void func_0209D774(void *p);

/*
 * MSL console write hook (the __write_console shape: handle, buffer,
 * size_t *count, returns 0): terminate the buffer's last byte, emit the
 * buffer, then emit the saved byte.  Both callees are bare `bx lr` stubs
 * in this release build.
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 43
 * (docs/notes/func_0209D7D4.c.txt).  The lever is the ARITY of
 * func_0209D778: it takes ONE argument.  The image's `mov r1, #0` is not a
 * second argument but the register the compiler picked for the terminator
 * store, free once `mov r0, r1` has consumed buffer; every earlier spelling
 * passed `(buffer, 0)`, which made the zero an argument CSE'd with the
 * store and forced it into r2 with a `mov r1, r2` copy (72 bytes).  With
 * the one-argument prototype the body is 68 bytes, 0 out.
 *
 * EXACT*: the listing extent runs to 0x0209D820 because the 8-byte
 * `mov r0, #0; bx lr` leaf at 0x0209D818 saves no lr and carries no label
 * (worth seeding into layout/function_starts.txt).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0209D7D4.c \
 *       --func func_0209D7D4 --addr 0x0209D7D4 --arm --cc 1.1p1
 */
int func_0209D7D4(int handle, u8 *buffer, u32 *count)
{
    if (*count > 1) {
        u8 *end = buffer + *count;
        u8 c = end[-1];
        end[-1] = 0;
        func_0209D778(buffer);
        func_0209D774(&c);
    } else {
        func_0209D774(buffer);
    }
    return 0;
}
