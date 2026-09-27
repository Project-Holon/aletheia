/*
 * unit:     no
 * function: __dmul
 * address:  0x0209B2E8
 * packet:   pkt_0209B2E8
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
 * IEEE-754 binary64 multiply: two `umull` pairs build the 106-bit
 * significand product, `add ip, r4, ip` sums the exponents, `orr
 * #0x80000000` restores the hidden bit and `bic ip, ip, #0x800` (2048)
 * removes the doubled bias.  0x0209B648..0x0209B750 (264 bytes) is data,
 * not code -- the routine's own rounding/normalisation table, addressed by
 * two `ldr r1, [pc, #imm]` literal loads inside the body (both landing on
 * its first word, 0x0209B648, coincidentally also the double +Infinity
 * highword 0x7FF00000).  Kept as 66 raw `dcd` words in original byte
 * order; a data table sitting inside a function's own extent is a library
 * shape compiled C cannot produce (it would live in .rodata instead).
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func __dmul --addr
 *     0x0209B2E8 --cc 1.1p1 --arm
 */

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
    dcd 0xE2012102
    dcd 0xE1A0CA21
    dcd 0xE3DCCB02
    dcd 0x0A000019
    dcd 0xE1A03A8C
    dcd 0xE3730602
    dcd 0x2A00000F
    dcd 0xE25CCD0E
    dcd 0x9A000018
    dcd 0xE35C00FF
    dcd 0xAA000032
    dcd 0xE1A01601
    dcd 0xE18234A1
    dcd 0xE1833EA0
    dcd 0xE1B01180
    dcd 0xE1830B8C
    dcd 0x012FFF1E
    dcd 0xE3110102
    dcd 0x012FFF1E
    dcd 0xE1B01081
    dcd 0x02101001
    dcd 0x12800001
    dcd 0xE12FFF1E
    dcd 0xE1903601
    dcd 0x1A000002
    dcd 0xE3A004FF
    dcd 0xE18200A0
    dcd 0xE12FFF1E
    dcd 0xE3E00102
    dcd 0xE12FFF1E
    dcd 0xE1903601
    dcd 0x1A00001B
    dcd 0xE1A00002
    dcd 0xE12FFF1E
    dcd 0xE37C0017
    dcd 0x0A000012
    dcd 0x4A000016
    dcd 0xE1A01581
    dcd 0xE3811102
    dcd 0xE1A03421
    dcd 0xE1833EA0
    dcd 0xE26CC001
    dcd 0xE1B01180
    dcd 0xE1820C33
    dcd 0xE26CC020
    dcd 0xE1A03C13
    dcd 0x13833001
    dcd 0xE1B01003
    dcd 0x012FFF1E
    dcd 0xE3110102
    dcd 0x012FFF1E
    dcd 0xE1B01081
    dcd 0x02101001
    dcd 0x12800001
    dcd 0xE12FFF1E
    dcd 0xE1800601
    dcd 0xE1B01000
    dcd 0xE1A00002
    dcd 0x12800001
    dcd 0xE12FFF1E
    dcd 0xE1A00002
    dcd 0xE12FFF1E
    dcd 0xE3A004FF
    dcd 0xE18200A0
    dcd 0xE12FFF1E
}
