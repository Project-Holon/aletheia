/*
 * unit:     no
 * function: __fmul
 * address:  0x0209C77C
 * packet:   pkt_0209C77C
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
 * IEEE-754 binary32 multiply: `mov ip, #0xff; ands r3, ip, r0, lsr #23`
 * pulls the exponent, `umull r1, r3, r0, r1` builds the 48-bit significand
 * product, and the denormal/overflow tails renormalise with `clz`.  Self
 * contained, no cross-entry sharing.
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func __fmul --addr
 *     0x0209C77C --cc 1.1p1 --arm
 */

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
